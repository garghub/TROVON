static void its_mask_msi_irq(struct irq_data *d)
{
pci_msi_mask_irq(d);
irq_chip_mask_parent(d);
}
static void its_unmask_msi_irq(struct irq_data *d)
{
pci_msi_unmask_irq(d);
irq_chip_unmask_parent(d);
}
static int its_pci_msi_vec_count(struct pci_dev *pdev)
{
int msi, msix;
msi = max(pci_msi_vec_count(pdev), 0);
msix = max(pci_msix_vec_count(pdev), 0);
return max(msi, msix);
}
static int its_get_pci_alias(struct pci_dev *pdev, u16 alias, void *data)
{
struct its_pci_alias *dev_alias = data;
if (pdev != dev_alias->pdev)
dev_alias->count += its_pci_msi_vec_count(pdev);
return 0;
}
static int its_pci_msi_prepare(struct irq_domain *domain, struct device *dev,
int nvec, msi_alloc_info_t *info)
{
struct pci_dev *pdev;
struct its_pci_alias dev_alias;
struct msi_domain_info *msi_info;
if (!dev_is_pci(dev))
return -EINVAL;
msi_info = msi_get_domain_info(domain->parent);
pdev = to_pci_dev(dev);
dev_alias.pdev = pdev;
dev_alias.count = nvec;
pci_for_each_dma_alias(pdev, its_get_pci_alias, &dev_alias);
info->scratchpad[0].ul = pci_msi_domain_get_msi_rid(domain, pdev);
return msi_info->ops->msi_prepare(domain->parent,
dev, dev_alias.count, info);
}
static int __init its_pci_msi_init(void)
{
struct device_node *np;
struct irq_domain *parent;
for (np = of_find_matching_node(NULL, its_device_id); np;
np = of_find_matching_node(np, its_device_id)) {
if (!of_property_read_bool(np, "msi-controller"))
continue;
parent = irq_find_matching_host(np, DOMAIN_BUS_NEXUS);
if (!parent || !msi_get_domain_info(parent)) {
pr_err("%s: unable to locate ITS domain\n",
np->full_name);
continue;
}
if (!pci_msi_create_irq_domain(of_node_to_fwnode(np),
&its_pci_msi_domain_info,
parent)) {
pr_err("%s: unable to create PCI domain\n",
np->full_name);
continue;
}
pr_info("PCI/MSI: %s domain created\n", np->full_name);
}
return 0;
}
