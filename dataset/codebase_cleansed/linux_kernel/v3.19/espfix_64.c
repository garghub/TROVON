static inline unsigned long espfix_base_addr(unsigned int cpu)
{
unsigned long page, slot;
unsigned long addr;
page = (cpu / ESPFIX_STACKS_PER_PAGE) ^ page_random;
slot = (cpu + slot_random) % ESPFIX_STACKS_PER_PAGE;
addr = (page << PAGE_SHIFT) + (slot * ESPFIX_STACK_SIZE);
addr = (addr & 0xffffUL) | ((addr & ~0xffffUL) << 16);
addr += ESPFIX_BASE_ADDR;
return addr;
}
static void init_espfix_random(void)
{
unsigned long rand;
if (!arch_get_random_long(&rand)) {
rdtscll(rand);
rand *= 0xc345c6b72fd16123UL;
}
slot_random = rand % ESPFIX_STACKS_PER_PAGE;
page_random = (rand / ESPFIX_STACKS_PER_PAGE)
& (ESPFIX_PAGE_SPACE - 1);
}
void __init init_espfix_bsp(void)
{
pgd_t *pgd_p;
pgd_p = &init_level4_pgt[pgd_index(ESPFIX_BASE_ADDR)];
pgd_populate(&init_mm, pgd_p, (pud_t *)espfix_pud_page);
init_espfix_random();
init_espfix_ap();
}
void init_espfix_ap(void)
{
unsigned int cpu, page;
unsigned long addr;
pud_t pud, *pud_p;
pmd_t pmd, *pmd_p;
pte_t pte, *pte_p;
int n;
void *stack_page;
pteval_t ptemask;
if (likely(this_cpu_read(espfix_stack)))
return;
cpu = smp_processor_id();
addr = espfix_base_addr(cpu);
page = cpu/ESPFIX_STACKS_PER_PAGE;
stack_page = ACCESS_ONCE(espfix_pages[page]);
if (likely(stack_page))
goto done;
mutex_lock(&espfix_init_mutex);
stack_page = ACCESS_ONCE(espfix_pages[page]);
if (stack_page)
goto unlock_done;
ptemask = __supported_pte_mask;
pud_p = &espfix_pud_page[pud_index(addr)];
pud = *pud_p;
if (!pud_present(pud)) {
pmd_p = (pmd_t *)__get_free_page(PGALLOC_GFP);
pud = __pud(__pa(pmd_p) | (PGTABLE_PROT & ptemask));
paravirt_alloc_pmd(&init_mm, __pa(pmd_p) >> PAGE_SHIFT);
for (n = 0; n < ESPFIX_PUD_CLONES; n++)
set_pud(&pud_p[n], pud);
}
pmd_p = pmd_offset(&pud, addr);
pmd = *pmd_p;
if (!pmd_present(pmd)) {
pte_p = (pte_t *)__get_free_page(PGALLOC_GFP);
pmd = __pmd(__pa(pte_p) | (PGTABLE_PROT & ptemask));
paravirt_alloc_pte(&init_mm, __pa(pte_p) >> PAGE_SHIFT);
for (n = 0; n < ESPFIX_PMD_CLONES; n++)
set_pmd(&pmd_p[n], pmd);
}
pte_p = pte_offset_kernel(&pmd, addr);
stack_page = (void *)__get_free_page(GFP_KERNEL);
pte = __pte(__pa(stack_page) | (__PAGE_KERNEL_RO & ptemask));
for (n = 0; n < ESPFIX_PTE_CLONES; n++)
set_pte(&pte_p[n*PTE_STRIDE], pte);
ACCESS_ONCE(espfix_pages[page]) = stack_page;
unlock_done:
mutex_unlock(&espfix_init_mutex);
done:
this_cpu_write(espfix_stack, addr);
this_cpu_write(espfix_waddr, (unsigned long)stack_page
+ (addr & ~PAGE_MASK));
}
