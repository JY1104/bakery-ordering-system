#include <iostream>
#include <windows.h>
#include <string>
#include <cmath>
#include <iomanip>
#include <unistd.h>
#include <ctime>
#include <random>
#include <fstream>
#include <conio.h>

using namespace std;


void prehome();

class member
{
protected:
    string username;
};

class Bakery: public member
{
public:
    // Constructor
    Bakery();
    void intro();
    void generate_time();
    void welcome(string choice);
    void menu(string choice);
    void cake(string choice);
    void bread(string choice);
    void donut(string choice);
    void drink(string choice);
    void cart(string choice);
    void exit();
    void payment_method(string choice);
    void payment_end();
    void writeReceiptToFile(const string& fileName,Bakery& bakery,string choice);
    void readReceiptFromFile(const string& fileName);
    void decide(string choice);
    void ask(string choice);
    void cash(string choice);
    void digital_wallet();
    void credit_card();
    void receipt();

    void setusername(const string& name)
    {
        username = name;
    }

private:

    // Private member variables
    // Cakes
    float tiramisu_cake , banana_cake , coffee_cake , pandan_cake , strawberry_cake , orange_cake , original_cake ;
    int tiramisu_cake_amount, banana_cake_amount, coffee_cake_amount, pandan_cake_amount, strawberry_cake_amount, orange_cake_amount, original_cake_amount;

    // Donuts
    float chocolate_donut, banana_donut, pandan_donut, strawberry_donut, original_donut;
    int chocolate_donut_amount, banana_donut_amount, pandan_donut_amount, strawberry_donut_amount, original_donut_amount;

    // Breads
    float chocolate_bread, banana_bread, pandan_bread, strawberry_bread, original_bread;
    int chocolate_bread_amount, banana_bread_amount, pandan_bread_amount, strawberry_bread_amount, original_bread_amount;

    // Drinks
    float hot_milk, cold_milk, hot_lemon, cold_lemon, mushroom, hot_coffee, cold_coffee;
    int hot_milk_amount, cold_milk_amount, hot_lemon_amount, cold_lemon_amount, mushroom_amount, hot_coffee_amount, cold_coffee_amount;

    // Other
    string milk_temperature, coffee_temperature, lemon_temperature, cake_flavor;

    // Totals
    double total, cake_total, donut_total, bread_total, drink_total, total_quantity, net_total ;

    // Your code logic here

    time_t now;
    char* dt;
    int p;
    string donut_flavor, bread_flavor, drink_flavor, choose, i, answer, method, ways, choice, choice1;
    double customer, received, change, invoice_no;
    string fileName,receiptNo;

    char card_num[13] ;
    char password[7] ;

    // Other variables
    char d_num[25] ;
    char d_password[7];
    int code;
    int number;
    char ch;
};

Bakery::Bakery()
{
    // Constructor to initialize variables and set the time
    generate_time();

    // Other variable initializations
    tiramisu_cake = 0;
    banana_cake = 0;
    coffee_cake = 0;
    pandan_cake = 0;
    strawberry_cake = 0;
    orange_cake = 0;
    original_cake = 0;
    banana_cake_amount = 0;
    coffee_cake_amount = 0;
    pandan_cake_amount = 0;
    strawberry_cake_amount = 0;
    orange_cake_amount = 0;
    original_cake_amount = 0;
    chocolate_donut = 0;
    banana_donut = 0;
    pandan_donut = 0;
    strawberry_donut = 0;
    original_donut = 0;
    chocolate_donut_amount = 0;
    banana_donut_amount = 0;
    pandan_donut_amount = 0;
    strawberry_donut_amount = 0;
    original_donut_amount = 0;
    chocolate_bread = 0;
    banana_bread = 0;
    pandan_bread = 0;
    strawberry_bread = 0;
    original_bread = 0;
    chocolate_bread_amount = 0;
    banana_bread_amount = 0;
    pandan_bread_amount = 0;
    strawberry_bread_amount = 0;
    original_bread_amount = 0;
    hot_milk = 0;
    cold_milk = 0;
    hot_lemon = 0;
    cold_lemon = 0;
    mushroom = 0;
    hot_coffee = 0;
    cold_coffee = 0;
    hot_milk_amount = 0;
    cold_milk_amount = 0;
    hot_lemon_amount = 0;
    cold_lemon_amount = 0;
    mushroom_amount = 0;
    hot_coffee_amount = 0;
    cold_coffee_amount = 0;
    tiramisu_cake_amount = 0;
    customer = 0;
    received = 0;
    change = 0;
    invoice_no = 0;
    total = 0;
    cake_total = 0;
    donut_total = 0;
    bread_total = 0;
    drink_total = 0;
    total_quantity = 0;
    net_total = 0;
    number=0;
    choice = "0";
}

class User: public member
{
public:
    string getusername()const
    {
        return username;
    }

void save_user(const string& fileName)

{
    ofstream input(fileName, ios::app);
        if (input.is_open())
        {
            input << username << " " << password << endl;
        }
        input.close();
}

void add_user()
{
    cout << "\nPlease enter your username: ";
    cin >> username;
    cout << "Please enter your password [not more that 6 digit number only]: ";
    for (int i = 0; i < 6; i++)
	{
		password[i] = _getch();
		if (isdigit(password[i]))
		{
			cout << "*";
		}
		else
		{
			password[i] = '\0';
			i--;
		}
	}
	if (check_user_add(username)) {
        cout << "\nUsername already used, please use other username!\n";
        add_user();
    } else {
        cout << "\n\nUser added";
        sleep(1);
        system("CLS");
        save_user(fileName);

    }

}

bool check_user(const string& username, const char* password)
{
    string storedUsername;
    char storedPassword[7] = { '\0' };
    ifstream check(fileName, ios::app);
        while (check >> storedUsername >> storedPassword)
    {
        if (username == storedUsername && strcmp(password, storedPassword) == 0)
        {
            check.close();
            return true; // Match found
        }
    }
    check.close();
    return (username == storedUsername) && (strcmp(password,storedPassword)==0);
    //strcmp is used to compare the entered password (password) with the stored password (storedPassword) to determine whether the login credentials are correct.
}

bool check_user_add(const string& username)
{
    string storedUsername;
    ifstream check(fileName, ios::app);
        while (check >> storedUsername)
    {
        if (username == storedUsername)
        {
            check.close();
            return true; // Match found
        }
    }
    check.close();
    return (username == storedUsername);
    //strcmp is used to compare the entered password (password) with the stored password (storedPassword) to determine whether the login credentials are correct.
}

void login(string choice)
{
    Bakery bakery;
    cout << "\nEnter username: ";
    cin >> username;

    cout << "Enter password: ";
    for (int i = 0; i < 6; i++)
    {
        password[i] = _getch();
        if (isdigit(password[i]))
        {
            cout << "*";
        }
        else
        {
            password[i] = '\0';
            i--;
        }
    }
    cout << endl;

    if (check_user(username, password)) {
        cout << "\nLogin successful. Welcome, " << username << "!\n";
        bakery.setusername(getusername());
        sleep(1);
        bakery.welcome(choice);
    } else {
        cout << "\nInvalid username or password. Login failed.\n";
        sleep(1);
        system("CLS");
        bakery.intro();
    }
}

//Added part
void prehome(string choice)
{
    Bakery bakery;
    system("CLS");
    int PreChoice;
    int PreChoice1;
    cout << "Are you a member? (number 1 or 2 only)\n"
         << "1.Yes\n"
         << "2.No\n";
    cin  >> PreChoice;
        switch (PreChoice)
        {
             case 1:
                 choice = "1";
                    login(choice);
                 break;
             case 2:
                 cout << "\nDo you want to become our membership?\n"
                      << "1.Yes\n"
                      << "2.No\n";
                      cin>> PreChoice1;
                      if (PreChoice1==1)
                      {
                          choice = "1";
                          add_user();
                          break;
                      }
                      else if (PreChoice1==2)
                      {
                          string choice = "0";
                          username = "anonymous";
                          bakery.welcome(choice);
                          break;
                      }
                      else
                      {
                          cout << "❌Invalid Choice" << endl;
                          prehome(choice);
                          break;
                      }
             default:
                 cout << "❌Invalid Choice" << endl;
                 sleep(2);//make system stop 2 second
                 system("CLS");
                 prehome(choice);
                break;
         }
}

private:
    string username;
    char ch;
    char password[7] = { '\0' };
    const string fileName = "user.txt";
};

void Bakery::receipt()
{
    time_t current_time;
    tm * current_tm;
    time(&current_time);
    current_tm = localtime(&current_time);

    ostringstream oss;
    oss << put_time(current_tm, "%a %d%m%Y%H%M%S");
    receiptNo = oss.str();

    // Generate file name
    ostringstream fileOss;
    fileOss << username << "-" << put_time(current_tm, "%a %d%m%Y%H%M%S");
    fileName = fileOss.str()+".txt";
    return;
}
void Bakery::generate_time()
{
    now = time(0);
    dt = ctime(&now);
}

void Bakery::intro()//main intro screen
{
    User user;
    SetConsoleOutputCP(CP_UTF8);
    system("CLS");
        cout<<"\n\n\n======================================";
        cout<<"\n\n|\tSweet Delights Bakery.😆     |";
        cout<<"\n\n|\teat health, test well        |";
        cout<<"\n\n|\t     order system            |";
        cout<<"\n\n======================================";
        cout<<"\n\n\n\nMADE BY : TCP6114 - Group 4\n";
    system ("pause");
    cin.clear();
    user.prehome(choice);
}

