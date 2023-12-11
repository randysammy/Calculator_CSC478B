#include <gtest/gtest.h>
#include "mathengine.h"

class MathEngineTest : public testing::Test
{
protected:

    MathEngine*         mMathEnginePtr;
    Task                task;

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
   // EXPECT_EQ(mMathEnginePtr->Run(task);
}

TEST_F(MathEngineTest, Subs)
{
    //EXPECT_EQ(mMathEnginePtr->ExecuteOp(MathOp::Sub,2,3),-1);
}

TEST_F(MathEngineTest, Multiply)
{
    //EXPECT_EQ(mMathEnginePtr->ExecuteOp(MathOp::Multi,2,3),6);
}

TEST_F(MathEngineTest, Division)
{
    //EXPECT_EQ(mMathEnginePtr->ExecuteOp(MathOp::Div,4,2),2);
}

TEST_F(MathEngineTest, Sin)
{
    //EXPECT_EQ(mMathEnginePtr->ExecuteOp(MathOp::Sin,0,90),1);
}

TEST_F(MathEngineTest, Cos)
{
    //EXPECT_EQ(mMathEnginePtr->ExecuteOp(MathOp::Cos,0,180),-1);
}

TEST_F(MathEngineTest, Tan)
{
    //EXPECT_EQ(mMathEnginePtr->ExecuteOp(MathOp::Tan,0,45),1);
}

TEST_F(MathEngineTest, ASin)
{
    //EXPECT_EQ(mMathEnginePtr->ExecuteOp(MathOp::Asin,0,0),0);
}

TEST_F(MathEngineTest, ACos)
{
    //EXPECT_EQ(mMathEnginePtr->ExecuteOp(MathOp::Acos,0,0),90);
}

TEST_F(MathEngineTest, ATan)
{
    //EXPECT_EQ(mMathEnginePtr->ExecuteOp(MathOp::Atan,0,0),0);
}

