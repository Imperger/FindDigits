#include "bruteforcetask.h"

BruteForceTask::BruteForceTask(const vector<Variable*>& vars, const vector<VariablesGroup*>& groups, const vector<Expression>& expressions, const size_t start, const size_t count, bool& inProgress): vars(vars), groups(groups), expressions(expressions), start(start), count(count), inProgress(inProgress)
{
	qRegisterMetaType<vector<Variable*>>("vector<Variable*>");
}
void BruteForceTask::process()
{
#pragma region LocalVariables
	vector<Variable*> localVars;
	for (auto& item : vars)
		localVars.push_back(new Variable(*item));
#pragma endregion
#pragma region LocalGroups
	vector<VariablesGroup*> localGroups;
	for (auto& group : groups)
	{
		vector<Variable*> groupVars;
		for (auto& v : group->Variables())
			groupVars.push_back(*find_if(localVars.begin(), localVars.end(), [&v](const Variable* vr)
		{
			return vr->Name() == v->Name();
		}));
		localGroups.push_back(new VariablesGroup(groupVars));
	}
#pragma endregion
#pragma region LocalExpression
	vector<Expression> localExpressions;
	for (auto& expression : expressions)
	{
		vector<VariablesGroup*> values;
		for (auto& group : expression.Groups())
			values.push_back(*find_if(localGroups.begin(), localGroups.end(), [&group](const VariablesGroup* g)
		{
			return g->Name() == group->Name();
		}));
		localExpressions.push_back(Expression(values, expression.Operator()));
	}
#pragma endregion

	auto cur = localVars.rbegin();

	(*cur)->HoldValue(start % (*cur)->ValuesCount());
	++cur;
	size_t startPos = start;
	while (cur != localVars.rend())
	{
		startPos /= (*(cur - 1))->ValuesCount();
		(*cur)->HoldValue((startPos) % (*cur)->ValuesCount());
		++cur;
	}

	size_t iterationLeft = count;
	while (inProgress && iterationLeft-- > 0)
	{
		for (auto it = localVars.rbegin(); it != localVars.rend(); ++it)
		{
			if (!(*it)->HoldNext())
				break;
		}


		bool hasDuplicates = false;
		struct { unsigned s : 10; }duplicates = { 0 };
		for (auto var : localVars)
		{
			VariableValue val = var->Value();
			if ((duplicates.s >> val) & 1)
			{
				hasDuplicates = true;
				break;
			}
			else
			{
				duplicates.s |= 1 << val;
			}
		}
		if (hasDuplicates)
			continue;

		if (all_of(localExpressions.begin(), localExpressions.end(), [](Expression& exp) {return exp.Test(); }))
		{
			for (size_t n = 0; n < vars.size(); ++n)
				vars[n]->HoldValue(localVars[n]->HoldIndex());
			emit solved(vars);
			inProgress = false;
			break;
		}

	}
	emit completed();
}
BruteForceTask::~BruteForceTask()
{

}
