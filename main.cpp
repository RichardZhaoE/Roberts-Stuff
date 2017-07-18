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


void calcMax (float array[][NUM_DAYS], int NUM_MONKEYS)
{
    float max[3] = { 0, 0, 0 }; // 0 = Bananas 1 = Days 2 = Monkeys
    for (int monkeys = 0; monkeys < NUM_MONKEYS; monkeys++)
    {
        for (int days = 0; days < NUM_DAYS; days++)
        {
            if (array[monkeys][days] > max[0])
            {
                max[0] = array[monkeys][days];
                max[1] = days + 1;
                max[2] = monkeys + 1;
            }
        }
    }
    cout << "Monkey number " << max[2] << " ate the most amount of food " << endl;
    cout << max[0] << " pounds, on day " <<  max[1] << endl;
    
}

void calcMin (float array[][NUM_DAYS], int NUM_MONKEYS)
{
    float min[3] = { 0, 0, 0 };
    for (int monkeys = 0; monkeys < NUM_MONKEYS; monkeys++)
    {
        for (int days = 0; days < NUM_DAYS; days++)
        {
            if (array[monkeys][days] < min[0] || (days == 0 && monkeys == 0))
            {
                min[0] = array[monkeys][days];
                min[1] = days + 1;
                min[2] = monkeys + 1;
            }
        }
    }
    cout << "Monkey number " << min[2] << " ate the least amount of food " << endl;
    cout << min[0] << " pounds, on day " <<  min[1] << endl;
}

void showAverage (float array[][NUM_DAYS], int numMonkeys)
{
    cout << endl;
    float total = 0;
    for (int days = 0; days < NUM_DAYS; days++)
    {
       	for (int monkeys = 0; monkeys < numMonkeys; monkeys++)
        {
            total += array[monkeys][days];
        }
        cout << "The average amount of food eaten on day " << days + 1 << "  is: " << total / 3 << " pounds." << endl;
        total = 0;
    }
    cout << endl;
}


int main()
{
    float food[NUM_MONKEYS][NUM_DAYS];
    fillArray (food, NUM_MONKEYS);
    showAverage (food, NUM_MONKEYS);
    calcMin (food, NUM_MONKEYS);
    calcMax (food, NUM_MONKEYS);
    return 0;
}