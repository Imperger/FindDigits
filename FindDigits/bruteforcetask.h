#ifndef BRUTEFORCETASK_H
#define BRUTEFORCETASK_H

#include <QThread>
#include <QObject>

#include <vector>

#include "Variable.h"
#include "VariablesGroup.h"
#include "Expression.h"

class BruteForceTask : public QObject
{
	Q_OBJECT
	QThread workerThread;
public:
	BruteForceTask(const vector<Variable*>& vars, const vector<VariablesGroup*>& groups, const vector<Expression>& expressions, const size_t start, const size_t count, bool& inProgress);
	~BruteForceTask();
private:
	size_t start;
	size_t count;
	bool& inProgress;
	vector<Variable*> vars;
	vector<VariablesGroup*> groups;
	vector<Expression> expressions;
public slots:
	void process();
signals:
	void solved(const vector<Variable*> vars);
	void completed();
	
};

#endif // BRUTEFORCETASK_H
