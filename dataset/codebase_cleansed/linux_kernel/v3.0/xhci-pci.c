static int xhci_pci_reinit(struct xhci_hcd *xhci, struct pci_dev *pdev)
{
if (!pci_set_mwi(pdev))
xhci_dbg(xhci, "MWI active\n");
xhci_dbg(xhci, "Finished xhci_pci_reinit\n");
return 0;
}
static int xhci_pci_setup(struct usb_hcd *hcd)
{
struct xhci_hcd *xhci;
struct pci_dev *pdev = to_pci_dev(hcd->self.controller);
int retval;
u32 temp;
hcd->self.sg_tablesize = TRBS_PER_SEGMENT - 2;
if (usb_hcd_is_primary_hcd(hcd)) {
xhci = kzalloc(sizeof(struct xhci_hcd), GFP_KERNEL);
if (!xhci)
return -ENOMEM;
*((struct xhci_hcd **) hcd->hcd_priv) = xhci;
xhci->main_hcd = hcd;
hcd->speed = HCD_USB2;
hcd->self.root_hub->speed = USB_SPEED_HIGH;
hcd->has_tt = 1;
} else {
xhci = hcd_to_xhci(hcd);
temp = xhci_readl(xhci, &xhci->cap_regs->hcc_params);
if (HCC_64BIT_ADDR(temp)) {
xhci_dbg(xhci, "Enabling 64-bit DMA addresses.\n");
dma_set_mask(hcd->self.controller, DMA_BIT_MASK(64));
} else {
dma_set_mask(hcd->self.controller, DMA_BIT_MASK(32));
}
return 0;
}
xhci->cap_regs = hcd->regs;
xhci->op_regs = hcd->regs +
HC_LENGTH(xhci_readl(xhci, &xhci->cap_regs->hc_capbase));
xhci->run_regs = hcd->regs +
(xhci_readl(xhci, &xhci->cap_regs->run_regs_off) & RTSOFF_MASK);
xhci->hcs_params1 = xhci_readl(xhci, &xhci->cap_regs->hcs_params1);
xhci->hcs_params2 = xhci_readl(xhci, &xhci->cap_regs->hcs_params2);
xhci->hcs_params3 = xhci_readl(xhci, &xhci->cap_regs->hcs_params3);
xhci->hcc_params = xhci_readl(xhci, &xhci->cap_regs->hc_capbase);
xhci->hci_version = HC_VERSION(xhci->hcc_params);
xhci->hcc_params = xhci_readl(xhci, &xhci->cap_regs->hcc_params);
xhci_print_registers(xhci);
if (pdev->vendor == PCI_VENDOR_ID_FRESCO_LOGIC &&
pdev->device == PCI_DEVICE_ID_FRESCO_LOGIC_PDK) {
if (pdev->revision == 0x0) {
xhci->quirks |= XHCI_RESET_EP_QUIRK;
xhci_dbg(xhci, "QUIRK: Fresco Logic xHC needs configure"
" endpoint cmd after reset endpoint\n");
}
xhci->quirks |= XHCI_BROKEN_MSI;
xhci_dbg(xhci, "QUIRK: Fresco Logic revision %u "
"has broken MSI implementation\n",
pdev->revision);
}
if (pdev->vendor == PCI_VENDOR_ID_NEC)
xhci->quirks |= XHCI_NEC_HOST;
if (pdev->vendor == PCI_VENDOR_ID_AMD && usb_amd_find_chipset_info())
xhci->quirks |= XHCI_AMD_PLL_FIX;
if (pdev->vendor == PCI_VENDOR_ID_INTEL &&
pdev->device == PCI_DEVICE_ID_INTEL_PANTHERPOINT_XHCI) {
xhci->quirks |= XHCI_SPURIOUS_SUCCESS;
xhci->quirks |= XHCI_EP_LIMIT_QUIRK;
xhci->limit_active_eps = 64;
}
if (pdev->vendor == PCI_VENDOR_ID_ETRON &&
pdev->device == PCI_DEVICE_ID_ASROCK_P67) {
xhci->quirks |= XHCI_RESET_ON_RESUME;
xhci_dbg(xhci, "QUIRK: Resetting on resume\n");
}
retval = xhci_halt(xhci);
if (retval)
goto error;
xhci_dbg(xhci, "Resetting HCD\n");
retval = xhci_reset(xhci);
if (retval)
goto error;
xhci_dbg(xhci, "Reset complete\n");
temp = xhci_readl(xhci, &xhci->cap_regs->hcc_params);
if (HCC_64BIT_ADDR(temp)) {
xhci_dbg(xhci, "Enabling 64-bit DMA addresses.\n");
dma_set_mask(hcd->self.controller, DMA_BIT_MASK(64));
} else {
dma_set_mask(hcd->self.controller, DMA_BIT_MASK(32));
}
xhci_dbg(xhci, "Calling HCD init\n");
retval = xhci_init(hcd);
if (retval)
goto error;
xhci_dbg(xhci, "Called HCD init\n");
pci_read_config_byte(pdev, XHCI_SBRN_OFFSET, &xhci->sbrn);
xhci_dbg(xhci, "Got SBRN %u\n", (unsigned int) xhci->sbrn);
retval = xhci_pci_reinit(xhci, pdev);
if (!retval)
return retval;
error:
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
IRQF_DISABLED | IRQF_SHARED);
if (retval)
goto put_usb3_hcd;
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
int retval = 0;
if (hcd->state != HC_STATE_SUSPENDED ||
xhci->shared_hcd->state != HC_STATE_SUSPENDED)
return -EINVAL;
retval = xhci_suspend(xhci);
return retval;
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
int xhci_register_pci(void)
{
return pci_register_driver(&xhci_pci_driver);
}
void xhci_unregister_pci(void)
{
pci_unregister_driver(&xhci_pci_driver);
}
