#pragma once
#include "headers.h"

extern std::mutex mtx;
extern std::condition_variable cv;
extern bool ready;

void waiting_thread();
void notifying_thread();