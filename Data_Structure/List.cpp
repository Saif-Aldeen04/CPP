#include<iostream>
using namespace std;

class List{
    
    private:

            int* arr;
            int cap;
            int size;

            void resize(bool plusorminus){
                if(plusorminus){
                    int newcap = 2 * cap;
                    int* newarr = new int[newcap];

                    for (int i = 0; i < cap; i++)
                    {
                        newarr[i] = arr[i];
                    }

                        delete[] arr;
                        arr = newarr;
                        cap = newcap;
                }else{
                    int newcap = cap / 2;
                    int* newarr = new int[newcap];

                    for (int i = 0; i < newcap; i++)
                    {
                        newarr[i] = arr[i];
                    } 

                        delete[] arr;
                        arr = newarr;
                        cap = newcap;
                }
            }

    public:

        List(int incap){
            cap = incap;
            size = 0;
            arr = new int[cap];
        }
        
        ~List(){
            delete[] arr;
        }

        void insert(int element){
            if(cap == size){
                resize(true);
            }
            arr[size++] = element;
        }

        void remove(int index){

            if(index < 0 || index >= size){
                cout << "There is invalid index.";
                return;
            }

            for (int i = index; i < size-1; i++)
            {
                arr[i] = arr[i + 1];
            }

            size--;

            if(size == cap / 2){
                resize(false);
            }

        }

        int count(){
            return size;
        }

        int read(int index){
            
            return arr [index];
        }

        void add(int element, int index){
            if(index < 0 || index >= cap){
                cout << "There is invalid index.";
                return;
            }

            if(index < cap && index >= size){

                arr [index] = element;
                size++;

            }else{

                if(cap == size){
                resize(true);
                }
                
                for (int i = size; i > index; i--) { 
                    arr[i] = arr[i - 1];
                }


                arr[index] = element;
                size++;
                
            }
        }

        void search(int element){
            bool check = false;

            for (int i = 0; i < size; i++){
                
                if(element == arr[i]){
                    cout << "The element found in index" << i;
                    check = true;
                    break;
                }

            }

            if(!check){
                cout<< "Not found.";
            }
        }
};