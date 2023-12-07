#include "gtest/gtest.h"
#include "mathengine.h"

int main(int argc, char **argv)
    {
    MathEngine* p = new MathEngine();
        ::testing::InitGoogleTest(&argc, argv);
        return RUN_ALL_TESTS();

    }
