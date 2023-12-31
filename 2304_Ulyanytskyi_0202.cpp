#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int get_user_input()
{
    int input;
    cin >> input;
    return input;
}

void fill_vector(vector<int>& A, int size, int max, int min)
{
    srand(time(0));
    int rand_num;

    if (!A.empty())
        A.clear();    
    
    for (int i = 0; i < size; i += 2)
    {
        rand_num = (rand() % max) + min;

        if (i == size - 1)
        {
            while (find(A.begin(), A.end(), rand_num) != A.end())
                rand_num = (rand() % max) + min;
            A.push_back(rand_num);
            break;
        }

        A.push_back(rand_num);
        A.push_back(rand_num);
    }
}

void display_vector(vector<int>& A)
{
    cout << "{ ";
    for (int& element : A)
        cout << element << ' ';
    cout << "}\n";
}

int solution(vector<int>& A)
{
    unordered_map<int, int> map;
    for (int element : A)
        map[element]++;

    for (const auto& pair : map)
    {
        if (pair.second % 2 != 0)
            return pair.first;
    }

    return -1;
}

int main()
{
    vector<int> A;
    int user_input;
    int unpaired_element;

    bool exit_status = false;
    
    const int MAX_ARRAY_SIZE = 999999;
    const int MIN_ARRAY_SIZE = 1;
    const int MAX_NUMBER = 1000000000;
    const int MIN_NUMBER = 1;

    cout << "The array must be odd in the range from 1 to 999999\n";

    while (!exit_status)
    {
        cout << "Enter array size: ";
        user_input = get_user_input();
        bool check_range = user_input >= MIN_ARRAY_SIZE && user_input <= MAX_ARRAY_SIZE;

        if (user_input % 2 != 0 && check_range)
        {
            fill_vector(A, user_input, MAX_NUMBER, MIN_NUMBER);
            unpaired_element = solution(A);

            if (unpaired_element == -1)
            {
                cout << "\nERROR!\n";
                continue;
            }                

            cout << "Array: ";
            display_vector(A);
            cout << "Unpaired element: " << unpaired_element;

            cout << "\n1 - for try again\n";
            cout << "0 - for Exit\n";
            cout << "Enter: ";

            switch (get_user_input())
            {
            case 0:
                exit_status = true;
                break;
            case 1:
                break;
            default:
                cout << "Invalid input!\n";
                break;
            }
        }
        else if (user_input % 2 == 0 && check_range)
        {
            cout << "The size of the array must be odd!\n";
        }
        else
        {
            cout << "Invalid input!\n";
        }

        cout << endl;
    }

    return 0;
}