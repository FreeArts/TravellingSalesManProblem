#include "roadpermutations.h"
#include <QtMath>

//---------Permutation Function---

QVector<QVector<Point::Coordinate> > L_setAllPermutation(QVector<Point::Coordinate> l_allPointsPrepare_v){
    QVector<QVector<Point::Coordinate>> l_allPermutations_v;
    l_allPermutations_v.push_back(l_allPointsPrepare_v);
     while(std::next_permutation(l_allPointsPrepare_v.begin(), l_allPointsPrepare_v.end())){

        /*-----------------------------DO NOT USE THESE LINES 'CAUSE EAT ALL MEMORY--------------------
         QVector<Point::Coordinate> l_tmpCopyVector_v;
        l_tmpCopyVector_v.clear();

        for(int l_iterator_i = 0; l_iterator_i < l_allPointsPrepare_v.size(); l_iterator_i++){
                l_tmpCopyVector_v.push_back(l_allPointsPrepare_v.value(l_iterator_i));
         }
         m_allPermutations_v.push_back(l_tmpCopyVector_v);
         ---------------------------------------------------------------------------------------*/
        l_allPermutations_v.push_back(l_allPointsPrepare_v);
     }

     ///* For Debug
     QString string;
          for(int x = 0; x< l_allPermutations_v.size(); x++){
                   for(int y = 0; y< l_allPermutations_v.at(x).size(); y++){
                          string = string + l_allPermutations_v[x][y].name;
                          if(y == l_allPermutations_v.at(x).size()-1)
                          {
                              string.push_back("        ");
                          }
                   }
               }

          qDebug() << string;
     //--------------*/
    return l_allPermutations_v;
}


//---Debug Functions------------------

//Test function for serial method
void RoadPermutations::roadLenghtCalculate()
{
/*
    for(int l_iteratorX =0; l_iteratorX < m_possibilityPermutations_v.size();l_iteratorX++){

        QString l_roadName = "";
        double l_roadLenght_d = 0;

        for(int l_iteratorY = 0; l_iteratorY < m_possibilityPermutations_v.at(l_iteratorX).size(); l_iteratorY++){

            l_roadName = l_roadName + m_possibilityPermutations_v[l_iteratorX][l_iteratorY].name;

           if(l_iteratorY != (m_possibilityPermutations_v.at(l_iteratorX).size())-1 ){

               if( ((m_possibilityPermutations_v[l_iteratorX][l_iteratorY].x - m_possibilityPermutations_v[l_iteratorX][l_iteratorY+1].x) != 0) &&
                       ((m_possibilityPermutations_v[l_iteratorX][l_iteratorY].y - m_possibilityPermutations_v[l_iteratorX][l_iteratorY+1].y) != 0))
               {
                   l_roadLenght_d = l_roadLenght_d + (qSqrt(
                           qPow(qFabs(m_possibilityPermutations_v[l_iteratorX][l_iteratorY].x - m_possibilityPermutations_v[l_iteratorX][l_iteratorY+1].x),2)  +
                           qPow(qFabs(m_possibilityPermutations_v[l_iteratorX][l_iteratorY].y - m_possibilityPermutations_v[l_iteratorX][l_iteratorY+1].y),2)));
               }

               else{
                   if( ((m_possibilityPermutations_v[l_iteratorX][l_iteratorY].x - m_possibilityPermutations_v[l_iteratorX][l_iteratorY+1].x) == 0)){
                       l_roadLenght_d = l_roadLenght_d + (qFabs(m_possibilityPermutations_v[l_iteratorX][l_iteratorY].y - m_possibilityPermutations_v[l_iteratorX][l_iteratorY+1].y));
                   }


                   if( ((m_possibilityPermutations_v[l_iteratorX][l_iteratorY].y - m_possibilityPermutations_v[l_iteratorX][l_iteratorY+1].y) == 0)){
                       l_roadLenght_d = l_roadLenght_d + (qFabs(m_possibilityPermutations_v[l_iteratorX][l_iteratorY].x - m_possibilityPermutations_v[l_iteratorX][l_iteratorY+1].x));
                   }
               }
           }
        }

            setRoadLengthName(l_iteratorX,l_roadName);
            setRoadLength(l_iteratorX,l_roadLenght_d);
    }
    //For Debug
    showRoadsLengthVector(); */
}

