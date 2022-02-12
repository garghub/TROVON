void __init paging_init(void)
{
pgd_t * pg_dir;
pte_t * pg_table;
int i;
unsigned long address;
unsigned long next_pgtable;
unsigned long bootmem_end;
unsigned long zones_size[MAX_NR_ZONES] = { 0, };
unsigned long size;
empty_zero_page = alloc_bootmem_pages(PAGE_SIZE);
address = PAGE_OFFSET;
pg_dir = swapper_pg_dir;
memset (swapper_pg_dir, 0, sizeof (swapper_pg_dir));
memset (kernel_pg_dir, 0, sizeof (kernel_pg_dir));
size = num_pages * sizeof(pte_t);
size = (size + PAGE_SIZE) & ~(PAGE_SIZE-1);
next_pgtable = (unsigned long)alloc_bootmem_pages(size);
bootmem_end = (next_pgtable + size + PAGE_SIZE) & PAGE_MASK;
pg_dir += PAGE_OFFSET >> PGDIR_SHIFT;
while (address < (unsigned long)high_memory) {
pg_table = (pte_t *) __pa (next_pgtable);
next_pgtable += PTRS_PER_PTE * sizeof (pte_t);
pgd_val(*pg_dir) = (unsigned long) pg_table;
pg_dir++;
pg_table = (pte_t *) __va ((unsigned long) pg_table);
for (i=0; i<PTRS_PER_PTE; ++i, ++pg_table) {
pte_t pte = pfn_pte(virt_to_pfn(address), PAGE_INIT);
if (address >= (unsigned long)high_memory)
pte_val (pte) = 0;
set_pte (pg_table, pte);
address += PAGE_SIZE;
}
}
mmu_emu_init(bootmem_end);
current->mm = NULL;
zones_size[ZONE_DMA] = ((unsigned long)high_memory - PAGE_OFFSET) >> PAGE_SHIFT;
free_area_init_node(0, zones_size,
(__pa(PAGE_OFFSET) >> PAGE_SHIFT) + 1, NULL);
}
