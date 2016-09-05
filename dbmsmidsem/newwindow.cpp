#include "newwindow.h"
#include "ui_newwindow.h"
#include<database.h>
#include<dialog.h>
#include<dialog1.h>
#include<iostream>
#include<QMessageBox>
using namespace std;
extern QString name1,balance;
extern QString username1;
extern Database * data_base;
extern QString user1;
bool loginfgpas;
extern bool withdrawlflag;
NewWindow::NewWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::NewWindow)
{
    ui->setupUi(this);
}

NewWindow::~NewWindow()
{
    delete ui;
}

void NewWindow::on_pushButton_2_clicked()//withdrawl
{
    if(withdrawlflag==0)
    {
        withdrawlflag=1;
        Dialog1 dial1;
        dial1.setModal(false);
        dial1.exec();

    }
    else{
      QMessageBox::information(this,tr("Please Wait"),tr("Another Transaction is already in progress"));
    }
}
void NewWindow::on_pushButton_3_clicked()
{
    close();
    loginfgpas=0;
}

void NewWindow::on_pushButton_clicked()//mini statement
{
    cout<<withdrawlflag<<endl;
    if(withdrawlflag==0)
    {
         QSqlQuery que=data_base->execute("select * from MEMBERS where name='"+user1+"'");
         que.next();
         username1=que.value(0).toString();
         name1=que.value(2).toString();
         balance=que.value(3).toString();
         Dialog dial;
         dial.setModal(true);
         dial.exec();
    }
    else{
      QMessageBox::information(this,tr("Please Wait"),tr("Another Transaction is already in progress"));
    }
}
