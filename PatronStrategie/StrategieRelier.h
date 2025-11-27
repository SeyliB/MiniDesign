#pragma once
#include <vector>
#include <cmath>
#include <algorithm>
#include "../PatronComposite/Point.h"

using namespace std;

class StrategieRelier {
public:
    virtual ~StrategieRelier() = default;
    virtual vector<pair<int, int>> relier(vector<Point*>& points) = 0;
};

class RelierParOrdreID : public StrategieRelier {
public:
    vector<pair<int, int>> relier(vector<Point*>& points) override {
        vector<pair<int, int>> connexions;
        
        vector<Point*> pointsTries = points;
        
        for (size_t i = 0; i < pointsTries.size(); i++) {
            for (size_t j = 0; j < pointsTries.size() - 1; j++) {
                if (pointsTries[j]->getId() > pointsTries[j + 1]->getId()) {
                    Point* temp = pointsTries[j];
                    pointsTries[j] = pointsTries[j + 1];
                    pointsTries[j + 1] = temp;
                }
            }
        }
        
        for (size_t i = 0; i < pointsTries.size() - 1; i++) {
            connexions.push_back({i, i + 1});
        }
        
        if (pointsTries.size() > 2) {
            connexions.push_back({pointsTries.size() - 1, 0});
        }
        
        return connexions;
    }
};

class RelierParDistanceMin : public StrategieRelier {
private:
    double calculerDistance(Point* p1, Point* p2) {
        int dx = p1->getX() - p2->getX();
        int dy = p1->getY() - p2->getY();
        return sqrt(dx * dx + dy * dy);
    }
    
public:
    vector<pair<int, int>> relier(vector<Point*>& points) override {
        vector<pair<int, int>> connexions;
        
        if (points.size() < 2) return connexions;
        
        vector<bool> visites(points.size(), false);
        visites[0] = true;
        int courant = 0;
        
        for (size_t i = 0; i < points.size() - 1; i++) {
            double distanceMin = numeric_limits<double>::max();
            int plusProche = -1;
            
            for (size_t j = 0; j < points.size(); j++) {
                if (!visites[j]) {
                    double distance = calculerDistance(points[courant], points[j]);
                    if (distance < distanceMin) {
                        distanceMin = distance;
                        plusProche = j;
                    }
                }
            }
            
            if (plusProche != -1) {
                connexions.push_back({courant, plusProche});
                visites[plusProche] = true;
                courant = plusProche;
            }
        }
        
        if (points.size() > 2) {
            connexions.push_back({courant, 0});
        }
        
        return connexions;
    }
};
