/*******************************************************************************************
*
*   raylib [core] example - Basic window
*
*   Welcome to raylib!
*
*   To test examples, just press Shift+F10 for Android Studio.
*
*   raylib official webpage: www.raylib.com
*
*   Enjoy using raylib. :)
*
*   Example licensed under an unmodified zlib/libpng license, which is an OSI-certified,
*   BSD-like license that allows static linking with closed source software
*
*   Copyright (c) 2013-2023 Ramon Santamaria (@raysan5) and reviewed by Victor Le Juez
*
********************************************************************************************/

#include "raymob.h" // This header can replace 'raylib.h' and includes additional functions related to Android.
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
#include "raylib-lua.h" // Raylib-Lua bindings header

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------

int main(void)
{
    // Initialize Lua state
    lua_State *L = luaL_newstate();
    if (L == NULL) {
        TraceLog(LOG_ERROR, "LUA: Failed to create Lua state");
        return 1;
    }

    // Open standard Lua libraries
    luaL_openlibs(L);

    // Initialize raylib-lua bindings
    raylib_lua_init(L);

    // Load and execute the Lua script
    if (luaL_dofile(L, "scripts/hello_world.lua") != LUA_OK) {
        TraceLog(LOG_ERROR, "LUA: Error loading script: %s", lua_tostring(L, -1));
        lua_close(L);
        return 1;
    }

    // Clean up Lua state
    lua_close(L);

    return 0;
}

