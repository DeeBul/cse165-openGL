#ifndef App_h
#define App_h

#include "GlutApp.h"
#include "AnimatedRect.h"


class App: public GlutApp {
    TexRect* a1;
    TexRect* a2;
    AnimatedRect* cat;
public:
    
    App(int argc, char** argv, int width, int height, const char* title);
    
    void draw();
    
    void keyDown(unsigned char key, float x, float y);
    
    ~App();
    
    friend void timer(int);
    
};

#endif
