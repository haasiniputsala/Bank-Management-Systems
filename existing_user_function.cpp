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

