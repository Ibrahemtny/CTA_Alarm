#include "preferencesmanager.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

PreferencesManager::PreferencesManager() {
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("cta_app.db");
}

PreferencesManager::~PreferencesManager() {
    db.close();
}

bool PreferencesManager::createTable() {
    if (!db.open()) {
        qDebug() << "Error opening database: " << db.lastError();
        return false;
    }

    QSqlQuery query;
    query.exec("CREATE TABLE IF NOT EXISTS preferences (station TEXT, line TEXT, notification_time INT)");

    return true;
}

bool PreferencesManager::savePreferences(QString station, QString line, int notificationTime) {
    QSqlQuery query;
    query.prepare("INSERT INTO preferences (station, line, notification_time) VALUES (:station, :line, :notification_time)");
    query.bindValue(":station", station);
    query.bindValue(":line", line);
    query.bindValue(":notification_time", notificationTime);

    if (!query.exec()) {
        qDebug() << "Error saving preferences: " << query.lastError();
        return false;
    }

    return true;
}

QList<QString> PreferencesManager::loadUserPreferences() {
    QList<QString> preferences;
    QSqlQuery query("SELECT * FROM preferences");

    while (query.next()) {
        QString station = query.value(0).toString();
        QString line = query.value(1).toString();
        int notificationTime = query.value(2).toInt();
        preferences.append(station + " - " + line);
    }

    return preferences;
}
