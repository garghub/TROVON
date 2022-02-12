int qib_pcie_init(struct pci_dev *pdev, const struct pci_device_id *ent)
{
int ret;
ret = pci_enable_device(pdev);
if (ret) {
qib_early_err(&pdev->dev, "pci enable failed: error %d\n",
-ret);
goto done;
}
ret = pci_request_regions(pdev, QIB_DRV_NAME);
if (ret) {
qib_devinfo(pdev, "pci_request_regions fails: err %d\n", -ret);
goto bail;
}
ret = pci_set_dma_mask(pdev, DMA_BIT_MASK(64));
if (ret) {
ret = pci_set_dma_mask(pdev, DMA_BIT_MASK(32));
if (ret) {
qib_devinfo(pdev, "Unable to set DMA mask: %d\n", ret);
goto bail;
}
ret = pci_set_consistent_dma_mask(pdev, DMA_BIT_MASK(32));
} else
ret = pci_set_consistent_dma_mask(pdev, DMA_BIT_MASK(64));
if (ret) {
qib_early_err(&pdev->dev,
"Unable to set DMA consistent mask: %d\n", ret);
goto bail;
}
pci_set_master(pdev);
ret = pci_enable_pcie_error_reporting(pdev);
if (ret) {
qib_early_err(&pdev->dev,
"Unable to enable pcie error reporting: %d\n",
ret);
ret = 0;
}
goto done;
bail:
pci_disable_device(pdev);
pci_release_regions(pdev);
done:
return ret;
}
int qib_pcie_ddinit(struct qib_devdata *dd, struct pci_dev *pdev,
const struct pci_device_id *ent)
{
unsigned long len;
resource_size_t addr;
dd->pcidev = pdev;
pci_set_drvdata(pdev, dd);
addr = pci_resource_start(pdev, 0);
len = pci_resource_len(pdev, 0);
#if defined(__powerpc__)
dd->kregbase = __ioremap(addr, len, _PAGE_NO_CACHE | _PAGE_WRITETHRU);
#else
dd->kregbase = ioremap_nocache(addr, len);
#endif
if (!dd->kregbase)
return -ENOMEM;
dd->kregend = (u64 __iomem *)((void __iomem *) dd->kregbase + len);
dd->physaddr = addr;
dd->pcibar0 = addr;
dd->pcibar1 = addr >> 32;
dd->deviceid = ent->device;
dd->vendorid = ent->vendor;
return 0;
}
void qib_pcie_ddcleanup(struct qib_devdata *dd)
{
u64 __iomem *base = (void __iomem *) dd->kregbase;
dd->kregbase = NULL;
iounmap(base);
if (dd->piobase)
iounmap(dd->piobase);
if (dd->userbase)
iounmap(dd->userbase);
if (dd->piovl15base)
iounmap(dd->piovl15base);
pci_disable_device(dd->pcidev);
pci_release_regions(dd->pcidev);
pci_set_drvdata(dd->pcidev, NULL);
}
static void qib_msix_setup(struct qib_devdata *dd, int pos, u32 *msixcnt,
struct qib_msix_entry *qib_msix_entry)
{
int ret;
int nvec = *msixcnt;
struct msix_entry *msix_entry;
int i;
ret = pci_msix_vec_count(dd->pcidev);
if (ret < 0)
goto do_intx;
nvec = min(nvec, ret);
msix_entry = kmalloc(nvec * sizeof(*msix_entry), GFP_KERNEL);
if (!msix_entry)
goto do_intx;
for (i = 0; i < nvec; i++)
msix_entry[i] = qib_msix_entry[i].msix;
ret = pci_enable_msix_range(dd->pcidev, msix_entry, 1, nvec);
if (ret < 0)
goto free_msix_entry;
else
nvec = ret;
for (i = 0; i < nvec; i++)
qib_msix_entry[i].msix = msix_entry[i];
kfree(msix_entry);
*msixcnt = nvec;
return;
free_msix_entry:
kfree(msix_entry);
do_intx:
qib_dev_err(dd, "pci_enable_msix_range %d vectors failed: %d, "
"falling back to INTx\n", nvec, ret);
*msixcnt = 0;
qib_enable_intx(dd->pcidev);
}
static int qib_msi_setup(struct qib_devdata *dd, int pos)
{
struct pci_dev *pdev = dd->pcidev;
u16 control;
int ret;
ret = pci_enable_msi(pdev);
if (ret)
qib_dev_err(dd,
"pci_enable_msi failed: %d, interrupts may not work\n",
ret);
pci_read_config_dword(pdev, pos + PCI_MSI_ADDRESS_LO,
&dd->msi_lo);
pci_read_config_dword(pdev, pos + PCI_MSI_ADDRESS_HI,
&dd->msi_hi);
pci_read_config_word(pdev, pos + PCI_MSI_FLAGS, &control);
pci_read_config_word(pdev, pos + ((control & PCI_MSI_FLAGS_64BIT)
? 12 : 8),
&dd->msi_data);
return ret;
}
int qib_pcie_params(struct qib_devdata *dd, u32 minw, u32 *nent,
struct qib_msix_entry *entry)
{
u16 linkstat, speed;
int pos = 0, ret = 1;
if (!pci_is_pcie(dd->pcidev)) {
qib_dev_err(dd, "Can't find PCI Express capability!\n");
dd->lbus_width = 1;
dd->lbus_speed = 2500;
goto bail;
}
pos = dd->pcidev->msix_cap;
if (nent && *nent && pos) {
qib_msix_setup(dd, pos, nent, entry);
ret = 0;
} else {
pos = dd->pcidev->msi_cap;
if (pos)
ret = qib_msi_setup(dd, pos);
else
qib_dev_err(dd, "No PCI MSI or MSIx capability!\n");
}
if (!pos)
qib_enable_intx(dd->pcidev);
pcie_capability_read_word(dd->pcidev, PCI_EXP_LNKSTA, &linkstat);
speed = linkstat & 0xf;
linkstat >>= 4;
linkstat &= 0x1f;
dd->lbus_width = linkstat;
switch (speed) {
case 1:
dd->lbus_speed = 2500;
break;
case 2:
dd->lbus_speed = 5000;
break;
default:
dd->lbus_speed = 2500;
break;
}
if (minw && linkstat < minw)
qib_dev_err(dd,
"PCIe width %u (x%u HCA), performance reduced\n",
linkstat, minw);
qib_tune_pcie_caps(dd);
qib_tune_pcie_coalesce(dd);
bail:
snprintf(dd->lbus_info, sizeof(dd->lbus_info),
"PCIe,%uMHz,x%u\n", dd->lbus_speed, dd->lbus_width);
return ret;
}
int qib_reinit_intr(struct qib_devdata *dd)
{
int pos;
u16 control;
int ret = 0;
if (!dd->msi_lo)
goto bail;
pos = dd->pcidev->msi_cap;
if (!pos) {
qib_dev_err(dd,
"Can't find MSI capability, can't restore MSI settings\n");
ret = 0;
goto bail;
}
pci_write_config_dword(dd->pcidev, pos + PCI_MSI_ADDRESS_LO,
dd->msi_lo);
pci_write_config_dword(dd->pcidev, pos + PCI_MSI_ADDRESS_HI,
dd->msi_hi);
pci_read_config_word(dd->pcidev, pos + PCI_MSI_FLAGS, &control);
if (!(control & PCI_MSI_FLAGS_ENABLE)) {
control |= PCI_MSI_FLAGS_ENABLE;
pci_write_config_word(dd->pcidev, pos + PCI_MSI_FLAGS,
control);
}
pci_write_config_word(dd->pcidev, pos +
((control & PCI_MSI_FLAGS_64BIT) ? 12 : 8),
dd->msi_data);
ret = 1;
bail:
if (!ret && (dd->flags & QIB_HAS_INTX)) {
qib_enable_intx(dd->pcidev);
ret = 1;
}
pci_set_master(dd->pcidev);
return ret;
}
void qib_nomsi(struct qib_devdata *dd)
{
dd->msi_lo = 0;
pci_disable_msi(dd->pcidev);
}
void qib_nomsix(struct qib_devdata *dd)
{
pci_disable_msix(dd->pcidev);
}
void qib_enable_intx(struct pci_dev *pdev)
{
u16 cw, new;
int pos;
pci_read_config_word(pdev, PCI_COMMAND, &cw);
new = cw & ~PCI_COMMAND_INTX_DISABLE;
if (new != cw)
pci_write_config_word(pdev, PCI_COMMAND, new);
pos = pdev->msi_cap;
if (pos) {
pci_read_config_word(pdev, pos + PCI_MSI_FLAGS, &cw);
new = cw & ~PCI_MSI_FLAGS_ENABLE;
if (new != cw)
pci_write_config_word(pdev, pos + PCI_MSI_FLAGS, new);
}
pos = pdev->msix_cap;
if (pos) {
pci_read_config_word(pdev, pos + PCI_MSIX_FLAGS, &cw);
new = cw & ~PCI_MSIX_FLAGS_ENABLE;
if (new != cw)
pci_write_config_word(pdev, pos + PCI_MSIX_FLAGS, new);
}
}
void qib_pcie_getcmd(struct qib_devdata *dd, u16 *cmd, u8 *iline, u8 *cline)
{
pci_read_config_word(dd->pcidev, PCI_COMMAND, cmd);
pci_read_config_byte(dd->pcidev, PCI_INTERRUPT_LINE, iline);
pci_read_config_byte(dd->pcidev, PCI_CACHE_LINE_SIZE, cline);
}
void qib_pcie_reenable(struct qib_devdata *dd, u16 cmd, u8 iline, u8 cline)
{
int r;
r = pci_write_config_dword(dd->pcidev, PCI_BASE_ADDRESS_0,
dd->pcibar0);
if (r)
qib_dev_err(dd, "rewrite of BAR0 failed: %d\n", r);
r = pci_write_config_dword(dd->pcidev, PCI_BASE_ADDRESS_1,
dd->pcibar1);
if (r)
qib_dev_err(dd, "rewrite of BAR1 failed: %d\n", r);
pci_write_config_word(dd->pcidev, PCI_COMMAND, cmd);
pci_write_config_byte(dd->pcidev, PCI_INTERRUPT_LINE, iline);
pci_write_config_byte(dd->pcidev, PCI_CACHE_LINE_SIZE, cline);
r = pci_enable_device(dd->pcidev);
if (r)
qib_dev_err(dd,
"pci_enable_device failed after reset: %d\n", r);
}
static void qib_tune_pcie_coalesce(struct qib_devdata *dd)
{
int r;
struct pci_dev *parent;
u16 devid;
u32 mask, bits, val;
if (!qib_pcie_coalesce)
return;
parent = dd->pcidev->bus->self;
if (parent->bus->parent) {
qib_devinfo(dd->pcidev, "Parent not root\n");
return;
}
if (!pci_is_pcie(parent))
return;
if (parent->vendor != 0x8086)
return;
devid = parent->device;
if (devid >= 0x25e2 && devid <= 0x25fa) {
if (parent->revision <= 0xb2)
bits = 1U << 10;
else
bits = 7U << 10;
mask = (3U << 24) | (7U << 10);
} else if (devid >= 0x65e2 && devid <= 0x65fa) {
bits = 1U << 10;
mask = (3U << 24) | (7U << 10);
} else if (devid >= 0x4021 && devid <= 0x402e) {
bits = 7U << 10;
mask = 7U << 10;
} else if (devid >= 0x3604 && devid <= 0x360a) {
bits = 7U << 10;
mask = (3U << 24) | (7U << 10);
} else {
return;
}
pci_read_config_dword(parent, 0x48, &val);
val &= ~mask;
val |= bits;
r = pci_write_config_dword(parent, 0x48, val);
}
static void qib_tune_pcie_caps(struct qib_devdata *dd)
{
struct pci_dev *parent;
u16 rc_mpss, rc_mps, ep_mpss, ep_mps;
u16 rc_mrrs, ep_mrrs, max_mrrs;
parent = dd->pcidev->bus->self;
if (!pci_is_root_bus(parent->bus)) {
qib_devinfo(dd->pcidev, "Parent not root\n");
return;
}
if (!pci_is_pcie(parent) || !pci_is_pcie(dd->pcidev))
return;
rc_mpss = parent->pcie_mpss;
rc_mps = ffs(pcie_get_mps(parent)) - 8;
ep_mpss = dd->pcidev->pcie_mpss;
ep_mps = ffs(pcie_get_mps(dd->pcidev)) - 8;
if (rc_mpss > ep_mpss)
rc_mpss = ep_mpss;
if (rc_mpss > (qib_pcie_caps & 7))
rc_mpss = qib_pcie_caps & 7;
if (rc_mpss > rc_mps) {
rc_mps = rc_mpss;
pcie_set_mps(parent, 128 << rc_mps);
}
if (rc_mpss > ep_mps) {
ep_mps = rc_mpss;
pcie_set_mps(dd->pcidev, 128 << ep_mps);
}
max_mrrs = 5;
if (max_mrrs > ((qib_pcie_caps >> 4) & 7))
max_mrrs = (qib_pcie_caps >> 4) & 7;
max_mrrs = 128 << max_mrrs;
rc_mrrs = pcie_get_readrq(parent);
ep_mrrs = pcie_get_readrq(dd->pcidev);
if (max_mrrs > rc_mrrs) {
rc_mrrs = max_mrrs;
pcie_set_readrq(parent, rc_mrrs);
}
if (max_mrrs > ep_mrrs) {
ep_mrrs = max_mrrs;
pcie_set_readrq(dd->pcidev, ep_mrrs);
}
}
static pci_ers_result_t
qib_pci_error_detected(struct pci_dev *pdev, pci_channel_state_t state)
{
struct qib_devdata *dd = pci_get_drvdata(pdev);
pci_ers_result_t ret = PCI_ERS_RESULT_RECOVERED;
switch (state) {
case pci_channel_io_normal:
qib_devinfo(pdev, "State Normal, ignoring\n");
break;
case pci_channel_io_frozen:
qib_devinfo(pdev, "State Frozen, requesting reset\n");
pci_disable_device(pdev);
ret = PCI_ERS_RESULT_NEED_RESET;
break;
case pci_channel_io_perm_failure:
qib_devinfo(pdev, "State Permanent Failure, disabling\n");
if (dd) {
dd->flags &= ~QIB_PRESENT;
qib_disable_after_error(dd);
}
ret = PCI_ERS_RESULT_DISCONNECT;
break;
default:
qib_devinfo(pdev, "QIB PCI errors detected (state %d)\n",
state);
break;
}
return ret;
}
static pci_ers_result_t
qib_pci_mmio_enabled(struct pci_dev *pdev)
{
u64 words = 0U;
struct qib_devdata *dd = pci_get_drvdata(pdev);
pci_ers_result_t ret = PCI_ERS_RESULT_RECOVERED;
if (dd && dd->pport) {
words = dd->f_portcntr(dd->pport, QIBPORTCNTR_WORDRCV);
if (words == ~0ULL)
ret = PCI_ERS_RESULT_NEED_RESET;
}
qib_devinfo(pdev,
"QIB mmio_enabled function called, read wordscntr %Lx, returning %d\n",
words, ret);
return ret;
}
static pci_ers_result_t
qib_pci_slot_reset(struct pci_dev *pdev)
{
qib_devinfo(pdev, "QIB slot_reset function called, ignored\n");
return PCI_ERS_RESULT_CAN_RECOVER;
}
static pci_ers_result_t
qib_pci_link_reset(struct pci_dev *pdev)
{
qib_devinfo(pdev, "QIB link_reset function called, ignored\n");
return PCI_ERS_RESULT_CAN_RECOVER;
}
static void
qib_pci_resume(struct pci_dev *pdev)
{
struct qib_devdata *dd = pci_get_drvdata(pdev);
qib_devinfo(pdev, "QIB resume function called\n");
pci_cleanup_aer_uncorrect_error_status(pdev);
qib_init(dd, 1);
}
