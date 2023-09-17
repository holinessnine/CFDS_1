#include "NewBear.h"

// Fill in here
#include <stdio.h>

                                            /*** Bear ***/
// constructor
Bear::Bear(int aWeight) {
    weight = aWeight;
}
// Accessors
void Bear::SetWeight(int aWeight) {
    weight = aWeight;
}   

// get weight
int Bear::GetWeight(void) {
    return (weight);
}

// printself
void Bear::PrintSelf(void) {
    printf("I am Bear, Weight=%d\n", weight);
}


                                        /*** 1. Polar Bear ***/
//// 1-1. constructor
Polar::Polar(int aWeight):Bear(aWeight){}

//// 1-2. aggressiveness
float Polar::aggressiveness(void) {
    return (weight);
}

//// 1-3. printself
void Polar::PrintSelf(void) {
    printf("I am Polar bear, Weight=%d, Aggressiveness=%g\n", weight, aggressiveness());
}


                                        /*** 2. Grizzly Bear ***/
//// 2-1. constructor
Grizzly::Grizzly(int aWeight):Bear(aWeight){}

//// 2-2. aggressiveness
float Grizzly::aggressiveness(void) {
    return (weight)*0.9;
}

//// 2-3. printself  
void Grizzly::PrintSelf(void) {
    printf("I am Grizzly bear, Weight=%d, Aggressiveness=%g\n", weight, aggressiveness());
}


                                        /*** 3. Black Bear ***/
//// 3-1. constructor
Black::Black(int aWeight):Bear(aWeight){}

//// 3-2. aggressiveness
float Black::aggressiveness(void) {
    return (weight)*0.7;
}

//// 3-3. printself  
void Black::PrintSelf(void) {
    printf("I am Black bear, Weight=%d, Aggressiveness=%g\n", weight, aggressiveness());
}


                                    /*** 4. Black Momma Bear ***/    
//// 4-1. constructor
Black_Momma::Black_Momma(int aWeight):Black(aWeight){}

//// 4-2. addcub
void Black_Momma::AddCub(Black *aCub) {
    cubcnt += 1;
    cubAggs += aCub->aggressiveness();
}

//// 4-3. aggressiveness
float Black_Momma::aggressiveness(void) {
    if (cubcnt >= 1)
        return (Black::aggressiveness() * 2);
    else
        return (Black::aggressiveness());
}

//// 4-4. Total aggressiveness
float Black_Momma::totalAggressiveness(void) {
    return (aggressiveness()+cubAggs);
}

//// 4-5. printself  
void Black_Momma::PrintSelf(void) {
    printf("I am Black Mommabear with %d cub(s), Weight=%d, Aggressiveness=%g, Total Aggressiveness=%g\n", cubcnt, weight, aggressiveness(), totalAggressiveness());
}