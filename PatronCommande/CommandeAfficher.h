#ifndef _CommandeAfficher_H_
#define _CommandeAfficher_H_

using namespace std;

#include "Commande.h"
// #include "affichage.h"
#include <vector>

class CommandeAfficher : public Commande
{
private:
    //Ici cest la le truc de patron strategie rentre en jeu (mais cest pas coder ici)
    //Save la classe affichage ici genre Affichage* m_affichage
    // vector<Point>& m_pointsTest;
public:
    CommandeAfficher() {} //Ici ca sera  CommandeAfficher(Affichage* affichage) : m_affichage(affichage) {}
    ~CommandeAfficher() = default;
    virtual void execute() override; 
};



#endif