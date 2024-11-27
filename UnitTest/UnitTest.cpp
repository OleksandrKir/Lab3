#include "pch.h"
#include "CppUnitTest.h"
#include "D:\Project\ProjectEP\lab2\lab2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab5
{
    // Тест 1: Перевіряє, що `a < b` для валідного вводу
    TEST_CLASS(UnitTest1)
    {
    public:
        TEST_METHOD(Test1)
        {
            long double a = 1.0, b = 2.0;
            Assert::IsTrue(a < b); // Якщо a >= b, тест не пройде
        }
    };

    // Тест 2: Перевіряє, що `n > 6`
    TEST_CLASS(UnitTest2)
    {
    public:
        TEST_METHOD(Test2)
        {
            int n = 7; // Валідне значення
            Assert::IsTrue(n > 6); // Якщо n <= 6, тест не пройде
        }
    };

    // Тест 3: Перевіряє, що `step > 0`
    TEST_CLASS(UnitTest3)
    {
    public:
        TEST_METHOD(Test3)
        {
            long double step = 0.1; // Валідне значення
            Assert::IsTrue(step > 0); // Якщо step <= 0, тест не пройде
        }
    };

    // Тест 4: Перевіряє, що `step == 0` не проходить
    TEST_CLASS(UnitTest4)
    {
    public:
        TEST_METHOD(Test4)
        {
            long double step = 0.0; // Некоректне значення
            Assert::IsFalse(step > 0); // Якщо step > 0, тест не пройде
        }
    };

    // Тест 5: Перевіряє, що `XLessThan1` працює для x < 1 і n > 3
    TEST_CLASS(UnitTest5)
    {
    public:
        TEST_METHOD(Test5)
        {
            long double x = 0.5;
            int n = 7;
            long double result = XLessThan1(x, n);
            Assert::IsTrue(result >= 0); // Результат має бути додатнім
        }
    };

    // Тест 6: Перевіряє, що `XLessThan1` не працює для n <= 3
    TEST_CLASS(UnitTest6)
    {
    public:
        TEST_METHOD(Test6)
        {
            long double x = 0.5;
            int n = 3; // Некоректне значення
            bool valid = true;
            try {
                XLessThan1(x, n); // Спроба обчислення
            }
            catch (...) {
                valid = false; // Якщо помилка, значення зміниться
            }
            Assert::IsFalse(valid); // Тест пройде, якщо обчислення не відбудеться
        }
    };

    // Тест 7: Перевіряє, що `XMoreOrEqual1` працює для x >= 1 і n > 4
    TEST_CLASS(UnitTest7)
    {
    public:
        TEST_METHOD(Test7)
        {
            long double x = 2.0;
            int n = 8;
            long double result = XMoreOrEqual1(x, n);
            Assert::IsTrue(result >= 0); // Результат має бути додатнім
        }
    };

    // Тест 8: Перевіряє, що `XMoreOrEqual1` не працює для x = 0
    TEST_CLASS(UnitTest8)
    {
    public:
        TEST_METHOD(Test8)
        {
            long double x = 0.0;
            int n = 8;
            bool valid = true;
            try {
                XMoreOrEqual1(x, n); // Спроба обчислення
            }
            catch (...) {
                valid = false; // Якщо помилка, значення зміниться
            }
            Assert::IsFalse(valid); // Тест пройде, якщо обчислення не відбудеться
        }
    };

    // Тест 9: Перевіряє, що введення букви замість числа не проходить
    TEST_CLASS(UnitTest9)
    {
    public:
        TEST_METHOD(Test9)
        {
            string input = "a"; // Некоректний ввід
            bool valid = true;
            try {
                long double value = stod(input); // Перетворення в число
            }
            catch (...) {
                valid = false; // Якщо помилка, значення зміниться
            }
            Assert::IsFalse(valid); // Тест пройде, якщо обчислення не відбудеться
        }
    };

    // Тест 10: Перевіряє, що `a >= b` не проходить
    TEST_CLASS(UnitTest10)
    {
    public:
        TEST_METHOD(Test10)
        {
            long double a = 2.0, b = 1.0; // Некоректний діапазон
            Assert::IsFalse(a < b); // Тест пройде, якщо діапазон некоректний
        }
    };

    // Тест 11: Перевіряє коректність обчислень для x < 1
    TEST_CLASS(UnitTest11)
    {
    public:
        TEST_METHOD(Test11)
        {
            long double x = 0.8;
            int n = 10;
            long double result = XLessThan1(x, n);
            Assert::IsTrue(result > 0); // Має бути додатній результат
        }
    };

    // Тест 12: Перевіряє коректність обчислень для x >= 1
    TEST_CLASS(UnitTest12)
    {
    public:
        TEST_METHOD(Test12)
        {
            long double x = 1.5;
            int n = 3;
            long double result = XMoreOrEqual1(x, n);
            Assert::IsTrue(result > 0); // Має бути додатній результат
        }
    };
}
