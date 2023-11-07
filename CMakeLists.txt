cmake_minimum_required(VERSION 3.5)

set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VERSION 0.0.${PATCH_VERSION})

project(HomeTask1 VERSION ${PROJECT_VERSION})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Catch2 3 REQUIRED)

configure_file(version.h.in version.h)

add_library(VersionLib version_lib.cpp)
add_executable(HomeTask1 main.cpp)
add_executable(TestVersion test_version.cpp)

target_include_directories(VersionLib PUBLIC "${CMAKE_BINARY_DIR}")

target_link_libraries(HomeTask1 PRIVATE VersionLib)

target_link_libraries(TestVersion PRIVATE Catch2::Catch2WithMain
                                  PRIVATE VersionLib)

install(TARGETS HomeTask1 RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT alservol@gmail.com)

include(CPack)

enable_testing()

add_test(TestVersion TestVersion)
