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
u16 num;
int err;
iowrite16(index, vp_dev->ioaddr + VIRTIO_PCI_QUEUE_SEL);
num = ioread16(vp_dev->ioaddr + VIRTIO_PCI_QUEUE_NUM);
if (!num || ioread32(vp_dev->ioaddr + VIRTIO_PCI_QUEUE_PFN))
return ERR_PTR(-ENOENT);
info->msix_vector = msix_vec;
vq = vring_create_virtqueue(index, num,
VIRTIO_PCI_VRING_ALIGN, &vp_dev->vdev,
true, false, vp_notify, callback, name);
if (!vq)
return ERR_PTR(-ENOMEM);
iowrite32(virtqueue_get_desc_addr(vq) >> VIRTIO_PCI_QUEUE_ADDR_SHIFT,
vp_dev->ioaddr + VIRTIO_PCI_QUEUE_PFN);
vq->priv = (void __force *)vp_dev->ioaddr + VIRTIO_PCI_QUEUE_NOTIFY;
if (msix_vec != VIRTIO_MSI_NO_VECTOR) {
iowrite16(msix_vec, vp_dev->ioaddr + VIRTIO_MSI_QUEUE_VECTOR);
msix_vec = ioread16(vp_dev->ioaddr + VIRTIO_MSI_QUEUE_VECTOR);
if (msix_vec == VIRTIO_MSI_NO_VECTOR) {
err = -EBUSY;
goto out_deactivate;
}
}
return vq;
out_deactivate:
iowrite32(0, vp_dev->ioaddr + VIRTIO_PCI_QUEUE_PFN);
vring_del_virtqueue(vq);
return ERR_PTR(err);
}
static void del_vq(struct virtio_pci_vq_info *info)
{
struct virtqueue *vq = info->vq;
struct virtio_pci_device *vp_dev = to_vp_device(vq->vdev);
iowrite16(vq->index, vp_dev->ioaddr + VIRTIO_PCI_QUEUE_SEL);
if (vp_dev->msix_enabled) {
iowrite16(VIRTIO_MSI_NO_VECTOR,
vp_dev->ioaddr + VIRTIO_MSI_QUEUE_VECTOR);
ioread8(vp_dev->ioaddr + VIRTIO_PCI_ISR);
}
iowrite32(0, vp_dev->ioaddr + VIRTIO_PCI_QUEUE_PFN);
vring_del_virtqueue(vq);
}
int virtio_pci_legacy_probe(struct virtio_pci_device *vp_dev)
{
struct pci_dev *pci_dev = vp_dev->pci_dev;
int rc;
if (pci_dev->device < 0x1000 || pci_dev->device > 0x103f)
return -ENODEV;
if (pci_dev->revision != VIRTIO_PCI_ABI_VERSION) {
printk(KERN_ERR "virtio_pci: expected ABI version %d, got %d\n",
VIRTIO_PCI_ABI_VERSION, pci_dev->revision);
return -ENODEV;
}
rc = dma_set_mask(&pci_dev->dev, DMA_BIT_MASK(64));
if (rc) {
rc = dma_set_mask_and_coherent(&pci_dev->dev, DMA_BIT_MASK(32));
} else {
dma_set_coherent_mask(&pci_dev->dev,
DMA_BIT_MASK(32 + VIRTIO_PCI_QUEUE_ADDR_SHIFT));
}
if (rc)
dev_warn(&pci_dev->dev, "Failed to enable 64-bit or 32-bit DMA. Trying to continue, but this might not work.\n");
rc = pci_request_region(pci_dev, 0, "virtio-pci-legacy");
if (rc)
return rc;
rc = -ENOMEM;
vp_dev->ioaddr = pci_iomap(pci_dev, 0, 0);
if (!vp_dev->ioaddr)
goto err_iomap;
vp_dev->isr = vp_dev->ioaddr + VIRTIO_PCI_ISR;
vp_dev->vdev.id.vendor = pci_dev->subsystem_vendor;
vp_dev->vdev.id.device = pci_dev->subsystem_device;
vp_dev->vdev.config = &virtio_pci_config_ops;
vp_dev->config_vector = vp_config_vector;
vp_dev->setup_vq = setup_vq;
vp_dev->del_vq = del_vq;
return 0;
err_iomap:
pci_release_region(pci_dev, 0);
return rc;
}
void virtio_pci_legacy_remove(struct virtio_pci_device *vp_dev)
{
struct pci_dev *pci_dev = vp_dev->pci_dev;
pci_iounmap(pci_dev, vp_dev->ioaddr);
pci_release_region(pci_dev, 0);
}
