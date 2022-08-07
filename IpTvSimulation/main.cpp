#include <QApplication>
#include "MainWindow.h"
#include "SimpleLogger.h"

//#include "Paths.h"
//#include "ChannelView.h"

int main(int argc, char** argv)
{
	QApplication app(argc, argv);
	MainWindow w{};
	w.show();
	return app.exec();
}
