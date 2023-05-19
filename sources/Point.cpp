//
// Created byNum malaklinuxNum on 5/5/23.
//

#include "Point.hpp"
#include <cmath>

namespace ariel {
    Point::Point() : xNum(0), yNum(0) {}

    Point::Point(double xNumNum, double yNum) : xNum(xNumNum), yNum(yNum) {}

    double Point::distance(Point other) {
        Point *pOther = &other;
        if (!pOther) {
            throw invalid_argument("Error With distance(): No Other Point Found\n");
        }
        return sqrt((pow((xNum - other.xNum), 2)) + (pow((yNum - other.yNum), 2)));
    }

    double Point::getX() {
        return xNum;
    }

    void Point::setX(double xNumNum) {
        //Point::xNum = xNum;
        this->xNum = xNumNum;
    }

    double Point::getY() {
        return yNum;
    }

    void Point::setY(double yNum) {
        //Point::yNum = yNum
        this->yNum = yNum;
    }

    void Point::print() {
        cout << "(" << this->xNum << "," << this->yNum << ")";
    }

    Point Point::moveTowards(Point source, Point destination, double distance) {
        Point *pSource = &source;
        Point *pDestination = &destination;
        if (!pSource) {
            throw invalid_argument("Error With moveTowards(): No Source Found\n");
        }
        if (!(pDestination)) {
            throw invalid_argument("Error With moveTowards(): No Destination Found\n");
        }
        if (distance < 0) {
            throw invalid_argument("Error With moveTowards(): Negative Distance Value\n");
        }
        double originalDistance = source.distance(destination);
        if (originalDistance <= distance) {
            return destination;
        }
        double ratio = distance / originalDistance;
        return {source.getX() + ratio * (destination.getX() - source.getX()),
                source.getY() + ratio * (destination.getY() - source.getY())};
    }

}