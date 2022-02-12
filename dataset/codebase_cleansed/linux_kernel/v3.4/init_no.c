void __init paging_init(void)
{
unsigned long end_mem = memory_end & PAGE_MASK;
unsigned long zones_size[MAX_NR_ZONES] = {0, };
empty_zero_page = alloc_bootmem_pages(PAGE_SIZE);
memset(empty_zero_page, 0, PAGE_SIZE);
set_fs (USER_DS);
zones_size[ZONE_DMA] = (end_mem - PAGE_OFFSET) >> PAGE_SHIFT;
free_area_init(zones_size);
}
void __init mem_init(void)
{
int codek = 0, datak = 0, initk = 0;
unsigned long tmp;
unsigned long len = _ramend - _rambase;
unsigned long start_mem = memory_start;
unsigned long end_mem = memory_end;
pr_debug("Mem_init: start=%lx, end=%lx\n", start_mem, end_mem);
end_mem &= PAGE_MASK;
high_memory = (void *) end_mem;
start_mem = PAGE_ALIGN(start_mem);
max_mapnr = num_physpages = (((unsigned long) high_memory) - PAGE_OFFSET) >> PAGE_SHIFT;
totalram_pages = free_all_bootmem();
codek = (_etext - _stext) >> 10;
datak = (_ebss - _sdata) >> 10;
initk = (__init_begin - __init_end) >> 10;
tmp = nr_free_pages() << PAGE_SHIFT;
printk(KERN_INFO "Memory available: %luk/%luk RAM, (%dk kernel code, %dk data)\n",
tmp >> 10,
len >> 10,
codek,
datak
);
}
void free_initrd_mem(unsigned long start, unsigned long end)
{
int pages = 0;
for (; start < end; start += PAGE_SIZE) {
ClearPageReserved(virt_to_page(start));
init_page_count(virt_to_page(start));
free_page(start);
totalram_pages++;
pages++;
}
pr_notice("Freeing initrd memory: %luk freed\n",
pages * (PAGE_SIZE / 1024));
}
void free_initmem(void)
{
#ifdef CONFIG_RAMKERNEL
unsigned long addr;
addr = PAGE_ALIGN((unsigned long) __init_begin);
for (; addr + PAGE_SIZE < ((unsigned long) __init_end); addr += PAGE_SIZE) {
ClearPageReserved(virt_to_page(addr));
init_page_count(virt_to_page(addr));
free_page(addr);
totalram_pages++;
}
pr_notice("Freeing unused kernel memory: %luk freed (0x%x - 0x%x)\n",
(addr - PAGE_ALIGN((unsigned long) __init_begin)) >> 10,
(int)(PAGE_ALIGN((unsigned long) __init_begin)),
(int)(addr - PAGE_SIZE));
#endif
}
