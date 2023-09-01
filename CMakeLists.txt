project(qt6-qrhi-tests)
cmake_minimum_required(VERSION 3.24)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 COMPONENTS Core REQUIRED)

#------------------------------------------------------------------
# helper functions defined in QtTestHelpers.cmake is too complex
# so we define some simple functions here.
#------------------------------------------------------------------
#include(${_qt_6_config_cmake_dir}/QtCMakeHelpers.cmake)
#include(${_qt_6_config_cmake_dir}/QtResourceHelpers.cmake)
#include(${_qt_6_config_cmake_dir}/QtTestHelpers.cmake)

function(qt_internal_add_manual_test NAME)
    cmake_parse_arguments(ARG "" "" "SOURCES;LIBRARIES" ${ARGN})

    set(FOUND_COMPONENTS "")
    foreach(lib ${ARG_LIBRARIES})
        if(lib MATCHES "Qt::(.+)")
            string(REGEX REPLACE "Qt::(.+)" "\\1" component ${lib})
            if(NOT component MATCHES "Private$")
                list(APPEND FOUND_COMPONENTS ${component})
            endif()
        endif()
    endforeach()

    find_package(Qt6 REQUIRED COMPONENTS ${FOUND_COMPONENTS})

    add_executable(${NAME} ${ARG_SOURCES})

    target_link_libraries(${NAME} PRIVATE ${ARG_LIBRARIES})

endfunction()

function(qt_internal_add_resource TARGET NAME)
    cmake_parse_arguments(ARG "" "PREFIX" "FILES" ${ARGN})

    qt_add_resources(${TARGET} ${NAME}
        PREFIX ${ARG_PREFIX}
        FILES ${ARG_FILES}
    )
message(db_add_resource: ${ARG_FILES})
endfunction()

#-----------------------------------------------------------------------

add_subdirectory(hellominimalcrossgfxtriangle)
add_subdirectory(compressedtexture_bc1)
add_subdirectory(compressedtexture_bc1_subupload)
add_subdirectory(texuploads)
add_subdirectory(msaatexture)
add_subdirectory(msaarenderbuffer)
add_subdirectory(cubemap)
add_subdirectory(cubemap_scissor)
add_subdirectory(cubemap_render)
add_subdirectory(multiwindow)
add_subdirectory(multiwindow_threaded)
add_subdirectory(triquadcube)
add_subdirectory(offscreen)
add_subdirectory(floattexture)
add_subdirectory(float16texture_with_compute)
add_subdirectory(mrt)
add_subdirectory(shadowmap)
add_subdirectory(computebuffer)
add_subdirectory(computeimage)
add_subdirectory(instancing)
add_subdirectory(noninstanced)
add_subdirectory(tex3d)
add_subdirectory(texturearray)
add_subdirectory(polygonmode)
add_subdirectory(tessellation)
add_subdirectory(geometryshader)
add_subdirectory(stenciloutline)
add_subdirectory(stereo)
add_subdirectory(tex1d)
if(QT_FEATURE_widgets)
    add_subdirectory(rhiwidget)
endif()
