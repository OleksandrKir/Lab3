#include "pch.h"
#include "CppUnitTest.h"
#include "D:\Project\ProjectEP\lab2\lab2.cpp" 

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
    TEST_CLASS(Validation_Tests)
    {
    public:
        TEST_METHOD(validateB_get3and1_noExceptionThrown)
        {
            double a = 1.0, b = 3.0;
            try {
                validateB(b, a);
                Assert::IsTrue(true);
            }
            catch (...) {
                Assert::Fail();
            }
        }

        TEST_METHOD(validateB_get1and3_exceptionThrown)
        {
            double a = 3.0, b = 1.0;
            try {
                validateB(b, a);
                Assert::Fail();
            }
            catch (...) {
                Assert::IsTrue(true);
            }
        }

        TEST_METHOD(validateStep_get1_noExceptionThrown)
        {
            double step = 1.0;
            try {
                validateStep(step);
                Assert::IsTrue(true);
            }
            catch (...) {
                Assert::Fail();
            }
        }

        TEST_METHOD(validateStep_get0_exceptionThrown)
        {
            double step = 0.0;
            try {
                validateStep(step);
                Assert::Fail();
            }
            catch (...) {
                Assert::IsTrue(true);
            }
        }

        TEST_METHOD(validateN_get7_noExceptionThrown)
        {
            int n = 7;
            try {
                validateN(n);
                Assert::IsTrue(true);
            }
            catch (...) {
                Assert::Fail();
            }
        }

        TEST_METHOD(validateN_get4_exceptionThrown)
        {
            int n = 4;
            try {
                validateN(n);
                Assert::Fail();
            }
            catch (...) {
                Assert::IsTrue(true);
            }
        }
    };

    TEST_CLASS(Calculate_Tests)
    {
    public:
        TEST_METHOD(XLessThan1_CorrectInput_NoException)
        {
            int n = 7;
            double x = -1.0; 
            double expected = -0.04167;
            double actual = XLessThan1(x, n); 
            double delta = 0.00001; 
            Assert::IsTrue(abs(expected - actual) < delta);
        }

        TEST_METHOD(XLessThan1_InvalidInput_ExceptionThrown)
        {
            int n = 3; 
            double x = -1.0;
            try {
                XLessThan1(x, n); 
                Assert::Fail(); 
            }
            catch (const std::invalid_argument&) {
                Assert::IsTrue(true); 
            }
        }

        TEST_METHOD(XMoreOrEqual1_CorrectInput_NoException)
        {
            int n = 7;
            double x = 1.5; 
            double expected = 8343170.79496;
            double actual = XMoreOrEqual1(x, n); 
            double delta = 0.00001; 
            Assert::IsTrue(abs(expected - actual) < delta);
        }

        TEST_METHOD(XMoreOrEqual1_InvalidInput_ExceptionThrown)
        {
            int n = 3; 
            double x = 1.5; 
            try {
                XMoreOrEqual1(x, n);
                Assert::Fail(); 
            }
            catch (const std::invalid_argument&) {
                Assert::IsTrue(true); 
            }
        }
    };
}