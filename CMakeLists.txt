cmake_minimum_required(VERSION 3.26)

# create project
project(lua_api)

# set where the compiled files goes
set(CMAKE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/libs)
set(CMAKE_PDB_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
LINK_DIRECTORIES(${CMAKE_BINARY_DIR}/libs)

# add dependencies
include(cmake/CPM.cmake)

CPMAddPackage(
  NAME lua
  GIT_REPOSITORY https://github.com/lua/lua.git
  VERSION 5.4.6
  DOWNLOAD_ONLY YES #download file only
  #OPTIONS "CXXOPTS_BUILD NO" "CXXOPTS_BUILD_EXAMPLES NO" "CXXOPTS_BUILD_TESTS NO" "CXXOPTS_ENABLE_INSTALL NO"
)

MESSAGE(STATUS "=================================")
MESSAGE(STATUS "lua: ${lua}")
if (lua_ADDED)
  FILE(GLOB lua_sources ${lua_SOURCE_DIR}/*.c)
  list(REMOVE_ITEM lua_sources 
    "${lua_SOURCE_DIR}/lua.c" 
    "${lua_SOURCE_DIR}/luac.c" 
    "${lua_SOURCE_DIR}/onelua.c"
  ) #default?
  MESSAGE(STATUS "lua_sources: ${lua_sources}")

  add_library(lua ${lua_sources})

  # set(lua_INCLUDES
  #   ${lua_SOURCE_DIR}/lua.h
  #   ${lua_SOURCE_DIR}/lualib.h
  #   ${lua_SOURCE_DIR}/lauxlib.h
  # )
  # include folder only not files
  include_directories(${lua_SOURCE_DIR})

endif()

add_executable(${PROJECT_NAME}_test src/test.c)
target_link_libraries(${PROJECT_NAME}_test PUBLIC lua)