/* //Debug function for Permutation test
void RoadPermutations::setAllPermutation( QVector<Point::Coordinate> l_allPointsPrepare_v)
{
    m_allPermutations_v.push_back(l_allPointsPrepare_v);
     while(std::next_permutation(l_allPointsPrepare_v.begin(), l_allPointsPrepare_v.end())){
        m_allPermutations_v.push_back(l_allPointsPrepare_v);
     }

     ///* For Debug
     QString string;
          for(int x = 0; x< m_allPermutations_v.size(); x++){
                   for(int y = 0; y< m_allPermutations_v.at(x).size(); y++){
                          string = string + m_allPermutations_v[x][y].name;
                          if(y == m_allPermutations_v.at(x).size()-1)
                          {
                              string.push_back("        ");
                          }
                   }
               }

          qDebug() << string;
}
*/

//-----------------------------------


RoadPermutations::RoadPermutations(QObject *parent) : QObject(parent)
{

}

RoadPermutations::~RoadPermutations()
{

}

void RoadPermutations::startPermutations(QVector<Point::Coordinate> l_allPoints_v)
{
    QFuture<QVector<QVector<Point::Coordinate>>> tmp_thread = QtConcurrent::run(L_setAllPermutation,l_allPoints_v);
    tmp_thread.waitForFinished();
    m_allPermutations_v = tmp_thread.result();

    filterPossibilityPermForGreedyPoint();
}


void RoadPermutations::setRoadLengthName(int l_iteratorX, QString l_roadName)
{
    m_roadsLenght_v.at(l_iteratorX)->roadName = l_roadName;
}

void RoadPermutations::setRoadLength(int l_iteratorX, double l_roadLenght_d)
{
    m_roadsLenght_v.at(l_iteratorX)->lenght = l_roadLenght_d;
}

void RoadPermutations::showRoadsLengthVector()
{
    //For Debug
    QString l_worstRoadName="";
    double l_worstRoadLength_d=0;

    QString l_bestRoadName="";
    double l_bestRoadLength_d=0;

    for(int l_iteratorZ =0; l_iteratorZ < m_roadsLenght_v.size();l_iteratorZ++){
        qDebug() << m_roadsLenght_v.at(l_iteratorZ)->roadName;
        qDebug() << m_roadsLenght_v.at(l_iteratorZ)->lenght;

        if(l_worstRoadLength_d < m_roadsLenght_v.at(l_iteratorZ)->lenght)
        {
            l_worstRoadLength_d = m_roadsLenght_v.at(l_iteratorZ)->lenght;
            l_worstRoadName = m_roadsLenght_v.at(l_iteratorZ)->roadName;
        }
    }

    qDebug() << "Worst Road";
    qDebug() << l_worstRoadName;
    qDebug() << l_worstRoadLength_d;

    for(int l_iteratorZ =0; l_iteratorZ < m_roadsLenght_v.size();l_iteratorZ++){
        if(l_worstRoadLength_d > m_roadsLenght_v.at(l_iteratorZ)->lenght)
        {
            l_bestRoadLength_d = m_roadsLenght_v.at(l_iteratorZ)->lenght;
            l_bestRoadName = m_roadsLenght_v.at(l_iteratorZ)->roadName;
        }
    }

    qDebug() << "Best Road";
    qDebug() << l_bestRoadName;
    qDebug() << l_bestRoadLength_d;
}

QVector<QVector<Point::Coordinate> > RoadPermutations::getPossibilityPermutations()
{
    return m_possibilityPermutations_v;
}


void RoadPermutations::filterPossibilityPermForGreedyPoint()
{
    QVector< Point::Coordinate > l_copyVector_v;
    l_copyVector_v.clear();

    for(int x = 0; x< m_allPermutations_v.size(); x++){
         l_copyVector_v.clear();
        if( m_allPermutations_v[x][0].name == "A"){
            for(int y = 0; y< m_allPermutations_v.at(x).size(); y++){
                  l_copyVector_v.push_back(m_allPermutations_v[x][y]);
            }
             l_copyVector_v.push_back(m_allPermutations_v[0][0]);
             m_possibilityPermutations_v.push_back(l_copyVector_v);
         }
     }

    ///* For Debug
    QString string;
         for(int x = 0; x< m_possibilityPermutations_v.size(); x++){
                  for(int y = 0; y< m_possibilityPermutations_v.at(x).size(); y++){
                         string = string + m_possibilityPermutations_v[x][y].name;
                         if(y == m_possibilityPermutations_v.at(x).size()-1)
                         {
                             string.push_back("        ");
                         }
                  }
              }
        qDebug() << "--------------------";
         qDebug() << string;
    //--------------*/

     //Init roadLenght Vector
        for(int l_vectorIterator_i = 0; l_vectorIterator_i < m_possibilityPermutations_v.size();l_vectorIterator_i++){
            Point::RoadLenght *l_roadsLength = new Point::RoadLenght;
            m_roadsLenght_v.push_back(l_roadsLength);
        }
}
