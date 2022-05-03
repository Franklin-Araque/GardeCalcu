#include <iostream>
#include <fstream>
#include <string>
#include <iomanip> 
#include <sstream>
using namespace std;

class Student {
private:
    int totalEle[42];
    int studentEle[14];
    int minProjScore;
    float weightProjScore;
    float weightExamScore;
    float weightFExamScore;
    float weightTotalScore;
    int studentNum;
    ifstream gradeFile;

    void openFile();
    void testFile();
    void readFile();
    void lowestProjScore();
    void projectAverageValue();
    void examAverageValue();
    void finalExamScore();
    void weightedScore();
public:
    Student();
    void driver();
};

Student::Student() {
    int minProjScore = 0;
    float weightProjScore = 0;
    float weightExamScore = 0;
    float weightFExamScore = 0;
    float weightTotalScore = 0;
}

void Student::openFile() {
    gradeFile.open("Fall2020Grades.txt");
}

void Student::testFile() {
    if (!gradeFile) {
        cout << "Error opening data file";
    }
}

//compares all values that are designated as project scores against each other to find the minimum value
void Student::lowestProjScore() {
    int min = studentEle[1];

    for (int j = 1; j < 9; j++) {
        if (studentEle[j] < min) {
            min = studentEle[j];
        }
    }
    //cout << "TRIGGERED";
    minProjScore = min;
}

//iterates over all project grades to find the weighted average of said projects
void Student::projectAverageValue() {
    float average = 0;

    for (int k = 1; k < 9; k++) {
        if (studentEle[k] != minProjScore) {
            average += studentEle[k];
        }
    }
    weightProjScore = (average / 7) * .45;

}


void Student::examAverageValue() {
    float average = 0;

    for (int k = 9; k < 13; k++) {
        average += studentEle[k];
    }
    weightExamScore = (average / 4) * 0.35;
}

void Student::finalExamScore() {
    weightFExamScore = studentEle[13] * 0.2;
}

void Student::weightedScore() {
    weightTotalScore = weightExamScore + weightProjScore + weightFExamScore;

    cout << studentEle[0] << "                  " << std::setprecision(3) << weightTotalScore << endl;
}

//sets all values present in the file to a single totalEle array, which is then split into seperate studentEle arrays becuase screw you that why. Then calls each function associated with finding the weighted grade average for each studentEle array. 
void Student::readFile() {
    for (int i = 0; i < 42; i++) {
        gradeFile >> totalEle[i];
        //cout << endl << totalEle[41];
    }

    for (int i = 0; i < 14; i++) {
        studentEle[i] = totalEle[i];
        //cout << endl << studentEle[i];

        if (i == 13) {
            int minProjScore = 0;
            float weightProjScore = 0;
            float weightExamScore = 0;
            float weightFExamScore = 0;
            float weightTotalScore = 0;

            lowestProjScore();
            projectAverageValue();
            examAverageValue();
            finalExamScore();
            weightedScore();
        }
    }

    for (int i = 14; i < 28; i++) {
        studentEle[i % 14] = totalEle[i];
        // cout << endl << studentEle[i%14];

        if (i == 27) {
            int minProjScore = 0;
            float weightProjScore = 0;
            float weightExamScore = 0;
            float weightFExamScore = 0;
            float weightTotalScore = 0;

            lowestProjScore();
            projectAverageValue();
            examAverageValue();
            finalExamScore();
            weightedScore();
        }
    }

    for (int i = 28; i < 42; i++) {
        studentEle[i % 14] = totalEle[i];
        //cout << endl << studentEle[i%14];

        if (i == 41) {
            int minProjScore = 0;
            float weightProjScore = 0;
            float weightExamScore = 0;
            float weightFExamScore = 0;
            float weightTotalScore = 0;

            lowestProjScore();
            projectAverageValue();
            examAverageValue();
            finalExamScore();
            weightedScore();
        }
    }
}

void Student::driver() {
    openFile();
    testFile();
    readFile();
}

//handles all output and the intialization of a student object
int main()
{
    using std::cout;
    using std::endl;

    cout << "Grade Average Calculator" << endl << endl;
    cout << "Opening File..." << endl << endl;
    cout << "Processing..." << endl << endl;
    cout << "Output: " << endl << endl << "Student ID:        " << "Total grade:       " << endl << endl;

    Student test;
    test.driver();

    cout << "End of program" << endl;

    //system("pause");
    return 0;