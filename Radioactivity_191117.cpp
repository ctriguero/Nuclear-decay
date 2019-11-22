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
	

// Check the number of arguments (1 means only the name of the program => No argument)
	if ( argc == 1 )
	{
	
		std::cout << std::endl ;
		std::cout << BOLDYELLOW << "    No specific values entered:" << RESET << std::endl ;
		std::cout << YELLOW << "    Taking default values: 100 unstable nuclei with decay probability 1/6" << RESET << std::endl ;
		std::cout << YELLOW << "    To set specific values:" << RESET << std::endl ;
		std::cout << BOLDRED << "\t " << argv[0] << " -n [Number of unstable nuclei] -p [Probability per unit of time 1/p]" << RESET << std::endl ;
		std::cout << " " << std::endl ;
		//return (0) ;
	}
	
	
	// Default values
	//------------------------------------
    unsigned Number_Unstable_Nucleus=100;
    unsigned Inverse_probability =6;
    //------------------------------------
	
	
	for ( int k = 1; k < argc ; ++k )
	{
		if ( ( argv[k] == std::string("-h") ) || ( argv[k] == std::string("-HELP") ) || ( argv[k] == std::string("-H") ) || ( argv[k] == std::string("-help") ) )
		{ 
			std::cout  << BOLDBLACK << "    HELP:" << RESET << std::endl ;
			std::cout << "    Generates a random decay time sequence for n unstable nuclei with decay probability 1/p" << std::endl ;
			std::cout << std::endl ;
			std::cout << "    ----------------------------------------------------------------------------------------" << std::endl ;
			std::cout << BOLDBLACK << "    Execution: ./a.out [+flags]" << RESET << std::endl ; 
			std::cout << BOLDBLACK << "    Number of nuclei flag:" << RESET << std::endl ; 
			std::cout << "    -n" << "\t" << "    to set the number of unstable nuclei (default value of nuclei n=100)" << std::endl ;
			std::cout << BOLDBLACK << "    Probability flag:" << RESET << std::endl ;
			std::cout << "    -p" << "\t" << "    to set the probability per unit of time  (default value 6)" << std::endl ; 
			std::cout << std::endl ;
			return (0) ;
		}
		if ( ( argv[k] == std::string("-n") ) || ( argv[k] == std::string("-N") ) ) { Number_Unstable_Nucleus = atoi(argv[k+1]) ; }
		if ( ( argv[k] == std::string("-p") ) || ( argv[k] == std::string("-P") ) ) { Inverse_probability = atoi(argv[k+1]) ; }
	}
	
	// Initial information:
	std::cout << std::endl ;
	std::cout << YELLOW << "    Initial unstable nuclei: " << BOLDWHITE << Number_Unstable_Nucleus << RESET << std::endl;
	std::cout << YELLOW << "    Inverse probability (1/p): " << BOLDWHITE << Inverse_probability << RESET << std::endl;
	std::cout << std::endl ;

	unsigned Number_Stable_Nucleus=0;
	unsigned i;
	unsigned count_time=0;
	
	srand(time(0));  // Initialize random number generator.

	// Count execution time
	int start_s=clock();
	
	std::ofstream Unstable_Time;
	std::ofstream pgf_Format;
 	pgf_Format.open ("pgf_format.dat", std::ios::out | std::ios::trunc);
 	
	Unstable_Time.open ("UNucleus_Time.dat", std::ios::out | std::ios::trunc);
	Unstable_Time << "#! Phase avalanche size distribution:" << std::endl;
 	Unstable_Time << "#! Size		Frequency" << std::endl;
 	Unstable_Time << "0" << "  " << Number_Unstable_Nucleus << std::endl;
 	pgf_Format << "(0," << Number_Unstable_Nucleus << ")";
 	
	while(Number_Unstable_Nucleus != 0)
	{
		for(i =0; i < Number_Unstable_Nucleus; i++ )
		{
			// generating random in the domain [1,6] (Piles are stable yet, spin <= 4)  (http://www.cplusplus.com/reference/cstdlib/rand/)
			int Random_event = rand() % Inverse_probability +1;
			//std::cout << i <<"   r="<< Random_event << std::endl;
			if(Random_event == 1) Number_Unstable_Nucleus=Number_Unstable_Nucleus-1;
		}
		count_time++;
		std::cout << "\r" << "    Time step = " << count_time << " Unstable nucleus = " << Number_Unstable_Nucleus << std::flush ;//std::endl;
		Unstable_Time << count_time << "  " << Number_Unstable_Nucleus << std::endl;
		pgf_Format << "(" << count_time << "," << Number_Unstable_Nucleus<< ")";	
	}
	Unstable_Time.close();
	
	
	// Finish:
	std::cout << "\r" << BOLDYELLOW << "    Finished!                                                    " << RESET << std::flush ;
	std::cout << std::endl ;
	std::cout << YELLOW << "    To analyse data, check the generated data files:" << RESET << std::endl;
	std::cout << std::endl ;
	std::cout << YELLOW << "    ----> UNucleus_Time.dat" << RESET << std::endl;
	std::cout << YELLOW << "    ----> pgf_format.dat" << RESET << std::endl;
	std::cout << std::endl ;
	std::cout << std::endl ;
	
	
	std::cout << BOLDYELLOW << "    Decay duration: " << BOLDWHITE << count_time << WHITE << " time units" << std::endl;
	// Count execution time
	int stop_s=clock();
 	//cout << std::endl;
 	//cout << "  Number of avalanches: \033[1m" << Avalanche_number << "\033[0m" << std::endl;
 	
	std::cout << BOLDYELLOW << "    Execution time: " << BOLDWHITE << (stop_s-start_s)/double(CLOCKS_PER_SEC) << WHITE << " seconds" << std::endl;
	std::cout << std::endl ;
	std::cout << std::endl ;
	//cout << std::endl;
}
