#pragma once

// Fill in here
#include <string>
class WordCounter {
public:
WordCounter(); // constructor

void InputText(std::string);
int GetWordCount(void);
int GetCharacterCount(void);
int GetUniqueWordCount(void);
int GetWordCount_OneWord(const char *);

protected:
std::string text;
};