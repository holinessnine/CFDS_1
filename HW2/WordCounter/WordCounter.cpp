#include "WordCounter.h"

// Fill in here
#include <iostream>
#include <set>
#include <sstream>
#include <algorithm>

/*** Constructor ***/
WordCounter::WordCounter(){
}

/*** Inputting Text ***/
void WordCounter::InputText(std::string aText){
    text = aText;
}

/*** Get Count of Words ***/
int WordCounter::GetWordCount(void){
    int cnt = 0;
    if (!isspace(text[0]) && (!ispunct(text[0]))) // 처음이 공백, 특수문자가 아니라면 cnt=1로 시작
        cnt++;
    for (int i=0; i<text.length()-1; i++){
        if((text[i]==' ') && !isspace(text[i+1]) && !ispunct(text[i+1])) // 공백을 구분하면서, 공백이 연속되지 않는다면 단어수 +
            cnt++;
    } 
    return cnt;
}

/*** Get Count of Characters ***/
int WordCounter::GetCharacterCount(void){
    int cnt = text.length();
    for (int i=0; i<text.length(); i++){
        if (text[i]==','|| text[i]=='.' || text[i]==' ') // ',' '.' ' '는 문자 수로 취급 x
            cnt--;
    }
    return cnt;
}

/*** Get Count of Unique Words ***/
int WordCounter::GetUniqueWordCount(void){
    
    // 문장 부호 strip
    text.erase(std::remove_if(text.begin(), text.end(), ispunct), text.end());

    std::set<std::string> wset; // 중복 단어 자동으로 없애주기 위해 set 사용
    std::stringstream s(text); // sstream으로 split
    s.str(text);

    // split된 각 단어를 set에 넣기
    std::string word;
    while(s >> word) {
        wset.insert(word);
    }   

    // set의 길이(고유한 단어의 개수) 반환
    return wset.size();
}


/*** Get Count of Particular Word within Text ***/
int WordCounter::GetWordCount_OneWord(const char *oneword){
    int cnt = 0; // 못 찾은 경우를 위해 0으로 초기화
    int start = 0;

    int temp = text.find(oneword); // 일치하는 position 찾기. 없는 경우 npos값

    while (temp != std::string::npos) { // 일치하는 position 찾았을 때(oneword가 text에 있을 때)
        cnt++; // 카운트 값 증가
        start = temp+1; // 찾은 위치 이후부터 검색하도록
        temp = text.find(oneword, start);
    }
 
    return cnt;
}