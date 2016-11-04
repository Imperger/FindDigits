#ifndef FINDDIGITS_H
#define FINDDIGITS_H

#include <QtWidgets/QMainWindow>
#include <QElapsedTimer>
#include <QFileDialog>

#include "ui_finddigits.h"

#include "Computer.h"

class FindDigits : public QMainWindow
{
	Q_OBJECT

public:
	FindDigits(QWidget *parent = 0);
	~FindDigits();
public slots:
	void toUpper(const QString& text);
	void overallValidation(const QString& text);
	void invertOperator(const QString& text);
	void solveButtonOnClick();
	void solved(const vector<Variable*> vars);
	void completed();
	void scrollToBottom(const QModelIndex & parent, int start, int end);
	void openAction();
private:
	QElapsedTimer solvedTimer;
	bool isSolved;
	QVector<QLineEdit*> groupsEdits;
	Computer comp;
	Ui::FindDigitsClass ui;
	QRegExpValidator* groupValidator;
	void setLabelOperator(QLabel* target, bool op);
	void load(QString filename);
	void resetUI();
};

#endif // FINDDIGITS_H
