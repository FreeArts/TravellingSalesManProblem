#ifndef ROADPERMUTATIONS_H
#define ROADPERMUTATIONS_H

#include <QObject>

namespace Point{

struct Coordinate{

    QString name;
    QChar x;
    QChar y;

    };
}

class RoadPermutations : public QObject
{
    Q_OBJECT
public:
    explicit RoadPermutations(QObject *parent = nullptr);
    ~RoadPermutations();

private:

    void copyPointsToAllStruct(QString l_PointName_s, QChar l_xCoordinate_c, QChar l_yCoordinate);

    void setAllPermutation(QVector<Point::Coordinate> const & l_allPoints_struct);
    void filterPossibilityPermForGreedyPoint(QVector<Point::Coordinate> const & l_allPossibility_struct);
    void filterInversePermutations(QVector<Point::Coordinate> const & l_PossibilityPerm_struct);

signals:

public slots:
};

#endif // ROADPERMUTATIONS_H
