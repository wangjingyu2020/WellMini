#pragma once

#include <QObject>
#include <QSystemTrayIcon>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
    class QMenu;
    class MainWindow;
}
QT_END_NAMESPACE

#pragma once
#include <QObject>
#include <QSystemTrayIcon>

class QMenu;
class MainWindow;

class TrayManager : public QObject {
Q_OBJECT
public:
    explicit TrayManager(MainWindow* mainWin, QObject* parent = nullptr);
    void showTray();


private slots:
    void toggleMainWindow();
    void quitApp();

private:
    QSystemTrayIcon* trayIcon;
    QMenu* trayMenu;
    MainWindow* mainWindow;
    QTimer* reminderTimer = nullptr;

};
