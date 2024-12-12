#include "Date.h"
using namespace std;

int main() {
    Date date1(15, 3, 2023);
    Date date2;

    cout << "current date: " << date1.toString() << endl;

    date2.fromString("28/02/2024");
    cout << "date read: " << date2.toString() << endl;

    ++date1;
    cout << "after++: " << date1.toString() << endl;

    date2 -= 10;
    cout << "after -= 10: " << date2.toString() << endl;

}
