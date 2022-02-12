static struct pcistub_device *pcistub_device_alloc(struct pci_dev *dev)
{
struct pcistub_device *psdev;
dev_dbg(&dev->dev, "pcistub_device_alloc\n");
psdev = kzalloc(sizeof(*psdev), GFP_ATOMIC);
if (!psdev)
return NULL;
psdev->dev = pci_dev_get(dev);
if (!psdev->dev) {
kfree(psdev);
return NULL;
}
kref_init(&psdev->kref);
spin_lock_init(&psdev->lock);
return psdev;
}
static void pcistub_device_release(struct kref *kref)
{
struct pcistub_device *psdev;
struct pci_dev *dev;
struct xen_pcibk_dev_data *dev_data;
psdev = container_of(kref, struct pcistub_device, kref);
dev = psdev->dev;
dev_data = pci_get_drvdata(dev);
dev_dbg(&dev->dev, "pcistub_device_release\n");
xen_unregister_device_domain_owner(dev);
__pci_reset_function_locked(dev);
if (pci_load_and_free_saved_state(dev, &dev_data->pci_saved_state))
dev_info(&dev->dev, "Could not reload PCI state\n");
else
pci_restore_state(dev);
if (dev->msix_cap) {
struct physdev_pci_device ppdev = {
.seg = pci_domain_nr(dev->bus),
.bus = dev->bus->number,
.devfn = dev->devfn
};
int err = HYPERVISOR_physdev_op(PHYSDEVOP_release_msix,
&ppdev);
if (err)
dev_warn(&dev->dev, "MSI-X release failed (%d)\n",
err);
}
xen_pcibk_reset_device(dev);
kfree(dev_data);
pci_set_drvdata(dev, NULL);
xen_pcibk_config_free_dyn_fields(dev);
xen_pcibk_config_free_dev(dev);
pci_clear_dev_assigned(dev);
pci_dev_put(dev);
kfree(psdev);
}
static inline void pcistub_device_get(struct pcistub_device *psdev)
{
kref_get(&psdev->kref);
}
static inline void pcistub_device_put(struct pcistub_device *psdev)
{
kref_put(&psdev->kref, pcistub_device_release);
}
static struct pcistub_device *pcistub_device_find(int domain, int bus,
int slot, int func)
{
struct pcistub_device *psdev = NULL;
unsigned long flags;
spin_lock_irqsave(&pcistub_devices_lock, flags);
list_for_each_entry(psdev, &pcistub_devices, dev_list) {
if (psdev->dev != NULL
&& domain == pci_domain_nr(psdev->dev->bus)
&& bus == psdev->dev->bus->number
&& slot == PCI_SLOT(psdev->dev->devfn)
&& func == PCI_FUNC(psdev->dev->devfn)) {
pcistub_device_get(psdev);
goto out;
}
}
psdev = NULL;
out:
spin_unlock_irqrestore(&pcistub_devices_lock, flags);
return psdev;
}
static struct pci_dev *pcistub_device_get_pci_dev(struct xen_pcibk_device *pdev,
struct pcistub_device *psdev)
{
struct pci_dev *pci_dev = NULL;
unsigned long flags;
pcistub_device_get(psdev);
spin_lock_irqsave(&psdev->lock, flags);
if (!psdev->pdev) {
psdev->pdev = pdev;
pci_dev = psdev->dev;
}
spin_unlock_irqrestore(&psdev->lock, flags);
if (!pci_dev)
pcistub_device_put(psdev);
return pci_dev;
}
struct pci_dev *pcistub_get_pci_dev_by_slot(struct xen_pcibk_device *pdev,
int domain, int bus,
int slot, int func)
{
struct pcistub_device *psdev;
struct pci_dev *found_dev = NULL;
unsigned long flags;
spin_lock_irqsave(&pcistub_devices_lock, flags);
list_for_each_entry(psdev, &pcistub_devices, dev_list) {
if (psdev->dev != NULL
&& domain == pci_domain_nr(psdev->dev->bus)
&& bus == psdev->dev->bus->number
&& slot == PCI_SLOT(psdev->dev->devfn)
&& func == PCI_FUNC(psdev->dev->devfn)) {
found_dev = pcistub_device_get_pci_dev(pdev, psdev);
break;
}
}
spin_unlock_irqrestore(&pcistub_devices_lock, flags);
return found_dev;
}
struct pci_dev *pcistub_get_pci_dev(struct xen_pcibk_device *pdev,
struct pci_dev *dev)
{
struct pcistub_device *psdev;
struct pci_dev *found_dev = NULL;
unsigned long flags;
spin_lock_irqsave(&pcistub_devices_lock, flags);
list_for_each_entry(psdev, &pcistub_devices, dev_list) {
if (psdev->dev == dev) {
found_dev = pcistub_device_get_pci_dev(pdev, psdev);
break;
}
}
spin_unlock_irqrestore(&pcistub_devices_lock, flags);
return found_dev;
}
void pcistub_put_pci_dev(struct pci_dev *dev)
{
struct pcistub_device *psdev, *found_psdev = NULL;
unsigned long flags;
struct xen_pcibk_dev_data *dev_data;
int ret;
spin_lock_irqsave(&pcistub_devices_lock, flags);
list_for_each_entry(psdev, &pcistub_devices, dev_list) {
if (psdev->dev == dev) {
found_psdev = psdev;
break;
}
}
spin_unlock_irqrestore(&pcistub_devices_lock, flags);
if (WARN_ON(!found_psdev))
return;
down_write(&pcistub_sem);
device_lock_assert(&dev->dev);
__pci_reset_function_locked(dev);
dev_data = pci_get_drvdata(dev);
ret = pci_load_saved_state(dev, dev_data->pci_saved_state);
if (!ret) {
pci_restore_state(dev);
} else
dev_info(&dev->dev, "Could not reload PCI state\n");
xen_pcibk_reset_device(dev);
xen_pcibk_config_reset_dev(dev);
xen_pcibk_config_free_dyn_fields(dev);
xen_unregister_device_domain_owner(dev);
spin_lock_irqsave(&found_psdev->lock, flags);
found_psdev->pdev = NULL;
spin_unlock_irqrestore(&found_psdev->lock, flags);
pcistub_device_put(found_psdev);
up_write(&pcistub_sem);
}
static int pcistub_match_one(struct pci_dev *dev,
struct pcistub_device_id *pdev_id)
{
for (; dev != NULL; dev = dev->bus->self) {
if (pci_domain_nr(dev->bus) == pdev_id->domain
&& dev->bus->number == pdev_id->bus
&& dev->devfn == pdev_id->devfn)
return 1;
if (dev == dev->bus->self)
break;
}
return 0;
}
static int pcistub_match(struct pci_dev *dev)
{
struct pcistub_device_id *pdev_id;
unsigned long flags;
int found = 0;
spin_lock_irqsave(&device_ids_lock, flags);
list_for_each_entry(pdev_id, &pcistub_device_ids, slot_list) {
if (pcistub_match_one(dev, pdev_id)) {
found = 1;
break;
}
}
spin_unlock_irqrestore(&device_ids_lock, flags);
return found;
}
static int pcistub_init_device(struct pci_dev *dev)
{
struct xen_pcibk_dev_data *dev_data;
int err = 0;
dev_dbg(&dev->dev, "initializing...\n");
dev_data = kzalloc(sizeof(*dev_data) + strlen(DRV_NAME "[]")
+ strlen(pci_name(dev)) + 1, GFP_ATOMIC);
if (!dev_data) {
err = -ENOMEM;
goto out;
}
pci_set_drvdata(dev, dev_data);
sprintf(dev_data->irq_name, DRV_NAME "[%s]", pci_name(dev));
dev_dbg(&dev->dev, "initializing config\n");
init_waitqueue_head(&xen_pcibk_aer_wait_queue);
err = xen_pcibk_config_init_dev(dev);
if (err)
goto out;
dev_dbg(&dev->dev, "enabling device\n");
err = pci_enable_device(dev);
if (err)
goto config_release;
if (dev->msix_cap) {
struct physdev_pci_device ppdev = {
.seg = pci_domain_nr(dev->bus),
.bus = dev->bus->number,
.devfn = dev->devfn
};
err = HYPERVISOR_physdev_op(PHYSDEVOP_prepare_msix, &ppdev);
if (err)
dev_err(&dev->dev, "MSI-X preparation failed (%d)\n",
err);
}
dev_dbg(&dev->dev, "save state of device\n");
pci_save_state(dev);
dev_data->pci_saved_state = pci_store_saved_state(dev);
if (!dev_data->pci_saved_state)
dev_err(&dev->dev, "Could not store PCI conf saved state!\n");
else {
dev_dbg(&dev->dev, "resetting (FLR, D3, etc) the device\n");
__pci_reset_function_locked(dev);
pci_restore_state(dev);
}
dev_dbg(&dev->dev, "reset device\n");
xen_pcibk_reset_device(dev);
pci_set_dev_assigned(dev);
return 0;
config_release:
xen_pcibk_config_free_dev(dev);
out:
pci_set_drvdata(dev, NULL);
kfree(dev_data);
return err;
}
static int __init pcistub_init_devices_late(void)
{
struct pcistub_device *psdev;
unsigned long flags;
int err = 0;
spin_lock_irqsave(&pcistub_devices_lock, flags);
while (!list_empty(&seized_devices)) {
psdev = container_of(seized_devices.next,
struct pcistub_device, dev_list);
list_del(&psdev->dev_list);
spin_unlock_irqrestore(&pcistub_devices_lock, flags);
err = pcistub_init_device(psdev->dev);
if (err) {
dev_err(&psdev->dev->dev,
"error %d initializing device\n", err);
kfree(psdev);
psdev = NULL;
}
spin_lock_irqsave(&pcistub_devices_lock, flags);
if (psdev)
list_add_tail(&psdev->dev_list, &pcistub_devices);
}
initialize_devices = 1;
spin_unlock_irqrestore(&pcistub_devices_lock, flags);
return 0;
}
static int pcistub_seize(struct pci_dev *dev)
{
struct pcistub_device *psdev;
unsigned long flags;
int err = 0;
psdev = pcistub_device_alloc(dev);
if (!psdev)
return -ENOMEM;
spin_lock_irqsave(&pcistub_devices_lock, flags);
if (initialize_devices) {
spin_unlock_irqrestore(&pcistub_devices_lock, flags);
err = pcistub_init_device(psdev->dev);
spin_lock_irqsave(&pcistub_devices_lock, flags);
if (!err)
list_add(&psdev->dev_list, &pcistub_devices);
} else {
dev_dbg(&dev->dev, "deferring initialization\n");
list_add(&psdev->dev_list, &seized_devices);
}
spin_unlock_irqrestore(&pcistub_devices_lock, flags);
if (err)
pcistub_device_put(psdev);
return err;
}
static int pcistub_probe(struct pci_dev *dev, const struct pci_device_id *id)
{
int err = 0;
dev_dbg(&dev->dev, "probing...\n");
if (pcistub_match(dev)) {
if (dev->hdr_type != PCI_HEADER_TYPE_NORMAL
&& dev->hdr_type != PCI_HEADER_TYPE_BRIDGE) {
dev_err(&dev->dev, "can't export pci devices that "
"don't have a normal (0) or bridge (1) "
"header type!\n");
err = -ENODEV;
goto out;
}
dev_info(&dev->dev, "seizing device\n");
err = pcistub_seize(dev);
} else
err = -ENODEV;
out:
return err;
}
static void pcistub_remove(struct pci_dev *dev)
{
struct pcistub_device *psdev, *found_psdev = NULL;
unsigned long flags;
dev_dbg(&dev->dev, "removing\n");
spin_lock_irqsave(&pcistub_devices_lock, flags);
xen_pcibk_config_quirk_release(dev);
list_for_each_entry(psdev, &pcistub_devices, dev_list) {
if (psdev->dev == dev) {
found_psdev = psdev;
break;
}
}
spin_unlock_irqrestore(&pcistub_devices_lock, flags);
if (found_psdev) {
dev_dbg(&dev->dev, "found device to remove %s\n",
found_psdev->pdev ? "- in-use" : "");
if (found_psdev->pdev) {
int domid = xen_find_device_domain_owner(dev);
pr_warn("****** removing device %s while still in-use by domain %d! ******\n",
pci_name(found_psdev->dev), domid);
pr_warn("****** driver domain may still access this device's i/o resources!\n");
pr_warn("****** shutdown driver domain before binding device\n");
pr_warn("****** to other drivers or domains\n");
xen_pcibk_release_pci_dev(found_psdev->pdev,
found_psdev->dev,
false );
}
spin_lock_irqsave(&pcistub_devices_lock, flags);
list_del(&found_psdev->dev_list);
spin_unlock_irqrestore(&pcistub_devices_lock, flags);
pcistub_device_put(found_psdev);
}
}
static void kill_domain_by_device(struct pcistub_device *psdev)
{
struct xenbus_transaction xbt;
int err;
char nodename[PCI_NODENAME_MAX];
BUG_ON(!psdev);
snprintf(nodename, PCI_NODENAME_MAX, "/local/domain/0/backend/pci/%d/0",
psdev->pdev->xdev->otherend_id);
again:
err = xenbus_transaction_start(&xbt);
if (err) {
dev_err(&psdev->dev->dev,
"error %d when start xenbus transaction\n", err);
return;
}
xenbus_printf(xbt, nodename, "aerState" , "aerfail");
err = xenbus_transaction_end(xbt, 0);
if (err) {
if (err == -EAGAIN)
goto again;
dev_err(&psdev->dev->dev,
"error %d when end xenbus transaction\n", err);
return;
}
}
static pci_ers_result_t common_process(struct pcistub_device *psdev,
pci_channel_state_t state, int aer_cmd,
pci_ers_result_t result)
{
pci_ers_result_t res = result;
struct xen_pcie_aer_op *aer_op;
struct xen_pcibk_device *pdev = psdev->pdev;
struct xen_pci_sharedinfo *sh_info = pdev->sh_info;
int ret;
aer_op = &(sh_info->aer_op);
aer_op->cmd = aer_cmd ;
aer_op->err = state;
ret = xen_pcibk_get_pcifront_dev(psdev->dev, psdev->pdev,
&aer_op->domain, &aer_op->bus, &aer_op->devfn);
if (!ret) {
dev_err(&psdev->dev->dev,
DRV_NAME ": failed to get pcifront device\n");
return PCI_ERS_RESULT_NONE;
}
wmb();
dev_dbg(&psdev->dev->dev,
DRV_NAME ": aer_op %x dom %x bus %x devfn %x\n",
aer_cmd, aer_op->domain, aer_op->bus, aer_op->devfn);
set_bit(_PCIB_op_pending, (unsigned long *)&pdev->flags);
set_bit(_XEN_PCIB_active,
(unsigned long *)&sh_info->flags);
wmb();
notify_remote_via_irq(pdev->evtchn_irq);
ret = wait_event_timeout(xen_pcibk_aer_wait_queue,
!(test_bit(_XEN_PCIB_active, (unsigned long *)
&sh_info->flags)), 300*HZ);
if (!ret) {
if (test_bit(_XEN_PCIB_active,
(unsigned long *)&sh_info->flags)) {
dev_err(&psdev->dev->dev,
"pcifront aer process not responding!\n");
clear_bit(_XEN_PCIB_active,
(unsigned long *)&sh_info->flags);
aer_op->err = PCI_ERS_RESULT_NONE;
return res;
}
}
clear_bit(_PCIB_op_pending, (unsigned long *)&pdev->flags);
if (test_bit(_XEN_PCIF_active,
(unsigned long *)&sh_info->flags)) {
dev_dbg(&psdev->dev->dev,
"schedule pci_conf service in " DRV_NAME "\n");
xen_pcibk_test_and_schedule_op(psdev->pdev);
}
res = (pci_ers_result_t)aer_op->err;
return res;
}
static pci_ers_result_t xen_pcibk_slot_reset(struct pci_dev *dev)
{
struct pcistub_device *psdev;
pci_ers_result_t result;
result = PCI_ERS_RESULT_RECOVERED;
dev_dbg(&dev->dev, "xen_pcibk_slot_reset(bus:%x,devfn:%x)\n",
dev->bus->number, dev->devfn);
down_write(&pcistub_sem);
psdev = pcistub_device_find(pci_domain_nr(dev->bus),
dev->bus->number,
PCI_SLOT(dev->devfn),
PCI_FUNC(dev->devfn));
if (!psdev || !psdev->pdev) {
dev_err(&dev->dev,
DRV_NAME " device is not found/assigned\n");
goto end;
}
if (!psdev->pdev->sh_info) {
dev_err(&dev->dev, DRV_NAME " device is not connected or owned"
" by HVM, kill it\n");
kill_domain_by_device(psdev);
goto end;
}
if (!test_bit(_XEN_PCIB_AERHANDLER,
(unsigned long *)&psdev->pdev->sh_info->flags)) {
dev_err(&dev->dev,
"guest with no AER driver should have been killed\n");
goto end;
}
result = common_process(psdev, 1, XEN_PCI_OP_aer_slotreset, result);
if (result == PCI_ERS_RESULT_NONE ||
result == PCI_ERS_RESULT_DISCONNECT) {
dev_dbg(&dev->dev,
"No AER slot_reset service or disconnected!\n");
kill_domain_by_device(psdev);
}
end:
if (psdev)
pcistub_device_put(psdev);
up_write(&pcistub_sem);
return result;
}
static pci_ers_result_t xen_pcibk_mmio_enabled(struct pci_dev *dev)
{
struct pcistub_device *psdev;
pci_ers_result_t result;
result = PCI_ERS_RESULT_RECOVERED;
dev_dbg(&dev->dev, "xen_pcibk_mmio_enabled(bus:%x,devfn:%x)\n",
dev->bus->number, dev->devfn);
down_write(&pcistub_sem);
psdev = pcistub_device_find(pci_domain_nr(dev->bus),
dev->bus->number,
PCI_SLOT(dev->devfn),
PCI_FUNC(dev->devfn));
if (!psdev || !psdev->pdev) {
dev_err(&dev->dev,
DRV_NAME " device is not found/assigned\n");
goto end;
}
if (!psdev->pdev->sh_info) {
dev_err(&dev->dev, DRV_NAME " device is not connected or owned"
" by HVM, kill it\n");
kill_domain_by_device(psdev);
goto end;
}
if (!test_bit(_XEN_PCIB_AERHANDLER,
(unsigned long *)&psdev->pdev->sh_info->flags)) {
dev_err(&dev->dev,
"guest with no AER driver should have been killed\n");
goto end;
}
result = common_process(psdev, 1, XEN_PCI_OP_aer_mmio, result);
if (result == PCI_ERS_RESULT_NONE ||
result == PCI_ERS_RESULT_DISCONNECT) {
dev_dbg(&dev->dev,
"No AER mmio_enabled service or disconnected!\n");
kill_domain_by_device(psdev);
}
end:
if (psdev)
pcistub_device_put(psdev);
up_write(&pcistub_sem);
return result;
}
static pci_ers_result_t xen_pcibk_error_detected(struct pci_dev *dev,
pci_channel_state_t error)
{
struct pcistub_device *psdev;
pci_ers_result_t result;
result = PCI_ERS_RESULT_CAN_RECOVER;
dev_dbg(&dev->dev, "xen_pcibk_error_detected(bus:%x,devfn:%x)\n",
dev->bus->number, dev->devfn);
down_write(&pcistub_sem);
psdev = pcistub_device_find(pci_domain_nr(dev->bus),
dev->bus->number,
PCI_SLOT(dev->devfn),
PCI_FUNC(dev->devfn));
if (!psdev || !psdev->pdev) {
dev_err(&dev->dev,
DRV_NAME " device is not found/assigned\n");
goto end;
}
if (!psdev->pdev->sh_info) {
dev_err(&dev->dev, DRV_NAME " device is not connected or owned"
" by HVM, kill it\n");
kill_domain_by_device(psdev);
goto end;
}
if (!test_bit(_XEN_PCIB_AERHANDLER,
(unsigned long *)&psdev->pdev->sh_info->flags)) {
dev_dbg(&dev->dev, "guest may have no aer driver, kill it\n");
kill_domain_by_device(psdev);
goto end;
}
result = common_process(psdev, error, XEN_PCI_OP_aer_detected, result);
if (result == PCI_ERS_RESULT_NONE ||
result == PCI_ERS_RESULT_DISCONNECT) {
dev_dbg(&dev->dev,
"No AER error_detected service or disconnected!\n");
kill_domain_by_device(psdev);
}
end:
if (psdev)
pcistub_device_put(psdev);
up_write(&pcistub_sem);
return result;
}
static void xen_pcibk_error_resume(struct pci_dev *dev)
{
struct pcistub_device *psdev;
dev_dbg(&dev->dev, "xen_pcibk_error_resume(bus:%x,devfn:%x)\n",
dev->bus->number, dev->devfn);
down_write(&pcistub_sem);
psdev = pcistub_device_find(pci_domain_nr(dev->bus),
dev->bus->number,
PCI_SLOT(dev->devfn),
PCI_FUNC(dev->devfn));
if (!psdev || !psdev->pdev) {
dev_err(&dev->dev,
DRV_NAME " device is not found/assigned\n");
goto end;
}
if (!psdev->pdev->sh_info) {
dev_err(&dev->dev, DRV_NAME " device is not connected or owned"
" by HVM, kill it\n");
kill_domain_by_device(psdev);
goto end;
}
if (!test_bit(_XEN_PCIB_AERHANDLER,
(unsigned long *)&psdev->pdev->sh_info->flags)) {
dev_err(&dev->dev,
"guest with no AER driver should have been killed\n");
kill_domain_by_device(psdev);
goto end;
}
common_process(psdev, 1, XEN_PCI_OP_aer_resume,
PCI_ERS_RESULT_RECOVERED);
end:
if (psdev)
pcistub_device_put(psdev);
up_write(&pcistub_sem);
return;
}
static inline int str_to_slot(const char *buf, int *domain, int *bus,
int *slot, int *func)
{
int parsed = 0;
switch (sscanf(buf, " %x:%x:%x.%x %n", domain, bus, slot, func,
&parsed)) {
case 3:
*func = -1;
sscanf(buf, " %x:%x:%x.* %n", domain, bus, slot, &parsed);
break;
case 2:
*slot = *func = -1;
sscanf(buf, " %x:%x:*.* %n", domain, bus, &parsed);
break;
}
if (parsed && !buf[parsed])
return 0;
*domain = 0;
switch (sscanf(buf, " %x:%x.%x %n", bus, slot, func, &parsed)) {
case 2:
*func = -1;
sscanf(buf, " %x:%x.* %n", bus, slot, &parsed);
break;
case 1:
*slot = *func = -1;
sscanf(buf, " %x:*.* %n", bus, &parsed);
break;
}
if (parsed && !buf[parsed])
return 0;
return -EINVAL;
}
static inline int str_to_quirk(const char *buf, int *domain, int *bus, int
*slot, int *func, int *reg, int *size, int *mask)
{
int parsed = 0;
sscanf(buf, " %x:%x:%x.%x-%x:%x:%x %n", domain, bus, slot, func,
reg, size, mask, &parsed);
if (parsed && !buf[parsed])
return 0;
*domain = 0;
sscanf(buf, " %x:%x.%x-%x:%x:%x %n", bus, slot, func, reg, size,
mask, &parsed);
if (parsed && !buf[parsed])
return 0;
return -EINVAL;
}
static int pcistub_device_id_add(int domain, int bus, int slot, int func)
{
struct pcistub_device_id *pci_dev_id;
unsigned long flags;
int rc = 0, devfn = PCI_DEVFN(slot, func);
if (slot < 0) {
for (slot = 0; !rc && slot < 32; ++slot)
rc = pcistub_device_id_add(domain, bus, slot, func);
return rc;
}
if (func < 0) {
for (func = 0; !rc && func < 8; ++func)
rc = pcistub_device_id_add(domain, bus, slot, func);
return rc;
}
if ((
#if !defined(MODULE) \
|| !defined(CONFIG_PCI_DOMAINS)
!pci_domains_supported ? domain :
#endif
domain < 0 || domain > 0xffff)
|| bus < 0 || bus > 0xff
|| PCI_SLOT(devfn) != slot
|| PCI_FUNC(devfn) != func)
return -EINVAL;
pci_dev_id = kmalloc(sizeof(*pci_dev_id), GFP_KERNEL);
if (!pci_dev_id)
return -ENOMEM;
pci_dev_id->domain = domain;
pci_dev_id->bus = bus;
pci_dev_id->devfn = devfn;
pr_debug("wants to seize %04x:%02x:%02x.%d\n",
domain, bus, slot, func);
spin_lock_irqsave(&device_ids_lock, flags);
list_add_tail(&pci_dev_id->slot_list, &pcistub_device_ids);
spin_unlock_irqrestore(&device_ids_lock, flags);
return 0;
}
static int pcistub_device_id_remove(int domain, int bus, int slot, int func)
{
struct pcistub_device_id *pci_dev_id, *t;
int err = -ENOENT;
unsigned long flags;
spin_lock_irqsave(&device_ids_lock, flags);
list_for_each_entry_safe(pci_dev_id, t, &pcistub_device_ids,
slot_list) {
if (pci_dev_id->domain == domain && pci_dev_id->bus == bus
&& (slot < 0 || PCI_SLOT(pci_dev_id->devfn) == slot)
&& (func < 0 || PCI_FUNC(pci_dev_id->devfn) == func)) {
list_del(&pci_dev_id->slot_list);
kfree(pci_dev_id);
err = 0;
pr_debug("removed %04x:%02x:%02x.%d from seize list\n",
domain, bus, slot, func);
}
}
spin_unlock_irqrestore(&device_ids_lock, flags);
return err;
}
static int pcistub_reg_add(int domain, int bus, int slot, int func,
unsigned int reg, unsigned int size,
unsigned int mask)
{
int err = 0;
struct pcistub_device *psdev;
struct pci_dev *dev;
struct config_field *field;
if (reg > 0xfff || (size < 4 && (mask >> (size * 8))))
return -EINVAL;
psdev = pcistub_device_find(domain, bus, slot, func);
if (!psdev) {
err = -ENODEV;
goto out;
}
dev = psdev->dev;
field = kzalloc(sizeof(*field), GFP_ATOMIC);
if (!field) {
err = -ENOMEM;
goto out;
}
field->offset = reg;
field->size = size;
field->mask = mask;
field->init = NULL;
field->reset = NULL;
field->release = NULL;
field->clean = xen_pcibk_config_field_free;
err = xen_pcibk_config_quirks_add_field(dev, field);
if (err)
kfree(field);
out:
if (psdev)
pcistub_device_put(psdev);
return err;
}
static ssize_t pcistub_slot_add(struct device_driver *drv, const char *buf,
size_t count)
{
int domain, bus, slot, func;
int err;
err = str_to_slot(buf, &domain, &bus, &slot, &func);
if (err)
goto out;
err = pcistub_device_id_add(domain, bus, slot, func);
out:
if (!err)
err = count;
return err;
}
static ssize_t pcistub_slot_remove(struct device_driver *drv, const char *buf,
size_t count)
{
int domain, bus, slot, func;
int err;
err = str_to_slot(buf, &domain, &bus, &slot, &func);
if (err)
goto out;
err = pcistub_device_id_remove(domain, bus, slot, func);
out:
if (!err)
err = count;
return err;
}
static ssize_t pcistub_slot_show(struct device_driver *drv, char *buf)
{
struct pcistub_device_id *pci_dev_id;
size_t count = 0;
unsigned long flags;
spin_lock_irqsave(&device_ids_lock, flags);
list_for_each_entry(pci_dev_id, &pcistub_device_ids, slot_list) {
if (count >= PAGE_SIZE)
break;
count += scnprintf(buf + count, PAGE_SIZE - count,
"%04x:%02x:%02x.%d\n",
pci_dev_id->domain, pci_dev_id->bus,
PCI_SLOT(pci_dev_id->devfn),
PCI_FUNC(pci_dev_id->devfn));
}
spin_unlock_irqrestore(&device_ids_lock, flags);
return count;
}
static ssize_t pcistub_irq_handler_show(struct device_driver *drv, char *buf)
{
struct pcistub_device *psdev;
struct xen_pcibk_dev_data *dev_data;
size_t count = 0;
unsigned long flags;
spin_lock_irqsave(&pcistub_devices_lock, flags);
list_for_each_entry(psdev, &pcistub_devices, dev_list) {
if (count >= PAGE_SIZE)
break;
if (!psdev->dev)
continue;
dev_data = pci_get_drvdata(psdev->dev);
if (!dev_data)
continue;
count +=
scnprintf(buf + count, PAGE_SIZE - count,
"%s:%s:%sing:%ld\n",
pci_name(psdev->dev),
dev_data->isr_on ? "on" : "off",
dev_data->ack_intr ? "ack" : "not ack",
dev_data->handled);
}
spin_unlock_irqrestore(&pcistub_devices_lock, flags);
return count;
}
static ssize_t pcistub_irq_handler_switch(struct device_driver *drv,
const char *buf,
size_t count)
{
struct pcistub_device *psdev;
struct xen_pcibk_dev_data *dev_data;
int domain, bus, slot, func;
int err;
err = str_to_slot(buf, &domain, &bus, &slot, &func);
if (err)
return err;
psdev = pcistub_device_find(domain, bus, slot, func);
if (!psdev) {
err = -ENOENT;
goto out;
}
dev_data = pci_get_drvdata(psdev->dev);
if (!dev_data) {
err = -ENOENT;
goto out;
}
dev_dbg(&psdev->dev->dev, "%s fake irq handler: %d->%d\n",
dev_data->irq_name, dev_data->isr_on,
!dev_data->isr_on);
dev_data->isr_on = !(dev_data->isr_on);
if (dev_data->isr_on)
dev_data->ack_intr = 1;
out:
if (psdev)
pcistub_device_put(psdev);
if (!err)
err = count;
return err;
}
static ssize_t pcistub_quirk_add(struct device_driver *drv, const char *buf,
size_t count)
{
int domain, bus, slot, func, reg, size, mask;
int err;
err = str_to_quirk(buf, &domain, &bus, &slot, &func, &reg, &size,
&mask);
if (err)
goto out;
err = pcistub_reg_add(domain, bus, slot, func, reg, size, mask);
out:
if (!err)
err = count;
return err;
}
static ssize_t pcistub_quirk_show(struct device_driver *drv, char *buf)
{
int count = 0;
unsigned long flags;
struct xen_pcibk_config_quirk *quirk;
struct xen_pcibk_dev_data *dev_data;
const struct config_field *field;
const struct config_field_entry *cfg_entry;
spin_lock_irqsave(&device_ids_lock, flags);
list_for_each_entry(quirk, &xen_pcibk_quirks, quirks_list) {
if (count >= PAGE_SIZE)
goto out;
count += scnprintf(buf + count, PAGE_SIZE - count,
"%02x:%02x.%01x\n\t%04x:%04x:%04x:%04x\n",
quirk->pdev->bus->number,
PCI_SLOT(quirk->pdev->devfn),
PCI_FUNC(quirk->pdev->devfn),
quirk->devid.vendor, quirk->devid.device,
quirk->devid.subvendor,
quirk->devid.subdevice);
dev_data = pci_get_drvdata(quirk->pdev);
list_for_each_entry(cfg_entry, &dev_data->config_fields, list) {
field = cfg_entry->field;
if (count >= PAGE_SIZE)
goto out;
count += scnprintf(buf + count, PAGE_SIZE - count,
"\t\t%08x:%01x:%08x\n",
cfg_entry->base_offset +
field->offset, field->size,
field->mask);
}
}
out:
spin_unlock_irqrestore(&device_ids_lock, flags);
return count;
}
static ssize_t permissive_add(struct device_driver *drv, const char *buf,
size_t count)
{
int domain, bus, slot, func;
int err;
struct pcistub_device *psdev;
struct xen_pcibk_dev_data *dev_data;
err = str_to_slot(buf, &domain, &bus, &slot, &func);
if (err)
goto out;
psdev = pcistub_device_find(domain, bus, slot, func);
if (!psdev) {
err = -ENODEV;
goto out;
}
dev_data = pci_get_drvdata(psdev->dev);
if (!dev_data) {
err = -ENXIO;
goto release;
}
if (!dev_data->permissive) {
dev_data->permissive = 1;
dev_warn(&psdev->dev->dev, "enabling permissive mode "
"configuration space accesses!\n");
dev_warn(&psdev->dev->dev,
"permissive mode is potentially unsafe!\n");
}
release:
pcistub_device_put(psdev);
out:
if (!err)
err = count;
return err;
}
static ssize_t permissive_show(struct device_driver *drv, char *buf)
{
struct pcistub_device *psdev;
struct xen_pcibk_dev_data *dev_data;
size_t count = 0;
unsigned long flags;
spin_lock_irqsave(&pcistub_devices_lock, flags);
list_for_each_entry(psdev, &pcistub_devices, dev_list) {
if (count >= PAGE_SIZE)
break;
if (!psdev->dev)
continue;
dev_data = pci_get_drvdata(psdev->dev);
if (!dev_data || !dev_data->permissive)
continue;
count +=
scnprintf(buf + count, PAGE_SIZE - count, "%s\n",
pci_name(psdev->dev));
}
spin_unlock_irqrestore(&pcistub_devices_lock, flags);
return count;
}
static void pcistub_exit(void)
{
driver_remove_file(&xen_pcibk_pci_driver.driver, &driver_attr_new_slot);
driver_remove_file(&xen_pcibk_pci_driver.driver,
&driver_attr_remove_slot);
driver_remove_file(&xen_pcibk_pci_driver.driver, &driver_attr_slots);
driver_remove_file(&xen_pcibk_pci_driver.driver, &driver_attr_quirks);
driver_remove_file(&xen_pcibk_pci_driver.driver,
&driver_attr_permissive);
driver_remove_file(&xen_pcibk_pci_driver.driver,
&driver_attr_irq_handlers);
driver_remove_file(&xen_pcibk_pci_driver.driver,
&driver_attr_irq_handler_state);
pci_unregister_driver(&xen_pcibk_pci_driver);
}
static int __init pcistub_init(void)
{
int pos = 0;
int err = 0;
int domain, bus, slot, func;
int parsed;
if (pci_devs_to_hide && *pci_devs_to_hide) {
do {
parsed = 0;
err = sscanf(pci_devs_to_hide + pos,
" (%x:%x:%x.%x) %n",
&domain, &bus, &slot, &func, &parsed);
switch (err) {
case 3:
func = -1;
sscanf(pci_devs_to_hide + pos,
" (%x:%x:%x.*) %n",
&domain, &bus, &slot, &parsed);
break;
case 2:
slot = func = -1;
sscanf(pci_devs_to_hide + pos,
" (%x:%x:*.*) %n",
&domain, &bus, &parsed);
break;
}
if (!parsed) {
domain = 0;
err = sscanf(pci_devs_to_hide + pos,
" (%x:%x.%x) %n",
&bus, &slot, &func, &parsed);
switch (err) {
case 2:
func = -1;
sscanf(pci_devs_to_hide + pos,
" (%x:%x.*) %n",
&bus, &slot, &parsed);
break;
case 1:
slot = func = -1;
sscanf(pci_devs_to_hide + pos,
" (%x:*.*) %n",
&bus, &parsed);
break;
}
}
if (parsed <= 0)
goto parse_error;
err = pcistub_device_id_add(domain, bus, slot, func);
if (err)
goto out;
pos += parsed;
} while (pci_devs_to_hide[pos]);
}
err = pci_register_driver(&xen_pcibk_pci_driver);
if (err < 0)
goto out;
err = driver_create_file(&xen_pcibk_pci_driver.driver,
&driver_attr_new_slot);
if (!err)
err = driver_create_file(&xen_pcibk_pci_driver.driver,
&driver_attr_remove_slot);
if (!err)
err = driver_create_file(&xen_pcibk_pci_driver.driver,
&driver_attr_slots);
if (!err)
err = driver_create_file(&xen_pcibk_pci_driver.driver,
&driver_attr_quirks);
if (!err)
err = driver_create_file(&xen_pcibk_pci_driver.driver,
&driver_attr_permissive);
if (!err)
err = driver_create_file(&xen_pcibk_pci_driver.driver,
&driver_attr_irq_handlers);
if (!err)
err = driver_create_file(&xen_pcibk_pci_driver.driver,
&driver_attr_irq_handler_state);
if (err)
pcistub_exit();
out:
return err;
parse_error:
pr_err("Error parsing pci_devs_to_hide at \"%s\"\n",
pci_devs_to_hide + pos);
return -EINVAL;
}
static struct pcistub_device *find_vfs(const struct pci_dev *pdev)
{
struct pcistub_device *psdev = NULL;
unsigned long flags;
bool found = false;
spin_lock_irqsave(&pcistub_devices_lock, flags);
list_for_each_entry(psdev, &pcistub_devices, dev_list) {
if (!psdev->pdev && psdev->dev != pdev
&& pci_physfn(psdev->dev) == pdev) {
found = true;
break;
}
}
spin_unlock_irqrestore(&pcistub_devices_lock, flags);
if (found)
return psdev;
return NULL;
}
static int pci_stub_notifier(struct notifier_block *nb,
unsigned long action, void *data)
{
struct device *dev = data;
const struct pci_dev *pdev = to_pci_dev(dev);
if (action != BUS_NOTIFY_UNBIND_DRIVER)
return NOTIFY_DONE;
if (!pdev->is_physfn)
return NOTIFY_DONE;
for (;;) {
struct pcistub_device *psdev = find_vfs(pdev);
if (!psdev)
break;
device_release_driver(&psdev->dev->dev);
}
return NOTIFY_DONE;
}
static int __init xen_pcibk_init(void)
{
int err;
if (!xen_initial_domain())
return -ENODEV;
err = xen_pcibk_config_init();
if (err)
return err;
#ifdef MODULE
err = pcistub_init();
if (err < 0)
return err;
#endif
pcistub_init_devices_late();
err = xen_pcibk_xenbus_register();
if (err)
pcistub_exit();
#ifdef CONFIG_PCI_IOV
else
bus_register_notifier(&pci_bus_type, &pci_stub_nb);
#endif
return err;
}
static void __exit xen_pcibk_cleanup(void)
{
#ifdef CONFIG_PCI_IOV
bus_unregister_notifier(&pci_bus_type, &pci_stub_nb);
#endif
xen_pcibk_xenbus_unregister();
pcistub_exit();
}
