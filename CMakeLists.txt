cmake_minimum_required(VERSION 3.25)

# Options. Turn on with 'cmake -test=ON'.
option(test "Build all tests." OFF) # Makes boolean 'test' available.

project(ropasc)

# Headers directory
include_directories(inc)
set(COMMON_INCLUDES ${PROJECT_SOURCE_DIR}/inc)

# GTest as per https://google.github.io/googletest/quickstart-cmake.html
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Source files
add_executable(ropasc 
    src/main.cpp
    src/game.cpp
)

##############
# Tests
##############
if(test)
    enable_testing()

    add_executable(unitTests
    tests/test.cc
    src/game.cpp
    )

    target_link_libraries(
        unitTests
        GTest::gtest_main
        GTest::gmock
    )

    include(GoogleTest)
    gtest_discover_tests(unitTests)
endif()