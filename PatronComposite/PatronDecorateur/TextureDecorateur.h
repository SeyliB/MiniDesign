#ifndef _TEXTUREDECORATEUR_H_
#define _TEXTUREDECORATEUR_H_

#include "../NuageAbstrait.h"

class TextureDecorateur : public NuageAbstrait {
    private:
        NuageAbstrait* m_nuageAbstrait;
    public:
        TextureDecorateur(NuageAbstrait* nuageAbstrait) : m_nuageAbstrait(nuageAbstrait) {}
        NuageAbstrait* getNuageAbstrait();
        string getDescription() override;
        int getX();
        int getY();
        int getId();
        void setX(int x);
        void setY(int y);
        void setId(int id);

};

#endif