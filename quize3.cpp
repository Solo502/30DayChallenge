#include "quize3.h"


int main(void)
{
    int Array[] = {1,2,3,4,5, 6,7,8,9};
    Arr_Obj Array_Test = {Array, MAX, size(Array)};

    Array_Test.Display();
    Array_Test.Append(10);
    Array_Test.Display();
    Array_Test.Insert(2, 0xff);
    Array_Test.Display();

    return 0;
}



void Arr_Obj::Display(void)
{
    for(int i=0; i<Length; i++)
    {
        cout<< Arr[i];
        (i < Length - 1)? cout<< " ": cout<< endl;
    }
}

void Arr_Obj::Append(int x)
{
    Arr[Length] = x;
    Length++;
}

void Arr_Obj::Insert(int index, int value)
{
    if(index>Length)
    {
        cout<< "Invalid input"<< endl;
    }
    else
    {
        /* Move value of current index into next index */
        for(int i=Length; i>index; i--)
        {
            Arr[i] = Arr[i-1];
        }

        /* Insert new value */
        Arr[index] = value;

        /* Increase size of array */
        Length++;
    }
}

void Arr_Obj::Delete(int index)
{
    if(index>Length)
    {
        cout<< "Invalid index"<< endl;
    }
    else
    {
        /* Delete this index by copy the next value to it */
        for(int i=index; i<Length-1; i++)
        {
            Arr[i] = Arr[i+1];
        }
        /* Decrease size of array */
        Length--;
    }
}