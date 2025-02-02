#ifndef PREFERENCESMANAGER_H
#define PREFERENCESMANAGER_H

#include <QString>
#include <QList>
#include <QSqlDatabase>

class PreferencesManager {
public:
    PreferencesManager();
    ~PreferencesManager();

    bool savePreferences(QString station, QString line, int notificationTime);
    QList<QString> loadUserPreferences();
    bool createTable();

private:
    QSqlDatabase db;
};

#endif // PREFERENCESMANAGER_H
