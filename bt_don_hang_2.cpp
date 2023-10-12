#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
#include <cstring>
#include <fstream>

using namespace std;
struct Product
{
	string name;
	 unsigned long long int	price;
	int quantity;
	
	friend istream& operator>>(istream& is, Product &prd)
	{
		cout<<"Ten SP: ";cin.ignore();getline(is,prd.name);
		cout<<"So luong SP: ";is>>prd.quantity;
		cout<<"Gia thanh tren 1 SP: ";is>>prd.price;
		
		return is;
	}

	friend ostream& operator<<(ostream& os, Product prd) {
    int name_width = max(20, static_cast<int>(prd.name.length()));
    int quantity_width = max(4, static_cast<int>(to_string(prd.quantity).length()));
    unsigned long long int price_width = max(20, static_cast<int>(to_string(prd.price).length()));

    os << "| " << setw(name_width) << left << prd.name << " |   "
       << setw(quantity_width)<< left << prd.quantity << " | "
       << setw(price_width) << right << prd.price << " | "
       << setw(price_width) << right << prd.price * prd.quantity << " |"<<endl;
	os << "|----------------------|--------|----------------------|----------------------|" ;

    return os;
	}
};

//write function show menu
	int show_menu()
	{
		system("cls");
		int choice;
		cout<<"===========MENU============"<<endl;
		cout<<" 1. Xem danh sach SP."<<endl;
		cout<<" 2. Them SP vao danh sach."<<endl;
		cout<<" 3. Xoa SP ra khoi danh sach."<<endl;
		cout<<" 4. Loc SP trong danh sach."<<endl;
		cout<<" 5. Xuat file danh sach SP."<<endl;
		cout<<" 6. Nhap danh sach SP."<<endl;
		
		
		cout<<" 0. Ket thuc chuong trinh."<<endl;

		cout<<" Moi nhap lua chon cua ban!! (0-4)  ";
		cin>>choice;

		return choice;
	}

	void print_products(Product *products,int size)
{
		if(!size)
	{
		cout<<"Khong co san pham nao trong danh sach"<<endl;	
	}
	else
	{
    // In tiêu đề của bảng
    cout << "|      Ten san pham    |So luong|       Gia thanh      |      Thanh tien      |" << endl;
    cout << "|----------------------|--------|----------------------|----------------------|" << endl;
    // Duyệt qua danh sách sản phẩm và in từng sản phẩm ra bảng
    for (int i = 0; i < size; i++)
	 {
    cout<<products[i]<<endl;
     }
    }
}

	void find_products(Product* &products,int &size)
	{
		while(true)
		{
		if (!size) 
		{
    cout << "khong co sp nao trong danh sach !!" << endl;
        } 
  else 
  {
    string search_name;
    cout << "nhap ten sp can tim : ";
    cin.ignore();
    getline(cin, search_name);

    int is_found = false;
    for (int i = 0; i < size; i++) {
      if (!search_name.compare(products[i].name)) {
        cout << "Tim thay SP: " << endl;
		// In tiêu đề của bảng
		cout << "|----------------------|--------|----------------------|----------------------|" <<endl;
        cout << "|      Ten san pham    |So luong|       Gia thanh      |      Thanh tien      |" << endl;
        cout << "|----------------------|--------|----------------------|----------------------|" << endl;
        cout << products[i] << endl;
        is_found = true;
        break;
         }
       }

    if (!is_found) {
      cout << "Khong tim thay SP nao!!" << endl;
    }
  }
    	//ham hoi co muon ket thuc ko
    	int is_continue;
       // Tạo vòng lặp `while` để tiếp tục hỏi người dùng
        while (true) {
       // Hiển thị thông báo cho người dùng
	    cout<<"===========CONTINUE============"<<endl;
		cout<<" 1. Tro ve Menu."<<endl;
		cout<<" 2. Tiep tuc tim kiem SP."<<endl;
		cout<<" Moi nhap lua chon cua ban!! (1/2) ";

    // Nhận đầu vào từ người dùng
    cin>>is_continue;
	system ("cls");
    // Sử dụng `switch` để kiểm tra đầu vào
    switch (is_continue) {
      // Nếu người dùng nhập 1, thì tiếp tục chương trình
      case 1:
        return;
		//tiep tuc chuong trinh
		case 2:
		break;
      // Nếu người dùng nhập bất kỳ giá trị nào khác, thì hiển thị thông báo lỗi
      default:
	  	system("cls");
        cout << "Lua chon cua ban khong hop le. Moi ban nhap lai: "<<endl;
        continue;
    }break;
	  }
	 }
	}
	
	
	//add products in show menu
	void add_products(Product* &products,int &size)
	{
		while (true)
		{
			Product new_products;
		cout<<"Nhap thong tin SP moi: "<<endl;
		cin>>new_products;
		int new_size=size+1;
		Product *tmp_prd=new Product[new_size];
		for(int i=0;i<size;i++)
		{
			tmp_prd[i]=products[i];
		}
		tmp_prd[new_size-1]=new_products;
		delete[] products;
		products=tmp_prd;
		size=new_size;
		cout<<"Them SP thanh cong !!"<<endl;
		int is_continue;
        while (true) {
	    cout<<"===========CONTINUE============"<<endl;
		cout<<" 1. Tro ve Menu."<<endl;
		cout<<" 2. Tiep tuc them SP."<<endl;
		cout<<" Moi nhap lua chon cua ban!! (1/2) ";
		cin>>is_continue;
		system ("cls");
		// Sử dụng `switch` để kiểm tra đầu vào
		switch (is_continue) {
		// Nếu người dùng nhập 1, thì tiếp tục chương trình
		case 1:
			return;
			//tiep tuc chuong trinh
			case 2:
			break;
		// Nếu người dùng nhập bất kỳ giá trị nào khác, thì hiển thị thông báo lỗi
		default:
			system("cls");
			cout << "Lua chon cua ban khong hop le. Moi ban nhap lai: "<<endl;
			continue;
		  }break;
			}
			}
	   }
		
	// delete products
	void deleted_products(Product* &products,int &size)
	{
		while (true)
		{
			if(!size)
		{
			cout<<"Chua co SP nao!!"<<endl;
		}
		else
		{
			string delete_name;
			cout<<"Nhap ten SP can xoa: ";cin.ignore();
			getline(cin,delete_name);

			int delete_index=-1;
			for(int i=0;i<size;i++)
			{
				if(!delete_name.compare(products[i].name))
				{
					delete_index=i;
					break;
				}
			}
			if(delete_index ==-1)
			{
				cout<<"Khong tim thay SP nao!!";
				cout<<endl;
			}
			else
			{
			for(int i=delete_index;i<size-1;i++)
			{
				products[i]=products[i+1];
			}
			size--;
			Product* index_pr=new Product[size];
			for(int i=0;i<size;i++)
			{
				index_pr[i]=products[i];
			}
			delete[]products;
			products=index_pr;
			cout<<"xoa SP thanh cong!!"<<endl;	
			}}
			 //ham hoi co muon ket thuc ko
			int is_continue;
		while (true) {
			cout<<"===========CONTINUE============"<<endl;
			cout<<" 1. Tro ve Menu."<<endl;
			cout<<" 2. Tiep tuc xoa SP."<<endl;
			cout<<" Moi nhap lua chon cua ban!! (1/2) ";
			cin>>is_continue;
			system ("cls");
			switch (is_continue) {
			// Nếu người dùng nhập 1, thì tiếp tục chương trình
			case 1:
				return;
				//tiep tuc chuong trinh
				case 2:
				break;
			// Nếu người dùng nhập bất kỳ giá trị nào khác, thì hiển thị thông báo lỗi
			default:
				system("cls");
				cout << "Lua chon cua ban khong hop le. Moi ban nhap lai: "<<endl;
				continue;
			}break;
				}
			  }
			}

			void export_products_to_file(Product* products, int size) {
			int option = 0;
			do {
				cout << "Chon dinh dang file de xuat du lieu: " << endl;
				cout << "1. CSV" << endl;
				cout << "2. JSON" << endl;
				cout << "3. XML" << endl;
				cout << "4. TXT" << endl;
				cout << "Lua chon cua ban la: ";
				cin >> option;
			} while (option < 1 || option > 4);

			// Tạo đối tượng ofstream để viết dữ liệu sản phẩm vào file
			ofstream outfile;
			switch (option) {
				case 1:
				outfile.open("products.csv");
				break;
				case 2:
				outfile.open("products.json");
				break;
				case 3:
				outfile.open("products.xml");
				break;
				case 4:
				outfile.open("products.txt");
				break;
			}
	
			// Duyệt qua danh sách sản phẩm và viết thông tin của từng sản phẩm vào file
		outfile << "|----------------------|--------|----------------------|----------------------|" <<endl;
        outfile << "|      Ten san pham    |So luong|       Gia thanh      |      Thanh tien      |" << endl;
        outfile << "|----------------------|--------|----------------------|----------------------|" << endl;
			for (int i = 0; i < size; i++) {
				  outfile << products[i]<< endl;
			}
				cout<<"Xuat file thanh cong :)";
			// Đóng file
			outfile.close();
			}
				// Tạo một hàm có tên `end()`
			void end_case1() {
				string index;
					cout<<"* Moi ban nhan phim bat ky de Tro ve Menu."<<endl;
					cin>>index;  
							}

			void nhap_du_lieu_tu_file(Product *&products, int &size) {
			// Yêu cầu người dùng nhập đường dẫn đến file
			cout << "Nhap duong dan den file: ";
			string duong_dan_file;
			cin >> duong_dan_file;

			// Mở file để đọc dữ liệu
			ifstream infile(duong_dan_file);
			if (!infile) {
				// File không tồn tại
				cout << "Khong tim thay file." << endl;
				return;
			}

			// Đọc dữ liệu từ file
			while (!infile.eof()) {
				Product new_product;
				infile >> new_product;

				int new_size = size + 1;
				Product *tmp_prd = new Product[new_size];
				for (int i = 0; i < size; i++) {
				tmp_prd[i] = products[i];
				cout<<endl;
				}
				tmp_prd[new_size - 1] = new_product;
				delete[] products;
				products = tmp_prd;
				size = new_size;break;
			}

			// Đóng file
			infile.close();
			}


