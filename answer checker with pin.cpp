#include<iostream>
#include<iomanip>
#include<fstream>
#include<cstdlib>
#include<ostream>
#include<ctime>
#include<cmath>
#include<stdlib.h>
using namespace std;
void save_data(string quest[], string answers[], int size) {
    ofstream writer("Questions_ModelAnswer.txt", ios::app);
    for (int i = 0; i < size; i++) {
        writer << quest[i] << " " << answers[i] << endl;
    }
}
void load_data(string quest[], string answers[]) {
    ifstream reader("Questions_ModelAnswer.txt", ios::app);
    int i = 0;
    while (!reader.eof()) {
        reader >> quest[i] >> answers[i];

        i++;
    }
}
int main()
{
    cout << "Welcome to the math exam" << endl;
    cout << "If you're a student, press 1, If you're a professor, press 0\n";
    int pin, countpin = 0, z, count = 0, a, b, c;
    string studentanswer;
    cin >> z;
    string question[100];
    string modelans[100];
    int size = 0;
    int q;
    if (z == 0)
    {
        do {
            cout << "enter your pin: ";
            cin >> pin;
            countpin++;
        } while (countpin < 3);
        {
            cout << "no trials left";
            if (countpin == 000)
                cout << "welcome";
        }
        if (countpin == 000)
            cout << "welcome";

        ofstream questions("Question_addition.txt", ios::app);
        cout << "Enter the number of questions you want to add" << endl;
        cin >> q;
        if (size != 100) {
            for (int i = 0; i < q; i++)
            {
                cout << "Enter Question:";
                cin >> question[size];
                questions << question[size] << " ";
                cout << "Enter 3 choices, containing model answer:";
                cin >> a >> b >> c;
                cout << "enter the model answer:" << endl;
                cin >> modelans[size];
                size++;
                questions << " " << a << " " << b << " " << c << endl;;

            }
            save_data(question, modelans, size);
        }
    }
    else
    {
        ifstream exam1("Question_addition.txt");
        int i = 0;
        while (!exam1.eof())
        {
            load_data(question, modelans);
            exam1 >> question[i];
            exam1 >> a >> b >> c;
            if (exam1.eof())
                break;
            cout << question[i] << endl << a << endl << b << endl << c << endl;
            cout << "\nEnter your choice:";
            cin >> studentanswer;

            if (studentanswer == modelans[i])
                count++;
            i++;
        }
        cout << "your score is = " << count << " / " << i;
    }
}