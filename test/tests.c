#include "ctest.h"
#include "../src/BullsLib.h"
CTEST(BullsLib, ReadAnswer)
{
    // Given	
        int guess[] = {0,0,0,0};
    	char answer1[] = "1234";
	char answer2[] = "98765";
	char answer3[] = "456";
	char answer4[] = "bull";
	char answer5[] = "123,5";
	char answer6[] = "12,5";
	char answer7[] = "1234ht";
	char answer8[] = "1.098";
 // Then
    	int guess1[] = {1,2,3,4};
    	int guess2[] = {-1,0,0,0};
    	int guess3[] = {-2,0,0,0};
    	int guess4[] = {-3,0,0,0};
    ASSERT_DATA(guess1,4, ReadAnswer(guess, answer1),4);
    ASSERT_DATA(guess4,4, ReadAnswer(guess, answer2),4);
    ASSERT_DATA(guess2,4, ReadAnswer(guess, answer3),4);
    ASSERT_DATA(guess3,4, ReadAnswer(guess, answer4),4);
}
CTEST(BullsLib, CheckBullsCows)
{
    // Given
    	int bullscows[] = {0,0};
    
    	int made[] = {1,2,3,4};

    	int guess1[] = {1,2,3,4};
    	int guess2[] = {0,2,7,8};
    	int guess3[] = {4,3,2,1};
    
    // Then
    	int expectedbullscows1[] = {4,0};
	int expectedbullscows2[] = {1,0};
	int expectedbullscows3[] = {0,4};
    ASSERT_DATA(expectedbullscows1,2, CheckBullsCows(bullscows, guess1, made),2);
    ASSERT_DATA(expectedbullscows2,2, CheckBullsCows(bullscows, guess2, made),2);
    ASSERT_DATA(expectedbullscows3,2, CheckBullsCows(bullscows, guess3, made),2);

}
