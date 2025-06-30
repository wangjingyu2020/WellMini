#include "../include/ReminderDialog.h"
#include "ui_reminderdialog.h"


ReminderDialog::ReminderDialog(QWidget* parent)
        : QDialog(parent), ui(new Ui::ReminderDialog) {
    ui->setupUi(this);
    setWindowFlags(Qt::Dialog | Qt::WindowStaysOnTopHint);
    connect(ui->btnLater, &QPushButton::clicked, this, &ReminderDialog::onBtnLaterClicked);
    connect(ui->btnOk, &QPushButton::clicked, this, &QDialog::accept);
}

ReminderDialog::~ReminderDialog() {
    delete ui;
}

bool ReminderDialog::postponeRequested() const {
    return postpone;
}

void ReminderDialog::onBtnLaterClicked() {
    postpone = true;
    accept();
}

