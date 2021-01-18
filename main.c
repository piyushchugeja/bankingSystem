#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define N 20

struct consumer
{
    int account_no;
    int balance;
    char name[30];
};

/*char a[20][30];
int front=-1, rear=-1;*/
void acceptAllDetails (struct consumer [], int);
void displayAllDetails (struct consumer [], int);
void withdrawMoney (struct consumer [], int, int);
void depositMoney (struct consumer [], int, int);
int searchAccountDetails (struct consumer[], int, int);
_Bool isAccountExist(struct consumer[], int, int);
//void viewQueue(int);


int main()
{
    struct consumer c[N];
    int n, ch, acc_no, data, amount;
    printf("Welcome to G10 banking system");
    printf ("\nHow many records would you like to enter?\n");
    scanf ("%d", &n);
    acceptAllDetails (c, n);
    while (1)
    {
        printf ("\nMenu:\n1. Display all records\n2. Search your account details\n3. Deposit money into your account\n4. Withdraw money from your account\n5. View ATM's pending operations (administrator only)\n6. Exit\n");
        printf ("\nEnter your choice: ");
        scanf ("%d", &ch);
        switch (ch)
        {
        case 1:
            displayAllDetails(c, n);
            system ("cls");
            break;

        case 2:
            printf ("\nEnter your account number to be searched: ");
            scanf ("%d", &acc_no);
            data=searchAccountDetails (c, n, acc_no);
            if (data==-1)
                printf ("\nAccount %d does not exist.\n", acc_no);
            else
            printf ("\nAccount number: %d\nName of holder: %s\nBalance in account: %d\n", c[data].account_no, c[data].name, c[data].balance);
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
                //strcpy(a[++front][30], "Deposited in an account");
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
                //strcpy(a[++front][15], "Withdrawn from an account");
                system ("pause");
            }
            else
            {
                printf ("\nInvalid account number, try again. ");
                system ("pause");
            }
            system ("cls");

        case 5:
            //viewQueue(n);
            system ("cls");
            break;

        case 6:
            exit (1);

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
        printf ("\nEnter your name: ");
        scanf ("%s", data[i].name);
        data[i].balance=0;
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
        system ("PAUSE");
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

/*void viewQueue(int n)
{
    int i;
    if (front==-1)
        printf ("\nQueue empty\n");

    else
    {
        for (i=0; i<=n; i++)
        {
            printf ("%s\n", a[1][i]);
        }
    }
}
*/