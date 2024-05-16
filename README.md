# cpm_cmake_lua_api

# License: MIT

# Packages:
 - Lua 5.4.6 https://github.com/lua/lua
 - CPM.cmake v0.39.0 dev https://github.com/cpm-cmake/CPM.cmake
 - CMake 3.29.2

# Information:
  This is simple lua script test in c lang build.

  By default it required internet to download repo for lua version 5.4.6.

  Kept it very simple for test run lua script API.

  Tested Windows 10 64bit.

  Reason is to find correct ways to add src and include without needed to add too much or incorrect config.

```
#...
FILE(GLOB lua_sources ${lua_SOURCE_DIR}/*.c)
# remove files from lua_sources reason is main entry error log.
list(REMOVE_ITEM lua_sources 
  "${lua_SOURCE_DIR}/lua.c" 
  "${lua_SOURCE_DIR}/luac.c" 
  "${lua_SOURCE_DIR}/onelua.c"
) #default?
#...
add_library(lua ${lua_sources})
#...
add_executable(${PROJECT_NAME}_test src/test.c)
target_link_libraries(${PROJECT_NAME}_test PUBLIC lua)
```

# links:
 - https://www.lua.org/manual/5.4/readme.html