void Bakery::welcome(string choice)
{//welcome
    system("CLS");
    cout << "Welcome to Bakery\n";
    this->menu(choice);
}

void Bakery::menu(string choice)
{
    ifstream inFile("menu.txt");

    if (inFile.is_open()) {
        string line;
        while (getline(inFile, line)) {
            cout << line << endl;
        }
        inFile.close();
    }

    choice1 = getch();//not using cin, direct enter num and continue
    if (choice1 == "1")
    {
        this->cake(choice);
    }
    else if(choice1 == "2")
    {
        this->donut(choice);
    }
    else if (choice1 == "3")
    {
        this->bread(choice);
    }
    else if (choice1 == "4")
    {
        this->drink(choice);
    }
    else if (choice1 == "5")
    {
        this->cart(choice);
    }
    else if (choice1 == "6")
    {
        this->exit();
    }
    else
    {
        cout << "❌Invalid Choice, go back to menu..." << endl;
            sleep(2);//make system stop 2 second
            system("CLS");
            this->welcome(choice);
            this->menu(choice);
    }
}

void Bakery::cake(string choice)
{//case 1
    system("CLS");
    cout << "What flavor you like? \n";;
    cout << "\n";
    cout << "------------------------------------------------------------------"<<endl;
    cout << "Flavor                                                    Price"<<endl;
    cout << "------------------------------------------------------------------"<<endl;
    cout << "1. Tiramisu🍫                                             RM9.00\n";
    cout << "2. Banana🍌                                               RM8.00\n";
    cout << "3. Coffee☕                                               RM8.50\n";
    cout << "4. Strawberry🍓                                           RM9.00\n";
    cout << "5. Orange🍊                                               RM7.80\n";
    cout << "6. Back🔙\n";
    cout << "------------------------------------------------------------------"<<endl;
    cout << "Enter your choice (number):\n ";

    cake_flavor=getch();
    cout << cake_flavor << endl;
    if (cake_flavor == "1")
    {
        cout << "Enter amount you want to buy [number only, maximum 999]:\n";
        cin >> tiramisu_cake_amount >>setprecision (0) >> fixed;//if user enter '12.04', it show 12
            if(tiramisu_cake_amount==1)
                {
                cout << "\nYour current Tiramisu cake is:"<<"\033[33m"<<tiramisu_cake_amount<<"\033[0m"<<"\n";
                }
            else if (tiramisu_cake_amount>=2)
                {
                cout << "\nYour current Tiramisu cake are:"<<"\033[33m"<<tiramisu_cake_amount<<"\033[0m"<< fixed<<"\n";
                }
            else
                {
                cout<<"\n";
                }
        tiramisu_cake = 9*tiramisu_cake_amount;
        if(tiramisu_cake_amount<1 || tiramisu_cake_amount >999)
            {//limit the enter range
            cout << "\033[33m🥺Value must between 1 to 999!\033[0m\n";//'\033[33m'is yellow colour code; '\033[0m' is return colour code
                sleep(1);
                cin.clear();
                cin.ignore(numeric_limits <streamsize> :: max(), '\n'); // Discard invalid input
                    tiramisu_cake_amount=0;
                    tiramisu_cake=0;
                    this->cake(choice);
            }
        else
        {
        cout << "\n\033[32m✅Successfully added to cart🛒!\033[0m\n";//input added; '\033[32m' is green colour code
        this->decide(choice);
        }
    }
    else if (cake_flavor == "2")
    {
        cout << "Enter amount you want to buy [number only, maximum 999]:\n";
        cin >> banana_cake_amount>>setprecision (0) >> fixed ;
        if(banana_cake_amount==1)
            {
            cout << "\nYour current banana cake is:"<<"\033[33m"<<banana_cake_amount<<"\033[0m" <<"\n";
            }
            else if (banana_cake_amount>=2)
                {
                cout << "\nYour current banana cake are:"<<"\033[33m"<<banana_cake_amount<<"\033[0m"<<"\n";
                }
            else
                {
                cout<<"\n";
                }

            banana_cake = 8*banana_cake_amount;

            if(banana_cake_amount<1||banana_cake_amount>999)
                {
                cout << "\033[33m🥺Value must between 1 to 999!\033[0m\n";
                    sleep(1);
                    cin.clear();
                    cin.ignore(numeric_limits <streamsize> :: max(), '\n');
                        banana_cake_amount=0;
                        banana_cake=0;
                        this->cake(choice);
                }
            else
                {
                cout << "\n\033[32m✅Successfully added to cart🛒!\033[0m\n";
                this->decide(choice);
                }
        }
    else if (cake_flavor == "3")
    {
        cout << "Enter amount you want to buy [number only, maximum 999]:\n";
        cin >> coffee_cake_amount>>setprecision (0) >> fixed ;
        if (coffee_cake_amount == 1)
            {
            cout << "\nYour current coffee cake is: \033[33m" << coffee_cake_amount << "\033[0m" << "\n";
            }
        else if (coffee_cake_amount >= 2)
            {
            cout << "\nYour current coffee cakes are: \033[33m" << coffee_cake_amount << "\033[0m" << "\n";
            }
        else
            {
            cout << "\n";
            }
        coffee_cake = 8.5*coffee_cake_amount;

        if(coffee_cake_amount<1 || coffee_cake_amount >999)
            {
            cout << "\033[33m🥺Value must between 1 to 999!\033[0m\n";
                sleep(1);
                cin.clear();
                cin.ignore(numeric_limits <streamsize> :: max(), '\n');
                coffee_cake_amount=0;
                coffee_cake=0;
                this->cake(choice);
                }
        else
            {
            cout << "\n\033[32m✅Successfully added to cart🛒!\033[0m\n";
            this->decide(choice);
            }
        }
    else if (cake_flavor == "4")
    {
        cout << "Enter amount you want to buy [number only,maximum 999]:\n";
        cin >> strawberry_cake_amount>>setprecision (0) >> fixed ;
        if (strawberry_cake_amount == 1)
            {
            cout << "\nYour current strawberry cake is: \033[33m" << strawberry_cake_amount << "\033[0m"  << "\n";
            }
        else if (strawberry_cake_amount >= 2)
            {
            cout << "\nYour current strawberry cakes are: \033[33m" << strawberry_cake_amount << "\033[0m" << "\n";
            }
        else
            {
            cout << "\n";
        }

                        strawberry_cake = 9*strawberry_cake_amount;

                            if(strawberry_cake_amount<1|| strawberry_cake_amount>999){
                                cout << "\033[33m🥺Value must between 1 to 999!\033[0m\n";
                                sleep(1);
                                cin.clear();
                                cin.ignore(numeric_limits <streamsize> :: max(), '\n');
                                    strawberry_cake_amount=0;
                                    strawberry_cake=0;
                                    this->cake(choice);
                            }else{
                                cout << "\n\033[32m✅Successfully added to cart🛒!\033[0m\n";
                                this->decide(choice);
                            }
                    }
                    else if (cake_flavor == "5"){
                        cout << "Enter amount you want to buy [number only, maximum 999]:\n";
                        cin >> orange_cake_amount>>setprecision (0) >> fixed ;
                            if (orange_cake_amount == 1) {
                                cout << "\nYour current orange cake is: \033[33m" << orange_cake_amount << "\033[0m" << "\n";
                            } else if (orange_cake_amount >= 2) {
                                cout << "\nYour current orange cakes are: \033[33m" << orange_cake_amount << "\033[0m"  << "\n";
                            } else {
                                cout << "\n";
                            }

                        orange_cake = 7.8*orange_cake_amount;


                            if(orange_cake_amount<1 || orange_cake_amount >999){
                                cout << "\033[33m🥺value must between 1 to 999!\033[0m\n";
                                sleep(1);
                                cin.clear();
                                cin.ignore(numeric_limits <streamsize> :: max(), '\n');
                                    orange_cake=0;
                                    orange_cake_amount=0;
                                    this->cake(choice);
                            }else{
                                cout << "\n\033[32m✅Successfully added to cart🛒!\033[0m\n";
                                this->decide(choice);
                            }
                    }
                    else if (cake_flavor == "6"){
                        system("CLS");
                        this->menu(choice);
                    }
                    else {//invalid input
                        cout <<"\033[31m"<< cake_flavor << " is not in the menu, please choose again❗\033[0m\n";// '\033[31m'is red color code
                        sleep(2);
                        this->cake(choice);
                    }
}
void Bakery::donut(string choice)
{// case 2

    system("CLS");
    cout << "What flavor you like? \n";
    cout << "\n";
    cout << "------------------------------------------------------------------"<<endl;
    cout << "Flavor                                                    Price"<<endl;
    cout << "------------------------------------------------------------------"<<endl;
    cout << "1. Chocolate🍫                                            RM2.50\n";
    cout << "2. Banana🍌                                               RM2.30\n";
    cout << "3. Pandan🌿                                               RM2.20\n";
    cout << "4. Strawberry🍓                                           RM2.40\n";
    cout << "5. Original😋                                             RM2.00\n";
    cout << "6. back🔙                                                        \n";
    cout << "------------------------------------------------------------------"<<endl;
    cout << "Enter your choice (number):\n";

    donut_flavor=getch();
    cout << donut_flavor <<endl;
        if (donut_flavor == "1")
        {
        cout << "Enter amount you want to buy [number only, maximum 999]:\n";
        cin >> chocolate_donut_amount>>setprecision (0) >> fixed ;
            if (chocolate_donut_amount == 1)
            {
            cout << "\nYour current chocolate donut is: \033[33m" << chocolate_donut_amount << "\033[0m"  << "\n";
            }
            else if (orange_cake_amount >= 2)
            {
            cout << "\nYour current chocolate donuts are: \033[33m" << chocolate_donut_amount << "\033[0m" << "\n";
            }
            else
            {
            cout << "\n";
            }
                chocolate_donut = 2.5* chocolate_donut_amount;
                    if(chocolate_donut_amount<1||chocolate_donut_amount>999)
                        {
                        cout << "\033[33m🥺Value must between 1 to 999\033[0m\n";
                        sleep(1);
                        cin.clear();
                        cin.ignore(numeric_limits <streamsize> :: max(), '\n');
                            chocolate_donut_amount=0;
                            chocolate_donut=0;
                        this->donut(choice);
                        }
                    else
                    {
                    cout << "\n\033[32m✅Successfully added to cart🛒!\033[0m\n";
                        this->decide(choice);
                    }
        }
        else if (donut_flavor == "2"){
                        cout << "Enter amount you want to buy [number only, maximum 999]:\n";
                        cin >> banana_donut_amount>>setprecision (0) >> fixed ;
                            if (banana_donut_amount == 1) {
                                cout << "\nYour current banana donut is: \033[33m" << banana_donut_amount << "\033[0m"  << "\n";
                            } else if (banana_donut_amount >= 2) {
                                cout << "\nYour current banana donuts are: \033[33m" << banana_donut_amount << "\033[0m"  << "\n";
                            } else {
                                cout << "\n";
                            }

                        banana_donut = 2.3* banana_donut_amount;

                            if(banana_donut_amount<1||banana_donut_amount>999){
                                cout << "\033[33m🥺Value must between 1 to 999!\033[0m\n";
                                sleep(1);
                                cin.clear();
                                cin.ignore(numeric_limits <streamsize> :: max(), '\n');
                                    banana_donut_amount=0;
                                    banana_donut=0;
                                    this->donut(choice);
                            }else{
                                cout << "\n\033[32m✅Successfully added to cart🛒!\033[0m\n";
                                this->decide(choice);
                            }
                    }
                    else if (donut_flavor == "3"){
                        cout << "Enter amount you want to buy [number only, maximum 999]:\n";
                        cin >> pandan_donut_amount>>setprecision (0) >> fixed ;
                            if (pandan_donut_amount == 1) {
                                cout << "\nYour current pandan donut is: \033[33m" << pandan_donut_amount << "\033[0m" << "\n";
                            } else if (pandan_donut_amount >= 2) {
                                cout << "\nYour current pandan donuts are: \033[33m" << pandan_donut_amount << "\033[0m" << "\n";
                            } else {
                                cout << "\n";
                            }


                        pandan_donut = 2.2* pandan_donut_amount;

                            if(pandan_donut_amount<1||pandan_donut_amount>999){
                                cout << "\033[33m🥺Value must between 1 to 999!\033[0m\n";
                                sleep(1);
                                cin.clear();
                                cin.ignore(numeric_limits <streamsize> :: max(), '\n');
                                    pandan_donut_amount=0;
                                    pandan_donut=0;
                                    this->donut(choice);
                            }else{
                                cout << "\n\033[32m✅Successfully added to cart🛒!\033[0m\n";
                                this->decide(choice);
                            }
                    }
                    else if (donut_flavor == "4"){
                        cout << "Enter amount you want to buy [number only, maximum 999]:\n";
                        cin >> strawberry_donut_amount>>setprecision (0) >> fixed ;
                            if (strawberry_donut_amount == 1) {
                                cout << "\nYour current strawberry donut is: \033[33m" << strawberry_donut_amount << "\033[0m"  << "\n";
                            } else if (strawberry_donut_amount >= 2) {
                                cout << "\nYour current strawberry donuts are: \033[33m" << strawberry_donut_amount << "\033[0m"  << "\n";
                            } else {
                                cout << "\n";
                            }


                        strawberry_donut = 2.4* strawberry_donut_amount;


                            if(strawberry_donut_amount<1||strawberry_donut_amount>999){
                                cout << "\033[33m🥺Value must between 1 to 999!\033[0m\n";
                                sleep(1);
                                cin.clear();
                                cin.ignore(numeric_limits <streamsize> :: max(), '\n');
                                    strawberry_donut_amount=0;
                                    strawberry_donut=0;
                                this->donut(choice);
                            }else{
                                cout << "\n\033[32m✅Successfully added to cart🛒!\033[0m\n";
                                this->decide(choice);
                            }
                    }
                    else if (donut_flavor == "5"){
                         cout << "Enter amount you want to buy [number only, maximum 999]:\n";
                         cin >> original_donut_amount>>setprecision (0) >> fixed ;
                            if (original_donut_amount == 1) {
                                cout << "\nYour current original donut is: \033[33m" << original_donut_amount << "\033[0m" << "\n";
                            } else if (original_donut_amount >= 2) {
                                cout << "\nYour current original donuts are: \033[33m" << original_donut_amount << "\033[0m"  << "\n";
                            } else {
                                cout << "\n";
                            }

                        original_donut = 2* original_donut_amount;


                            if(original_donut_amount<1||original_donut_amount>999){
                                cout << "\033[33m🥺Value must between 1 to 999!\033[0m\n";
                                sleep(1);
                                cin.clear();
                                cin.ignore(numeric_limits <streamsize> :: max(), '\n');
                                    original_donut_amount=0;
                                    original_donut=0;

                                this->donut(choice);
                            }else{
                            cout << "\n\033[32m✅Successfully added to cart🛒!\033[0m\n";
                            }
                            this->decide(choice);
                    }
                    else if (donut_flavor == "6"){
                        system("CLS");
                        this->menu(choice);
                    }
                    else {
                        cout <<"\033[31m"<< donut_flavor << " is not in the menu, please choose again❗\033[0m\n";
                        this->donut(choice);
                    }
}
void Bakery::bread(string choice)
{//case 3
                system("CLS");
                cout<< "What flavor you like? \n"
                    << "\n"
                    << "------------------------------------------------------------------\n"
                    << "Flavor                                                    Price\n"
                    << "------------------------------------------------------------------\n"
                    << "1. Chocolate🍫                                            RM4.00\n"
                    << "2. Banana🍌                                               RM4.00\n"
                    << "3. Pandan🌿                                               RM4.00\n"
                    << "4. Strawberry🍓                                           RM5.00\n"
                    << "5. Original😋                                             RM4.00\n"
                    << "6. Back🔙                                                       \n"
                    << "------------------------------------------------------------------\n"
                    << "Enter your choice (number):\n";

                bread_flavor=getch();
                cout << bread_flavor <<endl;
               if (bread_flavor == "1"){
                     cout << "Enter amount you want to buy [number only, maximum 999]:\n";
                     cin >> chocolate_bread_amount>>setprecision (0) >> fixed ;
                       if (chocolate_bread_amount == 1) {
                            cout << "\nYour current chocolate bread is: \033[33m" << chocolate_bread_amount << "\033[0m"  << "\n";
                        } else if (chocolate_bread_amount >= 2) {
                            cout << "\nYour current chocolate breads are: \033[33m" << chocolate_bread_amount << "\033[0m" << "\n";
                        } else {
                            cout << "\n";
                        }


                    chocolate_bread = 4* chocolate_bread_amount;


                        if(chocolate_bread_amount<1||chocolate_bread_amount>999){
                            cout << "\033[33m🥺Value must between 1 to 999!\033[0m\n";
                            sleep(1);
                            cin.clear();
                            cin.ignore(numeric_limits <streamsize> :: max(), '\n');
                                chocolate_bread_amount=0;
                                chocolate_bread=0;
                            this->bread(choice);
                        }else{
                            cout << "\n\033[32m✅Successfully added to cart🛒!\033[0m\n";
                           this->decide(choice);
                        }
                }
                if (bread_flavor == "2"){
                     cout << "Enter amount you want to buy [number only, maximum 999]:\n";
                     cin >> banana_bread_amount>>setprecision (0) >> fixed ;
                       if (banana_bread_amount == 1) {
                            cout << "\nYour current banana bread is: \033[33m" << banana_bread_amount << "\033[0m"  << "\n";
                        } else if (chocolate_bread_amount >= 2) {
                            cout << "\nYour current banana breads are: \033[33m" << banana_bread_amount << "\033[0m" << "\n";
                        } else {
                            cout << "\n";
                        }


                    banana_bread = 4* banana_bread_amount;


                        if(banana_bread_amount<1||banana_bread_amount>999){
                            cout << "\033[33m🥺Value must between 1 to 999!\033[0m\n";
                            sleep(1);
                            cin.clear();
                            cin.ignore(numeric_limits <streamsize> :: max(), '\n');
                                banana_bread_amount=0;
                                banana_bread=0;
                            this->bread(choice);
                        }else{
                            cout << "\n\033[32m✅Successfully added to cart🛒!\033[0m\n";
                           this->decide(choice);
                        }
                }
                else if (bread_flavor == "3"){
                    cout << "Enter amount you want to buy [number only, maximum 999]:\n";
                    cin >> pandan_bread_amount>>setprecision (0) >> fixed ;
                        if (pandan_bread_amount == 1) {
                            cout << "\nYour current pandan bread is: \033[33m" << pandan_bread_amount << "\033[0m"  << "\n";
                        } else if (pandan_bread_amount >= 2) {
                            cout << "\nYour current pandan breads are: \033[33m" << pandan_bread_amount << "\033[0m"  << "\n";
                        } else {
                            cout << "\n";
                        }

                    pandan_bread = 4* pandan_bread_amount;

                        if(pandan_bread_amount<1||pandan_bread_amount>999){
                            cout << "\033[33m🥺Value must between 1 to 999!\033[0m\n";
                            sleep(1);
                            cin.clear();
                            cin.ignore(numeric_limits <streamsize> :: max(), '\n');
                                pandan_bread_amount=0;
                                pandan_bread=0;
                            this->bread(choice);
                        }else{
                            cout << "\n\033[32m✅Successfully added to cart🛒!\033[0m\n";
                            this->decide(choice);
                        }
                }
                else if (bread_flavor == "4"){
                    cout << "Enter amount you want to buy [number only,maximum 999]:\n";
                    cin >> strawberry_bread_amount>>setprecision (0) >> fixed ;
                        if (strawberry_bread_amount == 1) {
                            cout << "\nYour current strawberry bread is: \033[33m" << strawberry_bread_amount << "\033[0m"  << "\n";
                        } else if (strawberry_bread_amount >= 2) {
                            cout << "\nYour current strawberry breads are: \033[33m" << strawberry_bread_amount << "\033[0m"  << "\n";
                        } else {
                            cout << "\n";
                        }

                    strawberry_bread = 5* strawberry_bread_amount;

                        if(strawberry_bread_amount<1||strawberry_bread_amount>999){
                            cout << "\033[33m🥺Value must between 1 to 999!\033[0m\n";
                            sleep(1);
                            cin.clear();
                            cin.ignore(numeric_limits <streamsize> :: max(), '\n');
                                strawberry_bread=0;
                                strawberry_bread_amount=0;
                            this->bread(choice);
                        }else{
                            cout << "\n\033[32m✅Successfully added to cart🛒!\033[0m\n";
                            this->decide(choice);
                        }
                }
                else if (bread_flavor == "5"){
                     cout << "Enter amount you want to buy [number only, maximum 999]:\n";
                     cin >> original_bread_amount>>setprecision (0) >> fixed ;
                            if (original_bread_amount == 1) {
                                cout << "\nYour current original bread is: \033[33m" << original_bread_amount << "\033[0m" << "\n";
                            } else if (original_bread_amount >= 2) {
                                cout << "\nYour current original breads are: \033[33m" << original_bread_amount << "\033[0m" << "\n";
                            } else {
                                cout << "\n";
                            }

                    original_bread = 4* original_bread_amount;

                        if(original_bread_amount<1||original_bread_amount>999){
                            cout << "\033[33m🥺Value must between 1 to 999!\033[0m\n";
                            sleep(1);
                            cin.clear();
                            cin.ignore(numeric_limits <streamsize> :: max(), '\n');
                                original_bread_amount=0;
                                original_bread=0;
                            this->bread(choice);
                        }else{
                            cout << "\n\033[32m✅Successfully added to cart🛒!\033[0m\n";
                            this->decide(choice);
                        }
                }
                else if (bread_flavor == "6"){
                    system("CLS");
                    this->menu(choice);
                }
                else {
                    cout <<"\033[31m"<< bread_flavor << " is not in the menu, please choose again❗\033[0m\n";
                   this->bread(choice);
                }
}

