#pragma once
#include "headers.h"

//Since these variables are not inside a struct, then we need to use the extern key word
extern std::mutex mtx1, mtx2;

void ThreadA();
void ThreadB();
