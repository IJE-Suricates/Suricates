/*
 * Exemplo de um nível: uma tela de frontend.
 *
 * Autor: Edson Alves
 * Data: 20/04/2015
 * Licença: LGPL. Sem copyright.
 */
#ifndef FRONT_END_H
#define FRONT_END_H

#include "level.h"
#include "keyboardevent.h"
#include "keyboardeventlistener.h"
#include <memory>

class Image;

class FrontEnd : public Level, public KeyboardEventListener
{
public:
    FrontEnd(const string& next, const string& image,
        unsigned long duration = 3000);

private:
    shared_ptr<Image> m_image;
    unsigned long m_start;
    unsigned long m_duration;
    int m_x, m_y;

    void update_self(unsigned long elapsed);
    void draw_self();
    bool onKeyboardEvent(const KeyboardEvent& event);
};

#endif
