static u64 vp_get_features(struct virtio_device *vdev)
{
struct virtio_pci_device *vp_dev = to_vp_device(vdev);
return ioread32(vp_dev->ioaddr + VIRTIO_PCI_HOST_FEATURES);
}
static int vp_finalize_features(struct virtio_device *vdev)
{
struct virtio_pci_device *vp_dev = to_vp_device(vdev);
vring_transport_features(vdev);
BUG_ON((u32)vdev->features != vdev->features);
iowrite32(vdev->features, vp_dev->ioaddr + VIRTIO_PCI_GUEST_FEATURES);
return 0;
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
ioread8(vp_dev->ioaddr + VIRTIO_PCI_STATUS);
vp_synchronize_vectors(vdev);
}
static u16 vp_config_vector(struct virtio_pci_device *vp_dev, u16 vector)
{
iowrite16(vector, vp_dev->ioaddr + VIRTIO_MSI_CONFIG_VECTOR);
return ioread16(vp_dev->ioaddr + VIRTIO_MSI_CONFIG_VECTOR);
}
static struct virtqueue *setup_vq(struct virtio_pci_device *vp_dev,
struct virtio_pci_vq_info *info,
unsigned index,
void (*callback)(struct virtqueue *vq),
const char *name,
u16 msix_vec)
{
struct virtqueue *vq;
unsigned long size;
u16 num;
int err;
iowrite16(index, vp_dev->ioaddr + VIRTIO_PCI_QUEUE_SEL);
num = ioread16(vp_dev->ioaddr + VIRTIO_PCI_QUEUE_NUM);
if (!num || ioread32(vp_dev->ioaddr + VIRTIO_PCI_QUEUE_PFN))
return ERR_PTR(-ENOENT);
info->num = num;
info->msix_vector = msix_vec;
size = PAGE_ALIGN(vring_size(num, VIRTIO_PCI_VRING_ALIGN));
info->queue = alloc_pages_exact(size, GFP_KERNEL|__GFP_ZERO);
if (info->queue == NULL)
return ERR_PTR(-ENOMEM);
iowrite32(virt_to_phys(info->queue) >> VIRTIO_PCI_QUEUE_ADDR_SHIFT,
vp_dev->ioaddr + VIRTIO_PCI_QUEUE_PFN);
vq = vring_new_virtqueue(index, info->num,
VIRTIO_PCI_VRING_ALIGN, &vp_dev->vdev,
true, info->queue, vp_notify, callback, name);
if (!vq) {
err = -ENOMEM;
goto out_activate_queue;
}
vq->priv = (void __force *)vp_dev->ioaddr + VIRTIO_PCI_QUEUE_NOTIFY;
if (msix_vec != VIRTIO_MSI_NO_VECTOR) {
iowrite16(msix_vec, vp_dev->ioaddr + VIRTIO_MSI_QUEUE_VECTOR);
msix_vec = ioread16(vp_dev->ioaddr + VIRTIO_MSI_QUEUE_VECTOR);
if (msix_vec == VIRTIO_MSI_NO_VECTOR) {
err = -EBUSY;
goto out_assign;
}
}
return vq;
out_assign:
vring_del_virtqueue(vq);
out_activate_queue:
iowrite32(0, vp_dev->ioaddr + VIRTIO_PCI_QUEUE_PFN);
free_pages_exact(info->queue, size);
return ERR_PTR(err);
}
static void del_vq(struct virtio_pci_vq_info *info)
{
struct virtqueue *vq = info->vq;
struct virtio_pci_device *vp_dev = to_vp_device(vq->vdev);
unsigned long size;
iowrite16(vq->index, vp_dev->ioaddr + VIRTIO_PCI_QUEUE_SEL);
if (vp_dev->msix_enabled) {
iowrite16(VIRTIO_MSI_NO_VECTOR,
vp_dev->ioaddr + VIRTIO_MSI_QUEUE_VECTOR);
ioread8(vp_dev->ioaddr + VIRTIO_PCI_ISR);
}
vring_del_virtqueue(vq);
iowrite32(0, vp_dev->ioaddr + VIRTIO_PCI_QUEUE_PFN);
size = PAGE_ALIGN(vring_size(info->num, VIRTIO_PCI_VRING_ALIGN));
free_pages_exact(info->queue, size);
}
static void virtio_pci_release_dev(struct device *_d)
{
struct virtio_device *vdev = dev_to_virtio(_d);
struct virtio_pci_device *vp_dev = to_vp_device(vdev);
kfree(vp_dev);
}
int virtio_pci_legacy_probe(struct pci_dev *pci_dev,
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
if (vp_dev->ioaddr == NULL) {
err = -ENOMEM;
goto out_req_regions;
}
vp_dev->isr = vp_dev->ioaddr + VIRTIO_PCI_ISR;
pci_set_drvdata(pci_dev, vp_dev);
pci_set_master(pci_dev);
vp_dev->vdev.id.vendor = pci_dev->subsystem_vendor;
vp_dev->vdev.id.device = pci_dev->subsystem_device;
vp_dev->config_vector = vp_config_vector;
vp_dev->setup_vq = setup_vq;
vp_dev->del_vq = del_vq;
err = register_virtio_device(&vp_dev->vdev);
if (err)
goto out_set_drvdata;
return 0;
out_set_drvdata:
pci_iounmap(pci_dev, vp_dev->ioaddr);
out_req_regions:
pci_release_regions(pci_dev);
out_enable_device:
pci_disable_device(pci_dev);
out:
kfree(vp_dev);
return err;
}
void virtio_pci_legacy_remove(struct pci_dev *pci_dev)
{
struct virtio_pci_device *vp_dev = pci_get_drvdata(pci_dev);
unregister_virtio_device(&vp_dev->vdev);
vp_del_vqs(&vp_dev->vdev);
pci_iounmap(pci_dev, vp_dev->ioaddr);
pci_release_regions(pci_dev);
pci_disable_device(pci_dev);
}
