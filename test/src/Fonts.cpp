/*
 *  Fonts.cpp
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

class Fonts : public UnitTest
{
public:
    Fonts(int argc, const char * argv[]) : UnitTest(argc, argv)
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

		        int layer = 0;
		        int fontSize = 280;
		        int lineSpacing = fontSize;
        		
		        int leftMargin = fontSize;
		        int rightMargin = fontSize;
		        int topMargin = fontSize;
		        int bottomMargin = fontSize;
        		
		        wchar_t *lines[32];

                wchar_t* line = new wchar_t[65];
		        wchar_t c = 1;

		        for (int i=0; i<32; i++)
		        {
                    wchar_t* line = new wchar_t[65];

                    for (int j=0; j<64; j++, c++)
				        line[j] = c;

                    line[64] = '\0';

                    lines[i] = line;
		        }
        		
                if (textGenerator->setFontFromFile(fileIn.c_str()) != TransformUtil::OK)
                    throw FSException("Could not load font file");

                FSColor black = FSColorTable::black();

                textGenerator->setIdentifier(movie.newIdentifier());
                textGenerator->setSize(fontSize);
                textGenerator->setColor(&black);

                FSDefineText2* text = textGenerator->defineWideTextBlock(movie.newIdentifier(), (const wchar_t **)lines, 32, lineSpacing);
		        FSDefineFont2* font = textGenerator->defineFont();

		        int screenWidth = text->getBounds().getWidth() + leftMargin + rightMargin;
		        int screenHeight = text->getBounds().getHeight() + topMargin + bottomMargin;
                
		        movie.setFrameSize(FSBounds(0, 0, screenWidth, screenHeight));
		        movie.setFrameRate(1.0f);
                movie.add(new FSSetBackgroundColor(FSColorTable::lightblue()));
		        movie.add(font);
		        movie.add(text);
		        movie.add(new FSPlaceObject2(text->getIdentifier(), ++layer, leftMargin , topMargin));
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
    Fonts encoder(argc, argv);

    return 0;
}
