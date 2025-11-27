#ifndef _NUAGE_H_
#define _NUAGE_H_

#include "NuageAbstrait.h"
#include <string>
#include <unordered_map>

using namespace std;

class Nuage : public NuageAbstrait {
private:
    string m_textures = ""; 
    unordered_map<int, NuageAbstrait*> m_points;
public:
    Nuage(int x, int y);
    ~Nuage() = default; // dans CommandeSupprimerPoint quand jexecute faut que je save une instance du point pour pouvoir faire un undo
    string getTexture() override;
    string getDescription() override;
    void removeTexture() ;
    int getX();
    int getY();
    int getId();
    void setX(int x);
    void setY(int y);
    void setId(int id);
    void addPoint(int id, NuageAbstrait* point);
    void removePoint(int id);
};

#endif