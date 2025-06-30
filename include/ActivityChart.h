#ifndef WELLMINI_ACTIVITYCHART_H
#define WELLMINI_ACTIVITYCHART_H

#pragma once

#include <QChartView>
#include <QLineSeries>
#include <QTimer>
#include "../include/ActivityMonitor.h"

class ActivityChart : public QChartView {
Q_OBJECT

public:
    explicit ActivityChart(ActivityMonitor* monitor, QWidget* parent = nullptr);

private slots:
    void updateChart();

private:
    QLineSeries* m_series;
    ActivityMonitor* m_monitor;
    QTimer* m_timer;
    int m_elapsedSeconds = 0;
};


#endif //WELLMINI_ACTIVITYCHART_H
