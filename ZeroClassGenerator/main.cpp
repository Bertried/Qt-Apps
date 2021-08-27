#include "widget.h"

#include <QApplication>
#include <QTranslator>
#include <QDir>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    if(translator.load("ZeroClassGenerator_en.qm","../ZeroClassGenerator")){
        a.installTranslator(&translator);
    }
    Widget w;
    w.show();
    return a.exec();
}
