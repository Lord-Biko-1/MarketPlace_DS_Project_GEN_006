#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "user.h"
#include "seller.h"
#include "Customer.h"
using namespace std;


struct userType {
	string name;
	string email;
	string password;
	string address;
	string phone;
};




Customer customerRegister(vector<Customer>& customers);
seller sellerRegister(vector<seller>& sellers);

bool emailValidation(string email);
