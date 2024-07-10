//
// Created by akash on 11-07-2024.
//

#include "mouse.h"

struct mouse {
    double x{0}, y{0};
    double lastx{0}, lasty{0};
    double scrollx{0}, scrolly{0};
    bool dragging{false};
    int8_t buttons{0};
};

static mouse MOUSE;

static void mouse_button_press(int button) {
    if (button < 0 || button > 7) return;
    MOUSE.buttons |= 1 << button;
}

static void mouse_button_release(int button) {
    if (button < 0 || button > 7) return;
    MOUSE.buttons &= ~(1 << button);
}

/* GLFW callbacks */
static void cursor_position_callback(GLFWwindow *window, double xpos, double ypos) {
    MOUSE.lastx = MOUSE.x;
    MOUSE.lasty = MOUSE.y;
    MOUSE.x = xpos;
    MOUSE.y = ypos;
    MOUSE.dragging = MOUSE.buttons;
}

static void mouse_button_callback(GLFWwindow *window, int button, int action, int mods) {
    if (action == GLFW_PRESS) {
        mouse_button_press(button);
    } else if (action == GLFW_RELEASE) {
        mouse_button_release(button);
        MOUSE.dragging = false;
    }
}

static void scroll_callback(GLFWwindow *window, double xoffset, double yoffset) {
    MOUSE.scrollx = xoffset;
    MOUSE.scrolly = yoffset;
}

float redengine::mouse::x() {
    return static_cast<float>(MOUSE.x);
}

float redengine::mouse::y() {
    return static_cast<float>(MOUSE.y);
}

float redengine::mouse::dx() {
    return static_cast<float>(MOUSE.x - MOUSE.lastx);
}

float redengine::mouse::dy() {
    return static_cast<float>(MOUSE.y - MOUSE.lasty);
}

float redengine::mouse::scrollx() {
    return static_cast<float>(MOUSE.scrollx);
}

float redengine::mouse::scrolly() {
    return static_cast<float>(MOUSE.scrolly);
}

bool redengine::mouse::dragging() {
    return MOUSE.dragging;
}

bool redengine::mouse::is_pressed(int button) {
    if (button < 0 || button > 7)
        return false;
    return MOUSE.buttons & 1 << button;
}

void redengine::mouse::end_frame() {
    MOUSE.lastx = MOUSE.x;
    MOUSE.lasty = MOUSE.y;
    MOUSE.scrollx = 0;
    MOUSE.scrolly = 0;
}

void redengine::mouse::init(const glfw::window &window) {
    MOUSE.x = 0;
    MOUSE.y = 0;
    MOUSE.lastx = 0;
    MOUSE.lasty = 0;
    MOUSE.scrollx = 0;
    MOUSE.scrolly = 0;
    MOUSE.dragging = false;
    MOUSE.buttons = 0;

    glfwSetCursorPosCallback(*window, cursor_position_callback);
    glfwSetMouseButtonCallback(*window, mouse_button_callback);
    glfwSetScrollCallback(*window, scroll_callback);
}