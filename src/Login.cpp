#include <QWidget>
#include "../include/Login.h"
#include "ui_Login.h"

Login::Login(QWidget* parent)
        : QWidget(parent), ui(new Ui::Login) {
    ui->setupUi(this);
}

Login::~Login() {
    delete ui;
}

void Login::on_loginButton_clicked() {
    // auto username = ui->usernameField->text();
    // auto password = ui->passwordField->text();

//    if (username == "admin" && password == "1234") {
        emit loginSuccess();
//    } else {
//        ui->statusLabel->setText("The username or password is incorrect.");
//    }
}
