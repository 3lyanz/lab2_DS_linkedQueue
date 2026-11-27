#include <iostream>


using namespace std;


class Node{
    public:
    int data;
    Node * next;
    Node * prev;
    Node(int val){
        this->data=val;
        this->next=NULL;
        this->prev=NULL;
    }
};

class Queue{
    Node * head;
    Node * tail;
    int count;
    public:

    Queue(){
        this->head=NULL;
        this->tail=NULL;
        this->count=0;
    }
    ~Queue(){
        Node * current = head;
        while(current!=NULL){
            Node* nextnode = current->next;
            delete current;
            current = nextnode;
        }
        head =NULL;
        tail = NULL;
        count = 0 ;
    }

    void Enqueue(int data){
        Node * newnode = new Node(data);
        if(head == NULL && tail == NULL){
            head = tail  = newnode;
        }
        else{
            tail->next=newnode;
            newnode->prev=tail;
            tail=tail->next;
        }
        cout<<data<<" is added"<<endl;
        count++;
    }
    void Dequeue(){
        if (tail == NULL) {
        cout << "Stack is empty" << endl;
        return;
        }

        if (head == tail) {
        delete tail;
        head = NULL;
        tail = NULL;
        count--;
        return;
        }
        Node * oldhead = head;
        head = head->next;
        head->prev=NULL;
        delete oldhead;
        count -- ;
    }


        // void insertafter(int data , int afterdata){
        //     Node * newnode = new Node(data);
        //     Node *current = head;
        //     do{
        //         if(current->data==afterdata){
        //             current->next = newnode;
        //             newnode->prev = current;
        //             cout<<data<<" is added after "<< afterdata <<endl;
        //             count++;
        //             break;
        //         }
        //         else{
        //             current=current->next;
        //         }

        //     }while(current!=NULL);
        // }

        // void insertbefore(int data , int beforedata){
        //     Node * newnode = new Node(data);
        //     Node *current = head;
        //     while(current!=NULL){
        //         if(current->data==beforedata){
        //             newnode->next=current;
        //             newnode->prev=current->prev;
        //             if(current==head){
        //                 head=newnode;
        //             }else{
        //                 current->prev->next=newnode;
        //             }
        //             cout<<data<<" is added before "<< beforedata <<endl;
        //             count++;
        //             break;
        //         }
        //         else{
        //             current=current->next;
        //         }
        //     }
        // }

    void getcount(){
        cout<<"the count is : "<<count<<endl;
    }

        // int getdatabyindex(int index){
        //     if (index < 0) {
        //         return -1;
        //     }

        //     int countforindex = 0;
        //     Node * current = head;
        //     while (current != nullptr) {
        //         if (countforindex == index) {
        //             return current->data;
        //         }
        //         current = current->next;
        //         ++countforindex;
        //     }
        //     // The index is out of range.
        //     return -1;
        // }

    void display(){
        Node * current = tail;
        while(current!=NULL){
            cout<<current->data<<endl;
            current=current->prev;
        }
    }        
};

// class Queue{
//      private:
//         // Node *front;
//         // Node *rear ;
//         linkedlist * l_list  ; 
//      public:   


//     Queue()
//     {
//         this->l_list=new linkedlist;
//         //ctor
//     }
//     // Stack(Stack & s)
//     // {
//     //     cout<<"I 'm ghost"<<endl;
//     //     //ctor
//     // }
//     // Stack(int sizeArray)
//     // {
//     //     this->sizeArray=sizeArray;
//     //     this->top=-1;
//     //     this->items=new int[sizeArray];
//     //     //ctor
//     // }
//     void Enqueue(int data){
//     // 5 items push() push()   push() push() push()
//     // if(top >= sizeArray -1){//5
//     //         cout<<"Stack is FUll"<<endl;
//     //         return ; //Early Exit
//     // }
//     l_list->add(data);
//     }
//     void Dequeue(){
//         // if(top == -1){
//         //     //LOG("Stack Empty");
//         //     return 0;
//         //     //return ??
//         // }
//         // items[top]=0;
//         // //LOG("Before POP"<<top);
//         // top--;
//         // //LOG("After POP"<<top);
//         // return 1;
//         l_list->remove();

//     }

//     void display(void){
//         // for(int i=top; i>=0; i--){
//         //         cout<<items[i]<<endl;
                
//         //     }
//         // }
//         // Stack & operator=(const Stack s){
//         // delete [] this->items;
//         // items=new int[s.sizeArray];
//         // this->sizeArray=s.sizeArray;
//         // this->top=s.top;
//         // for(int i=0; i<=top; i++){
//         //         this->items[i]=s.items[i];
//         // }
//         // return *this;
//         l_list->display();


//     }
    

//     ~Queue()
//     {
//         delete l_list;
//         l_list=nullptr;
//         //dtor
//     }
// };





int main(){

    Queue linkedqueue;
    linkedqueue.Enqueue(4);
    linkedqueue.Enqueue(4);
    linkedqueue.Enqueue(4);
    linkedqueue.display();
    cout<<"======================="<<endl;
    linkedqueue.Dequeue();
    linkedqueue.display();

}