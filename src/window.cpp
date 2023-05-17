/* GLFW */
#include <GLFW/glfw3.h>

/* Local */
#include <crystal_engine/window.h>

using namespace crysal_engine;

/* Static variables */
bool Window::s_any_window_opened(false);

Window::Window(int width, int height, const std::string &title) {
    /* If no window is opened */
    if (!s_any_window_opened) {
        /* Initialize GLFW */
        if (!glfwInit()) {
            throw std::runtime_error("Failed to initialize GLFW");
        }
    }

    /* Create window */
    m_window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);

    /* If window creation failed */
    if (!window) {
        /* Terminate GLFW and throw error */
        glfwTerminate();
        throw std::runtime_error("Failed to create window");
    }

     /* Set any window opened */
    s_any_window_opened = true;
}

Window::~Window() {
    /* Destroy window */
    glfwDestroyWindow(m_window);
}

GLFWwindow *Window::window() const {
    /* Return window */
    return m_window;
}

bool Window::closed() const {
    /* Check if window is closed */
    return glfwWindowShouldClose(m_window);
}

void Window::clear() {
    /* Clear window */
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Window::swap_buffers() {
    /* Swap buffers */
    glfwSwapBuffers(m_window);
}