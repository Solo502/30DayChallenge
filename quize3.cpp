#include "quize3.h"


int main(void)
{
    int Array[] = {0, 3, 4, 10, 1, 2, 5,8, 9, 11, 20, 25, 99};
    Arr_Obj Array_Test = {Array, MAX, size(Array)};
    int result;

    Array_Test.Display();
    Array_Test.Append(7);
    Array_Test.Display();
    Array_Test.Sort(LOW2HIGH);
    // Array_Test.Insert(2, 0xff);
    Array_Test.Display();
    result = Array_Test.Bin_Search(98);

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

int Arr_Obj::Delete(int index)
{
    int retVal = Arr[index];

    if(index>Length)
    {
        cout<< "Invalid index"<< endl;
        retVal = -1;
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
    return retVal;
}

void Arr_Obj::Sort(int optional)
{
    for(int i=0; i<Length-1; i++)
    {
        for(int j=i+1; j<Length; j++)
        {
            if((optional == LOW2HIGH) ? (Arr[i]>Arr[j]) : (Arr[i]<Arr[j]))
            {
                int tmp = Arr[i];
                Arr[i] = Arr[j];
                Arr[j] = tmp;
            }
        }
    }
}

int Arr_Obj::Search(int value)
{
    for(int i=0; i<Length; i++)
    {
        if(Arr[i] == value)
        {
            cout<< value<< " is found in index "<< i<< endl;
            return i;
        }
    }
    cout<< value<< " is not found in Arr"<< endl;

    return -1;
}

int Arr_Obj::Bin_Search(int value)
{
    int high, low;

    high = Length;
    low = 0;

    while(low<=high)
    {
        int mid = (high+low)/2;
        if(value > Arr[mid])
        {
            low = mid+1;
        }
        else if(value < Arr[mid])
        {
            high = mid-1;
        }
        else
        {
            cout<< value<< " is found in Arr at index "<< mid<< endl;
            return mid;
        }
    }

    cout<< value<< " is not found in Arr"<< endl;
    return -1;
}