#include "raymob.h"
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
#include "raylua.h"
#include <android/asset_manager.h>
#include <android/asset_manager_jni.h>

// Load file from Android assets
static int android_loadfile(lua_State *L) {
    const char *filename = luaL_checkstring(L, 1);
    AAssetManager *assetManager = GetAndroidApp()->activity->assetManager;
    AAsset *asset = AAssetManager_open(assetManager, filename, AASSET_MODE_BUFFER);
    if (!asset) {
        lua_pushnil(L);
        lua_pushfstring(L, "Cannot open asset: %s", filename);
        return 2;
    }
    size_t size = AAsset_getLength(asset);
    const char *buffer = (const char *)AAsset_getBuffer(asset);
    if (!buffer) {
        AAsset_close(asset);
        lua_pushnil(L);
        lua_pushfstring(L, "Cannot read asset: %s", filename);
        return 2;
    }
    luaL_loadbuffer(L, buffer, size, filename);
    AAsset_close(asset);
    return 1;
}

// List files (stub, as raylua expects it)
static int android_listfiles(lua_State *L) {
    lua_newtable(L); // Return empty table for simplicity
    return 1;
}

int main(void)
{
    lua_State *L = luaL_newstate();
    if (L == NULL) {
        TraceLog(LOG_ERROR, "LUA: Failed to create Lua state");
        return 1;
    }
    luaL_openlibs(L);
    raylua_boot(L, android_loadfile, android_listfiles, false);
    if (luaL_dofile(L, "scripts/hello_world.lua") != LUA_OK) {
        TraceLog(LOG_ERROR, "LUA: Error loading script: %s", lua_tostring(L, -1));
        lua_close(L);
        return 1;
    }
    lua_close(L);
    return 0;
}