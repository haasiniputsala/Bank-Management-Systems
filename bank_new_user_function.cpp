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
