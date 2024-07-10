//
// Created by akash on 11-07-2024.
//

#ifndef REDENGINE_MOUSE_H
#define REDENGINE_MOUSE_H
#include "glfw.h"

namespace redengine {
    namespace mouse {
        float x();
        float y();
        float dx();
        float dy();
        float scrollx();
        float scrolly();
        bool dragging();
        bool is_pressed(int button);
        void end_frame();
        void init(const glfw::window &);
    };
} // namespace redengine

#endif // REDENGINE_MOUSE_H
