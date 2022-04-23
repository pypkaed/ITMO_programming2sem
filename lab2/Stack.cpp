//#include <iostream>
//#include "Stack.h"
//
//bool Stack::push(int pushed_element) {
//    if (maxn == n + 1) return false;
//    n++;
//    arr[n] = pushed_element;
//    return true;
//}
//
//bool Stack::empty() {
//    return n < 0;
//};
//
//bool Stack::pop() {
//    if (n < 0) return false;
//    n--;
//    return true;
//}
//
//int Stack::size() {
//    return n + 1;
//}
//
//int Stack::top() {
//    return arr[n];
//}
//
//void Stack::show() {
//    for (int i = 0; i <= n; i++)
//        cout << arr[i] << " ";
//    cout << '\n';
//}
//
//int Stack::max_size() {
//    return maxn;
//}
//
//// --- menu ---
//
//bool Stack::Menu() {
//    cout << "--- Start ---\n1. Create a stack\n2. Exit\nYour command:";
//    short command;
//    cin >> command;
//    if (command != 1) {
//        cout << "Exiting.\n";
//        return true;
//    }
//    int n;
//    cout << "Type the size of the stack: ";
//    cin >> n;
//    Stack stack(n);
//    cout << "You've created a stack with the size of " << n << ".\n";
//    cout << '\n';
//    bool done_here = false;
//    while (!done_here) {
//        cout << "--- Choose the command ---\n1. Insert element(s)\n2. Delete element(s)\n";
//        cout << "3. Show the number of elements\n4. Check if the stack is empty\n5. Show the top element\n";
//        cout << "6. Show the whole stack\n 7. Exit\nYour command: ";
//        cin >> command;
//        if (command < 1 || command > 6) {
//            cout << "Exiting.\n";
//            done_here = true;
//            return true;
//        }
//        if (command == 1) {
//            int n, pushed_elem;
//            cout << "Type the number of elements you want to insert: ";
//            cin >> n;
//            cout << "Type the elements: ";
//            for (int i = 0; i < n; i++) {
//                cin >> pushed_elem;
//                bool flag = stack.push(pushed_elem);
//                if (flag == false) {cout << "An Error has occurred.\n";}
//            }
//            cout << '\n'; cout << '\n';
//        }
//        if (command == 2) {
//            int n;
//            cout << "Type the number of elements you want to delete: ";
//            cin >> n;
//            for (int i = 0; i < n; i++) {
//                bool flag = stack.pop();
//                if (flag == false) {cout << "An Error has occurred.\n";}
//            }
//            cout << '\n'; cout << '\n';
//        }
//        if (command == 3) {
//            cout << "The number of elements is: ";
//            cout << stack.size();
//            cout << '\n'; cout << '\n';
//        }
//        if (command == 4) {
//            cout << "The stack is ";
//            if (stack.empty()) cout << "empty";
//            else cout << "NOT empty";
//            cout << '\n'; cout << '\n';
//        }
//        if (command == 5) {
//            cout << "The top element is ";
//            cout << stack.top();
//            cout << '\n'; cout << '\n';
//        }
//        if (command == 6) {
//            cout << "Your stack: ";
//            stack.show();
//            cout << '\n'; cout << '\n';
//        }
//    }
//}