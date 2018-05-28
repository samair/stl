#include <iostream>
using namespace std;
#define SIZE 2

template <class T>
class vector{

private:
  int capacity;
  int size;
  T* array;
public:
  vector();

  //overload subscription operator
  T& operator[] (unsigned int index);
  void push_back(T);
  void resize();
};

template <class T>
vector<T>::vector():capacity(SIZE),size(0){
  array = new T[capacity];
}

template <class T>
T& vector<T>::operator[] (unsigned int index){
    if (index<=size){
      return (array[index]);
    }
}

template <class T>
void vector<T>::resize(){

   cout<<"Resizing"<<endl;
   // Allocate twice the current allocated memory
   capacity = capacity*2;
   T* newArray = new T[capacity];

   // copy the existing memory to new newArray
   for (int i =0; i<capacity/2; ++i){
     newArray[i] = array[i];
   }
   delete[] array;
   array = newArray;

}

template <class T>
void vector<T>::push_back(T val){

  //check if size of the internal array is available or not
  if (size == capacity -1){
    //resize the internal array
    cout<<"Reached limit trigger resize"<<endl;
    resize();
  }
  array[size] = val;
  ++size;
}

class test {

   public :
   int  a;
   test ()
   {
     a =1;
   }
};
int main()
{
  cout<<"Hello world"<<endl;
  vector<int> v;
  int a = 1;
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);
  cout<<"Value of v[0]:"<<v[2]<<endl;

  char c = 'd';

  vector<char> vChar;
  vChar.push_back(c);
  cout<<"Value of v[0]:"<<vChar[0]<<endl;


  test* t = new test();
  vector<test*> vtest;
  vtest.push_back(t);
  test* tmp = vtest[0];
  cout<<"Value of vtest[0]:"<<tmp->a<<endl;

}
