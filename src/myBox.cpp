//
//  box.cpp
//  myTestApp
//
//  Created by Adam Nastasia on 4/26/16.
//
//


#include "ofMain.h"

class myBox {
    
private:
    
    int x;
    int y;
    int z;
    int size;
    
    
    int maxx;
    int maxy;
    int maxz;
    
    int minx;
    int miny;
    int minz;
    
    
public:
    
    
    myBox(){
        x = 0;
        y = 0;
        z = 0;
        size = 0;
        
        maxx = 0;
        maxy = 0;
        maxz = 0;
        
        minx = 0;
        miny = 0;
        minz = 0;
    }
    
    void setup( int xcor, int ycor, int zcor, int sz ){
        
        x = xcor;
        y = ycor;
        z = zcor;
        size = sz;
        
        maxx = x + (size/2);
        maxy = y - (size/2);
        maxz = z + (size/2);
        
        
        minx = x - (size/2);
        miny = y + (size/2);
        minz = z - (size/2);
        
    }
    
    
    
    int getMaxX(){
        
        return maxx;
    }
    int getMaxY(){
        
        return maxy;
    }
    
    int getMaxZ(){
        
        return maxz;
    }
    
    int getMinX(){
        
        return minx;
    }
    int getMinY(){
        
        return miny;
    }
    int getMinZ(){
        
        return minz;
    }
    
    
    
    
    
    
    bool collidesX( myBox b, int speed ){
        
        
        if(minx - speed <= b.getMaxX() && maxx - speed >= b.getMinX() ){
            
            if(minz<= b.getMaxZ() && maxz >= b.getMinZ() ){
                
                if(miny <= b.getMinY() && maxy >= b.getMaxY()){
                    cout << "collide" << endl;
                    return true;
                }
                
            }

            
        }
        
        return false;
    }
    
    bool collidesZ( myBox b, int speed ){
        
        
        if(minx <= b.getMaxX() && maxx >= b.getMinX() ){
            
            if(minz - speed <= b.getMaxZ() && maxz - speed >= b.getMinZ() ){
                
                if(miny <= b.getMinY() && maxy >= b.getMaxY()){
                    
                    return true;
                }
                
            }
            
            
        }
        
        return false;
    }
    
    bool collidesY( myBox b ){
        
    
            
            if(minx <= b.getMaxX() && maxx >= b.getMinX() ){
                
            
                    return true;
                
            }
        
        return false;
    }

    

    

    

    
    int getSize(){
        
        
        return size;
    }
    
    
    
    
    void draw(){
        
        //ofDrawBox( x, y, z, size);
        ofDrawRectangle( x, y, z, size, size );
        
    }
    
    
    
};