void Bakery::drink(string choice)
{// case 4
                system("CLS");
                cout << "What flavor you like? \n";
                cout << "\n";
                cout << "------------------------------------------------------------------"<<endl;
                cout << "Flavor                                                    Price"<<endl;
                cout << "------------------------------------------------------------------"<<endl;
                cout << "1. Milk🥛                                                 RM4.00\n";
                cout << "2. Coffee☕                                               RM5.00\n";
                cout << "3. Lemon tea🍋                                            RM3.00\n";
                cout << "4. Mushroom soup🍄                                        RM7.00\n";
                cout << "5. Back🔙                                                       \n";
                cout << "------------------------------------------------------------------"<<endl;
                cout << "Enter your choice (number):\n";


                drink_flavor=getch();
                cout << drink_flavor <<endl;
                    if (drink_flavor == "1"){
                        cout << "\nWould u like to have hot(h) or cold(c)?\n";
                        milk_temperature=getch();
                            if(milk_temperature == "H"||milk_temperature == "h"||milk_temperature =="Hot"||milk_temperature == "hot"||milk_temperature == "HOT"){
                                cout << "Hot milk\n";
                                 cout << "\nEnter amount you want to buy [number only, maximum 999]:\n";
                                cin >> hot_milk_amount>>setprecision (0) >> fixed ;
                                   if (hot_milk_amount == 1) {
                                        cout << "\nYour current hot milk is: \033[33m" << hot_milk_amount << "\033[0m" << fixed << "\n";
                                    } else if (hot_milk_amount >= 2) {
                                        cout << "\nYour current hot milks are: \033[33m" << hot_milk_amount << "\033[0m" << fixed << "\n";
                                    } else {
                                        cout << "\n";
                                    }

                                hot_milk = 4*hot_milk_amount;

                                if(hot_milk_amount<1||hot_milk_amount>999){
                                    cout << "\033[33m🥺Value must between 1 to 999!\033[0m\n";
                                    sleep(1);
                                    cin.clear();
                                    cin.ignore(numeric_limits <streamsize> :: max(), '\n');
                                        hot_milk=0;
                                        hot_milk_amount=0;
                                    this->drink(choice);
                                    }else{
                                        cout << "\n\033[32m✅Successfully added to cart🛒!\033[0m\n";
                                        this->decide(choice);
                                    }
                            }else if (milk_temperature == "C"||milk_temperature =="c"||milk_temperature == "Cold"||milk_temperature == "COLD"||milk_temperature == "cold"){
                                cout << "Cold milk\n";
                                 cout << "Enter amount you want to buy [number only, maximum 999]:\n";
                                 cin >> cold_milk_amount>>setprecision (0) >> fixed ;
                                    if (cold_milk_amount == 1) {
                                        cout << "\nYour current cold milk is: \033[33m" << cold_milk_amount << "\033[0m"  << "\n";
                                    } else if (cold_milk_amount >= 2) {
                                        cout << "\nYour current cold milks are: \033[33m" << cold_milk_amount << "\033[0m"  << "\n";
                                    } else {
                                        cout << "\n";
                                    }

                                cold_milk = 4*cold_milk_amount;

                                if(cold_milk_amount<1||cold_milk_amount>999){
                                    cout << "\033[33m🥺Value must between 1 to 999!\033[0m\n";
                                    sleep(1);
                                    cin.clear();
                                    cin.ignore(numeric_limits <streamsize> :: max(), '\n');
                                        cold_milk_amount=0;
                                        cold_milk=0;
                                    this->drink(choice);
                                }else{
                                    cout << "\n\033[32m✅Successfully added to cart🛒!\033[0m\n";
                                    this->decide(choice);
                                }
                        }else {
                            cout<< "Invalid input";
                            sleep(2);
                            this->drink(choice);
                        }
                }
                else if (drink_flavor == "2"){
                    cout << "\nWould u like to have hot(h) or cold(c)?\n";
                    coffee_temperature = getch();
                        if (coffee_temperature == "H" || coffee_temperature == "h" || coffee_temperature == "Hot" || coffee_temperature == "hot" || coffee_temperature == "HOT") {
                            cout << "Hot coffee\n";
                             cout << "Enter amount you want to buy [number only, maximum 999]:\n";
                             cin >> hot_coffee_amount >> setprecision(0) >> fixed;
                                if (hot_coffee_amount == 1) {
                                    cout << "\nYour current hot coffee is: \033[33m" << hot_coffee_amount << "\033[0m"  << "\n";
                                } else if (hot_coffee_amount >= 2) {
                                    cout << "\nYour current hot coffees are: \033[33m" << hot_coffee_amount << "\033[0m" << "\n";
                                } else {
                                    cout << "\n";
                                }

                                hot_coffee = 4 * hot_coffee_amount;

                                if (hot_coffee_amount < 1 || hot_coffee_amount > 999) {
                                    cout << "\033[33m🥺Value must be between 1 to 999!\033[0m\n";
                                    sleep(1);
                                    cin.clear();
                                    cin.ignore(numeric_limits <streamsize> :: max(), '\n');
                                        hot_coffee=0;
                                        hot_coffee_amount=0;
                                    this->drink(choice);
                                } else {
                                    cout << "\n\033[32m✅Successfully added to cart🛒!\033[0m\n";
                                    this->decide(choice);
                                }
                        }
                        else if (coffee_temperature == "C" || coffee_temperature == "c" || coffee_temperature == "Cold" || coffee_temperature == "COLD" || coffee_temperature == "cold") {
                            cout << "Cold coffee\n";
                            cout << "Enter amount you want to buy [number only, maximum 999]:\n";
                            cin >> cold_coffee_amount >> setprecision(0) >> fixed;
                                if (cold_coffee_amount == 1) {
                                    cout << "\nYour current cold coffee is: \033[33m" << cold_coffee_amount << "\033[0m" << "\n";
                                } else if (cold_coffee_amount >= 2) {
                                    cout << "\nYour current cold coffees are: \033[33m" << cold_coffee_amount << "\033[0m"  << "\n";
                                } else {
                                    cout << "\n";
                                }

                            cold_coffee = 4 * cold_coffee_amount;

                                if (cold_coffee_amount < 1 || cold_coffee_amount > 999) {
                                    cout << "\033[33m🥺Value must be between 1 to 999!\033[0m\n";
                                    sleep(1);
                                    cin.clear();
                                    cin.ignore(numeric_limits <streamsize> :: max(), '\n');
                                        cold_coffee_amount = 0;
                                        cold_coffee = 0;
                                    this->drink(choice);
                                    } else {
                                        cout << "\n\033[32m✅Successfully added to cart🛒!\033[0m\n";
                                       this->decide(choice);
                                    }
                        } else {
                            cout << "Invalid input";
                            sleep(2);
                            this->drink(choice);
                        }
                }
                else if (drink_flavor == "3"){
                    cout << "\nWould u like to have hot(h) or cold(c)?\n";
                    lemon_temperature = getch();
                        if (lemon_temperature == "H" || lemon_temperature == "h" || lemon_temperature == "Hot" || lemon_temperature == "hot" || lemon_temperature == "HOT") {
                            cout << "Hot lemon tea\n";
                             cout << "Enter amount you want to buy [number only, maximum 999]:\n";
                             cin >> hot_lemon_amount >> setprecision(0) >> fixed;
                                if (hot_lemon_amount == 1) {
                                    cout << "\nYour current hot lemon tea is: \033[33m" << hot_lemon_amount << "\033[0m"  << "\n";
                                } else if (hot_lemon_amount >= 2) {
                                    cout << "\nYour current hot lemon teas are: \033[33m" << hot_lemon_amount << "\033[0m"  << "\n";
                                } else {
                                    cout << "\n";
                                }
                            hot_lemon = 4 * hot_lemon_amount;

                                if (hot_lemon_amount < 1 || hot_lemon_amount > 999) {
                                    cout << "\033[33m🥺Value must be between 1 to 999!\033[0m\n";
                                    sleep(1);
                                    cin.clear();
                                    cin.ignore(numeric_limits <streamsize> :: max(), '\n');
                                        hot_lemon=0;
                                        hot_lemon_amount=0;
                                    this->drink(choice);
                                } else {
                                    cout << "\n\033[32m✅Successfully added to cart🛒!\033[0m\n";
                                    this->decide(choice);
                                }
                        } else if (lemon_temperature == "C" || lemon_temperature == "c" || lemon_temperature == "Cold" || lemon_temperature == "COLD" || lemon_temperature == "cold") {
                            cout << "Cold lemon tea\n";
                             cout << "Enter amount you want to buy [number only, maximum 999]:\n";
                             cin >> cold_lemon_amount >> setprecision(0) >> fixed;
                               if (cold_lemon_amount == 1) {
                                    cout << "\nYour current cold lemon tea is: \033[33m" << cold_lemon_amount << "\033[0m" << "\n";
                                } else if (cold_lemon_amount >= 2) {
                                    cout << "\nYour current cold lemon teas are: \033[33m" << cold_lemon_amount << "\033[0m" << "\n";
                                } else {
                                    cout << "\n";
                                }

                            cold_lemon = 4 * cold_lemon_amount;

                                if (cold_lemon_amount < 1 || cold_lemon_amount > 999) {
                                    cout << "\033[33m🥺Value must be between 1 to 999!\033[0m\n";
                                    sleep(1);
                                    cin.clear();
                                    cin.ignore(numeric_limits <streamsize> :: max(), '\n');
                                        cold_lemon_amount = 0;
                                        cold_lemon = 0;
                                    this->drink(choice);
                                } else {
                                    cout << "\n\033[32m✅Successfully added to cart🛒!\033[0m\n";
                                    this->decide(choice);
                                }
                        } else {
                            cout << "Invalid input";
                            sleep(2);
                            this->drink(choice);

                        }
                }
                else if (drink_flavor == "4"){
                    cout << "\nMushroom soup cannot be choose as cold\n";
                     cout << "Enter amount you want to buy [number only, maximum 999]:\n";
                     cin >> mushroom_amount>>setprecision (0) >> fixed ;
                       if (mushroom_amount == 1) {
                            cout << "\nYour current mushroom soup is: \033[33m" << mushroom_amount << "\033[0m"  << "\n";
                        } else if (mushroom_amount >= 2) {
                            cout << "\nYour current mushroom soups are: \033[33m" << mushroom_amount << "\033[0m"  << "\n";
                        } else {
                            cout << "\n";
                        }

                        mushroom = 7*mushroom_amount;

                        if(mushroom_amount<1||mushroom_amount>999){
                            cout << "\033[33m🥺Please enter true value!\033[0m\n";
                            sleep(1);
                            cin.clear();
                            cin.ignore(numeric_limits <streamsize> :: max(), '\n');
                                mushroom=0;
                                mushroom_amount=0;
                            this->drink(choice);
                        }else{
                        cout << "\n\033[32m✅Successfully added to cart🛒!\033[0m\n";
                        }
                        this->decide(choice);
                }
                else if (drink_flavor == "5"){
                    system("CLS");
                    this->menu(choice);
                }
                else {
                    cout <<"\033[31m"<< drink_flavor << " is not in the menu, please choose again❗\033[0m\n";
                    this->drink(choice);
                }
}

