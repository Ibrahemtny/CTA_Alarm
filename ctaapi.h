#ifndef CTAAPI_H
#define CTAAPI_H

#include <QString>
#include <QList>

class CTAApi {
public:
    CTAApi();
    ~CTAApi();

    QList<QString> getRealTimeArrivals(QString station, QString line);
};

#endif // CTAAPI_H
