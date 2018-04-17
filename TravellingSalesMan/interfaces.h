#ifndef INTERFACES_H
#define INTERFACES_H

#include <QObject>
#include <QString>

namespace Point{

struct  RoadLenght{
      QString roadName;
      uint lenght;
};

    class Coordinate{
    public:
        QString name;
        int x;
        int y;

        void swap(Coordinate& targetClass)
        {
            std::swap(name,  targetClass.name);
        }

        void swap(Coordinate& targetClass_A, Coordinate& targetClass_B)
        {
            targetClass_A.swap(targetClass_B);
        }

        friend bool operator <(Point::Coordinate targetClass_A, Point::Coordinate targetClass_B)
        {
            if(targetClass_A.name < targetClass_B.name){
                return true;
            }
            else{
                return false;
            }
        }

    };  //CLASS END
} //NAMESPACE END
#endif // INTERFACES_H
