#include "Variable.h"

Variable::Variable(char name) : isHold(false), name(name), possibleValue({ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 })
{
}
char Variable::Name() const
{
	return name;
}
bool Variable::HasValue() const
{
	return isHold || possibleValue.size() == 1;
}
VariableValue Variable::Value() const
{
	if (HasValue())
	{
		if (isHold)
		{
			return possibleValue[holdIndex];
		}
		else
			return *possibleValue.begin();
	}
	else
		return NO_VALUE;
}
VariableValue Variable::MinValue() const
{
	return *possibleValue.begin();
}
VariableValue Variable::MaxValue() const
{
	return *possibleValue.rbegin();
}
bool Variable::Has(const VariableValue & val) const
{
	return std::any_of(possibleValue.begin(), possibleValue.end(), [&](const VariableValue& x) { return x == val; });
}
void Variable::Remove(const VariableValue val)
{
	possibleValue.erase(remove(possibleValue.begin(), possibleValue.end(), val), possibleValue.end());
}
void Variable::Remove(const vector<VariableValue>& values)
{
	possibleValue.erase(remove_if(possibleValue.begin(), possibleValue.end(), [&values](VariableValue& pVal)
	{
		return any_of(values.cbegin(), values.cend(), [&pVal](const VariableValue& checkVal)
		{
			return checkVal == pVal;
		});
	}), possibleValue.end());
}
void Variable::RemoveAllExcept(const VariableValue val)
{
	possibleValue.erase(remove_if(possibleValue.begin(), possibleValue.end(), [&val](VariableValue pVal)
	{
		return pVal != val;
	}), possibleValue.end());
}
void Variable::RemoveAllExcept(const vector<VariableValue>& values)
{
	possibleValue.erase(remove_if(possibleValue.begin(), possibleValue.end(), [&values](VariableValue& pVal)
	{
		return !any_of(values.cbegin(), values.cend(), [&pVal](const VariableValue& checkVal) 
		{
			return checkVal == pVal;
		});
	}), possibleValue.end());
}
void Variable::RemoveLessThan(VariableValue val)
{
	possibleValue.erase(remove_if(possibleValue.begin(), possibleValue.end(), [&val](const VariableValue& checkVal) { return checkVal < val; }), possibleValue.end());
}
void Variable::HoldValue(size_t index)
{
	holdIndex = index;
	isHold = true;
}
void Variable::UnHold()
{
	isHold = false;
}
size_t Variable::ValuesCount() const
{
	return possibleValue.size();
}
size_t Variable::HoldIndex() const
{
	return holdIndex;
}
bool Variable::HoldNext()
{
	if (holdIndex + 1 < ValuesCount())
	{
		holdIndex++;
		return false;
	}
	else
	{
		holdIndex = 0;
		return true;
	}
}
