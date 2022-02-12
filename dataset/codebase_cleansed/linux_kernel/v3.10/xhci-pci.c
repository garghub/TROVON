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
xhci_dbg(xhci, "QUIRK: Fresco Logic xHC needs configure"
" endpoint cmd after reset endpoint\n");
}
xhci->quirks |= XHCI_BROKEN_MSI;
xhci_dbg(xhci, "QUIRK: Fresco Logic revision %u "
"has broken MSI implementation\n",
pdev->revision);
xhci->quirks |= XHCI_TRUST_TX_LENGTH;
}
if (pdev->vendor == PCI_VENDOR_ID_NEC)
xhci->quirks |= XHCI_NEC_HOST;
if (pdev->vendor == PCI_VENDOR_ID_AMD && xhci->hci_version == 0x96)
xhci->quirks |= XHCI_AMD_0x96_HOST;
if (pdev->vendor == PCI_VENDOR_ID_AMD && usb_amd_find_chipset_info())
xhci->quirks |= XHCI_AMD_PLL_FIX;
if (pdev->vendor == PCI_VENDOR_ID_INTEL) {
xhci->quirks |= XHCI_LPM_SUPPORT;
xhci->quirks |= XHCI_INTEL_HOST;
}
if (pdev->vendor == PCI_VENDOR_ID_INTEL &&
pdev->device == PCI_DEVICE_ID_INTEL_PANTHERPOINT_XHCI) {
xhci->quirks |= XHCI_SPURIOUS_SUCCESS;
xhci->quirks |= XHCI_EP_LIMIT_QUIRK;
xhci->limit_active_eps = 64;
xhci->quirks |= XHCI_SW_BW_CHECKING;
xhci->quirks |= XHCI_SPURIOUS_REBOOT;
xhci->quirks |= XHCI_AVOID_BEI;
}
if (pdev->vendor == PCI_VENDOR_ID_ETRON &&
pdev->device == PCI_DEVICE_ID_ASROCK_P67) {
xhci->quirks |= XHCI_RESET_ON_RESUME;
xhci_dbg(xhci, "QUIRK: Resetting on resume\n");
xhci->quirks |= XHCI_TRUST_TX_LENGTH;
}
if (pdev->vendor == PCI_VENDOR_ID_VIA)
xhci->quirks |= XHCI_RESET_ON_RESUME;
}
static int xhci_pci_setup(struct usb_hcd *hcd)
{
struct xhci_hcd *xhci;
struct pci_dev *pdev = to_pci_dev(hcd->self.controller);
int retval;
retval = xhci_gen_setup(hcd, xhci_pci_quirks);
if (retval)
return retval;
xhci = hcd_to_xhci(hcd);
if (!usb_hcd_is_primary_hcd(hcd))
return 0;
pci_read_config_byte(pdev, XHCI_SBRN_OFFSET, &xhci->sbrn);
xhci_dbg(xhci, "Got SBRN %u\n", (unsigned int) xhci->sbrn);
retval = xhci_pci_reinit(xhci, pdev);
if (!retval)
return retval;
kfree(xhci);
return retval;
}
static int xhci_pci_probe(struct pci_dev *dev, const struct pci_device_id *id)
{
int retval;
struct xhci_hcd *xhci;
struct hc_driver *driver;
struct usb_hcd *hcd;
driver = (struct hc_driver *)id->driver_data;
retval = usb_hcd_pci_probe(dev, id);
if (retval)
return retval;
hcd = dev_get_drvdata(&dev->dev);
xhci = hcd_to_xhci(hcd);
xhci->shared_hcd = usb_create_shared_hcd(driver, &dev->dev,
pci_name(dev), hcd);
if (!xhci->shared_hcd) {
retval = -ENOMEM;
goto dealloc_usb2_hcd;
}
*((struct xhci_hcd **) xhci->shared_hcd->hcd_priv) = xhci;
retval = usb_add_hcd(xhci->shared_hcd, dev->irq,
IRQF_SHARED);
if (retval)
goto put_usb3_hcd;
if (xhci->quirks & XHCI_LPM_SUPPORT)
hcd_to_bus(xhci->shared_hcd)->root_hub->lpm_capable = 1;
return 0;
put_usb3_hcd:
usb_put_hcd(xhci->shared_hcd);
dealloc_usb2_hcd:
usb_hcd_pci_remove(dev);
return retval;
}
static void xhci_pci_remove(struct pci_dev *dev)
{
struct xhci_hcd *xhci;
xhci = hcd_to_xhci(pci_get_drvdata(dev));
if (xhci->shared_hcd) {
usb_remove_hcd(xhci->shared_hcd);
usb_put_hcd(xhci->shared_hcd);
}
usb_hcd_pci_remove(dev);
kfree(xhci);
}
static int xhci_pci_suspend(struct usb_hcd *hcd, bool do_wakeup)
{
struct xhci_hcd *xhci = hcd_to_xhci(hcd);
struct pci_dev *pdev = to_pci_dev(hcd->self.controller);
if (xhci_compliance_mode_recovery_timer_quirk_check())
pdev->no_d3cold = true;
return xhci_suspend(xhci);
}
static int xhci_pci_resume(struct usb_hcd *hcd, bool hibernated)
{
struct xhci_hcd *xhci = hcd_to_xhci(hcd);
struct pci_dev *pdev = to_pci_dev(hcd->self.controller);
int retval = 0;
if (usb_is_intel_switchable_xhci(pdev))
usb_enable_xhci_ports(pdev);
retval = xhci_resume(xhci, hibernated);
return retval;
}
int __init xhci_register_pci(void)
{
return pci_register_driver(&xhci_pci_driver);
}
void xhci_unregister_pci(void)
{
pci_unregister_driver(&xhci_pci_driver);
}
