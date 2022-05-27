#include "order.h"



seller order::getSeller(int id) {
	for (int i = 0; i < global.sellers.size(); i++) {
		if (global.sellers[i].getID() == id) {
			return global.sellers[i];
		}
	}
}

void order::assignOrder(cart_type p) {

	for (int i = 0; i < global.sellers.size(); i++) {
		if (global.sellers[i].getID() == p.cart_products.seller_id) {

			char tempDate[31];

			auto start = std::chrono::system_clock::now();
			auto legacyStart = std::chrono::system_clock::to_time_t(start);
			ctime_s(tempDate, sizeof(tempDate), &legacyStart);

			OrderDetails myOrder;
			myOrder.name = this->getDetails().name;
			myOrder.address = this->getDetails().address;
			myOrder.phone = this->getDetails().phone;
			myOrder.products.push_back(p);
			myOrder.tmBuff = tempDate;

			cout << "The ID: " << p.cart_products.id<<endl;

			/*for (int i = 0; i < temp.products.size(); i++) {
				cout << "The ID: " << temp.products[i].cart_products.id << endl;
			}*/

			global.sellers[i].orders.push_back(myOrder);
			

		}
	}
	
	//seller mySeller = getSeller(p.seller_id);
	
}