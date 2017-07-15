cmake_minimum_required(VERSION 3.2)
project(Scharfschutze)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
  src/main.cpp)
add_executable(Scharfschutze ${SOURCE_FILES})

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake/modules")

find_package(SFML REQUIRED system window graphics network audio)
find_package(EntityX)
find_package(Chipmunk)
find_package(PhysFS)

include_directories(
  ${SFML_INCLUDE_DIR}
  ${ENTITYX_INCLUDE_DIR}
  ${CHIPMUNK_INCLUDE_DIR}
  ${PHYSFS_INCLUDE_DIR})

target_link_libraries(Scharfschutze
  ${SFML_LIBRARIES}
  ${ENTITYX_LIBRARIES}
  ${CHIPMUNK_LIBRARIES}
  ${PHYSFS_LIBRARY})
