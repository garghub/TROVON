static size_t eeh_gather_pci_data(struct eeh_dev *edev, char * buf, size_t len)
{
struct device_node *dn = eeh_dev_to_of_node(edev);
struct pci_dev *dev = eeh_dev_to_pci_dev(edev);
u32 cfg;
int cap, i;
int n = 0;
n += scnprintf(buf+n, len-n, "%s\n", dn->full_name);
printk(KERN_WARNING "EEH: of node=%s\n", dn->full_name);
eeh_ops->read_config(dn, PCI_VENDOR_ID, 4, &cfg);
n += scnprintf(buf+n, len-n, "dev/vend:%08x\n", cfg);
printk(KERN_WARNING "EEH: PCI device/vendor: %08x\n", cfg);
eeh_ops->read_config(dn, PCI_COMMAND, 4, &cfg);
n += scnprintf(buf+n, len-n, "cmd/stat:%x\n", cfg);
printk(KERN_WARNING "EEH: PCI cmd/status register: %08x\n", cfg);
if (!dev) {
printk(KERN_WARNING "EEH: no PCI device for this of node\n");
return n;
}
if (dev->class >> 16 == PCI_BASE_CLASS_BRIDGE) {
eeh_ops->read_config(dn, PCI_SEC_STATUS, 2, &cfg);
n += scnprintf(buf+n, len-n, "sec stat:%x\n", cfg);
printk(KERN_WARNING "EEH: Bridge secondary status: %04x\n", cfg);
eeh_ops->read_config(dn, PCI_BRIDGE_CONTROL, 2, &cfg);
n += scnprintf(buf+n, len-n, "brdg ctl:%x\n", cfg);
printk(KERN_WARNING "EEH: Bridge control: %04x\n", cfg);
}
cap = pci_find_capability(dev, PCI_CAP_ID_PCIX);
if (cap) {
eeh_ops->read_config(dn, cap, 4, &cfg);
n += scnprintf(buf+n, len-n, "pcix-cmd:%x\n", cfg);
printk(KERN_WARNING "EEH: PCI-X cmd: %08x\n", cfg);
eeh_ops->read_config(dn, cap+4, 4, &cfg);
n += scnprintf(buf+n, len-n, "pcix-stat:%x\n", cfg);
printk(KERN_WARNING "EEH: PCI-X status: %08x\n", cfg);
}
if (pci_is_pcie(dev)) {
n += scnprintf(buf+n, len-n, "pci-e cap10:\n");
printk(KERN_WARNING
"EEH: PCI-E capabilities and status follow:\n");
for (i=0; i<=8; i++) {
eeh_ops->read_config(dn, dev->pcie_cap+4*i, 4, &cfg);
n += scnprintf(buf+n, len-n, "%02x:%x\n", 4*i, cfg);
printk(KERN_WARNING "EEH: PCI-E %02x: %08x\n", i, cfg);
}
cap = pci_find_ext_capability(dev, PCI_EXT_CAP_ID_ERR);
if (cap) {
n += scnprintf(buf+n, len-n, "pci-e AER:\n");
printk(KERN_WARNING
"EEH: PCI-E AER capability register set follows:\n");
for (i=0; i<14; i++) {
eeh_ops->read_config(dn, cap+4*i, 4, &cfg);
n += scnprintf(buf+n, len-n, "%02x:%x\n", 4*i, cfg);
printk(KERN_WARNING "EEH: PCI-E AER %02x: %08x\n", i, cfg);
}
}
}
return n;
}
void eeh_slot_error_detail(struct eeh_pe *pe, int severity)
{
size_t loglen = 0;
struct eeh_dev *edev, *tmp;
bool valid_cfg_log = true;
if (eeh_probe_mode_dev() &&
(pe->type & EEH_PE_PHB) &&
(pe->state & (EEH_PE_ISOLATED | EEH_PE_PHB_DEAD)))
valid_cfg_log = false;
if (valid_cfg_log) {
eeh_pci_enable(pe, EEH_OPT_THAW_MMIO);
eeh_ops->configure_bridge(pe);
eeh_pe_restore_bars(pe);
pci_regs_buf[0] = 0;
eeh_pe_for_each_dev(pe, edev, tmp) {
loglen += eeh_gather_pci_data(edev, pci_regs_buf + loglen,
EEH_PCI_REGS_LOG_LEN - loglen);
}
}
eeh_ops->get_log(pe, severity, pci_regs_buf, loglen);
}
static inline unsigned long eeh_token_to_phys(unsigned long token)
{
pte_t *ptep;
unsigned long pa;
int hugepage_shift;
ptep = find_linux_pte_or_hugepte(init_mm.pgd, token, &hugepage_shift);
if (!ptep)
return token;
WARN_ON(hugepage_shift);
pa = pte_pfn(*ptep) << PAGE_SHIFT;
return pa | (token & (PAGE_SIZE-1));
}
static int eeh_phb_check_failure(struct eeh_pe *pe)
{
struct eeh_pe *phb_pe;
unsigned long flags;
int ret;
if (!eeh_probe_mode_dev())
return -EPERM;
phb_pe = eeh_phb_pe_get(pe->phb);
if (!phb_pe) {
pr_warning("%s Can't find PE for PHB#%d\n",
__func__, pe->phb->global_number);
return -EEXIST;
}
eeh_serialize_lock(&flags);
if (phb_pe->state & (EEH_PE_ISOLATED | EEH_PE_PHB_DEAD)) {
ret = 0;
goto out;
}
ret = eeh_ops->get_state(phb_pe, NULL);
if ((ret < 0) ||
(ret == EEH_STATE_NOT_SUPPORT) ||
(ret & (EEH_STATE_MMIO_ACTIVE | EEH_STATE_DMA_ACTIVE)) ==
(EEH_STATE_MMIO_ACTIVE | EEH_STATE_DMA_ACTIVE)) {
ret = 0;
goto out;
}
eeh_pe_state_mark(phb_pe, EEH_PE_ISOLATED);
eeh_serialize_unlock(flags);
pr_err("EEH: PHB#%x failure detected\n",
phb_pe->phb->global_number);
dump_stack();
eeh_send_failure_event(phb_pe);
return 1;
out:
eeh_serialize_unlock(flags);
return ret;
}
int eeh_dev_check_failure(struct eeh_dev *edev)
{
int ret;
unsigned long flags;
struct device_node *dn;
struct pci_dev *dev;
struct eeh_pe *pe;
int rc = 0;
const char *location;
eeh_stats.total_mmio_ffs++;
if (!eeh_subsystem_enabled)
return 0;
if (!edev) {
eeh_stats.no_dn++;
return 0;
}
dn = eeh_dev_to_of_node(edev);
dev = eeh_dev_to_pci_dev(edev);
pe = edev->pe;
if (!pe) {
eeh_stats.ignored_check++;
pr_debug("EEH: Ignored check for %s %s\n",
eeh_pci_name(dev), dn->full_name);
return 0;
}
if (!pe->addr && !pe->config_addr) {
eeh_stats.no_cfg_addr++;
return 0;
}
ret = eeh_phb_check_failure(pe);
if (ret > 0)
return ret;
eeh_serialize_lock(&flags);
rc = 1;
if (pe->state & EEH_PE_ISOLATED) {
pe->check_count++;
if (pe->check_count % EEH_MAX_FAILS == 0) {
location = of_get_property(dn, "ibm,loc-code", NULL);
printk(KERN_ERR "EEH: %d reads ignored for recovering device at "
"location=%s driver=%s pci addr=%s\n",
pe->check_count, location,
eeh_driver_name(dev), eeh_pci_name(dev));
printk(KERN_ERR "EEH: Might be infinite loop in %s driver\n",
eeh_driver_name(dev));
dump_stack();
}
goto dn_unlock;
}
ret = eeh_ops->get_state(pe, NULL);
if ((ret < 0) ||
(ret == EEH_STATE_NOT_SUPPORT) ||
(ret & (EEH_STATE_MMIO_ACTIVE | EEH_STATE_DMA_ACTIVE)) ==
(EEH_STATE_MMIO_ACTIVE | EEH_STATE_DMA_ACTIVE)) {
eeh_stats.false_positives++;
pe->false_positives++;
rc = 0;
goto dn_unlock;
}
eeh_stats.slot_resets++;
eeh_pe_state_mark(pe, EEH_PE_ISOLATED);
eeh_serialize_unlock(flags);
pr_err("EEH: Frozen PE#%x detected on PHB#%x\n",
pe->addr, pe->phb->global_number);
dump_stack();
eeh_send_failure_event(pe);
return 1;
dn_unlock:
eeh_serialize_unlock(flags);
return rc;
}
unsigned long eeh_check_failure(const volatile void __iomem *token, unsigned long val)
{
unsigned long addr;
struct eeh_dev *edev;
addr = eeh_token_to_phys((unsigned long __force) token);
edev = eeh_addr_cache_get_dev(addr);
if (!edev) {
eeh_stats.no_device++;
return val;
}
eeh_dev_check_failure(edev);
return val;
}
int eeh_pci_enable(struct eeh_pe *pe, int function)
{
int rc;
rc = eeh_ops->set_option(pe, function);
if (rc)
pr_warning("%s: Unexpected state change %d on PHB#%d-PE#%x, err=%d\n",
__func__, function, pe->phb->global_number, pe->addr, rc);
rc = eeh_ops->wait_state(pe, PCI_BUS_RESET_WAIT_MSEC);
if (rc > 0 && (rc & EEH_STATE_MMIO_ENABLED) &&
(function == EEH_OPT_THAW_MMIO))
return 0;
return rc;
}
int pcibios_set_pcie_reset_state(struct pci_dev *dev, enum pcie_reset_state state)
{
struct eeh_dev *edev = pci_dev_to_eeh_dev(dev);
struct eeh_pe *pe = edev->pe;
if (!pe) {
pr_err("%s: No PE found on PCI device %s\n",
__func__, pci_name(dev));
return -EINVAL;
}
switch (state) {
case pcie_deassert_reset:
eeh_ops->reset(pe, EEH_RESET_DEACTIVATE);
break;
case pcie_hot_reset:
eeh_ops->reset(pe, EEH_RESET_HOT);
break;
case pcie_warm_reset:
eeh_ops->reset(pe, EEH_RESET_FUNDAMENTAL);
break;
default:
return -EINVAL;
};
return 0;
}
static void *eeh_set_dev_freset(void *data, void *flag)
{
struct pci_dev *dev;
unsigned int *freset = (unsigned int *)flag;
struct eeh_dev *edev = (struct eeh_dev *)data;
dev = eeh_dev_to_pci_dev(edev);
if (dev)
*freset |= dev->needs_freset;
return NULL;
}
static void eeh_reset_pe_once(struct eeh_pe *pe)
{
unsigned int freset = 0;
eeh_pe_dev_traverse(pe, eeh_set_dev_freset, &freset);
if (freset)
eeh_ops->reset(pe, EEH_RESET_FUNDAMENTAL);
else
eeh_ops->reset(pe, EEH_RESET_HOT);
#define PCI_BUS_RST_HOLD_TIME_MSEC 250
msleep(PCI_BUS_RST_HOLD_TIME_MSEC);
eeh_pe_state_clear(pe, EEH_PE_ISOLATED);
eeh_ops->reset(pe, EEH_RESET_DEACTIVATE);
#define PCI_BUS_SETTLE_TIME_MSEC 1800
msleep(PCI_BUS_SETTLE_TIME_MSEC);
}
int eeh_reset_pe(struct eeh_pe *pe)
{
int flags = (EEH_STATE_MMIO_ACTIVE | EEH_STATE_DMA_ACTIVE);
int i, rc;
for (i=0; i<3; i++) {
eeh_reset_pe_once(pe);
rc = eeh_ops->wait_state(pe, PCI_BUS_RESET_WAIT_MSEC);
if ((rc & flags) == flags)
return 0;
if (rc < 0) {
pr_err("%s: Unrecoverable slot failure on PHB#%d-PE#%x",
__func__, pe->phb->global_number, pe->addr);
return -1;
}
pr_err("EEH: bus reset %d failed on PHB#%d-PE#%x, rc=%d\n",
i+1, pe->phb->global_number, pe->addr, rc);
}
return -1;
}
void eeh_save_bars(struct eeh_dev *edev)
{
int i;
struct device_node *dn;
if (!edev)
return;
dn = eeh_dev_to_of_node(edev);
for (i = 0; i < 16; i++)
eeh_ops->read_config(dn, i * 4, 4, &edev->config_space[i]);
if (edev->mode & EEH_DEV_BRIDGE)
edev->config_space[1] |= PCI_COMMAND_MASTER;
}
int __init eeh_ops_register(struct eeh_ops *ops)
{
if (!ops->name) {
pr_warning("%s: Invalid EEH ops name for %p\n",
__func__, ops);
return -EINVAL;
}
if (eeh_ops && eeh_ops != ops) {
pr_warning("%s: EEH ops of platform %s already existing (%s)\n",
__func__, eeh_ops->name, ops->name);
return -EEXIST;
}
eeh_ops = ops;
return 0;
}
int __exit eeh_ops_unregister(const char *name)
{
if (!name || !strlen(name)) {
pr_warning("%s: Invalid EEH ops name\n",
__func__);
return -EINVAL;
}
if (eeh_ops && !strcmp(eeh_ops->name, name)) {
eeh_ops = NULL;
return 0;
}
return -EEXIST;
}
int eeh_init(void)
{
struct pci_controller *hose, *tmp;
struct device_node *phb;
static int cnt = 0;
int ret = 0;
if (machine_is(powernv) && cnt++ <= 0)
return ret;
if (!eeh_ops) {
pr_warning("%s: Platform EEH operation not found\n",
__func__);
return -EEXIST;
} else if ((ret = eeh_ops->init())) {
pr_warning("%s: Failed to call platform init function (%d)\n",
__func__, ret);
return ret;
}
ret = eeh_event_init();
if (ret)
return ret;
if (eeh_probe_mode_devtree()) {
list_for_each_entry_safe(hose, tmp,
&hose_list, list_node) {
phb = hose->dn;
traverse_pci_devices(phb, eeh_ops->of_probe, NULL);
}
} else if (eeh_probe_mode_dev()) {
list_for_each_entry_safe(hose, tmp,
&hose_list, list_node)
pci_walk_bus(hose->bus, eeh_ops->dev_probe, NULL);
} else {
pr_warning("%s: Invalid probe mode %d\n",
__func__, eeh_probe_mode);
return -EINVAL;
}
if (eeh_ops->post_init) {
ret = eeh_ops->post_init();
if (ret)
return ret;
}
if (eeh_subsystem_enabled)
pr_info("EEH: PCI Enhanced I/O Error Handling Enabled\n");
else
pr_warning("EEH: No capable adapters found\n");
return ret;
}
void eeh_add_device_early(struct device_node *dn)
{
struct pci_controller *phb;
if (!eeh_probe_mode_devtree())
return;
if (!of_node_to_eeh_dev(dn))
return;
phb = of_node_to_eeh_dev(dn)->phb;
if (NULL == phb || 0 == phb->buid)
return;
eeh_ops->of_probe(dn, NULL);
}
void eeh_add_device_tree_early(struct device_node *dn)
{
struct device_node *sib;
for_each_child_of_node(dn, sib)
eeh_add_device_tree_early(sib);
eeh_add_device_early(dn);
}
void eeh_add_device_late(struct pci_dev *dev)
{
struct device_node *dn;
struct eeh_dev *edev;
if (!dev || !eeh_subsystem_enabled)
return;
pr_debug("EEH: Adding device %s\n", pci_name(dev));
dn = pci_device_to_OF_node(dev);
edev = of_node_to_eeh_dev(dn);
if (edev->pdev == dev) {
pr_debug("EEH: Already referenced !\n");
return;
}
if (edev->pdev) {
eeh_rmv_from_parent_pe(edev);
eeh_addr_cache_rmv_dev(edev->pdev);
eeh_sysfs_remove_device(edev->pdev);
edev->mode &= ~EEH_DEV_SYSFS;
edev->pdev = NULL;
dev->dev.archdata.edev = NULL;
}
edev->pdev = dev;
dev->dev.archdata.edev = edev;
if (eeh_probe_mode_dev())
eeh_ops->dev_probe(dev, NULL);
eeh_addr_cache_insert_dev(dev);
}
void eeh_add_device_tree_late(struct pci_bus *bus)
{
struct pci_dev *dev;
list_for_each_entry(dev, &bus->devices, bus_list) {
eeh_add_device_late(dev);
if (dev->hdr_type == PCI_HEADER_TYPE_BRIDGE) {
struct pci_bus *subbus = dev->subordinate;
if (subbus)
eeh_add_device_tree_late(subbus);
}
}
}
void eeh_add_sysfs_files(struct pci_bus *bus)
{
struct pci_dev *dev;
list_for_each_entry(dev, &bus->devices, bus_list) {
eeh_sysfs_add_device(dev);
if (dev->hdr_type == PCI_HEADER_TYPE_BRIDGE) {
struct pci_bus *subbus = dev->subordinate;
if (subbus)
eeh_add_sysfs_files(subbus);
}
}
}
void eeh_remove_device(struct pci_dev *dev)
{
struct eeh_dev *edev;
if (!dev || !eeh_subsystem_enabled)
return;
edev = pci_dev_to_eeh_dev(dev);
pr_debug("EEH: Removing device %s\n", pci_name(dev));
if (!edev || !edev->pdev || !edev->pe) {
pr_debug("EEH: Not referenced !\n");
return;
}
edev->pdev = NULL;
dev->dev.archdata.edev = NULL;
if (!(edev->pe->state & EEH_PE_KEEP))
eeh_rmv_from_parent_pe(edev);
else
edev->mode |= EEH_DEV_DISCONNECTED;
eeh_addr_cache_rmv_dev(dev);
eeh_sysfs_remove_device(dev);
edev->mode &= ~EEH_DEV_SYSFS;
}
static int proc_eeh_show(struct seq_file *m, void *v)
{
if (0 == eeh_subsystem_enabled) {
seq_printf(m, "EEH Subsystem is globally disabled\n");
seq_printf(m, "eeh_total_mmio_ffs=%llu\n", eeh_stats.total_mmio_ffs);
} else {
seq_printf(m, "EEH Subsystem is enabled\n");
seq_printf(m,
"no device=%llu\n"
"no device node=%llu\n"
"no config address=%llu\n"
"check not wanted=%llu\n"
"eeh_total_mmio_ffs=%llu\n"
"eeh_false_positives=%llu\n"
"eeh_slot_resets=%llu\n",
eeh_stats.no_device,
eeh_stats.no_dn,
eeh_stats.no_cfg_addr,
eeh_stats.ignored_check,
eeh_stats.total_mmio_ffs,
eeh_stats.false_positives,
eeh_stats.slot_resets);
}
return 0;
}
static int proc_eeh_open(struct inode *inode, struct file *file)
{
return single_open(file, proc_eeh_show, NULL);
}
static int __init eeh_init_proc(void)
{
if (machine_is(pseries) || machine_is(powernv))
proc_create("powerpc/eeh", 0, NULL, &proc_eeh_operations);
return 0;
}
