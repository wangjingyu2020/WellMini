# WellMini 🌿

**WellMini** is a very basic Qt-based desktop application designed as a starting point for experimenting with core Qt concepts.

✨ Features
⏰ Timed Reminders Periodically prompts users (default: every 1 minute) to take screen breaks and reduce eye strain.

🖥️ System Tray Integration Minimizes to the tray instead of exiting; double-click the tray icon to reopen the application.

🔐 Login Interface Simple login screen before accessing the main interface; defaults to "guest" if left blank.

🗂️ Stacked Page Navigation Manages navigation between login and dashboard using QStackedWidget.

📊 Real-Time Dashboard Displays live keyboard/mouse activity via embedded charts using Qt Charts.

☁️ Cloud Sync via REST API Retrieves historical activity records from an external ASP.NET backend.

🧾 Activity History View Fetched historical records are displayed in a list, with daily summaries of active time.

📦 Tech Stack
UI Framework: Qt 6.x (including Widgets, Charts, and Network modules)

Build System: CMake 3.18 or newer

Language Standard: C++17

Backend Integration: REST API consumed via QNetworkAccessManager

Optional REST Server: Built with ASP.NET Core, equipped with Swagger for documentation/testing

🛠️ Prerequisites
Qt 6.5+ with Charts and Network modules installed

CMake 3.18+

A C++17-compatible compiler (e.g. MSVC, MinGW, GCC)

If using backend sync: run a local ASP.NET Core service at http://localhost:8080
- 
Feel free to let me know if there's any specific feature you'd like to add or change!