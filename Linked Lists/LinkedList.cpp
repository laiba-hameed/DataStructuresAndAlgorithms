#include <iostream>
#include <cstring>

using namespace std;
class Node {
private:
	int Data;
	Node* Next;
	Node* Previous;

public:
	int GetData();
	Node* GetNext();
	Node* GetPrevious();
	void SetData(int);
	void SetNext(Node*);
	void SetPrevious(Node*);
};

//Node::Node() {

//}

void Node::SetData(int Data)
{
	this->Data = Data;
}

void Node::SetNext(Node* Next) {
	this->Next = Next;
}

void Node::SetPrevious(Node* Previous) {
	this->Previous = Previous;
}


int Node::GetData() {
	return Data;
}

Node* Node::GetNext() {
	return Next;
}

Node* Node::GetPrevious() {
	return Previous;
}

class DoublyLinkedList {
private:
	//int size = 0;
	//int head = NULL;
	//Node prev, next;
	Node* CurrentLocation;
public:
	DoublyLinkedList() {
		CurrentLocation = NULL;
	}
	void Print();
	void Insert(int Data);
	void Delete(int Data);
};



void DoublyLinkedList::Print() {

	Node* tempNode = CurrentLocation;

	if (tempNode == NULL) {
		cout << "List is empty\n";
	}

	else if (tempNode->GetNext() == NULL) {
		cout << tempNode->GetData();
		cout << "-->";
		cout << "NULL" << endl;
	}

	else {
		do {
			cout << tempNode->GetData();
			cout << "-->";
			tempNode = tempNode->GetNext();
		}

		while (tempNode != NULL);

		cout << "NULL" << endl;
	}

}

void DoublyLinkedList::Insert(int Data) {
	Node* newNode = new Node();
	newNode->SetData(Data);
	newNode->SetNext(NULL);

	Node* tempNode = CurrentLocation;

	if (tempNode != NULL) {
		while (tempNode->GetNext() != NULL) {
			tempNode = tempNode->GetNext();
		}
		tempNode->SetNext(newNode);
	}
	else {
		CurrentLocation = newNode;
	}
}

void DoublyLinkedList::Delete(int Data) {
	Node* tempNode = CurrentLocation;

	if (tempNode == NULL) {
		cout << "List is empty" << endl;
	}

	else {
		while (tempNode->GetData() != Data) {
			if (tempNode->GetNext() != NULL) {
				tempNode = tempNode->GetNext();
			}
		}
	}
	delete tempNode;
	tempNode = NULL;
}

int main() {

	DoublyLinkedList li;
	li.Print();
	li.Insert(5);
	li.Insert(10);
	li.Insert(15);
	cout << endl;
	li.Print();
	li.Delete(10);
	cout << endl;
	li.Print();
	cout << endl;
	li.Delete(8);
	cout << endl;
	li.Print();
}