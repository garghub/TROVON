static inline void dart_tlb_invalidate_all(void)
{
unsigned long l = 0;
unsigned int reg, inv_bit;
unsigned long limit;
unsigned long flags;
spin_lock_irqsave(&invalidate_lock, flags);
DBG("dart: flush\n");
limit = 0;
inv_bit = dart_is_u4 ? DART_CNTL_U4_FLUSHTLB : DART_CNTL_U3_FLUSHTLB;
retry:
l = 0;
reg = DART_IN(DART_CNTL);
reg |= inv_bit;
DART_OUT(DART_CNTL, reg);
while ((DART_IN(DART_CNTL) & inv_bit) && l < (1L << limit))
l++;
if (l == (1L << limit)) {
if (limit < 4) {
limit++;
reg = DART_IN(DART_CNTL);
reg &= ~inv_bit;
DART_OUT(DART_CNTL, reg);
goto retry;
} else
panic("DART: TLB did not flush after waiting a long "
"time. Buggy U3 ?");
}
spin_unlock_irqrestore(&invalidate_lock, flags);
}
static inline void dart_tlb_invalidate_one(unsigned long bus_rpn)
{
unsigned int reg;
unsigned int l, limit;
unsigned long flags;
spin_lock_irqsave(&invalidate_lock, flags);
reg = DART_CNTL_U4_ENABLE | DART_CNTL_U4_IONE |
(bus_rpn & DART_CNTL_U4_IONE_MASK);
DART_OUT(DART_CNTL, reg);
limit = 0;
wait_more:
l = 0;
while ((DART_IN(DART_CNTL) & DART_CNTL_U4_IONE) && l < (1L << limit)) {
rmb();
l++;
}
if (l == (1L << limit)) {
if (limit < 4) {
limit++;
goto wait_more;
} else
panic("DART: TLB did not flush after waiting a long "
"time. Buggy U4 ?");
}
spin_unlock_irqrestore(&invalidate_lock, flags);
}
static void dart_flush(struct iommu_table *tbl)
{
mb();
if (dart_dirty) {
dart_tlb_invalidate_all();
dart_dirty = 0;
}
}
static int dart_build(struct iommu_table *tbl, long index,
long npages, unsigned long uaddr,
enum dma_data_direction direction,
struct dma_attrs *attrs)
{
unsigned int *dp;
unsigned int rpn;
long l;
DBG("dart: build at: %lx, %lx, addr: %x\n", index, npages, uaddr);
dp = ((unsigned int*)tbl->it_base) + index;
l = npages;
while (l--) {
rpn = __pa(uaddr) >> DART_PAGE_SHIFT;
*(dp++) = DARTMAP_VALID | (rpn & DARTMAP_RPNMASK);
uaddr += DART_PAGE_SIZE;
}
mb();
in_be32((unsigned __iomem *)dp);
mb();
if (dart_is_u4) {
rpn = index;
while (npages--)
dart_tlb_invalidate_one(rpn++);
} else {
dart_dirty = 1;
}
return 0;
}
static void dart_free(struct iommu_table *tbl, long index, long npages)
{
unsigned int *dp;
DBG("dart: free at: %lx, %lx\n", index, npages);
dp = ((unsigned int *)tbl->it_base) + index;
while (npages--)
*(dp++) = dart_emptyval;
}
static int __init dart_init(struct device_node *dart_node)
{
unsigned int i;
unsigned long tmp, base, size;
struct resource r;
if (dart_tablebase == 0 || dart_tablesize == 0) {
printk(KERN_INFO "DART: table not allocated, using "
"direct DMA\n");
return -ENODEV;
}
if (of_address_to_resource(dart_node, 0, &r))
panic("DART: can't get register base ! ");
flush_dcache_phys_range(dart_tablebase,
dart_tablebase + dart_tablesize);
tmp = memblock_alloc(DART_PAGE_SIZE, DART_PAGE_SIZE);
dart_emptyval = DARTMAP_VALID | ((tmp >> DART_PAGE_SHIFT) &
DARTMAP_RPNMASK);
dart = ioremap(r.start, resource_size(&r));
if (dart == NULL)
panic("DART: Cannot map registers!");
dart_vbase = ioremap(__pa(dart_tablebase), dart_tablesize);
for (i = 0; i < dart_tablesize/4; i++)
dart_vbase[i] = dart_emptyval;
base = dart_tablebase >> DART_PAGE_SHIFT;
size = dart_tablesize >> DART_PAGE_SHIFT;
if (dart_is_u4) {
size &= DART_SIZE_U4_SIZE_MASK;
DART_OUT(DART_BASE_U4, base);
DART_OUT(DART_SIZE_U4, size);
DART_OUT(DART_CNTL, DART_CNTL_U4_ENABLE);
} else {
size &= DART_CNTL_U3_SIZE_MASK;
DART_OUT(DART_CNTL,
DART_CNTL_U3_ENABLE |
(base << DART_CNTL_U3_BASE_SHIFT) |
(size << DART_CNTL_U3_SIZE_SHIFT));
}
dart_tlb_invalidate_all();
printk(KERN_INFO "DART IOMMU initialized for %s type chipset\n",
dart_is_u4 ? "U4" : "U3");
return 0;
}
static void iommu_table_dart_setup(void)
{
iommu_table_dart.it_busno = 0;
iommu_table_dart.it_offset = 0;
iommu_table_dart.it_size = dart_tablesize / sizeof(u32);
iommu_table_dart.it_page_shift = IOMMU_PAGE_SHIFT_4K;
iommu_table_dart.it_base = (unsigned long)dart_vbase;
iommu_table_dart.it_index = 0;
iommu_table_dart.it_blocksize = 1;
iommu_table_dart.it_ops = &iommu_dart_ops;
iommu_init_table(&iommu_table_dart, -1);
set_bit(iommu_table_dart.it_size - 1, iommu_table_dart.it_map);
}
static void dma_dev_setup_dart(struct device *dev)
{
if (get_dma_ops(dev) == &dma_direct_ops)
set_dma_offset(dev, DART_U4_BYPASS_BASE);
else
set_iommu_table_base(dev, &iommu_table_dart);
}
static void pci_dma_dev_setup_dart(struct pci_dev *dev)
{
dma_dev_setup_dart(&dev->dev);
}
static void pci_dma_bus_setup_dart(struct pci_bus *bus)
{
if (!iommu_table_dart_inited) {
iommu_table_dart_inited = 1;
iommu_table_dart_setup();
}
}
static bool dart_device_on_pcie(struct device *dev)
{
struct device_node *np = of_node_get(dev->of_node);
while(np) {
if (of_device_is_compatible(np, "U4-pcie") ||
of_device_is_compatible(np, "u4-pcie")) {
of_node_put(np);
return true;
}
np = of_get_next_parent(np);
}
return false;
}
static int dart_dma_set_mask(struct device *dev, u64 dma_mask)
{
if (!dev->dma_mask || !dma_supported(dev, dma_mask))
return -EIO;
if (dart_device_on_pcie(dev) && dma_mask >= DMA_BIT_MASK(40)) {
dev_info(dev, "Using 64-bit DMA iommu bypass\n");
set_dma_ops(dev, &dma_direct_ops);
} else {
dev_info(dev, "Using 32-bit DMA via iommu\n");
set_dma_ops(dev, &dma_iommu_ops);
}
dma_dev_setup_dart(dev);
*dev->dma_mask = dma_mask;
return 0;
}
void __init iommu_init_early_dart(struct pci_controller_ops *controller_ops)
{
struct device_node *dn;
dn = of_find_compatible_node(NULL, "dart", "u3-dart");
if (dn == NULL) {
dn = of_find_compatible_node(NULL, "dart", "u4-dart");
if (dn == NULL)
return;
dart_is_u4 = 1;
}
if (dart_init(dn) != 0)
goto bail;
if (dart_is_u4)
ppc_md.dma_set_mask = dart_dma_set_mask;
controller_ops->dma_dev_setup = pci_dma_dev_setup_dart;
controller_ops->dma_bus_setup = pci_dma_bus_setup_dart;
set_pci_dma_ops(&dma_iommu_ops);
return;
bail:
controller_ops->dma_dev_setup = NULL;
controller_ops->dma_bus_setup = NULL;
set_pci_dma_ops(&dma_direct_ops);
}
static void iommu_dart_save(void)
{
memcpy(dart_copy, dart_vbase, 2*1024*1024);
}
static void iommu_dart_restore(void)
{
memcpy(dart_vbase, dart_copy, 2*1024*1024);
dart_tlb_invalidate_all();
}
static int __init iommu_init_late_dart(void)
{
unsigned long tbasepfn;
struct page *p;
if (!dart_tablebase)
return 0;
tbasepfn = __pa(dart_tablebase) >> PAGE_SHIFT;
register_nosave_region_late(tbasepfn,
tbasepfn + ((1<<24) >> PAGE_SHIFT));
p = alloc_pages(GFP_KERNEL, 21 - PAGE_SHIFT);
BUG_ON(!p);
dart_copy = page_address(p);
ppc_md.iommu_save = iommu_dart_save;
ppc_md.iommu_restore = iommu_dart_restore;
return 0;
}
void __init alloc_dart_table(void)
{
if (iommu_is_off)
return;
if (!iommu_force_on && memblock_end_of_DRAM() <= 0x40000000ull)
return;
dart_tablesize = 1UL << 21;
dart_tablebase = (unsigned long)
__va(memblock_alloc_base(1UL<<24, 1UL<<24, 0x80000000L));
kmemleak_no_scan((void *)dart_tablebase);
printk(KERN_INFO "DART table allocated at: %lx\n", dart_tablebase);
}
