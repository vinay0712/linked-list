#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node *prev;
    node(int val)
    {
        data = val;
        next = NULL;
        prev = NULL;
    }
};
void insertathead(node *&head, int val)
{
    node *newnode = new node(val);
    newnode->next = head;
    if (head == NULL)
    {
        head->prev = newnode;
    }

    head = newnode;
}
void insertattail(node *&head, int val)
{
    if (head == NULL)
    {
        insertathead(head, val);
        return;
    }
    node *n = new node(val);
    node *temp = head;
    while (temp->next != NULL)

    {
        /* code */
        temp = temp->next;
    }
    temp->next = n;
    n->prev = temp;
}
void display(node *head)
{
    node *temp = head;
    while (temp->next != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "null" << endl;
}
void deleteathead(node * & head){
    node * todelete = head;
    head = head ->next;
    head -> prev = NULL; 
    delete todelete;
 }
void deletion(node *&head ,int pos){
    if(pos ==1){
        deleteathead(head);
    }
    node * temp = head;
    int count = 1;

    while(temp-> next != NULL && count != pos){
        temp = temp->next;
           count++;
    }
    temp-> prev->next = temp -> next;
    if(temp->next != NULL){
    temp->next -> prev = temp->prev;
    }
    delete temp;
}
 
int main()
{
    node *node1 = new node(10);
    node *head = node1;
    node *tail = node1;
    insertattail(head, 100);
    insertattail(head, 200);
    insertattail(head, 300);
    insertattail(head, 2400);
    insertattail(head, 2500);
    display(head);
    insertathead(head, 1000);
    insertathead(head, 5000);
    insertathead(head, 50005);
    display(head);
    deletion(head,5);
    display(head);
    deletion(head,1);
    display(head);

    return 0;
}