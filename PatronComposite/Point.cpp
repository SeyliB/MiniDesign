#include "Point.h"

string Point::getTexture(){
    return m_textures;
}

string Point::getDescription(){
    return to_string(getId()) + ": (" + to_string(m_x) + "," + to_string(m_y) + ") textures: '" + getTexture() + "'"; 
}

void Point::removeTexture(){
    m_textures = "";
}

int Point::getX(){
    return m_x;
}

int Point::getY(){
    return m_y;
}

int Point::getId(){
    return m_id;
}

void Point::setX(int x) {
    m_x = x;
}

void Point::setY(int y) {
    m_y = y;
}

void Point::setId(int id) {
    m_id = id;
}

Point::Point(int id, int x, int y) {
    setX(x);
    setY(y);
    setId(id);
}