
#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this); // Установка пользовательского интерфейса в окне MainWindow

    stackedWidget = new QStackedWidget; // Выделение памяти для QStackedWidget
    formMenu = new FormMenu; // Создание объекта FormMenu
    formCar = new FormCar; // Создание объекта FormCar
    formClient = new FormClient; // Создание объекта FormClient

    stackedWidget->addWidget(formMenu);
    stackedWidget->addWidget(formCar);
    stackedWidget->addWidget(formClient);

    stackedWidget->setCurrentIndex(0); // Переключение на главное меню (индекс 0)
    setCentralWidget(stackedWidget);

    dbConnection = QSqlDatabase::addDatabase("QSQLITE");
    dbConnection.setDatabaseName("./carRent.db");
    if (dbConnection.open())
    {
        qDebug() << "Databse is connected.";
    }
    else
    {
        qDebug() << "Databse is not connected.";
        qDebug() << "Error: " << dbConnection.lastError();
    }

}

void MainWindow::showMenuForm()
{
    stackedWidget->setCurrentWidget(formMenu); // Переключение на форму formMenu
}

void MainWindow::showCarForm()
{
    stackedWidget->setCurrentWidget(formCar); // Переключение на форму formCar
}

void MainWindow::showClientForm()
{
    stackedWidget->setCurrentWidget(formClient); // Переключение на форму formCar
}

void MainWindow::dbINSERT(const QString &tableName, const QStringList &columnNames, const QStringList &columnValues)
{
    dbConnection.open();
    QSqlDatabase::database().transaction();

    QString columns = columnNames.join(", ");
    QStringList valuePlaceholders;
    for (int i = 0; i < columnNames.size(); ++i) {
        valuePlaceholders << QString(":Value_%1").arg(i);
    }
    QString values = valuePlaceholders.join(", ");

    QSqlQuery queryInsertData(dbConnection);
    QString queryString = QString("INSERT INTO %1(%2) VALUES(%3)").arg(tableName, columns, values);
    queryInsertData.prepare(queryString);

    for (int i = 0; i < columnNames.size(); ++i) {
        queryInsertData.bindValue(QString(":Value_%1").arg(i), columnValues.at(i));
    }

    if (!queryInsertData.exec()) {
        // Обработка ошибок
    }

    QSqlDatabase::database().commit();
    dbConnection.close();
}

MainWindow::~MainWindow()
{
//    delete formMenu; // Освобождение памяти, занятой formMenu
//    delete formCar; // Освобождение памяти, занятой formCar
//    delete formClient; // Освобождение памяти, занятой formClient
//    delete stackedWidget; // Освобождение памяти, занятой stackedWidget
    delete ui; // Освобождение памяти, занятой ui
}


