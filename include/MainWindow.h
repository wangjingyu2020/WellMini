#pragma once

#include <QMainWindow>
#include <QStackedWidget>
#include "../include/ActivityMonitor.h"

namespace Ui {
class MainWindow;
}

class Login;
class Dashboard;

class MainWindow : public QMainWindow {
Q_OBJECT

public:
    MainWindow(ActivityMonitor* monitor, QWidget* parent = nullptr);
    ~MainWindow();

private:
    QStackedWidget* stackedWidget;
    Login* login;
    Dashboard* dashboard;
    ActivityMonitor *activityMonitor;


    void setupUI();
    void connectSignals();

protected:
    void closeEvent(QCloseEvent *event) override;

};
