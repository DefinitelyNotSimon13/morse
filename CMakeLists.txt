########## Project Setup ###########
cmake_minimum_required(VERSION 3.31)

set(PROJECT_NAME morse)
set(PROJECT_VERSION 0.0.1)
set(PROJECT_REPOSITORY_URL "https://google.com")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED true)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Options
option(ENABLE_AUTO_FORMAT
    "Automatically run ‘format’ target before building the main executable"
    ON
)

# Initiliazation of project
project(
    ${PROJECT_NAME}
    VERSION ${PROJECT_VERSION}
    DESCRIPTION "A tool to en/decode morse code"
    HOMEPAGE_URL ${PROJECT_REPOSITORY_URL}
)

# retrieve files from `src` and `include` directories recursively
file(GLOB_RECURSE SOURCES "${PROJECT_SOURCE_DIR}/src/*.cpp")
file(GLOB_RECURSE HEADERS "${PROJECT_SOURCE_DIR}/include/*.hpp")
set(PROJECT_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/include")

########## Windows Check ###########
# Windows is an optional requirement, for now
# compilation will fail when trying to compile on Windows
if(WIN32)
    message(FATAL_ERROR "Compiling the project for Windows is currently unsupported!")
endif()

########## Dependencies ###########
find_package(Boost REQUIRED
    COMPONENTS 
        log
        json
)

########## Main Executable ###########

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(
    ${PROJECT_NAME}
    PRIVATE
    ${PROJECT_INCLUDE_DIR}
    ${PROJECT_INCLUDE_DIR}/pets
)

target_link_libraries(
    ${PROJECT_NAME}
    PRIVATE
    Boost::log
    Boost::json
)

########## Formatting Target ###########
find_program(ASTYLE_EXECUTABLE NAMES astyle)
if(NOT ASTYLE_EXECUTABLE)
    message(WARNING "Formatting target unavailable, `astyle` executable not found")
else()
    add_custom_target(
        format
        COMMAND "${ASTYLE_EXECUTABLE}"
        -n
        ${SOURCES} ${HEADERS}
        VERBATIM
    )
    set_target_properties(format
        PROPERTIES
        EXCLUDE_FROM_ALL OFF
        EXCLUDE_FROM_DEFAULT_BUILD ON
        FOLDER "tools"
    )

    if(ENABLE_CODE_FORMAT)
        # add formatting as dependecy if enabled
        add_dependencies(${PROJECT_NAME} format)
    endif()
endif()


########## Doxygen Documentation ###########
find_package(Doxygen)
if(NOT DOXYGEN_FOUND)
    message(WARNING "Doxygen not found, unable to build documentation")
else()
    add_custom_target(
        generate_documentation
        COMMENT "Generating documentation with Doxygen..."
        COMMAND ${DOXYGEN_EXECUTABLE} ${PROJECT_SOURCE_DIR}/Doxyfile
        WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
        VERBATIM)
    set_target_properties(generate_documentation
        PROPERTIES
        EXCLUDE_FROM_ALL ON
        EXCLUDE_FROM_DEFAULT_BUILD ON
        FOLDER "tools"
    )
    # compile-commands.json should exists, as such the project beeing
    # build is added as a dependency
    add_dependencies(generate_documentation ${PROJECT_NAME})
endif()

