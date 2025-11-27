#include "PatronCommande/Executeur.h"
#include "PatronCommande/CommandeAfficher.h"
// #include "affichage.h"
#include <windows.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "PatronComposite/Point.h"
#include "PatronComposite/Nuage.h"
#include "PatronComposite/PatronDecorateur/TextureO.h"
#include "PatronComposite/PatronDecorateur/TextureHashtag.h"
#include "PatronComposite/PatronDecorateur/TextureDollar.h"


using namespace std;

int main(int argc, char* argv[]) {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    string getInitialInput(int argc, char* argv[]);

    /////////////////////////////////////////////////////////////////////////////////////////////////////////
    //TEEEESSSSSST Decorateur
    NuageAbstrait* p1 = new Point(0,5,0);
    NuageAbstrait* p2 = new Point(1,14,16);
    cout << p1->getDescription() << "\n";
    cout << p2->getDescription() << "\n";

    //Ajout de texture (ca sera fait quand on fait une fusion [f])
    p1 = new TextureO(p1);
    p1 = new TextureHashtag(p1);

    //pour get la description lors de laffichage avec cmd [a]
    cout << p1->getDescription() << "\n";
    cout << p2->getDescription() << "\n";

    //TEESSSSST NUAGE
    Nuage* n1 = new Nuage(0,0); //Je sais pas si je devrais initaliser un nuage avec un vecteur de points je pense c'est meilleur mais un nuage de point devrait aussi avoir une position x et y je pense
    
    cout << n1->getDescription() << "\n";
    
    n1->addPoint(1,p1);
    n1->addPoint(2,p2);
    cout << n1->getDescription() << "\n";

    // n1->removePoint(1);
    n1->removePoint(2);
    cout << n1->getDescription() << "\n";
    ////////////////////////////////////////////////////////////////////////////////////////////////////////
    

    string args = getInitialInput(argc, argv);
    Executeur executeur;
    string cmd;
    // Menu
    while (true) {
        cout << "\nCommandes:\n"
                  << "a  - Afficher les points et les nuages\n"
                  << "o1 - Afficher l'orthèse avec les textures des points\n"
                  << "o2 - Afficher l'orthèse avec les IDs des points\n"
                  << "f  - Fusionner des points dans un nuage (et appliquer texture)\n"
                  << "d  - Deplacer un point (ID)\n"
                  << "s  - Supprimer un point (ID)\n"
                  << "u  - Annuler la dernière commande (undo)\n"
                  << "r  - Réappliquer la dernière commande annulée (redo)\n"
                  << "c1 - Créer les surfaces selon l'ordre des IDs\n"
                  << "c2 - Créer les surfaces selon la distance minimale\n"
                  << "q  - Quitter\n> ";
        getline(cin, cmd);

        //Je peut ameliorer ca avec une map [string, fonction]
        if (cmd == "a"){
            executeur.setCommand(new CommandeAfficher()); //Entre les () de CommandeAfficher c'est la que je met la bonne stratégie d'affichage genre new AffichageList()
        }else if (cmd == "o1") {
            executeur.setCommand(new CommandeAfficher()); //Entre les () de CommandeAfficher c'est la que je met la bonne stratégie d'affichage genre new AffichageTextures()
        }else if (cmd == "o2") {
            executeur.setCommand(new CommandeAfficher()); //Entre les () de CommandeAfficher c'est la que je met la bonne stratégie d'affichage genre new AffichageIDs()
        }else if (cmd == "f") {

        }else if (cmd == "d") {

        }else if (cmd == "s") {

        }else if (cmd == "u") {
            executeur.undoCommand();
        }else if (cmd == "r") {
            executeur.redoCommand();
        }else if (cmd == "c1") {

        }else if (cmd == "c2") {

        }else if (cmd == "q") {
            break;
        }
        
        //ici execute la commande avec l'executeur (Jsp pas encore comment je gere le undo et redo mais ce if peut causer probleme)
        if(!cmd.empty()){
            executeur.executeCommand();
        }

    }
    return 0;
}


string getInitialInput(int argc, char* argv[]){
    string args;
    if (argc > 1) {
        ostringstream oss;
        for (int i = 1; i < argc; ++i) oss << argv[i] << " ";
        args = oss.str();
    } else {
        cout << "Entrez les points au format (x,y) :\n> ";
        getline(cin, args);
    }
        return args;
}

