// qm01.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "QbitState.h"
#include "QbitDm.h"

static void f_test02()
{
	std::cout << "\n" << __FUNCTION__ << std::endl;
	const udr::scalar_t sqrtm2 = 1.0 / std::sqrt(2.0);
	const udr::scalar_t half = 0.5;

	udr::QbitDm dm0;

	udr::QbitState qb1(sqrtm2, (-1.0)*sqrtm2);
	udr::QbitDm dm1(qb1);

	udr::QbitState qb2(1.0, 0.0);
	udr::QbitDm dm2(qb2);
	udr::QbitDm dm3 = (dm1 * half) + (dm2 * half);

	std::cout << "dm0: " << dm0.to_string() << std::endl;
	std::cout << "qb1: " << qb1.to_string() << std::endl;
	std::cout << "dm1: " << dm1.to_string() << std::endl;
	std::cout << "dm2: " << dm2.to_string() << std::endl;
	std::cout << "dm3: " << dm3.to_string() << std::endl;

	std::cout << "dm0: valid=" << dm0.isValid() << " pure=" << dm0.isPureState() << std::endl;
	std::cout << "dm1: valid=" << dm1.isValid() << " pure=" << dm1.isPureState() << std::endl;
	std::cout << "dm3: valid=" << dm3.isValid() << " pure=" << dm3.isPureState() << std::endl;

}

static void f_test01()
{
	std::cout << "\n" << __FUNCTION__ << std::endl;
	const udr::scalar_t sqrtm2 = 1.0 / std::sqrt(2.0);
	udr::QbitState qb1(1.0, 0.0);
	udr::QbitState qb2(sqrtm2, (-1.0)*sqrtm2);
	udr::QbitState qb3(qb1 + qb2);

	std::cout << "Qbit1: " << qb1.to_string() << std::endl;
	std::cout << "Qbit2: " << qb2.to_string() << std::endl;
	std::cout << "Qbit3: " << qb3.to_string() << std::endl;
}

int main()
{
	f_test01();
	f_test02();

    return 0;
}