void Bakery::cart(string choice)
{//case 5

        cake_total = tiramisu_cake+coffee_cake+banana_cake+orange_cake+strawberry_cake;
        donut_total = chocolate_donut+pandan_donut+banana_donut+original_donut+strawberry_donut;
        bread_total = chocolate_bread+pandan_bread+banana_bread+original_bread+strawberry_bread;
        drink_total= hot_milk+cold_milk+hot_coffee+cold_coffee+hot_lemon+cold_lemon+mushroom;
        total = cake_total+donut_total+bread_total+drink_total;
    system("CLS");
    if (total>0){//not empty cart can access
    if (cake_total >0 ){
    cout << setw(58)<<"Price\n";
    cout << "Cakes:\n";
    }else {
        cout << "";
    }
    if(tiramisu_cake >0){
        cout << setw(3)<< right<<setprecision (0) << fixed<< tiramisu_cake_amount << "*Tiramisu🍫"<< setw(39) << right<<"RM" << setw(8)<<setprecision (2) << fixed<<right<< tiramisu_cake <<endl;
    }else {
        cout << "";
    }
    if(banana_cake >0){
        cout << setw(3)<<right<<setprecision (0) << fixed<< banana_cake_amount << "*Banana🍌" << setw(41) << right<<"RM" << setw(8)<<setprecision (2) << fixed<<right<< banana_cake <<endl;
    }else {
        cout << "";
    }
    if (coffee_cake > 0) {
        cout << setw(3)<<right<<setprecision (0) << fixed<<coffee_cake_amount << "*Coffee☕" << setw(41) << right<<"RM" << setw(8)<<setprecision (2) << fixed<<right<< coffee_cake << endl;
    } else {
        cout << "";
    }
    if (strawberry_cake > 0) {
        cout << setw(3)<<right<<setprecision (0) << fixed<<strawberry_cake_amount << "*Strawberry🍓" << setw(37) << right<<"RM" << setw(8)<<setprecision (2) << fixed<<right<< strawberry_cake << endl;
    } else {
        cout << "";
    }
    if (orange_cake > 0) {
        cout << setw(3)<<right<<setprecision (0) << fixed<< orange_cake_amount << "*Orange🍊" << setw(41) << right<<"RM" << setw(8)<<setprecision (2) << fixed<<right<< orange_cake << endl;
    } else {
        cout << "";
    }
    if (cake_total >0){
        cout << "-------------------------------------------------------------------\n";
        cake_total = tiramisu_cake+coffee_cake+banana_cake+orange_cake+strawberry_cake;
        cout << "Cake total :"<< setw(41) << right<<"RM" << setw(8)<<setprecision (2) << fixed<<right<< cake_total<<"\n";
        cout << "-------------------------------------------------------------------\n";
    }else{
        cout << "";
    }

//donut
    if (donut_total>0){
        cout << "Donuts:\n";
    if (chocolate_donut > 0) {
        cout << setw(3)<<right<<setprecision (0) << fixed<< chocolate_donut_amount << "*Chocolate🍫" << setw(38) << right<<"RM" << setw(8)<<setprecision (2) << fixed<<right<<chocolate_donut<<endl;
    }
    if (banana_donut > 0) {
        cout << setw(3)<<right<<setprecision (0) << fixed<< banana_donut_amount << "*Banana🍌" << setw(41) << right<<"RM" << setw(8)<<setprecision (2) << fixed<<right<<banana_donut << endl;
    }
    if (pandan_donut > 0) {
        cout  << setw(3)<<right<<setprecision (0) << fixed<< pandan_donut_amount << "*Pandan🌿"<< setw(41) << right<<"RM" << setw(8)<<setprecision (2) << fixed<<right<< pandan_donut << endl;
    }
    if (strawberry_donut > 0) {
        cout  << setw(3)<<right<<setprecision (0) << fixed<< strawberry_donut_amount << "*Strawberry🍓" << setw(37) << right<<"RM" << setw(8)<<setprecision (2) << fixed<<right<< strawberry_donut << endl;
    }
    if (original_donut > 0) {
        cout << setw(3)<<right<<setprecision (0) << fixed<< original_donut_amount << setw(12) << left << "*Original😋"<< setw(39) << right<<"RM" << setw(8)<<setprecision (2) << fixed<<right<< original_donut << endl;
    }
        cout << "-------------------------------------------------------------------\n";
        donut_total = chocolate_donut+pandan_donut+banana_donut+original_donut+strawberry_donut;
        cout << "Donut total :"<< setw(40) << right<<"RM" << setw(8)<<setprecision (2) << fixed<<right<<donut_total<<"\n";
        cout << "-------------------------------------------------------------------\n";
    }else {
        cout << "";
    }

//bread
    if (bread_total>0){
        cout << "Breads:\n";
    if (chocolate_bread > 0) {
        cout  << setw(3)<<right<<setprecision (0) << fixed<< chocolate_bread_amount << "*Chocolate🍫" << setw(38) << right<<"RM" << setw(8)<<setprecision (2) << fixed<<right<< chocolate_bread << endl;
    }
    if (banana_bread > 0) {
        cout << setw(3)<<right<<setprecision (0) << fixed<< banana_bread_amount << "*Banana🍌" << setw(41) << right<<"RM" << setw(8)<<setprecision (2) << fixed<<right<< banana_bread << endl;
    }
    if (pandan_bread > 0) {
        cout << setw(3)<<right<<setprecision (0) << fixed<< pandan_bread_amount << "*Pandan🌿" << setw(41) << right<<"RM" << setw(8)<<setprecision (2) << fixed<<right<< pandan_bread << endl;
    }
    if (strawberry_bread > 0) {
        cout << setw(3)<<right<<setprecision (0) << fixed<< strawberry_bread_amount << "*Strawberry🍓" << setw(37) << right<<"RM" << setw(8)<<setprecision (2) << fixed<<right<< strawberry_bread << endl;
    }
    if (original_bread > 0) {
        cout << setw(3)<<right<<setprecision (0) << fixed<< original_bread_amount << "*Original😋" << setw(39) << right<<"RM" << setw(8)<<setprecision (2) << fixed<<right<< original_bread << endl;
    }
        cout << "-------------------------------------------------------------------\n";
        bread_total = chocolate_bread+pandan_bread+banana_bread+original_bread+strawberry_bread;
        cout << "Bread total :"<< setw(40) << right<<"RM" << setw(8)<<setprecision (2) << fixed<<right<< bread_total<<"\n";
        cout << "-------------------------------------------------------------------\n";
    }else{
        cout << "";
    }

//drink
    if(drink_total>0){
        cout << "Drinks:\n";
    }else{
        cout << "";
    }
    if (hot_milk_amount > 0) {
        cout << setw(3)<<right<<setprecision (0) << fixed<< hot_milk_amount << "*Milk🥛" << setw(43) << right<<"RM" << setw(8)<<setprecision (2) << fixed<<right<< hot_milk << endl;
        cout << "   H♨️\n";
    }else{
        cout << "";
    }
    if (cold_milk_amount>0){
        cout << setw(3)<<right<<setprecision (0) << fixed<< cold_milk_amount << "*Milk🥛" << setw(43) << right<<"RM" << setw(8)<<setprecision (2) << fixed<<right<< cold_milk << endl;
        cout << "   C🧊\n";
    }else{
        cout << "";
    }
    if (hot_coffee_amount > 0) {
        cout << setw(3) << right << setprecision(0) << fixed << hot_coffee_amount << "*Coffee☕️" << setw(40) << right<<"RM" << setw(8)<<setprecision (2) << fixed<<right<< hot_coffee << endl;
        cout << "   H♨️\n";
    } else {
        cout << "";
    }
    if (cold_coffee_amount > 0) {
        cout << setw(3) << right << setprecision(0) << fixed << cold_coffee_amount << "*Coffee☕️" << setw(40) << right<<"RM" << setw(8)<<setprecision (2) << fixed<<right<< cold_coffee << endl;
        cout << "   C🧊\n";
    } else {
        cout << "";
    }
    if (hot_lemon_amount > 0) {
            cout << setw(3) << right << setprecision(0) << fixed << hot_lemon_amount << "*Lemon🍋" << setw(42) << right<<"RM" << setw(8)<<setprecision (2) << fixed<<right<< hot_lemon << endl;
            cout << "   H♨️\n";
    } else {
        cout << "";
    }
    if (cold_lemon_amount > 0) {
        cout << setw(3) << right << setprecision(0) << fixed << cold_lemon_amount << "*Lemon🍋" << setw(42) << right<<"RM" << setw(8)<<setprecision (2) << fixed<<right<< cold_lemon << endl;
        cout << "   C🧊\n";
    } else {
        cout << "";
    }
    if (mushroom_amount > 0) {
    cout << setw(3)<<right<<setprecision (0) << fixed<< mushroom_amount  << "*Mushroom Soup🍄"<< setw(34) << right<<"RM" << setw(8)<<setprecision (2) << fixed<<right<< mushroom << endl;
    } else {
    cout << "";
    }
    if(drink_total>0){
        cout << "-------------------------------------------------------------------\n";
        drink_total= hot_milk+cold_milk+hot_coffee+cold_coffee+hot_lemon+cold_lemon+mushroom;
        cout << "Drink total :"<< setw(40) << right<<"RM" << setw(8)<<setprecision (2) << fixed<<right<< drink_total<<"\n";
        cout << "-------------------------------------------------------------------\n";
    }else {
        cout << "";
    }

    cout << "-------------------------------------------------------------------\n";
    total = cake_total+donut_total+bread_total+drink_total;

    cout << "Total sales :"<< setw(40) << right<<"RM" << setw(8)<<setprecision (2) << fixed<<right<<total<< "\n";
    cout << "-------------------------------------------------------------------\n";
    if (choice =="1")
    {
        cout<< "Member discount 5%\n";
        cout << "Discount Amount :"<< setw(34)<< "-" << right<<"RM" << setw(8)<<setprecision (2) << fixed<<right<<total*0.05<< "\n";
        cout << "Member Price :"<< setw(39) << right<<"RM" << setw(8)<<setprecision (2) << fixed<<right<<total*0.95<< "\n";
        cout << "-------------------------------------------------------------------\n";
    }
        this->ask(choice);
    }else{
        cout << "Your cart is empty, let us go add some\n";
        sleep(2);
        system ("CLS");
        this->menu(choice);
    }
}
void Bakery::exit()
{// case 6
    system("CLS");
    cake_total = tiramisu_cake+coffee_cake+banana_cake+orange_cake+strawberry_cake;
    donut_total = chocolate_donut+pandan_donut+banana_donut+original_donut+strawberry_donut;
    bread_total = chocolate_bread+pandan_bread+banana_bread+original_bread+strawberry_bread;
    drink_total= hot_milk+cold_milk+hot_coffee+cold_coffee+hot_lemon+cold_lemon+mushroom;
    total = cake_total+donut_total+bread_total+drink_total;
    if(total==0){
        cout <<"Goodbye, ";
        this->payment_end();

    }else{
        cout<<"Your cart have added foods, do you want to delete them?\n";
        cout<<"Y = Yes, delete them\n";
        cout<<"N = No, back to menu\n";
        i=getch();
        if (i=="Y"||i == "y"){
            system("CLS");
            this->payment_end();

        }else if(i == "N"||i == "n"){
            system("CLS");
            this->menu(choice);
        }else {
            cout<<"\033[31m❌Invalid Choice\033[0m\n";
            sleep(1);
            system("cls");
            this->exit();
        }
    }
}

