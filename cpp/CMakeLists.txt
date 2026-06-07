cmake_minimum_required(VERSION 3.16)
project(edgevision LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

find_package(OpenCV REQUIRED)

add_executable(edgevision_infer src/inference_main.cpp)
target_include_directories(edgevision_infer PRIVATE include)
target_link_libraries(edgevision_infer PRIVATE ${OpenCV_LIBS})

# Link TensorFlow Lite when building for ARM target:
# target_link_libraries(edgevision_infer PRIVATE tensorflow-lite)
