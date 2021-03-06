static int xhci_pci_reinit(struct xhci_hcd *xhci, struct pci_dev *pdev)
{
if (!pci_set_mwi(pdev))
xhci_dbg(xhci, "MWI active\n");
xhci_dbg(xhci, "Finished xhci_pci_reinit\n");
return 0;
}
static void xhci_pci_quirks(struct device *dev, struct xhci_hcd *xhci)
{
struct pci_dev *pdev = to_pci_dev(dev);
if (pdev->vendor == PCI_VENDOR_ID_FRESCO_LOGIC &&
(pdev->device == PCI_DEVICE_ID_FRESCO_LOGIC_PDK ||
pdev->device == PCI_DEVICE_ID_FRESCO_LOGIC_FL1400)) {
if (pdev->device == PCI_DEVICE_ID_FRESCO_LOGIC_PDK &&
pdev->revision == 0x0) {
xhci->quirks |= XHCI_RESET_EP_QUIRK;
xhci_dbg_trace(xhci, trace_xhci_dbg_quirks,
"QUIRK: Fresco Logic xHC needs configure"
" endpoint cmd after reset endpoint");
}
if (pdev->device == PCI_DEVICE_ID_FRESCO_LOGIC_PDK &&
pdev->revision == 0x4) {
xhci->quirks |= XHCI_SLOW_SUSPEND;
xhci_dbg_trace(xhci, trace_xhci_dbg_quirks,
"QUIRK: Fresco Logic xHC revision %u"
"must be suspended extra slowly",
pdev->revision);
}
if (pdev->device == PCI_DEVICE_ID_FRESCO_LOGIC_PDK)
xhci->quirks |= XHCI_BROKEN_STREAMS;
xhci->quirks |= XHCI_BROKEN_MSI;
xhci_dbg_trace(xhci, trace_xhci_dbg_quirks,
"QUIRK: Fresco Logic revision %u "
"has broken MSI implementation",
pdev->revision);
xhci->quirks |= XHCI_TRUST_TX_LENGTH;
}
if (pdev->vendor == PCI_VENDOR_ID_FRESCO_LOGIC &&
pdev->device == PCI_DEVICE_ID_FRESCO_LOGIC_FL1009)
xhci->quirks |= XHCI_BROKEN_STREAMS;
if (pdev->vendor == PCI_VENDOR_ID_NEC)
xhci->quirks |= XHCI_NEC_HOST;
if (pdev->vendor == PCI_VENDOR_ID_AMD && xhci->hci_version == 0x96)
xhci->quirks |= XHCI_AMD_0x96_HOST;
if (pdev->vendor == PCI_VENDOR_ID_AMD && usb_amd_find_chipset_info())
xhci->quirks |= XHCI_AMD_PLL_FIX;
if (pdev->vendor == PCI_VENDOR_ID_AMD)
xhci->quirks |= XHCI_TRUST_TX_LENGTH;
if (pdev->vendor == PCI_VENDOR_ID_INTEL) {
xhci->quirks |= XHCI_LPM_SUPPORT;
xhci->quirks |= XHCI_INTEL_HOST;
xhci->quirks |= XHCI_AVOID_BEI;
}
if (pdev->vendor == PCI_VENDOR_ID_INTEL &&
pdev->device == PCI_DEVICE_ID_INTEL_PANTHERPOINT_XHCI) {
xhci->quirks |= XHCI_EP_LIMIT_QUIRK;
xhci->limit_active_eps = 64;
xhci->quirks |= XHCI_SW_BW_CHECKING;
xhci->quirks |= XHCI_SPURIOUS_REBOOT;
}
if (pdev->vendor == PCI_VENDOR_ID_INTEL &&
(pdev->device == PCI_DEVICE_ID_INTEL_LYNXPOINT_LP_XHCI ||
pdev->device == PCI_DEVICE_ID_INTEL_WILDCATPOINT_LP_XHCI)) {
xhci->quirks |= XHCI_SPURIOUS_REBOOT;
xhci->quirks |= XHCI_SPURIOUS_WAKEUP;
}
if (pdev->vendor == PCI_VENDOR_ID_INTEL &&
(pdev->device == PCI_DEVICE_ID_INTEL_SUNRISEPOINT_LP_XHCI ||
pdev->device == PCI_DEVICE_ID_INTEL_SUNRISEPOINT_H_XHCI ||
pdev->device == PCI_DEVICE_ID_INTEL_CHERRYVIEW_XHCI ||
pdev->device == PCI_DEVICE_ID_INTEL_BROXTON_M_XHCI ||
pdev->device == PCI_DEVICE_ID_INTEL_BROXTON_B_XHCI ||
pdev->device == PCI_DEVICE_ID_INTEL_APL_XHCI ||
pdev->device == PCI_DEVICE_ID_INTEL_DNV_XHCI)) {
xhci->quirks |= XHCI_PME_STUCK_QUIRK;
}
if (pdev->vendor == PCI_VENDOR_ID_INTEL &&
pdev->device == PCI_DEVICE_ID_INTEL_CHERRYVIEW_XHCI) {
xhci->quirks |= XHCI_SSIC_PORT_UNUSED;
}
if (pdev->vendor == PCI_VENDOR_ID_INTEL &&
(pdev->device == PCI_DEVICE_ID_INTEL_CHERRYVIEW_XHCI ||
pdev->device == PCI_DEVICE_ID_INTEL_APL_XHCI ||
pdev->device == PCI_DEVICE_ID_INTEL_DNV_XHCI))
xhci->quirks |= XHCI_MISSING_CAS;
if (pdev->vendor == PCI_VENDOR_ID_ETRON &&
pdev->device == PCI_DEVICE_ID_EJ168) {
xhci->quirks |= XHCI_RESET_ON_RESUME;
xhci->quirks |= XHCI_TRUST_TX_LENGTH;
xhci->quirks |= XHCI_BROKEN_STREAMS;
}
if (pdev->vendor == PCI_VENDOR_ID_RENESAS &&
pdev->device == 0x0015)
xhci->quirks |= XHCI_RESET_ON_RESUME;
if (pdev->vendor == PCI_VENDOR_ID_VIA)
xhci->quirks |= XHCI_RESET_ON_RESUME;
if (pdev->vendor == PCI_VENDOR_ID_VIA &&
pdev->device == 0x3432)
xhci->quirks |= XHCI_BROKEN_STREAMS;
if (pdev->vendor == PCI_VENDOR_ID_ASMEDIA &&
pdev->device == 0x1042)
xhci->quirks |= XHCI_BROKEN_STREAMS;
if (pdev->vendor == PCI_VENDOR_ID_ASMEDIA &&
pdev->device == 0x1142)
xhci->quirks |= XHCI_TRUST_TX_LENGTH;
if (pdev->vendor == PCI_VENDOR_ID_TI && pdev->device == 0x8241)
xhci->quirks |= XHCI_LIMIT_ENDPOINT_INTERVAL_7;
if (xhci->quirks & XHCI_RESET_ON_RESUME)
xhci_dbg_trace(xhci, trace_xhci_dbg_quirks,
"QUIRK: Resetting on resume");
}
static void xhci_pme_acpi_rtd3_enable(struct pci_dev *dev)
{
static const u8 intel_dsm_uuid[] = {
0xb7, 0x0c, 0x34, 0xac, 0x01, 0xe9, 0xbf, 0x45,
0xb7, 0xe6, 0x2b, 0x34, 0xec, 0x93, 0x1e, 0x23,
};
union acpi_object *obj;
obj = acpi_evaluate_dsm(ACPI_HANDLE(&dev->dev), intel_dsm_uuid, 3, 1,
NULL);
ACPI_FREE(obj);
}
static void xhci_pme_acpi_rtd3_enable(struct pci_dev *dev) { }
static int xhci_pci_setup(struct usb_hcd *hcd)
{
struct xhci_hcd *xhci;
struct pci_dev *pdev = to_pci_dev(hcd->self.controller);
int retval;
xhci = hcd_to_xhci(hcd);
if (!xhci->sbrn)
pci_read_config_byte(pdev, XHCI_SBRN_OFFSET, &xhci->sbrn);
retval = xhci_gen_setup(hcd, xhci_pci_quirks);
if (retval)
return retval;
if (!usb_hcd_is_primary_hcd(hcd))
return 0;
xhci_dbg(xhci, "Got SBRN %u\n", (unsigned int) xhci->sbrn);
return xhci_pci_reinit(xhci, pdev);
}
static int xhci_pci_probe(struct pci_dev *dev, const struct pci_device_id *id)
{
int retval;
struct xhci_hcd *xhci;
struct hc_driver *driver;
struct usb_hcd *hcd;
driver = (struct hc_driver *)id->driver_data;
pm_runtime_get_noresume(&dev->dev);
retval = usb_hcd_pci_probe(dev, id);
if (retval)
goto put_runtime_pm;
hcd = dev_get_drvdata(&dev->dev);
xhci = hcd_to_xhci(hcd);
xhci->shared_hcd = usb_create_shared_hcd(driver, &dev->dev,
pci_name(dev), hcd);
if (!xhci->shared_hcd) {
retval = -ENOMEM;
goto dealloc_usb2_hcd;
}
retval = usb_add_hcd(xhci->shared_hcd, dev->irq,
IRQF_SHARED);
if (retval)
goto put_usb3_hcd;
if (!(xhci->quirks & XHCI_BROKEN_STREAMS) &&
HCC_MAX_PSA(xhci->hcc_params) >= 4)
xhci->shared_hcd->can_do_streams = 1;
if (xhci->quirks & XHCI_PME_STUCK_QUIRK)
xhci_pme_acpi_rtd3_enable(dev);
pm_runtime_put_noidle(&dev->dev);
return 0;
put_usb3_hcd:
usb_put_hcd(xhci->shared_hcd);
dealloc_usb2_hcd:
usb_hcd_pci_remove(dev);
put_runtime_pm:
pm_runtime_put_noidle(&dev->dev);
return retval;
}
static void xhci_pci_remove(struct pci_dev *dev)
{
struct xhci_hcd *xhci;
xhci = hcd_to_xhci(pci_get_drvdata(dev));
xhci->xhc_state |= XHCI_STATE_REMOVING;
if (xhci->shared_hcd) {
usb_remove_hcd(xhci->shared_hcd);
usb_put_hcd(xhci->shared_hcd);
}
if (xhci->quirks & XHCI_SPURIOUS_WAKEUP)
pci_set_power_state(dev, PCI_D3hot);
usb_hcd_pci_remove(dev);
}
static void xhci_ssic_port_unused_quirk(struct usb_hcd *hcd, bool suspend)
{
struct xhci_hcd *xhci = hcd_to_xhci(hcd);
u32 val;
void __iomem *reg;
int i;
for (i = 0; i < SSIC_PORT_NUM; i++) {
reg = (void __iomem *) xhci->cap_regs +
SSIC_PORT_CFG2 +
i * SSIC_PORT_CFG2_OFFSET;
val = readl(reg) & ~PROG_DONE;
writel(val, reg);
val = readl(reg);
if (suspend)
val |= SSIC_PORT_UNUSED;
else
val &= ~SSIC_PORT_UNUSED;
writel(val, reg);
val = readl(reg) | PROG_DONE;
writel(val, reg);
readl(reg);
}
}
static void xhci_pme_quirk(struct usb_hcd *hcd)
{
struct xhci_hcd *xhci = hcd_to_xhci(hcd);
void __iomem *reg;
u32 val;
reg = (void __iomem *) xhci->cap_regs + 0x80a4;
val = readl(reg);
writel(val | BIT(28), reg);
readl(reg);
}
static int xhci_pci_suspend(struct usb_hcd *hcd, bool do_wakeup)
{
struct xhci_hcd *xhci = hcd_to_xhci(hcd);
struct pci_dev *pdev = to_pci_dev(hcd->self.controller);
int ret;
if (xhci->quirks & XHCI_COMP_MODE_QUIRK)
pci_d3cold_disable(pdev);
if (xhci->quirks & XHCI_PME_STUCK_QUIRK)
xhci_pme_quirk(hcd);
if (xhci->quirks & XHCI_SSIC_PORT_UNUSED)
xhci_ssic_port_unused_quirk(hcd, true);
ret = xhci_suspend(xhci, do_wakeup);
if (ret && (xhci->quirks & XHCI_SSIC_PORT_UNUSED))
xhci_ssic_port_unused_quirk(hcd, false);
return ret;
}
static int xhci_pci_resume(struct usb_hcd *hcd, bool hibernated)
{
struct xhci_hcd *xhci = hcd_to_xhci(hcd);
struct pci_dev *pdev = to_pci_dev(hcd->self.controller);
int retval = 0;
if (pdev->vendor == PCI_VENDOR_ID_INTEL)
usb_enable_intel_xhci_ports(pdev);
if (xhci->quirks & XHCI_SSIC_PORT_UNUSED)
xhci_ssic_port_unused_quirk(hcd, false);
if (xhci->quirks & XHCI_PME_STUCK_QUIRK)
xhci_pme_quirk(hcd);
retval = xhci_resume(xhci, hibernated);
return retval;
}
static int __init xhci_pci_init(void)
{
xhci_init_driver(&xhci_pci_hc_driver, &xhci_pci_overrides);
#ifdef CONFIG_PM
xhci_pci_hc_driver.pci_suspend = xhci_pci_suspend;
xhci_pci_hc_driver.pci_resume = xhci_pci_resume;
#endif
return pci_register_driver(&xhci_pci_driver);
}
static void __exit xhci_pci_exit(void)
{
pci_unregister_driver(&xhci_pci_driver);
}
