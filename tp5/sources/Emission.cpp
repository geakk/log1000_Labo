#include "Emission.h"

#include <fstream>
#include <iostream>

// Constructeur
Emission::Emission (string titre,
                    string animateur,
                    string nomChaine, 
                    string codePostalChaine,
                    string addressChaine) {
    // Emission information
    titre_ = titre;
    animateur_ = animateur;
    chaine_ = new Chaine(nomChaine, codePostalChaine, addressChaine);
}

Emission::Emission(){}


Emission::~Emission()
{
    delete chaine_;
}

// Setters
void Emission::setTitre(string titre) {
    titre_ = titre;
}
void Emission::setAnimateur(string animateur) {
    animateur_ = animateur;
}

// Associer un chaine à l'Emission
void Emission::setChaine (Chaine* chaine) {
    chaine_ = chaine;
}


// Getters
string Emission::getTitre() const{
    return titre_;
}
string Emission::getAnimateur() const{
    return animateur_;
}

Chaine* Emission::getChaine() const{
    return chaine_;
}

// Enregistrer l'Emission dans un fichier
void Emission::saveEmission (string fileName) {

    ofstream outfile (fileName.c_str(), std::ofstream::binary | std::fstream::app);
    // write to outfile
    outfile<< titre_ <<","
                   << animateur_ <<","
                   << (*chaine_).getName() << ","
                   << (*chaine_).getCodePostal() << ","
                   << (*chaine_).getAddress() <<"\n";
 
    outfile.close();
}

// Trouver un Emission avec son nom dans la base de données DB
Emission* Emission::trouverEmission (string DB, string titre) {
    
    ifstream fichier(DB.c_str(), ios::in); // Ouvrir le fichier "DB.txt"
    Emission*tmp=NULL;
	
    if(fichier)
    {
        string line;
        // Lire les Emissions, un Emission par ligne dans la base de données (DB.txt)
        while (getline(fichier, line)) {
            string titreDB;
            // Récupérer le nom de l'Emission
            int i = 0;
            for (i = 0 ; i < line.length() ; i++) {
                if (line[i] != ',') {
                    titreDB += line[i];
                } else {
                    break;
                }
            }
          
            
            // Si l'Emission qu'on lit actuellement est celui qu'on cherche
            if (titreDB == titre) {
                
                // Récupérer le nom de l'animateur
                string animateurDB;
                for (i = i + 1; i < line.length() ; i++) {
                    if (line[i] != ',') {
                        animateurDB += line[i];
                    } else {
                        break;
                    }
                }
                
                //  Récupérer le nom de l'éditeur
                string chaineNameDB;
                for (i = i + 1; i < line.length() ; i++) {
                    if (line[i] != ',') {
                        chaineNameDB += line[i];
                    } else {
                        break;
                    }
                }
                
                // Récupérer le code postale de l'éditeur
                string chaineCodePostalDB;
                for (i = i + 1; i < line.length() ; i++) {
                    if (line[i] != ',') {
                        chaineCodePostalDB += line[i];
                    } else {
                        break;
                    }
                }
                
                // Récupérer l'addresse de l'éditeur
                string chaineAddressDB;
                for (i = i + 1; i < line.length() ; i++) {
                    if (line[i] != ',') {
                        chaineAddressDB += line[i];
                    } else {
                        break;
                    }
                }
               
                // Créer un objet de type Emission avec les informations récupérées
                Emission *a = new Emission(titreDB, animateurDB, chaineNameDB, chaineCodePostalDB, chaineAddressDB);
                // Fermer la base de données
                fichier.close();
                // Retourner l'Emission sélectionné
                return a;
            }
        }
        // Fermer la base de données
        fichier.close();
    }
    // Si l'Emission est innexistant, on retourne NULL
    return NULL;

}

// Afficher l'Emission
void Emission::afficher() {
    std::cout << "Titre : " << titre_ << std::endl;
    std::cout << "Animateur : " << animateur_ << std::endl;
    std::cout << "Chaine name : " << (*chaine_).getName()  << std::endl;
    std::cout << "Chaine code postale : " << (*chaine_).getCodePostal() << std::endl;
    std::cout << "Chaine address : " << (*chaine_).getAddress() << std::endl;
}



