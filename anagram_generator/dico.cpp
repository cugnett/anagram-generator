#include "dico.h"



Dico::Dico(QString name, QString lang, QString dicoFile)
    : m_name(name),
      m_lang(lang)
{
    m_dicoFile.setFileName(dicoFile);
}
