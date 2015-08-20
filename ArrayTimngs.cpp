
#include <chrono>
#include <iostream>
#include <cmath>



int main()
{
	
	long SIZEX = 1000;
	long SIZEY = 1000;
	long TESTS = 1000;
	
	const long SIZEXY = SIZEX*SIZEY;
	
	std::cout << "Test Parameters: SIZEX: " << SIZEX  <<  " SIZEY: " << SIZEY << " NUM TESTS: " << TESTS << std::endl; 
	
	{
		std::cout << "1D 1For Heap  ";
		
		int *myArray = new int[SIZEX*SIZEY];
	
		std::chrono::steady_clock::time_point starttime = std::chrono::steady_clock::now();
		for (long t=0; t< TESTS; ++t)
		{
		
			for (long i = 0; i < SIZEX*SIZEY; ++i)
			{
				int ii = i / SIZEX;
				int jj = i % SIZEX;
				
				myArray[i] = ii+jj+t;
			}
		
		}
		
		std::chrono::steady_clock::time_point endtime = std::chrono::steady_clock::now();

		std::chrono::duration<double> time_span = std::chrono::duration_cast < std::chrono::duration< double > >(endtime - starttime);

		double MonitorPeriod = time_span.count();

		std::cout << MonitorPeriod << "s" << std::endl;
		
		delete [] myArray;
		
	}
	
	{
		std::cout << "1D 1For Stack ";
		
		int myArray[SIZEXY];
	
		std::chrono::steady_clock::time_point starttime = std::chrono::steady_clock::now();
		for (long t=0; t< TESTS; ++t)
		{
		
			for (long i = 0; i < SIZEX*SIZEY; ++i)
			{
				int ii = i / SIZEX;
				int jj = i % SIZEX;
				
				myArray[i] = ii+jj+t;
			}
		
		}

		std::chrono::steady_clock::time_point endtime = std::chrono::steady_clock::now();

		std::chrono::duration<double> time_span = std::chrono::duration_cast < std::chrono::duration< double > >(endtime - starttime);

		double MonitorPeriod = time_span.count();

		std::cout << MonitorPeriod << "s" << std::endl;
	}
	
	{
		std::cout << "1D 2For Stack ";
		
		int myArray[SIZEXY];

		std::chrono::steady_clock::time_point starttime = std::chrono::steady_clock::now();
		for (long t=0; t< TESTS; ++t)
		{
		
			for (long i = 0; i < SIZEX; ++i)
			{
				for (long j = 0; j < SIZEY; ++j)
				{
					int ii = i;
					int jj = j;
					myArray[i*SIZEY+j] = ii+jj+t;
				}
			}	
		}

		std::chrono::steady_clock::time_point endtime = std::chrono::steady_clock::now();

		std::chrono::duration<double> time_span = std::chrono::duration_cast < std::chrono::duration< double > >(endtime - starttime);

		double MonitorPeriod = time_span.count();

		std::cout << MonitorPeriod << "s" << std::endl;
	}
	
	
	{
		std::cout << "2D 2For Stack ";
		
		int myArray[SIZEX][SIZEY];

		std::chrono::steady_clock::time_point starttime = std::chrono::steady_clock::now();
		for (long t=0; t< TESTS; ++t)
		{
		
			for (long i = 0; i < SIZEX; ++i)
			{
				for (long j = 0; j < SIZEY; ++j)
				{
					int ii = i;
					int jj = j;
					
					myArray[i][j] = ii+jj+t;
					
				}
			}
				
		}

		std::chrono::steady_clock::time_point endtime = std::chrono::steady_clock::now();

		std::chrono::duration<double> time_span = std::chrono::duration_cast < std::chrono::duration< double > >(endtime - starttime);

		double MonitorPeriod = time_span.count();

		std::cout << MonitorPeriod << "s" << std::endl;
	}
	
	{
		std::cout << "2D 1For Stack ";
		
		int myArray[SIZEX][SIZEY];

		std::chrono::steady_clock::time_point starttime = std::chrono::steady_clock::now();
		for (long t=0; t< TESTS; ++t)
		{
		
			for (long i = 0; i < SIZEX*SIZEY; ++i)
			{
				int ii = i / SIZEX;
				int jj = i % SIZEX;
				myArray[ii][jj] = ii+jj+t;
			}
				
		}

		std::chrono::steady_clock::time_point endtime = std::chrono::steady_clock::now();

		std::chrono::duration<double> time_span = std::chrono::duration_cast < std::chrono::duration< double > >(endtime - starttime);

		double MonitorPeriod = time_span.count();

		std::cout << MonitorPeriod << "s" << std::endl;
	}
	
	{
		std::cout << "2D 1For Stack ";
		
		int myArray[SIZEX][SIZEY];

		std::chrono::steady_clock::time_point starttime = std::chrono::steady_clock::now();
		for (long t=0; t< TESTS; ++t)
		{
		
			for (long i = 0; i < SIZEX*SIZEY; ++i)
			{
				int ii = i % SIZEX;
				int jj = i / SIZEX;
				myArray[ii][jj] = ii+jj+t;
			}
				
		}

		std::chrono::steady_clock::time_point endtime = std::chrono::steady_clock::now();

		std::chrono::duration<double> time_span = std::chrono::duration_cast < std::chrono::duration< double > >(endtime - starttime);

		double MonitorPeriod = time_span.count();

		std::cout << MonitorPeriod << "s" << " (this iterates through first index first)" << std::endl;
	}
	
	return 0;
}