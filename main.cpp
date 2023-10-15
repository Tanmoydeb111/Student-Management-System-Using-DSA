#include <bits/stdc++.h>
using namespace std;

class Node {
public:
	int roll;
	string Name;
	string Dept;
	int Marks;
	Node* next;
};

Node* head = new Node();

bool check(int x)
{
	if (head == NULL)
		return false;

	Node* t = new Node;
	t = head;

	while (t != NULL) {
		if (t->roll == x)
			return true;
		t = t->next;
	}

	return false;
}

void Insert_Record(int roll, string Name,
				string Dept, int Marks)
{
	if (check(roll)) {
		cout << "Student with this "
			<< "record Already Exists\n";
		return;
	}

	Node* t = new Node();
	t->roll = roll;
	t->Name = Name;
	t->Dept = Dept;
	t->Marks = Marks;
	t->next = NULL;

	if (head == NULL
		|| (head->roll >= t->roll)) {
		t->next = head;
		head = t;
	}

	else {
		Node* c = head;
		while (c->next != NULL
			&& c->next->roll < t->roll) {
			c = c->next;
		}
		t->next = c->next;
		c->next = t;
	}

	cout << "Record Inserted "
		<< "Successfully\n";
}

 Node* middle(Node* start, Node* last)
{
    if (start == NULL)
        return NULL;

     Node* slow = start;
     Node* fast = start->next;

    while (fast != last) {
        fast = fast->next;
        if (fast != last) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    return slow;
}

 Node* binarySearch(Node* head, int value)
{
     Node* start = head;
     Node* last = NULL;

    do {
        Node* mid = middle(start, last);

        if (mid == NULL)
            return NULL;

        if (mid->roll == value)
            
            return mid;

        else if (mid->roll < value)
        {
            start = mid->next;
        }

        else
            last = mid;

    } while (last == NULL || last != start);

    return NULL;
}


void deleteNode(Node** head, int roll) {
    Node* temp = *head;
    Node* prev = NULL;
    if (temp != NULL && temp->roll == roll) {
        *head = temp->next;
        delete temp;
        return;
    }
    while (temp != NULL && temp->roll != roll) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) return;
    prev->next = temp->next;
    delete temp;

}


void Show_Record()
{
	Node* p = head;
	if (p == NULL) {
		cout << "No Record "
			<< "Available\n";
	}
	else {
		cout << "Index\tName\tCourse"
			<< "\tMarks\n";

		while (p != NULL) {
			cout << p->roll << " \t"
				<< p->Name << "\t"
				<< p->Dept << "\t"
				<< p->Marks << endl;
			p = p->next;
		}
	}
}


int main()
{
	head = NULL;
	string Name, Course;
	int Roll, Marks;

     int choice;
    do {
        cout << "Menu:\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Search\n";
        cout << "4. View All\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";

        if (!(cin >> choice)) {
            cerr << "Invalid input. Please enter a valid choice." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        try {
            switch (choice) {
                case 1: {
                    cout << "Enter Name of Student" << endl;
                    cin.ignore();
                    getline(cin, Name);
                    cout << "Enter Roll Number of Student" << endl;
                    cin >> Roll;
                    cout << "Enter Course of Student" << endl;
                    cin.ignore();
                    getline(cin, Course);
                    cout << "Enter Total Marks of Student" << endl;
                    cin >> Marks;
                    Insert_Record(Roll, Name, Course, Marks);
                    break;
                }
                case 2: {
			cout << "Enter Roll Number of Student whose "
					"record is to be deleted\n";
			cin >> Roll;
		Node* p = head;
		while (p) {
			if (p->roll == Roll) {
            deleteNode(&head,Roll);
			cout << "Record Deleted "<< "Successfully\n";
			break;
			}
			p = p->next;
		}
		if (p == NULL)
			cout << "No such Record "
				<< "Available\n";      
		}
             break;       
                case 3: {
			cout << "Enter Roll Number of Student whose "
					"record you want to Search\n";
			cin >> Roll;
            if (binarySearch(head, Roll) == NULL)
                printf("Value not present\n");
            else
            {
		Node* p = head;
		while (p) {
			if (p->roll == Roll) {
				cout << "Roll Number\t"
					<< p->roll << endl;
				cout << "Name\t\t"
					<< p->Name << endl;
				cout << "Department\t"
					<< p->Dept << endl;
				cout << "Marks\t\t"
					<< p->Marks << endl;
			}
			p = p->next;
		}
		        
		    }
                    break;
                }
                case 4: {
                    Show_Record();
                    break;
                }
                case 5:
                    break;
                default:
                    cout<<"Invalid Input"<<endl;
            }
        } catch (const exception& e) {
			cerr<<"Invalid input \n";
        }
    } while (choice != 5);
    return 0;

}
