#ifndef output_h
#define output_h


#include <iostream>
#include <string>
#include <fstream>


int output(unsigned int logical_address,
                 unsigned int physical_address, unsigned int value) {

  //each output "block" is followed by a file write "block" that will look
  //identical to what pops up in the user's terminal upon execution

  std::ofstream output;
  output.open("vm_sim_output", std::ios_base::app);

  //template for each output line in the loop
  //LOOP:
  std::cout << "Virtual Address: "
            << logical_address
            << "; Physical address: "
            << physical_address
            << "; Value: "
            << value
            << std::endl;


  output    << "Virtual Address: "
            << logical_address
            << "; Physical address: "
            << physical_address
            << "; Value: "
            << value
            << "\r\n";
  //EXIT LOOP




}

bool welcomeandaskifphysical(bool & ret_showphys, bool & ret_fifo_y_n) {
  std::cout << "welcome to group_6's vm sim v 1.0" << std::endl << std::endl;

  std::cout << "number of logical pages: 256" << std::endl;
  std::cout << "page size: 256 bytes" << std::endl;
  std::cout << "page table size: 256" << std::endl;
  std::cout << "tlb size: 16 entries" << std::endl;
  std::cout << "number of physical frames: 256" << std::endl;
  std::cout << "physical memory size: 65,536 bytes" << std::endl << std::endl;

  std::string dispphysaddr = "";
  std::string tlbreplacestrat = "1";
  bool showphysaddr = false;
  bool fifo_y_n = true;
  //if fifo_y_n is true, do fifo, otherwise do lRU

  //str1.compare(str2)

  std::cout << "Display Physical Addresses? [yes or no]: ";
  std::cin >> dispphysaddr;
  std::cout << "Choose TLB Replacement Strategy [1: FIFO, 2: LRU]: ";
  std::cin >> tlbreplacestrat;
    if (dispphysaddr.compare("yes") == 0) {
    ret_showphys = true;
    //std::cout << "show phys addr" << std::endl;
  }

  if (tlbreplacestrat.compare("2") == 0) {
    ret_fifo_y_n = false;
  }

  std::cout << std::endl;
}


#endif
