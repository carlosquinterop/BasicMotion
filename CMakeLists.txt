project(basicmotion)
cmake_minimum_required(VERSION 3.2.2)

add_definitions(-D UNIX)
add_definitions(-D LINUX)
add_definitions(-D _GNU_SOURCE)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(CMAKE_AUTOMOC NO)
set(CMAKE_INCLUDE_CURRENT_DIR YES)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")

set(libs)

# Qt
find_package(Qt5Widgets)
include_directories(${Qt5Widgets_INCLUDES})
list(APPEND libs ${Qt5Widgets_LIBRARIES})

#find_package(Qt5Bluetooth)
#include_directories(${Qt5Bluetooth_INCLUDES})
#list(APPEND libs ${Qt5Bluetooth_LIBRARIES})

find_package(Qt5SerialPort)
include_directories(${Qt5SerialPort_INCLUDES})
list(APPEND libs ${Qt5SerialPort_LIBRARIES})


find_package(Qt5Gui)
include_directories(${Qt5Gui_INCLUDES})
list(APPEND libs ${Qt5Gui_LIBRARIES})

find_package(Qt5Core)
include_directories(${Qt5Core_INCLUDES})
list(APPEND libs ${Qt5Core_LIBRARIES})

include_directories(${PROJECT_SOURCE_DIR})

set(SOURCES
    src/main.cpp
    src/BasicMotion.cpp
    src/workerThread.cpp
    src/jscontroller.cpp
)

set(HEADERS     
    src/BasicMotion.h
    src/workerThread.h
    src/jscontroller.h
)

qt5_wrap_cpp(HEADERS ${HEADERS})

set(srcs
    ${HEADERS}
    ${SOURCES}
)

add_executable(basicmotion ${srcs})
target_link_libraries(basicmotion ${libs})