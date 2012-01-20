#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

	ofSetLogLevel(OF_LOG_VERBOSE);
	ofBackground(34, 34, 34);
	ofSetVerticalSync(false);
	ofEnableAlphaBlending();
		
	//we load a font and tell OF to make outlines so we can draw it as GL shapes rather than textures
    
	shader.load("shaders/lighting.vert", "shaders/lighting.frag");
	
	doShader = true;	
    glEnable(GL_DEPTH_TEST) ; 
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){


	ofSetColor(225);
	string shaderToggle = ( doShader == true ) ? " toggeled on." : "toggeled off." ; 
	ofDrawBitmapString("'s' toggles shader" + shaderToggle, 10, 20);
    
	ofSetColor( 255 , 255 , 255 );
	ofFill();
    
    //Enable culling to prevent the wrong faces from rendering
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

	if( doShader ){
		shader.begin();
        //we want to pass in some varrying values to animate our type / color 
        ofVec2f normalMouse = ofVec2f ( ((float)mouseX / (float)ofGetWidth()) - 0.5f , 
                                       ((float)mouseY / (float)ofGetHeight()) - 0.5f ) ; 
       
        
        shader.setUniform2f("nMouse", normalMouse.x, normalMouse.y ) ; 
        shader.setUniform1f( "time", ofGetElapsedTimef() ) ;
	}
	
		//finally draw some spheres
        ofTranslate ( ofGetWidth() * 0.2f , ofGetHeight()/2.0f , 80.0f ) ; 
        float step = ofGetWidth() / 10.0f ; 
        for ( int i = 0 ; i < 5 ; i++ ) 
        {
            ofTranslate ( step , 0.0f , 0.0f ) ; 
            ofSphere( 0 , 0 , 0 , 40.0f ) ; 
        }
	
	if( doShader ){
		shader.end();
	}
    
    glDisable(GL_DEPTH_TEST ) ; 
    glEnd() ; 
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

