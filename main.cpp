/***
 *  พลสิงห์ ตาเละมัน
 *  ID 64028780
****/

#include <iostream>
#include "Sorting.h"
using namespace std;

int main()
{
    int n;
    int a;
    

    cout << " SORTING " << endl;
    cout << "Enter Maxsize: ";
    cin >> n;
    Sorting s(n);
    s.random();
    s.restore();
    do
    {
        cout << " Manu " << endl;
        cout << "1:SeletionSort 2:InsertionSort 3:BuebleSort" << endl;
        cout << "4:ShellSort 5:MergeSort 6:QuickSoort 7:all Test" << endl;
        cout << "Enter Manu: ";
        cin >> a;

        switch (a)
        {
        case 1:
            cout<<endl;    
            cout << "SeletionSort" << endl;
            cout << endl;
            s.restore();
            s.display();
            s.seletion();
            s.display();
            s.diaplayswapCounter();
            s.displayloopCounter();
            s.displaytimes();
            cout << endl;
            break;

        case 2:
            cout<<endl; 
            cout << "InsertionSort" << endl;
            cout << endl;
            s.restore();
            s.display();
            s.Insertion();
            s.display();
            s.diaplayswapCounter();
            s.displayloopCounter();
            s.displaytimes();
            cout << endl;
            break;

        case 3:
            cout<<endl; 
            cout << "BuebleSort" << endl;
            cout << endl;
            s.restore();
            s.display();
            s.bubble();
            s.display();
            s.diaplayswapCounter();
            s.displayloopCounter();
            s.displaytimes();
            cout << endl;
            break;

        case 4:
            cout<<endl; 
            cout << "ShellSort" << endl;
            cout << endl;
            s.restore();
            s.display();
            s.shell();
            s.display();
            s.diaplayswapCounter();
            s.displayloopCounter();
            s.displaytimes();
            cout << endl;
            break;

        case 5:
            cout<<endl; 
            cout << "MergeSort" << endl;
            cout << endl;
            s.restore();
            s.display();
            s.merge();
            s.display();
            s.diaplayswapCounter();
            s.displayloopCounter();
            s.displaytimes();
            cout << endl;
            break;

        case 6:
            cout<<endl; 
            cout << "QuickSoort" << endl;
            cout << endl;
            s.restore();
            s.display();
            s.quick();
            s.display();
            s.diaplayswapCounter();
            s.displayloopCounter();
            s.displaytimes();
            cout << endl;
            break;

        case 7:
            cout<<endl; 
            int x;
            cout << "Enter Maxsize: ";
            cin >> x;
             Sorting k(x);

            cout << "all Test" << endl;
            cout << endl;

            cout << "SeletionSort" << endl;
            k.random();
            k.restore();
            k.seletion();
            // s.display();
            k.diaplayswapCounter();
            k.displayloopCounter();
            k.displaytimes();

            cout << endl;

            cout << "InsertionSort" << endl;
            k.restore();
            // s.display();
            k.Insertion();
            // s.display();
            k.diaplayswapCounter();
            k.displayloopCounter();
            k.displaytimes();

            cout << endl;

            cout << "BubbleSort" << endl;
            k.restore();
            // s.display();
            k.bubble();
            // s.display();
            k.diaplayswapCounter();
            k.displayloopCounter();
            k.displaytimes();

            cout << endl;

            cout << "ShellSort" << endl;
            k.restore();
            // s.display();
            k.shell();
            // s.display();
            k.diaplayswapCounter();
            k.displayloopCounter();
            k.displaytimes();

            cout << endl;

            cout << "MergeSort" << endl;
            k.restore();
            // s.display();
            k.merge();
            // s.display();
            k.diaplayswapCounter();
            k.displayloopCounter();
            k.displaytimes();

            cout << endl;

            cout << "QuickSort" << endl;
            k.restore();
            //  s.display();
            k.quick();
            //  s.display();
            k.diaplayswapCounter();
            k.displayloopCounter();
            k.displaytimes();
            break;
        }
        }
        while (a != 0);

       
        return 0;
    }