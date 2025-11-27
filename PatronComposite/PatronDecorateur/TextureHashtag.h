#ifndef _TEXTUREHASHTAG_H_
#define _TEXTUREHASHTAG_H_

#include "TextureDecorateur.h"

class TextureHashtag : public TextureDecorateur{
    private:
        string m_texture = "#";
    public:
        TextureHashtag(NuageAbstrait* nuageAbstrait);
        string getTexture() override;
        void removeTexture() override;
};

#endif