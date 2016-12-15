//
//  ofxFBXCamera.h
//  ofxFBX-Example-Importer-Animations
//
//  Created by satcy on 2016/12/14.
//
//

#pragma once

#include "ofConstants.h"
#include "ofVec3f.h"
#include "ofCamera.h"
#include "ofxFBXNode.h"


class ofxFBXCamera: public ofCamera, public ofxFBXNode{
public:
    void setTime(unsigned long ms);
    void setFrame(unsigned int frame);
protected:
    ofVec3f target;
private:
    void updateLookAt();
    friend class ofxFBXScene;
};
