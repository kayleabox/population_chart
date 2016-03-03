// this program will read population numbers from a file and 
//use them to display a verticle bar chart


#include <iostream>
#include <limits>
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;


int main()
{
    
    string infile_name = "people.txt";
    cout<<"this program will read the population data from file, "<<infile_name<<".";
 	cout<<"and display the data through a bar chart.\n";
	cout<<"each star in the bar represents 1000 people.\n";
	
	ifstream inFile;
	inFile.open(infile_name);
	
	const int TOTAL = 20;
    int population_num[TOTAL];
	int popcount = 0;
	int year = 1900;
	
	if (inFile) 
	{
		cout << "open of "<<infile_name<< " was successful.\n\n\n";
    
	    while (!inFile.eof()) 
		{
	
	    	//cout << "the population in "<<year<<" was " << population<< ".\n";
	    	//cout << year<<"\t"; test the file input
	    	for (int count = 0; count < TOTAL; ++count)
	    	{
				inFile >> population_num[count]; 
	
				if (inFile.eof()) break;
	    		//cout<<"pop = "<< population_num[count]; test the file input
	    		++popcount;
	    		year+=20;
	    		if (year > 2140) break;
	    	}
	    	
	
	    inFile.close();
		//cout << endl << popcount << " population numbers were found in the file.\n\n";
	  	}
	}
	else 
	{
    	cout << "Sorry, but file: "<<infile_name<<" did not open for input\n";
    	exit;
  	}

	    int largest_number = population_num[0];
	    
	    //cout<<"largest_num= "<<largest_number; //used this to test the largest number
	    	             
	    //get the highest number to control the number of rows
	    for (int get_highest = 0;get_highest < popcount;get_highest++)
		{
		    if(population_num[get_highest]>largest_number)
	        	largest_number = population_num[get_highest];
	        	//cout<<"largest = "<<largest_number<<endl; //used this to check the new largest number
	    }
	    
	    cout<<"\t\t\tPOPULATION CHART\n";
		cout<<"\tPopulation\n";
	    for (int rows = largest_number/1000; rows >= 1; --rows)
		{
			cout<<"\t"<<rows*1000;
			//cout<<"rows= "<<rows<<endl; //test the number of rows
			for (int col = 0; col < popcount; ++col)
	    	{
	    		
				if (population_num[col]/1000 >= rows)
				{
					//cout<<"col "<<col;//test columns
					//cout<<"population = "<<population_num[col];// test population
					cout<<"\t**";
				}
				else
					cout<<"\t  ";
	 		}
			cout<<endl;
		}
		cout<<"\tyear   ";
		for(int y = 1900; y < year; y += 20)
			cout<<y<<"    ";
		cout<<endl;   
	
   	
return 0;	
}

/*this program will read the population data from file, people.txt,and display the data through a bar chart.
each star in the bar represents 1000 people.
open of people.txt was successful.
                        POPULATION CHART
        Population
        25000                                                           **
        24000                                                           **
        23000                                                           **
        22000                                                           **
        21000                                                   **      **
        20000                                                   **      **
        19000                                                   **      **
        18000                                           **      **      **
        17000                                           **      **      **
        16000                                           **      **      **
        15000                                           **      **      **
        14000                                   **      **      **      **
        13000                                   **      **      **      **
        12000                                   **      **      **      **
        11000                                   **      **      **      **
        10000                                   **      **      **      **
        9000                            **      **      **      **      **
        8000                            **      **      **      **      **
        7000                            **      **      **      **      **
        6000                            **      **      **      **      **
        5000                    **      **      **      **      **      **
        4000            **      **      **      **      **      **      **
        3000            **      **      **      **      **      **      **
        2000    **      **      **      **      **      **      **      **
        1000    **      **      **      **      **      **      **      **
        year   1900    1920    1940    1960    1980    2000    2020    2040

8 population numbers were found in the file.


--------------------------------
Process exited after 0.06387 seconds with return value 0
Press any key to continue . . .

test with decreasing population:

this program will read the population data from file, people.txt,and display the data through a bar chart.
each star in the bar represents 1000 people.
open of TT13_L5_Box_People.txt was successful.
                        POPULATION CHART
        Population
        21000                                                   **
        20000                                                   **
        19000                                                   **
        18000                                           **      **
        17000                                           **      **
        16000                                           **      **
        15000                                           **      **
        14000                                           **      **
        13000                                           **      **
        12000                                           **      **
        11000                                           **      **
        10000                                           **      **
        9000                            **              **      **
        8000                            **              **      **
        7000                            **              **      **
        6000                            **      **      **      **
        5000                    **      **      **      **      **
        4000            **      **      **      **      **      **
        3000            **      **      **      **      **      **      **
        2000    **      **      **      **      **      **      **      **
        1000    **      **      **      **      **      **      **      **
        year   1900    1920    1940    1960    1980    2000    2020    2040

8 population numbers were found in the file.


--------------------------------
Process exited after 0.07617 seconds with return value 0
Press any key to continue . . .*/
