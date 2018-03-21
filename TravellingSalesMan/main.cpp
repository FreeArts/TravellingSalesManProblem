#include "mainwindow.h"
#include <QApplication>
#include "roadpermutations.h"
#include "interfaces.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    Point::Coordinate testStruct1;
    testStruct1.name="A";
    testStruct1.x=2;
    testStruct1.y=3;
    Point::Coordinate testStruct2;
    testStruct2.name="B";
    testStruct2.x=1;
    testStruct2.y=3;
    Point::Coordinate testStruct3;
    testStruct3.name="C";
    testStruct3.x=7;
    testStruct3.y=6;
    Point::Coordinate testStruct4;
    testStruct4.name="D";
    testStruct4.x=6;
    testStruct4.y=7;

    RoadPermutations test;
    QVector <Point::Coordinate> testVector;
    testVector.push_back(testStruct1);
    testVector.push_back(testStruct2);
    testVector.push_back(testStruct3);
    testVector.push_back(testStruct4);

    w.show();

    qDebug() << "Start";

    test.setAllPermutation(testVector);

    uint8_t aqqq = 2566;

    return a.exec();
}
