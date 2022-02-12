void pe_level_printk(const struct pnv_ioda_pe *pe, const char *level,
const char *fmt, ...)
{
struct va_format vaf;
va_list args;
char pfix[32];
va_start(args, fmt);
vaf.fmt = fmt;
vaf.va = &args;
if (pe->flags & PNV_IODA_PE_DEV)
strlcpy(pfix, dev_name(&pe->pdev->dev), sizeof(pfix));
else if (pe->flags & (PNV_IODA_PE_BUS | PNV_IODA_PE_BUS_ALL))
sprintf(pfix, "%04x:%02x ",
pci_domain_nr(pe->pbus), pe->pbus->number);
#ifdef CONFIG_PCI_IOV
else if (pe->flags & PNV_IODA_PE_VF)
sprintf(pfix, "%04x:%02x:%2x.%d",
pci_domain_nr(pe->parent_dev->bus),
(pe->rid & 0xff00) >> 8,
PCI_SLOT(pe->rid), PCI_FUNC(pe->rid));
#endif
printk("%spci %s: [PE# %.2x] %pV",
level, pfix, pe->pe_number, &vaf);
va_end(args);
}
static int __init iommu_setup(char *str)
{
if (!str)
return -EINVAL;
while (*str) {
if (!strncmp(str, "nobypass", 8)) {
pnv_iommu_bypass_disabled = true;
pr_info("PowerNV: IOMMU bypass window disabled.\n");
break;
}
str += strcspn(str, ",");
if (*str == ',')
str++;
}
return 0;
}
static inline bool pnv_pci_is_m64(struct pnv_phb *phb, struct resource *r)
{
return (r->start >= phb->ioda.m64_base &&
r->start < (phb->ioda.m64_base + phb->ioda.m64_size));
}
static inline bool pnv_pci_is_m64_flags(unsigned long resource_flags)
{
unsigned long flags = (IORESOURCE_MEM_64 | IORESOURCE_PREFETCH);
return (resource_flags & flags) == flags;
}
static struct pnv_ioda_pe *pnv_ioda_init_pe(struct pnv_phb *phb, int pe_no)
{
s64 rc;
phb->ioda.pe_array[pe_no].phb = phb;
phb->ioda.pe_array[pe_no].pe_number = pe_no;
rc = opal_pci_eeh_freeze_clear(phb->opal_id, pe_no,
OPAL_EEH_ACTION_CLEAR_FREEZE_ALL);
if (rc != OPAL_SUCCESS && rc != OPAL_UNSUPPORTED)
pr_warn("%s: Error %lld unfreezing PHB#%x-PE#%x\n",
__func__, rc, phb->hose->global_number, pe_no);
return &phb->ioda.pe_array[pe_no];
}
static void pnv_ioda_reserve_pe(struct pnv_phb *phb, int pe_no)
{
if (!(pe_no >= 0 && pe_no < phb->ioda.total_pe_num)) {
pr_warn("%s: Invalid PE %x on PHB#%x\n",
__func__, pe_no, phb->hose->global_number);
return;
}
if (test_and_set_bit(pe_no, phb->ioda.pe_alloc))
pr_debug("%s: PE %x was reserved on PHB#%x\n",
__func__, pe_no, phb->hose->global_number);
pnv_ioda_init_pe(phb, pe_no);
}
static struct pnv_ioda_pe *pnv_ioda_alloc_pe(struct pnv_phb *phb)
{
long pe;
for (pe = phb->ioda.total_pe_num - 1; pe >= 0; pe--) {
if (!test_and_set_bit(pe, phb->ioda.pe_alloc))
return pnv_ioda_init_pe(phb, pe);
}
return NULL;
}
static void pnv_ioda_free_pe(struct pnv_ioda_pe *pe)
{
struct pnv_phb *phb = pe->phb;
unsigned int pe_num = pe->pe_number;
WARN_ON(pe->pdev);
memset(pe, 0, sizeof(struct pnv_ioda_pe));
clear_bit(pe_num, phb->ioda.pe_alloc);
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
r = &phb->hose->mem_resources[1];
if (phb->ioda.reserved_pe_idx == 0)
r->start += (2 * phb->ioda.m64_segsize);
else if (phb->ioda.reserved_pe_idx == (phb->ioda.total_pe_num - 1))
r->end -= (2 * phb->ioda.m64_segsize);
else
pr_warn(" Cannot strip M64 segment for reserved PE#%x\n",
phb->ioda.reserved_pe_idx);
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
static void pnv_ioda_reserve_dev_m64_pe(struct pci_dev *pdev,
unsigned long *pe_bitmap)
{
struct pci_controller *hose = pci_bus_to_host(pdev->bus);
struct pnv_phb *phb = hose->private_data;
struct resource *r;
resource_size_t base, sgsz, start, end;
int segno, i;
base = phb->ioda.m64_base;
sgsz = phb->ioda.m64_segsize;
for (i = 0; i <= PCI_ROM_RESOURCE; i++) {
r = &pdev->resource[i];
if (!r->parent || !pnv_pci_is_m64(phb, r))
continue;
start = _ALIGN_DOWN(r->start - base, sgsz);
end = _ALIGN_UP(r->end - base, sgsz);
for (segno = start / sgsz; segno < end / sgsz; segno++) {
if (pe_bitmap)
set_bit(segno, pe_bitmap);
else
pnv_ioda_reserve_pe(phb, segno);
}
}
}
static int pnv_ioda1_init_m64(struct pnv_phb *phb)
{
struct resource *r;
int index;
for (index = 0; index < PNV_IODA1_M64_NUM; index++) {
unsigned long base, segsz = phb->ioda.m64_segsize;
int64_t rc;
base = phb->ioda.m64_base +
index * PNV_IODA1_M64_SEGS * segsz;
rc = opal_pci_set_phb_mem_window(phb->opal_id,
OPAL_M64_WINDOW_TYPE, index, base, 0,
PNV_IODA1_M64_SEGS * segsz);
if (rc != OPAL_SUCCESS) {
pr_warn(" Error %lld setting M64 PHB#%x-BAR#%d\n",
rc, phb->hose->global_number, index);
goto fail;
}
rc = opal_pci_phb_mmio_enable(phb->opal_id,
OPAL_M64_WINDOW_TYPE, index,
OPAL_ENABLE_M64_SPLIT);
if (rc != OPAL_SUCCESS) {
pr_warn(" Error %lld enabling M64 PHB#%x-BAR#%d\n",
rc, phb->hose->global_number, index);
goto fail;
}
}
r = &phb->hose->mem_resources[1];
if (phb->ioda.reserved_pe_idx == 0)
r->start += (2 * phb->ioda.m64_segsize);
else if (phb->ioda.reserved_pe_idx == (phb->ioda.total_pe_num - 1))
r->end -= (2 * phb->ioda.m64_segsize);
else
WARN(1, "Wrong reserved PE#%x on PHB#%x\n",
phb->ioda.reserved_pe_idx, phb->hose->global_number);
return 0;
fail:
for ( ; index >= 0; index--)
opal_pci_phb_mmio_enable(phb->opal_id,
OPAL_M64_WINDOW_TYPE, index, OPAL_DISABLE_M64);
return -EIO;
}
static void pnv_ioda_reserve_m64_pe(struct pci_bus *bus,
unsigned long *pe_bitmap,
bool all)
{
struct pci_dev *pdev;
list_for_each_entry(pdev, &bus->devices, bus_list) {
pnv_ioda_reserve_dev_m64_pe(pdev, pe_bitmap);
if (all && pdev->subordinate)
pnv_ioda_reserve_m64_pe(pdev->subordinate,
pe_bitmap, all);
}
}
static struct pnv_ioda_pe *pnv_ioda_pick_m64_pe(struct pci_bus *bus, bool all)
{
struct pci_controller *hose = pci_bus_to_host(bus);
struct pnv_phb *phb = hose->private_data;
struct pnv_ioda_pe *master_pe, *pe;
unsigned long size, *pe_alloc;
int i;
if (pci_is_root_bus(bus))
return NULL;
size = _ALIGN_UP(phb->ioda.total_pe_num / 8, sizeof(unsigned long));
pe_alloc = kzalloc(size, GFP_KERNEL);
if (!pe_alloc) {
pr_warn("%s: Out of memory !\n",
__func__);
return NULL;
}
pnv_ioda_reserve_m64_pe(bus, pe_alloc, all);
if (bitmap_empty(pe_alloc, phb->ioda.total_pe_num)) {
kfree(pe_alloc);
return NULL;
}
master_pe = NULL;
i = -1;
while ((i = find_next_bit(pe_alloc, phb->ioda.total_pe_num, i + 1)) <
phb->ioda.total_pe_num) {
pe = &phb->ioda.pe_array[i];
phb->ioda.m64_segmap[pe->pe_number] = pe->pe_number;
if (!master_pe) {
pe->flags |= PNV_IODA_PE_MASTER;
INIT_LIST_HEAD(&pe->slaves);
master_pe = pe;
} else {
pe->flags |= PNV_IODA_PE_SLAVE;
pe->master = master_pe;
list_add_tail(&pe->list, &master_pe->slaves);
}
if (phb->type == PNV_PHB_IODA1) {
int64_t rc;
rc = opal_pci_map_pe_mmio_window(phb->opal_id,
pe->pe_number, OPAL_M64_WINDOW_TYPE,
pe->pe_number / PNV_IODA1_M64_SEGS,
pe->pe_number % PNV_IODA1_M64_SEGS);
if (rc != OPAL_SUCCESS)
pr_warn("%s: Error %lld mapping M64 for PHB#%x-PE#%x\n",
__func__, rc, phb->hose->global_number,
pe->pe_number);
}
}
kfree(pe_alloc);
return master_pe;
}
static void __init pnv_ioda_parse_m64_window(struct pnv_phb *phb)
{
struct pci_controller *hose = phb->hose;
struct device_node *dn = hose->dn;
struct resource *res;
u32 m64_range[2], i;
const __be32 *r;
u64 pci_addr;
if (phb->type != PNV_PHB_IODA1 && phb->type != PNV_PHB_IODA2) {
pr_info(" Not support M64 window\n");
return;
}
if (!firmware_has_feature(FW_FEATURE_OPAL)) {
pr_info(" Firmware too old to support M64 window\n");
return;
}
r = of_get_property(dn, "ibm,opal-m64-window", NULL);
if (!r) {
pr_info(" No <ibm,opal-m64-window> on %pOF\n",
dn);
return;
}
if (of_property_read_u32_array(dn, "ibm,opal-available-m64-ranges",
m64_range, 2)) {
m64_range[0] = 0;
m64_range[1] = 16;
}
if (m64_range[1] > 63) {
pr_warn("%s: Limiting M64 range to 63 (from %d) on PHB#%x\n",
__func__, m64_range[1], phb->hose->global_number);
m64_range[1] = 63;
}
if (m64_range[1] <= m64_range[0]) {
pr_warn("%s: M64 empty, disabling M64 usage on PHB#%x\n",
__func__, phb->hose->global_number);
return;
}
res = &hose->mem_resources[1];
res->name = dn->full_name;
res->start = of_translate_address(dn, r + 2);
res->end = res->start + of_read_number(r + 4, 2) - 1;
res->flags = (IORESOURCE_MEM | IORESOURCE_MEM_64 | IORESOURCE_PREFETCH);
pci_addr = of_read_number(r, 2);
hose->mem_offset[1] = res->start - pci_addr;
phb->ioda.m64_size = resource_size(res);
phb->ioda.m64_segsize = phb->ioda.m64_size / phb->ioda.total_pe_num;
phb->ioda.m64_base = pci_addr;
pr_info(" MEM 0x%016llx..0x%016llx -> 0x%016llx (M64 #%d..%d)\n",
res->start, res->end, pci_addr, m64_range[0],
m64_range[0] + m64_range[1] - 1);
phb->ioda.m64_bar_alloc = (unsigned long)-1;
m64_range[1]--;
phb->ioda.m64_bar_idx = m64_range[0] + m64_range[1];
pr_info(" Using M64 #%d as default window\n", phb->ioda.m64_bar_idx);
for (i = m64_range[0]; i < m64_range[1]; i++)
clear_bit(i, &phb->ioda.m64_bar_alloc);
if (phb->type == PNV_PHB_IODA1)
phb->init_m64 = pnv_ioda1_init_m64;
else
phb->init_m64 = pnv_ioda2_init_m64;
phb->reserve_m64_pe = pnv_ioda_reserve_m64_pe;
phb->pick_m64_pe = pnv_ioda_pick_m64_pe;
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
if (pe_no < 0 || pe_no >= phb->ioda.total_pe_num)
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
struct pnv_ioda_pe *pnv_ioda_get_pe(struct pci_dev *dev)
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
struct pci_dev *pdev = NULL;
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
else if (pe->flags & PNV_IODA_PE_DEV)
pdev = pe->pdev->bus->self;
#ifdef CONFIG_PCI_IOV
else if (pe->flags & PNV_IODA_PE_VF)
pdev = pe->parent_dev;
#endif
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
static int pnv_ioda_deconfigure_pe(struct pnv_phb *phb, struct pnv_ioda_pe *pe)
{
struct pci_dev *parent;
uint8_t bcomp, dcomp, fcomp;
int64_t rc;
long rid_end, rid;
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
dev_err(&pe->pbus->dev, "Number of subordinate buses %d unsupported\n",
count);
bcomp = OpalPciBusAll;
}
rid_end = pe->rid + (count << 8);
} else {
#ifdef CONFIG_PCI_IOV
if (pe->flags & PNV_IODA_PE_VF)
parent = pe->parent_dev;
else
#endif
parent = pe->pdev->bus->self;
bcomp = OpalPciBusAll;
dcomp = OPAL_COMPARE_RID_DEVICE_NUMBER;
fcomp = OPAL_COMPARE_RID_FUNCTION_NUMBER;
rid_end = pe->rid + 1;
}
for (rid = pe->rid; rid < rid_end; rid++)
phb->ioda.pe_rmap[rid] = IODA_INVALID_PE;
while (parent) {
struct pci_dn *pdn = pci_get_pdn(parent);
if (pdn && pdn->pe_number != IODA_INVALID_PE) {
rc = opal_pci_set_peltv(phb->opal_id, pdn->pe_number,
pe->pe_number, OPAL_REMOVE_PE_FROM_DOMAIN);
}
parent = parent->bus->self;
}
opal_pci_eeh_freeze_clear(phb->opal_id, pe->pe_number,
OPAL_EEH_ACTION_CLEAR_FREEZE_ALL);
rc = opal_pci_set_peltv(phb->opal_id, pe->pe_number,
pe->pe_number, OPAL_REMOVE_PE_FROM_DOMAIN);
if (rc)
pe_warn(pe, "OPAL error %ld remove self from PELTV\n", rc);
rc = opal_pci_set_pe(phb->opal_id, pe->pe_number, pe->rid,
bcomp, dcomp, fcomp, OPAL_UNMAP_PE);
if (rc)
pe_err(pe, "OPAL error %ld trying to setup PELT table\n", rc);
pe->pbus = NULL;
pe->pdev = NULL;
#ifdef CONFIG_PCI_IOV
pe->parent_dev = NULL;
#endif
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
dev_err(&pe->pbus->dev, "Number of subordinate buses %d unsupported\n",
count);
bcomp = OpalPciBusAll;
}
rid_end = pe->rid + (count << 8);
} else {
#ifdef CONFIG_PCI_IOV
if (pe->flags & PNV_IODA_PE_VF)
parent = pe->parent_dev;
else
#endif
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
if (phb->type != PNV_PHB_NPU)
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
pe_err(pe, "OPAL error %ld setting up MVE %x\n",
rc, pe->mve_number);
pe->mve_number = -1;
} else {
rc = opal_pci_set_mve_enable(phb->opal_id,
pe->mve_number, OPAL_ENABLE_MVE);
if (rc) {
pe_err(pe, "OPAL error %ld enabling MVE %x\n",
rc, pe->mve_number);
pe->mve_number = -1;
}
}
out:
return 0;
}
static int pnv_pci_vf_resource_shift(struct pci_dev *dev, int offset)
{
struct pci_dn *pdn = pci_get_pdn(dev);
int i;
struct resource *res, res2;
resource_size_t size;
u16 num_vfs;
if (!dev->is_physfn)
return -EINVAL;
num_vfs = pdn->num_vfs;
for (i = 0; i < PCI_SRIOV_NUM_BARS; i++) {
res = &dev->resource[i + PCI_IOV_RESOURCES];
if (!res->flags || !res->parent)
continue;
size = pci_iov_resource_size(dev, i + PCI_IOV_RESOURCES);
res2.flags = res->flags;
res2.start = res->start + (size * offset);
res2.end = res2.start + (size * num_vfs) - 1;
if (res2.end > res->end) {
dev_err(&dev->dev, "VF BAR%d: %pR would extend past %pR (trying to enable %d VFs shifted by %d)\n",
i, &res2, res, num_vfs, offset);
return -EBUSY;
}
}
for (i = 0; i < PCI_SRIOV_NUM_BARS; i++) {
res = &dev->resource[i + PCI_IOV_RESOURCES];
if (!res->flags || !res->parent)
continue;
size = pci_iov_resource_size(dev, i + PCI_IOV_RESOURCES);
res2 = *res;
res->start += size * offset;
dev_info(&dev->dev, "VF BAR%d: %pR shifted to %pR (%sabling %d VFs shifted by %d)\n",
i, &res2, res, (offset > 0) ? "En" : "Dis",
num_vfs, offset);
pci_update_resource(dev, i + PCI_IOV_RESOURCES);
}
return 0;
}
static struct pnv_ioda_pe *pnv_ioda_setup_dev_PE(struct pci_dev *dev)
{
struct pci_controller *hose = pci_bus_to_host(dev->bus);
struct pnv_phb *phb = hose->private_data;
struct pci_dn *pdn = pci_get_pdn(dev);
struct pnv_ioda_pe *pe;
if (!pdn) {
pr_err("%s: Device tree node not associated properly\n",
pci_name(dev));
return NULL;
}
if (pdn->pe_number != IODA_INVALID_PE)
return NULL;
pe = pnv_ioda_alloc_pe(phb);
if (!pe) {
pr_warning("%s: Not enough PE# available, disabling device\n",
pci_name(dev));
return NULL;
}
pci_dev_get(dev);
pdn->pcidev = dev;
pdn->pe_number = pe->pe_number;
pe->flags = PNV_IODA_PE_DEV;
pe->pdev = dev;
pe->pbus = NULL;
pe->mve_number = -1;
pe->rid = dev->bus->number << 8 | pdn->devfn;
pe_info(pe, "Associated device to PE\n");
if (pnv_ioda_configure_pe(phb, pe)) {
pnv_ioda_free_pe(pe);
pdn->pe_number = IODA_INVALID_PE;
pe->pdev = NULL;
pci_dev_put(dev);
return NULL;
}
list_add_tail(&pe->list, &phb->ioda.pe_list);
return pe;
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
if (pdn->pe_number != IODA_INVALID_PE)
continue;
pe->device_count++;
pdn->pcidev = dev;
pdn->pe_number = pe->pe_number;
if ((pe->flags & PNV_IODA_PE_BUS_ALL) && dev->subordinate)
pnv_ioda_setup_same_PE(dev->subordinate, pe);
}
}
static struct pnv_ioda_pe *pnv_ioda_setup_bus_PE(struct pci_bus *bus, bool all)
{
struct pci_controller *hose = pci_bus_to_host(bus);
struct pnv_phb *phb = hose->private_data;
struct pnv_ioda_pe *pe = NULL;
unsigned int pe_num;
pe_num = phb->ioda.pe_rmap[bus->number << 8];
if (pe_num != IODA_INVALID_PE) {
pe = &phb->ioda.pe_array[pe_num];
pnv_ioda_setup_same_PE(bus, pe);
return NULL;
}
if (pci_is_root_bus(bus) &&
phb->ioda.root_pe_idx != IODA_INVALID_PE)
pe = &phb->ioda.pe_array[phb->ioda.root_pe_idx];
if (!pe && phb->pick_m64_pe)
pe = phb->pick_m64_pe(bus, all);
if (!pe)
pe = pnv_ioda_alloc_pe(phb);
if (!pe) {
pr_warning("%s: Not enough PE# available for PCI bus %04x:%02x\n",
__func__, pci_domain_nr(bus), bus->number);
return NULL;
}
pe->flags |= (all ? PNV_IODA_PE_BUS_ALL : PNV_IODA_PE_BUS);
pe->pbus = bus;
pe->pdev = NULL;
pe->mve_number = -1;
pe->rid = bus->busn_res.start << 8;
if (all)
pe_info(pe, "Secondary bus %d..%d associated with PE#%x\n",
bus->busn_res.start, bus->busn_res.end, pe->pe_number);
else
pe_info(pe, "Secondary bus %d associated with PE#%x\n",
bus->busn_res.start, pe->pe_number);
if (pnv_ioda_configure_pe(phb, pe)) {
pnv_ioda_free_pe(pe);
pe->pbus = NULL;
return NULL;
}
pnv_ioda_setup_same_PE(bus, pe);
list_add_tail(&pe->list, &phb->ioda.pe_list);
return pe;
}
static struct pnv_ioda_pe *pnv_ioda_setup_npu_PE(struct pci_dev *npu_pdev)
{
int pe_num, found_pe = false, rc;
long rid;
struct pnv_ioda_pe *pe;
struct pci_dev *gpu_pdev;
struct pci_dn *npu_pdn;
struct pci_controller *hose = pci_bus_to_host(npu_pdev->bus);
struct pnv_phb *phb = hose->private_data;
gpu_pdev = pnv_pci_get_gpu_dev(npu_pdev);
for (pe_num = 0; pe_num < phb->ioda.total_pe_num; pe_num++) {
pe = &phb->ioda.pe_array[pe_num];
if (!pe->pdev)
continue;
if (pnv_pci_get_gpu_dev(pe->pdev) == gpu_pdev) {
dev_info(&npu_pdev->dev,
"Associating to existing PE %x\n", pe_num);
pci_dev_get(npu_pdev);
npu_pdn = pci_get_pdn(npu_pdev);
rid = npu_pdev->bus->number << 8 | npu_pdn->devfn;
npu_pdn->pcidev = npu_pdev;
npu_pdn->pe_number = pe_num;
phb->ioda.pe_rmap[rid] = pe->pe_number;
rc = opal_pci_set_pe(phb->opal_id, pe_num, rid,
OpalPciBusAll,
OPAL_COMPARE_RID_DEVICE_NUMBER,
OPAL_COMPARE_RID_FUNCTION_NUMBER,
OPAL_MAP_PE);
WARN_ON(rc != OPAL_SUCCESS);
found_pe = true;
break;
}
}
if (!found_pe)
return pnv_ioda_setup_dev_PE(npu_pdev);
else
return pe;
}
static void pnv_ioda_setup_npu_PEs(struct pci_bus *bus)
{
struct pci_dev *pdev;
list_for_each_entry(pdev, &bus->devices, bus_list)
pnv_ioda_setup_npu_PE(pdev);
}
static void pnv_pci_ioda_setup_PEs(void)
{
struct pci_controller *hose, *tmp;
struct pnv_phb *phb;
list_for_each_entry_safe(hose, tmp, &hose_list, list_node) {
phb = hose->private_data;
if (phb->type == PNV_PHB_NPU) {
pnv_ioda_reserve_pe(phb, 0);
pnv_ioda_setup_npu_PEs(hose->bus);
if (phb->model == PNV_PHB_MODEL_NPU2)
pnv_npu2_init(phb);
}
}
}
static int pnv_pci_vf_release_m64(struct pci_dev *pdev, u16 num_vfs)
{
struct pci_bus *bus;
struct pci_controller *hose;
struct pnv_phb *phb;
struct pci_dn *pdn;
int i, j;
int m64_bars;
bus = pdev->bus;
hose = pci_bus_to_host(bus);
phb = hose->private_data;
pdn = pci_get_pdn(pdev);
if (pdn->m64_single_mode)
m64_bars = num_vfs;
else
m64_bars = 1;
for (i = 0; i < PCI_SRIOV_NUM_BARS; i++)
for (j = 0; j < m64_bars; j++) {
if (pdn->m64_map[j][i] == IODA_INVALID_M64)
continue;
opal_pci_phb_mmio_enable(phb->opal_id,
OPAL_M64_WINDOW_TYPE, pdn->m64_map[j][i], 0);
clear_bit(pdn->m64_map[j][i], &phb->ioda.m64_bar_alloc);
pdn->m64_map[j][i] = IODA_INVALID_M64;
}
kfree(pdn->m64_map);
return 0;
}
static int pnv_pci_vf_assign_m64(struct pci_dev *pdev, u16 num_vfs)
{
struct pci_bus *bus;
struct pci_controller *hose;
struct pnv_phb *phb;
struct pci_dn *pdn;
unsigned int win;
struct resource *res;
int i, j;
int64_t rc;
int total_vfs;
resource_size_t size, start;
int pe_num;
int m64_bars;
bus = pdev->bus;
hose = pci_bus_to_host(bus);
phb = hose->private_data;
pdn = pci_get_pdn(pdev);
total_vfs = pci_sriov_get_totalvfs(pdev);
if (pdn->m64_single_mode)
m64_bars = num_vfs;
else
m64_bars = 1;
pdn->m64_map = kmalloc_array(m64_bars,
sizeof(*pdn->m64_map),
GFP_KERNEL);
if (!pdn->m64_map)
return -ENOMEM;
for (i = 0; i < m64_bars ; i++)
for (j = 0; j < PCI_SRIOV_NUM_BARS; j++)
pdn->m64_map[i][j] = IODA_INVALID_M64;
for (i = 0; i < PCI_SRIOV_NUM_BARS; i++) {
res = &pdev->resource[i + PCI_IOV_RESOURCES];
if (!res->flags || !res->parent)
continue;
for (j = 0; j < m64_bars; j++) {
do {
win = find_next_zero_bit(&phb->ioda.m64_bar_alloc,
phb->ioda.m64_bar_idx + 1, 0);
if (win >= phb->ioda.m64_bar_idx + 1)
goto m64_failed;
} while (test_and_set_bit(win, &phb->ioda.m64_bar_alloc));
pdn->m64_map[j][i] = win;
if (pdn->m64_single_mode) {
size = pci_iov_resource_size(pdev,
PCI_IOV_RESOURCES + i);
start = res->start + size * j;
} else {
size = resource_size(res);
start = res->start;
}
if (pdn->m64_single_mode) {
pe_num = pdn->pe_num_map[j];
rc = opal_pci_map_pe_mmio_window(phb->opal_id,
pe_num, OPAL_M64_WINDOW_TYPE,
pdn->m64_map[j][i], 0);
}
rc = opal_pci_set_phb_mem_window(phb->opal_id,
OPAL_M64_WINDOW_TYPE,
pdn->m64_map[j][i],
start,
0,
size);
if (rc != OPAL_SUCCESS) {
dev_err(&pdev->dev, "Failed to map M64 window #%d: %lld\n",
win, rc);
goto m64_failed;
}
if (pdn->m64_single_mode)
rc = opal_pci_phb_mmio_enable(phb->opal_id,
OPAL_M64_WINDOW_TYPE, pdn->m64_map[j][i], 2);
else
rc = opal_pci_phb_mmio_enable(phb->opal_id,
OPAL_M64_WINDOW_TYPE, pdn->m64_map[j][i], 1);
if (rc != OPAL_SUCCESS) {
dev_err(&pdev->dev, "Failed to enable M64 window #%d: %llx\n",
win, rc);
goto m64_failed;
}
}
}
return 0;
m64_failed:
pnv_pci_vf_release_m64(pdev, num_vfs);
return -EBUSY;
}
static void pnv_pci_ioda2_release_dma_pe(struct pci_dev *dev, struct pnv_ioda_pe *pe)
{
struct iommu_table *tbl;
int64_t rc;
tbl = pe->table_group.tables[0];
rc = pnv_pci_ioda2_unset_window(&pe->table_group, 0);
if (rc)
pe_warn(pe, "OPAL error %ld release DMA window\n", rc);
pnv_pci_ioda2_set_bypass(pe, false);
if (pe->table_group.group) {
iommu_group_put(pe->table_group.group);
BUG_ON(pe->table_group.group);
}
iommu_tce_table_put(tbl);
}
static void pnv_ioda_release_vf_PE(struct pci_dev *pdev)
{
struct pci_bus *bus;
struct pci_controller *hose;
struct pnv_phb *phb;
struct pnv_ioda_pe *pe, *pe_n;
struct pci_dn *pdn;
bus = pdev->bus;
hose = pci_bus_to_host(bus);
phb = hose->private_data;
pdn = pci_get_pdn(pdev);
if (!pdev->is_physfn)
return;
list_for_each_entry_safe(pe, pe_n, &phb->ioda.pe_list, list) {
if (pe->parent_dev != pdev)
continue;
pnv_pci_ioda2_release_dma_pe(pdev, pe);
mutex_lock(&phb->ioda.pe_list_mutex);
list_del(&pe->list);
mutex_unlock(&phb->ioda.pe_list_mutex);
pnv_ioda_deconfigure_pe(phb, pe);
pnv_ioda_free_pe(pe);
}
}
void pnv_pci_sriov_disable(struct pci_dev *pdev)
{
struct pci_bus *bus;
struct pci_controller *hose;
struct pnv_phb *phb;
struct pnv_ioda_pe *pe;
struct pci_dn *pdn;
u16 num_vfs, i;
bus = pdev->bus;
hose = pci_bus_to_host(bus);
phb = hose->private_data;
pdn = pci_get_pdn(pdev);
num_vfs = pdn->num_vfs;
pnv_ioda_release_vf_PE(pdev);
if (phb->type == PNV_PHB_IODA2) {
if (!pdn->m64_single_mode)
pnv_pci_vf_resource_shift(pdev, -*pdn->pe_num_map);
pnv_pci_vf_release_m64(pdev, num_vfs);
if (pdn->m64_single_mode) {
for (i = 0; i < num_vfs; i++) {
if (pdn->pe_num_map[i] == IODA_INVALID_PE)
continue;
pe = &phb->ioda.pe_array[pdn->pe_num_map[i]];
pnv_ioda_free_pe(pe);
}
} else
bitmap_clear(phb->ioda.pe_alloc, *pdn->pe_num_map, num_vfs);
kfree(pdn->pe_num_map);
}
}
static void pnv_ioda_setup_vf_PE(struct pci_dev *pdev, u16 num_vfs)
{
struct pci_bus *bus;
struct pci_controller *hose;
struct pnv_phb *phb;
struct pnv_ioda_pe *pe;
int pe_num;
u16 vf_index;
struct pci_dn *pdn;
bus = pdev->bus;
hose = pci_bus_to_host(bus);
phb = hose->private_data;
pdn = pci_get_pdn(pdev);
if (!pdev->is_physfn)
return;
for (vf_index = 0; vf_index < num_vfs; vf_index++) {
if (pdn->m64_single_mode)
pe_num = pdn->pe_num_map[vf_index];
else
pe_num = *pdn->pe_num_map + vf_index;
pe = &phb->ioda.pe_array[pe_num];
pe->pe_number = pe_num;
pe->phb = phb;
pe->flags = PNV_IODA_PE_VF;
pe->pbus = NULL;
pe->parent_dev = pdev;
pe->mve_number = -1;
pe->rid = (pci_iov_virtfn_bus(pdev, vf_index) << 8) |
pci_iov_virtfn_devfn(pdev, vf_index);
pe_info(pe, "VF %04d:%02d:%02d.%d associated with PE#%x\n",
hose->global_number, pdev->bus->number,
PCI_SLOT(pci_iov_virtfn_devfn(pdev, vf_index)),
PCI_FUNC(pci_iov_virtfn_devfn(pdev, vf_index)), pe_num);
if (pnv_ioda_configure_pe(phb, pe)) {
pnv_ioda_free_pe(pe);
pe->pdev = NULL;
continue;
}
mutex_lock(&phb->ioda.pe_list_mutex);
list_add_tail(&pe->list, &phb->ioda.pe_list);
mutex_unlock(&phb->ioda.pe_list_mutex);
pnv_pci_ioda2_setup_dma_pe(phb, pe);
}
}
int pnv_pci_sriov_enable(struct pci_dev *pdev, u16 num_vfs)
{
struct pci_bus *bus;
struct pci_controller *hose;
struct pnv_phb *phb;
struct pnv_ioda_pe *pe;
struct pci_dn *pdn;
int ret;
u16 i;
bus = pdev->bus;
hose = pci_bus_to_host(bus);
phb = hose->private_data;
pdn = pci_get_pdn(pdev);
if (phb->type == PNV_PHB_IODA2) {
if (!pdn->vfs_expanded) {
dev_info(&pdev->dev, "don't support this SRIOV device"
" with non 64bit-prefetchable IOV BAR\n");
return -ENOSPC;
}
if (pdn->m64_single_mode && num_vfs > phb->ioda.m64_bar_idx) {
dev_info(&pdev->dev, "Not enough M64 BAR for VFs\n");
return -EBUSY;
}
if (pdn->m64_single_mode)
pdn->pe_num_map = kmalloc_array(num_vfs,
sizeof(*pdn->pe_num_map),
GFP_KERNEL);
else
pdn->pe_num_map = kmalloc(sizeof(*pdn->pe_num_map), GFP_KERNEL);
if (!pdn->pe_num_map)
return -ENOMEM;
if (pdn->m64_single_mode)
for (i = 0; i < num_vfs; i++)
pdn->pe_num_map[i] = IODA_INVALID_PE;
if (pdn->m64_single_mode) {
for (i = 0; i < num_vfs; i++) {
pe = pnv_ioda_alloc_pe(phb);
if (!pe) {
ret = -EBUSY;
goto m64_failed;
}
pdn->pe_num_map[i] = pe->pe_number;
}
} else {
mutex_lock(&phb->ioda.pe_alloc_mutex);
*pdn->pe_num_map = bitmap_find_next_zero_area(
phb->ioda.pe_alloc, phb->ioda.total_pe_num,
0, num_vfs, 0);
if (*pdn->pe_num_map >= phb->ioda.total_pe_num) {
mutex_unlock(&phb->ioda.pe_alloc_mutex);
dev_info(&pdev->dev, "Failed to enable VF%d\n", num_vfs);
kfree(pdn->pe_num_map);
return -EBUSY;
}
bitmap_set(phb->ioda.pe_alloc, *pdn->pe_num_map, num_vfs);
mutex_unlock(&phb->ioda.pe_alloc_mutex);
}
pdn->num_vfs = num_vfs;
ret = pnv_pci_vf_assign_m64(pdev, num_vfs);
if (ret) {
dev_info(&pdev->dev, "Not enough M64 window resources\n");
goto m64_failed;
}
if (!pdn->m64_single_mode) {
ret = pnv_pci_vf_resource_shift(pdev, *pdn->pe_num_map);
if (ret)
goto m64_failed;
}
}
pnv_ioda_setup_vf_PE(pdev, num_vfs);
return 0;
m64_failed:
if (pdn->m64_single_mode) {
for (i = 0; i < num_vfs; i++) {
if (pdn->pe_num_map[i] == IODA_INVALID_PE)
continue;
pe = &phb->ioda.pe_array[pdn->pe_num_map[i]];
pnv_ioda_free_pe(pe);
}
} else
bitmap_clear(phb->ioda.pe_alloc, *pdn->pe_num_map, num_vfs);
kfree(pdn->pe_num_map);
return ret;
}
int pcibios_sriov_disable(struct pci_dev *pdev)
{
pnv_pci_sriov_disable(pdev);
remove_dev_pci_data(pdev);
return 0;
}
int pcibios_sriov_enable(struct pci_dev *pdev, u16 num_vfs)
{
add_dev_pci_data(pdev);
return pnv_pci_sriov_enable(pdev, num_vfs);
}
static void pnv_pci_ioda_dma_dev_setup(struct pnv_phb *phb, struct pci_dev *pdev)
{
struct pci_dn *pdn = pci_get_pdn(pdev);
struct pnv_ioda_pe *pe;
if (!pdn || pdn->pe_number == IODA_INVALID_PE)
return;
pe = &phb->ioda.pe_array[pdn->pe_number];
WARN_ON(get_dma_ops(&pdev->dev) != &dma_iommu_ops);
set_dma_offset(&pdev->dev, pe->tce_bypass_base);
set_iommu_table_base(&pdev->dev, pe->table_group.tables[0]);
}
static bool pnv_pci_ioda_pe_single_vendor(struct pnv_ioda_pe *pe)
{
unsigned short vendor = 0;
struct pci_dev *pdev;
if (pe->device_count == 1)
return true;
if (!pe->pbus)
return true;
list_for_each_entry(pdev, &pe->pbus->devices, bus_list) {
if (!vendor) {
vendor = pdev->vendor;
continue;
}
if (pdev->vendor != vendor)
return false;
}
return true;
}
static int pnv_pci_ioda_dma_64bit_bypass(struct pnv_ioda_pe *pe)
{
u64 window_size, table_size, tce_count, addr;
struct page *table_pages;
u64 tce_order = 28;
__be64 *tces;
s64 rc;
window_size = roundup_pow_of_two(memory_hotplug_max() + (1ULL << 32));
tce_count = window_size >> tce_order;
table_size = tce_count << 3;
if (table_size < PAGE_SIZE)
table_size = PAGE_SIZE;
table_pages = alloc_pages_node(pe->phb->hose->node, GFP_KERNEL,
get_order(table_size));
if (!table_pages)
goto err;
tces = page_address(table_pages);
if (!tces)
goto err;
memset(tces, 0, table_size);
for (addr = 0; addr < memory_hotplug_max(); addr += (1 << tce_order)) {
tces[(addr + (1ULL << 32)) >> tce_order] =
cpu_to_be64(addr | TCE_PCI_READ | TCE_PCI_WRITE);
}
rc = opal_pci_map_pe_dma_window(pe->phb->opal_id,
pe->pe_number,
(pe->pe_number << 1) + 0,
1,
__pa(tces),
table_size,
1 << tce_order);
if (rc == OPAL_SUCCESS) {
pe_info(pe, "Using 64-bit DMA iommu bypass (through TVE#0)\n");
return 0;
}
err:
pe_err(pe, "Error configuring 64-bit DMA bypass\n");
return -EIO;
}
static int pnv_pci_ioda_dma_set_mask(struct pci_dev *pdev, u64 dma_mask)
{
struct pci_controller *hose = pci_bus_to_host(pdev->bus);
struct pnv_phb *phb = hose->private_data;
struct pci_dn *pdn = pci_get_pdn(pdev);
struct pnv_ioda_pe *pe;
uint64_t top;
bool bypass = false;
s64 rc;
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
} else {
if (dma_mask >> 32 &&
dma_mask > (memory_hotplug_max() + (1ULL << 32)) &&
pnv_pci_ioda_pe_single_vendor(pe) &&
phb->model == PNV_PHB_MODEL_PHB3) {
rc = pnv_pci_ioda_dma_64bit_bypass(pe);
if (rc)
return rc;
set_dma_offset(&pdev->dev, (1ULL << 32));
set_dma_ops(&pdev->dev, &dma_direct_ops);
} else if (dma_mask >> 32 && dma_mask != DMA_BIT_MASK(64)) {
return -ENOMEM;
} else {
dev_info(&pdev->dev, "Using 32-bit DMA via iommu\n");
set_dma_ops(&pdev->dev, &dma_iommu_ops);
}
}
*pdev->dev.dma_mask = dma_mask;
pnv_npu_try_dma_set_bypass(pdev, bypass);
return 0;
}
static u64 pnv_pci_ioda_dma_get_required_mask(struct pci_dev *pdev)
{
struct pci_controller *hose = pci_bus_to_host(pdev->bus);
struct pnv_phb *phb = hose->private_data;
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
bool add_to_group)
{
struct pci_dev *dev;
list_for_each_entry(dev, &bus->devices, bus_list) {
set_iommu_table_base(&dev->dev, pe->table_group.tables[0]);
set_dma_offset(&dev->dev, pe->tce_bypass_base);
if (add_to_group)
iommu_add_device(&dev->dev);
if ((pe->flags & PNV_IODA_PE_BUS_ALL) && dev->subordinate)
pnv_ioda_setup_bus_dma(pe, dev->subordinate,
add_to_group);
}
}
static inline __be64 __iomem *pnv_ioda_get_inval_reg(struct pnv_phb *phb,
bool real_mode)
{
return real_mode ? (__be64 __iomem *)(phb->regs_phys + 0x210) :
(phb->regs + 0x210);
}
static void pnv_pci_p7ioc_tce_invalidate(struct iommu_table *tbl,
unsigned long index, unsigned long npages, bool rm)
{
struct iommu_table_group_link *tgl = list_first_entry_or_null(
&tbl->it_group_list, struct iommu_table_group_link,
next);
struct pnv_ioda_pe *pe = container_of(tgl->table_group,
struct pnv_ioda_pe, table_group);
__be64 __iomem *invalidate = pnv_ioda_get_inval_reg(pe->phb, rm);
unsigned long start, end, inc;
start = __pa(((__be64 *)tbl->it_base) + index - tbl->it_offset);
end = __pa(((__be64 *)tbl->it_base) + index - tbl->it_offset +
npages - 1);
start |= (1ull << 63);
end |= (1ull << 63);
inc = 16;
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
static int pnv_ioda1_tce_build(struct iommu_table *tbl, long index,
long npages, unsigned long uaddr,
enum dma_data_direction direction,
unsigned long attrs)
{
int ret = pnv_tce_build(tbl, index, npages, uaddr, direction,
attrs);
if (!ret)
pnv_pci_p7ioc_tce_invalidate(tbl, index, npages, false);
return ret;
}
static int pnv_ioda1_tce_xchg(struct iommu_table *tbl, long index,
unsigned long *hpa, enum dma_data_direction *direction)
{
long ret = pnv_tce_xchg(tbl, index, hpa, direction);
if (!ret)
pnv_pci_p7ioc_tce_invalidate(tbl, index, 1, false);
return ret;
}
static int pnv_ioda1_tce_xchg_rm(struct iommu_table *tbl, long index,
unsigned long *hpa, enum dma_data_direction *direction)
{
long ret = pnv_tce_xchg(tbl, index, hpa, direction);
if (!ret)
pnv_pci_p7ioc_tce_invalidate(tbl, index, 1, true);
return ret;
}
static void pnv_ioda1_tce_free(struct iommu_table *tbl, long index,
long npages)
{
pnv_tce_free(tbl, index, npages);
pnv_pci_p7ioc_tce_invalidate(tbl, index, npages, false);
}
static void pnv_pci_phb3_tce_invalidate_entire(struct pnv_phb *phb, bool rm)
{
__be64 __iomem *invalidate = pnv_ioda_get_inval_reg(phb, rm);
const unsigned long val = PHB3_TCE_KILL_INVAL_ALL;
mb();
if (rm)
__raw_rm_writeq(cpu_to_be64(val), invalidate);
else
__raw_writeq(cpu_to_be64(val), invalidate);
}
static inline void pnv_pci_phb3_tce_invalidate_pe(struct pnv_ioda_pe *pe)
{
__be64 __iomem *invalidate = pnv_ioda_get_inval_reg(pe->phb, false);
unsigned long val = PHB3_TCE_KILL_INVAL_PE | (pe->pe_number & 0xFF);
mb();
__raw_writeq(cpu_to_be64(val), invalidate);
}
static void pnv_pci_phb3_tce_invalidate(struct pnv_ioda_pe *pe, bool rm,
unsigned shift, unsigned long index,
unsigned long npages)
{
__be64 __iomem *invalidate = pnv_ioda_get_inval_reg(pe->phb, rm);
unsigned long start, end, inc;
start = PHB3_TCE_KILL_INVAL_ONE;
start |= (pe->pe_number & 0xFF);
end = start;
start |= (index << shift);
end |= ((index + npages - 1) << shift);
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
static inline void pnv_pci_ioda2_tce_invalidate_pe(struct pnv_ioda_pe *pe)
{
struct pnv_phb *phb = pe->phb;
if (phb->model == PNV_PHB_MODEL_PHB3 && phb->regs)
pnv_pci_phb3_tce_invalidate_pe(pe);
else
opal_pci_tce_kill(phb->opal_id, OPAL_PCI_TCE_KILL_PE,
pe->pe_number, 0, 0, 0);
}
static void pnv_pci_ioda2_tce_invalidate(struct iommu_table *tbl,
unsigned long index, unsigned long npages, bool rm)
{
struct iommu_table_group_link *tgl;
list_for_each_entry_lockless(tgl, &tbl->it_group_list, next) {
struct pnv_ioda_pe *pe = container_of(tgl->table_group,
struct pnv_ioda_pe, table_group);
struct pnv_phb *phb = pe->phb;
unsigned int shift = tbl->it_page_shift;
if (phb->model == PNV_PHB_MODEL_NPU) {
pnv_pci_phb3_tce_invalidate_entire(phb, rm);
continue;
}
if (phb->model == PNV_PHB_MODEL_PHB3 && phb->regs)
pnv_pci_phb3_tce_invalidate(pe, rm, shift,
index, npages);
else
opal_pci_tce_kill(phb->opal_id,
OPAL_PCI_TCE_KILL_PAGES,
pe->pe_number, 1u << shift,
index << shift, npages);
}
}
void pnv_pci_ioda2_tce_invalidate_entire(struct pnv_phb *phb, bool rm)
{
if (phb->model == PNV_PHB_MODEL_NPU || phb->model == PNV_PHB_MODEL_PHB3)
pnv_pci_phb3_tce_invalidate_entire(phb, rm);
else
opal_pci_tce_kill(phb->opal_id, OPAL_PCI_TCE_KILL, 0, 0, 0, 0);
}
static int pnv_ioda2_tce_build(struct iommu_table *tbl, long index,
long npages, unsigned long uaddr,
enum dma_data_direction direction,
unsigned long attrs)
{
int ret = pnv_tce_build(tbl, index, npages, uaddr, direction,
attrs);
if (!ret)
pnv_pci_ioda2_tce_invalidate(tbl, index, npages, false);
return ret;
}
static int pnv_ioda2_tce_xchg(struct iommu_table *tbl, long index,
unsigned long *hpa, enum dma_data_direction *direction)
{
long ret = pnv_tce_xchg(tbl, index, hpa, direction);
if (!ret)
pnv_pci_ioda2_tce_invalidate(tbl, index, 1, false);
return ret;
}
static int pnv_ioda2_tce_xchg_rm(struct iommu_table *tbl, long index,
unsigned long *hpa, enum dma_data_direction *direction)
{
long ret = pnv_tce_xchg(tbl, index, hpa, direction);
if (!ret)
pnv_pci_ioda2_tce_invalidate(tbl, index, 1, true);
return ret;
}
static void pnv_ioda2_tce_free(struct iommu_table *tbl, long index,
long npages)
{
pnv_tce_free(tbl, index, npages);
pnv_pci_ioda2_tce_invalidate(tbl, index, npages, false);
}
static void pnv_ioda2_table_free(struct iommu_table *tbl)
{
pnv_pci_ioda2_table_free_pages(tbl);
}
static int pnv_pci_ioda_dev_dma_weight(struct pci_dev *dev, void *data)
{
unsigned int *weight = (unsigned int *)data;
if (dev->hdr_type != PCI_HEADER_TYPE_NORMAL)
return 0;
if (dev->class == PCI_CLASS_SERIAL_USB_UHCI ||
dev->class == PCI_CLASS_SERIAL_USB_OHCI ||
dev->class == PCI_CLASS_SERIAL_USB_EHCI)
*weight += 3;
else if ((dev->class >> 8) == PCI_CLASS_STORAGE_RAID)
*weight += 15;
else
*weight += 10;
return 0;
}
static unsigned int pnv_pci_ioda_pe_dma_weight(struct pnv_ioda_pe *pe)
{
unsigned int weight = 0;
#ifdef CONFIG_PCI_IOV
if ((pe->flags & PNV_IODA_PE_VF) && pe->parent_dev) {
pnv_pci_ioda_dev_dma_weight(pe->parent_dev, &weight);
return weight;
}
#endif
if ((pe->flags & PNV_IODA_PE_DEV) && pe->pdev) {
pnv_pci_ioda_dev_dma_weight(pe->pdev, &weight);
} else if ((pe->flags & PNV_IODA_PE_BUS) && pe->pbus) {
struct pci_dev *pdev;
list_for_each_entry(pdev, &pe->pbus->devices, bus_list)
pnv_pci_ioda_dev_dma_weight(pdev, &weight);
} else if ((pe->flags & PNV_IODA_PE_BUS_ALL) && pe->pbus) {
pci_walk_bus(pe->pbus, pnv_pci_ioda_dev_dma_weight, &weight);
}
return weight;
}
static void pnv_pci_ioda1_setup_dma_pe(struct pnv_phb *phb,
struct pnv_ioda_pe *pe)
{
struct page *tce_mem = NULL;
struct iommu_table *tbl;
unsigned int weight, total_weight = 0;
unsigned int tce32_segsz, base, segs, avail, i;
int64_t rc;
void *addr;
weight = pnv_pci_ioda_pe_dma_weight(pe);
if (!weight)
return;
pci_walk_bus(phb->hose->bus, pnv_pci_ioda_dev_dma_weight,
&total_weight);
segs = (weight * phb->ioda.dma32_count) / total_weight;
if (!segs)
segs = 1;
do {
for (base = 0; base <= phb->ioda.dma32_count - segs; base++) {
for (avail = 0, i = base; i < base + segs; i++) {
if (phb->ioda.dma32_segmap[i] ==
IODA_INVALID_PE)
avail++;
}
if (avail == segs)
goto found;
}
} while (--segs);
if (!segs) {
pe_warn(pe, "No available DMA32 segments\n");
return;
}
found:
tbl = pnv_pci_table_alloc(phb->hose->node);
if (WARN_ON(!tbl))
return;
iommu_register_group(&pe->table_group, phb->hose->global_number,
pe->pe_number);
pnv_pci_link_table_and_group(phb->hose->node, 0, tbl, &pe->table_group);
pe_info(pe, "DMA weight %d (%d), assigned (%d) %d DMA32 segments\n",
weight, total_weight, base, segs);
pe_info(pe, " Setting up 32-bit TCE table at %08x..%08x\n",
base * PNV_IODA1_DMA32_SEGSIZE,
(base + segs) * PNV_IODA1_DMA32_SEGSIZE - 1);
tce32_segsz = PNV_IODA1_DMA32_SEGSIZE >> (IOMMU_PAGE_SHIFT_4K - 3);
tce_mem = alloc_pages_node(phb->hose->node, GFP_KERNEL,
get_order(tce32_segsz * segs));
if (!tce_mem) {
pe_err(pe, " Failed to allocate a 32-bit TCE memory\n");
goto fail;
}
addr = page_address(tce_mem);
memset(addr, 0, tce32_segsz * segs);
for (i = 0; i < segs; i++) {
rc = opal_pci_map_pe_dma_window(phb->opal_id,
pe->pe_number,
base + i, 1,
__pa(addr) + tce32_segsz * i,
tce32_segsz, IOMMU_PAGE_SIZE_4K);
if (rc) {
pe_err(pe, " Failed to configure 32-bit TCE table,"
" err %ld\n", rc);
goto fail;
}
}
for (i = base; i < base + segs; i++)
phb->ioda.dma32_segmap[i] = pe->pe_number;
pnv_pci_setup_iommu_table(tbl, addr, tce32_segsz * segs,
base * PNV_IODA1_DMA32_SEGSIZE,
IOMMU_PAGE_SHIFT_4K);
tbl->it_ops = &pnv_ioda1_iommu_ops;
pe->table_group.tce32_start = tbl->it_offset << tbl->it_page_shift;
pe->table_group.tce32_size = tbl->it_size << tbl->it_page_shift;
iommu_init_table(tbl, phb->hose->node);
if (pe->flags & PNV_IODA_PE_DEV) {
set_iommu_table_base(&pe->pdev->dev, tbl);
iommu_add_device(&pe->pdev->dev);
} else if (pe->flags & (PNV_IODA_PE_BUS | PNV_IODA_PE_BUS_ALL))
pnv_ioda_setup_bus_dma(pe, pe->pbus, true);
return;
fail:
if (tce_mem)
__free_pages(tce_mem, get_order(tce32_segsz * segs));
if (tbl) {
pnv_pci_unlink_table_and_group(tbl, &pe->table_group);
iommu_tce_table_put(tbl);
}
}
static long pnv_pci_ioda2_set_window(struct iommu_table_group *table_group,
int num, struct iommu_table *tbl)
{
struct pnv_ioda_pe *pe = container_of(table_group, struct pnv_ioda_pe,
table_group);
struct pnv_phb *phb = pe->phb;
int64_t rc;
const unsigned long size = tbl->it_indirect_levels ?
tbl->it_level_size : tbl->it_size;
const __u64 start_addr = tbl->it_offset << tbl->it_page_shift;
const __u64 win_size = tbl->it_size << tbl->it_page_shift;
pe_info(pe, "Setting up window#%d %llx..%llx pg=%x\n", num,
start_addr, start_addr + win_size - 1,
IOMMU_PAGE_SIZE(tbl));
rc = opal_pci_map_pe_dma_window(phb->opal_id,
pe->pe_number,
(pe->pe_number << 1) + num,
tbl->it_indirect_levels + 1,
__pa(tbl->it_base),
size << 3,
IOMMU_PAGE_SIZE(tbl));
if (rc) {
pe_err(pe, "Failed to configure TCE table, err %ld\n", rc);
return rc;
}
pnv_pci_link_table_and_group(phb->hose->node, num,
tbl, &pe->table_group);
pnv_pci_ioda2_tce_invalidate_pe(pe);
return 0;
}
void pnv_pci_ioda2_set_bypass(struct pnv_ioda_pe *pe, bool enable)
{
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
}
if (rc)
pe_err(pe, "OPAL error %lld configuring bypass window\n", rc);
else
pe->tce_bypass_enabled = enable;
}
static long pnv_pci_ioda2_create_table(struct iommu_table_group *table_group,
int num, __u32 page_shift, __u64 window_size, __u32 levels,
struct iommu_table **ptbl)
{
struct pnv_ioda_pe *pe = container_of(table_group, struct pnv_ioda_pe,
table_group);
int nid = pe->phb->hose->node;
__u64 bus_offset = num ? pe->tce_bypass_base : table_group->tce32_start;
long ret;
struct iommu_table *tbl;
tbl = pnv_pci_table_alloc(nid);
if (!tbl)
return -ENOMEM;
tbl->it_ops = &pnv_ioda2_iommu_ops;
ret = pnv_pci_ioda2_table_alloc_pages(nid,
bus_offset, page_shift, window_size,
levels, tbl);
if (ret) {
iommu_tce_table_put(tbl);
return ret;
}
*ptbl = tbl;
return 0;
}
static long pnv_pci_ioda2_setup_default_config(struct pnv_ioda_pe *pe)
{
struct iommu_table *tbl = NULL;
long rc;
const u64 max_memory = __rounddown_pow_of_two(memory_hotplug_max());
const u64 window_size = min((u64)pe->table_group.tce32_size, max_memory);
rc = pnv_pci_ioda2_create_table(&pe->table_group, 0,
IOMMU_PAGE_SHIFT_4K,
window_size,
POWERNV_IOMMU_DEFAULT_LEVELS, &tbl);
if (rc) {
pe_err(pe, "Failed to create 32-bit TCE table, err %ld",
rc);
return rc;
}
iommu_init_table(tbl, pe->phb->hose->node);
rc = pnv_pci_ioda2_set_window(&pe->table_group, 0, tbl);
if (rc) {
pe_err(pe, "Failed to configure 32-bit TCE table, err %ld\n",
rc);
iommu_tce_table_put(tbl);
return rc;
}
if (!pnv_iommu_bypass_disabled)
pnv_pci_ioda2_set_bypass(pe, true);
if (pe->flags & PNV_IODA_PE_DEV)
set_iommu_table_base(&pe->pdev->dev, tbl);
return 0;
}
static long pnv_pci_ioda2_unset_window(struct iommu_table_group *table_group,
int num)
{
struct pnv_ioda_pe *pe = container_of(table_group, struct pnv_ioda_pe,
table_group);
struct pnv_phb *phb = pe->phb;
long ret;
pe_info(pe, "Removing DMA window #%d\n", num);
ret = opal_pci_map_pe_dma_window(phb->opal_id, pe->pe_number,
(pe->pe_number << 1) + num,
0, 0,
0, 0);
if (ret)
pe_warn(pe, "Unmapping failed, ret = %ld\n", ret);
else
pnv_pci_ioda2_tce_invalidate_pe(pe);
pnv_pci_unlink_table_and_group(table_group->tables[num], table_group);
return ret;
}
static unsigned long pnv_pci_ioda2_get_table_size(__u32 page_shift,
__u64 window_size, __u32 levels)
{
unsigned long bytes = 0;
const unsigned window_shift = ilog2(window_size);
unsigned entries_shift = window_shift - page_shift;
unsigned table_shift = entries_shift + 3;
unsigned long tce_table_size = max(0x1000UL, 1UL << table_shift);
unsigned long direct_table_size;
if (!levels || (levels > POWERNV_IOMMU_MAX_LEVELS) ||
(window_size > memory_hotplug_max()) ||
!is_power_of_2(window_size))
return 0;
entries_shift = (entries_shift + levels - 1) / levels;
table_shift = entries_shift + 3;
table_shift = max_t(unsigned, table_shift, PAGE_SHIFT);
direct_table_size = 1UL << table_shift;
for ( ; levels; --levels) {
bytes += _ALIGN_UP(tce_table_size, direct_table_size);
tce_table_size /= direct_table_size;
tce_table_size <<= 3;
tce_table_size = max_t(unsigned long,
tce_table_size, direct_table_size);
}
return bytes;
}
static void pnv_ioda2_take_ownership(struct iommu_table_group *table_group)
{
struct pnv_ioda_pe *pe = container_of(table_group, struct pnv_ioda_pe,
table_group);
struct iommu_table *tbl = pe->table_group.tables[0];
pnv_pci_ioda2_set_bypass(pe, false);
pnv_pci_ioda2_unset_window(&pe->table_group, 0);
if (pe->pbus)
pnv_ioda_setup_bus_dma(pe, pe->pbus, false);
iommu_tce_table_put(tbl);
}
static void pnv_ioda2_release_ownership(struct iommu_table_group *table_group)
{
struct pnv_ioda_pe *pe = container_of(table_group, struct pnv_ioda_pe,
table_group);
pnv_pci_ioda2_setup_default_config(pe);
if (pe->pbus)
pnv_ioda_setup_bus_dma(pe, pe->pbus, false);
}
static int gpe_table_group_to_npe_cb(struct device *dev, void *opaque)
{
struct pci_controller *hose;
struct pnv_phb *phb;
struct pnv_ioda_pe **ptmppe = opaque;
struct pci_dev *pdev = container_of(dev, struct pci_dev, dev);
struct pci_dn *pdn = pci_get_pdn(pdev);
if (!pdn || pdn->pe_number == IODA_INVALID_PE)
return 0;
hose = pci_bus_to_host(pdev->bus);
phb = hose->private_data;
if (phb->type != PNV_PHB_NPU)
return 0;
*ptmppe = &phb->ioda.pe_array[pdn->pe_number];
return 1;
}
static struct pnv_ioda_pe *gpe_table_group_to_npe(
struct iommu_table_group *table_group)
{
struct pnv_ioda_pe *npe = NULL;
int ret = iommu_group_for_each_dev(table_group->group, &npe,
gpe_table_group_to_npe_cb);
BUG_ON(!ret || !npe);
return npe;
}
static long pnv_pci_ioda2_npu_set_window(struct iommu_table_group *table_group,
int num, struct iommu_table *tbl)
{
long ret = pnv_pci_ioda2_set_window(table_group, num, tbl);
if (ret)
return ret;
ret = pnv_npu_set_window(gpe_table_group_to_npe(table_group), num, tbl);
if (ret)
pnv_pci_ioda2_unset_window(table_group, num);
return ret;
}
static long pnv_pci_ioda2_npu_unset_window(
struct iommu_table_group *table_group,
int num)
{
long ret = pnv_pci_ioda2_unset_window(table_group, num);
if (ret)
return ret;
return pnv_npu_unset_window(gpe_table_group_to_npe(table_group), num);
}
static void pnv_ioda2_npu_take_ownership(struct iommu_table_group *table_group)
{
pnv_npu_take_ownership(gpe_table_group_to_npe(table_group));
pnv_ioda2_take_ownership(table_group);
}
static void pnv_pci_ioda_setup_iommu_api(void)
{
struct pci_controller *hose, *tmp;
struct pnv_phb *phb;
struct pnv_ioda_pe *pe, *gpe;
list_for_each_entry_safe(hose, tmp, &hose_list, list_node) {
phb = hose->private_data;
if (phb->type != PNV_PHB_NPU)
continue;
list_for_each_entry(pe, &phb->ioda.pe_list, list) {
gpe = pnv_pci_npu_setup_iommu(pe);
if (gpe)
gpe->table_group.ops = &pnv_pci_ioda2_npu_ops;
}
}
}
static void pnv_pci_ioda_setup_iommu_api(void) { }
static __be64 *pnv_pci_ioda2_table_do_alloc_pages(int nid, unsigned shift,
unsigned levels, unsigned long limit,
unsigned long *current_offset, unsigned long *total_allocated)
{
struct page *tce_mem = NULL;
__be64 *addr, *tmp;
unsigned order = max_t(unsigned, shift, PAGE_SHIFT) - PAGE_SHIFT;
unsigned long allocated = 1UL << (order + PAGE_SHIFT);
unsigned entries = 1UL << (shift - 3);
long i;
tce_mem = alloc_pages_node(nid, GFP_KERNEL, order);
if (!tce_mem) {
pr_err("Failed to allocate a TCE memory, order=%d\n", order);
return NULL;
}
addr = page_address(tce_mem);
memset(addr, 0, allocated);
*total_allocated += allocated;
--levels;
if (!levels) {
*current_offset += allocated;
return addr;
}
for (i = 0; i < entries; ++i) {
tmp = pnv_pci_ioda2_table_do_alloc_pages(nid, shift,
levels, limit, current_offset, total_allocated);
if (!tmp)
break;
addr[i] = cpu_to_be64(__pa(tmp) |
TCE_PCI_READ | TCE_PCI_WRITE);
if (*current_offset >= limit)
break;
}
return addr;
}
static long pnv_pci_ioda2_table_alloc_pages(int nid, __u64 bus_offset,
__u32 page_shift, __u64 window_size, __u32 levels,
struct iommu_table *tbl)
{
void *addr;
unsigned long offset = 0, level_shift, total_allocated = 0;
const unsigned window_shift = ilog2(window_size);
unsigned entries_shift = window_shift - page_shift;
unsigned table_shift = max_t(unsigned, entries_shift + 3, PAGE_SHIFT);
const unsigned long tce_table_size = 1UL << table_shift;
if (!levels || (levels > POWERNV_IOMMU_MAX_LEVELS))
return -EINVAL;
if ((window_size > memory_hotplug_max()) || !is_power_of_2(window_size))
return -EINVAL;
entries_shift = (entries_shift + levels - 1) / levels;
level_shift = entries_shift + 3;
level_shift = max_t(unsigned, level_shift, PAGE_SHIFT);
if ((level_shift - 3) * levels + page_shift >= 60)
return -EINVAL;
addr = pnv_pci_ioda2_table_do_alloc_pages(nid, level_shift,
levels, tce_table_size, &offset, &total_allocated);
if (!addr)
return -ENOMEM;
if (offset < tce_table_size) {
pnv_pci_ioda2_table_do_free_pages(addr,
1ULL << (level_shift - 3), levels - 1);
return -ENOMEM;
}
pnv_pci_setup_iommu_table(tbl, addr, tce_table_size, bus_offset,
page_shift);
tbl->it_level_size = 1ULL << (level_shift - 3);
tbl->it_indirect_levels = levels - 1;
tbl->it_allocated_size = total_allocated;
pr_devel("Created TCE table: ws=%08llx ts=%lx @%08llx\n",
window_size, tce_table_size, bus_offset);
return 0;
}
static void pnv_pci_ioda2_table_do_free_pages(__be64 *addr,
unsigned long size, unsigned level)
{
const unsigned long addr_ul = (unsigned long) addr &
~(TCE_PCI_READ | TCE_PCI_WRITE);
if (level) {
long i;
u64 *tmp = (u64 *) addr_ul;
for (i = 0; i < size; ++i) {
unsigned long hpa = be64_to_cpu(tmp[i]);
if (!(hpa & (TCE_PCI_READ | TCE_PCI_WRITE)))
continue;
pnv_pci_ioda2_table_do_free_pages(__va(hpa), size,
level - 1);
}
}
free_pages(addr_ul, get_order(size << 3));
}
static void pnv_pci_ioda2_table_free_pages(struct iommu_table *tbl)
{
const unsigned long size = tbl->it_indirect_levels ?
tbl->it_level_size : tbl->it_size;
if (!tbl->it_size)
return;
pnv_pci_ioda2_table_do_free_pages((__be64 *)tbl->it_base, size,
tbl->it_indirect_levels);
}
static void pnv_pci_ioda2_setup_dma_pe(struct pnv_phb *phb,
struct pnv_ioda_pe *pe)
{
int64_t rc;
if (!pnv_pci_ioda_pe_dma_weight(pe))
return;
pe->tce_bypass_base = 1ull << 59;
iommu_register_group(&pe->table_group, phb->hose->global_number,
pe->pe_number);
pe_info(pe, "Setting up 32-bit TCE table at 0..%08x\n",
phb->ioda.m32_pci_base);
pe->table_group.tce32_start = 0;
pe->table_group.tce32_size = phb->ioda.m32_pci_base;
pe->table_group.max_dynamic_windows_supported =
IOMMU_TABLE_GROUP_MAX_TABLES;
pe->table_group.max_levels = POWERNV_IOMMU_MAX_LEVELS;
pe->table_group.pgsizes = SZ_4K | SZ_64K | SZ_16M;
#ifdef CONFIG_IOMMU_API
pe->table_group.ops = &pnv_pci_ioda2_ops;
#endif
rc = pnv_pci_ioda2_setup_default_config(pe);
if (rc)
return;
if (pe->flags & (PNV_IODA_PE_BUS | PNV_IODA_PE_BUS_ALL))
pnv_ioda_setup_bus_dma(pe, pe->pbus, true);
}
int64_t pnv_opal_pci_msi_eoi(struct irq_chip *chip, unsigned int hw_irq)
{
struct pnv_phb *phb = container_of(chip, struct pnv_phb,
ioda.irq_chip);
return opal_pci_msi_eoi(phb->opal_id, hw_irq);
}
static void pnv_ioda2_msi_eoi(struct irq_data *d)
{
int64_t rc;
unsigned int hw_irq = (unsigned int)irqd_to_hwirq(d);
struct irq_chip *chip = irq_data_get_irq_chip(d);
rc = pnv_opal_pci_msi_eoi(chip, hw_irq);
WARN_ON_ONCE(rc);
icp_native_eoi(d);
}
void pnv_set_msi_irq_chip(struct pnv_phb *phb, unsigned int virq)
{
struct irq_data *idata;
struct irq_chip *ichip;
if (phb->model != PNV_PHB_MODEL_PHB3)
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
bool is_pnv_opal_msi(struct irq_chip *chip)
{
return chip->irq_eoi == pnv_ioda2_msi_eoi;
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
pnv_set_msi_irq_chip(phb, virq);
pr_devel("%s: %s-bit MSI on hwirq %x (xive #%d),"
" address=%x_%08x data=%x PE# %x\n",
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
static void pnv_pci_ioda_fixup_iov_resources(struct pci_dev *pdev)
{
struct pci_controller *hose = pci_bus_to_host(pdev->bus);
struct pnv_phb *phb = hose->private_data;
const resource_size_t gate = phb->ioda.m64_segsize >> 2;
struct resource *res;
int i;
resource_size_t size, total_vf_bar_sz;
struct pci_dn *pdn;
int mul, total_vfs;
if (!pdev->is_physfn || pdev->is_added)
return;
pdn = pci_get_pdn(pdev);
pdn->vfs_expanded = 0;
pdn->m64_single_mode = false;
total_vfs = pci_sriov_get_totalvfs(pdev);
mul = phb->ioda.total_pe_num;
total_vf_bar_sz = 0;
for (i = 0; i < PCI_SRIOV_NUM_BARS; i++) {
res = &pdev->resource[i + PCI_IOV_RESOURCES];
if (!res->flags || res->parent)
continue;
if (!pnv_pci_is_m64_flags(res->flags)) {
dev_warn(&pdev->dev, "Don't support SR-IOV with"
" non M64 VF BAR%d: %pR. \n",
i, res);
goto truncate_iov;
}
total_vf_bar_sz += pci_iov_resource_size(pdev,
i + PCI_IOV_RESOURCES);
if (total_vf_bar_sz > gate) {
mul = roundup_pow_of_two(total_vfs);
dev_info(&pdev->dev,
"VF BAR Total IOV size %llx > %llx, roundup to %d VFs\n",
total_vf_bar_sz, gate, mul);
pdn->m64_single_mode = true;
break;
}
}
for (i = 0; i < PCI_SRIOV_NUM_BARS; i++) {
res = &pdev->resource[i + PCI_IOV_RESOURCES];
if (!res->flags || res->parent)
continue;
size = pci_iov_resource_size(pdev, i + PCI_IOV_RESOURCES);
if (pdn->m64_single_mode && (size < SZ_32M))
goto truncate_iov;
dev_dbg(&pdev->dev, " Fixing VF BAR%d: %pR to\n", i, res);
res->end = res->start + size * mul - 1;
dev_dbg(&pdev->dev, " %pR\n", res);
dev_info(&pdev->dev, "VF BAR%d: %pR (expanded to %d VFs for PE alignment)",
i, res, mul);
}
pdn->vfs_expanded = mul;
return;
truncate_iov:
for (i = 0; i < PCI_SRIOV_NUM_BARS; i++) {
res = &pdev->resource[i + PCI_IOV_RESOURCES];
res->flags = 0;
res->end = res->start - 1;
}
}
static void pnv_ioda_setup_pe_res(struct pnv_ioda_pe *pe,
struct resource *res)
{
struct pnv_phb *phb = pe->phb;
struct pci_bus_region region;
int index;
int64_t rc;
if (!res || !res->flags || res->start > res->end)
return;
if (res->flags & IORESOURCE_IO) {
region.start = res->start - phb->ioda.io_pci_base;
region.end = res->end - phb->ioda.io_pci_base;
index = region.start / phb->ioda.io_segsize;
while (index < phb->ioda.total_pe_num &&
region.start <= region.end) {
phb->ioda.io_segmap[index] = pe->pe_number;
rc = opal_pci_map_pe_mmio_window(phb->opal_id,
pe->pe_number, OPAL_IO_WINDOW_TYPE, 0, index);
if (rc != OPAL_SUCCESS) {
pr_err("%s: Error %lld mapping IO segment#%d to PE#%x\n",
__func__, rc, index, pe->pe_number);
break;
}
region.start += phb->ioda.io_segsize;
index++;
}
} else if ((res->flags & IORESOURCE_MEM) &&
!pnv_pci_is_m64(phb, res)) {
region.start = res->start -
phb->hose->mem_offset[0] -
phb->ioda.m32_pci_base;
region.end = res->end -
phb->hose->mem_offset[0] -
phb->ioda.m32_pci_base;
index = region.start / phb->ioda.m32_segsize;
while (index < phb->ioda.total_pe_num &&
region.start <= region.end) {
phb->ioda.m32_segmap[index] = pe->pe_number;
rc = opal_pci_map_pe_mmio_window(phb->opal_id,
pe->pe_number, OPAL_M32_WINDOW_TYPE, 0, index);
if (rc != OPAL_SUCCESS) {
pr_err("%s: Error %lld mapping M32 segment#%d to PE#%x",
__func__, rc, index, pe->pe_number);
break;
}
region.start += phb->ioda.m32_segsize;
index++;
}
}
}
static void pnv_ioda_setup_pe_seg(struct pnv_ioda_pe *pe)
{
struct pci_dev *pdev;
int i;
BUG_ON(!(pe->flags & (PNV_IODA_PE_BUS | PNV_IODA_PE_BUS_ALL)));
list_for_each_entry(pdev, &pe->pbus->devices, bus_list) {
for (i = 0; i <= PCI_ROM_RESOURCE; i++)
pnv_ioda_setup_pe_res(pe, &pdev->resource[i]);
if (!(pe->flags & PNV_IODA_PE_BUS_ALL) || !pci_is_bridge(pdev))
continue;
for (i = 0; i < PCI_BRIDGE_RESOURCE_NUM; i++)
pnv_ioda_setup_pe_res(pe,
&pdev->resource[PCI_BRIDGE_RESOURCES + i]);
}
}
static int pnv_pci_diag_data_set(void *data, u64 val)
{
struct pci_controller *hose;
struct pnv_phb *phb;
s64 ret;
if (val != 1ULL)
return -EINVAL;
hose = (struct pci_controller *)data;
if (!hose || !hose->private_data)
return -ENODEV;
phb = hose->private_data;
ret = opal_pci_get_phb_diag_data2(phb->opal_id, phb->diag_data,
phb->diag_data_size);
if (ret != OPAL_SUCCESS)
return -EIO;
pnv_pci_dump_phb_diag_data(phb->hose, phb->diag_data);
return 0;
}
static void pnv_pci_ioda_create_dbgfs(void)
{
#ifdef CONFIG_DEBUG_FS
struct pci_controller *hose, *tmp;
struct pnv_phb *phb;
char name[16];
list_for_each_entry_safe(hose, tmp, &hose_list, list_node) {
phb = hose->private_data;
phb->initialized = 1;
sprintf(name, "PCI%04x", hose->global_number);
phb->dbgfs = debugfs_create_dir(name, powerpc_debugfs_root);
if (!phb->dbgfs) {
pr_warning("%s: Error on creating debugfs on PHB#%x\n",
__func__, hose->global_number);
continue;
}
debugfs_create_file("dump_diag_regs", 0200, phb->dbgfs, hose,
&pnv_pci_diag_data_fops);
}
#endif
}
static void pnv_pci_ioda_fixup(void)
{
pnv_pci_ioda_setup_PEs();
pnv_pci_ioda_setup_iommu_api();
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
if (phb->ioda.m64_segsize && pnv_pci_is_m64_flags(type))
return phb->ioda.m64_segsize;
if (type & IORESOURCE_MEM)
return phb->ioda.m32_segsize;
return phb->ioda.io_segsize;
}
static void pnv_pci_fixup_bridge_resources(struct pci_bus *bus,
unsigned long type)
{
struct pci_controller *hose = pci_bus_to_host(bus);
struct pnv_phb *phb = hose->private_data;
struct pci_dev *bridge = bus->self;
struct resource *r, *w;
bool msi_region = false;
int i;
if (!pci_is_root_bus(bridge->bus) &&
!pci_is_root_bus(bridge->bus->self->bus))
return;
for (i = 0; i < PCI_BRIDGE_RESOURCE_NUM; i++) {
r = &bridge->resource[PCI_BRIDGE_RESOURCES + i];
if (!r->flags || !r->parent)
continue;
w = NULL;
if (r->flags & type & IORESOURCE_IO)
w = &hose->io_resource;
else if (pnv_pci_is_m64(phb, r) &&
(type & IORESOURCE_PREFETCH) &&
phb->ioda.m64_segsize)
w = &hose->mem_resources[1];
else if (r->flags & type & IORESOURCE_MEM) {
w = &hose->mem_resources[0];
msi_region = true;
}
r->start = w->start;
r->end = w->end;
if (msi_region) {
r->end += 0x10000;
r->end -= 0x100000;
}
}
}
static void pnv_pci_setup_bridge(struct pci_bus *bus, unsigned long type)
{
struct pci_controller *hose = pci_bus_to_host(bus);
struct pnv_phb *phb = hose->private_data;
struct pci_dev *bridge = bus->self;
struct pnv_ioda_pe *pe;
bool all = (pci_pcie_type(bridge) == PCI_EXP_TYPE_PCI_BRIDGE);
pnv_pci_fixup_bridge_resources(bus, type);
if (!phb->ioda.root_pe_populated) {
pe = pnv_ioda_setup_bus_PE(phb->hose->bus, false);
if (pe) {
phb->ioda.root_pe_idx = pe->pe_number;
phb->ioda.root_pe_populated = true;
}
}
if (list_empty(&bus->devices))
return;
if (phb->reserve_m64_pe)
phb->reserve_m64_pe(bus, NULL, all);
pe = pnv_ioda_setup_bus_PE(bus, all);
if (!pe)
return;
pnv_ioda_setup_pe_seg(pe);
switch (phb->type) {
case PNV_PHB_IODA1:
pnv_pci_ioda1_setup_dma_pe(phb, pe);
break;
case PNV_PHB_IODA2:
pnv_pci_ioda2_setup_dma_pe(phb, pe);
break;
default:
pr_warn("%s: No DMA for PHB#%x (type %d)\n",
__func__, phb->hose->global_number, phb->type);
}
}
static resource_size_t pnv_pci_default_alignment(void)
{
return PAGE_SIZE;
}
static resource_size_t pnv_pci_iov_resource_alignment(struct pci_dev *pdev,
int resno)
{
struct pci_controller *hose = pci_bus_to_host(pdev->bus);
struct pnv_phb *phb = hose->private_data;
struct pci_dn *pdn = pci_get_pdn(pdev);
resource_size_t align;
align = pci_iov_resource_size(pdev, resno);
if (!pdn->vfs_expanded)
return align;
if (pdn->m64_single_mode)
return max(align, (resource_size_t)phb->ioda.m64_segsize);
return pdn->vfs_expanded * align;
}
bool pnv_pci_enable_device_hook(struct pci_dev *dev)
{
struct pci_controller *hose = pci_bus_to_host(dev->bus);
struct pnv_phb *phb = hose->private_data;
struct pci_dn *pdn;
if (!phb->initialized)
return true;
pdn = pci_get_pdn(dev);
if (!pdn || pdn->pe_number == IODA_INVALID_PE)
return false;
return true;
}
static long pnv_pci_ioda1_unset_window(struct iommu_table_group *table_group,
int num)
{
struct pnv_ioda_pe *pe = container_of(table_group,
struct pnv_ioda_pe, table_group);
struct pnv_phb *phb = pe->phb;
unsigned int idx;
long rc;
pe_info(pe, "Removing DMA window #%d\n", num);
for (idx = 0; idx < phb->ioda.dma32_count; idx++) {
if (phb->ioda.dma32_segmap[idx] != pe->pe_number)
continue;
rc = opal_pci_map_pe_dma_window(phb->opal_id, pe->pe_number,
idx, 0, 0ul, 0ul, 0ul);
if (rc != OPAL_SUCCESS) {
pe_warn(pe, "Failure %ld unmapping DMA32 segment#%d\n",
rc, idx);
return rc;
}
phb->ioda.dma32_segmap[idx] = IODA_INVALID_PE;
}
pnv_pci_unlink_table_and_group(table_group->tables[num], table_group);
return OPAL_SUCCESS;
}
static void pnv_pci_ioda1_release_pe_dma(struct pnv_ioda_pe *pe)
{
unsigned int weight = pnv_pci_ioda_pe_dma_weight(pe);
struct iommu_table *tbl = pe->table_group.tables[0];
int64_t rc;
if (!weight)
return;
rc = pnv_pci_ioda1_unset_window(&pe->table_group, 0);
if (rc != OPAL_SUCCESS)
return;
pnv_pci_p7ioc_tce_invalidate(tbl, tbl->it_offset, tbl->it_size, false);
if (pe->table_group.group) {
iommu_group_put(pe->table_group.group);
WARN_ON(pe->table_group.group);
}
free_pages(tbl->it_base, get_order(tbl->it_size << 3));
iommu_tce_table_put(tbl);
}
static void pnv_pci_ioda2_release_pe_dma(struct pnv_ioda_pe *pe)
{
struct iommu_table *tbl = pe->table_group.tables[0];
unsigned int weight = pnv_pci_ioda_pe_dma_weight(pe);
#ifdef CONFIG_IOMMU_API
int64_t rc;
#endif
if (!weight)
return;
#ifdef CONFIG_IOMMU_API
rc = pnv_pci_ioda2_unset_window(&pe->table_group, 0);
if (rc)
pe_warn(pe, "OPAL error %ld release DMA window\n", rc);
#endif
pnv_pci_ioda2_set_bypass(pe, false);
if (pe->table_group.group) {
iommu_group_put(pe->table_group.group);
WARN_ON(pe->table_group.group);
}
pnv_pci_ioda2_table_free_pages(tbl);
iommu_tce_table_put(tbl);
}
static void pnv_ioda_free_pe_seg(struct pnv_ioda_pe *pe,
unsigned short win,
unsigned int *map)
{
struct pnv_phb *phb = pe->phb;
int idx;
int64_t rc;
for (idx = 0; idx < phb->ioda.total_pe_num; idx++) {
if (map[idx] != pe->pe_number)
continue;
if (win == OPAL_M64_WINDOW_TYPE)
rc = opal_pci_map_pe_mmio_window(phb->opal_id,
phb->ioda.reserved_pe_idx, win,
idx / PNV_IODA1_M64_SEGS,
idx % PNV_IODA1_M64_SEGS);
else
rc = opal_pci_map_pe_mmio_window(phb->opal_id,
phb->ioda.reserved_pe_idx, win, 0, idx);
if (rc != OPAL_SUCCESS)
pe_warn(pe, "Error %ld unmapping (%d) segment#%d\n",
rc, win, idx);
map[idx] = IODA_INVALID_PE;
}
}
static void pnv_ioda_release_pe_seg(struct pnv_ioda_pe *pe)
{
struct pnv_phb *phb = pe->phb;
if (phb->type == PNV_PHB_IODA1) {
pnv_ioda_free_pe_seg(pe, OPAL_IO_WINDOW_TYPE,
phb->ioda.io_segmap);
pnv_ioda_free_pe_seg(pe, OPAL_M32_WINDOW_TYPE,
phb->ioda.m32_segmap);
pnv_ioda_free_pe_seg(pe, OPAL_M64_WINDOW_TYPE,
phb->ioda.m64_segmap);
} else if (phb->type == PNV_PHB_IODA2) {
pnv_ioda_free_pe_seg(pe, OPAL_M32_WINDOW_TYPE,
phb->ioda.m32_segmap);
}
}
static void pnv_ioda_release_pe(struct pnv_ioda_pe *pe)
{
struct pnv_phb *phb = pe->phb;
struct pnv_ioda_pe *slave, *tmp;
list_del(&pe->list);
switch (phb->type) {
case PNV_PHB_IODA1:
pnv_pci_ioda1_release_pe_dma(pe);
break;
case PNV_PHB_IODA2:
pnv_pci_ioda2_release_pe_dma(pe);
break;
default:
WARN_ON(1);
}
pnv_ioda_release_pe_seg(pe);
pnv_ioda_deconfigure_pe(pe->phb, pe);
if (pe->flags & PNV_IODA_PE_MASTER) {
list_for_each_entry_safe(slave, tmp, &pe->slaves, list) {
list_del(&slave->list);
pnv_ioda_free_pe(slave);
}
}
if (phb->ioda.root_pe_populated &&
phb->ioda.root_pe_idx == pe->pe_number)
phb->ioda.root_pe_populated = false;
else
pnv_ioda_free_pe(pe);
}
static void pnv_pci_release_device(struct pci_dev *pdev)
{
struct pci_controller *hose = pci_bus_to_host(pdev->bus);
struct pnv_phb *phb = hose->private_data;
struct pci_dn *pdn = pci_get_pdn(pdev);
struct pnv_ioda_pe *pe;
if (pdev->is_virtfn)
return;
if (!pdn || pdn->pe_number == IODA_INVALID_PE)
return;
pe = &phb->ioda.pe_array[pdn->pe_number];
pdn->pe_number = IODA_INVALID_PE;
WARN_ON(--pe->device_count < 0);
if (pe->device_count == 0)
pnv_ioda_release_pe(pe);
}
static void pnv_pci_ioda_shutdown(struct pci_controller *hose)
{
struct pnv_phb *phb = hose->private_data;
opal_pci_reset(phb->opal_id, OPAL_RESET_PCI_IODA_TABLE,
OPAL_ASSERT_RESET);
}
static int pnv_npu_dma_set_mask(struct pci_dev *npdev, u64 dma_mask)
{
dev_err_once(&npdev->dev,
"%s operation unsupported for NVLink devices\n",
__func__);
return -EPERM;
}
static void __init pnv_pci_init_ioda_phb(struct device_node *np,
u64 hub_id, int ioda_type)
{
struct pci_controller *hose;
struct pnv_phb *phb;
unsigned long size, m64map_off, m32map_off, pemap_off;
unsigned long iomap_off = 0, dma32map_off = 0;
struct resource r;
const __be64 *prop64;
const __be32 *prop32;
int len;
unsigned int segno;
u64 phb_id;
void *aux;
long rc;
if (!of_device_is_available(np))
return;
pr_info("Initializing %s PHB (%pOF)\n", pnv_phb_names[ioda_type], np);
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
pr_err(" Can't allocate PCI controller for %pOF\n",
np);
memblock_free(__pa(phb), sizeof(struct pnv_phb));
return;
}
spin_lock_init(&phb->lock);
prop32 = of_get_property(np, "bus-range", &len);
if (prop32 && len == 8) {
hose->first_busno = be32_to_cpu(prop32[0]);
hose->last_busno = be32_to_cpu(prop32[1]);
} else {
pr_warn(" Broken <bus-range> on %pOF\n", np);
hose->first_busno = 0;
hose->last_busno = 0xff;
}
hose->private_data = phb;
phb->hub_id = hub_id;
phb->opal_id = phb_id;
phb->type = ioda_type;
mutex_init(&phb->ioda.pe_alloc_mutex);
if (of_device_is_compatible(np, "ibm,p7ioc-pciex"))
phb->model = PNV_PHB_MODEL_P7IOC;
else if (of_device_is_compatible(np, "ibm,power8-pciex"))
phb->model = PNV_PHB_MODEL_PHB3;
else if (of_device_is_compatible(np, "ibm,power8-npu-pciex"))
phb->model = PNV_PHB_MODEL_NPU;
else if (of_device_is_compatible(np, "ibm,power9-npu-pciex"))
phb->model = PNV_PHB_MODEL_NPU2;
else
phb->model = PNV_PHB_MODEL_UNKNOWN;
prop32 = of_get_property(np, "ibm,phb-diag-data-size", NULL);
if (prop32)
phb->diag_data_size = be32_to_cpup(prop32);
else
phb->diag_data_size = PNV_PCI_DIAG_BUF_SIZE;
phb->diag_data = memblock_virt_alloc(phb->diag_data_size, 0);
pci_process_bridge_OF_ranges(hose, np, !hose->global_number);
if (!of_address_to_resource(np, 0, &r)) {
phb->regs_phys = r.start;
phb->regs = ioremap(r.start, resource_size(&r));
if (phb->regs == NULL)
pr_err(" Failed to map registers !\n");
}
phb->ioda.total_pe_num = 1;
prop32 = of_get_property(np, "ibm,opal-num-pes", NULL);
if (prop32)
phb->ioda.total_pe_num = be32_to_cpup(prop32);
prop32 = of_get_property(np, "ibm,opal-reserved-pe", NULL);
if (prop32)
phb->ioda.reserved_pe_idx = be32_to_cpup(prop32);
for (segno = 0; segno < ARRAY_SIZE(phb->ioda.pe_rmap); segno++)
phb->ioda.pe_rmap[segno] = IODA_INVALID_PE;
pnv_ioda_parse_m64_window(phb);
phb->ioda.m32_size = resource_size(&hose->mem_resources[0]);
phb->ioda.m32_size += 0x10000;
phb->ioda.m32_segsize = phb->ioda.m32_size / phb->ioda.total_pe_num;
phb->ioda.m32_pci_base = hose->mem_resources[0].start - hose->mem_offset[0];
phb->ioda.io_size = hose->pci_io_size;
phb->ioda.io_segsize = phb->ioda.io_size / phb->ioda.total_pe_num;
phb->ioda.io_pci_base = 0;
phb->ioda.dma32_count = phb->ioda.m32_pci_base /
PNV_IODA1_DMA32_SEGSIZE;
size = _ALIGN_UP(max_t(unsigned, phb->ioda.total_pe_num, 8) / 8,
sizeof(unsigned long));
m64map_off = size;
size += phb->ioda.total_pe_num * sizeof(phb->ioda.m64_segmap[0]);
m32map_off = size;
size += phb->ioda.total_pe_num * sizeof(phb->ioda.m32_segmap[0]);
if (phb->type == PNV_PHB_IODA1) {
iomap_off = size;
size += phb->ioda.total_pe_num * sizeof(phb->ioda.io_segmap[0]);
dma32map_off = size;
size += phb->ioda.dma32_count *
sizeof(phb->ioda.dma32_segmap[0]);
}
pemap_off = size;
size += phb->ioda.total_pe_num * sizeof(struct pnv_ioda_pe);
aux = memblock_virt_alloc(size, 0);
phb->ioda.pe_alloc = aux;
phb->ioda.m64_segmap = aux + m64map_off;
phb->ioda.m32_segmap = aux + m32map_off;
for (segno = 0; segno < phb->ioda.total_pe_num; segno++) {
phb->ioda.m64_segmap[segno] = IODA_INVALID_PE;
phb->ioda.m32_segmap[segno] = IODA_INVALID_PE;
}
if (phb->type == PNV_PHB_IODA1) {
phb->ioda.io_segmap = aux + iomap_off;
for (segno = 0; segno < phb->ioda.total_pe_num; segno++)
phb->ioda.io_segmap[segno] = IODA_INVALID_PE;
phb->ioda.dma32_segmap = aux + dma32map_off;
for (segno = 0; segno < phb->ioda.dma32_count; segno++)
phb->ioda.dma32_segmap[segno] = IODA_INVALID_PE;
}
phb->ioda.pe_array = aux + pemap_off;
pnv_ioda_reserve_pe(phb, phb->ioda.reserved_pe_idx);
if (phb->ioda.reserved_pe_idx == 0) {
phb->ioda.root_pe_idx = 1;
pnv_ioda_reserve_pe(phb, phb->ioda.root_pe_idx);
} else if (phb->ioda.reserved_pe_idx == (phb->ioda.total_pe_num - 1)) {
phb->ioda.root_pe_idx = phb->ioda.reserved_pe_idx - 1;
pnv_ioda_reserve_pe(phb, phb->ioda.root_pe_idx);
} else {
phb->ioda.root_pe_idx = IODA_INVALID_PE;
}
INIT_LIST_HEAD(&phb->ioda.pe_list);
mutex_init(&phb->ioda.pe_list_mutex);
phb->ioda.dma32_count = phb->ioda.m32_pci_base /
PNV_IODA1_DMA32_SEGSIZE;
#if 0
rc = opal_pci_set_phb_mem_window(opal->phb_id,
window_type,
window_num,
starting_real_address,
starting_pci_address,
segment_size);
#endif
pr_info(" %03d (%03d) PE's M32: 0x%x [segment=0x%x]\n",
phb->ioda.total_pe_num, phb->ioda.reserved_pe_idx,
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
pnv_pci_init_ioda_msis(phb);
ppc_md.pcibios_fixup = pnv_pci_ioda_fixup;
if (phb->type == PNV_PHB_NPU) {
hose->controller_ops = pnv_npu_ioda_controller_ops;
} else {
phb->dma_dev_setup = pnv_pci_ioda_dma_dev_setup;
hose->controller_ops = pnv_pci_ioda_controller_ops;
}
ppc_md.pcibios_default_alignment = pnv_pci_default_alignment;
#ifdef CONFIG_PCI_IOV
ppc_md.pcibios_fixup_sriov = pnv_pci_ioda_fixup_iov_resources;
ppc_md.pcibios_iov_resource_alignment = pnv_pci_iov_resource_alignment;
#endif
pci_add_flags(PCI_REASSIGN_ALL_RSRC);
rc = opal_pci_reset(phb_id, OPAL_RESET_PCI_IODA_TABLE, OPAL_ASSERT_RESET);
if (rc)
pr_warning(" OPAL Error %ld performing IODA table reset !\n", rc);
if (is_kdump_kernel()) {
pr_info(" Issue PHB reset ...\n");
pnv_eeh_phb_reset(hose, EEH_RESET_FUNDAMENTAL);
pnv_eeh_phb_reset(hose, EEH_RESET_DEACTIVATE);
}
if (!phb->init_m64 || phb->init_m64(phb))
hose->mem_resources[1].flags = 0;
}
void __init pnv_pci_init_ioda2_phb(struct device_node *np)
{
pnv_pci_init_ioda_phb(np, 0, PNV_PHB_IODA2);
}
void __init pnv_pci_init_npu_phb(struct device_node *np)
{
pnv_pci_init_ioda_phb(np, 0, PNV_PHB_NPU);
}
void __init pnv_pci_init_ioda_hub(struct device_node *np)
{
struct device_node *phbn;
const __be64 *prop64;
u64 hub_id;
pr_info("Probing IODA IO-Hub %pOF\n", np);
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
