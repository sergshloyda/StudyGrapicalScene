#include "studygraphicsscene.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	StudyGraphicsScene w;
	w.show();
	return a.exec();
}