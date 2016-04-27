#include "ofApp.h"


//--------------------------------------------------------------

void drawBox( int x , int y, int z, int size );
void enrollBox( int x, int y, int z, int size );
bool collision( int choice );
void updateSpriteLoc();


int heldKey = 0;
int speed = 2;
int maxSpeed = 8;
int xPos = 0;
int yPos = 0;
int zPos = 0;


bool jump = false;
int jumpHeight = 110;
bool peaked = false;
int fallspeed = 15;


#define xSize 1000
#define ySize 1000
#define zSize 1000


#define spriteSize 30
#define ground 350

bool drawn = false;

#define numBoxes 1
myBox boxField[numBoxes];

myBox sprite;



void ofApp::setup(){
    
    xPos = 250;
    yPos = 350;
    zPos = 0;
    
    boxField[0].setup( 100, ground, 0, 30 );
    sprite.setup(xPos, yPos, zPos, spriteSize );
    
    
    
}



//--------------------------------------------------------------
void ofApp::update(){
    
    
    
    
    if( heldKey == 356 ){
        
        
        //move left
        
        
        xPos -= speed;
        if( speed < maxSpeed ){
            speed += 1;
        }
        
        
        
    }else{
        
        if( heldKey == 358 ){
            
            //move right
            
            xPos += speed;
            if( speed < maxSpeed ){
                speed += 1;
            }
            
        }else{
            
            if( heldKey == 359 ){
                
                // move in
                
                zPos += speed;
                if( speed < maxSpeed ){
                    speed += 1;
                }
                
            }else{
                
                if( heldKey == 357 ){
                    
                    //move out
                    
                    zPos -= speed;
                    if( speed < maxSpeed ){
                        speed += 1;
                    }
                }
                
            }
            
        }
    }
    
    if( jump && yPos >= (ground - jumpHeight) ){
        
        yPos -= fallspeed;
        fallspeed -=1;
    }
    
    if( jump && yPos <= (ground - jumpHeight) ){
        
        peaked = true;
        jump = false;
        fallspeed = 0;
        
    }
    
    if( peaked && yPos <= ground ){
        
        yPos += fallspeed;
        fallspeed +=1;
        if( yPos >= ground ){
            
            yPos = ground;
            fallspeed = 15;
            peaked = false;
        }
        
    }
    
    
    
    
    
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofRotateX(-30);
    ofDrawAxis(200);
    
    
    // the sprite
    sprite.setup(xPos, yPos, zPos, spriteSize );
    sprite.draw();
    
    
    // the not sprites
    //  ofDrawBox( 100, ground, 0, 30 );
    for( int x = 0; x < numBoxes; x ++ ){
        boxField[x].draw();
    }
    
    
    if( !drawn ){
        
        //enrollBox( 100, ground, 0, 10 );
        // enrollBox( 200, ground, 0, 5 );
        
        drawn = true;
    }
    
    
    
}










//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    
    if( key == 356 || key == 358 || key == 357 || key == 359 ){
        heldKey = key;
    }
    
    if( key == 32 && !peaked ){
        
        jump = true;
        
    }
    
    //std::cout << "x: " << key << endl;
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
    if( key == 356 || key == 358 || key == 357 || key == 359){
        heldKey = 0;
        speed = 2;
    }
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
    // std::cout << "x: " << x << "y: "  << y << endl;
    
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
