#include "raymob.h"
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
#include "raylua.h"

int main(void)
{
    lua_State *L = luaL_newstate();
    if (L == NULL) {
        TraceLog(LOG_ERROR, "LUA: Failed to create Lua state");
        return 1;
    }
    luaL_openlibs(L);
    raylua_init(L);
    if (luaL_dofile(L, "scripts/hello_world.lua") != LUA_OK) {
        TraceLog(LOG_ERROR, "LUA: Error loading script: %s", lua_tostring(L, -1));
        lua_close(L);
        return 1;
    }
    lua_close(L);
    return 0;
}
