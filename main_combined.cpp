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
#include <iomanip>

using namespace std;


// UPDATE THESE

int SESSION = 205;

class Course
{
public:
    Course ();
    void seperateCourseLineTransferEvl();
    bool isWanted(const std::string & line, std::string target);
    void addCourseLine (std::string courseLine);
    void addName (std::string name);
    void addUnit (std::string strUnit);
    bool ifTilteCourse();
    void printOutCourse();
    double showUnit ();
    std::string seperateTheCollege (std::string& original);
    void seperateCourseLine();
    bool showIfIP();
    void setUnit(int newUnit);
    bool showIfCollege();
    std::string showName ();
    bool operator==(const Course& other);
private:
    double m_unit;
    bool m_ifCollege;
    bool m_ifInProgress;
    std::string m_name;
    std::string m_courseLine;
    std::string m_titleName;
    std::string m_departName;
    std::string m_grade;
};



void writeAdditionalNotesTransfer ()
{
    cout << endl;
    cout << "Additional Notes: \n"<<endl;
    cout << "Referred student to Sociology department website http://www.sociology.ucla.edu\n"<< endl;
    cout << "Recommended Sociology 20, one major upper division course and one non major upper division."<<endl;
    cout << "Recommended student to take three classes in the fall.\n\nAlso recommended student not to take classes with finals on the same day.\n"<< endl;
}
void writeAdditionalNotesFY ()
{
    cout << endl;
    cout << "Additional Notes: \n"<<endl;
    cout << "Student met with Mary Anne Geber and was recommended to take Math 32A, Physics 1A and GE\n"<<endl;
    cout << "Referred to Engineering website http://www.seasoasa.ucla.edu.\n\nRecommended student to take three classes in the fall with a fiat lux or/and seminar as the only optional fourth/fifth class.\n\nAlso recommended student not to take classes with finals on the same day\n" << endl;
    cout << "Student expressed interest in STEM club, referred to Association for Computing Machinery (ACM) and Institute of Electrical and Electronics Engineers (IEEE) http://acm.cs.ucla.edu and http://www.ieee.ucla.edu\n" <<endl;
}

bool isInterested( const string interest)
{
    string popLine;
    ifstream filePOP("/Users/emilychen/Desktop/POP.txt");
    while (getline(filePOP, popLine))
        if (popLine.find(interest) != string::npos)
        {   cout <<endl;
            return true;}
    return false;
}

void writePOP ()
{
    
    if (isInterested("career plans"))
        cout << "Students interested in career plans and professional/graduate school, referred to Career Centre http://www.career.ucla.edu"<< endl;
    if (isInterested("community service opportunities"))
        cout << "Student expressed interests about community service, referred to Volunteer Centre and Community Service Commission http://volunteer.ucla.edu and http://www.communityservicecommission.org"<< endl;
    if (isInterested( "extracurricular activities"))
        cout << "Student expressed interests about clubs and ex-curricular activities, referred to Student Groups http://www.studentgroups.ucla.edu"<< endl;
    if (isInterested( "graduate/professional school"))
        cout << "Students interested in career plans and professional/graduate school, referred to Career Centre http://www.career.ucla.edu"<< endl;
    if (isInterested("living arrangements"))
        cout << "Student interested in housing options, referred to Community Housing Office cho.ucla.edu"<< endl;
    if (isInterested("research opportunities"))
        cout << "Student interested in research opportunities, referred to Undergraduate Research Centre - Science http://www.ugresearchsci.ucla.edu"<< endl;
    if (isInterested( "parking"))
        cout << "Student expressed interests in parking options, referred to UCLA Transportation https://main.transportation.ucla.edu"<< endl;
    if (isInterested( "music"))
        cout << "Student expressed interests in music, referred to UCLA Herb Alpert School of Music http://www.music.ucla.edu"<< endl;
    if (isInterested( "sport"))
        cout << "Student interested in sports, referred to Recreation Centre http://www.recreation.ucla.edu"<< endl;
    
    
    
    
}
bool Course::operator==(const Course& other)
{
    
    if (!ifTilteCourse())
    {
        return false;
    }
    
    if (m_titleName!= "" && m_titleName == other.m_titleName && m_departName == other.m_departName)
        return true;
    return false;
}

Course::Course()
{
    m_ifCollege = false;
    m_ifInProgress = false;
}

void Course::setUnit(int newUnit)
{
    m_unit = newUnit;
}
bool Course::isWanted(const std::string & line, string target)
{
    return (line.find(target) != string::npos);
}

double Course::showUnit (){return m_unit;}
bool Course::showIfCollege() {return m_ifCollege;}
bool Course::showIfIP()    {return m_ifInProgress;}
string Course::showName () {return m_name;}
void Course::addCourseLine (std::string courseLine)
{
    this -> m_courseLine = courseLine;
}

void Course::addName (std::string name)
{
    this -> m_titleName = name;
}
void Course::addUnit (std::string strUnit)
{
    m_unit = stod(strUnit);
}


