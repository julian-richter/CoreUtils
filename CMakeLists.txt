cmake_minimum_required(VERSION 3.14)
project(coreUtils)

# Set C++ and C standards
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 11)

# Platform-specific settings
if(APPLE)
    add_definitions(-DPLATFORM_MACOS=1)
    add_compile_options(-Wall -Werror)
elseif(UNIX AND NOT APPLE)
    add_definitions(-DPLATFORM_LINUX=1)
    add_compile_options(-Wall -Werror)
endif()

# Debug/Release settings
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_definitions(-DDEBUG)
else()
    add_definitions(-DNDEBUG)
endif()

# Output directories for all targets
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/${CMAKE_BUILD_TYPE}/${CMAKE_SYSTEM_NAME})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/${CMAKE_BUILD_TYPE}/${CMAKE_SYSTEM_NAME})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin-int/${CMAKE_BUILD_TYPE}/${CMAKE_SYSTEM_NAME})

# Create artifacts directory if it doesn't exist
file(MAKE_DIRECTORY ${CMAKE_SOURCE_DIR}/artifacts/${CMAKE_SYSTEM_NAME})

# coreUtils library
file(GLOB_RECURSE CORE_SOURCES src/*.c)
file(GLOB_RECURSE CORE_HEADERS include/*.h)

add_library(coreUtils SHARED ${CORE_SOURCES} ${CORE_HEADERS})
target_include_directories(coreUtils PUBLIC include)

# Platform-specific library settings
if(APPLE)
    set_target_properties(coreUtils PROPERTIES SUFFIX ".dylib")
elseif(UNIX AND NOT APPLE)
    set_target_properties(coreUtils PROPERTIES SUFFIX ".so")
    set_property(TARGET coreUtils PROPERTY POSITION_INDEPENDENT_CODE ON)
endif()

# Copy library to artifacts directory
add_custom_command(TARGET coreUtils POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
    $<TARGET_FILE:coreUtils>
    ${CMAKE_SOURCE_DIR}/artifacts/${CMAKE_SYSTEM_NAME}/$<TARGET_FILE_NAME:coreUtils>
)

# Main example application (all .cxx files)
file(GLOB EXAMPLE_SOURCES examples/*.cxx)
add_executable(example ${EXAMPLE_SOURCES})
target_link_libraries(example PRIVATE coreUtils)
target_include_directories(example PRIVATE include)

# Copy example to artifacts directory
add_custom_command(TARGET example POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
    $<TARGET_FILE:example>
    ${CMAKE_SOURCE_DIR}/artifacts/${CMAKE_SYSTEM_NAME}/$<TARGET_FILE_NAME:example>
)

# Discover and build individual example applications
# C examples (*.c files)
file(GLOB C_EXAMPLES examples/ex_*.c)
foreach(C_EXAMPLE ${C_EXAMPLES})
    get_filename_component(EXAMPLE_NAME ${C_EXAMPLE} NAME_WE)
    add_executable(${EXAMPLE_NAME} ${C_EXAMPLE})
    set_target_properties(${EXAMPLE_NAME} PROPERTIES LINKER_LANGUAGE C)
    target_link_libraries(${EXAMPLE_NAME} PRIVATE coreUtils)
    target_include_directories(${EXAMPLE_NAME} PRIVATE include)
    
    # Copy to artifacts directory
    add_custom_command(TARGET ${EXAMPLE_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
        $<TARGET_FILE:${EXAMPLE_NAME}>
        ${CMAKE_SOURCE_DIR}/artifacts/${CMAKE_SYSTEM_NAME}/$<TARGET_FILE_NAME:${EXAMPLE_NAME}>
    )
endforeach()

# C++ examples (*.cxx files)
file(GLOB CXX_EXAMPLES examples/ex_*.cxx)
foreach(CXX_EXAMPLE ${CXX_EXAMPLES})
    get_filename_component(EXAMPLE_NAME ${CXX_EXAMPLE} NAME_WE)
    add_executable(${EXAMPLE_NAME} ${CXX_EXAMPLE})
    set_target_properties(${EXAMPLE_NAME} PROPERTIES LINKER_LANGUAGE CXX)
    target_link_libraries(${EXAMPLE_NAME} PRIVATE coreUtils)
    target_include_directories(${EXAMPLE_NAME} PRIVATE include)
    
    # Copy to artifacts directory
    add_custom_command(TARGET ${EXAMPLE_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
        $<TARGET_FILE:${EXAMPLE_NAME}>
        ${CMAKE_SOURCE_DIR}/artifacts/${CMAKE_SYSTEM_NAME}/$<TARGET_FILE_NAME:${EXAMPLE_NAME}>
    )
endforeach()

# Set the startup project in Visual Studio
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT example)