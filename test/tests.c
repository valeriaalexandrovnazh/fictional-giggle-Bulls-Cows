#include "ctest.h"
#include "../src/BullsLib.h"



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
