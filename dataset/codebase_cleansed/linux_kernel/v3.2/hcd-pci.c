static void companion_common(struct pci_dev *pdev, struct usb_hcd *hcd,
enum companion_action action)
{
struct pci_dev *companion;
struct usb_hcd *companion_hcd;
unsigned int slot = PCI_SLOT(pdev->devfn);
companion = NULL;
for_each_pci_dev(companion) {
if (companion->bus != pdev->bus ||
PCI_SLOT(companion->devfn) != slot)
continue;
companion_hcd = pci_get_drvdata(companion);
if (!companion_hcd)
continue;
if ((pdev->class == CL_OHCI || pdev->class == CL_UHCI) &&
companion->class == CL_EHCI) {
dev_dbg(&companion->dev, "HS companion for %s\n",
dev_name(&pdev->dev));
hcd->self.hs_companion = &companion_hcd->self;
} else if (pdev->class == CL_EHCI &&
(companion->class == CL_OHCI ||
companion->class == CL_UHCI)) {
switch (action) {
case SET_HS_COMPANION:
dev_dbg(&pdev->dev, "HS companion for %s\n",
dev_name(&companion->dev));
companion_hcd->self.hs_companion = &hcd->self;
break;
case CLEAR_HS_COMPANION:
companion_hcd->self.hs_companion = NULL;
break;
case WAIT_FOR_COMPANIONS:
device_pm_wait_for_dev(&pdev->dev,
&companion->dev);
break;
}
}
}
}
static void set_hs_companion(struct pci_dev *pdev, struct usb_hcd *hcd)
{
mutex_lock(&companions_mutex);
dev_set_drvdata(&pdev->dev, hcd);
companion_common(pdev, hcd, SET_HS_COMPANION);
mutex_unlock(&companions_mutex);
}
static void clear_hs_companion(struct pci_dev *pdev, struct usb_hcd *hcd)
{
mutex_lock(&companions_mutex);
dev_set_drvdata(&pdev->dev, NULL);
if (pdev->class == CL_OHCI || pdev->class == CL_UHCI)
hcd->self.hs_companion = NULL;
else
companion_common(pdev, hcd, CLEAR_HS_COMPANION);
mutex_unlock(&companions_mutex);
}
static void wait_for_companions(struct pci_dev *pdev, struct usb_hcd *hcd)
{
if (pdev->class == CL_EHCI)
companion_common(pdev, hcd, WAIT_FOR_COMPANIONS);
}
static inline void set_hs_companion(struct pci_dev *d, struct usb_hcd *h) {}
static inline void clear_hs_companion(struct pci_dev *d, struct usb_hcd *h) {}
static inline void wait_for_companions(struct pci_dev *d, struct usb_hcd *h) {}
int usb_hcd_pci_probe(struct pci_dev *dev, const struct pci_device_id *id)
{
struct hc_driver *driver;
struct usb_hcd *hcd;
int retval;
if (usb_disabled())
return -ENODEV;
if (!id)
return -EINVAL;
driver = (struct hc_driver *)id->driver_data;
if (!driver)
return -EINVAL;
if (pci_enable_device(dev) < 0)
return -ENODEV;
dev->current_state = PCI_D0;
if (!dev->irq) {
dev_err(&dev->dev,
"Found HC with no IRQ. Check BIOS/PCI %s setup!\n",
pci_name(dev));
retval = -ENODEV;
goto disable_pci;
}
hcd = usb_create_hcd(driver, &dev->dev, pci_name(dev));
if (!hcd) {
retval = -ENOMEM;
goto disable_pci;
}
if (driver->flags & HCD_MEMORY) {
hcd->rsrc_start = pci_resource_start(dev, 0);
hcd->rsrc_len = pci_resource_len(dev, 0);
if (!request_mem_region(hcd->rsrc_start, hcd->rsrc_len,
driver->description)) {
dev_dbg(&dev->dev, "controller already in use\n");
retval = -EBUSY;
goto clear_companion;
}
hcd->regs = ioremap_nocache(hcd->rsrc_start, hcd->rsrc_len);
if (hcd->regs == NULL) {
dev_dbg(&dev->dev, "error mapping memory\n");
retval = -EFAULT;
goto release_mem_region;
}
} else {
int region;
for (region = 0; region < PCI_ROM_RESOURCE; region++) {
if (!(pci_resource_flags(dev, region) &
IORESOURCE_IO))
continue;
hcd->rsrc_start = pci_resource_start(dev, region);
hcd->rsrc_len = pci_resource_len(dev, region);
if (request_region(hcd->rsrc_start, hcd->rsrc_len,
driver->description))
break;
}
if (region == PCI_ROM_RESOURCE) {
dev_dbg(&dev->dev, "no i/o regions available\n");
retval = -EBUSY;
goto clear_companion;
}
}
pci_set_master(dev);
retval = usb_add_hcd(hcd, dev->irq, IRQF_SHARED);
if (retval != 0)
goto unmap_registers;
set_hs_companion(dev, hcd);
if (pci_dev_run_wake(dev))
pm_runtime_put_noidle(&dev->dev);
return retval;
unmap_registers:
if (driver->flags & HCD_MEMORY) {
iounmap(hcd->regs);
release_mem_region:
release_mem_region(hcd->rsrc_start, hcd->rsrc_len);
} else
release_region(hcd->rsrc_start, hcd->rsrc_len);
clear_companion:
clear_hs_companion(dev, hcd);
usb_put_hcd(hcd);
disable_pci:
pci_disable_device(dev);
dev_err(&dev->dev, "init %s fail, %d\n", pci_name(dev), retval);
return retval;
}
void usb_hcd_pci_remove(struct pci_dev *dev)
{
struct usb_hcd *hcd;
hcd = pci_get_drvdata(dev);
if (!hcd)
return;
if (pci_dev_run_wake(dev))
pm_runtime_get_noresume(&dev->dev);
local_irq_disable();
usb_hcd_irq(0, hcd);
local_irq_enable();
usb_remove_hcd(hcd);
if (hcd->driver->flags & HCD_MEMORY) {
iounmap(hcd->regs);
release_mem_region(hcd->rsrc_start, hcd->rsrc_len);
} else {
release_region(hcd->rsrc_start, hcd->rsrc_len);
}
clear_hs_companion(dev, hcd);
usb_put_hcd(hcd);
pci_disable_device(dev);
}
void usb_hcd_pci_shutdown(struct pci_dev *dev)
{
struct usb_hcd *hcd;
hcd = pci_get_drvdata(dev);
if (!hcd)
return;
if (test_bit(HCD_FLAG_HW_ACCESSIBLE, &hcd->flags) &&
hcd->driver->shutdown) {
hcd->driver->shutdown(hcd);
pci_disable_device(dev);
}
}
static void powermac_set_asic(struct pci_dev *pci_dev, int enable)
{
if (machine_is(powermac)) {
struct device_node *of_node;
of_node = pci_device_to_OF_node(pci_dev);
if (of_node)
pmac_call_feature(PMAC_FTR_USB_ENABLE,
of_node, 0, enable);
}
}
static inline void powermac_set_asic(struct pci_dev *pci_dev, int enable)
{}
static int check_root_hub_suspended(struct device *dev)
{
struct pci_dev *pci_dev = to_pci_dev(dev);
struct usb_hcd *hcd = pci_get_drvdata(pci_dev);
if (HCD_RH_RUNNING(hcd)) {
dev_warn(dev, "Root hub is not suspended\n");
return -EBUSY;
}
if (hcd->shared_hcd) {
hcd = hcd->shared_hcd;
if (HCD_RH_RUNNING(hcd)) {
dev_warn(dev, "Secondary root hub is not suspended\n");
return -EBUSY;
}
}
return 0;
}
static int suspend_common(struct device *dev, bool do_wakeup)
{
struct pci_dev *pci_dev = to_pci_dev(dev);
struct usb_hcd *hcd = pci_get_drvdata(pci_dev);
int retval;
retval = check_root_hub_suspended(dev);
if (retval)
return retval;
if (hcd->driver->pci_suspend && !HCD_DEAD(hcd)) {
if (do_wakeup && HCD_WAKEUP_PENDING(hcd))
return -EBUSY;
if (do_wakeup && hcd->shared_hcd &&
HCD_WAKEUP_PENDING(hcd->shared_hcd))
return -EBUSY;
retval = hcd->driver->pci_suspend(hcd, do_wakeup);
suspend_report_result(hcd->driver->pci_suspend, retval);
if ((retval == 0 && do_wakeup && HCD_WAKEUP_PENDING(hcd)) ||
(retval == 0 && do_wakeup && hcd->shared_hcd &&
HCD_WAKEUP_PENDING(hcd->shared_hcd))) {
if (hcd->driver->pci_resume)
hcd->driver->pci_resume(hcd, false);
retval = -EBUSY;
}
if (retval)
return retval;
}
if (!hcd->msix_enabled)
synchronize_irq(pci_dev->irq);
pci_disable_device(pci_dev);
return retval;
}
static int resume_common(struct device *dev, int event)
{
struct pci_dev *pci_dev = to_pci_dev(dev);
struct usb_hcd *hcd = pci_get_drvdata(pci_dev);
int retval;
if (HCD_RH_RUNNING(hcd) ||
(hcd->shared_hcd &&
HCD_RH_RUNNING(hcd->shared_hcd))) {
dev_dbg(dev, "can't resume, not suspended!\n");
return 0;
}
retval = pci_enable_device(pci_dev);
if (retval < 0) {
dev_err(dev, "can't re-enable after resume, %d!\n", retval);
return retval;
}
pci_set_master(pci_dev);
clear_bit(HCD_FLAG_SAW_IRQ, &hcd->flags);
if (hcd->shared_hcd)
clear_bit(HCD_FLAG_SAW_IRQ, &hcd->shared_hcd->flags);
if (hcd->driver->pci_resume && !HCD_DEAD(hcd)) {
if (event != PM_EVENT_AUTO_RESUME)
wait_for_companions(pci_dev, hcd);
retval = hcd->driver->pci_resume(hcd,
event == PM_EVENT_RESTORE);
if (retval) {
dev_err(dev, "PCI post-resume error %d!\n", retval);
if (hcd->shared_hcd)
usb_hc_died(hcd->shared_hcd);
usb_hc_died(hcd);
}
}
return retval;
}
static int hcd_pci_suspend(struct device *dev)
{
return suspend_common(dev, device_may_wakeup(dev));
}
static int hcd_pci_suspend_noirq(struct device *dev)
{
struct pci_dev *pci_dev = to_pci_dev(dev);
struct usb_hcd *hcd = pci_get_drvdata(pci_dev);
int retval;
retval = check_root_hub_suspended(dev);
if (retval)
return retval;
pci_save_state(pci_dev);
if (HCD_DEAD(hcd))
device_set_wakeup_enable(dev, 0);
dev_dbg(dev, "wakeup: %d\n", device_may_wakeup(dev));
retval = pci_prepare_to_sleep(pci_dev);
if (retval == -EIO) {
dev_dbg(dev, "--> PCI D0 legacy\n");
retval = 0;
} else if (retval == 0) {
dev_dbg(dev, "--> PCI %s\n",
pci_power_name(pci_dev->current_state));
} else {
suspend_report_result(pci_prepare_to_sleep, retval);
return retval;
}
powermac_set_asic(pci_dev, 0);
return retval;
}
static int hcd_pci_resume_noirq(struct device *dev)
{
struct pci_dev *pci_dev = to_pci_dev(dev);
powermac_set_asic(pci_dev, 1);
pci_back_from_sleep(pci_dev);
return 0;
}
static int hcd_pci_resume(struct device *dev)
{
return resume_common(dev, PM_EVENT_RESUME);
}
static int hcd_pci_restore(struct device *dev)
{
return resume_common(dev, PM_EVENT_RESTORE);
}
static int hcd_pci_runtime_suspend(struct device *dev)
{
int retval;
retval = suspend_common(dev, true);
if (retval == 0)
powermac_set_asic(to_pci_dev(dev), 0);
dev_dbg(dev, "hcd_pci_runtime_suspend: %d\n", retval);
return retval;
}
static int hcd_pci_runtime_resume(struct device *dev)
{
int retval;
powermac_set_asic(to_pci_dev(dev), 1);
retval = resume_common(dev, PM_EVENT_AUTO_RESUME);
dev_dbg(dev, "hcd_pci_runtime_resume: %d\n", retval);
return retval;
}
