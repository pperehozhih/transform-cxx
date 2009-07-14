/*
 *  EventSounds.cpp
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

class EventSounds : public UnitTest
{
public:
    EventSounds(int argc, const char * argv[]) : UnitTest(argc, argv)
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
                FSMovie movie;
                FSSoundConstructor* soundGenerator = SoundConstructor();
                
                if (soundGenerator->setSoundFromFile(fileIn.c_str()) != TransformUtil::OK)
                {
                    throw FSException("Could not load sound file");
                }

		        float framesPerSecond = 12.0f;

		        movie.setFrameSize(FSBounds(0, 0, 8000, 4000));
		        movie.setFrameRate(framesPerSecond);
            
                movie.add(new FSSetBackgroundColor(FSColorTable::lightblue()));

		        int soundId = movie.newIdentifier();

		        /*
		        * Calculate the time it takes to play the sound and the number of frames this
		        * represents.
		        */
		        float duration = ((float) soundGenerator->getSamplesPerChannel()) / ((float) soundGenerator->getSampleRate());
		        int numberOfFrames = (int) (duration * framesPerSecond);
                
		        /*
		        * Add the sound definition and the FSStartSound object which is used to start
		        * the sound playing.
		        */
                
		        FSDefineSound* sound = soundGenerator->defineSound(soundId);
                
		        movie.add(sound);
                movie.add(new FSStartSound(FSSound(soundId, FSSound::Start)));

		        /* 
		        * Add frames to give the sound time to play.
		        */
		        for (int i=0; i<numberOfFrames; i++)
			        movie.add(new FSShowFrame());

                movie.encodeToFile(fileOut.c_str());

                delete soundGenerator;
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
    EventSounds encoder(argc, argv);

    return 0;
}
