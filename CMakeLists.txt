cmake_minimum_required(VERSION 3.2)
project (Olive)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_EXE_LINKER_FLAGS "-static")

# Get source files from src/ and sub directories
file(GLOB_RECURSE SOURCES "src/*.cpp")
file(GLOB_RECURSE HEADERS "src/*.h")

set (INCLUDE_DIRS "")
foreach (_headerFile ${HEADERS})
    get_filename_component(_dir ${_headerFile} PATH)
    list (APPEND INCLUDE_DIRS ${_dir})
endforeach()
list(REMOVE_DUPLICATES INCLUDE_DIRS)

# Include files
include_directories(${INCLUDE_DIRS} ./include C:/VulkanSDK/1.0.3.1/Include /include)

LINK_DIRECTORIES(./lib C:/VulkanSDK/1.0.3.1/Bin32 C:/VulkanSDK/1.0.3.1/Bin)

# Adding executable and linking libraries.
add_executable(Olive ${SOURCES})

target_link_libraries(Olive glfw3 vulkan-1 opengl32 gdi32 user32 kernel32)

# Set executable location to /Debug
set_target_properties(Olive PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/Debug/)
