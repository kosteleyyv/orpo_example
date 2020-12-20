#include <gtest/gtest.h>

/*!
 * \brief Возвращает сумму элементов, если a>b. Если a равно b, возвращает значение a.  Иначе, b.
 * \author I
 * \version 1.1
 * \see main
 * \warning это пример, а не настоящая функция
 * \attention это точно пример, а не настоящая фунция
 * \todo можно добавить еще фунцию
 * \param[in] a Первый параметр
 * \param[in] b Второй параметр
 * \return результат
 * \bug
 * \code
 *  int a=3;
    int b=2;
    int actual=calcSum(a,b);
 * \endcode
 */
int calcSum(int a,int b)
{
    if(a>b)
    {
        return a+b;
    }
   else
    {
        if(a==b)
        {
            return a;
        }
    }
    return b;
}

//TEST
//a=2, b=2, expected=2
//a=2, b=3, expected=3
//a=3, b=2, expected 5

TEST ( test001, a_equal_b)
{

    int a=2;
    int b=2;

    int actual=calcSum(a,b);
    int expected=2;


    ASSERT_EQ(actual, expected );

}

TEST ( test002, a_less_b)
{

    int a=2;
    int b=3;

    int actual=calcSum(a,b);
    int expected=3;


    ASSERT_EQ(actual, expected );

}

TEST ( test003, a_more_b)
{

    int a=3;
    int b=2;

    int actual=calcSum(a,b);
    int expected=5;


    ASSERT_EQ(actual, expected );

}
/*!
 * \brief main Точка входа в приложение
 * \param argc число аргументов командной строки
 * \param argv аргументы командной строки
 * \return код завершения
 */
int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc,argv);

    return RUN_ALL_TESTS();
}
