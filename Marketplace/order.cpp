#include "order.h"





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

			

			global.sellers[i].orders.push_back(myOrder);
			

		}
	}
	
	
}