#include "formcar.h"
#include "mainwindow.h"
#include "ui_formcar.h"

FormCar::FormCar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormCar)
{
    ui->setupUi(this);
}

FormCar::~FormCar()
{
    delete ui;
}

void FormCar::on_toMenuFromCarButton_clicked()
{
    foreach (QLineEdit* lineEdit, this->findChildren<QLineEdit*>()) {
        lineEdit->clear();
    }
    MainWindow* mainWindow = qobject_cast<MainWindow*>(this->window());
    if (mainWindow) {
        mainWindow->showMenuForm(); // Добавьте функцию showMenuForm() в класс MainWindow для переключения на форму formMenu
    }
}


void FormCar::on_addCarButton_clicked()
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
        mainWindow->dbINSERT("cars", columnNames, columnValues);
    }
}

