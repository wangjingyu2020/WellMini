#include "../include/ActivityChart.h"
#include <QValueAxis>
#include <QDateTime>

ActivityChart::ActivityChart(ActivityMonitor* monitor, QWidget* parent)
        : QChartView(parent), m_monitor(monitor), m_series(new QLineSeries()), m_timer(new QTimer(this)) {

    QChart* chart = new QChart();
    chart->addSeries(m_series);
    chart->legend()->hide();
    chart->setTitle("Real-time Active Minutes");

    QValueAxis* axisX = new QValueAxis();
    axisX->setTitleText("Elapsed Minutes");
    axisX->setLabelFormat("%d");
    axisX->setTickCount(10);
    axisX->setRange(0, 10);

    QValueAxis* axisY = new QValueAxis();
    axisY->setTitleText("Cumulative Active Minutes");
    axisY->setRange(0, 60);

    chart->addAxis(axisX, Qt::AlignBottom);
    chart->addAxis(axisY, Qt::AlignLeft);
    m_series->attachAxis(axisX);
    m_series->attachAxis(axisY);

    setChart(chart);
    setRenderHint(QPainter::Antialiasing);

    connect(m_timer, &QTimer::timeout, this, &ActivityChart::updateChart);
    m_timer->start(5000);
}

void ActivityChart::updateChart() {
    m_elapsedSeconds += 5;
    int x = m_elapsedSeconds / 60;
    int y = m_monitor->totalActiveSeconds() / 60;

    m_series->append(x, y);
    chart()->axes(Qt::Horizontal).first()->setRange(0, x + 1);
}
