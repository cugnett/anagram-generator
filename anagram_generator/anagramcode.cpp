#include "anagramcode.h"

#include <iostream>
using namespace std;

AnagramCode::AnagramCode()
{

}

string AnagramCode::toString()
{
    return m_value.toStdString();
}

void AnagramCode::setValue(QString word)
{
    QString code("");
    int countLetter = 0;
    for(char i = 'a'; i<='z'; ++i) { //code is made of count letter in the word from 'a' to 'z'
        //Ex : "abbacccxz" gives "2230000000000...00101" code (26 chars in total)
        countLetter = word.count(i);
        code.append(QString::number(countLetter));

    }
    m_value = code;
}

bool operator<(AnagramCode const& a, AnagramCode const& b)
{
    return a.value() < b.value();
}

bool operator>(AnagramCode const& a, AnagramCode const& b)
{
    return a.value() > b.value();
}



