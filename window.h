//
// Created by akash on 11-07-2024.
//

#ifndef REDENGINE_WINDOW_H
#define REDENGINE_WINDOW_H

#include "glfw.h"
#include "mouse.h"

namespace redengine {
    class window {
    public:
        void init() {
        }
        void run();
        void cleanup();

        window();
        virtual ~window();
    private:
        glfw::window glfw_window;
    };


} // namespace redengine

#endif // REDENGINE_WINDOW_H
