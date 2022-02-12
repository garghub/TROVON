static struct virtio_pci_device *to_vp_device(struct virtio_device *vdev)
{
return container_of(vdev, struct virtio_pci_device, vdev);
}
static u32 vp_get_features(struct virtio_device *vdev)
{
struct virtio_pci_device *vp_dev = to_vp_device(vdev);
return ioread32(vp_dev->ioaddr + VIRTIO_PCI_HOST_FEATURES);
}
static void vp_finalize_features(struct virtio_device *vdev)
{
struct virtio_pci_device *vp_dev = to_vp_device(vdev);
vring_transport_features(vdev);
BUILD_BUG_ON(ARRAY_SIZE(vdev->features) != 1);
iowrite32(vdev->features[0], vp_dev->ioaddr+VIRTIO_PCI_GUEST_FEATURES);
}
static void vp_get(struct virtio_device *vdev, unsigned offset,
void *buf, unsigned len)
{
struct virtio_pci_device *vp_dev = to_vp_device(vdev);
void __iomem *ioaddr = vp_dev->ioaddr +
VIRTIO_PCI_CONFIG(vp_dev) + offset;
u8 *ptr = buf;
int i;
for (i = 0; i < len; i++)
ptr[i] = ioread8(ioaddr + i);
}
static void vp_set(struct virtio_device *vdev, unsigned offset,
const void *buf, unsigned len)
{
struct virtio_pci_device *vp_dev = to_vp_device(vdev);
void __iomem *ioaddr = vp_dev->ioaddr +
VIRTIO_PCI_CONFIG(vp_dev) + offset;
const u8 *ptr = buf;
int i;
for (i = 0; i < len; i++)
iowrite8(ptr[i], ioaddr + i);
}
static u8 vp_get_status(struct virtio_device *vdev)
{
struct virtio_pci_device *vp_dev = to_vp_device(vdev);
return ioread8(vp_dev->ioaddr + VIRTIO_PCI_STATUS);
}
static void vp_set_status(struct virtio_device *vdev, u8 status)
{
struct virtio_pci_device *vp_dev = to_vp_device(vdev);
BUG_ON(status == 0);
iowrite8(status, vp_dev->ioaddr + VIRTIO_PCI_STATUS);
}
static void vp_reset(struct virtio_device *vdev)
{
struct virtio_pci_device *vp_dev = to_vp_device(vdev);
iowrite8(0, vp_dev->ioaddr + VIRTIO_PCI_STATUS);
}
static void vp_notify(struct virtqueue *vq)
{
struct virtio_pci_device *vp_dev = to_vp_device(vq->vdev);
struct virtio_pci_vq_info *info = vq->priv;
iowrite16(info->queue_index, vp_dev->ioaddr + VIRTIO_PCI_QUEUE_NOTIFY);
}
static irqreturn_t vp_config_changed(int irq, void *opaque)
{
struct virtio_pci_device *vp_dev = opaque;
struct virtio_driver *drv;
drv = container_of(vp_dev->vdev.dev.driver,
struct virtio_driver, driver);
if (drv && drv->config_changed)
drv->config_changed(&vp_dev->vdev);
return IRQ_HANDLED;
}
static irqreturn_t vp_vring_interrupt(int irq, void *opaque)
{
struct virtio_pci_device *vp_dev = opaque;
struct virtio_pci_vq_info *info;
irqreturn_t ret = IRQ_NONE;
unsigned long flags;
spin_lock_irqsave(&vp_dev->lock, flags);
list_for_each_entry(info, &vp_dev->virtqueues, node) {
if (vring_interrupt(irq, info->vq) == IRQ_HANDLED)
ret = IRQ_HANDLED;
}
spin_unlock_irqrestore(&vp_dev->lock, flags);
return ret;
}
static irqreturn_t vp_interrupt(int irq, void *opaque)
{
struct virtio_pci_device *vp_dev = opaque;
u8 isr;
isr = ioread8(vp_dev->ioaddr + VIRTIO_PCI_ISR);
if (!isr)
return IRQ_NONE;
if (isr & VIRTIO_PCI_ISR_CONFIG)
vp_config_changed(irq, opaque);
return vp_vring_interrupt(irq, opaque);
}
static void vp_free_vectors(struct virtio_device *vdev)
{
struct virtio_pci_device *vp_dev = to_vp_device(vdev);
int i;
if (vp_dev->intx_enabled) {
free_irq(vp_dev->pci_dev->irq, vp_dev);
vp_dev->intx_enabled = 0;
}
for (i = 0; i < vp_dev->msix_used_vectors; ++i)
free_irq(vp_dev->msix_entries[i].vector, vp_dev);
if (vp_dev->msix_enabled) {
iowrite16(VIRTIO_MSI_NO_VECTOR,
vp_dev->ioaddr + VIRTIO_MSI_CONFIG_VECTOR);
ioread16(vp_dev->ioaddr + VIRTIO_MSI_CONFIG_VECTOR);
pci_disable_msix(vp_dev->pci_dev);
vp_dev->msix_enabled = 0;
vp_dev->msix_vectors = 0;
}
vp_dev->msix_used_vectors = 0;
kfree(vp_dev->msix_names);
vp_dev->msix_names = NULL;
kfree(vp_dev->msix_entries);
vp_dev->msix_entries = NULL;
}
static int vp_request_msix_vectors(struct virtio_device *vdev, int nvectors,
bool per_vq_vectors)
{
struct virtio_pci_device *vp_dev = to_vp_device(vdev);
const char *name = dev_name(&vp_dev->vdev.dev);
unsigned i, v;
int err = -ENOMEM;
vp_dev->msix_entries = kmalloc(nvectors * sizeof *vp_dev->msix_entries,
GFP_KERNEL);
if (!vp_dev->msix_entries)
goto error;
vp_dev->msix_names = kmalloc(nvectors * sizeof *vp_dev->msix_names,
GFP_KERNEL);
if (!vp_dev->msix_names)
goto error;
for (i = 0; i < nvectors; ++i)
vp_dev->msix_entries[i].entry = i;
err = pci_enable_msix(vp_dev->pci_dev, vp_dev->msix_entries, nvectors);
if (err > 0)
err = -ENOSPC;
if (err)
goto error;
vp_dev->msix_vectors = nvectors;
vp_dev->msix_enabled = 1;
v = vp_dev->msix_used_vectors;
snprintf(vp_dev->msix_names[v], sizeof *vp_dev->msix_names,
"%s-config", name);
err = request_irq(vp_dev->msix_entries[v].vector,
vp_config_changed, 0, vp_dev->msix_names[v],
vp_dev);
if (err)
goto error;
++vp_dev->msix_used_vectors;
iowrite16(v, vp_dev->ioaddr + VIRTIO_MSI_CONFIG_VECTOR);
v = ioread16(vp_dev->ioaddr + VIRTIO_MSI_CONFIG_VECTOR);
if (v == VIRTIO_MSI_NO_VECTOR) {
err = -EBUSY;
goto error;
}
if (!per_vq_vectors) {
v = vp_dev->msix_used_vectors;
snprintf(vp_dev->msix_names[v], sizeof *vp_dev->msix_names,
"%s-virtqueues", name);
err = request_irq(vp_dev->msix_entries[v].vector,
vp_vring_interrupt, 0, vp_dev->msix_names[v],
vp_dev);
if (err)
goto error;
++vp_dev->msix_used_vectors;
}
return 0;
error:
vp_free_vectors(vdev);
return err;
}
static int vp_request_intx(struct virtio_device *vdev)
{
int err;
struct virtio_pci_device *vp_dev = to_vp_device(vdev);
err = request_irq(vp_dev->pci_dev->irq, vp_interrupt,
IRQF_SHARED, dev_name(&vdev->dev), vp_dev);
if (!err)
vp_dev->intx_enabled = 1;
return err;
}
static struct virtqueue *setup_vq(struct virtio_device *vdev, unsigned index,
void (*callback)(struct virtqueue *vq),
const char *name,
u16 msix_vec)
{
struct virtio_pci_device *vp_dev = to_vp_device(vdev);
struct virtio_pci_vq_info *info;
struct virtqueue *vq;
unsigned long flags, size;
u16 num;
int err;
iowrite16(index, vp_dev->ioaddr + VIRTIO_PCI_QUEUE_SEL);
num = ioread16(vp_dev->ioaddr + VIRTIO_PCI_QUEUE_NUM);
if (!num || ioread32(vp_dev->ioaddr + VIRTIO_PCI_QUEUE_PFN))
return ERR_PTR(-ENOENT);
info = kmalloc(sizeof(struct virtio_pci_vq_info), GFP_KERNEL);
if (!info)
return ERR_PTR(-ENOMEM);
info->queue_index = index;
info->num = num;
info->msix_vector = msix_vec;
size = PAGE_ALIGN(vring_size(num, VIRTIO_PCI_VRING_ALIGN));
info->queue = alloc_pages_exact(size, GFP_KERNEL|__GFP_ZERO);
if (info->queue == NULL) {
err = -ENOMEM;
goto out_info;
}
iowrite32(virt_to_phys(info->queue) >> VIRTIO_PCI_QUEUE_ADDR_SHIFT,
vp_dev->ioaddr + VIRTIO_PCI_QUEUE_PFN);
vq = vring_new_virtqueue(info->num, VIRTIO_PCI_VRING_ALIGN,
vdev, info->queue, vp_notify, callback, name);
if (!vq) {
err = -ENOMEM;
goto out_activate_queue;
}
vq->priv = info;
info->vq = vq;
if (msix_vec != VIRTIO_MSI_NO_VECTOR) {
iowrite16(msix_vec, vp_dev->ioaddr + VIRTIO_MSI_QUEUE_VECTOR);
msix_vec = ioread16(vp_dev->ioaddr + VIRTIO_MSI_QUEUE_VECTOR);
if (msix_vec == VIRTIO_MSI_NO_VECTOR) {
err = -EBUSY;
goto out_assign;
}
}
spin_lock_irqsave(&vp_dev->lock, flags);
list_add(&info->node, &vp_dev->virtqueues);
spin_unlock_irqrestore(&vp_dev->lock, flags);
return vq;
out_assign:
vring_del_virtqueue(vq);
out_activate_queue:
iowrite32(0, vp_dev->ioaddr + VIRTIO_PCI_QUEUE_PFN);
free_pages_exact(info->queue, size);
out_info:
kfree(info);
return ERR_PTR(err);
}
static void vp_del_vq(struct virtqueue *vq)
{
struct virtio_pci_device *vp_dev = to_vp_device(vq->vdev);
struct virtio_pci_vq_info *info = vq->priv;
unsigned long flags, size;
spin_lock_irqsave(&vp_dev->lock, flags);
list_del(&info->node);
spin_unlock_irqrestore(&vp_dev->lock, flags);
iowrite16(info->queue_index, vp_dev->ioaddr + VIRTIO_PCI_QUEUE_SEL);
if (vp_dev->msix_enabled) {
iowrite16(VIRTIO_MSI_NO_VECTOR,
vp_dev->ioaddr + VIRTIO_MSI_QUEUE_VECTOR);
ioread8(vp_dev->ioaddr + VIRTIO_PCI_ISR);
}
vring_del_virtqueue(vq);
iowrite32(0, vp_dev->ioaddr + VIRTIO_PCI_QUEUE_PFN);
size = PAGE_ALIGN(vring_size(info->num, VIRTIO_PCI_VRING_ALIGN));
free_pages_exact(info->queue, size);
kfree(info);
}
static void vp_del_vqs(struct virtio_device *vdev)
{
struct virtio_pci_device *vp_dev = to_vp_device(vdev);
struct virtqueue *vq, *n;
struct virtio_pci_vq_info *info;
list_for_each_entry_safe(vq, n, &vdev->vqs, list) {
info = vq->priv;
if (vp_dev->per_vq_vectors &&
info->msix_vector != VIRTIO_MSI_NO_VECTOR)
free_irq(vp_dev->msix_entries[info->msix_vector].vector,
vq);
vp_del_vq(vq);
}
vp_dev->per_vq_vectors = false;
vp_free_vectors(vdev);
}
static int vp_try_to_find_vqs(struct virtio_device *vdev, unsigned nvqs,
struct virtqueue *vqs[],
vq_callback_t *callbacks[],
const char *names[],
bool use_msix,
bool per_vq_vectors)
{
struct virtio_pci_device *vp_dev = to_vp_device(vdev);
u16 msix_vec;
int i, err, nvectors, allocated_vectors;
if (!use_msix) {
err = vp_request_intx(vdev);
if (err)
goto error_request;
} else {
if (per_vq_vectors) {
nvectors = 1;
for (i = 0; i < nvqs; ++i)
if (callbacks[i])
++nvectors;
} else {
nvectors = 2;
}
err = vp_request_msix_vectors(vdev, nvectors, per_vq_vectors);
if (err)
goto error_request;
}
vp_dev->per_vq_vectors = per_vq_vectors;
allocated_vectors = vp_dev->msix_used_vectors;
for (i = 0; i < nvqs; ++i) {
if (!callbacks[i] || !vp_dev->msix_enabled)
msix_vec = VIRTIO_MSI_NO_VECTOR;
else if (vp_dev->per_vq_vectors)
msix_vec = allocated_vectors++;
else
msix_vec = VP_MSIX_VQ_VECTOR;
vqs[i] = setup_vq(vdev, i, callbacks[i], names[i], msix_vec);
if (IS_ERR(vqs[i])) {
err = PTR_ERR(vqs[i]);
goto error_find;
}
if (!vp_dev->per_vq_vectors || msix_vec == VIRTIO_MSI_NO_VECTOR)
continue;
snprintf(vp_dev->msix_names[msix_vec],
sizeof *vp_dev->msix_names,
"%s-%s",
dev_name(&vp_dev->vdev.dev), names[i]);
err = request_irq(vp_dev->msix_entries[msix_vec].vector,
vring_interrupt, 0,
vp_dev->msix_names[msix_vec],
vqs[i]);
if (err) {
vp_del_vq(vqs[i]);
goto error_find;
}
}
return 0;
error_find:
vp_del_vqs(vdev);
error_request:
return err;
}
static int vp_find_vqs(struct virtio_device *vdev, unsigned nvqs,
struct virtqueue *vqs[],
vq_callback_t *callbacks[],
const char *names[])
{
int err;
err = vp_try_to_find_vqs(vdev, nvqs, vqs, callbacks, names, true, true);
if (!err)
return 0;
err = vp_try_to_find_vqs(vdev, nvqs, vqs, callbacks, names,
true, false);
if (!err)
return 0;
return vp_try_to_find_vqs(vdev, nvqs, vqs, callbacks, names,
false, false);
}
static void virtio_pci_release_dev(struct device *_d)
{
struct virtio_device *dev = container_of(_d, struct virtio_device,
dev);
struct virtio_pci_device *vp_dev = to_vp_device(dev);
kfree(vp_dev);
}
static int __devinit virtio_pci_probe(struct pci_dev *pci_dev,
const struct pci_device_id *id)
{
struct virtio_pci_device *vp_dev;
int err;
if (pci_dev->device < 0x1000 || pci_dev->device > 0x103f)
return -ENODEV;
if (pci_dev->revision != VIRTIO_PCI_ABI_VERSION) {
printk(KERN_ERR "virtio_pci: expected ABI version %d, got %d\n",
VIRTIO_PCI_ABI_VERSION, pci_dev->revision);
return -ENODEV;
}
vp_dev = kzalloc(sizeof(struct virtio_pci_device), GFP_KERNEL);
if (vp_dev == NULL)
return -ENOMEM;
vp_dev->vdev.dev.parent = &pci_dev->dev;
vp_dev->vdev.dev.release = virtio_pci_release_dev;
vp_dev->vdev.config = &virtio_pci_config_ops;
vp_dev->pci_dev = pci_dev;
INIT_LIST_HEAD(&vp_dev->virtqueues);
spin_lock_init(&vp_dev->lock);
pci_msi_off(pci_dev);
err = pci_enable_device(pci_dev);
if (err)
goto out;
err = pci_request_regions(pci_dev, "virtio-pci");
if (err)
goto out_enable_device;
vp_dev->ioaddr = pci_iomap(pci_dev, 0, 0);
if (vp_dev->ioaddr == NULL)
goto out_req_regions;
pci_set_drvdata(pci_dev, vp_dev);
pci_set_master(pci_dev);
vp_dev->vdev.id.vendor = pci_dev->subsystem_vendor;
vp_dev->vdev.id.device = pci_dev->subsystem_device;
err = register_virtio_device(&vp_dev->vdev);
if (err)
goto out_set_drvdata;
return 0;
out_set_drvdata:
pci_set_drvdata(pci_dev, NULL);
pci_iounmap(pci_dev, vp_dev->ioaddr);
out_req_regions:
pci_release_regions(pci_dev);
out_enable_device:
pci_disable_device(pci_dev);
out:
kfree(vp_dev);
return err;
}
static void __devexit virtio_pci_remove(struct pci_dev *pci_dev)
{
struct virtio_pci_device *vp_dev = pci_get_drvdata(pci_dev);
unregister_virtio_device(&vp_dev->vdev);
vp_del_vqs(&vp_dev->vdev);
pci_set_drvdata(pci_dev, NULL);
pci_iounmap(pci_dev, vp_dev->ioaddr);
pci_release_regions(pci_dev);
pci_disable_device(pci_dev);
}
static int virtio_pci_suspend(struct pci_dev *pci_dev, pm_message_t state)
{
pci_save_state(pci_dev);
pci_set_power_state(pci_dev, PCI_D3hot);
return 0;
}
static int virtio_pci_resume(struct pci_dev *pci_dev)
{
pci_restore_state(pci_dev);
pci_set_power_state(pci_dev, PCI_D0);
return 0;
}
static int __init virtio_pci_init(void)
{
return pci_register_driver(&virtio_pci_driver);
}
static void __exit virtio_pci_exit(void)
{
pci_unregister_driver(&virtio_pci_driver);
}
