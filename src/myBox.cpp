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
    
    
    
    
    
    
    void draw(){
        
        ofDrawBox( x, y, z, size);
        
    }
    
    
    
};







