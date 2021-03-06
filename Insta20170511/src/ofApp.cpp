#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(0);
	ofEnableDepthTest();
	ofSetFrameRate(60);
	ofSetWindowTitle("NoiseBox");

	this->x_noise = ofRandom(10.0);
	this->y_noise = ofRandom(10.0);
	this->z_noise = ofRandom(10.0);

	this->font_size = 30;
	this->font.loadFont("fonts/Kazesawa-Bold.ttf", this->font_size);
	this->moji = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	cam.begin();

	float tmp_x_noise = x_noise;
	float tmp_y_noise = y_noise;
	float tmp_z_noise = z_noise;
	float noise_value = 0.0025;

	int font_span = this->font_size * 3;

	for (int x = 0; x <= this->x_len; x++) {

		tmp_x_noise += noise_value;
		tmp_y_noise = y_noise;
		for (int y = 0; y <= this->x_len; y++) {

			tmp_y_noise += noise_value;
			tmp_z_noise = z_noise;
			for (int z = 0; z <= this->z_len; z++) {
				ofVec3f location = ofVec3f(x * font_span - (this->x_len * font_span) / 2, y * font_span - (this->y_len * font_span) / 2, z * font_span - (this->z_len * font_span) / 2);
				float moji_index = ofMap(ofNoise(tmp_x_noise, tmp_y_noise, tmp_z_noise), 0, 1, 0, this->moji.length());

				ofColor c;
				c.setHsb(255 * ofNoise(tmp_x_noise, tmp_y_noise, tmp_z_noise), 255, 255);
				ofSetColor(c);
				
				ofPushMatrix();
				ofTranslate(location);
				this->font.drawString(this->moji.substr(moji_index, 1), 0, 0);
				ofPopMatrix();

				tmp_z_noise += noise_value;
			}
		}
	}

	this->x_noise += noise_value;
	this->y_noise += noise_value;
	this->z_noise += noise_value;

	cam.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
