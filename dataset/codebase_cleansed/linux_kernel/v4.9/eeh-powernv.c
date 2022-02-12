static int pnv_eeh_init(void)
{
struct pci_controller *hose;
struct pnv_phb *phb;
if (!firmware_has_feature(FW_FEATURE_OPAL)) {
pr_warn("%s: OPAL is required !\n",
__func__);
return -EINVAL;
}
eeh_add_flag(EEH_PROBE_MODE_DEV);
list_for_each_entry(hose, &hose_list, list_node) {
phb = hose->private_data;
if (phb->model == PNV_PHB_MODEL_P7IOC)
eeh_add_flag(EEH_ENABLE_IO_FOR_LOG);
if (phb->ioda.reserved_pe_idx != 0)
eeh_add_flag(EEH_VALID_PE_ZERO);
break;
}
return 0;
}
static irqreturn_t pnv_eeh_event(int irq, void *data)
{
disable_irq_nosync(irq);
if (eeh_enabled())
eeh_send_failure_event(NULL);
return IRQ_HANDLED;
}
static ssize_t pnv_eeh_ei_write(struct file *filp,
const char __user *user_buf,
size_t count, loff_t *ppos)
{
struct pci_controller *hose = filp->private_data;
struct eeh_dev *edev;
struct eeh_pe *pe;
int pe_no, type, func;
unsigned long addr, mask;
char buf[50];
int ret;
if (!eeh_ops || !eeh_ops->err_inject)
return -ENXIO;
ret = simple_write_to_buffer(buf, sizeof(buf), ppos, user_buf, count);
if (!ret)
return -EFAULT;
ret = sscanf(buf, "%x:%x:%x:%lx:%lx",
&pe_no, &type, &func, &addr, &mask);
if (ret != 5)
return -EINVAL;
edev = kzalloc(sizeof(*edev), GFP_KERNEL);
if (!edev)
return -ENOMEM;
edev->phb = hose;
edev->pe_config_addr = pe_no;
pe = eeh_pe_get(edev);
kfree(edev);
if (!pe)
return -ENODEV;
ret = eeh_ops->err_inject(pe, type, func, addr, mask);
return ret < 0 ? ret : count;
}
static int pnv_eeh_dbgfs_set(void *data, int offset, u64 val)
{
struct pci_controller *hose = data;
struct pnv_phb *phb = hose->private_data;
out_be64(phb->regs + offset, val);
return 0;
}
static int pnv_eeh_dbgfs_get(void *data, int offset, u64 *val)
{
struct pci_controller *hose = data;
struct pnv_phb *phb = hose->private_data;
*val = in_be64(phb->regs + offset);
return 0;
}
static int pnv_eeh_post_init(void)
{
struct pci_controller *hose;
struct pnv_phb *phb;
int ret = 0;
if (!pnv_eeh_nb_init) {
eeh_event_irq = opal_event_request(ilog2(OPAL_EVENT_PCI_ERROR));
if (eeh_event_irq < 0) {
pr_err("%s: Can't register OPAL event interrupt (%d)\n",
__func__, eeh_event_irq);
return eeh_event_irq;
}
ret = request_irq(eeh_event_irq, pnv_eeh_event,
IRQ_TYPE_LEVEL_HIGH, "opal-eeh", NULL);
if (ret < 0) {
irq_dispose_mapping(eeh_event_irq);
pr_err("%s: Can't request OPAL event interrupt (%d)\n",
__func__, eeh_event_irq);
return ret;
}
pnv_eeh_nb_init = true;
}
if (!eeh_enabled())
disable_irq(eeh_event_irq);
list_for_each_entry(hose, &hose_list, list_node) {
phb = hose->private_data;
if (eeh_enabled())
phb->flags |= PNV_PHB_FLAG_EEH;
else
phb->flags &= ~PNV_PHB_FLAG_EEH;
#ifdef CONFIG_DEBUG_FS
if (phb->has_dbgfs || !phb->dbgfs)
continue;
phb->has_dbgfs = 1;
debugfs_create_file("err_injct", 0200,
phb->dbgfs, hose,
&pnv_eeh_ei_fops);
debugfs_create_file("err_injct_outbound", 0600,
phb->dbgfs, hose,
&pnv_eeh_dbgfs_ops_outb);
debugfs_create_file("err_injct_inboundA", 0600,
phb->dbgfs, hose,
&pnv_eeh_dbgfs_ops_inbA);
debugfs_create_file("err_injct_inboundB", 0600,
phb->dbgfs, hose,
&pnv_eeh_dbgfs_ops_inbB);
#endif
}
return ret;
}
static int pnv_eeh_find_cap(struct pci_dn *pdn, int cap)
{
int pos = PCI_CAPABILITY_LIST;
int cnt = 48;
u32 status, id;
if (!pdn)
return 0;
pnv_pci_cfg_read(pdn, PCI_STATUS, 2, &status);
if (!(status & PCI_STATUS_CAP_LIST))
return 0;
while (cnt--) {
pnv_pci_cfg_read(pdn, pos, 1, &pos);
if (pos < 0x40)
break;
pos &= ~3;
pnv_pci_cfg_read(pdn, pos + PCI_CAP_LIST_ID, 1, &id);
if (id == 0xff)
break;
if (id == cap)
return pos;
pos += PCI_CAP_LIST_NEXT;
}
return 0;
}
static int pnv_eeh_find_ecap(struct pci_dn *pdn, int cap)
{
struct eeh_dev *edev = pdn_to_eeh_dev(pdn);
u32 header;
int pos = 256, ttl = (4096 - 256) / 8;
if (!edev || !edev->pcie_cap)
return 0;
if (pnv_pci_cfg_read(pdn, pos, 4, &header) != PCIBIOS_SUCCESSFUL)
return 0;
else if (!header)
return 0;
while (ttl-- > 0) {
if (PCI_EXT_CAP_ID(header) == cap && pos)
return pos;
pos = PCI_EXT_CAP_NEXT(header);
if (pos < 256)
break;
if (pnv_pci_cfg_read(pdn, pos, 4, &header) != PCIBIOS_SUCCESSFUL)
break;
}
return 0;
}
static void *pnv_eeh_probe(struct pci_dn *pdn, void *data)
{
struct pci_controller *hose = pdn->phb;
struct pnv_phb *phb = hose->private_data;
struct eeh_dev *edev = pdn_to_eeh_dev(pdn);
uint32_t pcie_flags;
int ret;
if (!edev || edev->pe)
return NULL;
if ((pdn->class_code >> 8) == PCI_CLASS_BRIDGE_ISA)
return NULL;
edev->class_code = pdn->class_code;
edev->mode &= 0xFFFFFF00;
edev->pcix_cap = pnv_eeh_find_cap(pdn, PCI_CAP_ID_PCIX);
edev->pcie_cap = pnv_eeh_find_cap(pdn, PCI_CAP_ID_EXP);
edev->af_cap = pnv_eeh_find_cap(pdn, PCI_CAP_ID_AF);
edev->aer_cap = pnv_eeh_find_ecap(pdn, PCI_EXT_CAP_ID_ERR);
if ((edev->class_code >> 8) == PCI_CLASS_BRIDGE_PCI) {
edev->mode |= EEH_DEV_BRIDGE;
if (edev->pcie_cap) {
pnv_pci_cfg_read(pdn, edev->pcie_cap + PCI_EXP_FLAGS,
2, &pcie_flags);
pcie_flags = (pcie_flags & PCI_EXP_FLAGS_TYPE) >> 4;
if (pcie_flags == PCI_EXP_TYPE_ROOT_PORT)
edev->mode |= EEH_DEV_ROOT_PORT;
else if (pcie_flags == PCI_EXP_TYPE_DOWNSTREAM)
edev->mode |= EEH_DEV_DS_PORT;
}
}
edev->config_addr = (pdn->busno << 8) | (pdn->devfn);
edev->pe_config_addr = phb->ioda.pe_rmap[edev->config_addr];
ret = eeh_add_to_parent_pe(edev);
if (ret) {
pr_warn("%s: Can't add PCI dev %04x:%02x:%02x.%01x to parent PE (%d)\n",
__func__, hose->global_number, pdn->busno,
PCI_SLOT(pdn->devfn), PCI_FUNC(pdn->devfn), ret);
return NULL;
}
if ((pdn->vendor_id == PCI_VENDOR_ID_BROADCOM &&
pdn->device_id == 0x1657) ||
(pdn->vendor_id == PCI_VENDOR_ID_BROADCOM &&
pdn->device_id == 0x168a) ||
(pdn->vendor_id == PCI_VENDOR_ID_BROADCOM &&
pdn->device_id == 0x168e))
edev->pe->state |= EEH_PE_CFG_RESTRICTED;
if (!(edev->pe->state & EEH_PE_PRI_BUS)) {
edev->pe->bus = pci_find_bus(hose->global_number,
pdn->busno);
if (edev->pe->bus)
edev->pe->state |= EEH_PE_PRI_BUS;
}
eeh_add_flag(EEH_ENABLED);
eeh_save_bars(edev);
return NULL;
}
static int pnv_eeh_set_option(struct eeh_pe *pe, int option)
{
struct pci_controller *hose = pe->phb;
struct pnv_phb *phb = hose->private_data;
bool freeze_pe = false;
int opt;
s64 rc;
switch (option) {
case EEH_OPT_DISABLE:
return -EPERM;
case EEH_OPT_ENABLE:
return 0;
case EEH_OPT_THAW_MMIO:
opt = OPAL_EEH_ACTION_CLEAR_FREEZE_MMIO;
break;
case EEH_OPT_THAW_DMA:
opt = OPAL_EEH_ACTION_CLEAR_FREEZE_DMA;
break;
case EEH_OPT_FREEZE_PE:
freeze_pe = true;
opt = OPAL_EEH_ACTION_SET_FREEZE_ALL;
break;
default:
pr_warn("%s: Invalid option %d\n", __func__, option);
return -EINVAL;
}
if (freeze_pe) {
if (phb->freeze_pe) {
phb->freeze_pe(phb, pe->addr);
return 0;
}
rc = opal_pci_eeh_freeze_set(phb->opal_id, pe->addr, opt);
if (rc != OPAL_SUCCESS) {
pr_warn("%s: Failure %lld freezing PHB#%x-PE#%x\n",
__func__, rc, phb->hose->global_number,
pe->addr);
return -EIO;
}
return 0;
}
if (phb->unfreeze_pe)
return phb->unfreeze_pe(phb, pe->addr, opt);
rc = opal_pci_eeh_freeze_clear(phb->opal_id, pe->addr, opt);
if (rc != OPAL_SUCCESS) {
pr_warn("%s: Failure %lld enable %d for PHB#%x-PE#%x\n",
__func__, rc, option, phb->hose->global_number,
pe->addr);
return -EIO;
}
return 0;
}
static int pnv_eeh_get_pe_addr(struct eeh_pe *pe)
{
return pe->addr;
}
static void pnv_eeh_get_phb_diag(struct eeh_pe *pe)
{
struct pnv_phb *phb = pe->phb->private_data;
s64 rc;
rc = opal_pci_get_phb_diag_data2(phb->opal_id, pe->data,
PNV_PCI_DIAG_BUF_SIZE);
if (rc != OPAL_SUCCESS)
pr_warn("%s: Failure %lld getting PHB#%x diag-data\n",
__func__, rc, pe->phb->global_number);
}
static int pnv_eeh_get_phb_state(struct eeh_pe *pe)
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
pnv_eeh_get_phb_diag(pe);
if (eeh_has_flag(EEH_EARLY_DUMP_LOG))
pnv_pci_dump_phb_diag_data(pe->phb, pe->data);
}
return result;
}
static int pnv_eeh_get_pe_state(struct eeh_pe *pe)
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
__func__, rc, phb->hose->global_number,
pe->addr);
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
pnv_eeh_get_phb_diag(pe);
if (eeh_has_flag(EEH_EARLY_DUMP_LOG))
pnv_pci_dump_phb_diag_data(pe->phb, pe->data);
}
return result;
}
static int pnv_eeh_get_state(struct eeh_pe *pe, int *delay)
{
int ret;
if (pe->type & EEH_PE_PHB)
ret = pnv_eeh_get_phb_state(pe);
else
ret = pnv_eeh_get_pe_state(pe);
if (!delay)
return ret;
*delay = 0;
if (ret & EEH_STATE_UNAVAILABLE)
*delay = 1000;
return ret;
}
static s64 pnv_eeh_poll(unsigned long id)
{
s64 rc = OPAL_HARDWARE;
while (1) {
rc = opal_pci_poll(id);
if (rc <= 0)
break;
if (system_state < SYSTEM_RUNNING)
udelay(1000 * rc);
else
msleep(rc);
}
return rc;
}
int pnv_eeh_phb_reset(struct pci_controller *hose, int option)
{
struct pnv_phb *phb = hose->private_data;
s64 rc = OPAL_HARDWARE;
pr_debug("%s: Reset PHB#%x, option=%d\n",
__func__, hose->global_number, option);
if (option == EEH_RESET_FUNDAMENTAL ||
option == EEH_RESET_HOT)
rc = opal_pci_reset(phb->opal_id,
OPAL_RESET_PHB_COMPLETE,
OPAL_ASSERT_RESET);
else if (option == EEH_RESET_DEACTIVATE)
rc = opal_pci_reset(phb->opal_id,
OPAL_RESET_PHB_COMPLETE,
OPAL_DEASSERT_RESET);
if (rc < 0)
goto out;
if (rc > 0)
rc = pnv_eeh_poll(phb->opal_id);
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
static int pnv_eeh_root_reset(struct pci_controller *hose, int option)
{
struct pnv_phb *phb = hose->private_data;
s64 rc = OPAL_HARDWARE;
pr_debug("%s: Reset PHB#%x, option=%d\n",
__func__, hose->global_number, option);
if (option == EEH_RESET_FUNDAMENTAL)
rc = opal_pci_reset(phb->opal_id,
OPAL_RESET_PCI_FUNDAMENTAL,
OPAL_ASSERT_RESET);
else if (option == EEH_RESET_HOT)
rc = opal_pci_reset(phb->opal_id,
OPAL_RESET_PCI_HOT,
OPAL_ASSERT_RESET);
else if (option == EEH_RESET_DEACTIVATE)
rc = opal_pci_reset(phb->opal_id,
OPAL_RESET_PCI_HOT,
OPAL_DEASSERT_RESET);
if (rc < 0)
goto out;
if (rc > 0)
rc = pnv_eeh_poll(phb->opal_id);
if (option == EEH_RESET_DEACTIVATE)
msleep(EEH_PE_RST_SETTLE_TIME);
out:
if (rc != OPAL_SUCCESS)
return -EIO;
return 0;
}
static int __pnv_eeh_bridge_reset(struct pci_dev *dev, int option)
{
struct pci_dn *pdn = pci_get_pdn_by_devfn(dev->bus, dev->devfn);
struct eeh_dev *edev = pdn_to_eeh_dev(pdn);
int aer = edev ? edev->aer_cap : 0;
u32 ctrl;
pr_debug("%s: Reset PCI bus %04x:%02x with option %d\n",
__func__, pci_domain_nr(dev->bus),
dev->bus->number, option);
switch (option) {
case EEH_RESET_FUNDAMENTAL:
case EEH_RESET_HOT:
if (aer) {
eeh_ops->read_config(pdn, aer + PCI_ERR_UNCOR_MASK,
4, &ctrl);
ctrl |= PCI_ERR_UNC_SURPDN;
eeh_ops->write_config(pdn, aer + PCI_ERR_UNCOR_MASK,
4, ctrl);
}
eeh_ops->read_config(pdn, PCI_BRIDGE_CONTROL, 2, &ctrl);
ctrl |= PCI_BRIDGE_CTL_BUS_RESET;
eeh_ops->write_config(pdn, PCI_BRIDGE_CONTROL, 2, ctrl);
msleep(EEH_PE_RST_HOLD_TIME);
break;
case EEH_RESET_DEACTIVATE:
eeh_ops->read_config(pdn, PCI_BRIDGE_CONTROL, 2, &ctrl);
ctrl &= ~PCI_BRIDGE_CTL_BUS_RESET;
eeh_ops->write_config(pdn, PCI_BRIDGE_CONTROL, 2, ctrl);
msleep(EEH_PE_RST_SETTLE_TIME);
if (aer) {
eeh_ops->read_config(pdn, aer + PCI_ERR_UNCOR_MASK,
4, &ctrl);
ctrl &= ~PCI_ERR_UNC_SURPDN;
eeh_ops->write_config(pdn, aer + PCI_ERR_UNCOR_MASK,
4, ctrl);
}
break;
}
return 0;
}
static int pnv_eeh_bridge_reset(struct pci_dev *pdev, int option)
{
struct pci_controller *hose = pci_bus_to_host(pdev->bus);
struct pnv_phb *phb = hose->private_data;
struct device_node *dn = pci_device_to_OF_node(pdev);
uint64_t id = PCI_SLOT_ID(phb->opal_id,
(pdev->bus->number << 8) | pdev->devfn);
uint8_t scope;
int64_t rc;
if (!dn || !of_get_property(dn, "ibm,reset-by-firmware", NULL))
return __pnv_eeh_bridge_reset(pdev, option);
switch (option) {
case EEH_RESET_FUNDAMENTAL:
scope = OPAL_RESET_PCI_FUNDAMENTAL;
break;
case EEH_RESET_HOT:
scope = OPAL_RESET_PCI_HOT;
break;
case EEH_RESET_DEACTIVATE:
return 0;
default:
dev_dbg(&pdev->dev, "%s: Unsupported reset %d\n",
__func__, option);
return -EINVAL;
}
rc = opal_pci_reset(id, scope, OPAL_ASSERT_RESET);
if (rc <= OPAL_SUCCESS)
goto out;
rc = pnv_eeh_poll(id);
out:
return (rc == OPAL_SUCCESS) ? 0 : -EIO;
}
void pnv_pci_reset_secondary_bus(struct pci_dev *dev)
{
struct pci_controller *hose;
if (pci_is_root_bus(dev->bus)) {
hose = pci_bus_to_host(dev->bus);
pnv_eeh_root_reset(hose, EEH_RESET_HOT);
pnv_eeh_root_reset(hose, EEH_RESET_DEACTIVATE);
} else {
pnv_eeh_bridge_reset(dev, EEH_RESET_HOT);
pnv_eeh_bridge_reset(dev, EEH_RESET_DEACTIVATE);
}
}
static void pnv_eeh_wait_for_pending(struct pci_dn *pdn, const char *type,
int pos, u16 mask)
{
struct eeh_dev *edev = pdn_to_eeh_dev(pdn);
int i, status = 0;
for (i = 0; i < 4; i++) {
eeh_ops->read_config(pdn, pos, 2, &status);
if (!(status & mask))
return;
msleep((1 << i) * 100);
}
pr_warn("%s: Pending transaction while issuing %sFLR to %04x:%02x:%02x.%01x\n",
__func__, type,
edev->phb->global_number, pdn->busno,
PCI_SLOT(pdn->devfn), PCI_FUNC(pdn->devfn));
}
static int pnv_eeh_do_flr(struct pci_dn *pdn, int option)
{
struct eeh_dev *edev = pdn_to_eeh_dev(pdn);
u32 reg = 0;
if (WARN_ON(!edev->pcie_cap))
return -ENOTTY;
eeh_ops->read_config(pdn, edev->pcie_cap + PCI_EXP_DEVCAP, 4, &reg);
if (!(reg & PCI_EXP_DEVCAP_FLR))
return -ENOTTY;
switch (option) {
case EEH_RESET_HOT:
case EEH_RESET_FUNDAMENTAL:
pnv_eeh_wait_for_pending(pdn, "",
edev->pcie_cap + PCI_EXP_DEVSTA,
PCI_EXP_DEVSTA_TRPND);
eeh_ops->read_config(pdn, edev->pcie_cap + PCI_EXP_DEVCTL,
4, &reg);
reg |= PCI_EXP_DEVCTL_BCR_FLR;
eeh_ops->write_config(pdn, edev->pcie_cap + PCI_EXP_DEVCTL,
4, reg);
msleep(EEH_PE_RST_HOLD_TIME);
break;
case EEH_RESET_DEACTIVATE:
eeh_ops->read_config(pdn, edev->pcie_cap + PCI_EXP_DEVCTL,
4, &reg);
reg &= ~PCI_EXP_DEVCTL_BCR_FLR;
eeh_ops->write_config(pdn, edev->pcie_cap + PCI_EXP_DEVCTL,
4, reg);
msleep(EEH_PE_RST_SETTLE_TIME);
break;
}
return 0;
}
static int pnv_eeh_do_af_flr(struct pci_dn *pdn, int option)
{
struct eeh_dev *edev = pdn_to_eeh_dev(pdn);
u32 cap = 0;
if (WARN_ON(!edev->af_cap))
return -ENOTTY;
eeh_ops->read_config(pdn, edev->af_cap + PCI_AF_CAP, 1, &cap);
if (!(cap & PCI_AF_CAP_TP) || !(cap & PCI_AF_CAP_FLR))
return -ENOTTY;
switch (option) {
case EEH_RESET_HOT:
case EEH_RESET_FUNDAMENTAL:
pnv_eeh_wait_for_pending(pdn, "AF",
edev->af_cap + PCI_AF_CTRL,
PCI_AF_STATUS_TP << 8);
eeh_ops->write_config(pdn, edev->af_cap + PCI_AF_CTRL,
1, PCI_AF_CTRL_FLR);
msleep(EEH_PE_RST_HOLD_TIME);
break;
case EEH_RESET_DEACTIVATE:
eeh_ops->write_config(pdn, edev->af_cap + PCI_AF_CTRL, 1, 0);
msleep(EEH_PE_RST_SETTLE_TIME);
break;
}
return 0;
}
static int pnv_eeh_reset_vf_pe(struct eeh_pe *pe, int option)
{
struct eeh_dev *edev;
struct pci_dn *pdn;
int ret;
edev = list_first_entry_or_null(&pe->edevs, struct eeh_dev, list);
pdn = eeh_dev_to_pdn(edev);
if (!pdn)
return -ENXIO;
ret = pnv_eeh_do_flr(pdn, option);
if (!ret)
return ret;
return pnv_eeh_do_af_flr(pdn, option);
}
static int pnv_eeh_reset(struct eeh_pe *pe, int option)
{
struct pci_controller *hose = pe->phb;
struct pnv_phb *phb;
struct pci_bus *bus;
int64_t rc;
if (pe->type & EEH_PE_PHB)
return pnv_eeh_phb_reset(hose, option);
phb = hose->private_data;
if (phb->model == PNV_PHB_MODEL_P7IOC &&
(option == EEH_RESET_HOT ||
option == EEH_RESET_FUNDAMENTAL)) {
rc = opal_pci_reset(phb->opal_id,
OPAL_RESET_PHB_ERROR,
OPAL_ASSERT_RESET);
if (rc != OPAL_SUCCESS) {
pr_warn("%s: Failure %lld clearing error injection registers\n",
__func__, rc);
return -EIO;
}
}
if (pe->type & EEH_PE_VF)
return pnv_eeh_reset_vf_pe(pe, option);
bus = eeh_pe_bus_get(pe);
if (!bus) {
pr_err("%s: Cannot find PCI bus for PHB#%d-PE#%x\n",
__func__, pe->phb->global_number, pe->addr);
return -EIO;
}
if (pci_is_root_bus(bus) ||
pci_is_root_bus(bus->parent))
return pnv_eeh_root_reset(hose, option);
return pnv_eeh_bridge_reset(bus->self, option);
}
static int pnv_eeh_wait_state(struct eeh_pe *pe, int max_wait)
{
int ret;
int mwait;
while (1) {
ret = pnv_eeh_get_state(pe, &mwait);
if (ret != EEH_STATE_UNAVAILABLE)
return ret;
if (max_wait <= 0) {
pr_warn("%s: Timeout getting PE#%x's state (%d)\n",
__func__, pe->addr, max_wait);
return EEH_STATE_NOT_SUPPORT;
}
max_wait -= mwait;
msleep(mwait);
}
return EEH_STATE_NOT_SUPPORT;
}
static int pnv_eeh_get_log(struct eeh_pe *pe, int severity,
char *drv_log, unsigned long len)
{
if (!eeh_has_flag(EEH_EARLY_DUMP_LOG))
pnv_pci_dump_phb_diag_data(pe->phb, pe->data);
return 0;
}
static int pnv_eeh_configure_bridge(struct eeh_pe *pe)
{
return 0;
}
static int pnv_eeh_err_inject(struct eeh_pe *pe, int type, int func,
unsigned long addr, unsigned long mask)
{
struct pci_controller *hose = pe->phb;
struct pnv_phb *phb = hose->private_data;
s64 rc;
if (type != OPAL_ERR_INJECT_TYPE_IOA_BUS_ERR &&
type != OPAL_ERR_INJECT_TYPE_IOA_BUS_ERR64) {
pr_warn("%s: Invalid error type %d\n",
__func__, type);
return -ERANGE;
}
if (func < OPAL_ERR_INJECT_FUNC_IOA_LD_MEM_ADDR ||
func > OPAL_ERR_INJECT_FUNC_IOA_DMA_WR_TARGET) {
pr_warn("%s: Invalid error function %d\n",
__func__, func);
return -ERANGE;
}
if (!opal_check_token(OPAL_PCI_ERR_INJECT)) {
pr_warn("%s: Firmware doesn't support error injection\n",
__func__);
return -ENXIO;
}
rc = opal_pci_err_inject(phb->opal_id, pe->addr,
type, func, addr, mask);
if (rc != OPAL_SUCCESS) {
pr_warn("%s: Failure %lld injecting error "
"%d-%d to PHB#%x-PE#%x\n",
__func__, rc, type, func,
hose->global_number, pe->addr);
return -EIO;
}
return 0;
}
static inline bool pnv_eeh_cfg_blocked(struct pci_dn *pdn)
{
struct eeh_dev *edev = pdn_to_eeh_dev(pdn);
if (!edev || !edev->pe)
return false;
if (edev->physfn && (edev->pe->state & EEH_PE_RESET))
return false;
if (edev->pe->state & EEH_PE_CFG_BLOCKED)
return true;
return false;
}
static int pnv_eeh_read_config(struct pci_dn *pdn,
int where, int size, u32 *val)
{
if (!pdn)
return PCIBIOS_DEVICE_NOT_FOUND;
if (pnv_eeh_cfg_blocked(pdn)) {
*val = 0xFFFFFFFF;
return PCIBIOS_SET_FAILED;
}
return pnv_pci_cfg_read(pdn, where, size, val);
}
static int pnv_eeh_write_config(struct pci_dn *pdn,
int where, int size, u32 val)
{
if (!pdn)
return PCIBIOS_DEVICE_NOT_FOUND;
if (pnv_eeh_cfg_blocked(pdn))
return PCIBIOS_SET_FAILED;
return pnv_pci_cfg_write(pdn, where, size, val);
}
static void pnv_eeh_dump_hub_diag_common(struct OpalIoP7IOCErrorData *data)
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
static void pnv_eeh_get_and_dump_hub_diag(struct pci_controller *hose)
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
switch (be16_to_cpu(data->type)) {
case OPAL_P7IOC_DIAG_TYPE_RGC:
pr_info("P7IOC diag-data for RGC\n\n");
pnv_eeh_dump_hub_diag_common(data);
if (data->rgc.rgcStatus || data->rgc.rgcLdcp)
pr_info(" RGC: %016llx %016llx\n",
be64_to_cpu(data->rgc.rgcStatus),
be64_to_cpu(data->rgc.rgcLdcp));
break;
case OPAL_P7IOC_DIAG_TYPE_BI:
pr_info("P7IOC diag-data for BI %s\n\n",
data->bi.biDownbound ? "Downbound" : "Upbound");
pnv_eeh_dump_hub_diag_common(data);
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
pnv_eeh_dump_hub_diag_common(data);
if (data->ci.ciPortStatus || data->ci.ciPortLdcp)
pr_info(" CI: %016llx %016llx\n",
be64_to_cpu(data->ci.ciPortStatus),
be64_to_cpu(data->ci.ciPortLdcp));
break;
case OPAL_P7IOC_DIAG_TYPE_MISC:
pr_info("P7IOC diag-data for MISC\n\n");
pnv_eeh_dump_hub_diag_common(data);
break;
case OPAL_P7IOC_DIAG_TYPE_I2C:
pr_info("P7IOC diag-data for I2C\n\n");
pnv_eeh_dump_hub_diag_common(data);
break;
default:
pr_warn("%s: Invalid type of HUB#%llx diag-data (%d)\n",
__func__, phb->hub_id, data->type);
}
}
static int pnv_eeh_get_pe(struct pci_controller *hose,
u16 pe_no, struct eeh_pe **pe)
{
struct pnv_phb *phb = hose->private_data;
struct pnv_ioda_pe *pnv_pe;
struct eeh_pe *dev_pe;
struct eeh_dev edev;
pnv_pe = &phb->ioda.pe_array[pe_no];
if (pnv_pe->flags & PNV_IODA_PE_SLAVE) {
pnv_pe = pnv_pe->master;
WARN_ON(!pnv_pe ||
!(pnv_pe->flags & PNV_IODA_PE_MASTER));
pe_no = pnv_pe->pe_number;
}
memset(&edev, 0, sizeof(struct eeh_dev));
edev.phb = hose;
edev.pe_config_addr = pe_no;
dev_pe = eeh_pe_get(&edev);
if (!dev_pe)
return -EEXIST;
*pe = dev_pe;
if (!(dev_pe->state & EEH_PE_ISOLATED))
phb->freeze_pe(phb, pe_no);
dev_pe = dev_pe->parent;
while (dev_pe && !(dev_pe->type & EEH_PE_PHB)) {
int ret;
int active_flags = (EEH_STATE_MMIO_ACTIVE |
EEH_STATE_DMA_ACTIVE);
ret = eeh_ops->get_state(dev_pe, NULL);
if (ret <= 0 || (ret & active_flags) == active_flags) {
dev_pe = dev_pe->parent;
continue;
}
*pe = dev_pe;
if (!(dev_pe->state & EEH_PE_ISOLATED))
phb->freeze_pe(phb, dev_pe->addr);
dev_pe = dev_pe->parent;
}
return 0;
}
static int pnv_eeh_next_error(struct eeh_pe **pe)
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
__func__, be16_to_cpu(err_type),
be16_to_cpu(severity), be64_to_cpu(frozen_pe_no),
hose->global_number);
switch (be16_to_cpu(err_type)) {
case OPAL_EEH_IOC_ERROR:
if (be16_to_cpu(severity) == OPAL_EEH_SEV_IOC_DEAD) {
pr_err("EEH: dead IOC detected\n");
ret = EEH_NEXT_ERR_DEAD_IOC;
} else if (be16_to_cpu(severity) == OPAL_EEH_SEV_INF) {
pr_info("EEH: IOC informative error "
"detected\n");
pnv_eeh_get_and_dump_hub_diag(hose);
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
pnv_eeh_get_phb_diag(phb_pe);
pnv_pci_dump_phb_diag_data(hose, phb_pe->data);
ret = EEH_NEXT_ERR_NONE;
}
break;
case OPAL_EEH_PE_ERROR:
if (pnv_eeh_get_pe(hose,
be64_to_cpu(frozen_pe_no), pe)) {
pr_info("EEH: Clear non-existing PHB#%x-PE#%llx\n",
hose->global_number, be64_to_cpu(frozen_pe_no));
pr_info("EEH: PHB location: %s\n",
eeh_pe_loc_get(phb_pe));
rc = opal_pci_get_phb_diag_data2(phb->opal_id,
phb->diag.blob, PNV_PCI_DIAG_BUF_SIZE);
if (rc == OPAL_SUCCESS)
pnv_pci_dump_phb_diag_data(hose,
phb->diag.blob);
opal_pci_eeh_freeze_clear(phb->opal_id,
be64_to_cpu(frozen_pe_no),
OPAL_EEH_ACTION_CLEAR_FREEZE_ALL);
ret = EEH_NEXT_ERR_NONE;
} else if ((*pe)->state & EEH_PE_ISOLATED ||
eeh_pe_passed(*pe)) {
ret = EEH_NEXT_ERR_NONE;
} else {
pr_err("EEH: Frozen PE#%x "
"on PHB#%x detected\n",
(*pe)->addr,
(*pe)->phb->global_number);
pr_err("EEH: PE location: %s, "
"PHB location: %s\n",
eeh_pe_loc_get(*pe),
eeh_pe_loc_get(phb_pe));
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
pnv_eeh_get_phb_diag(*pe);
if (eeh_has_flag(EEH_EARLY_DUMP_LOG))
pnv_pci_dump_phb_diag_data((*pe)->phb,
(*pe)->data);
}
if (ret == EEH_NEXT_ERR_FROZEN_PE) {
parent_pe = (*pe)->parent;
while (parent_pe) {
if (parent_pe->type & EEH_PE_PHB)
break;
state = eeh_ops->get_state(parent_pe, NULL);
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
if (ret == EEH_NEXT_ERR_NONE && eeh_enabled())
enable_irq(eeh_event_irq);
return ret;
}
static int pnv_eeh_restore_vf_config(struct pci_dn *pdn)
{
struct eeh_dev *edev = pdn_to_eeh_dev(pdn);
u32 devctl, cmd, cap2, aer_capctl;
int old_mps;
if (edev->pcie_cap) {
old_mps = (ffs(pdn->mps) - 8) << 5;
eeh_ops->read_config(pdn, edev->pcie_cap + PCI_EXP_DEVCTL,
2, &devctl);
devctl &= ~PCI_EXP_DEVCTL_PAYLOAD;
devctl |= old_mps;
eeh_ops->write_config(pdn, edev->pcie_cap + PCI_EXP_DEVCTL,
2, devctl);
eeh_ops->read_config(pdn, edev->pcie_cap + PCI_EXP_DEVCAP2,
4, &cap2);
if (cap2 & 0x10) {
eeh_ops->read_config(pdn,
edev->pcie_cap + PCI_EXP_DEVCTL2,
4, &cap2);
cap2 |= 0x10;
eeh_ops->write_config(pdn,
edev->pcie_cap + PCI_EXP_DEVCTL2,
4, cap2);
}
}
eeh_ops->read_config(pdn, PCI_COMMAND, 2, &cmd);
cmd |= (PCI_COMMAND_PARITY | PCI_COMMAND_SERR);
eeh_ops->write_config(pdn, PCI_COMMAND, 2, cmd);
if (edev->pcie_cap) {
eeh_ops->read_config(pdn, edev->pcie_cap + PCI_EXP_DEVCTL,
2, &devctl);
devctl &= ~PCI_EXP_DEVCTL_CERE;
devctl |= (PCI_EXP_DEVCTL_NFERE |
PCI_EXP_DEVCTL_FERE |
PCI_EXP_DEVCTL_URRE);
eeh_ops->write_config(pdn, edev->pcie_cap + PCI_EXP_DEVCTL,
2, devctl);
}
if (edev->pcie_cap && edev->aer_cap) {
eeh_ops->read_config(pdn, edev->aer_cap + PCI_ERR_CAP,
4, &aer_capctl);
aer_capctl |= (PCI_ERR_CAP_ECRC_GENE | PCI_ERR_CAP_ECRC_CHKE);
eeh_ops->write_config(pdn, edev->aer_cap + PCI_ERR_CAP,
4, aer_capctl);
}
return 0;
}
static int pnv_eeh_restore_config(struct pci_dn *pdn)
{
struct eeh_dev *edev = pdn_to_eeh_dev(pdn);
struct pnv_phb *phb;
s64 ret;
if (!edev)
return -EEXIST;
if (edev->physfn) {
ret = pnv_eeh_restore_vf_config(pdn);
} else {
phb = edev->phb->private_data;
ret = opal_pci_reinit(phb->opal_id,
OPAL_REINIT_PCI_DEV, edev->config_addr);
}
if (ret) {
pr_warn("%s: Can't reinit PCI dev 0x%x (%lld)\n",
__func__, edev->config_addr, ret);
return -EIO;
}
return 0;
}
void pcibios_bus_add_device(struct pci_dev *pdev)
{
struct pci_dn *pdn = pci_get_pdn(pdev);
if (!pdev->is_virtfn)
return;
eeh_add_device_early(pdn);
eeh_add_device_late(pdev);
eeh_sysfs_add_device(pdev);
}
static void pnv_pci_fixup_vf_mps(struct pci_dev *pdev)
{
struct pci_dn *pdn = pci_get_pdn(pdev);
int parent_mps;
if (!pdev->is_virtfn)
return;
parent_mps = pcie_get_mps(pdev->physfn);
if ((128 << pdev->pcie_mpss) >= parent_mps)
pcie_set_mps(pdev, parent_mps);
pdn->mps = pcie_get_mps(pdev);
}
static int __init eeh_powernv_init(void)
{
int ret = -EINVAL;
eeh_set_pe_aux_size(PNV_PCI_DIAG_BUF_SIZE);
ret = eeh_ops_register(&pnv_eeh_ops);
if (!ret)
pr_info("EEH: PowerNV platform initialized\n");
else
pr_info("EEH: Failed to initialize PowerNV platform (%d)\n", ret);
return ret;
}
