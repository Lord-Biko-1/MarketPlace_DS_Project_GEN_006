#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <chrono>
#include <ctime>
#include "seller.h"
#include "Globals.h"
#include "cart.h"
using namespace std;



class order
{
	OrderDetails orderDetails;
	Globals global = Globals();
	cart myCart;

 public:	
	vector<product_type> orderProducts;
	order(string name, string address, string phone, vector<cart_type> products) {
		
	
		orderDetails.name = name;
		orderDetails.address = address;
		orderDetails.phone = phone;
		orderDetails.products = products;


		for (int i = 0; i < products.size(); i++) {
			if (products[i].cart_products.quantity > 0) {
				bool available = myCart.updateQuantity(products[i].cart_products.id, products[i].ordered_quantity);
				if (available) {
					assignOrder(products[i]);
					cout << "Product --> " << products[i].cart_products.name << " <--Confirmed" << endl;

				}
			}
			
		}
	}

	OrderDetails getDetails() {
		return this->orderDetails;
	}

	seller getSeller(int id);
	void assignOrder(cart_type p);

};

