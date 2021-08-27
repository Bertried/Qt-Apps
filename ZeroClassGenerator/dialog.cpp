#include "dialog.h"

Dialog::Dialog( QString &hcode,QString & cppCode, QWidget *parent):QDialog(parent)
{
    QVBoxLayout *verticalLayout = new QVBoxLayout(this);
    verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
    tabs = new QTabWidget(this);
    className = parent->findChild<QLineEdit*>("nomLineEdit")->text();
    createHeaderTab(hcode);
    createCppTab(cppCode);
    verticalLayout->addWidget(tabs);
    setWindowTitle(tr("ZeroClassGenerator"));
    dialogbutton = new QDialogButtonBox(QDialogButtonBox::Save | QDialogButtonBox::Close);
    dialogbutton->button(QDialogButtonBox::Save)->setText(tr("Enregistrer"));
    dialogbutton->button(QDialogButtonBox::Close)->setText(tr("Fermer"));
    verticalLayout->addWidget(dialogbutton);

    QObject::connect(dialogbutton->button(QDialogButtonBox::Close),SIGNAL(clicked()),this,SLOT(reject()));
    QObject::connect(dialogbutton->button(QDialogButtonBox::Save),SIGNAL(clicked()),this,SLOT(save()));
}

Dialog::~Dialog(){}

void Dialog::createHeaderTab(QString &hcode){
    QWidget *headerfile = new QWidget();
    QVBoxLayout *headerLayout = new QVBoxLayout;
    headerLayout->setObjectName(QString::fromUtf8("headerLayout"));
    QTextEdit *textEdit = new QTextEdit;
    textEdit->setObjectName(QString::fromUtf8("hTabTextEdit"));
    textEdit->setText(hcode);
    textEdit->setReadOnly(true);
    headerLayout->addWidget(textEdit);
    headerfile->setLayout(headerLayout);
    tabs->addTab(headerfile,className + ".h");
}

void Dialog::createCppTab(QString &cppCode){
    QWidget *cppfile = new QWidget();
    QVBoxLayout *cppLayout = new QVBoxLayout;
    cppLayout->setObjectName(QString::fromUtf8("cppLayout"));
    QTextEdit *textEdit = new QTextEdit(cppfile);
    textEdit->setObjectName(QString::fromUtf8("cppTabTextEdit"));
    textEdit->setText(cppCode);
    textEdit->setReadOnly(true);
    cppLayout->addWidget(textEdit);
    cppfile->setLayout(cppLayout);
    tabs->addTab(cppfile,className + ".cpp");
}


void Dialog::save(){
    QString ext = tabs->currentIndex() == 0 ? ".h" : ".cpp";
    QString file = QFileDialog::getSaveFileName(this,tr("Enregistrer le fichier"),className + ext);
    QFile newFile(file);
    if(!newFile.open(QIODevice::WriteOnly)){
        QMessageBox::information(this,"Error Message",newFile.errorString());
        return;
    }
    QTextStream stream(&newFile);
    stream << findChild<QTextEdit*>(ext.remove(0,1) + "TabTextEdit")->toPlainText();

}
