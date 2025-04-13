cmake_minimum_required(VERSION 3.31)
project(iOS-icon-extractor CXX C)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(Headers
        include/IconCenters.h
        include/config.h
        include/IconIO.h
        )

set(Sources
        src/extract.cpp
        src/config.cpp
        src/IconIO.cpp
        )

add_executable(iOS-icon-extractor
        ${Sources}
        ${Headers})

find_package(OpenCV REQUIRED)

target_include_directories(iOS-icon-extractor PRIVATE ${OpenCV_INCLUDE_DIRS})
target_include_directories(iOS-icon-extractor PRIVATE include)

target_link_libraries(iOS-icon-extractor PRIVATE ${OpenCV_LIBS})