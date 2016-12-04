//
// Created by michael on 12/3/16.
//

#include <string>
#include <fstream>
#include "TLB.h"


int num_tlb_faults = 0; // Counter for num of tlb faults
int num_page_faults = 0;    // Counter for num of page faults
bool LRU = false;

void updatepagetable(std::vector<page_t> & page_table, frame_t frame_num)
{
    page_table[frame_num] = (page_t)frame_num;
}


void updatetlb(TLB *tlb, frame_t frame_num)
{
    if(tlb->rows[TLB_LENGTH-1].page_num != NULL)
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
            if(tlb->rows[i].page_num == NULL)
            {
                // row is free, take it
                tlb->rows[i].page_num = frame_num;
                tlb->rows[i].frame_num = frame_num;
            }
        }
    }
}

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

            phys_addr_t * pa = new phys_addr_t();

            // check if page num is in TLB, else inc TLB fault count
            frame_t frame_num = getframefromtlb(la, tlb);
            if(frame_num == NULL)
            {
                // page is not in tlb
                ++num_tlb_faults;
                // check if page num is in page table
                frame_num = getframefrompagetable(la, page_table);
                if(frame_num == NULL)
                {
                    // page not in page table
                    ++num_page_faults;
                    // load into mem for backing store
                    // update page table
                    updatepagetable(page_table, frame_num);
                    // update tlb
                    updatetlb(tlb, frame_num);
                }
                else
                {
                    // else: frame num is correct
                    setupphysicaladdress(pa, frame_num, la->offset);
                }
            }
            else
            {
                // the page number is in the tlb
                setupphysicaladdress(pa, frame_num, la->offset);
                if(LRU)
                {
                    resetage(tlb,frame_num);
                }
            }
            int a = 4;
            // add one to all ages in tlb
            for(int i = 0; tlb->rows[i].page_num == NULL; ++i)
            {
                ++tlb->rows[i].age;
            }
        }
    }
    else
    {
        printf("Could not Open the file \n");
    }
}