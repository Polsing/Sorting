#include <iostream>
#include "Sorting.h"
using namespace std;

Sorting::Sorting(int maxSize)
{
    swapCounter = 0;
    loopCounter = 0;
    timeElasped = 0.0;
    this->maxSize = maxSize;
    data = new Arraylist(this->maxSize);
    temp = new Arraylist(this->maxSize);

/*เริ่มเเรกเราจะกำหนด data ทุกตัวเป็น 0 ซึ่งเรารู้จำนวนรอบ คือ maxSize เราจึงใช้ for ในการ loop กำหนด data เเต่ละต่ำเเหน่ง
โดยใช้ฟังก์ชั่น ที่เรามีคือ add (กำหนดข้อมูลต่ำเเหนงที่ i เป็น 0)*/
    for(int i = 0 ; i<this->maxSize ;i++) 
    {
        data->add(i,0);
        temp->add(i,0);
    }
    srand(time(NULL)); // set random

}

Sorting::~Sorting()
{
    // mamery มีจำกัด สร้างเเล้วต้องทำลาย
    delete data;
    delete temp;
} 



void Sorting::swap(int i, int j) //สลับเเบบสามเหลี่ยม 
{
    int t = data->get(i);
    data->set(i, data->get(j));
    data->set(j,t);
    swapCounter++;
}

int Sorting::findMaxIndex(int n) // เก็บค่ามากสุดใน  *data
{
    int maxIndex = 0;
    for(int i = 1; i<n ;i++)
    {
        if(data->get(maxIndex) < data->get(i))
          maxIndex = i;
           
      loopCounter ++;
    }
    return maxIndex;
}

void Sorting::Insert(int n)
{
    int insertData = data->get(n-1);
    int insertpos = n-2;
        while (insertpos >=0 && data->get(insertpos) > insertData)
        {
           swap(insertpos , insertpos +1);
           insertpos --;
           loopCounter ++;
        }
        
}

void Sorting::bubble_(int n)
{
    for (int i = 0; i < n - 1; i ++)
    {
        if (data->get(i)> data->get(i+1))
            swap(i, i+1);

        loopCounter ++;    
    }
}

void Sorting::selectK(int k)
{
    for (int i = 0; i < k; i ++)
     for (int j = i; j < maxSize; j = j + k)
        {
            int iMin = findMinIndexK( j, k);
            swap(j, iMin);
        }

}

int Sorting::findMinIndexK(int iStart, int k)
{
    int minIndex = iStart;

    for (int i = iStart + k; i < maxSize; i = i + k)
        {
            if (data->get(i) < data->get(minIndex))
            minIndex = i;

            loopCounter++;
        }
        return minIndex;
}

void Sorting::copyArray(Arraylist *src, Arraylist *dest, int begin, int end)
{
    for(int i = begin; i <= end; i++)
    dest->set(i , src->get(i));
}

void Sorting::merge_(Arraylist *data, Arraylist *result, int begin, int end)
{
   

    if(end - begin <= 0) return;
    int mid = (begin + end) / 2;
    merge_(data , result , begin ,mid);
    merge_(data , result , mid + 1 ,end);

    int i = begin;
    int j = mid + 1;
    for(int k = begin; k <= end; k++)
    {
        if(i > mid)
            result->set(k , data->get(j++));
        else if (j > end)
            result->set(k , data->get(i++));
        else if(data->get(i) > data->get(j))
            result->set(k , data->get(j++));
        else
            result->set(k , data->get(i++));

        loopCounter  ++;    
    }
    copyArray(result , data , begin ,end);

}

void Sorting::quick_(int begin, int end)
{
    if (end - begin <= 0) return;
    int iPivot = pickPivotIndex(begin, end);
    swap(iPivot, end);

    int i = begin, j = end - 1;
    while (i <= j)
    {
        while (i <= j && data->get(i) < data->get(end)) i++;
        while (i <= j && data->get(j) >= data->get(end)) j--;
        if (i < j) swap( i, j);
        loopCounter ++;
    }
    swap(i, end);

    quick_(begin, i - 1);
    quick_(i + 1, end);
}

int Sorting::pickPivotIndex(int begin, int end)
{
    int mid = (begin + end) / 2;
    int a = data->get(begin), b = data->get(mid), c = data->get(end);
        if ((a >= b && b >= c) || (a <= b && b <= c)) 
            return mid;
        else if ((b >= c && c >= a) || (b <= c && c <= a)) 
            return end;
        else if ((c >= a && a >= b) || (c <= a && a <= b)) 
            return begin;
    return mid;
}


