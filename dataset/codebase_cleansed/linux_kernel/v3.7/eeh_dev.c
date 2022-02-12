void * __devinit eeh_dev_init(struct device_node *dn, void *data)
{
struct pci_controller *phb = data;
struct eeh_dev *edev;
edev = kzalloc(sizeof(*edev), GFP_KERNEL);
if (!edev) {
pr_warning("%s: out of memory\n", __func__);
return NULL;
}
PCI_DN(dn)->edev = edev;
edev->dn = dn;
edev->phb = phb;
INIT_LIST_HEAD(&edev->list);
return NULL;
}
void __devinit eeh_dev_phb_init_dynamic(struct pci_controller *phb)
{
struct device_node *dn = phb->dn;
eeh_phb_pe_create(phb);
eeh_dev_init(dn, phb);
traverse_pci_devices(dn, eeh_dev_init, phb);
}
static int __init eeh_dev_phb_init(void)
{
struct pci_controller *phb, *tmp;
list_for_each_entry_safe(phb, tmp, &hose_list, list_node)
eeh_dev_phb_init_dynamic(phb);
pr_info("EEH: devices created\n");
return 0;
}
