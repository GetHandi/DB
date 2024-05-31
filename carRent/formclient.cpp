#include "formclient.h"
#include "mainwindow.h"
#include "ui_formclient.h"

FormClient::FormClient(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormClient)
{
    ui->setupUi(this);
}

FormClient::~FormClient()
{
    delete ui;
}

void FormClient::on_toMenuFromClientButton_clicked()
{
    foreach (QLineEdit* lineEdit, this->findChildren<QLineEdit*>()) {
        lineEdit->clear();
    }
    MainWindow* mainWindow = qobject_cast<MainWindow*>(this->window());
    if (mainWindow) {
        mainWindow->showMenuForm(); // Добавьте функцию showMenuForm() в класс MainWindow для переключения на форму formMenu
    }
}


void FormClient::on_addClientButton_clicked()
{
    QStringList columnValues;
    foreach (QLineEdit* lineEdit, this->findChildren<QLineEdit*>()) {
        columnValues << lineEdit->text();
    }
    qDebug() << columnValues;
    QStringList columnNames;
    foreach (QLabel* label, this->findChildren<QLabel*>()) {
        columnNames << label->text();
    }
    qDebug() << columnNames;
    MainWindow* mainWindow = qobject_cast<MainWindow*>(this->window());
    if (mainWindow) {
        mainWindow->dbINSERT("clients", columnNames, columnValues);
    }
}

