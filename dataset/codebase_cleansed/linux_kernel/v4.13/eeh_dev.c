struct eeh_dev *eeh_dev_init(struct pci_dn *pdn)
{
struct pci_controller *phb = pdn->phb;
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
INIT_LIST_HEAD(&edev->rmv_list);
return edev;
}
void eeh_dev_phb_init_dynamic(struct pci_controller *phb)
{
eeh_phb_pe_create(phb);
}
static int __init eeh_dev_phb_init(void)
{
struct pci_controller *phb, *tmp;
list_for_each_entry_safe(phb, tmp, &hose_list, list_node)
eeh_dev_phb_init_dynamic(phb);
return 0;
}
