#include "ctaapi.h"
#include <QList>
#include <QDebug>

CTAApi::CTAApi() {}
CTAApi::~CTAApi() {}

QList<QString> CTAApi::getRealTimeArrivals(QString station, QString line) {
    // Here, you'll fetch real-time CTA data from an API (e.g., REST API)
    // For now, we return static values
    QList<QString> arrivals;
    if (line == "Red Line" && station == "Station A") {
        arrivals << "10:00 AM" << "10:05 AM";
    }
    return arrivals;
}
