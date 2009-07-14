#ifndef __UnitTest_h__
#define __UnitTest_h__

#include <string>
#include <vector>
#include <map>
#include <utility>
#include <iostream>

#ifdef WIN32
#include <io.h>
#include <direct.h>
#else
#include <dirent.h>
#endif

#include <transform/FSMovieListener.h>

using namespace std;
using namespace transform;

class UnitTest : public FSMovieListener
{
public:
    UnitTest(int argc, const char * argv[])
    {
        getOptions(argc, argv, options);

        logLevel = intOption(options, "logLevel");
    }

void getOptions(int argc, const char * args[], map<string, string>& options)
{
    for (int i=1; i<argc; i++)
    {
        string anOption = args[i];

        if (anOption.substr(0, 2) == "--")
        {
            string optionName = anOption.substr(2);
            string optionValue = "";

            if (i+1 < argc && strncmp(args[i+1], "--", 2) != 0)
                optionValue = args[i+1];

            options[optionName] = optionValue;
        }
    }
}

int intOption(map<string, string>& options, string optionName)
{
    int value = 0;

    if (options.find(optionName) != options.end())
    {
        string str = options[optionName];
        sscanf(str.c_str(), "%d", &value);
    }
    return value;
}

string stringOption(map<string, string>& options, string optionName)
{
    string data;

    if (options.find(optionName) != options.end())
    {
        data = options[optionName];
    }
    return data;
}

#ifdef WIN32

void findFiles(string rootDir, vector<string>& files)
{
    intptr_t findResult;
    struct _finddata_t fileInfo;

    char currentDir[_MAX_PATH];

    if (_getcwd(currentDir, _MAX_PATH) != NULL)
    {
        if (_chdir(rootDir.c_str()) == 0)
        {
            findResult = _findfirst("*", &fileInfo);

            if ((fileInfo.attrib & _A_SUBDIR) == 0)
            {
                char *extension = strrchr(fileInfo.name, '.');

                if (extension != NULL && strncmp(extension, ".swf", 4) == 0)
                    files.push_back(fileInfo.name);
            }

            while (_findnext(findResult, &fileInfo) == 0)
            {
                if ((fileInfo.attrib & _A_SUBDIR) == 0)
                {
                    char *extension = strrchr(fileInfo.name, '.');

                    if (extension != NULL && strncmp(extension, ".swf", 4) == 0)
                        files.push_back(fileInfo.name);
                }
            }
            _findclose(findResult);
        }
        _chdir(currentDir);
    }
}

#else

void findFiles(string rootDir, vector<string>& files)
{
    DIR *dir = opendir(rootDir.c_str());

    struct dirent *entry;

    while((entry = readdir(dir)) != NULL)
    {
        if (entry->d_type != DT_DIR)
        {
            char *extension = strrchr(entry->d_name, '.');

            if (extension != NULL && strncmp(extension, ".swf", 4) == 0)
                files.push_back(entry->d_name);
        }
    }
    closedir(dir);
}

#endif

    void logEvent(transform::FSMovieEvent anEvent)
    { 
        switch (anEvent.getEvent())
        {
            case FSMovieEvent::Begin:
                currentLevel++;
                prefix += "  ";
                break;
            case FSMovieEvent::End:
                currentLevel--;
                prefix = prefix.substr(2);
                break;
            default:
                break;
        }
    } 

protected:
    map<string, string> options;

    int logLevel;
    int currentLevel;
    std::string prefix;
};

#endif