void Bakery::payment_method(string choice)
{
    system("CLS");
    cout << "Choose payment method:\n";
    cout << "---------------------------------" << endl;
    cout << "1. CASH💰" << endl;
    cout << "2. DIGITAL WALLET🧧" << endl;
    cout << "3. CREDIT CARD💳" << endl;
    cout << "4. Back🔙"<<endl;
    cout << "---------------------------------" << endl;
    cout << "Enter number: \n";
    cout << "\n";
        i = getch();
            if (i == "1"){
                    ways = "CASH";
                    this->cash(choice);
               }
               else if(i == "2"){
                   ways = "DIGITAL WALLET";
                   this->digital_wallet();
               }
               else if (i == "3"){
                   ways = "CREDIT CARD";
                   this->credit_card();
               }else if (i == "4"){
                    cout << "\033[31m⚠️Operation cancel⚠️\033[0m\n";
                    sleep(1);
                    system("CLS");
                    this-> cart(choice);
               }
               else {
                    cout << "\033[31m❌Invalid Choice, payment cancelled\033[0m" << endl;
                    cin.clear();
                    cin.ignore(numeric_limits <streamsize> :: max(), '\n');
                    sleep(1);
                    system("cls");
                    this-> cart(choice);
               }
}
void Bakery::cash(string choice)
{
    Bakery bakery;


    net_total=total;
    if (choice =="1")
    {
        net_total=net_total*0.95;
    }

    cout<<"Total is RM "<<net_total<<"\n";
    cout<<"Input amount: RM ";
    cin >>received;
    cout<<"\n";
        if (received>=net_total){
            change=received-net_total;
            cout<<"Change: RM "<<change<<"\n";
            cout<<"\033[32m✅Payment successfully\033[0m";
            sleep(1);
            writeReceiptToFile(fileName,bakery,choice);
        }else if(received<net_total){
             change=received-net_total;
             cout<<"\033[31m❌ERROR, payment not complete!\033[0m\n";
                cin.clear();
                cin.ignore(numeric_limits <streamsize> :: max(), '\n');
                ways = "";
                received = 0;
                sleep(1);
             this->payment_method(choice);
        }
}
void Bakery::digital_wallet()
{
    Bakery bakery;
    cout<<"Please enter your number:\n";
    for (int i = 0; i < 29; i++)
		{
			d_num[i] = _getch();
			if (isdigit(d_num[i]))
			{
				cout << d_num[i];
				if (i == 3 || i == 8 || i == 13 || i==18 || i==23)
				{
					i++;
					cout << " ";
					d_num[i] = ' ';
				}
			}
			else
			{
				d_num[i] = '\0';
				i--;
			}
		}
    cout<<"\nPlease enter your password:";
	for (int i = 0; i < 6; i++)
	{
		d_password[i] = _getch();
		if (isdigit(d_password[i]))
		{
			cout << "*";
			d_password[i] = '*';
		}
		else
		{
			d_password[i] = '\0';
			i--;
		}
	}
            system("cls");
            cout<<"Wait a moment.\n";
            system("CLS");
            cout<<"Wait a moment..\n";
            system("CLS");
            cout<<"Wait a moment...\n";
            cout<<"\033[32m✅Payment successfully\033[0m";
            this->writeReceiptToFile(fileName,bakery,choice);
}

