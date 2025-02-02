#include "notificationapp.h"
#include <QComboBox>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QMediaPlayer>
#include <QTextToSpeech>
#include <QSqlQuery>
#include <QSqlError>

NotificationApp::NotificationApp(QWidget *parent)
    : QWidget(parent), preferencesManager(new PreferencesManager()), ctaApi(new CTAApi()) {

    // Initialize UI elements
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    headerLabel = new QLabel("CTA/MTA Notification System", this);
    headerLabel->setAlignment(Qt::AlignCenter);

    stationCombo = new QComboBox(this);
    lineCombo = new QComboBox(this);
    timeCombo = new QComboBox(this);

    // Populate combo boxes with stations, lines, and notification times
    stationCombo->addItem("Station A");
    stationCombo->addItem("Station B");
    lineCombo->addItem("Red Line");
    lineCombo->addItem("Blue Line");
    timeCombo->addItem("3");
    timeCombo->addItem("5");
    timeCombo->addItem("10");

    notifyButton = new QPushButton("Set Notification", this);
    themeButton = new QPushButton("Toggle Theme", this);

    mainLayout->addWidget(headerLabel);
    mainLayout->addWidget(stationCombo);
    mainLayout->addWidget(lineCombo);
    mainLayout->addWidget(timeCombo);
    mainLayout->addWidget(notifyButton);
    mainLayout->addWidget(themeButton);

    // Set light theme initially
    setLightTheme();

    // Connect notify button to setting notifications
    connect(notifyButton, &QPushButton::clicked, this, [this]() {
        QString station = stationCombo->currentText();
        QString line = lineCombo->currentText();
        int minutesBefore = timeCombo->currentText().toInt();

        int predictedDelay = predictDelay(line, station);
        int arrivalTime = 10; // Placeholder, needs real-time fetching
        int delayInSeconds = (arrivalTime - minutesBefore) * 60;

        if (delayInSeconds < 0) {
            handleError("Notification time is after the arrival time!");
            return;
        }

        // Set up notification timer
        QTimer::singleShot(delayInSeconds * 1000, this, [this, station, line, minutesBefore]() {
            sendNotification(station, line, minutesBefore);
            sendVoiceNotification(station, line, minutesBefore);
        });
    });

    // Toggle theme
    connect(themeButton, &QPushButton::clicked, this, [this]() {
        static bool isDark = false;
        if (isDark) {
            setLightTheme();
        } else {
            setDarkTheme();
        }
        isDark = !isDark;
    });
}

NotificationApp::~NotificationApp() {}

void NotificationApp::setLightTheme() {
    this->setStyleSheet("background-color: #f9f9f9; color: black;");
}

void NotificationApp::setDarkTheme() {
    this->setStyleSheet("background-color: #2d2d2d; color: white;");
}

int NotificationApp::predictDelay(QString line, QString station) {
    // Simulate delay prediction based on station/line
    if (line == "Red Line" && station == "Station A") return 5;
    if (line == "Blue Line" && station == "Station B") return 7;
    return 0;
}

void NotificationApp::sendNotification(QString station, QString line, int minutesBefore) {
    QSystemTrayIcon *trayIcon = new QSystemTrayIcon(QIcon(":icon.png"), this);
    trayIcon->show();
    trayIcon->showMessage("Next Arrival", 
        "Your " + line + " at " + station + " will arrive in " + QString::number(minutesBefore) + " minutes!", 
        QSystemTrayIcon::Information, 5000);
}

void NotificationApp::sendVoiceNotification(QString station, QString line, int minutesBefore) {
    QTextToSpeech *speechEngine = new QTextToSpeech(this);
    QString message = "Your " + line + " at " + station + " will arrive in " + QString::number(minutesBefore) + " minutes.";
    speechEngine->say(message);
}

void NotificationApp::playCustomSound(QString soundFile) {
    QMediaPlayer *player = new QMediaPlayer();
    player->setMedia(QUrl::fromLocalFile(soundFile));
    player->setVolume(100);
    player->play();
}

void NotificationApp::handleError(QString errorMsg) {
    QMessageBox::critical(this, "Error", errorMsg);
}
