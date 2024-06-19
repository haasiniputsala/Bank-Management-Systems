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