// Hàm lọc sản phẩm theo số lượng
void filter_products_by_quantity(Product* products, int size, int quantity) {
  // Tạo một mảng chứa các sản phẩm phù hợp với tiêu chí lọc
  Product* filtered_products = new Product[size];
  int filtered_size = 0;

  // Duyệt qua danh sách sản phẩm
  for (int i = 0; i < size; i++) {
    // Nếu sản phẩm tại vị trí i phù hợp với tiêu chí lọc
    if (products[i].quantity == quantity) {
      // Thêm sản phẩm đó vào mảng filtered_products
      filtered_products[filtered_size++] = products[i];
    }
  }

  // In ra danh sách sản phẩm đã được lọc
  print_products(filtered_products, filtered_size);

  // Xóa mảng filtered_products
  delete[] filtered_products;
}

// Hàm lọc sản phẩm theo giá thành
void filter_products_by_price(Product* products, int size, unsigned long long int price) {
  // Tạo một mảng chứa các sản phẩm phù hợp với tiêu chí lọc
  Product* filtered_products = new Product[size];
  int filtered_size = 0;

  // Duyệt qua danh sách sản phẩm
  for (int i = 0; i < size; i++) {
    // Nếu sản phẩm tại vị trí i phù hợp với tiêu chí lọc
    if (products[i].price == price) {
      // Thêm sản phẩm đó vào mảng filtered_products
      filtered_products[filtered_size++] = products[i];
    }
  }

  // In ra danh sách sản phẩm đã được lọc
  print_products(filtered_products, filtered_size);

  // Xóa mảng filtered_products
  delete[] filtered_products;
}

