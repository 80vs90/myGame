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
bool canjump = true;

int jumpHeight = 0;
int fallspeed = 15;


#define xSize 1000
#define ySize 1000
#define zSize 1000




#define spriteSize 50
#define defaultGround 350
int ground = 350;

ofVec3f camPos(250, 350, -1000);
ofVec2f lastMouse;

bool drawn = false;

#define numBoxes 1
myBox boxField[numBoxes];

myBox sprite;



void ofApp::setup(){
   xPos = 250;
   yPos = 350;
   zPos = 0;
   
   
   boxField[0].setup( 100, ground, 0, 50 );
   
   sprite.setup(xPos, yPos, zPos, spriteSize );

   cam.setPosition(camPos);
   cam.tilt(180);
   ofAddListener(ofEvents().mouseScrolled, this, &ofApp::mouseScrolled);
   ofAddListener(ofEvents().mouseDragged, this, &ofApp::mouseDragged);
   ofAddListener(ofEvents().mousePressed, this, &ofApp::mousePressed);
}



//--------------------------------------------------------------
void ofApp::update(){
    cam.setPosition(camPos);
    if( sprite.collidesY( boxField[0] ) ){
      ground = boxField[0].getMaxY() - spriteSize / 2;
    }else{
      // cout << "Not" << endl;
      ground = defaultGround;
    }
    
    if( heldKey == 356 ){
        //move left
        if( !sprite.collidesX( boxField[0], speed ) ){
               xPos -= speed;
                if( speed < maxSpeed ){
                    speed += 1;
                }
        }
    }else{
        
        if( heldKey == 358 ){
            //move right
            if( !sprite.collidesX( boxField[0], speed * -1 ) ){
                xPos += speed;
                if( speed < maxSpeed ){
                    speed += 1;
                }
            }
           
            
        }else{
            
            
            /**
            if( heldKey == 359 ){
                
                // move in
                
                
                
                if(!sprite.collidesZ( boxField[0], speed * -1  ) ){
                    
                    zPos += speed;
                    if( speed < maxSpeed ){
                        speed += 1;
                    }
                }
                
            }else{
                
                if( heldKey == 357 ){
                    
                    //move out
                    if(!sprite.collidesZ( boxField[0], speed ) ){

                        zPos -= speed;
                        if( speed < maxSpeed ){
                            speed += 1;
                        }
                    }
                }
                
            }
             **/
            
        }
    }
    
    if( jump ){
        if( jumpHeight < 20 ){
            yPos -= fallspeed;
            if( fallspeed >= 1){
                
                fallspeed --;
            }

            jumpHeight ++;
        }

        if( jumpHeight == 20 ){
            jumpHeight = 0;
            fallspeed = 0;
            jump = false;
        }
    }

    if( !jump && yPos <= ground ){
        
             if( fallspeed < 15 )fallspeed ++;
             yPos += fallspeed;
        
    }
    
    
    if( !jump && yPos >= ground ){
        
        canjump = true;
        fallspeed = 0;
        yPos = ground;
    }
    
   ground = defaultGround;
}

//--------------------------------------------------------------
void ofApp::draw(){
    cam.begin();
    //ofRotateX(-30);
    ofDrawAxis(200);
    
    // the not sprites
    //  ofDrawBox( 100, ground, 0, 30 );
    for( int x = 0; x < numBoxes; x ++ ){
        
        ofSetColor(0,0,0);
        boxField[x].draw();
    }
    
    
    if( !drawn ){
        
        //enrollBox( 100, ground, 0, 10 );
        // enrollBox( 200, ground, 0, 5 );
        
        drawn = true;
    }
    
    // the sprite
    ofSetColor(255,255,255);
    sprite.setup(xPos, yPos, zPos, spriteSize );
    sprite.draw();
    cam.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    
    if( key == 356 || key == 358 || key == 357 || key == 359 ){
        heldKey = key;
    }
    
    if( key == 32 && canjump ){
        
        canjump = false;
        fallspeed = 15;
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
void ofApp::mouseDragged(ofMouseEventArgs & mouse){
   if (mouse.button == 0) {
      ofVec2f offset = lastMouse - mouse;
      camPos.x = camPos.x + offset.x;
      camPos.y = camPos.y + offset.y;

      lastMouse = mouse;
   } else if (mouse.button == 2) {
      // Rotate around origin
   }
}

//--------------------------------------------------------------
void ofApp::mousePressed(ofMouseEventArgs & mouse){
   lastMouse = mouse;
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseScrolled(ofMouseEventArgs & mouse){
   camPos.z = camPos.z + mouse.scrollY * 30;
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
