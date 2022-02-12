void eeh_set_pe_aux_size(int size)
{
if (size < 0)
return;
eeh_pe_aux_size = size;
}
static struct eeh_pe *eeh_pe_alloc(struct pci_controller *phb, int type)
{
struct eeh_pe *pe;
size_t alloc_size;
alloc_size = sizeof(struct eeh_pe);
if (eeh_pe_aux_size) {
alloc_size = ALIGN(alloc_size, cache_line_size());
alloc_size += eeh_pe_aux_size;
}
pe = kzalloc(alloc_size, GFP_KERNEL);
if (!pe) return NULL;
pe->type = type;
pe->phb = phb;
INIT_LIST_HEAD(&pe->child_list);
INIT_LIST_HEAD(&pe->child);
INIT_LIST_HEAD(&pe->edevs);
pe->data = (void *)pe + ALIGN(sizeof(struct eeh_pe),
cache_line_size());
return pe;
}
int eeh_phb_pe_create(struct pci_controller *phb)
{
struct eeh_pe *pe;
pe = eeh_pe_alloc(phb, EEH_PE_PHB);
if (!pe) {
pr_err("%s: out of memory!\n", __func__);
return -ENOMEM;
}
list_add_tail(&pe->child, &eeh_phb_pe);
pr_debug("EEH: Add PE for PHB#%d\n", phb->global_number);
return 0;
}
struct eeh_pe *eeh_phb_pe_get(struct pci_controller *phb)
{
struct eeh_pe *pe;
list_for_each_entry(pe, &eeh_phb_pe, child) {
if ((pe->type & EEH_PE_PHB) && pe->phb == phb)
return pe;
}
return NULL;
}
static struct eeh_pe *eeh_pe_next(struct eeh_pe *pe,
struct eeh_pe *root)
{
struct list_head *next = pe->child_list.next;
if (next == &pe->child_list) {
while (1) {
if (pe == root)
return NULL;
next = pe->child.next;
if (next != &pe->parent->child_list)
break;
pe = pe->parent;
}
}
return list_entry(next, struct eeh_pe, child);
}
void *eeh_pe_traverse(struct eeh_pe *root,
eeh_traverse_func fn, void *flag)
{
struct eeh_pe *pe;
void *ret;
for (pe = root; pe; pe = eeh_pe_next(pe, root)) {
ret = fn(pe, flag);
if (ret) return ret;
}
return NULL;
}
void *eeh_pe_dev_traverse(struct eeh_pe *root,
eeh_traverse_func fn, void *flag)
{
struct eeh_pe *pe;
struct eeh_dev *edev, *tmp;
void *ret;
if (!root) {
pr_warn("%s: Invalid PE %p\n",
__func__, root);
return NULL;
}
for (pe = root; pe; pe = eeh_pe_next(pe, root)) {
eeh_pe_for_each_dev(pe, edev, tmp) {
ret = fn(edev, flag);
if (ret)
return ret;
}
}
return NULL;
}
static void *__eeh_pe_get(void *data, void *flag)
{
struct eeh_pe *pe = (struct eeh_pe *)data;
struct eeh_dev *edev = (struct eeh_dev *)flag;
if (pe->type & EEH_PE_PHB)
return NULL;
if (eeh_has_flag(EEH_VALID_PE_ZERO)) {
if (edev->pe_config_addr == pe->addr)
return pe;
} else {
if (edev->pe_config_addr &&
(edev->pe_config_addr == pe->addr))
return pe;
}
if (edev->config_addr &&
(edev->config_addr == pe->config_addr))
return pe;
return NULL;
}
struct eeh_pe *eeh_pe_get(struct eeh_dev *edev)
{
struct eeh_pe *root = eeh_phb_pe_get(edev->phb);
struct eeh_pe *pe;
pe = eeh_pe_traverse(root, __eeh_pe_get, edev);
return pe;
}
static struct eeh_pe *eeh_pe_get_parent(struct eeh_dev *edev)
{
struct device_node *dn;
struct eeh_dev *parent;
dn = edev->dn->parent;
while (dn) {
if (!PCI_DN(dn)) return NULL;
parent = of_node_to_eeh_dev(dn);
if (!parent) return NULL;
if (parent->pe)
return parent->pe;
dn = dn->parent;
}
return NULL;
}
int eeh_add_to_parent_pe(struct eeh_dev *edev)
{
struct eeh_pe *pe, *parent;
pe = eeh_pe_get(edev);
if (pe && !(pe->type & EEH_PE_INVALID)) {
if (!edev->pe_config_addr) {
pr_err("%s: PE with addr 0x%x already exists\n",
__func__, edev->config_addr);
return -EEXIST;
}
pe->type = EEH_PE_BUS;
edev->pe = pe;
list_add_tail(&edev->list, &pe->edevs);
pr_debug("EEH: Add %s to Bus PE#%x\n",
edev->dn->full_name, pe->addr);
return 0;
} else if (pe && (pe->type & EEH_PE_INVALID)) {
list_add_tail(&edev->list, &pe->edevs);
edev->pe = pe;
parent = pe;
while (parent) {
if (!(parent->type & EEH_PE_INVALID))
break;
parent->type &= ~(EEH_PE_INVALID | EEH_PE_KEEP);
parent = parent->parent;
}
pr_debug("EEH: Add %s to Device PE#%x, Parent PE#%x\n",
edev->dn->full_name, pe->addr, pe->parent->addr);
return 0;
}
pe = eeh_pe_alloc(edev->phb, EEH_PE_DEVICE);
if (!pe) {
pr_err("%s: out of memory!\n", __func__);
return -ENOMEM;
}
pe->addr = edev->pe_config_addr;
pe->config_addr = edev->config_addr;
parent = eeh_pe_get_parent(edev);
if (!parent) {
parent = eeh_phb_pe_get(edev->phb);
if (!parent) {
pr_err("%s: No PHB PE is found (PHB Domain=%d)\n",
__func__, edev->phb->global_number);
edev->pe = NULL;
kfree(pe);
return -EEXIST;
}
}
pe->parent = parent;
list_add_tail(&pe->child, &parent->child_list);
list_add_tail(&edev->list, &pe->edevs);
edev->pe = pe;
pr_debug("EEH: Add %s to Device PE#%x, Parent PE#%x\n",
edev->dn->full_name, pe->addr, pe->parent->addr);
return 0;
}
int eeh_rmv_from_parent_pe(struct eeh_dev *edev)
{
struct eeh_pe *pe, *parent, *child;
int cnt;
if (!edev->pe) {
pr_debug("%s: No PE found for EEH device %s\n",
__func__, edev->dn->full_name);
return -EEXIST;
}
pe = eeh_dev_to_pe(edev);
edev->pe = NULL;
list_del(&edev->list);
while (1) {
parent = pe->parent;
if (pe->type & EEH_PE_PHB)
break;
if (!(pe->state & EEH_PE_KEEP)) {
if (list_empty(&pe->edevs) &&
list_empty(&pe->child_list)) {
list_del(&pe->child);
kfree(pe);
} else {
break;
}
} else {
if (list_empty(&pe->edevs)) {
cnt = 0;
list_for_each_entry(child, &pe->child_list, child) {
if (!(child->type & EEH_PE_INVALID)) {
cnt++;
break;
}
}
if (!cnt)
pe->type |= EEH_PE_INVALID;
else
break;
}
}
pe = parent;
}
return 0;
}
void eeh_pe_update_time_stamp(struct eeh_pe *pe)
{
struct timeval tstamp;
if (!pe) return;
if (pe->freeze_count <= 0) {
pe->freeze_count = 0;
do_gettimeofday(&pe->tstamp);
} else {
do_gettimeofday(&tstamp);
if (tstamp.tv_sec - pe->tstamp.tv_sec > 3600) {
pe->tstamp = tstamp;
pe->freeze_count = 0;
}
}
}
static void *__eeh_pe_state_mark(void *data, void *flag)
{
struct eeh_pe *pe = (struct eeh_pe *)data;
int state = *((int *)flag);
struct eeh_dev *edev, *tmp;
struct pci_dev *pdev;
if (pe->state & EEH_PE_REMOVED)
return NULL;
pe->state |= state;
if (!(state & EEH_PE_ISOLATED))
return NULL;
eeh_pe_for_each_dev(pe, edev, tmp) {
pdev = eeh_dev_to_pci_dev(edev);
if (pdev)
pdev->error_state = pci_channel_io_frozen;
}
if (pe->state & EEH_PE_CFG_RESTRICTED)
pe->state |= EEH_PE_CFG_BLOCKED;
return NULL;
}
void eeh_pe_state_mark(struct eeh_pe *pe, int state)
{
eeh_pe_traverse(pe, __eeh_pe_state_mark, &state);
}
static void *__eeh_pe_dev_mode_mark(void *data, void *flag)
{
struct eeh_dev *edev = data;
int mode = *((int *)flag);
edev->mode |= mode;
return NULL;
}
void eeh_pe_dev_mode_mark(struct eeh_pe *pe, int mode)
{
eeh_pe_dev_traverse(pe, __eeh_pe_dev_mode_mark, &mode);
}
static void *__eeh_pe_state_clear(void *data, void *flag)
{
struct eeh_pe *pe = (struct eeh_pe *)data;
int state = *((int *)flag);
struct eeh_dev *edev, *tmp;
struct pci_dev *pdev;
if (pe->state & EEH_PE_REMOVED)
return NULL;
pe->state &= ~state;
if (!(state & EEH_PE_ISOLATED))
return NULL;
pe->check_count = 0;
eeh_pe_for_each_dev(pe, edev, tmp) {
pdev = eeh_dev_to_pci_dev(edev);
if (!pdev)
continue;
pdev->error_state = pci_channel_io_normal;
}
if (pe->state & EEH_PE_CFG_RESTRICTED)
pe->state &= ~EEH_PE_CFG_BLOCKED;
return NULL;
}
void eeh_pe_state_clear(struct eeh_pe *pe, int state)
{
eeh_pe_traverse(pe, __eeh_pe_state_clear, &state);
}
static void eeh_bridge_check_link(struct eeh_dev *edev,
struct device_node *dn)
{
int cap;
uint32_t val;
int timeout = 0;
if (!(edev->mode & (EEH_DEV_ROOT_PORT | EEH_DEV_DS_PORT)))
return;
pr_debug("%s: Check PCIe link for %04x:%02x:%02x.%01x ...\n",
__func__, edev->phb->global_number,
edev->config_addr >> 8,
PCI_SLOT(edev->config_addr & 0xFF),
PCI_FUNC(edev->config_addr & 0xFF));
cap = edev->pcie_cap;
eeh_ops->read_config(dn, cap + PCI_EXP_SLTSTA, 2, &val);
if (!(val & PCI_EXP_SLTSTA_PDS)) {
pr_debug(" No card in the slot (0x%04x) !\n", val);
return;
}
eeh_ops->read_config(dn, cap + PCI_EXP_SLTCAP, 2, &val);
if (val & PCI_EXP_SLTCAP_PCP) {
eeh_ops->read_config(dn, cap + PCI_EXP_SLTCTL, 2, &val);
if (val & PCI_EXP_SLTCTL_PCC) {
pr_debug(" In power-off state, power it on ...\n");
val &= ~(PCI_EXP_SLTCTL_PCC | PCI_EXP_SLTCTL_PIC);
val |= (0x0100 & PCI_EXP_SLTCTL_PIC);
eeh_ops->write_config(dn, cap + PCI_EXP_SLTCTL, 2, val);
msleep(2 * 1000);
}
}
eeh_ops->read_config(dn, cap + PCI_EXP_LNKCTL, 2, &val);
val &= ~PCI_EXP_LNKCTL_LD;
eeh_ops->write_config(dn, cap + PCI_EXP_LNKCTL, 2, val);
eeh_ops->read_config(dn, cap + PCI_EXP_LNKCAP, 4, &val);
if (!(val & PCI_EXP_LNKCAP_DLLLARC)) {
pr_debug(" No link reporting capability (0x%08x) \n", val);
msleep(1000);
return;
}
timeout = 0;
while (timeout < 5000) {
msleep(20);
timeout += 20;
eeh_ops->read_config(dn, cap + PCI_EXP_LNKSTA, 2, &val);
if (val & PCI_EXP_LNKSTA_DLLLA)
break;
}
if (val & PCI_EXP_LNKSTA_DLLLA)
pr_debug(" Link up (%s)\n",
(val & PCI_EXP_LNKSTA_CLS_2_5GB) ? "2.5GB" : "5GB");
else
pr_debug(" Link not ready (0x%04x)\n", val);
}
static void eeh_restore_bridge_bars(struct eeh_dev *edev,
struct device_node *dn)
{
int i;
for (i = 4; i < 13; i++)
eeh_ops->write_config(dn, i*4, 4, edev->config_space[i]);
eeh_ops->write_config(dn, 14*4, 4, edev->config_space[14]);
eeh_ops->write_config(dn, PCI_CACHE_LINE_SIZE, 1,
SAVED_BYTE(PCI_CACHE_LINE_SIZE));
eeh_ops->write_config(dn, PCI_LATENCY_TIMER, 1,
SAVED_BYTE(PCI_LATENCY_TIMER));
eeh_ops->write_config(dn, 15*4, 4, edev->config_space[15]);
eeh_ops->write_config(dn, PCI_COMMAND, 4, edev->config_space[1]);
eeh_bridge_check_link(edev, dn);
}
static void eeh_restore_device_bars(struct eeh_dev *edev,
struct device_node *dn)
{
int i;
u32 cmd;
for (i = 4; i < 10; i++)
eeh_ops->write_config(dn, i*4, 4, edev->config_space[i]);
eeh_ops->write_config(dn, 12*4, 4, edev->config_space[12]);
eeh_ops->write_config(dn, PCI_CACHE_LINE_SIZE, 1,
SAVED_BYTE(PCI_CACHE_LINE_SIZE));
eeh_ops->write_config(dn, PCI_LATENCY_TIMER, 1,
SAVED_BYTE(PCI_LATENCY_TIMER));
eeh_ops->write_config(dn, 15*4, 4, edev->config_space[15]);
eeh_ops->read_config(dn, PCI_COMMAND, 4, &cmd);
if (edev->config_space[1] & PCI_COMMAND_PARITY)
cmd |= PCI_COMMAND_PARITY;
else
cmd &= ~PCI_COMMAND_PARITY;
if (edev->config_space[1] & PCI_COMMAND_SERR)
cmd |= PCI_COMMAND_SERR;
else
cmd &= ~PCI_COMMAND_SERR;
eeh_ops->write_config(dn, PCI_COMMAND, 4, cmd);
}
static void *eeh_restore_one_device_bars(void *data, void *flag)
{
struct eeh_dev *edev = (struct eeh_dev *)data;
struct device_node *dn = eeh_dev_to_of_node(edev);
if (edev->mode & EEH_DEV_BRIDGE)
eeh_restore_bridge_bars(edev, dn);
else
eeh_restore_device_bars(edev, dn);
if (eeh_ops->restore_config)
eeh_ops->restore_config(dn);
return NULL;
}
void eeh_pe_restore_bars(struct eeh_pe *pe)
{
eeh_pe_dev_traverse(pe, eeh_restore_one_device_bars, NULL);
}
const char *eeh_pe_loc_get(struct eeh_pe *pe)
{
struct pci_bus *bus = eeh_pe_bus_get(pe);
struct device_node *dn = pci_bus_to_OF_node(bus);
const char *loc = NULL;
if (!dn)
goto out;
if (pci_is_root_bus(bus)) {
loc = of_get_property(dn, "ibm,loc-code", NULL);
if (!loc)
loc = of_get_property(dn, "ibm,io-base-loc-code", NULL);
if (loc)
goto out;
dn = dn->child;
if (!dn)
goto out;
}
loc = of_get_property(dn, "ibm,loc-code", NULL);
if (!loc)
loc = of_get_property(dn, "ibm,slot-location-code", NULL);
out:
return loc ? loc : "N/A";
}
struct pci_bus *eeh_pe_bus_get(struct eeh_pe *pe)
{
struct pci_bus *bus = NULL;
struct eeh_dev *edev;
struct pci_dev *pdev;
if (pe->type & EEH_PE_PHB) {
bus = pe->phb->bus;
} else if (pe->type & EEH_PE_BUS ||
pe->type & EEH_PE_DEVICE) {
if (pe->bus) {
bus = pe->bus;
goto out;
}
edev = list_first_entry(&pe->edevs, struct eeh_dev, list);
pdev = eeh_dev_to_pci_dev(edev);
if (pdev)
bus = pdev->bus;
}
out:
return bus;
}
