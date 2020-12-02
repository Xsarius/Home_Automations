#include "data_saver.h"

File backup;

void SaveCurrentPosition(int currentSteps)
{
    backup = SPIFFS.open("backup.txt", "w");
    backup.write(currentSteps);
}

int ReadBackup()
{
    backup = SPIFFS.open("backup.txt", "r");
    int backupedStepps = (int)backup.read();
    return backupedStepps;
}