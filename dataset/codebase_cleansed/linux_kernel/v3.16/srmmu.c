static inline int srmmu_pmd_none(pmd_t pmd)
{ return !(pmd_val(pmd) & 0xFFFFFFF); }
static inline void srmmu_ctxd_set(ctxd_t *ctxp, pgd_t *pgdp)
{ set_pte((pte_t *)ctxp, (SRMMU_ET_PTD | (__nocache_pa((unsigned long) pgdp) >> 4))); }
void pmd_set(pmd_t *pmdp, pte_t *ptep)
{
unsigned long ptp;
int i;
ptp = __nocache_pa((unsigned long) ptep) >> 4;
for (i = 0; i < PTRS_PER_PTE/SRMMU_REAL_PTRS_PER_PTE; i++) {
set_pte((pte_t *)&pmdp->pmdv[i], SRMMU_ET_PTD | ptp);
ptp += (SRMMU_REAL_PTRS_PER_PTE*sizeof(pte_t) >> 4);
}
}
void pmd_populate(struct mm_struct *mm, pmd_t *pmdp, struct page *ptep)
{
unsigned long ptp;
int i;
ptp = page_to_pfn(ptep) << (PAGE_SHIFT-4);
for (i = 0; i < PTRS_PER_PTE/SRMMU_REAL_PTRS_PER_PTE; i++) {
set_pte((pte_t *)&pmdp->pmdv[i], SRMMU_ET_PTD | ptp);
ptp += (SRMMU_REAL_PTRS_PER_PTE*sizeof(pte_t) >> 4);
}
}
pte_t *pte_offset_kernel(pmd_t *dir, unsigned long address)
{
void *pte;
pte = __nocache_va((dir->pmdv[0] & SRMMU_PTD_PMASK) << 4);
return (pte_t *) pte +
((address >> PAGE_SHIFT) & (PTRS_PER_PTE - 1));
}
static void *__srmmu_get_nocache(int size, int align)
{
int offset;
unsigned long addr;
if (size < SRMMU_NOCACHE_BITMAP_SHIFT) {
printk(KERN_ERR "Size 0x%x too small for nocache request\n",
size);
size = SRMMU_NOCACHE_BITMAP_SHIFT;
}
if (size & (SRMMU_NOCACHE_BITMAP_SHIFT - 1)) {
printk(KERN_ERR "Size 0x%x unaligned int nocache request\n",
size);
size += SRMMU_NOCACHE_BITMAP_SHIFT - 1;
}
BUG_ON(align > SRMMU_NOCACHE_ALIGN_MAX);
offset = bit_map_string_get(&srmmu_nocache_map,
size >> SRMMU_NOCACHE_BITMAP_SHIFT,
align >> SRMMU_NOCACHE_BITMAP_SHIFT);
if (offset == -1) {
printk(KERN_ERR "srmmu: out of nocache %d: %d/%d\n",
size, (int) srmmu_nocache_size,
srmmu_nocache_map.used << SRMMU_NOCACHE_BITMAP_SHIFT);
return NULL;
}
addr = SRMMU_NOCACHE_VADDR + (offset << SRMMU_NOCACHE_BITMAP_SHIFT);
return (void *)addr;
}
void *srmmu_get_nocache(int size, int align)
{
void *tmp;
tmp = __srmmu_get_nocache(size, align);
if (tmp)
memset(tmp, 0, size);
return tmp;
}
void srmmu_free_nocache(void *addr, int size)
{
unsigned long vaddr;
int offset;
vaddr = (unsigned long)addr;
if (vaddr < SRMMU_NOCACHE_VADDR) {
printk("Vaddr %lx is smaller than nocache base 0x%lx\n",
vaddr, (unsigned long)SRMMU_NOCACHE_VADDR);
BUG();
}
if (vaddr + size > srmmu_nocache_end) {
printk("Vaddr %lx is bigger than nocache end 0x%lx\n",
vaddr, srmmu_nocache_end);
BUG();
}
if (!is_power_of_2(size)) {
printk("Size 0x%x is not a power of 2\n", size);
BUG();
}
if (size < SRMMU_NOCACHE_BITMAP_SHIFT) {
printk("Size 0x%x is too small\n", size);
BUG();
}
if (vaddr & (size - 1)) {
printk("Vaddr %lx is not aligned to size 0x%x\n", vaddr, size);
BUG();
}
offset = (vaddr - SRMMU_NOCACHE_VADDR) >> SRMMU_NOCACHE_BITMAP_SHIFT;
size = size >> SRMMU_NOCACHE_BITMAP_SHIFT;
bit_map_clear(&srmmu_nocache_map, offset, size);
}
static unsigned long __init probe_memory(void)
{
unsigned long total = 0;
int i;
for (i = 0; sp_banks[i].num_bytes; i++)
total += sp_banks[i].num_bytes;
return total;
}
static void __init srmmu_nocache_calcsize(void)
{
unsigned long sysmemavail = probe_memory() / 1024;
int srmmu_nocache_npages;
srmmu_nocache_npages =
sysmemavail / SRMMU_NOCACHE_ALCRATIO / 1024 * 256;
if (srmmu_nocache_npages < SRMMU_MIN_NOCACHE_PAGES)
srmmu_nocache_npages = SRMMU_MIN_NOCACHE_PAGES;
if (srmmu_nocache_npages > SRMMU_MAX_NOCACHE_PAGES)
srmmu_nocache_npages = SRMMU_MAX_NOCACHE_PAGES;
srmmu_nocache_size = srmmu_nocache_npages * PAGE_SIZE;
srmmu_nocache_end = SRMMU_NOCACHE_VADDR + srmmu_nocache_size;
}
static void __init srmmu_nocache_init(void)
{
void *srmmu_nocache_bitmap;
unsigned int bitmap_bits;
pgd_t *pgd;
pmd_t *pmd;
pte_t *pte;
unsigned long paddr, vaddr;
unsigned long pteval;
bitmap_bits = srmmu_nocache_size >> SRMMU_NOCACHE_BITMAP_SHIFT;
srmmu_nocache_pool = __alloc_bootmem(srmmu_nocache_size,
SRMMU_NOCACHE_ALIGN_MAX, 0UL);
memset(srmmu_nocache_pool, 0, srmmu_nocache_size);
srmmu_nocache_bitmap =
__alloc_bootmem(BITS_TO_LONGS(bitmap_bits) * sizeof(long),
SMP_CACHE_BYTES, 0UL);
bit_map_init(&srmmu_nocache_map, srmmu_nocache_bitmap, bitmap_bits);
srmmu_swapper_pg_dir = __srmmu_get_nocache(SRMMU_PGD_TABLE_SIZE, SRMMU_PGD_TABLE_SIZE);
memset(__nocache_fix(srmmu_swapper_pg_dir), 0, SRMMU_PGD_TABLE_SIZE);
init_mm.pgd = srmmu_swapper_pg_dir;
srmmu_early_allocate_ptable_skeleton(SRMMU_NOCACHE_VADDR, srmmu_nocache_end);
paddr = __pa((unsigned long)srmmu_nocache_pool);
vaddr = SRMMU_NOCACHE_VADDR;
while (vaddr < srmmu_nocache_end) {
pgd = pgd_offset_k(vaddr);
pmd = pmd_offset(__nocache_fix(pgd), vaddr);
pte = pte_offset_kernel(__nocache_fix(pmd), vaddr);
pteval = ((paddr >> 4) | SRMMU_ET_PTE | SRMMU_PRIV);
if (srmmu_cache_pagetables)
pteval |= SRMMU_CACHE;
set_pte(__nocache_fix(pte), __pte(pteval));
vaddr += PAGE_SIZE;
paddr += PAGE_SIZE;
}
flush_cache_all();
flush_tlb_all();
}
pgd_t *get_pgd_fast(void)
{
pgd_t *pgd = NULL;
pgd = __srmmu_get_nocache(SRMMU_PGD_TABLE_SIZE, SRMMU_PGD_TABLE_SIZE);
if (pgd) {
pgd_t *init = pgd_offset_k(0);
memset(pgd, 0, USER_PTRS_PER_PGD * sizeof(pgd_t));
memcpy(pgd + USER_PTRS_PER_PGD, init + USER_PTRS_PER_PGD,
(PTRS_PER_PGD - USER_PTRS_PER_PGD) * sizeof(pgd_t));
}
return pgd;
}
pgtable_t pte_alloc_one(struct mm_struct *mm, unsigned long address)
{
unsigned long pte;
struct page *page;
if ((pte = (unsigned long)pte_alloc_one_kernel(mm, address)) == 0)
return NULL;
page = pfn_to_page(__nocache_pa(pte) >> PAGE_SHIFT);
if (!pgtable_page_ctor(page)) {
__free_page(page);
return NULL;
}
return page;
}
void pte_free(struct mm_struct *mm, pgtable_t pte)
{
unsigned long p;
pgtable_page_dtor(pte);
p = (unsigned long)page_address(pte);
if (p == 0)
BUG();
p = page_to_pfn(pte) << PAGE_SHIFT;
srmmu_free_nocache(__nocache_va(p), PTE_SIZE);
}
static inline void remove_from_ctx_list(struct ctx_list *entry)
{
entry->next->prev = entry->prev;
entry->prev->next = entry->next;
}
static inline void add_to_ctx_list(struct ctx_list *head, struct ctx_list *entry)
{
entry->next = head;
(entry->prev = head->prev)->next = entry;
head->prev = entry;
}
static inline void alloc_context(struct mm_struct *old_mm, struct mm_struct *mm)
{
struct ctx_list *ctxp;
ctxp = ctx_free.next;
if (ctxp != &ctx_free) {
remove_from_ctx_list(ctxp);
add_to_used_ctxlist(ctxp);
mm->context = ctxp->ctx_number;
ctxp->ctx_mm = mm;
return;
}
ctxp = ctx_used.next;
if (ctxp->ctx_mm == old_mm)
ctxp = ctxp->next;
if (ctxp == &ctx_used)
panic("out of mmu contexts");
flush_cache_mm(ctxp->ctx_mm);
flush_tlb_mm(ctxp->ctx_mm);
remove_from_ctx_list(ctxp);
add_to_used_ctxlist(ctxp);
ctxp->ctx_mm->context = NO_CONTEXT;
ctxp->ctx_mm = mm;
mm->context = ctxp->ctx_number;
}
static inline void free_context(int context)
{
struct ctx_list *ctx_old;
ctx_old = ctx_list_pool + context;
remove_from_ctx_list(ctx_old);
add_to_free_ctxlist(ctx_old);
}
static void __init sparc_context_init(int numctx)
{
int ctx;
unsigned long size;
size = numctx * sizeof(struct ctx_list);
ctx_list_pool = __alloc_bootmem(size, SMP_CACHE_BYTES, 0UL);
for (ctx = 0; ctx < numctx; ctx++) {
struct ctx_list *clist;
clist = (ctx_list_pool + ctx);
clist->ctx_number = ctx;
clist->ctx_mm = NULL;
}
ctx_free.next = ctx_free.prev = &ctx_free;
ctx_used.next = ctx_used.prev = &ctx_used;
for (ctx = 0; ctx < numctx; ctx++)
add_to_free_ctxlist(ctx_list_pool + ctx);
}
void switch_mm(struct mm_struct *old_mm, struct mm_struct *mm,
struct task_struct *tsk)
{
if (mm->context == NO_CONTEXT) {
spin_lock(&srmmu_context_spinlock);
alloc_context(old_mm, mm);
spin_unlock(&srmmu_context_spinlock);
srmmu_ctxd_set(&srmmu_context_table[mm->context], mm->pgd);
}
if (sparc_cpu_model == sparc_leon)
leon_switch_mm();
if (is_hypersparc)
hyper_flush_whole_icache();
srmmu_set_context(mm->context);
}
static inline void srmmu_mapioaddr(unsigned long physaddr,
unsigned long virt_addr, int bus_type)
{
pgd_t *pgdp;
pmd_t *pmdp;
pte_t *ptep;
unsigned long tmp;
physaddr &= PAGE_MASK;
pgdp = pgd_offset_k(virt_addr);
pmdp = pmd_offset(pgdp, virt_addr);
ptep = pte_offset_kernel(pmdp, virt_addr);
tmp = (physaddr >> 4) | SRMMU_ET_PTE;
tmp |= (bus_type << 28);
tmp |= SRMMU_PRIV;
__flush_page_to_ram(virt_addr);
set_pte(ptep, __pte(tmp));
}
void srmmu_mapiorange(unsigned int bus, unsigned long xpa,
unsigned long xva, unsigned int len)
{
while (len != 0) {
len -= PAGE_SIZE;
srmmu_mapioaddr(xpa, xva, bus);
xva += PAGE_SIZE;
xpa += PAGE_SIZE;
}
flush_tlb_all();
}
static inline void srmmu_unmapioaddr(unsigned long virt_addr)
{
pgd_t *pgdp;
pmd_t *pmdp;
pte_t *ptep;
pgdp = pgd_offset_k(virt_addr);
pmdp = pmd_offset(pgdp, virt_addr);
ptep = pte_offset_kernel(pmdp, virt_addr);
__pte_clear(ptep);
}
void srmmu_unmapiorange(unsigned long virt_addr, unsigned int len)
{
while (len != 0) {
len -= PAGE_SIZE;
srmmu_unmapioaddr(virt_addr);
virt_addr += PAGE_SIZE;
}
flush_tlb_all();
}
static void __init early_pgtable_allocfail(char *type)
{
prom_printf("inherit_prom_mappings: Cannot alloc kernel %s.\n", type);
prom_halt();
}
static void __init srmmu_early_allocate_ptable_skeleton(unsigned long start,
unsigned long end)
{
pgd_t *pgdp;
pmd_t *pmdp;
pte_t *ptep;
while (start < end) {
pgdp = pgd_offset_k(start);
if (pgd_none(*(pgd_t *)__nocache_fix(pgdp))) {
pmdp = __srmmu_get_nocache(
SRMMU_PMD_TABLE_SIZE, SRMMU_PMD_TABLE_SIZE);
if (pmdp == NULL)
early_pgtable_allocfail("pmd");
memset(__nocache_fix(pmdp), 0, SRMMU_PMD_TABLE_SIZE);
pgd_set(__nocache_fix(pgdp), pmdp);
}
pmdp = pmd_offset(__nocache_fix(pgdp), start);
if (srmmu_pmd_none(*(pmd_t *)__nocache_fix(pmdp))) {
ptep = __srmmu_get_nocache(PTE_SIZE, PTE_SIZE);
if (ptep == NULL)
early_pgtable_allocfail("pte");
memset(__nocache_fix(ptep), 0, PTE_SIZE);
pmd_set(__nocache_fix(pmdp), ptep);
}
if (start > (0xffffffffUL - PMD_SIZE))
break;
start = (start + PMD_SIZE) & PMD_MASK;
}
}
static void __init srmmu_allocate_ptable_skeleton(unsigned long start,
unsigned long end)
{
pgd_t *pgdp;
pmd_t *pmdp;
pte_t *ptep;
while (start < end) {
pgdp = pgd_offset_k(start);
if (pgd_none(*pgdp)) {
pmdp = __srmmu_get_nocache(SRMMU_PMD_TABLE_SIZE, SRMMU_PMD_TABLE_SIZE);
if (pmdp == NULL)
early_pgtable_allocfail("pmd");
memset(pmdp, 0, SRMMU_PMD_TABLE_SIZE);
pgd_set(pgdp, pmdp);
}
pmdp = pmd_offset(pgdp, start);
if (srmmu_pmd_none(*pmdp)) {
ptep = __srmmu_get_nocache(PTE_SIZE,
PTE_SIZE);
if (ptep == NULL)
early_pgtable_allocfail("pte");
memset(ptep, 0, PTE_SIZE);
pmd_set(pmdp, ptep);
}
if (start > (0xffffffffUL - PMD_SIZE))
break;
start = (start + PMD_SIZE) & PMD_MASK;
}
}
static inline unsigned long srmmu_probe(unsigned long vaddr)
{
unsigned long retval;
if (sparc_cpu_model != sparc_leon) {
vaddr &= PAGE_MASK;
__asm__ __volatile__("lda [%1] %2, %0\n\t" :
"=r" (retval) :
"r" (vaddr | 0x400), "i" (ASI_M_FLUSH_PROBE));
} else {
retval = leon_swprobe(vaddr, NULL);
}
return retval;
}
static void __init srmmu_inherit_prom_mappings(unsigned long start,
unsigned long end)
{
unsigned long probed;
unsigned long addr;
pgd_t *pgdp;
pmd_t *pmdp;
pte_t *ptep;
int what;
while (start <= end) {
if (start == 0)
break;
if (start == 0xfef00000)
start = KADB_DEBUGGER_BEGVM;
probed = srmmu_probe(start);
if (!probed) {
start += PAGE_SIZE;
continue;
}
what = 0;
addr = start - PAGE_SIZE;
if (!(start & ~(SRMMU_REAL_PMD_MASK))) {
if (srmmu_probe(addr + SRMMU_REAL_PMD_SIZE) == probed)
what = 1;
}
if (!(start & ~(SRMMU_PGDIR_MASK))) {
if (srmmu_probe(addr + SRMMU_PGDIR_SIZE) == probed)
what = 2;
}
pgdp = pgd_offset_k(start);
if (what == 2) {
*(pgd_t *)__nocache_fix(pgdp) = __pgd(probed);
start += SRMMU_PGDIR_SIZE;
continue;
}
if (pgd_none(*(pgd_t *)__nocache_fix(pgdp))) {
pmdp = __srmmu_get_nocache(SRMMU_PMD_TABLE_SIZE,
SRMMU_PMD_TABLE_SIZE);
if (pmdp == NULL)
early_pgtable_allocfail("pmd");
memset(__nocache_fix(pmdp), 0, SRMMU_PMD_TABLE_SIZE);
pgd_set(__nocache_fix(pgdp), pmdp);
}
pmdp = pmd_offset(__nocache_fix(pgdp), start);
if (srmmu_pmd_none(*(pmd_t *)__nocache_fix(pmdp))) {
ptep = __srmmu_get_nocache(PTE_SIZE, PTE_SIZE);
if (ptep == NULL)
early_pgtable_allocfail("pte");
memset(__nocache_fix(ptep), 0, PTE_SIZE);
pmd_set(__nocache_fix(pmdp), ptep);
}
if (what == 1) {
unsigned int x;
unsigned long *val;
x = (start >> PMD_SHIFT) & 15;
val = &pmdp->pmdv[x];
*(unsigned long *)__nocache_fix(val) = probed;
start += SRMMU_REAL_PMD_SIZE;
continue;
}
ptep = pte_offset_kernel(__nocache_fix(pmdp), start);
*(pte_t *)__nocache_fix(ptep) = __pte(probed);
start += PAGE_SIZE;
}
}
static void __init do_large_mapping(unsigned long vaddr, unsigned long phys_base)
{
pgd_t *pgdp = pgd_offset_k(vaddr);
unsigned long big_pte;
big_pte = KERNEL_PTE(phys_base >> 4);
*(pgd_t *)__nocache_fix(pgdp) = __pgd(big_pte);
}
static unsigned long __init map_spbank(unsigned long vbase, int sp_entry)
{
unsigned long pstart = (sp_banks[sp_entry].base_addr & SRMMU_PGDIR_MASK);
unsigned long vstart = (vbase & SRMMU_PGDIR_MASK);
unsigned long vend = SRMMU_PGDIR_ALIGN(vbase + sp_banks[sp_entry].num_bytes);
const unsigned long min_vaddr = PAGE_OFFSET;
const unsigned long max_vaddr = PAGE_OFFSET + SRMMU_MAXMEM;
if (vstart < min_vaddr || vstart >= max_vaddr)
return vstart;
if (vend > max_vaddr || vend < min_vaddr)
vend = max_vaddr;
while (vstart < vend) {
do_large_mapping(vstart, pstart);
vstart += SRMMU_PGDIR_SIZE; pstart += SRMMU_PGDIR_SIZE;
}
return vstart;
}
static void __init map_kernel(void)
{
int i;
if (phys_base > 0) {
do_large_mapping(PAGE_OFFSET, phys_base);
}
for (i = 0; sp_banks[i].num_bytes != 0; i++) {
map_spbank((unsigned long)__va(sp_banks[i].base_addr), i);
}
}
void __init srmmu_paging_init(void)
{
int i;
phandle cpunode;
char node_str[128];
pgd_t *pgd;
pmd_t *pmd;
pte_t *pte;
unsigned long pages_avail;
init_mm.context = (unsigned long) NO_CONTEXT;
sparc_iomap.start = SUN4M_IOBASE_VADDR;
if (sparc_cpu_model == sun4d)
num_contexts = 65536;
else {
cpunode = prom_getchild(prom_root_node);
num_contexts = 0;
while (cpunode != 0) {
prom_getstring(cpunode, "device_type", node_str, sizeof(node_str));
if (!strcmp(node_str, "cpu")) {
num_contexts = prom_getintdefault(cpunode, "mmu-nctx", 0x8);
break;
}
cpunode = prom_getsibling(cpunode);
}
}
if (!num_contexts) {
prom_printf("Something wrong, can't find cpu node in paging_init.\n");
prom_halt();
}
pages_avail = 0;
last_valid_pfn = bootmem_init(&pages_avail);
srmmu_nocache_calcsize();
srmmu_nocache_init();
srmmu_inherit_prom_mappings(0xfe400000, (LINUX_OPPROM_ENDVM - PAGE_SIZE));
map_kernel();
srmmu_context_table = __srmmu_get_nocache(num_contexts * sizeof(ctxd_t), num_contexts * sizeof(ctxd_t));
srmmu_ctx_table_phys = (ctxd_t *)__nocache_pa((unsigned long)srmmu_context_table);
for (i = 0; i < num_contexts; i++)
srmmu_ctxd_set((ctxd_t *)__nocache_fix(&srmmu_context_table[i]), srmmu_swapper_pg_dir);
flush_cache_all();
srmmu_set_ctable_ptr((unsigned long)srmmu_ctx_table_phys);
#ifdef CONFIG_SMP
local_ops->tlb_all();
#else
flush_tlb_all();
#endif
poke_srmmu();
srmmu_allocate_ptable_skeleton(sparc_iomap.start, IOBASE_END);
srmmu_allocate_ptable_skeleton(DVMA_VADDR, DVMA_END);
srmmu_allocate_ptable_skeleton(
__fix_to_virt(__end_of_fixed_addresses - 1), FIXADDR_TOP);
srmmu_allocate_ptable_skeleton(PKMAP_BASE, PKMAP_END);
pgd = pgd_offset_k(PKMAP_BASE);
pmd = pmd_offset(pgd, PKMAP_BASE);
pte = pte_offset_kernel(pmd, PKMAP_BASE);
pkmap_page_table = pte;
flush_cache_all();
flush_tlb_all();
sparc_context_init(num_contexts);
kmap_init();
{
unsigned long zones_size[MAX_NR_ZONES];
unsigned long zholes_size[MAX_NR_ZONES];
unsigned long npages;
int znum;
for (znum = 0; znum < MAX_NR_ZONES; znum++)
zones_size[znum] = zholes_size[znum] = 0;
npages = max_low_pfn - pfn_base;
zones_size[ZONE_DMA] = npages;
zholes_size[ZONE_DMA] = npages - pages_avail;
npages = highend_pfn - max_low_pfn;
zones_size[ZONE_HIGHMEM] = npages;
zholes_size[ZONE_HIGHMEM] = npages - calc_highpages();
free_area_init_node(0, zones_size, pfn_base, zholes_size);
}
}
void mmu_info(struct seq_file *m)
{
seq_printf(m,
"MMU type\t: %s\n"
"contexts\t: %d\n"
"nocache total\t: %ld\n"
"nocache used\t: %d\n",
srmmu_name,
num_contexts,
srmmu_nocache_size,
srmmu_nocache_map.used << SRMMU_NOCACHE_BITMAP_SHIFT);
}
int init_new_context(struct task_struct *tsk, struct mm_struct *mm)
{
mm->context = NO_CONTEXT;
return 0;
}
void destroy_context(struct mm_struct *mm)
{
if (mm->context != NO_CONTEXT) {
flush_cache_mm(mm);
srmmu_ctxd_set(&srmmu_context_table[mm->context], srmmu_swapper_pg_dir);
flush_tlb_mm(mm);
spin_lock(&srmmu_context_spinlock);
free_context(mm->context);
spin_unlock(&srmmu_context_spinlock);
mm->context = NO_CONTEXT;
}
}
static void __init srmmu_is_bad(void)
{
prom_printf("Could not determine SRMMU chip type.\n");
prom_halt();
}
static void __init init_vac_layout(void)
{
phandle nd;
int cache_lines;
char node_str[128];
#ifdef CONFIG_SMP
int cpu = 0;
unsigned long max_size = 0;
unsigned long min_line_size = 0x10000000;
#endif
nd = prom_getchild(prom_root_node);
while ((nd = prom_getsibling(nd)) != 0) {
prom_getstring(nd, "device_type", node_str, sizeof(node_str));
if (!strcmp(node_str, "cpu")) {
vac_line_size = prom_getint(nd, "cache-line-size");
if (vac_line_size == -1) {
prom_printf("can't determine cache-line-size, halting.\n");
prom_halt();
}
cache_lines = prom_getint(nd, "cache-nlines");
if (cache_lines == -1) {
prom_printf("can't determine cache-nlines, halting.\n");
prom_halt();
}
vac_cache_size = cache_lines * vac_line_size;
#ifdef CONFIG_SMP
if (vac_cache_size > max_size)
max_size = vac_cache_size;
if (vac_line_size < min_line_size)
min_line_size = vac_line_size;
cpu++;
if (cpu >= nr_cpu_ids || !cpu_online(cpu))
break;
#else
break;
#endif
}
}
if (nd == 0) {
prom_printf("No CPU nodes found, halting.\n");
prom_halt();
}
#ifdef CONFIG_SMP
vac_cache_size = max_size;
vac_line_size = min_line_size;
#endif
printk("SRMMU: Using VAC size of %d bytes, line size %d bytes.\n",
(int)vac_cache_size, (int)vac_line_size);
}
static void poke_hypersparc(void)
{
volatile unsigned long clear;
unsigned long mreg = srmmu_get_mmureg();
hyper_flush_unconditional_combined();
mreg &= ~(HYPERSPARC_CWENABLE);
mreg |= (HYPERSPARC_CENABLE | HYPERSPARC_WBENABLE);
mreg |= (HYPERSPARC_CMODE);
srmmu_set_mmureg(mreg);
#if 0
hyper_clear_all_tags();
#endif
put_ross_icr(HYPERSPARC_ICCR_FTD | HYPERSPARC_ICCR_ICE);
hyper_flush_whole_icache();
clear = srmmu_get_faddr();
clear = srmmu_get_fstatus();
}
static void __init init_hypersparc(void)
{
srmmu_name = "ROSS HyperSparc";
srmmu_modtype = HyperSparc;
init_vac_layout();
is_hypersparc = 1;
sparc32_cachetlb_ops = &hypersparc_ops;
poke_srmmu = poke_hypersparc;
hypersparc_setup_blockops();
}
static void poke_swift(void)
{
unsigned long mreg;
swift_flush_cache_all();
mreg = srmmu_get_mmureg();
mreg |= (SWIFT_IE | SWIFT_DE);
mreg &= ~(SWIFT_BF);
srmmu_set_mmureg(mreg);
}
static void __init init_swift(void)
{
unsigned long swift_rev;
__asm__ __volatile__("lda [%1] %2, %0\n\t"
"srl %0, 0x18, %0\n\t" :
"=r" (swift_rev) :
"r" (SWIFT_MASKID_ADDR), "i" (ASI_M_BYPASS));
srmmu_name = "Fujitsu Swift";
switch (swift_rev) {
case 0x11:
case 0x20:
case 0x23:
case 0x30:
srmmu_modtype = Swift_lots_o_bugs;
hwbug_bitmask |= (HWBUG_KERN_ACCBROKEN | HWBUG_KERN_CBITBROKEN);
break;
case 0x25:
case 0x31:
srmmu_modtype = Swift_bad_c;
hwbug_bitmask |= HWBUG_KERN_CBITBROKEN;
break;
default:
srmmu_modtype = Swift_ok;
break;
}
sparc32_cachetlb_ops = &swift_ops;
flush_page_for_dma_global = 0;
poke_srmmu = poke_swift;
}
static void turbosparc_flush_cache_all(void)
{
flush_user_windows();
turbosparc_idflash_clear();
}
static void turbosparc_flush_cache_mm(struct mm_struct *mm)
{
FLUSH_BEGIN(mm)
flush_user_windows();
turbosparc_idflash_clear();
FLUSH_END
}
static void turbosparc_flush_cache_range(struct vm_area_struct *vma, unsigned long start, unsigned long end)
{
FLUSH_BEGIN(vma->vm_mm)
flush_user_windows();
turbosparc_idflash_clear();
FLUSH_END
}
static void turbosparc_flush_cache_page(struct vm_area_struct *vma, unsigned long page)
{
FLUSH_BEGIN(vma->vm_mm)
flush_user_windows();
if (vma->vm_flags & VM_EXEC)
turbosparc_flush_icache();
turbosparc_flush_dcache();
FLUSH_END
}
static void turbosparc_flush_page_to_ram(unsigned long page)
{
#ifdef TURBOSPARC_WRITEBACK
volatile unsigned long clear;
if (srmmu_probe(page))
turbosparc_flush_page_cache(page);
clear = srmmu_get_fstatus();
#endif
}
static void turbosparc_flush_sig_insns(struct mm_struct *mm, unsigned long insn_addr)
{
}
static void turbosparc_flush_page_for_dma(unsigned long page)
{
turbosparc_flush_dcache();
}
static void turbosparc_flush_tlb_all(void)
{
srmmu_flush_whole_tlb();
}
static void turbosparc_flush_tlb_mm(struct mm_struct *mm)
{
FLUSH_BEGIN(mm)
srmmu_flush_whole_tlb();
FLUSH_END
}
static void turbosparc_flush_tlb_range(struct vm_area_struct *vma, unsigned long start, unsigned long end)
{
FLUSH_BEGIN(vma->vm_mm)
srmmu_flush_whole_tlb();
FLUSH_END
}
static void turbosparc_flush_tlb_page(struct vm_area_struct *vma, unsigned long page)
{
FLUSH_BEGIN(vma->vm_mm)
srmmu_flush_whole_tlb();
FLUSH_END
}
static void poke_turbosparc(void)
{
unsigned long mreg = srmmu_get_mmureg();
unsigned long ccreg;
turbosparc_flush_cache_all();
mreg &= ~(TURBOSPARC_ICENABLE | TURBOSPARC_DCENABLE);
mreg &= ~(TURBOSPARC_PCENABLE);
srmmu_set_mmureg(mreg);
ccreg = turbosparc_get_ccreg();
#ifdef TURBOSPARC_WRITEBACK
ccreg |= (TURBOSPARC_SNENABLE);
ccreg &= ~(TURBOSPARC_uS2 | TURBOSPARC_WTENABLE);
#else
ccreg |= (TURBOSPARC_SNENABLE | TURBOSPARC_WTENABLE);
ccreg &= ~(TURBOSPARC_uS2);
#endif
switch (ccreg & 7) {
case 0:
case 7:
break;
default:
ccreg |= (TURBOSPARC_SCENABLE);
}
turbosparc_set_ccreg(ccreg);
mreg |= (TURBOSPARC_ICENABLE | TURBOSPARC_DCENABLE);
mreg |= (TURBOSPARC_ICSNOOP);
srmmu_set_mmureg(mreg);
}
static void __init init_turbosparc(void)
{
srmmu_name = "Fujitsu TurboSparc";
srmmu_modtype = TurboSparc;
sparc32_cachetlb_ops = &turbosparc_ops;
poke_srmmu = poke_turbosparc;
}
static void poke_tsunami(void)
{
unsigned long mreg = srmmu_get_mmureg();
tsunami_flush_icache();
tsunami_flush_dcache();
mreg &= ~TSUNAMI_ITD;
mreg |= (TSUNAMI_IENAB | TSUNAMI_DENAB);
srmmu_set_mmureg(mreg);
}
static void __init init_tsunami(void)
{
srmmu_name = "TI Tsunami";
srmmu_modtype = Tsunami;
sparc32_cachetlb_ops = &tsunami_ops;
poke_srmmu = poke_tsunami;
tsunami_setup_blockops();
}
static void poke_viking(void)
{
unsigned long mreg = srmmu_get_mmureg();
static int smp_catch;
if (viking_mxcc_present) {
unsigned long mxcc_control = mxcc_get_creg();
mxcc_control |= (MXCC_CTL_ECE | MXCC_CTL_PRE | MXCC_CTL_MCE);
mxcc_control &= ~(MXCC_CTL_RRC);
mxcc_set_creg(mxcc_control);
mreg |= VIKING_TCENABLE;
} else {
unsigned long bpreg;
mreg &= ~(VIKING_TCENABLE);
if (smp_catch++) {
bpreg = viking_get_bpreg();
bpreg &= ~(VIKING_ACTION_MIX);
viking_set_bpreg(bpreg);
msi_set_sync();
}
}
mreg |= VIKING_SPENABLE;
mreg |= (VIKING_ICENABLE | VIKING_DCENABLE);
mreg |= VIKING_SBENABLE;
mreg &= ~(VIKING_ACENABLE);
srmmu_set_mmureg(mreg);
}
static void __init init_viking(void)
{
unsigned long mreg = srmmu_get_mmureg();
if (mreg & VIKING_MMODE) {
srmmu_name = "TI Viking";
viking_mxcc_present = 0;
msi_set_sync();
viking_ops.page_for_dma = viking_flush_page;
#ifdef CONFIG_SMP
viking_sun4d_smp_ops.page_for_dma = viking_flush_page;
#endif
flush_page_for_dma_global = 0;
} else {
srmmu_name = "TI Viking/MXCC";
viking_mxcc_present = 1;
srmmu_cache_pagetables = 1;
}
sparc32_cachetlb_ops = (const struct sparc32_cachetlb_ops *)
&viking_ops;
#ifdef CONFIG_SMP
if (sparc_cpu_model == sun4d)
sparc32_cachetlb_ops = (const struct sparc32_cachetlb_ops *)
&viking_sun4d_smp_ops;
#endif
poke_srmmu = poke_viking;
}
static void __init get_srmmu_type(void)
{
unsigned long mreg, psr;
unsigned long mod_typ, mod_rev, psr_typ, psr_vers;
srmmu_modtype = SRMMU_INVAL_MOD;
hwbug_bitmask = 0;
mreg = srmmu_get_mmureg(); psr = get_psr();
mod_typ = (mreg & 0xf0000000) >> 28;
mod_rev = (mreg & 0x0f000000) >> 24;
psr_typ = (psr >> 28) & 0xf;
psr_vers = (psr >> 24) & 0xf;
if (sparc_cpu_model == sparc_leon) {
init_leon();
return;
}
if (mod_typ == 1) {
switch (mod_rev) {
case 7:
init_hypersparc();
break;
case 0:
case 2:
case 10:
case 11:
case 12:
case 13:
case 14:
case 15:
default:
prom_printf("Sparc-Linux Cypress support does not longer exit.\n");
prom_halt();
break;
}
return;
}
if (psr_typ == 0 && psr_vers == 5) {
init_turbosparc();
return;
}
if (psr_typ == 0 && psr_vers == 4) {
phandle cpunode;
char node_str[128];
cpunode = prom_getchild(prom_root_node);
while ((cpunode = prom_getsibling(cpunode)) != 0) {
prom_getstring(cpunode, "device_type", node_str, sizeof(node_str));
if (!strcmp(node_str, "cpu")) {
if (!prom_getintdefault(cpunode, "psr-implementation", 1) &&
prom_getintdefault(cpunode, "psr-version", 1) == 5) {
init_turbosparc();
return;
}
break;
}
}
init_swift();
return;
}
if (psr_typ == 4 &&
((psr_vers == 0) ||
((psr_vers == 1) && (mod_typ == 0) && (mod_rev == 0)))) {
init_viking();
return;
}
if (psr_typ == 4 && psr_vers == 1 && (mod_typ || mod_rev)) {
init_tsunami();
return;
}
srmmu_is_bad();
}
static void smp_flush_page_for_dma(unsigned long page)
{
xc1((smpfunc_t) local_ops->page_for_dma, page);
local_ops->page_for_dma(page);
}
static void smp_flush_cache_all(void)
{
xc0((smpfunc_t) local_ops->cache_all);
local_ops->cache_all();
}
static void smp_flush_tlb_all(void)
{
xc0((smpfunc_t) local_ops->tlb_all);
local_ops->tlb_all();
}
static void smp_flush_cache_mm(struct mm_struct *mm)
{
if (mm->context != NO_CONTEXT) {
cpumask_t cpu_mask;
cpumask_copy(&cpu_mask, mm_cpumask(mm));
cpumask_clear_cpu(smp_processor_id(), &cpu_mask);
if (!cpumask_empty(&cpu_mask))
xc1((smpfunc_t) local_ops->cache_mm, (unsigned long) mm);
local_ops->cache_mm(mm);
}
}
static void smp_flush_tlb_mm(struct mm_struct *mm)
{
if (mm->context != NO_CONTEXT) {
cpumask_t cpu_mask;
cpumask_copy(&cpu_mask, mm_cpumask(mm));
cpumask_clear_cpu(smp_processor_id(), &cpu_mask);
if (!cpumask_empty(&cpu_mask)) {
xc1((smpfunc_t) local_ops->tlb_mm, (unsigned long) mm);
if (atomic_read(&mm->mm_users) == 1 && current->active_mm == mm)
cpumask_copy(mm_cpumask(mm),
cpumask_of(smp_processor_id()));
}
local_ops->tlb_mm(mm);
}
}
static void smp_flush_cache_range(struct vm_area_struct *vma,
unsigned long start,
unsigned long end)
{
struct mm_struct *mm = vma->vm_mm;
if (mm->context != NO_CONTEXT) {
cpumask_t cpu_mask;
cpumask_copy(&cpu_mask, mm_cpumask(mm));
cpumask_clear_cpu(smp_processor_id(), &cpu_mask);
if (!cpumask_empty(&cpu_mask))
xc3((smpfunc_t) local_ops->cache_range,
(unsigned long) vma, start, end);
local_ops->cache_range(vma, start, end);
}
}
static void smp_flush_tlb_range(struct vm_area_struct *vma,
unsigned long start,
unsigned long end)
{
struct mm_struct *mm = vma->vm_mm;
if (mm->context != NO_CONTEXT) {
cpumask_t cpu_mask;
cpumask_copy(&cpu_mask, mm_cpumask(mm));
cpumask_clear_cpu(smp_processor_id(), &cpu_mask);
if (!cpumask_empty(&cpu_mask))
xc3((smpfunc_t) local_ops->tlb_range,
(unsigned long) vma, start, end);
local_ops->tlb_range(vma, start, end);
}
}
static void smp_flush_cache_page(struct vm_area_struct *vma, unsigned long page)
{
struct mm_struct *mm = vma->vm_mm;
if (mm->context != NO_CONTEXT) {
cpumask_t cpu_mask;
cpumask_copy(&cpu_mask, mm_cpumask(mm));
cpumask_clear_cpu(smp_processor_id(), &cpu_mask);
if (!cpumask_empty(&cpu_mask))
xc2((smpfunc_t) local_ops->cache_page,
(unsigned long) vma, page);
local_ops->cache_page(vma, page);
}
}
static void smp_flush_tlb_page(struct vm_area_struct *vma, unsigned long page)
{
struct mm_struct *mm = vma->vm_mm;
if (mm->context != NO_CONTEXT) {
cpumask_t cpu_mask;
cpumask_copy(&cpu_mask, mm_cpumask(mm));
cpumask_clear_cpu(smp_processor_id(), &cpu_mask);
if (!cpumask_empty(&cpu_mask))
xc2((smpfunc_t) local_ops->tlb_page,
(unsigned long) vma, page);
local_ops->tlb_page(vma, page);
}
}
static void smp_flush_page_to_ram(unsigned long page)
{
#if 1
xc1((smpfunc_t) local_ops->page_to_ram, page);
#endif
local_ops->page_to_ram(page);
}
static void smp_flush_sig_insns(struct mm_struct *mm, unsigned long insn_addr)
{
cpumask_t cpu_mask;
cpumask_copy(&cpu_mask, mm_cpumask(mm));
cpumask_clear_cpu(smp_processor_id(), &cpu_mask);
if (!cpumask_empty(&cpu_mask))
xc2((smpfunc_t) local_ops->sig_insns,
(unsigned long) mm, insn_addr);
local_ops->sig_insns(mm, insn_addr);
}
void __init load_mmu(void)
{
get_srmmu_type();
#ifdef CONFIG_SMP
local_ops = sparc32_cachetlb_ops;
if (sparc_cpu_model == sun4d || sparc_cpu_model == sparc_leon) {
smp_cachetlb_ops.tlb_all = local_ops->tlb_all;
smp_cachetlb_ops.tlb_mm = local_ops->tlb_mm;
smp_cachetlb_ops.tlb_range = local_ops->tlb_range;
smp_cachetlb_ops.tlb_page = local_ops->tlb_page;
}
if (poke_srmmu == poke_viking) {
smp_cachetlb_ops.cache_all = local_ops->cache_all;
smp_cachetlb_ops.cache_mm = local_ops->cache_mm;
smp_cachetlb_ops.cache_range = local_ops->cache_range;
smp_cachetlb_ops.cache_page = local_ops->cache_page;
smp_cachetlb_ops.page_to_ram = local_ops->page_to_ram;
smp_cachetlb_ops.sig_insns = local_ops->sig_insns;
smp_cachetlb_ops.page_for_dma = local_ops->page_for_dma;
}
sparc32_cachetlb_ops = (const struct sparc32_cachetlb_ops *)
&smp_cachetlb_ops;
#endif
if (sparc_cpu_model == sun4d)
ld_mmu_iounit();
else
ld_mmu_iommu();
#ifdef CONFIG_SMP
if (sparc_cpu_model == sun4d)
sun4d_init_smp();
else if (sparc_cpu_model == sparc_leon)
leon_init_smp();
else
sun4m_init_smp();
#endif
}