void Bakery::credit_card()
{
    Bakery bakery;
    cout<<"Please enter your card number:\n";
    for (int i = 0; i < 19; i++)
		{
			card_num[i] = _getch();
			if (isdigit(card_num[i]))
			{
				cout << card_num[i];
				if (i == 3 || i == 8 || i == 13)
				{
					i++;
					cout << "-";
					card_num[i] = '-';
				}
			}
			else
			{
				card_num[i] = '\0';
				i--;
			}
		}
    cout<<"\nPlease enter your password:";
	for (int i = 0; i < 6; i++)
	{
		password[i] = _getch();
		if (isdigit(password[i]))
		{
			cout << "*";
			password[i] = '*';
		}
		else
		{
			password[i] = '\0';
			i--;
		}
	}
            system("cls");
            cout<<"Wait a moment.\n";
            system("CLS");
            cout<<"Wait a moment..\n";
            system("CLS");
            cout<<"Wait a moment...\n";
            cout<<"\033[32m✅Payment successfully\033[0m";
            sleep(1);
            this->writeReceiptToFile(fileName,bakery,choice);
}
void Bakery::writeReceiptToFile(const string& fileName,Bakery& bakery, string choice)
{
this->receipt();
ofstream outFile(fileName);
if (outFile.is_open()) {
    User user;
    bakery.setusername(user.getusername());

   // number ++;// for order number+1 if the program not shut down
    customer++;
    invoice_no++;
    cout << "\n\nPrinting receipt...";
    sleep(2);// use some time to make animation
    system("CLS");// receipt
    outFile << "                   Sweet Delights Bakery\n";
    outFile << "               75450 Bukit Beruang, Malacca\n";
    outFile << "                   TEL: 012-3456789\n\n";
    outFile << "                       << PAID >>\n\n";
    outFile << "                        INVOICE\n\n";
    outFile << "CUSTOMER    : "<<username<<"\n";
    outFile << "INVOICE NO  : " <<receiptNo<< endl;
    outFile << "\n" << dt;
    outFile << "                                                            (RM)";
    outFile << "\n===================================================================\n";

// Cakes
    if(tiramisu_cake >0){
        outFile<<setw(20)<<left<<"TIRAMISU CAKE🍫"<<"@9.00\n";
        outFile<<setw(18)<<left<<"34521"<<"*"<<setw(3)<<right<<setprecision(0)<<fixed<<tiramisu_cake_amount<<setw(45)<<right<<setprecision(2)<<fixed<<tiramisu_cake<<"\n"<<endl;
    }else {
        outFile << "";
    }
    if(banana_cake >0){
        outFile<<setw(20)<<left<<"BANANA CAKE🍌"<<"@8.00\n";
        outFile<<setw(18)<<left<<"23412"<<"*"<<setw(3)<<right<<setprecision(0)<<banana_cake_amount<<setw(45)<<right<<setprecision(2)<<fixed<<banana_cake<<"\n"<<endl;
    }else {
        outFile << "";
    }
    if (coffee_cake > 0) {
        outFile<<setw(19)<<left<<"COFFEE CAKE☕"<<"@8.50\n";
        outFile<<setw(18)<<left<<"78022"<<"*"<<setw(3)<<right<<setprecision(0)<<coffee_cake_amount<<setw(45)<<right<<setprecision(2)<<fixed<<coffee_cake<<"\n"<<endl;
    } else {
        outFile << "";
    }
    if (strawberry_cake > 0) {
        outFile<<setw(20)<<left<<"STRAWBERRY CAKE🍓"<<"@9.00\n";
        outFile<<setw(18)<<left<<"43562"<<"*"<<setw(3)<<right<<setprecision(0)<<strawberry_cake_amount<<setw(45)<<right<<setprecision(2)<<fixed<<strawberry_cake<<"\n"<<endl;
    } else {
        outFile << "";
    }
    if (orange_cake > 0) {
        outFile<<setw(20)<<left<<"ORANGE CAKE🍊"<<"@7.80\n";
        outFile<<setw(18)<<left<<"78652"<<"*"<<setw(3)<<right<<setprecision(0)<<orange_cake_amount<<setw(45)<<right<<setprecision(2)<<fixed<<orange_cake<<"\n"<<endl;
    } else {
        outFile << "";
    }

//donut
    if (chocolate_donut > 0) {
        outFile<<setw(20)<<left<<"CHOCOLATE DONUT🍫"<<"@2.50\n";
        outFile<<setw(18)<<left<<"76885"<<"*"<<setw(3)<<right<<setprecision(0)<<chocolate_donut_amount<<setw(45)<<right<<setprecision(2)<<fixed<<chocolate_donut<<"\n"<<endl;
    } else {
        outFile << "";
    }
    if (banana_donut > 0) {
        outFile<<setw(20)<<left<<"BANANA DONUT🍌"<<"@2.30\n";
        outFile<<setw(18)<<left<<"75468"<<"*"<<setw(3)<<right<<setprecision(0)<<banana_donut_amount<<setw(45)<<right<<setprecision(2)<<fixed<<banana_donut<<"\n"<<endl;
    } else {
        outFile << "";
    }
    if (pandan_donut > 0) {
        outFile<<setw(20)<<left<<"PANDAN DONUT🌿"<<"@2.20\n";
        outFile<<setw(18)<<left<<"54677"<<"*"<<setw(3)<<right<<setprecision(0)<<pandan_donut_amount<<setw(45)<<right<<setprecision(2)<<fixed<<pandan_donut<<"\n"<<endl;
    } else {
        outFile << "";
    }
    if (strawberry_donut > 0) {
        outFile<<setw(20)<<left<<"STRAWBERRY DONUT🍓"<<"@2.40\n";
        outFile<<setw(18)<<left<<"73884"<<"*"<<setw(3)<<right<<setprecision(0)<<strawberry_donut_amount<<setw(45)<<right<<setprecision(2)<<fixed<<strawberry_donut<<"\n"<<endl;
    } else {
        outFile << "";
    }
    if (original_donut > 0) {
        outFile<<setw(20)<<left<<"ORIGINAL DONUT🍩"<<"@2.00\n";
        outFile<<setw(18)<<left<<"73990"<<"*"<<setw(3)<<right<<setprecision(0)<<original_donut_amount<<setw(45)<<right<<setprecision(2)<<fixed<<original_donut<<"\n"<<endl;
    } else {
        outFile << "";
    }
//bread
    if (chocolate_bread > 0) {
        outFile<<setw(20)<<left<<"CHOCOLATE BREAD🍫"<<"@4.00\n";
        outFile<<setw(18)<<left<<"98872"<<"*"<<setw(3)<<right<<setprecision(0)<<chocolate_bread_amount<<setw(45)<<right<<setprecision(2)<<fixed<<chocolate_bread<<"\n"<<endl;
    } else {
        outFile << "";
    }
    if (banana_bread > 0) {
        outFile<<setw(20)<<left<<"BANANA BREAD🍌"<<"@4.00\n";
        outFile<<setw(18)<<left<<"97757"<<"*"<<setw(3)<<right<<setprecision(0)<<banana_bread_amount<<setw(45)<<right<<setprecision(2)<<fixed<<banana_bread<<"\n"<<endl;
    } else {
        outFile << "";
    }
    if (pandan_bread > 0) {
        outFile<<setw(20)<<left<<"PANDAN BREAD🌿"<<"@4.00\n";
        outFile<<setw(18)<<left<<"98898"<<"*"<<setw(3)<<right<<setprecision(0)<<pandan_bread_amount<<setw(45)<<right<<setprecision(2)<<fixed<<pandan_bread<<"\n"<<endl;
    } else {
        outFile << "";
    }
    if (strawberry_bread > 0) {
        outFile<<setw(20)<<left<<"STRAWBERRY BREAD🍓"<<"@5.00\n";
        outFile<<setw(18)<<left<<"97655"<<"*"<<setw(3)<<right<<setprecision(0)<<strawberry_bread_amount<<setw(45)<<right<<setprecision(2)<<fixed<<strawberry_bread<<"\n"<<endl;
    } else {
        outFile << "";
    }
    if (original_bread > 0) {
        outFile<<setw(20)<<left<<"ORIGINAL BREAD🍞"<<"@4.00\n";
        outFile<<setw(18)<<left<<"98089"<<"*"<<setw(3)<<right<<setprecision(0)<<original_bread_amount<<setw(45)<<right<<setprecision(2)<<fixed<<original_bread<<"\n"<<endl;
    } else {
        outFile << "";
    }
//drink
    if (hot_milk_amount > 0) {
        outFile<<setw(20)<<left<<"MILK🥛 (H)"<<"@4.00\n";
        outFile<<setw(18)<<left<<"91456"<<"*"<<setw(3)<<right<<setprecision(0)<<hot_milk_amount<<setw(45)<<right<<setprecision(2)<<fixed<<hot_milk<<"\n"<<endl;
    }else{
        outFile << "";
    }
    if (cold_milk_amount>0){
        outFile<<setw(20)<<left<<"MILK🥛 (C)"<<"@4.00\n";
        outFile<<setw(18)<<left<<"99624"<<"*"<<setw(3)<<right<<setprecision(0)<<cold_milk_amount<<setw(45)<<right<<setprecision(2)<<fixed<<cold_milk<<"\n"<<endl;
    }else{
        outFile << "";
    }
    if (hot_coffee_amount > 0) {
        outFile<<setw(21)<<left<<"COFFEE☕️ (H)"<<"@5.00\n";
        outFile<<setw(18)<<left<<"87732"<<"*"<<setw(3)<<right<<setprecision(0)<<hot_coffee_amount<<setw(45)<<right<<setprecision(2)<<fixed<<hot_coffee<<"\n"<<endl;
    } else {
        outFile << "";
    }
    if (cold_coffee_amount > 0) {
        outFile<<setw(21)<<left<<"COFFEE☕️ (C)"<<"@5.00\n";
        outFile<<setw(18)<<left<<"87733"<<"*"<<setw(3)<<right<<setprecision(0)<<cold_coffee_amount<<setw(45)<<right<<setprecision(2)<<fixed<<cold_coffee<<"\n"<<endl;
    } else {
        outFile << "";
    }
    if (hot_lemon_amount > 0) {
        outFile<<setw(20)<<left<<"LEMON TEA🍋 (H)"<<"@3.00\n";
        outFile<<setw(18)<<left<<"14233"<<"*"<<setw(3)<<right<<setprecision(0)<<hot_lemon_amount<<setw(45)<<right<<setprecision(2)<<fixed<<hot_lemon<<"\n"<<endl;
    } else {
        outFile << "";
    }
    if (cold_lemon_amount > 0) {
        outFile<<setw(20)<<left<<"LEMON TEA🍋 (C)"<<"@3.00\n";
        outFile<<setw(18)<<left<<"14234"<<"*"<<setw(3)<<right<<setprecision(0)<<cold_lemon_amount<<setw(45)<<right<<setprecision(2)<<fixed<<cold_lemon<<"\n"<<endl;
    } else {
        outFile << "";
    }
    if (mushroom_amount > 0) {
        outFile<<setw(20)<<left<<"MUSHROOM SOUP🍄 "<<"@7.00\n";
        outFile<<setw(18)<<left<<"82771"<<"*"<<setw(3)<<right<<setprecision(0)<<mushroom_amount<<setw(45)<<right<<setprecision(2)<<fixed<<mushroom<<"\n"<<endl;
    } else {
    outFile << "";
    }

    outFile << "-------------------------------------------------------------------\n";
    total_quantity=tiramisu_cake_amount+banana_cake_amount+orange_cake_amount+strawberry_cake_amount+coffee_cake_amount+chocolate_donut_amount+banana_donut_amount+pandan_donut_amount+strawberry_donut_amount+original_donut_amount+chocolate_bread_amount+banana_bread_amount+pandan_bread_amount+original_bread_amount+strawberry_bread_amount+hot_milk_amount+hot_lemon_amount+hot_coffee_amount+mushroom_amount+cold_milk_amount+cold_coffee_amount+cold_lemon_amount;
    outFile << "QUANTITY: "<<setprecision(0)<<fixed<<total_quantity<<" Units\n";
    outFile << "-------------------------------------------------------------------\n";

    total = cake_total+donut_total+bread_total+drink_total;

    outFile << setw(20)<<left<<"Total Sales"<<setw(40)<<right<<setprecision(2)<<fixed<<"RM "<<right<<total << "\n";

    net_total=total;
    if (choice =="1")
    {
        net_total=net_total*0.95;
    }
    outFile << setw(20)<<left<<"Net Total"<<setw(40)<<right<<setprecision(2)<<fixed<<"RM "<<right<<net_total<<"\n";
    outFile << "------------------------------------------------------------------\n";
    outFile << setw(20)<<left<<"Payment Method"<<setw(47)<<right<<ways<<"\n";
        if(ways == "CASH"){
            outFile << setw(20)<<left<<"Received Cash"<<setw(40)<<right<<setprecision(2)<<fixed<<"RM "<<right<<received<<"\n";
            outFile<<setw(20)<<left<<"Change"<<setw(40)<<right<<setprecision(2)<<fixed<<"RM "<<right<<change<<"\n";
        }else if(ways == "DIGITAL WALLET"){
            outFile << setw(20)<<left<<"Received"<<setw(40)<<right<<setprecision(2)<<fixed<<"RM "<<right<<received<<"\n";
            outFile << setw(20)<<left<<"DIGITAL WALLET ID"<<setw(48)<<right<<setprecision(2)<<right<<d_num<<"\n";
            outFile<<setw(20)<<left<<"Change"<<setw(40)<<right<<setprecision(2)<<fixed<<"RM "<<right<<change<<"\n";
        }else if(ways == "CREDIT CARD"){
            outFile << setw(20)<<left<<"Received"<<setw(40)<<right<<setprecision(2)<<fixed<<"RM "<<right<<received<<"\n";
            outFile << setw(20)<<left<<"Credit card number"<<setw(47)<<right<<setprecision(2)<<right<<card_num<<"\n";
            outFile<<setw(20)<<left<<"Change"<<setw(40)<<right<<setprecision(2)<<fixed<<"RM "<<right<<change<<"\n";
        }
    outFile << "-------------------------------------------------------------------\n";
    outFile << "PLEASE VERIFY YOUR RECEIPT\n";
    outFile << "ISSUE WILL NOT BE ATTENDED AFTER SOLD!\n";
    outFile << "THANK YOU AND PLEASE COME AGAIN\n";
    outFile.close();
        cout << "Receipt written to " << fileName << " successfully." << endl;
    } else {
        cout << "Unable to open the file " << fileName << " for writing." << endl;
    }
    sleep (2);
    this->readReceiptFromFile(fileName);
    this->payment_end();
}

