#include "anagramdico.h"

using namespace std;

AnagramDico::AnagramDico(QString name, QString lang, QString dicoFile) :
    Dico(name,lang, dicoFile)
{

}

void AnagramDico::generateAnagramDico()
{
    //opening dico file TO DO -> DYNAMIC NAME
    QFile inputFile(":/french_dico.txt");
    if( !inputFile.open(QIODevice::ReadOnly) ) {
        cout << inputFile.fileName().toStdString() << "can't be opened !\n";
    }

    QTextStream in(&inputFile);
    QString line;
    int i = 0;
    while( (line = in.readLine()) != nullptr) {

        //line normalization (only with ascii chars). Each line read is a word from the dico file

        QString lineNormalized = line.normalized (QString::NormalizationForm_KD); // -> decompose non ascii char into an ascii car and the associated accents
        // www.unicode.org/reports/tr15/ for normalization info
        lineNormalized.remove(QRegExp("[^a-zA-Z]")); // removing all non ascii characters
        lineNormalized.remove(QRegExp("I")); //normalization decomposition adds an "I" char when there is a non ascii char to decompose (why ?)

        // code word calculation : it gives a code CODE following this propertie :
        // "For all word W1, For all word W2, CODE(W1) == CODE(W2) if and only if W1 and W2 are anagrams
        AnagramCode code;
        code.setValue(lineNormalized);

        // adding to the anagram table. This is a map with code as key and the list of associated words as value
        QList<QString> value;    
        if(m_anagramTable.contains(code)) {
          value = m_anagramTable.value(code);
        }
        if(!value.contains(lineNormalized)) //because we remove accents before checking anagrams : in the dico there are duplicated words (such as "chateau" and "château")
            value.append(lineNormalized);

        m_anagramTable.insert(code, value);
        i++;
    }

    inputFile.close();
}


QList<QString> AnagramDico::findAnagrams(QString word)
{
    AnagramCode code;
    code.setValue(word);
    QMap<AnagramCode, QList<QString>>::iterator i = m_anagramTable.find(code);
    if(i == m_anagramTable.end()){
        return QList<QString>();
    }
    i->removeAll(word); // we remove the word from the list (removeAll bcs the word could be duplicated in the list (some words are in the dico file)
    return i.value();
}



void AnagramDico::displayAnagramDico() //for debug purposes
{
    cout << "Displaying anagram dico :\n";
    QMapIterator<AnagramCode, QList<QString>> i(m_anagramTable);
    while(i.hasNext()) {
        i.next();
        QListIterator<QString> list(i.value());
        AnagramCode key = i.key();
        if(i.value().size() >= 2) { //displaying only words that have at least 1 anagram
            cout << key.toString() << " : ";
            while(list.hasNext()) {
                cout << list.next().toStdString();
                cout << ";";
            }
            cout << endl;
        }
    }
    cout << "End anagram dico display\n\n";
}



