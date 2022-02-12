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
for (i = 0; i < sizeof(dev->features)*8; i++)
len += sprintf(buf+len, "%c",
__virtio_test_bit(dev, i) ? '1' : '0');
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
if (drv->feature_table_legacy) {
for (i = 0; i < drv->feature_table_size_legacy; i++)
if (drv->feature_table_legacy[i] == fbit)
return;
}
BUG();
}
static void __virtio_config_changed(struct virtio_device *dev)
{
struct virtio_driver *drv = drv_to_virtio(dev->dev.driver);
if (!dev->config_enabled)
dev->config_change_pending = true;
else if (drv && drv->config_changed)
drv->config_changed(dev);
}
void virtio_config_changed(struct virtio_device *dev)
{
unsigned long flags;
spin_lock_irqsave(&dev->config_lock, flags);
__virtio_config_changed(dev);
spin_unlock_irqrestore(&dev->config_lock, flags);
}
static void virtio_config_disable(struct virtio_device *dev)
{
spin_lock_irq(&dev->config_lock);
dev->config_enabled = false;
spin_unlock_irq(&dev->config_lock);
}
static void virtio_config_enable(struct virtio_device *dev)
{
spin_lock_irq(&dev->config_lock);
dev->config_enabled = true;
if (dev->config_change_pending)
__virtio_config_changed(dev);
dev->config_change_pending = false;
spin_unlock_irq(&dev->config_lock);
}
static int virtio_finalize_features(struct virtio_device *dev)
{
int ret = dev->config->finalize_features(dev);
unsigned status;
if (ret)
return ret;
if (!virtio_has_feature(dev, VIRTIO_F_VERSION_1))
return 0;
add_status(dev, VIRTIO_CONFIG_S_FEATURES_OK);
status = dev->config->get_status(dev);
if (!(status & VIRTIO_CONFIG_S_FEATURES_OK)) {
dev_err(&dev->dev, "virtio: device refuses features: %x\n",
status);
return -ENODEV;
}
return 0;
}
static int virtio_dev_probe(struct device *_d)
{
int err, i;
struct virtio_device *dev = dev_to_virtio(_d);
struct virtio_driver *drv = drv_to_virtio(dev->dev.driver);
u64 device_features;
u64 driver_features;
u64 driver_features_legacy;
add_status(dev, VIRTIO_CONFIG_S_DRIVER);
device_features = dev->config->get_features(dev);
driver_features = 0;
for (i = 0; i < drv->feature_table_size; i++) {
unsigned int f = drv->feature_table[i];
BUG_ON(f >= 64);
driver_features |= (1ULL << f);
}
if (drv->feature_table_legacy) {
driver_features_legacy = 0;
for (i = 0; i < drv->feature_table_size_legacy; i++) {
unsigned int f = drv->feature_table_legacy[i];
BUG_ON(f >= 64);
driver_features_legacy |= (1ULL << f);
}
} else {
driver_features_legacy = driver_features;
}
if (device_features & (1ULL << VIRTIO_F_VERSION_1))
dev->features = driver_features & device_features;
else
dev->features = driver_features_legacy & device_features;
for (i = VIRTIO_TRANSPORT_F_START; i < VIRTIO_TRANSPORT_F_END; i++)
if (device_features & (1ULL << i))
__virtio_set_bit(dev, i);
err = virtio_finalize_features(dev);
if (err)
goto err;
err = drv->probe(dev);
if (err)
goto err;
if (!(dev->config->get_status(dev) & VIRTIO_CONFIG_S_DRIVER_OK))
virtio_device_ready(dev);
if (drv->scan)
drv->scan(dev);
virtio_config_enable(dev);
return 0;
err:
add_status(dev, VIRTIO_CONFIG_S_FAILED);
return err;
}
static int virtio_dev_remove(struct device *_d)
{
struct virtio_device *dev = dev_to_virtio(_d);
struct virtio_driver *drv = drv_to_virtio(dev->dev.driver);
virtio_config_disable(dev);
drv->remove(dev);
WARN_ON_ONCE(dev->config->get_status(dev));
add_status(dev, VIRTIO_CONFIG_S_ACKNOWLEDGE);
return 0;
}
bool virtio_device_is_legacy_only(struct virtio_device_id id)
{
return id.device == VIRTIO_ID_BALLOON;
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
spin_lock_init(&dev->config_lock);
dev->config_enabled = false;
dev->config_change_pending = false;
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
int virtio_device_freeze(struct virtio_device *dev)
{
struct virtio_driver *drv = drv_to_virtio(dev->dev.driver);
virtio_config_disable(dev);
dev->failed = dev->config->get_status(dev) & VIRTIO_CONFIG_S_FAILED;
if (drv && drv->freeze)
return drv->freeze(dev);
return 0;
}
int virtio_device_restore(struct virtio_device *dev)
{
struct virtio_driver *drv = drv_to_virtio(dev->dev.driver);
int ret;
dev->config->reset(dev);
add_status(dev, VIRTIO_CONFIG_S_ACKNOWLEDGE);
if (dev->failed)
add_status(dev, VIRTIO_CONFIG_S_FAILED);
if (!drv)
return 0;
add_status(dev, VIRTIO_CONFIG_S_DRIVER);
ret = virtio_finalize_features(dev);
if (ret)
goto err;
if (drv->restore) {
ret = drv->restore(dev);
if (ret)
goto err;
}
add_status(dev, VIRTIO_CONFIG_S_DRIVER_OK);
virtio_config_enable(dev);
return 0;
err:
add_status(dev, VIRTIO_CONFIG_S_FAILED);
return ret;
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
