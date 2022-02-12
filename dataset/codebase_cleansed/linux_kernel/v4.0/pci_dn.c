struct pci_dn *pci_get_pdn(struct pci_dev *pdev)
{
struct device_node *dn = pci_device_to_OF_node(pdev);
if (!dn)
return NULL;
return PCI_DN(dn);
}
void *update_dn_pci_info(struct device_node *dn, void *data)
{
struct pci_controller *phb = data;
const __be32 *type = of_get_property(dn, "ibm,pci-config-space-type", NULL);
const __be32 *regs;
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
pdn->pci_ext_config_space = (type && of_read_number(type, 1) == 1);
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
void pci_devs_phb_init_dynamic(struct pci_controller *phb)
{
struct device_node *dn = phb->dn;
struct pci_dn *pdn;
update_dn_pci_info(dn, phb);
pdn = dn->data;
if (pdn)
pdn->devfn = pdn->busno = -1;
traverse_pci_devices(dn, update_dn_pci_info, phb);
}
void __init pci_devs_phb_init(void)
{
struct pci_controller *phb, *tmp;
list_for_each_entry_safe(phb, tmp, &hose_list, list_node)
pci_devs_phb_init_dynamic(phb);
}
