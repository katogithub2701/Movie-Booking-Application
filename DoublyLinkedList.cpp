#include <iostream>
using namespace std;

template<typename T>
struct Node 
{
    T data;
    Node* prev;
    Node* next;
};

template<typename T>
class DoublyLinkedList 
{
    public:
        Node<T>* head;

    public:
        DoublyLinkedList() 
        {
            this->head = nullptr;
        }
        void Insert(T new_data) 
        {
            Node<T>* new_node = new Node<T>;
            new_node->data = new_data;
            new_node->prev = nullptr;
            new_node->next = this->head;

            if (head != nullptr) 
            {
                this->head->prev = new_node;
            }
            this->head = new_node;
        }
        void Display() 
        {
            Node<T>* temp = head;
            while (temp != nullptr && temp->next != nullptr) 
            {
                temp = temp->next;
            }
            while (temp != nullptr) 
            {
                cout << temp->data;
                temp = temp->prev;
            }
        }
        void Remove(T value)
        {
            Node<T>* current = head;
            while (current != nullptr) 
            {
                if (current->data == value) 
                {
                    if (current == head) 
                    {
                        head = current->next;
                        if (head != nullptr) 
                        {
                            head->prev = nullptr;
                        }
                    } 
                    else 
                    {
                        current->prev->next = current->next;
                        if (current->next != nullptr) 
                        {
                            current->next->prev = current->prev;
                        }
                    }
                    delete current;
                    return;
                }
                current = current->next;
            }
        }
};