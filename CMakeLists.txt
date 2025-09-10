cmake_minimum_required(VERSION 3.15)
project(KenshiLib LANGUAGES CXX)

# Require C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find Boost
find_package(Boost REQUIRED)

# Collect all C++ source and header files
file(GLOB_RECURSE KENSHILIB_SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/Source/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/Include/*.h"
)

# Build KenshiLib as a static library including ASM
add_library(KenshiLib STATIC ${KENSHILIB_SOURCES})

# Add dependent directories
target_include_directories(KenshiLib PUBLIC ${Boost_INCLUDE_DIRS})
target_include_directories(KenshiLib PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/Include/mygui")
target_include_directories(KenshiLib PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/Include/ogre")
target_include_directories(KenshiLib PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/Include")

# Link external libraries
target_link_libraries(KenshiLib PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/Libraries/mygui/MyGUIEngine_x64.lib"
    "${CMAKE_CURRENT_SOURCE_DIR}/Libraries/ogre/OgreMain_x64.lib"
)

# Windows-specific defines
if(WIN32)
    target_compile_definitions(KenshiLib PUBLIC WIN32_LEAN_AND_MEAN)
endif()