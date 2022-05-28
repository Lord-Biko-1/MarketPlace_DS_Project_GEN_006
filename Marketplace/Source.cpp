#include <iostream>
#include <Windows.h> 
#include <string>
#include <vector>
#include <ctime>
#include "auth.h"
#include "login.cpp"
#include "Globals.h";
#include "Customer.h"
#include <iomanip>
#pragma warning(disable : 4996) // <------- to disable the unsafe error for ctime method 
using namespace std;
static vector<Customer> customers;

int main() {
	time_t t = time(NULL);
	system("color B5");
	Globals glob = Globals();
	seller loggedSeller = seller("s","s@.","1");
	Customer loggedCustomer = Customer("c", "c@.", "1", "c", "2");
	int enterChois;
	do {
		
		std::cout.width(120); std::cout << std::right << ctime(&t);
		std::cout.width(72); std::cout << std::right <<"(______ON THE MARKET_____)" << '\n';
		cout << "Enter 1 for Register\nEnter 2 for Login" << endl;
		cin >> enterChois;
		if (enterChois == 1) {
			cout << "Do you want to register as Customer or Seller\nEnter 1 for Customer\nEnter 2 for Seller\nEnter 3 for back" << endl;
			cin >> enterChois;

			if (enterChois == 1) {
				loggedCustomer = customerRegister(customers);
				
				loggedCustomer.Order_Screen();
				
			}
			else if (enterChois == 2) {
				loggedSeller = sellerRegister(glob.sellers);
				loggedSeller.sellerScreen();
			}

			else if (enterChois == 3) {
				main();
			}
			else {
				cout << "Invalid choise" << endl;
			}
		}
		else if (enterChois == 2) {
			cout << "Do you want to login as Customer or Seller\nEnter 1 for Customer\nEnter 2 for Seller\nEnter 3 for back" << endl;
			cin >> enterChois;

			if (enterChois == 1) {
				cout << "Customer Login" << endl;

				
				 loggedCustomer = userLogin<Customer>(customers);
				 if (loggedCustomer.getIsLogged() == true) {
				 	cout << "**********Login Success**********" << endl;
					loggedCustomer.Order_Screen();
					
				 }
				 else {
				 	cout << "\n**********Login Failed**********" << endl;

				 }
			}
			else {
				cout << "Seller Login" << endl;

				loggedSeller = userLogin<seller>(glob.sellers);

				if (loggedSeller.getIsLogged() == true) {
					cout << "**********Login Success**********" << endl;
					loggedSeller.sellerScreen();
				}
				else {
					cout << "**********Login Failed**********" << endl;

				}
			}

			
		}
		else {
			break;
		}
		
	} while (true);

	
	return 0;
}

