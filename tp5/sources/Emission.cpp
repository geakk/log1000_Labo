#include "Emission.h"

#include <fstream>
#include <iostream>

// Constructeur
Emission::Emission (string titre,
                  string animateur,
                  string chaineName,
                  string chaineCodePostal,
                  string chaineAddress) {
    // Emission information
    this->titre = titre;
    this->animateur = animateur;
    
    // Chaine information
    this->chaineName = chaineName;
    this->chaineCodePostal = chaineCodePostal;
    this->chaineAddress = chaineAddress;
    
}

// Setters
void Emission::setTitre(string titre) {
    this->titre = titre;
}
void Emission::setAnimateur(string animateur) {
    this->animateur = animateur;
}

// Associer un chaine à l'Emission
void Emission::associerChaine (string chaineName,
                               string chaineCodePostal,
                               string chaineAddress) {
    this->chaineName = chaineName;
    this->chaineCodePostal = chaineCodePostal;
    this->chaineAddress = chaineAddress;
}


// Getters
string Emission::getTitre() {
    return this->titre;
}
string Emission::getAnimateur() {
    return this->animateur;
}

string Emission::getChaineName() {
    return this->chaineName;
}

string Emission::getChaineCodePostal() {
    return this->chaineCodePostal;
}

string Emission::getChaineAddress() {
    return this->chaineAddress;
}


// Enregistrer l'Emission dans un fichier
void Emission::saveEmission (string fileName) {

    ofstream outfile (fileName.c_str(), std::ofstream::binary | std::fstream::app);
    // write to outfile
    outfile<<this->titre <<","
                   <<this->animateur <<","
                   <<this->chaineName << ","
                   <<this->chaineCodePostal << ","
                   <<this->chaineAddress <<"\n";
 
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
    std::cout << "Titre : " << this->titre << std::endl;
    std::cout << "Animateur : " << this->animateur << std::endl;
    std::cout << "Chaine name : " << this->chaineName << std::endl;
    std::cout << "Chaine code postale : " << this->chaineCodePostal << std::endl;
    std::cout << "Chaine address : " << this->chaineAddress << std::endl;
}



