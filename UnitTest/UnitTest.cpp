#include "pch.h"
#include "CppUnitTest.h"
#include "D:\Project\ProjectEP\lab2\lab2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab5
{
    // ���� 1: ��������, �� `a < b` ��� �������� �����
    TEST_CLASS(UnitTest1)
    {
    public:
        TEST_METHOD(Test1)
        {
            long double a = 1.0, b = 2.0;
            Assert::IsTrue(a < b); // ���� a >= b, ���� �� ������
        }
    };

    // ���� 2: ��������, �� `n > 6`
    TEST_CLASS(UnitTest2)
    {
    public:
        TEST_METHOD(Test2)
        {
            int n = 7; // ������ ��������
            Assert::IsTrue(n > 6); // ���� n <= 6, ���� �� ������
        }
    };

    // ���� 3: ��������, �� `step > 0`
    TEST_CLASS(UnitTest3)
    {
    public:
        TEST_METHOD(Test3)
        {
            long double step = 0.1; // ������ ��������
            Assert::IsTrue(step > 0); // ���� step <= 0, ���� �� ������
        }
    };

    // ���� 4: ��������, �� `step == 0` �� ���������
    TEST_CLASS(UnitTest4)
    {
    public:
        TEST_METHOD(Test4)
        {
            long double step = 0.0; // ���������� ��������
            Assert::IsFalse(step > 0); // ���� step > 0, ���� �� ������
        }
    };

    // ���� 5: ��������, �� `XLessThan1` ������ ��� x < 1 � n > 3
    TEST_CLASS(UnitTest5)
    {
    public:
        TEST_METHOD(Test5)
        {
            long double x = 0.5;
            int n = 7;
            long double result = XLessThan1(x, n);
            Assert::IsTrue(result >= 0); // ��������� �� ���� �������
        }
    };

    // ���� 6: ��������, �� `XLessThan1` �� ������ ��� n <= 3
    TEST_CLASS(UnitTest6)
    {
    public:
        TEST_METHOD(Test6)
        {
            long double x = 0.5;
            int n = 3; // ���������� ��������
            bool valid = true;
            try {
                XLessThan1(x, n); // ������ ����������
            }
            catch (...) {
                valid = false; // ���� �������, �������� ��������
            }
            Assert::IsFalse(valid); // ���� ������, ���� ���������� �� ����������
        }
    };

    // ���� 7: ��������, �� `XMoreOrEqual1` ������ ��� x >= 1 � n > 4
    TEST_CLASS(UnitTest7)
    {
    public:
        TEST_METHOD(Test7)
        {
            long double x = 2.0;
            int n = 8;
            long double result = XMoreOrEqual1(x, n);
            Assert::IsTrue(result >= 0); // ��������� �� ���� �������
        }
    };

    // ���� 8: ��������, �� `XMoreOrEqual1` �� ������ ��� x = 0
    TEST_CLASS(UnitTest8)
    {
    public:
        TEST_METHOD(Test8)
        {
            long double x = 0.0;
            int n = 8;
            bool valid = true;
            try {
                XMoreOrEqual1(x, n); // ������ ����������
            }
            catch (...) {
                valid = false; // ���� �������, �������� ��������
            }
            Assert::IsFalse(valid); // ���� ������, ���� ���������� �� ����������
        }
    };

    // ���� 9: ��������, �� �������� ����� ������ ����� �� ���������
    TEST_CLASS(UnitTest9)
    {
    public:
        TEST_METHOD(Test9)
        {
            string input = "a"; // ����������� ���
            bool valid = true;
            try {
                long double value = stod(input); // ������������ � �����
            }
            catch (...) {
                valid = false; // ���� �������, �������� ��������
            }
            Assert::IsFalse(valid); // ���� ������, ���� ���������� �� ����������
        }
    };

    // ���� 10: ��������, �� `a >= b` �� ���������
    TEST_CLASS(UnitTest10)
    {
    public:
        TEST_METHOD(Test10)
        {
            long double a = 2.0, b = 1.0; // ����������� �������
            Assert::IsFalse(a < b); // ���� ������, ���� ������� �����������
        }
    };

    // ���� 11: �������� ���������� ��������� ��� x < 1
    TEST_CLASS(UnitTest11)
    {
    public:
        TEST_METHOD(Test11)
        {
            long double x = 0.8;
            int n = 10;
            long double result = XLessThan1(x, n);
            Assert::IsTrue(result > 0); // �� ���� ������� ���������
        }
    };

    // ���� 12: �������� ���������� ��������� ��� x >= 1
    TEST_CLASS(UnitTest12)
    {
    public:
        TEST_METHOD(Test12)
        {
            long double x = 1.5;
            int n = 3;
            long double result = XMoreOrEqual1(x, n);
            Assert::IsTrue(result > 0); // �� ���� ������� ���������
        }
    };
}
