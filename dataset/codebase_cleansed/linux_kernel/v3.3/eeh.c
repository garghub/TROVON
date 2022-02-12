static void rtas_slot_error_detail(struct pci_dn *pdn, int severity,
char *driver_log, size_t loglen)
{
int config_addr;
unsigned long flags;
int rc;
spin_lock_irqsave(&slot_errbuf_lock, flags);
memset(slot_errbuf, 0, eeh_error_buf_size);
config_addr = pdn->eeh_config_addr;
if (pdn->eeh_pe_config_addr)
config_addr = pdn->eeh_pe_config_addr;
rc = rtas_call(ibm_slot_error_detail,
8, 1, NULL, config_addr,
BUID_HI(pdn->phb->buid),
BUID_LO(pdn->phb->buid),
virt_to_phys(driver_log), loglen,
virt_to_phys(slot_errbuf),
eeh_error_buf_size,
severity);
if (rc == 0)
log_error(slot_errbuf, ERR_TYPE_RTAS_LOG, 0);
spin_unlock_irqrestore(&slot_errbuf_lock, flags);
}
static size_t gather_pci_data(struct pci_dn *pdn, char * buf, size_t len)
{
struct pci_dev *dev = pdn->pcidev;
u32 cfg;
int cap, i;
int n = 0;
n += scnprintf(buf+n, len-n, "%s\n", pdn->node->full_name);
printk(KERN_WARNING "EEH: of node=%s\n", pdn->node->full_name);
rtas_read_config(pdn, PCI_VENDOR_ID, 4, &cfg);
n += scnprintf(buf+n, len-n, "dev/vend:%08x\n", cfg);
printk(KERN_WARNING "EEH: PCI device/vendor: %08x\n", cfg);
rtas_read_config(pdn, PCI_COMMAND, 4, &cfg);
n += scnprintf(buf+n, len-n, "cmd/stat:%x\n", cfg);
printk(KERN_WARNING "EEH: PCI cmd/status register: %08x\n", cfg);
if (!dev) {
printk(KERN_WARNING "EEH: no PCI device for this of node\n");
return n;
}
if (dev->class >> 16 == PCI_BASE_CLASS_BRIDGE) {
rtas_read_config(pdn, PCI_SEC_STATUS, 2, &cfg);
n += scnprintf(buf+n, len-n, "sec stat:%x\n", cfg);
printk(KERN_WARNING "EEH: Bridge secondary status: %04x\n", cfg);
rtas_read_config(pdn, PCI_BRIDGE_CONTROL, 2, &cfg);
n += scnprintf(buf+n, len-n, "brdg ctl:%x\n", cfg);
printk(KERN_WARNING "EEH: Bridge control: %04x\n", cfg);
}
cap = pci_find_capability(dev, PCI_CAP_ID_PCIX);
if (cap) {
rtas_read_config(pdn, cap, 4, &cfg);
n += scnprintf(buf+n, len-n, "pcix-cmd:%x\n", cfg);
printk(KERN_WARNING "EEH: PCI-X cmd: %08x\n", cfg);
rtas_read_config(pdn, cap+4, 4, &cfg);
n += scnprintf(buf+n, len-n, "pcix-stat:%x\n", cfg);
printk(KERN_WARNING "EEH: PCI-X status: %08x\n", cfg);
}
cap = pci_find_capability(dev, PCI_CAP_ID_EXP);
if (cap) {
n += scnprintf(buf+n, len-n, "pci-e cap10:\n");
printk(KERN_WARNING
"EEH: PCI-E capabilities and status follow:\n");
for (i=0; i<=8; i++) {
rtas_read_config(pdn, cap+4*i, 4, &cfg);
n += scnprintf(buf+n, len-n, "%02x:%x\n", 4*i, cfg);
printk(KERN_WARNING "EEH: PCI-E %02x: %08x\n", i, cfg);
}
cap = pci_find_ext_capability(dev, PCI_EXT_CAP_ID_ERR);
if (cap) {
n += scnprintf(buf+n, len-n, "pci-e AER:\n");
printk(KERN_WARNING
"EEH: PCI-E AER capability register set follows:\n");
for (i=0; i<14; i++) {
rtas_read_config(pdn, cap+4*i, 4, &cfg);
n += scnprintf(buf+n, len-n, "%02x:%x\n", 4*i, cfg);
printk(KERN_WARNING "EEH: PCI-E AER %02x: %08x\n", i, cfg);
}
}
}
if (dev->class >> 16 == PCI_BASE_CLASS_BRIDGE) {
struct device_node *dn;
for_each_child_of_node(pdn->node, dn) {
pdn = PCI_DN(dn);
if (pdn)
n += gather_pci_data(pdn, buf+n, len-n);
}
}
return n;
}
void eeh_slot_error_detail(struct pci_dn *pdn, int severity)
{
size_t loglen = 0;
pci_regs_buf[0] = 0;
rtas_pci_enable(pdn, EEH_THAW_MMIO);
rtas_configure_bridge(pdn);
eeh_restore_bars(pdn);
loglen = gather_pci_data(pdn, pci_regs_buf, EEH_PCI_REGS_LOG_LEN);
rtas_slot_error_detail(pdn, severity, pci_regs_buf, loglen);
}
static int read_slot_reset_state(struct pci_dn *pdn, int rets[])
{
int token, outputs;
int config_addr;
if (ibm_read_slot_reset_state2 != RTAS_UNKNOWN_SERVICE) {
token = ibm_read_slot_reset_state2;
outputs = 4;
} else {
token = ibm_read_slot_reset_state;
rets[2] = 0;
outputs = 3;
}
config_addr = pdn->eeh_config_addr;
if (pdn->eeh_pe_config_addr)
config_addr = pdn->eeh_pe_config_addr;
return rtas_call(token, 3, outputs, rets, config_addr,
BUID_HI(pdn->phb->buid), BUID_LO(pdn->phb->buid));
}
int
eeh_wait_for_slot_status(struct pci_dn *pdn, int max_wait_msecs)
{
int rc;
int rets[3];
int mwait;
while (1) {
rc = read_slot_reset_state(pdn, rets);
if (rc) return rc;
if (rets[1] == 0) return -1;
if (rets[0] != 5) return rets[0];
if (rets[2] == 0) return -1;
if (max_wait_msecs <= 0) break;
mwait = rets[2];
if (mwait <= 0) {
printk (KERN_WARNING
"EEH: Firmware returned bad wait value=%d\n", mwait);
mwait = 1000;
} else if (mwait > 300*1000) {
printk (KERN_WARNING
"EEH: Firmware is taking too long, time=%d\n", mwait);
mwait = 300*1000;
}
max_wait_msecs -= mwait;
msleep (mwait);
}
printk(KERN_WARNING "EEH: Timed out waiting for slot status\n");
return -2;
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
struct device_node * find_device_pe(struct device_node *dn)
{
while ((dn->parent) && PCI_DN(dn->parent) &&
(PCI_DN(dn->parent)->eeh_mode & EEH_MODE_SUPPORTED)) {
dn = dn->parent;
}
return dn;
}
static void __eeh_mark_slot(struct device_node *parent, int mode_flag)
{
struct device_node *dn;
for_each_child_of_node(parent, dn) {
if (PCI_DN(dn)) {
struct pci_dev *dev = PCI_DN(dn)->pcidev;
PCI_DN(dn)->eeh_mode |= mode_flag;
if (dev && dev->driver)
dev->error_state = pci_channel_io_frozen;
__eeh_mark_slot(dn, mode_flag);
}
}
}
void eeh_mark_slot (struct device_node *dn, int mode_flag)
{
struct pci_dev *dev;
dn = find_device_pe (dn);
if (!pcibios_find_pci_bus(dn) && PCI_DN(dn->parent))
dn = dn->parent;
PCI_DN(dn)->eeh_mode |= mode_flag;
dev = PCI_DN(dn)->pcidev;
if (dev)
dev->error_state = pci_channel_io_frozen;
__eeh_mark_slot(dn, mode_flag);
}
static void __eeh_clear_slot(struct device_node *parent, int mode_flag)
{
struct device_node *dn;
for_each_child_of_node(parent, dn) {
if (PCI_DN(dn)) {
PCI_DN(dn)->eeh_mode &= ~mode_flag;
PCI_DN(dn)->eeh_check_count = 0;
__eeh_clear_slot(dn, mode_flag);
}
}
}
void eeh_clear_slot (struct device_node *dn, int mode_flag)
{
unsigned long flags;
raw_spin_lock_irqsave(&confirm_error_lock, flags);
dn = find_device_pe (dn);
if (!pcibios_find_pci_bus(dn) && PCI_DN(dn->parent))
dn = dn->parent;
PCI_DN(dn)->eeh_mode &= ~mode_flag;
PCI_DN(dn)->eeh_check_count = 0;
__eeh_clear_slot(dn, mode_flag);
raw_spin_unlock_irqrestore(&confirm_error_lock, flags);
}
void __eeh_set_pe_freset(struct device_node *parent, unsigned int *freset)
{
struct device_node *dn;
for_each_child_of_node(parent, dn) {
if (PCI_DN(dn)) {
struct pci_dev *dev = PCI_DN(dn)->pcidev;
if (dev && dev->driver)
*freset |= dev->needs_freset;
__eeh_set_pe_freset(dn, freset);
}
}
}
void eeh_set_pe_freset(struct device_node *dn, unsigned int *freset)
{
struct pci_dev *dev;
dn = find_device_pe(dn);
if (!pcibios_find_pci_bus(dn) && PCI_DN(dn->parent))
dn = dn->parent;
dev = PCI_DN(dn)->pcidev;
if (dev)
*freset |= dev->needs_freset;
__eeh_set_pe_freset(dn, freset);
}
int eeh_dn_check_failure(struct device_node *dn, struct pci_dev *dev)
{
int ret;
int rets[3];
unsigned long flags;
struct pci_dn *pdn;
int rc = 0;
const char *location;
total_mmio_ffs++;
if (!eeh_subsystem_enabled)
return 0;
if (!dn) {
no_dn++;
return 0;
}
dn = find_device_pe(dn);
pdn = PCI_DN(dn);
if (!(pdn->eeh_mode & EEH_MODE_SUPPORTED) ||
pdn->eeh_mode & EEH_MODE_NOCHECK) {
ignored_check++;
pr_debug("EEH: Ignored check (%x) for %s %s\n",
pdn->eeh_mode, eeh_pci_name(dev), dn->full_name);
return 0;
}
if (!pdn->eeh_config_addr && !pdn->eeh_pe_config_addr) {
no_cfg_addr++;
return 0;
}
raw_spin_lock_irqsave(&confirm_error_lock, flags);
rc = 1;
if (pdn->eeh_mode & EEH_MODE_ISOLATED) {
pdn->eeh_check_count ++;
if (pdn->eeh_check_count % EEH_MAX_FAILS == 0) {
location = of_get_property(dn, "ibm,loc-code", NULL);
printk (KERN_ERR "EEH: %d reads ignored for recovering device at "
"location=%s driver=%s pci addr=%s\n",
pdn->eeh_check_count, location,
eeh_driver_name(dev), eeh_pci_name(dev));
printk (KERN_ERR "EEH: Might be infinite loop in %s driver\n",
eeh_driver_name(dev));
dump_stack();
}
goto dn_unlock;
}
ret = read_slot_reset_state(pdn, rets);
if (ret != 0) {
printk(KERN_WARNING "EEH: read_slot_reset_state() failed; rc=%d dn=%s\n",
ret, dn->full_name);
false_positives++;
pdn->eeh_false_positives ++;
rc = 0;
goto dn_unlock;
}
if ((rets[0] == 5) && (rets[2] == 0) && (dn->child == NULL)) {
false_positives++;
pdn->eeh_false_positives ++;
rc = 0;
goto dn_unlock;
}
if (rets[1] != 1) {
printk(KERN_WARNING "EEH: event on unsupported device, rc=%d dn=%s\n",
ret, dn->full_name);
false_positives++;
pdn->eeh_false_positives ++;
rc = 0;
goto dn_unlock;
}
if (rets[0] != 1 && rets[0] != 2 && rets[0] != 4 && rets[0] != 5) {
false_positives++;
pdn->eeh_false_positives ++;
rc = 0;
goto dn_unlock;
}
slot_resets++;
eeh_mark_slot (dn, EEH_MODE_ISOLATED);
raw_spin_unlock_irqrestore(&confirm_error_lock, flags);
eeh_send_failure_event (dn, dev);
dump_stack();
return 1;
dn_unlock:
raw_spin_unlock_irqrestore(&confirm_error_lock, flags);
return rc;
}
unsigned long eeh_check_failure(const volatile void __iomem *token, unsigned long val)
{
unsigned long addr;
struct pci_dev *dev;
struct device_node *dn;
addr = eeh_token_to_phys((unsigned long __force) token);
dev = pci_get_device_by_addr(addr);
if (!dev) {
no_device++;
return val;
}
dn = pci_device_to_OF_node(dev);
eeh_dn_check_failure (dn, dev);
pci_dev_put(dev);
return val;
}
int
rtas_pci_enable(struct pci_dn *pdn, int function)
{
int config_addr;
int rc;
config_addr = pdn->eeh_config_addr;
if (pdn->eeh_pe_config_addr)
config_addr = pdn->eeh_pe_config_addr;
rc = rtas_call(ibm_set_eeh_option, 4, 1, NULL,
config_addr,
BUID_HI(pdn->phb->buid),
BUID_LO(pdn->phb->buid),
function);
if (rc)
printk(KERN_WARNING "EEH: Unexpected state change %d, err=%d dn=%s\n",
function, rc, pdn->node->full_name);
rc = eeh_wait_for_slot_status (pdn, PCI_BUS_RESET_WAIT_MSEC);
if ((rc == 4) && (function == EEH_THAW_MMIO))
return 0;
return rc;
}
static void
rtas_pci_slot_reset(struct pci_dn *pdn, int state)
{
int config_addr;
int rc;
BUG_ON (pdn==NULL);
if (!pdn->phb) {
printk (KERN_WARNING "EEH: in slot reset, device node %s has no phb\n",
pdn->node->full_name);
return;
}
config_addr = pdn->eeh_config_addr;
if (pdn->eeh_pe_config_addr)
config_addr = pdn->eeh_pe_config_addr;
rc = rtas_call(ibm_set_slot_reset, 4, 1, NULL,
config_addr,
BUID_HI(pdn->phb->buid),
BUID_LO(pdn->phb->buid),
state);
if (rc == -8 && state == 3) {
rc = rtas_call(ibm_set_slot_reset, 4, 1, NULL,
config_addr,
BUID_HI(pdn->phb->buid),
BUID_LO(pdn->phb->buid), 1);
if (rc)
printk(KERN_WARNING
"EEH: Unable to reset the failed slot,"
" #RST=%d dn=%s\n",
rc, pdn->node->full_name);
}
}
int pcibios_set_pcie_reset_state(struct pci_dev *dev, enum pcie_reset_state state)
{
struct device_node *dn = pci_device_to_OF_node(dev);
struct pci_dn *pdn = PCI_DN(dn);
switch (state) {
case pcie_deassert_reset:
rtas_pci_slot_reset(pdn, 0);
break;
case pcie_hot_reset:
rtas_pci_slot_reset(pdn, 1);
break;
case pcie_warm_reset:
rtas_pci_slot_reset(pdn, 3);
break;
default:
return -EINVAL;
};
return 0;
}
static void __rtas_set_slot_reset(struct pci_dn *pdn)
{
unsigned int freset = 0;
eeh_set_pe_freset(pdn->node, &freset);
if (freset)
rtas_pci_slot_reset(pdn, 3);
else
rtas_pci_slot_reset(pdn, 1);
#define PCI_BUS_RST_HOLD_TIME_MSEC 250
msleep (PCI_BUS_RST_HOLD_TIME_MSEC);
eeh_clear_slot (pdn->node, EEH_MODE_ISOLATED);
rtas_pci_slot_reset (pdn, 0);
#define PCI_BUS_SETTLE_TIME_MSEC 1800
msleep (PCI_BUS_SETTLE_TIME_MSEC);
}
int rtas_set_slot_reset(struct pci_dn *pdn)
{
int i, rc;
for (i=0; i<3; i++) {
__rtas_set_slot_reset(pdn);
rc = eeh_wait_for_slot_status(pdn, PCI_BUS_RESET_WAIT_MSEC);
if (rc == 0)
return 0;
if (rc < 0) {
printk(KERN_ERR "EEH: unrecoverable slot failure %s\n",
pdn->node->full_name);
return -1;
}
printk(KERN_ERR "EEH: bus reset %d failed on slot %s, rc=%d\n",
i+1, pdn->node->full_name, rc);
}
return -1;
}
static inline void __restore_bars (struct pci_dn *pdn)
{
int i;
u32 cmd;
if (NULL==pdn->phb) return;
for (i=4; i<10; i++) {
rtas_write_config(pdn, i*4, 4, pdn->config_space[i]);
}
rtas_write_config(pdn, 12*4, 4, pdn->config_space[12]);
#define BYTE_SWAP(OFF) (8*((OFF)/4)+3-(OFF))
#define SAVED_BYTE(OFF) (((u8 *)(pdn->config_space))[BYTE_SWAP(OFF)])
rtas_write_config (pdn, PCI_CACHE_LINE_SIZE, 1,
SAVED_BYTE(PCI_CACHE_LINE_SIZE));
rtas_write_config (pdn, PCI_LATENCY_TIMER, 1,
SAVED_BYTE(PCI_LATENCY_TIMER));
rtas_write_config(pdn, 15*4, 4, pdn->config_space[15]);
rtas_read_config(pdn, PCI_COMMAND, 4, &cmd);
if (pdn->config_space[1] & PCI_COMMAND_PARITY)
cmd |= PCI_COMMAND_PARITY;
else
cmd &= ~PCI_COMMAND_PARITY;
if (pdn->config_space[1] & PCI_COMMAND_SERR)
cmd |= PCI_COMMAND_SERR;
else
cmd &= ~PCI_COMMAND_SERR;
rtas_write_config(pdn, PCI_COMMAND, 4, cmd);
}
void eeh_restore_bars(struct pci_dn *pdn)
{
struct device_node *dn;
if (!pdn)
return;
if ((pdn->eeh_mode & EEH_MODE_SUPPORTED) && !IS_BRIDGE(pdn->class_code))
__restore_bars (pdn);
for_each_child_of_node(pdn->node, dn)
eeh_restore_bars (PCI_DN(dn));
}
static void eeh_save_bars(struct pci_dn *pdn)
{
int i;
if (!pdn )
return;
for (i = 0; i < 16; i++)
rtas_read_config(pdn, i * 4, 4, &pdn->config_space[i]);
}
void
rtas_configure_bridge(struct pci_dn *pdn)
{
int config_addr;
int rc;
int token;
config_addr = pdn->eeh_config_addr;
if (pdn->eeh_pe_config_addr)
config_addr = pdn->eeh_pe_config_addr;
if (ibm_configure_pe != RTAS_UNKNOWN_SERVICE)
token = ibm_configure_pe;
else
token = ibm_configure_bridge;
rc = rtas_call(token, 3, 1, NULL,
config_addr,
BUID_HI(pdn->phb->buid),
BUID_LO(pdn->phb->buid));
if (rc) {
printk (KERN_WARNING "EEH: Unable to configure device bridge (%d) for %s\n",
rc, pdn->node->full_name);
}
}
static int get_pe_addr (int config_addr,
struct eeh_early_enable_info *info)
{
unsigned int rets[3];
int ret;
if (ibm_get_config_addr_info2 != RTAS_UNKNOWN_SERVICE) {
ret = rtas_call (ibm_get_config_addr_info2, 4, 2, rets,
config_addr, info->buid_hi, info->buid_lo, 1);
if (ret || (rets[0]==0))
return 0;
ret = rtas_call (ibm_get_config_addr_info2, 4, 2, rets,
config_addr, info->buid_hi, info->buid_lo, 0);
if (ret)
return 0;
return rets[0];
}
if (ibm_get_config_addr_info != RTAS_UNKNOWN_SERVICE) {
ret = rtas_call (ibm_get_config_addr_info, 4, 2, rets,
config_addr, info->buid_hi, info->buid_lo, 0);
if (ret)
return 0;
return rets[0];
}
return 0;
}
static void *early_enable_eeh(struct device_node *dn, void *data)
{
unsigned int rets[3];
struct eeh_early_enable_info *info = data;
int ret;
const u32 *class_code = of_get_property(dn, "class-code", NULL);
const u32 *vendor_id = of_get_property(dn, "vendor-id", NULL);
const u32 *device_id = of_get_property(dn, "device-id", NULL);
const u32 *regs;
int enable;
struct pci_dn *pdn = PCI_DN(dn);
pdn->class_code = 0;
pdn->eeh_mode = 0;
pdn->eeh_check_count = 0;
pdn->eeh_freeze_count = 0;
pdn->eeh_false_positives = 0;
if (!of_device_is_available(dn))
return NULL;
if (!class_code || !vendor_id || !device_id)
return NULL;
if (dn->type && !strcmp(dn->type, "isa")) {
pdn->eeh_mode |= EEH_MODE_NOCHECK;
return NULL;
}
pdn->class_code = *class_code;
regs = of_get_property(dn, "reg", NULL);
if (regs) {
ret = rtas_call(ibm_set_eeh_option, 4, 1, NULL,
regs[0], info->buid_hi, info->buid_lo,
EEH_ENABLE);
enable = 0;
if (ret == 0) {
pdn->eeh_config_addr = regs[0];
pdn->eeh_pe_config_addr = get_pe_addr(pdn->eeh_config_addr, info);
ret = read_slot_reset_state(pdn, rets);
if ((ret == 0) && (rets[1] == 1))
enable = 1;
}
if (enable) {
eeh_subsystem_enabled = 1;
pdn->eeh_mode |= EEH_MODE_SUPPORTED;
pr_debug("EEH: %s: eeh enabled, config=%x pe_config=%x\n",
dn->full_name, pdn->eeh_config_addr,
pdn->eeh_pe_config_addr);
} else {
if (dn->parent && PCI_DN(dn->parent)
&& (PCI_DN(dn->parent)->eeh_mode & EEH_MODE_SUPPORTED)) {
pdn->eeh_mode |= EEH_MODE_SUPPORTED;
pdn->eeh_config_addr = PCI_DN(dn->parent)->eeh_config_addr;
return NULL;
}
}
} else {
printk(KERN_WARNING "EEH: %s: unable to get reg property.\n",
dn->full_name);
}
eeh_save_bars(pdn);
return NULL;
}
void __init eeh_init(void)
{
struct device_node *phb, *np;
struct eeh_early_enable_info info;
raw_spin_lock_init(&confirm_error_lock);
spin_lock_init(&slot_errbuf_lock);
np = of_find_node_by_path("/rtas");
if (np == NULL)
return;
ibm_set_eeh_option = rtas_token("ibm,set-eeh-option");
ibm_set_slot_reset = rtas_token("ibm,set-slot-reset");
ibm_read_slot_reset_state2 = rtas_token("ibm,read-slot-reset-state2");
ibm_read_slot_reset_state = rtas_token("ibm,read-slot-reset-state");
ibm_slot_error_detail = rtas_token("ibm,slot-error-detail");
ibm_get_config_addr_info = rtas_token("ibm,get-config-addr-info");
ibm_get_config_addr_info2 = rtas_token("ibm,get-config-addr-info2");
ibm_configure_bridge = rtas_token ("ibm,configure-bridge");
ibm_configure_pe = rtas_token("ibm,configure-pe");
if (ibm_set_eeh_option == RTAS_UNKNOWN_SERVICE)
return;
eeh_error_buf_size = rtas_token("rtas-error-log-max");
if (eeh_error_buf_size == RTAS_UNKNOWN_SERVICE) {
eeh_error_buf_size = 1024;
}
if (eeh_error_buf_size > RTAS_ERROR_LOG_MAX) {
printk(KERN_WARNING "EEH: rtas-error-log-max is bigger than allocated "
"buffer ! (%d vs %d)", eeh_error_buf_size, RTAS_ERROR_LOG_MAX);
eeh_error_buf_size = RTAS_ERROR_LOG_MAX;
}
for (phb = of_find_node_by_name(NULL, "pci"); phb;
phb = of_find_node_by_name(phb, "pci")) {
unsigned long buid;
buid = get_phb_buid(phb);
if (buid == 0 || PCI_DN(phb) == NULL)
continue;
info.buid_lo = BUID_LO(buid);
info.buid_hi = BUID_HI(buid);
traverse_pci_devices(phb, early_enable_eeh, &info);
}
if (eeh_subsystem_enabled)
printk(KERN_INFO "EEH: PCI Enhanced I/O Error Handling Enabled\n");
else
printk(KERN_WARNING "EEH: No capable adapters found\n");
}
static void eeh_add_device_early(struct device_node *dn)
{
struct pci_controller *phb;
struct eeh_early_enable_info info;
if (!dn || !PCI_DN(dn))
return;
phb = PCI_DN(dn)->phb;
if (NULL == phb || 0 == phb->buid)
return;
info.buid_hi = BUID_HI(phb->buid);
info.buid_lo = BUID_LO(phb->buid);
early_enable_eeh(dn, &info);
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
struct pci_dn *pdn;
if (!dev || !eeh_subsystem_enabled)
return;
pr_debug("EEH: Adding device %s\n", pci_name(dev));
dn = pci_device_to_OF_node(dev);
pdn = PCI_DN(dn);
if (pdn->pcidev == dev) {
pr_debug("EEH: Already referenced !\n");
return;
}
WARN_ON(pdn->pcidev);
pci_dev_get (dev);
pdn->pcidev = dev;
pci_addr_cache_insert_device(dev);
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
static void eeh_remove_device(struct pci_dev *dev)
{
struct device_node *dn;
if (!dev || !eeh_subsystem_enabled)
return;
pr_debug("EEH: Removing device %s\n", pci_name(dev));
dn = pci_device_to_OF_node(dev);
if (PCI_DN(dn)->pcidev == NULL) {
pr_debug("EEH: Not referenced !\n");
return;
}
PCI_DN(dn)->pcidev = NULL;
pci_dev_put (dev);
pci_addr_cache_remove_device(dev);
eeh_sysfs_remove_device(dev);
}
void eeh_remove_bus_device(struct pci_dev *dev)
{
struct pci_bus *bus = dev->subordinate;
struct pci_dev *child, *tmp;
eeh_remove_device(dev);
if (bus && dev->hdr_type == PCI_HEADER_TYPE_BRIDGE) {
list_for_each_entry_safe(child, tmp, &bus->devices, bus_list)
eeh_remove_bus_device(child);
}
}
static int proc_eeh_show(struct seq_file *m, void *v)
{
if (0 == eeh_subsystem_enabled) {
seq_printf(m, "EEH Subsystem is globally disabled\n");
seq_printf(m, "eeh_total_mmio_ffs=%ld\n", total_mmio_ffs);
} else {
seq_printf(m, "EEH Subsystem is enabled\n");
seq_printf(m,
"no device=%ld\n"
"no device node=%ld\n"
"no config address=%ld\n"
"check not wanted=%ld\n"
"eeh_total_mmio_ffs=%ld\n"
"eeh_false_positives=%ld\n"
"eeh_slot_resets=%ld\n",
no_device, no_dn, no_cfg_addr,
ignored_check, total_mmio_ffs,
false_positives,
slot_resets);
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
