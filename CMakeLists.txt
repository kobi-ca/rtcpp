cmake_minimum_required(VERSION 3.26)
project(rtc__)

set(CMAKE_CXX_STANDARD 20)

add_executable(led led.cpp)
target_compile_options(led PRIVATE -Wall -Wextra -pedantic -Weffc++)

add_executable(led-template led-template.cpp)
target_compile_options(led-template PRIVATE -Wall -Wextra -pedantic -Weffc++)

add_executable(simple-class simple-class.cpp)
target_compile_options(simple-class PRIVATE -Wall -Wextra -pedantic -Weffc++)

add_executable(simple-class-as-struct simple-class-as-struct.cpp)
target_compile_options(simple-class-as-struct PRIVATE -Wall -Wextra -pedantic -Weffc++)
