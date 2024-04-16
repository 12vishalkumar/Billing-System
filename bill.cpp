//******************** Importing required libararies ************************
#include<iostream>
#include<string>
#include<conio.h>
#include<iomanip>
#include<fstream>
using namespace std;

//******************** Product class *****************************************
class Product {
    private:
        int productNumber;
        string productName;
        float productRate;
    public:
        Product(){
            productNumber = 0;
            productName = "";
            productRate = 0.0;
        }
    Product(int pNum, string pNam, float rate):productNumber(pNum),productName(pNam),productRate(rate){
        ofstream outProduct;
        outProduct.open("products.txt", ios::out | ios::app);
        outProduct
            << productNumber
            << ' '
            << productName
            << ' '
            << productRate
            <<endl;
        cout << "\n\n\n\tPRODUCT CREATED SUCCESSFULLY";
        getch();
    }
    int getNumber(){
        return productNumber;
    }
    string getName(){
        return productName;
    }
    float getRate(){
        return productRate;
    }
    void setNumber(int x){
        productNumber = x;
    }
    void setName(string x){
        productName = x;
    }
    void setRate(float x){
        productRate = x;
    }
};

//*************************** Billing class ************************
class Bill {
public:
	string date;
	float totalAmount;
public:
	Bill(){
		time_t now = time(0);
		char* dt = ctime(&now);
		date = dt;
		totalAmount = 0;
	}
};


//*************************** Bill Item class **********************
class BillItems {
private:
	Product product;
	int quantity;
public:
	void getItem(int code){
		ifstream prod;
		prod.open("products.txt", ios::in);
		int pn;
		string pp;
		float pr;
		while (1){
			prod >> pn >> pp >> pr;
			if (pn == code){
				product.setNumber(pn);
				product.setName(pp);
				product.setRate(pr);
				break;
			}
		}
	}

	void setQuantity(int x){
		quantity = x;
	}

	float getAmount(){
		int r;
		r = product.getRate();
		return r*quantity;
	}
    
	void printItemDet(){
		cout
			<< "\t" << setw(14) << product.getNumber()
			<< "\t" << setw(12) << product.getName()
			<< "\t" << setw(12) << product.getRate()
			<< "\t" << setw(8) << quantity << "\t";
	}
};


//************************* Invoice class *************************
class Invoice :public Bill {
private:
	int numOfItems;
	BillItems item[50];
};


//************************* new pagination class ******************
class NavPages {
public: 
	static void intro(){
		cout << "\n\n\n\tBILLING SYSTEM"<<endl;
		cout << "\n\t==========================================================================\n";
		cout << "\n\n\tMADE BY:";
		cout << "\n\n\tVishal Kumar";
	}

	static void user(){
		int ch;
		system("cls");
		cout << "\n\n\n\tMAIN MENU";
		cout << "\n\n\t1. CUSTOMER";
		cout << "\n\n\t2. ADMINISTRATOR";
		cout << "\n\n\t3. EXIT";
		cout << "\n\n\tPlease Select Your Option (1 - 3) ";
		cin >> ch;
		switch (ch){
		case 1: customer(); break;
		case 2: admin(); break;
		case 3: exit(0);
		}
	}
	
	static void customer(){
		int n;
		BillItems item[20];
		system("cls");
		cout << "\n\n\tENTER THE NUMBER OF ITEMS:";
		cin >> n;
		displayProduct();//display all products
		int code;
		int qty;
		for (int i = 0; i < n; i++){
			cout << "\n\tENTER ITEM CODE:" << endl;
			cin >> code;
			item[i].getItem(code);
			cout << "\n\tENTER ITEM QUANTITY:" << endl;
			cin >> qty;
			item[i].setQuantity(qty);
		}
		Bill fBill;
		for (int i = 0; i < n; i++){
			fBill.totalAmount+=item[i].getAmount();
		}
		system("cls");
		cout << "\n\n\tINVOICE\t\t\tDate/Time:" << fBill.date << endl;
		cout << "\t=================================================================================="<<endl;
		cout << "\tProduct Number\tProduct Name\tProduct Rate\tQuantity\tAmount" << endl;
		for (int i = 0; i < n; i++){
			item[i].printItemDet();
			cout << setw(6) << item[i].getAmount() << endl;
		}
		cout << "\n\n\t\t\t\tTOTAL AMOUNT: " << fBill.totalAmount;
		cout << "\n\tThank You for Shopping" << endl;
		cout << "\n\tPress any key to continue...";
		getch();
	}

