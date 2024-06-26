#include "pch.h"
#include "Fixtures/EmployeeFixture.h"
#include "Fixtures/EngineerFixture.h"
#include "Fixtures/DepartmentFixture.h"
#include "Fixtures/ManagerFixture.h"
#include "Fixtures/SalaryFixture.h"


TEST(TestCaseName, DISABLED_TestName) {    
  EXPECT_EQ(1, 1);
  ASSERT_EQ(fun(), "darshan");
}

TEST_F(EmployeeFixture , DISABLED_constructionTest) {  
	ASSERT_EQ(emp.getId(), 1);
	ASSERT_EQ(emp.getFirstname(), "Darshan");
	ASSERT_EQ(emp.getLastname(), "Chandegara");
	ASSERT_EQ(emp.getEmail(), "darshan@gmail.com");
	ASSERT_EQ(emp.getMobile(), "8469557424");
	ASSERT_EQ(emp.getDob(), "26-08-2002"); 
	ASSERT_EQ(emp.getDoj(), "01-01-2024"); 
	ASSERT_EQ(emp.getManagerId(), 1); 
	ASSERT_EQ(emp.getDepartmentId(), 1); 
	ASSERT_EQ(emp.getGender(), Gender::Male);
}



// Employee 

TEST_F(EmployeeFixture, InsertTest) {
	ASSERT_TRUE(e1.insertEmployee());  // Success
	ASSERT_FALSE(e2.insertEmployee());  // Fail because Employee is already exist  
	ASSERT_FALSE(e3.insertEmployee()); // Fail Beacause Manager is not available  
	ASSERT_FALSE(e4.insertEmployee()); // Fail Beacause Department is not available   
}

TEST_F(EmployeeFixture, DISABLED_ViewTest) {
	ASSERT_TRUE(emp.viewEmployee()); //sucess
	ASSERT_FALSE(emp.viewEmployee()); //record not avilable     
}


TEST_F(EmployeeFixture, UpdateTest) {
	ASSERT_FALSE(e6.updateEmployee()); //  updated manager id is not available 
	EXPECT_FALSE(e7.updateEmployee()); // Updated Department id is not avialable 
	EXPECT_FALSE(e8.updateEmployee()); // Enter Employee is not aviable   
	ASSERT_TRUE(e1.updateEmployee()); // Sucess     
}

TEST_F(EmployeeFixture, DeleteTest) {
	ASSERT_FALSE(e9.deleteEmployee()); // Fail Beacuse  it is a manager of other employeees   
	ASSERT_FALSE(e8.deleteEmployee()); // Fail because Employee with given id is not available   

	ASSERT_TRUE(e1.deleteEmployee());  // Suceess   
}




// Engineer 

TEST_F(EngineerFixture, InsertTest) {
	ASSERT_TRUE(eg1.insertEngineer());    // Success  
	ASSERT_FALSE(eng.insertEngineer());  // Fail because Employee is already exist  
	ASSERT_FALSE(eg2.insertEngineer()); // Fail Beacause Manager is not available  
	ASSERT_FALSE(eg3.insertEngineer()); // Fail Beacause Department is not available  
}

TEST_F(EngineerFixture, DISABLED_ViewTest) {
	ASSERT_TRUE(eg1.viewEngineer()); //sucess 
	ASSERT_FALSE(eng.viewEngineer()); //record not avilable   
}

TEST_F(EngineerFixture, UpdateTest) {
	ASSERT_FALSE(eg4.updateEngineer()); //  updated manager id is not available  
	EXPECT_FALSE(eg5.updateEngineer()); // Updated Department id is not avialable    
	EXPECT_FALSE(eg4.updateEngineer()); // Enter Employee is not aviable      
	ASSERT_TRUE(eng.updateEngineer()); // Sucess         
}

TEST_F(EngineerFixture, DeleteTest) {
	ASSERT_FALSE(eg6.deleteEngineer()); // Fail because Employee with given id is not available    
	
	ASSERT_TRUE(eg1.deleteEngineer());  // Suceess  ID    
}



