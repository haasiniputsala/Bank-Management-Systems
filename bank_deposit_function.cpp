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

