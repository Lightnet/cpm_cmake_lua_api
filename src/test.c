// Simple C program to display "Hello World"
 
// Header file for input output functions
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
//#include <sol/sol.hpp>
#include <stdlib.h>
#include <stdio.h>
 
// main function -
// where the execution of program begins
int main()
{ 
    // prints hello world
    printf("Hello World");

    int status, result, i;
    double sum;
    lua_State *L;

    L = luaL_newstate();
    luaL_openlibs(L); //need this load libs example print() to loadfile

    status = luaL_loadfile(L, "script.lua");
    if (status) {
        /* If something went wrong, error message is at the top of */
        /* the stack */
        fprintf(stderr, "Couldn't load file: %s\n", lua_tostring(L, -1));
        exit(1);
    }

    lua_newtable(L);    /* We will pass a table */

    for (i = 1; i <= 5; i++) {
        lua_pushnumber(L, i);   /* Push the table index */
        lua_pushnumber(L, i*2); /* Push the cell value */
        lua_rawset(L, -3);      /* Stores the pair in the table */
    }

    lua_setglobal(L, "foo");

    result = lua_pcall(L, 0, LUA_MULTRET, 0);
    if (result) {
        fprintf(stderr, "Failed to run script: %s\n", lua_tostring(L, -1));
        exit(1);
    }

    /* Get the returned value at the top of the stack (index -1) */
    sum = lua_tonumber(L, -1);

    printf("Script returned: %.0f\n", sum);

    lua_pop(L, 1);  /* Take the returned value out of the stack */
    lua_close(L);   /* Cya, Lua */


 
    return 0;
}