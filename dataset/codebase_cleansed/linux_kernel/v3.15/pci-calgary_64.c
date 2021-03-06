static inline int translation_enabled(struct iommu_table *tbl)
{
return (tbl != NULL);
}
static void iommu_range_reserve(struct iommu_table *tbl,
unsigned long start_addr, unsigned int npages)
{
unsigned long index;
unsigned long end;
unsigned long flags;
index = start_addr >> PAGE_SHIFT;
if (index >= tbl->it_size)
return;
end = index + npages;
if (end > tbl->it_size)
end = tbl->it_size;
spin_lock_irqsave(&tbl->it_lock, flags);
bitmap_set(tbl->it_map, index, npages);
spin_unlock_irqrestore(&tbl->it_lock, flags);
}
static unsigned long iommu_range_alloc(struct device *dev,
struct iommu_table *tbl,
unsigned int npages)
{
unsigned long flags;
unsigned long offset;
unsigned long boundary_size;
boundary_size = ALIGN(dma_get_seg_boundary(dev) + 1,
PAGE_SIZE) >> PAGE_SHIFT;
BUG_ON(npages == 0);
spin_lock_irqsave(&tbl->it_lock, flags);
offset = iommu_area_alloc(tbl->it_map, tbl->it_size, tbl->it_hint,
npages, 0, boundary_size, 0);
if (offset == ~0UL) {
tbl->chip_ops->tce_cache_blast(tbl);
offset = iommu_area_alloc(tbl->it_map, tbl->it_size, 0,
npages, 0, boundary_size, 0);
if (offset == ~0UL) {
pr_warn("IOMMU full\n");
spin_unlock_irqrestore(&tbl->it_lock, flags);
if (panic_on_overflow)
panic("Calgary: fix the allocator.\n");
else
return DMA_ERROR_CODE;
}
}
tbl->it_hint = offset + npages;
BUG_ON(tbl->it_hint > tbl->it_size);
spin_unlock_irqrestore(&tbl->it_lock, flags);
return offset;
}
static dma_addr_t iommu_alloc(struct device *dev, struct iommu_table *tbl,
void *vaddr, unsigned int npages, int direction)
{
unsigned long entry;
dma_addr_t ret;
entry = iommu_range_alloc(dev, tbl, npages);
if (unlikely(entry == DMA_ERROR_CODE)) {
pr_warn("failed to allocate %u pages in iommu %p\n",
npages, tbl);
return DMA_ERROR_CODE;
}
ret = (entry << PAGE_SHIFT) | ((unsigned long)vaddr & ~PAGE_MASK);
tce_build(tbl, entry, npages, (unsigned long)vaddr & PAGE_MASK,
direction);
return ret;
}
static void iommu_free(struct iommu_table *tbl, dma_addr_t dma_addr,
unsigned int npages)
{
unsigned long entry;
unsigned long badend;
unsigned long flags;
badend = DMA_ERROR_CODE + (EMERGENCY_PAGES * PAGE_SIZE);
if (unlikely((dma_addr >= DMA_ERROR_CODE) && (dma_addr < badend))) {
WARN(1, KERN_ERR "Calgary: driver tried unmapping bad DMA "
"address 0x%Lx\n", dma_addr);
return;
}
entry = dma_addr >> PAGE_SHIFT;
BUG_ON(entry + npages > tbl->it_size);
tce_free(tbl, entry, npages);
spin_lock_irqsave(&tbl->it_lock, flags);
bitmap_clear(tbl->it_map, entry, npages);
spin_unlock_irqrestore(&tbl->it_lock, flags);
}
static inline struct iommu_table *find_iommu_table(struct device *dev)
{
struct pci_dev *pdev;
struct pci_bus *pbus;
struct iommu_table *tbl;
pdev = to_pci_dev(dev);
pbus = pdev->bus;
do {
tbl = pci_iommu(pbus);
if (tbl && tbl->it_busno == pbus->number)
break;
tbl = NULL;
pbus = pbus->parent;
} while (pbus);
BUG_ON(tbl && (tbl->it_busno != pbus->number));
return tbl;
}
static void calgary_unmap_sg(struct device *dev, struct scatterlist *sglist,
int nelems,enum dma_data_direction dir,
struct dma_attrs *attrs)
{
struct iommu_table *tbl = find_iommu_table(dev);
struct scatterlist *s;
int i;
if (!translation_enabled(tbl))
return;
for_each_sg(sglist, s, nelems, i) {
unsigned int npages;
dma_addr_t dma = s->dma_address;
unsigned int dmalen = s->dma_length;
if (dmalen == 0)
break;
npages = iommu_num_pages(dma, dmalen, PAGE_SIZE);
iommu_free(tbl, dma, npages);
}
}
static int calgary_map_sg(struct device *dev, struct scatterlist *sg,
int nelems, enum dma_data_direction dir,
struct dma_attrs *attrs)
{
struct iommu_table *tbl = find_iommu_table(dev);
struct scatterlist *s;
unsigned long vaddr;
unsigned int npages;
unsigned long entry;
int i;
for_each_sg(sg, s, nelems, i) {
BUG_ON(!sg_page(s));
vaddr = (unsigned long) sg_virt(s);
npages = iommu_num_pages(vaddr, s->length, PAGE_SIZE);
entry = iommu_range_alloc(dev, tbl, npages);
if (entry == DMA_ERROR_CODE) {
s->dma_length = 0;
goto error;
}
s->dma_address = (entry << PAGE_SHIFT) | s->offset;
tce_build(tbl, entry, npages, vaddr & PAGE_MASK, dir);
s->dma_length = s->length;
}
return nelems;
error:
calgary_unmap_sg(dev, sg, nelems, dir, NULL);
for_each_sg(sg, s, nelems, i) {
sg->dma_address = DMA_ERROR_CODE;
sg->dma_length = 0;
}
return 0;
}
static dma_addr_t calgary_map_page(struct device *dev, struct page *page,
unsigned long offset, size_t size,
enum dma_data_direction dir,
struct dma_attrs *attrs)
{
void *vaddr = page_address(page) + offset;
unsigned long uaddr;
unsigned int npages;
struct iommu_table *tbl = find_iommu_table(dev);
uaddr = (unsigned long)vaddr;
npages = iommu_num_pages(uaddr, size, PAGE_SIZE);
return iommu_alloc(dev, tbl, vaddr, npages, dir);
}
static void calgary_unmap_page(struct device *dev, dma_addr_t dma_addr,
size_t size, enum dma_data_direction dir,
struct dma_attrs *attrs)
{
struct iommu_table *tbl = find_iommu_table(dev);
unsigned int npages;
npages = iommu_num_pages(dma_addr, size, PAGE_SIZE);
iommu_free(tbl, dma_addr, npages);
}
static void* calgary_alloc_coherent(struct device *dev, size_t size,
dma_addr_t *dma_handle, gfp_t flag, struct dma_attrs *attrs)
{
void *ret = NULL;
dma_addr_t mapping;
unsigned int npages, order;
struct iommu_table *tbl = find_iommu_table(dev);
size = PAGE_ALIGN(size);
npages = size >> PAGE_SHIFT;
order = get_order(size);
flag &= ~(__GFP_DMA | __GFP_HIGHMEM | __GFP_DMA32);
ret = (void *)__get_free_pages(flag, order);
if (!ret)
goto error;
memset(ret, 0, size);
mapping = iommu_alloc(dev, tbl, ret, npages, DMA_BIDIRECTIONAL);
if (mapping == DMA_ERROR_CODE)
goto free;
*dma_handle = mapping;
return ret;
free:
free_pages((unsigned long)ret, get_order(size));
ret = NULL;
error:
return ret;
}
static void calgary_free_coherent(struct device *dev, size_t size,
void *vaddr, dma_addr_t dma_handle,
struct dma_attrs *attrs)
{
unsigned int npages;
struct iommu_table *tbl = find_iommu_table(dev);
size = PAGE_ALIGN(size);
npages = size >> PAGE_SHIFT;
iommu_free(tbl, dma_handle, npages);
free_pages((unsigned long)vaddr, get_order(size));
}
static inline void __iomem * busno_to_bbar(unsigned char num)
{
return bus_info[num].bbar;
}
static inline int busno_to_phbid(unsigned char num)
{
return bus_info[num].phbid;
}
static inline unsigned long split_queue_offset(unsigned char num)
{
size_t idx = busno_to_phbid(num);
return split_queue_offsets[idx];
}
static inline unsigned long tar_offset(unsigned char num)
{
size_t idx = busno_to_phbid(num);
return tar_offsets[idx];
}
static inline unsigned long phb_offset(unsigned char num)
{
size_t idx = busno_to_phbid(num);
return phb_offsets[idx];
}
static inline void __iomem* calgary_reg(void __iomem *bar, unsigned long offset)
{
unsigned long target = ((unsigned long)bar) | offset;
return (void __iomem*)target;
}
static inline int is_calioc2(unsigned short device)
{
return (device == PCI_DEVICE_ID_IBM_CALIOC2);
}
static inline int is_calgary(unsigned short device)
{
return (device == PCI_DEVICE_ID_IBM_CALGARY);
}
static inline int is_cal_pci_dev(unsigned short device)
{
return (is_calgary(device) || is_calioc2(device));
}
static void calgary_tce_cache_blast(struct iommu_table *tbl)
{
u64 val;
u32 aer;
int i = 0;
void __iomem *bbar = tbl->bbar;
void __iomem *target;
target = calgary_reg(bbar, phb_offset(tbl->it_busno) | PHB_AER_OFFSET);
aer = readl(target);
writel(0, target);
target = calgary_reg(bbar, phb_offset(tbl->it_busno) | PHB_PLSSR_OFFSET);
val = readl(target);
target = calgary_reg(bbar, split_queue_offset(tbl->it_busno));
do {
val = readq(target);
i++;
} while ((val & 0xff) != 0xff && i < 100);
if (i == 100)
pr_warn("PCI bus not quiesced, continuing anyway\n");
target = calgary_reg(bbar, tar_offset(tbl->it_busno));
writeq(tbl->tar_val, target);
target = calgary_reg(bbar, phb_offset(tbl->it_busno) | PHB_AER_OFFSET);
writel(aer, target);
(void)readl(target);
}
static void calioc2_tce_cache_blast(struct iommu_table *tbl)
{
void __iomem *bbar = tbl->bbar;
void __iomem *target;
u64 val64;
u32 val;
int i = 0;
int count = 1;
unsigned char bus = tbl->it_busno;
begin:
printk(KERN_DEBUG "Calgary: CalIOC2 bus 0x%x entering tce cache blast "
"sequence - count %d\n", bus, count);
target = calgary_reg(bbar, phb_offset(bus) | PHB_PAGE_MIG_CTRL);
val = be32_to_cpu(readl(target));
printk(KERN_DEBUG "1a. read 0x%x [LE] from %p\n", val, target);
val |= PMR_SOFTSTOP;
printk(KERN_DEBUG "1b. writing 0x%x [LE] to %p\n", val, target);
writel(cpu_to_be32(val), target);
printk(KERN_DEBUG "2a. starting to poll split queues\n");
target = calgary_reg(bbar, split_queue_offset(bus));
do {
val64 = readq(target);
i++;
} while ((val64 & 0xff) != 0xff && i < 100);
if (i == 100)
pr_warn("CalIOC2: PCI bus not quiesced, continuing anyway\n");
target = calgary_reg(bbar, phb_offset(bus) | PHB_PAGE_MIG_DEBUG);
val = be32_to_cpu(readl(target));
printk(KERN_DEBUG "3. read 0x%x [LE] from %p\n", val, target);
if (val & PMR_SOFTSTOPFAULT) {
if (++count < 100)
goto begin;
else {
pr_warn("CalIOC2: too many SoftStopFaults, aborting TCE cache flush sequence!\n");
return;
}
}
target = calgary_reg(bbar, phb_offset(bus) | PHB_PAGE_MIG_CTRL);
printk(KERN_DEBUG "5a. slamming into HardStop by reading %p\n", target);
val = be32_to_cpu(readl(target));
printk(KERN_DEBUG "5b. read 0x%x [LE] from %p\n", val, target);
target = calgary_reg(bbar, phb_offset(bus) | PHB_PAGE_MIG_DEBUG);
val = be32_to_cpu(readl(target));
printk(KERN_DEBUG "5c. read 0x%x [LE] from %p (debug)\n", val, target);
printk(KERN_DEBUG "6. invalidating TCE cache\n");
target = calgary_reg(bbar, tar_offset(bus));
writeq(tbl->tar_val, target);
printk(KERN_DEBUG "7a. Re-reading PMCR\n");
target = calgary_reg(bbar, phb_offset(bus) | PHB_PAGE_MIG_CTRL);
val = be32_to_cpu(readl(target));
printk(KERN_DEBUG "7b. read 0x%x [LE] from %p\n", val, target);
printk(KERN_DEBUG "8a. removing HardStop from PMCR\n");
target = calgary_reg(bbar, phb_offset(bus) | PHB_PAGE_MIG_CTRL);
val = 0;
printk(KERN_DEBUG "8b. writing 0x%x [LE] to %p\n", val, target);
writel(cpu_to_be32(val), target);
val = be32_to_cpu(readl(target));
printk(KERN_DEBUG "8c. read 0x%x [LE] from %p\n", val, target);
}
static void __init calgary_reserve_mem_region(struct pci_dev *dev, u64 start,
u64 limit)
{
unsigned int numpages;
limit = limit | 0xfffff;
limit++;
numpages = ((limit - start) >> PAGE_SHIFT);
iommu_range_reserve(pci_iommu(dev->bus), start, numpages);
}
static void __init calgary_reserve_peripheral_mem_1(struct pci_dev *dev)
{
void __iomem *target;
u64 low, high, sizelow;
u64 start, limit;
struct iommu_table *tbl = pci_iommu(dev->bus);
unsigned char busnum = dev->bus->number;
void __iomem *bbar = tbl->bbar;
target = calgary_reg(bbar, phb_offset(busnum) | PHB_MEM_1_LOW);
low = be32_to_cpu(readl(target));
target = calgary_reg(bbar, phb_offset(busnum) | PHB_MEM_1_HIGH);
high = be32_to_cpu(readl(target));
target = calgary_reg(bbar, phb_offset(busnum) | PHB_MEM_1_SIZE);
sizelow = be32_to_cpu(readl(target));
start = (high << 32) | low;
limit = sizelow;
calgary_reserve_mem_region(dev, start, limit);
}
static void __init calgary_reserve_peripheral_mem_2(struct pci_dev *dev)
{
void __iomem *target;
u32 val32;
u64 low, high, sizelow, sizehigh;
u64 start, limit;
struct iommu_table *tbl = pci_iommu(dev->bus);
unsigned char busnum = dev->bus->number;
void __iomem *bbar = tbl->bbar;
target = calgary_reg(bbar, phb_offset(busnum) | PHB_CONFIG_RW_OFFSET);
val32 = be32_to_cpu(readl(target));
if (!(val32 & PHB_MEM2_ENABLE))
return;
target = calgary_reg(bbar, phb_offset(busnum) | PHB_MEM_2_LOW);
low = be32_to_cpu(readl(target));
target = calgary_reg(bbar, phb_offset(busnum) | PHB_MEM_2_HIGH);
high = be32_to_cpu(readl(target));
target = calgary_reg(bbar, phb_offset(busnum) | PHB_MEM_2_SIZE_LOW);
sizelow = be32_to_cpu(readl(target));
target = calgary_reg(bbar, phb_offset(busnum) | PHB_MEM_2_SIZE_HIGH);
sizehigh = be32_to_cpu(readl(target));
start = (high << 32) | low;
limit = (sizehigh << 32) | sizelow;
calgary_reserve_mem_region(dev, start, limit);
}
static void __init calgary_reserve_regions(struct pci_dev *dev)
{
unsigned int npages;
u64 start;
struct iommu_table *tbl = pci_iommu(dev->bus);
iommu_range_reserve(tbl, DMA_ERROR_CODE, EMERGENCY_PAGES);
if (is_calgary(dev->device)) {
start = (640 * 1024);
npages = ((1024 - 640) * 1024) >> PAGE_SHIFT;
} else {
start = 0;
npages = (1 * 1024 * 1024) >> PAGE_SHIFT;
}
iommu_range_reserve(tbl, start, npages);
calgary_reserve_peripheral_mem_1(dev);
calgary_reserve_peripheral_mem_2(dev);
}
static int __init calgary_setup_tar(struct pci_dev *dev, void __iomem *bbar)
{
u64 val64;
u64 table_phys;
void __iomem *target;
int ret;
struct iommu_table *tbl;
ret = build_tce_table(dev, bbar);
if (ret)
return ret;
tbl = pci_iommu(dev->bus);
tbl->it_base = (unsigned long)bus_info[dev->bus->number].tce_space;
if (is_kdump_kernel())
calgary_init_bitmap_from_tce_table(tbl);
else
tce_free(tbl, 0, tbl->it_size);
if (is_calgary(dev->device))
tbl->chip_ops = &calgary_chip_ops;
else if (is_calioc2(dev->device))
tbl->chip_ops = &calioc2_chip_ops;
else
BUG();
calgary_reserve_regions(dev);
target = calgary_reg(bbar, tar_offset(dev->bus->number));
val64 = be64_to_cpu(readq(target));
val64 &= ~TAR_SW_BITS;
table_phys = (u64)__pa(tbl->it_base);
val64 |= table_phys;
BUG_ON(specified_table_size > TCE_TABLE_SIZE_8M);
val64 |= (u64) specified_table_size;
tbl->tar_val = cpu_to_be64(val64);
writeq(tbl->tar_val, target);
readq(target);
return 0;
}
static void __init calgary_free_bus(struct pci_dev *dev)
{
u64 val64;
struct iommu_table *tbl = pci_iommu(dev->bus);
void __iomem *target;
unsigned int bitmapsz;
target = calgary_reg(tbl->bbar, tar_offset(dev->bus->number));
val64 = be64_to_cpu(readq(target));
val64 &= ~TAR_SW_BITS;
writeq(cpu_to_be64(val64), target);
readq(target);
bitmapsz = tbl->it_size / BITS_PER_BYTE;
free_pages((unsigned long)tbl->it_map, get_order(bitmapsz));
tbl->it_map = NULL;
kfree(tbl);
set_pci_iommu(dev->bus, NULL);
bus_info[dev->bus->number].tce_space = NULL;
}
static void calgary_dump_error_regs(struct iommu_table *tbl)
{
void __iomem *bbar = tbl->bbar;
void __iomem *target;
u32 csr, plssr;
target = calgary_reg(bbar, phb_offset(tbl->it_busno) | PHB_CSR_OFFSET);
csr = be32_to_cpu(readl(target));
target = calgary_reg(bbar, phb_offset(tbl->it_busno) | PHB_PLSSR_OFFSET);
plssr = be32_to_cpu(readl(target));
pr_emerg("DMA error on Calgary PHB 0x%x, 0x%08x@CSR 0x%08x@PLSSR\n",
tbl->it_busno, csr, plssr);
}
static void calioc2_dump_error_regs(struct iommu_table *tbl)
{
void __iomem *bbar = tbl->bbar;
u32 csr, csmr, plssr, mck, rcstat;
void __iomem *target;
unsigned long phboff = phb_offset(tbl->it_busno);
unsigned long erroff;
u32 errregs[7];
int i;
target = calgary_reg(bbar, phboff | PHB_CSR_OFFSET);
csr = be32_to_cpu(readl(target));
target = calgary_reg(bbar, phboff | PHB_PLSSR_OFFSET);
plssr = be32_to_cpu(readl(target));
target = calgary_reg(bbar, phboff | 0x290);
csmr = be32_to_cpu(readl(target));
target = calgary_reg(bbar, phboff | 0x800);
mck = be32_to_cpu(readl(target));
pr_emerg("DMA error on CalIOC2 PHB 0x%x\n", tbl->it_busno);
pr_emerg("0x%08x@CSR 0x%08x@PLSSR 0x%08x@CSMR 0x%08x@MCK\n",
csr, plssr, csmr, mck);
pr_emerg("");
for (i = 0; i < ARRAY_SIZE(errregs); i++) {
erroff = (0x810 + (i * 0x10));
target = calgary_reg(bbar, phboff | erroff);
errregs[i] = be32_to_cpu(readl(target));
pr_cont("0x%08x@0x%lx ", errregs[i], erroff);
}
pr_cont("\n");
target = calgary_reg(bbar, phboff | PHB_ROOT_COMPLEX_STATUS);
rcstat = be32_to_cpu(readl(target));
printk(KERN_EMERG "Calgary: 0x%08x@0x%x\n", rcstat,
PHB_ROOT_COMPLEX_STATUS);
}
static void calgary_watchdog(unsigned long data)
{
struct pci_dev *dev = (struct pci_dev *)data;
struct iommu_table *tbl = pci_iommu(dev->bus);
void __iomem *bbar = tbl->bbar;
u32 val32;
void __iomem *target;
target = calgary_reg(bbar, phb_offset(tbl->it_busno) | PHB_CSR_OFFSET);
val32 = be32_to_cpu(readl(target));
if (val32 & CSR_AGENT_MASK) {
tbl->chip_ops->dump_error_regs(tbl);
writel(0, target);
target = calgary_reg(bbar, phb_offset(tbl->it_busno) |
PHB_CONFIG_RW_OFFSET);
val32 = be32_to_cpu(readl(target));
val32 |= PHB_SLOT_DISABLE;
writel(cpu_to_be32(val32), target);
readl(target);
} else {
mod_timer(&tbl->watchdog_timer, jiffies + 2 * HZ);
}
}
static void __init calgary_set_split_completion_timeout(void __iomem *bbar,
unsigned char busnum, unsigned long timeout)
{
u64 val64;
void __iomem *target;
unsigned int phb_shift = ~0;
u64 mask;
switch (busno_to_phbid(busnum)) {
case 0: phb_shift = (63 - 19);
break;
case 1: phb_shift = (63 - 23);
break;
case 2: phb_shift = (63 - 27);
break;
case 3: phb_shift = (63 - 35);
break;
default:
BUG_ON(busno_to_phbid(busnum));
}
target = calgary_reg(bbar, CALGARY_CONFIG_REG);
val64 = be64_to_cpu(readq(target));
mask = ~(0xFUL << phb_shift);
val64 &= mask;
val64 |= (timeout << phb_shift);
writeq(cpu_to_be64(val64), target);
readq(target);
}
static void __init calioc2_handle_quirks(struct iommu_table *tbl, struct pci_dev *dev)
{
unsigned char busnum = dev->bus->number;
void __iomem *bbar = tbl->bbar;
void __iomem *target;
u32 val;
target = calgary_reg(bbar, phb_offset(busnum) | PHB_SAVIOR_L2);
val = cpu_to_be32(readl(target));
val |= 0x00800000;
writel(cpu_to_be32(val), target);
}
static void __init calgary_handle_quirks(struct iommu_table *tbl, struct pci_dev *dev)
{
unsigned char busnum = dev->bus->number;
if (is_calgary(dev->device) && (busnum == 1))
calgary_set_split_completion_timeout(tbl->bbar, busnum,
CCR_2SEC_TIMEOUT);
}
static void __init calgary_enable_translation(struct pci_dev *dev)
{
u32 val32;
unsigned char busnum;
void __iomem *target;
void __iomem *bbar;
struct iommu_table *tbl;
busnum = dev->bus->number;
tbl = pci_iommu(dev->bus);
bbar = tbl->bbar;
target = calgary_reg(bbar, phb_offset(busnum) | PHB_CONFIG_RW_OFFSET);
val32 = be32_to_cpu(readl(target));
val32 |= PHB_TCE_ENABLE | PHB_DAC_DISABLE | PHB_MCSR_ENABLE;
printk(KERN_INFO "Calgary: enabling translation on %s PHB %#x\n",
(dev->device == PCI_DEVICE_ID_IBM_CALGARY) ?
"Calgary" : "CalIOC2", busnum);
printk(KERN_INFO "Calgary: errant DMAs will now be prevented on this "
"bus.\n");
writel(cpu_to_be32(val32), target);
readl(target);
init_timer(&tbl->watchdog_timer);
tbl->watchdog_timer.function = &calgary_watchdog;
tbl->watchdog_timer.data = (unsigned long)dev;
mod_timer(&tbl->watchdog_timer, jiffies);
}
static void __init calgary_disable_translation(struct pci_dev *dev)
{
u32 val32;
unsigned char busnum;
void __iomem *target;
void __iomem *bbar;
struct iommu_table *tbl;
busnum = dev->bus->number;
tbl = pci_iommu(dev->bus);
bbar = tbl->bbar;
target = calgary_reg(bbar, phb_offset(busnum) | PHB_CONFIG_RW_OFFSET);
val32 = be32_to_cpu(readl(target));
val32 &= ~(PHB_TCE_ENABLE | PHB_DAC_DISABLE | PHB_MCSR_ENABLE);
printk(KERN_INFO "Calgary: disabling translation on PHB %#x!\n", busnum);
writel(cpu_to_be32(val32), target);
readl(target);
del_timer_sync(&tbl->watchdog_timer);
}
static void __init calgary_init_one_nontraslated(struct pci_dev *dev)
{
pci_dev_get(dev);
set_pci_iommu(dev->bus, NULL);
if (dev->bus->parent)
dev->bus->parent->self = dev;
else
dev->bus->self = dev;
}
static int __init calgary_init_one(struct pci_dev *dev)
{
void __iomem *bbar;
struct iommu_table *tbl;
int ret;
bbar = busno_to_bbar(dev->bus->number);
ret = calgary_setup_tar(dev, bbar);
if (ret)
goto done;
pci_dev_get(dev);
if (dev->bus->parent) {
if (dev->bus->parent->self)
printk(KERN_WARNING "Calgary: IEEEE, dev %p has "
"bus->parent->self!\n", dev);
dev->bus->parent->self = dev;
} else
dev->bus->self = dev;
tbl = pci_iommu(dev->bus);
tbl->chip_ops->handle_quirks(tbl, dev);
calgary_enable_translation(dev);
return 0;
done:
return ret;
}
static int __init calgary_locate_bbars(void)
{
int ret;
int rioidx, phb, bus;
void __iomem *bbar;
void __iomem *target;
unsigned long offset;
u8 start_bus, end_bus;
u32 val;
ret = -ENODATA;
for (rioidx = 0; rioidx < rio_table_hdr->num_rio_dev; rioidx++) {
struct rio_detail *rio = rio_devs[rioidx];
if ((rio->type != COMPAT_CALGARY) && (rio->type != ALT_CALGARY))
continue;
bbar = ioremap_nocache(rio->BBAR, 1024 * 1024);
if (!bbar)
goto error;
for (phb = 0; phb < PHBS_PER_CALGARY; phb++) {
offset = phb_debug_offsets[phb] | PHB_DEBUG_STUFF_OFFSET;
target = calgary_reg(bbar, offset);
val = be32_to_cpu(readl(target));
start_bus = (u8)((val & 0x00FF0000) >> 16);
end_bus = (u8)((val & 0x0000FF00) >> 8);
if (end_bus) {
for (bus = start_bus; bus <= end_bus; bus++) {
bus_info[bus].bbar = bbar;
bus_info[bus].phbid = phb;
}
} else {
bus_info[start_bus].bbar = bbar;
bus_info[start_bus].phbid = phb;
}
}
}
return 0;
error:
for (bus = 0; bus < ARRAY_SIZE(bus_info); bus++)
if (bus_info[bus].bbar)
iounmap(bus_info[bus].bbar);
return ret;
}
static int __init calgary_init(void)
{
int ret;
struct pci_dev *dev = NULL;
struct calgary_bus_info *info;
ret = calgary_locate_bbars();
if (ret)
return ret;
if (is_kdump_kernel())
get_tce_space_from_tar();
do {
dev = pci_get_device(PCI_VENDOR_ID_IBM, PCI_ANY_ID, dev);
if (!dev)
break;
if (!is_cal_pci_dev(dev->device))
continue;
info = &bus_info[dev->bus->number];
if (info->translation_disabled) {
calgary_init_one_nontraslated(dev);
continue;
}
if (!info->tce_space && !translate_empty_slots)
continue;
ret = calgary_init_one(dev);
if (ret)
goto error;
} while (1);
dev = NULL;
for_each_pci_dev(dev) {
struct iommu_table *tbl;
tbl = find_iommu_table(&dev->dev);
if (translation_enabled(tbl))
dev->dev.archdata.dma_ops = &calgary_dma_ops;
}
return ret;
error:
do {
dev = pci_get_device(PCI_VENDOR_ID_IBM, PCI_ANY_ID, dev);
if (!dev)
break;
if (!is_cal_pci_dev(dev->device))
continue;
info = &bus_info[dev->bus->number];
if (info->translation_disabled) {
pci_dev_put(dev);
continue;
}
if (!info->tce_space && !translate_empty_slots)
continue;
calgary_disable_translation(dev);
calgary_free_bus(dev);
pci_dev_put(dev);
dev->dev.archdata.dma_ops = NULL;
} while (1);
return ret;
}
static inline int __init determine_tce_table_size(void)
{
int ret;
if (specified_table_size != TCE_TABLE_SIZE_UNSPECIFIED)
return specified_table_size;
if (is_kdump_kernel() && saved_max_pfn) {
ret = get_order((saved_max_pfn * PAGE_SIZE) >> 13);
if (ret > TCE_TABLE_SIZE_8M)
ret = TCE_TABLE_SIZE_8M;
} else {
ret = TCE_TABLE_SIZE_8M;
}
return ret;
}
static int __init build_detail_arrays(void)
{
unsigned long ptr;
unsigned numnodes, i;
int scal_detail_size, rio_detail_size;
numnodes = rio_table_hdr->num_scal_dev;
if (numnodes > MAX_NUMNODES){
printk(KERN_WARNING
"Calgary: MAX_NUMNODES too low! Defined as %d, "
"but system has %d nodes.\n",
MAX_NUMNODES, numnodes);
return -ENODEV;
}
switch (rio_table_hdr->version){
case 2:
scal_detail_size = 11;
rio_detail_size = 13;
break;
case 3:
scal_detail_size = 12;
rio_detail_size = 15;
break;
default:
printk(KERN_WARNING
"Calgary: Invalid Rio Grande Table Version: %d\n",
rio_table_hdr->version);
return -EPROTO;
}
ptr = ((unsigned long)rio_table_hdr) + 3;
for (i = 0; i < numnodes; i++, ptr += scal_detail_size)
scal_devs[i] = (struct scal_detail *)ptr;
for (i = 0; i < rio_table_hdr->num_rio_dev;
i++, ptr += rio_detail_size)
rio_devs[i] = (struct rio_detail *)ptr;
return 0;
}
static int __init calgary_bus_has_devices(int bus, unsigned short pci_dev)
{
int dev;
u32 val;
if (pci_dev == PCI_DEVICE_ID_IBM_CALIOC2) {
return 1;
}
for (dev = 1; dev < 8; dev++) {
val = read_pci_config(bus, dev, 0, 0);
if (val != 0xffffffff)
break;
}
return (val != 0xffffffff);
}
static void calgary_init_bitmap_from_tce_table(struct iommu_table *tbl)
{
u64 *tp;
unsigned int index;
tp = ((u64 *)tbl->it_base);
for (index = 0 ; index < tbl->it_size; index++) {
if (*tp != 0x0)
set_bit(index, tbl->it_map);
tp++;
}
}
static void __init get_tce_space_from_tar(void)
{
int bus;
void __iomem *target;
unsigned long tce_space;
for (bus = 0; bus < MAX_PHB_BUS_NUM; bus++) {
struct calgary_bus_info *info = &bus_info[bus];
unsigned short pci_device;
u32 val;
val = read_pci_config(bus, 0, 0, 0);
pci_device = (val & 0xFFFF0000) >> 16;
if (!is_cal_pci_dev(pci_device))
continue;
if (info->translation_disabled)
continue;
if (calgary_bus_has_devices(bus, pci_device) ||
translate_empty_slots) {
target = calgary_reg(bus_info[bus].bbar,
tar_offset(bus));
tce_space = be64_to_cpu(readq(target));
tce_space = tce_space & TAR_SW_BITS;
tce_space = tce_space & (~specified_table_size);
info->tce_space = (u64 *)__va(tce_space);
}
}
return;
}
static int __init calgary_iommu_init(void)
{
int ret;
printk(KERN_INFO "PCI-DMA: Using Calgary IOMMU\n");
ret = calgary_init();
if (ret) {
printk(KERN_ERR "PCI-DMA: Calgary init failed %d, "
"falling back to no_iommu\n", ret);
return ret;
}
return 0;
}
int __init detect_calgary(void)
{
int bus;
void *tbl;
int calgary_found = 0;
unsigned long ptr;
unsigned int offset, prev_offset;
int ret;
if (no_iommu || iommu_detected)
return -ENODEV;
if (!use_calgary)
return -ENODEV;
if (!early_pci_allowed())
return -ENODEV;
printk(KERN_DEBUG "Calgary: detecting Calgary via BIOS EBDA area\n");
ptr = (unsigned long)phys_to_virt(get_bios_ebda());
rio_table_hdr = NULL;
prev_offset = 0;
offset = 0x180;
while (offset > prev_offset) {
if (*((unsigned short *)(ptr + offset + 2)) == 0x4752){
rio_table_hdr = (struct rio_table_hdr *)(ptr + offset + 4);
break;
}
prev_offset = offset;
offset = *((unsigned short *)(ptr + offset));
}
if (!rio_table_hdr) {
printk(KERN_DEBUG "Calgary: Unable to locate Rio Grande table "
"in EBDA - bailing!\n");
return -ENODEV;
}
ret = build_detail_arrays();
if (ret) {
printk(KERN_DEBUG "Calgary: build_detail_arrays ret %d\n", ret);
return -ENOMEM;
}
specified_table_size = determine_tce_table_size();
for (bus = 0; bus < MAX_PHB_BUS_NUM; bus++) {
struct calgary_bus_info *info = &bus_info[bus];
unsigned short pci_device;
u32 val;
val = read_pci_config(bus, 0, 0, 0);
pci_device = (val & 0xFFFF0000) >> 16;
if (!is_cal_pci_dev(pci_device))
continue;
if (info->translation_disabled)
continue;
if (calgary_bus_has_devices(bus, pci_device) ||
translate_empty_slots) {
if (!is_kdump_kernel()) {
tbl = alloc_tce_table();
if (!tbl)
goto cleanup;
info->tce_space = tbl;
}
calgary_found = 1;
}
}
printk(KERN_DEBUG "Calgary: finished detection, Calgary %s\n",
calgary_found ? "found" : "not found");
if (calgary_found) {
iommu_detected = 1;
calgary_detected = 1;
printk(KERN_INFO "PCI-DMA: Calgary IOMMU detected.\n");
printk(KERN_INFO "PCI-DMA: Calgary TCE table spec is %d\n",
specified_table_size);
x86_init.iommu.iommu_init = calgary_iommu_init;
}
return calgary_found;
cleanup:
for (--bus; bus >= 0; --bus) {
struct calgary_bus_info *info = &bus_info[bus];
if (info->tce_space)
free_tce_table(info->tce_space);
}
return -ENOMEM;
}
static int __init calgary_parse_options(char *p)
{
unsigned int bridge;
unsigned long val;
size_t len;
ssize_t ret;
while (*p) {
if (!strncmp(p, "64k", 3))
specified_table_size = TCE_TABLE_SIZE_64K;
else if (!strncmp(p, "128k", 4))
specified_table_size = TCE_TABLE_SIZE_128K;
else if (!strncmp(p, "256k", 4))
specified_table_size = TCE_TABLE_SIZE_256K;
else if (!strncmp(p, "512k", 4))
specified_table_size = TCE_TABLE_SIZE_512K;
else if (!strncmp(p, "1M", 2))
specified_table_size = TCE_TABLE_SIZE_1M;
else if (!strncmp(p, "2M", 2))
specified_table_size = TCE_TABLE_SIZE_2M;
else if (!strncmp(p, "4M", 2))
specified_table_size = TCE_TABLE_SIZE_4M;
else if (!strncmp(p, "8M", 2))
specified_table_size = TCE_TABLE_SIZE_8M;
len = strlen("translate_empty_slots");
if (!strncmp(p, "translate_empty_slots", len))
translate_empty_slots = 1;
len = strlen("disable");
if (!strncmp(p, "disable", len)) {
p += len;
if (*p == '=')
++p;
if (*p == '\0')
break;
ret = kstrtoul(p, 0, &val);
if (ret)
break;
bridge = val;
if (bridge < MAX_PHB_BUS_NUM) {
printk(KERN_INFO "Calgary: disabling "
"translation for PHB %#x\n", bridge);
bus_info[bridge].translation_disabled = 1;
}
}
p = strpbrk(p, ",");
if (!p)
break;
p++;
}
return 1;
}
static void __init calgary_fixup_one_tce_space(struct pci_dev *dev)
{
struct iommu_table *tbl;
unsigned int npages;
int i;
tbl = pci_iommu(dev->bus);
for (i = 0; i < 4; i++) {
struct resource *r = &dev->resource[PCI_BRIDGE_RESOURCES + i];
if (!(r->flags & IORESOURCE_MEM))
continue;
if (!r->start)
continue;
npages = resource_size(r) >> PAGE_SHIFT;
npages++;
iommu_range_reserve(tbl, r->start, npages);
}
}
static int __init calgary_fixup_tce_spaces(void)
{
struct pci_dev *dev = NULL;
struct calgary_bus_info *info;
if (no_iommu || swiotlb || !calgary_detected)
return -ENODEV;
printk(KERN_DEBUG "Calgary: fixing up tce spaces\n");
do {
dev = pci_get_device(PCI_VENDOR_ID_IBM, PCI_ANY_ID, dev);
if (!dev)
break;
if (!is_cal_pci_dev(dev->device))
continue;
info = &bus_info[dev->bus->number];
if (info->translation_disabled)
continue;
if (!info->tce_space)
continue;
calgary_fixup_one_tce_space(dev);
} while (1);
return 0;
}
