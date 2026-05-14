cmake_minimum_required(VERSION 3.10)

project(canbusSimulation LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Qt modüllerini bul
find_package(Qt5 COMPONENTS
    Quick
    Qml
    SerialBus
    REQUIRED
)

# Kaynak dosyalar
set(SOURCES
    main.cpp
    wallboxcharger.cpp
)

set(HEADERS
    wallboxcharger.h
)

# QML + QRC dosyası
qt5_add_resources(QML_RESOURCES qml.qrc)

# Uygulama derleme
add_executable(${PROJECT_NAME}
    ${SOURCES}
    ${HEADERS}
    ${QML_RESOURCES}
)

# Bağlanacak Qt kütüphaneleri
target_link_libraries(${PROJECT_NAME}
    Qt5::Quick
    Qt5::Qml
    Qt5::SerialBus
)
