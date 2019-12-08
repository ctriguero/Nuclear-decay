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
		std::cout << YELLOW << "    Taking default values:" << BOLDWHITE << " 100 unstable nuclei" << YELLOW  <<   " with decay probability" << BOLDWHITE <<  " p=1/6" << RESET << std::endl ;
		std::cout << YELLOW << "    To set specific values:" << RESET << std::endl ;
		std::cout << " " << std::endl ;
		std::cout << BOLDRED << "\t " << argv[0] << " -n [Number of unstable nuclei] -p [Probability per unit of time 1/p]" << RESET << std::endl ;
		std::cout << " " << std::endl ;
		//return (0) ;
	}
	
	
	// Default values
	//------------------------------------
    unsigned Number_Unstable_Nucleus=1;
    unsigned Inverse_probability =6;
    unsigned Realization=1;
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
		if ( ( argv[k] == std::string("-p") ) || ( argv[k] == std::string("-P") ) ) { Inverse_probability = atoi(argv[k+1]) ; }
		if ( ( argv[k] == std::string("-r") ) || ( argv[k] == std::string("-R") ) ) { Realization = atoi(argv[k+1]) ; }
	}
	
	// Initial information:
	std::cout << std::endl ;
	std::cout << YELLOW << "    Initial unstable nuclei: " << BOLDWHITE << Number_Unstable_Nucleus << RESET << std::endl;
	std::cout << YELLOW << "    Inverse probability (1/p): " << BOLDWHITE << Inverse_probability << RESET << std::endl;
	std::cout << std::endl ;

	unsigned Nt=Number_Unstable_Nucleus;
	unsigned Number_Stable_Nucleus=0;
	unsigned i;
	unsigned r;
	unsigned count_time=0;
	
	

	// Count execution time
	int start_s=clock();
	
	std::ofstream Unstable_Time;
	std::ofstream pgf_Format;
	std::ofstream pgf_Format_Norm_N0;
	std::ofstream Duration_realizations;
	
	
 	pgf_Format.open ("pgf_format.dat", std::ios::out | std::ios::trunc);
 	pgf_Format_Norm_N0.open  ("pgf_format_Norm_N0.dat", std::ios::out | std::ios::trunc);
 	
	Unstable_Time.open ("UNucleus_Time.dat", std::ios::out | std::ios::trunc);
	Unstable_Time << "#! Phase avalanche size distribution:" << std::endl;
 	Unstable_Time << "#! Size		Frequency" << std::endl;
 	Unstable_Time << "0" << "  " << Number_Unstable_Nucleus << std::endl;
 	pgf_Format << "(0," << Number_Unstable_Nucleus << ")";
 	pgf_Format_Norm_N0 << "(0,1.0)";
 	
 	Duration_realizations.open ("Duration.dat", std::ios::out | std::ios::trunc);
 	
 	
 	// Safety check for initial parameters
 	if( Number_Unstable_Nucleus == 0)
 	{
 		std::cout << BOLDRED << "    * WARNING: Initial number of unstable nuclei is zero. Decay is not possible." << std::endl;
 		std::cout << std::endl ;
 		std::cout << std::endl ;
 		return 0;
 	}
 	
 	if( Inverse_probability == 1)
 	{
 		std::cout << BOLDRED << "    * WARNING: Probability 1. All nuclei will decay in one step. Trivial simulation." << std::endl;
 		std::cout << std::endl ;
 		std::cout << std::endl ;
 		return 0;
 	}
 	
 	if( Inverse_probability == 0)
 	{
 		std::cout << BOLDRED << "    * WARNING: Divergent probability. Try p different from zero." << std::endl;
 		std::cout << std::endl ;
		std::cout << std::endl ;
 		return 0;
 	}
 	
 	
 	srand(time(0));  // Initialize random number generator.
 	
 	// Begin Realization loop
 	
 	
	for(r =0; r < Realization; r++ )
	{
	int Random_event = rand() % 6 + 1; //% Inverse_probability +1;
	Duration_realizations << Random_event << std::endl;			
	}
	
}
