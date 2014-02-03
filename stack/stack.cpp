#include <stdio.h>

template<class T> class Node{
 
   public:
       T data;
       Node<T>* next;
      
       Node<T>();
       Node<T>(T data);
};

template<class T> class Stack{

    public:
        int count;
        void push(T data);
        T pop();
        
        Stack<T>();
        Node<T>* head;
};


template<class T> Node<T>::Node(){
    this->next = 0;
}

template<class T> Stack<T>::Stack(){
    this->head = 0;
}

template<class T> Node<T>::Node(T data){
    this->data = data;
}

template<class T> void Stack<T>::push(T data){
    if(this->head==0){
        // first node we've pushed
        this->head = new Node<T>(data);
        count = 0;
    }else{
        // we have a new head
        Node<T> *temp = new Node<T>(data);
        temp->next = head;
        this->head = temp;
    }
    count++;
}

template<class T> T Stack<T>::pop(){
    T data = head->data;
    head = head->next;
    return data;
}

int main(int argc, char** argv){
    Stack<int> s;

    for (int i=0;i<1000; i++){
        s.push(i);
    }
    printf("count is %d\n", s.count);

    for(int i=0;i<s.count;i++)
    {
        printf("data is %d\n", s.pop());
    }
}
