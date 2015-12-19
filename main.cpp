#include<iostream>
#include<fstream>
using namespace std;

class library
{
    private:

  struct book
    {
        string title;
        string author;
        int isbn;

        book *next;

    };
    
        book *head;
    public:
        library() 
		{ 
		head = NULL;
		 }
        ~library(){}
        void printList();
        void insertNode();
       void deleteNode(string title1);
       int searchbook(int isbn);
};

void library::insertNode()
{
    book *newNode, *nodePtr, *previousNode;
    newNode = new book;

   	cout << "Title:\t\t\t";
	cin.ignore(500,'\n');
	getline(cin,  newNode->title);
	cout << "Author:\t\t\t";
	getline(cin,  newNode->author);
	cout << "ISBN:\t\t\t";
	cin>>newNode->isbn;


    if (!head)
    {
        head = newNode;
        newNode->next = NULL;
    }
    else
    {
        nodePtr = head;

    while ((nodePtr != NULL))
    {
        previousNode = nodePtr;
        nodePtr = nodePtr->next;
    }

    if (previousNode == NULL)
    {
         head = newNode;
        newNode->next = nodePtr;
    }
    else
    {
        previousNode->next = newNode;
        newNode->next = nodePtr;
    }
    }
}

int library::searchbook(int isbn)
{

	book *temp=new book;
	temp=head;


    int found=0;

	while (temp != NULL)
	{
		if (isbn == temp->isbn)
		{
			cout << temp->title << "\n";
			cout << temp->author << "\n";
			cout << temp->isbn << "\n\n";
			found=1;
		}
		temp = temp->next;
	}
	cout << "\n";
	return found;
}



void library::deleteNode(string title1)
{
   book *nodePtr, *previousNode;

    if (!head)
        cout<<"No Entry ";

    if (head->title == title1)
    {
        nodePtr = head->next;
        delete head;
        head = nodePtr;
    }
    else
    {

        nodePtr = head;

    while (nodePtr->title!=title1)
    {
        previousNode = nodePtr;
        nodePtr = nodePtr->next;
    }

        previousNode->next = nodePtr->next;
        delete nodePtr;
    }
}
void library::printList()
{

  book *temp;
  temp=head;
	while (temp != NULL)
	{
		cout << temp->title << "\n";
		cout << temp->author << "\n";
		cout << temp->isbn << "\n\n";
		temp = temp->next;
	}
	cout << "\n";


}
class Student
{
    struct Node
    {
        string name;
        string rollNo;
        char isbn;
        struct Node* next;
    };
    Node* head;
    public:
    string	isb;
    int found;
    string buffer;
        void insertNode(int isbn);
        void fileSearch();
        
        

};
	void Student::fileSearch()
		{
		  		cout<<"Enter isbn to search "<<endl;
	          	cin>>isb;	
					
															
		ifstream ooutf("input.txt");
		
		  if (!ooutf)
            {
	        	cerr<<"Not Found !!!"<<endl;
		    }
										
	    	while(ooutf)
			{
				  getline(ooutf,buffer);
			
							    
				  found =buffer.find(isb);
												 
					if (found!=string::npos)
						{
					    	cout<<"NameFound in Data Base :"<<endl;
					    
						         cout<<buffer<<endl;
						  	cout<<endl<<endl;
					    	break;
				         }
																				
			}
						 if (found==string::npos)
						  {
						  
							cout<<"Name Not Found In Data  Base :"<<endl;
						}										           	
																							
			ooutf.close();
		}
			

void Student::insertNode(int isbn)
{   library lib;
    Node *newNode, *nodePtr, *previousNode;
    newNode = new Node;
    int found=0;
   	cout << "Student Name:\t\t\t";
	cin.ignore(500,'\n');
	getline(cin,  newNode->name);
	cout << "Roll NO :\t\t\t";
	getline(cin,  newNode->rollNo);
    newNode->isbn=isbn;




    if (!head)
    {
        head = newNode;
        newNode->next = NULL;
    }
    else
    {
        nodePtr = head;

    while ((nodePtr != NULL))
    {
        previousNode = nodePtr;
        nodePtr = nodePtr->next;
    }

    if (previousNode == NULL)
    {
         head = newNode;
        newNode->next = nodePtr;
    }
    else
    {
        previousNode->next = newNode;
        newNode->next = nodePtr;
    }
    }
}


int main()
{
 Student s;
 library lib;

	int choice;
    int isb;
    int isbb;
	string title;
	int found=0;

	do
	{
		cout << "Menu: Select your option\n\n";
		cout << "(1) Add a book to the list\n";
		cout << "(2) Delete a book based on Title\n";
		cout << "(3) Search for a book by ISBN.\n";
		cout << "(4) List all books.\n";
		cout << "(5) Book Issue\n";
		cout << "(6) Quit.\n\n";
		cout << "(7) Search from file \n";
		cout << "Enter your choice ---> ";

		cin >> choice;

		if (1 <= choice && choice <= 7)
		{
			switch (choice)
			{
			case 1:
				lib.insertNode();
				break;
			case 2:
				cout<<"Enter Tilte of book to delete "<<endl;
			 	cin>>title;
			    lib.deleteNode(title);
				break;

			case 3:
                cout << "Book ISBN:\t\t\t";
                cin>>isb;
				found=lib.searchbook(isb);
				if(found==0)
                {
                    cout<<"Book not found in Database ";
                }
				break;
            case 5:

                cout << "Enter Book ISBN:\t\t";
                cin.ignore(500,'\n');
                cin>>isbb;
                if(lib.searchbook(isbb)==0)
                {
                    cout<<"Book Not found in Database";
                }else
                {
                         s.insertNode(isbb);
                }

                break;
			case 4:
                lib.printList()	;
				break;
          
           case 7:
                s.fileSearch();
				break;
			default:
				cout << "Invalid choice.  Enter again.\n\n";
				break;
			}
		}
	}
	while (choice != 6);

  	return 0;
}
