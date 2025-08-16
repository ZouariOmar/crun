# Set the cmake min version (current - 3.29.3)
cmake_minimum_required(VERSION 3.29.3)

# Set the project name
project(crun)

# Set the CMake version
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set Crun compiler flags
add_compile_options(-Wall -Wextra)

# Generate release product
set(CMAKE_BUILD_TYPE Release)

# Set sources files
set(SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/../project/src/main.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/../project/src/Crun.cpp)

# Set headers files
set(HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/../project/include/Crun.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/../project/import/Patterns.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/../project/import/Color.h)

# Generate Crun
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})
