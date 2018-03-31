#include <string>
#include <iostream>
#include "superhero.h"

class SuperheroMain{

public:
	Superhero::getPage_id(int page_id){
		return page_id;
}
	Superhero::setPage_id(){
		page_id= this.page_id;
}
	Superhero::getName(string name){
		return name;
}
	Superhero::setName(){
		name = this.name;
}
	Superhero::getUrlslug(string urlslug){
		return urlslug;
}
	Superhero::setUrlslug(){
		urlslug = this.urlslug;
}
	Superhero::getId(string id){
		return id
}
	Superhero::setId(){
		id = this.id;
}
	Superhero::getAlignment(string alignment){
		return alignment;
}
	Superhero::setAlignment(){
		alignment = this.alignment;
}
	Superhero::getEye_color(char eye_color){
		return eye_color;
}
	Superhero::setEye_color(){
		eye_color = this.eye_color;
}
	Superhero::getHair_color(char hair_color){
		return hair_color();
}
	Superhero::setHair_color(){
		hair_color = this.hair_color;
}
	Superhero::getSex(char sex){
		return sex;
}
	Superhero::setSex(){
		sex = this.sex;
}
	Superhero::getGsm(string gsm){
		return gsm;
}
	Superhero::setGsm(){
		gsm = this.gsm;
}
	Superhero::getAlive(bool alive){
		if(alive == true){
			return true;
		}
		else{
			return false;
		}
}
	Superhero::setAlive(){
		alive = this.alive;
}
	Superhero::getAppearances(int appearances){
		return appearances;
	}
	Superhero::setAppearances(){
		appearances = this.appearances;
}
	Superhero::getFirst_appearance(string first_appearance){
		return first_appearance;
	}
	Superhero::setFirst_appearance(){
		first_appearance = this.first_appearance;
}
	Superhero::getYear(int year){
		return year;
}
	Superhero::setYear(){
		year = this.year;
}
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
	
