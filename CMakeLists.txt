cmake_minimum_required(VERSION 3.15)
project(lite_logger CXX)

find_package(spdlog REQUIRED)

add_library(lite_logger src/lite_logger.cpp)
target_include_directories(lite_logger PUBLIC include PRIVATE src)
target_link_libraries(lite_logger PUBLIC spdlog::spdlog)
set_target_properties(lite_logger PROPERTIES PUBLIC_HEADER "src/lite_logger.h")
install(TARGETS lite_logger EXPORT LitLoggerTargets)
# install(TARGETS lite_logger DESTINATION ".")

add_executable(demo demo.cpp)
target_link_libraries(demo PUBLIC lite_logger)