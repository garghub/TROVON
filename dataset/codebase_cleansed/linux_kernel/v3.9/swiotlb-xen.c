static dma_addr_t xen_phys_to_bus(phys_addr_t paddr)
{
return phys_to_machine(XPADDR(paddr)).maddr;
}
static phys_addr_t xen_bus_to_phys(dma_addr_t baddr)
{
return machine_to_phys(XMADDR(baddr)).paddr;
}
static dma_addr_t xen_virt_to_bus(void *address)
{
return xen_phys_to_bus(virt_to_phys(address));
}
static int check_pages_physically_contiguous(unsigned long pfn,
unsigned int offset,
size_t length)
{
unsigned long next_mfn;
int i;
int nr_pages;
next_mfn = pfn_to_mfn(pfn);
nr_pages = (offset + length + PAGE_SIZE-1) >> PAGE_SHIFT;
for (i = 1; i < nr_pages; i++) {
if (pfn_to_mfn(++pfn) != ++next_mfn)
return 0;
}
return 1;
}
static int range_straddles_page_boundary(phys_addr_t p, size_t size)
{
unsigned long pfn = PFN_DOWN(p);
unsigned int offset = p & ~PAGE_MASK;
if (offset + size <= PAGE_SIZE)
return 0;
if (check_pages_physically_contiguous(pfn, offset, size))
return 0;
return 1;
}
static int is_xen_swiotlb_buffer(dma_addr_t dma_addr)
{
unsigned long mfn = PFN_DOWN(dma_addr);
unsigned long pfn = mfn_to_local_pfn(mfn);
phys_addr_t paddr;
if (pfn_valid(pfn)) {
paddr = PFN_PHYS(pfn);
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
dma_bits = get_order(IO_TLB_SEGSIZE << IO_TLB_SHIFT) + PAGE_SHIFT;
i = 0;
do {
int slabs = min(nslabs - i, (unsigned long)IO_TLB_SEGSIZE);
do {
rc = xen_create_contiguous_region(
(unsigned long)buf + (i << IO_TLB_SHIFT),
get_order(slabs << IO_TLB_SHIFT),
dma_bits);
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
xen_io_tlb_start = (void *)__get_free_pages(__GFP_NOWARN, order);
if (xen_io_tlb_start)
break;
order--;
}
if (order != get_order(bytes)) {
pr_warn("Warning: only able to allocate %ld MB "
"for software IO TLB\n", (PAGE_SIZE << order) >> 20);
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
return rc;
error:
if (repeat--) {
xen_io_tlb_nslabs = max(1024UL,
(xen_io_tlb_nslabs >> 1));
printk(KERN_INFO "Xen-SWIOTLB: Lowering to %luMB\n",
(xen_io_tlb_nslabs << IO_TLB_SHIFT) >> 20);
goto retry;
}
pr_err("%s (rc:%d)", xen_swiotlb_error(m_ret), rc);
if (early)
panic("%s (rc:%d)", xen_swiotlb_error(m_ret), rc);
else
free_pages((unsigned long)xen_io_tlb_start, order);
return rc;
}
void *
xen_swiotlb_alloc_coherent(struct device *hwdev, size_t size,
dma_addr_t *dma_handle, gfp_t flags,
struct dma_attrs *attrs)
{
void *ret;
int order = get_order(size);
u64 dma_mask = DMA_BIT_MASK(32);
unsigned long vstart;
phys_addr_t phys;
dma_addr_t dev_addr;
flags &= ~(__GFP_DMA | __GFP_HIGHMEM);
if (dma_alloc_from_coherent(hwdev, size, dma_handle, &ret))
return ret;
vstart = __get_free_pages(flags, order);
ret = (void *)vstart;
if (!ret)
return ret;
if (hwdev && hwdev->coherent_dma_mask)
dma_mask = dma_alloc_coherent_mask(hwdev, flags);
phys = virt_to_phys(ret);
dev_addr = xen_phys_to_bus(phys);
if (((dev_addr + size - 1 <= dma_mask)) &&
!range_straddles_page_boundary(phys, size))
*dma_handle = dev_addr;
else {
if (xen_create_contiguous_region(vstart, order,
fls64(dma_mask)) != 0) {
free_pages(vstart, order);
return NULL;
}
*dma_handle = virt_to_machine(ret).maddr;
}
memset(ret, 0, size);
return ret;
}
void
xen_swiotlb_free_coherent(struct device *hwdev, size_t size, void *vaddr,
dma_addr_t dev_addr, struct dma_attrs *attrs)
{
int order = get_order(size);
phys_addr_t phys;
u64 dma_mask = DMA_BIT_MASK(32);
if (dma_release_from_coherent(hwdev, order, vaddr))
return;
if (hwdev && hwdev->coherent_dma_mask)
dma_mask = hwdev->coherent_dma_mask;
phys = virt_to_phys(vaddr);
if (((dev_addr + size - 1 > dma_mask)) ||
range_straddles_page_boundary(phys, size))
xen_destroy_contiguous_region((unsigned long)vaddr, order);
free_pages((unsigned long)vaddr, order);
}
dma_addr_t xen_swiotlb_map_page(struct device *dev, struct page *page,
unsigned long offset, size_t size,
enum dma_data_direction dir,
struct dma_attrs *attrs)
{
phys_addr_t map, phys = page_to_phys(page) + offset;
dma_addr_t dev_addr = xen_phys_to_bus(phys);
BUG_ON(dir == DMA_NONE);
if (dma_capable(dev, dev_addr, size) &&
!range_straddles_page_boundary(phys, size) && !swiotlb_force)
return dev_addr;
map = swiotlb_tbl_map_single(dev, start_dma_addr, phys, size, dir);
if (map == SWIOTLB_MAP_ERROR)
return DMA_ERROR_CODE;
dev_addr = xen_phys_to_bus(map);
if (!dma_capable(dev, dev_addr, size)) {
swiotlb_tbl_unmap_single(dev, map, size, dir);
dev_addr = 0;
}
return dev_addr;
}
static void xen_unmap_single(struct device *hwdev, dma_addr_t dev_addr,
size_t size, enum dma_data_direction dir)
{
phys_addr_t paddr = xen_bus_to_phys(dev_addr);
BUG_ON(dir == DMA_NONE);
if (is_xen_swiotlb_buffer(dev_addr)) {
swiotlb_tbl_unmap_single(hwdev, paddr, size, dir);
return;
}
if (dir != DMA_FROM_DEVICE)
return;
dma_mark_clean(phys_to_virt(paddr), size);
}
void xen_swiotlb_unmap_page(struct device *hwdev, dma_addr_t dev_addr,
size_t size, enum dma_data_direction dir,
struct dma_attrs *attrs)
{
xen_unmap_single(hwdev, dev_addr, size, dir);
}
static void
xen_swiotlb_sync_single(struct device *hwdev, dma_addr_t dev_addr,
size_t size, enum dma_data_direction dir,
enum dma_sync_target target)
{
phys_addr_t paddr = xen_bus_to_phys(dev_addr);
BUG_ON(dir == DMA_NONE);
if (is_xen_swiotlb_buffer(dev_addr)) {
swiotlb_tbl_sync_single(hwdev, paddr, size, dir, target);
return;
}
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
struct dma_attrs *attrs)
{
struct scatterlist *sg;
int i;
BUG_ON(dir == DMA_NONE);
for_each_sg(sgl, sg, nelems, i) {
phys_addr_t paddr = sg_phys(sg);
dma_addr_t dev_addr = xen_phys_to_bus(paddr);
if (swiotlb_force ||
!dma_capable(hwdev, dev_addr, sg->length) ||
range_straddles_page_boundary(paddr, sg->length)) {
phys_addr_t map = swiotlb_tbl_map_single(hwdev,
start_dma_addr,
sg_phys(sg),
sg->length,
dir);
if (map == SWIOTLB_MAP_ERROR) {
xen_swiotlb_unmap_sg_attrs(hwdev, sgl, i, dir,
attrs);
sgl[0].dma_length = 0;
return DMA_ERROR_CODE;
}
sg->dma_address = xen_phys_to_bus(map);
} else
sg->dma_address = dev_addr;
sg->dma_length = sg->length;
}
return nelems;
}
void
xen_swiotlb_unmap_sg_attrs(struct device *hwdev, struct scatterlist *sgl,
int nelems, enum dma_data_direction dir,
struct dma_attrs *attrs)
{
struct scatterlist *sg;
int i;
BUG_ON(dir == DMA_NONE);
for_each_sg(sgl, sg, nelems, i)
xen_unmap_single(hwdev, sg->dma_address, sg->dma_length, dir);
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
sg->dma_length, dir, target);
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
xen_swiotlb_dma_mapping_error(struct device *hwdev, dma_addr_t dma_addr)
{
return !dma_addr;
}
int
xen_swiotlb_dma_supported(struct device *hwdev, u64 mask)
{
return xen_virt_to_bus(xen_io_tlb_end - 1) <= mask;
}
