#ifndef QUESTION_H
#define QUESTION_H
#include <string>

using namespace std;

struct Question {
    string text;
    string options[4]; // Vị trí 0: A, 1: B, 2: C, 3: D
    char correctAnswer; 
};

#endif

