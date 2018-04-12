#include "roadpermutations.h"

RoadPermutations::RoadPermutations(QObject *parent) : QObject(parent)
{

}

RoadPermutations::~RoadPermutations()
{

}

void RoadPermutations::setAllPermutation( QVector<Point::Coordinate> l_allPoints_v)
{
    QVector< Point::Coordinate > l_tmpCopyVector_v;

    m_allPermutations_v.push_back(l_allPoints_v);
     while(std::next_permutation(l_allPoints_v.begin(), l_allPoints_v.end())){
         QVector<Point::Coordinate> l_tmpCopyVector_v;
        l_tmpCopyVector_v.clear();

         for(int l_iterator_i = 0; l_iterator_i < l_allPoints_v.size(); l_iterator_i++){
                l_tmpCopyVector_v.push_back(l_allPoints_v.value(l_iterator_i));
         }
         m_allPermutations_v.push_back(l_tmpCopyVector_v);
     }
}

void RoadPermutations::filterPossibilityPermForGreedyPoint(QVector<Point::Coordinate> l_allPossibility_v)
{
}

void RoadPermutations::filterInversePermutations(QVector<Point::Coordinate> l_PossibilityPerm_v)
{

}
