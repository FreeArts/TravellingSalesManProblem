#include "roadpermutations.h"

RoadPermutations::RoadPermutations(QObject *parent) : QObject(parent)
{

}

RoadPermutations::~RoadPermutations()
{

}

void RoadPermutations::setAllPermutation( QVector<Point::Coordinate> l_allPoints_v)
{
    uint l_iterator_ui=0;
    QVector<QString> l_tmpCopyVector_v;

     for (int i = 0; i < l_allPoints_v.size(); ++i) {
         l_tmpCopyVector_v.push_back(l_allPoints_v.at(i).name) ;
         qDebug() <<  l_allPoints_v.at(i).name;
     }

     std::next_permutation( l_allPoints_v.begin(), l_allPoints_v.end());
     qDebug() << l_tmpCopyVector_v;
}

void RoadPermutations::filterPossibilityPermForGreedyPoint(QVector<Point::Coordinate> l_allPossibility_v)
{
}

void RoadPermutations::filterInversePermutations(QVector<Point::Coordinate> l_PossibilityPerm_v)
{

}
