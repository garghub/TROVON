static inline unsigned long get_padding(struct kaslr_memory_region *region)
{
return (region->size_tb << TB_SHIFT);
}
static inline bool kaslr_memory_enabled(void)
{
return kaslr_enabled() && !IS_ENABLED(CONFIG_KASAN);
}
void __init kernel_randomize_memory(void)
{
size_t i;
unsigned long vaddr = vaddr_start;
unsigned long rand, memory_tb;
struct rnd_state rand_state;
unsigned long remain_entropy;
BUILD_BUG_ON(vaddr_start >= vaddr_end);
BUILD_BUG_ON(IS_ENABLED(CONFIG_X86_ESPFIX64) &&
vaddr_end >= EFI_VA_END);
BUILD_BUG_ON((IS_ENABLED(CONFIG_X86_ESPFIX64) ||
IS_ENABLED(CONFIG_EFI)) &&
vaddr_end >= __START_KERNEL_map);
BUILD_BUG_ON(vaddr_end > __START_KERNEL_map);
if (!kaslr_memory_enabled())
return;
BUG_ON(kaslr_regions[0].base != &page_offset_base);
memory_tb = DIV_ROUND_UP(max_pfn << PAGE_SHIFT, 1UL << TB_SHIFT) +
CONFIG_RANDOMIZE_MEMORY_PHYSICAL_PADDING;
if (memory_tb < kaslr_regions[0].size_tb)
kaslr_regions[0].size_tb = memory_tb;
remain_entropy = vaddr_end - vaddr_start;
for (i = 0; i < ARRAY_SIZE(kaslr_regions); i++)
remain_entropy -= get_padding(&kaslr_regions[i]);
prandom_seed_state(&rand_state, kaslr_get_random_long("Memory"));
for (i = 0; i < ARRAY_SIZE(kaslr_regions); i++) {
unsigned long entropy;
entropy = remain_entropy / (ARRAY_SIZE(kaslr_regions) - i);
prandom_bytes_state(&rand_state, &rand, sizeof(rand));
if (IS_ENABLED(CONFIG_X86_5LEVEL))
entropy = (rand % (entropy + 1)) & P4D_MASK;
else
entropy = (rand % (entropy + 1)) & PUD_MASK;
vaddr += entropy;
*kaslr_regions[i].base = vaddr;
vaddr += get_padding(&kaslr_regions[i]);
if (IS_ENABLED(CONFIG_X86_5LEVEL))
vaddr = round_up(vaddr + 1, P4D_SIZE);
else
vaddr = round_up(vaddr + 1, PUD_SIZE);
remain_entropy -= entropy;
}
}
static void __meminit init_trampoline_pud(void)
{
unsigned long paddr, paddr_next;
pgd_t *pgd;
pud_t *pud_page, *pud_page_tramp;
int i;
pud_page_tramp = alloc_low_page();
paddr = 0;
pgd = pgd_offset_k((unsigned long)__va(paddr));
pud_page = (pud_t *) pgd_page_vaddr(*pgd);
for (i = pud_index(paddr); i < PTRS_PER_PUD; i++, paddr = paddr_next) {
pud_t *pud, *pud_tramp;
unsigned long vaddr = (unsigned long)__va(paddr);
pud_tramp = pud_page_tramp + pud_index(paddr);
pud = pud_page + pud_index(vaddr);
paddr_next = (paddr & PUD_MASK) + PUD_SIZE;
*pud_tramp = *pud;
}
set_pgd(&trampoline_pgd_entry,
__pgd(_KERNPG_TABLE | __pa(pud_page_tramp)));
}
static void __meminit init_trampoline_p4d(void)
{
unsigned long paddr, paddr_next;
pgd_t *pgd;
p4d_t *p4d_page, *p4d_page_tramp;
int i;
p4d_page_tramp = alloc_low_page();
paddr = 0;
pgd = pgd_offset_k((unsigned long)__va(paddr));
p4d_page = (p4d_t *) pgd_page_vaddr(*pgd);
for (i = p4d_index(paddr); i < PTRS_PER_P4D; i++, paddr = paddr_next) {
p4d_t *p4d, *p4d_tramp;
unsigned long vaddr = (unsigned long)__va(paddr);
p4d_tramp = p4d_page_tramp + p4d_index(paddr);
p4d = p4d_page + p4d_index(vaddr);
paddr_next = (paddr & P4D_MASK) + P4D_SIZE;
*p4d_tramp = *p4d;
}
set_pgd(&trampoline_pgd_entry,
__pgd(_KERNPG_TABLE | __pa(p4d_page_tramp)));
}
void __meminit init_trampoline(void)
{
if (!kaslr_memory_enabled()) {
init_trampoline_default();
return;
}
if (IS_ENABLED(CONFIG_X86_5LEVEL))
init_trampoline_p4d();
else
init_trampoline_pud();
}
