#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <conio.h>
using namespace std;
void addcashier(string newcashier[100], string cashierlogin[100], int &currentcashier);
void title();
void adminMenu(int &enteringKeyforProducts);
void profitLoss(long double &totalPurchasedAmountFromCostomer, long double &totalPurchasedAmountFromWholesale);

void wholeSalePurchase(string arr[], int priceOfProducts[], int &currentProducts);
void salePurchaseProfitLossMenu();
void gotoxy(int x, int y);
void addproductsbyadmin(string arr[], int priceOfProducts[], int proSize, int &currentProducts);
void displayProducts(int priceOfProducts[], string arr[], int currentProducts);
void adminCashierValidation(string passwordCashier, bool &pass2);
void namePassCompare(string cashierlogin[], int currentcashier, string passwordCashier, bool &namecomp, bool &passcomp);
void removeProducts(string arr[], int &currentProducts, string removedObjectName);
void addcashier(int &countpc, int &currentCustomer, bool &true1);
void totalsalepurchase(double totalCostofitemsPurchased[], int currentCustomer);
void displaygoto(int countpc, string nameofproducts[][100], string nameofCustomer[], double totalCostofitemsPurchased[], int proSize, int currentCustomer);
double customerPurchase(string nameofproducts[][100], string nameofCustomer[], double totalCostofitemsPurchased[], int proSize, int currentCustomer, string &proName, int countpc, double totalPurchasedAmountFromCostomer);
int main()
{
    string newcashier[100], cashierlogin[100], nameofproducts[100][100], proName;
    int currentcashier = 0, again = 1, currentCustomer = 0, countpc = 0;
    bool pass2 = false, passcomp, namecomp, true1;
    int enteringKey;
    int countProducts = 0, proSize = 100, currentProducts = 0, priceOfProducts[100];
    string arr[100];
    string nameofCustomer[100];
    double noOfPurchaseditems[100], totalCostofitemsPurchased[100];
    double totalPurchasedAmountFromCostomer = 0;

    while (again == 1)
    {

        title();

        cout << "Press 1 to Enter as a ADMIN: " << endl;
        cout << "Press 2 to Enter as a CASHIER: " << endl;
        cin >> enteringKey;
        system("cls");
        // choose admin r cashier
        if (enteringKey == 1)
        {
            int passwordAdmin;
            string adminName;

            cout << "Please Enter the Admin Name :" << endl;
            cin >> adminName;
            cout << "Please Enter Password :" << endl;

            cin >> passwordAdmin;

            system("cls");
            // entrance of admin
            if (passwordAdmin == 1234 && adminName == "KALEEM")
            {
                cout << "YOU SUCCESSFULLY ENTERED AS AN ADMIN  :" << endl;
                int enteringKeyforProducts;
                // ADMIN FUNCTIONALITIES STARTS FROM HERE:

                while (enteringKeyforProducts < 6)
                {
                    adminMenu(enteringKeyforProducts);
                    // admin key 1
                    if (enteringKeyforProducts == 1)
                    {
                        addproductsbyadmin(arr, priceOfProducts, proSize, currentProducts);
                    }
                    else if (enteringKeyforProducts == 2)
                    // admin key 2
                    {
                        string removedObjectName;
                        cout << "Enter a Product which is to be removed :" << endl;
                        cin >> removedObjectName;
                        // FOR REMOVING PRODUCTS
                        removeProducts(arr, currentProducts, removedObjectName);
                        cout << "List after Removing objects :" << endl;
                        currentProducts = 0;
                        for (int i = 0; i < 100; i++)
                        {
                            if (arr[i] != "" && arr[i] != "2")
                            {
                                cout << arr[i] << endl;

                                currentProducts++;
                            }
                        }
                        cout << "No. of products after removing :" << currentProducts << endl;
                        // admin key 3
                        // countProducts = 10 - countProducts; 3
                    }
                    else if (enteringKeyforProducts == 3)
                    {
                        displayProducts(priceOfProducts, arr, currentProducts);
                    }
                    // admin key 4
                    else if (enteringKeyforProducts == 4)
                    {
                        int cashierkey = 1;
                        pass2 = false;
                        string cashierpass, namecashier;

                        while (cashierkey == 1)
                        {

                            while (!pass2)
                            {
                                cout << "PLEASE ENTER CASHIER NAME " << endl;
                                cin >> namecashier;

                                adminCashierValidation(namecashier, pass2);
                            }
                            newcashier[currentcashier] = namecashier;
                            cout << "PLEASE ENTER CASHIER PASSWORD " << endl;
                            cin >> cashierlogin[currentcashier];

                            currentcashier++;
                            cout << "IF YOU WANT TO ADD MORE CASHIERS : PRESS 1 " << endl;
                            cout << "OR PRESS ANY KEY EXCEPT 1 TO GO BACK " << endl;
                            cin >> cashierkey;
                        }
                    }
                    // totalCostofitemsPurchased[currentCustomer] //////////////
                    else if (enteringKeyforProducts == 5)
                    {
                        totalsalepurchase(totalCostofitemsPurchased, currentCustomer);
                    }

                    else
                    {
                        cout << "Please Enter a Right key :" << endl;
                    }
                }
            }
            // for wrong admin password

            else
            {
                cout << "YOU ENTERED WRONG ADMIN NAME OR PASSWORD :" << endl;
                cout << "PLEASE TRY AGAIN :" << endl;
            }
        }
        // for cashier start entring key 2
        else if (enteringKey == 2)
        {
            int tryagain = 1;
            passcomp = false;
            string passwordCashier, cashname;
            bool namecomp = false;
            while (tryagain == 1)
            {

                cout << "You want to Enter as an CASHIER : " << endl;
                system("cls");

                while (!namecomp)
                {
                    cout << "PLEASE ENTER THE CASHIER NAME :" << endl;
                    cin >> cashname;

                    adminCashierValidation(passwordCashier, pass2);
                    if (pass2)
                    {

                        namePassCompare(newcashier, currentcashier, cashname, namecomp, passcomp);
                    }
                }
                passcomp = false;
                while (!passcomp)
                {

                    cout << "Please Enter Password :" << endl;
                    cin >> passwordCashier;

                    namePassCompare(cashierlogin, currentcashier, passwordCashier, namecomp, passcomp);
                }

                if (passcomp)
                {

                    long double totalPurchasedAmountFromCostomer, totalPurchasedAmountFromWholesale;
                    int key1 = 1;

                    while (key1 < 5 && key1 >= 1)

                    {
                        salePurchaseProfitLossMenu();
                        cin >> key1;
                        if (key1 == 1)
                        {
                            true1 = true;
                            cout << "Enter the name of customer :" << endl;
                            cin >> nameofCustomer[currentCustomer];
                            while (true1)
                            {
                                customerPurchase(nameofproducts, nameofCustomer, totalCostofitemsPurchased, proSize, currentCustomer, proName, countpc, totalPurchasedAmountFromCostomer);

                                removeProducts(arr, currentProducts, proName);
                                addcashier(countpc, currentCustomer, true1);
                            }
                            displaygoto(countpc, nameofproducts, nameofCustomer, totalCostofitemsPurchased, proSize, currentCustomer);
                        }

                        else if (key1 == 2)
                        {
                            wholeSalePurchase(arr, priceOfProducts, currentProducts);
                        }

                        else if (key1 == 3)
                        {
                            profitLoss(totalPurchasedAmountFromCostomer, totalPurchasedAmountFromWholesale);
                        }

                        else if (key1 == 4)
                        {
                            key1 = 5;
                            tryagain = 2;
                        }
                    }
                }
            }
        }
        // if wrong key for  cashier
        else
        {
            cout << "Please Enter a Right key :" << endl;
        }
    }
}

