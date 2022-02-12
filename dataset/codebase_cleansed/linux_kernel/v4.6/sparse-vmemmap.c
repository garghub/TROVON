static void * __init_refok __earlyonly_bootmem_alloc(int node,
unsigned long size,
unsigned long align,
unsigned long goal)
{
return memblock_virt_alloc_try_nid(size, align, goal,
BOOTMEM_ALLOC_ACCESSIBLE, node);
}
void * __meminit vmemmap_alloc_block(unsigned long size, int node)
{
if (slab_is_available()) {
struct page *page;
if (node_state(node, N_HIGH_MEMORY))
page = alloc_pages_node(
node, GFP_KERNEL | __GFP_ZERO | __GFP_REPEAT,
get_order(size));
else
page = alloc_pages(
GFP_KERNEL | __GFP_ZERO | __GFP_REPEAT,
get_order(size));
if (page)
return page_address(page);
return NULL;
} else
return __earlyonly_bootmem_alloc(node, size, size,
__pa(MAX_DMA_ADDRESS));
}
static void * __meminit alloc_block_buf(unsigned long size, int node)
{
void *ptr;
if (!vmemmap_buf)
return vmemmap_alloc_block(size, node);
ptr = (void *)ALIGN((unsigned long)vmemmap_buf, size);
if (ptr + size > vmemmap_buf_end)
return vmemmap_alloc_block(size, node);
vmemmap_buf = ptr + size;
return ptr;
}
static unsigned long __meminit vmem_altmap_next_pfn(struct vmem_altmap *altmap)
{
return altmap->base_pfn + altmap->reserve + altmap->alloc
+ altmap->align;
}
static unsigned long __meminit vmem_altmap_nr_free(struct vmem_altmap *altmap)
{
unsigned long allocated = altmap->alloc + altmap->align;
if (altmap->free > allocated)
return altmap->free - allocated;
return 0;
}
static unsigned long __meminit vmem_altmap_alloc(struct vmem_altmap *altmap,
unsigned long nr_pfns)
{
unsigned long pfn = vmem_altmap_next_pfn(altmap);
unsigned long nr_align;
nr_align = 1UL << find_first_bit(&nr_pfns, BITS_PER_LONG);
nr_align = ALIGN(pfn, nr_align) - pfn;
if (nr_pfns + nr_align > vmem_altmap_nr_free(altmap))
return ULONG_MAX;
altmap->alloc += nr_pfns;
altmap->align += nr_align;
return pfn + nr_align;
}
static void * __meminit altmap_alloc_block_buf(unsigned long size,
struct vmem_altmap *altmap)
{
unsigned long pfn, nr_pfns;
void *ptr;
if (size & ~PAGE_MASK) {
pr_warn_once("%s: allocations must be multiple of PAGE_SIZE (%ld)\n",
__func__, size);
return NULL;
}
nr_pfns = size >> PAGE_SHIFT;
pfn = vmem_altmap_alloc(altmap, nr_pfns);
if (pfn < ULONG_MAX)
ptr = __va(__pfn_to_phys(pfn));
else
ptr = NULL;
pr_debug("%s: pfn: %#lx alloc: %ld align: %ld nr: %#lx\n",
__func__, pfn, altmap->alloc, altmap->align, nr_pfns);
return ptr;
}
void * __meminit __vmemmap_alloc_block_buf(unsigned long size, int node,
struct vmem_altmap *altmap)
{
if (altmap)
return altmap_alloc_block_buf(size, altmap);
return alloc_block_buf(size, node);
}
void __meminit vmemmap_verify(pte_t *pte, int node,
unsigned long start, unsigned long end)
{
unsigned long pfn = pte_pfn(*pte);
int actual_node = early_pfn_to_nid(pfn);
if (node_distance(actual_node, node) > LOCAL_DISTANCE)
pr_warn("[%lx-%lx] potential offnode page_structs\n",
start, end - 1);
}
pte_t * __meminit vmemmap_pte_populate(pmd_t *pmd, unsigned long addr, int node)
{
pte_t *pte = pte_offset_kernel(pmd, addr);
if (pte_none(*pte)) {
pte_t entry;
void *p = alloc_block_buf(PAGE_SIZE, node);
if (!p)
return NULL;
entry = pfn_pte(__pa(p) >> PAGE_SHIFT, PAGE_KERNEL);
set_pte_at(&init_mm, addr, pte, entry);
}
return pte;
}
pmd_t * __meminit vmemmap_pmd_populate(pud_t *pud, unsigned long addr, int node)
{
pmd_t *pmd = pmd_offset(pud, addr);
if (pmd_none(*pmd)) {
void *p = vmemmap_alloc_block(PAGE_SIZE, node);
if (!p)
return NULL;
pmd_populate_kernel(&init_mm, pmd, p);
}
return pmd;
}
pud_t * __meminit vmemmap_pud_populate(pgd_t *pgd, unsigned long addr, int node)
{
pud_t *pud = pud_offset(pgd, addr);
if (pud_none(*pud)) {
void *p = vmemmap_alloc_block(PAGE_SIZE, node);
if (!p)
return NULL;
pud_populate(&init_mm, pud, p);
}
return pud;
}
pgd_t * __meminit vmemmap_pgd_populate(unsigned long addr, int node)
{
pgd_t *pgd = pgd_offset_k(addr);
if (pgd_none(*pgd)) {
void *p = vmemmap_alloc_block(PAGE_SIZE, node);
if (!p)
return NULL;
pgd_populate(&init_mm, pgd, p);
}
return pgd;
}
int __meminit vmemmap_populate_basepages(unsigned long start,
unsigned long end, int node)
{
unsigned long addr = start;
pgd_t *pgd;
pud_t *pud;
pmd_t *pmd;
pte_t *pte;
for (; addr < end; addr += PAGE_SIZE) {
pgd = vmemmap_pgd_populate(addr, node);
if (!pgd)
return -ENOMEM;
pud = vmemmap_pud_populate(pgd, addr, node);
if (!pud)
return -ENOMEM;
pmd = vmemmap_pmd_populate(pud, addr, node);
if (!pmd)
return -ENOMEM;
pte = vmemmap_pte_populate(pmd, addr, node);
if (!pte)
return -ENOMEM;
vmemmap_verify(pte, node, addr, addr + PAGE_SIZE);
}
return 0;
}
struct page * __meminit sparse_mem_map_populate(unsigned long pnum, int nid)
{
unsigned long start;
unsigned long end;
struct page *map;
map = pfn_to_page(pnum * PAGES_PER_SECTION);
start = (unsigned long)map;
end = (unsigned long)(map + PAGES_PER_SECTION);
if (vmemmap_populate(start, end, nid))
return NULL;
return map;
}
void __init sparse_mem_maps_populate_node(struct page **map_map,
unsigned long pnum_begin,
unsigned long pnum_end,
unsigned long map_count, int nodeid)
{
unsigned long pnum;
unsigned long size = sizeof(struct page) * PAGES_PER_SECTION;
void *vmemmap_buf_start;
size = ALIGN(size, PMD_SIZE);
vmemmap_buf_start = __earlyonly_bootmem_alloc(nodeid, size * map_count,
PMD_SIZE, __pa(MAX_DMA_ADDRESS));
if (vmemmap_buf_start) {
vmemmap_buf = vmemmap_buf_start;
vmemmap_buf_end = vmemmap_buf_start + size * map_count;
}
for (pnum = pnum_begin; pnum < pnum_end; pnum++) {
struct mem_section *ms;
if (!present_section_nr(pnum))
continue;
map_map[pnum] = sparse_mem_map_populate(pnum, nodeid);
if (map_map[pnum])
continue;
ms = __nr_to_section(pnum);
pr_err("%s: sparsemem memory map backing failed some memory will not be available\n",
__func__);
ms->section_mem_map = 0;
}
if (vmemmap_buf_start) {
memblock_free_early(__pa(vmemmap_buf),
vmemmap_buf_end - vmemmap_buf);
vmemmap_buf = NULL;
vmemmap_buf_end = NULL;
}
}
