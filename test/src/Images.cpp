/*
 *  Images.cpp
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

class Images : public UnitTest
{
public:
    Images(int argc, const char * argv[]) : UnitTest(argc, argv)
    {
        vector<string> files;
    
        string dirIn = stringOption(options, "dirIn");
        string dirOut = stringOption(options, "dirOut");
        string extension = stringOption(options, "ext");

        string fileIn = "";
        string fileOut = "";
    
        findFiles(dirIn, files, extension);
        
        for (vector<string>::iterator i = files.begin(); i != files.end(); ++i)
        {
            fileIn = *i;
            fileOut = fileIn.substr(0, fileIn.find_first_of('.')) + ".swf";

            cout << fileIn << endl;

    #ifdef WIN32
            fileOut = dirOut + "\\" + fileOut;
    #else
            fileOut = dirOut + "/" + fileOut;
    #endif

            try 
            {
                /* Create the FSImages object used to generate the object
                * containing the image definition. Initialize it using the name of 
                * the image file passed on the command line when the exanple was run.
                */
                FSImageConstructor* imageGenerator = ImageConstructor();
            
                if (imageGenerator->setImageFromFile(fileIn.c_str()) != TransformUtil::OK)
                {
                    throw FSException("Could not load image file");
                }

                FSMovie movie;
            
                int imageId = movie.newIdentifier();
                int shapeId = movie.newIdentifier();
            
                int xOrigin = imageGenerator->getWidth()/2;
                int yOrigin = imageGenerator->getHeight()/2;
            
                // Generate the image defintion
                FSDefineObject* image = imageGenerator->defineImage(imageId);
            
                /*
                * All images must be displayed as a bitmap fill inside a shape. The 
                * FSImages class generates the shape enclosing the image.
                * If no border is required then the line style may be set to null.
                */
                FSColor black = FSColorTable::black();

                FSDefineShape3* shape = imageGenerator->defineShape(shapeId, imageId, -xOrigin, -yOrigin, 20, &black);
            
                /* 
                * Add all the objects together to create the movie.
                */
                movie.setFrameRate(1.0f);
                movie.setFrameSize(shape->getBounds());
                movie.add(new FSSetBackgroundColor(FSColorTable::lightblue()));
                movie.add(image);
                movie.add(shape);
                movie.add(new FSPlaceObject2(shapeId, 1, 0, 0));
                movie.add(new FSShowFrame());
            
                movie.encodeToFile(fileOut.c_str());

                delete imageGenerator;
            }
            catch (FSException e)
            {
                cerr << e.what();
            }
        }
    }
};

int main (int argc, const char * argv[])
{
    Images encoder(argc, argv);

    return 0;
}
