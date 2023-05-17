#ifndef _CRYSTAL_ENGINE_WINDOW_H_
#define _CRYSTAL_ENGINE_WINDOW_H_

/* C++ */
#include <string>

/* GLFW */
struct GLFWwindow;

/* Crystal Engine */
namespace crysal_engine {

/* An abstract window class */
class Window {
public:
    /* Create a window with the given width, height and title */
    Window(int width, int height, const std::string &title);
    /* Destroy the window */
    virtual ~Window();

    /* Get the window */
    GLFWwindow *window() const;
    /* Is the window closed? */
    virtual bool closed() const;

    /* Start the window */
    virtual void start() = 0;
    /* Update the window */
    virtual void update() = 0;

    /* Clear the window */
    virtual void clear();
    /* Swap the buffers */
    virtual void swap_buffers();
    /* Poll events */
    virtual void poll_events();

private:
    /* The window */
    GLFWwindow *window;
};

} /* namespace crysal_engine */

#endif /* _CRYSTAL_ENGINE_WINDOW_H_ */