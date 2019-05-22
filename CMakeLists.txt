cmake_minimum_required(VERSION 3.1...3.14)
if(${CMAKE_VERSION} VERSION_LESS 3.12)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

project(live_reloading VERSION 1.0
                  DESCRIPTION "live file reloading"
                  LANGUAGES CXX)
                  

#add_library(main STATIC main.cpp main.h) #either STATIC, SHARED or MODULE.

target_include_directories(main PUBLIC include) #adds include directory to target
 #target_include_directories(
   # MyTarget
    # PUBLIC
   #  $<BUILD_INTERFACE:"${CMAKE_CURRENT_SOURCE_DIR}/include">
   #  $<INSTALL_INTERFACE:include>
   #  )



add_executable(main main.cc main.h)
target_link_libraries(calc PUBLIC calclib)
