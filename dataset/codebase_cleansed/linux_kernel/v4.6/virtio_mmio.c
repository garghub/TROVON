static u64 vm_get_features(struct virtio_device *vdev)
{
struct virtio_mmio_device *vm_dev = to_virtio_mmio_device(vdev);
u64 features;
writel(1, vm_dev->base + VIRTIO_MMIO_DEVICE_FEATURES_SEL);
features = readl(vm_dev->base + VIRTIO_MMIO_DEVICE_FEATURES);
features <<= 32;
writel(0, vm_dev->base + VIRTIO_MMIO_DEVICE_FEATURES_SEL);
features |= readl(vm_dev->base + VIRTIO_MMIO_DEVICE_FEATURES);
return features;
}
static int vm_finalize_features(struct virtio_device *vdev)
{
struct virtio_mmio_device *vm_dev = to_virtio_mmio_device(vdev);
vring_transport_features(vdev);
if (vm_dev->version == 2 &&
!__virtio_test_bit(vdev, VIRTIO_F_VERSION_1)) {
dev_err(&vdev->dev, "New virtio-mmio devices (version 2) must provide VIRTIO_F_VERSION_1 feature!\n");
return -EINVAL;
}
writel(1, vm_dev->base + VIRTIO_MMIO_DRIVER_FEATURES_SEL);
writel((u32)(vdev->features >> 32),
vm_dev->base + VIRTIO_MMIO_DRIVER_FEATURES);
writel(0, vm_dev->base + VIRTIO_MMIO_DRIVER_FEATURES_SEL);
writel((u32)vdev->features,
vm_dev->base + VIRTIO_MMIO_DRIVER_FEATURES);
return 0;
}
static void vm_get(struct virtio_device *vdev, unsigned offset,
void *buf, unsigned len)
{
struct virtio_mmio_device *vm_dev = to_virtio_mmio_device(vdev);
void __iomem *base = vm_dev->base + VIRTIO_MMIO_CONFIG;
u8 b;
__le16 w;
__le32 l;
if (vm_dev->version == 1) {
u8 *ptr = buf;
int i;
for (i = 0; i < len; i++)
ptr[i] = readb(base + offset + i);
return;
}
switch (len) {
case 1:
b = readb(base + offset);
memcpy(buf, &b, sizeof b);
break;
case 2:
w = cpu_to_le16(readw(base + offset));
memcpy(buf, &w, sizeof w);
break;
case 4:
l = cpu_to_le32(readl(base + offset));
memcpy(buf, &l, sizeof l);
break;
case 8:
l = cpu_to_le32(readl(base + offset));
memcpy(buf, &l, sizeof l);
l = cpu_to_le32(ioread32(base + offset + sizeof l));
memcpy(buf + sizeof l, &l, sizeof l);
break;
default:
BUG();
}
}
static void vm_set(struct virtio_device *vdev, unsigned offset,
const void *buf, unsigned len)
{
struct virtio_mmio_device *vm_dev = to_virtio_mmio_device(vdev);
void __iomem *base = vm_dev->base + VIRTIO_MMIO_CONFIG;
u8 b;
__le16 w;
__le32 l;
if (vm_dev->version == 1) {
const u8 *ptr = buf;
int i;
for (i = 0; i < len; i++)
writeb(ptr[i], base + offset + i);
return;
}
switch (len) {
case 1:
memcpy(&b, buf, sizeof b);
writeb(b, base + offset);
break;
case 2:
memcpy(&w, buf, sizeof w);
writew(le16_to_cpu(w), base + offset);
break;
case 4:
memcpy(&l, buf, sizeof l);
writel(le32_to_cpu(l), base + offset);
break;
case 8:
memcpy(&l, buf, sizeof l);
writel(le32_to_cpu(l), base + offset);
memcpy(&l, buf + sizeof l, sizeof l);
writel(le32_to_cpu(l), base + offset + sizeof l);
break;
default:
BUG();
}
}
static u32 vm_generation(struct virtio_device *vdev)
{
struct virtio_mmio_device *vm_dev = to_virtio_mmio_device(vdev);
if (vm_dev->version == 1)
return 0;
else
return readl(vm_dev->base + VIRTIO_MMIO_CONFIG_GENERATION);
}
static u8 vm_get_status(struct virtio_device *vdev)
{
struct virtio_mmio_device *vm_dev = to_virtio_mmio_device(vdev);
return readl(vm_dev->base + VIRTIO_MMIO_STATUS) & 0xff;
}
static void vm_set_status(struct virtio_device *vdev, u8 status)
{
struct virtio_mmio_device *vm_dev = to_virtio_mmio_device(vdev);
BUG_ON(status == 0);
writel(status, vm_dev->base + VIRTIO_MMIO_STATUS);
}
static void vm_reset(struct virtio_device *vdev)
{
struct virtio_mmio_device *vm_dev = to_virtio_mmio_device(vdev);
writel(0, vm_dev->base + VIRTIO_MMIO_STATUS);
}
static bool vm_notify(struct virtqueue *vq)
{
struct virtio_mmio_device *vm_dev = to_virtio_mmio_device(vq->vdev);
writel(vq->index, vm_dev->base + VIRTIO_MMIO_QUEUE_NOTIFY);
return true;
}
static irqreturn_t vm_interrupt(int irq, void *opaque)
{
struct virtio_mmio_device *vm_dev = opaque;
struct virtio_mmio_vq_info *info;
unsigned long status;
unsigned long flags;
irqreturn_t ret = IRQ_NONE;
status = readl(vm_dev->base + VIRTIO_MMIO_INTERRUPT_STATUS);
writel(status, vm_dev->base + VIRTIO_MMIO_INTERRUPT_ACK);
if (unlikely(status & VIRTIO_MMIO_INT_CONFIG)) {
virtio_config_changed(&vm_dev->vdev);
ret = IRQ_HANDLED;
}
if (likely(status & VIRTIO_MMIO_INT_VRING)) {
spin_lock_irqsave(&vm_dev->lock, flags);
list_for_each_entry(info, &vm_dev->virtqueues, node)
ret |= vring_interrupt(irq, info->vq);
spin_unlock_irqrestore(&vm_dev->lock, flags);
}
return ret;
}
static void vm_del_vq(struct virtqueue *vq)
{
struct virtio_mmio_device *vm_dev = to_virtio_mmio_device(vq->vdev);
struct virtio_mmio_vq_info *info = vq->priv;
unsigned long flags;
unsigned int index = vq->index;
spin_lock_irqsave(&vm_dev->lock, flags);
list_del(&info->node);
spin_unlock_irqrestore(&vm_dev->lock, flags);
writel(index, vm_dev->base + VIRTIO_MMIO_QUEUE_SEL);
if (vm_dev->version == 1) {
writel(0, vm_dev->base + VIRTIO_MMIO_QUEUE_PFN);
} else {
writel(0, vm_dev->base + VIRTIO_MMIO_QUEUE_READY);
WARN_ON(readl(vm_dev->base + VIRTIO_MMIO_QUEUE_READY));
}
vring_del_virtqueue(vq);
kfree(info);
}
static void vm_del_vqs(struct virtio_device *vdev)
{
struct virtio_mmio_device *vm_dev = to_virtio_mmio_device(vdev);
struct virtqueue *vq, *n;
list_for_each_entry_safe(vq, n, &vdev->vqs, list)
vm_del_vq(vq);
free_irq(platform_get_irq(vm_dev->pdev, 0), vm_dev);
}
static struct virtqueue *vm_setup_vq(struct virtio_device *vdev, unsigned index,
void (*callback)(struct virtqueue *vq),
const char *name)
{
struct virtio_mmio_device *vm_dev = to_virtio_mmio_device(vdev);
struct virtio_mmio_vq_info *info;
struct virtqueue *vq;
unsigned long flags;
unsigned int num;
int err;
if (!name)
return NULL;
writel(index, vm_dev->base + VIRTIO_MMIO_QUEUE_SEL);
if (readl(vm_dev->base + (vm_dev->version == 1 ?
VIRTIO_MMIO_QUEUE_PFN : VIRTIO_MMIO_QUEUE_READY))) {
err = -ENOENT;
goto error_available;
}
info = kmalloc(sizeof(*info), GFP_KERNEL);
if (!info) {
err = -ENOMEM;
goto error_kmalloc;
}
num = readl(vm_dev->base + VIRTIO_MMIO_QUEUE_NUM_MAX);
if (num == 0) {
err = -ENOENT;
goto error_new_virtqueue;
}
vq = vring_create_virtqueue(index, num, VIRTIO_MMIO_VRING_ALIGN, vdev,
true, true, vm_notify, callback, name);
if (!vq) {
err = -ENOMEM;
goto error_new_virtqueue;
}
writel(virtqueue_get_vring_size(vq), vm_dev->base + VIRTIO_MMIO_QUEUE_NUM);
if (vm_dev->version == 1) {
writel(PAGE_SIZE, vm_dev->base + VIRTIO_MMIO_QUEUE_ALIGN);
writel(virtqueue_get_desc_addr(vq) >> PAGE_SHIFT,
vm_dev->base + VIRTIO_MMIO_QUEUE_PFN);
} else {
u64 addr;
addr = virtqueue_get_desc_addr(vq);
writel((u32)addr, vm_dev->base + VIRTIO_MMIO_QUEUE_DESC_LOW);
writel((u32)(addr >> 32),
vm_dev->base + VIRTIO_MMIO_QUEUE_DESC_HIGH);
addr = virtqueue_get_avail_addr(vq);
writel((u32)addr, vm_dev->base + VIRTIO_MMIO_QUEUE_AVAIL_LOW);
writel((u32)(addr >> 32),
vm_dev->base + VIRTIO_MMIO_QUEUE_AVAIL_HIGH);
addr = virtqueue_get_used_addr(vq);
writel((u32)addr, vm_dev->base + VIRTIO_MMIO_QUEUE_USED_LOW);
writel((u32)(addr >> 32),
vm_dev->base + VIRTIO_MMIO_QUEUE_USED_HIGH);
writel(1, vm_dev->base + VIRTIO_MMIO_QUEUE_READY);
}
vq->priv = info;
info->vq = vq;
spin_lock_irqsave(&vm_dev->lock, flags);
list_add(&info->node, &vm_dev->virtqueues);
spin_unlock_irqrestore(&vm_dev->lock, flags);
return vq;
error_new_virtqueue:
if (vm_dev->version == 1) {
writel(0, vm_dev->base + VIRTIO_MMIO_QUEUE_PFN);
} else {
writel(0, vm_dev->base + VIRTIO_MMIO_QUEUE_READY);
WARN_ON(readl(vm_dev->base + VIRTIO_MMIO_QUEUE_READY));
}
kfree(info);
error_kmalloc:
error_available:
return ERR_PTR(err);
}
static int vm_find_vqs(struct virtio_device *vdev, unsigned nvqs,
struct virtqueue *vqs[],
vq_callback_t *callbacks[],
const char * const names[])
{
struct virtio_mmio_device *vm_dev = to_virtio_mmio_device(vdev);
unsigned int irq = platform_get_irq(vm_dev->pdev, 0);
int i, err;
err = request_irq(irq, vm_interrupt, IRQF_SHARED,
dev_name(&vdev->dev), vm_dev);
if (err)
return err;
for (i = 0; i < nvqs; ++i) {
vqs[i] = vm_setup_vq(vdev, i, callbacks[i], names[i]);
if (IS_ERR(vqs[i])) {
vm_del_vqs(vdev);
return PTR_ERR(vqs[i]);
}
}
return 0;
}
static const char *vm_bus_name(struct virtio_device *vdev)
{
struct virtio_mmio_device *vm_dev = to_virtio_mmio_device(vdev);
return vm_dev->pdev->name;
}
static int virtio_mmio_probe(struct platform_device *pdev)
{
struct virtio_mmio_device *vm_dev;
struct resource *mem;
unsigned long magic;
mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!mem)
return -EINVAL;
if (!devm_request_mem_region(&pdev->dev, mem->start,
resource_size(mem), pdev->name))
return -EBUSY;
vm_dev = devm_kzalloc(&pdev->dev, sizeof(*vm_dev), GFP_KERNEL);
if (!vm_dev)
return -ENOMEM;
vm_dev->vdev.dev.parent = &pdev->dev;
vm_dev->vdev.config = &virtio_mmio_config_ops;
vm_dev->pdev = pdev;
INIT_LIST_HEAD(&vm_dev->virtqueues);
spin_lock_init(&vm_dev->lock);
vm_dev->base = devm_ioremap(&pdev->dev, mem->start, resource_size(mem));
if (vm_dev->base == NULL)
return -EFAULT;
magic = readl(vm_dev->base + VIRTIO_MMIO_MAGIC_VALUE);
if (magic != ('v' | 'i' << 8 | 'r' << 16 | 't' << 24)) {
dev_warn(&pdev->dev, "Wrong magic value 0x%08lx!\n", magic);
return -ENODEV;
}
vm_dev->version = readl(vm_dev->base + VIRTIO_MMIO_VERSION);
if (vm_dev->version < 1 || vm_dev->version > 2) {
dev_err(&pdev->dev, "Version %ld not supported!\n",
vm_dev->version);
return -ENXIO;
}
vm_dev->vdev.id.device = readl(vm_dev->base + VIRTIO_MMIO_DEVICE_ID);
if (vm_dev->vdev.id.device == 0) {
return -ENODEV;
}
vm_dev->vdev.id.vendor = readl(vm_dev->base + VIRTIO_MMIO_VENDOR_ID);
if (vm_dev->version == 1)
writel(PAGE_SIZE, vm_dev->base + VIRTIO_MMIO_GUEST_PAGE_SIZE);
platform_set_drvdata(pdev, vm_dev);
return register_virtio_device(&vm_dev->vdev);
}
static int virtio_mmio_remove(struct platform_device *pdev)
{
struct virtio_mmio_device *vm_dev = platform_get_drvdata(pdev);
unregister_virtio_device(&vm_dev->vdev);
return 0;
}
static int vm_cmdline_set(const char *device,
const struct kernel_param *kp)
{
int err;
struct resource resources[2] = {};
char *str;
long long int base, size;
unsigned int irq;
int processed, consumed = 0;
struct platform_device *pdev;
size = memparse(device, &str);
processed = sscanf(str, "@%lli:%u%n:%d%n",
&base, &irq, &consumed,
&vm_cmdline_id, &consumed);
if (processed < 2 || str[consumed])
return -EINVAL;
resources[0].flags = IORESOURCE_MEM;
resources[0].start = base;
resources[0].end = base + size - 1;
resources[1].flags = IORESOURCE_IRQ;
resources[1].start = resources[1].end = irq;
if (!vm_cmdline_parent_registered) {
err = device_register(&vm_cmdline_parent);
if (err) {
pr_err("Failed to register parent device!\n");
return err;
}
vm_cmdline_parent_registered = 1;
}
pr_info("Registering device virtio-mmio.%d at 0x%llx-0x%llx, IRQ %d.\n",
vm_cmdline_id,
(unsigned long long)resources[0].start,
(unsigned long long)resources[0].end,
(int)resources[1].start);
pdev = platform_device_register_resndata(&vm_cmdline_parent,
"virtio-mmio", vm_cmdline_id++,
resources, ARRAY_SIZE(resources), NULL, 0);
if (IS_ERR(pdev))
return PTR_ERR(pdev);
return 0;
}
static int vm_cmdline_get_device(struct device *dev, void *data)
{
char *buffer = data;
unsigned int len = strlen(buffer);
struct platform_device *pdev = to_platform_device(dev);
snprintf(buffer + len, PAGE_SIZE - len, "0x%llx@0x%llx:%llu:%d\n",
pdev->resource[0].end - pdev->resource[0].start + 1ULL,
(unsigned long long)pdev->resource[0].start,
(unsigned long long)pdev->resource[1].start,
pdev->id);
return 0;
}
static int vm_cmdline_get(char *buffer, const struct kernel_param *kp)
{
buffer[0] = '\0';
device_for_each_child(&vm_cmdline_parent, buffer,
vm_cmdline_get_device);
return strlen(buffer) + 1;
}
static int vm_unregister_cmdline_device(struct device *dev,
void *data)
{
platform_device_unregister(to_platform_device(dev));
return 0;
}
static void vm_unregister_cmdline_devices(void)
{
if (vm_cmdline_parent_registered) {
device_for_each_child(&vm_cmdline_parent, NULL,
vm_unregister_cmdline_device);
device_unregister(&vm_cmdline_parent);
vm_cmdline_parent_registered = 0;
}
}
static void vm_unregister_cmdline_devices(void)
{
}
static int __init virtio_mmio_init(void)
{
return platform_driver_register(&virtio_mmio_driver);
}
static void __exit virtio_mmio_exit(void)
{
platform_driver_unregister(&virtio_mmio_driver);
vm_unregister_cmdline_devices();
}