	static void admin(){
		while (1){
			system("cls");
			int ch;
			cout << "\n\n\n\tADMIN MENU";
			cout << "\n\n\t1.CREATE PRODUCT";
			cout << "\n\n\t2.DISPLAY ALL PRODUCTS";
			cout << "\n\n\t3.MODIFY PRODUCT";
			cout << "\n\n\t4.DELETE PRODUCT";
			cout << "\n\n\t5.BACK TO MAIN MENU";
			cout << "\n\n\tPlease Enter Your Choice (1-5) ";
			cin >> ch;
			switch (ch){
			case 1:createProduct(); break;
			case 2:displayProduct(); break;
			case 3:modifyProduct(); break;
			case 4:deleteProduct(); break;
			case 5: user(); break;
			default: break;
			}
		}
	}

	static void createProduct(){
		system("cls");
		int n;
		string p;
		float r;
		cout << "\n\n\tENTER THE DETAILS OF THE PRODUCT" << endl;
		cout << "\n\tENTER THE PRODUCT NUMBER" << endl;
		cin >> n;
		cout << "\n\tENTER THE PRODUCT NAME" << endl;
		cin >> p;
		cout << "\n\tENTER THE PRODUCT RATE" << endl;
		cin >> r;
		Product prod(n,p,r);
	}

	static void displayProduct(){
		system("cls");
		ifstream displayProducts;
		displayProducts.open("products.txt", ios::in);
		int n;
		string p;
		float r;
		cout << "\n\n\tDISPLAY THE ALL PRODUCTS"<<"\n\t==================================================";
		while (1)
		{
			displayProducts >> n;
			if (displayProducts.eof())
				break;
			displayProducts >> p >> r;
			//displaying on screen
			cout << "\n\tPRODUCT NUMBER : " << n;
			cout << "\n\tPRODUCT NAME : " << p;
			cout << "\n\tRATE OF PRODUCT : " << r;
			cout << "\n\t=================================================================";
		}
		cout<<"\n\tPress any key";
		getch();
	}

	static void modifyProduct(){
		system("cls");
		displayProduct();
		ifstream prodIn;
		ofstream prodTmp;
		cout << "\n\t######################################################################";
		cout << "\n\tEnter the Product Number to Modify:\n";
		int modNum;
		cin >> modNum;
		prodIn.open("products.txt", ios::in);
		prodTmp.open("temp.txt", ios::out);
		int n;
		string p;
		float r;
		while (1){
			prodIn >> n;
			if (prodIn.eof())
				break;
			prodIn >> p >> r;
			if (n == modNum)
			{
				cout << "\n\tEnter new rate:";
				cin >> r;
			}	
			prodTmp
				<< n
				<< ' '
				<< p
				<< ' '
				<< r
				<< endl;
		}
		prodIn.close();
		prodTmp.close();
		remove("products.txt");
		rename("temp.txt", "products.txt");
		cout << "\n\n\n\tPRODUCT RATE UPDATED SUCCESSFULLY";
		getch();
	}

	static void deleteProduct(){
		system("cls");
		displayProduct();
		ifstream prodIn;
		ofstream prodTmp;
		cout << "\n\t#####################################################################";
		cout << "\n\tEnter the Product Number to Delete:\n";
		int modNum;
		cin >> modNum;
		prodIn.open("products.txt", ios::in);
		prodTmp.open("temp.txt", ios::out);
		int n;
		string p;
		float r;
		while (1){
			prodIn >> n;
			if (prodIn.eof())
				break;
			prodIn >> p >> r;
			if (n != modNum){
				prodTmp
                    << n
					<< ' '
					<< p
					<< ' '
					<< r
					<< endl;
			}
		}
		prodIn.close();
		prodTmp.close();
		remove("products.txt");
		rename("temp.txt", "products.txt");
		cout << "\n\n\n\tPRODUCT DELETED SUCCESSFULLY";
		getch();
	}
};


//******************************* Main function ****************************
void main()
{
	NavPages::intro();
	getch();
	system("cls");
	while (1){
		NavPages::user();
	}
}