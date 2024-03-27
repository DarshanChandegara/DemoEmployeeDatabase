#pragma once
#include "include/Model/Salary.h"
#include "gtest/gtest.h"

class SalaryFixture : public testing::Test {
protected:

	void SetUp() {

		// Uncomment for UpdateTest
		s3.setId(510);
		s2.setId(502);
		s2.setBaseSalary(700000);
		s4.setId(503);
		s4.setBonus(50000);
		
	}

	void TearDown() {

	}

	Model::Salary s1{2 , 600000 , 500000 , 100000};
	Model::Salary s2 = s1;
	Model::Salary s3 = s1;
	Model::Salary s4 = s1;
};