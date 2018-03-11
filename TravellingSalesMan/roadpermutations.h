#ifndef ROADPERMUTATIONS_H
#define ROADPERMUTATIONS_H

#include <QObject>
#include <QVector>
#include "interfaces.h"

class RoadPermutations : public QObject
{
    Q_OBJECT

public:
    explicit RoadPermutations(QObject *parent = nullptr);
    ~RoadPermutations();

private:

    QVector<Point::Coordinate> m_allPermutations_v;
    QVector<Point::Coordinate> m_possibilityPermutations_v;
    QVector<Point::Coordinate> m_filteredPermutations_v;

    void setAllPermutation(QVector<Point::Coordinate> const &l_allPoints_v);
    void filterPossibilityPermForGreedyPoint(QVector<Point::Coordinate> const &l_allPossibility_v);
    void filterInversePermutations(QVector<Point::Coordinate> const &l_PossibilityPerm_v);

signals:

public slots:
};

#endif // ROADPERMUTATIONS_H
