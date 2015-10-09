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
    }
    else {
        dmxConnected = true;
        cout << "DMX connected: " << device << endl;
    }
}
//--------------------------------------------------------------
void ofApp::setupTrees(int numberOfTrees)
{
    for (int ch = 1; ch < (numberOfTrees*3); ch += 3) {
        Tree t;
        t.setup((ch/3)+1, ch);
        trees.push_back(t);
    }
}
//--------------------------------------------------------------
void ofApp::setup()
{
    counter = 0;
    setupTrees(8);
    setupDMX("/dev/tty.usbserial-EN150288");
    setupColors();
}
#pragma mark - Updates
//--------------------------------------------------------------
void ofApp::updateDMX()
{
    for (int i = 0; i < trees.size(); i++) {
        enttecBox.setLevel(trees[i].getAddresses(),trees[i].getColor().r);
        enttecBox.setLevel(trees[i].getAddresses()+1,trees[i].getColor().g);
        enttecBox.setLevel(trees[i].getAddresses()+2,trees[i].getColor().b);
    }
    enttecBox.update();
}
//--------------------------------------------------------------
void ofApp::update()
{
    if(counter > colorsArray.size()) {
        counter = 0;
    }
    if (ofGetFrameNum() % 60 == 0) {
        counter++;
    }
    for (int i = 0; i < trees.size(); i++) {
        trees[i].setColor(colorsArray[counter]);
    }
}
#pragma mark - Draw
//--------------------------------------------------------------
void ofApp::draw()
{
    ofBackground(50);
    for(int i = 0; i < colorsArray.size(); i++) {
        ofSetColor(colorsArray[i]);
        ofCircle((ofGetWidth()/2-(colorsArray.size()/2*25))+(i*25),ofGetHeight()/2,10);
    }
    
    for (int i = 0; i < trees.size(); i++) {
        trees[i].draw(25+(i*50), 50);
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
