void *eeh_dev_init(struct pci_dn *pdn, void *data)
{
struct pci_controller *phb = data;
struct eeh_dev *edev;
edev = kzalloc(sizeof(*edev), GFP_KERNEL);
if (!edev) {
pr_warn("%s: out of memory\n",
__func__);
return NULL;
}
pdn->edev = edev;
edev->pdn = pdn;
edev->phb = phb;
INIT_LIST_HEAD(&edev->list);
return NULL;
}
void eeh_dev_phb_init_dynamic(struct pci_controller *phb)
{
struct pci_dn *root = phb->pci_data;
eeh_phb_pe_create(phb);
eeh_dev_init(root, phb);
traverse_pci_dn(root, eeh_dev_init, phb);
}
static int __init eeh_dev_phb_init(void)
{
struct pci_controller *phb, *tmp;
list_for_each_entry_safe(phb, tmp, &hose_list, list_node)
eeh_dev_phb_init_dynamic(phb);
pr_info("EEH: devices created\n");
return 0;
}
