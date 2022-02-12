static struct kvm_vqconfig *kvm_vq_config(const struct kvm_device_desc *desc)
{
return (struct kvm_vqconfig *)(desc + 1);
}
static u8 *kvm_vq_features(const struct kvm_device_desc *desc)
{
return (u8 *)(kvm_vq_config(desc) + desc->num_vq);
}
static u8 *kvm_vq_configspace(const struct kvm_device_desc *desc)
{
return kvm_vq_features(desc) + desc->feature_len * 2;
}
static unsigned desc_size(const struct kvm_device_desc *desc)
{
return sizeof(*desc)
+ desc->num_vq * sizeof(struct kvm_vqconfig)
+ desc->feature_len * 2
+ desc->config_len;
}
static u64 kvm_get_features(struct virtio_device *vdev)
{
unsigned int i;
u32 features = 0;
struct kvm_device_desc *desc = to_kvmdev(vdev)->desc;
u8 *in_features = kvm_vq_features(desc);
for (i = 0; i < min(desc->feature_len * 8, 32); i++)
if (in_features[i / 8] & (1 << (i % 8)))
features |= (1 << i);
return features;
}
static int kvm_finalize_features(struct virtio_device *vdev)
{
unsigned int i, bits;
struct kvm_device_desc *desc = to_kvmdev(vdev)->desc;
u8 *out_features = kvm_vq_features(desc) + desc->feature_len;
vring_transport_features(vdev);
BUG_ON((u32)vdev->features != vdev->features);
memset(out_features, 0, desc->feature_len);
bits = min_t(unsigned, desc->feature_len, sizeof(vdev->features)) * 8;
for (i = 0; i < bits; i++) {
if (__virtio_test_bit(vdev, i))
out_features[i / 8] |= (1 << (i % 8));
}
return 0;
}
static void kvm_get(struct virtio_device *vdev, unsigned int offset,
void *buf, unsigned len)
{
struct kvm_device_desc *desc = to_kvmdev(vdev)->desc;
BUG_ON(offset + len > desc->config_len);
memcpy(buf, kvm_vq_configspace(desc) + offset, len);
}
static void kvm_set(struct virtio_device *vdev, unsigned int offset,
const void *buf, unsigned len)
{
struct kvm_device_desc *desc = to_kvmdev(vdev)->desc;
BUG_ON(offset + len > desc->config_len);
memcpy(kvm_vq_configspace(desc) + offset, buf, len);
}
static u8 kvm_get_status(struct virtio_device *vdev)
{
return to_kvmdev(vdev)->desc->status;
}
static void kvm_set_status(struct virtio_device *vdev, u8 status)
{
BUG_ON(!status);
to_kvmdev(vdev)->desc->status = status;
kvm_hypercall1(KVM_S390_VIRTIO_SET_STATUS,
(unsigned long) to_kvmdev(vdev)->desc);
}
static void kvm_reset(struct virtio_device *vdev)
{
kvm_hypercall1(KVM_S390_VIRTIO_RESET,
(unsigned long) to_kvmdev(vdev)->desc);
}
static bool kvm_notify(struct virtqueue *vq)
{
long rc;
struct kvm_vqconfig *config = vq->priv;
rc = kvm_hypercall1(KVM_S390_VIRTIO_NOTIFY, config->address);
if (rc < 0)
return false;
return true;
}
static struct virtqueue *kvm_find_vq(struct virtio_device *vdev,
unsigned index,
void (*callback)(struct virtqueue *vq),
const char *name)
{
struct kvm_device *kdev = to_kvmdev(vdev);
struct kvm_vqconfig *config;
struct virtqueue *vq;
int err;
if (index >= kdev->desc->num_vq)
return ERR_PTR(-ENOENT);
if (!name)
return NULL;
config = kvm_vq_config(kdev->desc)+index;
err = vmem_add_mapping(config->address,
vring_size(config->num,
KVM_S390_VIRTIO_RING_ALIGN));
if (err)
goto out;
vq = vring_new_virtqueue(index, config->num, KVM_S390_VIRTIO_RING_ALIGN,
vdev, true, (void *) config->address,
kvm_notify, callback, name);
if (!vq) {
err = -ENOMEM;
goto unmap;
}
config->token = (u64) vq;
vq->priv = config;
return vq;
unmap:
vmem_remove_mapping(config->address,
vring_size(config->num,
KVM_S390_VIRTIO_RING_ALIGN));
out:
return ERR_PTR(err);
}
static void kvm_del_vq(struct virtqueue *vq)
{
struct kvm_vqconfig *config = vq->priv;
vring_del_virtqueue(vq);
vmem_remove_mapping(config->address,
vring_size(config->num,
KVM_S390_VIRTIO_RING_ALIGN));
}
static void kvm_del_vqs(struct virtio_device *vdev)
{
struct virtqueue *vq, *n;
list_for_each_entry_safe(vq, n, &vdev->vqs, list)
kvm_del_vq(vq);
}
static int kvm_find_vqs(struct virtio_device *vdev, unsigned nvqs,
struct virtqueue *vqs[],
vq_callback_t *callbacks[],
const char * const names[])
{
struct kvm_device *kdev = to_kvmdev(vdev);
int i;
if (nvqs > kdev->desc->num_vq)
return -ENOENT;
for (i = 0; i < nvqs; ++i) {
vqs[i] = kvm_find_vq(vdev, i, callbacks[i], names[i]);
if (IS_ERR(vqs[i]))
goto error;
}
return 0;
error:
kvm_del_vqs(vdev);
return PTR_ERR(vqs[i]);
}
static const char *kvm_bus_name(struct virtio_device *vdev)
{
return "";
}
static void add_kvm_device(struct kvm_device_desc *d, unsigned int offset)
{
struct kvm_device *kdev;
kdev = kzalloc(sizeof(*kdev), GFP_KERNEL);
if (!kdev) {
printk(KERN_EMERG "Cannot allocate kvm dev %u type %u\n",
offset, d->type);
return;
}
kdev->vdev.dev.parent = kvm_root;
kdev->vdev.id.device = d->type;
kdev->vdev.config = &kvm_vq_configspace_ops;
kdev->desc = d;
if (register_virtio_device(&kdev->vdev) != 0) {
printk(KERN_ERR "Failed to register kvm device %u type %u\n",
offset, d->type);
kfree(kdev);
}
}
static void scan_devices(void)
{
unsigned int i;
struct kvm_device_desc *d;
for (i = 0; i < PAGE_SIZE; i += desc_size(d)) {
d = kvm_devices + i;
if (d->type == 0)
break;
add_kvm_device(d, i);
}
}
static int match_desc(struct device *dev, void *data)
{
struct virtio_device *vdev = dev_to_virtio(dev);
struct kvm_device *kdev = to_kvmdev(vdev);
return kdev->desc == data;
}
static void hotplug_devices(struct work_struct *dummy)
{
unsigned int i;
struct kvm_device_desc *d;
struct device *dev;
for (i = 0; i < PAGE_SIZE; i += desc_size(d)) {
d = kvm_devices + i;
if (d->type == 0)
break;
dev = device_find_child(kvm_root, d, match_desc);
if (dev) {
put_device(dev);
continue;
}
printk(KERN_INFO "Adding new virtio device %p\n", d);
add_kvm_device(d, i);
}
}
static void kvm_extint_handler(struct ext_code ext_code,
unsigned int param32, unsigned long param64)
{
struct virtqueue *vq;
u32 param;
if ((ext_code.subcode & 0xff00) != VIRTIO_SUBCODE_64)
return;
inc_irq_stat(IRQEXT_VRT);
vq = (struct virtqueue *)(param64 & ~1UL);
param = param32 & VIRTIO_PARAM_MASK;
switch (param) {
case VIRTIO_PARAM_CONFIG_CHANGED:
virtio_config_changed(vq->vdev);
break;
case VIRTIO_PARAM_DEV_ADD:
schedule_work(&hotplug_work);
break;
case VIRTIO_PARAM_VRING_INTERRUPT:
default:
vring_interrupt(0, vq);
break;
}
}
static int __init test_devices_support(unsigned long addr)
{
int ret = -EIO;
asm volatile(
"0: lura 0,%1\n"
"1: xgr %0,%0\n"
"2:\n"
EX_TABLE(0b,2b)
EX_TABLE(1b,2b)
: "+d" (ret)
: "a" (addr)
: "0", "cc");
return ret;
}
static int __init kvm_devices_init(void)
{
int rc;
unsigned long total_memory_size = sclp.rzm * sclp.rnmax;
if (!MACHINE_IS_KVM)
return -ENODEV;
if (test_devices_support(total_memory_size) < 0)
return -ENODEV;
pr_warn("The s390-virtio transport is deprecated. Please switch to a modern host providing virtio-ccw.\n");
rc = vmem_add_mapping(total_memory_size, PAGE_SIZE);
if (rc)
return rc;
kvm_devices = (void *) total_memory_size;
kvm_root = root_device_register("kvm_s390");
if (IS_ERR(kvm_root)) {
rc = PTR_ERR(kvm_root);
printk(KERN_ERR "Could not register kvm_s390 root device");
vmem_remove_mapping(total_memory_size, PAGE_SIZE);
return rc;
}
INIT_WORK(&hotplug_work, hotplug_devices);
irq_subclass_register(IRQ_SUBCLASS_SERVICE_SIGNAL);
register_external_irq(EXT_IRQ_CP_SERVICE, kvm_extint_handler);
scan_devices();
return 0;
}
static int early_put_chars(u32 vtermno, const char *buf, int count)
{
char scratch[17];
unsigned int len = count;
if (len > sizeof(scratch) - 1)
len = sizeof(scratch) - 1;
scratch[len] = '\0';
memcpy(scratch, buf, len);
kvm_hypercall1(KVM_S390_VIRTIO_NOTIFY, __pa(scratch));
return len;
}
static int __init s390_virtio_console_init(void)
{
if (sclp.has_vt220 || sclp.has_linemode)
return -ENODEV;
return virtio_cons_early_init(early_put_chars);
}
