static int powernv_eeh_init(void)
{
if (!firmware_has_feature(FW_FEATURE_OPALv3)) {
pr_warning("%s: OPALv3 is required !\n", __func__);
return -EINVAL;
}
eeh_probe_mode_set(EEH_PROBE_MODE_DEV);
return 0;
}
static int powernv_eeh_post_init(void)
{
struct pci_controller *hose;
struct pnv_phb *phb;
int ret = 0;
list_for_each_entry(hose, &hose_list, list_node) {
phb = hose->private_data;
if (phb->eeh_ops && phb->eeh_ops->post_init) {
ret = phb->eeh_ops->post_init(hose);
if (ret)
break;
}
}
return ret;
}
static int powernv_eeh_dev_probe(struct pci_dev *dev, void *flag)
{
struct pci_controller *hose = pci_bus_to_host(dev->bus);
struct pnv_phb *phb = hose->private_data;
struct device_node *dn = pci_device_to_OF_node(dev);
struct eeh_dev *edev = of_node_to_eeh_dev(dn);
if (!dn || !edev || edev->pe)
return 0;
if ((dev->class >> 8) == PCI_CLASS_BRIDGE_ISA)
return 0;
edev->class_code = dev->class;
edev->mode &= 0xFFFFFF00;
if (dev->hdr_type == PCI_HEADER_TYPE_BRIDGE)
edev->mode |= EEH_DEV_BRIDGE;
if (pci_is_pcie(dev)) {
edev->pcie_cap = pci_pcie_cap(dev);
if (pci_pcie_type(dev) == PCI_EXP_TYPE_ROOT_PORT)
edev->mode |= EEH_DEV_ROOT_PORT;
else if (pci_pcie_type(dev) == PCI_EXP_TYPE_DOWNSTREAM)
edev->mode |= EEH_DEV_DS_PORT;
}
edev->config_addr = ((dev->bus->number << 8) | dev->devfn);
edev->pe_config_addr = phb->bdfn_to_pe(phb, dev->bus, dev->devfn & 0xff);
eeh_add_to_parent_pe(edev);
eeh_set_enable(true);
eeh_save_bars(edev);
return 0;
}
static int powernv_eeh_set_option(struct eeh_pe *pe, int option)
{
struct pci_controller *hose = pe->phb;
struct pnv_phb *phb = hose->private_data;
int ret = -EEXIST;
if (phb->eeh_ops && phb->eeh_ops->set_option)
ret = phb->eeh_ops->set_option(pe, option);
return ret;
}
static int powernv_eeh_get_pe_addr(struct eeh_pe *pe)
{
return pe->addr;
}
static int powernv_eeh_get_state(struct eeh_pe *pe, int *delay)
{
struct pci_controller *hose = pe->phb;
struct pnv_phb *phb = hose->private_data;
int ret = EEH_STATE_NOT_SUPPORT;
if (phb->eeh_ops && phb->eeh_ops->get_state) {
ret = phb->eeh_ops->get_state(pe);
if (delay) {
*delay = 0;
if (ret & EEH_STATE_UNAVAILABLE)
*delay = 1000;
}
}
return ret;
}
static int powernv_eeh_reset(struct eeh_pe *pe, int option)
{
struct pci_controller *hose = pe->phb;
struct pnv_phb *phb = hose->private_data;
int ret = -EEXIST;
if (phb->eeh_ops && phb->eeh_ops->reset)
ret = phb->eeh_ops->reset(pe, option);
return ret;
}
static int powernv_eeh_wait_state(struct eeh_pe *pe, int max_wait)
{
int ret;
int mwait;
while (1) {
ret = powernv_eeh_get_state(pe, &mwait);
if (ret != EEH_STATE_UNAVAILABLE)
return ret;
max_wait -= mwait;
if (max_wait <= 0) {
pr_warning("%s: Timeout getting PE#%x's state (%d)\n",
__func__, pe->addr, max_wait);
return EEH_STATE_NOT_SUPPORT;
}
msleep(mwait);
}
return EEH_STATE_NOT_SUPPORT;
}
static int powernv_eeh_get_log(struct eeh_pe *pe, int severity,
char *drv_log, unsigned long len)
{
struct pci_controller *hose = pe->phb;
struct pnv_phb *phb = hose->private_data;
int ret = -EEXIST;
if (phb->eeh_ops && phb->eeh_ops->get_log)
ret = phb->eeh_ops->get_log(pe, severity, drv_log, len);
return ret;
}
static int powernv_eeh_configure_bridge(struct eeh_pe *pe)
{
struct pci_controller *hose = pe->phb;
struct pnv_phb *phb = hose->private_data;
int ret = 0;
if (phb->eeh_ops && phb->eeh_ops->configure_bridge)
ret = phb->eeh_ops->configure_bridge(pe);
return ret;
}
static int powernv_eeh_next_error(struct eeh_pe **pe)
{
struct pci_controller *hose;
struct pnv_phb *phb = NULL;
list_for_each_entry(hose, &hose_list, list_node) {
phb = hose->private_data;
break;
}
if (phb && phb->eeh_ops->next_error)
return phb->eeh_ops->next_error(pe);
return -EEXIST;
}
static int powernv_eeh_restore_config(struct device_node *dn)
{
struct eeh_dev *edev = of_node_to_eeh_dev(dn);
struct pnv_phb *phb;
s64 ret;
if (!edev)
return -EEXIST;
phb = edev->phb->private_data;
ret = opal_pci_reinit(phb->opal_id,
OPAL_REINIT_PCI_DEV, edev->config_addr);
if (ret) {
pr_warn("%s: Can't reinit PCI dev 0x%x (%lld)\n",
__func__, edev->config_addr, ret);
return -EIO;
}
return 0;
}
static int __init eeh_powernv_init(void)
{
int ret = -EINVAL;
if (!machine_is(powernv))
return ret;
ret = eeh_ops_register(&powernv_eeh_ops);
if (!ret)
pr_info("EEH: PowerNV platform initialized\n");
else
pr_info("EEH: Failed to initialize PowerNV platform (%d)\n", ret);
return ret;
}
