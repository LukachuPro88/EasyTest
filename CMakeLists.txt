
cmake_minimum_required(VERSION 3.20)

project(EasyTest
    VERSION 0.1.0
    LANGUAGES C
)

add_library(EasyTest
    src/tests.c
    src/assertions.c
)

target_include_directories(EasyTest
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_compile_features(EasyTest PUBLIC c_std_11)

set_target_properties(EasyTest PROPERTIES
    C_STANDARD_REQUIRED ON
    C_EXTENSIONS OFF
)
