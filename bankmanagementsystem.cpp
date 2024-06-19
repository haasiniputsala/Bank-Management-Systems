#include <iostream>  // input and output stream operations (e.g., std::cin, std::cout).
#include <conio.h>   // console input/output operations, especially for functions like getch() and kbhit().
#include <stdio.h>   // standard input and output operations (e.g., printf, scanf, etc.).
#include <fstream>   // file input and output operations (e.g., file streams like ifstream, ofstream).
#include <windows.h> // Windows-specific functions and definitions (e.g., Sleep(), CreateFile(), etc.).

using namespace std;

// Since it's OOP we create a class called bank
class bank {
    private:
        float balance;
        string id,pass,name,fname,address,phone,pin;
    public:
        void menu();
        void bank_management();
        void atm_management();
        void new_user();
        void existing_user();
        void withdraw();
        void deposit();
        void transfer();
        void payment();
        void search();
        void edit();
        void udelete();
        void show_records();
        void show_payments();
        void user_balance();
        void atm_withdraw();
        void atm_acctdetails();
};
// Defining member function menu under bank
void bank::menu() {
    p: // Labelled p as a repeat function till exit is clicked on
    system("cls"); // System clear screen

    // Making a variable choice for main menu
    int choice;

    // Making the input type in variables for bank management
    char ch;
    string pin, pass;
    string email;

    cout << "\n\n\t\t\t Control Panel";
    cout << "\n\n 1. Bank Management";
    cout << "\n\n 2. ATM Management";
    cout << "\n\n 3. Exit";
    cout << "\n\n Enter your choice: ";
    cin >> choice;

    switch (choice) { // Making switch case for the choices
    case 1:
        cout << "\n\n\t\tAccount Login";
        cout << "\n\n Enter your E-mail: ";
        cin >> email;
        cout << "\n\n\t\t Enter PIN: ";
        pin = ""; // Ensure pin is empty before input
        for (int i = 1; i <= 5; i++) {
            ch = getch(); // Taking user value in ch
            pin += ch;    // Adding ch value to initial pin value
            cout << "*";  // To show pin number as *
        }
        cout << "\n\n Enter Password: ";
        pass = ""; // Ensure pass is empty before input
        for (int i = 1; i <= 5; i++) {
            ch = getch(); // Taking user value in ch, overrides prev value
            pass += ch;   // Adding ch value to initial pin value
            cout << "*";  // To show pin number as *
        }
        // Debugging output
        cout << "\nEmail entered: " << email;
        cout << "\nPIN entered: " << pin;
        cout << "\nPassword entered: " << pass;
        if (email == "batman@gmail.com" && pin == "12345" && pass == "lbats") 
        {
            cout<<"\n\n\t\tLogin Successful";
            bank_management();
        }
        else 
        {
            cout << "\n\n\t\tYour Credentials are not valid. Please try again";
        }
        break;

    case 2:
        atm_management(); // atm management function call
        break;

    case 3:
        cout << "\n\n Thank you for using our services";
        exit(5); // Built-in function to exit

    default:
        cout << "\n\n Invalid Value \n Please try again";
    }
    getch(); // Will take in any character from the user
    goto p;  // To repeat again from a specific point
}

// Defining member function bank_management under bank
void bank::bank_management() 
{
    p: //back to this point again
    system("cls");
    int choice;
    cout<<"\n\n\t\t\t BANK MANAGEMENT SYSTEM";
    cout<<"\n\n 1. New User";
    cout<<"\n\n 2. Existing User";
    cout<<"\n\n 3. Deposits";
    cout<<"\n\n 4. Withdrawals";
    cout<<"\n\n 5. Transfer";
    cout<<"\n\n 6. Payments";
    cout<<"\n\n 7. Search User Record";
    cout<<"\n\n 8. Edit User Record";
    cout<<"\n\n 9. Delete User Record";
    cout<<"\n\n 10. Show all records";
    cout<<"\n\n 11. Payments for all Records";
    cout<<"\n\n 12. Go back to Home page";
    cout<<"\n\n Enter your choice";
    cin>>choice;
    switch(choice)
    {
        case 1:
            new_user();
            break;
        case 2:
            existing_user();
            break;
        case 3:
            deposit();
            break;
        case 4:
            withdraw();
            break;
        case 5:
            transfer();
            break;
        case 6:
            payment();
            break;
        case 7:
            search();
            break;
        case 8:
            edit();
            break;
        case 9:
            udelete();
            break;
        case 10:
            show_records();
            break;
        case 11:
            show_payments();
            break;
        case 12:
            break;
        default:
            cout<< "\n\n Invalid Value \n Please try again";
    }
    getch();
    goto p;
}

