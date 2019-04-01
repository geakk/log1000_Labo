#include <iostream>
#include "Emission.h"

using namespace std;

/*
 * fonction principale
 */
int main(int argc, char** argv) {
    
    Emission* emission = new Emission(); // Création d'un emission
    string DBFile = "DB.txt"; // Fichier qui contient une base des emissions
    int choix; // Opération séléctionnée par l'utilisateur
   
    do {
        // Afficher les opérations possibles
        std::cout << std::endl << "--------------------------------------" << std::endl;
        std::cout << "0 - Quitter le programme " << std::endl;
        std::cout << "1 - Créer une emission " << std::endl;
        std::cout << "2 - Trouver une emission " << std::endl;
        std::cout << "3 - Afficher une emission " << std::endl;
        std::cout << "4 - Enregistrer l'émission " << std::endl;
        std::cout << "--------------------------------------" << std::endl;
        
        // Lire le choi d'utilisateur
        std::cin >> choix;
        
        switch (choix) {
            case 1:
            {
                // Informations du nouvel emission
                string titre;
                string animateur;
                string chaineName;
                string chaineCodePostal;
                string chaineAddress;
                // Demander l'utilisateur de saisir les informatins du nouvel emission
                std::cout << "Saisir le titre de l'émission : " ;
                std::cin >> titre;
                std::cout << "Saisir l'animateur de l'émission : " ;
                std::cin >> animateur;
                std::cout << "Saisir le nom de la chaine : " ;
                std::cin >> chaineName;
                std::cout << "Saisir le code postale de la chaine : " ;
                std::cin >> chaineCodePostal;
                std::cout << "Saisir l'addresse de la chaine : " ;
                std::cin >> chaineAddress;
                // Créer un nouvel emission
                delete emission;
                emission = new Emission (titre, animateur, chaineName, chaineCodePostal, chaineAddress);       
                break;
            }
            case 2:
            {
                // Demander l'utilisateur de saisir le nom d'emission à chercher dans la base de données
                string titre;
                std::cout << "Saisir le titre de titre l'émission : " ;
                std::cin >> titre;
                // Chercher l'emission
                Emission* tmp = emission->trouverEmission(DBFile, titre);
                if (tmp != NULL) {// Si l'emission est trouvé
                    emission = tmp;
		     std::cout << "Emission trouvée !" << std::endl;	
                } else {
                    std::cout << "Aucune émission trouvée !" << std::endl;
                }
                break;
            }
            case 3:
            {
                // Afficher l'emission
                if (emission != NULL) {
                    emission->afficher();
                } else {
                    std::cout << "Aucune émission séléctionnée" << std::endl;
                }
                break;
            }
            case 4:
            {
                // Enregistrer l'emission dans la base de données.
                if (emission != NULL) {
		    	
                    emission->saveEmission(DBFile);
                    std::cout << "Emission enregistrée !" << std::endl;
                }
            }
        }        
    } while (choix!= 0); // Tant que l'utilisateur ne décide pas de quitter le programmme
    
    return 0;
}

