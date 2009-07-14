/*
 *  StreamingSounds.cpp
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

class StreamingSounds : public UnitTest
{
public:
    StreamingSounds(int argc, const char * argv[]) : UnitTest(argc, argv)
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

                /*
                * Calculate the time it takes to play the sound and the number of frames this
                * represents.
                */
                float duration = ((float) soundGenerator->getSamplesPerChannel()) / ((float) soundGenerator->getSampleRate());
                int numberOfFrames = (int) (duration * framesPerSecond);
                
                /*
                * Play the Streaming Sound.
                *
                * Calculate the number of decoded sound samples played for each frame and
                * the size, in bytes, of each block compressed sound data.
                */
                int samplesPerBlock = soundGenerator->getSampleRate() / (int) framesPerSecond;
                int numberOfBlocks = soundGenerator->getSamplesPerChannel() / samplesPerBlock;

                /* 
                * An FSSoundStreamHeader2 object defines the attributes of the streaming sound.
		        */
                movie.add(soundGenerator->streamHeader(samplesPerBlock));

                /* 
                * Add a streaming block for each frame so the sound is played as each frame 
                * is displayed.
                */
                for (int i=0; i<numberOfBlocks; i++)
                {
                    movie.add(soundGenerator->streamBlock(i, samplesPerBlock));
                    movie.add(new FSShowFrame());
                }
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
    StreamingSounds encoder(argc, argv);

    return 0;
}
