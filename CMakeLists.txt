cmake_minimum_required(VERSION 3.10)

set(CMAKE_EXPORT_COMPILE_COMMANDS true)

project(Visualizador3D)

file(GLOB SRC_FILES src/*.cpp)
file(GLOB SRC_FILES_C src/*.c)

add_executable(app ${SRC_FILES} ${SRC_FILES_C})

set_target_properties(app PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED TRUE
    CXX_EXTENSIONS TRUE
)

set(CMAKE_CXX_LINK_EXECUTABLE "${CMAKE_CXX_LINK_EXECUTABLE} -ldl")

find_package(glfw3 3.3 REQUIRED)
target_link_libraries(app glfw)

find_package(assimp CONFIG REQUIRED)
target_link_libraries(app assimp::assimp)

find_package(nlohmann_json CONFIG REQUIRED)
target_link_libraries(app nlohmann_json::nlohmann_json)

include_directories("include")
