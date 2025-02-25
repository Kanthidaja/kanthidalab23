#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;

char score2grade(int score)
{
    if (score >= 80)
        return 'A';
    if (score >= 70)
        return 'B';
    if (score >= 60)
        return 'C';
    if (score >= 50)
        return 'D';
    else
        return 'F';
}

string toUpperStr(string x)
{
    string y = x;
    for (unsigned i = 0; i < x.size(); i++)
        y[i] = toupper(x[i]);
    return y;
}

void importDataFromFile(string filename, vector<string> &names, vector<int> &scores, vector<char> &grades)
{
    ifstream fin(filename);
    string s;
    char format[] = "%[^:]:%d %d %d";
    int score1, score2, score3;
    char name[100];
    while (getline(fin, s))
    {
        int sum = 0;
        sscanf(s.c_str(), format, name, &score1, &score2, &score3);
        names.push_back(name);
        sum = score1 + score2 + score3;
        scores.push_back(sum);
        grades.push_back(score2grade(sum));
    }
}
void getCommand(string &command, string &key)
{
    cout << "Please input your command:\n";
    cin >> command;
    command = toUpperStr(command);
    if (command == "GRADE")
    {
        cin >> key;
    }
    else if (command == "NAME")
    {
        cin.ignore();
        getline(cin, key);
    }
}

void searchName(vector<string> names, vector<int> scores, vector<char> grades, string key)
{
    bool a = false;
    cout << "---------------------------------\n";
    for (unsigned int i = 0; i < names.size(); i++)
    {
        if (toUpperStr(names[i]) == key)
        {
            a = true;
            cout << names[i] << "'s " << "score = " << scores[i] << endl;
            cout << names[i] << "'s " << "grade = " << grades[i] << endl;
        }
    }
    if (a == false)
    {
        cout << "Cannot found.\n";
    }
    cout << "---------------------------------\n";
}

void searchGrade(vector<string> names, vector<int> scores, vector<char> grades, string key)
{
    bool a = false;
    cout << "---------------------------------\n";
    for (unsigned int i = 0; i < names.size(); i++)
    {
        if (grades[i] == key[0])
        {
            a = true;
            cout << names[i] << " (" << scores[i] << ")" << endl;
        }
    }
    if (a == false)
    {
        cout << "Cannot found.\n";
    }
    cout << "---------------------------------\n";
}

int main()
{
    string filename = "name_score.txt";
    vector<string> names;
    vector<int> scores;
    vector<char> grades;
    importDataFromFile(filename, names, scores, grades);

    do
    {
        string command, key;
        getCommand(command, key);
        command = toUpperStr(command);
        key = toUpperStr(key);
        if (command == "EXIT")
            break;
        else if (command == "GRADE")
            searchGrade(names, scores, grades, key);
        else if (command == "NAME")
            searchName(names, scores, grades, key);
        else
        {
            cout << "---------------------------------\n";
            cout << "Invalid command.\n";
            cout << "---------------------------------\n";
        }
    } while (true);

    return 0;
}