void addcashier(int &countpc, int &currentCustomer, bool &true1)
{
    int key;

    cout << "Press 1 to continue :" << endl;

    cout << "Press any other key from 0 to 9 ,except 1 to Exit :" << endl;
    cin >> key;
    if (key == 1)
    {

        countpc++;
    }
    else if (key != 1)
    {
        true1 = false;
        currentCustomer++;
    }

    system("cls");
}
void title()
{
    cout << " ____________________________________________________" << endl;
    cout << "| ***************************************************|" << endl;
    cout << "| *                                                 *|" << endl;
    cout << "| *          SHOP MANAGMENT SYSTEM                  *|" << endl;
    cout << "| *                                                 *|" << endl;
    cout << "| ***************************************************|" << endl;
    cout << "|____________________________________________________|" << endl;
    cout << endl;
}
void adminMenu(int &enteringKeyforProducts)
{
    // admin menu
    cout << "Enter key 1 to Add Products :" << endl;
    cout << "Enter key 2 to Remove Products :" << endl;
    cout << "Enter key 3 to count Total Products :" << endl;
    cout << "Enter key 4 to Add cashier :" << endl;
    cout << "Enter key 5 to see total sale purchase of the day :" << endl;
    cout << "Enter key 6 to Exit " << endl;
    cin >> enteringKeyforProducts;
    system("cls");
}

