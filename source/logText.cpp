#include "logText.h"

#include <cstdio>
#include <cstdlib>
#include <cstring>
//#include <map>
//#include <string>
//#include <vector>

void writeToPath(char *text, char const * path) {
    FILE* fSave = fopen( path, "w" );
    if (fSave != NULL) {
        fputs(text, fSave);
    }
    fclose(fSave);
}

void logTextP(char *text, char const * path) {
    writeToPath(text, path);

    /*
    FILE* fLoad = fopen( LOG_PATH, "r" );
    
    if (fLoad != NULL) {
        fseek(fLoad, 0L, SEEK_END);
        int currentSize = ftell(fLoad);
        fseek(fLoad, 0L, SEEK_SET);
        
        char currentLog[currentSize];
        fgets(currentLog, currentSize, fLoad);
        
        int newSize = sizeof(text);
        char newLog[currentSize + newSize + 2];
        
        strcpy(newLog, currentLog);
//        strcat(newLog, currentLog);
        strcat(newLog, "\n");
        strcat(newLog, text);
        
        fclose(fLoad);
        write(newLog);
    }
    else {
        fclose(fLoad);
        write(text);
    }
     */
}

void logU8(uint8_t i, char * label) {
    char s[strlen(label)+8];
    sprintf(s, "%s: %u", label, i);
    logText(s);
}

void logInt(int i, char * label) {
    char s[strlen(label)+8];
    sprintf(s, "%s: %d", label, i);
    logText(s);
}

void logText(char *text) {
    char const * path = "sdmc:/log.txt";
    logTextP(text, path);
}