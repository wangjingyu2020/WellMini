#ifndef WELLMINI_ACTIVITYMONITOR_H
#define WELLMINI_ACTIVITYMONITOR_H

#pragma once

#include <QObject>
#include <QDateTime>
#include <QTimer>

class ActivityMonitor : public QObject {
Q_OBJECT

public:
    explicit ActivityMonitor(QObject* parent = nullptr);
    bool isActive() const;
    qint64 totalActiveSeconds() const;

protected:
    bool eventFilter(QObject* obj, QEvent* event) override;

private slots:
    void onTick();

private:
    QDateTime m_lastActive;
    qint64 m_totalActiveSec = 0;
    QTimer* m_tickTimer;
};

#endif //WELLMINI_ACTIVITYMONITOR_H
