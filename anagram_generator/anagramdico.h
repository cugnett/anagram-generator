#ifndef ANAGRAMDICO_H
#define ANAGRAMDICO_H

#include <QMap>
#include <QTextStream>
#include <iostream>


#include "anagramcode.h"
# include "dico.h"

class AnagramDico : public Dico
{
public:
    AnagramDico(QString name, QString lang, QString dicoFile);
    void generateAnagramDico();
    void displayAnagramDico();
    QList<QString> findAnagrams(QString word);

private:
    QMap<AnagramCode, QList<QString>> m_anagramTable;
};

#endif // ANAGRAMDICO_H
