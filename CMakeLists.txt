cmake_minimum_required(VERSION 3.1.0)

project(q_example)
add_compile_options(-std=c++11)


# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed
set(CMAKE_AUTOMOC ON)
# Create code from a list of Qt designer ui files
set(CMAKE_AUTOUIC ON)

# Find the QtWidgets library
find_package(Qt5Widgets CONFIG REQUIRED)


# Populate a CMake variable with the sources
set(q_example_HDRS
    include
)

set(q_example_SRCS
    src/q_test.ui
    src/main.cpp
    src/main_window_example.cpp
)

qt5_wrap_cpp(moc_SRC
    include/main_window_example.hpp
)

# Tell CMake to create the q_example executable
add_executable(q_example ${q_example_SRCS}
    ${moc_SRC}
)
# Use the Widgets module from Qt 5
target_link_libraries(q_example Qt5::Widgets)
target_include_directories(q_example PUBLIC ${q_example_HDRS})