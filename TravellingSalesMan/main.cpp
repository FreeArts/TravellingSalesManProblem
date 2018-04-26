#include "mainwindow.h"
#include <QApplication>
#include "roadpermutations.h"
#include "interfaces.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    w.show();

    qDebug() << "Start";

    Point::Coordinate test_point1;
    Point::Coordinate test_point2;
    Point::Coordinate test_point3;
    //Point::Coordinate test_point4;

    test_point1.name = "A";
    test_point2.name = "B";
    test_point3.name = "C";
    //test_point4.name = "D";

    test_point1.x = 3;
    test_point2.x = 5;
    test_point3.x = 8;
    //test_point4.x = 1;

    test_point1.y = 6;
    test_point2.y = 9;
    test_point3.y = 4;
    //test_point4.y = 1;

    QVector<Point::Coordinate> test_vector;

    test_vector.push_back(test_point1);
    test_vector.push_back(test_point2);
    test_vector.push_back(test_point3);
    //test_vector.push_back(test_point4);

    RoadPermutations test;
    test.startPermutations(test_vector);
    test.roadLenghtCalculate();

    return a.exec();
}
