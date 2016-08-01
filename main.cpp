//
//  main.cpp
//  Translate DAR
//
//  Created by Emily Chen on 2016-07-15.
//  Copyright © 2016 Emily C. All rights reserved.
//


#include "DAR_translator.h"
using namespace std;

int main()
{
    string ListOfCollege [10];
    ListOfCollege[0] = "hi";
    
    bool ifAnyCourseIP= false;
 
    vector<Course> listOfCourse;
    Course sample;
    string line;
    int count = 1;
    int courseCount = 0;
    ifstream myFile("/home/ubuntu/workspace/DAR.txt"); //CHANGE THIS!!
    while (getline(myFile, line))
    {
        if (count % 3 == 1)
        {   listOfCourse.push_back(sample);
            listOfCourse[courseCount].addCourseLine(line);
        }
        else if (count % 3 == 2)
            listOfCourse[courseCount].addName(line);
        else
        {
            listOfCourse[courseCount].seperateCourseLine();
            courseCount ++;
        }
        count ++;

    }
    
    double totalUnit = 0;
    double collegeUnit = 0;
    int collegeCount = 0;
    for (vector<Course>::iterator it = listOfCourse.begin();it!= listOfCourse.end();it++)
        
    {   if (it->showIfIP())
        ifAnyCourseIP = true;
        it -> seperateCourseLine();
        if (it->showIfCollege())
        {
            ListOfCollege[collegeCount] = it->showName();
            if (collegeCount != 0)
            {
            cout << "Total "<< ListOfCollege[collegeCount-1]<< " Unit = ";
            cout << fixed << setprecision(1) << collegeUnit << endl;
            cout << endl;
            }
            collegeCount ++;
            collegeUnit = 0;
        }
        it->printOutCourse();
        totalUnit += it -> showUnit();
        collegeUnit += it ->showUnit();

    }
    
    if (ifAnyCourseIP)
    cout <<"*Courses still in progress, instructed student to send in final transcript to UCLA Admission office and check DAR in Fall."<<endl;
    // print out total unit
    cout << "Total "<<ListOfCollege[collegeCount]<< " Unit = ";
    cout << fixed << setprecision(1) << collegeUnit << endl;
    cout << endl;

    cout << "Total Transfer Unit = ";
    cout << fixed << setprecision(1) << totalUnit << endl;
 
 
    //POP///////////////////////////////////////////////////
    //writePOP();
    return 0;
}

