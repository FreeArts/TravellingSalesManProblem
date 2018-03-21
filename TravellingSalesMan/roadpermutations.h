#ifndef ROADPERMUTATIONS_H
#define ROADPERMUTATIONS_H

#include <QObject>
#include <QVector>
#include <QDebug>
#include <algorithm>    // std::next_permutation, std::sort

#include "interfaces.h"

class RoadPermutations : public QObject
{
    Q_OBJECT

public:
    explicit RoadPermutations(QObject *parent = nullptr);
    ~RoadPermutations();

    void setAllPermutation(QVector<Point::Coordinate> l_allPoints_v);
    void filterPossibilityPermForGreedyPoint(QVector<Point::Coordinate>  l_allPossibility_v);
    void filterInversePermutations(QVector<Point::Coordinate> l_PossibilityPerm_v);

private:

    QVector<Point::Coordinate> m_allPermutations_v;
    QVector<Point::Coordinate> m_possibilityPermutations_v;
    QVector<Point::Coordinate> m_filteredPermutations_v;

signals:

public slots:
};

#endif // ROADPERMUTATIONS_H
