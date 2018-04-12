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

    test_point1.name = "A";
    test_point2.name = "B";
    test_point3.name = "C";

    test_point1.x = 1;
    test_point2.x = 2;
    test_point3.x = 3;

    test_point1.y = 1;
    test_point2.y = 2;
    test_point3.y = 3;

    QVector<Point::Coordinate> test_vector;

    test_vector.push_back(test_point1);
    test_vector.push_back(test_point2);
    test_vector.push_back(test_point3);

    RoadPermutations test;
    test.setAllPermutation(test_vector);

    return a.exec();
}
