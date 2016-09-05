#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include<newwindow.h>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
       void openNewWindow();
private:
       NewWindow *mMyNewWindow;

private slots:
    void on_login_pushButton_clicked();

    void on_commandLinkButton_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