void Sorting::seletion(bool verbose) //เมทตอทหลัก
{
    resetCounter();
   clock_t  beginTime = clock(); // ให้ beginTime = เวลาปัจจุบัน
    for(int nElement = maxSize ; nElement > 1 ; nElement--)
    {
        int maxIndex = findMaxIndex(nElement);
        swap(maxIndex , nElement -1);

        if(verbose) display();
    }
  clock_t  endTime = clock(); // ให้ endTime = เวลาปัจจุบัน
  timeElasped = (double)(endTime - beginTime ) /(double)CLOCKS_PER_SEC; // ให้ timeElasped = endTime - beginTime 
}

void Sorting::Insertion()
{
     resetCounter();
   clock_t  beginTime = clock(); // ให้ beginTime = เวลาปัจจุบัน
    for (int ndata =2; ndata <= maxSize; ndata++)
        Insert(ndata);

    clock_t  endTime = clock(); // ให้ endTime = เวลาปัจจุบัน
  timeElasped = (double)(endTime - beginTime ) /(double)CLOCKS_PER_SEC; // ให้ timeElasped = endTime - beginTime     
}

void Sorting::bubble()
{
     resetCounter();
   clock_t  beginTime = clock(); // ให้ beginTime = เวลาปัจจุบัน
    for (int nData = maxSize; nData > 1; nData --)
       bubble_(nData);

     clock_t  endTime = clock(); // ให้ endTime = เวลาปัจจุบัน
  timeElasped = (double)(endTime - beginTime ) /(double)CLOCKS_PER_SEC;   
}

void Sorting::shell()
{
      resetCounter();
   clock_t  beginTime = clock(); // ให้ beginTime = เวลาปัจจุบัน
    for (int k = maxSize / 2; k >= 1; k = k / 2)
    selectK(k);

    clock_t  endTime = clock(); // ให้ endTime = เวลาปัจจุบัน
  timeElasped = (double)(endTime - beginTime ) /(double)CLOCKS_PER_SEC;
}

void Sorting::merge()
{
    resetCounter();
    clock_t  beginTime = clock();
    Arraylist *tdata = new Arraylist(maxSize);
    for(int i=0; i<maxSize;i++)
    tdata->add(i,0);

    copyArray(data ,tdata ,0 ,maxSize-1);
    merge_(tdata,data,0,maxSize-1);
    delete tdata;
    clock_t  endTime = clock();
    timeElasped = (endTime - beginTime ) /(double)CLOCKS_PER_SEC;
   

}

void Sorting::quick()
{
    resetCounter();
    clock_t  beginTime = clock();
    quick_(0,maxSize - 1);
    clock_t  endTime = clock();
    timeElasped = (endTime - beginTime ) /(double)CLOCKS_PER_SEC;
}



void Sorting::random() // สุ่มข้อมูลขึ้นมาไปเก็บไว้ใน *data
{
    for(int i =0; i<maxSize; i++)
        data->set(i,rand() % 100); // % 100 เพราะต้องการค่าในช่วง 0-99

     //display();   
    backup();
}

void Sorting::backup() // coppy *data
{
    for(int i =0; i<maxSize; i++)
        temp->set(i, data->get(i));
}

void Sorting::restore() // *temp->*data
{
    for(int i =0; i<maxSize; i++)
        data->set(i, temp->get(i));
}

void Sorting::resetCounter()
{
     swapCounter = 0; 
     loopCounter = 0; 
     timeElasped = 0.0;
}

void Sorting::diaplayswapCounter()
{
    cout<<"Swap: "<< swapCounter <<" times"<<endl;
}

void Sorting::displayloopCounter()
{
    cout<<"loop: "<< loopCounter << " times"<<endl;

}

void Sorting::displaytimes()
{
    printf("Time: %0.9f second \n", timeElasped);
}

void Sorting::display()
{
    cout<<"Data: ["; 
    for(int i = 0 ;i<maxSize ; i++)
    {
      //  cout<< data->get(i);
      printf("%2d",data->get(i));
         if(i<maxSize -1)
          cout<<" ";
    } 
    cout<<"]"<<endl;
}
