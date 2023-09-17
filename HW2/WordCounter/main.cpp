#include <iostream>
#include <string>
#include "WordCounter.h"
using namespace std;

int main() {
  	string text= "He is I";
	//string text = "Mrs. Dursley was thin and blonde and had nearly twice the usual amount of neck, which came in very useful as she spent so much of her time craning over garden fences, spying on the neighbors.";
	WordCounter counter;
	counter.InputText(text);
	
	cout << "Word Count: " << counter.GetWordCount() << endl;
	cout << "Character Count: " << counter.GetCharacterCount() << endl;
	cout << "Number of Unique Words: " << counter.GetUniqueWordCount() << endl;
 	cout << "The word and appears " << counter.GetWordCount_OneWord("and") << " times" << endl;
 	
 	return 0;
}