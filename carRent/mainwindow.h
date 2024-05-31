
#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include "formmenu.h"
#include "formcar.h"
#include "formclient.h"
#include <QMainWindow>
#include <QStackedWidget>
#include <QtSql>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow

{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void showCarForm();

    void showMenuForm();

    void showClientForm();

    void dbINSERT(const QString &tableName, const QStringList &columnNames, const QStringList &columnValues);

private:
    Ui::MainWindow *ui; // Указатель на объект класса Ui::MainWindow

    QStackedWidget *stackedWidget; // Указатель на объект класса QStackedWidget для управления экранами
    FormMenu *formMenu; // Указатель на объект класса FormMenu для работы с экраном меню
    FormCar *formCar; // Указатель на объект класса FormCar для работы с экраном машины
    FormClient *formClient; // Указатель на объект класса FormClient для работы с экраном клиента

    QSqlDatabase dbConnection; // Объект класса QSqlDatabase для работы с базой данных

};

#endif // MAINWINDOW_H

