#include "mainwindow.h"
#include <QApplication>
#include "roadpermutations.h"
#include "interfaces.h"
#include <QtMath>

#include <QFuture>
#include <QThread>
#include <QtConcurrent/QtConcurrent>

void roadLengthParallelCalc(QVector<QVector<Point::Coordinate>> l_possibilityRoadPermutations_v, RoadPermutations &Road)
{
    QString l_roadName;
    double l_roadLenght_d;
#pragma omp parallel private(l_roadName,l_roadLenght_d)
{
    #pragma omp parallel for
    for(int l_iteratorX =0; l_iteratorX < l_possibilityRoadPermutations_v.size();l_iteratorX++){
            l_roadName = "";
            l_roadLenght_d = 0;
            uint l_maxRowNumber = (l_possibilityRoadPermutations_v.at(l_iteratorX).size())-1;

            for(int l_iteratorY = 0; l_iteratorY < l_possibilityRoadPermutations_v.at(l_iteratorX).size(); l_iteratorY++){

                #pragma omp critical
                {
                    l_roadName = l_roadName + l_possibilityRoadPermutations_v[l_iteratorX][l_iteratorY].name;
                }

                if(l_iteratorY != l_maxRowNumber ){

                    #pragma omp critical
                    {
                    l_roadLenght_d = l_roadLenght_d + (qSqrt(
                            qPow(qFabs(l_possibilityRoadPermutations_v[l_iteratorX][l_iteratorY].x - l_possibilityRoadPermutations_v[l_iteratorX][l_iteratorY+1].x),2)  +
                            qPow(qFabs(l_possibilityRoadPermutations_v[l_iteratorX][l_iteratorY].y - l_possibilityRoadPermutations_v[l_iteratorX][l_iteratorY+1].y),2)));
                    }

                }
            }
            #pragma omp critical
            {
                Road.setRoadLengthName(l_iteratorX,l_roadName);
                Road.setRoadLength(l_iteratorX,l_roadLenght_d);
            }
    }
}
    //For Debug
    Road.showRoadsLengthVector();
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
       MainWindow w;

       w.show();

       qDebug() << "Start";

       Point::Coordinate test_point1;
       Point::Coordinate test_point2;
       Point::Coordinate test_point3;
       Point::Coordinate test_point4;
       Point::Coordinate test_point5;
       Point::Coordinate test_point6;
       Point::Coordinate test_point7;


       test_point1.name = "A";
       test_point2.name = "B";
       test_point3.name = "C";
       test_point4.name = "D";
       test_point5.name = "E";
       test_point6.name = "F";
       test_point7.name = "G";



       test_point1.x = 3;
       test_point2.x = 5;
       test_point3.x = 8;
       test_point4.x = 11;
       test_point5.x = 17;
       test_point6.x = 20;
       test_point7.x = 27;

       test_point1.y = 6;
       test_point2.y = 9;
       test_point3.y = 4;
       test_point4.y = 13;
       test_point5.y = 18;
       test_point6.y = 21;
       test_point7.y = 32;


       QVector<Point::Coordinate> test_vector;

       test_vector.push_back(test_point1);
       test_vector.push_back(test_point2);
       test_vector.push_back(test_point3);
       test_vector.push_back(test_point4);
       test_vector.push_back(test_point5);
       test_vector.push_back(test_point6);
       test_vector.push_back(test_point7);

    RoadPermutations Road;
    Road.startPermutations(test_vector);

    QVector<QVector<Point::Coordinate>> l_possibilityRoadPermutations_v;
    l_possibilityRoadPermutations_v = Road.getPossibilityPermutations();

    //Road.roadLenghtCalculate();

    roadLengthParallelCalc(l_possibilityRoadPermutations_v,Road);


    return a.exec();
}
