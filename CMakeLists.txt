cmake_minimum_required(VERSION 3.5...3.10)
project(calculator VERSION 1.0.0)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

set(package_name calculator)

# Create targets and set properties
add_library(${PROJECT_NAME} "src/Calculator.cpp")
add_library(${package_name}::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME} 
    PUBLIC
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"    
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/include>"    
        "$<INSTALL_INTERFACE:include>"
    PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/src"
)

include(InstallPackage)
install_package(
    PACKAGE ${package_name} 
    TARGETS ${PROJECT_NAME}
    INCLUDE_DIRS include/${PROJECT_NAME}
)

# Add apps that depend on this library
add_subdirectory(apps)

# Add tests
if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    include(CTest)

    if(BUILD_TESTING)
        add_subdirectory(extern/googletest)
        add_subdirectory(tests)
    endif()
endif()

# CPack settings
set(CPACK_PACKAGE_CONTACT "k")
set(CPACK_PACKAGE_VERSION_MAJOR ${PROJECT_VERSION_MAJOR})
set(CPACK_PACKAGE_VERSION_MINOR ${PROJECT_VERSION_MINOR})
set(CPACK_PACKAGE_VERSION_PATCH ${PROJECT_VERSION_PATCH})
include(CPack)
