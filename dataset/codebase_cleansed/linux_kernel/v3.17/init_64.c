static void ident_pmd_init(unsigned long pmd_flag, pmd_t *pmd_page,
unsigned long addr, unsigned long end)
{
addr &= PMD_MASK;
for (; addr < end; addr += PMD_SIZE) {
pmd_t *pmd = pmd_page + pmd_index(addr);
if (!pmd_present(*pmd))
set_pmd(pmd, __pmd(addr | pmd_flag));
}
}
static int ident_pud_init(struct x86_mapping_info *info, pud_t *pud_page,
unsigned long addr, unsigned long end)
{
unsigned long next;
for (; addr < end; addr = next) {
pud_t *pud = pud_page + pud_index(addr);
pmd_t *pmd;
next = (addr & PUD_MASK) + PUD_SIZE;
if (next > end)
next = end;
if (pud_present(*pud)) {
pmd = pmd_offset(pud, 0);
ident_pmd_init(info->pmd_flag, pmd, addr, next);
continue;
}
pmd = (pmd_t *)info->alloc_pgt_page(info->context);
if (!pmd)
return -ENOMEM;
ident_pmd_init(info->pmd_flag, pmd, addr, next);
set_pud(pud, __pud(__pa(pmd) | _KERNPG_TABLE));
}
return 0;
}
int kernel_ident_mapping_init(struct x86_mapping_info *info, pgd_t *pgd_page,
unsigned long addr, unsigned long end)
{
unsigned long next;
int result;
int off = info->kernel_mapping ? pgd_index(__PAGE_OFFSET) : 0;
for (; addr < end; addr = next) {
pgd_t *pgd = pgd_page + pgd_index(addr) + off;
pud_t *pud;
next = (addr & PGDIR_MASK) + PGDIR_SIZE;
if (next > end)
next = end;
if (pgd_present(*pgd)) {
pud = pud_offset(pgd, 0);
result = ident_pud_init(info, pud, addr, next);
if (result)
return result;
continue;
}
pud = (pud_t *)info->alloc_pgt_page(info->context);
if (!pud)
return -ENOMEM;
result = ident_pud_init(info, pud, addr, next);
if (result)
return result;
set_pgd(pgd, __pgd(__pa(pud) | _KERNPG_TABLE));
}
return 0;
}
static int __init parse_direct_gbpages_off(char *arg)
{
direct_gbpages = 0;
return 0;
}
static int __init parse_direct_gbpages_on(char *arg)
{
direct_gbpages = 1;
return 0;
}
static int __init nonx32_setup(char *str)
{
if (!strcmp(str, "on"))
force_personality32 &= ~READ_IMPLIES_EXEC;
else if (!strcmp(str, "off"))
force_personality32 |= READ_IMPLIES_EXEC;
return 1;
}
void sync_global_pgds(unsigned long start, unsigned long end)
{
unsigned long address;
for (address = start; address <= end; address += PGDIR_SIZE) {
const pgd_t *pgd_ref = pgd_offset_k(address);
struct page *page;
if (pgd_none(*pgd_ref))
continue;
spin_lock(&pgd_lock);
list_for_each_entry(page, &pgd_list, lru) {
pgd_t *pgd;
spinlock_t *pgt_lock;
pgd = (pgd_t *)page_address(page) + pgd_index(address);
pgt_lock = &pgd_page_get_mm(page)->page_table_lock;
spin_lock(pgt_lock);
if (pgd_none(*pgd))
set_pgd(pgd, *pgd_ref);
else
BUG_ON(pgd_page_vaddr(*pgd)
!= pgd_page_vaddr(*pgd_ref));
spin_unlock(pgt_lock);
}
spin_unlock(&pgd_lock);
}
}
static __ref void *spp_getpage(void)
{
void *ptr;
if (after_bootmem)
ptr = (void *) get_zeroed_page(GFP_ATOMIC | __GFP_NOTRACK);
else
ptr = alloc_bootmem_pages(PAGE_SIZE);
if (!ptr || ((unsigned long)ptr & ~PAGE_MASK)) {
panic("set_pte_phys: cannot allocate page data %s\n",
after_bootmem ? "after bootmem" : "");
}
pr_debug("spp_getpage %p\n", ptr);
return ptr;
}
static pud_t *fill_pud(pgd_t *pgd, unsigned long vaddr)
{
if (pgd_none(*pgd)) {
pud_t *pud = (pud_t *)spp_getpage();
pgd_populate(&init_mm, pgd, pud);
if (pud != pud_offset(pgd, 0))
printk(KERN_ERR "PAGETABLE BUG #00! %p <-> %p\n",
pud, pud_offset(pgd, 0));
}
return pud_offset(pgd, vaddr);
}
static pmd_t *fill_pmd(pud_t *pud, unsigned long vaddr)
{
if (pud_none(*pud)) {
pmd_t *pmd = (pmd_t *) spp_getpage();
pud_populate(&init_mm, pud, pmd);
if (pmd != pmd_offset(pud, 0))
printk(KERN_ERR "PAGETABLE BUG #01! %p <-> %p\n",
pmd, pmd_offset(pud, 0));
}
return pmd_offset(pud, vaddr);
}
static pte_t *fill_pte(pmd_t *pmd, unsigned long vaddr)
{
if (pmd_none(*pmd)) {
pte_t *pte = (pte_t *) spp_getpage();
pmd_populate_kernel(&init_mm, pmd, pte);
if (pte != pte_offset_kernel(pmd, 0))
printk(KERN_ERR "PAGETABLE BUG #02!\n");
}
return pte_offset_kernel(pmd, vaddr);
}
void set_pte_vaddr_pud(pud_t *pud_page, unsigned long vaddr, pte_t new_pte)
{
pud_t *pud;
pmd_t *pmd;
pte_t *pte;
pud = pud_page + pud_index(vaddr);
pmd = fill_pmd(pud, vaddr);
pte = fill_pte(pmd, vaddr);
set_pte(pte, new_pte);
__flush_tlb_one(vaddr);
}
void set_pte_vaddr(unsigned long vaddr, pte_t pteval)
{
pgd_t *pgd;
pud_t *pud_page;
pr_debug("set_pte_vaddr %lx to %lx\n", vaddr, native_pte_val(pteval));
pgd = pgd_offset_k(vaddr);
if (pgd_none(*pgd)) {
printk(KERN_ERR
"PGD FIXMAP MISSING, it should be setup in head.S!\n");
return;
}
pud_page = (pud_t*)pgd_page_vaddr(*pgd);
set_pte_vaddr_pud(pud_page, vaddr, pteval);
}
pmd_t * __init populate_extra_pmd(unsigned long vaddr)
{
pgd_t *pgd;
pud_t *pud;
pgd = pgd_offset_k(vaddr);
pud = fill_pud(pgd, vaddr);
return fill_pmd(pud, vaddr);
}
pte_t * __init populate_extra_pte(unsigned long vaddr)
{
pmd_t *pmd;
pmd = populate_extra_pmd(vaddr);
return fill_pte(pmd, vaddr);
}
static void __init __init_extra_mapping(unsigned long phys, unsigned long size,
pgprot_t prot)
{
pgd_t *pgd;
pud_t *pud;
pmd_t *pmd;
BUG_ON((phys & ~PMD_MASK) || (size & ~PMD_MASK));
for (; size; phys += PMD_SIZE, size -= PMD_SIZE) {
pgd = pgd_offset_k((unsigned long)__va(phys));
if (pgd_none(*pgd)) {
pud = (pud_t *) spp_getpage();
set_pgd(pgd, __pgd(__pa(pud) | _KERNPG_TABLE |
_PAGE_USER));
}
pud = pud_offset(pgd, (unsigned long)__va(phys));
if (pud_none(*pud)) {
pmd = (pmd_t *) spp_getpage();
set_pud(pud, __pud(__pa(pmd) | _KERNPG_TABLE |
_PAGE_USER));
}
pmd = pmd_offset(pud, phys);
BUG_ON(!pmd_none(*pmd));
set_pmd(pmd, __pmd(phys | pgprot_val(prot)));
}
}
void __init init_extra_mapping_wb(unsigned long phys, unsigned long size)
{
__init_extra_mapping(phys, size, PAGE_KERNEL_LARGE);
}
void __init init_extra_mapping_uc(unsigned long phys, unsigned long size)
{
__init_extra_mapping(phys, size, PAGE_KERNEL_LARGE_NOCACHE);
}
void __init cleanup_highmap(void)
{
unsigned long vaddr = __START_KERNEL_map;
unsigned long vaddr_end = __START_KERNEL_map + KERNEL_IMAGE_SIZE;
unsigned long end = roundup((unsigned long)_brk_end, PMD_SIZE) - 1;
pmd_t *pmd = level2_kernel_pgt;
if (max_pfn_mapped)
vaddr_end = __START_KERNEL_map + (max_pfn_mapped << PAGE_SHIFT);
for (; vaddr + PMD_SIZE - 1 < vaddr_end; pmd++, vaddr += PMD_SIZE) {
if (pmd_none(*pmd))
continue;
if (vaddr < (unsigned long) _text || vaddr > end)
set_pmd(pmd, __pmd(0));
}
}
static unsigned long __meminit
phys_pte_init(pte_t *pte_page, unsigned long addr, unsigned long end,
pgprot_t prot)
{
unsigned long pages = 0, next;
unsigned long last_map_addr = end;
int i;
pte_t *pte = pte_page + pte_index(addr);
for (i = pte_index(addr); i < PTRS_PER_PTE; i++, addr = next, pte++) {
next = (addr & PAGE_MASK) + PAGE_SIZE;
if (addr >= end) {
if (!after_bootmem &&
!e820_any_mapped(addr & PAGE_MASK, next, E820_RAM) &&
!e820_any_mapped(addr & PAGE_MASK, next, E820_RESERVED_KERN))
set_pte(pte, __pte(0));
continue;
}
if (pte_val(*pte)) {
if (!after_bootmem)
pages++;
continue;
}
if (0)
printk(" pte=%p addr=%lx pte=%016lx\n",
pte, addr, pfn_pte(addr >> PAGE_SHIFT, PAGE_KERNEL).pte);
pages++;
set_pte(pte, pfn_pte(addr >> PAGE_SHIFT, prot));
last_map_addr = (addr & PAGE_MASK) + PAGE_SIZE;
}
update_page_count(PG_LEVEL_4K, pages);
return last_map_addr;
}
static unsigned long __meminit
phys_pmd_init(pmd_t *pmd_page, unsigned long address, unsigned long end,
unsigned long page_size_mask, pgprot_t prot)
{
unsigned long pages = 0, next;
unsigned long last_map_addr = end;
int i = pmd_index(address);
for (; i < PTRS_PER_PMD; i++, address = next) {
pmd_t *pmd = pmd_page + pmd_index(address);
pte_t *pte;
pgprot_t new_prot = prot;
next = (address & PMD_MASK) + PMD_SIZE;
if (address >= end) {
if (!after_bootmem &&
!e820_any_mapped(address & PMD_MASK, next, E820_RAM) &&
!e820_any_mapped(address & PMD_MASK, next, E820_RESERVED_KERN))
set_pmd(pmd, __pmd(0));
continue;
}
if (pmd_val(*pmd)) {
if (!pmd_large(*pmd)) {
spin_lock(&init_mm.page_table_lock);
pte = (pte_t *)pmd_page_vaddr(*pmd);
last_map_addr = phys_pte_init(pte, address,
end, prot);
spin_unlock(&init_mm.page_table_lock);
continue;
}
if (page_size_mask & (1 << PG_LEVEL_2M)) {
if (!after_bootmem)
pages++;
last_map_addr = next;
continue;
}
new_prot = pte_pgprot(pte_clrhuge(*(pte_t *)pmd));
}
if (page_size_mask & (1<<PG_LEVEL_2M)) {
pages++;
spin_lock(&init_mm.page_table_lock);
set_pte((pte_t *)pmd,
pfn_pte((address & PMD_MASK) >> PAGE_SHIFT,
__pgprot(pgprot_val(prot) | _PAGE_PSE)));
spin_unlock(&init_mm.page_table_lock);
last_map_addr = next;
continue;
}
pte = alloc_low_page();
last_map_addr = phys_pte_init(pte, address, end, new_prot);
spin_lock(&init_mm.page_table_lock);
pmd_populate_kernel(&init_mm, pmd, pte);
spin_unlock(&init_mm.page_table_lock);
}
update_page_count(PG_LEVEL_2M, pages);
return last_map_addr;
}
static unsigned long __meminit
phys_pud_init(pud_t *pud_page, unsigned long addr, unsigned long end,
unsigned long page_size_mask)
{
unsigned long pages = 0, next;
unsigned long last_map_addr = end;
int i = pud_index(addr);
for (; i < PTRS_PER_PUD; i++, addr = next) {
pud_t *pud = pud_page + pud_index(addr);
pmd_t *pmd;
pgprot_t prot = PAGE_KERNEL;
next = (addr & PUD_MASK) + PUD_SIZE;
if (addr >= end) {
if (!after_bootmem &&
!e820_any_mapped(addr & PUD_MASK, next, E820_RAM) &&
!e820_any_mapped(addr & PUD_MASK, next, E820_RESERVED_KERN))
set_pud(pud, __pud(0));
continue;
}
if (pud_val(*pud)) {
if (!pud_large(*pud)) {
pmd = pmd_offset(pud, 0);
last_map_addr = phys_pmd_init(pmd, addr, end,
page_size_mask, prot);
__flush_tlb_all();
continue;
}
if (page_size_mask & (1 << PG_LEVEL_1G)) {
if (!after_bootmem)
pages++;
last_map_addr = next;
continue;
}
prot = pte_pgprot(pte_clrhuge(*(pte_t *)pud));
}
if (page_size_mask & (1<<PG_LEVEL_1G)) {
pages++;
spin_lock(&init_mm.page_table_lock);
set_pte((pte_t *)pud,
pfn_pte((addr & PUD_MASK) >> PAGE_SHIFT,
PAGE_KERNEL_LARGE));
spin_unlock(&init_mm.page_table_lock);
last_map_addr = next;
continue;
}
pmd = alloc_low_page();
last_map_addr = phys_pmd_init(pmd, addr, end, page_size_mask,
prot);
spin_lock(&init_mm.page_table_lock);
pud_populate(&init_mm, pud, pmd);
spin_unlock(&init_mm.page_table_lock);
}
__flush_tlb_all();
update_page_count(PG_LEVEL_1G, pages);
return last_map_addr;
}
unsigned long __meminit
kernel_physical_mapping_init(unsigned long start,
unsigned long end,
unsigned long page_size_mask)
{
bool pgd_changed = false;
unsigned long next, last_map_addr = end;
unsigned long addr;
start = (unsigned long)__va(start);
end = (unsigned long)__va(end);
addr = start;
for (; start < end; start = next) {
pgd_t *pgd = pgd_offset_k(start);
pud_t *pud;
next = (start & PGDIR_MASK) + PGDIR_SIZE;
if (pgd_val(*pgd)) {
pud = (pud_t *)pgd_page_vaddr(*pgd);
last_map_addr = phys_pud_init(pud, __pa(start),
__pa(end), page_size_mask);
continue;
}
pud = alloc_low_page();
last_map_addr = phys_pud_init(pud, __pa(start), __pa(end),
page_size_mask);
spin_lock(&init_mm.page_table_lock);
pgd_populate(&init_mm, pgd, pud);
spin_unlock(&init_mm.page_table_lock);
pgd_changed = true;
}
if (pgd_changed)
sync_global_pgds(addr, end - 1);
__flush_tlb_all();
return last_map_addr;
}
void __init initmem_init(void)
{
memblock_set_node(0, (phys_addr_t)ULLONG_MAX, &memblock.memory, 0);
}
void __init paging_init(void)
{
sparse_memory_present_with_active_regions(MAX_NUMNODES);
sparse_init();
node_clear_state(0, N_MEMORY);
if (N_MEMORY != N_NORMAL_MEMORY)
node_clear_state(0, N_NORMAL_MEMORY);
zone_sizes_init();
}
static void update_end_of_memory_vars(u64 start, u64 size)
{
unsigned long end_pfn = PFN_UP(start + size);
if (end_pfn > max_pfn) {
max_pfn = end_pfn;
max_low_pfn = end_pfn;
high_memory = (void *)__va(max_pfn * PAGE_SIZE - 1) + 1;
}
}
int arch_add_memory(int nid, u64 start, u64 size)
{
struct pglist_data *pgdat = NODE_DATA(nid);
struct zone *zone = pgdat->node_zones +
zone_for_memory(nid, start, size, ZONE_NORMAL);
unsigned long start_pfn = start >> PAGE_SHIFT;
unsigned long nr_pages = size >> PAGE_SHIFT;
int ret;
init_memory_mapping(start, start + size);
ret = __add_pages(nid, zone, start_pfn, nr_pages);
WARN_ON_ONCE(ret);
update_end_of_memory_vars(start, size);
return ret;
}
static void __meminit free_pagetable(struct page *page, int order)
{
unsigned long magic;
unsigned int nr_pages = 1 << order;
if (PageReserved(page)) {
__ClearPageReserved(page);
magic = (unsigned long)page->lru.next;
if (magic == SECTION_INFO || magic == MIX_SECTION_INFO) {
while (nr_pages--)
put_page_bootmem(page++);
} else
while (nr_pages--)
free_reserved_page(page++);
} else
free_pages((unsigned long)page_address(page), order);
}
static void __meminit free_pte_table(pte_t *pte_start, pmd_t *pmd)
{
pte_t *pte;
int i;
for (i = 0; i < PTRS_PER_PTE; i++) {
pte = pte_start + i;
if (pte_val(*pte))
return;
}
free_pagetable(pmd_page(*pmd), 0);
spin_lock(&init_mm.page_table_lock);
pmd_clear(pmd);
spin_unlock(&init_mm.page_table_lock);
}
static void __meminit free_pmd_table(pmd_t *pmd_start, pud_t *pud)
{
pmd_t *pmd;
int i;
for (i = 0; i < PTRS_PER_PMD; i++) {
pmd = pmd_start + i;
if (pmd_val(*pmd))
return;
}
free_pagetable(pud_page(*pud), 0);
spin_lock(&init_mm.page_table_lock);
pud_clear(pud);
spin_unlock(&init_mm.page_table_lock);
}
static bool __meminit free_pud_table(pud_t *pud_start, pgd_t *pgd)
{
pud_t *pud;
int i;
for (i = 0; i < PTRS_PER_PUD; i++) {
pud = pud_start + i;
if (pud_val(*pud))
return false;
}
free_pagetable(pgd_page(*pgd), 0);
spin_lock(&init_mm.page_table_lock);
pgd_clear(pgd);
spin_unlock(&init_mm.page_table_lock);
return true;
}
static void __meminit
remove_pte_table(pte_t *pte_start, unsigned long addr, unsigned long end,
bool direct)
{
unsigned long next, pages = 0;
pte_t *pte;
void *page_addr;
phys_addr_t phys_addr;
pte = pte_start + pte_index(addr);
for (; addr < end; addr = next, pte++) {
next = (addr + PAGE_SIZE) & PAGE_MASK;
if (next > end)
next = end;
if (!pte_present(*pte))
continue;
phys_addr = pte_val(*pte) + (addr & PAGE_MASK);
if (phys_addr < (phys_addr_t)0x40000000)
return;
if (IS_ALIGNED(addr, PAGE_SIZE) &&
IS_ALIGNED(next, PAGE_SIZE)) {
if (!direct)
free_pagetable(pte_page(*pte), 0);
spin_lock(&init_mm.page_table_lock);
pte_clear(&init_mm, addr, pte);
spin_unlock(&init_mm.page_table_lock);
pages++;
} else {
memset((void *)addr, PAGE_INUSE, next - addr);
page_addr = page_address(pte_page(*pte));
if (!memchr_inv(page_addr, PAGE_INUSE, PAGE_SIZE)) {
free_pagetable(pte_page(*pte), 0);
spin_lock(&init_mm.page_table_lock);
pte_clear(&init_mm, addr, pte);
spin_unlock(&init_mm.page_table_lock);
}
}
}
flush_tlb_all();
if (direct)
update_page_count(PG_LEVEL_4K, -pages);
}
static void __meminit
remove_pmd_table(pmd_t *pmd_start, unsigned long addr, unsigned long end,
bool direct)
{
unsigned long next, pages = 0;
pte_t *pte_base;
pmd_t *pmd;
void *page_addr;
pmd = pmd_start + pmd_index(addr);
for (; addr < end; addr = next, pmd++) {
next = pmd_addr_end(addr, end);
if (!pmd_present(*pmd))
continue;
if (pmd_large(*pmd)) {
if (IS_ALIGNED(addr, PMD_SIZE) &&
IS_ALIGNED(next, PMD_SIZE)) {
if (!direct)
free_pagetable(pmd_page(*pmd),
get_order(PMD_SIZE));
spin_lock(&init_mm.page_table_lock);
pmd_clear(pmd);
spin_unlock(&init_mm.page_table_lock);
pages++;
} else {
memset((void *)addr, PAGE_INUSE, next - addr);
page_addr = page_address(pmd_page(*pmd));
if (!memchr_inv(page_addr, PAGE_INUSE,
PMD_SIZE)) {
free_pagetable(pmd_page(*pmd),
get_order(PMD_SIZE));
spin_lock(&init_mm.page_table_lock);
pmd_clear(pmd);
spin_unlock(&init_mm.page_table_lock);
}
}
continue;
}
pte_base = (pte_t *)pmd_page_vaddr(*pmd);
remove_pte_table(pte_base, addr, next, direct);
free_pte_table(pte_base, pmd);
}
if (direct)
update_page_count(PG_LEVEL_2M, -pages);
}
static void __meminit
remove_pud_table(pud_t *pud_start, unsigned long addr, unsigned long end,
bool direct)
{
unsigned long next, pages = 0;
pmd_t *pmd_base;
pud_t *pud;
void *page_addr;
pud = pud_start + pud_index(addr);
for (; addr < end; addr = next, pud++) {
next = pud_addr_end(addr, end);
if (!pud_present(*pud))
continue;
if (pud_large(*pud)) {
if (IS_ALIGNED(addr, PUD_SIZE) &&
IS_ALIGNED(next, PUD_SIZE)) {
if (!direct)
free_pagetable(pud_page(*pud),
get_order(PUD_SIZE));
spin_lock(&init_mm.page_table_lock);
pud_clear(pud);
spin_unlock(&init_mm.page_table_lock);
pages++;
} else {
memset((void *)addr, PAGE_INUSE, next - addr);
page_addr = page_address(pud_page(*pud));
if (!memchr_inv(page_addr, PAGE_INUSE,
PUD_SIZE)) {
free_pagetable(pud_page(*pud),
get_order(PUD_SIZE));
spin_lock(&init_mm.page_table_lock);
pud_clear(pud);
spin_unlock(&init_mm.page_table_lock);
}
}
continue;
}
pmd_base = (pmd_t *)pud_page_vaddr(*pud);
remove_pmd_table(pmd_base, addr, next, direct);
free_pmd_table(pmd_base, pud);
}
if (direct)
update_page_count(PG_LEVEL_1G, -pages);
}
static void __meminit
remove_pagetable(unsigned long start, unsigned long end, bool direct)
{
unsigned long next;
pgd_t *pgd;
pud_t *pud;
bool pgd_changed = false;
for (; start < end; start = next) {
next = pgd_addr_end(start, end);
pgd = pgd_offset_k(start);
if (!pgd_present(*pgd))
continue;
pud = (pud_t *)pgd_page_vaddr(*pgd);
remove_pud_table(pud, start, next, direct);
if (free_pud_table(pud, pgd))
pgd_changed = true;
}
if (pgd_changed)
sync_global_pgds(start, end - 1);
flush_tlb_all();
}
void __ref vmemmap_free(unsigned long start, unsigned long end)
{
remove_pagetable(start, end, false);
}
static void __meminit
kernel_physical_mapping_remove(unsigned long start, unsigned long end)
{
start = (unsigned long)__va(start);
end = (unsigned long)__va(end);
remove_pagetable(start, end, true);
}
int __ref arch_remove_memory(u64 start, u64 size)
{
unsigned long start_pfn = start >> PAGE_SHIFT;
unsigned long nr_pages = size >> PAGE_SHIFT;
struct zone *zone;
int ret;
zone = page_zone(pfn_to_page(start_pfn));
kernel_physical_mapping_remove(start, start + size);
ret = __remove_pages(zone, start_pfn, nr_pages);
WARN_ON_ONCE(ret);
return ret;
}
static void __init register_page_bootmem_info(void)
{
#ifdef CONFIG_NUMA
int i;
for_each_online_node(i)
register_page_bootmem_info_node(NODE_DATA(i));
#endif
}
void __init mem_init(void)
{
pci_iommu_alloc();
register_page_bootmem_info();
free_all_bootmem();
after_bootmem = 1;
kclist_add(&kcore_vsyscall, (void *)VSYSCALL_ADDR,
PAGE_SIZE, KCORE_OTHER);
mem_init_print_info(NULL);
}
void set_kernel_text_rw(void)
{
unsigned long start = PFN_ALIGN(_text);
unsigned long end = PFN_ALIGN(__stop___ex_table);
if (!kernel_set_to_readonly)
return;
pr_debug("Set kernel text: %lx - %lx for read write\n",
start, end);
set_memory_rw(start, (end - start) >> PAGE_SHIFT);
}
void set_kernel_text_ro(void)
{
unsigned long start = PFN_ALIGN(_text);
unsigned long end = PFN_ALIGN(__stop___ex_table);
if (!kernel_set_to_readonly)
return;
pr_debug("Set kernel text: %lx - %lx for read only\n",
start, end);
set_memory_ro(start, (end - start) >> PAGE_SHIFT);
}
void mark_rodata_ro(void)
{
unsigned long start = PFN_ALIGN(_text);
unsigned long rodata_start = PFN_ALIGN(__start_rodata);
unsigned long end = (unsigned long) &__end_rodata_hpage_align;
unsigned long text_end = PFN_ALIGN(&__stop___ex_table);
unsigned long rodata_end = PFN_ALIGN(&__end_rodata);
unsigned long all_end = PFN_ALIGN(&_end);
printk(KERN_INFO "Write protecting the kernel read-only data: %luk\n",
(end - start) >> 10);
set_memory_ro(start, (end - start) >> PAGE_SHIFT);
kernel_set_to_readonly = 1;
set_memory_nx(rodata_start, (all_end - rodata_start) >> PAGE_SHIFT);
rodata_test();
#ifdef CONFIG_CPA_DEBUG
printk(KERN_INFO "Testing CPA: undo %lx-%lx\n", start, end);
set_memory_rw(start, (end-start) >> PAGE_SHIFT);
printk(KERN_INFO "Testing CPA: again\n");
set_memory_ro(start, (end-start) >> PAGE_SHIFT);
#endif
free_init_pages("unused kernel",
(unsigned long) __va(__pa_symbol(text_end)),
(unsigned long) __va(__pa_symbol(rodata_start)));
free_init_pages("unused kernel",
(unsigned long) __va(__pa_symbol(rodata_end)),
(unsigned long) __va(__pa_symbol(_sdata)));
}
int kern_addr_valid(unsigned long addr)
{
unsigned long above = ((long)addr) >> __VIRTUAL_MASK_SHIFT;
pgd_t *pgd;
pud_t *pud;
pmd_t *pmd;
pte_t *pte;
if (above != 0 && above != -1UL)
return 0;
pgd = pgd_offset_k(addr);
if (pgd_none(*pgd))
return 0;
pud = pud_offset(pgd, addr);
if (pud_none(*pud))
return 0;
if (pud_large(*pud))
return pfn_valid(pud_pfn(*pud));
pmd = pmd_offset(pud, addr);
if (pmd_none(*pmd))
return 0;
if (pmd_large(*pmd))
return pfn_valid(pmd_pfn(*pmd));
pte = pte_offset_kernel(pmd, addr);
if (pte_none(*pte))
return 0;
return pfn_valid(pte_pfn(*pte));
}
static const char *gate_vma_name(struct vm_area_struct *vma)
{
return "[vsyscall]";
}
struct vm_area_struct *get_gate_vma(struct mm_struct *mm)
{
#ifdef CONFIG_IA32_EMULATION
if (!mm || mm->context.ia32_compat)
return NULL;
#endif
return &gate_vma;
}
int in_gate_area(struct mm_struct *mm, unsigned long addr)
{
struct vm_area_struct *vma = get_gate_vma(mm);
if (!vma)
return 0;
return (addr >= vma->vm_start) && (addr < vma->vm_end);
}
int in_gate_area_no_mm(unsigned long addr)
{
return (addr & PAGE_MASK) == VSYSCALL_ADDR;
}
static unsigned long probe_memory_block_size(void)
{
unsigned long bz = 1UL<<31;
#ifdef CONFIG_X86_UV
if (is_uv_system()) {
printk(KERN_INFO "UV: memory block size 2GB\n");
return 2UL * 1024 * 1024 * 1024;
}
#endif
if ((max_pfn << PAGE_SHIFT) < (16UL << 32))
return MIN_MEMORY_BLOCK_SIZE;
while (bz > MIN_MEMORY_BLOCK_SIZE) {
if (!((max_pfn << PAGE_SHIFT) & (bz - 1)))
break;
bz >>= 1;
}
printk(KERN_DEBUG "memory block size : %ldMB\n", bz >> 20);
return bz;
}
unsigned long memory_block_size_bytes(void)
{
if (!memory_block_size_probed)
memory_block_size_probed = probe_memory_block_size();
return memory_block_size_probed;
}
static int __meminit vmemmap_populate_hugepages(unsigned long start,
unsigned long end, int node)
{
unsigned long addr;
unsigned long next;
pgd_t *pgd;
pud_t *pud;
pmd_t *pmd;
for (addr = start; addr < end; addr = next) {
next = pmd_addr_end(addr, end);
pgd = vmemmap_pgd_populate(addr, node);
if (!pgd)
return -ENOMEM;
pud = vmemmap_pud_populate(pgd, addr, node);
if (!pud)
return -ENOMEM;
pmd = pmd_offset(pud, addr);
if (pmd_none(*pmd)) {
void *p;
p = vmemmap_alloc_block_buf(PMD_SIZE, node);
if (p) {
pte_t entry;
entry = pfn_pte(__pa(p) >> PAGE_SHIFT,
PAGE_KERNEL_LARGE);
set_pmd(pmd, __pmd(pte_val(entry)));
if (p_end != p || node_start != node) {
if (p_start)
printk(KERN_DEBUG " [%lx-%lx] PMD -> [%p-%p] on node %d\n",
addr_start, addr_end-1, p_start, p_end-1, node_start);
addr_start = addr;
node_start = node;
p_start = p;
}
addr_end = addr + PMD_SIZE;
p_end = p + PMD_SIZE;
continue;
}
} else if (pmd_large(*pmd)) {
vmemmap_verify((pte_t *)pmd, node, addr, next);
continue;
}
pr_warn_once("vmemmap: falling back to regular page backing\n");
if (vmemmap_populate_basepages(addr, next, node))
return -ENOMEM;
}
return 0;
}
int __meminit vmemmap_populate(unsigned long start, unsigned long end, int node)
{
int err;
if (cpu_has_pse)
err = vmemmap_populate_hugepages(start, end, node);
else
err = vmemmap_populate_basepages(start, end, node);
if (!err)
sync_global_pgds(start, end - 1);
return err;
}
void register_page_bootmem_memmap(unsigned long section_nr,
struct page *start_page, unsigned long size)
{
unsigned long addr = (unsigned long)start_page;
unsigned long end = (unsigned long)(start_page + size);
unsigned long next;
pgd_t *pgd;
pud_t *pud;
pmd_t *pmd;
unsigned int nr_pages;
struct page *page;
for (; addr < end; addr = next) {
pte_t *pte = NULL;
pgd = pgd_offset_k(addr);
if (pgd_none(*pgd)) {
next = (addr + PAGE_SIZE) & PAGE_MASK;
continue;
}
get_page_bootmem(section_nr, pgd_page(*pgd), MIX_SECTION_INFO);
pud = pud_offset(pgd, addr);
if (pud_none(*pud)) {
next = (addr + PAGE_SIZE) & PAGE_MASK;
continue;
}
get_page_bootmem(section_nr, pud_page(*pud), MIX_SECTION_INFO);
if (!cpu_has_pse) {
next = (addr + PAGE_SIZE) & PAGE_MASK;
pmd = pmd_offset(pud, addr);
if (pmd_none(*pmd))
continue;
get_page_bootmem(section_nr, pmd_page(*pmd),
MIX_SECTION_INFO);
pte = pte_offset_kernel(pmd, addr);
if (pte_none(*pte))
continue;
get_page_bootmem(section_nr, pte_page(*pte),
SECTION_INFO);
} else {
next = pmd_addr_end(addr, end);
pmd = pmd_offset(pud, addr);
if (pmd_none(*pmd))
continue;
nr_pages = 1 << (get_order(PMD_SIZE));
page = pmd_page(*pmd);
while (nr_pages--)
get_page_bootmem(section_nr, page++,
SECTION_INFO);
}
}
}
void __meminit vmemmap_populate_print_last(void)
{
if (p_start) {
printk(KERN_DEBUG " [%lx-%lx] PMD -> [%p-%p] on node %d\n",
addr_start, addr_end-1, p_start, p_end-1, node_start);
p_start = NULL;
p_end = NULL;
node_start = 0;
}
}
