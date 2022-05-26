#pragma once
#include<iostream>
#include<deque>
#include <chrono>
#include<ctime>
#include "user.h"
#include "product.h"
#include "cart.h"

struct OrderDetails {
	string name;
	string address;
	string phone;
	vector<cart_type> products;
	char tmBuff[31];

};

class seller : public user
{
private :
	static int prod_id;

public:
	
	seller(string name, string email, string password);
	
	string sellerName =  name;
	static deque<OrderDetails> orders;
	product pro;
	product proloop;
	product_type sel;
	product_type addingProduct();
	void deletProduct();
	void UpdateProduct(int idToBeUpdated);
	void showOrder();
	void sellerScreen();
};
