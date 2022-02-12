static void uhci_pci_reset_hc(struct uhci_hcd *uhci)
{
uhci_reset_hc(to_pci_dev(uhci_dev(uhci)), uhci->io_addr);
}
static int uhci_pci_check_and_reset_hc(struct uhci_hcd *uhci)
{
return uhci_check_and_reset_hc(to_pci_dev(uhci_dev(uhci)),
uhci->io_addr);
}
static void uhci_pci_configure_hc(struct uhci_hcd *uhci)
{
struct pci_dev *pdev = to_pci_dev(uhci_dev(uhci));
pci_write_config_word(pdev, USBLEGSUP, USBLEGSUP_DEFAULT);
if (pdev->vendor == PCI_VENDOR_ID_INTEL)
pci_write_config_byte(pdev, USBRES_INTEL, 0);
}
static int uhci_pci_resume_detect_interrupts_are_broken(struct uhci_hcd *uhci)
{
int port;
switch (to_pci_dev(uhci_dev(uhci))->vendor) {
default:
break;
case PCI_VENDOR_ID_GENESYS:
return 1;
case PCI_VENDOR_ID_INTEL:
for (port = 0; port < uhci->rh_numports; ++port) {
if (inw(uhci->io_addr + USBPORTSC1 + port * 2) &
USBPORTSC_OC)
return 1;
}
break;
}
return 0;
}
static int uhci_pci_global_suspend_mode_is_broken(struct uhci_hcd *uhci)
{
int port;
const char *sys_info;
static const char bad_Asus_board[] = "A7V8X";
sys_info = dmi_get_system_info(DMI_BOARD_NAME);
if (sys_info && !strcmp(sys_info, bad_Asus_board)) {
for (port = 0; port < uhci->rh_numports; ++port) {
if (inw(uhci->io_addr + USBPORTSC1 + port * 2) &
USBPORTSC_CCS)
return 1;
}
}
return 0;
}
static int uhci_pci_init(struct usb_hcd *hcd)
{
struct uhci_hcd *uhci = hcd_to_uhci(hcd);
uhci->io_addr = (unsigned long) hcd->rsrc_start;
uhci->rh_numports = uhci_count_ports(hcd);
if (to_pci_dev(uhci_dev(uhci))->vendor == PCI_VENDOR_ID_VIA)
uhci->oc_low = 1;
if (to_pci_dev(uhci_dev(uhci))->vendor == PCI_VENDOR_ID_HP)
uhci->wait_for_hp = 1;
if (to_pci_dev(uhci_dev(uhci))->vendor == PCI_VENDOR_ID_INTEL)
device_set_wakeup_capable(uhci_dev(uhci), true);
uhci->reset_hc = uhci_pci_reset_hc;
uhci->check_and_reset_hc = uhci_pci_check_and_reset_hc;
uhci->configure_hc = uhci_pci_configure_hc;
uhci->resume_detect_interrupts_are_broken =
uhci_pci_resume_detect_interrupts_are_broken;
uhci->global_suspend_mode_is_broken =
uhci_pci_global_suspend_mode_is_broken;
check_and_reset_hc(uhci);
return 0;
}
static void uhci_shutdown(struct pci_dev *pdev)
{
struct usb_hcd *hcd = pci_get_drvdata(pdev);
uhci_hc_died(hcd_to_uhci(hcd));
}
static int uhci_pci_suspend(struct usb_hcd *hcd, bool do_wakeup)
{
struct uhci_hcd *uhci = hcd_to_uhci(hcd);
struct pci_dev *pdev = to_pci_dev(uhci_dev(uhci));
int rc = 0;
dev_dbg(uhci_dev(uhci), "%s\n", __func__);
spin_lock_irq(&uhci->lock);
if (!HCD_HW_ACCESSIBLE(hcd) || uhci->dead)
goto done_okay;
pci_write_config_word(pdev, USBLEGSUP, 0);
clear_bit(HCD_FLAG_POLL_RH, &hcd->flags);
if (do_wakeup) {
if (pdev->vendor == PCI_VENDOR_ID_INTEL)
pci_write_config_byte(pdev, USBRES_INTEL,
USBPORT1EN | USBPORT2EN);
}
done_okay:
clear_bit(HCD_FLAG_HW_ACCESSIBLE, &hcd->flags);
spin_unlock_irq(&uhci->lock);
synchronize_irq(hcd->irq);
if (do_wakeup && HCD_WAKEUP_PENDING(hcd)) {
uhci_pci_resume(hcd, false);
rc = -EBUSY;
}
return rc;
}
static int uhci_pci_resume(struct usb_hcd *hcd, bool hibernated)
{
struct uhci_hcd *uhci = hcd_to_uhci(hcd);
dev_dbg(uhci_dev(uhci), "%s\n", __func__);
set_bit(HCD_FLAG_HW_ACCESSIBLE, &hcd->flags);
spin_lock_irq(&uhci->lock);
if (hibernated) {
uhci->reset_hc(uhci);
finish_reset(uhci);
}
else {
check_and_reset_hc(uhci);
}
configure_hc(uhci);
if (uhci->rh_state == UHCI_RH_RESET)
usb_root_hub_lost_power(hcd->self.root_hub);
spin_unlock_irq(&uhci->lock);
if (!uhci->RD_enable && hcd->self.root_hub->do_remote_wakeup)
set_bit(HCD_FLAG_POLL_RH, &hcd->flags);
usb_hcd_poll_rh_status(hcd);
return 0;
}
