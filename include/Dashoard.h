#pragma once

#include <QWidget>
#include <QNetworkAccessManager>
#include "../include/ActivityChart.h"

namespace Ui { class Dashboard; }

class Dashboard : public QWidget {
Q_OBJECT

public:
    explicit Dashboard(ActivityMonitor* monitor, QWidget* parent = nullptr);
    ~Dashboard();

private slots:
    void onSyncButtonClicked();
    void onHistoryDataReceived(QNetworkReply* reply);
    void updateStatusLabel();

private:
    Ui::Dashboard* ui;
    ActivityChart* chart;
    ActivityMonitor* monitor;
    QNetworkAccessManager* networkManager;
    QTimer* statusTimer;
};
