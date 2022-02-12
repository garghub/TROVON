static int broken_suspend(struct usb_hcd *hcd)
{
device_init_wakeup(&hcd->self.root_hub->dev, 0);
return 0;
}
static int ohci_quirk_amd756(struct usb_hcd *hcd)
{
struct ohci_hcd *ohci = hcd_to_ohci (hcd);
ohci->flags = OHCI_QUIRK_AMD756;
ohci_dbg (ohci, "AMD756 erratum 4 workaround\n");
return broken_suspend(hcd);
}
static int ohci_quirk_opti(struct usb_hcd *hcd)
{
struct ohci_hcd *ohci = hcd_to_ohci (hcd);
ohci_dbg (ohci, "WARNING: OPTi workarounds unavailable\n");
return 0;
}
static int ohci_quirk_ns(struct usb_hcd *hcd)
{
struct pci_dev *pdev = to_pci_dev(hcd->self.controller);
struct pci_dev *b;
b = pci_get_slot (pdev->bus, PCI_DEVFN (PCI_SLOT (pdev->devfn), 1));
if (b && b->device == PCI_DEVICE_ID_NS_87560_LIO
&& b->vendor == PCI_VENDOR_ID_NS) {
struct ohci_hcd *ohci = hcd_to_ohci (hcd);
ohci->flags |= OHCI_QUIRK_SUPERIO;
ohci_dbg (ohci, "Using NSC SuperIO setup\n");
}
pci_dev_put(b);
return 0;
}
static int ohci_quirk_zfmicro(struct usb_hcd *hcd)
{
struct ohci_hcd *ohci = hcd_to_ohci (hcd);
ohci->flags |= OHCI_QUIRK_ZFMICRO;
ohci_dbg(ohci, "enabled Compaq ZFMicro chipset quirks\n");
return 0;
}
static int ohci_quirk_toshiba_scc(struct usb_hcd *hcd)
{
struct ohci_hcd *ohci = hcd_to_ohci (hcd);
#ifdef CONFIG_USB_OHCI_BIG_ENDIAN_MMIO
ohci->flags |= OHCI_QUIRK_BE_MMIO;
ohci_dbg (ohci, "enabled big endian Toshiba quirk\n");
return 0;
#else
ohci_err (ohci, "unsupported big endian Toshiba quirk\n");
return -ENXIO;
#endif
}
static void ohci_quirk_nec_worker(struct work_struct *work)
{
struct ohci_hcd *ohci = container_of(work, struct ohci_hcd, nec_work);
int status;
status = ohci_init(ohci);
if (status != 0) {
ohci_err(ohci, "Restarting NEC controller failed in %s, %d\n",
"ohci_init", status);
return;
}
status = ohci_restart(ohci);
if (status != 0)
ohci_err(ohci, "Restarting NEC controller failed in %s, %d\n",
"ohci_restart", status);
}
static int ohci_quirk_nec(struct usb_hcd *hcd)
{
struct ohci_hcd *ohci = hcd_to_ohci (hcd);
ohci->flags |= OHCI_QUIRK_NEC;
INIT_WORK(&ohci->nec_work, ohci_quirk_nec_worker);
ohci_dbg (ohci, "enabled NEC chipset lost interrupt quirk\n");
return 0;
}
static int ohci_quirk_amd700(struct usb_hcd *hcd)
{
struct ohci_hcd *ohci = hcd_to_ohci(hcd);
struct pci_dev *amd_smbus_dev;
u8 rev;
if (usb_amd_find_chipset_info())
ohci->flags |= OHCI_QUIRK_AMD_PLL;
amd_smbus_dev = pci_get_device(PCI_VENDOR_ID_ATI,
PCI_DEVICE_ID_ATI_SBX00_SMBUS, NULL);
if (!amd_smbus_dev)
return 0;
rev = amd_smbus_dev->revision;
if ((rev >= 0x40) && (rev <= 0x4f)) {
ohci->flags |= OHCI_QUIRK_AMD_PREFETCH;
ohci_dbg(ohci, "enabled AMD prefetch quirk\n");
}
pci_dev_put(amd_smbus_dev);
amd_smbus_dev = NULL;
return 0;
}
static void sb800_prefetch(struct ohci_hcd *ohci, int on)
{
struct pci_dev *pdev;
u16 misc;
pdev = to_pci_dev(ohci_to_hcd(ohci)->self.controller);
pci_read_config_word(pdev, 0x50, &misc);
if (on == 0)
pci_write_config_word(pdev, 0x50, misc & 0xfcff);
else
pci_write_config_word(pdev, 0x50, misc | 0x0300);
}
static int ohci_pci_reset (struct usb_hcd *hcd)
{
struct ohci_hcd *ohci = hcd_to_ohci (hcd);
int ret = 0;
if (hcd->self.controller) {
struct pci_dev *pdev = to_pci_dev(hcd->self.controller);
const struct pci_device_id *quirk_id;
quirk_id = pci_match_id(ohci_pci_quirks, pdev);
if (quirk_id != NULL) {
int (*quirk)(struct usb_hcd *ohci);
quirk = (void *)quirk_id->driver_data;
ret = quirk(hcd);
}
}
if (ret == 0) {
ohci_hcd_init (ohci);
return ohci_init (ohci);
}
return ret;
}
static int ohci_pci_start (struct usb_hcd *hcd)
{
struct ohci_hcd *ohci = hcd_to_ohci (hcd);
int ret;
#ifdef CONFIG_PM
if (hcd->self.controller) {
struct pci_dev *pdev = to_pci_dev(hcd->self.controller);
if (device_can_wakeup(&pdev->dev))
ohci->hc_control |= OHCI_CTRL_RWC;
}
#endif
ret = ohci_run (ohci);
if (ret < 0) {
ohci_err (ohci, "can't start\n");
ohci_stop (hcd);
}
return ret;
}
