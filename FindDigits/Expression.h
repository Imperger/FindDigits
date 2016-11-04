#pragma once
#include <algorithm>
#include <vector>

#include "VariablesGroup.h"
using namespace std;

enum GroupIndex { LEFT = 0, RIGHT = 1, RESULT = 2 };
class Expression
{
	char op;
	vector<VariablesGroup*> values;
public:
	Expression(string expStr);
	Expression(const vector<VariablesGroup*>& values, char op);
	char Operator() const;
	const VariablesGroup& Group(GroupIndex index) const;
	const vector<VariablesGroup*>& Groups() const;
	bool Test() const;
};

