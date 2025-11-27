#ifndef _EXECUTEUR_H_
#define _EXECUTEUR_H_

#include "Commande.h"
#include <queue>

using namespace std;


class Executeur {
    private:
    Commande* m_cmd;
    queue<Commande*> m_lastCmds;
    queue<Commande*> m_lastUndoCmds;  
    public:
    Executeur() : m_cmd(nullptr) {}
    virtual ~Executeur() = default; //Jsp encore si ca pourrait causer des erreurs
    void setCommand(Commande* cmd);
    void executeCommand();
    void undoCommand();
    void redoCommand();
};

#endif