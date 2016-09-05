#include "database.h"
#include <iostream>

using namespace std;

// Constructor
Database::Database()
{

    // Creates application configuration directory.
    QString configDir = QDir::homePath() + "/." + qApp->applicationName().replace(" ", "").toLower();

    QDir qDir;

    if (! qDir.exists(configDir))
        qDir.mkpath(configDir);

    // Connects with the databases
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName(configDir + "/database.sqlite");
    database.open();

}

// Destructor
Database::~Database()
{
    database.close();
}

// Executes a query and returns the results set.
QSqlQuery Database::execute(QString query)
{
    cout << "QUERY  : " << query.toStdString() << "\nOUTPUT :" << endl;

    QSqlQuery results = database.exec(query);

    database.commit();

    return results;
}

// Executes a query and prints the results.
void Database::executeAndPrint(QString query)
{

    cout << "QUERY  : " << query.toStdString() << "\nOUTPUT :" << endl;

    QSqlQuery results = execute(query);

    results.next();  // Moves the pointer to the first record.

    int columnCount = results.record().count();

    do {

        for(int i = 0; i < columnCount; i++){
             std::cout << results.value(i).toString().toStdString() << " ";
       }

       cout << endl;

    } while (results.next());

}
