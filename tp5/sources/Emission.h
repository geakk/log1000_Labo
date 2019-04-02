#ifndef Emission_H
#define Emission_H

#include <string>
#include "Chaine.h"

using namespace std;
        
// Cette classe représente un Emission
class Emission {
public:
    // Constructeurs
    Emission();
    Emission(string, string, string, string, string);
    ~Emission();
    
    // Setters
    void setTitre(string);
    void setAnimateur(string);
    void setChaine(Chaine* chaine);
    
    // Getters
    string getTitre() const;
    string getAnimateur() const;
    Chaine* getChaine() const;
    
    // Enregistrer l'Emission
    void saveEmission(string);
    // Afficher l'Emission
    void afficher();
    // Chercher un Emission dans une base de données par titre
    Emission* trouverEmission(string, string);

    string lireDonnee(int &i,string line);
    
private:
    // Information sur l'emission
    string titre_;
    string animateur_;
    Chaine* chaine_;
};

#endif 
