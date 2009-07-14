/*
 *  TextString.cpp
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

class TextString : public UnitTest
{
public:
    TextString(int argc, const char * argv[]) : UnitTest(argc, argv)
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
	            FSTextConstructor* textGenerator = TextConstructor();
                FSMovie movie;

                string message = "The quick, brown fox jumped over the lazy dog.";

		        int layer = 0;
		        int fontSize = 280;
		        int lineSpacing = fontSize;
        		
		        int leftMargin = fontSize;
		        int rightMargin = fontSize;
		        int topMargin = fontSize;
		        int bottomMargin = fontSize;
        		
                if (textGenerator->setFontFromFile(fileIn.c_str()) != TransformUtil::OK)
                    throw FSException("Could not load font file");

                FSColor black = FSColorTable::black();

                textGenerator->setIdentifier(movie.newIdentifier());
                textGenerator->setSize(fontSize);
                textGenerator->setColor(&black);

                FSDefineText2* text = textGenerator->defineText(movie.newIdentifier(), message.c_str());
                FSDefineShape3* shape = textGenerator->defineShape(movie.newIdentifier(), message.c_str());
		        FSDefineFont2* font = textGenerator->defineFont();

		        int screenWidth = text->getBounds().getWidth() + leftMargin + rightMargin;
		        int screenHeight = text->getBounds().getHeight() + fontSize + topMargin + bottomMargin;
                
		        movie.setFrameSize(FSBounds(0, 0, screenWidth, screenHeight));
		        movie.setFrameRate(1.0f);
                movie.add(new FSSetBackgroundColor(FSColorTable::lightblue()));
		        movie.add(font);
		        movie.add(text);
		        movie.add(shape);
		        movie.add(new FSPlaceObject2(text->getIdentifier(), ++layer, leftMargin , topMargin));
		        movie.add(new FSPlaceObject2(shape->getIdentifier(), ++layer, leftMargin , topMargin+fontSize));
		        movie.add(new FSShowFrame());

                movie.encodeToFile(fileOut.c_str());

                delete textGenerator;
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
    TextString encoder(argc, argv);

    return 0;
}
