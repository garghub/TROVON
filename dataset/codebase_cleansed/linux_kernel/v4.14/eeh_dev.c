struct eeh_dev *eeh_dev_init(struct pci_dn *pdn)
{
struct eeh_dev *edev;
edev = kzalloc(sizeof(*edev), GFP_KERNEL);
if (!edev)
return NULL;
pdn->edev = edev;
edev->pdn = pdn;
INIT_LIST_HEAD(&edev->list);
INIT_LIST_HEAD(&edev->rmv_list);
return edev;
}
void eeh_dev_phb_init_dynamic(struct pci_controller *phb)
{
eeh_phb_pe_create(phb);
}
