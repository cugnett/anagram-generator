#include "anagramgeneratorwindow.h"
#include "ui_anagramgeneratorwindow.h"

#include <QFile>
#include <QTextStream>
#include <iostream>


AnagramGeneratorWindow::AnagramGeneratorWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AnagramGeneratorWindow)
    , m_anagramDico("test", "francais", nullptr) //IS IT A GOOD SOLUTION TO ADD M_ANAGRAM_DICO AS A MEMBER OF the AnagramGeneratorWindow ??
{
    ui->setupUi(this);
    loadAnagramDico();
}

AnagramGeneratorWindow::~AnagramGeneratorWindow()
{
    delete ui;
}


void AnagramGeneratorWindow::on_findAnagramsButton_clicked()
{
    //finding the anagrams of the word into the lineEdit
    QString searchString = ui->lineEdit->text();
    ui->textEdit->find(searchString, QTextDocument::FindWholeWords);
    QList<QString> result = m_anagramDico.findAnagrams(searchString);

    //displaying the result into the textEdit
    QString stringResult("");
    if(result.isEmpty()) {
        stringResult = "This word has no anagram !\n";
    } else {
        QListIterator<QString> list(result);
        while(list.hasNext()) {
            stringResult.append(list.next());
            stringResult.append("\n");
        }
    }
    ui->textEdit->setText(stringResult);

}

void AnagramGeneratorWindow::loadAnagramDico()
{
    m_anagramDico.generateAnagramDico();
    // m_anagramDico.displayAnagramDico(); //for debug purposes
}
