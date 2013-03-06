#ifndef DIALOG_COM_H
#define DIALOG_COM_H

#include <QDialog>
#include <QSettings>
#include <QDebug>

namespace Ui {
    class Dialog_com;
}

class Dialog_com : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_com(QWidget *parent = 0);
    ~Dialog_com();
    Ui::Dialog_com *ui;
private:


private slots:
    void on_buttonBox_accepted();
};

#endif // DIALOG_COM_H
