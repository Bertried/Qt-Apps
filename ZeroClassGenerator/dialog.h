#ifndef DIALOG_H
#define DIALOG_H
#include <QtWidgets>


class Dialog : public QDialog
{
    Q_OBJECT
public:
    Dialog(QString &hcode,QString &cppCode, QWidget *parent);
    ~Dialog();

private slots:
    void save();

private:
    QTabWidget *tabs;
    QString className;
    QDialogButtonBox *dialogbutton;
    void createCppTab(QString &cppCode);
    void createHeaderTab(QString &hcode);
};

#endif // DIALOG_H
