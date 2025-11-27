#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "../PatronComposite/Point.h"

using namespace std;



    //vector<char> texturesNuages = {'o', '#', '$'};


class MethodeAffichageAbstrait{
    private:
    const int LARGEUR = 30;
    const int HAUTEUR = 20;
    public:
    void afficher(const std::vector<Point*>& points){
        imprimerGrille(points);
        for(Point* p : points){
            afficherPoint(p);
        }
    }

    virtual ~MethodeAffichageAbstrait() = default;

    protected:
    vector<Point> creerPoints(const std::string& ligne);
    void tracerLigne(std::vector<std::vector<char>>& grille, int x0, int y0, int x1, int y1);
    void imprimerGrille(const std::vector<Point*>& points);
    virtual void afficherPoint(Point* p) = 0;

};

class MethodeAffichageParTexture : public MethodeAffichageAbstrait{

    void afficherPoint(Point* p) override{

        cout << p->getTexture();
    };

};

class MethodeAffichageParId : public MethodeAffichageAbstrait{

    void afficherPoint(Point* p) override{
        cout << p->getId();
    }
};