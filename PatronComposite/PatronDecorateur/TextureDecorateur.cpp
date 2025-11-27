#include "TextureDecorateur.h"

NuageAbstrait* TextureDecorateur::getNuageAbstrait() {
    return m_nuageAbstrait;
}

string TextureDecorateur::getDescription(){
    return to_string(getId()) + ": (" + to_string(getX()) + "," + to_string(getY()) + ") textures: '" + getTexture() + "'"; 
}

int TextureDecorateur::getX() {
    return getNuageAbstrait()->getX();
}

int TextureDecorateur::getY() {
    return getNuageAbstrait()->getY();
}

int TextureDecorateur::getId(){
    return getNuageAbstrait()->getId();
}

void TextureDecorateur::setX(int x) {
    m_x = x;
}

void TextureDecorateur::setY(int y) {
    m_y = y;
}

void TextureDecorateur::setId(int id) {
    m_id = id;
}