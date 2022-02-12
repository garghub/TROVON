static struct pci_dn *pci_bus_to_pdn(struct pci_bus *bus)
{
struct pci_bus *pbus;
struct device_node *dn;
struct pci_dn *pdn;
pbus = bus;
while (pbus) {
if (pci_is_root_bus(pbus) || pbus->self)
break;
pbus = pbus->parent;
}
dn = pci_bus_to_OF_node(pbus);
pdn = dn ? PCI_DN(dn) : NULL;
return pdn;
}
struct pci_dn *pci_get_pdn_by_devfn(struct pci_bus *bus,
int devfn)
{
struct device_node *dn = NULL;
struct pci_dn *parent, *pdn;
struct pci_dev *pdev = NULL;
list_for_each_entry(pdev, &bus->devices, bus_list) {
if (pdev->devfn == devfn) {
if (pdev->dev.archdata.pci_data)
return pdev->dev.archdata.pci_data;
dn = pci_device_to_OF_node(pdev);
break;
}
}
pdn = dn ? PCI_DN(dn) : NULL;
if (pdn)
return pdn;
parent = pci_bus_to_pdn(bus);
if (!parent)
return NULL;
list_for_each_entry(pdn, &parent->child_list, list) {
if (pdn->busno == bus->number &&
pdn->devfn == devfn)
return pdn;
}
return NULL;
}
struct pci_dn *pci_get_pdn(struct pci_dev *pdev)
{
struct device_node *dn;
struct pci_dn *parent, *pdn;
if (pdev->dev.archdata.pci_data)
return pdev->dev.archdata.pci_data;
dn = pci_device_to_OF_node(pdev);
pdn = dn ? PCI_DN(dn) : NULL;
if (pdn)
return pdn;
parent = pci_bus_to_pdn(pdev->bus);
if (!parent)
return NULL;
list_for_each_entry(pdn, &parent->child_list, list) {
if (pdn->busno == pdev->bus->number &&
pdn->devfn == pdev->devfn)
return pdn;
}
return NULL;
}
static struct pci_dn *add_one_dev_pci_data(struct pci_dn *parent,
struct pci_dev *pdev,
int vf_index,
int busno, int devfn)
{
struct pci_dn *pdn;
if (!parent)
return NULL;
pdn = kzalloc(sizeof(*pdn), GFP_KERNEL);
if (!pdn) {
dev_warn(&pdev->dev, "%s: Out of memory!\n", __func__);
return NULL;
}
pdn->phb = parent->phb;
pdn->parent = parent;
pdn->busno = busno;
pdn->devfn = devfn;
#ifdef CONFIG_PPC_POWERNV
pdn->vf_index = vf_index;
pdn->pe_number = IODA_INVALID_PE;
#endif
INIT_LIST_HEAD(&pdn->child_list);
INIT_LIST_HEAD(&pdn->list);
list_add_tail(&pdn->list, &parent->child_list);
if (pdev)
pdev->dev.archdata.pci_data = pdn;
return pdn;
}
struct pci_dn *add_dev_pci_data(struct pci_dev *pdev)
{
#ifdef CONFIG_PCI_IOV
struct pci_dn *parent, *pdn;
struct eeh_dev *edev;
int i;
if (!pdev->is_physfn)
return pci_get_pdn(pdev);
pdn = pci_get_pdn(pdev);
if (!pdn || (pdn->flags & PCI_DN_FLAG_IOV_VF))
return NULL;
pdn->flags |= PCI_DN_FLAG_IOV_VF;
parent = pci_bus_to_pdn(pdev->bus);
if (!parent)
return NULL;
for (i = 0; i < pci_sriov_get_totalvfs(pdev); i++) {
pdn = add_one_dev_pci_data(parent, NULL, i,
pci_iov_virtfn_bus(pdev, i),
pci_iov_virtfn_devfn(pdev, i));
if (!pdn) {
dev_warn(&pdev->dev, "%s: Cannot create firmware data for VF#%d\n",
__func__, i);
return NULL;
}
eeh_dev_init(pdn, pci_bus_to_host(pdev->bus));
edev = pdn_to_eeh_dev(pdn);
BUG_ON(!edev);
edev->physfn = pdev;
}
#endif
return pci_get_pdn(pdev);
}
void remove_dev_pci_data(struct pci_dev *pdev)
{
#ifdef CONFIG_PCI_IOV
struct pci_dn *parent;
struct pci_dn *pdn, *tmp;
struct eeh_dev *edev;
int i;
if (pdev->is_virtfn) {
pdn = pci_get_pdn(pdev);
#ifdef CONFIG_PPC_POWERNV
pdn->pe_number = IODA_INVALID_PE;
#endif
return;
}
if (!pdev->is_physfn)
return;
pdn = pci_get_pdn(pdev);
if (!pdn || !(pdn->flags & PCI_DN_FLAG_IOV_VF))
return;
pdn->flags &= ~PCI_DN_FLAG_IOV_VF;
parent = pci_bus_to_pdn(pdev->bus);
if (!parent)
return;
for (i = 0; i < pci_sriov_get_totalvfs(pdev); i++) {
list_for_each_entry_safe(pdn, tmp,
&parent->child_list, list) {
if (pdn->busno != pci_iov_virtfn_bus(pdev, i) ||
pdn->devfn != pci_iov_virtfn_devfn(pdev, i))
continue;
edev = pdn_to_eeh_dev(pdn);
if (edev) {
pdn->edev = NULL;
kfree(edev);
}
if (!list_empty(&pdn->list))
list_del(&pdn->list);
kfree(pdn);
}
}
#endif
}
void *update_dn_pci_info(struct device_node *dn, void *data)
{
struct pci_controller *phb = data;
const __be32 *type = of_get_property(dn, "ibm,pci-config-space-type", NULL);
const __be32 *regs;
struct device_node *parent;
struct pci_dn *pdn;
pdn = zalloc_maybe_bootmem(sizeof(*pdn), GFP_KERNEL);
if (pdn == NULL)
return NULL;
dn->data = pdn;
pdn->node = dn;
pdn->phb = phb;
#ifdef CONFIG_PPC_POWERNV
pdn->pe_number = IODA_INVALID_PE;
#endif
regs = of_get_property(dn, "reg", NULL);
if (regs) {
u32 addr = of_read_number(regs, 1);
pdn->busno = (addr >> 16) & 0xff;
pdn->devfn = (addr >> 8) & 0xff;
}
regs = of_get_property(dn, "vendor-id", NULL);
pdn->vendor_id = regs ? of_read_number(regs, 1) : 0;
regs = of_get_property(dn, "device-id", NULL);
pdn->device_id = regs ? of_read_number(regs, 1) : 0;
regs = of_get_property(dn, "class-code", NULL);
pdn->class_code = regs ? of_read_number(regs, 1) : 0;
pdn->pci_ext_config_space = (type && of_read_number(type, 1) == 1);
INIT_LIST_HEAD(&pdn->child_list);
INIT_LIST_HEAD(&pdn->list);
parent = of_get_parent(dn);
pdn->parent = parent ? PCI_DN(parent) : NULL;
if (pdn->parent)
list_add_tail(&pdn->list, &pdn->parent->child_list);
return NULL;
}
void *traverse_pci_devices(struct device_node *start, traverse_func pre,
void *data)
{
struct device_node *dn, *nextdn;
void *ret;
for (dn = start->child; dn; dn = nextdn) {
const __be32 *classp;
u32 class = 0;
nextdn = NULL;
classp = of_get_property(dn, "class-code", NULL);
if (classp)
class = of_read_number(classp, 1);
if (pre && ((ret = pre(dn, data)) != NULL))
return ret;
if (dn->child && ((class >> 8) == PCI_CLASS_BRIDGE_PCI ||
(class >> 8) == PCI_CLASS_BRIDGE_CARDBUS))
nextdn = dn->child;
else if (dn->sibling)
nextdn = dn->sibling;
if (!nextdn) {
do {
dn = dn->parent;
if (dn == start)
return NULL;
} while (dn->sibling == NULL);
nextdn = dn->sibling;
}
}
return NULL;
}
static struct pci_dn *pci_dn_next_one(struct pci_dn *root,
struct pci_dn *pdn)
{
struct list_head *next = pdn->child_list.next;
if (next != &pdn->child_list)
return list_entry(next, struct pci_dn, list);
while (1) {
if (pdn == root)
return NULL;
next = pdn->list.next;
if (next != &pdn->parent->child_list)
break;
pdn = pdn->parent;
}
return list_entry(next, struct pci_dn, list);
}
void *traverse_pci_dn(struct pci_dn *root,
void *(*fn)(struct pci_dn *, void *),
void *data)
{
struct pci_dn *pdn = root;
void *ret;
for (pdn = pci_dn_next_one(root, pdn); pdn;
pdn = pci_dn_next_one(root, pdn)) {
ret = fn(pdn, data);
if (ret)
return ret;
}
return NULL;
}
void pci_devs_phb_init_dynamic(struct pci_controller *phb)
{
struct device_node *dn = phb->dn;
struct pci_dn *pdn;
update_dn_pci_info(dn, phb);
pdn = dn->data;
if (pdn) {
pdn->devfn = pdn->busno = -1;
pdn->vendor_id = pdn->device_id = pdn->class_code = 0;
pdn->phb = phb;
phb->pci_data = pdn;
}
traverse_pci_devices(dn, update_dn_pci_info, phb);
}
void __init pci_devs_phb_init(void)
{
struct pci_controller *phb, *tmp;
list_for_each_entry_safe(phb, tmp, &hose_list, list_node)
pci_devs_phb_init_dynamic(phb);
}
static void pci_dev_pdn_setup(struct pci_dev *pdev)
{
struct pci_dn *pdn;
if (pdev->dev.archdata.pci_data)
return;
pdn = pci_get_pdn(pdev);
pdev->dev.archdata.pci_data = pdn;
}
