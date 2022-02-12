static ssize_t device_show(struct device *_d,
struct device_attribute *attr, char *buf)
{
struct virtio_device *dev = dev_to_virtio(_d);
return sprintf(buf, "0x%04x\n", dev->id.device);
}
static ssize_t vendor_show(struct device *_d,
struct device_attribute *attr, char *buf)
{
struct virtio_device *dev = dev_to_virtio(_d);
return sprintf(buf, "0x%04x\n", dev->id.vendor);
}
static ssize_t status_show(struct device *_d,
struct device_attribute *attr, char *buf)
{
struct virtio_device *dev = dev_to_virtio(_d);
return sprintf(buf, "0x%08x\n", dev->config->get_status(dev));
}
static ssize_t modalias_show(struct device *_d,
struct device_attribute *attr, char *buf)
{
struct virtio_device *dev = dev_to_virtio(_d);
return sprintf(buf, "virtio:d%08Xv%08X\n",
dev->id.device, dev->id.vendor);
}
static ssize_t features_show(struct device *_d,
struct device_attribute *attr, char *buf)
{
struct virtio_device *dev = dev_to_virtio(_d);
unsigned int i;
ssize_t len = 0;
for (i = 0; i < ARRAY_SIZE(dev->features)*BITS_PER_LONG; i++)
len += sprintf(buf+len, "%c",
test_bit(i, dev->features) ? '1' : '0');
len += sprintf(buf+len, "\n");
return len;
}
static inline int virtio_id_match(const struct virtio_device *dev,
const struct virtio_device_id *id)
{
if (id->device != dev->id.device && id->device != VIRTIO_DEV_ANY_ID)
return 0;
return id->vendor == VIRTIO_DEV_ANY_ID || id->vendor == dev->id.vendor;
}
static int virtio_dev_match(struct device *_dv, struct device_driver *_dr)
{
unsigned int i;
struct virtio_device *dev = dev_to_virtio(_dv);
const struct virtio_device_id *ids;
ids = drv_to_virtio(_dr)->id_table;
for (i = 0; ids[i].device; i++)
if (virtio_id_match(dev, &ids[i]))
return 1;
return 0;
}
static int virtio_uevent(struct device *_dv, struct kobj_uevent_env *env)
{
struct virtio_device *dev = dev_to_virtio(_dv);
return add_uevent_var(env, "MODALIAS=virtio:d%08Xv%08X",
dev->id.device, dev->id.vendor);
}
static void add_status(struct virtio_device *dev, unsigned status)
{
dev->config->set_status(dev, dev->config->get_status(dev) | status);
}
void virtio_check_driver_offered_feature(const struct virtio_device *vdev,
unsigned int fbit)
{
unsigned int i;
struct virtio_driver *drv = drv_to_virtio(vdev->dev.driver);
for (i = 0; i < drv->feature_table_size; i++)
if (drv->feature_table[i] == fbit)
return;
BUG();
}
static int virtio_dev_probe(struct device *_d)
{
int err, i;
struct virtio_device *dev = dev_to_virtio(_d);
struct virtio_driver *drv = drv_to_virtio(dev->dev.driver);
u32 device_features;
add_status(dev, VIRTIO_CONFIG_S_DRIVER);
device_features = dev->config->get_features(dev);
memset(dev->features, 0, sizeof(dev->features));
for (i = 0; i < drv->feature_table_size; i++) {
unsigned int f = drv->feature_table[i];
BUG_ON(f >= 32);
if (device_features & (1 << f))
set_bit(f, dev->features);
}
for (i = VIRTIO_TRANSPORT_F_START; i < VIRTIO_TRANSPORT_F_END; i++)
if (device_features & (1 << i))
set_bit(i, dev->features);
dev->config->finalize_features(dev);
err = drv->probe(dev);
if (err)
add_status(dev, VIRTIO_CONFIG_S_FAILED);
else {
add_status(dev, VIRTIO_CONFIG_S_DRIVER_OK);
if (drv->scan)
drv->scan(dev);
}
return err;
}
static int virtio_dev_remove(struct device *_d)
{
struct virtio_device *dev = dev_to_virtio(_d);
struct virtio_driver *drv = drv_to_virtio(dev->dev.driver);
drv->remove(dev);
WARN_ON_ONCE(dev->config->get_status(dev));
add_status(dev, VIRTIO_CONFIG_S_ACKNOWLEDGE);
return 0;
}
int register_virtio_driver(struct virtio_driver *driver)
{
BUG_ON(driver->feature_table_size && !driver->feature_table);
driver->driver.bus = &virtio_bus;
return driver_register(&driver->driver);
}
void unregister_virtio_driver(struct virtio_driver *driver)
{
driver_unregister(&driver->driver);
}
int register_virtio_device(struct virtio_device *dev)
{
int err;
dev->dev.bus = &virtio_bus;
err = ida_simple_get(&virtio_index_ida, 0, 0, GFP_KERNEL);
if (err < 0)
goto out;
dev->index = err;
dev_set_name(&dev->dev, "virtio%u", dev->index);
dev->config->reset(dev);
add_status(dev, VIRTIO_CONFIG_S_ACKNOWLEDGE);
INIT_LIST_HEAD(&dev->vqs);
err = device_register(&dev->dev);
out:
if (err)
add_status(dev, VIRTIO_CONFIG_S_FAILED);
return err;
}
void unregister_virtio_device(struct virtio_device *dev)
{
int index = dev->index;
device_unregister(&dev->dev);
ida_simple_remove(&virtio_index_ida, index);
}
static int virtio_init(void)
{
if (bus_register(&virtio_bus) != 0)
panic("virtio bus registration failed");
return 0;
}
static void __exit virtio_exit(void)
{
bus_unregister(&virtio_bus);
}
