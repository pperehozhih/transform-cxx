/*
 *  Shapes.cpp
 *  Transform Utilities
 *
 *  Created by smackay on Wed May 26 2004.
 *  Copyright (c) 2001-2003 Flagstone Software Ltd. All rights reserved.
 *
 *  This code is distributed on an 'AS IS' basis, WITHOUT WARRANTY OF ANY KIND, EITHER
 *  EXPRESS OR IMPLIED, AND Flagstone HEREBY DISCLAIMS ALL SUCH WARRANTIES, INCLUDING
 *  WITHOUT LIMITATION, ANY WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR
 *  PURPOSE, AND NONINFRINGEMENT OF THIRD PARTY RIGHTS.
 */

#include "UnitTest.hpp"

class Shapes : public UnitTest
{
public:
    Shapes(int argc, const char * argv[]) : UnitTest(argc, argv)
    {
        string dirOut = stringOption(options, "dirOut");
        string fileOut = "Shapes.swf";
    
    #ifdef WIN32
        fileOut = dirOut + "\\" + fileOut;
    #else
        fileOut = dirOut + "/" + fileOut;
    #endif

        try 
        {
            FSShapeConstructor* path = ShapeConstructor();
            FSMovie movie;
            
            path->COORDINATES_ARE_PIXELS = true;
            
            int width = 150;
            int height = 100;
            int cornerRadius = 10;
            
            int identifier = 0;
            
            path->addLineStyle(new FSSolidLine(20, FSColorTable::black()));
            path->addFillStyle(new FSSolidFill(FSColorTable::red()));
            
            movie.setFrameRate(1.0f);
            movie.setFrameSize(FSBounds(-4000, -4000, 4000, 4000));
            movie.add(new FSSetBackgroundColor(FSColorTable::lightblue()));
            
            identifier = movie.newIdentifier();
            
            path->selectStyle(0, 0, -1);
            path->rect(width/2, -height/2, width, height);
            movie.add(path->defineShape(identifier));
            movie.add(new FSPlaceObject2(identifier, 1, 0, 0));
            movie.add(new FSShowFrame());
            
            /*
            * Draw a rectangle with rounded corners
            */
            identifier = movie.newIdentifier();

            path->newPath();
            path->selectStyle(0, 0, -1);
            path->rect(width/2, height/2, width, height, cornerRadius);
            movie.add(path->defineShape(identifier));
            movie.add(new FSPlaceObject2(identifier, 1));
            movie.add(new FSShowFrame());

            /*
            * Draw a circle
            */
            identifier = movie.newIdentifier();

            path->newPath();
            path->selectStyle(0, 0, -1);
            path->circle(-width/2, height/2, height/2);
            movie.add(path->defineShape(identifier));
            movie.add(new FSPlaceObject2(identifier, 1));
            movie.add(new FSShowFrame());
            
            /*
            * Draw a elipse
            */
            identifier = movie.newIdentifier();

            path->newPath();
            path->selectStyle(0, 0, -1);
            path->ellipse(-width/2, -height/2, width/2, height/2);
            movie.add(path->defineShape(identifier));
            movie.add(new FSPlaceObject2(identifier, 1));
            movie.add(new FSShowFrame());
            
            /*
            * Draw a polyline
            */
            identifier = movie.newIdentifier();

            size_t size = 28;

            int points[] = { 
                0, -100, 
                10, 0, 
                0, 90, 
                90, 0, 
                0, 20,
                -90, 0,
                0, 90,
                -20, 0,
                0, -90,
                -90, 0,
                0, -20,
                90, 0,
                0, -90,
                10, 0
            };

            path->newPath();
            path->selectStyle(0, 0, -1);
            path->polygon(points, size);
            movie.add(path->defineShape(identifier));
            movie.add(new FSPlaceObject2(identifier, 1));
            movie.add(new FSShowFrame());
            
            /*
            * Draw a cubic bezier curve
            */
		    identifier = movie.newIdentifier();

		    path->newPath();
		    path->selectStyle(0, 0, -1);
		    path->curve(0, -100, 150, -100, 150, 0);
		    path->closePath();
		    movie.add(path->defineShape(identifier));
		    movie.add(new FSPlaceObject2(identifier, 1));
		    movie.add(new FSShowFrame());
    		
		    movie.encodeToFile(fileOut.c_str());

            delete path;
        }
        catch (FSException e)
        {
            cerr << e.what();
        }
    }
};

int main (int argc, const char * argv[])
{
    Shapes encoder(argc, argv);

    return 0;
}
