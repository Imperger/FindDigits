#pragma once
#include <numeric>
#include <vector>

#include "Variable.h"

using namespace std;

typedef unsigned int GroupValue;
class VariablesGroup
{
	const vector<Variable*> group;
	GroupValue ComputeValue() const;
public:
	VariablesGroup(const vector<Variable*>& vars);
	static const GroupValue NO_VALUE = -1;
	bool HasValue() const;
	GroupValue Value() const;
	const vector<Variable*>& Variables() const;
	size_t Size() const;
	string Name() const;
};

