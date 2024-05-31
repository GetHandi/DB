#include "formmenu.h"
#include "mainwindow.h"
#include "ui_formmenu.h"

FormMenu::FormMenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormMenu)
{
    ui->setupUi(this);
}

FormMenu::~FormMenu()
{
    delete ui;
}

void FormMenu::on_carButton_clicked()
{
    // Получаем указатель на главное окно
    MainWindow* mainWindow = qobject_cast<MainWindow*>(this->window());

    if (mainWindow) {
        mainWindow->showCarForm(); // Создайте функцию showCarForm() в классе MainWindow для переключения на форму formCar
    }
}

void FormMenu::on_pushButton_2_clicked()
{
    // Получаем указатель на главное окно
    MainWindow* mainWindow = qobject_cast<MainWindow*>(this->window());

    if (mainWindow) {
        mainWindow->showClientForm(); // Создайте функцию showCarForm() в классе MainWindow для переключения на форму formCar
    }
}