void Course::seperateCourseLineTransferEvl()
{
    istringstream iss (m_courseLine);
    string substring;
    int count=1;
    vector<string> stringgroup;
    while (getline(iss, substring, '\t'))
    {
        if (count  == 8)
            m_name = substring;
        if (count == 9)
            m_titleName = substring;
        if (count == 10)
            addUnit(substring);
        count ++;
    }
    
}
void Course::seperateCourseLine()
{
    std::istringstream iss (m_courseLine);
    std::string substring;
    int count=1;
    std::vector<std::string> stringgroup;
    if (isWanted(m_courseLine, "Sub-Requirement Complete" ))
    {
        m_ifCollege = true;
    }
    while (getline(iss, substring, '\t'))
    {
        if (count % 4 == 2)
        {
            
            if (substring == "Advanced Placement Test Scores")
            {
                substring = "Advanced Placement";
            }
            
            m_name = substring;
        }
        
        
        if (count % 4 == 3)
            addUnit(substring);
        count ++;
    }
}

bool Course::ifTilteCourse()
{
    for (int i =0; i< m_name.size(); i++)
    {
        if (isdigit(m_name[i]))
        {
            if (m_name[i-1]=='T')
            {
                for (int k = 0; k< i-2; k++ )
                    m_departName += m_name[k];
                return true;
            }
        }
    }
    m_departName = "";
    return false;
}

void Course::printOutCourse()
{
    //IF COLLGE
    if (m_ifCollege)
    {
        cout << "<u>" << m_name << "</u>" <<endl;
        return;
    }
    
    //IF ACTUAL COURSE
    //cout << name << endl;
    if (ifTilteCourse())
    {
        std::cout << m_departName << " - " << m_titleName << " LD (";
        std::cout << std::fixed << std::setprecision(1) << m_unit << ") ";
        
    }
    else
    {   std::cout << m_name << " (";
        std::cout << std::fixed << std::setprecision(1) << m_unit << ") ";
    }
    if (m_unit==0)
    {
        std::cout << "- IP * " << std::endl;
        m_ifInProgress = true;
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

int main()
{
    vector<Course> listOfCourse;
    Course sample;
    string type;
    string line;
    ifstream myFile("/Users/emilychen/Desktop/DAR.txt");
    // READ INPUT
    //////////////////////////////////////
    do {
        cout << " Do you want to translate from Dar or Transfer Evaluation? (please enter 'D' or 'T') : ";
        cin >> type;
    }
    while (type != "D" && type != "T");
    
    cout << "\n\nDegree Audit Report (DAR) with transfer work posted Session "<< SESSION <<"\n" << endl;
    ////////////////////////////////////////////////////////
    //DAR////////////////////////////////////////
    /////////////////////////////////////////////////////////
    if (type == "D")
    {
        string ListOfCollege [10];
        bool ifAnyCourseIP= false;
        
        int count = 1;
        int courseCount = 0;
        
        
        while (getline(myFile, line))
        {
            if (count % 3 == 1)
            {   listOfCourse.push_back(sample);
                listOfCourse[courseCount].addCourseLine(line);
                listOfCourse[courseCount].seperateCourseLine();
            }
            else if (count % 3 == 2)
                listOfCourse[courseCount].addName(line);
            else
            {
                if (courseCount > 1 && (listOfCourse[courseCount] == listOfCourse[courseCount-1]))
                {
                    listOfCourse[courseCount-1].setUnit(8.0);
                    
                }
                else
                    courseCount ++;
            }
            count ++;
            
        }
        
        double totalUnit = 0;
        double collegeUnit = 0;
        int collegeCount = 0;
        //for (vector<Course>::iterator it = listOfCourse.begin();it!= listOfCourse[courseCount];it++)
        for (int k=0; k<courseCount; k++)
            
        {
            if (listOfCourse[k].showIfCollege())
            {
                ListOfCollege[collegeCount] = listOfCourse[k].showName();
                if (collegeCount != 0)
                {
                    cout << "\nTotal "<< ListOfCollege[collegeCount-1]<< " Units = ";
                    cout << fixed << setprecision(1) << collegeUnit << endl;
                    cout << endl;
                }
                collegeCount ++;
                collegeUnit = 0;
            }
            listOfCourse[k].printOutCourse();
            totalUnit += listOfCourse[k].showUnit();
            collegeUnit += listOfCourse[k].showUnit();
            if (listOfCourse[k].showIfIP())
                ifAnyCourseIP = true;
            
        }
        
        
        // print out total unit
        cout << "\nTotal ";
        cout << ListOfCollege[collegeCount - 1]<< " Units = ";
        cout << fixed << setprecision(1) << collegeUnit << endl;
        cout << endl;
        
        cout << "Total Transfer Units = ";
        cout << fixed << setprecision(1) << totalUnit << endl;
        
        if (ifAnyCourseIP)
            cout <<"\n*Courses in progress, instruct student to send in final transcript to Admission office and check DAR in fall."<<endl;
    }
    ////////////////////////////////////////////////////
    // TRANSLATE TRANSFER ELVA / BLANK DAR
    ////////////////////////////////////////////////////
    else
    {
        
        int count = 0;
        
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
    }
    
    // FINISHED TRANLATION --> ADDITIONAL NOTES
    //POP///////////////////////////////////////////////////
    //POP///////////////////////////////////////////////////
    //writeAdditionalNotesFY();
    //writePOP();
    
    return 0;
}



