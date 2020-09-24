#ifndef ANAGRAMCODE_H
#define ANAGRAMCODE_H

#include <QString>


class AnagramCode
{
public:
    AnagramCode();
    QString value() const { return  m_value; }
    std::string toString();
    void setValue(QString word);



private:
    QString m_value;

};

bool operator>(AnagramCode const& a, AnagramCode const& b);
bool operator<(AnagramCode const& a, AnagramCode const& b);

#endif // ANAGRAMCODE_H
