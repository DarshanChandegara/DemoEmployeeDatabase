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

		// Uncomment for InsertTest
		//e2.setId(1); 
		//e3.setId(4);
		//e3.setManagerId(12); 
		//e4.setId(5);
		//e4.setDepartmentId(10);

		// Uncommnet for DeleteTest
		//e2.setId(2);
		//e3.setId(3);
		//e3.setEmail("this@gmail.com");

		// Uncomment for UpdateTest
		e1.setDob("26-08-2003");
		e1.setEmail("newemail@gmail.com");
		e1.setManagerId(2);
		e1.setDepartmentId(2);
		emp.setManagerId(5);
		emp.setDepartmentId(4);
		e3.setId(4);


	}

	void TearDown() {

	}
	Model::Salary s{ 2 , 600000.0 , 500000.0 , 100000.0 };
	Model::Employee emp;
	Model::Employee e1{ 2 , "darshan" , "patel" , "16-12-1212" , "5567894565" , "this@gmail.com" , "jsdhgfd fgsd" , Gender::Male , "01-01-2023" , 1 , 1 , s};
	Model::Employee e2 = e1;
	Model::Employee e3 = e1;
	Model::Employee e4 = e1;
};