// Defining new_user function 
void bank ::new_user()
{
    p:
    system("cls");
    fstream file; //to check if ID is unique, hence a file is created with variable file
    int p;
    float b; //balance
    string i,n,f,a,pa,ph,pi; //id,name,fname,pswrd,add,phno,pincode
    cout<<"\n\n\t\t\tNew User Sign Up";
    cout<<"\n\nUser Email ID:";
    cin>>id;
    cout<<"\n\n\t\tFull Name:";
    cin>>name;
    cout<<"\n\n\t\tFather's Name:";
    cin>>fname;
    cout<<"\n\n\t\tAddress:";
    cin>>address;
    cout<<"\n\nPin Code (5 Digit):";
    cin>>pin;
    cout<<"\n\n\t\tSet Password:";
    cin>>pass;
    cout<<"\n\nPhone No.:";
    cin>>phone;
    cout<<"\n\n\t\tCurrent Balance:";
    cin>>balance;
    //opening a file bank, to check if user already preexists
    file.open("bank.txt",ios::in); 
    if(!file)
    {
        // new data appended to the end of the file without overwriting.
        file.open("bank.txt",ios::app|ios::out); //app-append, out-output write
        file<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<" \n";
        file.close();
    }
    else
    {
        file>>i>>n>>f>>a>>p>>pa>>ph>>b;
        while(!file.eof()) //file reading 
        {
            if(i == id)
            {
                cout<<"\n\n User already exists.";
                getch();
                goto p;
            }
            file>>i>>n>>f>>a>>p>>pa>>ph>>b;
        }
        file.close();
        file.open("bank.txt",ios::app|ios::out);
        file<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<" \n";
        file.close();
    }
    cout<<"\n\n User signed up Succesfully";
}

// Defining Existing User function
void bank::existing_user()
{
    system("cls");
    fstream file; //file variable declaration
    string t_id;
    int found = 0;
    cout<<"\n\n Existing User Login";
    file.open("bank.txt",ios::in); //in-read
    if(!file)
    {
        cout<<"\n\nLooks like you haven't made an account.";
    }
    else
    {
        cout<<"\n\nUser Email ID:";
        cin>>t_id; //test_id for the user.
        //to read the file - function used
        file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
        while(!file.eof())
        {
            if(t_id == id)
            {
                system("cls");
                cout<<"\n\n\t\tExisting User Login";
                cout<<"\n\nUser Email Id"<<id<<"   Pin Code"<<pin<<"   Password:"<<pass;
                found++;
            }
            file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
        }
        file.close();
        if(found == 0)
        cout<<"\n\nUser not found.";
    }
}

// Defining Deposit function
void bank::deposit()
{
    fstream file, file1; //new file for updates
    string t_id;
    float dep;
    int found = 0;
    system("cls");
    cout<<"\n\n\t\tDeposits";
    file.open("bank.txt",ios::in); //to access the files and read content
    if(!file)
    {
        cout<<"\n\nFile can't be accessed";
    }
    else
    {
        cout<<"\n\nUser Email ID:";
        cin>>t_id; //test_id for the user.
        file1.open("bank1.txt",ios::app|ios::out);
        //to read the file - function used
        file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
        while(!file.eof())
        {
            if(t_id == id)
            {
                cout<<"\n\nAmount to be Deposited:";
                cin>>dep;
                balance = balance+dep;//to add to existing balance
                file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<" \n";
                found++;
                cout<<"\n\n\t\t\t Your amount is"<<dep<<"  "<<"is sucessfully deposited.";
            }
            else
            {
                  file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<" \n";
            }
            file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
        }
        file1.close();
        file.close();
        remove("bank.txt");
        rename("bank1.txt","bank.txt");
        if(found == 0)
        cout<<"\n\nUser not found.";
    }
}

