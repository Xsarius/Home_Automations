#include <Arduino.h>
#include <FS.h>
#include "config.h"

extern File backup;

void SaveCurrentPosition(int);

int ReadBackup();