#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
template <typename T>
class simple_set{
    public:
        std::vector<T> data;
         int size(){
            return data.size();
        }
         bool find(const T& x){
             for (int i = 0; i <data.size(); i++){
                if (x == data[i]){
                    return true;
                }
             }
        return false;
        }
        void erase(const T& x){
            for (int i = 0; i < data.size(); i++)
            {
                if (x == data[i]){
                    data[i] = data.back();
                    data.pop_back();
                }
                else{
                    continue;
                }
            }
            return;
        }
        
        void insert(const T& x)
        {
            if (this->find(x))
            {
                return;
            }
            data.push_back(x);
        }

};

template <typename T>
class simple_set <T*>{
    public:
    std::vector <T*> data;
    int size(){
            return data.size();
        }
    bool find(const T& x){
             for (int i = 0; i < data.size(); i++){
                if (x == *(data[i])){
                    return true;
                }
             }
        return false;
        }
    void insert(T* x)
        {
            if (this->find(*x))
            {return;}
            data.push_back(x);
        }
    void erase(const T& x){
            for (int i = 0; i < data.size(); i++)
            {
                if (x == *(data[i])){
                    data[i] = data.back();
                    data.pop_back();
                }
                else{continue;}
            }
            return;
        }
};


template < >
class simple_set <bool>
{
    public:
    bool has_true;
    bool has_false;
    int size(){
            if (has_true == true && has_false == true){
                return 2;
            }
            else if (has_true && !has_false || !has_true && has_false)
            {
                return 1;
            }
            else {
                return 0;
            } 
        }
    bool find(const bool &x){
             if (x==true){
                if(has_true){
                    return true;
                }
                return false;
             }
             else{
                if (has_false){
                    return true;
                }
                return false;
             }
        }
    void insert(const bool x)
        {
            if (x == true){
                has_true = true;     
        }
            else if (x == false){
                has_false = true;
            }
            else{
                return;
            }
        }
    void erase(const bool& x){
           if (x && has_true)
           {
            has_true = false;
           }
           else if (!x && has_false)
           {
            has_false = false;
           }
           return;
    }
};




/*

insert(n){
    check if n is in the vector
    if yes, return
    if no, push back to vector
}

find (n){
    check if n is in the set
    loop through each element
}

erase(n){
    check if n is in the vector
    if yes, shift over each element in front of the one that you want to erase
    or
    take the last element and copy it into the position that you want to erase, and pop_back
    if no
    do nothing
}

size (n){
    loop through each element and count++
    return count;
}
*/