// Hàm lọc sản phẩm theo tên
void filter_products_by_name(Product* products, int size, string name) {
  // Tạo một mảng chứa các sản phẩm phù hợp với tiêu chí lọc
  Product* filtered_products = new Product[size];
  int filtered_size = 0;

  // Duyệt qua danh sách sản phẩm
  for (int i = 0; i < size; i++) {
    // Nếu sản phẩm tại vị trí i phù hợp với tiêu chí lọc
    if (products[i].name.find(name) != string::npos) {
      // Thêm sản phẩm đó vào mảng filtered_products
      filtered_products[filtered_size++] = products[i];
    }
  }

  // In ra danh sách sản phẩm đã được lọc
  print_products(filtered_products, filtered_size);

  // Xóa mảng filtered_products
  delete[] filtered_products;
}

// Hàm lọc sản phẩm
void filter_products(Product* products, int size, int type, int value, string label) {
  switch (type) {
    case 1:
      filter_products_by_name(products, size, label);
      break;
    case 2:
      filter_products_by_quantity(products, size, value);
      break;
    case 3:
      filter_products_by_price(products, size, value);
      break;
    default:
      cout << "Lua chon khong hop le." << endl;
      break;
  }
}

			

ofstream outfile;
int main()
{
	int size=0;
	Product *products=new Product[size];
	string label;
	int value; 
	int type;
	while(true)
	{
		int choice=show_menu();
		system ("cls");
		switch(choice)
		{
			case 1://xem danh sach sp
				print_products(products,size);
				end_case1();
				break;

			case 2://them sp
				add_products(products,size);
				break;

			case 3://xoa sp
				deleted_products(products,size);
				break;
			case 4://tim sp
				system("cls");
				while (true){
				cout << "Chon loai loc: " << endl;
				cout << "1. Ten" << endl;
				cout << "2. So luong" << endl;
				cout << "3. Gia thanh" << endl;
				
				cin >> type;
				if(type == 2||type == 3){
				cout << "Nhap gia tri loc: ";
				cin >> value;
				filter_products(products, size, type, value, label);
				}
				else
				{cout << "Nhap gia ten loc: ";
				cin >> label;
				filter_products(products, size, type, value, label);
				}end_case1();break;}break;
			case 5://xuat file
				export_products_to_file(products,size);
				end_case1();
				break;
			case 6://nhap file
				nhap_du_lieu_tu_file(products, size);
				end_case1();
				break;
			

			case 0://thoat khoi chuong trinh
			cout<<"cam on ban da su dung chuong trinh cua chung toi ";
			return 0;

			default:
			cout<<"lua chon ban nhap ko hop le :( "<<endl;
			break;
		}
	}
	return 0;
}
