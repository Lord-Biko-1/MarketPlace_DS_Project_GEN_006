#include "cart.h"
#include <iostream>
using namespace std;

cart::cart(void)
{
	totalPrice = 0.0;
	promo.push_back("test1");
	promo.push_back("test2");
	promo.push_back("test3");
}

bool cart::updateQuantity(int prodID, int q) {
	for (int i = 0; i < myProd.prod.size(); i++) {
		if (myProd.prod[i].id == prodID) {
			if (myProd.prod[i].quantity >= q) {
				myProd.prod[i].quantity -= q;
				return true;
			}
			else {
				cout << "No sufficient stock\n";
				return false;
			}
		}
	}
}

void cart::addToCart(cart_type p)
{
	prod.push_back(p);
}

bool cart::removeFromCart(int removed_id) {

	bool found = false;
	int i = 0;
	while (i != prod.size()) {

		if (prod[i].cart_products.id == removed_id) {
			prod.erase(prod.begin() + i);
			found = true;
			break;
		}
		i++;
	}
	return found;
}

void  cart::promoPrice(string promocode)
{
	bool discount = false;

	for (int i = 0; i < promo.capacity(); i++)
	{
		if (promo[i] == promocode )

		{
			totalPrice -= 30;
			cout << "you have a 30 pounds discount.." << endl;
			cout << "\n your total price is :" << totalPrice << " .L.E"<<endl;
			discount = true;
		}
	}
	if (!discount)
	{
		cout << "invalide promo code" << endl;
	}
}
void  cart::displayTotalPrice()
{
	double temp = 0;
	char ch = 'y';
	string promo;
	for (int i = 0; i < prod.size(); i++)
	{
		cout << "product Name :" << prod[i].cart_products.name << endl;
		cout << "product price :" << prod[i].cart_products.price << endl;
		cout << "product Quantity :" << prod[i].ordered_quantity << endl;

		temp += prod[i].cart_products.price * prod[i].ordered_quantity;

	}
	totalPrice = temp;
	cout << "total price is :" << totalPrice <<" .L.E" << endl;
	cout << "do you have a promo code ? (y/n)";
	cin >> ch;
	if (totalPrice>=100 && ch == 'y')
	{
			cout << "entre promo code to get your discount :";
			cin.ignore();
			getline(cin, promo);
			promoPrice(promo);
	}
	else if (totalPrice<100 && ch == 'y')
	{
		cout << "Sorry your total price less than 100 .L.E " << endl;
	}
	
}//saif //saif

