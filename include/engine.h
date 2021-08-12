/* date = August 12th 2021 2:53 pm */

#ifndef ENGINE_H
#define ENGINE_H

#include "state.h"

constexpr const char* L_ENGINE_ACCESSOR = "ENGINE";

class engine {
    public:
    engine();
    
    void push_state(const std::string_view stateFile);
    void run();
    
    ~engine();
    
    private:
    void init_window();
    void update();
    void render();
    void register_lua_state(lua_State* L);
    void run_lua_function(lua_State* L, const std::string_view name);
    
    private:
    static int l_log_info(lua_State* L) {
        const std::string message = lua_tostring(L, -1);
        lua_getglobal(L, L_ENGINE_ACCESSOR);
        spdlog::info("[Lua] {}", message);
    }
    
    private:
    sf::RenderWindow _window;
    sf::Clock _clock;
    sf::Event _event;
    
    unsigned int _width, _height = 0;
};

#endif //ENGINE_H
