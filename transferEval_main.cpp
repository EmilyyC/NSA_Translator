//
//  Transfer Elva.cpp
//  
//
//  Created by Emily Chen on 2016-07-31.
//
//

#include "DAR translator.h"
using namespace std;
// TRANSFER ELVA
int main()
{
    
    vector<Course> listOfCourse;
    Course sample;
    string line;
    int count = 0;
    ifstream myFile("/Users/emilychen/Desktop/DAR.txt");
    while (getline(myFile, line))
    {
        if (line.find("Target Course") != string::npos)
        {
            listOfCourse.push_back(sample);
            listOfCourse[count].addCourseLine(line);
            
            count ++;
        }
        
    }
    double totalUnit = 0;
    for (vector<Course>::iterator it = listOfCourse.begin();it!= listOfCourse.end();it++)
    {
        it -> seperateCourseLineTransferEvl();
        it->printOutCourse();
        totalUnit += it -> showUnit();
    }
    
    // print out total unit
    cout << "Total Unit = ";
    cout << fixed << setprecision(1) << totalUnit << endl;
    //POP///////////////////////////////////////////////////
    //writePOP();
    return 0;
}
