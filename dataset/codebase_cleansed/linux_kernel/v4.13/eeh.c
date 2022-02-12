static int __init eeh_setup(char *str)
{
if (!strcmp(str, "off"))
eeh_add_flag(EEH_FORCE_DISABLED);
else if (!strcmp(str, "early_log"))
eeh_add_flag(EEH_EARLY_DUMP_LOG);
return 1;
}
static size_t eeh_dump_dev_log(struct eeh_dev *edev, char *buf, size_t len)
{
struct pci_dn *pdn = eeh_dev_to_pdn(edev);
u32 cfg;
int cap, i;
int n = 0, l = 0;
char buffer[128];
n += scnprintf(buf+n, len-n, "%04x:%02x:%02x.%01x\n",
edev->phb->global_number, pdn->busno,
PCI_SLOT(pdn->devfn), PCI_FUNC(pdn->devfn));
pr_warn("EEH: of node=%04x:%02x:%02x.%01x\n",
edev->phb->global_number, pdn->busno,
PCI_SLOT(pdn->devfn), PCI_FUNC(pdn->devfn));
eeh_ops->read_config(pdn, PCI_VENDOR_ID, 4, &cfg);
n += scnprintf(buf+n, len-n, "dev/vend:%08x\n", cfg);
pr_warn("EEH: PCI device/vendor: %08x\n", cfg);
eeh_ops->read_config(pdn, PCI_COMMAND, 4, &cfg);
n += scnprintf(buf+n, len-n, "cmd/stat:%x\n", cfg);
pr_warn("EEH: PCI cmd/status register: %08x\n", cfg);
if (edev->mode & EEH_DEV_BRIDGE) {
eeh_ops->read_config(pdn, PCI_SEC_STATUS, 2, &cfg);
n += scnprintf(buf+n, len-n, "sec stat:%x\n", cfg);
pr_warn("EEH: Bridge secondary status: %04x\n", cfg);
eeh_ops->read_config(pdn, PCI_BRIDGE_CONTROL, 2, &cfg);
n += scnprintf(buf+n, len-n, "brdg ctl:%x\n", cfg);
pr_warn("EEH: Bridge control: %04x\n", cfg);
}
cap = edev->pcix_cap;
if (cap) {
eeh_ops->read_config(pdn, cap, 4, &cfg);
n += scnprintf(buf+n, len-n, "pcix-cmd:%x\n", cfg);
pr_warn("EEH: PCI-X cmd: %08x\n", cfg);
eeh_ops->read_config(pdn, cap+4, 4, &cfg);
n += scnprintf(buf+n, len-n, "pcix-stat:%x\n", cfg);
pr_warn("EEH: PCI-X status: %08x\n", cfg);
}
cap = edev->pcie_cap;
if (cap) {
n += scnprintf(buf+n, len-n, "pci-e cap10:\n");
pr_warn("EEH: PCI-E capabilities and status follow:\n");
for (i=0; i<=8; i++) {
eeh_ops->read_config(pdn, cap+4*i, 4, &cfg);
n += scnprintf(buf+n, len-n, "%02x:%x\n", 4*i, cfg);
if ((i % 4) == 0) {
if (i != 0)
pr_warn("%s\n", buffer);
l = scnprintf(buffer, sizeof(buffer),
"EEH: PCI-E %02x: %08x ",
4*i, cfg);
} else {
l += scnprintf(buffer+l, sizeof(buffer)-l,
"%08x ", cfg);
}
}
pr_warn("%s\n", buffer);
}
cap = edev->aer_cap;
if (cap) {
n += scnprintf(buf+n, len-n, "pci-e AER:\n");
pr_warn("EEH: PCI-E AER capability register set follows:\n");
for (i=0; i<=13; i++) {
eeh_ops->read_config(pdn, cap+4*i, 4, &cfg);
n += scnprintf(buf+n, len-n, "%02x:%x\n", 4*i, cfg);
if ((i % 4) == 0) {
if (i != 0)
pr_warn("%s\n", buffer);
l = scnprintf(buffer, sizeof(buffer),
"EEH: PCI-E AER %02x: %08x ",
4*i, cfg);
} else {
l += scnprintf(buffer+l, sizeof(buffer)-l,
"%08x ", cfg);
}
}
pr_warn("%s\n", buffer);
}
return n;
}
static void *eeh_dump_pe_log(void *data, void *flag)
{
struct eeh_pe *pe = data;
struct eeh_dev *edev, *tmp;
size_t *plen = flag;
eeh_pe_for_each_dev(pe, edev, tmp)
*plen += eeh_dump_dev_log(edev, pci_regs_buf + *plen,
EEH_PCI_REGS_LOG_LEN - *plen);
return NULL;
}
void eeh_slot_error_detail(struct eeh_pe *pe, int severity)
{
size_t loglen = 0;
if (!(pe->type & EEH_PE_PHB)) {
if (eeh_has_flag(EEH_ENABLE_IO_FOR_LOG) ||
severity == EEH_LOG_PERM)
eeh_pci_enable(pe, EEH_OPT_THAW_MMIO);
eeh_ops->configure_bridge(pe);
if (!(pe->state & EEH_PE_CFG_BLOCKED)) {
eeh_pe_restore_bars(pe);
pci_regs_buf[0] = 0;
eeh_pe_traverse(pe, eeh_dump_pe_log, &loglen);
}
}
eeh_ops->get_log(pe, severity, pci_regs_buf, loglen);
}
static inline unsigned long eeh_token_to_phys(unsigned long token)
{
pte_t *ptep;
unsigned long pa;
int hugepage_shift;
ptep = __find_linux_pte_or_hugepte(init_mm.pgd, token,
NULL, &hugepage_shift);
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
if (!eeh_has_flag(EEH_PROBE_MODE_DEV))
return -EPERM;
phb_pe = eeh_phb_pe_get(pe->phb);
if (!phb_pe) {
pr_warn("%s Can't find PE for PHB#%x\n",
__func__, pe->phb->global_number);
return -EEXIST;
}
eeh_serialize_lock(&flags);
if (phb_pe->state & EEH_PE_ISOLATED) {
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
pr_err("EEH: PHB#%x failure detected, location: %s\n",
phb_pe->phb->global_number, eeh_pe_loc_get(phb_pe));
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
int active_flags = (EEH_STATE_MMIO_ACTIVE | EEH_STATE_DMA_ACTIVE);
unsigned long flags;
struct pci_dn *pdn;
struct pci_dev *dev;
struct eeh_pe *pe, *parent_pe, *phb_pe;
int rc = 0;
const char *location = NULL;
eeh_stats.total_mmio_ffs++;
if (!eeh_enabled())
return 0;
if (!edev) {
eeh_stats.no_dn++;
return 0;
}
dev = eeh_dev_to_pci_dev(edev);
pe = eeh_dev_to_pe(edev);
if (!pe) {
eeh_stats.ignored_check++;
pr_debug("EEH: Ignored check for %s\n",
eeh_pci_name(dev));
return 0;
}
if (!pe->addr && !pe->config_addr) {
eeh_stats.no_cfg_addr++;
return 0;
}
ret = eeh_phb_check_failure(pe);
if (ret > 0)
return ret;
if (eeh_pe_passed(pe))
return 0;
eeh_serialize_lock(&flags);
rc = 1;
if (pe->state & EEH_PE_ISOLATED) {
pe->check_count++;
if (pe->check_count % EEH_MAX_FAILS == 0) {
pdn = eeh_dev_to_pdn(edev);
if (pdn->node)
location = of_get_property(pdn->node, "ibm,loc-code", NULL);
printk(KERN_ERR "EEH: %d reads ignored for recovering device at "
"location=%s driver=%s pci addr=%s\n",
pe->check_count,
location ? location : "unknown",
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
((ret & active_flags) == active_flags)) {
eeh_stats.false_positives++;
pe->false_positives++;
rc = 0;
goto dn_unlock;
}
parent_pe = pe->parent;
while (parent_pe) {
if (parent_pe->type & EEH_PE_PHB)
break;
ret = eeh_ops->get_state(parent_pe, NULL);
if (ret > 0 &&
(ret & active_flags) != active_flags)
pe = parent_pe;
parent_pe = parent_pe->parent;
}
eeh_stats.slot_resets++;
eeh_pe_state_mark(pe, EEH_PE_ISOLATED);
eeh_serialize_unlock(flags);
phb_pe = eeh_phb_pe_get(pe->phb);
pr_err("EEH: Frozen PHB#%x-PE#%x detected\n",
pe->phb->global_number, pe->addr);
pr_err("EEH: PE location: %s, PHB location: %s\n",
eeh_pe_loc_get(pe), eeh_pe_loc_get(phb_pe));
dump_stack();
eeh_send_failure_event(pe);
return 1;
dn_unlock:
eeh_serialize_unlock(flags);
return rc;
}
int eeh_check_failure(const volatile void __iomem *token)
{
unsigned long addr;
struct eeh_dev *edev;
addr = eeh_token_to_phys((unsigned long __force) token);
edev = eeh_addr_cache_get_dev(addr);
if (!edev) {
eeh_stats.no_device++;
return 0;
}
return eeh_dev_check_failure(edev);
}
int eeh_pci_enable(struct eeh_pe *pe, int function)
{
int active_flag, rc;
switch (function) {
case EEH_OPT_THAW_MMIO:
active_flag = EEH_STATE_MMIO_ACTIVE | EEH_STATE_MMIO_ENABLED;
break;
case EEH_OPT_THAW_DMA:
active_flag = EEH_STATE_DMA_ACTIVE;
break;
case EEH_OPT_DISABLE:
case EEH_OPT_ENABLE:
case EEH_OPT_FREEZE_PE:
active_flag = 0;
break;
default:
pr_warn("%s: Invalid function %d\n",
__func__, function);
return -EINVAL;
}
if (active_flag) {
rc = eeh_ops->get_state(pe, NULL);
if (rc < 0)
return rc;
if (rc == EEH_STATE_NOT_SUPPORT)
return 0;
if (rc & active_flag)
return 0;
}
rc = eeh_ops->set_option(pe, function);
if (rc)
pr_warn("%s: Unexpected state change %d on "
"PHB#%x-PE#%x, err=%d\n",
__func__, function, pe->phb->global_number,
pe->addr, rc);
if (active_flag) {
rc = eeh_ops->wait_state(pe, PCI_BUS_RESET_WAIT_MSEC);
if (rc < 0)
return rc;
if (rc & active_flag)
return 0;
return -EIO;
}
return rc;
}
static void *eeh_disable_and_save_dev_state(void *data, void *userdata)
{
struct eeh_dev *edev = data;
struct pci_dev *pdev = eeh_dev_to_pci_dev(edev);
struct pci_dev *dev = userdata;
if (!pdev || pdev == dev)
return NULL;
pci_set_power_state(pdev, PCI_D0);
pci_save_state(pdev);
pci_write_config_word(pdev, PCI_COMMAND, PCI_COMMAND_INTX_DISABLE);
return NULL;
}
static void *eeh_restore_dev_state(void *data, void *userdata)
{
struct eeh_dev *edev = data;
struct pci_dn *pdn = eeh_dev_to_pdn(edev);
struct pci_dev *pdev = eeh_dev_to_pci_dev(edev);
struct pci_dev *dev = userdata;
if (!pdev)
return NULL;
if (pdn && eeh_ops->restore_config)
eeh_ops->restore_config(pdn);
if (pdev != dev)
pci_restore_state(pdev);
return NULL;
}
int pcibios_set_pcie_reset_state(struct pci_dev *dev, enum pcie_reset_state state)
{
struct eeh_dev *edev = pci_dev_to_eeh_dev(dev);
struct eeh_pe *pe = eeh_dev_to_pe(edev);
if (!pe) {
pr_err("%s: No PE found on PCI device %s\n",
__func__, pci_name(dev));
return -EINVAL;
}
switch (state) {
case pcie_deassert_reset:
eeh_ops->reset(pe, EEH_RESET_DEACTIVATE);
eeh_unfreeze_pe(pe, false);
if (!(pe->type & EEH_PE_VF))
eeh_pe_state_clear(pe, EEH_PE_CFG_BLOCKED);
eeh_pe_dev_traverse(pe, eeh_restore_dev_state, dev);
eeh_pe_state_clear(pe, EEH_PE_ISOLATED);
break;
case pcie_hot_reset:
eeh_pe_state_mark_with_cfg(pe, EEH_PE_ISOLATED);
eeh_ops->set_option(pe, EEH_OPT_FREEZE_PE);
eeh_pe_dev_traverse(pe, eeh_disable_and_save_dev_state, dev);
if (!(pe->type & EEH_PE_VF))
eeh_pe_state_mark(pe, EEH_PE_CFG_BLOCKED);
eeh_ops->reset(pe, EEH_RESET_HOT);
break;
case pcie_warm_reset:
eeh_pe_state_mark_with_cfg(pe, EEH_PE_ISOLATED);
eeh_ops->set_option(pe, EEH_OPT_FREEZE_PE);
eeh_pe_dev_traverse(pe, eeh_disable_and_save_dev_state, dev);
if (!(pe->type & EEH_PE_VF))
eeh_pe_state_mark(pe, EEH_PE_CFG_BLOCKED);
eeh_ops->reset(pe, EEH_RESET_FUNDAMENTAL);
break;
default:
eeh_pe_state_clear(pe, EEH_PE_ISOLATED | EEH_PE_CFG_BLOCKED);
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
int eeh_pe_reset_full(struct eeh_pe *pe)
{
int active_flags = (EEH_STATE_MMIO_ACTIVE | EEH_STATE_DMA_ACTIVE);
int reset_state = (EEH_PE_RESET | EEH_PE_CFG_BLOCKED);
int type = EEH_RESET_HOT;
unsigned int freset = 0;
int i, state, ret;
eeh_pe_dev_traverse(pe, eeh_set_dev_freset, &freset);
if (freset)
type = EEH_RESET_FUNDAMENTAL;
eeh_pe_state_mark(pe, reset_state);
for (i = 0; i < 3; i++) {
ret = eeh_pe_reset(pe, type);
if (ret)
break;
ret = eeh_pe_reset(pe, EEH_RESET_DEACTIVATE);
if (ret)
break;
state = eeh_ops->wait_state(pe, PCI_BUS_RESET_WAIT_MSEC);
if ((state & active_flags) == active_flags)
break;
if (state < 0) {
pr_warn("%s: Unrecoverable slot failure on PHB#%x-PE#%x",
__func__, pe->phb->global_number, pe->addr);
ret = -ENOTRECOVERABLE;
break;
}
ret = -EIO;
pr_warn("%s: Failure %d resetting PHB#%x-PE#%x\n (%d)\n",
__func__, state, pe->phb->global_number, pe->addr, (i + 1));
}
eeh_pe_state_clear(pe, reset_state);
return ret;
}
void eeh_save_bars(struct eeh_dev *edev)
{
struct pci_dn *pdn;
int i;
pdn = eeh_dev_to_pdn(edev);
if (!pdn)
return;
for (i = 0; i < 16; i++)
eeh_ops->read_config(pdn, i * 4, 4, &edev->config_space[i]);
if (edev->mode & EEH_DEV_BRIDGE)
edev->config_space[1] |= PCI_COMMAND_MASTER;
}
int __init eeh_ops_register(struct eeh_ops *ops)
{
if (!ops->name) {
pr_warn("%s: Invalid EEH ops name for %p\n",
__func__, ops);
return -EINVAL;
}
if (eeh_ops && eeh_ops != ops) {
pr_warn("%s: EEH ops of platform %s already existing (%s)\n",
__func__, eeh_ops->name, ops->name);
return -EEXIST;
}
eeh_ops = ops;
return 0;
}
int __exit eeh_ops_unregister(const char *name)
{
if (!name || !strlen(name)) {
pr_warn("%s: Invalid EEH ops name\n",
__func__);
return -EINVAL;
}
if (eeh_ops && !strcmp(eeh_ops->name, name)) {
eeh_ops = NULL;
return 0;
}
return -EEXIST;
}
static int eeh_reboot_notifier(struct notifier_block *nb,
unsigned long action, void *unused)
{
eeh_clear_flag(EEH_ENABLED);
return NOTIFY_DONE;
}
int eeh_init(void)
{
struct pci_controller *hose, *tmp;
struct pci_dn *pdn;
static int cnt = 0;
int ret = 0;
if (machine_is(powernv) && cnt++ <= 0)
return ret;
ret = register_reboot_notifier(&eeh_reboot_nb);
if (ret) {
pr_warn("%s: Failed to register notifier (%d)\n",
__func__, ret);
return ret;
}
if (!eeh_ops) {
pr_warn("%s: Platform EEH operation not found\n",
__func__);
return -EEXIST;
} else if ((ret = eeh_ops->init()))
return ret;
ret = eeh_event_init();
if (ret)
return ret;
list_for_each_entry_safe(hose, tmp, &hose_list, list_node) {
pdn = hose->pci_data;
traverse_pci_dn(pdn, eeh_ops->probe, NULL);
}
if (eeh_ops->post_init) {
ret = eeh_ops->post_init();
if (ret)
return ret;
}
if (eeh_enabled())
pr_info("EEH: PCI Enhanced I/O Error Handling Enabled\n");
else
pr_info("EEH: No capable adapters found\n");
return ret;
}
void eeh_add_device_early(struct pci_dn *pdn)
{
struct pci_controller *phb;
struct eeh_dev *edev = pdn_to_eeh_dev(pdn);
if (!edev)
return;
if (!eeh_has_flag(EEH_PROBE_MODE_DEVTREE))
return;
phb = edev->phb;
if (NULL == phb ||
(eeh_has_flag(EEH_PROBE_MODE_DEVTREE) && 0 == phb->buid))
return;
eeh_ops->probe(pdn, NULL);
}
void eeh_add_device_tree_early(struct pci_dn *pdn)
{
struct pci_dn *n;
if (!pdn)
return;
list_for_each_entry(n, &pdn->child_list, list)
eeh_add_device_tree_early(n);
eeh_add_device_early(pdn);
}
void eeh_add_device_late(struct pci_dev *dev)
{
struct pci_dn *pdn;
struct eeh_dev *edev;
if (!dev || !eeh_enabled())
return;
pr_debug("EEH: Adding device %s\n", pci_name(dev));
pdn = pci_get_pdn_by_devfn(dev->bus, dev->devfn);
edev = pdn_to_eeh_dev(pdn);
if (edev->pdev == dev) {
pr_debug("EEH: Already referenced !\n");
return;
}
if (edev->pdev) {
eeh_rmv_from_parent_pe(edev);
eeh_addr_cache_rmv_dev(edev->pdev);
eeh_sysfs_remove_device(edev->pdev);
edev->mode &= ~EEH_DEV_SYSFS;
edev->mode |= EEH_DEV_NO_HANDLER;
edev->pdev = NULL;
dev->dev.archdata.edev = NULL;
}
if (eeh_has_flag(EEH_PROBE_MODE_DEV))
eeh_ops->probe(pdn, NULL);
edev->pdev = dev;
dev->dev.archdata.edev = edev;
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
if (!dev || !eeh_enabled())
return;
edev = pci_dev_to_eeh_dev(dev);
pr_debug("EEH: Removing device %s\n", pci_name(dev));
if (!edev || !edev->pdev || !edev->pe) {
pr_debug("EEH: Not referenced !\n");
return;
}
edev->pdev = NULL;
edev->in_error = false;
dev->dev.archdata.edev = NULL;
if (!(edev->pe->state & EEH_PE_KEEP))
eeh_rmv_from_parent_pe(edev);
else
edev->mode |= EEH_DEV_DISCONNECTED;
edev->mode |= EEH_DEV_NO_HANDLER;
eeh_addr_cache_rmv_dev(dev);
eeh_sysfs_remove_device(dev);
edev->mode &= ~EEH_DEV_SYSFS;
}
int eeh_unfreeze_pe(struct eeh_pe *pe, bool sw_state)
{
int ret;
ret = eeh_pci_enable(pe, EEH_OPT_THAW_MMIO);
if (ret) {
pr_warn("%s: Failure %d enabling IO on PHB#%x-PE#%x\n",
__func__, ret, pe->phb->global_number, pe->addr);
return ret;
}
ret = eeh_pci_enable(pe, EEH_OPT_THAW_DMA);
if (ret) {
pr_warn("%s: Failure %d enabling DMA on PHB#%x-PE#%x\n",
__func__, ret, pe->phb->global_number, pe->addr);
return ret;
}
if (sw_state && (pe->state & EEH_PE_ISOLATED))
eeh_pe_state_clear(pe, EEH_PE_ISOLATED);
return ret;
}
static int eeh_pe_change_owner(struct eeh_pe *pe)
{
struct eeh_dev *edev, *tmp;
struct pci_dev *pdev;
struct pci_device_id *id;
int flags, ret;
flags = (EEH_STATE_MMIO_ACTIVE | EEH_STATE_DMA_ACTIVE);
ret = eeh_ops->get_state(pe, NULL);
if (ret < 0 || ret == EEH_STATE_NOT_SUPPORT)
return 0;
if ((ret & flags) == flags)
return 0;
eeh_pe_for_each_dev(pe, edev, tmp) {
pdev = eeh_dev_to_pci_dev(edev);
if (!pdev)
continue;
for (id = &eeh_reset_ids[0]; id->vendor != 0; id++) {
if (id->vendor != PCI_ANY_ID &&
id->vendor != pdev->vendor)
continue;
if (id->device != PCI_ANY_ID &&
id->device != pdev->device)
continue;
if (id->subvendor != PCI_ANY_ID &&
id->subvendor != pdev->subsystem_vendor)
continue;
if (id->subdevice != PCI_ANY_ID &&
id->subdevice != pdev->subsystem_device)
continue;
return eeh_pe_reset_and_recover(pe);
}
}
return eeh_unfreeze_pe(pe, true);
}
int eeh_dev_open(struct pci_dev *pdev)
{
struct eeh_dev *edev;
int ret = -ENODEV;
mutex_lock(&eeh_dev_mutex);
if (!pdev)
goto out;
edev = pci_dev_to_eeh_dev(pdev);
if (!edev || !edev->pe)
goto out;
ret = eeh_pe_change_owner(edev->pe);
if (ret)
goto out;
atomic_inc(&edev->pe->pass_dev_cnt);
mutex_unlock(&eeh_dev_mutex);
return 0;
out:
mutex_unlock(&eeh_dev_mutex);
return ret;
}
void eeh_dev_release(struct pci_dev *pdev)
{
struct eeh_dev *edev;
mutex_lock(&eeh_dev_mutex);
if (!pdev)
goto out;
edev = pci_dev_to_eeh_dev(pdev);
if (!edev || !edev->pe || !eeh_pe_passed(edev->pe))
goto out;
WARN_ON(atomic_dec_if_positive(&edev->pe->pass_dev_cnt) < 0);
eeh_pe_change_owner(edev->pe);
out:
mutex_unlock(&eeh_dev_mutex);
}
static int dev_has_iommu_table(struct device *dev, void *data)
{
struct pci_dev *pdev = to_pci_dev(dev);
struct pci_dev **ppdev = data;
if (!dev)
return 0;
if (dev->iommu_group) {
*ppdev = pdev;
return 1;
}
return 0;
}
struct eeh_pe *eeh_iommu_group_to_pe(struct iommu_group *group)
{
struct pci_dev *pdev = NULL;
struct eeh_dev *edev;
int ret;
if (!group)
return NULL;
ret = iommu_group_for_each_dev(group, &pdev, dev_has_iommu_table);
if (!ret || !pdev)
return NULL;
edev = pci_dev_to_eeh_dev(pdev);
if (!edev || !edev->pe)
return NULL;
return edev->pe;
}
int eeh_pe_set_option(struct eeh_pe *pe, int option)
{
int ret = 0;
if (!pe)
return -ENODEV;
switch (option) {
case EEH_OPT_ENABLE:
if (eeh_enabled()) {
ret = eeh_pe_change_owner(pe);
break;
}
ret = -EIO;
break;
case EEH_OPT_DISABLE:
break;
case EEH_OPT_THAW_MMIO:
case EEH_OPT_THAW_DMA:
case EEH_OPT_FREEZE_PE:
if (!eeh_ops || !eeh_ops->set_option) {
ret = -ENOENT;
break;
}
ret = eeh_pci_enable(pe, option);
break;
default:
pr_debug("%s: Option %d out of range (%d, %d)\n",
__func__, option, EEH_OPT_DISABLE, EEH_OPT_THAW_DMA);
ret = -EINVAL;
}
return ret;
}
int eeh_pe_get_state(struct eeh_pe *pe)
{
int result, ret = 0;
bool rst_active, dma_en, mmio_en;
if (!pe)
return -ENODEV;
if (!eeh_ops || !eeh_ops->get_state)
return -ENOENT;
if (pe->parent &&
!(pe->state & EEH_PE_REMOVED) &&
(pe->parent->state & (EEH_PE_ISOLATED | EEH_PE_RECOVERING)))
return EEH_PE_STATE_UNAVAIL;
result = eeh_ops->get_state(pe, NULL);
rst_active = !!(result & EEH_STATE_RESET_ACTIVE);
dma_en = !!(result & EEH_STATE_DMA_ENABLED);
mmio_en = !!(result & EEH_STATE_MMIO_ENABLED);
if (rst_active)
ret = EEH_PE_STATE_RESET;
else if (dma_en && mmio_en)
ret = EEH_PE_STATE_NORMAL;
else if (!dma_en && !mmio_en)
ret = EEH_PE_STATE_STOPPED_IO_DMA;
else if (!dma_en && mmio_en)
ret = EEH_PE_STATE_STOPPED_DMA;
else
ret = EEH_PE_STATE_UNAVAIL;
return ret;
}
static int eeh_pe_reenable_devices(struct eeh_pe *pe)
{
struct eeh_dev *edev, *tmp;
struct pci_dev *pdev;
int ret = 0;
eeh_pe_restore_bars(pe);
eeh_pe_for_each_dev(pe, edev, tmp) {
pdev = eeh_dev_to_pci_dev(edev);
if (!pdev)
continue;
ret = pci_reenable_device(pdev);
if (ret) {
pr_warn("%s: Failure %d reenabling %s\n",
__func__, ret, pci_name(pdev));
return ret;
}
}
return eeh_unfreeze_pe(pe, true);
}
int eeh_pe_reset(struct eeh_pe *pe, int option)
{
int ret = 0;
if (!pe)
return -ENODEV;
if (!eeh_ops || !eeh_ops->set_option || !eeh_ops->reset)
return -ENOENT;
switch (option) {
case EEH_RESET_DEACTIVATE:
ret = eeh_ops->reset(pe, option);
eeh_pe_state_clear(pe, EEH_PE_CFG_BLOCKED);
if (ret)
break;
ret = eeh_pe_reenable_devices(pe);
break;
case EEH_RESET_HOT:
case EEH_RESET_FUNDAMENTAL:
eeh_ops->set_option(pe, EEH_OPT_FREEZE_PE);
eeh_pe_state_mark(pe, EEH_PE_CFG_BLOCKED);
ret = eeh_ops->reset(pe, option);
break;
default:
pr_debug("%s: Unsupported option %d\n",
__func__, option);
ret = -EINVAL;
}
return ret;
}
int eeh_pe_configure(struct eeh_pe *pe)
{
int ret = 0;
if (!pe)
return -ENODEV;
return ret;
}
int eeh_pe_inject_err(struct eeh_pe *pe, int type, int func,
unsigned long addr, unsigned long mask)
{
if (!pe)
return -ENODEV;
if (!eeh_ops || !eeh_ops->err_inject)
return -ENOENT;
if (type != EEH_ERR_TYPE_32 && type != EEH_ERR_TYPE_64)
return -EINVAL;
if (func < EEH_ERR_FUNC_MIN || func > EEH_ERR_FUNC_MAX)
return -EINVAL;
return eeh_ops->err_inject(pe, type, func, addr, mask);
}
static int proc_eeh_show(struct seq_file *m, void *v)
{
if (!eeh_enabled()) {
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
static int eeh_enable_dbgfs_set(void *data, u64 val)
{
if (val)
eeh_clear_flag(EEH_FORCE_DISABLED);
else
eeh_add_flag(EEH_FORCE_DISABLED);
if (eeh_ops->post_init)
eeh_ops->post_init();
return 0;
}
static int eeh_enable_dbgfs_get(void *data, u64 *val)
{
if (eeh_enabled())
*val = 0x1ul;
else
*val = 0x0ul;
return 0;
}
static int eeh_freeze_dbgfs_set(void *data, u64 val)
{
eeh_max_freezes = val;
return 0;
}
static int eeh_freeze_dbgfs_get(void *data, u64 *val)
{
*val = eeh_max_freezes;
return 0;
}
static int __init eeh_init_proc(void)
{
if (machine_is(pseries) || machine_is(powernv)) {
proc_create("powerpc/eeh", 0, NULL, &proc_eeh_operations);
#ifdef CONFIG_DEBUG_FS
debugfs_create_file("eeh_enable", 0600,
powerpc_debugfs_root, NULL,
&eeh_enable_dbgfs_ops);
debugfs_create_file("eeh_max_freezes", 0600,
powerpc_debugfs_root, NULL,
&eeh_freeze_dbgfs_ops);
#endif
}
return 0;
}
