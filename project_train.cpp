#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <ctime>
using namespace std;
class cancel1
{
public:
	int pnr;
	int d, m, y;
	char tname[100];
	int t_id;
	char dest[100];
	char source[100];
	int nosr;
	int amc;
	char cls;
	void canceltickets()
	{
		cout << "Pnr:"
			 << " ";
		cin >> pnr;
		cout << "Date Of Cancellation"
			 << " ";
		cin >> d >> m >> y;
		cout << "...........END OF GETTING DETAILS...........\n";
	}
	void show_details()
	{
		cout << "...........................................\n";
		cout << "...........................................\n";
		cout << "Pnr no:" << pnr;
		cout << "\nTrain no:" << t_id;
		cout << "\nTrain name:" << tname;
		cout << "Boarding point:" << source;
		cout << "Destination pt:" << dest;
		cout << "\nYour class:" << cls;
		cout << "no of seats to be cancelled:" << nosr;
		cout << "\nDate of cancellation:" << d << "-" << m << "-" << y;
		cout << "\nYou can collect:" << amc << "rs" << endl;
		cout << "*****************************************\n";
		cout << ".........END OF CANCELLATION.............\n";
		cout << "*****************************************\n";
	}
};
class reser
{
public:
	char tname[100];
	int t_id;
	char dest[100];
	char source[100];
	int nosr;
	int amc;
	vector<string> pname;
	vector<int> age;
	char cls;
	int d, y, m;
	string temp;
	int temp1;
	int pnr;
	int con;
	void getdetails()
	{
		cout << "Enter the details:" << endl;
		cout << "Train No."
			 << " ";
		cin >> t_id;
		cout << "Train Name"
			 << " ";
		cin >> tname;
		cout << "Destination"
			 << " ";
		cin >> dest;
		cout << "Source"
			 << " ";
		cin >> source;
		cout << "No of seats required";
		cin >> nosr;
		//			for(int i=0;i<nosr;i++)
		//			{
		//				cout<<"Passenger Name"<<" "<<i<<" ";
		//				cin>>temp;
		//				pname.push_back(temp);
		//				cout<<"Passenger Age"<<" ";
		//				cin>>temp1;
		//				age.push_back(temp1);
		//			}
		cout << "Enter the class"
			 << " ";
		cin >> cls;
		cout << "Date of travel"
			 << " ";
		cin >> d >> m >> y;

		cout << "............END OF GETTING DETAILS............\n";
	}
	void displayresdet()
	{
		cout << "...............................................\n";
		cout << "...............................................\n";
		cout << "Train No"
			 << " " << t_id << endl
			 << "Train Name"
			 << " " << tname << endl
			 << "Desination :"
			 << " " << dest << endl
			 << "Source :"
			 << " " << source << endl
			 << "Number of seats"
			 << " " << nosr << endl
			 << "Total Amount"
			 << " " << amc << endl;
		cout << "Passenger No"
			 << " " << pnr << endl;
		//			cout<<"***********************************************\n";
		//        cout<<".........END OF RESERVATION.................\n";
		//        cout<<"***********************************************\n";
	}
};
class login
{
public:
	char id[100];
	char pass[100];
	void getid()
	{
		cout << "Enter the id"
			 << " ";
		cin >> id;
		cout << "Enter the password"
			 << " ";
		cin >> pass;
	}
	void display_id()
	{
		cout << "The ID is"
			 << " " << id << endl;
		cout << "The password is"
			 << " " << pass << endl;
	}
};
class details
{
public:
	char tname[100];
	int t_id;
	char dest[100];
	char source[100];
	int c1, cf1;
	int c2, cf2;
	int d, y, m;
	void getdetails()
	{
		cout << "Enter the details:" << endl;
		cout << "Train No. ";
		cin >> t_id;
		cout << "Train Name ";
		cin >> tname;
		cout << "Destination ";
		cin >> dest;
		cout << "Source ";
		cin >> source;
		cout << "No of seats in class 1 and fair of ticket per seat ";
		cin >> c1 >> cf1;
		cout << "No of seats in class 2 and fair of ticket per seat ";
		cin >> c2 >> cf2;
		cout << "Date of travel (dd mm yyyy)";
		cin >> d >> m >> y;
	}
	void display_details()
	{
		cout << t_id << "\t" << tname << "\t" << dest << "\t" << source << "\t" << c1 << "\t" << cf1 << "\t" << c2 << "\t" << cf2 << "\t" << d << "-" << m << "-" << y << endl;
	}
};

