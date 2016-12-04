#include <iostream>
#include <string>

int proto_output() {
  std::cout << "Welcome to Group_6's VM Sim V 1.0" << std::endl << std::endl;

  std::cout << "Number of logical pages: 256" << std::endl;
  std::cout << "Page size: 256 bytes" << std::endl;
  std::cout << "Page table size: 256" << std::endl;
  std::cout << "TLB size: 16 entries" << std::endl;
  std::cout << "Number of physical frames: 256" << std::endl;
  std::cout << "Physical memory size: 65,536 bytes" << std::endl << std::endl;

  std::string dispPhysAddr = "";
  std::string TLBReplaceStrat = "1";
  bool showPhysAddr = false;
  bool fifo_y_n = true;
  //if fifo_y_n is true, do fifo, otherwise do LRU

  //str1.compare(str2)

  std::cout << "Display Physical Addresses? [yes or no]: ";
  std::cin >> dispPhysAddr;
  std::cout << "Choose TLB Replacement Strategy [1: FIFO, 2: LRU]: ";
  std::cin >> TLBReplaceStrat;

  if (dispPhysAddr.compare("yes") == 0) {
    showPhysAddr = true;
    std::cout << "show phys addr" << std::endl;
  }

  if (TLBReplaceStrat.compare("2") == 0) {
    fifo_y_n = false;
    std::cout << "do LRU" << std::endl;
  }

  std::cout << std::endl;

  //template for each output line in the loop
  std::cout << "Virtual Address: "
            << "" /*virtual address var*/
            << "; Physical address: "
            << "" /*physical address var*/
            << "; Value: "
            << "" /*value var*/
            << std::endl;


  std::cout << std::endl << "Page Fault Rate: "
            << "" /*page fault rate calculated var*/
            << std::endl;

  std::cout << "TLB hit rate: "
            << "" /* tlb hit rate var */
            << std::endl;

  std::cout << std::endl
            << "Check the results in the outputfile: vm_som_output"
            << std::endl;


}