// Defining withdraw function
void bank::withdraw()
{
    fstream file, file1; //new file for updates
    string t_id;
    float with;
    int found = 0;
    system("cls");
    cout<<"\n\n\t\t Withdraw";
    file.open("bank.txt",ios::in); //to access the files and read content
    if(!file)
    {
        cout<<"\n\nFile can't be accessed";
    }
    else
    {
        cout<<"\n\nUser Email ID:";
        cin>>t_id; //test_id for the user.
        file1.open("bank1.txt",ios::app|ios::out);
        //to read the file - function used
        file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
        while(!file.eof())
        {
            if(t_id == id)
            {
                cout<<"\n\nAmount to be Withdrawed:";
                cin>>with;
                if(with <= balance)
                {
                balance = balance-with;//to add to existing balance
                file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<" \n";
                cout<<"\n\n\t\t\t Your amount is"<<with<<"  "<<"is sucessfully withdrawed.";
                }
                else
                {
                    //to update the new file.
                    file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<" \n";
                    cout<<"\n\n\t\t\t Your Current Balance is less.\n\t\t\tBalance:"<<balance;
                }
            }
            else
            {
                  file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<" \n";
            }
            file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
        }
        file1.close();
        file.close();
        remove("bank.txt");
        //getting rid of old unwanted data
        rename("bank1.txt","bank.txt");
        if(found == 0)
        cout<<"\n\nUser not found.";
    }
}

// Defining Transfer Function
void bank::transfer()
{
    fstream file,file1; 
    //making dual variable files so that the information can be updated.
    string s_id,r_id;
    float amount;
    int found;
    system("cls");
    cout<<"\n\n\t\t\t Payment Transfers";
    file.open("bank.txt",ios::in); //to access the files and read content
    if(!file) //if file doesn't exist
    {
        cout<<"\n\nFile can't be accessed";
    }
    else
    {
        cout<<"\n\nEnter the Sender ID:";
        cin>>s_id;
        cout<<"\n\nEnter the Reciever ID:";
        cin>>r_id;
        cout<<"\n\nEnter transaction amount:";
        cin>>amount;        
         //to recall the file
        file1.open("bank1.txt",ios::app|ios::out);
        file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
        while(!file.eof()) // file reading
        {
            if(s_id == id && amount >= balance) //if sender id = id or reciever id = id
            found++;               
            else
            found++;  
            file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
        }
        file.close();
        if(found ==2)
        {
            file.open("bank.txt",ios::in);
            file1.open("bank1.txt",ios::app|ios::out);
            file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
            while(!file.eof())
            {
                if(s_id == id)
                {
                    balance =balance- amount;
                    file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<" \n";
                    // saved in new file
                }
                else if(r_id == id)
                {
                    balance = balance+amount;
                    file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<" \n";
                }
                else 
                {
                    file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<" \n";
                }
                file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
            }
            file.close();
            file1.close();
            remove("bank.txt");
            rename("bank1.txt","bank.txt");
        }
        else
        {
            cout <<"\n\n\t\t\tBoth Transaction ID's can't be found";
        }
    }
}

