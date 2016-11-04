#pragma once
#include <string>
#include <vector>
#include <map>
#include <string>
#include <functional>
#include <tuple>
#include <thread>
#include <iostream>

#include <QThread>
#include <QDebug>

#include "Expression.h"
#include "Variable.h"
#include "bruteforcetask.h"

using namespace std;

Q_DECLARE_METATYPE(vector<Variable*>)

class Computer: public QObject
{
	Q_OBJECT	

	vector<Variable*> vars;
	vector<VariablesGroup*> groups;
	vector<Expression> expressions;

	size_t tasksCompleted;
	vector<QThread*> workers;
	bool inProgress;
	void BruteForce();
	void FirstCantBeZero();
	void EqualLastVariable();
	void HasVariableValue();
	Variable& GetVariable(char name);
	VariablesGroup& GetGroup(string name);
public:
	void AddExpression(const Expression& exp);
	void Optimize(function<void(size_t)> optimizationRound, function<void(string, size_t)> onOptFuncComplete);
	void Run();
	const vector<Variable*>& Variables() const;
	const vector<VariablesGroup*>& Groups() const;
	const vector<Expression>& Expressions() const;
	size_t IterationNeeded() const;
	void Reset();
signals:
	void Solved(const vector<Variable*> vars);
	void Completed();
public slots:
	void TaskSolved(const vector<Variable*> vars);
	void TaskCompleted();
};
