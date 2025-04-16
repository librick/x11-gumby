#include <X11/Xlib.h>
#include <X11/cursorfont.h>
#include <cstdlib>

int main() {
    Display* display = XOpenDisplay(nullptr);
    if (!display) return 1;

    int screen = DefaultScreen(display);
    Window root = RootWindow(display, screen);

    // Create a simple window
    Window win = XCreateSimpleWindow(display, root,
                                     100, 100, 400, 300, 1,
                                     BlackPixel(display, screen),
                                     WhitePixel(display, screen));

    // Select events to listen for
    XSelectInput(display, win, ExposureMask | KeyPressMask);

    // Map (show) the window
    XMapWindow(display, win);

    // Set the cursor
    Cursor cursor = XCreateFontCursor(display, XC_gumby);
    XDefineCursor(display, win, cursor);

    XEvent event;
    while (true) {
        XNextEvent(display, &event);
        if (event.type == KeyPress)
            break;
    }

    XFreeCursor(display, cursor);
    XDestroyWindow(display, win);
    XCloseDisplay(display);
    return 0;
}

