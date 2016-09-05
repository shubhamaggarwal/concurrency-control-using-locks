#include "dialog1.h"
#include "ui_dialog1.h"
#include<database.h>
#include<QMessageBox>
#include<iostream>
using namespace std;
Database * data_base;
QString username1,user1;
bool withdrawlflag;
Dialog1::Dialog1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog1)
{
    ui->setupUi(this);
}

Dialog1::~Dialog1()
{
    delete ui;
}

void Dialog1::on_pushButton_clicked()
{
    clock_t start;
    double duration;
    start = clock();
    while(1)
    {
        duration=(clock()-start)/(double)CLOCKS_PER_SEC;
        if(duration>1.0){
            withdrawlflag=0;
            break;
        }
    }
    string user=user1.toStdString();

    QSqlQuery quer=data_base->execute("select * from MEMBERS where username=\""+user1+"\"");

    quer.next();

    int balance=quer.value(3).toString().toInt();

    QString bal=ui->textEdit->toPlainText();

    int entered=bal.toInt();

    if(entered>balance)
    {
        QMessageBox::information(this,tr("Message"),tr("Insufficient Balance"));
    }
    else
    {
        int remaining=balance-entered;

        QString newBalance=QString::number(remaining);

        QMessageBox::information(this,tr("Message"),tr("Withdrawl Successful"));

        data_base->execute("update MEMBERS set balance ="+newBalance+" where username=\""+user1+"\"");

        withdrawlflag=0;
    }
}
