#ifndef __Clone_h__
#define __Clone_h__

#include "UnitTest.hpp"

#include <transform/FSMovie.h>

class Clone : public UnitTest
{
public:
    Clone(int argc, const char * argv[]) : UnitTest(argc, argv)
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
            fileOut = dirOut + "\\" + fileIn;
            fileIn = dirIn + "\\" + fileIn;
#else
            fileOut = dirOut + "/" + fileIn;
            fileIn = dirIn + "/" + fileIn;
#endif
            FSMovie* aMovie = new FSMovie();
            aMovie->decodeFromFile(fileIn.c_str(), this);

            FSMovie* movieClone = new FSMovie();

            movieClone->setVersion(aMovie->getVersion());
            movieClone->setFrameSize(aMovie->getFrameSize());
            movieClone->setFrameRate(aMovie->getFrameRate());

            for (FSVector<FSMovieObject*>::iterator i = aMovie->getObjects().begin(); i != aMovie->getObjects().end(); ++i)
                movieClone->add((*i)->clone());

            movieClone->encodeToFile(fileOut.c_str(), this);

            delete aMovie;
        }
    }

    void logEvent(FSMovieEvent anEvent)
    {
        string logMessage;

        UnitTest::logEvent(anEvent);
    
        if (anEvent.getAction() == FSMovieEvent::Encode)
        {
            switch (anEvent.getEvent())
            {
                case FSMovieEvent::Begin:
				    logMessage = anEvent.getType();
                    break;
                default:
                    break;
            }
        }
    
        if (logMessage.length() > 0 && currentLevel < logLevel)
            cout << prefix << logMessage << endl;
    }
};

int main (int argc, const char * argv[])
{
    Clone cloner(argc, argv);
}

#endif