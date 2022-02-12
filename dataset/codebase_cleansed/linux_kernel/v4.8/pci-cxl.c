struct device_node *pnv_pci_get_phb_node(struct pci_dev *dev)
{
struct pci_controller *hose = pci_bus_to_host(dev->bus);
return of_node_get(hose->dn);
}
int pnv_phb_to_cxl_mode(struct pci_dev *dev, uint64_t mode)
{
struct pci_controller *hose = pci_bus_to_host(dev->bus);
struct pnv_phb *phb = hose->private_data;
struct pnv_ioda_pe *pe;
int rc;
pe = pnv_ioda_get_pe(dev);
if (!pe)
return -ENODEV;
pe_info(pe, "Switching PHB to CXL\n");
rc = opal_pci_set_phb_cxl_mode(phb->opal_id, mode, pe->pe_number);
if (rc == OPAL_UNSUPPORTED)
dev_err(&dev->dev, "Required cxl mode not supported by firmware - update skiboot\n");
else if (rc)
dev_err(&dev->dev, "opal_pci_set_phb_cxl_mode failed: %i\n", rc);
return rc;
}
int pnv_cxl_alloc_hwirqs(struct pci_dev *dev, int num)
{
struct pci_controller *hose = pci_bus_to_host(dev->bus);
struct pnv_phb *phb = hose->private_data;
int hwirq = msi_bitmap_alloc_hwirqs(&phb->msi_bmp, num);
if (hwirq < 0) {
dev_warn(&dev->dev, "Failed to find a free MSI\n");
return -ENOSPC;
}
return phb->msi_base + hwirq;
}
void pnv_cxl_release_hwirqs(struct pci_dev *dev, int hwirq, int num)
{
struct pci_controller *hose = pci_bus_to_host(dev->bus);
struct pnv_phb *phb = hose->private_data;
msi_bitmap_free_hwirqs(&phb->msi_bmp, hwirq - phb->msi_base, num);
}
void pnv_cxl_release_hwirq_ranges(struct cxl_irq_ranges *irqs,
struct pci_dev *dev)
{
struct pci_controller *hose = pci_bus_to_host(dev->bus);
struct pnv_phb *phb = hose->private_data;
int i, hwirq;
for (i = 1; i < CXL_IRQ_RANGES; i++) {
if (!irqs->range[i])
continue;
pr_devel("cxl release irq range 0x%x: offset: 0x%lx limit: %ld\n",
i, irqs->offset[i],
irqs->range[i]);
hwirq = irqs->offset[i] - phb->msi_base;
msi_bitmap_free_hwirqs(&phb->msi_bmp, hwirq,
irqs->range[i]);
}
}
int pnv_cxl_alloc_hwirq_ranges(struct cxl_irq_ranges *irqs,
struct pci_dev *dev, int num)
{
struct pci_controller *hose = pci_bus_to_host(dev->bus);
struct pnv_phb *phb = hose->private_data;
int i, hwirq, try;
memset(irqs, 0, sizeof(struct cxl_irq_ranges));
for (i = 1; i < CXL_IRQ_RANGES && num; i++) {
try = num;
while (try) {
hwirq = msi_bitmap_alloc_hwirqs(&phb->msi_bmp, try);
if (hwirq >= 0)
break;
try /= 2;
}
if (!try)
goto fail;
irqs->offset[i] = phb->msi_base + hwirq;
irqs->range[i] = try;
pr_devel("cxl alloc irq range 0x%x: offset: 0x%lx limit: %li\n",
i, irqs->offset[i], irqs->range[i]);
num -= try;
}
if (num)
goto fail;
return 0;
fail:
pnv_cxl_release_hwirq_ranges(irqs, dev);
return -ENOSPC;
}
int pnv_cxl_get_irq_count(struct pci_dev *dev)
{
struct pci_controller *hose = pci_bus_to_host(dev->bus);
struct pnv_phb *phb = hose->private_data;
return phb->msi_bmp.irq_count;
}
int pnv_cxl_ioda_msi_setup(struct pci_dev *dev, unsigned int hwirq,
unsigned int virq)
{
struct pci_controller *hose = pci_bus_to_host(dev->bus);
struct pnv_phb *phb = hose->private_data;
unsigned int xive_num = hwirq - phb->msi_base;
struct pnv_ioda_pe *pe;
int rc;
if (!(pe = pnv_ioda_get_pe(dev)))
return -ENODEV;
rc = opal_pci_set_xive_pe(phb->opal_id, pe->pe_number, xive_num);
if (rc) {
pe_warn(pe, "%s: OPAL error %d setting msi_base 0x%x "
"hwirq 0x%x XIVE 0x%x PE\n",
pci_name(dev), rc, phb->msi_base, hwirq, xive_num);
return -EIO;
}
pnv_set_msi_irq_chip(phb, virq);
return 0;
}
static inline int get_cxl_module(void)
{
struct module *cxl_module;
mutex_lock(&module_mutex);
cxl_module = find_module("cxl");
if (cxl_module)
__module_get(cxl_module);
mutex_unlock(&module_mutex);
if (!cxl_module)
return -ENODEV;
return 0;
}
static inline int get_cxl_module(void) { return 0; }
int pnv_cxl_enable_phb_kernel_api(struct pci_controller *hose, bool enable)
{
struct pnv_phb *phb = hose->private_data;
int rc;
if (!enable) {
return -EPERM;
}
rc = get_cxl_module();
if (rc)
return rc;
phb->flags |= PNV_PHB_FLAG_CXL;
hose->controller_ops = pnv_cxl_cx4_ioda_controller_ops;
return 0;
}
bool pnv_pci_on_cxl_phb(struct pci_dev *dev)
{
struct pci_controller *hose = pci_bus_to_host(dev->bus);
struct pnv_phb *phb = hose->private_data;
return !!(phb->flags & PNV_PHB_FLAG_CXL);
}
struct cxl_afu *pnv_cxl_phb_to_afu(struct pci_controller *hose)
{
struct pnv_phb *phb = hose->private_data;
return (struct cxl_afu *)phb->cxl_afu;
}
void pnv_cxl_phb_set_peer_afu(struct pci_dev *dev, struct cxl_afu *afu)
{
struct pci_controller *hose = pci_bus_to_host(dev->bus);
struct pnv_phb *phb = hose->private_data;
phb->cxl_afu = afu;
}
bool pnv_cxl_enable_device_hook(struct pci_dev *dev)
{
struct pci_controller *hose = pci_bus_to_host(dev->bus);
struct pnv_phb *phb = hose->private_data;
struct cxl_afu *afu = phb->cxl_afu;
if (!pnv_pci_enable_device_hook(dev))
return false;
if (PCI_FUNC(dev->devfn) == 0)
return true;
if (!afu) {
dev_WARN(&dev->dev, "Attempted to enable function > 0 on CXL PHB without a peer AFU\n");
return false;
}
dev_info(&dev->dev, "Enabling function on CXL enabled PHB with peer AFU\n");
cxl_afu_get(afu);
return cxl_pci_associate_default_context(dev, afu);
}
void pnv_cxl_disable_device(struct pci_dev *dev)
{
struct pci_controller *hose = pci_bus_to_host(dev->bus);
struct pnv_phb *phb = hose->private_data;
struct cxl_afu *afu = phb->cxl_afu;
if (PCI_FUNC(dev->devfn) == 0)
return;
cxl_pci_disable_device(dev);
cxl_afu_put(afu);
}
int pnv_cxl_cx4_setup_msi_irqs(struct pci_dev *pdev, int nvec, int type)
{
struct pci_controller *hose = pci_bus_to_host(pdev->bus);
struct pnv_phb *phb = hose->private_data;
struct msi_desc *entry;
struct cxl_context *ctx = NULL;
unsigned int virq;
int hwirq;
int afu_irq = 0;
int rc;
if (WARN_ON(!phb) || !phb->msi_bmp.bitmap)
return -ENODEV;
if (pdev->no_64bit_msi && !phb->msi32_support)
return -ENODEV;
rc = cxl_cx4_setup_msi_irqs(pdev, nvec, type);
if (rc)
return rc;
for_each_pci_msi_entry(entry, pdev) {
if (!entry->msi_attrib.is_64 && !phb->msi32_support) {
pr_warn("%s: Supports only 64-bit MSIs\n",
pci_name(pdev));
return -ENXIO;
}
hwirq = cxl_next_msi_hwirq(pdev, &ctx, &afu_irq);
if (WARN_ON(hwirq <= 0))
return (hwirq ? hwirq : -ENOMEM);
virq = irq_create_mapping(NULL, hwirq);
if (virq == NO_IRQ) {
pr_warn("%s: Failed to map cxl mode MSI to linux irq\n",
pci_name(pdev));
return -ENOMEM;
}
rc = pnv_cxl_ioda_msi_setup(pdev, hwirq, virq);
if (rc) {
pr_warn("%s: Failed to setup cxl mode MSI\n", pci_name(pdev));
irq_dispose_mapping(virq);
return rc;
}
irq_set_msi_desc(virq, entry);
}
return 0;
}
void pnv_cxl_cx4_teardown_msi_irqs(struct pci_dev *pdev)
{
struct pci_controller *hose = pci_bus_to_host(pdev->bus);
struct pnv_phb *phb = hose->private_data;
struct msi_desc *entry;
irq_hw_number_t hwirq;
if (WARN_ON(!phb))
return;
for_each_pci_msi_entry(entry, pdev) {
if (entry->irq == NO_IRQ)
continue;
hwirq = virq_to_hw(entry->irq);
irq_set_msi_desc(entry->irq, NULL);
irq_dispose_mapping(entry->irq);
}
cxl_cx4_teardown_msi_irqs(pdev);
}
