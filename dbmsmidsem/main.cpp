#include "mainwindow.h"
#include <QApplication>
#include <database.h>
extern bool loginfg;

extern Database *data_base;

using namespace std;

int main(int argc, char *argv[])
{
    loginfg=0;

    QApplication a(argc, argv);

    data_base=new Database();

    data_base->execute("CREATE TABLE MEMBERS (username varchar(50),password varchar(50), NAME VARCHAR(50),BALANCE int)");

    //data_base->execute("insert into MEMBERS values('shubham','shubham','Shubham Aggarwal',32800)");

    MainWindow w;

    w.show();

    //data_base->execute("drop table MEMBERS");

    //delete data_base;

    return a.exec();
}

