static inline size_t cookie_msi_granule(struct iommu_dma_cookie *cookie)
{
if (cookie->type == IOMMU_DMA_IOVA_COOKIE)
return cookie->iovad.granule;
return PAGE_SIZE;
}
static inline struct iova_domain *cookie_iovad(struct iommu_domain *domain)
{
struct iommu_dma_cookie *cookie = domain->iova_cookie;
if (cookie->type == IOMMU_DMA_IOVA_COOKIE)
return &cookie->iovad;
return NULL;
}
static struct iommu_dma_cookie *cookie_alloc(enum iommu_dma_cookie_type type)
{
struct iommu_dma_cookie *cookie;
cookie = kzalloc(sizeof(*cookie), GFP_KERNEL);
if (cookie) {
spin_lock_init(&cookie->msi_lock);
INIT_LIST_HEAD(&cookie->msi_page_list);
cookie->type = type;
}
return cookie;
}
int iommu_dma_init(void)
{
return iova_cache_get();
}
int iommu_get_dma_cookie(struct iommu_domain *domain)
{
if (domain->iova_cookie)
return -EEXIST;
domain->iova_cookie = cookie_alloc(IOMMU_DMA_IOVA_COOKIE);
if (!domain->iova_cookie)
return -ENOMEM;
return 0;
}
int iommu_get_msi_cookie(struct iommu_domain *domain, dma_addr_t base)
{
struct iommu_dma_cookie *cookie;
if (domain->type != IOMMU_DOMAIN_UNMANAGED)
return -EINVAL;
if (domain->iova_cookie)
return -EEXIST;
cookie = cookie_alloc(IOMMU_DMA_MSI_COOKIE);
if (!cookie)
return -ENOMEM;
cookie->msi_iova = base;
domain->iova_cookie = cookie;
return 0;
}
void iommu_put_dma_cookie(struct iommu_domain *domain)
{
struct iommu_dma_cookie *cookie = domain->iova_cookie;
struct iommu_dma_msi_page *msi, *tmp;
if (!cookie)
return;
if (cookie->type == IOMMU_DMA_IOVA_COOKIE && cookie->iovad.granule)
put_iova_domain(&cookie->iovad);
list_for_each_entry_safe(msi, tmp, &cookie->msi_page_list, list) {
list_del(&msi->list);
kfree(msi);
}
kfree(cookie);
domain->iova_cookie = NULL;
}
static void iova_reserve_pci_windows(struct pci_dev *dev,
struct iova_domain *iovad)
{
struct pci_host_bridge *bridge = pci_find_host_bridge(dev->bus);
struct resource_entry *window;
unsigned long lo, hi;
resource_list_for_each_entry(window, &bridge->windows) {
if (resource_type(window->res) != IORESOURCE_MEM &&
resource_type(window->res) != IORESOURCE_IO)
continue;
lo = iova_pfn(iovad, window->res->start - window->offset);
hi = iova_pfn(iovad, window->res->end - window->offset);
reserve_iova(iovad, lo, hi);
}
}
int iommu_dma_init_domain(struct iommu_domain *domain, dma_addr_t base,
u64 size, struct device *dev)
{
struct iommu_dma_cookie *cookie = domain->iova_cookie;
struct iova_domain *iovad = &cookie->iovad;
unsigned long order, base_pfn, end_pfn;
bool pci = dev && dev_is_pci(dev);
if (!cookie || cookie->type != IOMMU_DMA_IOVA_COOKIE)
return -EINVAL;
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
if (pci)
end_pfn &= DMA_BIT_MASK(32) >> order;
if (iovad->start_pfn) {
if (1UL << order != iovad->granule ||
base_pfn != iovad->start_pfn) {
pr_warn("Incompatible range for DMA domain\n");
return -EFAULT;
}
iovad->dma_32bit_pfn = min(end_pfn, iovad->dma_32bit_pfn);
} else {
init_iova_domain(iovad, 1UL << order, base_pfn, end_pfn);
if (pci)
iova_reserve_pci_windows(to_pci_dev(dev), iovad);
}
return 0;
}
int dma_info_to_prot(enum dma_data_direction dir, bool coherent,
unsigned long attrs)
{
int prot = coherent ? IOMMU_CACHE : 0;
if (attrs & DMA_ATTR_PRIVILEGED)
prot |= IOMMU_PRIV;
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
dma_addr_t dma_limit, struct device *dev)
{
struct iova_domain *iovad = cookie_iovad(domain);
unsigned long shift = iova_shift(iovad);
unsigned long length = iova_align(iovad, size) >> shift;
struct iova *iova = NULL;
if (domain->geometry.force_aperture)
dma_limit = min(dma_limit, domain->geometry.aperture_end);
if (dma_limit > DMA_BIT_MASK(32) && dev_is_pci(dev))
iova = alloc_iova(iovad, length, DMA_BIT_MASK(32) >> shift,
true);
if (!iova)
iova = alloc_iova(iovad, length, dma_limit >> shift, true);
return iova;
}
static void __iommu_dma_unmap(struct iommu_domain *domain, dma_addr_t dma_addr)
{
struct iova_domain *iovad = cookie_iovad(domain);
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
struct iova_domain *iovad = cookie_iovad(domain);
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
iova = __alloc_iova(domain, size, dev->coherent_dma_mask, dev);
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
static dma_addr_t __iommu_dma_map(struct device *dev, phys_addr_t phys,
size_t size, int prot)
{
dma_addr_t dma_addr;
struct iommu_domain *domain = iommu_get_domain_for_dev(dev);
struct iova_domain *iovad = cookie_iovad(domain);
size_t iova_off = iova_offset(iovad, phys);
size_t len = iova_align(iovad, size + iova_off);
struct iova *iova = __alloc_iova(domain, len, dma_get_mask(dev), dev);
if (!iova)
return DMA_ERROR_CODE;
dma_addr = iova_dma_addr(iovad, iova);
if (iommu_map(domain, dma_addr, phys - iova_off, len, prot)) {
__free_iova(iovad, iova);
return DMA_ERROR_CODE;
}
return dma_addr + iova_off;
}
dma_addr_t iommu_dma_map_page(struct device *dev, struct page *page,
unsigned long offset, size_t size, int prot)
{
return __iommu_dma_map(dev, page_to_phys(page) + offset, size, prot);
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
struct iova_domain *iovad = cookie_iovad(domain);
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
iova = __alloc_iova(domain, iova_len, dma_get_mask(dev), dev);
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
dma_addr_t iommu_dma_map_resource(struct device *dev, phys_addr_t phys,
size_t size, enum dma_data_direction dir, unsigned long attrs)
{
return __iommu_dma_map(dev, phys, size,
dma_info_to_prot(dir, false, attrs) | IOMMU_MMIO);
}
void iommu_dma_unmap_resource(struct device *dev, dma_addr_t handle,
size_t size, enum dma_data_direction dir, unsigned long attrs)
{
__iommu_dma_unmap(iommu_get_domain_for_dev(dev), handle);
}
int iommu_dma_mapping_error(struct device *dev, dma_addr_t dma_addr)
{
return dma_addr == DMA_ERROR_CODE;
}
static struct iommu_dma_msi_page *iommu_dma_get_msi_page(struct device *dev,
phys_addr_t msi_addr, struct iommu_domain *domain)
{
struct iommu_dma_cookie *cookie = domain->iova_cookie;
struct iommu_dma_msi_page *msi_page;
struct iova_domain *iovad = cookie_iovad(domain);
struct iova *iova;
int prot = IOMMU_WRITE | IOMMU_NOEXEC | IOMMU_MMIO;
size_t size = cookie_msi_granule(cookie);
msi_addr &= ~(phys_addr_t)(size - 1);
list_for_each_entry(msi_page, &cookie->msi_page_list, list)
if (msi_page->phys == msi_addr)
return msi_page;
msi_page = kzalloc(sizeof(*msi_page), GFP_ATOMIC);
if (!msi_page)
return NULL;
msi_page->phys = msi_addr;
if (iovad) {
iova = __alloc_iova(domain, size, dma_get_mask(dev), dev);
if (!iova)
goto out_free_page;
msi_page->iova = iova_dma_addr(iovad, iova);
} else {
msi_page->iova = cookie->msi_iova;
cookie->msi_iova += size;
}
if (iommu_map(domain, msi_page->iova, msi_addr, size, prot))
goto out_free_iova;
INIT_LIST_HEAD(&msi_page->list);
list_add(&msi_page->list, &cookie->msi_page_list);
return msi_page;
out_free_iova:
if (iovad)
__free_iova(iovad, iova);
else
cookie->msi_iova -= size;
out_free_page:
kfree(msi_page);
return NULL;
}
void iommu_dma_map_msi_msg(int irq, struct msi_msg *msg)
{
struct device *dev = msi_desc_to_dev(irq_get_msi_desc(irq));
struct iommu_domain *domain = iommu_get_domain_for_dev(dev);
struct iommu_dma_cookie *cookie;
struct iommu_dma_msi_page *msi_page;
phys_addr_t msi_addr = (u64)msg->address_hi << 32 | msg->address_lo;
unsigned long flags;
if (!domain || !domain->iova_cookie)
return;
cookie = domain->iova_cookie;
spin_lock_irqsave(&cookie->msi_lock, flags);
msi_page = iommu_dma_get_msi_page(dev, msi_addr, domain);
spin_unlock_irqrestore(&cookie->msi_lock, flags);
if (WARN_ON(!msi_page)) {
msg->address_hi = ~0U;
msg->address_lo = ~0U;
msg->data = ~0U;
} else {
msg->address_hi = upper_32_bits(msi_page->iova);
msg->address_lo &= cookie_msi_granule(cookie) - 1;
msg->address_lo += lower_32_bits(msi_page->iova);
}
}
