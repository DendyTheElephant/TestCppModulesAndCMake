cmake_minimum_required(VERSION 3.28)

set(CMAKE_EXPERIMENTAL_CXX_MODULE_DYNDEP 1)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_SCAN_FOR_MODULES YES)
#set(CMAKE_AUTOMOC ON)
#set(CMAKE_AUTORCC ON)
#set(CMAKE_AUTOUIC ON)



project(
        "TestProjectCpp23WithQt"
        VERSION 0.1.0
        LANGUAGES CXX
)

# It is always easier to navigate in an IDE when projects are organized in folders.
#set_property(GLOBAL PROPERTY USE_FOLDERS ON)





message("\nCurrent Profile: " ${CMAKE_PROFILE})
message("Current Source Directory: " ${CMAKE_CURRENT_SOURCE_DIR})
message("Current Binary Directory: " ${CMAKE_CURRENT_BINARY_DIR})
message("CMAKE_CXX_SOURCE_FILE_EXTENSIONS ${CMAKE_CXX_SOURCE_FILE_EXTENSIONS}\n")


## Project Source & Headers
#file(GLOB_RECURSE SOURCE_CPP code/**/*.cpp code/game/*.cpp)
#file(GLOB_RECURSE SOURCE_H code/**/*.h)

#message("Current src files: " ${SOURCE_H}\n)


#find_package(Qt6 COMPONENTS
#        Core
#        REQUIRED)


add_library("DendyEngine" STATIC)
target_sources(
        "DendyEngine"
        PUBLIC
        FILE_SET cxx_modules TYPE CXX_MODULES FILES
        modules/DendyEngine/DendyEngineCore.ixx
)


add_executable("TestProjectCpp23WithQt")
target_sources(
        "TestProjectCpp23WithQt"
        PRIVATE
        src/main.cpp
)

target_link_libraries("TestProjectCpp23WithQt" PRIVATE "DendyEngine")

# Only support statically linking for now.
#target_compile_definitions(
#        "TestProjectCpp23WithQt"
#        PRIVATE SEQUENTIAL_PROCESSING=0
#)

target_compile_features(
        "TestProjectCpp23WithQt"
        PRIVATE cxx_std_23
)

#set_target_properties(
#        "TestProjectCpp23WithQt"
#        PROPERTIES INTERPROCEDURAL_OPTIMIZATION ON
#)

#target_link_libraries(TestProjectCpp23WithQt
#        Qt::Core
#)

#if (WIN32 AND NOT DEFINED CMAKE_TOOLCHAIN_FILE)
#    set(DEBUG_SUFFIX)
#    if (MSVC AND CMAKE_BUILD_TYPE MATCHES "Debug")
#        set(DEBUG_SUFFIX "d")
#    endif ()
#    set(QT_INSTALL_PATH "${CMAKE_PREFIX_PATH}")
#    if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
#        set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
#        if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
#            set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
#        endif ()
#    endif ()
#    if (EXISTS "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll")
#        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
#                COMMAND ${CMAKE_COMMAND} -E make_directory
#                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
#        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
#                COMMAND ${CMAKE_COMMAND} -E copy
#                "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll"
#                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
#    endif ()
#    foreach (QT_LIB Core)
#        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
#                COMMAND ${CMAKE_COMMAND} -E copy
#                "${QT_INSTALL_PATH}/bin/Qt6${QT_LIB}${DEBUG_SUFFIX}.dll"
#                "$<TARGET_FILE_DIR:${PROJECT_NAME}>")
#    endforeach (QT_LIB)
#endif ()


find_package( PkgConfig )


####################################################################################################

## GLAD & GLM Sources & Headers
#get_filename_component(GLAD_INCLUDE_DIR include/glad ABSOLUTE)
#get_filename_component(GLAD_SOURCE_DIR include ABSOLUTE)
#get_filename_component(GLM_DIR include/glm ABSOLUTE)


#### OpenGL
find_package(OpenGL 4.6 REQUIRED)
if(OPENGL_FOUND)
    message(STATUS "OPENGL Found")
    message(STATUS "    Includes - ${OPENGL_INCLUDE_DIR}")
    message(STATUS "    Libraries - ${OPENGL_LIBRARIES}")
else()
    message(STATUS "OPENGL Not Found")
endif(OPENGL_FOUND)

#include_directories(${OPENGL_INCLUDE_DIR})
#link_directories(${OPENGL_LIBRARIES})


#### QT5
#find_package(Qt5 5.10.0 REQUIRED Core Widgets Gui Qml Quick Network)

#### GLFW
#find_package(glfw3 3.3 REQUIRED)
#if(glfw3_FOUND)
#    message(STATUS "GLWF3 Found")
#else()
#    message("GLFW3 Not found")
#endif(glfw3_FOUND)




#### GLAD & GLM
#include_directories(${GLAD_INCLUDE_DIR} ${GLM_DIR})


## Add All Sources & Headers
#add_executable(${PROJECT_NAME} ${SOURCE_CPP} ${SOURCE_H}
#        ${GLAD_INCLUDE_DIR}/glad/glad.h ${GLAD_INCLUDE_DIR}/KHR/khrplatform.h
#        ${GLAD_SOURCE_DIR}/glad.c ${ResourceSources})