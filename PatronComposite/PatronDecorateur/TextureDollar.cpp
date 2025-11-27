#include "TextureDollar.h"

TextureDollar::TextureDollar(NuageAbstrait* nuageAbstrait) : TextureDecorateur(nuageAbstrait) {}

string TextureDollar::getTexture(){
    if(getNuageAbstrait()->getTexture() == "."){
        getNuageAbstrait()->removeTexture();
    }
    return getNuageAbstrait()->getTexture() + m_texture;
}

void TextureDollar::removeTexture(){
    getNuageAbstrait()->removeTexture();
}