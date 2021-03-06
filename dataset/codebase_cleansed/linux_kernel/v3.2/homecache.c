static int __init set_noallocl2(char *str)
{
noallocl2 = 1;
return 0;
}
static void hv_flush_update(const struct cpumask *cache_cpumask,
struct cpumask *tlb_cpumask,
unsigned long tlb_va, unsigned long tlb_length,
HV_Remote_ASID *asids, int asidcount)
{
struct cpumask mask;
int i, cpu;
cpumask_clear(&mask);
if (cache_cpumask)
cpumask_or(&mask, &mask, cache_cpumask);
if (tlb_cpumask && tlb_length) {
cpumask_or(&mask, &mask, tlb_cpumask);
}
for (i = 0; i < asidcount; ++i)
cpumask_set_cpu(asids[i].y * smp_width + asids[i].x, &mask);
for_each_cpu(cpu, &mask)
++per_cpu(irq_stat, cpu).irq_hv_flush_count;
}
void flush_remote(unsigned long cache_pfn, unsigned long cache_control,
const struct cpumask *cache_cpumask_orig,
HV_VirtAddr tlb_va, unsigned long tlb_length,
unsigned long tlb_pgsize,
const struct cpumask *tlb_cpumask_orig,
HV_Remote_ASID *asids, int asidcount)
{
int rc;
int timestamp = 0;
struct cpumask cache_cpumask_copy, tlb_cpumask_copy;
struct cpumask *cache_cpumask, *tlb_cpumask;
HV_PhysAddr cache_pa;
char cache_buf[NR_CPUS*5], tlb_buf[NR_CPUS*5];
mb();
if (cache_cpumask_orig && cache_control) {
cpumask_copy(&cache_cpumask_copy, cache_cpumask_orig);
cache_cpumask = &cache_cpumask_copy;
} else {
cpumask_clear(&cache_cpumask_copy);
cache_cpumask = NULL;
}
if (cache_cpumask == NULL)
cache_control = 0;
if (tlb_cpumask_orig && tlb_length) {
cpumask_copy(&tlb_cpumask_copy, tlb_cpumask_orig);
tlb_cpumask = &tlb_cpumask_copy;
} else {
cpumask_clear(&tlb_cpumask_copy);
tlb_cpumask = NULL;
}
hv_flush_update(cache_cpumask, tlb_cpumask, tlb_va, tlb_length,
asids, asidcount);
cache_pa = (HV_PhysAddr)cache_pfn << PAGE_SHIFT;
if (cache_control & HV_FLUSH_EVICT_L2)
timestamp = mark_caches_evicted_start();
rc = hv_flush_remote(cache_pa, cache_control,
cpumask_bits(cache_cpumask),
tlb_va, tlb_length, tlb_pgsize,
cpumask_bits(tlb_cpumask),
asids, asidcount);
if (cache_control & HV_FLUSH_EVICT_L2)
mark_caches_evicted_finish(cache_cpumask, timestamp);
if (rc == 0)
return;
cpumask_scnprintf(cache_buf, sizeof(cache_buf), &cache_cpumask_copy);
cpumask_scnprintf(tlb_buf, sizeof(tlb_buf), &tlb_cpumask_copy);
pr_err("hv_flush_remote(%#llx, %#lx, %p [%s],"
" %#lx, %#lx, %#lx, %p [%s], %p, %d) = %d\n",
cache_pa, cache_control, cache_cpumask, cache_buf,
(unsigned long)tlb_va, tlb_length, tlb_pgsize,
tlb_cpumask, tlb_buf,
asids, asidcount, rc);
panic("Unsafe to continue.");
}
void flush_remote_page(struct page *page, int order)
{
int i, pages = (1 << order);
for (i = 0; i < pages; ++i, ++page) {
void *p = kmap_atomic(page);
int hfh = 0;
int home = page_home(page);
#if CHIP_HAS_CBOX_HOME_MAP()
if (home == PAGE_HOME_HASH)
hfh = 1;
else
#endif
BUG_ON(home < 0 || home >= NR_CPUS);
finv_buffer_remote(p, PAGE_SIZE, hfh);
kunmap_atomic(p);
}
}
void homecache_evict(const struct cpumask *mask)
{
flush_remote(0, HV_FLUSH_EVICT_L2, mask, 0, 0, 0, NULL, NULL, 0);
}
static int homecache_mask(struct page *page, int pages,
struct cpumask *home_mask)
{
int i;
int cached_coherently = 1;
cpumask_clear(home_mask);
for (i = 0; i < pages; ++i) {
int home = page_home(&page[i]);
if (home == PAGE_HOME_IMMUTABLE ||
home == PAGE_HOME_INCOHERENT) {
cpumask_copy(home_mask, cpu_possible_mask);
return 0;
}
#if CHIP_HAS_CBOX_HOME_MAP()
if (home == PAGE_HOME_HASH) {
cpumask_or(home_mask, home_mask, &hash_for_home_map);
continue;
}
#endif
if (home == PAGE_HOME_UNCACHED) {
cached_coherently = 0;
continue;
}
BUG_ON(home < 0 || home >= NR_CPUS);
cpumask_set_cpu(home, home_mask);
}
return cached_coherently;
}
static unsigned long cache_flush_length(unsigned long length)
{
return (length >= CHIP_L2_CACHE_SIZE()) ? HV_FLUSH_EVICT_L2 : length;
}
void homecache_flush_cache(struct page *page, int order)
{
int pages = 1 << order;
int length = cache_flush_length(pages * PAGE_SIZE);
unsigned long pfn = page_to_pfn(page);
struct cpumask home_mask;
homecache_mask(page, pages, &home_mask);
flush_remote(pfn, length, &home_mask, 0, 0, 0, NULL, NULL, 0);
sim_validate_lines_evicted(PFN_PHYS(pfn), pages * PAGE_SIZE);
}
static int pte_to_home(pte_t pte)
{
if (hv_pte_get_nc(pte))
return PAGE_HOME_IMMUTABLE;
switch (hv_pte_get_mode(pte)) {
case HV_PTE_MODE_CACHE_TILE_L3:
return get_remote_cache_cpu(pte);
case HV_PTE_MODE_CACHE_NO_L3:
return PAGE_HOME_INCOHERENT;
case HV_PTE_MODE_UNCACHED:
return PAGE_HOME_UNCACHED;
#if CHIP_HAS_CBOX_HOME_MAP()
case HV_PTE_MODE_CACHE_HASH_L3:
return PAGE_HOME_HASH;
#endif
}
panic("Bad PTE %#llx\n", pte.val);
}
pte_t pte_set_home(pte_t pte, int home)
{
if (pte_file(pte))
return pte;
#if CHIP_HAS_MMIO()
if (hv_pte_get_mode(pte) == HV_PTE_MODE_MMIO)
return pte;
#endif
if (hv_pte_get_nc(pte) && home != PAGE_HOME_IMMUTABLE) {
pte = hv_pte_clear_nc(pte);
pr_err("non-immutable page incoherently referenced: %#llx\n",
pte.val);
}
switch (home) {
case PAGE_HOME_UNCACHED:
pte = hv_pte_set_mode(pte, HV_PTE_MODE_UNCACHED);
break;
case PAGE_HOME_INCOHERENT:
pte = hv_pte_set_mode(pte, HV_PTE_MODE_CACHE_NO_L3);
break;
case PAGE_HOME_IMMUTABLE:
BUG_ON(hv_pte_get_writable(pte));
if (pte_get_forcecache(pte)) {
if (hv_pte_get_mode(pte) == HV_PTE_MODE_CACHE_TILE_L3
&& pte_get_anyhome(pte)) {
pte = hv_pte_set_mode(pte,
HV_PTE_MODE_CACHE_NO_L3);
}
} else
#if CHIP_HAS_CBOX_HOME_MAP()
if (hash_default)
pte = hv_pte_set_mode(pte, HV_PTE_MODE_CACHE_HASH_L3);
else
#endif
pte = hv_pte_set_mode(pte, HV_PTE_MODE_CACHE_NO_L3);
pte = hv_pte_set_nc(pte);
break;
#if CHIP_HAS_CBOX_HOME_MAP()
case PAGE_HOME_HASH:
pte = hv_pte_set_mode(pte, HV_PTE_MODE_CACHE_HASH_L3);
break;
#endif
default:
BUG_ON(home < 0 || home >= NR_CPUS ||
!cpu_is_valid_lotar(home));
pte = hv_pte_set_mode(pte, HV_PTE_MODE_CACHE_TILE_L3);
pte = set_remote_cache_cpu(pte, home);
break;
}
#if CHIP_HAS_NC_AND_NOALLOC_BITS()
if (noallocl2)
pte = hv_pte_set_no_alloc_l2(pte);
if (hv_pte_get_no_alloc_l2(pte) && hv_pte_get_no_alloc_l1(pte) &&
hv_pte_get_mode(pte) == HV_PTE_MODE_CACHE_NO_L3) {
pte = hv_pte_set_mode(pte, HV_PTE_MODE_UNCACHED);
}
#endif
BUG_ON(hv_pte_get_mode(pte) == 0);
return pte;
}
static inline int initial_page_home(void) { return PAGE_HOME_HASH; }
static inline int initial_page_home(void) { return 0; }
int page_home(struct page *page)
{
if (PageHighMem(page)) {
return initial_page_home();
} else {
unsigned long kva = (unsigned long)page_address(page);
return pte_to_home(*virt_to_pte(NULL, kva));
}
}
void homecache_change_page_home(struct page *page, int order, int home)
{
int i, pages = (1 << order);
unsigned long kva;
BUG_ON(PageHighMem(page));
BUG_ON(page_count(page) > 1);
BUG_ON(page_mapcount(page) != 0);
kva = (unsigned long) page_address(page);
flush_remote(0, HV_FLUSH_EVICT_L2, &cpu_cacheable_map,
kva, pages * PAGE_SIZE, PAGE_SIZE, cpu_online_mask,
NULL, 0);
for (i = 0; i < pages; ++i, kva += PAGE_SIZE) {
pte_t *ptep = virt_to_pte(NULL, kva);
pte_t pteval = *ptep;
BUG_ON(!pte_present(pteval) || pte_huge(pteval));
__set_pte(ptep, pte_set_home(pteval, home));
}
}
struct page *homecache_alloc_pages(gfp_t gfp_mask,
unsigned int order, int home)
{
struct page *page;
BUG_ON(gfp_mask & __GFP_HIGHMEM);
page = alloc_pages(gfp_mask, order);
if (page)
homecache_change_page_home(page, order, home);
return page;
}
struct page *homecache_alloc_pages_node(int nid, gfp_t gfp_mask,
unsigned int order, int home)
{
struct page *page;
BUG_ON(gfp_mask & __GFP_HIGHMEM);
page = alloc_pages_node(nid, gfp_mask, order);
if (page)
homecache_change_page_home(page, order, home);
return page;
}
void homecache_free_pages(unsigned long addr, unsigned int order)
{
struct page *page;
if (addr == 0)
return;
VM_BUG_ON(!virt_addr_valid((void *)addr));
page = virt_to_page((void *)addr);
if (put_page_testzero(page)) {
homecache_change_page_home(page, order, initial_page_home());
if (order == 0) {
free_hot_cold_page(page, 0);
} else {
init_page_count(page);
__free_pages(page, order);
}
}
}
