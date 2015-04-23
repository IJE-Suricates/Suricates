#include "babel.h"
#include "environment.h"
#include "frontend.h"
#include "menu.h"

using namespace std;

Babel::Babel()
    : Game("classification")
{
}

void
Babel::init(const string& title, int w, int h) throw (Exception)
{
    Environment *env = Environment::get_instance();

    env->video->set_resolution(w, h);
    env->video->set_window_name(title);

    m_level = load_frontend(m_id);
}

void
Babel::run()
{
    while (m_level and not m_done)
    {
        unsigned long now = update_timestep();
        process_input();

        m_level->update(now);
        m_level->draw();

        update_screen();
        delay(1);

        if (m_level->next() == "menu" and m_level->is_done())
        {
            m_level = load_menu();
        }
        else if (m_level->is_done())
        {
            string next = m_level->next();
            delete m_level;
            m_level = load_frontend(next);
        }
    }
}

Level *
Babel::load_frontend(const string& id)
{
    if (id == "classification")
    {
        return new FrontEnd("game_logo", "res/images/classification.png");
    }
    else if (id == "game_logo")
    {
        return new FrontEnd("sdl_logo", "res/images/game_logo.png");
    }
    else if (id == "sdl_logo")
    {
        return new FrontEnd("menu", "res/images/sdl_logo.png");
    }

    return nullptr;
}

Level *
Babel::load_menu()
{
    return new Menu("", "res/images/menu.png");
}
