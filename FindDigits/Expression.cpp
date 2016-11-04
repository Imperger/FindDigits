#include "Expression.h"

Expression::Expression(string expStr)
{
	expStr.erase(remove(expStr.begin(), expStr.end(), ' '), expStr.end());
	vector<Variable*> group;
	for (auto token : expStr)
	{
		switch (token)
		{
		case '+':
		case '-':
			op = token;
		case '=':
			values.push_back(new VariablesGroup(group));
			group.clear();
			break;
		default:
			group.push_back(new Variable(token));
		}
	}
	values.push_back(new VariablesGroup(group));
}
Expression::Expression(const vector<VariablesGroup*>& values, char op): values(values), op(op)
{
}
char Expression::Operator() const
{
	return op;
}
const VariablesGroup& Expression::Group(GroupIndex index) const
{
	return *values[index];
}
const vector<VariablesGroup*>& Expression::Groups() const
{
	return values;
}
bool Expression::Test() const
{
	switch (op)
	{
	case '+':
		return values[0]->Value() +
			values[1]->Value() == 
			values[2]->Value();
	case '-':
		return values[0]->Value() -
			values[1]->Value() ==
			values[2]->Value();
	}
	return false;
}
