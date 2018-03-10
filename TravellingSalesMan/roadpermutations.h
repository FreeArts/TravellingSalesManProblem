#ifndef ROADPERMUTATIONS_H
#define ROADPERMUTATIONS_H

#include <QObject>
#include "interfaces.h"

class RoadPermutations : public QObject
{
    Q_OBJECT

public:
    explicit RoadPermutations(QObject *parent = nullptr);
    ~RoadPermutations();

private:

    void setAllPermutation(QVector<Point::Coordinate> const &l_allPoints_struct);
    void filterPossibilityPermForGreedyPoint(QVector<Point::Coordinate> const &l_allPossibility_struct);
    void filterInversePermutations(QVector<Point::Coordinate> const &l_PossibilityPerm_struct);

signals:

public slots:
};

#endif // ROADPERMUTATIONS_H
