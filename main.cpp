#include "Diplom_Work.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	Diplom_Work process;
	process.InitTable();
	process.InitOpenButtom();
	process.InitDeleteButtom();
	process.InitAddButtom();
	process.InitShablonButtom();
	process.InitArhiveButtom();
	process.InitFindButtom();
	process.show();

	return a.exec();
}
