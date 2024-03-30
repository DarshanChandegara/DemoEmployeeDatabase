#include "../include/Model/Department.h"
#include "../include/Model/Engineer.h" 
#include "../include/Model/Manager.h"
#include "../include/controllers/departmentController.h"
#include "../include/controllers/engineerController.h"
#include<optional>
using namespace std;

void action(int j) noexcept {
	auto check{ true };
	while (check) {
		system("cls");
		std::cout << "Select The Operation You Want The Perform\n";
		std::cout << "1. View\n";
		std::cout << "2. Insert\n";
		std::cout << "3. Update\n";
		std::cout << "4. Delete\n";
		std::cout << "5. Go to Main Menu\n\n";

		int i;
		i = std::stoi(input("Enter Your Choice : ", std::regex{ "[1-5]" }).value_or("5"));
		Model::Engineer e; 
		Model::Manager m; 
		Model::Department d;
		switch (j) {
		case 1:
			switch (i) {
			case 1:
				e.viewEngineer();
				break;

			case 2:
			{
				auto e1 = userInputEngineer();
				if (e1.has_value()) {
					e1.value().insertEngineer();
				}
				else {
					std::cerr << "\x1b[33m Insertion Failed \x1b[0m\n\n"; 
					waitMenu(); 
				}
				break;
			}

			case 3:
			{
				auto e1 = updateEngineerController(); 
				if (e1.has_value()) { 
					e1.value().updateEngineer();  
				}
				else {
					std::cerr << "\x1b[33m Updation Failed \x1b[0m\n\n"; 
					waitMenu(); 
				}
				break;
			}

			case 4:
			{
				auto e1 = deleteEmployeeController(); 
				if (e1.has_value()) { 
					e1.value().deleteEmployee(); 
				}
				else {
					std::cerr << "\x1b[33m Insertion Failed \x1b[0m\n\n"; 
					waitMenu(); 
				}
				break;
			}

			case 5:
				check = false;
				break;
			}
			break;

		case 2:
			switch (i) {
			case 1:
				m.viewManager();
				break;

			case 2:
				m.insertManager();
				break;

			case 3:
				m.updateManager();
				break;

			case 4:
				m.deleteManager();
				break;

			case 5:
				check = false;
				break;
			}
			break;

		case 3:
			switch (i) {
			case 1:
				d.viewDepartment(); 
				break;

			case 2:
			{
				auto d1 = userinputDepartment();
				if (d1.has_value())  
					d1.value().insertDepartment();
				else {
					std::cerr << "\x1b[33m Insertion Failed \x1b[0m\n\n";
					waitMenu(); 
				}  
				break;
			}

			case 3:
			{
				auto d1 = updateDepartmentController();
				if (d1.has_value()) 
					d1.value().updateDepartment();
				else {
					std::cerr << "\x1b[33m Updation Failed \x1b[0m\n\n"; 
					waitMenu(); 
				}
				break;
			}

			case 4:
			{
				auto d1 = deleteDepartmentController();
				if (d1.has_value())
					d1.value().deleteDepartment();
				else {
					std::cerr << "\x1b[33m Deletion Failed \x1b[0m\n\n"; 
					waitMenu(); 
				}
				break;
			}

			case 5:
				check = false;
				break;
			}
			break;

		default:
			std::cout << "Enter Valid Choice\n";
		}
	}
}
