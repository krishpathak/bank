#include <iostream>
#include <string>
using namespace std;

struct user
{
    string username;
    long password;
    long balance;
    long mobilenum;
    long acc;
};
class Bank {
protected:
     int tot;
     int amount;
public:
	// Function to set the person's data
	void pinval(long x,int y)
	{   long k;
		cout<<"Enter your mobile number"<<endl;
		cin>>k;
		cout<<"Verifying your mobile number"<<endl;
		
		if(k==x)
		{
		    cout<<"Mobile number succesfully verified"<<endl;
		    cout<<"Your pin is "<<y<<endl;
		}
		else
		{
		    cout<<"Mobile number not verified.\n Try again later"<<endl;
		}
	}

	// Function to display the required data
	void showdata(string a,long b,long c,long d)
	{
		cout << "Name:" << a << endl;
		cout << "Account No:" << b << endl;
		cout<< "Your registered mobile number is:"<<c<<endl;
		tot=d;
		cout << "Balance:" << d << endl;
	}

	// Function to deposit the amount in ATM
	void deposit(long b)
	{ 
	    tot=b;
		cout << "\nEnter amount to be Deposited\n";
		cin >> amount;
		tot=tot+amount;
		cout<<"Balance in your account is now"<<tot<<endl;
	}

	// Function to show the balance amount
	void showbal(long a)
	{
	    tot=a;
		tot = tot + amount;
		cout << "\nTotal balance is: " << tot;
	}

	// Function to withdraw the amount in ATM
	void withdrawl(long b)
	{
	    tot=b;
		int a;
		cout << "Enter amount to withdraw\n";
		cin >> a;
		if(a<=tot)
		{
		tot=tot-a;
		cout << "Available Balance is" << tot<<endl;
		}
		else
		{
		    cout<<"Not enough balance in account"<<endl;
		}
	}
};
int main()
{
    user users[1000];
    int n = 0;

    cout << "Welcome to MY Bank" << endl;
    cout << "Choose any one" << endl;
    cout << "1. Create an account\n2. Login to an account\n3. Exit" << endl;
    
    int choice;
    cin >> choice;

    while (choice != 3)
    {
        if (choice == 1)
        {
            user newuser;
            cout << "Enter your username:";
            cin >> newuser.username;
            cout << "Create new pin:";
            cin >> newuser.password;
            cout<<"Enter mobile number to be registered:";
            cin>>newuser.mobilenum;
            cout<<"Enter manual account number:"<<endl;
            cin>>newuser.acc;
            newuser.balance = 0;

            bool userExists = false;
            for (int i = 0; i < n; i++)
            {
                if (users[i].username == newuser.username)
                {
                    cout << "Username already exists";
                    userExists = true;
                    break;
                }
            }

            if (!userExists)
            {
                users[n] = newuser;
                n++;
                cout << "Account successfully created\n";
            }
        }
        else if (choice == 2)
        {
            user loginUser;
            cout << "Enter your username:";
            cin >> loginUser.username;
            cout << "Enter your pin:";
            cin >> loginUser.password;
            loginUser.balance=0;
            bool loggedIn = false;
            for (int j = 0; j < n; j++)
            {
                if (users[j].username == loginUser.username && users[j].password == loginUser.password)
                {
                    cout << "Login successfully!! Welcome " << loginUser.username << endl;
                    loggedIn = true;
                    Bank b;

	int choice;
		cout << "Enter Your Choice\n";
		cout << "\t1. Show pin\n";
		cout << "\t2. Balance Enquiry\n";
		cout << "\t3. Deposit Money\n";
		cout << "\t4. Show Total balance\n";
		cout << "\t5. Withdraw Money\n";
		cout << "\t6. Cancel\n\n";
		cout<<"Enter your choice"<<endl;
		cin >> choice;
		

		// Choices to select from
		switch (choice) {
		    
		case 1:
		    
			b.pinval(loginUser.mobilenum,loginUser.password);
			break;
		case 2:
			b.showdata(loginUser.username,loginUser.acc,loginUser.mobilenum,loginUser.balance);
			break;
		case 3:
			b.deposit(loginUser.balance);
			break;
		case 4:
			b.showbal(loginUser.balance);
			break;
		case 5:
			b.withdrawl(loginUser.balance);
			break;
		case 6:
			exit(1);
			break;
		default:
			cout << "\nInvalid choice\n";
		}
                    break;
                }
            }

            if (!loggedIn)
            {
                cout << "Please check your username and password. Account doesn't exist or credentials are incorrect." << endl;
            }
        }

        cout << "Choose any one" << endl;
        cout << "1. Create an account\n2. Login to an account\n3. Exit" << endl;
        cin >> choice;
    }

    return 0;
}