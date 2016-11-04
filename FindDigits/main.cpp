#include "finddigits.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	FindDigits w;
	w.show();
	return a.exec();
}
