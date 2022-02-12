void memory_present(int nid, unsigned long start, unsigned long end)
{
unsigned long pfn;
printk(KERN_INFO "Node: %d, start_pfn: %lx, end_pfn: %lx\n",
nid, start, end);
printk(KERN_DEBUG " Setting physnode_map array to node %d for pfns:\n", nid);
printk(KERN_DEBUG " ");
start = round_down(start, PAGES_PER_SECTION);
end = round_up(end, PAGES_PER_SECTION);
for (pfn = start; pfn < end; pfn += PAGES_PER_SECTION) {
physnode_map[pfn / PAGES_PER_SECTION] = nid;
printk(KERN_CONT "%lx ", pfn);
}
printk(KERN_CONT "\n");
}
unsigned long node_memmap_size_bytes(int nid, unsigned long start_pfn,
unsigned long end_pfn)
{
unsigned long nr_pages = end_pfn - start_pfn;
if (!nr_pages)
return 0;
return (nr_pages + 1) * sizeof(struct page);
}
void __init initmem_init(void)
{
x86_numa_init();
#ifdef CONFIG_HIGHMEM
highstart_pfn = highend_pfn = max_pfn;
if (max_pfn > max_low_pfn)
highstart_pfn = max_low_pfn;
printk(KERN_NOTICE "%ldMB HIGHMEM available.\n",
pages_to_mb(highend_pfn - highstart_pfn));
high_memory = (void *) __va(highstart_pfn * PAGE_SIZE - 1) + 1;
#else
high_memory = (void *) __va(max_low_pfn * PAGE_SIZE - 1) + 1;
#endif
printk(KERN_NOTICE "%ldMB LOWMEM available.\n",
pages_to_mb(max_low_pfn));
printk(KERN_DEBUG "max_low_pfn = %lx, highstart_pfn = %lx\n",
max_low_pfn, highstart_pfn);
printk(KERN_DEBUG "Low memory ends at vaddr %08lx\n",
(ulong) pfn_to_kaddr(max_low_pfn));
printk(KERN_DEBUG "High memory starts at vaddr %08lx\n",
(ulong) pfn_to_kaddr(highstart_pfn));
__vmalloc_start_set = true;
setup_bootmem_allocator();
}