// Department 
TEST_F(DepartmentFixture, InsertTest) {
	ASSERT_FALSE(d1.insertDepartment()); // Fail because With given department id there is already some other department 
	ASSERT_FALSE(d2.insertDepartment());  // Fail because enterd manager is not in manager table  
	ASSERT_TRUE(d3.insertDepartment()); // Success  
	ASSERT_TRUE(d4.insertDepartment()); // Success 
}

TEST_F(DepartmentFixture, DISABLED_ViewTest) {
	ASSERT_FALSE(d1.viewDepartment());
}

TEST_F(DepartmentFixture, UpdateTest) {
	ASSERT_FALSE(d2.updateDepartment());  // Fail because manager id is not in database  
	ASSERT_FALSE(d5.updateDepartment());  // Fali beacuse department is not in table      
	ASSERT_TRUE(d3.updateDepartment());   // Success    
}

TEST_F(DepartmentFixture, DeleteTest) {
	ASSERT_FALSE(d1.deleteDepartment()); // Fail because there is employee which are working in this department 
	ASSERT_FALSE(d5.deleteDepartment()); // Fail beacuse there is no department like this id 
	ASSERT_TRUE(d3.deleteDepartment());  // Success id
	ASSERT_TRUE(d4.deleteDepartment());  // Success id
}



// Manager 
TEST_F(ManagerFixture, InsertTest) {
	ASSERT_TRUE(m2.insertManager());    // Success  
	ASSERT_TRUE(m3.insertManager());    // Success  

	ASSERT_FALSE(m1.insertManager());  // Fail because Employee is already exist     
	ASSERT_FALSE(m6.insertManager()); // Fail Beacause Department is not available   
	ASSERT_FALSE(m7.insertManager()); // Fail Beacause Manager is not available   
}

TEST_F(ManagerFixture, UpdateTest) {
	ASSERT_FALSE(m6.updateManager()); //  updated department id is not available  
	EXPECT_FALSE(m7.updateManager()); // Updated manager id is not avialable    
	EXPECT_FALSE(m8.updateManager()); // Enter Employee is not aviable      
	ASSERT_TRUE(m9.updateManager()); // Sucess
}

TEST_F(ManagerFixture, DISABLED_ViewTest) {
	EXPECT_TRUE(m1.viewManager());
}

TEST_F(ManagerFixture, DelelteTest) {
	ASSERT_FALSE(m1.deleteManager()); // Fail beacuse this is a manager of other emloyees 
	ASSERT_FALSE(m10.deleteManager()); // Fail becuse such manager is not available  

	ASSERT_TRUE(m2.deleteManager()); // Success ID
	ASSERT_TRUE(m3.deleteManager()); // Success ID

}



// Salary
TEST_F(SalaryFixture, IncrementTest) {
	double d1 = s1.getBaseSalary(); 
	s1.increment(25 , s1.getId());

	double d2 = d1 + (d1 * 0.25);
	ASSERT_DOUBLE_EQ(s1.getBaseSalary(), d2);
	ASSERT_DOUBLE_EQ(s1.getAmount() ,s1.getBaseSalary() + s1.getBonus() );
}

TEST_F(SalaryFixture, DISABLED_ViewTest) {
	ASSERT_TRUE(s1.viewSalary());
}

TEST_F(SalaryFixture, UpdateTest) {
	ASSERT_FALSE(s3.updateSalary()); // Fail beacuse Sid is not in table
	s2.updateSalary(); 
	ASSERT_DOUBLE_EQ(s2.getAmount() , s2.getBaseSalary() + s2.getBonus()); // Success base_salary  
	s4.updateSalary(); 
	ASSERT_DOUBLE_EQ(s4.getAmount() , s4.getBaseSalary() + s4.getBonus()); // Success bonus 
}



 
int main(int argv, char** argc) {
	DB::Database::getInstance().open("employee.db");  
	DB::Database::getInstance().createDefaultTables();  
	testing::InitGoogleTest(&argv, argc);
	return RUN_ALL_TESTS();
}