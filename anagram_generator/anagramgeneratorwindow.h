#ifndef ANAGRAMGENERATORWINDOW_H
#define ANAGRAMGENERATORWINDOW_H

#include <QWidget>
#include "anagramdico.h"

QT_BEGIN_NAMESPACE
namespace Ui { class AnagramGeneratorWindow; }
QT_END_NAMESPACE

class AnagramGeneratorWindow : public QWidget
{
    Q_OBJECT

public:
    AnagramGeneratorWindow(QWidget *parent = nullptr);
    ~AnagramGeneratorWindow();

private slots:
    void on_findAnagramsButton_clicked();

private:
    Ui::AnagramGeneratorWindow *ui;
    AnagramDico m_anagramDico;
    void loadAnagramDico();
};
#endif // ANAGRAMGENERATORWINDOW_H
