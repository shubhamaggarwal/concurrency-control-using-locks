#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<iostream>
#include<dialog.h>
#include<database.h>
#include<QString>
#include<QMessageBox>
using namespace std;
extern Database *data_base;
bool loginfg;
extern bool loginfgpas;
extern QString user1;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->login_pushButton, SIGNAL(click()), this, SLOT(openNewWindow()));//opens a new window
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openNewWindow()
{
    mMyNewWindow = new NewWindow();

    mMyNewWindow->show();

}
void MainWindow::on_login_pushButton_clicked()
{

    bool fg=0;

    user1=ui->textEdit->toPlainText();

    QString pass1=ui->lineEdit->text();

    QSqlQuery que=data_base->execute("Select count(*) from MEMBERS where username=\"" + user1 + "\"and password=\""  + pass1+"\"" );

    que.next();

    int count=que.value(0).toString().toInt();

    if(count==0)
        fg=0;
    else
        fg=1;

    if(!fg)
    {
        QMessageBox::information(this,tr("Login Failed"),tr("Username or Password is incorrect!"));
    }
    else
    {
        if(loginfgpas == 0){
            openNewWindow();
            loginfgpas = 1;
        }
        else
        {
            QMessageBox::information(this,tr("Login Failed"),tr("Another User is already logged in!"));
        }
    }
}


void MainWindow::on_pushButton_clicked()//new user button
{
    user1=ui->textEdit->toPlainText();

    QString pass1=ui->lineEdit->text();

    QString name=ui->lineEdit->text();

    QString amount=ui->textEdit_2->toPlainText();

    QSqlQuery que=data_base->execute("Select count(*) from MEMBERS where username=\"" + user1 + "\"" );

    que.next();

    int count=que.value(0).toString().toInt();

    if(count==0&&loginfgpas==0)
    {

        data_base->execute("insert into MEMBERS values('"+user1+"','"+pass1+"','"+name+"',"+amount+")");
        QMessageBox::information(this,tr("Successful :)"),tr("Registration Successful"));
    }
    else if(loginfgpas==1)
        QMessageBox::information(this,tr("Registration Failed"),tr("Another User is already logged in!"));
    else
        QMessageBox::information(this,tr("Unsuccessful"),tr("Another user with same username already exists!"));
}
