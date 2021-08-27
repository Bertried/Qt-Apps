#include "widget.h"
#include "ui_widget.h"
#include <QTextStream>
#include <QDialog>
#include <QVBoxLayout>
#include "dialog.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_quitButton_clicked()
{
    QApplication::quit();
}


void Widget::on_genererButton_clicked()
{
    QString hCode ;
    QString name = ui->nomLineEdit->text();
    QString cppCode;

    QRegularExpression regex("([A-Z_])+");
    regex.setPatternOptions(QRegularExpression::CaseInsensitiveOption);
    QRegularExpressionValidator validator(regex,nullptr);
    int pos = 0;
    if(name.isEmpty()){
        QMessageBox::critical(this,"ZeroClassGenerator",CLASSNAME_EMPTY_MESSAGE);
        return;
    }
    if(validator.validate(name,pos) == QValidator::Invalid){
        QMessageBox::critical(this,"ZeroClassGenerator",CLASSNAME_INVALID_MESSAGE);
        return;
    }
    if(ui->comments->isChecked()){
        hCode += "/*\nAuteur : ";
        hCode += ui->auteurLineEdit->text() + "\n";
        hCode += "Date de Création :" + ui->daTeDeCrAtionDateEdit->text();
        hCode += "\nRôle :\n";
        hCode += ui->rlDeLaClasseTextEdit->toPlainText() + "\n" + "*/" ;
        hCode += "\n\n\n";
    }
    if(ui->header->isChecked()){
        hCode += "#ifndef ";
        hCode += ui->defineLineEdit->text() + "\n";
        hCode += "#define " + ui->defineLineEdit->text();
        hCode += "\n\n\n";
    }
    hCode += "class " + name;
    hCode += " : public " + ui->classeMReLineEdit->text();
    hCode += "{\n\t";
    hCode += "public:\n";
    if(ui->constructor->isChecked()){
        hCode += "\t" + name + "();\n";
        cppCode += name + "::" + name;
        cppCode += "(){\n\n}\n\n";
    }
    if(ui->destructor->isChecked()){
        hCode += "\n\t~" + name + "();\n";
        cppCode += name + "::~" + name + "(){\n\n}";
    }
    hCode += "\n\tprotected:\n\n";
    hCode += "\tprivate:\n\n};";
    Dialog dialog(hCode,cppCode,this);
    dialog.exec();
}

void Widget::on_nomLineEdit_textChanged(const QString &arg1)
{
    ui->defineLineEdit->setText(arg1.toUpper() + "_H");
}

