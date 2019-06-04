
template <class T>
class Array
{
protected:
    T* data; //con tro tro vao ptu dau tien
    int size; //kich thuoc
public:
    Array();
    Array(int length); //hàm tạo array với length phần tử
    Array(const Array& a);
    ~Array();

public:
    void CopyFrom(T*); //copy data từ mảng đầu vào 
    int Size(); //lay kich thuoc array
public:
    T& operator[](int index);
    Array& operator=(const Array&a);
};
//=======================

class IntArray:public Array<int>
{
    int isSorted; //cờ xác định mảng đã sắp xếp hay chưa
public:
    IntArray(int *v, int n); //hàm tạo từ mảng int có n phần tử
    void Sort();    //sắp xếp theo thuật toán chèn
    int Sum(); //hàm tính tổng các phần tử của mảng
    double Average(); //trung bình cộng
    int Search(int value); //tìm vị trí value trong mảng bằng thuật toán tk nhị phân
};


int main()
{
    int A[]={4,2,3,1};
    IntArray arr(A,4);

    cout<<arr.Sum()<<' '<<arr.Average()<<endl; //10 2.5
    cout<< (arr.Search(5)>=0?"C":"Khong c")<<"o giai tri 5 trong mang"<<endl;
    cout<< (arr.Search(3)>=0?"C":"Khong c")<<"o giai tri 3 trong mang"<<endl;
    system("pause");
}
