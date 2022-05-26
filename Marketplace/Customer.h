#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "user.h"
#include "cart.h"
#include "product.h"
#include "order.h"

using namespace std;

class Customer :public user
{
	string address;
	string phone;
	product myProduct;

public:
	cart mycart;
	product view;
	Customer(string name, string email, string password, string address, string phone);
	Customer(string name, string email, string password);
	deque<product_type> browseByCategory();
	deque<product_type> browseByName();
	void addProductToCart(product_type p, int q);
	void viewCart();
	void confirmOrder();
	void Order_Screen();
	void viewProduct();
};

