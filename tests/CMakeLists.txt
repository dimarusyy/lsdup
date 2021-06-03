set(TEST_APP_NAME "lsdup.tests")

# Dependencies
find_package(Boost COMPONENTS iostreams REQUIRED)
find_package(doctest REQUIRED)

# Files
file(GLOB_RECURSE TESTS_HEADERS $<$<VERSION_GREATER_EQUAL:${CMAKE_VERSION},3.14>:CONFIGURE_DEPENDS>
    ${CMAKE_SOURCE_DIR}/tests/*.h
)

file(GLOB_RECURSE TESTS_SOURCES $<$<VERSION_GREATER_EQUAL:${CMAKE_VERSION},3.14>:CONFIGURE_DEPENDS>
    ${CMAKE_SOURCE_DIR}/tests/*.cpp
)

set(MURMUHASH3_HEADERS ${CMAKE_SOURCE_DIR}/3rdparty/smhasher-git-src/src/MurmurHash3.h)
set(MURMUHASH3_SOURCES ${CMAKE_SOURCE_DIR}/3rdparty/smhasher-git-src/src/MurmurHash3.cpp)

list(APPEND TESTS_HEADERS "${MURMUHASH3_HEADERS}")
list(APPEND TESTS_SOURCES "${MURMUHASH3_SOURCES}")


# Test Binary
add_executable(${TEST_APP_NAME} ${TESTS_HEADERS} ${TESTS_SOURCES})
target_include_directories(${TEST_APP_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/src)
target_include_directories(${TEST_APP_NAME} PRIVATE "${CMAKE_SOURCE_DIR}/3rdparty/smhasher-git-src/src")
target_link_libraries(${TEST_APP_NAME} PRIVATE doctest::doctest Boost::iostreams)

file(COPY ${CMAKE_SOURCE_DIR}/tests/input DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

# Enable CTest
include(doctest)
doctest_discover_tests(${TEST_APP_NAME})
