#ifndef FORMMENU_H
#define FORMMENU_H

#include <QWidget>

namespace Ui {
class FormMenu;
}

class FormMenu : public QWidget
{
    Q_OBJECT

public:
    explicit FormMenu(QWidget *parent = nullptr);
    ~FormMenu();

private:
    Ui::FormMenu *ui;

private slots:
    void on_carButton_clicked();
    void on_pushButton_2_clicked();
};

#endif // FORMMENU_H
