#include "anagramgeneratorwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    AnagramGeneratorWindow w;
    w.show();
    return a.exec();
}
