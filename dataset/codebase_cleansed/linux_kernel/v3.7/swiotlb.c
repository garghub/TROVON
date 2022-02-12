static int __init
setup_io_tlb_npages(char *str)
{
if (isdigit(*str)) {
io_tlb_nslabs = simple_strtoul(str, &str, 0);
io_tlb_nslabs = ALIGN(io_tlb_nslabs, IO_TLB_SEGSIZE);
}
if (*str == ',')
++str;
if (!strcmp(str, "force"))
swiotlb_force = 1;
return 1;
}
unsigned long swiotlb_nr_tbl(void)
{
return io_tlb_nslabs;
}
static dma_addr_t swiotlb_virt_to_bus(struct device *hwdev,
volatile void *address)
{
return phys_to_dma(hwdev, virt_to_phys(address));
}
void swiotlb_print_info(void)
{
unsigned long bytes = io_tlb_nslabs << IO_TLB_SHIFT;
phys_addr_t pstart, pend;
pstart = virt_to_phys(io_tlb_start);
pend = virt_to_phys(io_tlb_end);
printk(KERN_INFO "software IO TLB [mem %#010llx-%#010llx] (%luMB) mapped at [%p-%p]\n",
(unsigned long long)pstart, (unsigned long long)pend - 1,
bytes >> 20, io_tlb_start, io_tlb_end - 1);
}
void __init swiotlb_init_with_tbl(char *tlb, unsigned long nslabs, int verbose)
{
unsigned long i, bytes;
bytes = nslabs << IO_TLB_SHIFT;
io_tlb_nslabs = nslabs;
io_tlb_start = tlb;
io_tlb_end = io_tlb_start + bytes;
io_tlb_list = alloc_bootmem_pages(PAGE_ALIGN(io_tlb_nslabs * sizeof(int)));
for (i = 0; i < io_tlb_nslabs; i++)
io_tlb_list[i] = IO_TLB_SEGSIZE - OFFSET(i, IO_TLB_SEGSIZE);
io_tlb_index = 0;
io_tlb_orig_addr = alloc_bootmem_pages(PAGE_ALIGN(io_tlb_nslabs * sizeof(phys_addr_t)));
io_tlb_overflow_buffer = alloc_bootmem_low_pages(PAGE_ALIGN(io_tlb_overflow));
if (!io_tlb_overflow_buffer)
panic("Cannot allocate SWIOTLB overflow buffer!\n");
if (verbose)
swiotlb_print_info();
}
static void __init
swiotlb_init_with_default_size(size_t default_size, int verbose)
{
unsigned long bytes;
if (!io_tlb_nslabs) {
io_tlb_nslabs = (default_size >> IO_TLB_SHIFT);
io_tlb_nslabs = ALIGN(io_tlb_nslabs, IO_TLB_SEGSIZE);
}
bytes = io_tlb_nslabs << IO_TLB_SHIFT;
io_tlb_start = alloc_bootmem_low_pages(PAGE_ALIGN(bytes));
if (!io_tlb_start)
panic("Cannot allocate SWIOTLB buffer");
swiotlb_init_with_tbl(io_tlb_start, io_tlb_nslabs, verbose);
}
void __init
swiotlb_init(int verbose)
{
swiotlb_init_with_default_size(64 * (1<<20), verbose);
}
int
swiotlb_late_init_with_default_size(size_t default_size)
{
unsigned long bytes, req_nslabs = io_tlb_nslabs;
unsigned int order;
int rc = 0;
if (!io_tlb_nslabs) {
io_tlb_nslabs = (default_size >> IO_TLB_SHIFT);
io_tlb_nslabs = ALIGN(io_tlb_nslabs, IO_TLB_SEGSIZE);
}
order = get_order(io_tlb_nslabs << IO_TLB_SHIFT);
io_tlb_nslabs = SLABS_PER_PAGE << order;
bytes = io_tlb_nslabs << IO_TLB_SHIFT;
while ((SLABS_PER_PAGE << order) > IO_TLB_MIN_SLABS) {
io_tlb_start = (void *)__get_free_pages(GFP_DMA | __GFP_NOWARN,
order);
if (io_tlb_start)
break;
order--;
}
if (!io_tlb_start) {
io_tlb_nslabs = req_nslabs;
return -ENOMEM;
}
if (order != get_order(bytes)) {
printk(KERN_WARNING "Warning: only able to allocate %ld MB "
"for software IO TLB\n", (PAGE_SIZE << order) >> 20);
io_tlb_nslabs = SLABS_PER_PAGE << order;
}
rc = swiotlb_late_init_with_tbl(io_tlb_start, io_tlb_nslabs);
if (rc)
free_pages((unsigned long)io_tlb_start, order);
return rc;
}
int
swiotlb_late_init_with_tbl(char *tlb, unsigned long nslabs)
{
unsigned long i, bytes;
bytes = nslabs << IO_TLB_SHIFT;
io_tlb_nslabs = nslabs;
io_tlb_start = tlb;
io_tlb_end = io_tlb_start + bytes;
memset(io_tlb_start, 0, bytes);
io_tlb_list = (unsigned int *)__get_free_pages(GFP_KERNEL,
get_order(io_tlb_nslabs * sizeof(int)));
if (!io_tlb_list)
goto cleanup2;
for (i = 0; i < io_tlb_nslabs; i++)
io_tlb_list[i] = IO_TLB_SEGSIZE - OFFSET(i, IO_TLB_SEGSIZE);
io_tlb_index = 0;
io_tlb_orig_addr = (phys_addr_t *)
__get_free_pages(GFP_KERNEL,
get_order(io_tlb_nslabs *
sizeof(phys_addr_t)));
if (!io_tlb_orig_addr)
goto cleanup3;
memset(io_tlb_orig_addr, 0, io_tlb_nslabs * sizeof(phys_addr_t));
io_tlb_overflow_buffer = (void *)__get_free_pages(GFP_DMA,
get_order(io_tlb_overflow));
if (!io_tlb_overflow_buffer)
goto cleanup4;
swiotlb_print_info();
late_alloc = 1;
return 0;
cleanup4:
free_pages((unsigned long)io_tlb_orig_addr,
get_order(io_tlb_nslabs * sizeof(phys_addr_t)));
io_tlb_orig_addr = NULL;
cleanup3:
free_pages((unsigned long)io_tlb_list, get_order(io_tlb_nslabs *
sizeof(int)));
io_tlb_list = NULL;
cleanup2:
io_tlb_end = NULL;
io_tlb_start = NULL;
io_tlb_nslabs = 0;
return -ENOMEM;
}
void __init swiotlb_free(void)
{
if (!io_tlb_overflow_buffer)
return;
if (late_alloc) {
free_pages((unsigned long)io_tlb_overflow_buffer,
get_order(io_tlb_overflow));
free_pages((unsigned long)io_tlb_orig_addr,
get_order(io_tlb_nslabs * sizeof(phys_addr_t)));
free_pages((unsigned long)io_tlb_list, get_order(io_tlb_nslabs *
sizeof(int)));
free_pages((unsigned long)io_tlb_start,
get_order(io_tlb_nslabs << IO_TLB_SHIFT));
} else {
free_bootmem_late(__pa(io_tlb_overflow_buffer),
PAGE_ALIGN(io_tlb_overflow));
free_bootmem_late(__pa(io_tlb_orig_addr),
PAGE_ALIGN(io_tlb_nslabs * sizeof(phys_addr_t)));
free_bootmem_late(__pa(io_tlb_list),
PAGE_ALIGN(io_tlb_nslabs * sizeof(int)));
free_bootmem_late(__pa(io_tlb_start),
PAGE_ALIGN(io_tlb_nslabs << IO_TLB_SHIFT));
}
io_tlb_nslabs = 0;
}
static int is_swiotlb_buffer(phys_addr_t paddr)
{
return paddr >= virt_to_phys(io_tlb_start) &&
paddr < virt_to_phys(io_tlb_end);
}
void swiotlb_bounce(phys_addr_t phys, char *dma_addr, size_t size,
enum dma_data_direction dir)
{
unsigned long pfn = PFN_DOWN(phys);
if (PageHighMem(pfn_to_page(pfn))) {
unsigned int offset = phys & ~PAGE_MASK;
char *buffer;
unsigned int sz = 0;
unsigned long flags;
while (size) {
sz = min_t(size_t, PAGE_SIZE - offset, size);
local_irq_save(flags);
buffer = kmap_atomic(pfn_to_page(pfn));
if (dir == DMA_TO_DEVICE)
memcpy(dma_addr, buffer + offset, sz);
else
memcpy(buffer + offset, dma_addr, sz);
kunmap_atomic(buffer);
local_irq_restore(flags);
size -= sz;
pfn++;
dma_addr += sz;
offset = 0;
}
} else {
if (dir == DMA_TO_DEVICE)
memcpy(dma_addr, phys_to_virt(phys), size);
else
memcpy(phys_to_virt(phys), dma_addr, size);
}
}
void *swiotlb_tbl_map_single(struct device *hwdev, dma_addr_t tbl_dma_addr,
phys_addr_t phys, size_t size,
enum dma_data_direction dir)
{
unsigned long flags;
char *dma_addr;
unsigned int nslots, stride, index, wrap;
int i;
unsigned long mask;
unsigned long offset_slots;
unsigned long max_slots;
mask = dma_get_seg_boundary(hwdev);
tbl_dma_addr &= mask;
offset_slots = ALIGN(tbl_dma_addr, 1 << IO_TLB_SHIFT) >> IO_TLB_SHIFT;
max_slots = mask + 1
? ALIGN(mask + 1, 1 << IO_TLB_SHIFT) >> IO_TLB_SHIFT
: 1UL << (BITS_PER_LONG - IO_TLB_SHIFT);
nslots = ALIGN(size, 1 << IO_TLB_SHIFT) >> IO_TLB_SHIFT;
if (size > PAGE_SIZE)
stride = (1 << (PAGE_SHIFT - IO_TLB_SHIFT));
else
stride = 1;
BUG_ON(!nslots);
spin_lock_irqsave(&io_tlb_lock, flags);
index = ALIGN(io_tlb_index, stride);
if (index >= io_tlb_nslabs)
index = 0;
wrap = index;
do {
while (iommu_is_span_boundary(index, nslots, offset_slots,
max_slots)) {
index += stride;
if (index >= io_tlb_nslabs)
index = 0;
if (index == wrap)
goto not_found;
}
if (io_tlb_list[index] >= nslots) {
int count = 0;
for (i = index; i < (int) (index + nslots); i++)
io_tlb_list[i] = 0;
for (i = index - 1; (OFFSET(i, IO_TLB_SEGSIZE) != IO_TLB_SEGSIZE - 1) && io_tlb_list[i]; i--)
io_tlb_list[i] = ++count;
dma_addr = io_tlb_start + (index << IO_TLB_SHIFT);
io_tlb_index = ((index + nslots) < io_tlb_nslabs
? (index + nslots) : 0);
goto found;
}
index += stride;
if (index >= io_tlb_nslabs)
index = 0;
} while (index != wrap);
not_found:
spin_unlock_irqrestore(&io_tlb_lock, flags);
return NULL;
found:
spin_unlock_irqrestore(&io_tlb_lock, flags);
for (i = 0; i < nslots; i++)
io_tlb_orig_addr[index+i] = phys + (i << IO_TLB_SHIFT);
if (dir == DMA_TO_DEVICE || dir == DMA_BIDIRECTIONAL)
swiotlb_bounce(phys, dma_addr, size, DMA_TO_DEVICE);
return dma_addr;
}
static void *
map_single(struct device *hwdev, phys_addr_t phys, size_t size,
enum dma_data_direction dir)
{
dma_addr_t start_dma_addr = swiotlb_virt_to_bus(hwdev, io_tlb_start);
return swiotlb_tbl_map_single(hwdev, start_dma_addr, phys, size, dir);
}
void
swiotlb_tbl_unmap_single(struct device *hwdev, char *dma_addr, size_t size,
enum dma_data_direction dir)
{
unsigned long flags;
int i, count, nslots = ALIGN(size, 1 << IO_TLB_SHIFT) >> IO_TLB_SHIFT;
int index = (dma_addr - io_tlb_start) >> IO_TLB_SHIFT;
phys_addr_t phys = io_tlb_orig_addr[index];
if (phys && ((dir == DMA_FROM_DEVICE) || (dir == DMA_BIDIRECTIONAL)))
swiotlb_bounce(phys, dma_addr, size, DMA_FROM_DEVICE);
spin_lock_irqsave(&io_tlb_lock, flags);
{
count = ((index + nslots) < ALIGN(index + 1, IO_TLB_SEGSIZE) ?
io_tlb_list[index + nslots] : 0);
for (i = index + nslots - 1; i >= index; i--)
io_tlb_list[i] = ++count;
for (i = index - 1; (OFFSET(i, IO_TLB_SEGSIZE) != IO_TLB_SEGSIZE -1) && io_tlb_list[i]; i--)
io_tlb_list[i] = ++count;
}
spin_unlock_irqrestore(&io_tlb_lock, flags);
}
void
swiotlb_tbl_sync_single(struct device *hwdev, char *dma_addr, size_t size,
enum dma_data_direction dir,
enum dma_sync_target target)
{
int index = (dma_addr - io_tlb_start) >> IO_TLB_SHIFT;
phys_addr_t phys = io_tlb_orig_addr[index];
phys += ((unsigned long)dma_addr & ((1 << IO_TLB_SHIFT) - 1));
switch (target) {
case SYNC_FOR_CPU:
if (likely(dir == DMA_FROM_DEVICE || dir == DMA_BIDIRECTIONAL))
swiotlb_bounce(phys, dma_addr, size, DMA_FROM_DEVICE);
else
BUG_ON(dir != DMA_TO_DEVICE);
break;
case SYNC_FOR_DEVICE:
if (likely(dir == DMA_TO_DEVICE || dir == DMA_BIDIRECTIONAL))
swiotlb_bounce(phys, dma_addr, size, DMA_TO_DEVICE);
else
BUG_ON(dir != DMA_FROM_DEVICE);
break;
default:
BUG();
}
}
void *
swiotlb_alloc_coherent(struct device *hwdev, size_t size,
dma_addr_t *dma_handle, gfp_t flags)
{
dma_addr_t dev_addr;
void *ret;
int order = get_order(size);
u64 dma_mask = DMA_BIT_MASK(32);
if (hwdev && hwdev->coherent_dma_mask)
dma_mask = hwdev->coherent_dma_mask;
ret = (void *)__get_free_pages(flags, order);
if (ret && swiotlb_virt_to_bus(hwdev, ret) + size - 1 > dma_mask) {
free_pages((unsigned long) ret, order);
ret = NULL;
}
if (!ret) {
ret = map_single(hwdev, 0, size, DMA_FROM_DEVICE);
if (!ret)
return NULL;
}
memset(ret, 0, size);
dev_addr = swiotlb_virt_to_bus(hwdev, ret);
if (dev_addr + size - 1 > dma_mask) {
printk("hwdev DMA mask = 0x%016Lx, dev_addr = 0x%016Lx\n",
(unsigned long long)dma_mask,
(unsigned long long)dev_addr);
swiotlb_tbl_unmap_single(hwdev, ret, size, DMA_TO_DEVICE);
return NULL;
}
*dma_handle = dev_addr;
return ret;
}
void
swiotlb_free_coherent(struct device *hwdev, size_t size, void *vaddr,
dma_addr_t dev_addr)
{
phys_addr_t paddr = dma_to_phys(hwdev, dev_addr);
WARN_ON(irqs_disabled());
if (!is_swiotlb_buffer(paddr))
free_pages((unsigned long)vaddr, get_order(size));
else
swiotlb_tbl_unmap_single(hwdev, vaddr, size, DMA_TO_DEVICE);
}
static void
swiotlb_full(struct device *dev, size_t size, enum dma_data_direction dir,
int do_panic)
{
printk(KERN_ERR "DMA: Out of SW-IOMMU space for %zu bytes at "
"device %s\n", size, dev ? dev_name(dev) : "?");
if (size <= io_tlb_overflow || !do_panic)
return;
if (dir == DMA_BIDIRECTIONAL)
panic("DMA: Random memory could be DMA accessed\n");
if (dir == DMA_FROM_DEVICE)
panic("DMA: Random memory could be DMA written\n");
if (dir == DMA_TO_DEVICE)
panic("DMA: Random memory could be DMA read\n");
}
dma_addr_t swiotlb_map_page(struct device *dev, struct page *page,
unsigned long offset, size_t size,
enum dma_data_direction dir,
struct dma_attrs *attrs)
{
phys_addr_t phys = page_to_phys(page) + offset;
dma_addr_t dev_addr = phys_to_dma(dev, phys);
void *map;
BUG_ON(dir == DMA_NONE);
if (dma_capable(dev, dev_addr, size) && !swiotlb_force)
return dev_addr;
map = map_single(dev, phys, size, dir);
if (!map) {
swiotlb_full(dev, size, dir, 1);
map = io_tlb_overflow_buffer;
}
dev_addr = swiotlb_virt_to_bus(dev, map);
if (!dma_capable(dev, dev_addr, size)) {
swiotlb_tbl_unmap_single(dev, map, size, dir);
dev_addr = swiotlb_virt_to_bus(dev, io_tlb_overflow_buffer);
}
return dev_addr;
}
static void unmap_single(struct device *hwdev, dma_addr_t dev_addr,
size_t size, enum dma_data_direction dir)
{
phys_addr_t paddr = dma_to_phys(hwdev, dev_addr);
BUG_ON(dir == DMA_NONE);
if (is_swiotlb_buffer(paddr)) {
swiotlb_tbl_unmap_single(hwdev, phys_to_virt(paddr), size, dir);
return;
}
if (dir != DMA_FROM_DEVICE)
return;
dma_mark_clean(phys_to_virt(paddr), size);
}
void swiotlb_unmap_page(struct device *hwdev, dma_addr_t dev_addr,
size_t size, enum dma_data_direction dir,
struct dma_attrs *attrs)
{
unmap_single(hwdev, dev_addr, size, dir);
}
static void
swiotlb_sync_single(struct device *hwdev, dma_addr_t dev_addr,
size_t size, enum dma_data_direction dir,
enum dma_sync_target target)
{
phys_addr_t paddr = dma_to_phys(hwdev, dev_addr);
BUG_ON(dir == DMA_NONE);
if (is_swiotlb_buffer(paddr)) {
swiotlb_tbl_sync_single(hwdev, phys_to_virt(paddr), size, dir,
target);
return;
}
if (dir != DMA_FROM_DEVICE)
return;
dma_mark_clean(phys_to_virt(paddr), size);
}
void
swiotlb_sync_single_for_cpu(struct device *hwdev, dma_addr_t dev_addr,
size_t size, enum dma_data_direction dir)
{
swiotlb_sync_single(hwdev, dev_addr, size, dir, SYNC_FOR_CPU);
}
void
swiotlb_sync_single_for_device(struct device *hwdev, dma_addr_t dev_addr,
size_t size, enum dma_data_direction dir)
{
swiotlb_sync_single(hwdev, dev_addr, size, dir, SYNC_FOR_DEVICE);
}
int
swiotlb_map_sg_attrs(struct device *hwdev, struct scatterlist *sgl, int nelems,
enum dma_data_direction dir, struct dma_attrs *attrs)
{
struct scatterlist *sg;
int i;
BUG_ON(dir == DMA_NONE);
for_each_sg(sgl, sg, nelems, i) {
phys_addr_t paddr = sg_phys(sg);
dma_addr_t dev_addr = phys_to_dma(hwdev, paddr);
if (swiotlb_force ||
!dma_capable(hwdev, dev_addr, sg->length)) {
void *map = map_single(hwdev, sg_phys(sg),
sg->length, dir);
if (!map) {
swiotlb_full(hwdev, sg->length, dir, 0);
swiotlb_unmap_sg_attrs(hwdev, sgl, i, dir,
attrs);
sgl[0].dma_length = 0;
return 0;
}
sg->dma_address = swiotlb_virt_to_bus(hwdev, map);
} else
sg->dma_address = dev_addr;
sg->dma_length = sg->length;
}
return nelems;
}
int
swiotlb_map_sg(struct device *hwdev, struct scatterlist *sgl, int nelems,
enum dma_data_direction dir)
{
return swiotlb_map_sg_attrs(hwdev, sgl, nelems, dir, NULL);
}
void
swiotlb_unmap_sg_attrs(struct device *hwdev, struct scatterlist *sgl,
int nelems, enum dma_data_direction dir, struct dma_attrs *attrs)
{
struct scatterlist *sg;
int i;
BUG_ON(dir == DMA_NONE);
for_each_sg(sgl, sg, nelems, i)
unmap_single(hwdev, sg->dma_address, sg->dma_length, dir);
}
void
swiotlb_unmap_sg(struct device *hwdev, struct scatterlist *sgl, int nelems,
enum dma_data_direction dir)
{
return swiotlb_unmap_sg_attrs(hwdev, sgl, nelems, dir, NULL);
}
static void
swiotlb_sync_sg(struct device *hwdev, struct scatterlist *sgl,
int nelems, enum dma_data_direction dir,
enum dma_sync_target target)
{
struct scatterlist *sg;
int i;
for_each_sg(sgl, sg, nelems, i)
swiotlb_sync_single(hwdev, sg->dma_address,
sg->dma_length, dir, target);
}
void
swiotlb_sync_sg_for_cpu(struct device *hwdev, struct scatterlist *sg,
int nelems, enum dma_data_direction dir)
{
swiotlb_sync_sg(hwdev, sg, nelems, dir, SYNC_FOR_CPU);
}
void
swiotlb_sync_sg_for_device(struct device *hwdev, struct scatterlist *sg,
int nelems, enum dma_data_direction dir)
{
swiotlb_sync_sg(hwdev, sg, nelems, dir, SYNC_FOR_DEVICE);
}
int
swiotlb_dma_mapping_error(struct device *hwdev, dma_addr_t dma_addr)
{
return (dma_addr == swiotlb_virt_to_bus(hwdev, io_tlb_overflow_buffer));
}
int
swiotlb_dma_supported(struct device *hwdev, u64 mask)
{
return swiotlb_virt_to_bus(hwdev, io_tlb_end - 1) <= mask;
}
