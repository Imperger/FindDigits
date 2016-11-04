#include "finddigits.h"

FindDigits::FindDigits(QWidget *parent)
	: QMainWindow(parent),
	groupValidator(new QRegExpValidator(QRegExp("[a-jA-J]{0,5}"), this)),
	isSolved(false)
{
	ui.setupUi(this);
	QRegExp labelOperator("e\\dop");
	groupsEdits.reserve(9);
	for (size_t itemIndex = 0; itemIndex < ui.expressionsGrid->count(); ++itemIndex)
	{
		if (QLineEdit* lineEdit = qobject_cast<QLineEdit*>(ui.expressionsGrid->itemAt(itemIndex)->widget()))
		{
			lineEdit->setValidator(groupValidator);
			QObject::connect(lineEdit, SIGNAL(textChanged(const QString)), this, SLOT(toUpper(const QString)));
			QObject::connect(lineEdit, SIGNAL(textChanged(const QString)), this, SLOT(overallValidation(const QString)));
			groupsEdits.push_back(lineEdit);
		}
		else if (QLabel* label = qobject_cast<QLabel*>(ui.expressionsGrid->itemAt(itemIndex)->widget()))
		{
			if(labelOperator.exactMatch(label->objectName()))
				QObject::connect(label, SIGNAL(linkActivated(const QString)), this, SLOT(invertOperator(const QString)));
		}
	}

	QObject::connect(ui.solveButton, SIGNAL(clicked()), this, SLOT(solveButtonOnClick()));

	QObject::connect(&comp, SIGNAL(Solved(const vector<Variable*>)), this, SLOT(solved(const vector<Variable*>)));
	QObject::connect(&comp, SIGNAL(Completed()), this, SLOT(completed()));


	QObject::connect(ui.logList->model(), SIGNAL(rowsInserted(const QModelIndex&, int, int)), this, SLOT(scrollToBottom(const QModelIndex&, int, int)));

	QObject::connect(ui.open, SIGNAL(triggered()), this, SLOT(openAction()));
}
void FindDigits::toUpper(const QString& text)
{
	if (QLineEdit* lineEdit = qobject_cast<QLineEdit*>(QObject::sender()))
		lineEdit->setText(text.toUpper());
}
void FindDigits::overallValidation(const QString& text)
{
	ui.solveButton->setEnabled(!any_of(groupsEdits.begin(), groupsEdits.end(), [](const QLineEdit* g) {return g->text().isEmpty(); }));
}
void FindDigits::invertOperator(const QString& text)
{
	QLabel* label = qobject_cast<QLabel*>(QObject::sender());
	setLabelOperator(label, !label->property("operator").toBool());
}
void FindDigits::solveButtonOnClick()
{
	solvedTimer.start();

	if (QPushButton* button = qobject_cast<QPushButton*>(QObject::sender()))
		button->setEnabled(false);

	isSolved = false;

	comp.Reset();
	resetUI();

	auto g = ui.e1g1->text();
	comp.AddExpression(Expression(QString("%1%2%3=%4").
		arg(ui.e1g1->text(), ui.e1op->property("operator").toBool()? "+": "-", ui.e1g2->text(), ui.e1g3->text()).toUtf8().constData()));

	comp.AddExpression(Expression(QString("%1%2%3=%4").
		arg(ui.e2g1->text(), ui.e2op->property("operator").toBool() ? "+" : "-", ui.e2g2->text(), ui.e2g3->text()).toUtf8().constData()));

	comp.AddExpression(Expression(QString("%1%2%3=%4").
		arg(ui.e3g1->text(), ui.e3op->property("operator").toBool() ? "+" : "-", ui.e3g2->text(), ui.e3g3->text()).toUtf8().constData()));


	comp.AddExpression(Expression(QString("%1%2%3=%4").
		arg(ui.e1g1->text(), ui.e4op->property("operator").toBool() ? "+" : "-", ui.e2g1->text(), ui.e3g1->text()).toUtf8().constData()));

	comp.AddExpression(Expression(QString("%1%2%3=%4").
		arg(ui.e1g2->text(), ui.e5op->property("operator").toBool() ? "+" : "-", ui.e2g2->text(), ui.e3g2->text()).toUtf8().constData()));

	comp.AddExpression(Expression(QString("%1%2%3=%4").
		arg(ui.e1g3->text(), ui.e6op->property("operator").toBool() ? "+" : "-", ui.e2g3->text(), ui.e3g3->text()).toUtf8().constData()));

	ui.logList->addItem(QString(u8"Необходимо итераций: %1").arg(comp.IterationNeeded()));
	ui.logList->addItem(u8"Оптимизация: ");

	comp.Optimize([this](size_t round)
	{
		ui.logList->addItem(QString(u8"Раунд: %1").arg(round));
	}, [this](string funcName, size_t prev)
	{
		ui.logList->addItem(QString(u8"%1 %2 (%3)").arg(QString(funcName.c_str()), QString::number(comp.IterationNeeded()), QString::number(static_cast<long long>(comp.IterationNeeded() - prev))));
	});

	comp.Run();
}
void FindDigits::solved(const vector<Variable*> vars)
{
	isSolved = true;
	const char firstChar = 'A';
	for (char labelId = firstChar; labelId < firstChar + vars.size(); ++labelId)
	{
		findChild<QLabel*>(QString("label%1").arg(labelId))->setText(QString("%1=%2").arg(QString(labelId), QString::number((*find_if(vars.begin(), vars.end(), [&labelId](const Variable* v) {return v->Name() == labelId; }))->Value())));
	}
}
void FindDigits::completed()
{
	ui.logList->addItem(QString(u8"Время выполнения: %1 мс").arg(solvedTimer.elapsed()));
	if (isSolved)
		ui.logList->addItem(u8"Решено...");
	else
		ui.logList->addItem(u8"Решение не найдено...");

	ui.solveButton->setEnabled(true);

}
void FindDigits::scrollToBottom(const QModelIndex & parent, int start, int end)
{
	ui.logList->scrollToBottom();
}
void FindDigits::openAction()
{
	QFileDialog dialog(this);
	if (dialog.exec())
		load(dialog.selectedFiles().at(0));
}
void FindDigits::setLabelOperator(QLabel* target, bool op)
{
	if (target == nullptr)
		return;

	const QString plus = "#plus";
	const QString minus = "#minus";
	const QString link = "<a style=\"text-decoration:none; color:black\"  href=\"%1\">%2</a>";

	target->setText(op ? link.arg(plus, "+") : link.arg(minus, "-"));
	target->setProperty("operator", op);
}
void FindDigits::load(QString filename)
{
	QFile inputFile(filename);
	QRegExp expression("([A-J]{1,5})([+-])([A-J]{1,5})=([A-J]{1,5})");
	if (inputFile.open(QIODevice::ReadOnly))
	{
		QTextStream in(&inputFile);
		const size_t HORIZONTAL_EXP_COUNT = 3;
		const size_t TOTAL_EXP_COUNT = 6;
		for (size_t e = 1; e <= HORIZONTAL_EXP_COUNT && !in.atEnd(); ++e)
		{
			if (expression.exactMatch(in.readLine()))
			{
				findChild<QLineEdit*>(QString("e%1g1").arg(e))->setText(expression.cap(1));

				setLabelOperator(findChild<QLabel*>(QString("e%1op").arg(e)), expression.cap(2) == "+");

				findChild<QLineEdit*>(QString("e%1g2").arg(e))->setText(expression.cap(3));
				findChild<QLineEdit*>(QString("e%1g3").arg(e))->setText(expression.cap(4));
			}
		}
		for (size_t e = HORIZONTAL_EXP_COUNT + 1; e <= TOTAL_EXP_COUNT && !in.atEnd(); ++e)
		{
			if (expression.exactMatch(in.readLine()))
			{
				setLabelOperator(findChild<QLabel*>(QString("e%1op").arg(e)), expression.cap(2) == "+");
			}
		}
		inputFile.close();
	}
}
void FindDigits::resetUI()
{
	ui.labelA->setText("A= ?");
	ui.labelB->setText("B= ?");
	ui.labelC->setText("C= ?");
	ui.labelD->setText("D= ?");
	ui.labelE->setText("E= ?");
	ui.labelF->setText("F= ?");
	ui.labelG->setText("G= ?");
	ui.labelH->setText("H= ?");
	ui.labelI->setText("I= ?");
	ui.labelJ->setText("J= ?");

	ui.logList->clear();
}
FindDigits::~FindDigits()
{
	delete groupValidator;
}
