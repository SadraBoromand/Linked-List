#include <iostream>
#include <cstdlib>

using namespace std;

class Linked_List;

class Node
{
	friend class Linked_List;
	int data = 0; // Data List
	Node* next = NULL; // Next Node
};

class Linked_List
{
	Node* first; // first Node
public:
	int length;
	Linked_List()
	{
		first = new Node;
		first->next = NULL;
		length = 0;
	}
	// for Insert Element in Linked list
	void Insert()
	{
		Node* cur1, * cur2 , * p = new Node;

		int data;
		cout << "\n Enter Data : ";
		cin >> data;

		if (first->next == NULL) // for Linked List Empty
		{
			p->data = data;
			p->next = first->next;
			first->next = p;
			return;
		}

		cur1 = first;
		cur2 = first->next;
		while (cur2 != NULL)
		{
			if (cur1->data < data && cur2->data > data)
			{
				p->data = data;
				cur1->next = p;
				p->next = cur2;
				return;
			}
			if (cur1->data + 1 == data)
			{
				p->data = data;
				p->next = cur1->next;
				cur1->next = p;
				return;
			}
			if (cur2->data + 1 == data)
			{
				p->data = data;
				p->next = cur2->next;
				cur2->next = p;
				return;
			}
			if(cur2 == NULL)
            {
                if (data > cur2->data)
                {
                    p->data = data;
                    p->next = cur2->next;
                    cur2->next = p;
                    return;
                }
            }
			cur1 = cur1->next;
			cur2 = cur2->next;
		}
		cout << "\n The Number is Maxer in List \n";

	}

	// for Delete Element of Linked list
	void Delete()
	{
		Node* cur, * p;
		cur = first;
		p = first->next;

		if (first->next == NULL) // for Linked List Empty
		{
			cout << "\n Linked List is Empty \n";
			return;
		}

		int n = 0;
		cout << "\n Enter Number for Delete : ";
		cin >> n;


		while (p != NULL)
		{
			if (p->data == n)
			{
				cout << "\n Deleted " << n << " in Linked List \n";
				cur->next = p->next;
				delete p; // delete Element
				return;
			}
			cur = cur->next;
			p = cur->next;
		}
		cout << "\n This Number Is Invalid \n";
	}

	// for Delete Linked list
	void Delete_List()
	{
		Node* cur, * p = new Node;

		if (first->next == NULL)// for Linked List Empty
		{
			cout << "\n Linked List is Empty \n";
			return;
		}

		cur = first->next;
		while (cur != NULL)
		{
            p = cur->next;
            delete p; // delete Linked List
            p = new Node;
            cur = cur->next;
            p = cur;
		}

		first->next = NULL;
		cout << "\n Linked List Is Deleted \n";
	}

	// for Search in Linked list
	void Search()
	{
		Node* cur = new Node;
		cur = first->next;

		if (first->next == NULL)// for Linked List Empty
		{
			cout << "\n Linked List is Empty \n";
			return;
		}

		int d = 0;
		cout << "\n Enter Number Data for Seach : ";
		cin >> d;

		while (cur != NULL)
		{
			if (cur->data == d)
			{
				cout << "\n Find " << d << " in Linked List \n";
				return;
			}
			cur = cur->next;
		}
		cout << "\n Not Find " << d << " in Linked List \n";
	}

	// for Display Linked list
	void Show()
	{
		Node* cur = new Node;
		cur = first->next;

		if (first->next != NULL)
		{
			cout << "\n";
			while (cur != NULL)
			{
				cout << " " << cur->data << " -> ";
				cur = cur->next;
			}
			cout << "NULL \n";
		}
		else
			cout << "\n Linked List is Empty \n";
	}
};

void Menu(int* Num_Menu) // Menu for Linked List
{
	cout << "\n\t\t*** Menu *** \n\n";
	cout << "\n (1) Insert in List \n (2) Show List \n (3) Delete in List \n (4) Search List \n (5) Delete Linked List";

	cout << "\n (0) Exit \n";
	cout << "\n Enter Number of Menu : ";
	cin >> *Num_Menu;
}

int main()
{
	int Num_Menu = 0;
	Linked_List* L = new Linked_List; // linked List

	while (true)
	{
		Menu(&Num_Menu);
		switch (Num_Menu)
		{
		case 1:
			L->Insert();
			break;

		case 2:
			L->Show();
			break;

		case 3:
			L->Delete();
			break;

		case 4:
			L->Search();
			break;

		case 5:
			L->Delete_List();
			break;

		case 0:
			exit(0);
			break;

		default:
			cout << "\n Number Is Invalid \n";
			break;
		}
	}
	return 0;
}
