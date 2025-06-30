#include <QCloseEvent>
#include "../include/MainWindow.h"
#include "../include/Login.h"
#include "../include/Dashoard.h"
#include "../include/ActivityMonitor.h"

MainWindow::MainWindow(ActivityMonitor* monitor, QWidget* parent)
        : QMainWindow(parent), activityMonitor(monitor) {
    setupUI();
    connectSignals();
}




MainWindow::~MainWindow() = default;

void MainWindow::closeEvent(QCloseEvent* event) {
    if (stackedWidget->currentIndex() == 0) {
        event->accept();
    } else {
        this->hide();
        event->ignore();
    }
}

void MainWindow::setupUI() {
    resize(600, 400);

    stackedWidget = new QStackedWidget(this);
    setCentralWidget(stackedWidget);

    login = new Login(this);
    dashboard = new Dashboard(activityMonitor, this);

    stackedWidget->addWidget(login);
    stackedWidget->addWidget(dashboard);

    stackedWidget->setCurrentIndex(0);
}

void MainWindow::connectSignals() {
    connect(login, &Login::loginSuccess, this, [=]() {
        stackedWidget->setCurrentIndex(1);
    });
}
