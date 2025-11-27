#include "TextureO.h"

TextureO::TextureO(NuageAbstrait* nuageAbstrait) : TextureDecorateur(nuageAbstrait) {}

string TextureO::getTexture(){
    if(getNuageAbstrait()->getTexture() == "."){
        getNuageAbstrait()->removeTexture();
    }
    return getNuageAbstrait()->getTexture() + m_texture;
}

void TextureO::removeTexture(){
    getNuageAbstrait()->removeTexture();
}