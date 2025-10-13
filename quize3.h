#include <iostream>
#include <string>

#define MAX         (20)
#define LOW2HIGH    (1)
#define HIGH2LOW    (2)

using namespace std;

class Arr_Obj
{
private:
    int Arr[MAX];
    int Size;
    int Length;

public:
    Arr_Obj(int initArr[], int initSize, int initLength)
    {
        this->Size = initSize;
        this->Length = initLength;

        for(int i=0; i<Length; i++)
        {
            this->Arr[i] = initArr[i];
        }

        for(int i=this->Length; i<this->Size; i++)
        {
            Arr[i] = 0;
        }
    }
    // void set();
    void Display(void);
    void Append(int x);
    void Insert(int index, int value);
    int Delete(int index);
    void Sort(int optional);
    int Search(int value);
    int Bin_Search(int value);

};