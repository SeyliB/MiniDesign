#ifndef _TEXTUREO_H_
#define _TEXTUREO_H_

#include "TextureDecorateur.h"

class TextureO : public TextureDecorateur{
    private:
        string m_texture = "o";
    public:
        TextureO(NuageAbstrait* nuageAbstrait);
        string getTexture() override;
        void removeTexture() override;
};

#endif