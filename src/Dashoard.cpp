#include <QAbstractButton>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QDebug>

#include "../include/Dashoard.h"
#include "ui_Dashboard.h"

Dashboard::Dashboard(ActivityMonitor* monitor, QWidget* parent)
        : QWidget(parent), ui(new Ui::Dashboard), monitor(monitor),
          networkManager(new QNetworkAccessManager(this))
{
    ui->setupUi(this);

    // Initialize real-time activity chart
    chart = new ActivityChart(monitor, this);
    ui->chartLayout->addWidget(chart);

    // Connect sync button to request handler
    connect(ui->syncButton, &QPushButton::clicked,
            this, &Dashboard::onSyncButtonClicked);

    // Handle incoming historical data response
    connect(networkManager, &QNetworkAccessManager::finished,
            this, &Dashboard::onHistoryDataReceived);

    // Update status label every 10 seconds
    statusTimer = new QTimer(this);
    connect(statusTimer, &QTimer::timeout, this, &Dashboard::updateStatusLabel);
    statusTimer->start(10'000);
}

Dashboard::~Dashboard() {
    delete ui;
}

void Dashboard::onSyncButtonClicked() {
    QUrl url("http://localhost:8080/api/Activity/history");
    QNetworkRequest request(url);
    networkManager->get(request);
}

void Dashboard::onHistoryDataReceived(QNetworkReply* reply) {
    if (reply->error() != QNetworkReply::NoError) {
        qDebug() << "Network request failed:" << reply->errorString();
        ui->historyList->addItem(" Request failed: " + reply->errorString());
        reply->deleteLater();
        return;
    }

    QJsonDocument doc = QJsonDocument::fromJson(reply->readAll());
    QJsonArray arr = doc.array();

    ui->historyList->clear();
    for (const QJsonValue& val : arr) {
        qDebug() << val;

        QJsonObject obj = val.toObject();
        QString date = obj["date"].toString();
        int mins = obj["activeMinutes"].toInt();
        QString item = QString("%1 — %2 minutes active").arg(date).arg(mins);
        ui->historyList->addItem(item);
    }

    reply->deleteLater();
}

void Dashboard::updateStatusLabel() {
    int mins = monitor->totalActiveSeconds() / 60;
    ui->statusLabel->setText(QString("Active this session: %1 minutes").arg(mins));
}
