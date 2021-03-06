static int
tioca_gart_init(struct tioca_kernel *tioca_kern)
{
u64 ap_reg;
u64 offset;
struct page *tmp;
struct tioca_common *tioca_common;
struct tioca __iomem *ca_base;
tioca_common = tioca_kern->ca_common;
ca_base = (struct tioca __iomem *)tioca_common->ca_common.bs_base;
if (list_empty(tioca_kern->ca_devices))
return 0;
ap_reg = 0;
switch (CA_APERATURE_SIZE >> 20) {
case 4:
ap_reg |= (0x3ff << CA_GART_AP_SIZE_SHFT);
break;
case 8:
ap_reg |= (0x3fe << CA_GART_AP_SIZE_SHFT);
break;
case 16:
ap_reg |= (0x3fc << CA_GART_AP_SIZE_SHFT);
break;
case 32:
ap_reg |= (0x3f8 << CA_GART_AP_SIZE_SHFT);
break;
case 64:
ap_reg |= (0x3f0 << CA_GART_AP_SIZE_SHFT);
break;
case 128:
ap_reg |= (0x3e0 << CA_GART_AP_SIZE_SHFT);
break;
case 256:
ap_reg |= (0x3c0 << CA_GART_AP_SIZE_SHFT);
break;
case 512:
ap_reg |= (0x380 << CA_GART_AP_SIZE_SHFT);
break;
case 1024:
ap_reg |= (0x300 << CA_GART_AP_SIZE_SHFT);
break;
case 2048:
ap_reg |= (0x200 << CA_GART_AP_SIZE_SHFT);
break;
case 4096:
ap_reg |= (0x000 << CA_GART_AP_SIZE_SHFT);
break;
default:
printk(KERN_ERR "%s: Invalid CA_APERATURE_SIZE "
"0x%lx\n", __func__, (ulong) CA_APERATURE_SIZE);
return -1;
}
if (PAGE_SIZE >= 16384) {
tioca_kern->ca_ap_pagesize = 16384;
ap_reg |= CA_GART_PAGE_SIZE;
} else {
tioca_kern->ca_ap_pagesize = 4096;
}
tioca_kern->ca_ap_size = CA_APERATURE_SIZE;
tioca_kern->ca_ap_bus_base = CA_APERATURE_BASE;
tioca_kern->ca_gart_entries =
tioca_kern->ca_ap_size / tioca_kern->ca_ap_pagesize;
ap_reg |= (CA_GART_AP_ENB_AGP | CA_GART_AP_ENB_PCI);
ap_reg |= tioca_kern->ca_ap_bus_base;
tioca_kern->ca_gart_size = tioca_kern->ca_gart_entries * sizeof(u64);
tmp =
alloc_pages_node(tioca_kern->ca_closest_node,
GFP_KERNEL | __GFP_ZERO,
get_order(tioca_kern->ca_gart_size));
if (!tmp) {
printk(KERN_ERR "%s: Could not allocate "
"%llu bytes (order %d) for GART\n",
__func__,
tioca_kern->ca_gart_size,
get_order(tioca_kern->ca_gart_size));
return -ENOMEM;
}
tioca_kern->ca_gart = page_address(tmp);
tioca_kern->ca_gart_coretalk_addr =
PHYS_TO_TIODMA(virt_to_phys(tioca_kern->ca_gart));
offset = CA_PCI32_MAPPED_BASE - CA_APERATURE_BASE;
tioca_kern->ca_pciap_base = CA_PCI32_MAPPED_BASE;
tioca_kern->ca_pciap_size = CA_PCI32_MAPPED_SIZE;
tioca_kern->ca_pcigart_start = offset / tioca_kern->ca_ap_pagesize;
tioca_kern->ca_pcigart_base =
tioca_kern->ca_gart_coretalk_addr + offset;
tioca_kern->ca_pcigart =
&tioca_kern->ca_gart[tioca_kern->ca_pcigart_start];
tioca_kern->ca_pcigart_entries =
tioca_kern->ca_pciap_size / tioca_kern->ca_ap_pagesize;
tioca_kern->ca_pcigart_pagemap =
kzalloc(tioca_kern->ca_pcigart_entries / 8, GFP_KERNEL);
if (!tioca_kern->ca_pcigart_pagemap) {
free_pages((unsigned long)tioca_kern->ca_gart,
get_order(tioca_kern->ca_gart_size));
return -1;
}
offset = CA_AGP_MAPPED_BASE - CA_APERATURE_BASE;
tioca_kern->ca_gfxap_base = CA_AGP_MAPPED_BASE;
tioca_kern->ca_gfxap_size = CA_AGP_MAPPED_SIZE;
tioca_kern->ca_gfxgart_start = offset / tioca_kern->ca_ap_pagesize;
tioca_kern->ca_gfxgart_base =
tioca_kern->ca_gart_coretalk_addr + offset;
tioca_kern->ca_gfxgart =
&tioca_kern->ca_gart[tioca_kern->ca_gfxgart_start];
tioca_kern->ca_gfxgart_entries =
tioca_kern->ca_gfxap_size / tioca_kern->ca_ap_pagesize;
__sn_setq_relaxed(&ca_base->ca_control1,
CA_AGPDMA_OP_ENB_COMBDELAY);
__sn_clrq_relaxed(&ca_base->ca_control2, CA_GART_MEM_PARAM);
__sn_setq_relaxed(&ca_base->ca_control2,
(0x2ull << CA_GART_MEM_PARAM_SHFT));
tioca_kern->ca_gart_iscoherent = 1;
__sn_clrq_relaxed(&ca_base->ca_control2,
(CA_GART_WR_PREFETCH_ENB | CA_GART_RD_PREFETCH_ENB));
writeq(CA_GART_FETCH_ERR, &ca_base->ca_int_status_alias);
writeq(CA_GART_FETCH_ERR, &ca_base->ca_mult_error_alias);
__sn_clrq_relaxed(&ca_base->ca_int_mask, CA_GART_FETCH_ERR);
writeq(ap_reg, &ca_base->ca_gart_aperature);
writeq(tioca_kern->ca_gart_coretalk_addr|1, &ca_base->ca_gart_ptr_table);
return 0;
}
void
tioca_fastwrite_enable(struct tioca_kernel *tioca_kern)
{
int cap_ptr;
u32 reg;
struct tioca __iomem *tioca_base;
struct pci_dev *pdev;
struct tioca_common *common;
common = tioca_kern->ca_common;
list_for_each_entry(pdev, tioca_kern->ca_devices, bus_list) {
if (pdev->class != (PCI_CLASS_DISPLAY_VGA << 8))
continue;
cap_ptr = pci_find_capability(pdev, PCI_CAP_ID_AGP);
if (!cap_ptr)
return;
pci_read_config_dword(pdev, cap_ptr + PCI_AGP_STATUS, &reg);
if (!(reg & PCI_AGP_STATUS_FW))
return;
}
list_for_each_entry(pdev, tioca_kern->ca_devices, bus_list) {
if (pdev->class != (PCI_CLASS_DISPLAY_VGA << 8))
continue;
cap_ptr = pci_find_capability(pdev, PCI_CAP_ID_AGP);
pci_read_config_dword(pdev, cap_ptr + PCI_AGP_COMMAND, &reg);
reg |= PCI_AGP_COMMAND_FW;
pci_write_config_dword(pdev, cap_ptr + PCI_AGP_COMMAND, reg);
}
tioca_base = (struct tioca __iomem*)common->ca_common.bs_base;
__sn_setq_relaxed(&tioca_base->ca_control1, CA_AGP_FW_ENABLE);
}
static u64
tioca_dma_d64(unsigned long paddr)
{
dma_addr_t bus_addr;
bus_addr = PHYS_TO_TIODMA(paddr);
BUG_ON(!bus_addr);
BUG_ON(bus_addr >> 54);
bus_addr |= (1UL << 60);
return bus_addr;
}
static u64
tioca_dma_d48(struct pci_dev *pdev, u64 paddr)
{
struct tioca_common *tioca_common;
struct tioca __iomem *ca_base;
u64 ct_addr;
dma_addr_t bus_addr;
u32 node_upper;
u64 agp_dma_extn;
struct pcidev_info *pcidev_info = SN_PCIDEV_INFO(pdev);
tioca_common = (struct tioca_common *)pcidev_info->pdi_pcibus_info;
ca_base = (struct tioca __iomem *)tioca_common->ca_common.bs_base;
ct_addr = PHYS_TO_TIODMA(paddr);
if (!ct_addr)
return 0;
bus_addr = (dma_addr_t) (ct_addr & 0xffffffffffffUL);
node_upper = ct_addr >> 48;
if (node_upper > 64) {
printk(KERN_ERR "%s: coretalk addr 0x%p node id out "
"of range\n", __func__, (void *)ct_addr);
return 0;
}
agp_dma_extn = __sn_readq_relaxed(&ca_base->ca_agp_dma_addr_extn);
if (node_upper != (agp_dma_extn >> CA_AGP_DMA_NODE_ID_SHFT)) {
printk(KERN_ERR "%s: coretalk upper node (%u) "
"mismatch with ca_agp_dma_addr_extn (%llu)\n",
__func__,
node_upper, (agp_dma_extn >> CA_AGP_DMA_NODE_ID_SHFT));
return 0;
}
return bus_addr;
}
static dma_addr_t
tioca_dma_mapped(struct pci_dev *pdev, unsigned long paddr, size_t req_size)
{
int ps, ps_shift, entry, entries, mapsize;
u64 xio_addr, end_xio_addr;
struct tioca_common *tioca_common;
struct tioca_kernel *tioca_kern;
dma_addr_t bus_addr = 0;
struct tioca_dmamap *ca_dmamap;
void *map;
unsigned long flags;
struct pcidev_info *pcidev_info = SN_PCIDEV_INFO(pdev);
tioca_common = (struct tioca_common *)pcidev_info->pdi_pcibus_info;
tioca_kern = (struct tioca_kernel *)tioca_common->ca_kernel_private;
xio_addr = PHYS_TO_TIODMA(paddr);
if (!xio_addr)
return 0;
spin_lock_irqsave(&tioca_kern->ca_lock, flags);
ca_dmamap = kzalloc(sizeof(struct tioca_dmamap), GFP_ATOMIC);
if (!ca_dmamap)
goto map_return;
ps = tioca_kern->ca_ap_pagesize;
ps_shift = ffs(ps) - 1;
end_xio_addr = xio_addr + req_size - 1;
entries = (end_xio_addr >> ps_shift) - (xio_addr >> ps_shift) + 1;
map = tioca_kern->ca_pcigart_pagemap;
mapsize = tioca_kern->ca_pcigart_entries;
entry = bitmap_find_next_zero_area(map, mapsize, 0, entries, 0);
if (entry >= mapsize) {
kfree(ca_dmamap);
goto map_return;
}
bitmap_set(map, entry, entries);
bus_addr = tioca_kern->ca_pciap_base + (entry * ps);
ca_dmamap->cad_dma_addr = bus_addr;
ca_dmamap->cad_gart_size = entries;
ca_dmamap->cad_gart_entry = entry;
list_add(&ca_dmamap->cad_list, &tioca_kern->ca_dmamaps);
if (xio_addr % ps) {
tioca_kern->ca_pcigart[entry] = tioca_paddr_to_gart(xio_addr);
bus_addr += xio_addr & (ps - 1);
xio_addr &= ~(ps - 1);
xio_addr += ps;
entry++;
}
while (xio_addr < end_xio_addr) {
tioca_kern->ca_pcigart[entry] = tioca_paddr_to_gart(xio_addr);
xio_addr += ps;
entry++;
}
tioca_tlbflush(tioca_kern);
map_return:
spin_unlock_irqrestore(&tioca_kern->ca_lock, flags);
return bus_addr;
}
static void
tioca_dma_unmap(struct pci_dev *pdev, dma_addr_t bus_addr, int dir)
{
int i, entry;
struct tioca_common *tioca_common;
struct tioca_kernel *tioca_kern;
struct tioca_dmamap *map;
struct pcidev_info *pcidev_info = SN_PCIDEV_INFO(pdev);
unsigned long flags;
tioca_common = (struct tioca_common *)pcidev_info->pdi_pcibus_info;
tioca_kern = (struct tioca_kernel *)tioca_common->ca_kernel_private;
if (bus_addr < tioca_kern->ca_pciap_base ||
bus_addr >= (tioca_kern->ca_pciap_base + tioca_kern->ca_pciap_size))
return;
spin_lock_irqsave(&tioca_kern->ca_lock, flags);
list_for_each_entry(map, &tioca_kern->ca_dmamaps, cad_list)
if (map->cad_dma_addr == bus_addr)
break;
BUG_ON(map == NULL);
entry = map->cad_gart_entry;
for (i = 0; i < map->cad_gart_size; i++, entry++) {
clear_bit(entry, tioca_kern->ca_pcigart_pagemap);
tioca_kern->ca_pcigart[entry] = 0;
}
tioca_tlbflush(tioca_kern);
list_del(&map->cad_list);
spin_unlock_irqrestore(&tioca_kern->ca_lock, flags);
kfree(map);
}
static u64
tioca_dma_map(struct pci_dev *pdev, unsigned long paddr, size_t byte_count, int dma_flags)
{
u64 mapaddr;
if (dma_flags & SN_DMA_MSI)
return 0;
if (pdev->dma_mask == ~0UL)
mapaddr = tioca_dma_d64(paddr);
else if (pdev->dma_mask == 0xffffffffffffUL)
mapaddr = tioca_dma_d48(pdev, paddr);
else
mapaddr = 0;
if (mapaddr == 0)
mapaddr = tioca_dma_mapped(pdev, paddr, byte_count);
return mapaddr;
}
static irqreturn_t
tioca_error_intr_handler(int irq, void *arg)
{
struct tioca_common *soft = arg;
struct ia64_sal_retval ret_stuff;
u64 segment;
u64 busnum;
ret_stuff.status = 0;
ret_stuff.v0 = 0;
segment = soft->ca_common.bs_persist_segment;
busnum = soft->ca_common.bs_persist_busnum;
SAL_CALL_NOLOCK(ret_stuff,
(u64) SN_SAL_IOIF_ERROR_INTERRUPT,
segment, busnum, 0, 0, 0, 0, 0);
return IRQ_HANDLED;
}
static void *
tioca_bus_fixup(struct pcibus_bussoft *prom_bussoft, struct pci_controller *controller)
{
struct tioca_common *tioca_common;
struct tioca_kernel *tioca_kern;
struct pci_bus *bus;
if (is_shub1() && sn_sal_rev() < 0x0406) {
printk
(KERN_ERR "%s: SGI prom rev 4.06 or greater required "
"for tioca support\n", __func__);
return NULL;
}
tioca_common = kmemdup(prom_bussoft, sizeof(struct tioca_common),
GFP_KERNEL);
if (!tioca_common)
return NULL;
tioca_common->ca_common.bs_base = (unsigned long)
ioremap(REGION_OFFSET(tioca_common->ca_common.bs_base),
sizeof(struct tioca_common));
tioca_kern = kzalloc(sizeof(struct tioca_kernel), GFP_KERNEL);
if (!tioca_kern) {
kfree(tioca_common);
return NULL;
}
tioca_kern->ca_common = tioca_common;
spin_lock_init(&tioca_kern->ca_lock);
INIT_LIST_HEAD(&tioca_kern->ca_dmamaps);
tioca_kern->ca_closest_node =
nasid_to_cnodeid(tioca_common->ca_closest_nasid);
tioca_common->ca_kernel_private = (u64) tioca_kern;
bus = pci_find_bus(tioca_common->ca_common.bs_persist_segment,
tioca_common->ca_common.bs_persist_busnum);
BUG_ON(!bus);
tioca_kern->ca_devices = &bus->devices;
if (tioca_gart_init(tioca_kern) < 0) {
kfree(tioca_kern);
kfree(tioca_common);
return NULL;
}
tioca_gart_found++;
list_add(&tioca_kern->ca_list, &tioca_list);
if (request_irq(SGI_TIOCA_ERROR,
tioca_error_intr_handler,
IRQF_SHARED, "TIOCA error", (void *)tioca_common))
printk(KERN_WARNING
"%s: Unable to get irq %d. "
"Error interrupts won't be routed for TIOCA bus %d\n",
__func__, SGI_TIOCA_ERROR,
(int)tioca_common->ca_common.bs_persist_busnum);
sn_set_err_irq_affinity(SGI_TIOCA_ERROR);
controller->node = tioca_kern->ca_closest_node;
return tioca_common;
}
int
tioca_init_provider(void)
{
sn_pci_provider[PCIIO_ASIC_TYPE_TIOCA] = &tioca_pci_interfaces;
return 0;
}
