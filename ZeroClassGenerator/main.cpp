#include "widget.h"

#include <QApplication>
#include <QTranslator>
#include <QDir>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QString locale = QLocale::system().name().section('_',0,0);
    QTranslator translator;
    if(translator.load("ZeroClassGenerator_" + locale + ".qm","../ZeroClassGenerator")){
        a.installTranslator(&translator);
    }
    Widget w;
    w.show();
    return a.exec();
}
