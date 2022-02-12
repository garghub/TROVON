static struct pci_dn *pnv_ioda_get_pdn(struct pci_dev *dev)
{
struct device_node *np;
np = pci_device_to_OF_node(dev);
if (!np)
return NULL;
return PCI_DN(np);
}
static int pnv_ioda_alloc_pe(struct pnv_phb *phb)
{
unsigned long pe;
do {
pe = find_next_zero_bit(phb->ioda.pe_alloc,
phb->ioda.total_pe, 0);
if (pe >= phb->ioda.total_pe)
return IODA_INVALID_PE;
} while(test_and_set_bit(pe, phb->ioda.pe_alloc));
phb->ioda.pe_array[pe].pe_number = pe;
return pe;
}
static void pnv_ioda_free_pe(struct pnv_phb *phb, int pe)
{
WARN_ON(phb->ioda.pe_array[pe].pdev);
memset(&phb->ioda.pe_array[pe], 0, sizeof(struct pnv_ioda_pe));
clear_bit(pe, phb->ioda.pe_alloc);
}
static struct pnv_ioda_pe *pnv_ioda_get_pe(struct pci_dev *dev)
{
struct pci_controller *hose = pci_bus_to_host(dev->bus);
struct pnv_phb *phb = hose->private_data;
struct pci_dn *pdn = pnv_ioda_get_pdn(dev);
if (!pdn)
return NULL;
if (pdn->pe_number == IODA_INVALID_PE)
return NULL;
return &phb->ioda.pe_array[pdn->pe_number];
}
static int pnv_ioda_configure_pe(struct pnv_phb *phb, struct pnv_ioda_pe *pe)
{
struct pci_dev *parent;
uint8_t bcomp, dcomp, fcomp;
long rc, rid_end, rid;
if (pe->pbus) {
int count;
dcomp = OPAL_IGNORE_RID_DEVICE_NUMBER;
fcomp = OPAL_IGNORE_RID_FUNCTION_NUMBER;
parent = pe->pbus->self;
if (pe->flags & PNV_IODA_PE_BUS_ALL)
count = pe->pbus->busn_res.end - pe->pbus->busn_res.start + 1;
else
count = 1;
switch(count) {
case 1: bcomp = OpalPciBusAll; break;
case 2: bcomp = OpalPciBus7Bits; break;
case 4: bcomp = OpalPciBus6Bits; break;
case 8: bcomp = OpalPciBus5Bits; break;
case 16: bcomp = OpalPciBus4Bits; break;
case 32: bcomp = OpalPciBus3Bits; break;
default:
pr_err("%s: Number of subordinate busses %d"
" unsupported\n",
pci_name(pe->pbus->self), count);
bcomp = OpalPciBusAll;
}
rid_end = pe->rid + (count << 8);
} else {
parent = pe->pdev->bus->self;
bcomp = OpalPciBusAll;
dcomp = OPAL_COMPARE_RID_DEVICE_NUMBER;
fcomp = OPAL_COMPARE_RID_FUNCTION_NUMBER;
rid_end = pe->rid + 1;
}
rc = opal_pci_set_pe(phb->opal_id, pe->pe_number, pe->rid,
bcomp, dcomp, fcomp, OPAL_MAP_PE);
if (rc) {
pe_err(pe, "OPAL error %ld trying to setup PELT table\n", rc);
return -ENXIO;
}
opal_pci_eeh_freeze_clear(phb->opal_id, pe->pe_number,
OPAL_EEH_ACTION_CLEAR_FREEZE_ALL);
while (parent) {
struct pci_dn *pdn = pnv_ioda_get_pdn(parent);
if (pdn && pdn->pe_number != IODA_INVALID_PE) {
rc = opal_pci_set_peltv(phb->opal_id, pdn->pe_number,
pe->pe_number, OPAL_ADD_PE_TO_DOMAIN);
}
parent = parent->bus->self;
}
for (rid = pe->rid; rid < rid_end; rid++)
phb->ioda.pe_rmap[rid] = pe->pe_number;
if (phb->type == PNV_PHB_IODA1) {
pe->mve_number = pe->pe_number;
rc = opal_pci_set_mve(phb->opal_id, pe->mve_number,
pe->pe_number);
if (rc) {
pe_err(pe, "OPAL error %ld setting up MVE %d\n",
rc, pe->mve_number);
pe->mve_number = -1;
} else {
rc = opal_pci_set_mve_enable(phb->opal_id,
pe->mve_number, OPAL_ENABLE_MVE);
if (rc) {
pe_err(pe, "OPAL error %ld enabling MVE %d\n",
rc, pe->mve_number);
pe->mve_number = -1;
}
}
} else if (phb->type == PNV_PHB_IODA2)
pe->mve_number = 0;
return 0;
}
static void pnv_ioda_link_pe_by_weight(struct pnv_phb *phb,
struct pnv_ioda_pe *pe)
{
struct pnv_ioda_pe *lpe;
list_for_each_entry(lpe, &phb->ioda.pe_dma_list, dma_link) {
if (lpe->dma_weight < pe->dma_weight) {
list_add_tail(&pe->dma_link, &lpe->dma_link);
return;
}
}
list_add_tail(&pe->dma_link, &phb->ioda.pe_dma_list);
}
static unsigned int pnv_ioda_dma_weight(struct pci_dev *dev)
{
if (dev->hdr_type != PCI_HEADER_TYPE_NORMAL)
return 0;
if (dev->class == PCI_CLASS_SERIAL_USB_UHCI ||
dev->class == PCI_CLASS_SERIAL_USB_OHCI ||
dev->class == PCI_CLASS_SERIAL_USB_EHCI)
return 3;
if ((dev->class >> 8) == PCI_CLASS_STORAGE_RAID)
return 15;
return 10;
}
static void pnv_ioda_setup_same_PE(struct pci_bus *bus, struct pnv_ioda_pe *pe)
{
struct pci_dev *dev;
list_for_each_entry(dev, &bus->devices, bus_list) {
struct pci_dn *pdn = pnv_ioda_get_pdn(dev);
if (pdn == NULL) {
pr_warn("%s: No device node associated with device !\n",
pci_name(dev));
continue;
}
pci_dev_get(dev);
pdn->pcidev = dev;
pdn->pe_number = pe->pe_number;
pe->dma_weight += pnv_ioda_dma_weight(dev);
if ((pe->flags & PNV_IODA_PE_BUS_ALL) && dev->subordinate)
pnv_ioda_setup_same_PE(dev->subordinate, pe);
}
}
static void pnv_ioda_setup_bus_PE(struct pci_bus *bus, int all)
{
struct pci_controller *hose = pci_bus_to_host(bus);
struct pnv_phb *phb = hose->private_data;
struct pnv_ioda_pe *pe;
int pe_num;
pe_num = pnv_ioda_alloc_pe(phb);
if (pe_num == IODA_INVALID_PE) {
pr_warning("%s: Not enough PE# available for PCI bus %04x:%02x\n",
__func__, pci_domain_nr(bus), bus->number);
return;
}
pe = &phb->ioda.pe_array[pe_num];
pe->flags = (all ? PNV_IODA_PE_BUS_ALL : PNV_IODA_PE_BUS);
pe->pbus = bus;
pe->pdev = NULL;
pe->tce32_seg = -1;
pe->mve_number = -1;
pe->rid = bus->busn_res.start << 8;
pe->dma_weight = 0;
if (all)
pe_info(pe, "Secondary bus %d..%d associated with PE#%d\n",
bus->busn_res.start, bus->busn_res.end, pe_num);
else
pe_info(pe, "Secondary bus %d associated with PE#%d\n",
bus->busn_res.start, pe_num);
if (pnv_ioda_configure_pe(phb, pe)) {
if (pe_num)
pnv_ioda_free_pe(phb, pe_num);
pe->pbus = NULL;
return;
}
pnv_ioda_setup_same_PE(bus, pe);
list_add_tail(&pe->list, &phb->ioda.pe_list);
if (pe->dma_weight != 0) {
phb->ioda.dma_weight += pe->dma_weight;
phb->ioda.dma_pe_count++;
}
pnv_ioda_link_pe_by_weight(phb, pe);
}
static void pnv_ioda_setup_PEs(struct pci_bus *bus)
{
struct pci_dev *dev;
pnv_ioda_setup_bus_PE(bus, 0);
list_for_each_entry(dev, &bus->devices, bus_list) {
if (dev->subordinate) {
if (pci_pcie_type(dev) == PCI_EXP_TYPE_PCI_BRIDGE)
pnv_ioda_setup_bus_PE(dev->subordinate, 1);
else
pnv_ioda_setup_PEs(dev->subordinate);
}
}
}
static void pnv_pci_ioda_setup_PEs(void)
{
struct pci_controller *hose, *tmp;
list_for_each_entry_safe(hose, tmp, &hose_list, list_node) {
pnv_ioda_setup_PEs(hose->bus);
}
}
static void pnv_pci_ioda_dma_dev_setup(struct pnv_phb *phb, struct pci_dev *dev)
{
}
static void pnv_ioda_setup_bus_dma(struct pnv_ioda_pe *pe, struct pci_bus *bus)
{
struct pci_dev *dev;
list_for_each_entry(dev, &bus->devices, bus_list) {
set_iommu_table_base(&dev->dev, &pe->tce32_table);
if (dev->subordinate)
pnv_ioda_setup_bus_dma(pe, dev->subordinate);
}
}
static void pnv_pci_ioda_setup_dma_pe(struct pnv_phb *phb,
struct pnv_ioda_pe *pe, unsigned int base,
unsigned int segs)
{
struct page *tce_mem = NULL;
const __be64 *swinvp;
struct iommu_table *tbl;
unsigned int i;
int64_t rc;
void *addr;
#define TCE32_TABLE_SIZE ((0x10000000 / 0x1000) * 8)
if (WARN_ON(pe->tce32_seg >= 0))
return;
pe->tce32_seg = base;
pe_info(pe, " Setting up 32-bit TCE table at %08x..%08x\n",
(base << 28), ((base + segs) << 28) - 1);
tce_mem = alloc_pages_node(phb->hose->node, GFP_KERNEL,
get_order(TCE32_TABLE_SIZE * segs));
if (!tce_mem) {
pe_err(pe, " Failed to allocate a 32-bit TCE memory\n");
goto fail;
}
addr = page_address(tce_mem);
memset(addr, 0, TCE32_TABLE_SIZE * segs);
for (i = 0; i < segs; i++) {
rc = opal_pci_map_pe_dma_window(phb->opal_id,
pe->pe_number,
base + i, 1,
__pa(addr) + TCE32_TABLE_SIZE * i,
TCE32_TABLE_SIZE, 0x1000);
if (rc) {
pe_err(pe, " Failed to configure 32-bit TCE table,"
" err %ld\n", rc);
goto fail;
}
}
tbl = &pe->tce32_table;
pnv_pci_setup_iommu_table(tbl, addr, TCE32_TABLE_SIZE * segs,
base << 28);
swinvp = of_get_property(phb->hose->dn, "ibm,opal-tce-kill", NULL);
if (swinvp) {
tbl->it_busno = 0;
tbl->it_index = (unsigned long)ioremap(be64_to_cpup(swinvp), 8);
tbl->it_type = TCE_PCI_SWINV_CREATE | TCE_PCI_SWINV_FREE
| TCE_PCI_SWINV_PAIR;
}
iommu_init_table(tbl, phb->hose->node);
if (pe->pdev)
set_iommu_table_base(&pe->pdev->dev, tbl);
else
pnv_ioda_setup_bus_dma(pe, pe->pbus);
return;
fail:
if (pe->tce32_seg >= 0)
pe->tce32_seg = -1;
if (tce_mem)
__free_pages(tce_mem, get_order(TCE32_TABLE_SIZE * segs));
}
static void pnv_ioda_setup_dma(struct pnv_phb *phb)
{
struct pci_controller *hose = phb->hose;
unsigned int residual, remaining, segs, tw, base;
struct pnv_ioda_pe *pe;
if (phb->ioda.dma_pe_count > phb->ioda.tce32_count)
residual = 0;
else
residual = phb->ioda.tce32_count -
phb->ioda.dma_pe_count;
pr_info("PCI: Domain %04x has %ld available 32-bit DMA segments\n",
hose->global_number, phb->ioda.tce32_count);
pr_info("PCI: %d PE# for a total weight of %d\n",
phb->ioda.dma_pe_count, phb->ioda.dma_weight);
remaining = phb->ioda.tce32_count;
tw = phb->ioda.dma_weight;
base = 0;
list_for_each_entry(pe, &phb->ioda.pe_dma_list, dma_link) {
if (!pe->dma_weight)
continue;
if (!remaining) {
pe_warn(pe, "No DMA32 resources available\n");
continue;
}
segs = 1;
if (residual) {
segs += ((pe->dma_weight * residual) + (tw / 2)) / tw;
if (segs > remaining)
segs = remaining;
}
pe_info(pe, "DMA weight %d, assigned %d DMA32 segments\n",
pe->dma_weight, segs);
pnv_pci_ioda_setup_dma_pe(phb, pe, base, segs);
remaining -= segs;
base += segs;
}
}
static int pnv_pci_ioda_msi_setup(struct pnv_phb *phb, struct pci_dev *dev,
unsigned int hwirq, unsigned int is_64,
struct msi_msg *msg)
{
struct pnv_ioda_pe *pe = pnv_ioda_get_pe(dev);
unsigned int xive_num = hwirq - phb->msi_base;
uint64_t addr64;
uint32_t addr32, data;
int rc;
if (pe == NULL)
return -ENXIO;
if (pe->mve_number < 0)
return -ENXIO;
rc = opal_pci_set_xive_pe(phb->opal_id, pe->pe_number, xive_num);
if (rc) {
pr_warn("%s: OPAL error %d setting XIVE %d PE\n",
pci_name(dev), rc, xive_num);
return -EIO;
}
if (is_64) {
rc = opal_get_msi_64(phb->opal_id, pe->mve_number, xive_num, 1,
&addr64, &data);
if (rc) {
pr_warn("%s: OPAL error %d getting 64-bit MSI data\n",
pci_name(dev), rc);
return -EIO;
}
msg->address_hi = addr64 >> 32;
msg->address_lo = addr64 & 0xfffffffful;
} else {
rc = opal_get_msi_32(phb->opal_id, pe->mve_number, xive_num, 1,
&addr32, &data);
if (rc) {
pr_warn("%s: OPAL error %d getting 32-bit MSI data\n",
pci_name(dev), rc);
return -EIO;
}
msg->address_hi = 0;
msg->address_lo = addr32;
}
msg->data = data;
pr_devel("%s: %s-bit MSI on hwirq %x (xive #%d),"
" address=%x_%08x data=%x PE# %d\n",
pci_name(dev), is_64 ? "64" : "32", hwirq, xive_num,
msg->address_hi, msg->address_lo, data, pe->pe_number);
return 0;
}
static void pnv_pci_init_ioda_msis(struct pnv_phb *phb)
{
unsigned int bmap_size;
const __be32 *prop = of_get_property(phb->hose->dn,
"ibm,opal-msi-ranges", NULL);
if (!prop) {
prop = of_get_property(phb->hose->dn, "msi-ranges", NULL);
}
if (!prop)
return;
phb->msi_base = be32_to_cpup(prop);
phb->msi_count = be32_to_cpup(prop + 1);
bmap_size = BITS_TO_LONGS(phb->msi_count) * sizeof(unsigned long);
phb->msi_map = zalloc_maybe_bootmem(bmap_size, GFP_KERNEL);
if (!phb->msi_map) {
pr_err("PCI %d: Failed to allocate MSI bitmap !\n",
phb->hose->global_number);
return;
}
phb->msi_setup = pnv_pci_ioda_msi_setup;
phb->msi32_support = 1;
pr_info(" Allocated bitmap for %d MSIs (base IRQ 0x%x)\n",
phb->msi_count, phb->msi_base);
}
static void pnv_pci_init_ioda_msis(struct pnv_phb *phb) { }
static void pnv_ioda_setup_pe_seg(struct pci_controller *hose,
struct pnv_ioda_pe *pe)
{
struct pnv_phb *phb = hose->private_data;
struct pci_bus_region region;
struct resource *res;
int i, index;
int rc;
BUG_ON(!(pe->flags & (PNV_IODA_PE_BUS | PNV_IODA_PE_BUS_ALL)));
pci_bus_for_each_resource(pe->pbus, res, i) {
if (!res || !res->flags ||
res->start > res->end)
continue;
if (res->flags & IORESOURCE_IO) {
region.start = res->start - phb->ioda.io_pci_base;
region.end = res->end - phb->ioda.io_pci_base;
index = region.start / phb->ioda.io_segsize;
while (index < phb->ioda.total_pe &&
region.start <= region.end) {
phb->ioda.io_segmap[index] = pe->pe_number;
rc = opal_pci_map_pe_mmio_window(phb->opal_id,
pe->pe_number, OPAL_IO_WINDOW_TYPE, 0, index);
if (rc != OPAL_SUCCESS) {
pr_err("%s: OPAL error %d when mapping IO "
"segment #%d to PE#%d\n",
__func__, rc, index, pe->pe_number);
break;
}
region.start += phb->ioda.io_segsize;
index++;
}
} else if (res->flags & IORESOURCE_MEM) {
region.start = res->start -
hose->pci_mem_offset -
phb->ioda.m32_pci_base;
region.end = res->end -
hose->pci_mem_offset -
phb->ioda.m32_pci_base;
index = region.start / phb->ioda.m32_segsize;
while (index < phb->ioda.total_pe &&
region.start <= region.end) {
phb->ioda.m32_segmap[index] = pe->pe_number;
rc = opal_pci_map_pe_mmio_window(phb->opal_id,
pe->pe_number, OPAL_M32_WINDOW_TYPE, 0, index);
if (rc != OPAL_SUCCESS) {
pr_err("%s: OPAL error %d when mapping M32 "
"segment#%d to PE#%d",
__func__, rc, index, pe->pe_number);
break;
}
region.start += phb->ioda.m32_segsize;
index++;
}
}
}
}
static void pnv_pci_ioda_setup_seg(void)
{
struct pci_controller *tmp, *hose;
struct pnv_phb *phb;
struct pnv_ioda_pe *pe;
list_for_each_entry_safe(hose, tmp, &hose_list, list_node) {
phb = hose->private_data;
list_for_each_entry(pe, &phb->ioda.pe_list, list) {
pnv_ioda_setup_pe_seg(hose, pe);
}
}
}
static void pnv_pci_ioda_setup_DMA(void)
{
struct pci_controller *hose, *tmp;
struct pnv_phb *phb;
list_for_each_entry_safe(hose, tmp, &hose_list, list_node) {
pnv_ioda_setup_dma(hose->private_data);
phb = hose->private_data;
phb->initialized = 1;
}
}
static void pnv_pci_ioda_fixup(void)
{
pnv_pci_ioda_setup_PEs();
pnv_pci_ioda_setup_seg();
pnv_pci_ioda_setup_DMA();
}
static resource_size_t pnv_pci_window_alignment(struct pci_bus *bus,
unsigned long type)
{
struct pci_dev *bridge;
struct pci_controller *hose = pci_bus_to_host(bus);
struct pnv_phb *phb = hose->private_data;
int num_pci_bridges = 0;
bridge = bus->self;
while (bridge) {
if (pci_pcie_type(bridge) == PCI_EXP_TYPE_PCI_BRIDGE) {
num_pci_bridges++;
if (num_pci_bridges >= 2)
return 1;
}
bridge = bridge->bus->self;
}
if (type & IORESOURCE_MEM)
return phb->ioda.m32_segsize;
return phb->ioda.io_segsize;
}
static int pnv_pci_enable_device_hook(struct pci_dev *dev)
{
struct pci_controller *hose = pci_bus_to_host(dev->bus);
struct pnv_phb *phb = hose->private_data;
struct pci_dn *pdn;
if (!phb->initialized)
return 0;
pdn = pnv_ioda_get_pdn(dev);
if (!pdn || pdn->pe_number == IODA_INVALID_PE)
return -EINVAL;
return 0;
}
static u32 pnv_ioda_bdfn_to_pe(struct pnv_phb *phb, struct pci_bus *bus,
u32 devfn)
{
return phb->ioda.pe_rmap[(bus->number << 8) | devfn];
}
void __init pnv_pci_init_ioda1_phb(struct device_node *np)
{
struct pci_controller *hose;
static int primary = 1;
struct pnv_phb *phb;
unsigned long size, m32map_off, iomap_off, pemap_off;
const u64 *prop64;
u64 phb_id;
void *aux;
long rc;
pr_info(" Initializing IODA OPAL PHB %s\n", np->full_name);
prop64 = of_get_property(np, "ibm,opal-phbid", NULL);
if (!prop64) {
pr_err(" Missing \"ibm,opal-phbid\" property !\n");
return;
}
phb_id = be64_to_cpup(prop64);
pr_debug(" PHB-ID : 0x%016llx\n", phb_id);
phb = alloc_bootmem(sizeof(struct pnv_phb));
if (phb) {
memset(phb, 0, sizeof(struct pnv_phb));
phb->hose = hose = pcibios_alloc_controller(np);
}
if (!phb || !phb->hose) {
pr_err("PCI: Failed to allocate PCI controller for %s\n",
np->full_name);
return;
}
spin_lock_init(&phb->lock);
hose->first_busno = 0;
hose->last_busno = 0xff;
hose->private_data = phb;
phb->opal_id = phb_id;
phb->type = PNV_PHB_IODA1;
if (of_device_is_compatible(np, "ibm,p7ioc-pciex"))
phb->model = PNV_PHB_MODEL_P7IOC;
else
phb->model = PNV_PHB_MODEL_UNKNOWN;
pci_process_bridge_OF_ranges(phb->hose, np, primary);
primary = 0;
phb->regs = of_iomap(np, 0);
if (phb->regs == NULL)
pr_err(" Failed to map registers !\n");
phb->ioda.total_pe = 128;
phb->ioda.m32_size = resource_size(&hose->mem_resources[0]);
phb->ioda.m32_size += 0x10000;
phb->ioda.m32_segsize = phb->ioda.m32_size / phb->ioda.total_pe;
phb->ioda.m32_pci_base = hose->mem_resources[0].start -
hose->pci_mem_offset;
phb->ioda.io_size = hose->pci_io_size;
phb->ioda.io_segsize = phb->ioda.io_size / phb->ioda.total_pe;
phb->ioda.io_pci_base = 0;
size = _ALIGN_UP(phb->ioda.total_pe / 8, sizeof(unsigned long));
m32map_off = size;
size += phb->ioda.total_pe * sizeof(phb->ioda.m32_segmap[0]);
iomap_off = size;
size += phb->ioda.total_pe * sizeof(phb->ioda.io_segmap[0]);
pemap_off = size;
size += phb->ioda.total_pe * sizeof(struct pnv_ioda_pe);
aux = alloc_bootmem(size);
memset(aux, 0, size);
phb->ioda.pe_alloc = aux;
phb->ioda.m32_segmap = aux + m32map_off;
phb->ioda.io_segmap = aux + iomap_off;
phb->ioda.pe_array = aux + pemap_off;
set_bit(0, phb->ioda.pe_alloc);
INIT_LIST_HEAD(&phb->ioda.pe_dma_list);
INIT_LIST_HEAD(&phb->ioda.pe_list);
phb->ioda.tce32_count = phb->ioda.m32_pci_base >> 28;
hose->mem_resources[1].flags = 0;
hose->mem_resources[1].start = 0;
hose->mem_resources[1].end = 0;
hose->mem_resources[2].flags = 0;
hose->mem_resources[2].start = 0;
hose->mem_resources[2].end = 0;
#if 0
rc = opal_pci_set_phb_mem_window(opal->phb_id,
window_type,
window_num,
starting_real_address,
starting_pci_address,
segment_size);
#endif
pr_info(" %d PE's M32: 0x%x [segment=0x%x] IO: 0x%x [segment=0x%x]\n",
phb->ioda.total_pe,
phb->ioda.m32_size, phb->ioda.m32_segsize,
phb->ioda.io_size, phb->ioda.io_segsize);
if (phb->regs) {
pr_devel(" BUID = 0x%016llx\n", in_be64(phb->regs + 0x100));
pr_devel(" PHB2_CR = 0x%016llx\n", in_be64(phb->regs + 0x160));
pr_devel(" IO_BAR = 0x%016llx\n", in_be64(phb->regs + 0x170));
pr_devel(" IO_BAMR = 0x%016llx\n", in_be64(phb->regs + 0x178));
pr_devel(" IO_SAR = 0x%016llx\n", in_be64(phb->regs + 0x180));
pr_devel(" M32_BAR = 0x%016llx\n", in_be64(phb->regs + 0x190));
pr_devel(" M32_BAMR = 0x%016llx\n", in_be64(phb->regs + 0x198));
pr_devel(" M32_SAR = 0x%016llx\n", in_be64(phb->regs + 0x1a0));
}
phb->hose->ops = &pnv_pci_ops;
phb->bdfn_to_pe = pnv_ioda_bdfn_to_pe;
phb->dma_dev_setup = pnv_pci_ioda_dma_dev_setup;
pnv_pci_init_ioda_msis(phb);
ppc_md.pcibios_fixup = pnv_pci_ioda_fixup;
ppc_md.pcibios_enable_device_hook = pnv_pci_enable_device_hook;
ppc_md.pcibios_window_alignment = pnv_pci_window_alignment;
pci_add_flags(PCI_REASSIGN_ALL_RSRC);
rc = opal_pci_reset(phb_id, OPAL_PCI_IODA_TABLE_RESET, OPAL_ASSERT_RESET);
if (rc)
pr_warning(" OPAL Error %ld performing IODA table reset !\n", rc);
opal_pci_set_pe(phb_id, 0, 0, 7, 1, 1 , OPAL_MAP_PE);
}
void __init pnv_pci_init_ioda_hub(struct device_node *np)
{
struct device_node *phbn;
const u64 *prop64;
u64 hub_id;
pr_info("Probing IODA IO-Hub %s\n", np->full_name);
prop64 = of_get_property(np, "ibm,opal-hubid", NULL);
if (!prop64) {
pr_err(" Missing \"ibm,opal-hubid\" property !\n");
return;
}
hub_id = be64_to_cpup(prop64);
pr_devel(" HUB-ID : 0x%016llx\n", hub_id);
for_each_child_of_node(np, phbn) {
if (of_device_is_compatible(phbn, "ibm,ioda-phb"))
pnv_pci_init_ioda1_phb(phbn);
}
}
