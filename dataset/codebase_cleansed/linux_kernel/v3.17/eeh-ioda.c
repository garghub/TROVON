static int ioda_eeh_event(struct notifier_block *nb,
unsigned long events, void *change)
{
uint64_t changed_evts = (uint64_t)change;
if (!(changed_evts & OPAL_EVENT_PCI_ERROR) ||
!(events & OPAL_EVENT_PCI_ERROR))
return 0;
if (eeh_enabled())
eeh_send_failure_event(NULL);
else
opal_notifier_update_evt(OPAL_EVENT_PCI_ERROR, 0x0ul);
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
if (!phb->has_dbgfs && phb->dbgfs) {
phb->has_dbgfs = 1;
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
if (eeh_enabled())
phb->flags |= PNV_PHB_FLAG_EEH;
else
phb->flags &= ~PNV_PHB_FLAG_EEH;
return 0;
}
static int ioda_eeh_set_option(struct eeh_pe *pe, int option)
{
struct pci_controller *hose = pe->phb;
struct pnv_phb *phb = hose->private_data;
int enable, ret = 0;
s64 rc;
if (pe->addr < 0 || pe->addr >= phb->ioda.total_pe) {
pr_err("%s: PE address %x out of range [0, %x] "
"on PHB#%x\n",
__func__, pe->addr, phb->ioda.total_pe,
hose->global_number);
return -EINVAL;
}
switch (option) {
case EEH_OPT_DISABLE:
return -EPERM;
case EEH_OPT_ENABLE:
return 0;
case EEH_OPT_THAW_MMIO:
enable = OPAL_EEH_ACTION_CLEAR_FREEZE_MMIO;
break;
case EEH_OPT_THAW_DMA:
enable = OPAL_EEH_ACTION_CLEAR_FREEZE_DMA;
break;
default:
pr_warn("%s: Invalid option %d\n",
__func__, option);
return -EINVAL;
}
if (phb->unfreeze_pe) {
ret = phb->unfreeze_pe(phb, pe->addr, enable);
} else {
rc = opal_pci_eeh_freeze_clear(phb->opal_id,
pe->addr,
enable);
if (rc != OPAL_SUCCESS) {
pr_warn("%s: Failure %lld enable %d for PHB#%x-PE#%x\n",
__func__, rc, option, phb->hose->global_number,
pe->addr);
ret = -EIO;
}
}
return ret;
}
static void ioda_eeh_phb_diag(struct eeh_pe *pe)
{
struct pnv_phb *phb = pe->phb->private_data;
long rc;
rc = opal_pci_get_phb_diag_data2(phb->opal_id, pe->data,
PNV_PCI_DIAG_BUF_SIZE);
if (rc != OPAL_SUCCESS)
pr_warn("%s: Failed to get diag-data for PHB#%x (%ld)\n",
__func__, pe->phb->global_number, rc);
}
static int ioda_eeh_get_phb_state(struct eeh_pe *pe)
{
struct pnv_phb *phb = pe->phb->private_data;
u8 fstate;
__be16 pcierr;
s64 rc;
int result = 0;
rc = opal_pci_eeh_freeze_status(phb->opal_id,
pe->addr,
&fstate,
&pcierr,
NULL);
if (rc != OPAL_SUCCESS) {
pr_warn("%s: Failure %lld getting PHB#%x state\n",
__func__, rc, phb->hose->global_number);
return EEH_STATE_NOT_SUPPORT;
}
if (be16_to_cpu(pcierr) != OPAL_EEH_PHB_ERROR) {
result = (EEH_STATE_MMIO_ACTIVE |
EEH_STATE_DMA_ACTIVE |
EEH_STATE_MMIO_ENABLED |
EEH_STATE_DMA_ENABLED);
} else if (!(pe->state & EEH_PE_ISOLATED)) {
eeh_pe_state_mark(pe, EEH_PE_ISOLATED);
ioda_eeh_phb_diag(pe);
}
return result;
}
static int ioda_eeh_get_pe_state(struct eeh_pe *pe)
{
struct pnv_phb *phb = pe->phb->private_data;
u8 fstate;
__be16 pcierr;
s64 rc;
int result;
if (pe->state & EEH_PE_RESET) {
result = (EEH_STATE_MMIO_ACTIVE |
EEH_STATE_DMA_ACTIVE |
EEH_STATE_MMIO_ENABLED |
EEH_STATE_DMA_ENABLED);
return result;
}
if (phb->get_pe_state) {
fstate = phb->get_pe_state(phb, pe->addr);
} else {
rc = opal_pci_eeh_freeze_status(phb->opal_id,
pe->addr,
&fstate,
&pcierr,
NULL);
if (rc != OPAL_SUCCESS) {
pr_warn("%s: Failure %lld getting PHB#%x-PE%x state\n",
__func__, rc, phb->hose->global_number, pe->addr);
return EEH_STATE_NOT_SUPPORT;
}
}
switch (fstate) {
case OPAL_EEH_STOPPED_NOT_FROZEN:
result = (EEH_STATE_MMIO_ACTIVE |
EEH_STATE_DMA_ACTIVE |
EEH_STATE_MMIO_ENABLED |
EEH_STATE_DMA_ENABLED);
break;
case OPAL_EEH_STOPPED_MMIO_FREEZE:
result = (EEH_STATE_DMA_ACTIVE |
EEH_STATE_DMA_ENABLED);
break;
case OPAL_EEH_STOPPED_DMA_FREEZE:
result = (EEH_STATE_MMIO_ACTIVE |
EEH_STATE_MMIO_ENABLED);
break;
case OPAL_EEH_STOPPED_MMIO_DMA_FREEZE:
result = 0;
break;
case OPAL_EEH_STOPPED_RESET:
result = EEH_STATE_RESET_ACTIVE;
break;
case OPAL_EEH_STOPPED_TEMP_UNAVAIL:
result = EEH_STATE_UNAVAILABLE;
break;
case OPAL_EEH_STOPPED_PERM_UNAVAIL:
result = EEH_STATE_NOT_SUPPORT;
break;
default:
result = EEH_STATE_NOT_SUPPORT;
pr_warn("%s: Invalid PHB#%x-PE#%x state %x\n",
__func__, phb->hose->global_number,
pe->addr, fstate);
}
if (!(result & EEH_STATE_NOT_SUPPORT) &&
!(result & EEH_STATE_UNAVAILABLE) &&
!(result & EEH_STATE_MMIO_ACTIVE) &&
!(result & EEH_STATE_DMA_ACTIVE) &&
!(pe->state & EEH_PE_ISOLATED)) {
if (phb->freeze_pe)
phb->freeze_pe(phb, pe->addr);
eeh_pe_state_mark(pe, EEH_PE_ISOLATED);
ioda_eeh_phb_diag(pe);
}
return result;
}
static int ioda_eeh_get_state(struct eeh_pe *pe)
{
struct pnv_phb *phb = pe->phb->private_data;
if (pe->addr < 0 ||
pe->addr >= phb->ioda.total_pe) {
pr_warn("%s: PHB#%x-PE#%x out of range [0, %x]\n",
__func__, phb->hose->global_number,
pe->addr, phb->ioda.total_pe);
return EEH_STATE_NOT_SUPPORT;
}
if (pe->type & EEH_PE_PHB)
return ioda_eeh_get_phb_state(pe);
return ioda_eeh_get_pe_state(pe);
}
static s64 ioda_eeh_phb_poll(struct pnv_phb *phb)
{
s64 rc = OPAL_HARDWARE;
while (1) {
rc = opal_pci_poll(phb->opal_id);
if (rc <= 0)
break;
if (system_state < SYSTEM_RUNNING)
udelay(1000 * rc);
else
msleep(rc);
}
return rc;
}
int ioda_eeh_phb_reset(struct pci_controller *hose, int option)
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
if (option == EEH_RESET_DEACTIVATE) {
if (system_state < SYSTEM_RUNNING)
udelay(1000 * EEH_PE_RST_SETTLE_TIME);
else
msleep(EEH_PE_RST_SETTLE_TIME);
}
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
if (option == EEH_RESET_DEACTIVATE)
msleep(EEH_PE_RST_SETTLE_TIME);
out:
if (rc != OPAL_SUCCESS)
return -EIO;
return 0;
}
static int ioda_eeh_bridge_reset(struct pci_dev *dev, int option)
{
struct device_node *dn = pci_device_to_OF_node(dev);
struct eeh_dev *edev = of_node_to_eeh_dev(dn);
int aer = edev ? edev->aer_cap : 0;
u32 ctrl;
pr_debug("%s: Reset PCI bus %04x:%02x with option %d\n",
__func__, pci_domain_nr(dev->bus),
dev->bus->number, option);
switch (option) {
case EEH_RESET_FUNDAMENTAL:
case EEH_RESET_HOT:
if (aer) {
eeh_ops->read_config(dn, aer + PCI_ERR_UNCOR_MASK,
4, &ctrl);
ctrl |= PCI_ERR_UNC_SURPDN;
eeh_ops->write_config(dn, aer + PCI_ERR_UNCOR_MASK,
4, ctrl);
}
eeh_ops->read_config(dn, PCI_BRIDGE_CONTROL, 2, &ctrl);
ctrl |= PCI_BRIDGE_CTL_BUS_RESET;
eeh_ops->write_config(dn, PCI_BRIDGE_CONTROL, 2, ctrl);
msleep(EEH_PE_RST_HOLD_TIME);
break;
case EEH_RESET_DEACTIVATE:
eeh_ops->read_config(dn, PCI_BRIDGE_CONTROL, 2, &ctrl);
ctrl &= ~PCI_BRIDGE_CTL_BUS_RESET;
eeh_ops->write_config(dn, PCI_BRIDGE_CONTROL, 2, ctrl);
msleep(EEH_PE_RST_SETTLE_TIME);
if (aer) {
eeh_ops->read_config(dn, aer + PCI_ERR_UNCOR_MASK,
4, &ctrl);
ctrl &= ~PCI_ERR_UNC_SURPDN;
eeh_ops->write_config(dn, aer + PCI_ERR_UNCOR_MASK,
4, ctrl);
}
break;
}
return 0;
}
void pnv_pci_reset_secondary_bus(struct pci_dev *dev)
{
struct pci_controller *hose;
if (pci_is_root_bus(dev->bus)) {
hose = pci_bus_to_host(dev->bus);
ioda_eeh_root_reset(hose, EEH_RESET_HOT);
ioda_eeh_root_reset(hose, EEH_RESET_DEACTIVATE);
} else {
ioda_eeh_bridge_reset(dev, EEH_RESET_HOT);
ioda_eeh_bridge_reset(dev, EEH_RESET_DEACTIVATE);
}
}
static int ioda_eeh_reset(struct eeh_pe *pe, int option)
{
struct pci_controller *hose = pe->phb;
struct pci_bus *bus;
int ret;
if (pe->type & EEH_PE_PHB) {
ret = ioda_eeh_phb_reset(hose, option);
} else {
bus = eeh_pe_bus_get(pe);
if (pci_is_root_bus(bus) ||
pci_is_root_bus(bus->parent))
ret = ioda_eeh_root_reset(hose, option);
else
ret = ioda_eeh_bridge_reset(bus->self, option);
}
return ret;
}
int ioda_eeh_get_log(struct eeh_pe *pe, int severity,
char *drv_log, unsigned long len)
{
pnv_pci_dump_phb_diag_data(pe->phb, pe->data);
return 0;
}
static int ioda_eeh_configure_bridge(struct eeh_pe *pe)
{
return 0;
}
static void ioda_eeh_hub_diag_common(struct OpalIoP7IOCErrorData *data)
{
if (data->gemXfir || data->gemRfir ||
data->gemRirqfir || data->gemMask || data->gemRwof)
pr_info(" GEM: %016llx %016llx %016llx %016llx %016llx\n",
be64_to_cpu(data->gemXfir),
be64_to_cpu(data->gemRfir),
be64_to_cpu(data->gemRirqfir),
be64_to_cpu(data->gemMask),
be64_to_cpu(data->gemRwof));
if (data->lemFir || data->lemErrMask ||
data->lemAction0 || data->lemAction1 || data->lemWof)
pr_info(" LEM: %016llx %016llx %016llx %016llx %016llx\n",
be64_to_cpu(data->lemFir),
be64_to_cpu(data->lemErrMask),
be64_to_cpu(data->lemAction0),
be64_to_cpu(data->lemAction1),
be64_to_cpu(data->lemWof));
}
static void ioda_eeh_hub_diag(struct pci_controller *hose)
{
struct pnv_phb *phb = hose->private_data;
struct OpalIoP7IOCErrorData *data = &phb->diag.hub_diag;
long rc;
rc = opal_pci_get_hub_diag_data(phb->hub_id, data, sizeof(*data));
if (rc != OPAL_SUCCESS) {
pr_warn("%s: Failed to get HUB#%llx diag-data (%ld)\n",
__func__, phb->hub_id, rc);
return;
}
switch (data->type) {
case OPAL_P7IOC_DIAG_TYPE_RGC:
pr_info("P7IOC diag-data for RGC\n\n");
ioda_eeh_hub_diag_common(data);
if (data->rgc.rgcStatus || data->rgc.rgcLdcp)
pr_info(" RGC: %016llx %016llx\n",
be64_to_cpu(data->rgc.rgcStatus),
be64_to_cpu(data->rgc.rgcLdcp));
break;
case OPAL_P7IOC_DIAG_TYPE_BI:
pr_info("P7IOC diag-data for BI %s\n\n",
data->bi.biDownbound ? "Downbound" : "Upbound");
ioda_eeh_hub_diag_common(data);
if (data->bi.biLdcp0 || data->bi.biLdcp1 ||
data->bi.biLdcp2 || data->bi.biFenceStatus)
pr_info(" BI: %016llx %016llx %016llx %016llx\n",
be64_to_cpu(data->bi.biLdcp0),
be64_to_cpu(data->bi.biLdcp1),
be64_to_cpu(data->bi.biLdcp2),
be64_to_cpu(data->bi.biFenceStatus));
break;
case OPAL_P7IOC_DIAG_TYPE_CI:
pr_info("P7IOC diag-data for CI Port %d\n\n",
data->ci.ciPort);
ioda_eeh_hub_diag_common(data);
if (data->ci.ciPortStatus || data->ci.ciPortLdcp)
pr_info(" CI: %016llx %016llx\n",
be64_to_cpu(data->ci.ciPortStatus),
be64_to_cpu(data->ci.ciPortLdcp));
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
pr_warn("%s: Invalid type of HUB#%llx diag-data (%d)\n",
__func__, phb->hub_id, data->type);
}
}
static int ioda_eeh_get_pe(struct pci_controller *hose,
u16 pe_no, struct eeh_pe **pe)
{
struct pnv_phb *phb = hose->private_data;
struct pnv_ioda_pe *pnv_pe;
struct eeh_pe *dev_pe;
struct eeh_dev edev;
if (phb->get_pe_state) {
pnv_pe = &phb->ioda.pe_array[pe_no];
if (pnv_pe->flags & PNV_IODA_PE_SLAVE) {
pnv_pe = pnv_pe->master;
WARN_ON(!pnv_pe ||
!(pnv_pe->flags & PNV_IODA_PE_MASTER));
pe_no = pnv_pe->pe_number;
}
}
memset(&edev, 0, sizeof(struct eeh_dev));
edev.phb = hose;
edev.pe_config_addr = pe_no;
dev_pe = eeh_pe_get(&edev);
if (!dev_pe)
return -EEXIST;
*pe = dev_pe;
if (phb->freeze_pe &&
!(dev_pe->state & EEH_PE_ISOLATED))
phb->freeze_pe(phb, pe_no);
return 0;
}
static int ioda_eeh_next_error(struct eeh_pe **pe)
{
struct pci_controller *hose;
struct pnv_phb *phb;
struct eeh_pe *phb_pe, *parent_pe;
__be64 frozen_pe_no;
__be16 err_type, severity;
int active_flags = (EEH_STATE_MMIO_ACTIVE | EEH_STATE_DMA_ACTIVE);
long rc;
int state, ret = EEH_NEXT_ERR_NONE;
eeh_remove_event(NULL, false);
opal_notifier_update_evt(OPAL_EVENT_PCI_ERROR, 0x0ul);
list_for_each_entry(hose, &hose_list, list_node) {
phb = hose->private_data;
phb_pe = eeh_phb_pe_get(hose);
if (!phb_pe || (phb_pe->state & EEH_PE_ISOLATED))
continue;
rc = opal_pci_next_error(phb->opal_id,
&frozen_pe_no, &err_type, &severity);
if (rc != OPAL_SUCCESS) {
pr_devel("%s: Invalid return value on "
"PHB#%x (0x%lx) from opal_pci_next_error",
__func__, hose->global_number, rc);
continue;
}
if (be16_to_cpu(err_type) == OPAL_EEH_NO_ERROR ||
be16_to_cpu(severity) == OPAL_EEH_SEV_NO_ERROR) {
pr_devel("%s: No error found on PHB#%x\n",
__func__, hose->global_number);
continue;
}
pr_devel("%s: Error (%d, %d, %llu) on PHB#%x\n",
__func__, be16_to_cpu(err_type), be16_to_cpu(severity),
be64_to_cpu(frozen_pe_no), hose->global_number);
switch (be16_to_cpu(err_type)) {
case OPAL_EEH_IOC_ERROR:
if (be16_to_cpu(severity) == OPAL_EEH_SEV_IOC_DEAD) {
pr_err("EEH: dead IOC detected\n");
ret = EEH_NEXT_ERR_DEAD_IOC;
} else if (be16_to_cpu(severity) == OPAL_EEH_SEV_INF) {
pr_info("EEH: IOC informative error "
"detected\n");
ioda_eeh_hub_diag(hose);
ret = EEH_NEXT_ERR_NONE;
}
break;
case OPAL_EEH_PHB_ERROR:
if (be16_to_cpu(severity) == OPAL_EEH_SEV_PHB_DEAD) {
*pe = phb_pe;
pr_err("EEH: dead PHB#%x detected, "
"location: %s\n",
hose->global_number,
eeh_pe_loc_get(phb_pe));
ret = EEH_NEXT_ERR_DEAD_PHB;
} else if (be16_to_cpu(severity) ==
OPAL_EEH_SEV_PHB_FENCED) {
*pe = phb_pe;
pr_err("EEH: Fenced PHB#%x detected, "
"location: %s\n",
hose->global_number,
eeh_pe_loc_get(phb_pe));
ret = EEH_NEXT_ERR_FENCED_PHB;
} else if (be16_to_cpu(severity) == OPAL_EEH_SEV_INF) {
pr_info("EEH: PHB#%x informative error "
"detected, location: %s\n",
hose->global_number,
eeh_pe_loc_get(phb_pe));
ioda_eeh_phb_diag(phb_pe);
pnv_pci_dump_phb_diag_data(hose, phb_pe->data);
ret = EEH_NEXT_ERR_NONE;
}
break;
case OPAL_EEH_PE_ERROR:
if (ioda_eeh_get_pe(hose,
be64_to_cpu(frozen_pe_no), pe)) {
pr_info("EEH: Clear non-existing PHB#%x-PE#%llx\n",
hose->global_number, frozen_pe_no);
pr_info("EEH: PHB location: %s\n",
eeh_pe_loc_get(phb_pe));
opal_pci_eeh_freeze_clear(phb->opal_id, frozen_pe_no,
OPAL_EEH_ACTION_CLEAR_FREEZE_ALL);
ret = EEH_NEXT_ERR_NONE;
} else if ((*pe)->state & EEH_PE_ISOLATED ||
eeh_pe_passed(*pe)) {
ret = EEH_NEXT_ERR_NONE;
} else {
pr_err("EEH: Frozen PE#%x on PHB#%x detected\n",
(*pe)->addr, (*pe)->phb->global_number);
pr_err("EEH: PE location: %s, PHB location: %s\n",
eeh_pe_loc_get(*pe), eeh_pe_loc_get(phb_pe));
ret = EEH_NEXT_ERR_FROZEN_PE;
}
break;
default:
pr_warn("%s: Unexpected error type %d\n",
__func__, be16_to_cpu(err_type));
}
if ((ret == EEH_NEXT_ERR_FROZEN_PE ||
ret == EEH_NEXT_ERR_FENCED_PHB) &&
!((*pe)->state & EEH_PE_ISOLATED)) {
eeh_pe_state_mark(*pe, EEH_PE_ISOLATED);
ioda_eeh_phb_diag(*pe);
}
if (ret == EEH_NEXT_ERR_FROZEN_PE) {
parent_pe = (*pe)->parent;
while (parent_pe) {
if (parent_pe->type & EEH_PE_PHB)
break;
state = ioda_eeh_get_state(parent_pe);
if (state > 0 &&
(state & active_flags) != active_flags)
*pe = parent_pe;
parent_pe = parent_pe->parent;
}
eeh_pe_state_mark(*pe, EEH_PE_ISOLATED);
}
if (ret > EEH_NEXT_ERR_INF)
break;
}
return ret;
}
