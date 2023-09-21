#if !defined(_SORTING_H)
#define _SORTING_H
#include "../Arraylist/Arraylist.h"
#include <stdlib.h>
#include <time.h>
#define DEAULT_SIZE 50000
class Sorting
{
    private:
        Arraylist *data;
        Arraylist *temp;
        int maxSize;
        int swapCounter; // วัดจำนวนการสลับ
        int loopCounter; //วัดจำนวน loop ยิ่งน้อย หใายความว่าเร็ว
        double timeElasped; // วัดเวลาที่ใช้ไป

    public:
        Sorting(int maxSize = DEAULT_SIZE);
        ~Sorting();


    private: //ชุดคําสั่งสําหรับ Selection Sort
        void swap(int i, int j); 
        int findMaxIndex(int n);
        void Insert(int n);
        void bubble_(int n);
        void selectK( int k);
        int findMinIndexK(int iStart, int k);
        void copyArray(Arraylist *src ,Arraylist *dest , int begin ,int end );
        void merge_(Arraylist *data ,Arraylist *result , int begin ,int end);
        void quick_(int begin, int end);
        int pickPivotIndex(int begin, int end);

    public:
        void seletion(bool verbose = false);
        void Insertion();
        void bubble();
        void shell();
        void merge();
        void quick();
    
   
    public: //fountoint เสริม
        void resetCounter();
        void random(); //สุ่ม data ต้องดึง stdlib & time
        void backup();
        void restore();
        void diaplayswapCounter();
        void displayloopCounter();
        void displaytimes();
        void display();

   


   
};



#endif // _SORTING
