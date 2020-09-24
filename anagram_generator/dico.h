#ifndef DICO_H
#define DICO_H

#include <QFile>
#include <QString>


	class Dico {
		
		public:
            Dico(QString name, QString lang, QString dicoFile);
			
					
		
		private:
            QString m_name; ///< Dictionnary name
            QString m_lang; ///< Dictionnary lang
            QFile   m_dicoFile; ///< dicoFile, is a file which should contain lines with the following structure : "word;code"

			
			
	};


#endif
