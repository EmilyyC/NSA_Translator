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
    // TRANSLATE DAR////////////////////////////////////////
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
            cout <<"*Courses in progress, instruct student to send in final transcript to Admission office and check DAR in fall."<<endl;
        // print out total unit
        cout << "Total ";
        cout << ListOfCollege[collegeCount - 1]<< " Unit = ";
        cout << fixed << setprecision(1) << collegeUnit << endl;
        cout << endl;
        
        cout << "Total Transfer Unit = ";
        cout << fixed << setprecision(1) << totalUnit << endl;
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
        return 0;
    }
    
    // FINISHED TRANLATION --> ADDITIONAL NOTES
    //POP///////////////////////////////////////////////////
    //POP///////////////////////////////////////////////////
    //writePOP();
    return 0;
}
