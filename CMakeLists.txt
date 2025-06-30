cmake_minimum_required(VERSION 3.16)

project(WellMini VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Charts Network)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Charts Network)

set(PROJECT_SOURCES
        include/MainWindow.h
        include/TrayManager.h

        src/Main.cpp
        src/MainWindow.cpp
        src/TrayManager.cpp

        ui/MainWindow.ui
        ui/ReminderDialog.ui
        include/ReminderDialog.h
        src/ReminderDialog.cpp
        include/ReminderDialog.h
        include/Login.h
        src/Login.cpp
        include/Dashoard.h
        src/Dashoard.cpp
        include/ActivityMonitor.h
        src/ActivityMonitor.cpp
        include/ActivityChart.h
        src/ActivityChart.cpp
)

set(CMAKE_AUTOUIC_SEARCH_PATHS
        ${CMAKE_SOURCE_DIR}/ui
)

qt_add_resources(APP_RESOURCES resources/resources.qrc)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(WellMini
            MANUAL_FINALIZATION
            ${PROJECT_SOURCES}
            ${APP_RESOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET WellMini APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(WellMini SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(WellMini
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(WellMini
        PRIVATE Qt${QT_VERSION_MAJOR}::Widgets
        PRIVATE Qt${QT_VERSION_MAJOR}::Charts
        PRIVATE Qt${QT_VERSION_MAJOR}::Network)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.WellMini)
endif()
set_target_properties(WellMini PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS WellMini
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(WellMini)
endif()
