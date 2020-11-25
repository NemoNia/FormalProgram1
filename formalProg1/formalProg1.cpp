//Nia Iott
//CS1300 Programing Poject #1
//Structures and Grade Weighting
//Due 11/18/20
//Mansfield, J

# include <iostream>
# include <fstream>
# include <iomanip>
# include <string>

using namespace std;

ifstream inData;

//struct that holds student name info
struct studentName
{
    int ID;
    string lastName;
    string firstName;
};
//struct that holds studentName as well as all of the arrays for grading
struct grades
{
    studentName name;
    double exam[4];
    double lab[8];
    double program[2];
};
//5 students
const int MAX = 5;

grades list[MAX];

void getData(grades list[]);
void printData(grades list[]);

int main ()
{
    //opens the data text file
    inData.open("testData.txt");

    getData(list);
    printData(list);

    inData.close();
    return 0;
}
//function that contains all of the loops to fill the grading arrays 
void getData(grades list [])
{
    for(int i= 1; i < MAX; i++)
    {
        
        inData >> list[i].name.ID >> list[i].name.firstName >> list[i].name.lastName;
        for (int j = 0; j < 4; j++)
        {
            inData >> list[i].exam[j];
        }
        for (int j = 0; j < 8; j++)
        {
            inData >> list[i].lab[j];
        }
        for (int j = 0; j < 2; j++)
        {
            inData >> list[i].program[j];
        }
    }
}
//function to print out everything and make it look nice
void printData(grades list[])
{
    for(int i= 1; i < MAX; i++)
    {
        cout << list[i].name.ID << " " << list[i].name.firstName << "  " << list[i].name.lastName  << endl;
        cout << "Exam Scores:";
            for (int j = 0; j < 4; j++)
        {
            cout << " " << list[i].exam[j];
        }
        cout << endl;
        cout << "Lab Scores:";
        for (int j = 0; j < 8; j++)
        {
            cout << " " << list[i].lab[j];
        }
        cout << endl;
        cout << "Program Scores:";
        for (int j = 0; j < 2; j++)
        {
            cout << " " <<list[i].program[j];
        }
        cout << endl;
        cout << endl;
    }
}