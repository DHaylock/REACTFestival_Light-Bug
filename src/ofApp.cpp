#include "ofApp.h"

#pragma mark - Setups
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
void ofApp::setupDMX(string device)
{
    enttecBox.connect(device);
    if (!enttecBox.isConnected()) {
        cout << "DMX not connected" << endl;
        dmxConnected = false;
//        return;
    }
    else {
        dmxConnected = true;
        cout << "DMX connected: " << device << endl;
    }
}
//--------------------------------------------------------------
void ofApp::setup()
{
    setupDMX("/dev/tty.usbserial-EN150288");
    setupColors();
}
#pragma mark - Updates
//--------------------------------------------------------------
void ofApp::updateDMX()
{
    
    enttecBox.update();
}
//--------------------------------------------------------------
void ofApp::update()
{


}
#pragma mark - Draw
//--------------------------------------------------------------
void ofApp::draw()
{
    ofBackground(255, 255, 255);
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
