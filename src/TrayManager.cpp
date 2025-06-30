#include "../include/TrayManager.h"
#include "../include/MainWindow.h"
#include "../include/ReminderDialog.h"
#include <QMenu>
#include <QAction>
#include <QApplication>
#include <QTimer>
#include <QDialog>



TrayManager::TrayManager(MainWindow* mainWin, QObject* parent)
        : QObject(parent), mainWindow(mainWin) {


    reminderTimer = new QTimer(this);
    reminderTimer->start(1000 * 60);

    connect(reminderTimer, &QTimer::timeout, this, [=]() {
        ReminderDialog dialog(mainWindow);
        if (dialog.exec() == QDialog::Accepted && dialog.postponeRequested()) {
            reminderTimer->start(1000 * 30);
        } else {
            reminderTimer->start(1000 * 60);
        }
    });



    trayIcon = new QSystemTrayIcon(QIcon(":/resources/logo.png"), this);
    trayIcon->setToolTip("WellMini is running");

    connect(trayIcon, &QSystemTrayIcon::activated, this, [=](QSystemTrayIcon::ActivationReason reason) {
        if (reason == QSystemTrayIcon::DoubleClick) {
            toggleMainWindow();
        }
    });

    trayMenu = new QMenu();

    QAction* toggleAction = new QAction("show / hide main window", this);
    connect(toggleAction, &QAction::triggered, this, &TrayManager::toggleMainWindow);

    QAction* quitAction = new QAction("exit", this);
    connect(quitAction, &QAction::triggered, this, &TrayManager::quitApp);

    trayMenu->addAction(toggleAction);
    trayMenu->addSeparator();
    trayMenu->addAction(quitAction);

    trayIcon->setContextMenu(trayMenu);
    trayIcon->show();
}


void TrayManager::toggleMainWindow() {
    if (mainWindow->isVisible()) {
        mainWindow->hide();
    } else {
        mainWindow->showNormal();
        mainWindow->raise();
        mainWindow->activateWindow();
    }
}

void TrayManager::quitApp() {
    trayIcon->hide();
    QApplication::quit();
}

void TrayManager::showTray() {
    trayIcon->show();
}
