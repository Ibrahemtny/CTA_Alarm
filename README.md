# CTA_Alarm

**Your Personal CTA Transit Tracker**  
CTA_Alarm is your go-to app for real-time transit notifications, keeping you updated on bus and train arrivals in Chicago. Whether you're commuting to work or running errands, this app ensures you’re always on time by notifying you about upcoming transit arrivals right when you need it.

---

### Key Features

- **Real-Time Transit Alerts** (Pending CTA API): Once fully integrated, the app will fetch **live** data about upcoming train and bus arrivals, ensuring you always know when your ride is coming.
- **Customizable Notifications**: Set the notification time based on your preference, whether it’s 5, 10, or 15 minutes before the arrival time. 
- **Machine Learning Predictions**: This feature will predict delays using historical data and train patterns. Right now, we're simulating this with basic logic, but when fully implemented, it will use real-time data and machine learning models for accurate predictions.
- **User Preferences**: Save your favorite stations and routes, so you never have to enter them again. Your preferences are stored in a local SQLite database for persistence.
- **Offline Mode**: No internet? No problem! The app will continue to work offline, using locally cached data to keep you updated.
- **Voice Notifications**: Don’t want to look at your screen? Let the app read your notifications aloud using text-to-speech.
- **Light/Dark Mode**: Customize your app’s look by toggling between light and dark themes for a smoother experience.
- **Notification Sounds & Vibration**: Get notified with custom sounds or vibrations so you never miss a reminder.

---

### About the CTA API

This app is designed to pull **real-time** data directly from the **Chicago Transit Authority (CTA)** API, but **API integration is still pending**. Here's a breakdown of what that will bring to the table once it’s in place:

- **Real-Time Arrival Data**: The app will dynamically fetch the next arrival time for buses and trains at your selected station. No more guesswork!
- **Predicted Delays**: Using **historical transit data**, the app will be able to predict delays and give you timely alerts, so you know if your bus or train is running late.
- **Stations & Lines Data**: The CTA API will provide a comprehensive list of stations and transit lines, which will be used to populate the app’s dropdowns and allow you to easily select the station and line you want to track.
- **Upcoming Features**: With the API, we plan to integrate machine learning to improve delay predictions, which will analyze patterns in arrival times and external factors (e.g., weather, time of day, historical delays) to give you better accuracy.

Currently, this app is simulating the CTA data with hardcoded values, so once the API is connected, you'll get **live, up-to-the-minute updates**.

---


### Installation & Setup

 **Clone the repo**:

```bash
git clone https://github.com/Ibrahemtny/CTA_Alarm.git
cd CTA_Alarm

# CTA_Alarm

## Open in Qt Creator:
1. Launch Qt Creator and click **Open Project**.
2. Select the `CTA_Alarm.pro` file from the repo directory.

## Get Your CTA API Key:
For real-time data, you'll need to get an API key from the [CTA Developer Portal](https://developer.transitchicago.com/).
1. Replace `"YOUR_API_KEY"` in the app code with your personal API key (found in `notificationapp.cpp`).

## Build & Run:
1. In Qt Creator, click **Build** to compile the app.
2. Once compiled, click **Run** to launch the app.

**Note**: As of now, the API is not yet integrated, so the app will simulate arrival data using hardcoded values. When the API is live, the app will automatically pull live data.

## How Does the App Work?

### Step 1: Select your station and line
Choose the station (e.g., “Station A”) and the transit line (e.g., “Red Line”) from the dropdowns.

### Step 2: Set your notification time
Decide how far in advance you want to be notified. Options include 5, 10, or 15 minutes before the next arrival.

### Step 3: Notifications
Once the app receives the arrival data (or simulated data for now), it will send you a notification. You can even have it read aloud using text-to-speech!

## Offline Mode
If you're not connected to the internet, don’t worry! The app can still show data from previous sessions through local caching.

## Voice Notifications & Themes

### Voice Notifications:
Use Qt’s `QTextToSpeech` module to make the app speak your notifications. It’s perfect for hands-free operation.

### Light/Dark Mode:
You can switch between light mode (default) and dark mode based on your preference. Toggle between the two with a button in the settings.

## Offline Data Caching
Even if you're offline, CTA_Alarm will still function! It stores your recent transit data in a local SQLite database, so you can still track stations and routes, even when your connection is down.



Ibrahem Tamimi - Developer


## License
This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details.

