// Nuclear decay
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <ctime>
#include <unistd.h>
#include <cstdlib>
#include <time.h> 

#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */


//**********************************************************************************
// main function
//**********************************************************************************
int main( int argc, const char* argv[] ) 
{

	std::cout << std::endl ;
	std::cout << BOLDYELLOW << "    _________________________________________________" << std::endl ;
	std::cout << BOLDYELLOW << "            _=_                                      " << RESET << std::endl ;
	std::cout << BOLDYELLOW << "          q(-_-)p                                    " << RESET << std::endl ;
	std::cout << BOLDYELLOW << "          '_) (_`         Nuclear Decay              " << RESET << std::endl ;
	std::cout << BOLDYELLOW << "          /__/  \\         Carles Triguero 2019      " << RESET << std::endl ;
	std::cout << BOLDYELLOW << "        _(<_   / )_                                  " << RESET << std::endl ;
	std::cout << BOLDYELLOW << "       (__\\_\\_|_/__)                               " << RESET << std::endl ;
	std::cout << BOLDYELLOW << "    _________________________________________________" << RESET << std::endl ;
	std::cout << std::endl ;
	
	
	// Default values
	//------------------------------------
    int Inverse_probability =50;
    int Realization=10000000;
    //------------------------------------
	
	
	int r;
	int count_time=0;
	
	

	// Count execution time
	int start_s=clock();
	
		
 	std::ofstream Unstable_Time;
	Unstable_Time.open ("UNucleus_Time.dat", std::ios::out | std::ios::trunc);
	Unstable_Time << "#! Phase avalanche size distribution:" << std::endl;
 	Unstable_Time << "#! Size		Frequency" << std::endl;


 	std::ofstream Duration_realizations;
 	Duration_realizations.open ("Duration.dat", std::ios::out | std::ios::trunc);
 	
 	
 	srand(time(0));  // Initialize random number generator.
 	
 	// Begin Realization loop
 	
 	
 	int Random_event;

 	

    for(r=0; r < Realization; r++ )
	{
		count_time=0;
		
		std::cout << std::endl;
		std::cout << "    Realization="<< r+1 << std::endl;

        Random_event = 2;
	    while( Random_event != 1 )
	    {	
		    // generating random in the domain [1,6] (Piles are stable yet, spin <= 4)  (http://www.cplusplus.com/reference/cstdlib/rand/)
		    Random_event = rand() % Inverse_probability +1;
            // std::cout << "R=" << Random_event << std::endl;
		
		    count_time++;
	
    		Unstable_Time << count_time << "  " << std::endl;
	    }

        std::cout << BOLDYELLOW << "    Decay duration: " << BOLDWHITE << count_time << WHITE << " time units" << std::endl;
	
    	Duration_realizations << count_time << std::endl;

	    std::cout << std::endl;		

	
	    Unstable_Time.close();

    }
	// Count execution time
	int stop_s=clock();
 	//cout << std::endl;
 	//cout << "  Number of avalanches: \033[1m" << Avalanche_number << "\033[0m" << std::endl;
    
    std::cout << BOLDYELLOW << "    Execution time: " << BOLDWHITE << (stop_s-start_s)/double(CLOCKS_PER_SEC) << WHITE << " seconds" << std::endl;
    std::cout << std::endl ;
    std::cout << std::endl ;
    //cout << std::endl;
}