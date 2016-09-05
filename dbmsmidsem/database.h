#ifndef DATABASE_H
#define DATABASE_H

#include <QtSql>
#include <QApplication>
#include <QDir>
#include <QString>

class Database
{
private:
    QSqlDatabase database;

public:
    Database();
    ~Database();

    // Executes a query and returns the results set.
    QSqlQuery execute(QString query);

    // Executes a query and prints the results.
    void executeAndPrint(QString query);
};
extern Database *data_base;
#endif // DATABASE_H
