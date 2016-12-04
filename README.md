COMP3500 Project 5 Report

Jason Stephens -
Michael Harrison -
Jake Mullins -
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

		Accessing Backing_Store: //Talk about this one if you have a good answer, otherwise
							     //leave it out (REMOVE IF EMPTY)

	Data Structures:

			Address structure:			
				typedef struct logical_address_struct
				{
					unsigned int full_addr;
					page_t page_num;
					offset_t offset;
				}log_addr_t;

				typedef struct physical_address_struct
				{
					unsigned int full_addr;
					frame_t fram_num;
					offset_t offset;
				}phys_addr_t;

			TLB structure:
				typedef struct TLB_row_struct
				{
				    page_t page_num;
				    frame_t frame_num;
				    int age;
				}TLB_row;

				typedef struct TLB_struct
				{
				    std::vector<TLB_row> rows;

				}TLB;

			Page table structure:
				std::vector<page_t> page_table(PAGE_TABLE_SIZE);

			Physical memory structure:
				std::vector<frame_t> physical_mem(PHYSICAL_MEM_SIZE);

Project Report Questions:

	Solution Description:

		//You must describe your solutions with good sample input and output to
		//show users what your memory manager is doing (REMOVE THIS BEFORE SUBMIT)

		1) How did you guarantee that each logical address is translated to the
		   correct physical address?

				We use an algorithm that utilizes bit shifting and bit masking
				in a way that always results in the proper logical to physical
				address conversion. This solution is demonstrated in address.cpp

		2) How did you implement the page table, physical memory, and TLB?

			Page table - instantiated as a vector of pages.

			Physical memory - created physical address structure that includes full
			address, frame number, and offset. The physical memory itself is a vector
			of frame numbers, where each frame number correlates with a frame number
			in a struct. This effectively makes the vector an array of unique references
			to chunks of memory.

			TLB - a structure that contains a vector of TLB row objects. These TLB row
			objects include page number, frame number, and age.

		3) Does your program realistically and accurately simulate a virtual memory
		   system?			

			 Absolutely. The code is designed to be as true to a virtual memory system
			 as possible for us to achieve.

		4) Did you use the Java operators for bit-masking and bit-shifting?

			Yes, bit-shifting and bit-masking is performed with ">>" and "<<"
			operators.

		5) When a TLB miss occurs, how do you decided which entry to replace?

			The user will be able to select one of two methods to do this (both which
			are implemented): a first in first out system, where the first entry in
			would be the first to be replaced, or a least recently used system, where
			the entry being replaced will be the entry that was used the longest ago.


	Generality and Performance Criteria:

		1) How general is your solution?

			Our code is very general; we made our structures and functions with
			reusability in mind.

		2) How easy would it be to change parameters such as the size of the TLB?

			Very easy; since we were extremely conscious of reusability and
			maintainability throughout the design process, such changes do not
			require much source code manipulation.

		3) Does your program only load pages from the backing store when they are
		   needed?

			 Yes, the only time our program is designed to access backing_store is when
			 it is absolutely necessary. Theoretically there are no redundant or
			 unnecessary writes to or reads from backing_store based on our testing.


		4) Does your solution allow the physical address space to be smaller than
		   the virtual address space?

				Yes; number of bits needed to address something in physical memory
				is not required to be as large as the virtual address.

	Miscellaneous Factors:

		1) Is your code elegant?

			The code definitely could be considered so. It is succinct, formatted well,
			and was made to be as general as we possibly could make it.

		2) How innovative is your solution? Did you try any ideas not suggested here?

			No; we tended to focus on ensuring functionality rather than innovation in
			effort to make sure everything worked well in good time.


		3) Did you document all outside sources?

			Yes; A few were used, but where they are implemented they are credited.


Further Discussion:

	Unfinished Work:

		//answer (if there is any)
		//save this file as project5_report.txt instead of README.md once done.
