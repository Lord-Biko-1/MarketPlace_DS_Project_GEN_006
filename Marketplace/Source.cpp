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
#pragma warning(disable : 4996)
using namespace std;
static vector<Customer> customers;

int main() {
	time_t t = time(NULL);
	cout << ctime(&t);
	system("color 0A");
	Globals glob = Globals();
	seller loggedSeller = seller("s","s@.","1");
	Customer loggedCustomer = Customer("c", "c@.", "1", "c", "2");
	
	int enterChois;
	do {
		std::cout.width(65); std::cout << std::right <<"ON THE MARKET" << '\n';
		cout << "Enter 1 for Register\nEnter 2 for Login\n" << endl;
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

	/*seller newSeller = seller("seif", "s@.", "s");

	Globals global = Globals();

	global.addSeller(newSeller);

	cout << "Sellers: " << global.sellers.size() << endl;
	cout << &global.sellers << endl;

	product_type createdProduct = newSeller.addingProduct();
	Customer newCustomer = Customer("ss", "ss@.", "ss", "Cairo", "010");
	newCustomer.addProductToCart(createdProduct);
	cout<< "Cart: " << newCustomer.mycart.prod.size() << endl;
	newCustomer.confirmOrder();

	cout << "from main " << newSeller.orders.size() << endl;
	cout << "befoooooor front method " <<  endl;

	cout << "from main " << newSeller.orders.front().name << endl;
	cout << "before omran loop" << endl;

	for (auto o : newSeller.orders) {
		cout << "Order Name " << o.products[0].name << endl;
	}
	newSeller.showOrder();*/
	return 0;
}

