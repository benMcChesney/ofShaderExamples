#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

	ofSetLogLevel(OF_LOG_VERBOSE);
	ofBackground(34, 34, 34);
	ofSetVerticalSync(false);
	ofEnableAlphaBlending();
		
	//we load a font and tell OF to make outlines so we can draw it as GL shapes rather than textures
	font.loadFont("type/verdana.ttf", 100, true, false, true, 0.4, 72);
	shader.load("shaders/simpleShader.vert", "shaders/simpleShader.frag");
	
	doShader = true;	
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){

	ofSetColor(225);
    string shaderToggle = ( doShader == true ) ? " toggeled on." : "toggeled off." ; 
	ofDrawBitmapString("'s' toggles shader" + shaderToggle, 10, 20);

	ofSetColor(245, 58, 135);
	ofFill();
	
	if( doShader ){
		shader.begin();
			//we want to pass in some varrying values to animate our type / color 
			shader.setUniform2f("mouse", (float)mouseX / (float)ofGetWidth() , (float)mouseY / (float)ofGetHeight() );
	}
	
		//finally draw our text
		font.drawStringAsShapes("openFrameworks", 90, 260);
	
	if( doShader ){
		shader.end();
	}
}

//--------------------------------------------------------------
void testApp::keyPressed  (int key){ 
	if( key == 's' ){
		doShader = !doShader;
	}	
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){ 
	
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
	
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
	
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}

