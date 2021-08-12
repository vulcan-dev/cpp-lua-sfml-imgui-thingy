/* date = August 12th 2021 2:58 pm */

#ifndef STATE_H
#define STATE_H

extern "C" {
#include <lua.hpp>
#include <luajit/luajit.h>
}

#include <imgui-SFML.h>
#include <imgui.h>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <spdlog/spdlog.h>
#include <vector>
#include <string>
#include <stack>

class state {
    public:
    state(const std::string_view file);
    void init();
    void load_file();
    ~state();
    
    public:
    std::string _lua_state_file = "";
    inline lua_State* get_state() const { return this->_L; }
    
    private:
    lua_State* _L;
};

#endif //STATE_H