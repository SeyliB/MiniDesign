#include "Executeur.h"

void Executeur::setCommand(Commande* cmd) {
    if(cmd != nullptr){
        m_cmd = cmd;
    }
}

void Executeur::executeCommand() {
    if(m_cmd != nullptr){
        m_cmd->execute();
        m_lastCmds.push(m_cmd);
    }
}

void Executeur::undoCommand() {
    if(!m_lastCmds.empty()){
        Commande* cmd = m_lastCmds.front();
        cmd->undo();
        m_lastUndoCmds.push(cmd);
        m_lastCmds.pop();
    }
}

void Executeur::redoCommand() {
    if(!m_lastUndoCmds.empty()){
        if(!m_lastUndoCmds.empty()){
            Commande* cmd = m_lastUndoCmds.front();
            cmd->redo();
            //A voir si ici cest la bonne logique pour les scenarios
            m_lastCmds.push(cmd);
            m_lastUndoCmds.pop();
        }
    }
}