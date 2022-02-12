static dma_addr_t octeon_hole_phys_to_dma(phys_addr_t paddr)
{
if (paddr >= CVMX_PCIE_BAR1_PHYS_BASE && paddr < (CVMX_PCIE_BAR1_PHYS_BASE + CVMX_PCIE_BAR1_PHYS_SIZE))
return paddr - CVMX_PCIE_BAR1_PHYS_BASE + CVMX_PCIE_BAR1_RC_BASE;
else
return paddr;
}
static phys_addr_t octeon_hole_dma_to_phys(dma_addr_t daddr)
{
if (daddr >= CVMX_PCIE_BAR1_RC_BASE)
return daddr + CVMX_PCIE_BAR1_PHYS_BASE - CVMX_PCIE_BAR1_RC_BASE;
else
return daddr;
}
static dma_addr_t octeon_gen1_phys_to_dma(struct device *dev, phys_addr_t paddr)
{
if (paddr >= 0x410000000ull && paddr < 0x420000000ull)
paddr -= 0x400000000ull;
return octeon_hole_phys_to_dma(paddr);
}
static phys_addr_t octeon_gen1_dma_to_phys(struct device *dev, dma_addr_t daddr)
{
daddr = octeon_hole_dma_to_phys(daddr);
if (daddr >= 0x10000000ull && daddr < 0x20000000ull)
daddr += 0x400000000ull;
return daddr;
}
static dma_addr_t octeon_gen2_phys_to_dma(struct device *dev, phys_addr_t paddr)
{
return octeon_hole_phys_to_dma(paddr);
}
static phys_addr_t octeon_gen2_dma_to_phys(struct device *dev, dma_addr_t daddr)
{
return octeon_hole_dma_to_phys(daddr);
}
static dma_addr_t octeon_big_phys_to_dma(struct device *dev, phys_addr_t paddr)
{
if (paddr >= 0x410000000ull && paddr < 0x420000000ull)
paddr -= 0x400000000ull;
if (paddr >= 0xf0000000ull)
paddr = OCTEON_BAR2_PCI_ADDRESS + paddr;
return paddr;
}
static phys_addr_t octeon_big_dma_to_phys(struct device *dev, dma_addr_t daddr)
{
if (daddr >= OCTEON_BAR2_PCI_ADDRESS)
daddr -= OCTEON_BAR2_PCI_ADDRESS;
if (daddr >= 0x10000000ull && daddr < 0x20000000ull)
daddr += 0x400000000ull;
return daddr;
}
static dma_addr_t octeon_small_phys_to_dma(struct device *dev,
phys_addr_t paddr)
{
if (paddr >= 0x410000000ull && paddr < 0x420000000ull)
paddr -= 0x400000000ull;
if (paddr >= octeon_bar1_pci_phys && paddr < octeon_bar1_pci_phys + 0x8000000ull)
paddr = paddr - octeon_bar1_pci_phys;
else
paddr = OCTEON_BAR2_PCI_ADDRESS + paddr;
return paddr;
}
static phys_addr_t octeon_small_dma_to_phys(struct device *dev,
dma_addr_t daddr)
{
if (daddr >= OCTEON_BAR2_PCI_ADDRESS)
daddr -= OCTEON_BAR2_PCI_ADDRESS;
else
daddr += octeon_bar1_pci_phys;
if (daddr >= 0x10000000ull && daddr < 0x20000000ull)
daddr += 0x400000000ull;
return daddr;
}
static dma_addr_t octeon_dma_map_page(struct device *dev, struct page *page,
unsigned long offset, size_t size, enum dma_data_direction direction,
struct dma_attrs *attrs)
{
dma_addr_t daddr = swiotlb_map_page(dev, page, offset, size,
direction, attrs);
mb();
return daddr;
}
static int octeon_dma_map_sg(struct device *dev, struct scatterlist *sg,
int nents, enum dma_data_direction direction, struct dma_attrs *attrs)
{
int r = swiotlb_map_sg_attrs(dev, sg, nents, direction, attrs);
mb();
return r;
}
static void octeon_dma_sync_single_for_device(struct device *dev,
dma_addr_t dma_handle, size_t size, enum dma_data_direction direction)
{
swiotlb_sync_single_for_device(dev, dma_handle, size, direction);
mb();
}
static void octeon_dma_sync_sg_for_device(struct device *dev,
struct scatterlist *sg, int nelems, enum dma_data_direction direction)
{
swiotlb_sync_sg_for_device(dev, sg, nelems, direction);
mb();
}
static void *octeon_dma_alloc_coherent(struct device *dev, size_t size,
dma_addr_t *dma_handle, gfp_t gfp, struct dma_attrs *attrs)
{
void *ret;
if (dma_alloc_from_coherent(dev, size, dma_handle, &ret))
return ret;
gfp &= ~(__GFP_DMA | __GFP_DMA32 | __GFP_HIGHMEM);
#ifdef CONFIG_ZONE_DMA
if (dev == NULL)
gfp |= __GFP_DMA;
else if (dev->coherent_dma_mask <= DMA_BIT_MASK(24))
gfp |= __GFP_DMA;
else
#endif
#ifdef CONFIG_ZONE_DMA32
if (dev->coherent_dma_mask <= DMA_BIT_MASK(32))
gfp |= __GFP_DMA32;
else
#endif
;
gfp |= __GFP_NORETRY;
ret = swiotlb_alloc_coherent(dev, size, dma_handle, gfp);
mb();
return ret;
}
static void octeon_dma_free_coherent(struct device *dev, size_t size,
void *vaddr, dma_addr_t dma_handle, struct dma_attrs *attrs)
{
int order = get_order(size);
if (dma_release_from_coherent(dev, order, vaddr))
return;
swiotlb_free_coherent(dev, size, vaddr, dma_handle);
}
static dma_addr_t octeon_unity_phys_to_dma(struct device *dev, phys_addr_t paddr)
{
return paddr;
}
static phys_addr_t octeon_unity_dma_to_phys(struct device *dev, dma_addr_t daddr)
{
return daddr;
}
dma_addr_t phys_to_dma(struct device *dev, phys_addr_t paddr)
{
struct octeon_dma_map_ops *ops = container_of(get_dma_ops(dev),
struct octeon_dma_map_ops,
dma_map_ops);
return ops->phys_to_dma(dev, paddr);
}
phys_addr_t dma_to_phys(struct device *dev, dma_addr_t daddr)
{
struct octeon_dma_map_ops *ops = container_of(get_dma_ops(dev),
struct octeon_dma_map_ops,
dma_map_ops);
return ops->dma_to_phys(dev, daddr);
}
void __init plat_swiotlb_setup(void)
{
int i;
phys_addr_t max_addr;
phys_addr_t addr_size;
size_t swiotlbsize;
unsigned long swiotlb_nslabs;
max_addr = 0;
addr_size = 0;
for (i = 0 ; i < boot_mem_map.nr_map; i++) {
struct boot_mem_map_entry *e = &boot_mem_map.map[i];
if (e->type != BOOT_MEM_RAM && e->type != BOOT_MEM_INIT_RAM)
continue;
if (e->addr > 0x410000000ull && !OCTEON_IS_MODEL(OCTEON_CN6XXX))
continue;
addr_size += e->size;
if (max_addr < e->addr + e->size)
max_addr = e->addr + e->size;
}
swiotlbsize = PAGE_SIZE;
#ifdef CONFIG_PCI
if (OCTEON_IS_MODEL(OCTEON_CN31XX)
|| OCTEON_IS_MODEL(OCTEON_CN38XX_PASS2)) {
swiotlbsize = addr_size / 4;
if (swiotlbsize > 64 * (1<<20))
swiotlbsize = 64 * (1<<20);
} else if (max_addr > 0xf0000000ul) {
swiotlbsize = 64 * (1<<20);
}
#endif
#ifdef CONFIG_USB_OCTEON_OHCI
if (OCTEON_IS_MODEL(OCTEON_CN6XXX) && max_addr >= 0x100000000ul)
swiotlbsize = 64 * (1<<20);
#endif
swiotlb_nslabs = swiotlbsize >> IO_TLB_SHIFT;
swiotlb_nslabs = ALIGN(swiotlb_nslabs, IO_TLB_SEGSIZE);
swiotlbsize = swiotlb_nslabs << IO_TLB_SHIFT;
octeon_swiotlb = alloc_bootmem_low_pages(swiotlbsize);
if (swiotlb_init_with_tbl(octeon_swiotlb, swiotlb_nslabs, 1) == -ENOMEM)
panic("Cannot allocate SWIOTLB buffer");
mips_dma_map_ops = &octeon_linear_dma_map_ops.dma_map_ops;
}
void __init octeon_pci_dma_init(void)
{
switch (octeon_dma_bar_type) {
case OCTEON_DMA_BAR_TYPE_PCIE2:
_octeon_pci_dma_map_ops.phys_to_dma = octeon_gen2_phys_to_dma;
_octeon_pci_dma_map_ops.dma_to_phys = octeon_gen2_dma_to_phys;
break;
case OCTEON_DMA_BAR_TYPE_PCIE:
_octeon_pci_dma_map_ops.phys_to_dma = octeon_gen1_phys_to_dma;
_octeon_pci_dma_map_ops.dma_to_phys = octeon_gen1_dma_to_phys;
break;
case OCTEON_DMA_BAR_TYPE_BIG:
_octeon_pci_dma_map_ops.phys_to_dma = octeon_big_phys_to_dma;
_octeon_pci_dma_map_ops.dma_to_phys = octeon_big_dma_to_phys;
break;
case OCTEON_DMA_BAR_TYPE_SMALL:
_octeon_pci_dma_map_ops.phys_to_dma = octeon_small_phys_to_dma;
_octeon_pci_dma_map_ops.dma_to_phys = octeon_small_dma_to_phys;
break;
default:
BUG();
}
octeon_pci_dma_map_ops = &_octeon_pci_dma_map_ops.dma_map_ops;
}
