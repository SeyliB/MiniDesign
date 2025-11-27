#ifndef _Point_H_
#define _Point_H_

#include "NuageAbstrait.h"
#include <string>

using namespace std;

class Point : public NuageAbstrait {
private:
    string m_textures = ""; 
public:
    Point(int id, int x, int y);
    ~Point() = default; // dans CommandeSupprimerPoint quand jexecute faut que je save une instance du point pour pouvoir faire un undo
    string getTexture() override;
    string getDescription() override;
    void removeTexture() ;
    int getX();
    int getY();
    int getId();
    void setX(int x);
    void setY(int y);
    void setId(int id);
};

#endif