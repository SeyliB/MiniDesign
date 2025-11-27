#ifndef _COMMANDE_H_
#define _COMMANDE_H_

class Commande {
    public:
        virtual ~Commande() = default;
        virtual void execute() = 0;
        virtual void undo(){ execute();} //Jsp encore si faut que je fasse = 0
        virtual void redo() { execute();}
};

#endif