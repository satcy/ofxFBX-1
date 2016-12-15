//
//  ofxFBXCamera.cpp
//  ofxFBX-Example-Importer-Animations
//
//  Created by satcy on 2016/12/14.
//
//
#include "ofxFBX.h"
#include "ofxFBXCamera.h"

void ofxFBXCamera::updateLookAt(){
    float  length = (target - ofCamera::getGlobalPosition()).length();
    
    ofVec3f rotationVector(1.0,0,0);
    ofVec3f center = ofCamera::getGlobalOrientation() * rotationVector;
    center *= length;
    center += ofCamera::getPosition();
    
    
    rotationVector.set(0,1.0,0);
    ofVec3f up = ofCamera::getGlobalOrientation() * rotationVector;
    
    ofVec3f forward = center - ofCamera::getGlobalPosition();
    forward.normalize();
    ofVec3f right = up.cross(forward);
    right.normalize();
    up = forward.cross(right);
    up.normalize();
    
    ofCamera::lookAt(center,up);
}

void ofxFBXCamera::setTime(u_long ms){
    ofCamera::setOrientation(getRotationAt(ms));
    ofCamera::setPosition(getPositionAt(ms));
    ofCamera::setScale(getScaleAt(ms));
    updateLookAt();
}


void ofxFBXCamera::setFrame(u_int frame){
    ofCamera::setOrientation(getRotationAtFrame(frame));
    ofCamera::setPosition(getPositionAtFrame(frame));
    ofCamera::setScale(getScaleAtFrame(frame));
    updateLookAt();
}
