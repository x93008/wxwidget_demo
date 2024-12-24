cmake_minimum_required(VERSION 3.25)

project(wxwidget_demo)
set(APP_NAME wxwidget_demo)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(${PROJECT_SOURCE_DIR}/src)

find_package(wxWidgets REQUIRED CONFIG)

aux_source_directory(src SRC)

if (CMAKE_SYSTEM_NAME MATCHES "Windows")
    add_executable(${APP_NAME} WIN32 ${SRC})
else()
    add_executable(${APP_NAME} ${SRC})
endif()

target_link_libraries(${APP_NAME} PRIVATE wxWidgets::wxWidgets)
