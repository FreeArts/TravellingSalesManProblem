#include "roadpermutations.h"

RoadPermutations::RoadPermutations(QObject *parent) : QObject(parent)
{

}

RoadPermutations::~RoadPermutations()
{

}

void RoadPermutations::setAllPermutation( QVector<Point::Coordinate> l_allPoints_v)
{
    QVector< QVector< int > > l_tmpCopyVector_v;

    QVector <QVector <int> > myVector;

    int massive[4][4] = { {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16} };

    for(int i = 0; i < 4; i++)
    {
        QVector<int> tempVector;

        for(int j = 0; j < 4; j++)
        {
            tempVector.push_back(massive[i][j]);
            qDebug() << "Value " << j << ": " << tempVector.value(j);
        }
        myVector.push_back(tempVector);
        qDebug() << "myVector " << i << ": " << myVector.value(i);
    }

     //std::next_permutation( l_allPoints_v.begin(), l_allPoints_v.end());
    //qDebug() << l_tmpCopyVector_v;
    int l_vectorIterator_i = 0;
     while(std::next_permutation(l_allPoints_v.begin(), l_allPoints_v.end())){

         for (int l_iterator_i = 0; l_iterator_i < l_allPoints_v.size(); ++l_iterator_i) {

        }
     }
}

void RoadPermutations::filterPossibilityPermForGreedyPoint(QVector<Point::Coordinate> l_allPossibility_v)
{
}

void RoadPermutations::filterInversePermutations(QVector<Point::Coordinate> l_PossibilityPerm_v)
{

}
