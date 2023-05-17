#ifndef _CRYSTAL_ENGINE_WINDOW_H_
#define _CRYSTAL_ENGINE_WINDOW_H_

/* C++ */
#include <string>
#include <stdexcept>

/* GLFW */
struct GLFWwindow;

/* Crystal Engine */
namespace CrystalEngine {

/* A window class */
class Window {
public:
    /* Create a window with the given width, height and title */
    Window(int width, int height, const std::string &title);
    /* Create a window with the given title */
    Window(const std::string &title);

    /* Prevent copying */
    Window(const Window &) = delete;
    /* Prevent copying */
    Window &operator=(const Window &) = delete;

    /* Prevent moving */
    Window(Window &&) = delete;
    /* Prevent moving */
    Window &operator=(Window &&) = delete;

    /* Destroy the window */
    virtual ~Window();

    /* Get the window */
    GLFWwindow *window() const;
    /* Is the window closed? */
    virtual bool closed() const;

    /* Start the window */
    virtual void start();
    /* Update the window */
    virtual void update();

    /* Clear the window */
    virtual void clear();
    /* Swap the buffers */
    virtual void swap_buffers();
    /* Poll events */
    virtual void poll_events();

    /* Show the window */
    virtual void show();

    /* Is any window opened? */
    static bool any_window_opened();

    /* Is the window opened? */
    bool operator!() const;
    /* Is the window opened? */
    operator bool() const;

    /* Get the window */
    operator GLFWwindow *() const;

private:
    /* The window */
    GLFWwindow *m_window;
    /* Is any window opened? */
    static bool s_any_window_opened; 
};

} /* namespace crysal_engine */

#endif /* _CRYSTAL_ENGINE_WINDOW_H_ */