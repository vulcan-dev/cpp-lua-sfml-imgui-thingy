#include "state.h"

state::state(const std::string_view file) {
    this->_L = luaL_newstate();
    luaL_openlibs(this->_L);
    
    this->_lua_state_file = file;
}

void state::load_file() {
    if (luaL_dofile(this->_L, this->_lua_state_file.c_str())) {
        spdlog::error("[Lua] Error: {}", lua_tostring(this->_L, -1));
        lua_pop(this->_L, lua_gettop(this->_L));
        throw("Failed loading State File: %s", this->_lua_state_file.c_str());
    }
}

void state::init() {
    lua_getglobal(this->_L, "init");
    if (lua_pcall(this->_L, 0, 0, 0)) {
        spdlog::warn("no init function found");
    }
}

state::~state() {
    lua_close(this->_L);
}