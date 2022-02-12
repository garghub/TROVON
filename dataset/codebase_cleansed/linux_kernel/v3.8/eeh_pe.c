static struct eeh_pe *eeh_pe_alloc(struct pci_controller *phb, int type)
{
struct eeh_pe *pe;
pe = kzalloc(sizeof(struct eeh_pe), GFP_KERNEL);
if (!pe) return NULL;
pe->type = type;
pe->phb = phb;
INIT_LIST_HEAD(&pe->child_list);
INIT_LIST_HEAD(&pe->child);
INIT_LIST_HEAD(&pe->edevs);
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
eeh_lock();
list_add_tail(&pe->child, &eeh_phb_pe);
eeh_unlock();
pr_debug("EEH: Add PE for PHB#%d\n", phb->global_number);
return 0;
}
static struct eeh_pe *eeh_phb_pe_get(struct pci_controller *phb)
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
static void *eeh_pe_traverse(struct eeh_pe *root,
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
struct eeh_dev *edev;
void *ret;
if (!root) {
pr_warning("%s: Invalid PE %p\n", __func__, root);
return NULL;
}
eeh_lock();
for (pe = root; pe; pe = eeh_pe_next(pe, root)) {
eeh_pe_for_each_dev(pe, edev) {
ret = fn(edev, flag);
if (ret) {
eeh_unlock();
return ret;
}
}
}
eeh_unlock();
return NULL;
}
static void *__eeh_pe_get(void *data, void *flag)
{
struct eeh_pe *pe = (struct eeh_pe *)data;
struct eeh_dev *edev = (struct eeh_dev *)flag;
if (pe->type & EEH_PE_PHB)
return NULL;
if (edev->pe_config_addr &&
(edev->pe_config_addr == pe->addr))
return pe;
if (edev->pe_config_addr &&
(edev->config_addr == pe->config_addr))
return pe;
return NULL;
}
static struct eeh_pe *eeh_pe_get(struct eeh_dev *edev)
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
eeh_lock();
pe = eeh_pe_get(edev);
if (pe && !(pe->type & EEH_PE_INVALID)) {
if (!edev->pe_config_addr) {
eeh_unlock();
pr_err("%s: PE with addr 0x%x already exists\n",
__func__, edev->config_addr);
return -EEXIST;
}
pe->type = EEH_PE_BUS;
edev->pe = pe;
list_add_tail(&edev->list, &pe->edevs);
eeh_unlock();
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
parent->type &= ~EEH_PE_INVALID;
parent = parent->parent;
}
eeh_unlock();
pr_debug("EEH: Add %s to Device PE#%x, Parent PE#%x\n",
edev->dn->full_name, pe->addr, pe->parent->addr);
return 0;
}
pe = eeh_pe_alloc(edev->phb, EEH_PE_DEVICE);
if (!pe) {
eeh_unlock();
pr_err("%s: out of memory!\n", __func__);
return -ENOMEM;
}
pe->addr = edev->pe_config_addr;
pe->config_addr = edev->config_addr;
parent = eeh_pe_get_parent(edev);
if (!parent) {
parent = eeh_phb_pe_get(edev->phb);
if (!parent) {
eeh_unlock();
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
eeh_unlock();
pr_debug("EEH: Add %s to Device PE#%x, Parent PE#%x\n",
edev->dn->full_name, pe->addr, pe->parent->addr);
return 0;
}
int eeh_rmv_from_parent_pe(struct eeh_dev *edev, int purge_pe)
{
struct eeh_pe *pe, *parent, *child;
int cnt;
if (!edev->pe) {
pr_warning("%s: No PE found for EEH device %s\n",
__func__, edev->dn->full_name);
return -EEXIST;
}
eeh_lock();
pe = edev->pe;
edev->pe = NULL;
list_del(&edev->list);
while (1) {
parent = pe->parent;
if (pe->type & EEH_PE_PHB)
break;
if (purge_pe) {
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
eeh_unlock();
return 0;
}
static void *__eeh_pe_state_mark(void *data, void *flag)
{
struct eeh_pe *pe = (struct eeh_pe *)data;
int state = *((int *)flag);
struct eeh_dev *tmp;
struct pci_dev *pdev;
pe->state |= state;
eeh_pe_for_each_dev(pe, tmp) {
pdev = eeh_dev_to_pci_dev(tmp);
if (pdev)
pdev->error_state = pci_channel_io_frozen;
}
return NULL;
}
void eeh_pe_state_mark(struct eeh_pe *pe, int state)
{
eeh_lock();
eeh_pe_traverse(pe, __eeh_pe_state_mark, &state);
eeh_unlock();
}
static void *__eeh_pe_state_clear(void *data, void *flag)
{
struct eeh_pe *pe = (struct eeh_pe *)data;
int state = *((int *)flag);
pe->state &= ~state;
pe->check_count = 0;
return NULL;
}
void eeh_pe_state_clear(struct eeh_pe *pe, int state)
{
eeh_lock();
eeh_pe_traverse(pe, __eeh_pe_state_clear, &state);
eeh_unlock();
}
static void *eeh_restore_one_device_bars(void *data, void *flag)
{
int i;
u32 cmd;
struct eeh_dev *edev = (struct eeh_dev *)data;
struct device_node *dn = eeh_dev_to_of_node(edev);
for (i = 4; i < 10; i++)
eeh_ops->write_config(dn, i*4, 4, edev->config_space[i]);
eeh_ops->write_config(dn, 12*4, 4, edev->config_space[12]);
#define BYTE_SWAP(OFF) (8*((OFF)/4)+3-(OFF))
#define SAVED_BYTE(OFF) (((u8 *)(edev->config_space))[BYTE_SWAP(OFF)])
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
return NULL;
}
void eeh_pe_restore_bars(struct eeh_pe *pe)
{
eeh_pe_dev_traverse(pe, eeh_restore_one_device_bars, NULL);
}
struct pci_bus *eeh_pe_bus_get(struct eeh_pe *pe)
{
struct pci_bus *bus = NULL;
struct eeh_dev *edev;
struct pci_dev *pdev;
eeh_lock();
if (pe->type & EEH_PE_PHB) {
bus = pe->phb->bus;
} else if (pe->type & EEH_PE_BUS) {
edev = list_first_entry(&pe->edevs, struct eeh_dev, list);
pdev = eeh_dev_to_pci_dev(edev);
if (pdev)
bus = pdev->bus;
}
eeh_unlock();
return bus;
}
