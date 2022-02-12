long __init kvm_cma_declare_contiguous(phys_addr_t size, phys_addr_t alignment)
{
long base_pfn;
phys_addr_t addr;
struct kvm_cma *cma = &kvm_cma_area;
pr_debug("%s(size %lx)\n", __func__, (unsigned long)size);
if (!size)
return -EINVAL;
alignment = max(alignment, (phys_addr_t)(PAGE_SIZE << pageblock_order));
size = ALIGN(size, alignment);
addr = __memblock_alloc_base(size, alignment, 0);
if (!addr) {
base_pfn = -ENOMEM;
goto err;
} else
base_pfn = PFN_DOWN(addr);
cma->base_pfn = base_pfn;
cma->count = size >> PAGE_SHIFT;
pr_info("CMA: reserved %ld MiB\n", (unsigned long)size / SZ_1M);
return 0;
err:
pr_err("CMA: failed to reserve %ld MiB\n", (unsigned long)size / SZ_1M);
return base_pfn;
}
struct page *kvm_alloc_cma(unsigned long nr_pages, unsigned long align_pages)
{
int ret;
struct page *page = NULL;
struct kvm_cma *cma = &kvm_cma_area;
unsigned long chunk_count, nr_chunk;
unsigned long mask, pfn, pageno, start = 0;
if (!cma || !cma->count)
return NULL;
pr_debug("%s(cma %p, count %lu, align pages %lu)\n", __func__,
(void *)cma, nr_pages, align_pages);
if (!nr_pages)
return NULL;
VM_BUG_ON(!is_power_of_2(align_pages));
mask = (align_pages >> (KVM_CMA_CHUNK_ORDER - PAGE_SHIFT)) - 1;
BUILD_BUG_ON(PAGE_SHIFT > KVM_CMA_CHUNK_ORDER);
chunk_count = cma->count >> (KVM_CMA_CHUNK_ORDER - PAGE_SHIFT);
nr_chunk = nr_pages >> (KVM_CMA_CHUNK_ORDER - PAGE_SHIFT);
mutex_lock(&kvm_cma_mutex);
for (;;) {
pageno = bitmap_find_next_zero_area(cma->bitmap, chunk_count,
start, nr_chunk, mask);
if (pageno >= chunk_count)
break;
pfn = cma->base_pfn + (pageno << (KVM_CMA_CHUNK_ORDER - PAGE_SHIFT));
ret = alloc_contig_range(pfn, pfn + nr_pages, MIGRATE_CMA);
if (ret == 0) {
bitmap_set(cma->bitmap, pageno, nr_chunk);
page = pfn_to_page(pfn);
memset(pfn_to_kaddr(pfn), 0, nr_pages << PAGE_SHIFT);
break;
} else if (ret != -EBUSY) {
break;
}
pr_debug("%s(): memory range at %p is busy, retrying\n",
__func__, pfn_to_page(pfn));
start = pageno + mask + 1;
}
mutex_unlock(&kvm_cma_mutex);
pr_debug("%s(): returned %p\n", __func__, page);
return page;
}
bool kvm_release_cma(struct page *pages, unsigned long nr_pages)
{
unsigned long pfn;
unsigned long nr_chunk;
struct kvm_cma *cma = &kvm_cma_area;
if (!cma || !pages)
return false;
pr_debug("%s(page %p count %lu)\n", __func__, (void *)pages, nr_pages);
pfn = page_to_pfn(pages);
if (pfn < cma->base_pfn || pfn >= cma->base_pfn + cma->count)
return false;
VM_BUG_ON(pfn + nr_pages > cma->base_pfn + cma->count);
nr_chunk = nr_pages >> (KVM_CMA_CHUNK_ORDER - PAGE_SHIFT);
mutex_lock(&kvm_cma_mutex);
bitmap_clear(cma->bitmap,
(pfn - cma->base_pfn) >> (KVM_CMA_CHUNK_ORDER - PAGE_SHIFT),
nr_chunk);
free_contig_range(pfn, nr_pages);
mutex_unlock(&kvm_cma_mutex);
return true;
}
static int __init kvm_cma_activate_area(unsigned long base_pfn,
unsigned long count)
{
unsigned long pfn = base_pfn;
unsigned i = count >> pageblock_order;
struct zone *zone;
WARN_ON_ONCE(!pfn_valid(pfn));
zone = page_zone(pfn_to_page(pfn));
do {
unsigned j;
base_pfn = pfn;
for (j = pageblock_nr_pages; j; --j, pfn++) {
WARN_ON_ONCE(!pfn_valid(pfn));
if (page_zone(pfn_to_page(pfn)) != zone)
return -EINVAL;
}
init_cma_reserved_pageblock(pfn_to_page(base_pfn));
} while (--i);
return 0;
}
static int __init kvm_cma_init_reserved_areas(void)
{
int bitmap_size, ret;
unsigned long chunk_count;
struct kvm_cma *cma = &kvm_cma_area;
pr_debug("%s()\n", __func__);
if (!cma->count)
return 0;
chunk_count = cma->count >> (KVM_CMA_CHUNK_ORDER - PAGE_SHIFT);
bitmap_size = BITS_TO_LONGS(chunk_count) * sizeof(long);
cma->bitmap = kzalloc(bitmap_size, GFP_KERNEL);
if (!cma->bitmap)
return -ENOMEM;
ret = kvm_cma_activate_area(cma->base_pfn, cma->count);
if (ret)
goto error;
return 0;
error:
kfree(cma->bitmap);
return ret;
}
