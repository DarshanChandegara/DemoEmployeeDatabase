#pragma once
#include "include/Model/Engineer.h"
#include "include/Model/Salary.h"
#include "gtest/gtest.h"

class EngineerFixture : public testing::Test {
protected:

	void SetUp() {
		eng.setId(1);
		eng.setFirstname("Darshan");
		eng.setLastname("Chandegara");
		eng.setDob("26-08-2002");
		eng.setEmail("darshan@gmail.com");
		eng.setMobile("8469557424");
		eng.setGender(Gender::Male);
		eng.setDoj("01-01-2024");
		eng.setManagerId(1);
		eng.setDepartmentId(1);  

		std::stringstream input(" Surat Gujarat");
		std::streambuf* originalCin = std::cin.rdbuf(input.rdbuf());
		eng.setAddress();
		std::cin.rdbuf(originalCin);

		eng.setProgramming_language("JAVA");

		std::stringstream input1(" Jr Software Engineer");
		std::streambuf* originalCin1 = std::cin.rdbuf(input.rdbuf()); 
		eng.setSpecialization(); 
		std::cin.rdbuf(originalCin);  
	}

	void TearDown() {

	}
	Salary sg1{ 2 , 600000.0 , 500000.0 , 100000.0 };
	Engineer eng;
	Engineer eg1{ 3 , "Kalpesh" , "Shukla" , "16-12-1212" , "5567894565" , "this@gmail.com" , "jsdhgfd fgsd" , Gender::Male , "01-01-2023" , 1 , 1 , sg1 , "C++", "Senior C++ Develpoer"};
};