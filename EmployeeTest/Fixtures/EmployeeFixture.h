#pragma once
#include "include/Model/Employee.h"
#include "include/Model/Salary.h"
#include "gtest/gtest.h"

class EmployeeFixture : public testing::Test {
protected:

	void SetUp() {
		emp.setId(1);
		emp.setFirstname("Darshan");
		emp.setLastname("Chandegara");
		emp.setDob("26-08-2002");
		emp.setEmail("darshan@gmail.com");
		emp.setMobile("8469557424");
		emp.setGender(Gender::Male);
		emp.setDoj("01-01-2024");
		emp.setManagerId(1);
		emp.setDepartmentId(1);

		std::stringstream input(" Surat Gujarat"); 
		std::streambuf* originalCin = std::cin.rdbuf(input.rdbuf());
		emp.setAddress(); 
		std::cin.rdbuf(originalCin);
	}

	void TearDown() {

	}
	Salary s{ 2 , 600000.0 , 500000.0 , 100000.0 };
	Employee emp;
	Employee e1{ 2 , "darshan" , "patel" , "16-12-1212" , "5567894565" , "this@gmail.com" , "jsdhgfd fgsd" , Gender::Male , "01-01-2023" , 1 , 1 , s};
};