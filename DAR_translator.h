//
//  DAR translator.hpp
//  Dar translate
//
//  Created by Emily Chen on 2016-07-28.
//  Copyright © 2016 Emily C. All rights reserved.
//


#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <iomanip>
using namespace std;

class Course
{
public:
    void seperateCourseLineTransferEvl();
    bool isWanted(const std::string & line, std::string target);
    void seperateCpurseLine();
    void addCourseLine (std::string courseLine);
    void addName (std::string name);
    void addUnit (std::string strUnit);
    bool ifTilteCourse();
    void printOutCourse();
    double showUnit ();
    std::string seperateTheCollege (std::string& original);
    void seperateCourseLine();
    bool showIfIP();
    bool showIfCollege();
    std::string showName ();
private:
    double unit;
    bool ifCollege = false;
    bool ifInProgress = false;
    std::string name;
    //bool ifTitleCourse;
    std::string courseLine;
    std::string titleName;
    std::string departName;
};

bool Course::isWanted(const std::string & line, string target)
{
    return (line.find(target) != string::npos);
}

double Course::showUnit (){return unit;}
bool Course::showIfCollege() {return ifCollege;}
bool Course::showIfIP()    {return ifInProgress;}
string Course::showName () {return name;}
void Course::addCourseLine (std::string courseLine)
{
    this -> courseLine = courseLine;
}

void Course::addName (std::string name)
{
    this -> titleName = name;
}
void Course::addUnit (std::string strUnit)
{
    unit = stod(strUnit);
}


void Course::seperateCourseLineTransferEvl()
{
    istringstream iss (courseLine);
    string substring;
    int count=1;
    vector<string> stringgroup;
    while (getline(iss, substring, '\t'))
    {
        if (count  == 8)
            name = substring;
        if (count == 9)
            titleName = substring;
        if (count == 10)
            addUnit(substring);
        count ++;
    }
    
}
void Course::seperateCourseLine()
{
    std::istringstream iss (courseLine);
    std::string substring;
    int count=1;
    std::vector<std::string> stringgroup;
    if (isWanted(courseLine, "Sub-Requirement Complete" ))
    {
        ifCollege = true;
    }
    while (getline(iss, substring, '\t'))
    {
        if (count % 4 == 2)
            name = substring;
        
        if (count % 4 == 3)
            addUnit(substring);
        count ++;
    }
}

bool Course::ifTilteCourse()
{
    for (int i =0; i< name.size(); i++)
    {
        if (isdigit(name[i]))
        {
            if (name[i-1]=='T')
            {
                for (int k = 0; k< i-2; k++ )
                    departName += name[k];
                return true;
            }
        }
    }
    departName = "";
    return false;
}

void Course::printOutCourse()
{
    //IF COLLGE
    if (ifCollege)
    {
        cout << "<u>" << name << "</u>" <<endl;
        return;
    }
    
    //IF ACTUAL COURSE
    //cout << name << endl;
    if (ifTilteCourse())
    {
        std::cout << departName << " -- " << titleName << " LD (";
        std::cout << std::fixed << std::setprecision(1) << unit << ") ";

    }
    else
    {   std::cout << name << " (";
        std::cout << std::fixed << std::setprecision(1) << unit << ") ";
    }
    if (unit==0)
    {   std::cout << "-- IP * " << std::endl;
        ifInProgress = true;
    }
    else cout << endl;
}

std::string Course::seperateTheCollege (std::string& original)
{
    std::string college = "";
    //getline(original.begin(),'\n')
    for (int i= 0; original[i]!= '\n'; i++)
        college += original[i];
    original.erase(0, original.find('\n')+1);
    return college;
}