void profitLoss(long double &totalPurchasedAmountFromCostomer, long double &totalPurchasedAmountFromWholesale)
{
    if (totalPurchasedAmountFromWholesale > totalPurchasedAmountFromCostomer)
    {
        cout << "THE PROFIT IS :" << endl;
        cout << totalPurchasedAmountFromWholesale - totalPurchasedAmountFromCostomer;
    }
    else if (totalPurchasedAmountFromWholesale < totalPurchasedAmountFromCostomer)
    {
        cout << "THE LOSS IS :" << endl;
        cout << totalPurchasedAmountFromCostomer - totalPurchasedAmountFromWholesale;
    }
    else
    {
        cout << "THERE IS NO ANY PROFIT OR LOSS :" << endl;
    }
}
double customerPurchase(string nameofproducts[][100], string nameofCustomer[], double totalCostofitemsPurchased[], int proSize, int currentCustomer, string &proName, int countpc, double totalPurchasedAmountFromCostomer)
{
    // 1 : record of contomer details
    // yhan cashier customer sy intract kar saky ga

    int key = 1;

    cout << "Enter the name of product you want to purchase :" << endl;
    cin >> proName;

    nameofproducts[currentCustomer][countpc] = proName;
    cout << "Enter total cost of items that a customer purchased :" << endl;
    cin >> totalPurchasedAmountFromCostomer;

    totalCostofitemsPurchased[currentCustomer] = totalPurchasedAmountFromCostomer + totalCostofitemsPurchased[currentCustomer];
}
void displaygoto(int countpc, string nameofproducts[][100], string nameofCustomer[], double totalCostofitemsPurchased[], int proSize, int currentCustomer)
{
    // record of customers
    int x = 3, y = 1;
    gotoxy(x, y);
    cout << "NAME OF CUSTOMER";
    x = x + 25;

    gotoxy(x, y);
    cout << "NAME OF PRODUCTS";

    x = x + 25;
    gotoxy(x, y);
    cout << "THEIR TOTAL COST ";
    x = x - 50;
    y = y + 1;
    for (int i = 0; i < currentCustomer; i++)
    {
        for (int j = 0; j <= countpc; j++)
        {
            gotoxy(x, y);
            cout << nameofCustomer[i];
            x = x + 25;
            gotoxy(x, y);
            cout << nameofproducts[i][j];
            x = x + 25;
            gotoxy(x, y);
            cout << totalCostofitemsPurchased[i];
            x = x - 50;
            y = y + 1;
        }
    }
    cout << endl;
    getch();
}
void wholeSalePurchase(string arr[], int priceOfProducts[], int &currentProducts)
{
    // whole sale purchasing

    double noOfPurchaseditemsFromWholesale[100];

    long double totalPurchasedAmountFromWholesale = 0;
    int key2 = 1;

    while (key2 == 1)
    {

        cout << "Enter the name of product you want to purchase from wholesale :" << endl;
        cin >> arr[currentProducts];

        cout << "Enter how much you purchased items form wholesale :" << endl;
        cin >> noOfPurchaseditemsFromWholesale[currentProducts];

        cout << "Enter total cost of items that you purchased from whole sale :" << endl;
        cin >> priceOfProducts[currentProducts];

        totalPurchasedAmountFromWholesale = totalPurchasedAmountFromWholesale + priceOfProducts[currentProducts];
        currentProducts++;

        cout << "Press 1 to continue :" << endl;
        cout << "Press any other key from 0 to 9 ,except 1 to Exit :" << endl;
        cin >> key2;
        system("cls");
        if (key2 != 1)
        {
            int x = 3, y = 1;

            gotoxy(x, y);
            cout << "NAME OF PRODUCTS";
            x = x + 25;
            gotoxy(x, y);
            cout << "ITEMS PURCHASED ";
            x = x + 25;
            gotoxy(x, y);
            cout << "THEIR TOTAL COST ";
            x = x - 50;
            y = y + 1;
            for (int i = 0; i < currentProducts; i++)
            {
                if (arr[i] != "")
                {

                    gotoxy(x, y);
                    cout << arr[i];
                    x = x + 25;
                    gotoxy(x, y);
                    cout << noOfPurchaseditemsFromWholesale[i];
                    x = x + 25;
                    gotoxy(x, y);
                    cout << priceOfProducts[i];
                    x = x - 50;
                    y = y + 1;
                }
            }
            cout << endl;
            cout << "TOTAL PURCHASE AMOUNT IS :" << totalPurchasedAmountFromWholesale << endl;
            key2 = 2;
            getch();
        }
        system("cls");
    }
}
void addproductsbyadmin(string arr[], int priceOfProducts[], int proSize, int &currentProducts)
{
    arr[currentProducts] = "0";

    while (arr[currentProducts] != "2")
    {

        cout << "Enter products Names :" << endl;
        cout << "Or press 2 to go back " << endl;

        cin >> arr[currentProducts];

        if (arr[currentProducts] != "2")
        {
            cout << "Enter the price of the " << arr[currentProducts] << endl;
            cin >> priceOfProducts[currentProducts];

            currentProducts++;
        }
    }
}
void salePurchaseProfitLossMenu()
{

    cout << "Enter key 1 to sale products to customer :" << endl;
    cout << "Enter key 2 to buy products from wholesale :" << endl;
    cout << "Enter key 3 to check profit and loss" << endl;
    cout << "Enter key 4 to Exit " << endl;
}
void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void displayProducts(int priceOfProducts[], string arr[], int currentProducts)
{
    for (int i = 0; i < currentProducts; i++)
    {
        cout << " products name are :" << arr[i] << endl;
        cout << "products prices are :" << priceOfProducts[i] << endl;
    }

    cout << "Total Products are :" << currentProducts << endl;
}
void adminCashierValidation(string passwordCashier, bool &pass2)
{

    int pass1;

    pass1 = passwordCashier.length();
    for (int i = 0; i < pass1; i++)
    {
        if (((passwordCashier[i] >= 'A' && passwordCashier[i] <= 'Z') || (passwordCashier[i] >= 'a' && passwordCashier[i] <= 'z')))
        {
            pass2 = true;
        }
        if (!((passwordCashier[i] >= 'A' && passwordCashier[i] <= 'Z') || (passwordCashier[i] >= 'a' && passwordCashier[i] <= 'z')))
        {
            pass2 = false;
            break;
        }
    }
    if (pass2)
    {
        cout << "YOU ENTERED A RIGHT CODE " << endl;
    }
    else if (!pass2)
    {
        cout << "YOU ENTER A WRONG CODE" << endl;
    }
}
void namePassCompare(string cashierlogin[], int currentcashier, string passwordCashier, bool &namecomp, bool &passcomp)
{
    for (int i = 0; i <= currentcashier; i++)
    {
        if (passwordCashier == cashierlogin[i])
        {
            cout << "You Entered as as an CAHIER :" << endl;
            passcomp = true;
            namecomp = true;
        }
    }
}
void removeProducts(string arr[], int &currentProducts, string removedObjectName)
{
    for (int i = 0; i < currentProducts; i++)
    {
        if (arr[i] == removedObjectName)
        {
            for (int j = i; j < currentProducts - 1; j++)
            {
                arr[j] = arr[j + 1];
            }
            arr[currentProducts - 1] = "";
        }
    }
}
void totalsalepurchase(double totalCostofitemsPurchased[], int currentCustomer)
{
    int totalamountoftheday = 0;
    for (int i = 0; i < currentCustomer; i++)
    {
        totalamountoftheday = totalamountoftheday + totalCostofitemsPurchased[i];
    }
    cout << "TOTAL SALE OF THE DAY = " << totalamountoftheday << endl;
    getch();
}