//
// Created by michael on 12/3/16.
//

#include <string>
#include <fstream>
#include "TLB.h"
#include "backingstore_reader.h"
#include "output.h"


double num_tlb_faults = 0; // Counter for num of tlb faults
double num_page_faults = 0;    // Counter for num of page faults
double num_of_loops = 0;
bool LRU = false;
bool show_phys = false;

void updatepagetable(std::vector<page_t> & page_table, frame_t frame_num)
{
    page_table[frame_num] = (page_t)frame_num;
}


void updatetlb(TLB *tlb, frame_t frame_num)
{
    if(tlb->rows[TLB_LENGTH-1].page_num != 0)
    {
        // tlb is full, replacement is needed
        //  find the oldest entry and replace it
        int oldest_entry_index = 0;
        for (int i = 1; i < TLB_LENGTH; ++i)
        {
            if(tlb->rows[i].age > tlb->rows[oldest_entry_index].age)
            {
                // this new index is older, make it the oldest
                oldest_entry_index = i;
            }
        }
        // replace oldest index
        tlb->rows[oldest_entry_index].page_num = frame_num;
        tlb->rows[oldest_entry_index].frame_num = frame_num;

    }
    else
    {
        // tlb is not full, add to next opening
        for (int i = 0; i < TLB_LENGTH; ++i)
        {
            if(tlb->rows[i].page_num == 0)
            {
                // row is free, take it
                tlb->rows[i].page_num = frame_num;
                tlb->rows[i].frame_num = frame_num;
            }
        }
    }
}

int main() {
    welcomeandaskifphysical(show_phys, LRU);

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
            // update line counter
            ++num_of_loops;

            log_addr_t * la = new log_addr_t();
            la->full_addr = (unsigned int) std::stoul(line);
            setuplogicaladdress(la);

            phys_addr_t * pa = new phys_addr_t();

            unsigned char value;

            // check if page num is in TLB, else inc TLB fault count
            frame_t frame_num = getframefromtlb(la, tlb);
            if(frame_num == 0)
            {
                // page is not in tlb
                ++num_tlb_faults;
                // check if page num is in page table
                frame_num = getframefrompagetable(la, page_table);
                if(frame_num == 0)
                {
                    // page not in page table
                    ++num_page_faults;
                    // load into mem for backing store
                    getfrombs(la->page_num, value, frame_num);
                    // update page table
                    updatepagetable(page_table, frame_num);
                    // update tlb
                    updatetlb(tlb, frame_num);
                    if(!LRU)
                    {
                        resetage(tlb, frame_num);
                    }
                    output(la->full_addr, frame_num, value);
                }
                else
                {
                    // else: frame num is correct
                    setupphysicaladdress(pa, frame_num, la->offset);
                    output(la->full_addr, frame_num, 0);
                }
            }
            else
            {
                // the page number is in the tlb
                setupphysicaladdress(pa, frame_num, la->offset);
                if(!LRU)
                {
                    resetage(tlb,frame_num);
                }

                output(la->full_addr, frame_num, 0);
            }
            int a = 4;
            // add one to all ages in tlb
            for(int i = 0; tlb->rows[i].page_num == 0; ++i)
            {
                ++tlb->rows[i].age;
            }
        }
    }
    else
    {
        printf("Could not Open the file \n");
    }

    std::cout << std::endl << "Page Fault Rate: "
                << num_page_faults / num_of_loops
                << std::endl;

    std::cout << "tlb hit rate: "
                <<  num_tlb_faults / num_of_loops
                << std::endl;

    std::ofstream output;
    output.open("vm_sim_output", std::ios_base::app);
    output << "\r\n" << "page fault rate: "
            << num_page_faults / num_of_loops
                << "\r\n";

    output << "tlb hit rate: "
            <<  num_tlb_faults / num_of_loops
                << "\r\n";
    output.close();

    std::cout << std::endl
              << "Check the results in the outputfile: vm_som_output"
              << std::endl;
}