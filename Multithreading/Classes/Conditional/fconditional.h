#pragma once
#include "headers.h"

extern std::mutex mtx;
extern std::condition_variable cv;
extern int data;
extern std::queue<int> intQueue;
extern bool done;

void waiting_thread();
void notifying_thread();

void producer(int number);
void consumer();