#ifndef WELLMINI_LOGIN_H
#define WELLMINI_LOGIN_H

#pragma once

#include <QWidget>

namespace Ui {
    class Login;
}

class Login : public QWidget {
Q_OBJECT

public:
    explicit Login(QWidget* parent = nullptr);
    ~Login();

signals:
    void loginSuccess();

private:
    Ui::Login* ui;

private slots:
    void on_loginButton_clicked();
};



#endif //WELLMINI_LOGIN_H
