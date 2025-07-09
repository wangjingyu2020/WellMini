#pragma once
#include <QDialog>

namespace Ui {
    class ReminderDialog;
}

class ReminderDialog : public QDialog {
Q_OBJECT

public:
    explicit ReminderDialog(QWidget* parent = nullptr);
    ~ReminderDialog();

    bool postponeRequested() const;

private:
    Ui::ReminderDialog* ui;
    bool postpone = false;

private slots:
    void onBtnLaterClicked();
};
