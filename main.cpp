#include "ecrmanagementsystem.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	ECRManagementSystem w;
	w.show();
	return a.exec();
}
