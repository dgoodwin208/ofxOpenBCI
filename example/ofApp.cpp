
#include "ofApp.h"

//------------------------------------------------------------------------------
void ofApp::setup()
{
   ofxbci.startStreaming();
    
    time_t seconds = time(NULL);
    ostringstream filename;
    
    filename << "~/Desktop/l" << seconds << ".csv";
    cout << "Filename: " << filename.str().c_str();
    logFile.open(filename.str().c_str());
    logFile << "timestamp,prompt,chan0,chan1,chan2,chan3,chan4,chan5,chan6,chan7,\n";
    
    
}

//------------------------------------------------------------------------------
void ofApp::update()
{
    
    //Get any and all bytes off the serial port
    ofxbci.update(false); //Param is to echo to the command line
    if(ofxbci.isNewDataPacketAvailable())
    {
        vector<openBCIPacket> newData = ofxbci.getData();
        
        printf("Sees %lu new packets\n", newData.size());
        
        //Saving just two data channels for purposes of example
        for (int i=0; i<newData.size(); ++i) {
            logFile << newData[i].values[0] << ",";
            logFile << newData[i].values[1] << ",";            
            logFile << "\n";
        }
    }

    
}


//------------------------------------------------------------------------------
void ofApp::draw()
{
	
}

//------------------------------------------------------------------------------
void ofApp::keyPressed(int key)
{

    if (key==OF_KEY_RETURN)
    {
        if(!boardIsStreaming){
            ofHttpResponse res = ofLoadURL("http://localhost:5000/board/stream/start");
            boardIsStreaming = true;
        }
        else{
            ofHttpResponse res = ofLoadURL("http://localhost:5000/board/stream/stop");
            boardIsStreaming = false;
        }
    }

   
}

