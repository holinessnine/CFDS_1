#pragma once

/***  Class Bear ***/
class Bear {
public:
	Bear (int aWeight); // Constructor

	int GetWeight(void); // accessors
	void SetWeight(int aWeight); // set Weight

	virtual void PrintSelf(void); // print info

protected:
	int weight;
};

/*** Class Polar bear ***/
class Polar : public Bear {
	public:
	Polar(int aWeight); // constructor
	float aggressiveness(void); // calculate aggressiveness
	void PrintSelf(void); // print info
};

/*** Class Grizzly bear ***/
class Grizzly : public Bear{
	public:
	Grizzly(int aWeight); // constructor
	float aggressiveness(void); // calculate aggressiveness
	void PrintSelf(void); // print info
};

/*** Class Black bear ***/
class Black : public Bear {
	public:
	Black(int aWeight); // constructor
	float aggressiveness(void); // calculate aggressiveness
	void PrintSelf(void); // print info
};

/*** Class Black - Momma bear ***/
class Black_Momma : public Black {
	public:
	Black_Momma(int aWeight); // constructor
	
	void AddCub(Black *aCub); // add cub into momma

	float aggressiveness(void); // calculate aggressiveness
	float totalAggressiveness(void); // calculate total aggressiveness
	
	void PrintSelf(void); // print info

	protected:
	Bear *cub;
	
	int cubcnt = 0; // total count of cubs
	int cubAggs = 0; // total aggressiveness of cubs
};

