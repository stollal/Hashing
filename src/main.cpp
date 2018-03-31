#include<iostream>
#include<fstream>
#include "my_hash.h"
#include<string>
#include "superhero.h"
#include<sstream>
#include<iterator>

template <class T>
/*
 *Class creation to input the file it is a template that can read strings,ints, doubles, etc.
 *
 * went to stack overflow for direction with this code
 *https://stackoverflow.com/questions/how-to-read-a-csv-file-data-into-an-array
 */
class csv_istream_iterator: public iterator<input_iterator_tag, T>{
	std::istream* _input;
	std::char _delim;
	std::string _value;
public:
	//read in file and accepts ',' delimiter
	csv_istream_iterator(char delim= ','): _input( 0 ), _delim( delim ) {}
	csv_istream_iterator( istream & in, char delim = ','): _input(&in), _delim( delim )
	//this takes in the value
	const T operator *() const {
		istringstream ss(_value);
		T value;
		ss >> value;
		return value;
	}
	//iterates through the input, values, and delimiters
	istream & operator ++(){
		if(!(getline(*_input, _value, _delim))){
			input = 0;
		}
		return *_input;
	}
	//checks to make sure input and input rhs are not equal
	bool operator != ( const csv_istream_iterator & rhs)const{
		return _input != rhs._input;
	}
	//template for the instream iterator 
	template<>
	const string csv_istream_iterator<string>::operator *() const{
		return _value;
	}
	//tests the file for integers and strings and print collisions
	int main(int argc, char * args[]){
		{
		//test for integers
		ifstream fin("Superhero Database.csv");
		if( fin ){
			copy( csv_istream_iterator<int>( fin ),
				csv_istream_iterator<int>(),
				ostream_iterator<int>( cout, " "));
			fin.close();
		}
	}
	std::cout << endl << "----" << std::endl;
	{
		//test for strings
		ifstream fin( "Superhero Database.csv");
		if( fin ){
			copy( csv_istream_iterator<string>( fin ),
				csv_istream_iterator<string>(),
				ostream_iterator<string>( cout, "|"));
			fin.close();
		}
	}
	return 0;
	

	int count = 0;
	int collisions = 0;
	fstream input( fin );
	string x;
	
	//file stream
	while(!input.eof()){
		input>>x;
		array[count] = hashcode(x);
		for(int i = 0; i<count; i++){
			if (array[i] == array[count]){
				collisions++;
				
				break;
			}
		}
		count++;
		}
		std::cout<<"Total input is " <<count-1<<std::endl;
		std::cout<<"Collision # is "<<collisions<<std::endl;
}
}
}
};
	

