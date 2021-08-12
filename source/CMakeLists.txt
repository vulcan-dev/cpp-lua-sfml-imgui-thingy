cmake_minimum_required(VERSION 3.13.4)

set(CMAKE_TOOLCHAIN_FILE "D:\\vcpkg\\scripts\\buildsystems\\vcpkg.cmake")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(main)

find_package(SFML COMPONENTS system window graphics CONFIG REQUIRED)
find_package(spdlog CONFIG REQUIRED)
find_package(imgui CONFIG REQUIRED)
find_package(ImGui-SFML CONFIG REQUIRED)

include_directories(${PROJECT_NAME} include)

file(GLOB_RECURSE fileCollection "*.cpp")
add_executable(${PROJECT_NAME} ${fileCollection})

target_link_libraries(${PROJECT_NAME} PRIVATE sfml-system sfml-network sfml-graphics sfml-window spdlog::spdlog spdlog::spdlog_header_only imgui::imgui ImGui-SFML::ImGui-SFML)