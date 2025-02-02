#include <QApplication>
#include <QWidget>
#include <QSystemTrayIcon>
#include <QMessageBox>
#include <QIcon>
#include "notificationapp.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // Set the application icon for the system tray
    QIcon appIcon(":icon.png");
    app.setWindowIcon(appIcon);

    NotificationApp window;
    window.setWindowTitle("CTA/MTA Notification System");
    window.setStyleSheet("background-color: #f4f4f4; font-family: Arial, sans-serif;");
    window.resize(400, 350);
    window.show();

    return app.exec();
}
