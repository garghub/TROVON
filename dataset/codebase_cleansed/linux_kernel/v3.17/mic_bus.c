static ssize_t device_show(struct device *d,
struct device_attribute *attr, char *buf)
{
struct mbus_device *dev = dev_to_mbus(d);
return sprintf(buf, "0x%04x\n", dev->id.device);
}
static ssize_t vendor_show(struct device *d,
struct device_attribute *attr, char *buf)
{
struct mbus_device *dev = dev_to_mbus(d);
return sprintf(buf, "0x%04x\n", dev->id.vendor);
}
static ssize_t modalias_show(struct device *d,
struct device_attribute *attr, char *buf)
{
struct mbus_device *dev = dev_to_mbus(d);
return sprintf(buf, "mbus:d%08Xv%08X\n",
dev->id.device, dev->id.vendor);
}
static inline int mbus_id_match(const struct mbus_device *dev,
const struct mbus_device_id *id)
{
if (id->device != dev->id.device && id->device != MBUS_DEV_ANY_ID)
return 0;
return id->vendor == MBUS_DEV_ANY_ID || id->vendor == dev->id.vendor;
}
static int mbus_dev_match(struct device *dv, struct device_driver *dr)
{
unsigned int i;
struct mbus_device *dev = dev_to_mbus(dv);
const struct mbus_device_id *ids;
ids = drv_to_mbus(dr)->id_table;
for (i = 0; ids[i].device; i++)
if (mbus_id_match(dev, &ids[i]))
return 1;
return 0;
}
static int mbus_uevent(struct device *dv, struct kobj_uevent_env *env)
{
struct mbus_device *dev = dev_to_mbus(dv);
return add_uevent_var(env, "MODALIAS=mbus:d%08Xv%08X",
dev->id.device, dev->id.vendor);
}
static int mbus_dev_probe(struct device *d)
{
int err;
struct mbus_device *dev = dev_to_mbus(d);
struct mbus_driver *drv = drv_to_mbus(dev->dev.driver);
err = drv->probe(dev);
if (!err)
if (drv->scan)
drv->scan(dev);
return err;
}
static int mbus_dev_remove(struct device *d)
{
struct mbus_device *dev = dev_to_mbus(d);
struct mbus_driver *drv = drv_to_mbus(dev->dev.driver);
drv->remove(dev);
return 0;
}
int mbus_register_driver(struct mbus_driver *driver)
{
driver->driver.bus = &mic_bus;
return driver_register(&driver->driver);
}
void mbus_unregister_driver(struct mbus_driver *driver)
{
driver_unregister(&driver->driver);
}
static void mbus_release_dev(struct device *d)
{
struct mbus_device *mbdev = dev_to_mbus(d);
kfree(mbdev);
}
struct mbus_device *
mbus_register_device(struct device *pdev, int id, struct dma_map_ops *dma_ops,
struct mbus_hw_ops *hw_ops, void __iomem *mmio_va)
{
int ret;
struct mbus_device *mbdev;
mbdev = kzalloc(sizeof(*mbdev), GFP_KERNEL);
if (!mbdev)
return ERR_PTR(-ENOMEM);
mbdev->mmio_va = mmio_va;
mbdev->dev.parent = pdev;
mbdev->id.device = id;
mbdev->id.vendor = MBUS_DEV_ANY_ID;
mbdev->dev.archdata.dma_ops = dma_ops;
mbdev->dev.dma_mask = &mbdev->dev.coherent_dma_mask;
dma_set_mask(&mbdev->dev, DMA_BIT_MASK(64));
mbdev->dev.release = mbus_release_dev;
mbdev->hw_ops = hw_ops;
mbdev->dev.bus = &mic_bus;
ret = ida_simple_get(&mbus_index_ida, 0, 0, GFP_KERNEL);
if (ret < 0)
goto free_mbdev;
mbdev->index = ret;
dev_set_name(&mbdev->dev, "mbus-dev%u", mbdev->index);
ret = device_register(&mbdev->dev);
if (ret)
goto ida_remove;
return mbdev;
ida_remove:
ida_simple_remove(&mbus_index_ida, mbdev->index);
free_mbdev:
kfree(mbdev);
return ERR_PTR(ret);
}
void mbus_unregister_device(struct mbus_device *mbdev)
{
int index = mbdev->index;
device_unregister(&mbdev->dev);
ida_simple_remove(&mbus_index_ida, index);
}
static int __init mbus_init(void)
{
return bus_register(&mic_bus);
}
static void __exit mbus_exit(void)
{
bus_unregister(&mic_bus);
ida_destroy(&mbus_index_ida);
}
