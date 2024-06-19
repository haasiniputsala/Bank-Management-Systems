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
