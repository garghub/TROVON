int iommu_dma_init(void)
{
return iova_cache_get();
}
int iommu_get_dma_cookie(struct iommu_domain *domain)
{
struct iova_domain *iovad;
if (domain->iova_cookie)
return -EEXIST;
iovad = kzalloc(sizeof(*iovad), GFP_KERNEL);
domain->iova_cookie = iovad;
return iovad ? 0 : -ENOMEM;
}
void iommu_put_dma_cookie(struct iommu_domain *domain)
{
struct iova_domain *iovad = domain->iova_cookie;
if (!iovad)
return;
if (iovad->granule)
put_iova_domain(iovad);
kfree(iovad);
domain->iova_cookie = NULL;
}
int iommu_dma_init_domain(struct iommu_domain *domain, dma_addr_t base, u64 size)
{
struct iova_domain *iovad = domain->iova_cookie;
unsigned long order, base_pfn, end_pfn;
if (!iovad)
return -ENODEV;
order = __ffs(domain->pgsize_bitmap);
base_pfn = max_t(unsigned long, 1, base >> order);
end_pfn = (base + size - 1) >> order;
if (domain->geometry.force_aperture) {
if (base > domain->geometry.aperture_end ||
base + size <= domain->geometry.aperture_start) {
pr_warn("specified DMA range outside IOMMU capability\n");
return -EFAULT;
}
base_pfn = max_t(unsigned long, base_pfn,
domain->geometry.aperture_start >> order);
end_pfn = min_t(unsigned long, end_pfn,
domain->geometry.aperture_end >> order);
}
if (iovad->start_pfn) {
if (1UL << order != iovad->granule ||
base_pfn != iovad->start_pfn ||
end_pfn < iovad->dma_32bit_pfn) {
pr_warn("Incompatible range for DMA domain\n");
return -EFAULT;
}
iovad->dma_32bit_pfn = end_pfn;
} else {
init_iova_domain(iovad, 1UL << order, base_pfn, end_pfn);
}
return 0;
}
int dma_direction_to_prot(enum dma_data_direction dir, bool coherent)
{
int prot = coherent ? IOMMU_CACHE : 0;
switch (dir) {
case DMA_BIDIRECTIONAL:
return prot | IOMMU_READ | IOMMU_WRITE;
case DMA_TO_DEVICE:
return prot | IOMMU_READ;
case DMA_FROM_DEVICE:
return prot | IOMMU_WRITE;
default:
return 0;
}
}
static struct iova *__alloc_iova(struct iommu_domain *domain, size_t size,
dma_addr_t dma_limit)
{
struct iova_domain *iovad = domain->iova_cookie;
unsigned long shift = iova_shift(iovad);
unsigned long length = iova_align(iovad, size) >> shift;
if (domain->geometry.force_aperture)
dma_limit = min(dma_limit, domain->geometry.aperture_end);
return alloc_iova(iovad, length, dma_limit >> shift, true);
}
static void __iommu_dma_unmap(struct iommu_domain *domain, dma_addr_t dma_addr)
{
struct iova_domain *iovad = domain->iova_cookie;
unsigned long shift = iova_shift(iovad);
unsigned long pfn = dma_addr >> shift;
struct iova *iova = find_iova(iovad, pfn);
size_t size;
if (WARN_ON(!iova))
return;
size = iova_size(iova) << shift;
size -= iommu_unmap(domain, pfn << shift, size);
WARN_ON(size > 0);
__free_iova(iovad, iova);
}
static void __iommu_dma_free_pages(struct page **pages, int count)
{
while (count--)
__free_page(pages[count]);
kvfree(pages);
}
static struct page **__iommu_dma_alloc_pages(unsigned int count,
unsigned long order_mask, gfp_t gfp)
{
struct page **pages;
unsigned int i = 0, array_size = count * sizeof(*pages);
order_mask &= (2U << MAX_ORDER) - 1;
if (!order_mask)
return NULL;
if (array_size <= PAGE_SIZE)
pages = kzalloc(array_size, GFP_KERNEL);
else
pages = vzalloc(array_size);
if (!pages)
return NULL;
gfp |= __GFP_NOWARN | __GFP_HIGHMEM;
while (count) {
struct page *page = NULL;
unsigned int order_size;
for (order_mask &= (2U << __fls(count)) - 1;
order_mask; order_mask &= ~order_size) {
unsigned int order = __fls(order_mask);
order_size = 1U << order;
page = alloc_pages((order_mask - order_size) ?
gfp | __GFP_NORETRY : gfp, order);
if (!page)
continue;
if (!order)
break;
if (!PageCompound(page)) {
split_page(page, order);
break;
} else if (!split_huge_page(page)) {
break;
}
__free_pages(page, order);
}
if (!page) {
__iommu_dma_free_pages(pages, i);
return NULL;
}
count -= order_size;
while (order_size--)
pages[i++] = page++;
}
return pages;
}
void iommu_dma_free(struct device *dev, struct page **pages, size_t size,
dma_addr_t *handle)
{
__iommu_dma_unmap(iommu_get_domain_for_dev(dev), *handle);
__iommu_dma_free_pages(pages, PAGE_ALIGN(size) >> PAGE_SHIFT);
*handle = DMA_ERROR_CODE;
}
struct page **iommu_dma_alloc(struct device *dev, size_t size, gfp_t gfp,
unsigned long attrs, int prot, dma_addr_t *handle,
void (*flush_page)(struct device *, const void *, phys_addr_t))
{
struct iommu_domain *domain = iommu_get_domain_for_dev(dev);
struct iova_domain *iovad = domain->iova_cookie;
struct iova *iova;
struct page **pages;
struct sg_table sgt;
dma_addr_t dma_addr;
unsigned int count, min_size, alloc_sizes = domain->pgsize_bitmap;
*handle = DMA_ERROR_CODE;
min_size = alloc_sizes & -alloc_sizes;
if (min_size < PAGE_SIZE) {
min_size = PAGE_SIZE;
alloc_sizes |= PAGE_SIZE;
} else {
size = ALIGN(size, min_size);
}
if (attrs & DMA_ATTR_ALLOC_SINGLE_PAGES)
alloc_sizes = min_size;
count = PAGE_ALIGN(size) >> PAGE_SHIFT;
pages = __iommu_dma_alloc_pages(count, alloc_sizes >> PAGE_SHIFT, gfp);
if (!pages)
return NULL;
iova = __alloc_iova(domain, size, dev->coherent_dma_mask);
if (!iova)
goto out_free_pages;
size = iova_align(iovad, size);
if (sg_alloc_table_from_pages(&sgt, pages, count, 0, size, GFP_KERNEL))
goto out_free_iova;
if (!(prot & IOMMU_CACHE)) {
struct sg_mapping_iter miter;
sg_miter_start(&miter, sgt.sgl, sgt.orig_nents, SG_MITER_FROM_SG);
while (sg_miter_next(&miter))
flush_page(dev, miter.addr, page_to_phys(miter.page));
sg_miter_stop(&miter);
}
dma_addr = iova_dma_addr(iovad, iova);
if (iommu_map_sg(domain, dma_addr, sgt.sgl, sgt.orig_nents, prot)
< size)
goto out_free_sg;
*handle = dma_addr;
sg_free_table(&sgt);
return pages;
out_free_sg:
sg_free_table(&sgt);
out_free_iova:
__free_iova(iovad, iova);
out_free_pages:
__iommu_dma_free_pages(pages, count);
return NULL;
}
int iommu_dma_mmap(struct page **pages, size_t size, struct vm_area_struct *vma)
{
unsigned long uaddr = vma->vm_start;
unsigned int i, count = PAGE_ALIGN(size) >> PAGE_SHIFT;
int ret = -ENXIO;
for (i = vma->vm_pgoff; i < count && uaddr < vma->vm_end; i++) {
ret = vm_insert_page(vma, uaddr, pages[i]);
if (ret)
break;
uaddr += PAGE_SIZE;
}
return ret;
}
dma_addr_t iommu_dma_map_page(struct device *dev, struct page *page,
unsigned long offset, size_t size, int prot)
{
dma_addr_t dma_addr;
struct iommu_domain *domain = iommu_get_domain_for_dev(dev);
struct iova_domain *iovad = domain->iova_cookie;
phys_addr_t phys = page_to_phys(page) + offset;
size_t iova_off = iova_offset(iovad, phys);
size_t len = iova_align(iovad, size + iova_off);
struct iova *iova = __alloc_iova(domain, len, dma_get_mask(dev));
if (!iova)
return DMA_ERROR_CODE;
dma_addr = iova_dma_addr(iovad, iova);
if (iommu_map(domain, dma_addr, phys - iova_off, len, prot)) {
__free_iova(iovad, iova);
return DMA_ERROR_CODE;
}
return dma_addr + iova_off;
}
void iommu_dma_unmap_page(struct device *dev, dma_addr_t handle, size_t size,
enum dma_data_direction dir, unsigned long attrs)
{
__iommu_dma_unmap(iommu_get_domain_for_dev(dev), handle);
}
static int __finalise_sg(struct device *dev, struct scatterlist *sg, int nents,
dma_addr_t dma_addr)
{
struct scatterlist *s, *cur = sg;
unsigned long seg_mask = dma_get_seg_boundary(dev);
unsigned int cur_len = 0, max_len = dma_get_max_seg_size(dev);
int i, count = 0;
for_each_sg(sg, s, nents, i) {
unsigned int s_iova_off = sg_dma_address(s);
unsigned int s_length = sg_dma_len(s);
unsigned int s_iova_len = s->length;
s->offset += s_iova_off;
s->length = s_length;
sg_dma_address(s) = DMA_ERROR_CODE;
sg_dma_len(s) = 0;
if (cur_len && !s_iova_off && (dma_addr & seg_mask) &&
(cur_len + s_length <= max_len)) {
cur_len += s_length;
} else {
if (i > 0)
cur = sg_next(cur);
cur_len = s_length;
count++;
sg_dma_address(cur) = dma_addr + s_iova_off;
}
sg_dma_len(cur) = cur_len;
dma_addr += s_iova_len;
if (s_length + s_iova_off < s_iova_len)
cur_len = 0;
}
return count;
}
static void __invalidate_sg(struct scatterlist *sg, int nents)
{
struct scatterlist *s;
int i;
for_each_sg(sg, s, nents, i) {
if (sg_dma_address(s) != DMA_ERROR_CODE)
s->offset += sg_dma_address(s);
if (sg_dma_len(s))
s->length = sg_dma_len(s);
sg_dma_address(s) = DMA_ERROR_CODE;
sg_dma_len(s) = 0;
}
}
int iommu_dma_map_sg(struct device *dev, struct scatterlist *sg,
int nents, int prot)
{
struct iommu_domain *domain = iommu_get_domain_for_dev(dev);
struct iova_domain *iovad = domain->iova_cookie;
struct iova *iova;
struct scatterlist *s, *prev = NULL;
dma_addr_t dma_addr;
size_t iova_len = 0;
unsigned long mask = dma_get_seg_boundary(dev);
int i;
for_each_sg(sg, s, nents, i) {
size_t s_iova_off = iova_offset(iovad, s->offset);
size_t s_length = s->length;
size_t pad_len = (mask - iova_len + 1) & mask;
sg_dma_address(s) = s_iova_off;
sg_dma_len(s) = s_length;
s->offset -= s_iova_off;
s_length = iova_align(iovad, s_length + s_iova_off);
s->length = s_length;
if (pad_len && pad_len < s_length - 1) {
prev->length += pad_len;
iova_len += pad_len;
}
iova_len += s_length;
prev = s;
}
iova = __alloc_iova(domain, iova_len, dma_get_mask(dev));
if (!iova)
goto out_restore_sg;
dma_addr = iova_dma_addr(iovad, iova);
if (iommu_map_sg(domain, dma_addr, sg, nents, prot) < iova_len)
goto out_free_iova;
return __finalise_sg(dev, sg, nents, dma_addr);
out_free_iova:
__free_iova(iovad, iova);
out_restore_sg:
__invalidate_sg(sg, nents);
return 0;
}
void iommu_dma_unmap_sg(struct device *dev, struct scatterlist *sg, int nents,
enum dma_data_direction dir, unsigned long attrs)
{
__iommu_dma_unmap(iommu_get_domain_for_dev(dev), sg_dma_address(sg));
}
int iommu_dma_supported(struct device *dev, u64 mask)
{
return 1;
}
int iommu_dma_mapping_error(struct device *dev, dma_addr_t dma_addr)
{
return dma_addr == DMA_ERROR_CODE;
}
