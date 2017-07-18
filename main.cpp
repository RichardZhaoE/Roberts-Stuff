#include <iostream>
#include <iomanip>
#include <string>

using namespace std;


const int NUM_MONKEYS = 3;
const int NUM_DAYS = 5;



void fillArray (float array[][NUM_DAYS], int NUM_MONKEYS)
{
    for (int monkeys = 0; monkeys < NUM_MONKEYS; monkeys++)
    {
        for (int days = 0; days < NUM_DAYS; days++)
            do {
                cout << " Enter food eaten (in pounds) by each monkey per day\n";
                cout << " Monkey " << (monkeys + 1)
                << ", Day " << (days + 1) << ": ";
                cin >> array[monkeys][days];
                if (array[monkeys][days] <0)
                    cout << "Food cannot be negative" << endl;
            } while (array[monkeys][days] <0);
        cout << endl;
    }
}

float calcAvg (float array[][NUM_DAYS], int NUM_MONKEYS)
{
    float total;
    float average;
    for (int monkeys = 0; monkeys < NUM_MONKEYS; monkeys++)
    {
        for (int days = 0; days < NUM_DAYS; days++)
            total += array[monkeys][days];
        average = total / 3;
    }
    return average;
}

float calcMax (float array[][NUM_DAYS], int NUM_MONKEYS)
{
    float max = array[0][0];
    for (int monkeys = 0; monkeys < NUM_MONKEYS; monkeys++)
    {
        for (int days = 0; days < NUM_DAYS; days++)
        {   if (array[monkeys][days] > max)
            max = array[monkeys][days];
        }
    }
    return max;
    
}

float calcMin (float array[][NUM_DAYS], int NUM_MONKEYS)
{
    float min = array[0][0];
    for (int monkeys = 0; monkeys < NUM_MONKEYS; monkeys++)
    {
        for (int days = 0; days < NUM_DAYS; days++)
        { if (array[monkeys][days] < min)
            min = array[monkeys][days];
        }
    }
    return min;
}

void showArray (float array[][NUM_DAYS], int NUM_MONKEYS, float average, float max, float min)//[NUM_DAYS])
{
    cout << endl;
    cout << endl;
    cout << "The average amount of food eaten (in pounds) by all monkeys is: " << average << " pounds." << endl;
    cout << "The greatest amount of food eaten (in pounds) by one monkey this week is: " << max << " pounds." << endl;
    cout << "The least amount of food eaten (in pounds) by one monkey this week is: " <<min << " pounds." << endl;
    
    cout << endl;
}





int main()
{
    float food[NUM_MONKEYS][NUM_DAYS];
    float min, max, average;
    
    fillArray (food, NUM_MONKEYS);
    max = calcMax (food, NUM_MONKEYS);
    min = calcMin (food, NUM_MONKEYS);
    average = calcAvg (food, NUM_MONKEYS);
    
    showArray (food, NUM_MONKEYS, average, max, min);
    return 0;
}