cmake_minimum_required(VERSION 3.16)

project(clock VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 6.5 REQUIRED COMPONENTS Quick)

qt_standard_project_setup(REQUIRES 6.5)

qt_add_executable(appclock
    main.cpp
    assets.qrc
    clockobject.cpp
    clockobject.h
)

qt_add_qml_module(appclock
    URI clock
    VERSION 1.0
    QML_FILES Main.qml
    Button.qml
    AlarmSwitch.qml
    PageHome.qml
    PageAlarm.qml
    Page.qml
    Counter.qml
    PageAlarmList.qml
)

set_target_properties(appclock PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appclock
    PRIVATE Qt6::Quick
)

install(TARGETS appclock
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
