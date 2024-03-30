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

		//std::stringstream input(" Surat Gujarat");
		//std::streambuf* originalCin = std::cin.rdbuf(input.rdbuf());
		eng.setAddress("Surat Gujarat");
		//std::cin.rdbuf(originalCin);

		eng.setProgramming_language("JAVA");

		//std::stringstream input1(" Jr Software Engineer");
		//std::streambuf* originalCin1 = std::cin.rdbuf(input.rdbuf());
		eng.setSpecialization("Jr Software Engineer");
		//std::cin.rdbuf(originalCin);


		eg3.setDepartmentId(5);
		eg3.setManagerId(1);


		// Uncomment for UpdateTest
		//eg2.setId(1);
		eg1.setId(1);
		eg1.setDepartmentId(5);
		eng.setDob("26-08-2003");
		eng.setEmail("newemail@gmail.com");
		eng.setManagerId(1);
		eng.setDepartmentId(1);



		// Uncomment for DeleteTest
		//eg3.setid(1);
		//eg3.setemail("dfhja@djhfg.fedjb");
		//eg2.setid(2); 
		//eg1.setemail("this@gmail.com");
	}

	void TearDown() {

	}
	Model::Salary sg1{ 4 , 600000.0 , 500000.0 , 100000.0 };
	Model::Engineer eng;
	Model::Engineer eg1{ 3 , "Kalpesh" , "Shukla" , "16-12-1212" , "5567894565" , "this@gmail.com" , "jsdhgfd fgsd" , Gender::Male , "01-01-2023" , 1 , 1 , sg1 , "C++", "Senior C++ Develpoer" };
	Model::Engineer eg2{ 4 , "Kalpesh" , "Shukla" , "16-12-1212" , "5567894565" , "this@gmail.com" , "jsdhgfd fgsd" , Gender::Male , "01-01-2023" , 15 , 1 , sg1 , "C++", "Senior C++ Develpoer" }; 
	Model::Engineer eg4{ 4 , "Kalpesh" , "Shukla" , "16-12-1212" , "5567894565" , "this@gmail.com" , "jsdhgfd fgsd" , Gender::Male , "01-01-2023" , 15 , 1 , sg1 , "C++", "Senior C++ Develpoer" };
	Model::Engineer eg3 = eg2;
	

};