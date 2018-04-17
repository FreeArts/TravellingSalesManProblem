#include "roadpermutations.h"

RoadPermutations::RoadPermutations(QObject *parent) : QObject(parent)
{

}

RoadPermutations::~RoadPermutations()
{

}

void RoadPermutations::startPermutations(QVector<Point::Coordinate> l_allPoints_v)
{
    setAllPermutation(l_allPoints_v);
    filterPossibilityPermForGreedyPoint();
}

void RoadPermutations::roadLenghtCalculate()
{
    for(int x =0; x < m_possibilityPermutations_v.size();x++){
            QString l_roadName = "";
            for(int y = 0; y< m_possibilityPermutations_v.at(x).size(); y++){
                l_roadName = l_roadName + m_possibilityPermutations_v[x][y].name;
            }
    }
}

void RoadPermutations::setAllPermutation( QVector<Point::Coordinate> l_allPointsPrepare_v)
{
    m_allPermutations_v.push_back(l_allPointsPrepare_v);
     while(std::next_permutation(l_allPointsPrepare_v.begin(), l_allPointsPrepare_v.end())){

        /*-----------------------------DO NOT USE THESE LINES 'CAUSE EAT ALL MEMORY--------------------
         QVector<Point::Coordinate> l_tmpCopyVector_v;
        l_tmpCopyVector_v.clear();

        for(int l_iterator_i = 0; l_iterator_i < l_allPointsPrepare_v.size(); l_iterator_i++){
                l_tmpCopyVector_v.push_back(l_allPointsPrepare_v.value(l_iterator_i));
         }
         m_allPermutations_v.push_back(l_tmpCopyVector_v);
         ---------------------------------------------------------------------------------------*/
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
     //--------------*/
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
            Point::RoadLenght *l_roadsLengh;
            m_roadsLenght_v.push_back(l_roadsLengh);
        }
       //WTF
}
