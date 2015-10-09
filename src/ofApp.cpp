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
    doneOnce = false;
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
    if (!doneOnce) {
        if (command.length() > 0) {
            string cut = command.substr(1,command.length());
            split.clear();
            split = ofSplitString(cut, ",");
            for(int i = 0; i < split.size(); i++) {
                if (i == split.size()-1) {
                    cout << split[i] << endl;
                }
                else {
                    cout << split[i] << " ";
                }
            }
        }
        for (int i = 0; i < split.size(); i++) {
            
            
            if (split[i].substr(0,1) == "1") {
                cout << "We Have A 1" << endl;
                if (split[i].substr(2,1) == "R") {
                    if (split[i].substr(3,1) == "1") {
                        trees[0].setColor(RED_1);
                    }
                    else if (split[i].substr(3,1) == "2") {
                        trees[0].setColor(RED_2);
                    }
                    else if (split[i].substr(3,1) == "3") {
                        trees[0].setColor(RED_3);
                    }
                    else if (split[i].substr(3,1) == "4") {
                        trees[0].setColor(RED_4);
                    }
                }
                else if (split[i].substr(2,1) == "G") {
                    if (split[i].substr(3,1) == "1") {
                        trees[0].setColor(GREEN_1);
                    }
                    else if (split[i].substr(3,1) == "2") {
                        trees[0].setColor(GREEN_2);
                    }
                    else if (split[i].substr(3,1) == "3") {
                        trees[0].setColor(GREEN_3);
                    }
                    else if (split[i].substr(3,1) == "4") {
                        trees[0].setColor(GREEN_4);
                    }
                }
                else if (split[i].substr(2,1) == "B") {
                    if (split[i].substr(3,1) == "1") {
                        trees[0].setColor(BLUE_1);
                    }
                    else if (split[i].substr(3,1) == "2") {
                        trees[0].setColor(BLUE_2);
                    }
                    else if (split[i].substr(3,1) == "3") {
                        trees[0].setColor(BLUE_3);
                    }
                    else if (split[i].substr(3,1) == "4") {
                        trees[0].setColor(BLUE_4);
                    }
                }
            }
            else if (split[i].substr(0,1) == "2") {
                cout << "We Have A 2" << endl;
                if (split[i].substr(2,1) == "R") {
                    if (split[i].substr(3,1) == "1") {
                        trees[2].setColor(RED_1);
                    }
                    else if (split[i].substr(3,1) == "2") {
                        trees[2].setColor(RED_2);
                    }
                    else if (split[i].substr(3,1) == "3") {
                        trees[2].setColor(RED_3);
                    }
                    else if (split[i].substr(3,1) == "4") {
                        trees[2].setColor(RED_4);
                    }
                }
                else if (split[i].substr(2,1) == "G") {
                    if (split[i].substr(3,1) == "1") {
                        trees[2].setColor(GREEN_1);
                    }
                    else if (split[i].substr(3,1) == "2") {
                        trees[2].setColor(GREEN_2);
                    }
                    else if (split[i].substr(3,1) == "3") {
                        trees[2].setColor(GREEN_3);
                    }
                    else if (split[i].substr(3,1) == "4") {
                        trees[2].setColor(GREEN_4);
                    }
                }
                else if (split[i].substr(2,1) == "B") {
                    if (split[i].substr(3,1) == "1") {
                        trees[2].setColor(BLUE_1);
                    }
                    else if (split[i].substr(3,1) == "2") {
                        trees[2].setColor(BLUE_2);
                    }
                    else if (split[i].substr(3,1) == "3") {
                        trees[2].setColor(BLUE_3);
                    }
                    else if (split[i].substr(3,1) == "4") {
                        trees[2].setColor(BLUE_4);
                    }
                }
            }
        }
        doneOnce = true;
    }
    

//    if (command == ALL_OFF) {
//        for (int i = 0; i < trees.size(); i++) {
//            trees[i].setColor(OFF);
//        }
//    }
//    else if (command == ALL_ON_WHITE) {
//        for (int i = 0; i < trees.size(); i++) {
//            trees[i].setColor(WHITE);
//        }
//    }
//    if(counter > colorsArray.size()) {
//        counter = 0;
//    }
//    if (ofGetFrameNum() % 60 == 0) {
//        counter++;
//    }
//    for (int i = 0; i < trees.size(); i++) {
//        trees[i].setColor(colorsArray[counter]);
//    }
}
#pragma mark - Draw
//--------------------------------------------------------------
void ofApp::draw()
{
    ofBackground(50);
    for(int i = 0; i < colorsArray.size(); i++) {
        ofSetColor(colorsArray[i]);
        ofCircle(25, (ofGetHeight()/2-(colorsArray.size()/2*25))+(i*25), 10);
    }
    
    for (int i = 0; i < trees.size(); i++) {
        trees[i].draw(25+(i*50), 50);
    }
}
//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
    string a;
    switch (key) {
        case 'f':
            command = "";
            a = "#"+ofToString(T1_ON_B1)+","+ofToString(T2_ON_B4)+","+ofToString(T5_ON_G3);
            command = a;
            doneOnce = false;
            break;
        case 'O':
            command = "";
            a = "#"+ofToString(ALL_ON_WHITE);
            command = a;
            doneOnce = false;
            break;
            
            default:

                break;
    }
}
//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{

}
