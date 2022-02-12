static int ioda_eeh_event(struct notifier_block *nb,
unsigned long events, void *change)
{
uint64_t changed_evts = (uint64_t)change;
if ((changed_evts & OPAL_EVENT_PCI_ERROR) &&
(events & OPAL_EVENT_PCI_ERROR) &&
eeh_enabled())
eeh_send_failure_event(NULL);
return 0;
}
static int ioda_eeh_dbgfs_set(void *data, int offset, u64 val)
{
struct pci_controller *hose = data;
struct pnv_phb *phb = hose->private_data;
out_be64(phb->regs + offset, val);
return 0;
}
static int ioda_eeh_dbgfs_get(void *data, int offset, u64 *val)
{
struct pci_controller *hose = data;
struct pnv_phb *phb = hose->private_data;
*val = in_be64(phb->regs + offset);
return 0;
}
static int ioda_eeh_outb_dbgfs_set(void *data, u64 val)
{
return ioda_eeh_dbgfs_set(data, 0xD10, val);
}
static int ioda_eeh_outb_dbgfs_get(void *data, u64 *val)
{
return ioda_eeh_dbgfs_get(data, 0xD10, val);
}
static int ioda_eeh_inbA_dbgfs_set(void *data, u64 val)
{
return ioda_eeh_dbgfs_set(data, 0xD90, val);
}
static int ioda_eeh_inbA_dbgfs_get(void *data, u64 *val)
{
return ioda_eeh_dbgfs_get(data, 0xD90, val);
}
static int ioda_eeh_inbB_dbgfs_set(void *data, u64 val)
{
return ioda_eeh_dbgfs_set(data, 0xE10, val);
}
static int ioda_eeh_inbB_dbgfs_get(void *data, u64 *val)
{
return ioda_eeh_dbgfs_get(data, 0xE10, val);
}
static int ioda_eeh_post_init(struct pci_controller *hose)
{
struct pnv_phb *phb = hose->private_data;
int ret;
if (!ioda_eeh_nb_init) {
ret = opal_notifier_register(&ioda_eeh_nb);
if (ret) {
pr_err("%s: Can't register OPAL event notifier (%d)\n",
__func__, ret);
return ret;
}
ioda_eeh_nb_init = 1;
}
#ifdef CONFIG_DEBUG_FS
if (phb->dbgfs) {
debugfs_create_file("err_injct_outbound", 0600,
phb->dbgfs, hose,
&ioda_eeh_outb_dbgfs_ops);
debugfs_create_file("err_injct_inboundA", 0600,
phb->dbgfs, hose,
&ioda_eeh_inbA_dbgfs_ops);
debugfs_create_file("err_injct_inboundB", 0600,
phb->dbgfs, hose,
&ioda_eeh_inbB_dbgfs_ops);
}
#endif
phb->eeh_state |= PNV_EEH_STATE_ENABLED;
return 0;
}
static int ioda_eeh_set_option(struct eeh_pe *pe, int option)
{
s64 ret;
u32 pe_no;
struct pci_controller *hose = pe->phb;
struct pnv_phb *phb = hose->private_data;
if (pe->addr < 0 || pe->addr >= phb->ioda.total_pe) {
pr_err("%s: PE address %x out of range [0, %x] "
"on PHB#%x\n",
__func__, pe->addr, phb->ioda.total_pe,
hose->global_number);
return -EINVAL;
}
pe_no = pe->addr;
switch (option) {
case EEH_OPT_DISABLE:
ret = -EEXIST;
break;
case EEH_OPT_ENABLE:
ret = 0;
break;
case EEH_OPT_THAW_MMIO:
ret = opal_pci_eeh_freeze_clear(phb->opal_id, pe_no,
OPAL_EEH_ACTION_CLEAR_FREEZE_MMIO);
if (ret) {
pr_warning("%s: Failed to enable MMIO for "
"PHB#%x-PE#%x, err=%lld\n",
__func__, hose->global_number, pe_no, ret);
return -EIO;
}
break;
case EEH_OPT_THAW_DMA:
ret = opal_pci_eeh_freeze_clear(phb->opal_id, pe_no,
OPAL_EEH_ACTION_CLEAR_FREEZE_DMA);
if (ret) {
pr_warning("%s: Failed to enable DMA for "
"PHB#%x-PE#%x, err=%lld\n",
__func__, hose->global_number, pe_no, ret);
return -EIO;
}
break;
default:
pr_warning("%s: Invalid option %d\n", __func__, option);
return -EINVAL;
}
return ret;
}
static void ioda_eeh_phb_diag(struct pci_controller *hose)
{
struct pnv_phb *phb = hose->private_data;
long rc;
rc = opal_pci_get_phb_diag_data2(phb->opal_id, phb->diag.blob,
PNV_PCI_DIAG_BUF_SIZE);
if (rc != OPAL_SUCCESS) {
pr_warning("%s: Failed to get diag-data for PHB#%x (%ld)\n",
__func__, hose->global_number, rc);
return;
}
pnv_pci_dump_phb_diag_data(hose, phb->diag.blob);
}
static int ioda_eeh_get_state(struct eeh_pe *pe)
{
s64 ret = 0;
u8 fstate;
u16 pcierr;
u32 pe_no;
int result;
struct pci_controller *hose = pe->phb;
struct pnv_phb *phb = hose->private_data;
if (pe->addr < 0 || pe->addr >= phb->ioda.total_pe) {
pr_err("%s: PE address %x out of range [0, %x] "
"on PHB#%x\n",
__func__, pe->addr, phb->ioda.total_pe,
hose->global_number);
return EEH_STATE_NOT_SUPPORT;
}
pe_no = pe->addr;
ret = opal_pci_eeh_freeze_status(phb->opal_id, pe_no,
&fstate, &pcierr, NULL);
if (ret) {
pr_err("%s: Failed to get EEH status on "
"PHB#%x-PE#%x\n, err=%lld\n",
__func__, hose->global_number, pe_no, ret);
return EEH_STATE_NOT_SUPPORT;
}
if (pe->type & EEH_PE_PHB) {
result = 0;
result &= ~EEH_STATE_RESET_ACTIVE;
if (pcierr != OPAL_EEH_PHB_ERROR) {
result |= EEH_STATE_MMIO_ACTIVE;
result |= EEH_STATE_DMA_ACTIVE;
result |= EEH_STATE_MMIO_ENABLED;
result |= EEH_STATE_DMA_ENABLED;
} else if (!(pe->state & EEH_PE_ISOLATED)) {
eeh_pe_state_mark(pe, EEH_PE_ISOLATED);
ioda_eeh_phb_diag(hose);
}
return result;
}
result = 0;
switch (fstate) {
case OPAL_EEH_STOPPED_NOT_FROZEN:
result &= ~EEH_STATE_RESET_ACTIVE;
result |= EEH_STATE_MMIO_ACTIVE;
result |= EEH_STATE_DMA_ACTIVE;
result |= EEH_STATE_MMIO_ENABLED;
result |= EEH_STATE_DMA_ENABLED;
break;
case OPAL_EEH_STOPPED_MMIO_FREEZE:
result &= ~EEH_STATE_RESET_ACTIVE;
result |= EEH_STATE_DMA_ACTIVE;
result |= EEH_STATE_DMA_ENABLED;
break;
case OPAL_EEH_STOPPED_DMA_FREEZE:
result &= ~EEH_STATE_RESET_ACTIVE;
result |= EEH_STATE_MMIO_ACTIVE;
result |= EEH_STATE_MMIO_ENABLED;
break;
case OPAL_EEH_STOPPED_MMIO_DMA_FREEZE:
result &= ~EEH_STATE_RESET_ACTIVE;
break;
case OPAL_EEH_STOPPED_RESET:
result |= EEH_STATE_RESET_ACTIVE;
break;
case OPAL_EEH_STOPPED_TEMP_UNAVAIL:
result |= EEH_STATE_UNAVAILABLE;
break;
case OPAL_EEH_STOPPED_PERM_UNAVAIL:
result |= EEH_STATE_NOT_SUPPORT;
break;
default:
pr_warning("%s: Unexpected EEH status 0x%x "
"on PHB#%x-PE#%x\n",
__func__, fstate, hose->global_number, pe_no);
}
if (result != EEH_STATE_NOT_SUPPORT &&
(result & (EEH_STATE_MMIO_ACTIVE | EEH_STATE_DMA_ACTIVE)) !=
(EEH_STATE_MMIO_ACTIVE | EEH_STATE_DMA_ACTIVE) &&
!(pe->state & EEH_PE_ISOLATED)) {
eeh_pe_state_mark(pe, EEH_PE_ISOLATED);
ioda_eeh_phb_diag(hose);
}
return result;
}
static int ioda_eeh_pe_clear(struct eeh_pe *pe)
{
struct pci_controller *hose;
struct pnv_phb *phb;
u32 pe_no;
u8 fstate;
u16 pcierr;
s64 ret;
pe_no = pe->addr;
hose = pe->phb;
phb = pe->phb->private_data;
ret = opal_pci_eeh_freeze_clear(phb->opal_id,
pe_no, OPAL_EEH_ACTION_CLEAR_FREEZE_ALL);
if (ret) {
pr_err("%s: Failed to clear EEH error for "
"PHB#%x-PE#%x, err=%lld\n",
__func__, hose->global_number, pe_no, ret);
return -EIO;
}
ret = opal_pci_eeh_freeze_status(phb->opal_id, pe_no,
&fstate, &pcierr, NULL);
if (ret) {
pr_err("%s: Failed to get EEH status on "
"PHB#%x-PE#%x\n, err=%lld\n",
__func__, hose->global_number, pe_no, ret);
return -EIO;
}
if (fstate != OPAL_EEH_STOPPED_NOT_FROZEN) {
pr_err("%s: Frozen state not cleared on "
"PHB#%x-PE#%x, sts=%x\n",
__func__, hose->global_number, pe_no, fstate);
return -EIO;
}
return 0;
}
static s64 ioda_eeh_phb_poll(struct pnv_phb *phb)
{
s64 rc = OPAL_HARDWARE;
while (1) {
rc = opal_pci_poll(phb->opal_id);
if (rc <= 0)
break;
msleep(rc);
}
return rc;
}
static int ioda_eeh_phb_reset(struct pci_controller *hose, int option)
{
struct pnv_phb *phb = hose->private_data;
s64 rc = OPAL_HARDWARE;
pr_debug("%s: Reset PHB#%x, option=%d\n",
__func__, hose->global_number, option);
if (option == EEH_RESET_FUNDAMENTAL ||
option == EEH_RESET_HOT)
rc = opal_pci_reset(phb->opal_id,
OPAL_PHB_COMPLETE,
OPAL_ASSERT_RESET);
else if (option == EEH_RESET_DEACTIVATE)
rc = opal_pci_reset(phb->opal_id,
OPAL_PHB_COMPLETE,
OPAL_DEASSERT_RESET);
if (rc < 0)
goto out;
rc = ioda_eeh_phb_poll(phb);
out:
if (rc != OPAL_SUCCESS)
return -EIO;
return 0;
}
static int ioda_eeh_root_reset(struct pci_controller *hose, int option)
{
struct pnv_phb *phb = hose->private_data;
s64 rc = OPAL_SUCCESS;
pr_debug("%s: Reset PHB#%x, option=%d\n",
__func__, hose->global_number, option);
if (option == EEH_RESET_FUNDAMENTAL)
rc = opal_pci_reset(phb->opal_id,
OPAL_PCI_FUNDAMENTAL_RESET,
OPAL_ASSERT_RESET);
else if (option == EEH_RESET_HOT)
rc = opal_pci_reset(phb->opal_id,
OPAL_PCI_HOT_RESET,
OPAL_ASSERT_RESET);
else if (option == EEH_RESET_DEACTIVATE)
rc = opal_pci_reset(phb->opal_id,
OPAL_PCI_HOT_RESET,
OPAL_DEASSERT_RESET);
if (rc < 0)
goto out;
rc = ioda_eeh_phb_poll(phb);
out:
if (rc != OPAL_SUCCESS)
return -EIO;
return 0;
}
static int ioda_eeh_bridge_reset(struct pci_controller *hose,
struct pci_dev *dev, int option)
{
u16 ctrl;
pr_debug("%s: Reset device %04x:%02x:%02x.%01x with option %d\n",
__func__, hose->global_number, dev->bus->number,
PCI_SLOT(dev->devfn), PCI_FUNC(dev->devfn), option);
switch (option) {
case EEH_RESET_FUNDAMENTAL:
case EEH_RESET_HOT:
pci_read_config_word(dev, PCI_BRIDGE_CONTROL, &ctrl);
ctrl |= PCI_BRIDGE_CTL_BUS_RESET;
pci_write_config_word(dev, PCI_BRIDGE_CONTROL, ctrl);
break;
case EEH_RESET_DEACTIVATE:
pci_read_config_word(dev, PCI_BRIDGE_CONTROL, &ctrl);
ctrl &= ~PCI_BRIDGE_CTL_BUS_RESET;
pci_write_config_word(dev, PCI_BRIDGE_CONTROL, ctrl);
break;
}
return 0;
}
static int ioda_eeh_reset(struct eeh_pe *pe, int option)
{
struct pci_controller *hose = pe->phb;
struct pci_bus *bus;
int ret;
if (!(pe->type & EEH_PE_PHB) &&
(option == EEH_RESET_HOT ||
option == EEH_RESET_FUNDAMENTAL)) {
ret = ioda_eeh_pe_clear(pe);
if (ret)
return -EIO;
}
if (pe->type & EEH_PE_PHB) {
ret = ioda_eeh_phb_reset(hose, option);
} else {
bus = eeh_pe_bus_get(pe);
if (pci_is_root_bus(bus))
ret = ioda_eeh_root_reset(hose, option);
else
ret = ioda_eeh_bridge_reset(hose, bus->self, option);
}
return ret;
}
static int ioda_eeh_configure_bridge(struct eeh_pe *pe)
{
return 0;
}
static void ioda_eeh_hub_diag_common(struct OpalIoP7IOCErrorData *data)
{
pr_info(" GEM XFIR: %016llx\n", data->gemXfir);
pr_info(" GEM RFIR: %016llx\n", data->gemRfir);
pr_info(" GEM RIRQFIR: %016llx\n", data->gemRirqfir);
pr_info(" GEM Mask: %016llx\n", data->gemMask);
pr_info(" GEM RWOF: %016llx\n", data->gemRwof);
pr_info(" LEM FIR: %016llx\n", data->lemFir);
pr_info(" LEM Error Mask: %016llx\n", data->lemErrMask);
pr_info(" LEM Action 0: %016llx\n", data->lemAction0);
pr_info(" LEM Action 1: %016llx\n", data->lemAction1);
pr_info(" LEM WOF: %016llx\n", data->lemWof);
}
static void ioda_eeh_hub_diag(struct pci_controller *hose)
{
struct pnv_phb *phb = hose->private_data;
struct OpalIoP7IOCErrorData *data = &phb->diag.hub_diag;
long rc;
rc = opal_pci_get_hub_diag_data(phb->hub_id, data, sizeof(*data));
if (rc != OPAL_SUCCESS) {
pr_warning("%s: Failed to get HUB#%llx diag-data (%ld)\n",
__func__, phb->hub_id, rc);
return;
}
switch (data->type) {
case OPAL_P7IOC_DIAG_TYPE_RGC:
pr_info("P7IOC diag-data for RGC\n\n");
ioda_eeh_hub_diag_common(data);
pr_info(" RGC Status: %016llx\n", data->rgc.rgcStatus);
pr_info(" RGC LDCP: %016llx\n", data->rgc.rgcLdcp);
break;
case OPAL_P7IOC_DIAG_TYPE_BI:
pr_info("P7IOC diag-data for BI %s\n\n",
data->bi.biDownbound ? "Downbound" : "Upbound");
ioda_eeh_hub_diag_common(data);
pr_info(" BI LDCP 0: %016llx\n", data->bi.biLdcp0);
pr_info(" BI LDCP 1: %016llx\n", data->bi.biLdcp1);
pr_info(" BI LDCP 2: %016llx\n", data->bi.biLdcp2);
pr_info(" BI Fence Status: %016llx\n", data->bi.biFenceStatus);
break;
case OPAL_P7IOC_DIAG_TYPE_CI:
pr_info("P7IOC diag-data for CI Port %d\\nn",
data->ci.ciPort);
ioda_eeh_hub_diag_common(data);
pr_info(" CI Port Status: %016llx\n", data->ci.ciPortStatus);
pr_info(" CI Port LDCP: %016llx\n", data->ci.ciPortLdcp);
break;
case OPAL_P7IOC_DIAG_TYPE_MISC:
pr_info("P7IOC diag-data for MISC\n\n");
ioda_eeh_hub_diag_common(data);
break;
case OPAL_P7IOC_DIAG_TYPE_I2C:
pr_info("P7IOC diag-data for I2C\n\n");
ioda_eeh_hub_diag_common(data);
break;
default:
pr_warning("%s: Invalid type of HUB#%llx diag-data (%d)\n",
__func__, phb->hub_id, data->type);
}
}
static int ioda_eeh_get_phb_pe(struct pci_controller *hose,
struct eeh_pe **pe)
{
struct eeh_pe *phb_pe;
phb_pe = eeh_phb_pe_get(hose);
if (!phb_pe) {
pr_warning("%s Can't find PE for PHB#%d\n",
__func__, hose->global_number);
return -EEXIST;
}
*pe = phb_pe;
return 0;
}
static int ioda_eeh_get_pe(struct pci_controller *hose,
u16 pe_no, struct eeh_pe **pe)
{
struct eeh_pe *phb_pe, *dev_pe;
struct eeh_dev dev;
if (ioda_eeh_get_phb_pe(hose, &phb_pe))
return -EEXIST;
memset(&dev, 0, sizeof(struct eeh_dev));
dev.phb = hose;
dev.pe_config_addr = pe_no;
dev_pe = eeh_pe_get(&dev);
if (!dev_pe) return -EEXIST;
*pe = dev_pe;
return 0;
}
static int ioda_eeh_next_error(struct eeh_pe **pe)
{
struct pci_controller *hose;
struct pnv_phb *phb;
u64 frozen_pe_no;
u16 err_type, severity;
long rc;
int ret = EEH_NEXT_ERR_NONE;
eeh_remove_event(NULL);
opal_notifier_update_evt(OPAL_EVENT_PCI_ERROR, 0x0ul);
list_for_each_entry(hose, &hose_list, list_node) {
phb = hose->private_data;
if (phb->eeh_state & PNV_EEH_STATE_REMOVED)
continue;
rc = opal_pci_next_error(phb->opal_id,
&frozen_pe_no, &err_type, &severity);
if (rc != OPAL_SUCCESS) {
pr_devel("%s: Invalid return value on "
"PHB#%x (0x%lx) from opal_pci_next_error",
__func__, hose->global_number, rc);
continue;
}
if (err_type == OPAL_EEH_NO_ERROR ||
severity == OPAL_EEH_SEV_NO_ERROR) {
pr_devel("%s: No error found on PHB#%x\n",
__func__, hose->global_number);
continue;
}
pr_devel("%s: Error (%d, %d, %llu) on PHB#%x\n",
__func__, err_type, severity,
frozen_pe_no, hose->global_number);
switch (err_type) {
case OPAL_EEH_IOC_ERROR:
if (severity == OPAL_EEH_SEV_IOC_DEAD) {
list_for_each_entry(hose, &hose_list,
list_node) {
phb = hose->private_data;
phb->eeh_state |= PNV_EEH_STATE_REMOVED;
}
pr_err("EEH: dead IOC detected\n");
ret = EEH_NEXT_ERR_DEAD_IOC;
} else if (severity == OPAL_EEH_SEV_INF) {
pr_info("EEH: IOC informative error "
"detected\n");
ioda_eeh_hub_diag(hose);
ret = EEH_NEXT_ERR_NONE;
}
break;
case OPAL_EEH_PHB_ERROR:
if (severity == OPAL_EEH_SEV_PHB_DEAD) {
if (ioda_eeh_get_phb_pe(hose, pe))
break;
pr_err("EEH: dead PHB#%x detected\n",
hose->global_number);
phb->eeh_state |= PNV_EEH_STATE_REMOVED;
ret = EEH_NEXT_ERR_DEAD_PHB;
} else if (severity == OPAL_EEH_SEV_PHB_FENCED) {
if (ioda_eeh_get_phb_pe(hose, pe))
break;
pr_err("EEH: fenced PHB#%x detected\n",
hose->global_number);
ret = EEH_NEXT_ERR_FENCED_PHB;
} else if (severity == OPAL_EEH_SEV_INF) {
pr_info("EEH: PHB#%x informative error "
"detected\n",
hose->global_number);
ioda_eeh_phb_diag(hose);
ret = EEH_NEXT_ERR_NONE;
}
break;
case OPAL_EEH_PE_ERROR:
if (ioda_eeh_get_pe(hose, frozen_pe_no, pe)) {
if (!ioda_eeh_get_phb_pe(hose, pe)) {
pr_err("EEH: Escalated fenced PHB#%x "
"detected for PE#%llx\n",
hose->global_number,
frozen_pe_no);
ret = EEH_NEXT_ERR_FENCED_PHB;
} else {
ret = EEH_NEXT_ERR_NONE;
}
} else {
pr_err("EEH: Frozen PE#%x on PHB#%x detected\n",
(*pe)->addr, (*pe)->phb->global_number);
ret = EEH_NEXT_ERR_FROZEN_PE;
}
break;
default:
pr_warn("%s: Unexpected error type %d\n",
__func__, err_type);
}
if ((ret == EEH_NEXT_ERR_FROZEN_PE ||
ret == EEH_NEXT_ERR_FENCED_PHB) &&
!((*pe)->state & EEH_PE_ISOLATED)) {
eeh_pe_state_mark(*pe, EEH_PE_ISOLATED);
ioda_eeh_phb_diag(hose);
}
if (ret > EEH_NEXT_ERR_INF)
break;
}
return ret;
}
