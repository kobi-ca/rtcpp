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

add_executable(basic-stl-algo basic-stl-algo.cpp)
target_compile_options(basic-stl-algo PRIVATE -Wall -Wextra -pedantic -Weffc++)

add_executable(basic-stl-fill basic-stl-fill.cpp)
target_compile_options(basic-stl-fill PRIVATE -Wall -Wextra -pedantic -Weffc++)

add_executable(basic-stl-fill-accumulate basic-stl-fill-accumulate.cpp)
target_compile_options(basic-stl-fill-accumulate PRIVATE -Wall -Wextra -pedantic -Weffc++)

add_executable(literals-example literals-example.cpp)
target_compile_options(literals-example PRIVATE -Wall -Wextra -pedantic -Weffc++)

add_executable(align-example align-example.cpp)
target_compile_options(align-example PRIVATE -Wall -Wextra -pedantic -Weffc++)

add_executable(span-example span-example.cpp)
target_compile_options(span-example PRIVATE -Wall -Wextra -pedantic -Weffc++)

add_executable(template-integer-sequence-example template-integer-sequence-example.cpp)
target_compile_options(template-integer-sequence-example PRIVATE -Wall -Wextra -pedantic -Weffc++)