// Defining Payment Functions
void bank::payment()
{
    system("cls");
    fstream file, file1;
    int found=0;
    string b_name, t_id;
    float amount;
    SYSTEMTIME x; //for current time
    cout<<"\n\n\t\t\tBill Payments";
    file.open("bank.txt", ios::in);//in- read mode
    if(!file)
    cout<<"\n\n File doesn't exist.";
    else
    {
        cout<<"\n\n Enter User ID:";
        cin>>t_id;
        cout<<"\n\n Bill Name:";
        cin>>b_name;
        cout<<"\n\n Amount:";
        cin>>amount;
        file1.open("bank1.txt",ios::app|ios::out);
        file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
        while(!file.eof())
        {
            if(t_id == id && amount <= balance)
            {
                balance = balance - amount;
                file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<" \n";
                found++;
            }
            else
            {
                file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<" \n";
            }
            file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
        }
        file.close(); 
        file1.close();
        remove("bank.txt");
        rename("bank1.txt","bank.txt");
        if(found ==1)
        {
            GetSystemTime(&x);
            file.open("bill.txt",ios::app|ios::out);
            file<<t_id<<" "<<b_name<<" "<<amount<<" "<<x.wDay<<"/"<<x.wMonth<<"/"<<x.wYear<<"\n";
            file.close();
            cout<<"\n\n\t\t\t"<<b_name<<"Bill paid Sucessfully.";
        }
        else
        {
            cout<<"\n\nInvalid amount input.";
        }
    }
}

// Defining user searching account
void bank::search()
{
    system("cls");
    string t_id;
    int found =0;
    fstream file;
    cout<<"\n\n\t\t\tSearch User record";
    file.open("bank.txt", ios::in);
    if(!file)
    {
        cout<<"\n\n File Opening Error";
    }
    else
    {
        cout<<"\n\n Enter the User ID:";
        cin>>t_id;
        file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
        while(!file.eof())
        {
            if(t_id == id)
            {
                system("cls");
                cout<<"\n\n\t\t\tSearch User record";
                cout<<"\n\nUser Information: "<<t_id<<" Name: "<<name<<" Father's Name: "<<fname<<" "<<"\n";
                cout<<"\n Address:"<<address<<" Pin"<<pin<<"Password:" <<pass;
                cout<<"\n Phone no:"<<phone<<" Corrent Balance:"<<balance;
                found++;
            }
            file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
        }
        file.close();
        if(found == 0)
        cout<<"\n\n User ID can't be found.";
    }
}

// Defining Edit user function
void bank::edit()
{
    system("cls");
    int pin;
    float balance;
    fstream file, file1;
    string t_id;
    int found = 0,pi;
    string n,f,a,p,ph;
    cout<<"\n\n\t\t\tEdit User Record";
    file.open("bank.txt", ios::in);
    if(!file)
    {
        cout<<"\n\n File Opening Error";
    }
    else
    {
        cout<<"\n\n User ID:";
        cin>>t_id;
        file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
        file1.open("bank1.txt", ios::app|ios::out);
        while(!file.eof())
        {
        if(t_id ==id)
        {
            cout<<"\n\n\t\tFull Name:";
            cin>>n;
            cout<<"\n\n\t\tFather's Name:";
            cin>>f;
            cout<<"\n\n\t\tAddress:";
            cin>>a;
            cout<<"\n\nPin Code (5 Digit):";
            cin>>pi;
            cout<<"\n\n\t\tSet Password:";
            cin>>p;
            cout<<"\n\nPhone No.:";
            cin>>ph;
            cout<<"\n\nCurrent balance.:";
            file1<<" "<<id<<" "<<n<<" "<<f<<" "<<a<<" "<<pi<<" "<<p<<" "<<ph<<" "<<balance<<" \n";
            cout<<"\n\n\n\t\t\tPersonal record updated sucessfully";
            found++;
        }
        else
        {
            file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<" \n";
        }
        file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
        }
        file.close();
        file1.close();
        remove("bank.txt");
        rename("bank1.txt","bank.txt");
        if(found==0)
        cout<<"\n\n User ID can't be found.";
    }
}

// Defining delete user function
void bank::udelete()
{
    system("cls");
    fstream file, file1;
    string t_id;
    int found = 0;
    cout<<"\n\n\t\t\tDelete User Record";
    file.open("bank.txt", ios::in);
    if(!file)
    {
        cout<<"\n\n File Opening Error";
    }
    else
    {
        cout<<"\n\n User ID:";
        cin>>t_id;
        file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
        file1.open("bank1.txt", ios::app|ios::out);
        while(!file.eof())
        {
        if(t_id ==id)
        {
            cout<<"\n\n\n\t\t\tPersonal record deleted sucessfully";
            found++;
        }
        else
        {
            file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<" \n";
        }
        file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
        }
        file.close();
        file1.close();
        remove("bank.txt");
        rename("bank1.txt","bank.txt");
        if(found==0)
        cout<<"\n\n User ID can't be found.";
    }
}

