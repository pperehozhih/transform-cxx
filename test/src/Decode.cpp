#ifndef __Decode_h__
#define __Decode_h__

#include "UnitTest.hpp"

#include <transform/FSMovie.h>

class Decode : public UnitTest
{
public:
    Decode(int argc, const char * argv[]) : UnitTest(argc, argv)
    {
        vector<string> files;
    
        string dirIn = stringOption(options, "dirIn");
        string dirOut = stringOption(options, "dirOut");

        string fileIn = "";
        string fileOut = "";
    
        findFiles(dirIn, files);
        
        for (vector<string>::iterator i = files.begin(); i != files.end(); ++i)
        {
		    fileIn = *i;

            cout << fileIn << endl;

#ifdef WIN32
            fileIn = dirIn + "\\" + fileIn;
            fileOut = dirOut + "\\" + fileIn;
#else
            fileIn = dirIn + "\\" + fileIn;
            fileOut = dirOut + "/" + fileIn;
#endif
            FSMovie* aMovie = new FSMovie();
            aMovie->decodeFromFile(fileIn.c_str(), this);

            delete aMovie;
        }
    }

    void logEvent(FSMovieEvent anEvent)
    {
        string logMessage;

	  UnitTest::logEvent(anEvent);
    
        switch (anEvent.getEvent())
        {
            case FSMovieEvent::Begin:
                logMessage = anEvent.getType();
                break;
            default:
                break;
        }
    
        if (logMessage.length() > 0 && currentLevel < logLevel)
            cout << prefix << logMessage << endl;
    }
};

int main (int argc, const char * argv[])
{
    Decode decoder(argc, argv);
}

#endif