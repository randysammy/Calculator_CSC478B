#include <gtest/gtest.h>

#include "mathengine.h"

class MathEngineTest : public testing::Test
{
protected:

    MathEngine*         mMathEnginePtr;

    void SetUp() override
    {
        mMathEnginePtr = new MathEngine();
    }

    void TearDown() override
    {
      delete mMathEnginePtr;
    }
};

TEST_F(MathEngineTest, Addition)
{
    EXPECT_EQ(mMathEnginePtr->ExecuteOp(MathOp::Add,2,3),5);
}

TEST_F(MathEngineTest, Subs)
{
    EXPECT_EQ(mMathEnginePtr->ExecuteOp(MathOp::Sub,2,3),-1);
}

TEST_F(MathEngineTest, Multiply)
{
    EXPECT_EQ(mMathEnginePtr->ExecuteOp(MathOp::Multi,2,3),6);
}

TEST_F(MathEngineTest, Division)
{
    EXPECT_EQ(mMathEnginePtr->ExecuteOp(MathOp::Div,4,2),2);
}


