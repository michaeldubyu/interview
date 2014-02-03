#include <stdio.h>

template<class T> class Node{
 
   public:
       T data;
       Node<T>* next;
      
       Node<T>();
       Node<T>(T data);
       static Node<T>* reverse(Node<T>* head);
};

template<class T> Node<T>::Node(){
    this->next = 0;
}

template<class T> Node<T>* Node<T>::reverse(Node<T>* head){
    if(head->next==0){
        printf("found null\n");
        return head;
    }else{
        Node<T>* last = head;
        printf("head's value is %d\n", head->data);
        Node<T>* first = reverse(head->next);
        last->next = 0;
        first->next = last;
        return first;
    }
}

int main(){
    Node<int> A;
    Node<int> B;
    Node<int> C;

    A.data = 0;
    B.data = 1;
    C.data = 2;

    A.next = &B;
    B.next = &C;
    C.next = 0;

    Node<int>* reversed = Node<int>::reverse(&A);

}
