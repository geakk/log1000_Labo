#include <string>

using namespace std;
        
// Cette classe représente un Emission
class Chaine {
public:
    // Constructeurs
    Chaine(string name, string codePostal, string address);
    
    // Setters
    void setName(string nom);
    void setCodePostal(string codePostal);
    void setAddress(string adress);
    
    // Getters
    string getName() const;
    string getCodePostal() const;
    string getAddress() const;

    // Enregistrer l'Emission
   
    // Afficher l'Emission

    // Chercher un Emission dans une base de données par titre
  
    
private:
    string name_;
    string codePostal_;
    string address_;
    
};