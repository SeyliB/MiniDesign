#include "Nuage.h"
#include <algorithm>

string Nuage::getTexture(){
    return m_textures;
}

string Nuage::getDescription(){
    if(m_points.empty()){return "Le nuage est vide";}

    m_textures = m_points.begin()->second->getTexture().back();

    string description = "Nuage '" + m_textures + "' contient les éléments:";

    for (const auto& pair : m_points) { //Ici va peut etre falloir genre inverser lordre du print live ca fait 2 1 au lieu de 1 2 mais je peux le fix en inversant la maniere dont je add les points au nuage
        int id = pair.first;
        description += " " + to_string(id);
    }

    return description; 
}

void Nuage::removeTexture(){
    m_textures = "";
}

int Nuage::getX(){
    return m_x;
}

int Nuage::getY(){
    return m_y;
}

int Nuage::getId(){
    return m_id;
}

void Nuage::setX(int x) {
    m_x = x;
}

void Nuage::setY(int y) {
    m_y = y;
}
void Nuage::setId(int id) {
    m_id = id;
}

Nuage::Nuage(int x, int y) {
    setX(x);
    setY(y);
}

void Nuage::addPoint(int id, NuageAbstrait* point){
    m_points[id] = point;
}

void Nuage::removePoint(int id){
    m_points.erase(id);
}