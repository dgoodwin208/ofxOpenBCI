#pragma once

#include "ofMain.h"
#include "ofxOpenBCIOSC.h"

using namespace ofx::IO;


class ofApp: public ofBaseApp
{
public:
    void setup();
    void update();
    void draw();

    void keyPressed(int key);

 	ofxOpenBCIOSC ofxbci;
    ofstream logFile;
    
    //cheap way of start/stop management for now
    bool boardIsStreaming;

};
