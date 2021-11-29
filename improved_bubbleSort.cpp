#include <iostream>

using namespace std;

//function for bubble sort
template <class T>
void buubleSort(T *, const int);

template <class T>
void printMe(T *, const int);

int main()
{
    //the static one can be converted to dynamic
    const int size = 10; //size of the array
    int array[size] = {57, 58, 67, 90, 100, 106, 107, 213, 217, 227};

    cout << "\nUnsorted Array : ";
    //printing array
    printMe<int>(array, size);
    cout << endl;

    //calling function to sort acendingly
    //as in this array was sorted thus it will only run single time not for the whole thus optimized
    buubleSort<int>(array, size);

    cout << "Sorted Array   : ";
    //printing array
    printMe<int>(array, size);
    cout << endl;

    return 0;
}

//printing the array
template <class T>
void printMe(T *array, const int size)
{

    int i = 0;

    cout << " { ";

    for (i = 0; i < size; i++)
    {
        cout << array[i] << " , ";
    }

    // \b delete the previous character ---- in this case the extra space and comma
    cout << "\b\b} " << endl;
}

//sorting function
template <class T>
void buubleSort(T *array, const int size)
{
    //the iteration variables
    int i = 0, j = 0;

    //for swaping
    int swap = 0;
    
    //will use in improved
    bool swapDone = false;

    //the loop will move one less to size because this is for passes thus the last one will be sorted automaticallay
    for (i = 0; i < size - 1; i++)
    {
        //is for comparision between the entries
        //minus i indicates the last elemt is on right position --- bubble up and so in each iteration the correct place elements will increase
        //thus -i

        //at starting considering no swap thus
        swapDone = false;

        for (j = 0; j < size - i - 1; j++)
        {

            //comparing and swapping if the current elemnt is greater than the next one
            if (*(array + j) > *(array + j + 1))
            {
                //swapping
                swap = array[j];
                array[j] = array[j + 1];
                array[j + 1] = swap;

                //the swap is done thus
                swapDone = true;
            }
        }

        //if swap was not done in the whole previous pass than mean it was sorted thus
        //this wil be optimised and will run less times
        if(swapDone == false)
        {
            break; //mean no swap was done thus was sorted
        }
    }
}