void database();
void user();
void exit();
void user_manage();
void display_pass_details();
void reserve();
void enquiry();
void cancel();
void res();
void show_pass();
void show();

int main()
{
	int ch = 0;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	cout << ".......WELCOME TO RAILWAY RESERVATION SYSTEM..........\n";
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	while (ch <= 3)
	{
		cout << "^^^^^^^^^^^^^^^^^^^^^^MAIN MENU^^^^^^^^^^^^^^^^^^^^\n";
		cout << "1.Admin mode\n2.User mode\n3.Exit\n";
		cout << "Enter your choice:";
		cin >> ch;
		cout << endl;
		if (ch == 1)
		{
			database();
		}
		else if (ch == 2)
		{
			user();
		}
		else if (ch == 3)
		{
			exit();
			break;
		}
	}
	return 0;
}
void database()
{
	int ch = 0;
	fstream f;
	details a;
	string password = "heyu";
	cout << "Enter your password:"
		 << " ";
	string pass = "";
	cin >> pass;
	if (pass == password)
	{
		do
		{
			cout << "...........ADMINISTRATOR MENU...........\n";
			cout << "1.Create detail data base\n2.Add details\n";
			cout << "3.Display details\n4.User management\n";
			cout << "5.Display passenger details\n6.Return to main menu\n";
			cout << "Enter your choice: ";
			cin >> ch;

			if (ch == 1)
			{
				f.open("t1.txt", ios::out);
				char c;
				do
				{
					a.getdetails();
					f.write((char *)&a, sizeof(a));
					cout << "Want to write more entries?" << endl;
					cout << "y-for Yes\nn-for No\n";
					cin >> c;
				} while (c == 'Y' || c == 'y');
				f.close();
			}
			if (ch == 2)
			{
				f.open("t1.txt", ios::app);
				a.getdetails();
				f.write((char *)&a, sizeof(a));
				f.close();
			}
			if (ch == 3)
			{
				f.open("t1.txt", ios::in | ios::out | ios::app);
				f.seekg(0);
				while (f.read((char *)&a, sizeof(a)))
				{
					a.display_details();
					cout << endl;
				}
				f.close();
			}
			if (ch == 4)
			{
				user_manage();
			}
		} while (ch <= 4);
		f.close();
	}
	else
	{
		cout << "Enter the correct password";
	}
}
void exit()
{
	cout << "Thanks for your visit" << endl;
}
void user_manage()
{
	login a;
	int ch;
	fstream f;
	do
	{
		cout << "1.Create id data base\n2.Add details\n";
		cout << "3.Display details\n4.Return to the main menu\n";
		cout << "Enter your choice: ";
		cin >> ch;
		if (ch == 1)
		{
			char c;
			f.open("id.txt", ios::out);
			do
			{
				a.getid();
				f.write((char *)&a, sizeof(a));
				cout << "Want to write more entries?" << endl;
				cout << "y-for Yes\nn-for No\n";
				cin >> c;
			} while (c == 'y');
			f.close();
		}
		if (ch == 2)
		{
			f.open("id.txt", ios::app);
			a.getid();
			f.write((char *)&a, sizeof(a));
			f.close();
		}
		if (ch == 3)
		{
			f.open("id.txt", ios::in);
			f.seekg(0);
			while (f.read((char *)&a, sizeof(a)))
			{
				a.display_id();
				cout << endl;
			}
			f.close();
		}

	} while (ch <= 3);
}

