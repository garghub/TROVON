static void pe_level_printk(const struct pnv_ioda_pe *pe, const char *level,
const char *fmt, ...)
{
struct va_format vaf;
va_list args;
char pfix[32];
va_start(args, fmt);
vaf.fmt = fmt;
vaf.va = &args;
if (pe->pdev)
strlcpy(pfix, dev_name(&pe->pdev->dev), sizeof(pfix));
else
sprintf(pfix, "%04x:%02x ",
pci_domain_nr(pe->pbus), pe->pbus->number);
printk("%spci %s: [PE# %.3d] %pV",
level, pfix, pe->pe_number, &vaf);
va_end(args);
}
static inline void __raw_rm_writeq(u64 val, volatile void __iomem *paddr)
{
__asm__ __volatile__("stdcix %0,0,%1"
: : "r" (val), "r" (paddr) : "memory");
}
static inline bool pnv_pci_is_mem_pref_64(unsigned long flags)
{
return ((flags & (IORESOURCE_MEM_64 | IORESOURCE_PREFETCH)) ==
(IORESOURCE_MEM_64 | IORESOURCE_PREFETCH));
}
static void pnv_ioda_reserve_pe(struct pnv_phb *phb, int pe_no)
{
if (!(pe_no >= 0 && pe_no < phb->ioda.total_pe)) {
pr_warn("%s: Invalid PE %d on PHB#%x\n",
__func__, pe_no, phb->hose->global_number);
return;
}
if (test_and_set_bit(pe_no, phb->ioda.pe_alloc)) {
pr_warn("%s: PE %d was assigned on PHB#%x\n",
__func__, pe_no, phb->hose->global_number);
return;
}
phb->ioda.pe_array[pe_no].phb = phb;
phb->ioda.pe_array[pe_no].pe_number = pe_no;
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
phb->ioda.pe_array[pe].phb = phb;
phb->ioda.pe_array[pe].pe_number = pe;
return pe;
}
static void pnv_ioda_free_pe(struct pnv_phb *phb, int pe)
{
WARN_ON(phb->ioda.pe_array[pe].pdev);
memset(&phb->ioda.pe_array[pe], 0, sizeof(struct pnv_ioda_pe));
clear_bit(pe, phb->ioda.pe_alloc);
}
static int pnv_ioda2_init_m64(struct pnv_phb *phb)
{
const char *desc;
struct resource *r;
s64 rc;
rc = opal_pci_set_phb_mem_window(phb->opal_id,
OPAL_M64_WINDOW_TYPE,
phb->ioda.m64_bar_idx,
phb->ioda.m64_base,
0,
phb->ioda.m64_size);
if (rc != OPAL_SUCCESS) {
desc = "configuring";
goto fail;
}
rc = opal_pci_phb_mmio_enable(phb->opal_id,
OPAL_M64_WINDOW_TYPE,
phb->ioda.m64_bar_idx,
OPAL_ENABLE_M64_SPLIT);
if (rc != OPAL_SUCCESS) {
desc = "enabling";
goto fail;
}
set_bit(phb->ioda.m64_bar_idx, &phb->ioda.m64_bar_alloc);
r = &phb->hose->mem_resources[1];
if (phb->ioda.reserved_pe == 0)
r->start += phb->ioda.m64_segsize;
else if (phb->ioda.reserved_pe == (phb->ioda.total_pe - 1))
r->end -= phb->ioda.m64_segsize;
else
pr_warn(" Cannot strip M64 segment for reserved PE#%d\n",
phb->ioda.reserved_pe);
return 0;
fail:
pr_warn(" Failure %lld %s M64 BAR#%d\n",
rc, desc, phb->ioda.m64_bar_idx);
opal_pci_phb_mmio_enable(phb->opal_id,
OPAL_M64_WINDOW_TYPE,
phb->ioda.m64_bar_idx,
OPAL_DISABLE_M64);
return -EIO;
}
static void pnv_ioda2_reserve_m64_pe(struct pnv_phb *phb)
{
resource_size_t sgsz = phb->ioda.m64_segsize;
struct pci_dev *pdev;
struct resource *r;
int base, step, i;
list_for_each_entry(pdev, &phb->hose->bus->devices, bus_list) {
for (i = 0; i < PCI_BRIDGE_RESOURCE_NUM; i++) {
r = &pdev->resource[PCI_BRIDGE_RESOURCES + i];
if (!r->parent ||
!pnv_pci_is_mem_pref_64(r->flags))
continue;
base = (r->start - phb->ioda.m64_base) / sgsz;
for (step = 0; step < resource_size(r) / sgsz; step++)
pnv_ioda_reserve_pe(phb, base + step);
}
}
}
static int pnv_ioda2_pick_m64_pe(struct pnv_phb *phb,
struct pci_bus *bus, int all)
{
resource_size_t segsz = phb->ioda.m64_segsize;
struct pci_dev *pdev;
struct resource *r;
struct pnv_ioda_pe *master_pe, *pe;
unsigned long size, *pe_alloc;
bool found;
int start, i, j;
if (pci_is_root_bus(bus))
return IODA_INVALID_PE;
found = false;
pci_bus_for_each_resource(bus, r, i) {
if (r && r->parent &&
pnv_pci_is_mem_pref_64(r->flags)) {
found = true;
break;
}
}
if (!found)
return IODA_INVALID_PE;
size = _ALIGN_UP(phb->ioda.total_pe / 8, sizeof(unsigned long));
pe_alloc = kzalloc(size, GFP_KERNEL);
if (!pe_alloc) {
pr_warn("%s: Out of memory !\n",
__func__);
return IODA_INVALID_PE;
}
start = (r->start - phb->ioda.m64_base) / segsz;
for (i = 0; i < resource_size(r) / segsz; i++)
set_bit(start + i, pe_alloc);
if (all)
goto done;
list_for_each_entry(pdev, &bus->devices, bus_list) {
if (!pdev->subordinate)
continue;
pci_bus_for_each_resource(pdev->subordinate, r, i) {
if (!r || !r->parent ||
!pnv_pci_is_mem_pref_64(r->flags))
continue;
start = (r->start - phb->ioda.m64_base) / segsz;
for (j = 0; j < resource_size(r) / segsz ; j++)
clear_bit(start + j, pe_alloc);
}
}
if (bitmap_empty(pe_alloc, phb->ioda.total_pe)) {
kfree(pe_alloc);
return IODA_INVALID_PE;
}
done:
master_pe = NULL;
i = -1;
while ((i = find_next_bit(pe_alloc, phb->ioda.total_pe, i + 1)) <
phb->ioda.total_pe) {
pe = &phb->ioda.pe_array[i];
if (!master_pe) {
pe->flags |= PNV_IODA_PE_MASTER;
INIT_LIST_HEAD(&pe->slaves);
master_pe = pe;
} else {
pe->flags |= PNV_IODA_PE_SLAVE;
pe->master = master_pe;
list_add_tail(&pe->list, &master_pe->slaves);
}
}
kfree(pe_alloc);
return master_pe->pe_number;
}
static void __init pnv_ioda_parse_m64_window(struct pnv_phb *phb)
{
struct pci_controller *hose = phb->hose;
struct device_node *dn = hose->dn;
struct resource *res;
const u32 *r;
u64 pci_addr;
if (phb->type != PNV_PHB_IODA2) {
pr_info(" Not support M64 window\n");
return;
}
if (!firmware_has_feature(FW_FEATURE_OPALv3)) {
pr_info(" Firmware too old to support M64 window\n");
return;
}
r = of_get_property(dn, "ibm,opal-m64-window", NULL);
if (!r) {
pr_info(" No <ibm,opal-m64-window> on %s\n",
dn->full_name);
return;
}
res = &hose->mem_resources[1];
res->start = of_translate_address(dn, r + 2);
res->end = res->start + of_read_number(r + 4, 2) - 1;
res->flags = (IORESOURCE_MEM | IORESOURCE_MEM_64 | IORESOURCE_PREFETCH);
pci_addr = of_read_number(r, 2);
hose->mem_offset[1] = res->start - pci_addr;
phb->ioda.m64_size = resource_size(res);
phb->ioda.m64_segsize = phb->ioda.m64_size / phb->ioda.total_pe;
phb->ioda.m64_base = pci_addr;
phb->ioda.m64_bar_idx = 15;
phb->init_m64 = pnv_ioda2_init_m64;
phb->reserve_m64_pe = pnv_ioda2_reserve_m64_pe;
phb->pick_m64_pe = pnv_ioda2_pick_m64_pe;
}
static void pnv_ioda_freeze_pe(struct pnv_phb *phb, int pe_no)
{
struct pnv_ioda_pe *pe = &phb->ioda.pe_array[pe_no];
struct pnv_ioda_pe *slave;
s64 rc;
if (pe->flags & PNV_IODA_PE_SLAVE) {
pe = pe->master;
if (WARN_ON(!pe || !(pe->flags & PNV_IODA_PE_MASTER)))
return;
pe_no = pe->pe_number;
}
rc = opal_pci_eeh_freeze_set(phb->opal_id,
pe_no,
OPAL_EEH_ACTION_SET_FREEZE_ALL);
if (rc != OPAL_SUCCESS) {
pr_warn("%s: Failure %lld freezing PHB#%x-PE#%x\n",
__func__, rc, phb->hose->global_number, pe_no);
return;
}
if (!(pe->flags & PNV_IODA_PE_MASTER))
return;
list_for_each_entry(slave, &pe->slaves, list) {
rc = opal_pci_eeh_freeze_set(phb->opal_id,
slave->pe_number,
OPAL_EEH_ACTION_SET_FREEZE_ALL);
if (rc != OPAL_SUCCESS)
pr_warn("%s: Failure %lld freezing PHB#%x-PE#%x\n",
__func__, rc, phb->hose->global_number,
slave->pe_number);
}
}
static int pnv_ioda_unfreeze_pe(struct pnv_phb *phb, int pe_no, int opt)
{
struct pnv_ioda_pe *pe, *slave;
s64 rc;
pe = &phb->ioda.pe_array[pe_no];
if (pe->flags & PNV_IODA_PE_SLAVE) {
pe = pe->master;
WARN_ON(!pe || !(pe->flags & PNV_IODA_PE_MASTER));
pe_no = pe->pe_number;
}
rc = opal_pci_eeh_freeze_clear(phb->opal_id, pe_no, opt);
if (rc != OPAL_SUCCESS) {
pr_warn("%s: Failure %lld clear %d on PHB#%x-PE#%x\n",
__func__, rc, opt, phb->hose->global_number, pe_no);
return -EIO;
}
if (!(pe->flags & PNV_IODA_PE_MASTER))
return 0;
list_for_each_entry(slave, &pe->slaves, list) {
rc = opal_pci_eeh_freeze_clear(phb->opal_id,
slave->pe_number,
opt);
if (rc != OPAL_SUCCESS) {
pr_warn("%s: Failure %lld clear %d on PHB#%x-PE#%x\n",
__func__, rc, opt, phb->hose->global_number,
slave->pe_number);
return -EIO;
}
}
return 0;
}
static int pnv_ioda_get_pe_state(struct pnv_phb *phb, int pe_no)
{
struct pnv_ioda_pe *slave, *pe;
u8 fstate, state;
__be16 pcierr;
s64 rc;
if (pe_no < 0 || pe_no >= phb->ioda.total_pe)
return OPAL_EEH_STOPPED_PERM_UNAVAIL;
pe = &phb->ioda.pe_array[pe_no];
if (pe->flags & PNV_IODA_PE_SLAVE) {
pe = pe->master;
WARN_ON(!pe || !(pe->flags & PNV_IODA_PE_MASTER));
pe_no = pe->pe_number;
}
rc = opal_pci_eeh_freeze_status(phb->opal_id, pe_no,
&state, &pcierr, NULL);
if (rc != OPAL_SUCCESS) {
pr_warn("%s: Failure %lld getting "
"PHB#%x-PE#%x state\n",
__func__, rc,
phb->hose->global_number, pe_no);
return OPAL_EEH_STOPPED_TEMP_UNAVAIL;
}
if (!(pe->flags & PNV_IODA_PE_MASTER))
return state;
list_for_each_entry(slave, &pe->slaves, list) {
rc = opal_pci_eeh_freeze_status(phb->opal_id,
slave->pe_number,
&fstate,
&pcierr,
NULL);
if (rc != OPAL_SUCCESS) {
pr_warn("%s: Failure %lld getting "
"PHB#%x-PE#%x state\n",
__func__, rc,
phb->hose->global_number, slave->pe_number);
return OPAL_EEH_STOPPED_TEMP_UNAVAIL;
}
if (fstate > state)
state = fstate;
}
return state;
}
static struct pnv_ioda_pe *pnv_ioda_get_pe(struct pci_dev *dev)
{
struct pci_controller *hose = pci_bus_to_host(dev->bus);
struct pnv_phb *phb = hose->private_data;
struct pci_dn *pdn = pci_get_pdn(dev);
if (!pdn)
return NULL;
if (pdn->pe_number == IODA_INVALID_PE)
return NULL;
return &phb->ioda.pe_array[pdn->pe_number];
}
static int pnv_ioda_set_one_peltv(struct pnv_phb *phb,
struct pnv_ioda_pe *parent,
struct pnv_ioda_pe *child,
bool is_add)
{
const char *desc = is_add ? "adding" : "removing";
uint8_t op = is_add ? OPAL_ADD_PE_TO_DOMAIN :
OPAL_REMOVE_PE_FROM_DOMAIN;
struct pnv_ioda_pe *slave;
long rc;
rc = opal_pci_set_peltv(phb->opal_id, parent->pe_number,
child->pe_number, op);
if (rc != OPAL_SUCCESS) {
pe_warn(child, "OPAL error %ld %s to parent PELTV\n",
rc, desc);
return -ENXIO;
}
if (!(child->flags & PNV_IODA_PE_MASTER))
return 0;
list_for_each_entry(slave, &child->slaves, list) {
rc = opal_pci_set_peltv(phb->opal_id, parent->pe_number,
slave->pe_number, op);
if (rc != OPAL_SUCCESS) {
pe_warn(slave, "OPAL error %ld %s to parent PELTV\n",
rc, desc);
return -ENXIO;
}
}
return 0;
}
static int pnv_ioda_set_peltv(struct pnv_phb *phb,
struct pnv_ioda_pe *pe,
bool is_add)
{
struct pnv_ioda_pe *slave;
struct pci_dev *pdev;
int ret;
if (is_add) {
opal_pci_eeh_freeze_clear(phb->opal_id, pe->pe_number,
OPAL_EEH_ACTION_CLEAR_FREEZE_ALL);
if (pe->flags & PNV_IODA_PE_MASTER) {
list_for_each_entry(slave, &pe->slaves, list)
opal_pci_eeh_freeze_clear(phb->opal_id,
slave->pe_number,
OPAL_EEH_ACTION_CLEAR_FREEZE_ALL);
}
}
ret = pnv_ioda_set_one_peltv(phb, pe, pe, is_add);
if (ret)
return ret;
if (pe->flags & PNV_IODA_PE_MASTER) {
list_for_each_entry(slave, &pe->slaves, list) {
ret = pnv_ioda_set_one_peltv(phb, slave, pe, is_add);
if (ret)
return ret;
}
}
if (pe->flags & (PNV_IODA_PE_BUS_ALL | PNV_IODA_PE_BUS))
pdev = pe->pbus->self;
else
pdev = pe->pdev->bus->self;
while (pdev) {
struct pci_dn *pdn = pci_get_pdn(pdev);
struct pnv_ioda_pe *parent;
if (pdn && pdn->pe_number != IODA_INVALID_PE) {
parent = &phb->ioda.pe_array[pdn->pe_number];
ret = pnv_ioda_set_one_peltv(phb, parent, pe, is_add);
if (ret)
return ret;
}
pdev = pdev->bus->self;
}
return 0;
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
pnv_ioda_set_peltv(phb, pe, true);
for (rid = pe->rid; rid < rid_end; rid++)
phb->ioda.pe_rmap[rid] = pe->pe_number;
if (phb->type != PNV_PHB_IODA1) {
pe->mve_number = 0;
goto out;
}
pe->mve_number = pe->pe_number;
rc = opal_pci_set_mve(phb->opal_id, pe->mve_number, pe->pe_number);
if (rc != OPAL_SUCCESS) {
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
out:
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
struct pci_dn *pdn = pci_get_pdn(dev);
if (pdn == NULL) {
pr_warn("%s: No device node associated with device !\n",
pci_name(dev));
continue;
}
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
int pe_num = IODA_INVALID_PE;
if (phb->pick_m64_pe)
pe_num = phb->pick_m64_pe(phb, bus, all);
if (pe_num == IODA_INVALID_PE)
pe_num = pnv_ioda_alloc_pe(phb);
if (pe_num == IODA_INVALID_PE) {
pr_warning("%s: Not enough PE# available for PCI bus %04x:%02x\n",
__func__, pci_domain_nr(bus), bus->number);
return;
}
pe = &phb->ioda.pe_array[pe_num];
pe->flags |= (all ? PNV_IODA_PE_BUS_ALL : PNV_IODA_PE_BUS);
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
struct pnv_phb *phb;
list_for_each_entry_safe(hose, tmp, &hose_list, list_node) {
phb = hose->private_data;
if (phb->reserve_m64_pe)
phb->reserve_m64_pe(phb);
pnv_ioda_setup_PEs(hose->bus);
}
}
static void pnv_pci_ioda_dma_dev_setup(struct pnv_phb *phb, struct pci_dev *pdev)
{
struct pci_dn *pdn = pci_get_pdn(pdev);
struct pnv_ioda_pe *pe;
if (!pdn || pdn->pe_number == IODA_INVALID_PE)
return;
pe = &phb->ioda.pe_array[pdn->pe_number];
WARN_ON(get_dma_ops(&pdev->dev) != &dma_iommu_ops);
set_iommu_table_base_and_group(&pdev->dev, &pe->tce32_table);
}
static int pnv_pci_ioda_dma_set_mask(struct pnv_phb *phb,
struct pci_dev *pdev, u64 dma_mask)
{
struct pci_dn *pdn = pci_get_pdn(pdev);
struct pnv_ioda_pe *pe;
uint64_t top;
bool bypass = false;
if (WARN_ON(!pdn || pdn->pe_number == IODA_INVALID_PE))
return -ENODEV;;
pe = &phb->ioda.pe_array[pdn->pe_number];
if (pe->tce_bypass_enabled) {
top = pe->tce_bypass_base + memblock_end_of_DRAM() - 1;
bypass = (dma_mask >= top);
}
if (bypass) {
dev_info(&pdev->dev, "Using 64-bit DMA iommu bypass\n");
set_dma_ops(&pdev->dev, &dma_direct_ops);
set_dma_offset(&pdev->dev, pe->tce_bypass_base);
} else {
dev_info(&pdev->dev, "Using 32-bit DMA via iommu\n");
set_dma_ops(&pdev->dev, &dma_iommu_ops);
set_iommu_table_base(&pdev->dev, &pe->tce32_table);
}
*pdev->dev.dma_mask = dma_mask;
return 0;
}
static u64 pnv_pci_ioda_dma_get_required_mask(struct pnv_phb *phb,
struct pci_dev *pdev)
{
struct pci_dn *pdn = pci_get_pdn(pdev);
struct pnv_ioda_pe *pe;
u64 end, mask;
if (WARN_ON(!pdn || pdn->pe_number == IODA_INVALID_PE))
return 0;
pe = &phb->ioda.pe_array[pdn->pe_number];
if (!pe->tce_bypass_enabled)
return __dma_get_required_mask(&pdev->dev);
end = pe->tce_bypass_base + memblock_end_of_DRAM();
mask = 1ULL << (fls64(end) - 1);
mask += mask - 1;
return mask;
}
static void pnv_ioda_setup_bus_dma(struct pnv_ioda_pe *pe,
struct pci_bus *bus,
bool add_to_iommu_group)
{
struct pci_dev *dev;
list_for_each_entry(dev, &bus->devices, bus_list) {
if (add_to_iommu_group)
set_iommu_table_base_and_group(&dev->dev,
&pe->tce32_table);
else
set_iommu_table_base(&dev->dev, &pe->tce32_table);
if (dev->subordinate)
pnv_ioda_setup_bus_dma(pe, dev->subordinate,
add_to_iommu_group);
}
}
static void pnv_pci_ioda1_tce_invalidate(struct pnv_ioda_pe *pe,
struct iommu_table *tbl,
__be64 *startp, __be64 *endp, bool rm)
{
__be64 __iomem *invalidate = rm ?
(__be64 __iomem *)pe->tce_inval_reg_phys :
(__be64 __iomem *)tbl->it_index;
unsigned long start, end, inc;
const unsigned shift = tbl->it_page_shift;
start = __pa(startp);
end = __pa(endp);
if (tbl->it_busno) {
start <<= shift;
end <<= shift;
inc = 128ull << shift;
start |= tbl->it_busno;
end |= tbl->it_busno;
} else if (tbl->it_type & TCE_PCI_SWINV_PAIR) {
start |= (1ull << 63);
end |= (1ull << 63);
inc = 16;
} else {
inc = 128;
}
end |= inc - 1;
mb();
while (start <= end) {
if (rm)
__raw_rm_writeq(cpu_to_be64(start), invalidate);
else
__raw_writeq(cpu_to_be64(start), invalidate);
start += inc;
}
}
static void pnv_pci_ioda2_tce_invalidate(struct pnv_ioda_pe *pe,
struct iommu_table *tbl,
__be64 *startp, __be64 *endp, bool rm)
{
unsigned long start, end, inc;
__be64 __iomem *invalidate = rm ?
(__be64 __iomem *)pe->tce_inval_reg_phys :
(__be64 __iomem *)tbl->it_index;
const unsigned shift = tbl->it_page_shift;
start = 0x2ull << 60;
start |= (pe->pe_number & 0xFF);
end = start;
inc = tbl->it_offset + (((u64)startp - tbl->it_base) / sizeof(u64));
start |= (inc << shift);
inc = tbl->it_offset + (((u64)endp - tbl->it_base) / sizeof(u64));
end |= (inc << shift);
inc = (0x1ull << shift);
mb();
while (start <= end) {
if (rm)
__raw_rm_writeq(cpu_to_be64(start), invalidate);
else
__raw_writeq(cpu_to_be64(start), invalidate);
start += inc;
}
}
void pnv_pci_ioda_tce_invalidate(struct iommu_table *tbl,
__be64 *startp, __be64 *endp, bool rm)
{
struct pnv_ioda_pe *pe = container_of(tbl, struct pnv_ioda_pe,
tce32_table);
struct pnv_phb *phb = pe->phb;
if (phb->type == PNV_PHB_IODA1)
pnv_pci_ioda1_tce_invalidate(pe, tbl, startp, endp, rm);
else
pnv_pci_ioda2_tce_invalidate(pe, tbl, startp, endp, rm);
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
base << 28, IOMMU_PAGE_SHIFT_4K);
swinvp = of_get_property(phb->hose->dn, "ibm,opal-tce-kill", NULL);
if (swinvp) {
pe->tce_inval_reg_phys = be64_to_cpup(swinvp);
tbl->it_index = (unsigned long)ioremap(pe->tce_inval_reg_phys,
8);
tbl->it_type |= (TCE_PCI_SWINV_CREATE |
TCE_PCI_SWINV_FREE |
TCE_PCI_SWINV_PAIR);
}
iommu_init_table(tbl, phb->hose->node);
iommu_register_group(tbl, phb->hose->global_number, pe->pe_number);
if (pe->pdev)
set_iommu_table_base_and_group(&pe->pdev->dev, tbl);
else
pnv_ioda_setup_bus_dma(pe, pe->pbus, true);
return;
fail:
if (pe->tce32_seg >= 0)
pe->tce32_seg = -1;
if (tce_mem)
__free_pages(tce_mem, get_order(TCE32_TABLE_SIZE * segs));
}
static void pnv_pci_ioda2_set_bypass(struct iommu_table *tbl, bool enable)
{
struct pnv_ioda_pe *pe = container_of(tbl, struct pnv_ioda_pe,
tce32_table);
uint16_t window_id = (pe->pe_number << 1 ) + 1;
int64_t rc;
pe_info(pe, "%sabling 64-bit DMA bypass\n", enable ? "En" : "Dis");
if (enable) {
phys_addr_t top = memblock_end_of_DRAM();
top = roundup_pow_of_two(top);
rc = opal_pci_map_pe_dma_window_real(pe->phb->opal_id,
pe->pe_number,
window_id,
pe->tce_bypass_base,
top);
} else {
rc = opal_pci_map_pe_dma_window_real(pe->phb->opal_id,
pe->pe_number,
window_id,
pe->tce_bypass_base,
0);
if (pe->pdev)
set_iommu_table_base(&pe->pdev->dev, tbl);
else
pnv_ioda_setup_bus_dma(pe, pe->pbus, false);
}
if (rc)
pe_err(pe, "OPAL error %lld configuring bypass window\n", rc);
else
pe->tce_bypass_enabled = enable;
}
static void pnv_pci_ioda2_setup_bypass_pe(struct pnv_phb *phb,
struct pnv_ioda_pe *pe)
{
pe->tce_bypass_base = 1ull << 59;
pe->tce32_table.set_bypass = pnv_pci_ioda2_set_bypass;
pnv_pci_ioda2_set_bypass(&pe->tce32_table, true);
}
static void pnv_pci_ioda2_setup_dma_pe(struct pnv_phb *phb,
struct pnv_ioda_pe *pe)
{
struct page *tce_mem = NULL;
void *addr;
const __be64 *swinvp;
struct iommu_table *tbl;
unsigned int tce_table_size, end;
int64_t rc;
if (WARN_ON(pe->tce32_seg >= 0))
return;
pe->tce32_seg = 0;
end = (1 << ilog2(phb->ioda.m32_pci_base));
tce_table_size = (end / 0x1000) * 8;
pe_info(pe, "Setting up 32-bit TCE table at 0..%08x\n",
end);
tce_mem = alloc_pages_node(phb->hose->node, GFP_KERNEL,
get_order(tce_table_size));
if (!tce_mem) {
pe_err(pe, "Failed to allocate a 32-bit TCE memory\n");
goto fail;
}
addr = page_address(tce_mem);
memset(addr, 0, tce_table_size);
rc = opal_pci_map_pe_dma_window(phb->opal_id, pe->pe_number,
pe->pe_number << 1, 1, __pa(addr),
tce_table_size, 0x1000);
if (rc) {
pe_err(pe, "Failed to configure 32-bit TCE table,"
" err %ld\n", rc);
goto fail;
}
tbl = &pe->tce32_table;
pnv_pci_setup_iommu_table(tbl, addr, tce_table_size, 0,
IOMMU_PAGE_SHIFT_4K);
swinvp = of_get_property(phb->hose->dn, "ibm,opal-tce-kill", NULL);
if (swinvp) {
pe->tce_inval_reg_phys = be64_to_cpup(swinvp);
tbl->it_index = (unsigned long)ioremap(pe->tce_inval_reg_phys,
8);
tbl->it_type |= (TCE_PCI_SWINV_CREATE | TCE_PCI_SWINV_FREE);
}
iommu_init_table(tbl, phb->hose->node);
iommu_register_group(tbl, phb->hose->global_number, pe->pe_number);
if (pe->pdev)
set_iommu_table_base_and_group(&pe->pdev->dev, tbl);
else
pnv_ioda_setup_bus_dma(pe, pe->pbus, true);
pnv_pci_ioda2_setup_bypass_pe(phb, pe);
return;
fail:
if (pe->tce32_seg >= 0)
pe->tce32_seg = -1;
if (tce_mem)
__free_pages(tce_mem, get_order(tce_table_size));
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
if (phb->type == PNV_PHB_IODA1) {
pe_info(pe, "DMA weight %d, assigned %d DMA32 segments\n",
pe->dma_weight, segs);
pnv_pci_ioda_setup_dma_pe(phb, pe, base, segs);
} else {
pe_info(pe, "Assign DMA32 space\n");
segs = 0;
pnv_pci_ioda2_setup_dma_pe(phb, pe);
}
remaining -= segs;
base += segs;
}
}
static void pnv_ioda2_msi_eoi(struct irq_data *d)
{
unsigned int hw_irq = (unsigned int)irqd_to_hwirq(d);
struct irq_chip *chip = irq_data_get_irq_chip(d);
struct pnv_phb *phb = container_of(chip, struct pnv_phb,
ioda.irq_chip);
int64_t rc;
rc = opal_pci_msi_eoi(phb->opal_id, hw_irq);
WARN_ON_ONCE(rc);
icp_native_eoi(d);
}
static void set_msi_irq_chip(struct pnv_phb *phb, unsigned int virq)
{
struct irq_data *idata;
struct irq_chip *ichip;
if (phb->type != PNV_PHB_IODA2)
return;
if (!phb->ioda.irq_chip_init) {
idata = irq_get_irq_data(virq);
ichip = irq_data_get_irq_chip(idata);
phb->ioda.irq_chip_init = 1;
phb->ioda.irq_chip = *ichip;
phb->ioda.irq_chip.irq_eoi = pnv_ioda2_msi_eoi;
}
irq_set_chip(virq, &phb->ioda.irq_chip);
}
struct device_node *pnv_pci_to_phb_node(struct pci_dev *dev)
{
struct pci_controller *hose = pci_bus_to_host(dev->bus);
return hose->dn;
}
int pnv_phb_to_cxl(struct pci_dev *dev)
{
struct pci_controller *hose = pci_bus_to_host(dev->bus);
struct pnv_phb *phb = hose->private_data;
struct pnv_ioda_pe *pe;
int rc;
pe = pnv_ioda_get_pe(dev);
if (!pe)
return -ENODEV;
pe_info(pe, "Switching PHB to CXL\n");
rc = opal_pci_set_phb_cxl_mode(phb->opal_id, 1, pe->pe_number);
if (rc)
dev_err(&dev->dev, "opal_pci_set_phb_cxl_mode failed: %i\n", rc);
return rc;
}
int pnv_cxl_alloc_hwirqs(struct pci_dev *dev, int num)
{
struct pci_controller *hose = pci_bus_to_host(dev->bus);
struct pnv_phb *phb = hose->private_data;
int hwirq = msi_bitmap_alloc_hwirqs(&phb->msi_bmp, num);
if (hwirq < 0) {
dev_warn(&dev->dev, "Failed to find a free MSI\n");
return -ENOSPC;
}
return phb->msi_base + hwirq;
}
void pnv_cxl_release_hwirqs(struct pci_dev *dev, int hwirq, int num)
{
struct pci_controller *hose = pci_bus_to_host(dev->bus);
struct pnv_phb *phb = hose->private_data;
msi_bitmap_free_hwirqs(&phb->msi_bmp, hwirq - phb->msi_base, num);
}
void pnv_cxl_release_hwirq_ranges(struct cxl_irq_ranges *irqs,
struct pci_dev *dev)
{
struct pci_controller *hose = pci_bus_to_host(dev->bus);
struct pnv_phb *phb = hose->private_data;
int i, hwirq;
for (i = 1; i < CXL_IRQ_RANGES; i++) {
if (!irqs->range[i])
continue;
pr_devel("cxl release irq range 0x%x: offset: 0x%lx limit: %ld\n",
i, irqs->offset[i],
irqs->range[i]);
hwirq = irqs->offset[i] - phb->msi_base;
msi_bitmap_free_hwirqs(&phb->msi_bmp, hwirq,
irqs->range[i]);
}
}
int pnv_cxl_alloc_hwirq_ranges(struct cxl_irq_ranges *irqs,
struct pci_dev *dev, int num)
{
struct pci_controller *hose = pci_bus_to_host(dev->bus);
struct pnv_phb *phb = hose->private_data;
int i, hwirq, try;
memset(irqs, 0, sizeof(struct cxl_irq_ranges));
for (i = 1; i < CXL_IRQ_RANGES && num; i++) {
try = num;
while (try) {
hwirq = msi_bitmap_alloc_hwirqs(&phb->msi_bmp, try);
if (hwirq >= 0)
break;
try /= 2;
}
if (!try)
goto fail;
irqs->offset[i] = phb->msi_base + hwirq;
irqs->range[i] = try;
pr_devel("cxl alloc irq range 0x%x: offset: 0x%lx limit: %li\n",
i, irqs->offset[i], irqs->range[i]);
num -= try;
}
if (num)
goto fail;
return 0;
fail:
pnv_cxl_release_hwirq_ranges(irqs, dev);
return -ENOSPC;
}
int pnv_cxl_get_irq_count(struct pci_dev *dev)
{
struct pci_controller *hose = pci_bus_to_host(dev->bus);
struct pnv_phb *phb = hose->private_data;
return phb->msi_bmp.irq_count;
}
int pnv_cxl_ioda_msi_setup(struct pci_dev *dev, unsigned int hwirq,
unsigned int virq)
{
struct pci_controller *hose = pci_bus_to_host(dev->bus);
struct pnv_phb *phb = hose->private_data;
unsigned int xive_num = hwirq - phb->msi_base;
struct pnv_ioda_pe *pe;
int rc;
if (!(pe = pnv_ioda_get_pe(dev)))
return -ENODEV;
rc = opal_pci_set_xive_pe(phb->opal_id, pe->pe_number, xive_num);
if (rc) {
pe_warn(pe, "%s: OPAL error %d setting msi_base 0x%x "
"hwirq 0x%x XIVE 0x%x PE\n",
pci_name(dev), rc, phb->msi_base, hwirq, xive_num);
return -EIO;
}
set_msi_irq_chip(phb, virq);
return 0;
}
static int pnv_pci_ioda_msi_setup(struct pnv_phb *phb, struct pci_dev *dev,
unsigned int hwirq, unsigned int virq,
unsigned int is_64, struct msi_msg *msg)
{
struct pnv_ioda_pe *pe = pnv_ioda_get_pe(dev);
unsigned int xive_num = hwirq - phb->msi_base;
__be32 data;
int rc;
if (pe == NULL)
return -ENXIO;
if (pe->mve_number < 0)
return -ENXIO;
if (dev->no_64bit_msi)
is_64 = 0;
rc = opal_pci_set_xive_pe(phb->opal_id, pe->pe_number, xive_num);
if (rc) {
pr_warn("%s: OPAL error %d setting XIVE %d PE\n",
pci_name(dev), rc, xive_num);
return -EIO;
}
if (is_64) {
__be64 addr64;
rc = opal_get_msi_64(phb->opal_id, pe->mve_number, xive_num, 1,
&addr64, &data);
if (rc) {
pr_warn("%s: OPAL error %d getting 64-bit MSI data\n",
pci_name(dev), rc);
return -EIO;
}
msg->address_hi = be64_to_cpu(addr64) >> 32;
msg->address_lo = be64_to_cpu(addr64) & 0xfffffffful;
} else {
__be32 addr32;
rc = opal_get_msi_32(phb->opal_id, pe->mve_number, xive_num, 1,
&addr32, &data);
if (rc) {
pr_warn("%s: OPAL error %d getting 32-bit MSI data\n",
pci_name(dev), rc);
return -EIO;
}
msg->address_hi = 0;
msg->address_lo = be32_to_cpu(addr32);
}
msg->data = be32_to_cpu(data);
set_msi_irq_chip(phb, virq);
pr_devel("%s: %s-bit MSI on hwirq %x (xive #%d),"
" address=%x_%08x data=%x PE# %d\n",
pci_name(dev), is_64 ? "64" : "32", hwirq, xive_num,
msg->address_hi, msg->address_lo, data, pe->pe_number);
return 0;
}
static void pnv_pci_init_ioda_msis(struct pnv_phb *phb)
{
unsigned int count;
const __be32 *prop = of_get_property(phb->hose->dn,
"ibm,opal-msi-ranges", NULL);
if (!prop) {
prop = of_get_property(phb->hose->dn, "msi-ranges", NULL);
}
if (!prop)
return;
phb->msi_base = be32_to_cpup(prop);
count = be32_to_cpup(prop + 1);
if (msi_bitmap_alloc(&phb->msi_bmp, count, phb->hose->dn)) {
pr_err("PCI %d: Failed to allocate MSI bitmap !\n",
phb->hose->global_number);
return;
}
phb->msi_setup = pnv_pci_ioda_msi_setup;
phb->msi32_support = 1;
pr_info(" Allocated bitmap for %d MSIs (base IRQ 0x%x)\n",
count, phb->msi_base);
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
hose->mem_offset[0] -
phb->ioda.m32_pci_base;
region.end = res->end -
hose->mem_offset[0] -
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
static void pnv_pci_ioda_create_dbgfs(void)
{
#ifdef CONFIG_DEBUG_FS
struct pci_controller *hose, *tmp;
struct pnv_phb *phb;
char name[16];
list_for_each_entry_safe(hose, tmp, &hose_list, list_node) {
phb = hose->private_data;
sprintf(name, "PCI%04x", hose->global_number);
phb->dbgfs = debugfs_create_dir(name, powerpc_debugfs_root);
if (!phb->dbgfs)
pr_warning("%s: Error on creating debugfs on PHB#%x\n",
__func__, hose->global_number);
}
#endif
}
static void pnv_pci_ioda_fixup(void)
{
pnv_pci_ioda_setup_PEs();
pnv_pci_ioda_setup_seg();
pnv_pci_ioda_setup_DMA();
pnv_pci_ioda_create_dbgfs();
#ifdef CONFIG_EEH
eeh_init();
eeh_addr_cache_build();
#endif
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
if (phb->ioda.m64_segsize &&
pnv_pci_is_mem_pref_64(type))
return phb->ioda.m64_segsize;
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
pdn = pci_get_pdn(dev);
if (!pdn || pdn->pe_number == IODA_INVALID_PE)
return -EINVAL;
return 0;
}
static u32 pnv_ioda_bdfn_to_pe(struct pnv_phb *phb, struct pci_bus *bus,
u32 devfn)
{
return phb->ioda.pe_rmap[(bus->number << 8) | devfn];
}
static void pnv_pci_ioda_shutdown(struct pnv_phb *phb)
{
opal_pci_reset(phb->opal_id, OPAL_RESET_PCI_IODA_TABLE,
OPAL_ASSERT_RESET);
}
static void __init pnv_pci_init_ioda_phb(struct device_node *np,
u64 hub_id, int ioda_type)
{
struct pci_controller *hose;
struct pnv_phb *phb;
unsigned long size, m32map_off, pemap_off, iomap_off = 0;
const __be64 *prop64;
const __be32 *prop32;
int len;
u64 phb_id;
void *aux;
long rc;
pr_info("Initializing IODA%d OPAL PHB %s\n", ioda_type, np->full_name);
prop64 = of_get_property(np, "ibm,opal-phbid", NULL);
if (!prop64) {
pr_err(" Missing \"ibm,opal-phbid\" property !\n");
return;
}
phb_id = be64_to_cpup(prop64);
pr_debug(" PHB-ID : 0x%016llx\n", phb_id);
phb = memblock_virt_alloc(sizeof(struct pnv_phb), 0);
phb->hose = hose = pcibios_alloc_controller(np);
if (!phb->hose) {
pr_err(" Can't allocate PCI controller for %s\n",
np->full_name);
memblock_free(__pa(phb), sizeof(struct pnv_phb));
return;
}
spin_lock_init(&phb->lock);
prop32 = of_get_property(np, "bus-range", &len);
if (prop32 && len == 8) {
hose->first_busno = be32_to_cpu(prop32[0]);
hose->last_busno = be32_to_cpu(prop32[1]);
} else {
pr_warn(" Broken <bus-range> on %s\n", np->full_name);
hose->first_busno = 0;
hose->last_busno = 0xff;
}
hose->private_data = phb;
phb->hub_id = hub_id;
phb->opal_id = phb_id;
phb->type = ioda_type;
if (of_device_is_compatible(np, "ibm,p7ioc-pciex"))
phb->model = PNV_PHB_MODEL_P7IOC;
else if (of_device_is_compatible(np, "ibm,power8-pciex"))
phb->model = PNV_PHB_MODEL_PHB3;
else
phb->model = PNV_PHB_MODEL_UNKNOWN;
pci_process_bridge_OF_ranges(hose, np, !hose->global_number);
phb->regs = of_iomap(np, 0);
if (phb->regs == NULL)
pr_err(" Failed to map registers !\n");
phb->ioda.total_pe = 1;
prop32 = of_get_property(np, "ibm,opal-num-pes", NULL);
if (prop32)
phb->ioda.total_pe = be32_to_cpup(prop32);
prop32 = of_get_property(np, "ibm,opal-reserved-pe", NULL);
if (prop32)
phb->ioda.reserved_pe = be32_to_cpup(prop32);
pnv_ioda_parse_m64_window(phb);
phb->ioda.m32_size = resource_size(&hose->mem_resources[0]);
phb->ioda.m32_size += 0x10000;
phb->ioda.m32_segsize = phb->ioda.m32_size / phb->ioda.total_pe;
phb->ioda.m32_pci_base = hose->mem_resources[0].start - hose->mem_offset[0];
phb->ioda.io_size = hose->pci_io_size;
phb->ioda.io_segsize = phb->ioda.io_size / phb->ioda.total_pe;
phb->ioda.io_pci_base = 0;
size = _ALIGN_UP(phb->ioda.total_pe / 8, sizeof(unsigned long));
m32map_off = size;
size += phb->ioda.total_pe * sizeof(phb->ioda.m32_segmap[0]);
if (phb->type == PNV_PHB_IODA1) {
iomap_off = size;
size += phb->ioda.total_pe * sizeof(phb->ioda.io_segmap[0]);
}
pemap_off = size;
size += phb->ioda.total_pe * sizeof(struct pnv_ioda_pe);
aux = memblock_virt_alloc(size, 0);
phb->ioda.pe_alloc = aux;
phb->ioda.m32_segmap = aux + m32map_off;
if (phb->type == PNV_PHB_IODA1)
phb->ioda.io_segmap = aux + iomap_off;
phb->ioda.pe_array = aux + pemap_off;
set_bit(phb->ioda.reserved_pe, phb->ioda.pe_alloc);
INIT_LIST_HEAD(&phb->ioda.pe_dma_list);
INIT_LIST_HEAD(&phb->ioda.pe_list);
phb->ioda.tce32_count = phb->ioda.m32_pci_base >> 28;
#if 0
rc = opal_pci_set_phb_mem_window(opal->phb_id,
window_type,
window_num,
starting_real_address,
starting_pci_address,
segment_size);
#endif
pr_info(" %03d (%03d) PE's M32: 0x%x [segment=0x%x]\n",
phb->ioda.total_pe, phb->ioda.reserved_pe,
phb->ioda.m32_size, phb->ioda.m32_segsize);
if (phb->ioda.m64_size)
pr_info(" M64: 0x%lx [segment=0x%lx]\n",
phb->ioda.m64_size, phb->ioda.m64_segsize);
if (phb->ioda.io_size)
pr_info(" IO: 0x%x [segment=0x%x]\n",
phb->ioda.io_size, phb->ioda.io_segsize);
phb->hose->ops = &pnv_pci_ops;
phb->get_pe_state = pnv_ioda_get_pe_state;
phb->freeze_pe = pnv_ioda_freeze_pe;
phb->unfreeze_pe = pnv_ioda_unfreeze_pe;
#ifdef CONFIG_EEH
phb->eeh_ops = &ioda_eeh_ops;
#endif
phb->bdfn_to_pe = pnv_ioda_bdfn_to_pe;
phb->dma_dev_setup = pnv_pci_ioda_dma_dev_setup;
phb->dma_set_mask = pnv_pci_ioda_dma_set_mask;
phb->dma_get_required_mask = pnv_pci_ioda_dma_get_required_mask;
phb->shutdown = pnv_pci_ioda_shutdown;
pnv_pci_init_ioda_msis(phb);
ppc_md.pcibios_fixup = pnv_pci_ioda_fixup;
ppc_md.pcibios_enable_device_hook = pnv_pci_enable_device_hook;
ppc_md.pcibios_window_alignment = pnv_pci_window_alignment;
ppc_md.pcibios_reset_secondary_bus = pnv_pci_reset_secondary_bus;
pci_add_flags(PCI_REASSIGN_ALL_RSRC);
rc = opal_pci_reset(phb_id, OPAL_RESET_PCI_IODA_TABLE, OPAL_ASSERT_RESET);
if (rc)
pr_warning(" OPAL Error %ld performing IODA table reset !\n", rc);
if (is_kdump_kernel()) {
pr_info(" Issue PHB reset ...\n");
ioda_eeh_phb_reset(hose, EEH_RESET_FUNDAMENTAL);
ioda_eeh_phb_reset(hose, EEH_RESET_DEACTIVATE);
}
if (!phb->init_m64 || phb->init_m64(phb))
hose->mem_resources[1].flags = 0;
}
void __init pnv_pci_init_ioda2_phb(struct device_node *np)
{
pnv_pci_init_ioda_phb(np, 0, PNV_PHB_IODA2);
}
void __init pnv_pci_init_ioda_hub(struct device_node *np)
{
struct device_node *phbn;
const __be64 *prop64;
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
pnv_pci_init_ioda_phb(phbn, hub_id, PNV_PHB_IODA1);
}
}
