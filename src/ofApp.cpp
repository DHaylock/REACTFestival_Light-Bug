#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setupColors()
{
    colorsArray.push_back(RED_1);
    colorsArray.push_back(RED_2);
    colorsArray.push_back(RED_3);
    colorsArray.push_back(RED_4);
    
    colorsArray.push_back(GREEN_1);
    colorsArray.push_back(GREEN_2);
    colorsArray.push_back(GREEN_3);
    colorsArray.push_back(GREEN_4);
    
    colorsArray.push_back(BLUE_1);
    colorsArray.push_back(BLUE_2);
    colorsArray.push_back(BLUE_3);
    colorsArray.push_back(BLUE_4);
    
    colorsArray.push_back(WHITE);
    colorsArray.push_back(OFF);
}
//--------------------------------------------------------------
void ofApp::setup()
{
    setupColors();
}
//--------------------------------------------------------------
void ofApp::update()
{

}
//--------------------------------------------------------------
void ofApp::draw()
{
    for(int i = 0; i < colorsArray.size(); i++) {
        ofSetColor(colorsArray[i]);
        ofCircle((ofGetWidth()/2-(colorsArray.size()/2*25))+(i*25),ofGetHeight()/2,10);
    }
}
//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{

}
//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{

}
