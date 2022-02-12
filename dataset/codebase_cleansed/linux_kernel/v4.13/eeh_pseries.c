static int pseries_eeh_init(void)
{
ibm_set_eeh_option = rtas_token("ibm,set-eeh-option");
ibm_set_slot_reset = rtas_token("ibm,set-slot-reset");
ibm_read_slot_reset_state2 = rtas_token("ibm,read-slot-reset-state2");
ibm_read_slot_reset_state = rtas_token("ibm,read-slot-reset-state");
ibm_slot_error_detail = rtas_token("ibm,slot-error-detail");
ibm_get_config_addr_info2 = rtas_token("ibm,get-config-addr-info2");
ibm_get_config_addr_info = rtas_token("ibm,get-config-addr-info");
ibm_configure_pe = rtas_token("ibm,configure-pe");
if (ibm_configure_pe == RTAS_UNKNOWN_SERVICE)
ibm_configure_pe = rtas_token("ibm,configure-bridge");
if (ibm_set_eeh_option == RTAS_UNKNOWN_SERVICE ||
ibm_set_slot_reset == RTAS_UNKNOWN_SERVICE ||
(ibm_read_slot_reset_state2 == RTAS_UNKNOWN_SERVICE &&
ibm_read_slot_reset_state == RTAS_UNKNOWN_SERVICE) ||
ibm_slot_error_detail == RTAS_UNKNOWN_SERVICE ||
ibm_configure_pe == RTAS_UNKNOWN_SERVICE) {
pr_info("EEH functionality not supported\n");
return -EINVAL;
}
spin_lock_init(&slot_errbuf_lock);
eeh_error_buf_size = rtas_token("rtas-error-log-max");
if (eeh_error_buf_size == RTAS_UNKNOWN_SERVICE) {
pr_info("%s: unknown EEH error log size\n",
__func__);
eeh_error_buf_size = 1024;
} else if (eeh_error_buf_size > RTAS_ERROR_LOG_MAX) {
pr_info("%s: EEH error log size %d exceeds the maximal %d\n",
__func__, eeh_error_buf_size, RTAS_ERROR_LOG_MAX);
eeh_error_buf_size = RTAS_ERROR_LOG_MAX;
}
eeh_add_flag(EEH_PROBE_MODE_DEVTREE | EEH_ENABLE_IO_FOR_LOG);
return 0;
}
static int pseries_eeh_cap_start(struct pci_dn *pdn)
{
u32 status;
if (!pdn)
return 0;
rtas_read_config(pdn, PCI_STATUS, 2, &status);
if (!(status & PCI_STATUS_CAP_LIST))
return 0;
return PCI_CAPABILITY_LIST;
}
static int pseries_eeh_find_cap(struct pci_dn *pdn, int cap)
{
int pos = pseries_eeh_cap_start(pdn);
int cnt = 48;
u32 id;
if (!pos)
return 0;
while (cnt--) {
rtas_read_config(pdn, pos, 1, &pos);
if (pos < 0x40)
break;
pos &= ~3;
rtas_read_config(pdn, pos + PCI_CAP_LIST_ID, 1, &id);
if (id == 0xff)
break;
if (id == cap)
return pos;
pos += PCI_CAP_LIST_NEXT;
}
return 0;
}
static int pseries_eeh_find_ecap(struct pci_dn *pdn, int cap)
{
struct eeh_dev *edev = pdn_to_eeh_dev(pdn);
u32 header;
int pos = 256;
int ttl = (4096 - 256) / 8;
if (!edev || !edev->pcie_cap)
return 0;
if (rtas_read_config(pdn, pos, 4, &header) != PCIBIOS_SUCCESSFUL)
return 0;
else if (!header)
return 0;
while (ttl-- > 0) {
if (PCI_EXT_CAP_ID(header) == cap && pos)
return pos;
pos = PCI_EXT_CAP_NEXT(header);
if (pos < 256)
break;
if (rtas_read_config(pdn, pos, 4, &header) != PCIBIOS_SUCCESSFUL)
break;
}
return 0;
}
static void *pseries_eeh_probe(struct pci_dn *pdn, void *data)
{
struct eeh_dev *edev;
struct eeh_pe pe;
u32 pcie_flags;
int enable = 0;
int ret;
edev = pdn_to_eeh_dev(pdn);
if (!edev || edev->pe)
return NULL;
if (!pdn->vendor_id || !pdn->device_id || !pdn->class_code)
return NULL;
if ((pdn->class_code >> 8) == PCI_CLASS_BRIDGE_ISA)
return NULL;
edev->class_code = pdn->class_code;
edev->pcix_cap = pseries_eeh_find_cap(pdn, PCI_CAP_ID_PCIX);
edev->pcie_cap = pseries_eeh_find_cap(pdn, PCI_CAP_ID_EXP);
edev->aer_cap = pseries_eeh_find_ecap(pdn, PCI_EXT_CAP_ID_ERR);
edev->mode &= 0xFFFFFF00;
if ((edev->class_code >> 8) == PCI_CLASS_BRIDGE_PCI) {
edev->mode |= EEH_DEV_BRIDGE;
if (edev->pcie_cap) {
rtas_read_config(pdn, edev->pcie_cap + PCI_EXP_FLAGS,
2, &pcie_flags);
pcie_flags = (pcie_flags & PCI_EXP_FLAGS_TYPE) >> 4;
if (pcie_flags == PCI_EXP_TYPE_ROOT_PORT)
edev->mode |= EEH_DEV_ROOT_PORT;
else if (pcie_flags == PCI_EXP_TYPE_DOWNSTREAM)
edev->mode |= EEH_DEV_DS_PORT;
}
}
memset(&pe, 0, sizeof(struct eeh_pe));
pe.phb = edev->phb;
pe.config_addr = (pdn->busno << 16) | (pdn->devfn << 8);
ret = eeh_ops->set_option(&pe, EEH_OPT_ENABLE);
if (!ret) {
edev->config_addr = (pdn->busno << 16) | (pdn->devfn << 8);
edev->pe_config_addr = eeh_ops->get_pe_addr(&pe);
pe.addr = edev->pe_config_addr;
ret = eeh_ops->get_state(&pe, NULL);
if (ret > 0 && ret != EEH_STATE_NOT_SUPPORT)
enable = 1;
if (enable) {
eeh_add_flag(EEH_ENABLED);
eeh_add_to_parent_pe(edev);
pr_debug("%s: EEH enabled on %02x:%02x.%01x PHB#%x-PE#%x\n",
__func__, pdn->busno, PCI_SLOT(pdn->devfn),
PCI_FUNC(pdn->devfn), pe.phb->global_number,
pe.addr);
} else if (pdn->parent && pdn_to_eeh_dev(pdn->parent) &&
(pdn_to_eeh_dev(pdn->parent))->pe) {
edev->config_addr = pdn_to_eeh_dev(pdn->parent)->config_addr;
edev->pe_config_addr = pdn_to_eeh_dev(pdn->parent)->pe_config_addr;
eeh_add_to_parent_pe(edev);
}
}
eeh_save_bars(edev);
return NULL;
}
static int pseries_eeh_set_option(struct eeh_pe *pe, int option)
{
int ret = 0;
int config_addr;
switch (option) {
case EEH_OPT_DISABLE:
case EEH_OPT_ENABLE:
case EEH_OPT_THAW_MMIO:
case EEH_OPT_THAW_DMA:
config_addr = pe->config_addr;
if (pe->addr)
config_addr = pe->addr;
break;
case EEH_OPT_FREEZE_PE:
return 0;
default:
pr_err("%s: Invalid option %d\n",
__func__, option);
return -EINVAL;
}
ret = rtas_call(ibm_set_eeh_option, 4, 1, NULL,
config_addr, BUID_HI(pe->phb->buid),
BUID_LO(pe->phb->buid), option);
return ret;
}
static int pseries_eeh_get_pe_addr(struct eeh_pe *pe)
{
int ret = 0;
int rets[3];
if (ibm_get_config_addr_info2 != RTAS_UNKNOWN_SERVICE) {
ret = rtas_call(ibm_get_config_addr_info2, 4, 2, rets,
pe->config_addr, BUID_HI(pe->phb->buid),
BUID_LO(pe->phb->buid), 1);
if (ret || (rets[0] == 0))
return 0;
ret = rtas_call(ibm_get_config_addr_info2, 4, 2, rets,
pe->config_addr, BUID_HI(pe->phb->buid),
BUID_LO(pe->phb->buid), 0);
if (ret) {
pr_warn("%s: Failed to get address for PHB#%x-PE#%x\n",
__func__, pe->phb->global_number, pe->config_addr);
return 0;
}
return rets[0];
}
if (ibm_get_config_addr_info != RTAS_UNKNOWN_SERVICE) {
ret = rtas_call(ibm_get_config_addr_info, 4, 2, rets,
pe->config_addr, BUID_HI(pe->phb->buid),
BUID_LO(pe->phb->buid), 0);
if (ret) {
pr_warn("%s: Failed to get address for PHB#%x-PE#%x\n",
__func__, pe->phb->global_number, pe->config_addr);
return 0;
}
return rets[0];
}
return ret;
}
static int pseries_eeh_get_state(struct eeh_pe *pe, int *state)
{
int config_addr;
int ret;
int rets[4];
int result;
config_addr = pe->config_addr;
if (pe->addr)
config_addr = pe->addr;
if (ibm_read_slot_reset_state2 != RTAS_UNKNOWN_SERVICE) {
ret = rtas_call(ibm_read_slot_reset_state2, 3, 4, rets,
config_addr, BUID_HI(pe->phb->buid),
BUID_LO(pe->phb->buid));
} else if (ibm_read_slot_reset_state != RTAS_UNKNOWN_SERVICE) {
rets[2] = 0;
ret = rtas_call(ibm_read_slot_reset_state, 3, 3, rets,
config_addr, BUID_HI(pe->phb->buid),
BUID_LO(pe->phb->buid));
} else {
return EEH_STATE_NOT_SUPPORT;
}
if (ret)
return ret;
if (!rets[1])
return EEH_STATE_NOT_SUPPORT;
switch(rets[0]) {
case 0:
result = EEH_STATE_MMIO_ACTIVE |
EEH_STATE_DMA_ACTIVE;
break;
case 1:
result = EEH_STATE_RESET_ACTIVE |
EEH_STATE_MMIO_ACTIVE |
EEH_STATE_DMA_ACTIVE;
break;
case 2:
result = 0;
break;
case 4:
result = EEH_STATE_MMIO_ENABLED;
break;
case 5:
if (rets[2]) {
if (state) *state = rets[2];
result = EEH_STATE_UNAVAILABLE;
} else {
result = EEH_STATE_NOT_SUPPORT;
}
break;
default:
result = EEH_STATE_NOT_SUPPORT;
}
return result;
}
static int pseries_eeh_reset(struct eeh_pe *pe, int option)
{
int config_addr;
int ret;
config_addr = pe->config_addr;
if (pe->addr)
config_addr = pe->addr;
ret = rtas_call(ibm_set_slot_reset, 4, 1, NULL,
config_addr, BUID_HI(pe->phb->buid),
BUID_LO(pe->phb->buid), option);
if (option == EEH_RESET_FUNDAMENTAL &&
ret == -8) {
option = EEH_RESET_HOT;
ret = rtas_call(ibm_set_slot_reset, 4, 1, NULL,
config_addr, BUID_HI(pe->phb->buid),
BUID_LO(pe->phb->buid), option);
}
if (option == EEH_RESET_FUNDAMENTAL ||
option == EEH_RESET_HOT)
msleep(EEH_PE_RST_HOLD_TIME);
else
msleep(EEH_PE_RST_SETTLE_TIME);
return ret;
}
static int pseries_eeh_wait_state(struct eeh_pe *pe, int max_wait)
{
int ret;
int mwait;
#define EEH_STATE_MIN_WAIT_TIME (1000)
#define EEH_STATE_MAX_WAIT_TIME (300 * 1000)
while (1) {
ret = pseries_eeh_get_state(pe, &mwait);
if (ret != EEH_STATE_UNAVAILABLE)
return ret;
if (max_wait <= 0) {
pr_warn("%s: Timeout when getting PE's state (%d)\n",
__func__, max_wait);
return EEH_STATE_NOT_SUPPORT;
}
if (mwait <= 0) {
pr_warn("%s: Firmware returned bad wait value %d\n",
__func__, mwait);
mwait = EEH_STATE_MIN_WAIT_TIME;
} else if (mwait > EEH_STATE_MAX_WAIT_TIME) {
pr_warn("%s: Firmware returned too long wait value %d\n",
__func__, mwait);
mwait = EEH_STATE_MAX_WAIT_TIME;
}
max_wait -= mwait;
msleep(mwait);
}
return EEH_STATE_NOT_SUPPORT;
}
static int pseries_eeh_get_log(struct eeh_pe *pe, int severity, char *drv_log, unsigned long len)
{
int config_addr;
unsigned long flags;
int ret;
spin_lock_irqsave(&slot_errbuf_lock, flags);
memset(slot_errbuf, 0, eeh_error_buf_size);
config_addr = pe->config_addr;
if (pe->addr)
config_addr = pe->addr;
ret = rtas_call(ibm_slot_error_detail, 8, 1, NULL, config_addr,
BUID_HI(pe->phb->buid), BUID_LO(pe->phb->buid),
virt_to_phys(drv_log), len,
virt_to_phys(slot_errbuf), eeh_error_buf_size,
severity);
if (!ret)
log_error(slot_errbuf, ERR_TYPE_RTAS_LOG, 0);
spin_unlock_irqrestore(&slot_errbuf_lock, flags);
return ret;
}
static int pseries_eeh_configure_bridge(struct eeh_pe *pe)
{
int config_addr;
int ret;
int max_wait = 200;
config_addr = pe->config_addr;
if (pe->addr)
config_addr = pe->addr;
while (max_wait > 0) {
ret = rtas_call(ibm_configure_pe, 3, 1, NULL,
config_addr, BUID_HI(pe->phb->buid),
BUID_LO(pe->phb->buid));
if (!ret)
return ret;
if (ret > RTAS_EXTENDED_DELAY_MIN+2 &&
ret <= RTAS_EXTENDED_DELAY_MAX)
ret = RTAS_EXTENDED_DELAY_MIN+2;
max_wait -= rtas_busy_delay_time(ret);
if (max_wait < 0)
break;
rtas_busy_delay(ret);
}
pr_warn("%s: Unable to configure bridge PHB#%x-PE#%x (%d)\n",
__func__, pe->phb->global_number, pe->addr, ret);
return ret;
}
static int pseries_eeh_read_config(struct pci_dn *pdn, int where, int size, u32 *val)
{
return rtas_read_config(pdn, where, size, val);
}
static int pseries_eeh_write_config(struct pci_dn *pdn, int where, int size, u32 val)
{
return rtas_write_config(pdn, where, size, val);
}
static int __init eeh_pseries_init(void)
{
int ret;
ret = eeh_ops_register(&pseries_eeh_ops);
if (!ret)
pr_info("EEH: pSeries platform initialized\n");
else
pr_info("EEH: pSeries platform initialization failure (%d)\n",
ret);
return ret;
}
