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
cap = pci_find_capability(dev, PCI_CAP_ID_EXP);
if (cap) {
n += scnprintf(buf+n, len-n, "pci-e cap10:\n");
printk(KERN_WARNING
"EEH: PCI-E capabilities and status follow:\n");
for (i=0; i<=8; i++) {
eeh_ops->read_config(dn, cap+4*i, 4, &cfg);
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
struct eeh_dev *edev;
eeh_pci_enable(pe, EEH_OPT_THAW_MMIO);
eeh_ops->configure_bridge(pe);
eeh_pe_restore_bars(pe);
pci_regs_buf[0] = 0;
eeh_pe_for_each_dev(pe, edev) {
loglen += eeh_gather_pci_data(edev, pci_regs_buf,
EEH_PCI_REGS_LOG_LEN);
}
eeh_ops->get_log(pe, severity, pci_regs_buf, loglen);
}
static inline unsigned long eeh_token_to_phys(unsigned long token)
{
pte_t *ptep;
unsigned long pa;
ptep = find_linux_pte(init_mm.pgd, token);
if (!ptep)
return token;
pa = pte_pfn(*ptep) << PAGE_SHIFT;
return pa | (token & (PAGE_SIZE-1));
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
raw_spin_lock_irqsave(&confirm_error_lock, flags);
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
raw_spin_unlock_irqrestore(&confirm_error_lock, flags);
eeh_send_failure_event(pe);
WARN(1, "EEH: failure detected\n");
return 1;
dn_unlock:
raw_spin_unlock_irqrestore(&confirm_error_lock, flags);
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
pci_dev_put(eeh_dev_to_pci_dev(edev));
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
int i, rc;
for (i=0; i<3; i++) {
eeh_reset_pe_once(pe);
rc = eeh_ops->wait_state(pe, PCI_BUS_RESET_WAIT_MSEC);
if (rc == (EEH_STATE_MMIO_ACTIVE | EEH_STATE_DMA_ACTIVE))
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
static int __init eeh_init(void)
{
struct pci_controller *hose, *tmp;
struct device_node *phb;
int ret;
if (!eeh_ops) {
pr_warning("%s: Platform EEH operation not found\n",
__func__);
return -EEXIST;
} else if ((ret = eeh_ops->init())) {
pr_warning("%s: Failed to call platform init function (%d)\n",
__func__, ret);
return ret;
}
raw_spin_lock_init(&confirm_error_lock);
if (eeh_probe_mode_devtree()) {
list_for_each_entry_safe(hose, tmp,
&hose_list, list_node) {
phb = hose->dn;
traverse_pci_devices(phb, eeh_ops->of_probe, NULL);
}
}
if (eeh_subsystem_enabled)
pr_info("EEH: PCI Enhanced I/O Error Handling Enabled\n");
else
pr_warning("EEH: No capable adapters found\n");
return ret;
}
static void eeh_add_device_early(struct device_node *dn)
{
struct pci_controller *phb;
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
static void eeh_add_device_late(struct pci_dev *dev)
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
WARN_ON(edev->pdev);
pci_dev_get(dev);
edev->pdev = dev;
dev->dev.archdata.edev = edev;
eeh_addr_cache_insert_dev(dev);
eeh_sysfs_add_device(dev);
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
static void eeh_remove_device(struct pci_dev *dev, int purge_pe)
{
struct eeh_dev *edev;
if (!dev || !eeh_subsystem_enabled)
return;
edev = pci_dev_to_eeh_dev(dev);
pr_debug("EEH: Removing device %s\n", pci_name(dev));
if (!edev || !edev->pdev) {
pr_debug("EEH: Not referenced !\n");
return;
}
edev->pdev = NULL;
dev->dev.archdata.edev = NULL;
pci_dev_put(dev);
eeh_rmv_from_parent_pe(edev, purge_pe);
eeh_addr_cache_rmv_dev(dev);
eeh_sysfs_remove_device(dev);
}
void eeh_remove_bus_device(struct pci_dev *dev, int purge_pe)
{
struct pci_bus *bus = dev->subordinate;
struct pci_dev *child, *tmp;
eeh_remove_device(dev, purge_pe);
if (bus && dev->hdr_type == PCI_HEADER_TYPE_BRIDGE) {
list_for_each_entry_safe(child, tmp, &bus->devices, bus_list)
eeh_remove_bus_device(child, purge_pe);
}
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
if (machine_is(pseries))
proc_create("powerpc/eeh", 0, NULL, &proc_eeh_operations);
return 0;
}
