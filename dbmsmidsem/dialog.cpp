#include "dialog.h"
#include "ui_dialog.h"
using namespace std;
QString name1,balance;
extern QString username1;
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->label_4->setText(username1);
    ui->label_5->setText(name1);
    ui->label_6->setText(balance);
}

Dialog::~Dialog()
{
    delete ui;
}
