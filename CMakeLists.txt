project(KenshiLib LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Boost REQUIRED)

file(GLOB_RECURSE KENSHILIB_SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/Source/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/Include/*.h"
)

add_library(KenshiLib STATIC ${KENSHILIB_SOURCES})

target_include_directories(KenshiLib PUBLIC ${Boost_INCLUDE_DIRS})
target_include_directories(KenshiLib PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/Include/mygui")
target_include_directories(KenshiLib PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/Include/ogre")
target_include_directories(KenshiLib PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/Include")

target_link_libraries(KenshiLib PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/Libraries/mygui/MyGUIEngine_x64.lib"
    "${CMAKE_CURRENT_SOURCE_DIR}/Libraries/ogre/OgreMain_x64.lib"
)

if(WIN32)
    target_compile_definitions(KenshiLib PUBLIC WIN32_LEAN_AND_MEAN)
endif()