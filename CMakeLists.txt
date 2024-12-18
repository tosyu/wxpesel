cmake_minimum_required(VERSION 3.28.3)

project(wxpesel VERSION 0.1)

set(CMAKE_CXX_STANDARD 17)

find_package(wxWidgets COMPONENTS gl core base OPTIONAL_COMPONENTS net)
include(${wxWidgets_USE_FILE})
include_directories(include)

add_executable(wxpesel)

add_subdirectory(src)

target_link_libraries(wxpesel ${wxWidgets_LIBRARIES})
