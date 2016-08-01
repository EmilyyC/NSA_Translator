//
//  DAR translator.cpp
//  Dar translate
//
//  Created by Emily Chen on 2016-07-28.
//  Copyright © 2016 Emily C. All rights reserved.
//

#include "DAR_translator.h"
using namespace std;

bool isInterested( const string interest)
{
    string popLine;
    ifstream filePOP("/home/ubuntu/workspace/POP.txt"); //CHANGE THIS!!
    while (getline(filePOP, popLine))
        if (popLine.find(interest) != string::npos)
        {   cout <<endl;
            return true;}
    return false;
}

void writePOP ()
{
    cout << endl;
    cout << "Additional Notes: \n"<<endl;
    cout << "Referred student to Sociology department website http://www.sociology.ucla.edu\n"<< endl;
    cout << "Recommended Sociology 20, one major upper division course and one non major upper division."<<endl;
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
    
    cout << endl;
    cout << "Recommended student to take three classes in the fall.\n\nAlso recommended student not to take classes with finals on the same day.\n"<< endl;
    
    
}



