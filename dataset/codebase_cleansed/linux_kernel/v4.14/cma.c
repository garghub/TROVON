phys_addr_t cma_get_base(const struct cma *cma)
{
return PFN_PHYS(cma->base_pfn);
}
unsigned long cma_get_size(const struct cma *cma)
{
return cma->count << PAGE_SHIFT;
}
const char *cma_get_name(const struct cma *cma)
{
return cma->name ? cma->name : "(undefined)";
}
static unsigned long cma_bitmap_aligned_mask(const struct cma *cma,
unsigned int align_order)
{
if (align_order <= cma->order_per_bit)
return 0;
return (1UL << (align_order - cma->order_per_bit)) - 1;
}
static unsigned long cma_bitmap_aligned_offset(const struct cma *cma,
unsigned int align_order)
{
return (cma->base_pfn & ((1UL << align_order) - 1))
>> cma->order_per_bit;
}
static unsigned long cma_bitmap_pages_to_bits(const struct cma *cma,
unsigned long pages)
{
return ALIGN(pages, 1UL << cma->order_per_bit) >> cma->order_per_bit;
}
static void cma_clear_bitmap(struct cma *cma, unsigned long pfn,
unsigned int count)
{
unsigned long bitmap_no, bitmap_count;
bitmap_no = (pfn - cma->base_pfn) >> cma->order_per_bit;
bitmap_count = cma_bitmap_pages_to_bits(cma, count);
mutex_lock(&cma->lock);
bitmap_clear(cma->bitmap, bitmap_no, bitmap_count);
mutex_unlock(&cma->lock);
}
static int __init cma_activate_area(struct cma *cma)
{
int bitmap_size = BITS_TO_LONGS(cma_bitmap_maxno(cma)) * sizeof(long);
unsigned long base_pfn = cma->base_pfn, pfn = base_pfn;
unsigned i = cma->count >> pageblock_order;
struct zone *zone;
cma->bitmap = kzalloc(bitmap_size, GFP_KERNEL);
if (!cma->bitmap)
return -ENOMEM;
WARN_ON_ONCE(!pfn_valid(pfn));
zone = page_zone(pfn_to_page(pfn));
do {
unsigned j;
base_pfn = pfn;
for (j = pageblock_nr_pages; j; --j, pfn++) {
WARN_ON_ONCE(!pfn_valid(pfn));
if (page_zone(pfn_to_page(pfn)) != zone)
goto not_in_zone;
}
init_cma_reserved_pageblock(pfn_to_page(base_pfn));
} while (--i);
mutex_init(&cma->lock);
#ifdef CONFIG_CMA_DEBUGFS
INIT_HLIST_HEAD(&cma->mem_head);
spin_lock_init(&cma->mem_head_lock);
#endif
return 0;
not_in_zone:
pr_err("CMA area %s could not be activated\n", cma->name);
kfree(cma->bitmap);
cma->count = 0;
return -EINVAL;
}
static int __init cma_init_reserved_areas(void)
{
int i;
for (i = 0; i < cma_area_count; i++) {
int ret = cma_activate_area(&cma_areas[i]);
if (ret)
return ret;
}
return 0;
}
int __init cma_init_reserved_mem(phys_addr_t base, phys_addr_t size,
unsigned int order_per_bit,
const char *name,
struct cma **res_cma)
{
struct cma *cma;
phys_addr_t alignment;
if (cma_area_count == ARRAY_SIZE(cma_areas)) {
pr_err("Not enough slots for CMA reserved regions!\n");
return -ENOSPC;
}
if (!size || !memblock_is_region_reserved(base, size))
return -EINVAL;
alignment = PAGE_SIZE <<
max_t(unsigned long, MAX_ORDER - 1, pageblock_order);
if (!IS_ALIGNED(alignment >> PAGE_SHIFT, 1 << order_per_bit))
return -EINVAL;
if (ALIGN(base, alignment) != base || ALIGN(size, alignment) != size)
return -EINVAL;
cma = &cma_areas[cma_area_count];
if (name) {
cma->name = name;
} else {
cma->name = kasprintf(GFP_KERNEL, "cma%d\n", cma_area_count);
if (!cma->name)
return -ENOMEM;
}
cma->base_pfn = PFN_DOWN(base);
cma->count = size >> PAGE_SHIFT;
cma->order_per_bit = order_per_bit;
*res_cma = cma;
cma_area_count++;
totalcma_pages += (size / PAGE_SIZE);
return 0;
}
int __init cma_declare_contiguous(phys_addr_t base,
phys_addr_t size, phys_addr_t limit,
phys_addr_t alignment, unsigned int order_per_bit,
bool fixed, const char *name, struct cma **res_cma)
{
phys_addr_t memblock_end = memblock_end_of_DRAM();
phys_addr_t highmem_start;
int ret = 0;
highmem_start = __pa(high_memory - 1) + 1;
pr_debug("%s(size %pa, base %pa, limit %pa alignment %pa)\n",
__func__, &size, &base, &limit, &alignment);
if (cma_area_count == ARRAY_SIZE(cma_areas)) {
pr_err("Not enough slots for CMA reserved regions!\n");
return -ENOSPC;
}
if (!size)
return -EINVAL;
if (alignment && !is_power_of_2(alignment))
return -EINVAL;
alignment = max(alignment, (phys_addr_t)PAGE_SIZE <<
max_t(unsigned long, MAX_ORDER - 1, pageblock_order));
base = ALIGN(base, alignment);
size = ALIGN(size, alignment);
limit &= ~(alignment - 1);
if (!base)
fixed = false;
if (!IS_ALIGNED(size >> PAGE_SHIFT, 1 << order_per_bit))
return -EINVAL;
if (fixed && base < highmem_start && base + size > highmem_start) {
ret = -EINVAL;
pr_err("Region at %pa defined on low/high memory boundary (%pa)\n",
&base, &highmem_start);
goto err;
}
if (limit == 0 || limit > memblock_end)
limit = memblock_end;
if (fixed) {
if (memblock_is_region_reserved(base, size) ||
memblock_reserve(base, size) < 0) {
ret = -EBUSY;
goto err;
}
} else {
phys_addr_t addr = 0;
if (base < highmem_start && limit > highmem_start) {
addr = memblock_alloc_range(size, alignment,
highmem_start, limit,
MEMBLOCK_NONE);
limit = highmem_start;
}
if (!addr) {
addr = memblock_alloc_range(size, alignment, base,
limit,
MEMBLOCK_NONE);
if (!addr) {
ret = -ENOMEM;
goto err;
}
}
kmemleak_ignore_phys(addr);
base = addr;
}
ret = cma_init_reserved_mem(base, size, order_per_bit, name, res_cma);
if (ret)
goto err;
pr_info("Reserved %ld MiB at %pa\n", (unsigned long)size / SZ_1M,
&base);
return 0;
err:
pr_err("Failed to reserve %ld MiB\n", (unsigned long)size / SZ_1M);
return ret;
}
static void cma_debug_show_areas(struct cma *cma)
{
unsigned long next_zero_bit, next_set_bit;
unsigned long start = 0;
unsigned int nr_zero, nr_total = 0;
mutex_lock(&cma->lock);
pr_info("number of available pages: ");
for (;;) {
next_zero_bit = find_next_zero_bit(cma->bitmap, cma->count, start);
if (next_zero_bit >= cma->count)
break;
next_set_bit = find_next_bit(cma->bitmap, cma->count, next_zero_bit);
nr_zero = next_set_bit - next_zero_bit;
pr_cont("%s%u@%lu", nr_total ? "+" : "", nr_zero, next_zero_bit);
nr_total += nr_zero;
start = next_zero_bit + nr_zero;
}
pr_cont("=> %u free of %lu total pages\n", nr_total, cma->count);
mutex_unlock(&cma->lock);
}
static inline void cma_debug_show_areas(struct cma *cma) { }
struct page *cma_alloc(struct cma *cma, size_t count, unsigned int align,
gfp_t gfp_mask)
{
unsigned long mask, offset;
unsigned long pfn = -1;
unsigned long start = 0;
unsigned long bitmap_maxno, bitmap_no, bitmap_count;
struct page *page = NULL;
int ret = -ENOMEM;
if (!cma || !cma->count)
return NULL;
pr_debug("%s(cma %p, count %zu, align %d)\n", __func__, (void *)cma,
count, align);
if (!count)
return NULL;
mask = cma_bitmap_aligned_mask(cma, align);
offset = cma_bitmap_aligned_offset(cma, align);
bitmap_maxno = cma_bitmap_maxno(cma);
bitmap_count = cma_bitmap_pages_to_bits(cma, count);
if (bitmap_count > bitmap_maxno)
return NULL;
for (;;) {
mutex_lock(&cma->lock);
bitmap_no = bitmap_find_next_zero_area_off(cma->bitmap,
bitmap_maxno, start, bitmap_count, mask,
offset);
if (bitmap_no >= bitmap_maxno) {
mutex_unlock(&cma->lock);
break;
}
bitmap_set(cma->bitmap, bitmap_no, bitmap_count);
mutex_unlock(&cma->lock);
pfn = cma->base_pfn + (bitmap_no << cma->order_per_bit);
mutex_lock(&cma_mutex);
ret = alloc_contig_range(pfn, pfn + count, MIGRATE_CMA,
gfp_mask);
mutex_unlock(&cma_mutex);
if (ret == 0) {
page = pfn_to_page(pfn);
break;
}
cma_clear_bitmap(cma, pfn, count);
if (ret != -EBUSY)
break;
pr_debug("%s(): memory range at %p is busy, retrying\n",
__func__, pfn_to_page(pfn));
start = bitmap_no + mask + 1;
}
trace_cma_alloc(pfn, page, count, align);
if (ret && !(gfp_mask & __GFP_NOWARN)) {
pr_info("%s: alloc failed, req-size: %zu pages, ret: %d\n",
__func__, count, ret);
cma_debug_show_areas(cma);
}
pr_debug("%s(): returned %p\n", __func__, page);
return page;
}
bool cma_release(struct cma *cma, const struct page *pages, unsigned int count)
{
unsigned long pfn;
if (!cma || !pages)
return false;
pr_debug("%s(page %p)\n", __func__, (void *)pages);
pfn = page_to_pfn(pages);
if (pfn < cma->base_pfn || pfn >= cma->base_pfn + cma->count)
return false;
VM_BUG_ON(pfn + count > cma->base_pfn + cma->count);
free_contig_range(pfn, count);
cma_clear_bitmap(cma, pfn, count);
trace_cma_release(pfn, pages, count);
return true;
}
int cma_for_each_area(int (*it)(struct cma *cma, void *data), void *data)
{
int i;
for (i = 0; i < cma_area_count; i++) {
int ret = it(&cma_areas[i], data);
if (ret)
return ret;
}
return 0;
}
