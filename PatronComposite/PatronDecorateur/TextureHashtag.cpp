#include "TextureHashtag.h"

TextureHashtag::TextureHashtag(NuageAbstrait* nuageAbstrait) : TextureDecorateur(nuageAbstrait) {}

string TextureHashtag::getTexture(){
    if(getNuageAbstrait()->getTexture() == "."){
        getNuageAbstrait()->removeTexture();
    }
    return getNuageAbstrait()->getTexture() + m_texture;
}

void TextureHashtag::removeTexture(){
    getNuageAbstrait()->removeTexture();
}