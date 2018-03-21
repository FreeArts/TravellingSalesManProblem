#ifndef INTERFACES_H
#define INTERFACES_H

#include <QObject>

namespace Point{

class Coordinate{
public:
    QString name;
    QChar x;
    QChar y;

    void swap(Coordinate& a)
    {
         //FIXME:fos
        std::swap(name,  a.name);
    }

    void swap(Coordinate& a,Coordinate& b)
    {
        a.swap(b);
    }

    friend bool operator <(Point::Coordinate a, Point::Coordinate b)
    {
        return true; //FIXME:fos
    }

};











}





#endif // INTERFACES_H
