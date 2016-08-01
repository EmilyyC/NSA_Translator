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

