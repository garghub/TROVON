void vp_synchronize_vectors(struct virtio_device *vdev)
{
struct virtio_pci_device *vp_dev = to_vp_device(vdev);
int i;
if (vp_dev->intx_enabled)
synchronize_irq(vp_dev->pci_dev->irq);
for (i = 0; i < vp_dev->msix_vectors; ++i)
synchronize_irq(vp_dev->msix_entries[i].vector);
}
bool vp_notify(struct virtqueue *vq)
{
iowrite16(vq->index, (void __iomem *)vq->priv);
return true;
}
static irqreturn_t vp_config_changed(int irq, void *opaque)
{
struct virtio_pci_device *vp_dev = opaque;
virtio_config_changed(&vp_dev->vdev);
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
isr = ioread8(vp_dev->isr);
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
for (i = 0; i < vp_dev->msix_vectors; i++)
if (vp_dev->msix_affinity_masks[i])
free_cpumask_var(vp_dev->msix_affinity_masks[i]);
if (vp_dev->msix_enabled) {
vp_dev->config_vector(vp_dev, VIRTIO_MSI_NO_VECTOR);
pci_disable_msix(vp_dev->pci_dev);
vp_dev->msix_enabled = 0;
}
vp_dev->msix_vectors = 0;
vp_dev->msix_used_vectors = 0;
kfree(vp_dev->msix_names);
vp_dev->msix_names = NULL;
kfree(vp_dev->msix_entries);
vp_dev->msix_entries = NULL;
kfree(vp_dev->msix_affinity_masks);
vp_dev->msix_affinity_masks = NULL;
}
static int vp_request_msix_vectors(struct virtio_device *vdev, int nvectors,
bool per_vq_vectors)
{
struct virtio_pci_device *vp_dev = to_vp_device(vdev);
const char *name = dev_name(&vp_dev->vdev.dev);
unsigned i, v;
int err = -ENOMEM;
vp_dev->msix_vectors = nvectors;
vp_dev->msix_entries = kmalloc(nvectors * sizeof *vp_dev->msix_entries,
GFP_KERNEL);
if (!vp_dev->msix_entries)
goto error;
vp_dev->msix_names = kmalloc(nvectors * sizeof *vp_dev->msix_names,
GFP_KERNEL);
if (!vp_dev->msix_names)
goto error;
vp_dev->msix_affinity_masks
= kzalloc(nvectors * sizeof *vp_dev->msix_affinity_masks,
GFP_KERNEL);
if (!vp_dev->msix_affinity_masks)
goto error;
for (i = 0; i < nvectors; ++i)
if (!alloc_cpumask_var(&vp_dev->msix_affinity_masks[i],
GFP_KERNEL))
goto error;
for (i = 0; i < nvectors; ++i)
vp_dev->msix_entries[i].entry = i;
err = pci_enable_msix_exact(vp_dev->pci_dev,
vp_dev->msix_entries, nvectors);
if (err)
goto error;
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
v = vp_dev->config_vector(vp_dev, v);
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
static struct virtqueue *vp_setup_vq(struct virtio_device *vdev, unsigned index,
void (*callback)(struct virtqueue *vq),
const char *name,
u16 msix_vec)
{
struct virtio_pci_device *vp_dev = to_vp_device(vdev);
struct virtio_pci_vq_info *info = kmalloc(sizeof *info, GFP_KERNEL);
struct virtqueue *vq;
unsigned long flags;
if (!info)
return ERR_PTR(-ENOMEM);
vq = vp_dev->setup_vq(vp_dev, info, index, callback, name, msix_vec);
if (IS_ERR(vq))
goto out_info;
info->vq = vq;
if (callback) {
spin_lock_irqsave(&vp_dev->lock, flags);
list_add(&info->node, &vp_dev->virtqueues);
spin_unlock_irqrestore(&vp_dev->lock, flags);
} else {
INIT_LIST_HEAD(&info->node);
}
vp_dev->vqs[index] = info;
return vq;
out_info:
kfree(info);
return vq;
}
static void vp_del_vq(struct virtqueue *vq)
{
struct virtio_pci_device *vp_dev = to_vp_device(vq->vdev);
struct virtio_pci_vq_info *info = vp_dev->vqs[vq->index];
unsigned long flags;
spin_lock_irqsave(&vp_dev->lock, flags);
list_del(&info->node);
spin_unlock_irqrestore(&vp_dev->lock, flags);
vp_dev->del_vq(info);
kfree(info);
}
void vp_del_vqs(struct virtio_device *vdev)
{
struct virtio_pci_device *vp_dev = to_vp_device(vdev);
struct virtqueue *vq, *n;
struct virtio_pci_vq_info *info;
list_for_each_entry_safe(vq, n, &vdev->vqs, list) {
info = vp_dev->vqs[vq->index];
if (vp_dev->per_vq_vectors &&
info->msix_vector != VIRTIO_MSI_NO_VECTOR)
free_irq(vp_dev->msix_entries[info->msix_vector].vector,
vq);
vp_del_vq(vq);
}
vp_dev->per_vq_vectors = false;
vp_free_vectors(vdev);
kfree(vp_dev->vqs);
vp_dev->vqs = NULL;
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
vp_dev->vqs = kmalloc(nvqs * sizeof *vp_dev->vqs, GFP_KERNEL);
if (!vp_dev->vqs)
return -ENOMEM;
if (!use_msix) {
err = vp_request_intx(vdev);
if (err)
goto error_find;
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
goto error_find;
}
vp_dev->per_vq_vectors = per_vq_vectors;
allocated_vectors = vp_dev->msix_used_vectors;
for (i = 0; i < nvqs; ++i) {
if (!names[i]) {
vqs[i] = NULL;
continue;
} else if (!callbacks[i] || !vp_dev->msix_enabled)
msix_vec = VIRTIO_MSI_NO_VECTOR;
else if (vp_dev->per_vq_vectors)
msix_vec = allocated_vectors++;
else
msix_vec = VP_MSIX_VQ_VECTOR;
vqs[i] = vp_setup_vq(vdev, i, callbacks[i], names[i], msix_vec);
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
return err;
}
int vp_find_vqs(struct virtio_device *vdev, unsigned nvqs,
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
const char *vp_bus_name(struct virtio_device *vdev)
{
struct virtio_pci_device *vp_dev = to_vp_device(vdev);
return pci_name(vp_dev->pci_dev);
}
int vp_set_vq_affinity(struct virtqueue *vq, int cpu)
{
struct virtio_device *vdev = vq->vdev;
struct virtio_pci_device *vp_dev = to_vp_device(vdev);
struct virtio_pci_vq_info *info = vp_dev->vqs[vq->index];
struct cpumask *mask;
unsigned int irq;
if (!vq->callback)
return -EINVAL;
if (vp_dev->msix_enabled) {
mask = vp_dev->msix_affinity_masks[info->msix_vector];
irq = vp_dev->msix_entries[info->msix_vector].vector;
if (cpu == -1)
irq_set_affinity_hint(irq, NULL);
else {
cpumask_set_cpu(cpu, mask);
irq_set_affinity_hint(irq, mask);
}
}
return 0;
}
static int virtio_pci_freeze(struct device *dev)
{
struct pci_dev *pci_dev = to_pci_dev(dev);
struct virtio_pci_device *vp_dev = pci_get_drvdata(pci_dev);
int ret;
ret = virtio_device_freeze(&vp_dev->vdev);
if (!ret)
pci_disable_device(pci_dev);
return ret;
}
static int virtio_pci_restore(struct device *dev)
{
struct pci_dev *pci_dev = to_pci_dev(dev);
struct virtio_pci_device *vp_dev = pci_get_drvdata(pci_dev);
int ret;
ret = pci_enable_device(pci_dev);
if (ret)
return ret;
pci_set_master(pci_dev);
return virtio_device_restore(&vp_dev->vdev);
}
static int virtio_pci_probe(struct pci_dev *pci_dev,
const struct pci_device_id *id)
{
return virtio_pci_legacy_probe(pci_dev, id);
}
static void virtio_pci_remove(struct pci_dev *pci_dev)
{
virtio_pci_legacy_remove(pci_dev);
}
