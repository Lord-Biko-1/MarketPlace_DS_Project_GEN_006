#include "auth.h"

bool emailValidation(string email) {
	
	if (email.find("@") != string::npos) {
		if (email.find(".") != string::npos) {
			return true;
		}
		else {
			cout << "Invalid Email, Please enter valid email" << endl;
			return false;
		}
	}
	else {
		cout << "Invalid Email, Please enter valid email" << endl;
		return false;
	}
}


Customer customerRegister(vector<Customer>& customers) {
	userType temp;

	cin.ignore();
	cout << "Enter Your Name" << endl;
	getline(cin, temp.name);

	do {
		cout << "enter your email" << endl;
		getline(cin, temp.email);

	} while (emailValidation(temp.email) == false);

	cout << "Enter Your Password" << endl;
	getline(cin, temp.password);


	cout << "Enter Address" << endl;
	getline(cin, temp.address);


	cout << "Enter Phone" << endl;
	getline(cin, temp.phone);


	Customer createdCustomer = Customer(temp.name, temp.email, temp.password, temp.address, temp.phone);
	customers.push_back(createdCustomer);


	return createdCustomer;
}


seller sellerRegister(vector<seller>& sellers) {
	userType temp;

	cin.ignore();

	cout << "enter your name" << endl;
	getline(cin, temp.name);

	
	do {
		cout << "enter your email" << endl;
		getline(cin, temp.email);

	} while (emailValidation(temp.email) == false);
	cout << "enter your password" << endl;
	getline(cin, temp.password);


	seller createdseller = seller(temp.name, temp.email, temp.password);
	sellers.push_back(createdseller);
	return createdseller;
}










//
//template<class t>
//t userLogin(vector<t>& users) {
//	string enteredEmail;
//	string enteredPassword;
//
//	cout << "Enter Email" << endl;
//	cin >> enteredEmail;
//	cout << "Enter Password" << endl;
//	cin >> enteredPassword;
//
//	int i = 0;
//	while (i != users.capacity()) {
//		if (users[i].getEmail() == enteredEmail && users[i].getPassword() == enteredPassword) {
//			
//			return users[i];
//		}
//		else {
//
//			break;
//		}
//		i++;
//
//	}
//	cout << "Invalid login details";
//
//}
//
//

//template<class t>
//t userRegister(vector<t>& users, int type) {
//	userType temp;
//
//	cout << "Enter Your Name" << endl;
//	cin >> temp.name;
//
//	do {
//		cout << "Enter Your Email" << endl;
//		cin >> temp.email;
//		if (temp.email.find("@") != string::npos) {
//			if (temp.email.find(".") != string::npos) {
//				break;
//			}
//			else {
//				cout << "Invalid Email, Please enter valid email" << endl;
//				
//			}
//		}
//		else {
//			cout << "Invalid Email, Please enter valid email" << endl;
//			
//		}
//	} while (true);
//	cout << "Enter Your Password" << endl;
//	cin >> temp.password;
//
//	if (type == 1) {
//		cout << "Enter Address" << endl;
//		cin >> temp.address;
//		cout << "Enter Phone" << endl;
//		cin >> temp.phone;
//		t createdCustomer = t(temp.name, temp.email, temp.password, temp.address, temp.phone);
//		users.push_back(createdCustomer);
//		return createdCustomer;
//	}
//	else {
//		t createdSeller = t(temp.name, temp.email, temp.password);
//		users.push_back(createdSeller);
//		return createdSeller;
//	}
//
//	
//}