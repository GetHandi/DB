#ifndef FORMCAR_H
#define FORMCAR_H

#include <QWidget>

namespace Ui {
class FormCar;
}

class FormCar : public QWidget
{
    Q_OBJECT

public:
    explicit FormCar(QWidget *parent = nullptr);
    ~FormCar();

private slots:
    void on_toMenuFromCarButton_clicked();

    void on_addCarButton_clicked();

private:
    Ui::FormCar *ui;
};

#endif // FORMCAR_H
