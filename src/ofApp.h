#pragma once

#include "ofMain.h"

//------------------------------------------------
// *
// * Color Definitions
// *
//------------------------------------------------
#define RED_1 ofColor(255,80,80)
#define RED_2 ofColor(255,0,0)
#define RED_3 ofColor(255,50,0)
#define RED_4 ofColor(255,80,0)

#define GREEN_1 ofColor(255,255,0)
#define GREEN_2 ofColor(0,255,0)
#define GREEN_3 ofColor(0,220,10)
#define GREEN_4 ofColor(0,140,40)

#define BLUE_1 ofColor(0,220,170)
#define BLUE_2 ofColor(0,0,255)
#define BLUE_3 ofColor(40,0,170)
#define BLUE_4 ofColor(255,0,255)

#define WHITE ofColor(255,255,255)
#define OFF ofColor(0,0,0)

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
    
    
        // Make the colors
        void setupColors();
        vector <ofColor> colorsArray;
};
