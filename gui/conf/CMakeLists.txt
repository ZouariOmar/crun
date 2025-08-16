# Set the CMake minimum version
cmake_minimum_required(VERSION 3.29.3)

# Set the project name
project(app VERSION 0.1 LANGUAGES CXX)

# Add Qt's uic for processing .ui files
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

# Set the CMake C/C++ version
set(CMAKE_CXX_STANDARD 20) # set(CMAKE_CX_STANDARD 99) for C

# Add a compiler flag
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

# Add the main window source files
set(SOURCES
  ${CMAKE_SOURCE_DIR}/../project/src/main.cpp
  ${CMAKE_SOURCE_DIR}/../project/src/mainwindow.cpp
  ${CMAKE_SOURCE_DIR}/../project/src/suAccess.cpp
)

# Add the main window header files
set(HEADERS
  ${CMAKE_SOURCE_DIR}/../project/inc/mainwindow.hpp
  ${CMAKE_SOURCE_DIR}/../project/inc/suAccess.hpp
)

# Add the UI file
set(UI_FILES
  ${CMAKE_SOURCE_DIR}/../project/res/mainWindow.ui
  ${CMAKE_SOURCE_DIR}/../project/res/suAccess.ui
)

# Add the qrc file
set(QRC_FILES
  ${CMAKE_SOURCE_DIR}/../project/res/CrunIco.qrc
  ${CMAKE_SOURCE_DIR}/../project/res/Crun.qrc
)

find_package(Qt6 COMPONENTS Widgets Core REQUIRED)

# Add the executable target
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS} ${UI_FILES} ${QRC_FILES})

# Link Qt libraries
target_link_libraries(${PROJECT_NAME} Qt6::Core Qt6::Widgets)

# Add the tests subdirectory
# add_subdirectory(test)


# Make this a GUI application on Windows
if(WIN32)
  set(CMAKE_WIN32_EXECUTABLE ON)
endif()
