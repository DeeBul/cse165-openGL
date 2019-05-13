#include <iostream>
#include "App.h"

App* singleton;

void timer(int id){
    // This will get called every 16 milliseconds after
    // you call it once
    
    // If you want to manipulate the app in here
    // do it through the singleton pointer
   
    if (singleton->up){
        float ypos = singleton->projectile->getY();
        ypos +=0.05;
        singleton->projectile->setY(ypos);
        singleton->redraw();
        singleton->mush == true;
    
        
        if(singleton->projectile->getY() >= 0.86) {
            singleton->up = false;
            singleton->mush = false;
            singleton->boom->playOnce();
        }
    }
    
    glutTimerFunc(16, timer, id);
}


App::App(int argc, char** argv, int width, int height, const char* title): GlutApp(argc, argv, width, height, title){
    
    mushroom = new TexRect("/Users/darshanbulsara/Desktop/cse_165/lab_6/mushroom.png", -0.25, 0.9, 0.5, 0.5);
    projectile = new Rect(-0.05, -0.8, 0.1, 0.1);
    boom = new AnimatedRect("/Users/darshanbulsara/Desktop/cse_165/lab_6/fireball.png", 6, 6, 1000, true, true, -0.25, 0.9, 0.5, 0.5);
    up = false;
    mush = true;
    
    singleton = this;
 
    
    timer(1);
}

void App::draw() {
    
    if(singleton->mush == true) {
        mushroom->draw(0.1);
        singleton->projectile->draw();
    }
    
    if(singleton->mush == false) {
    //mushroom->draw(0.1);
   // projectile->draw();
    singleton->boom->draw(0.3);
    
    }

    }

void App::keyDown(unsigned char key, float x, float y){
    if (key == 27){
        exit(0);
    }
    if (key == ' '){
        up = true;
    }
}

App::~App(){
    delete mushroom;
    delete boom;
    std::cout << "Exiting..." << std::endl;
}
