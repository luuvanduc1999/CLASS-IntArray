#include <iostream>

using namespace std;

template <class T>
class Array
{
protected:
    T* data;
    int size;
public:
    Array() : size(0), data(NULL) {}
    Array(int length) {
        size=length;
        data=new T[size];
    }
    Array(const Array& a)
    {
        size=a.size;
        data=new T[size];
        CopyFrom(a.data);
    }
    ~Array()
    {
        delete []data;

    }

public:
    void CopyFrom(T*);
    int Size();
public:
    T& operator[](int index);
    Array& operator=(const Array&a);
    friend ostream& operator<<(ostream& left, const Array<T>& X);
};
//=======================

template <class T>
void Array<T>::CopyFrom(T* X)
{
    for(int i=0; i<size; i++)
        data[i]=X[i];
}

template <class T>
int Array<T>::Size()
{
    return size;
}

template <class T>
T& Array<T>::operator[](int index)
{
    return data[index];
}

template <class T>
Array<T>& Array<T>::operator=(const Array& a)
{
    size=a.Size();
    delete []data;
    data=new T[size];
    CopyFrom(a.data);
    return *this;
}

template <class T>
ostream& operator<<(ostream& left, const Array<T>& X)
{
    left<<"["<<X.data[0];
    for (int i=1; i<X.size; i++)
        left<<", "<<X.data[i];
    left<<"]"<<endl;
    return(left);
}

//=======================

class IntArray:public Array<int>
{
    int isSorted;
public:
    IntArray(int *v, int n) : Array<int> (n) { CopyFrom(v); isSorted=0;}
    void Sort();//sap xep chen
    int Sum();
    double Average();
    int Search(int value);
    friend ostream& operator<<(ostream& left, const IntArray& X);

};

//=======================

int IntArray::Sum()
{
    int S=0;
    for(int i=0; i<size; i++)
        S+=data[i];
    return(S);
}

double IntArray::Average()
{
    return(double(Sum())/size);
}

int IntArray::Search(int x)
{
    int L=0; int R=size-1;
    while (L<R)
    {
        int k=(L+R)/2;
        if (data[k]==x)
            return(k);
        if (data[k]<x) L=k+1;
        else R=k-1;
    }
    return(-1);
}

void IntArray::Sort()
{
    for (int i=1; i<size; i++)
    {
        int k=data[i];
        int j=i-1;
        while ((j>=0) && (k<=data[j]))
        {
            data[j+1]=data[j];
            j--;
        }
        data[j+1]=k;
    }
    isSorted=1;
}

ostream& operator<<(ostream& left, const IntArray& X)
{
    left<<"["<<X.data[0];
        for (int i=1; i<X.size; i++)
    left<<", "<<X.data[i];
    left<<"]"<<endl;
    return(left);
}


int main()
{
    int A[]={4,2,3,1};
    IntArray arr(A,4);

    cout<<arr.Sum()<<' '<<arr.Average()<<endl; //10 2.5
    cout<< (arr.Search(5)>=0?"C":"Khong c")<<"o giai tri 5 trong mang"<<endl;
    cout<< (arr.Search(3)>=0?"C":"Khong c")<<"o giai tri 3 trong mang"<<endl;
    arr.Sort();
    cout<<arr;
}
