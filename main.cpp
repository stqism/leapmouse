#include <iostream>
#include <X11/Xlib.h>
//#include <X11/X.h>
//#include <X11/Xutil.h>
#include "Leap.h"

using namespace std;
using namespace Leap;

//void setcur(char a,b){
//	XWarpPointer(dpy, None, root_window, a, b, 0, 0, 100, 100);
//}

int main(){
	Display *dpy;
	Window root;
	Controller controller;
	Frame frame = controller.frame();

	dpy = XOpenDisplay(0);
	root = XRootWindow(dpy,0);
	XSelectInput(dpy,root,KeyReleaseMask);
	int x,y;
	while(1){ cout << "Tick";
		if (frame.pointables().count() > 0) {
			cout << "Tock";
			Pointable pointable = frame.pointables()[0];
			ScreenList screens = controller.calibratedScreens();
			Leap::Screen screen = screens.closestScreenHit(pointable);
			Vector normalizedCoordinates = screen.intersect(pointable, true);
			x = (int)(normalizedCoordinates.x * screen.widthPixels());
			y = screen.heightPixels() - (int)(normalizedCoordinates.y * screen.heightPixels());
			XWarpPointer(dpy, None, root, x, y, 0, 0, 1000, 1000);
        		XFlush(dpy);
		};
	};
}
