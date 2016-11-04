#include "Computer.h"


void Computer::BruteForce()
{	
	if (any_of(vars.begin(), vars.end(), [](const Variable* v) {return v->ValuesCount() == 0; }))
	{
		emit Completed();
		return;
	}

	inProgress = true;

	for (auto var: vars)
		var->HoldValue(0);

	tasksCompleted = 0;
	size_t threadCount = thread::hardware_concurrency();
	size_t iterationPerThread = ceil(IterationNeeded() / threadCount);
	
	size_t threadIdx = 0;
	workers.resize(threadCount);

	generate(workers.begin(), workers.end(), [&threadIdx, &iterationPerThread, this]()
	{
		QThread* thread = new QThread();
		BruteForceTask* task = new BruteForceTask(vars, groups, expressions, threadIdx++ * iterationPerThread, iterationPerThread, inProgress);
		QObject::connect(task, SIGNAL(solved(const vector<Variable*>)), this, SLOT(TaskSolved(const vector<Variable*>)));
		QObject::connect(task, SIGNAL(completed()), this, SLOT(TaskCompleted()));
		QObject::connect(thread, SIGNAL(started()), task, SLOT(process()));
		task->moveToThread(thread);
		
		return thread;
	});

	for_each(workers.begin(), workers.end(), [](QThread* t)
	{
		t->start();
	});
}
void Computer::FirstCantBeZero()
{
	for (auto group: groups)
	{
		group->Variables()[0]->Remove(0);
	}
}
void Computer::EqualLastVariable()
{
	function<void(Variable*, Variable*)> keepDoubles = [](Variable* source, Variable* target) 
	{
		vector<VariableValue> excepts;
		excepts.reserve(source->ValuesCount());

		for (size_t index = 0; index < source->ValuesCount(); ++index)
		{
			source->HoldValue(index);
			VariableValue val = 2 * source->Value();
			if (val < 10)
				excepts.push_back(val);
			source->UnHold();
		}
		target->RemoveAllExcept(excepts);
	};

	for (auto& exp: expressions)
	{
		if (exp.Groups()[0]->Variables().back() == exp.Groups()[1]->Variables().back())//2
		{
			if (exp.Operator() == '+')
			{
				keepDoubles(exp.Groups()[0]->Variables().back(), exp.Groups()[2]->Variables().back());
			}
			else if (exp.Operator() == '-')
			{
				exp.Groups()[2]->Variables().back()->RemoveAllExcept(0);
			}
		}
		else if (exp.Groups()[0]->Variables().back() == exp.Groups()[2]->Variables().back())//1
		{
			exp.Groups()[1]->Variables().back()->RemoveAllExcept(0);
		}
		else if (exp.Groups()[1]->Variables().back() == exp.Groups()[2]->Variables().back())//0
		{
			if (exp.Operator() == '+')
			{
				exp.Groups()[0]->Variables().back()->RemoveAllExcept(0);
			}
			else if (exp.Operator() == '-')
			{
				keepDoubles(exp.Groups()[1]->Variables().back(), exp.Groups()[0]->Variables().back());
			}
		}
	}
}
void Computer::HasVariableValue()
{
	vector<VariableValue> knownVars;
	for (auto var: vars)
	{
		if (var->HasValue())
			knownVars.push_back(var->Value());
	}

	for (auto var : vars)
	{
		if (!var->HasValue())
			var->Remove(knownVars);
	}
}
Variable& Computer::GetVariable(char name)
{
	Variable* var = nullptr;
	auto found = find_if(vars.begin(), vars.end(), [&name](const Variable* v) 
	{
		return v->Name() == name;
	});
	if (found == vars.end())
	{
		var = new Variable(name);
		vars.push_back(var);
	}
	else
	{
		var = *found;
	}
	return *var;
}
VariablesGroup& Computer::GetGroup(string name)
{
	VariablesGroup* group = nullptr;
	auto found = find_if(groups.begin(), groups.end(), [&name](const VariablesGroup* v) 
	{
		return v->Name() == name;
	});
	if (found == groups.end())
	{
		vector<Variable*> newGroup;
		for (char var : name)
		{
			newGroup.push_back(&GetVariable(var));
		}
		group = new VariablesGroup(newGroup);
		groups.push_back(group);
	}
	else
	{
		group = *found;
	}
	return *group;
}
void Computer::AddExpression(const Expression& exp)
{
	vector<VariablesGroup*> groups;
	for (auto group : exp.Groups())
	{
		groups.push_back(&GetGroup(group->Name()));
	}
	expressions.push_back(Expression(groups, exp.Operator()));
}
void Computer::Optimize(function<void(size_t)> optimizationRound, function<void(string, size_t)> onOptFuncComplete)
{
	vector<tuple<string, function<void(void)>, bool>> optimisationFuncs
	{ make_tuple( "FirstCantBeZero", bind(&Computer::FirstCantBeZero, this), false ),
		make_tuple("EqualLastVariable", bind(&Computer::EqualLastVariable, this), true) ,
	 make_tuple("HasVariableValue", bind(&Computer::HasVariableValue, this), true) };

	bool needReoptimization = true;
	bool skipNonReopt = false;
	size_t prevIterationNeeded = IterationNeeded();
	size_t optRound = 1;	
	while (needReoptimization)
	{
		optimizationRound(optRound++);
		size_t beforeOptimization = IterationNeeded();
		for (auto opt : optimisationFuncs)
		{
			if (skipNonReopt && !get<2>(opt))
				continue;

			get<1>(opt)();
			onOptFuncComplete(get<0>(opt), prevIterationNeeded);
			prevIterationNeeded = IterationNeeded();
		}
		needReoptimization = IterationNeeded() < beforeOptimization;
		skipNonReopt = true;
	}
	
}
void Computer::Run()
{
	BruteForce();
}
const vector<Variable*>& Computer::Variables() const
{
	return vars;
}
const vector<VariablesGroup*>& Computer::Groups() const
{
	return groups;
}
const vector<Expression>& Computer::Expressions() const
{
	return expressions;
}
size_t Computer::IterationNeeded() const
{
	return accumulate(vars.begin(), vars.end(), 1LL, [](size_t acc, const Variable* v) 
	{
		return acc * v->ValuesCount();
	});
}
void Computer::Reset()
{
	for (vector<Variable*>::iterator it = vars.begin(); it != vars.end(); ++it)
	{
		delete (*it);
	}
	vars.clear();

	for (vector<VariablesGroup*>::iterator it = groups.begin(); it != groups.end(); ++it)
	{
		delete (*it);
	}
	groups.clear();

	expressions.clear();
}
void Computer::TaskSolved(const vector<Variable*> vars)
{
	emit Solved(vars);
}
void Computer::TaskCompleted()
{
	if (++tasksCompleted == workers.size())
		emit Completed();
}
