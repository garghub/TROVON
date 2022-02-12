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
rand = rdtsc();
rand *= 0xc345c6b72fd16123UL;
}
slot_random = rand % ESPFIX_STACKS_PER_PAGE;
page_random = (rand / ESPFIX_STACKS_PER_PAGE)
& (ESPFIX_PAGE_SPACE - 1);
}
void __init init_espfix_bsp(void)
{
pgd_t *pgd;
p4d_t *p4d;
pgd = &init_top_pgt[pgd_index(ESPFIX_BASE_ADDR)];
p4d = p4d_alloc(&init_mm, pgd, ESPFIX_BASE_ADDR);
p4d_populate(&init_mm, p4d, espfix_pud_page);
init_espfix_random();
init_espfix_ap(0);
}
void init_espfix_ap(int cpu)
{
unsigned int page;
unsigned long addr;
pud_t pud, *pud_p;
pmd_t pmd, *pmd_p;
pte_t pte, *pte_p;
int n, node;
void *stack_page;
pteval_t ptemask;
if (likely(per_cpu(espfix_stack, cpu)))
return;
addr = espfix_base_addr(cpu);
page = cpu/ESPFIX_STACKS_PER_PAGE;
stack_page = ACCESS_ONCE(espfix_pages[page]);
if (likely(stack_page))
goto done;
mutex_lock(&espfix_init_mutex);
stack_page = ACCESS_ONCE(espfix_pages[page]);
if (stack_page)
goto unlock_done;
node = cpu_to_node(cpu);
ptemask = __supported_pte_mask;
pud_p = &espfix_pud_page[pud_index(addr)];
pud = *pud_p;
if (!pud_present(pud)) {
struct page *page = alloc_pages_node(node, PGALLOC_GFP, 0);
pmd_p = (pmd_t *)page_address(page);
pud = __pud(__pa(pmd_p) | (PGTABLE_PROT & ptemask));
paravirt_alloc_pmd(&init_mm, __pa(pmd_p) >> PAGE_SHIFT);
for (n = 0; n < ESPFIX_PUD_CLONES; n++)
set_pud(&pud_p[n], pud);
}
pmd_p = pmd_offset(&pud, addr);
pmd = *pmd_p;
if (!pmd_present(pmd)) {
struct page *page = alloc_pages_node(node, PGALLOC_GFP, 0);
pte_p = (pte_t *)page_address(page);
pmd = __pmd(__pa(pte_p) | (PGTABLE_PROT & ptemask));
paravirt_alloc_pte(&init_mm, __pa(pte_p) >> PAGE_SHIFT);
for (n = 0; n < ESPFIX_PMD_CLONES; n++)
set_pmd(&pmd_p[n], pmd);
}
pte_p = pte_offset_kernel(&pmd, addr);
stack_page = page_address(alloc_pages_node(node, GFP_KERNEL, 0));
pte = __pte(__pa(stack_page) | ((__PAGE_KERNEL_RO | _PAGE_ENC) & ptemask));
for (n = 0; n < ESPFIX_PTE_CLONES; n++)
set_pte(&pte_p[n*PTE_STRIDE], pte);
ACCESS_ONCE(espfix_pages[page]) = stack_page;
unlock_done:
mutex_unlock(&espfix_init_mutex);
done:
per_cpu(espfix_stack, cpu) = addr;
per_cpu(espfix_waddr, cpu) = (unsigned long)stack_page
+ (addr & ~PAGE_MASK);
}
