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
return 0;
}
unsigned long swiotlb_nr_tbl(void)
{
return io_tlb_nslabs;
}
unsigned long swiotlb_size_or_default(void)
{
unsigned long size;
size = io_tlb_nslabs << IO_TLB_SHIFT;
return size ? size : (IO_TLB_DEFAULT_SIZE);
}
static dma_addr_t swiotlb_virt_to_bus(struct device *hwdev,
volatile void *address)
{
return phys_to_dma(hwdev, virt_to_phys(address));
}
void swiotlb_print_info(void)
{
unsigned long bytes = io_tlb_nslabs << IO_TLB_SHIFT;
unsigned char *vstart, *vend;
if (no_iotlb_memory) {
pr_warn("software IO TLB: No low mem\n");
return;
}
vstart = phys_to_virt(io_tlb_start);
vend = phys_to_virt(io_tlb_end);
printk(KERN_INFO "software IO TLB [mem %#010llx-%#010llx] (%luMB) mapped at [%p-%p]\n",
(unsigned long long)io_tlb_start,
(unsigned long long)io_tlb_end,
bytes >> 20, vstart, vend - 1);
}
int __init swiotlb_init_with_tbl(char *tlb, unsigned long nslabs, int verbose)
{
void *v_overflow_buffer;
unsigned long i, bytes;
bytes = nslabs << IO_TLB_SHIFT;
io_tlb_nslabs = nslabs;
io_tlb_start = __pa(tlb);
io_tlb_end = io_tlb_start + bytes;
v_overflow_buffer = memblock_virt_alloc_low_nopanic(
PAGE_ALIGN(io_tlb_overflow),
PAGE_SIZE);
if (!v_overflow_buffer)
return -ENOMEM;
io_tlb_overflow_buffer = __pa(v_overflow_buffer);
io_tlb_list = memblock_virt_alloc(
PAGE_ALIGN(io_tlb_nslabs * sizeof(int)),
PAGE_SIZE);
io_tlb_orig_addr = memblock_virt_alloc(
PAGE_ALIGN(io_tlb_nslabs * sizeof(phys_addr_t)),
PAGE_SIZE);
for (i = 0; i < io_tlb_nslabs; i++) {
io_tlb_list[i] = IO_TLB_SEGSIZE - OFFSET(i, IO_TLB_SEGSIZE);
io_tlb_orig_addr[i] = INVALID_PHYS_ADDR;
}
io_tlb_index = 0;
if (verbose)
swiotlb_print_info();
return 0;
}
void __init
swiotlb_init(int verbose)
{
size_t default_size = IO_TLB_DEFAULT_SIZE;
unsigned char *vstart;
unsigned long bytes;
if (!io_tlb_nslabs) {
io_tlb_nslabs = (default_size >> IO_TLB_SHIFT);
io_tlb_nslabs = ALIGN(io_tlb_nslabs, IO_TLB_SEGSIZE);
}
bytes = io_tlb_nslabs << IO_TLB_SHIFT;
vstart = memblock_virt_alloc_low_nopanic(PAGE_ALIGN(bytes), PAGE_SIZE);
if (vstart && !swiotlb_init_with_tbl(vstart, io_tlb_nslabs, verbose))
return;
if (io_tlb_start)
memblock_free_early(io_tlb_start,
PAGE_ALIGN(io_tlb_nslabs << IO_TLB_SHIFT));
pr_warn("Cannot allocate SWIOTLB buffer");
no_iotlb_memory = true;
}
int
swiotlb_late_init_with_default_size(size_t default_size)
{
unsigned long bytes, req_nslabs = io_tlb_nslabs;
unsigned char *vstart = NULL;
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
vstart = (void *)__get_free_pages(GFP_DMA | __GFP_NOWARN,
order);
if (vstart)
break;
order--;
}
if (!vstart) {
io_tlb_nslabs = req_nslabs;
return -ENOMEM;
}
if (order != get_order(bytes)) {
printk(KERN_WARNING "Warning: only able to allocate %ld MB "
"for software IO TLB\n", (PAGE_SIZE << order) >> 20);
io_tlb_nslabs = SLABS_PER_PAGE << order;
}
rc = swiotlb_late_init_with_tbl(vstart, io_tlb_nslabs);
if (rc)
free_pages((unsigned long)vstart, order);
return rc;
}
int
swiotlb_late_init_with_tbl(char *tlb, unsigned long nslabs)
{
unsigned long i, bytes;
unsigned char *v_overflow_buffer;
bytes = nslabs << IO_TLB_SHIFT;
io_tlb_nslabs = nslabs;
io_tlb_start = virt_to_phys(tlb);
io_tlb_end = io_tlb_start + bytes;
memset(tlb, 0, bytes);
v_overflow_buffer = (void *)__get_free_pages(GFP_DMA,
get_order(io_tlb_overflow));
if (!v_overflow_buffer)
goto cleanup2;
io_tlb_overflow_buffer = virt_to_phys(v_overflow_buffer);
io_tlb_list = (unsigned int *)__get_free_pages(GFP_KERNEL,
get_order(io_tlb_nslabs * sizeof(int)));
if (!io_tlb_list)
goto cleanup3;
io_tlb_orig_addr = (phys_addr_t *)
__get_free_pages(GFP_KERNEL,
get_order(io_tlb_nslabs *
sizeof(phys_addr_t)));
if (!io_tlb_orig_addr)
goto cleanup4;
for (i = 0; i < io_tlb_nslabs; i++) {
io_tlb_list[i] = IO_TLB_SEGSIZE - OFFSET(i, IO_TLB_SEGSIZE);
io_tlb_orig_addr[i] = INVALID_PHYS_ADDR;
}
io_tlb_index = 0;
swiotlb_print_info();
late_alloc = 1;
return 0;
cleanup4:
free_pages((unsigned long)io_tlb_list, get_order(io_tlb_nslabs *
sizeof(int)));
io_tlb_list = NULL;
cleanup3:
free_pages((unsigned long)v_overflow_buffer,
get_order(io_tlb_overflow));
io_tlb_overflow_buffer = 0;
cleanup2:
io_tlb_end = 0;
io_tlb_start = 0;
io_tlb_nslabs = 0;
return -ENOMEM;
}
void __init swiotlb_free(void)
{
if (!io_tlb_orig_addr)
return;
if (late_alloc) {
free_pages((unsigned long)phys_to_virt(io_tlb_overflow_buffer),
get_order(io_tlb_overflow));
free_pages((unsigned long)io_tlb_orig_addr,
get_order(io_tlb_nslabs * sizeof(phys_addr_t)));
free_pages((unsigned long)io_tlb_list, get_order(io_tlb_nslabs *
sizeof(int)));
free_pages((unsigned long)phys_to_virt(io_tlb_start),
get_order(io_tlb_nslabs << IO_TLB_SHIFT));
} else {
memblock_free_late(io_tlb_overflow_buffer,
PAGE_ALIGN(io_tlb_overflow));
memblock_free_late(__pa(io_tlb_orig_addr),
PAGE_ALIGN(io_tlb_nslabs * sizeof(phys_addr_t)));
memblock_free_late(__pa(io_tlb_list),
PAGE_ALIGN(io_tlb_nslabs * sizeof(int)));
memblock_free_late(io_tlb_start,
PAGE_ALIGN(io_tlb_nslabs << IO_TLB_SHIFT));
}
io_tlb_nslabs = 0;
}
int is_swiotlb_buffer(phys_addr_t paddr)
{
return paddr >= io_tlb_start && paddr < io_tlb_end;
}
static void swiotlb_bounce(phys_addr_t orig_addr, phys_addr_t tlb_addr,
size_t size, enum dma_data_direction dir)
{
unsigned long pfn = PFN_DOWN(orig_addr);
unsigned char *vaddr = phys_to_virt(tlb_addr);
if (PageHighMem(pfn_to_page(pfn))) {
unsigned int offset = orig_addr & ~PAGE_MASK;
char *buffer;
unsigned int sz = 0;
unsigned long flags;
while (size) {
sz = min_t(size_t, PAGE_SIZE - offset, size);
local_irq_save(flags);
buffer = kmap_atomic(pfn_to_page(pfn));
if (dir == DMA_TO_DEVICE)
memcpy(vaddr, buffer + offset, sz);
else
memcpy(buffer + offset, vaddr, sz);
kunmap_atomic(buffer);
local_irq_restore(flags);
size -= sz;
pfn++;
vaddr += sz;
offset = 0;
}
} else if (dir == DMA_TO_DEVICE) {
memcpy(vaddr, phys_to_virt(orig_addr), size);
} else {
memcpy(phys_to_virt(orig_addr), vaddr, size);
}
}
phys_addr_t swiotlb_tbl_map_single(struct device *hwdev,
dma_addr_t tbl_dma_addr,
phys_addr_t orig_addr, size_t size,
enum dma_data_direction dir)
{
unsigned long flags;
phys_addr_t tlb_addr;
unsigned int nslots, stride, index, wrap;
int i;
unsigned long mask;
unsigned long offset_slots;
unsigned long max_slots;
if (no_iotlb_memory)
panic("Can not allocate SWIOTLB buffer earlier and can't now provide you with the DMA bounce buffer");
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
tlb_addr = io_tlb_start + (index << IO_TLB_SHIFT);
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
if (printk_ratelimit())
dev_warn(hwdev, "swiotlb buffer is full (sz: %zd bytes)\n", size);
return SWIOTLB_MAP_ERROR;
found:
spin_unlock_irqrestore(&io_tlb_lock, flags);
for (i = 0; i < nslots; i++)
io_tlb_orig_addr[index+i] = orig_addr + (i << IO_TLB_SHIFT);
if (dir == DMA_TO_DEVICE || dir == DMA_BIDIRECTIONAL)
swiotlb_bounce(orig_addr, tlb_addr, size, DMA_TO_DEVICE);
return tlb_addr;
}
static phys_addr_t
map_single(struct device *hwdev, phys_addr_t phys, size_t size,
enum dma_data_direction dir)
{
dma_addr_t start_dma_addr = phys_to_dma(hwdev, io_tlb_start);
return swiotlb_tbl_map_single(hwdev, start_dma_addr, phys, size, dir);
}
void swiotlb_tbl_unmap_single(struct device *hwdev, phys_addr_t tlb_addr,
size_t size, enum dma_data_direction dir)
{
unsigned long flags;
int i, count, nslots = ALIGN(size, 1 << IO_TLB_SHIFT) >> IO_TLB_SHIFT;
int index = (tlb_addr - io_tlb_start) >> IO_TLB_SHIFT;
phys_addr_t orig_addr = io_tlb_orig_addr[index];
if (orig_addr != INVALID_PHYS_ADDR &&
((dir == DMA_FROM_DEVICE) || (dir == DMA_BIDIRECTIONAL)))
swiotlb_bounce(orig_addr, tlb_addr, size, DMA_FROM_DEVICE);
spin_lock_irqsave(&io_tlb_lock, flags);
{
count = ((index + nslots) < ALIGN(index + 1, IO_TLB_SEGSIZE) ?
io_tlb_list[index + nslots] : 0);
for (i = index + nslots - 1; i >= index; i--) {
io_tlb_list[i] = ++count;
io_tlb_orig_addr[i] = INVALID_PHYS_ADDR;
}
for (i = index - 1; (OFFSET(i, IO_TLB_SEGSIZE) != IO_TLB_SEGSIZE -1) && io_tlb_list[i]; i--)
io_tlb_list[i] = ++count;
}
spin_unlock_irqrestore(&io_tlb_lock, flags);
}
void swiotlb_tbl_sync_single(struct device *hwdev, phys_addr_t tlb_addr,
size_t size, enum dma_data_direction dir,
enum dma_sync_target target)
{
int index = (tlb_addr - io_tlb_start) >> IO_TLB_SHIFT;
phys_addr_t orig_addr = io_tlb_orig_addr[index];
if (orig_addr == INVALID_PHYS_ADDR)
return;
orig_addr += (unsigned long)tlb_addr & ((1 << IO_TLB_SHIFT) - 1);
switch (target) {
case SYNC_FOR_CPU:
if (likely(dir == DMA_FROM_DEVICE || dir == DMA_BIDIRECTIONAL))
swiotlb_bounce(orig_addr, tlb_addr,
size, DMA_FROM_DEVICE);
else
BUG_ON(dir != DMA_TO_DEVICE);
break;
case SYNC_FOR_DEVICE:
if (likely(dir == DMA_TO_DEVICE || dir == DMA_BIDIRECTIONAL))
swiotlb_bounce(orig_addr, tlb_addr,
size, DMA_TO_DEVICE);
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
if (ret) {
dev_addr = swiotlb_virt_to_bus(hwdev, ret);
if (dev_addr + size - 1 > dma_mask) {
free_pages((unsigned long) ret, order);
ret = NULL;
}
}
if (!ret) {
phys_addr_t paddr = map_single(hwdev, 0, size, DMA_FROM_DEVICE);
if (paddr == SWIOTLB_MAP_ERROR)
goto err_warn;
ret = phys_to_virt(paddr);
dev_addr = phys_to_dma(hwdev, paddr);
if (dev_addr + size - 1 > dma_mask) {
printk("hwdev DMA mask = 0x%016Lx, dev_addr = 0x%016Lx\n",
(unsigned long long)dma_mask,
(unsigned long long)dev_addr);
swiotlb_tbl_unmap_single(hwdev, paddr,
size, DMA_TO_DEVICE);
goto err_warn;
}
}
*dma_handle = dev_addr;
memset(ret, 0, size);
return ret;
err_warn:
pr_warn("swiotlb: coherent allocation failed for device %s size=%zu\n",
dev_name(hwdev), size);
dump_stack();
return NULL;
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
swiotlb_tbl_unmap_single(hwdev, paddr, size, DMA_TO_DEVICE);
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
phys_addr_t map, phys = page_to_phys(page) + offset;
dma_addr_t dev_addr = phys_to_dma(dev, phys);
BUG_ON(dir == DMA_NONE);
if (dma_capable(dev, dev_addr, size) && !swiotlb_force)
return dev_addr;
trace_swiotlb_bounced(dev, dev_addr, size, swiotlb_force);
map = map_single(dev, phys, size, dir);
if (map == SWIOTLB_MAP_ERROR) {
swiotlb_full(dev, size, dir, 1);
return phys_to_dma(dev, io_tlb_overflow_buffer);
}
dev_addr = phys_to_dma(dev, map);
if (!dma_capable(dev, dev_addr, size)) {
swiotlb_tbl_unmap_single(dev, map, size, dir);
return phys_to_dma(dev, io_tlb_overflow_buffer);
}
return dev_addr;
}
static void unmap_single(struct device *hwdev, dma_addr_t dev_addr,
size_t size, enum dma_data_direction dir)
{
phys_addr_t paddr = dma_to_phys(hwdev, dev_addr);
BUG_ON(dir == DMA_NONE);
if (is_swiotlb_buffer(paddr)) {
swiotlb_tbl_unmap_single(hwdev, paddr, size, dir);
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
swiotlb_tbl_sync_single(hwdev, paddr, size, dir, target);
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
phys_addr_t map = map_single(hwdev, sg_phys(sg),
sg->length, dir);
if (map == SWIOTLB_MAP_ERROR) {
swiotlb_full(hwdev, sg->length, dir, 0);
swiotlb_unmap_sg_attrs(hwdev, sgl, i, dir,
attrs);
sg_dma_len(sgl) = 0;
return 0;
}
sg->dma_address = phys_to_dma(hwdev, map);
} else
sg->dma_address = dev_addr;
sg_dma_len(sg) = sg->length;
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
unmap_single(hwdev, sg->dma_address, sg_dma_len(sg), dir);
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
sg_dma_len(sg), dir, target);
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
return (dma_addr == phys_to_dma(hwdev, io_tlb_overflow_buffer));
}
int
swiotlb_dma_supported(struct device *hwdev, u64 mask)
{
return phys_to_dma(hwdev, io_tlb_end - 1) <= mask;
}
