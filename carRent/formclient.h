#ifndef FORMCLIENT_H
#define FORMCLIENT_H

#include <QWidget>

namespace Ui {
class FormClient;
}

class FormClient : public QWidget
{
    Q_OBJECT

public:
    explicit FormClient(QWidget *parent = nullptr);
    ~FormClient();

private slots:
    void on_toMenuFromClientButton_clicked();

    void on_addClientButton_clicked();

private:
    Ui::FormClient *ui;
};

#endif // FORMCLIENT_H
