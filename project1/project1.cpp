//Cody Williams
//924008283
//CSCE 315-507
//Due: January 29, 2018
//main.cpp


#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <sstream>
#include <math.h>
#include <algorithm>

using namespace std;

//this function takes 2 points as arguements and calculates their
//distance from eachother using the distance formula
//d = sqrt((x2-x1)^2 + (y2-y1)^2)
double calcSingleDistance(pair<int,int> pair1, pair<int,int> pair2){
    double distance;
    int x2 = pair1.first;
    int x1 = pair2.first;
    int y2 = pair1.second;
    int y1 = pair2.second;
    int xdistance = (x2-x1)*(x2-x1);
    int ydistance = (y2-y1)*(y2-y1);
    distance = sqrt(xdistance + ydistance);
    return distance;
}

// This function takes in a vector of pairs (x and y) cordinates and calculates
//all distances to each point in the vector from a single point (currentPoint)
vector<double> calcAllDistances(vector<pair<int,int> > points, pair<int,int> currentPoint){
    vector<double> distances;
    for(unsigned i = 0; i < points.size(); i++){
        distances.push_back(calcSingleDistance(points[i], currentPoint));
    }
    return distances;
}

//this function takes in a vector of unsorted distances and returns the smallest distance in the vector
double smallestDistance(vector<double> distances){
    double minDistance;
    sort(distances.begin(), distances.end());
    minDistance = distances[0];
    return minDistance;
}

//this function takes in a vector of unsorted distances and returns the index of the smallest distance
int indexOfSmallestDistance(vector<double> distances){
    int indexOfSmallestDistance = 0;
    for (unsigned i = 0; i < distances.size(); ++i)
    {
        if (distances[i] < distances[indexOfSmallestDistance])
            indexOfSmallestDistance = i;
    }
    return indexOfSmallestDistance;
}


int main(){
    
    //reading input from a redirected file or storing data points into a vector of pairs
    vector<pair<int,int> > points;
    int a,b;
    while(cin >> a >> b){
        points.push_back(make_pair(a,b));
    }
    
    //initializing variables to be utilized by the below while loop
    int index = 0;
    double totalDistance = 0;
    double minDistance;
    
    //This pair contains the data from the first pair that will be used in the final
    //distance calculation of the traveling samesman problem
    pair<int,int> firstPair = make_pair(points[0].first,points[0].second);
    
    //This while loop completes the traveling salesman problem
    while(points.size() > 1){
        
        // 1) creating temporary point to hold the information contained in the point located at index
        pair<int,int> temp = make_pair(points[index].first, points[index].second);
        
        // 2) erasing the old point so it doen't interfere with further distance calculations
        points.erase(points.begin() + index);
        
        // 3) calculate all distances of points from point located at index
        vector<double> allDistances = calcAllDistances(points,temp);
        
        // 4) find smallest distance from all calculated distancesand add it to todal distance
        minDistance = smallestDistance(allDistances);
        totalDistance = totalDistance + minDistance;
        
        // 5) changes the current index to the index of the point located the smallest distance from previous point
        index = indexOfSmallestDistance(allDistances);
        
    }
    
    //this pair holds information about the last pair visited in the traveling samesman problem
    pair<int,int> lastPair = make_pair(points[index].first, points[index].second);
    
    //final operation that calculates distance from last point to inital point
    double lastdistance = calcSingleDistance(firstPair, lastPair);
    
    //adding the distance between the first and last visited points to produce the final distance
    totalDistance = totalDistance + lastdistance;
    
    cout << totalDistance << endl;
    
}


