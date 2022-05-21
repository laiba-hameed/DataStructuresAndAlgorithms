//stack using linked list

#include <iostream>
using namespace std;

class Node
{
private:
	int Data;
	Node* Next;

public:
	Node();
	int GetData();
	Node* GetNext();
	void SetData(int);
	void SetNext(Node*);
};

Node::Node() {

}

int Node::GetData() {
	return Data;
}

Node* Node::GetNext() {
	return Next;
}

void Node::SetData(int Data) {
	this->Data = Data;
}

void Node::SetNext(Node* Next) {
	this->Next = Next;
}


class Stack
{
private:
	Node* Top;

public:
	Stack();
	void Print();
	void Push(int);
	void Pop();
};


Stack::Stack() {
	Top = 0;
}
void Stack::Push(int data)

{

	Node* tempNode = Top;

	Node* newNode = new Node();

	newNode->SetData(data);

	newNode->SetNext(NULL);

	newNode->SetNext(tempNode);

	Top = newNode;

}


void Stack::Print() {
	Node* temp = Top;
	while (temp->GetNext() != NULL) {
		cout << temp->GetData() << " --> ";
		temp = temp->GetNext();
	}

	cout << "NULL";
}

void Stack::Pop() {
	Node* tempNode = Top;
	Top = Top->GetNext();
	delete tempNode;
}


int main()
{
	Stack stk;
	stk.Push(100);
	stk.Push(200);
	stk.Push(300);
	stk.Push(400);
	stk.Push(500);

	stk.Print();

	cout << "\nPoping..\n";
	stk.Pop();
	stk.Print();
	system("pause");
}
