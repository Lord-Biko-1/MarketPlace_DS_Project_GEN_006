#include "seller.h"
#include<string>
#include <iostream>
using namespace std;


deque<OrderDetails> seller::orders;
seller::seller(string name, string email, string password)
	:user(name, email, password)
{
	
}


int seller::prod_id = 0;
product_type seller::addingProduct()
{
	auto start = std::chrono::system_clock::now();
	auto legacyStart = std::chrono::system_clock::to_time_t(start);
	ctime_s(sel.tmBuff, sizeof(sel.tmBuff), &legacyStart);

	sel.seller_id = this->id;
	sel.id = ++prod_id;
	cout << "\nentre product name :";
	cin.ignore();
	getline(cin, sel.name);
	cout << "\nentre product price :";
	cin >> sel.price;
	cout << "\nentre product quantity:";
	cin >> sel.quantity;
	cout << "\nentre product category:";
	cin.ignore();
	getline(cin, sel.category);
	pro.add_products(sel);
	return sel;
}
 void seller::deletProduct()
{
	int x;
	cout << "entre id to delete";
	cin >> x;
	pro.delete_products(x);
}
 void seller::UpdateProduct(int idToBeUpdated)
 {
	 cout << "welcome in updating....";
	 int x;
	 char ch = 'y';
	 if (!proloop.prod.empty()) {

		 for (int count = 0; count <= proloop.prod.capacity() - 1; count++)
		 {
			 if (proloop.prod[count].id == idToBeUpdated)
			 {
				 cout << "\n1-to update ID\n2-to update name\n3-to update price\n4-to update category\n5-to update quantity\n6-to update seller ID\n0-to back" << endl;
				 cin >> x;
				 switch (x)
				 {
				 case 1: {
					 int newId;
					 cout << "old id:\t";
					 cout << proloop.prod[count].id;
					 cout << "\nentre new id :";
					 cin >> newId;
					 proloop.prod[count].id = newId;
					 break;
				 }
				 case 2: {
					 string newname;
					 cout << "old name is :" << proloop.prod[count].name << endl;
					 cout << "entre new name :";
					 cin.ignore();
					 getline(cin, newname);
					 proloop.prod[count].name = newname;
					 break; }
				 case 3:
				 {
					 double newPrice;
					 cout << "old price:" << proloop.prod[count].price << endl;
					 cout << "entre new price:";
					 cin >> newPrice;
					 proloop.prod[count].price = newPrice;
					 break;
				 }
				 case 4: {
					 string newCategory;
					 cout << "old category:" << proloop.prod[count].category << endl;
					 cout << "entre new category:";
					 cin.ignore();
					 getline(cin, newCategory);
					 proloop.prod[count].category = newCategory;
					 break;
				 }
				 case 5:
				 {
					 int newquntity;
					 cout << "old quntity:" << proloop.prod[count].quantity << endl;
					 cout << "entre new quntity:";
					 cin >> newquntity;
					 proloop.prod[count].quantity = newquntity;
					 break;
				 }
				 case 6:
				 {int newId;
				 cout << "Old ID:" << proloop.prod[count].seller_id << endl;
				 cout << "entre new ID:";
				 cin >> newId;
				 proloop.prod[count].seller_id = newId;
				 break;
				 }
				 case 0:
				 {
					 sellerScreen();
					 break;
				 }
				 cout << "Any other update ? (y/n)" << endl;
				 cin >> ch;
				 if (ch == 'y')
				 {
					 UpdateProduct(idToBeUpdated);
				 }
				 else
				 {
					 sellerScreen();
				 }

				 }
			 }
		 }
	 }
	 else
	 {
		 cout << "there is no products to update" << endl;
	 }
 }
 void seller::showOrder()
 {
	
	 if (!orders.empty())
	 {

		 for (int i = 0; i < orders.size(); i++)
		 {
			 cout << "-----------------------------Order details--------------------------" << endl;
			 cout << "Welcome :" << sellerName<<endl;
			 cout << "Order no. #" << i + 1 << endl;
			 cout << "Order date :"<< orders[i].tmBuff << endl;
			 cout << "customer name :" << orders[i].name << endl;
			 cout << "customer adress :" << orders[i].address << endl;
			 cout << "customer phone :" << orders[i].phone << endl;
				
			cout << "product ID :" << orders[i].products[0].cart_products.id << endl;
			cout << "product name :" << orders[i].products[0].cart_products.name << endl;
			cout << "product category :" << orders[i].products[0].cart_products.category << endl;
			cout << "product price :" << orders[i].products[0].cart_products.price << endl;
			cout << "product quentity :" << orders[i].products[0].ordered_quantity << endl;
			cout << "product Seller Id :" << orders[i].products[0].cart_products.seller_id << endl;
			
			cout << "-------------------------------------------------------" << endl;

		 }
	 }
	 else
	 {
		 cout << "Sorry there is no Ordders yet" << endl;
		 
	 }
 }
 void seller::sellerScreen() {
	 int ch;

	 do {
		 cout << endl;
		 cout << "1 - Add New Product.\n";
		 cout << "2 - Delete Product.\n";
		 cout << "3 - Update Product.\n";
		 cout << "4 - Show My Products.\n";
		 cout << "5 - Show Existing Orders.\n";
		 cout << "6 - Sign Out.\n";


		 cout << endl;

		 int choice;
		 cin >> choice;
		 if (choice == 1) {
			 addingProduct();
		 }
		 else if (choice == 2) {
			 deletProduct();
		 }
		 else if (choice == 3) {
			 int update_id;
			 cout << "Enter the ID of product" << endl;
			 cin >> update_id;
			 UpdateProduct(update_id);
		 }
		 else if (choice == 4) {
			 pro.ViewProductForSeller(getID());
		 }
		 else if (choice == 5) {
			 showOrder();
		 }
		 else if (choice == 6) {
			 break;
		 }
		 cout << "Enter 0 to back to menu\n";
		 cin >> ch;
	 } while (ch == 0);
 }