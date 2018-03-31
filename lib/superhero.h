#include <string>
#include <iostream>

#ifndef __SUPERHERO_H___
#define __SUPERHERO_H__

class Superhero{

public:
	int getPage_id();
	int setPage_id();
	std::string getName();
	std::string setName();
	std::string getUrlslug();
	std::string setUrlslug();
	std::string getAlignment();
	std::string setAlignment();
	char getEye_color();
	char setEyecolor();
	char getHair_color();
	char setHair_color();
	char getSex();
	char setSex();
	std::string getGsm();
	std::string setGsm();
	bool setAlive();
	bool getAlive();
	int getAppearances();
	int setAppearances();
	std::string getFirst_appearance();
	std::string setFirst_appearance();
	int getYear();
	int setYear();

private:
	int page_id;
	std::string name;
	std::string urlslug;
	std::string id;
	std::string alignment;
	char eye_color;
	char hair_color;
	char sex;
	std::string gsm;
	bool alive;
	int appearances;
	std::string first_appearance;
	int year;
};
#endif