void Bakery::readReceiptFromFile(const string& fileName)
{
    ifstream inFile(fileName);

    if (inFile.is_open()) {
        string line;
        while (getline(inFile, line)) {
            cout << line << endl;
        }

        // Close the file when done
        inFile.close();
    } else {
        cerr << "Unable to open the file " << fileName << " for reading." << endl;
    }
}

void Bakery::payment_end()
{//reset all the value = 0
    cout << "Press 'c' to continue... \n";
    i=getch();
    if (i == "c" ||i == "C")
    {
        system("CLS");
        total = 0, cake_total = 0, donut_total = 0, bread_total = 0, drink_total = 0, tiramisu_cake_amount = 0, tiramisu_cake = 0, chocolate_donut_amount = 0, chocolate_donut = 0, chocolate_bread_amount = 0, chocolate_bread = 0,total_quantity=0,received=0,change=0;
        banana_cake_amount = 0, banana_cake = 0, banana_donut_amount = 0, banana_donut = 0, banana_bread_amount = 0, banana_bread = 0, coffee_cake_amount = 0, coffee_cake = 0, pandan_donut_amount = 0, pandan_donut = 0, pandan_bread_amount = 0, pandan_bread = 0,net_total=0;
        strawberry_cake_amount = 0, strawberry_cake = 0, strawberry_donut_amount = 0, strawberry_donut = 0, strawberry_bread_amount = 0, strawberry_bread = 0, orange_cake_amount = 0, orange_cake = 0, original_donut_amount = 0, original_donut = 0, original_bread_amount = 0, original_bread = 0;
        hot_milk_amount = 0, cold_milk_amount=0, hot_lemon_amount = 0,cold_lemon_amount=0, mushroom_amount = 0, hot_coffee_amount = 0,cold_coffee_amount=0, hot_milk = 0,cold_milk=0, hot_lemon = 0,cold_lemon=0, mushroom = 0, hot_coffee = 0,cold_coffee=0;
        code=0, change=0;
        cout << "Restoring 100%... please don't press any key\n";
        cout << "[■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■] 100%";
        sleep(1);
        system("CLS");
        intro();
        cin.get();
        this->welcome(choice);
    }
    else {
        cout << "\033[31m❌Invalid input\033[0m\n";
        cin.clear();
        cin.ignore(numeric_limits <streamsize> :: max(), '\n');
        this->payment_end();
    }
}