void user()
{
	int ch;
	login a;
	fstream f1;
	f1.open("id.txt", ios::in);
	char id[100];
	char pass[100];
	cout << "Enter your Id"
		 << " ";
	cin >> id;
	cout << "Enter your password"
		 << " ";
	cin >> pass;
	int flag = 0;
	while (f1.read((char *)&a, sizeof(a)))
	{
		if (strcmp(id, a.id) == 0 && strcmp(pass, a.pass) == 0)
		{
			flag = 1;
			do
			{
				cout << "1.Reserve\n2.Cancell\n3.Show Pass\n4.Enquiry\n5.Return to the main menu\n";
				cout << "Enter your choice:";
				cin >> ch;
				cout << endl;
				if (ch == 1)
					reserve();
				if (ch == 2)
					cancel();
				if (ch == 3)
					show_pass();
				if (ch == 4)
					enquiry();
			} while (ch <= 4);
		}
	}
	f1.close();
	if (flag == 0)
		cout << "Wrong ID or Password\n";
}
void reserve()
{
	int ch;
	do
	{
		cout << "1.Reserve\n2.Return to the main menu\n";
		cout << "Enter your choice:";
		cin >> ch;
		cout << endl;
		if (ch == 1)
		{
			res();
		}
	} while (ch == 1);
}
int addr, ad;
void res()
{
	details a;
	reser b;
	time_t t;
	int amount;
	fstream f1;
	fstream f2;
	f1.open("t1.txt", ios::in | ios::out);
	f2.open("p.txt", ios::out | ios::app);
	b.getdetails();

	while (f1.read((char *)&a, sizeof(a)))
	{
		if (b.t_id == a.t_id)
		{
			if (b.cls == 'f')
			{
				if (b.nosr <= a.c1)
				{
					b.amc = a.cf1 * b.nosr;
					addr = f1.tellg();
					ad = sizeof(a.c1);
					f1.seekp(addr - 7 * ad);
					a.c1 = a.c1 - b.nosr;
					srand((unsigned)time(&t));
					b.pnr = rand();
					f1.write((char *)&a.c1, sizeof(a.c1));
					f2.write((char *)&b, sizeof(b));
					b.displayresdet();
					cout << "------------------------------------------------------\n";
					cout << "--------------Your ticket is reserved-----------\n";
					cout << "-----------------End of reservation menu-------\n";
				}
				else
					cout << "No seats available in Class 1";
			}
			else if (b.cls == 's')
			{
				if (b.nosr <= a.c2)
				{
					b.amc = a.cf2 * b.nosr;
					addr = f1.tellg();
					ad = sizeof(a.c2);
					f1.seekp(addr - 5 * ad);
					a.c2 = a.c2 - b.nosr;
					srand((unsigned)time(&t));
					b.pnr = rand();
					f1.write((char *)&a.c2, sizeof(a.c2));
					f2.write((char *)&b, sizeof(b));
					b.displayresdet();
					cout << "------------------------------------------------------\n";
					cout << "--------------Your ticket is reserved-----------\n";
					cout << "-----------------End of reservation menu-------\n";
				}
				else
					cout << "No seats available in Class 2";
			}
		}
	}
	f1.close();
	f2.close();
}
void enquiry()
{
	fstream f;
	f.open("t1.txt", ios::in);
	details a;
	while (f.read((char *)&a, sizeof(a)))
	{
		a.display_details();
		cout << endl;
	}
}

void show_pass()
{
	fstream f;
	reser b;
	f.open("p.txt", ios::in | ios::out | ios::binary);
	f.seekg(0);
	while (f.read((char *)&b, sizeof(b)))
	{
		b.displayresdet();
	}
	f.close();
}
void cancel()
{
	fstream f1, f2, f3;
	f1.open("t1.txt", ios::in | ios::out | ios::binary);
	f2.open("p.txt", ios::in | ios::out | ios::binary);
	f3.open("o.txt", ios::in | ios::out | ios::binary);
	cancel1 c;
	reser b;
	details a;
	int flag = 0;
	c.canceltickets();
	while (f2.read((char *)&b, sizeof(b)))
	{
		if (b.pnr == c.pnr)
		{
			c.t_id = b.t_id;
			strcpy(c.tname, b.tname);
			strcpy(c.source, b.source);
			strcpy(c.dest, b.dest);
			c.nosr = b.nosr;
			c.cls = b.cls;
			if (c.cls == 'f')
			{
				while (f1.read((char *)&a, sizeof(a)))
				{
					if (a.t_id == c.t_id)
					{
						flag = 1;
						int d = a.d;
						int m = a.m;
						cout << a.c1 << endl;
						a.c1 = a.c1 + c.nosr;
						cout << a.c1 << endl;
						int ad = sizeof(a.c1);
						int addr = f1.tellg();
						f1.seekp(addr - (7 * ad));
						f1.write((char *)&a.c1, sizeof(a.c1));
						c.amc = b.amc;
						c.show_details();
					}
				}
			}
			else if (c.cls == 's')
			{
				while (f1.read((char *)&a, sizeof(a)))
				{
					if (a.t_id == c.t_id)
					{
						flag = 1;
						a.c1 = a.c1 + c.nosr;
						int ad = sizeof(a.c1);
						int addr = f1.tellg();
						f1.seekp(addr - 5 * ad);
						f1.write((char *)&a.c1, sizeof(a.c1));
						c.amc = b.amc;
						c.show_details();
					}
				}
			}
		}
		else
			flag = 0;
	}
	if (flag == 0)
		cout << "Incorrect Passenger Number" << endl;
	f1.close();
	f2.close();
	f3.close();
}
