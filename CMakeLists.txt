cmake_minimum_required(VERSION 3.16)

project(planer-recorder-tool VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets Core)
find_package(spdlog REQUIRED)

qt_standard_project_setup()

set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
add_subdirectory(src/app)

target_link_libraries(planer-recorder-tool PRIVATE Qt6::Core Qt6::Widgets)
target_link_libraries(planer-recorder-tool PRIVATE spdlog::spdlog)

find_program(CLANG_FORMAT clang-format)
if(CLANG_FORMAT)
  file(GLOB_RECURSE ALL_SOURCE_FILES src/*.cpp src/*.h)
  add_custom_target(format 
    COMMAND ${CLANG_FORMAT} -i ${ALL_SOURCE_FILES}
  )
endif()
