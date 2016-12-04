//
// Created by michael on 12/3/16.
//

#include <string>
#include <fstream>
#include "TLB.h"

#define PHYSICAL_MEM_SIZE 256
#define PAGE_TABLE_SIZE 256

int main() {
    // Make TLB
    TLB * tlb = new TLB();
    setuptlb(tlb);
    // Make page table
    std::vector<page_t> page_table(PAGE_TABLE_SIZE);
    // Make Physical Memory
    std::vector<frame_t> physical_mem(PHYSICAL_MEM_SIZE);

    std::string line;
    //std::ifstream file ("./" + filename);
    std::ifstream file ("/home/michael/ClionProjects/OS_Project5/testinput.txt");

    if(file.is_open())
}