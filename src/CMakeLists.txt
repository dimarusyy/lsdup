cmake_minimum_required(VERSION 3.14)

find_package(Boost COMPONENTS iostreams REQUIRED)

file(GLOB_RECURSE LSDUP_HEADERS $<$<VERSION_GREATER_EQUAL:${CMAKE_VERSION},3.14>:CONFIGURE_DEPENDS>
    ${CMAKE_SOURCE_DIR}/src/*.h
)

file(GLOB_RECURSE LSDUP_SOURCES $<$<VERSION_GREATER_EQUAL:${CMAKE_VERSION},3.14>:CONFIGURE_DEPENDS>
    ${CMAKE_SOURCE_DIR}/src/*.cpp
)

set(MURMUHASH3_HEADERS ${CMAKE_SOURCE_DIR}/3rdparty/smhasher-git-src/src/MurmurHash3.h)
set(MURMUHASH3_SOURCES ${CMAKE_SOURCE_DIR}/3rdparty/smhasher-git-src/src/MurmurHash3.cpp)

list(APPEND LSDUP_HEADERS "${MURMUHASH3_HEADERS}")
list(APPEND LSDUP_SOURCES "${MURMUHASH3_SOURCES}")

add_executable(${LSDUP_BINARY_NAME} ${LSDUP_HEADERS} ${LSDUP_SOURCES})
target_include_directories(${LSDUP_BINARY_NAME} PRIVATE "${CMAKE_SOURCE_DIR}/3rdparty/smhasher-git-src/src")
target_link_libraries(${LSDUP_BINARY_NAME} PRIVATE Boost::iostreams)

