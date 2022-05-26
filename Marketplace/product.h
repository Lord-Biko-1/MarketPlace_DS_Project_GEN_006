#pragma once
#include <string>
#include <vector>
#include <deque>

using namespace std;


struct product_type {
    int id ;
	string name;
	double price;
	string category;
	int quantity;
	int seller_id;
	char tmBuff[30];

};

class product
{
	private:
		product_type p;

	public :
		static vector<product_type> prod;

		product();
		void add_products(product_type p);
		void delete_products(int deleted_id);
		deque<product_type> searchByCategory(string searched_category);
		deque<product_type> searchByName(string searched_name);
		deque<product_type> ViewProductForSeller(int selid);

		

};

