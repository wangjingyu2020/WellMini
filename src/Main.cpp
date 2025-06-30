#include <QApplication>
#include "../include/MainWindow.h"
#include "../include/TrayManager.h"
#include "../include/ActivityMonitor.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    ActivityMonitor* monitor = new ActivityMonitor();
    app.installEventFilter(monitor);

    MainWindow* mainWin = new MainWindow(monitor);

    TrayManager* tray = new TrayManager(mainWin);

    tray->showTray();
    mainWin->show();

    return app.exec();
}