void Bakery::decide(string choice)
{
    Bakery bakery;
    cout << "Press 'c' key to continue add food, or 'x' go to cart ";
        i=getch();
        if (i == "c"||i == "C"){
            system("CLS");
            cout << "What would you like to add?\n";
            this->menu(choice);
        }else if (i == "X"||i=="x"){
            system("CLS");
            this->cart(choice);
        }else{
            cout << "\n\033[31m❌Invalid input\033[0m\n";
            cin.clear();
            cin.ignore(numeric_limits <streamsize> :: max(), '\n');
            this->decide(choice);
        }
}
void Bakery::ask(string choice)
{
    cout << "\nDo you want to make a payment?\n";
    cout << "[Y = YES]\t";
    cout << "[N = NO]\n";
    answer=getch();
        if (answer == "Y" || answer == "y"){
            this->payment_method(choice);
        }else if (answer == "N"|| answer == "n"){
            system("CLS");
            cout << "What would you like to add?\n";
            this->menu(choice);
        }
        else {
            cout << "\n\033[31m❌Invalid input\033[0m\n";
            cin.clear();
            cin.ignore(numeric_limits <streamsize> :: max(), '\n');
            this->ask(choice);
        }
}

int main()
{
    Bakery bakery;
    User user;
    string choice;
    SetConsoleOutputCP(CP_UTF8);//use to put emoji

        bakery.intro();
        user.prehome(choice);
}
//made by TCP 2A_CP2_G4
