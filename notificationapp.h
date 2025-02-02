#ifndef NOTIFICATIONAPP_H
#define NOTIFICATIONAPP_H

#include <QWidget>
#include <QComboBox>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QSqlDatabase>
#include <QTextToSpeech>
#include <QMediaPlayer>
#include <QSystemTrayIcon>
#include <QTimer>
#include "preferencesmanager.h"
#include "ctaapi.h"

class NotificationApp : public QWidget {
    Q_OBJECT

public:
    NotificationApp(QWidget *parent = nullptr);
    ~NotificationApp();

private:
    // UI Elements
    QComboBox *stationCombo, *lineCombo, *timeCombo;
    QPushButton *notifyButton, *themeButton;
    QLabel *headerLabel;

    // Core features
    void sendNotification(QString station, QString line, int minutesBefore);
    void sendVoiceNotification(QString station, QString line, int minutesBefore);
    void playCustomSound(QString soundFile);

    // Theme support
    void setLightTheme();
    void setDarkTheme();

    // Machine Learning Prediction
    int predictDelay(QString line, QString station);

    // Data Persistence
    PreferencesManager *preferencesManager;
    CTAApi *ctaApi;

    // Error Handling
    void handleError(QString errorMsg);

    // Timer for updating predicted delays
    QTimer *delayUpdateTimer;
};

#endif // NOTIFICATIONAPP_H
