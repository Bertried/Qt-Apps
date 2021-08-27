#ifndef WIDGET_H
#define WIDGET_H
#define CLASSNAME_INVALID_MESSAGE "The Class name is INVALID \n Admitted characters : (A-Z) , \'_\'"
#define CLASSNAME_EMPTY_MESSAGE "Enter atleast a name for the class"

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_quitButton_clicked();

    void on_genererButton_clicked();

    void on_nomLineEdit_textChanged(const QString &arg1);

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
