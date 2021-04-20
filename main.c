#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <conio.h>
#define max 5
#define success true

struct consumer
{
    int account_no;
    int balance;
    char name[30];
};

char password[10];
void getPassword()
{
    for (int i = 0; i < 5; i++)
    {
        char ch = getch();
        password[i] = ch;
        ch = '*';
        printf ("%c", ch);
    }
    getch();
}

void showGroupDetails()
{
    printf ("\tBanking software made by group 10 of CO3iB\n");
    printf ("\tGroup details:\n");
    printf ("\t-------------------------\n");
    printf ("\t|S.No.|   Name   | R.No.|");
    printf ("\n\t-------------------------\n");
    printf ("\t|  1  |  Piyush  |  38  |\n");
    printf ("\t-------------------------\n");
    printf ("\t|  2  |   Vinit  |  39  |\n");
    printf ("\t-------------------------\n");
    printf ("\t|  3  |  Vedant  |  40  |\n");
    printf ("\t-------------------------\n");
    printf ("\t|  4  | Siddhant |  41  |\n");
    printf ("\t-------------------------\n");
    system ("pause");
    system ("cls");
}

char a[max][100];
int front=-1, rear=-1;
void acceptAllDetails (struct consumer [], int);
void displayAllDetails (struct consumer [], int);
void withdrawMoney (struct consumer [], int, int);
void depositMoney (struct consumer [], int, int);
int searchAccountDetails (struct consumer[], int, int);
_Bool isAccountExist(struct consumer[], int, int);
_Bool loginToAccount();
void insertInQueue(char data[80]);
void viewQueue();
void deleteFromQueue();


int main()
{
    struct consumer c[max];
    int n, ch, acc_no, data, amount;
    //showGroupDetails();
    printf("Welcome to G10 banking system");
    printf ("\nHow many records would you like to enter?\n");
    scanf ("%d", &n);
    acceptAllDetails (c, n);
    while (1)
    {
        printf ("\nMenu:\n1. Display all records (administrator only)\n2. Search your account details\n3. Deposit money into your account\n4. Withdraw money from your account\n5. View ATM's pending operations (administrator only)\n6. Exit\n");
        printf ("\nEnter your choice: ");
        scanf ("%d", &ch);
        switch (ch)
        {
        case 1:
            if (loginToAccount()==success)
            {
                displayAllDetails(c, n);
                insertInQueue("\nAll details were viewed.");
            }

            else
                printf ("\nLogin unsuccessful.\n");
            system ("cls");
            break;

        case 2:
            printf ("\nEnter your account number to be searched: ");
            scanf ("%d", &acc_no);
            data=searchAccountDetails (c, n, acc_no);
            if (data==-1)
                printf ("\nAccount %d does not exist.\n", acc_no);
            else
            {
                printf ("\nAccount number: %d\nName of holder: %s\nBalance in account: %d\n", c[data].account_no, c[data].name, c[data].balance);
                insertInQueue ("\nData was searched.");
            }
            system ("pause");
            system ("cls");
            break;

        case 3:
            printf ("\nEnter your account number: ");
            scanf ("%d", &acc_no);
            if (isAccountExist(c, n, acc_no)==true)
            {
                printf ("\nEnter the amount you want to deposit in the account: ");
                scanf ("%d", &amount);
                data=searchAccountDetails (c, n, acc_no);
                depositMoney (c, data, amount);
                printf ("\nAmount deposited.\n");
                insertInQueue("\nAmount was deposited");
                system ("pause");
            }
            else
            {
                printf ("\nInvalid account number, try again.");
                system ("pause");
            }
            system ("cls");
            break;

        case 4:
            printf ("\nEnter your account number: ");
            scanf ("%d", &acc_no);
            if (isAccountExist(c, n, acc_no)==true)
            {
                printf ("\nEnter the amount you want to withdraw from the account: ");
                scanf ("%d", &amount);
                data=searchAccountDetails (c, n, acc_no);
                withdrawMoney (c, data, amount);
                system ("pause");
            }
            else
            {
                printf ("\nInvalid account number, try again. ");
                system ("pause");
            }
            system ("cls");
            break;

        case 5:
            if (loginToAccount()==success)
            {
                viewQueue();
            }
            else
                printf ("\nLogin failed. Try again later if you want to.");
            system ("cls");
            break;

        case 6:
            exit (1);

        default:
            printf ("\nEnter proper choices!");

        }
    }
    return 0;
}

void acceptAllDetails(struct consumer data[20], int n)
{
    int i;
    for (i=0; i<n; i++)
    {
        printf ("\nEnter the details of account %d.\n", i+1);
        printf ("Enter the account number: ");
        scanf ("%d", &data[i].account_no);
        printf ("Enter your name: ");
        scanf ("%s", &data[i].name);
        data[i].balance=1000;
    }
    system ("pause");
    system ("cls");
}

void displayAllDetails(struct consumer list[20], int n)
{
    int i;
    for (i=0; i<n; i++)
    {
        printf ("\nAccount details %d:\nAccount number: %d\nName of account holder: %s\nBalance in account: %d\n", i+1, list[i].account_no, list[i].name, list[i].balance);
        printf ("----------------------------------");
        getch();
    }
}

int searchAccountDetails(struct consumer list[20], int n, int account)
{
    int i;
    for (i=0; i<n; i++)
    {
        if (list[i].account_no==account)
        {
            return i;
        }
    }
    return -1;
}

void depositMoney(struct consumer data[20], int n, int amount)
{
    data[n].balance+=amount;
}

void withdrawMoney(struct consumer data[20], int n, int amount)
{
    if (data[n].balance>=amount)
    {
        data[n].balance-=amount;
        printf ("\nAmount withdrawn. ");
        insertInQueue("\nAmount was withdrawn from account.");
    }

    else
        printf ("\nInsufficient balance, try later. ");
}

_Bool isAccountExist(struct consumer data[20], int n, int acc)
{
    int i;
    for (i=0; i<n; i++)
    {
        if (data[i].account_no==acc)
        {
            return true;
        }
    }
    return false;
}

void insertInQueue(char data[80])
{
    if(rear == max-1)
    {
        deleteFromQueue();
    }

    if (front==-1)
        front=rear=0;

    else
        rear++;

    strcpy(a[rear], data);
}

void deleteFromQueue()
{
    if (front<0 || front>rear)
    {
        return;
    }
    front++;
}

void viewQueue()
{
    int i;
    if (front==-1)
        printf ("\nNothing happened today\n");

    else
    {
        for (i=front; i<=rear; i++)
        {
            printf ("%s\n", a[i]);
        }
    }
    printf ("\n");
    system ("PAUSE");
}

_Bool loginToAccount()
{
    char username[10], ch;
    int i;
    printf ("\nEnter your user-name: ");
    scanf ("%s", username);
    printf ("Enter your password: ");
    getPassword();
    //scanf ("%s", password);
    if (strcmp(username, "admin")==0 && strcmp (password, "admin")==0)
        return success;

    else
        return false;

    system ("pause");
}
