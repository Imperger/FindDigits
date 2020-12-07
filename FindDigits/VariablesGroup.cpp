#include "VariablesGroup.h"

VariablesGroup::VariablesGroup(const vector<Variable*>& vars) : group(vars)
{
}
GroupValue VariablesGroup::ComputeValue() const
{
	size_t index = 1;
	size_t groupSize = group.size();
	size_t pow10[] = {1, 10, 100, 1000, 10000, 100000, 1000000};
	
	return accumulate(group.cbegin(), group.cend(), 0u, [&index, &groupSize, &pow10, this](const VariableValue& acc, const Variable* var)
	{
		return acc + var->Value() * pow10[groupSize - index++];
	});
}
bool VariablesGroup::HasValue() const
{
	for (const Variable* v : group)
		if (!v->HasValue())
			return false;
	return true;
}
GroupValue VariablesGroup::Value() const
{
	return HasValue() ? ComputeValue() : VariablesGroup::NO_VALUE;
}
const vector<Variable*>& VariablesGroup::Variables() const
{
	return group;
}
size_t VariablesGroup::Size() const
{
	return group.size();
}
string VariablesGroup::Name() const
{
	return accumulate(group.cbegin(), group.cend(), string(""), [](string name, Variable* var) 
	{
		return name + var->Name();
	});
}