#include "product.h"
#include <iostream>


using namespace std;

vector<product_type> product::prod;

product::product() {


}

void product::add_products(product_type p) {

	prod.push_back(p);
}


void product::delete_products(int deleted_id) {
	
	bool found = false;

	

	int i=0;
	while (i < prod.capacity()){

		if (prod[i].id == deleted_id) {
			prod.erase(prod.begin()+i);
			found = true;
			break;
		}
		i++;
	}
	if (found) {
		cout << "deleted successflly \n";
	}
	else {
		cout << "sorry Product not found \n";
	}
}


deque<product_type> product::searchByCategory(string searched_category){
	bool found = false;
	deque <product_type> searched_que;

	int i = 0;
	while(i < prod.size()) {
		if (prod[i].category.compare(searched_category)==0) {
			searched_que.push_back(prod[i]);
			cout << "---------------------------------------------------" << endl;
			cout << "Product ID: " << prod[i].id << endl;
			cout << "Product Name: " << prod[i].name << endl;
			cout << "Product Price: " << prod[i].price << endl;
			cout << "Product Category: " << prod[i].category << endl;
			cout << "Product Quantity: " << prod[i].quantity << endl;
			cout << "---------------------------------------------------" << endl;

			found = true;
		}
		i++;
	}
	if (!found) {
		cout << "sorry not found this category \n";
	}
	while (!searched_que.empty()) {
		return searched_que ;
	}
}

deque<product_type> product::searchByName(string searched_name) {
	bool found = false;

	deque <product_type> searched_que;

	int i = 0;
	while (i < prod.size()) {
		
		if (prod[i].name.compare(searched_name) == 0) {
			searched_que.push_back(prod[i]);
			cout << "---------------------------------------------------" << endl;
			cout << "Product ID: " << prod[i].id << endl;
			cout << "Product Name: " << prod[i].name << endl;
			cout << "Product Price: " << prod[i].price << endl;
			cout << "Product Category: " << prod[i].category << endl;
			cout << "Product Quantity: " << prod[i].quantity << endl;
			cout << "Product Seller: " << prod[i].seller_id << endl;
			cout << "---------------------------------------------------" << endl;

			found = true;
		}
		i++;

	}
	if (!found) {
		cout << "sorry not found this product \n";
	}
	while (!searched_que.empty()) {
		return searched_que;
	}
}

deque<product_type> product::ViewProductForSeller(int selid)
{
	bool found = false;

	deque <product_type> ProductForSameSeller;

	int i = 0;
	while (i < prod.size()) {

		if (prod[i].seller_id ==selid) {
			ProductForSameSeller.push_back(prod[i]);
			cout << "----------------------------------------" << endl;
			cout << "creation date: " << prod[i].tmBuff<< endl;
			cout << "Product ID: " << prod[i].id << endl;
			cout << "Product Name: " << prod[i].name << endl;
			cout << "Product Price: " << prod[i].price << endl;
			cout << "Product Category: " << prod[i].category << endl;
			cout << "Product Quantity: " << prod[i].quantity << endl;
			cout << "Product Seller: " << prod[i].seller_id << endl;
			cout << "----------------------------------------" << endl;
			found = true;
		}
		i++;

	}
	if (!found) {
		cout << "sorry no products to show \n";
	}
	while (!ProductForSameSeller.empty()) {
		return ProductForSameSeller;
	}
}