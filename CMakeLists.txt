cmake_minimum_required(VERSION 3.16)

project(easytest
    VERSION 0.1.0
    LANGUAGES C
)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

add_library(easytest STATIC
    src/suite.c
    src/assert.c
)

target_include_directories(easytest
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_executable(easytest_tests
    tests/main.c
)

target_link_libraries(easytest_tests
    PRIVATE easytest
)

enable_testing()
add_test(NAME easytest_tests COMMAND easytest_tests)

