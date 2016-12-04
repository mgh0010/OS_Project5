COMP3500 Project 5 Report

Jason Stephens
Michael Harrison
Jake Mullins
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Introduction:

	For this project we will design and implement a standalone virtual memory manager
	with a software-managed TLB. There are three main things our program will be 
	responsible for:

		1) Loading a file containing a list of logical addresses
		2) Translating these logical addresses into physical addresses for a virtual
			address space of size 2^16 (65,536) bytes
		3) Outputting the value of the byte stored at the translated physical address

	This project will not be built on top of OS161, but will instead be a standalone 
	program. 

	Project Report questions/answers are provided at the bottom of this page. 

Design:

	Our program will read in a file containing a list of 32-bit integer numbers. These
	numbers each represent a 32-bit logical address. Since our program only deals with
	16-bit addresses we will need to mask the rightmost 16 bits of each address. Each 
	16-bit address is divided into two parts, an 8-bit page number and an 8-bit offset.

	System Parameters:

		1) Page table size: 2^8
		2) Number of TLB entries: 16
		3) Page size: 2^8
		4) Frame size: 2^8
		5) Number of frames: 256
		6) Physical memory size: 65,636 bytes

	Address Translation:
		
		Our program uses the following three steps to translate addresses:
			
			1) Page number is extracted from the logical address
			2) Use the page number to access the TLB
				- If there is a TLB-hit, obtain the page's frame number
				- Otherwise, proceed to step 3 to access the page table
			3) Access the page table
				- The frame number is obtained from the page table if the page has been
				  loaded into main memory
				- Otherwise, a page fault occurs

	Handling Page Faults:

		When a page fault occurs our program will perform the following four steps:
			
			1) Read a 256-byte page from BACKING_STORE 
			2) Store the loaded page frame in the physical memory
			3) Update the page table
			4) Update the TLB

	Data Structures:

			// Address structure				

			// TLB structure (section 6.3)

			// Page table structure (section 6.2)

			// Physical memory structure

Project Report Questions:
	
	Solution Description:

		//You must describe your solutions with good sample input and output to 
		//show users what your memory manager is doing (REMOVE THIS BEFORE SUBMIT)
		
		1) How did you guarantee that each logical address is translated to the
		   correct physical address?
				
				//answer 

		2) How did you implement the page table, physical memory, and TLB?

				//answer

		3) Does your program realistically and accurately simulate a virtual memory
		   system?			
			
				//answer

		4) Did you use the Java operators for bit-masking and bit-shifting?

				//answer

		5) When a TLB miss occurs, how do you decided which entry to replace?

				//answer

	Generality and Performance Criteria:

		1) How general is your solution?

				//answer

		2) How easy would it be to change parameters such as the size of the TLB?

				//answer

		3) Does your program only load pages from the backing store when they are
		   needed?

				//answer

		4) Does your solution allow the physical address space to be smaller than 
		   the virtual address space?

				//answer

	Miscellaneous Factors:

		1) Is your code elegant?
		
				//answer

		2) How innovative is your solution? Did you try any ideas not suggested here?

				//answer

		3) Did you document all outside sources?

				//answer

Further Discussion:

	Unfinished Work:

		//answer (if there is any) 
		//save this file as project5_report.txt instead of README.md once done. 


































			
