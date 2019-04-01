#ifndef Emission_H
#define Emission_H

#include <string>

using namespace std;
        
// Cette classe représente un Emission
class Emission {
public:
    // Constructeurs
    Emission () {}
    Emission(string, string, string, string, string);
    
    // Setters
    void setTitre(string);
    void setAnimateur(string);
    
    void associerChaine(string, string, string);
    
    // Getters
    string getTitre();
    string getAnimateur();
    
    string getChaineName();
    string getChaineCodePostal();
    string getChaineAddress();
    
    // Enregistrer l'Emission
    void saveEmission(string);
    // Afficher l'Emission
    void afficher();
    // Chercher un Emission dans une base de données par titre
    Emission* trouverEmission(string, string);
    
private:
    // Information sur l'emission
    string titre;
    string animateur;
	
    
    // Informations sur la chaine de l'emission
    string chaineName;
    string chaineCodePostal;
    string chaineAddress;
    
};

#endif 
