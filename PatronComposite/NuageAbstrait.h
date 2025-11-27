#ifndef _NUAGEABSTRAIT_H_
#define _NUAGEABSTRAIT_H_

using namespace std;

#include <string>

class NuageAbstrait {
    protected:
        int m_id, m_x, m_y;
    public:
        virtual string getTexture() = 0; 
        virtual string getDescription() = 0;
        virtual void removeTexture() = 0;

        //Jsp si cest une bonne pratique vue que les nuage n'ont pas de x ou y sauf si on considere un nuage comme un forme a part entiere avec un x et y en faite je pense que cest le cas donc cest bon
        virtual int getX() = 0;
        virtual int getY() = 0;
        virtual int getId() = 0;
        virtual void setX(int x) = 0;
        virtual void setY(int y) = 0; 
        virtual void setId(int id) = 0; 

};

#endif