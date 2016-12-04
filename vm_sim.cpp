//
// Created by michael on 12/3/16.
//

#include <string>
#include <fstream>
#include "TLB.h"

#define PHYSICAL_MEM_SIZE 256
#define PAGE_TABLE_SIZE 256

int num_tlb_faults = 0; // Counter for num of tlb faults
int num_page_faults = 0;    // Counter for num of page faults

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
    std::ifstream file ("/home/michael/ClionProjects/OS_Project5/InputFile.txt");

    if(file.is_open())
    {
        while(getline(file, line))
        {
            log_addr_t * la = new log_addr_t();
            la->full_addr = (unsigned int) std::stoul(line);
            setuplogicaladdress(la);
            // check if page num is in TLB, else inc TLB fault count
            if(pagenotintlb(la, tlb))
            {
                ++num_tlb_faults;
            }
            int a = 4;
        }
    }
    else
    {
        printf("Could not Open the file \n");
    }
}