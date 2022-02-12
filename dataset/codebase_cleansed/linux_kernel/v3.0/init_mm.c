void __init m68k_setup_node(int node)
{
#ifndef CONFIG_SINGLE_MEMORY_CHUNK
struct mem_info *info = m68k_memory + node;
int i, end;
i = (unsigned long)phys_to_virt(info->addr) >> __virt_to_node_shift();
end = (unsigned long)phys_to_virt(info->addr + info->size - 1) >> __virt_to_node_shift();
for (; i <= end; i++) {
if (pg_data_table[i])
printk("overlap at %u for chunk %u\n", i, node);
pg_data_table[i] = pg_data_map + node;
}
#endif
pg_data_map[node].bdata = bootmem_node_data + node;
node_set_online(node);
}
void __init mem_init(void)
{
pg_data_t *pgdat;
int codepages = 0;
int datapages = 0;
int initpages = 0;
int i;
#ifdef CONFIG_ATARI
if (MACH_IS_ATARI)
atari_stram_mem_init_hook();
#endif
totalram_pages = num_physpages = 0;
for_each_online_pgdat(pgdat) {
num_physpages += pgdat->node_present_pages;
totalram_pages += free_all_bootmem_node(pgdat);
for (i = 0; i < pgdat->node_spanned_pages; i++) {
struct page *page = pgdat->node_mem_map + i;
char *addr = page_to_virt(page);
if (!PageReserved(page))
continue;
if (addr >= _text &&
addr < _etext)
codepages++;
else if (addr >= __init_begin &&
addr < __init_end)
initpages++;
else
datapages++;
}
}
#ifndef CONFIG_SUN3
init_pointer_table((unsigned long)kernel_pg_dir);
for (i = 0; i < PTRS_PER_PGD; i++) {
if (pgd_present(kernel_pg_dir[i]))
init_pointer_table(__pgd_page(kernel_pg_dir[i]));
}
if (zero_pgtable)
init_pointer_table((unsigned long)zero_pgtable);
#endif
printk("Memory: %luk/%luk available (%dk kernel code, %dk data, %dk init)\n",
nr_free_pages() << (PAGE_SHIFT-10),
totalram_pages << (PAGE_SHIFT-10),
codepages << (PAGE_SHIFT-10),
datapages << (PAGE_SHIFT-10),
initpages << (PAGE_SHIFT-10));
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
printk ("Freeing initrd memory: %dk freed\n", pages);
}
