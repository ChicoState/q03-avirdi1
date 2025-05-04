/**
 * Unit Tests for the class
**/

#include <gtest/gtest.h>
#include "Guesser.h"

class GuesserTest : public ::testing::Test
{
	protected:
		GuesserTest(){} //constructor runs before each test
		virtual ~GuesserTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(GuesserTest, match_test)
{
	Guesser object("set");
	ASSERT_TRUE(object.match("set"));
}

TEST(GuesserTest, almost_match_test)
{
	Guesser object("apple");
	ASSERT_FALSE(object.match("apples"));
}

TEST(GuesserTest, remain_test)
{
	Guesser object("orange");
	object.match("oracle");
	ASSERT_EQ(2, object.remaining());
}

TEST(GuesserTest, remain_test_three)
{
	Guesser object("diamond");
	object.match("recliner");
	ASSERT_EQ(3, object.remaining());
}

TEST(GuesserTest, too_long)
{
	Guesser object("thissentenceisgoingtobelongerthanthirtytwocharacters");
	ASSERT_TRUE(object.match("thissentenceisgoingtobelongertha"));
	ASSERT_FALSE(object.match("thissentenceisgoingtobelongerthanthirtytwocharacters"));

}

TEST(GuesserTest, lock) 
{
	Guesser object("lock");
	object.match("AAAAHHHH");
	ASSERT_FALSE(object.match("lock"));
	ASSERT_EQ(3, object.remaining());
}

TEST(GuesserTest, correct_remaining)
{
	Guesser object("correct");
	object.match("coyrect");
	ASSERT_EQ(2, object.remaining());
	object.match("correct");
	ASSERT_EQ(3, object.remaining()); // remaining should reset with a correct guess so the code is incorrect
}

TEST(GuesserTest, three_close_guesses)
{
	Guesser object("triangle");
	object.match("triangre");
	object.match("traingle");
	object.match("triagnle");
	ASSERT_FALSE(object.match("triangle"));
	ASSERT_EQ(0, object.remaining());
}

