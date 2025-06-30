#include "../include/ActivityMonitor.h"
#include <QEvent>

ActivityMonitor::ActivityMonitor(QObject* parent)
        : QObject(parent),
          m_lastActive(QDateTime::currentDateTime()),
          m_tickTimer(new QTimer(this)) {

    connect(m_tickTimer, &QTimer::timeout, this, &ActivityMonitor::onTick);
    m_tickTimer->start(1000);
}

bool ActivityMonitor::eventFilter(QObject* obj, QEvent* event) {
    switch (event->type()) {
        case QEvent::MouseMove:
        case QEvent::KeyPress:
        case QEvent::MouseButtonPress:
            m_lastActive = QDateTime::currentDateTime();
            break;
        default:
            break;
    }
    return QObject::eventFilter(obj, event);
}

void ActivityMonitor::onTick() {
    qint64 diff = m_lastActive.msecsTo(QDateTime::currentDateTime());
    if (diff < 60 * 1000) {
        m_totalActiveSec += 1;
    }
}

bool ActivityMonitor::isActive() const {
    return m_lastActive.msecsTo(QDateTime::currentDateTime()) < 60 * 1000;
}

qint64 ActivityMonitor::totalActiveSeconds() const {
    return m_totalActiveSec;
}