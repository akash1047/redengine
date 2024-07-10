//
// Created by akash on 11-07-2024.
//

#ifndef REDENGINE_GLFW_H
#define REDENGINE_GLFW_H

#define GLFW_INCLUDE_NONE

#include <GLFW/glfw3.h>

namespace glfw {
    inline bool init() { return glfwInit(); }

    inline bool init(GLFWerrorfun f) {
        glfwSetErrorCallback(f);
        return glfwInit();
    }

    inline void terminate() { glfwTerminate(); }

    class window {
    public:
        explicit window(GLFWwindow *window_handle) : handle(window_handle) {}

        ~window() { glfwDestroyWindow(handle); }

        GLFWwindow *operator*() const { return handle; }

    private:
        GLFWwindow *handle;
    };

    enum class client_api : int {
        opengl = GLFW_OPENGL_API,
        opengl_es = GLFW_OPENGL_ES_API,
        none = GLFW_NO_API,
    };

    enum class opengl_profile : int {
        any = GLFW_OPENGL_ANY_PROFILE,
        compat = GLFW_OPENGL_COMPAT_PROFILE,
        core = GLFW_OPENGL_CORE_PROFILE,
    };

    class window_hint {
    public:
        window_hint &maximized(bool value) {
            glfwWindowHint(GLFW_MAXIMIZED, value);
            return *this;
        }

        window_hint &visible(bool value) {
            glfwWindowHint(GLFW_VISIBLE, value);
            return *this;
        }

        window_hint &resizable(bool value) {
            glfwWindowHint(GLFW_RESIZABLE, value);
            return *this;
        }

        window_hint &client_api(client_api api) {
            glfwWindowHint(GLFW_CLIENT_API, static_cast<int>(api));
            return *this;
        }

        window_hint &context_version_major(int value) {
            glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, value);
            return *this;
        }

        window_hint &context_version_minor(int value) {
            glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, value);
            return *this;
        }

        window_hint &context_version(int major, int minor) {
            glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, major);
            glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, minor);
            return *this;
        }

        window_hint &opengl_profile(opengl_profile profile) {
            glfwWindowHint(GLFW_OPENGL_PROFILE, static_cast<int>(profile));
            return *this;
        }
    };
} // namespace glfw

#endif // REDENGINE_GLFW_H
