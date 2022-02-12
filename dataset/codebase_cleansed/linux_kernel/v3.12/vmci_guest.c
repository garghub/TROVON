bool vmci_guest_code_active(void)
{
return atomic_read(&vmci_num_guest_devices) != 0;
}
u32 vmci_get_vm_context_id(void)
{
if (vm_context_id == VMCI_INVALID_ID) {
struct vmci_datagram get_cid_msg;
get_cid_msg.dst =
vmci_make_handle(VMCI_HYPERVISOR_CONTEXT_ID,
VMCI_GET_CONTEXT_ID);
get_cid_msg.src = VMCI_ANON_SRC_HANDLE;
get_cid_msg.payload_size = 0;
vm_context_id = vmci_send_datagram(&get_cid_msg);
}
return vm_context_id;
}
int vmci_send_datagram(struct vmci_datagram *dg)
{
unsigned long flags;
int result;
if (dg == NULL)
return VMCI_ERROR_INVALID_ARGS;
spin_lock_irqsave(&vmci_dev_spinlock, flags);
if (vmci_dev_g) {
iowrite8_rep(vmci_dev_g->iobase + VMCI_DATA_OUT_ADDR,
dg, VMCI_DG_SIZE(dg));
result = ioread32(vmci_dev_g->iobase + VMCI_RESULT_LOW_ADDR);
} else {
result = VMCI_ERROR_UNAVAILABLE;
}
spin_unlock_irqrestore(&vmci_dev_spinlock, flags);
return result;
}
static void vmci_guest_cid_update(u32 sub_id,
const struct vmci_event_data *event_data,
void *client_data)
{
const struct vmci_event_payld_ctx *ev_payload =
vmci_event_data_const_payload(event_data);
if (sub_id != ctx_update_sub_id) {
pr_devel("Invalid subscriber (ID=0x%x)\n", sub_id);
return;
}
if (!event_data || ev_payload->context_id == VMCI_INVALID_ID) {
pr_devel("Invalid event data\n");
return;
}
pr_devel("Updating context from (ID=0x%x) to (ID=0x%x) on event (type=%d)\n",
vm_context_id, ev_payload->context_id, event_data->event);
vm_context_id = ev_payload->context_id;
}
static bool vmci_check_host_caps(struct pci_dev *pdev)
{
bool result;
struct vmci_resource_query_msg *msg;
u32 msg_size = sizeof(struct vmci_resource_query_hdr) +
VMCI_UTIL_NUM_RESOURCES * sizeof(u32);
struct vmci_datagram *check_msg;
check_msg = kmalloc(msg_size, GFP_KERNEL);
if (!check_msg) {
dev_err(&pdev->dev, "%s: Insufficient memory\n", __func__);
return false;
}
check_msg->dst = vmci_make_handle(VMCI_HYPERVISOR_CONTEXT_ID,
VMCI_RESOURCES_QUERY);
check_msg->src = VMCI_ANON_SRC_HANDLE;
check_msg->payload_size = msg_size - VMCI_DG_HEADERSIZE;
msg = (struct vmci_resource_query_msg *)VMCI_DG_PAYLOAD(check_msg);
msg->num_resources = VMCI_UTIL_NUM_RESOURCES;
msg->resources[0] = VMCI_GET_CONTEXT_ID;
result = vmci_send_datagram(check_msg) == 0x01;
kfree(check_msg);
dev_dbg(&pdev->dev, "%s: Host capability check: %s\n",
__func__, result ? "PASSED" : "FAILED");
return result;
}
static void vmci_dispatch_dgs(unsigned long data)
{
struct vmci_guest_device *vmci_dev = (struct vmci_guest_device *)data;
u8 *dg_in_buffer = vmci_dev->data_buffer;
struct vmci_datagram *dg;
size_t dg_in_buffer_size = VMCI_MAX_DG_SIZE;
size_t current_dg_in_buffer_size = PAGE_SIZE;
size_t remaining_bytes;
BUILD_BUG_ON(VMCI_MAX_DG_SIZE < PAGE_SIZE);
ioread8_rep(vmci_dev->iobase + VMCI_DATA_IN_ADDR,
vmci_dev->data_buffer, current_dg_in_buffer_size);
dg = (struct vmci_datagram *)dg_in_buffer;
remaining_bytes = current_dg_in_buffer_size;
while (dg->dst.resource != VMCI_INVALID_ID ||
remaining_bytes > PAGE_SIZE) {
unsigned dg_in_size;
if (dg->dst.resource == VMCI_INVALID_ID) {
dg = (struct vmci_datagram *)roundup(
(uintptr_t)dg + 1, PAGE_SIZE);
remaining_bytes =
(size_t)(dg_in_buffer +
current_dg_in_buffer_size -
(u8 *)dg);
continue;
}
dg_in_size = VMCI_DG_SIZE_ALIGNED(dg);
if (dg_in_size <= dg_in_buffer_size) {
int result;
if (dg_in_size > remaining_bytes) {
if (remaining_bytes !=
current_dg_in_buffer_size) {
memmove(dg_in_buffer, dg_in_buffer +
current_dg_in_buffer_size -
remaining_bytes,
remaining_bytes);
dg = (struct vmci_datagram *)
dg_in_buffer;
}
if (current_dg_in_buffer_size !=
dg_in_buffer_size)
current_dg_in_buffer_size =
dg_in_buffer_size;
ioread8_rep(vmci_dev->iobase +
VMCI_DATA_IN_ADDR,
vmci_dev->data_buffer +
remaining_bytes,
current_dg_in_buffer_size -
remaining_bytes);
}
if (dg->src.context == VMCI_HYPERVISOR_CONTEXT_ID &&
dg->dst.resource == VMCI_EVENT_HANDLER) {
result = vmci_event_dispatch(dg);
} else {
result = vmci_datagram_invoke_guest_handler(dg);
}
if (result < VMCI_SUCCESS)
dev_dbg(vmci_dev->dev,
"Datagram with resource (ID=0x%x) failed (err=%d)\n",
dg->dst.resource, result);
dg = (struct vmci_datagram *)((u8 *)dg +
dg_in_size);
} else {
size_t bytes_to_skip;
dev_dbg(vmci_dev->dev,
"Failed to receive datagram (size=%u bytes)\n",
dg_in_size);
bytes_to_skip = dg_in_size - remaining_bytes;
if (current_dg_in_buffer_size != dg_in_buffer_size)
current_dg_in_buffer_size = dg_in_buffer_size;
for (;;) {
ioread8_rep(vmci_dev->iobase +
VMCI_DATA_IN_ADDR,
vmci_dev->data_buffer,
current_dg_in_buffer_size);
if (bytes_to_skip <= current_dg_in_buffer_size)
break;
bytes_to_skip -= current_dg_in_buffer_size;
}
dg = (struct vmci_datagram *)(dg_in_buffer +
bytes_to_skip);
}
remaining_bytes =
(size_t) (dg_in_buffer + current_dg_in_buffer_size -
(u8 *)dg);
if (remaining_bytes < VMCI_DG_HEADERSIZE) {
ioread8_rep(vmci_dev->iobase + VMCI_DATA_IN_ADDR,
vmci_dev->data_buffer,
current_dg_in_buffer_size);
dg = (struct vmci_datagram *)dg_in_buffer;
remaining_bytes = current_dg_in_buffer_size;
}
}
}
static void vmci_process_bitmap(unsigned long data)
{
struct vmci_guest_device *dev = (struct vmci_guest_device *)data;
if (!dev->notification_bitmap) {
dev_dbg(dev->dev, "No bitmap present in %s\n", __func__);
return;
}
vmci_dbell_scan_notification_entries(dev->notification_bitmap);
}
static int vmci_enable_msix(struct pci_dev *pdev,
struct vmci_guest_device *vmci_dev)
{
int i;
int result;
for (i = 0; i < VMCI_MAX_INTRS; ++i) {
vmci_dev->msix_entries[i].entry = i;
vmci_dev->msix_entries[i].vector = i;
}
result = pci_enable_msix(pdev, vmci_dev->msix_entries, VMCI_MAX_INTRS);
if (result == 0)
vmci_dev->exclusive_vectors = true;
else if (result > 0)
result = pci_enable_msix(pdev, vmci_dev->msix_entries, 1);
return result;
}
static irqreturn_t vmci_interrupt(int irq, void *_dev)
{
struct vmci_guest_device *dev = _dev;
if (dev->intr_type == VMCI_INTR_TYPE_MSIX && dev->exclusive_vectors) {
tasklet_schedule(&dev->datagram_tasklet);
} else {
unsigned int icr;
icr = ioread32(dev->iobase + VMCI_ICR_ADDR);
if (icr == 0 || icr == ~0)
return IRQ_NONE;
if (icr & VMCI_ICR_DATAGRAM) {
tasklet_schedule(&dev->datagram_tasklet);
icr &= ~VMCI_ICR_DATAGRAM;
}
if (icr & VMCI_ICR_NOTIFICATION) {
tasklet_schedule(&dev->bm_tasklet);
icr &= ~VMCI_ICR_NOTIFICATION;
}
if (icr != 0)
dev_warn(dev->dev,
"Ignoring unknown interrupt cause (%d)\n",
icr);
}
return IRQ_HANDLED;
}
static irqreturn_t vmci_interrupt_bm(int irq, void *_dev)
{
struct vmci_guest_device *dev = _dev;
tasklet_schedule(&dev->bm_tasklet);
return IRQ_HANDLED;
}
static int vmci_guest_probe_device(struct pci_dev *pdev,
const struct pci_device_id *id)
{
struct vmci_guest_device *vmci_dev;
void __iomem *iobase;
unsigned int capabilities;
unsigned long cmd;
int vmci_err;
int error;
dev_dbg(&pdev->dev, "Probing for vmci/PCI guest device\n");
error = pcim_enable_device(pdev);
if (error) {
dev_err(&pdev->dev,
"Failed to enable VMCI device: %d\n", error);
return error;
}
error = pcim_iomap_regions(pdev, 1 << 0, KBUILD_MODNAME);
if (error) {
dev_err(&pdev->dev, "Failed to reserve/map IO regions\n");
return error;
}
iobase = pcim_iomap_table(pdev)[0];
dev_info(&pdev->dev, "Found VMCI PCI device at %#lx, irq %u\n",
(unsigned long)iobase, pdev->irq);
vmci_dev = devm_kzalloc(&pdev->dev, sizeof(*vmci_dev), GFP_KERNEL);
if (!vmci_dev) {
dev_err(&pdev->dev,
"Can't allocate memory for VMCI device\n");
return -ENOMEM;
}
vmci_dev->dev = &pdev->dev;
vmci_dev->intr_type = VMCI_INTR_TYPE_INTX;
vmci_dev->exclusive_vectors = false;
vmci_dev->iobase = iobase;
tasklet_init(&vmci_dev->datagram_tasklet,
vmci_dispatch_dgs, (unsigned long)vmci_dev);
tasklet_init(&vmci_dev->bm_tasklet,
vmci_process_bitmap, (unsigned long)vmci_dev);
vmci_dev->data_buffer = vmalloc(VMCI_MAX_DG_SIZE);
if (!vmci_dev->data_buffer) {
dev_err(&pdev->dev,
"Can't allocate memory for datagram buffer\n");
return -ENOMEM;
}
pci_set_master(pdev);
capabilities = ioread32(vmci_dev->iobase + VMCI_CAPS_ADDR);
if (!(capabilities & VMCI_CAPS_DATAGRAM)) {
dev_err(&pdev->dev, "Device does not support datagrams\n");
error = -ENXIO;
goto err_free_data_buffer;
}
if (capabilities & VMCI_CAPS_NOTIFICATIONS) {
vmci_dev->notification_bitmap = dma_alloc_coherent(
&pdev->dev, PAGE_SIZE, &vmci_dev->notification_base,
GFP_KERNEL);
if (!vmci_dev->notification_bitmap) {
dev_warn(&pdev->dev,
"Unable to allocate notification bitmap\n");
} else {
memset(vmci_dev->notification_bitmap, 0, PAGE_SIZE);
capabilities |= VMCI_CAPS_NOTIFICATIONS;
}
}
dev_info(&pdev->dev, "Using capabilities 0x%x\n", capabilities);
iowrite32(capabilities, vmci_dev->iobase + VMCI_CAPS_ADDR);
spin_lock_irq(&vmci_dev_spinlock);
vmci_dev_g = vmci_dev;
vmci_pdev = pdev;
spin_unlock_irq(&vmci_dev_spinlock);
if (capabilities & VMCI_CAPS_NOTIFICATIONS) {
unsigned long bitmap_ppn =
vmci_dev->notification_base >> PAGE_SHIFT;
if (!vmci_dbell_register_notification_bitmap(bitmap_ppn)) {
dev_warn(&pdev->dev,
"VMCI device unable to register notification bitmap with PPN 0x%x\n",
(u32) bitmap_ppn);
goto err_remove_vmci_dev_g;
}
}
if (!vmci_check_host_caps(pdev))
goto err_remove_bitmap;
vmci_err = vmci_event_subscribe(VMCI_EVENT_CTX_ID_UPDATE,
vmci_guest_cid_update, NULL,
&ctx_update_sub_id);
if (vmci_err < VMCI_SUCCESS)
dev_warn(&pdev->dev,
"Failed to subscribe to event (type=%d): %d\n",
VMCI_EVENT_CTX_ID_UPDATE, vmci_err);
if (!vmci_disable_msix && !vmci_enable_msix(pdev, vmci_dev)) {
vmci_dev->intr_type = VMCI_INTR_TYPE_MSIX;
vmci_dev->irq = vmci_dev->msix_entries[0].vector;
} else if (!vmci_disable_msi && !pci_enable_msi(pdev)) {
vmci_dev->intr_type = VMCI_INTR_TYPE_MSI;
vmci_dev->irq = pdev->irq;
} else {
vmci_dev->intr_type = VMCI_INTR_TYPE_INTX;
vmci_dev->irq = pdev->irq;
}
error = request_irq(vmci_dev->irq, vmci_interrupt, IRQF_SHARED,
KBUILD_MODNAME, vmci_dev);
if (error) {
dev_err(&pdev->dev, "Irq %u in use: %d\n",
vmci_dev->irq, error);
goto err_disable_msi;
}
if (vmci_dev->exclusive_vectors) {
error = request_irq(vmci_dev->msix_entries[1].vector,
vmci_interrupt_bm, 0, KBUILD_MODNAME,
vmci_dev);
if (error) {
dev_err(&pdev->dev,
"Failed to allocate irq %u: %d\n",
vmci_dev->msix_entries[1].vector, error);
goto err_free_irq;
}
}
dev_dbg(&pdev->dev, "Registered device\n");
atomic_inc(&vmci_num_guest_devices);
cmd = VMCI_IMR_DATAGRAM;
if (capabilities & VMCI_CAPS_NOTIFICATIONS)
cmd |= VMCI_IMR_NOTIFICATION;
iowrite32(cmd, vmci_dev->iobase + VMCI_IMR_ADDR);
iowrite32(VMCI_CONTROL_INT_ENABLE,
vmci_dev->iobase + VMCI_CONTROL_ADDR);
pci_set_drvdata(pdev, vmci_dev);
return 0;
err_free_irq:
free_irq(vmci_dev->irq, &vmci_dev);
tasklet_kill(&vmci_dev->datagram_tasklet);
tasklet_kill(&vmci_dev->bm_tasklet);
err_disable_msi:
if (vmci_dev->intr_type == VMCI_INTR_TYPE_MSIX)
pci_disable_msix(pdev);
else if (vmci_dev->intr_type == VMCI_INTR_TYPE_MSI)
pci_disable_msi(pdev);
vmci_err = vmci_event_unsubscribe(ctx_update_sub_id);
if (vmci_err < VMCI_SUCCESS)
dev_warn(&pdev->dev,
"Failed to unsubscribe from event (type=%d) with subscriber (ID=0x%x): %d\n",
VMCI_EVENT_CTX_ID_UPDATE, ctx_update_sub_id, vmci_err);
err_remove_bitmap:
if (vmci_dev->notification_bitmap) {
iowrite32(VMCI_CONTROL_RESET,
vmci_dev->iobase + VMCI_CONTROL_ADDR);
dma_free_coherent(&pdev->dev, PAGE_SIZE,
vmci_dev->notification_bitmap,
vmci_dev->notification_base);
}
err_remove_vmci_dev_g:
spin_lock_irq(&vmci_dev_spinlock);
vmci_pdev = NULL;
vmci_dev_g = NULL;
spin_unlock_irq(&vmci_dev_spinlock);
err_free_data_buffer:
vfree(vmci_dev->data_buffer);
return error;
}
static void vmci_guest_remove_device(struct pci_dev *pdev)
{
struct vmci_guest_device *vmci_dev = pci_get_drvdata(pdev);
int vmci_err;
dev_dbg(&pdev->dev, "Removing device\n");
atomic_dec(&vmci_num_guest_devices);
vmci_qp_guest_endpoints_exit();
vmci_err = vmci_event_unsubscribe(ctx_update_sub_id);
if (vmci_err < VMCI_SUCCESS)
dev_warn(&pdev->dev,
"Failed to unsubscribe from event (type=%d) with subscriber (ID=0x%x): %d\n",
VMCI_EVENT_CTX_ID_UPDATE, ctx_update_sub_id, vmci_err);
spin_lock_irq(&vmci_dev_spinlock);
vmci_dev_g = NULL;
vmci_pdev = NULL;
spin_unlock_irq(&vmci_dev_spinlock);
dev_dbg(&pdev->dev, "Resetting vmci device\n");
iowrite32(VMCI_CONTROL_RESET, vmci_dev->iobase + VMCI_CONTROL_ADDR);
free_irq(vmci_dev->irq, vmci_dev);
if (vmci_dev->intr_type == VMCI_INTR_TYPE_MSIX) {
if (vmci_dev->exclusive_vectors)
free_irq(vmci_dev->msix_entries[1].vector, vmci_dev);
pci_disable_msix(pdev);
} else if (vmci_dev->intr_type == VMCI_INTR_TYPE_MSI) {
pci_disable_msi(pdev);
}
tasklet_kill(&vmci_dev->datagram_tasklet);
tasklet_kill(&vmci_dev->bm_tasklet);
if (vmci_dev->notification_bitmap) {
dma_free_coherent(&pdev->dev, PAGE_SIZE,
vmci_dev->notification_bitmap,
vmci_dev->notification_base);
}
vfree(vmci_dev->data_buffer);
}
int __init vmci_guest_init(void)
{
return pci_register_driver(&vmci_guest_driver);
}
void __exit vmci_guest_exit(void)
{
pci_unregister_driver(&vmci_guest_driver);
}
