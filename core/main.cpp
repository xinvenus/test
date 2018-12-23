#include <gtest/gtest.h>//引入gtest库
int main(int argc, char* argv[])
{
    testing::InitGoogleTest(&argc, argv);
    int a = RUN_ALL_TESTS();
    //Start();

    system("pause");
    return 0;
}