// Defining show all records function
void bank::show_records()
{
    system("cls");
    int found =0;
    cout<<"\n\n\t\t\tShow All User Records";
    fstream file;
    file.open("bank.txt", ios::in);
    if(!file)
    {
        cout<<"\n\n File Opening Error";
    }
    else
    {
        file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
        while(!file.eof())
        {
            cout<<"\n\n\n UserID:"<<id;
            cout<<"\n\n\n Name:"<<name;
            cout<<"\n\n\n Father Name:"<<fname;
            cout<<"\n\n\n Address:"<<address;
            cout<<"\n\n\n Pin:"<<pin;
            cout<<"\n\n\n Password:"<<pass;
            cout<<"\n\n\n Phone No.:"<<phone;
            cout<<"\n\n\n Current Balance:"<<balance;
            cout<<"\n\n ---------------------------------------------------------------";
            file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
            found++;
        }
        file.close();
        if(found==0)
        cout<<"\n\n No Users Exist.";
    }
}

// Defining Show Payments Function
void bank::show_payments()
{
    system("cls");
    int found =0;
    float amount, id, name;
    string c_d; //c-current, d-day, m-month, y-year
    cout<<"\n\n\t\t\tShow All Payment Records";
    fstream file;
    file.open("bill.txt", ios::in);
    if(!file)
    {
        cout<<"\n\n File Opening Error";
    }
    else
    {
        file>>id>>name>>amount>>c_d;
        while(!file.eof())
        {
            cout<<"\n\n\n UserID:"<<id;
            cout<<"\n\n\n Bill Name:"<<name;
            cout<<"\n\n\n Bill Amount:"<<amount;
            cout<<"\n\n\n Date:"<<c_d;
            cout<<"\n\n ---------------------------------------------------------------";
            file>>id>>name>>amount>>c_d>>c_m>>c_y;
            found++;
        }
        file.close();
        if(found==0)
        cout<<"\n\n No Payments to show.";
    }
}
    

// Defining member function atm_management under bank
void bank::atm_management() 
{
    p: //back to this point again
    system("cls");
    int choice;
    cout<<"\n\n\t\t\t ATM MANAGEMENT SYSTEM";
    cout<<"\n\n 1. User Login & Check Balance";
    cout<<"\n\n 2. Withdraw Amount";
    cout<<"\n\n 3. Account Details";
    cout<<"\n\n 4. Go Back";
    cout<<"\n\n Enter your choice";
    cin>>choice;
    switch(choice)
    {
        case 1: 
            user_balance();
            break;
        case 2:
            atm_withdraw();
            break;
        case 3:
            atm_acctdetails();
            break;
        case 4:
            break;
        default:
            cout << "\n\n Invalid Value \n Please try again";
    }
    getch();
    goto p;
}

// Defining user_balance function for ATM
void bank::user_balance()
{
    system("cls");
    string t_id,t_pin, t_pass;
    char ch;
    int found;
    cout<<"\n\n\t\t\t User Login and Balance check";
    fstream file;
    file.open("bank.txt", ios::in);
    if(!file)
    {
        cout<<"\n\n File Opening Error.";
    }
    else
    {
        cout<<"\n\n User ID: ";
        cin>>t_id;
        cout<<"\n\n\t\t PinCode:";
        for(int i=1; i<=5;i++)
        {
            ch = getch();
            t_pin = t_pin + ch;
            cout<<"*";
        }
        cout<<"\n\n Password:";
        for(int i=1; i<=5;i++)
        {
            ch = getch();
            t_pass = t_pass + ch;
            cout<<"*";
        }
        file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
        while(!file.eof())
        {
           if(t_id == id && t_pin == pin && t_pass == pass)
           {
                cout<<"\n\n\t\t\t Your Current Balance is :"<<balance;
                found ++;
           }
           file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
        }
        file.close();
        if(found ==0)
        {
            cout<<"\n\n\t\t\t Invalid UserID/Pin/Password";
        }
    }
}

