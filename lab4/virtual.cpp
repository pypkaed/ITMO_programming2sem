#include <iostream>
#include <vector>
#include <algorithm>
#include "abstract.h"

using namespace std;

vector<Figure*> System;

int main() {
    short command;
    double x, y, massAll, squareAll, perimAll;
    CVector2D centerMassAll;
    while (true) {
        cout << "--- Choose the command ---\n1. Add figure\n2. Show the whole system\n";
        cout << "3. Show the square size of the system\n4. Show the perimeter of the system\n5. Show the center mass of the system\n";
        cout << "6. Show the memory size\n7. Sort by mass\n8.Exit\nYour command: ";
        cin >> command;
        if (command < 1 || command > 7) {
            cout << "Exiting.\n";
            return 0;
        }

        switch (command) {
            case 1:
            {
                cout << "1. Rectangle\n2. Parallelogram";
                cin >> command;
                switch (command) {
                    case 1:
                        System.push_back(new Rectangle());
                        break;
                    case 2:
                        System.push_back(new Parallelogram());
                        break;
                    default:
                        cout << "We don't have this type of figure" << '\n';
                        break;
                }
                break;
            }
            case 2:
            {
                for (int i = 0; i < System.size(); i++)
                    System[i]->draw();
                break;
            }
            case 3:
            {
                squareAll = 0;
                for (int i = 0; i < System.size(); i++)
                    squareAll += System[i]->square();
                cout << "The square size of the system is: " << squareAll << '\n';
                break;
            }
            case 4:
            {
                perimAll = 0;
                for (int i = 0; i < System.size(); i++)
                    perimAll += System[i]->perimeter();
                cout << "The perimeter of the system is: " << perimAll << '\n';
                break;
            }
            case 5:
            {
                massAll = 0;
                x = 0; y = 0;
                for (int i = 0; i < System.size(); i++) {
                    x += System[i]->position().x * System[i]->mass();
                    y += System[i]->position().y * System[i]->mass();
                    massAll += System[i]->mass();
                }
                centerMassAll.x = x / massAll;
                centerMassAll.y = y / massAll;
                cout << "Center mass of the system is: (" << centerMassAll.x << ", " << centerMassAll.y << ")\n";
                break;
            }
            case 6:
            {
                cout << "Memory size of the system is: ";
                for (int i = 0; i < System.size(); i++)
                    cout << System[i]->size() << ", ";
                cout << '\n';
                break;
            }
            case 7:
            {
                sort(System.begin(), System.end(), [](Figure* x, Figure* y) {return *x < *y; });
                break;
            }
        }
    }
}