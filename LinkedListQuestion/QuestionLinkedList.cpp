#include<iostream>
using namespace std;
//class Node
class Node
{
private:
	int data;
	Node* next;
public:
	int getData();
	Node* getNext();
	void setData(int);
	void setNext(Node*);
};
//getter for node class 
int Node::getData()
{
	return data;
}
Node* Node::getNext()
{
	return next;
}
//Setters for Node class
void Node::setData(int data)
{
	this->data = data;
}
void Node::setNext(Node* next)
{
	this->next = next;
}
//Class List
class List
{
private:
	Node* currentLoc;
public:
	List()
	{
		currentLoc = NULL;
	}
	void Print();
	void Insert(int data);
	void Delete(Node* head, int data);
	void setCurrentLoc(Node* currentLoc);
	void AddBetween(Node* currentLoc, int data);
	void FindMin(Node* n);
	void FindMax(Node* n);
	int Search(Node* head, int Value);
	void desiredLoc(int loc, int data);
	void swap(Node*& head, Node*& tail);
	void sort(Node* head);
};

void List::desiredLoc(int loc, int data)
{
	Node* tempNode = currentLoc;
	Node* newNode = new Node();
	newNode->setData(data);
	if (loc == 1)
	{
		newNode->setNext(tempNode);
		currentLoc = newNode;
		return;
	}
	for (int i = 1; i < loc - 1; i++)
	{
		tempNode = tempNode->getNext();
	}
	newNode->setNext(tempNode->getNext());
	tempNode->setNext(newNode);
}
int List::Search(Node* head, int Value)
{
	int S;
	while (head != NULL)
	{
		if (head->getData() == Value)
		{
			S = Value;
		}
		head = head->getNext();
	}
	if (S == Value)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void List::FindMax(Node* n)
{
	int max = n->getData();
	while (n->getNext() != NULL)
	{
		if (max < n->getNext()->getData())
		{
			max = n->getNext()->getData();
		}
		n = n->getNext();
	}
	cout << "Maximum value is: " << max << endl;
}
void List::FindMin(Node* n)
{
	int min = n->getData();
	while (n->getNext() != NULL)
	{
		if (min > n->getNext()->getData())
		{
			min = n->getNext()->getData();
		}
		n = n->getNext();
	}
	cout << "Minimum value is: " << min << endl;
}
void List::AddBetween(Node* currentLoc, int data)
{
	if (currentLoc == NULL)
	{
		cout << " Previous Location Should Not be NULL";
		return;
	}
	else
	{
		Node* newNode = new Node();
		newNode->setData(data);
		newNode->setNext(currentLoc->getNext());
		currentLoc->setNext(newNode);
	}
}
void List::Delete(Node* head, int data)
{
	Node* tempNode = head;
	while (tempNode->getNext()->getData() != data)
	{
		tempNode = tempNode->getNext();
	}
	Node* toDelete = tempNode->getNext();
	tempNode->setNext(tempNode->getNext()->getNext());
	delete toDelete;
}
void List::Insert(int data)
{
	Node* newNode = new Node();
	newNode->setData(data);
	newNode->setNext(NULL);
	Node* tempNode = currentLoc;
	while (tempNode->getNext() != NULL)
	{
		tempNode = tempNode->getNext();
	}
	tempNode->setNext(newNode);
}
void List::setCurrentLoc(Node* currentLoc)
{
	this->currentLoc = currentLoc;
}
void List::Print()
{
	Node* tempNode = currentLoc;
	while (tempNode != NULL)
	{
		if (tempNode->getNext() == NULL)
		{
			cout << tempNode->getData() << " --> NULL ";
		}
		else
		{
			cout << tempNode->getData() << " --> ";
		}
		tempNode = tempNode->getNext();
	}
}
int main()
{
	Node* Node1 = new Node();
	Node* Node2 = new Node();
	Node1->setData(2);
	Node1->setNext(Node2);
	Node2->setData(3);
	Node2->setNext(NULL);
	List l;
	l.setCurrentLoc(Node1);
	l.Insert(0);
	l.Insert(5);
	l.Insert(6);
	cout << "Before Deleting" << endl;
	l.Print();
	cout << endl;
	cout << "After Deleting" << endl;
	l.Delete(Node1, 3);
	l.Print();
	cout << endl;

	cout << "After Adding in Between" << endl;
	l.AddBetween(Node2, 8);
	l.Print();
	cout << endl;
	l.FindMin(Node1);
	l.FindMax(Node1);
	if (l.Search(Node1, 6) == 1)
	{
		cout << "Searched Value Exist" << endl;
	}
	else
	{
		cout << "Searched Value Does Not Exist" << endl;
	}
	l.Print();
	cout << endl;
	cout << endl;
	l.FindMax(Node1);
	l.desiredLoc(2, 588);
	l.Print();

	return 0;
}