// Defining function for withdraw function in ATM
void bank::atm_withdraw()
{
    system("cls");
    cout<<"\n\n\t\t\tWithdraw Amount";
    fstream file, file1; //new file for updates
    string t_id, t_pass, t_pin;
    float with;
    char ch;
    int found = 0;
    system("cls");
    cout<<"\n\n\t\t Withdraw";
    file.open("bank.txt",ios::in); //to access the files and read content
    if(!file)
    {
        cout<<"\n\nFile can't be accessed";
    }
    else
    {
        cout<<"\n\nUser Email ID:";
        cin>>t_id; //test_id for the user.
        cout<<"\n\t\tPassword:";
        for(int i=1; i<=5;i++)
        {
            ch = getch();
            t_pass = t_pass + ch;
            cout<<"*";
        }
        cout<<"\n\n\t\t PinCode:";
        for(int i=1; i<=5;i++)
        {
            ch = getch();
            t_pin = t_pin + ch;
            cout<<"*";
        }
        file1.open("bank1.txt",ios::app|ios::out);
        //to read the file - function used
        file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
        while(!file.eof())
        {
            if(t_id == id && t_pin == pin && t_pass == pass)
            {
                cout<<"\n\nAmount to be Withdrawed:";
                cin>>with;
                if(with <= balance)
                {
                balance = balance-with;//to add to existing balance
                file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<" \n";
                cout<<"\n\n\t\t\t Your amount is"<<with<<"  "<<"is sucessfully withdrawed.";
                cout<<"\n\n\t\t\t Your Current Balance is"<<balance;
                }
                else
                {
                    //to update the new file.
                    file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<" \n";
                    cout<<"\n\n\t\t\t Your Current Balance is less.\n\t\t\tBalance:"<<balance;
                }
            }
            else
            {
                file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<" \n";
            }
            file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
        }
        file.close();
        if(found == 0)
        cout<<"\n\nUser not found.";
    }
}

//Defining Function for Account Details under ATM
void bank::atm_acctdetails()
{
    system("cls");
    cout<<"\n\n\t\t\tAccount Details";
    fstream file,file1; //new file for updates
    string t_id, t_pass, t_pin;
    float with;
    char ch;
    int found = 0;
    file.open("bank.txt",ios::in); //to access the files and read content
    if(!file)
    {
        cout<<"\n\nFile can't be accessed";
    }
    else
    {
        cout<<"\n\nUser Email ID:";
        cin>>t_id; //test_id for the user.
        cout<<"\n\t\tPassword:";
        for(int i=1; i<=5;i++)
        {
            ch = getch();
            t_pass = t_pass + ch;
            cout<<"*";
        }
        cout<<"\n\n\t\t PinCode:";
        for(int i=1; i<=5;i++)
        {
            ch = getch();
            t_pin = t_pin + ch;
            cout<<"*";
        }
        //to fetch data from the files
        file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
        while(!file.eof())
        {
            if(t_id == id && t_pin == pin && t_pass == pass)
            {
                cout<<"\n\n\n UserID:"<<id;
                cout<<"\n\n\n Name:"<<name;
                cout<<"\n\n\n Father Name:"<<fname;
                cout<<"\n\n\n Address:"<<address;
                cout<<"\n\n\n Pin:"<<pin;
                cout<<"\n\n\n Password:"<<pass;
                cout<<"\n\n\n Phone No.:"<<phone;
                cout<<"\n\n\n Current Balance:"<<balance;
                cout<<"\n\n ---------------------------------------------------------------";
                file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
                found++;
            }
            file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
        }
    }
        file1.close();
        file.close();
        remove("bank.txt");
        //getting rid of old unwanted data
        rename("bank1.txt","bank.txt");
        if(found == 0)
        cout<<"\n\nUser not found.";
    }

}

//main function code
int main() {
    bank obj;   // Making object with name obj
    obj.menu(); // Calling the menu function and running it
    return 0;   // Add return 0 to signify successful execution
}
