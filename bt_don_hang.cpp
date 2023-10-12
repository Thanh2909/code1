# include <iostream>
# include <string>
using namespace std;
class Product {
	private:
		int quantity, price;
		string name;
	public:
		void input(){
			cout<<"nhap ten SP: ";cin.ignore();
			getline(cin,name);
			cout<<"nhap so luong SP: ";cin>>quantity;
			cout<<"nhap gia thanh tren 1 SP: ";cin>>price;
			
		}
		void output(){
			cout<<"Ten: "<<name;
			cout<<", So luong: "<<quantity;
			int into_money=quantity*price;
			cout<<", Thanh tien:  "<<into_money<<endl;
			
		}
		int show_menu(){
		system("cls");
		int chose;
		cout << "xin chao !!:" <<endl<<"====MENU===="<<endl<<"Moi nhap lua chon cua ban"<<endl;
		
        cout << "1. Xem danh sach SP" << endl;
        cout << "2. Them SP moi" << endl;
        cout << "3. Xoa SP" << endl;
        cout << "0. Ket thuc chuong trinh" << endl;
        cout << "nhap lua chon cua ban (0-3): ";
        
        cin>>chose;
        return chose;
		}
		Product(){}
		void print_product(int* arr, int size){
			if(!size){
				cout<<"khong co SP nao trong danh sach !!";
			}
			else{
				cout<<"Danh sach SP:"<<endl;
				for(int i=0;i<size;i++)
				    {
					cout<<arr[i]<<endl;
			     	}
		    	}
	       	}
	       void add_product(Product* &arr, int &size){
			Product new_product;
			cout << "nhap thong tin sp moi: " << endl;
			new_product.input();
			int new_size = size + 1;
			Product* new_arr = new Product[new_size];
			for(int i=0; i<size; i++){
				new_arr[i] = arr[i];
			}
			delete []arr;
			arr = new_arr; 
			arr[new_size-1] = new_product;
			size = new_size;
			cout << "Them SP thanh cong" << endl;
		}
	
};
int main(){
	Product p;
	int n=0;
	Product* products = nullptr;
	
    
    while(true){
    	int chose=p.show_menu();
    	system("cls");
    	switch(chose)
		{
    	case 1: 
    	    p.print_product(products,n);
    	       break;
		case 2:
			p.add_product(products,n);
			   break;
		case 3:
			   break;
	    case 0:
	    cout<<"Bye Bye !!";
	    return 0;
		default:
		cout<<"Lua chon ko hop le."<<endl;	
		}
		cout<<"Ban co muon tiep tuc khong? (1/0)";
		bool is_continue;
		cin>>is_continue;
		
		if(!is_continue){
			cout<<"Bye Bye !!"<<endl<<"cam on ban da dung sp cua chung toi";
			delete[]number;
			break;
		}
	}


	return 0;
}
