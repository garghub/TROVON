static unsigned long dma_alloc_coherent_mask(struct device *dev,
gfp_t gfp)
{
unsigned long dma_mask = 0;
dma_mask = dev->coherent_dma_mask;
if (!dma_mask)
dma_mask = (gfp & GFP_DMA) ? DMA_BIT_MASK(24) : DMA_BIT_MASK(32);
return dma_mask;
}
static inline dma_addr_t xen_phys_to_bus(phys_addr_t paddr)
{
unsigned long bfn = pfn_to_bfn(XEN_PFN_DOWN(paddr));
dma_addr_t dma = (dma_addr_t)bfn << XEN_PAGE_SHIFT;
dma |= paddr & ~XEN_PAGE_MASK;
return dma;
}
static inline phys_addr_t xen_bus_to_phys(dma_addr_t baddr)
{
unsigned long xen_pfn = bfn_to_pfn(XEN_PFN_DOWN(baddr));
dma_addr_t dma = (dma_addr_t)xen_pfn << XEN_PAGE_SHIFT;
phys_addr_t paddr = dma;
paddr |= baddr & ~XEN_PAGE_MASK;
return paddr;
}
static inline dma_addr_t xen_virt_to_bus(void *address)
{
return xen_phys_to_bus(virt_to_phys(address));
}
static int check_pages_physically_contiguous(unsigned long xen_pfn,
unsigned int offset,
size_t length)
{
unsigned long next_bfn;
int i;
int nr_pages;
next_bfn = pfn_to_bfn(xen_pfn);
nr_pages = (offset + length + XEN_PAGE_SIZE-1) >> XEN_PAGE_SHIFT;
for (i = 1; i < nr_pages; i++) {
if (pfn_to_bfn(++xen_pfn) != ++next_bfn)
return 0;
}
return 1;
}
static inline int range_straddles_page_boundary(phys_addr_t p, size_t size)
{
unsigned long xen_pfn = XEN_PFN_DOWN(p);
unsigned int offset = p & ~XEN_PAGE_MASK;
if (offset + size <= XEN_PAGE_SIZE)
return 0;
if (check_pages_physically_contiguous(xen_pfn, offset, size))
return 0;
return 1;
}
static int is_xen_swiotlb_buffer(dma_addr_t dma_addr)
{
unsigned long bfn = XEN_PFN_DOWN(dma_addr);
unsigned long xen_pfn = bfn_to_local_pfn(bfn);
phys_addr_t paddr = XEN_PFN_PHYS(xen_pfn);
if (pfn_valid(PFN_DOWN(paddr))) {
return paddr >= virt_to_phys(xen_io_tlb_start) &&
paddr < virt_to_phys(xen_io_tlb_end);
}
return 0;
}
static int
xen_swiotlb_fixup(void *buf, size_t size, unsigned long nslabs)
{
int i, rc;
int dma_bits;
dma_addr_t dma_handle;
phys_addr_t p = virt_to_phys(buf);
dma_bits = get_order(IO_TLB_SEGSIZE << IO_TLB_SHIFT) + PAGE_SHIFT;
i = 0;
do {
int slabs = min(nslabs - i, (unsigned long)IO_TLB_SEGSIZE);
do {
rc = xen_create_contiguous_region(
p + (i << IO_TLB_SHIFT),
get_order(slabs << IO_TLB_SHIFT),
dma_bits, &dma_handle);
} while (rc && dma_bits++ < max_dma_bits);
if (rc)
return rc;
i += slabs;
} while (i < nslabs);
return 0;
}
static unsigned long xen_set_nslabs(unsigned long nr_tbl)
{
if (!nr_tbl) {
xen_io_tlb_nslabs = (64 * 1024 * 1024 >> IO_TLB_SHIFT);
xen_io_tlb_nslabs = ALIGN(xen_io_tlb_nslabs, IO_TLB_SEGSIZE);
} else
xen_io_tlb_nslabs = nr_tbl;
return xen_io_tlb_nslabs << IO_TLB_SHIFT;
}
static const char *xen_swiotlb_error(enum xen_swiotlb_err err)
{
switch (err) {
case XEN_SWIOTLB_ENOMEM:
return "Cannot allocate Xen-SWIOTLB buffer\n";
case XEN_SWIOTLB_EFIXUP:
return "Failed to get contiguous memory for DMA from Xen!\n"\
"You either: don't have the permissions, do not have"\
" enough free memory under 4GB, or the hypervisor memory"\
" is too fragmented!";
default:
break;
}
return "";
}
int __ref xen_swiotlb_init(int verbose, bool early)
{
unsigned long bytes, order;
int rc = -ENOMEM;
enum xen_swiotlb_err m_ret = XEN_SWIOTLB_UNKNOWN;
unsigned int repeat = 3;
xen_io_tlb_nslabs = swiotlb_nr_tbl();
retry:
bytes = xen_set_nslabs(xen_io_tlb_nslabs);
order = get_order(xen_io_tlb_nslabs << IO_TLB_SHIFT);
if (early)
xen_io_tlb_start = alloc_bootmem_pages(PAGE_ALIGN(bytes));
else {
#define SLABS_PER_PAGE (1 << (PAGE_SHIFT - IO_TLB_SHIFT))
#define IO_TLB_MIN_SLABS ((1<<20) >> IO_TLB_SHIFT)
while ((SLABS_PER_PAGE << order) > IO_TLB_MIN_SLABS) {
xen_io_tlb_start = (void *)xen_get_swiotlb_free_pages(order);
if (xen_io_tlb_start)
break;
order--;
}
if (order != get_order(bytes)) {
pr_warn("Warning: only able to allocate %ld MB for software IO TLB\n",
(PAGE_SIZE << order) >> 20);
xen_io_tlb_nslabs = SLABS_PER_PAGE << order;
bytes = xen_io_tlb_nslabs << IO_TLB_SHIFT;
}
}
if (!xen_io_tlb_start) {
m_ret = XEN_SWIOTLB_ENOMEM;
goto error;
}
xen_io_tlb_end = xen_io_tlb_start + bytes;
rc = xen_swiotlb_fixup(xen_io_tlb_start,
bytes,
xen_io_tlb_nslabs);
if (rc) {
if (early)
free_bootmem(__pa(xen_io_tlb_start), PAGE_ALIGN(bytes));
else {
free_pages((unsigned long)xen_io_tlb_start, order);
xen_io_tlb_start = NULL;
}
m_ret = XEN_SWIOTLB_EFIXUP;
goto error;
}
start_dma_addr = xen_virt_to_bus(xen_io_tlb_start);
if (early) {
if (swiotlb_init_with_tbl(xen_io_tlb_start, xen_io_tlb_nslabs,
verbose))
panic("Cannot allocate SWIOTLB buffer");
rc = 0;
} else
rc = swiotlb_late_init_with_tbl(xen_io_tlb_start, xen_io_tlb_nslabs);
if (!rc)
swiotlb_set_max_segment(PAGE_SIZE);
return rc;
error:
if (repeat--) {
xen_io_tlb_nslabs = max(1024UL,
(xen_io_tlb_nslabs >> 1));
pr_info("Lowering to %luMB\n",
(xen_io_tlb_nslabs << IO_TLB_SHIFT) >> 20);
goto retry;
}
pr_err("%s (rc:%d)\n", xen_swiotlb_error(m_ret), rc);
if (early)
panic("%s (rc:%d)", xen_swiotlb_error(m_ret), rc);
else
free_pages((unsigned long)xen_io_tlb_start, order);
return rc;
}
void *
xen_swiotlb_alloc_coherent(struct device *hwdev, size_t size,
dma_addr_t *dma_handle, gfp_t flags,
unsigned long attrs)
{
void *ret;
int order = get_order(size);
u64 dma_mask = DMA_BIT_MASK(32);
phys_addr_t phys;
dma_addr_t dev_addr;
flags &= ~(__GFP_DMA | __GFP_HIGHMEM);
ret = xen_alloc_coherent_pages(hwdev, size, dma_handle, flags, attrs);
if (!ret)
return ret;
if (hwdev && hwdev->coherent_dma_mask)
dma_mask = dma_alloc_coherent_mask(hwdev, flags);
phys = *dma_handle;
dev_addr = xen_phys_to_bus(phys);
if (((dev_addr + size - 1 <= dma_mask)) &&
!range_straddles_page_boundary(phys, size))
*dma_handle = dev_addr;
else {
if (xen_create_contiguous_region(phys, order,
fls64(dma_mask), dma_handle) != 0) {
xen_free_coherent_pages(hwdev, size, ret, (dma_addr_t)phys, attrs);
return NULL;
}
}
memset(ret, 0, size);
return ret;
}
void
xen_swiotlb_free_coherent(struct device *hwdev, size_t size, void *vaddr,
dma_addr_t dev_addr, unsigned long attrs)
{
int order = get_order(size);
phys_addr_t phys;
u64 dma_mask = DMA_BIT_MASK(32);
if (hwdev && hwdev->coherent_dma_mask)
dma_mask = hwdev->coherent_dma_mask;
phys = xen_bus_to_phys(dev_addr);
if (((dev_addr + size - 1 > dma_mask)) ||
range_straddles_page_boundary(phys, size))
xen_destroy_contiguous_region(phys, order);
xen_free_coherent_pages(hwdev, size, vaddr, (dma_addr_t)phys, attrs);
}
dma_addr_t xen_swiotlb_map_page(struct device *dev, struct page *page,
unsigned long offset, size_t size,
enum dma_data_direction dir,
unsigned long attrs)
{
phys_addr_t map, phys = page_to_phys(page) + offset;
dma_addr_t dev_addr = xen_phys_to_bus(phys);
BUG_ON(dir == DMA_NONE);
if (dma_capable(dev, dev_addr, size) &&
!range_straddles_page_boundary(phys, size) &&
!xen_arch_need_swiotlb(dev, phys, dev_addr) &&
(swiotlb_force != SWIOTLB_FORCE)) {
xen_dma_map_page(dev, page, dev_addr, offset, size, dir, attrs);
return dev_addr;
}
trace_swiotlb_bounced(dev, dev_addr, size, swiotlb_force);
map = swiotlb_tbl_map_single(dev, start_dma_addr, phys, size, dir,
attrs);
if (map == SWIOTLB_MAP_ERROR)
return DMA_ERROR_CODE;
dev_addr = xen_phys_to_bus(map);
xen_dma_map_page(dev, pfn_to_page(map >> PAGE_SHIFT),
dev_addr, map & ~PAGE_MASK, size, dir, attrs);
if (dma_capable(dev, dev_addr, size))
return dev_addr;
attrs |= DMA_ATTR_SKIP_CPU_SYNC;
swiotlb_tbl_unmap_single(dev, map, size, dir, attrs);
return DMA_ERROR_CODE;
}
static void xen_unmap_single(struct device *hwdev, dma_addr_t dev_addr,
size_t size, enum dma_data_direction dir,
unsigned long attrs)
{
phys_addr_t paddr = xen_bus_to_phys(dev_addr);
BUG_ON(dir == DMA_NONE);
xen_dma_unmap_page(hwdev, dev_addr, size, dir, attrs);
if (is_xen_swiotlb_buffer(dev_addr)) {
swiotlb_tbl_unmap_single(hwdev, paddr, size, dir, attrs);
return;
}
if (dir != DMA_FROM_DEVICE)
return;
dma_mark_clean(phys_to_virt(paddr), size);
}
void xen_swiotlb_unmap_page(struct device *hwdev, dma_addr_t dev_addr,
size_t size, enum dma_data_direction dir,
unsigned long attrs)
{
xen_unmap_single(hwdev, dev_addr, size, dir, attrs);
}
static void
xen_swiotlb_sync_single(struct device *hwdev, dma_addr_t dev_addr,
size_t size, enum dma_data_direction dir,
enum dma_sync_target target)
{
phys_addr_t paddr = xen_bus_to_phys(dev_addr);
BUG_ON(dir == DMA_NONE);
if (target == SYNC_FOR_CPU)
xen_dma_sync_single_for_cpu(hwdev, dev_addr, size, dir);
if (is_xen_swiotlb_buffer(dev_addr))
swiotlb_tbl_sync_single(hwdev, paddr, size, dir, target);
if (target == SYNC_FOR_DEVICE)
xen_dma_sync_single_for_device(hwdev, dev_addr, size, dir);
if (dir != DMA_FROM_DEVICE)
return;
dma_mark_clean(phys_to_virt(paddr), size);
}
void
xen_swiotlb_sync_single_for_cpu(struct device *hwdev, dma_addr_t dev_addr,
size_t size, enum dma_data_direction dir)
{
xen_swiotlb_sync_single(hwdev, dev_addr, size, dir, SYNC_FOR_CPU);
}
void
xen_swiotlb_sync_single_for_device(struct device *hwdev, dma_addr_t dev_addr,
size_t size, enum dma_data_direction dir)
{
xen_swiotlb_sync_single(hwdev, dev_addr, size, dir, SYNC_FOR_DEVICE);
}
int
xen_swiotlb_map_sg_attrs(struct device *hwdev, struct scatterlist *sgl,
int nelems, enum dma_data_direction dir,
unsigned long attrs)
{
struct scatterlist *sg;
int i;
BUG_ON(dir == DMA_NONE);
for_each_sg(sgl, sg, nelems, i) {
phys_addr_t paddr = sg_phys(sg);
dma_addr_t dev_addr = xen_phys_to_bus(paddr);
if (swiotlb_force == SWIOTLB_FORCE ||
xen_arch_need_swiotlb(hwdev, paddr, dev_addr) ||
!dma_capable(hwdev, dev_addr, sg->length) ||
range_straddles_page_boundary(paddr, sg->length)) {
phys_addr_t map = swiotlb_tbl_map_single(hwdev,
start_dma_addr,
sg_phys(sg),
sg->length,
dir, attrs);
if (map == SWIOTLB_MAP_ERROR) {
dev_warn(hwdev, "swiotlb buffer is full\n");
attrs |= DMA_ATTR_SKIP_CPU_SYNC;
xen_swiotlb_unmap_sg_attrs(hwdev, sgl, i, dir,
attrs);
sg_dma_len(sgl) = 0;
return 0;
}
dev_addr = xen_phys_to_bus(map);
xen_dma_map_page(hwdev, pfn_to_page(map >> PAGE_SHIFT),
dev_addr,
map & ~PAGE_MASK,
sg->length,
dir,
attrs);
sg->dma_address = dev_addr;
} else {
xen_dma_map_page(hwdev, pfn_to_page(paddr >> PAGE_SHIFT),
dev_addr,
paddr & ~PAGE_MASK,
sg->length,
dir,
attrs);
sg->dma_address = dev_addr;
}
sg_dma_len(sg) = sg->length;
}
return nelems;
}
void
xen_swiotlb_unmap_sg_attrs(struct device *hwdev, struct scatterlist *sgl,
int nelems, enum dma_data_direction dir,
unsigned long attrs)
{
struct scatterlist *sg;
int i;
BUG_ON(dir == DMA_NONE);
for_each_sg(sgl, sg, nelems, i)
xen_unmap_single(hwdev, sg->dma_address, sg_dma_len(sg), dir, attrs);
}
static void
xen_swiotlb_sync_sg(struct device *hwdev, struct scatterlist *sgl,
int nelems, enum dma_data_direction dir,
enum dma_sync_target target)
{
struct scatterlist *sg;
int i;
for_each_sg(sgl, sg, nelems, i)
xen_swiotlb_sync_single(hwdev, sg->dma_address,
sg_dma_len(sg), dir, target);
}
void
xen_swiotlb_sync_sg_for_cpu(struct device *hwdev, struct scatterlist *sg,
int nelems, enum dma_data_direction dir)
{
xen_swiotlb_sync_sg(hwdev, sg, nelems, dir, SYNC_FOR_CPU);
}
void
xen_swiotlb_sync_sg_for_device(struct device *hwdev, struct scatterlist *sg,
int nelems, enum dma_data_direction dir)
{
xen_swiotlb_sync_sg(hwdev, sg, nelems, dir, SYNC_FOR_DEVICE);
}
int
xen_swiotlb_dma_supported(struct device *hwdev, u64 mask)
{
return xen_virt_to_bus(xen_io_tlb_end - 1) <= mask;
}
int
xen_swiotlb_set_dma_mask(struct device *dev, u64 dma_mask)
{
if (!dev->dma_mask || !xen_swiotlb_dma_supported(dev, dma_mask))
return -EIO;
*dev->dma_mask = dma_mask;
return 0;
}
