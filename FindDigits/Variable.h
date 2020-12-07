#pragma once
#include <algorithm>
#include <vector>

using namespace std;

typedef unsigned int VariableValue;
class Variable
{
	bool isHold;
	size_t holdIndex;
	const char name;
	vector<VariableValue> possibleValue;
public:
	static const VariableValue NO_VALUE = -1;
	Variable(char name);
	char Name() const;
	bool HasValue() const;
	VariableValue Value() const;
	VariableValue MinValue() const;
	VariableValue MaxValue() const;
	bool Has(const VariableValue& val) const;
	void Remove(const VariableValue val);
	void Remove(const vector<VariableValue>& values);
	void RemoveAllExcept(const VariableValue val);
	void RemoveAllExcept(const vector<VariableValue>& values);
	void RemoveLessThan(VariableValue val);
	void HoldValue(size_t index);
	void UnHold();
	size_t ValuesCount() const;
	size_t HoldIndex() const;
	bool HoldNext();
};
