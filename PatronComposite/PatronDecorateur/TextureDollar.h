#ifndef _TEXTUREDOLLAR_H_
#define _TEXTUREDOLLAR_H_

#include "TextureDecorateur.h"

class TextureDollar : public TextureDecorateur{
    private:
        string m_texture = "$";
    public:
        TextureDollar(NuageAbstrait* nuageAbstrait);
        string getTexture() override;
        void removeTexture() override;
};

#endif