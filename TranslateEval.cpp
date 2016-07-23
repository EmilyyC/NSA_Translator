//
//  main.cpp
//  Translate DAR
//
//  Created by Emily Chen on 2016-07-15.
//  Copyright © 2016 Emily C. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

class Course
{
public:
   /*Course()
    {
        courseLine = "";
    }
    
    Course(string courseLine, string name)
    :courseLine(""), name ("")
    {
        this -> courseLine = courseLine;
        this -> name = name;
    }
    */
    void seperateCpurseLine()
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
    void addCourseLine (string courseLine)
    {
        this -> courseLine = courseLine;
    }
    
    void addName (string name)
    {
        this -> titleName = name;
    }
    void addUnit (string strUnit)
    {
        unit = stod(strUnit);
       
    }
    bool ifTilteCourse()
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
    
    void printOutCourse()
    {
        //cout << courseLine << endl;
        if (ifTilteCourse())
        {
            cout << departName << " -- " << titleName << " LD (" << unit << ") "<< endl;
        }
        else
            cout << name << " (" << unit << ") " << endl;
       
    }
private:
    double unit;
    string name;
    //bool ifTitleCourse;
    string courseLine;
    string titleName;
    string departName;
};

string seperateTheCollege (string& original)
{
    string college = "";
    //getline(original.begin(),'\n')
    for (int i= 0; original[i]!= '\n'; i++)
        college += original[i];
    original.erase(0, original.find('\n')+1);
    return college;
}



bool isWanted(const std::string & line)
{
    return (line.find("Target Course") != string::npos);
}


int main()
{
    ifstream myFile("/Users/emilychen/Desktop/DAR.txt");
    vector<Course> listOfCourse (40);
    string line;
    int count = 0;
    while (getline(myFile, line))
    {
        if (isWanted(line))
        {
            listOfCourse.push_back(listOfCourse[count]);
            listOfCourse[count].addCourseLine(line);
           
            count ++;
        }
        
    }
    for (vector<Course>::iterator it = listOfCourse.begin();it!= listOfCourse.end();it++)
    {   it -> seperateCpurseLine();
        it->printOutCourse();}
    
    // print out total unit
    //cout << "total "
    return 0;
}


/*int main()
{
    string original = "";
    string addOn = "";
    ifstream myfile;
    myfile.open("/Users/emilychen/Desktop/DAR.txt");
    while ( myfile.is_open()&&!myfile.eof())
    {
        getline(myfile, addOn);
        original += addOn;
        original += "\n";
    }
    cout << "<u>"<<seperateTheCollege(original)<< "</u>" <<endl;
    cout << original<< endl;
    return 0;
}
*/
