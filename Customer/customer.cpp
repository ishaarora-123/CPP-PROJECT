#include <iostream>
#include <iomanip>
using namespace std;
class Customer {
    int u;
    char c;
    int s;
    float e = 0;
    public:
        void input (char category , int units) {
            u = units;
            c = category;
        }
        int subtotalc();
        int extrac();
        int subtotald();
        int extrad();
};
int Customer :: subtotald() {
    if (u < 600) {
        s = 250; 
    }
    else {
        s = (u * 8) +250 ;
    }
    return s;
}
int Customer :: extrad() {
    if (s > 10000) {
        e = (s-10000)/20;
    }
    return e;
}
int Customer :: subtotalc() {
    s = (u * 15)+1000;
    return s;
}
int Customer :: extrac() {
    if (s > 100000) {
        e = (s-10000)/10;
    }
    return e;
}
int main() {
    const char separator    = ' ';
    const int width = 10;
    char category[100];
    int units[100];
    Customer b1[100];
    int subtotal[100];
    int extra[100];
    int i = 0;
    int fixedc = 250;
    int fixedd = 1000;
    int totalc = 0;
    int totald = 0;
    while(true) {
        cout << "Enter the type of customer \n 1. Domestic \n 2. Commercial"<< endl;
        cin >> category[i];
        if (category[i] == 'D' || category[i] == 'C') {
            cout << "Enter the units consumed: ";
            cin >> units[i];
            b1[i].input(category[i], units[i]);
            if (category[i] == 'D') {
                subtotal[i] = b1[i].subtotald();
                extra[i] = b1[i].extrad();
            }
            else {
                subtotal[i] = b1[i].subtotalc();
                extra[i] = b1[i].extrac();
            }
            i ++;
        }
        else {
            break;
        } 
    }
    int j = 0;
        cout << left; 
        cout <<setw(5) << "SNo" 
        <<setw(10) << "Category" 
        <<setw(15) << "Fixed Amount(Rs)" 
        <<setw(15) << "Units"
        <<setw(15) << "Sub Total(Rs)"
        <<setw(15) << "Extra Charges(Rs)"
        <<setw(15) << "Total(Rs)" << endl; 
    while (j < i) {
        if (category[j] == 'D') {
            cout << left; 
            cout <<setw(5) << j+1 
            <<setw(10) << "Domestic"
            <<setw(15) << fixedd   
            <<setw(15) << units[j]
            <<setw(15) << subtotal[j]
            <<setw(15) << extra[j]
            <<setw(15) << extra[j] + subtotal[j]<< endl;
            totald = totald + extra[j] + subtotal[j];
        }
        else {
            cout << left; 
            cout <<setw(5) << j+1 
            <<setw(10) << "Commercial"
            <<setw(15) << fixedc
            <<setw(15) << units[j]
            <<setw(15) << subtotal[j]
            <<setw(15) << extra[j]
            <<setw(15) << extra[j] + subtotal[j]<< endl;
            totalc = totalc + extra[j] + subtotal[j];
        }
        j++;
    }
    cout << "Total Commercial Revenue: "<< totalc << endl;
        cout << "Total Domestic Revenue: "<< totald;
}