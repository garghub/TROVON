static ssize_t device_show(struct device *d,
struct device_attribute *attr, char *buf)
{
struct vop_device *dev = dev_to_vop(d);
return sprintf(buf, "0x%04x\n", dev->id.device);
}
static ssize_t vendor_show(struct device *d,
struct device_attribute *attr, char *buf)
{
struct vop_device *dev = dev_to_vop(d);
return sprintf(buf, "0x%04x\n", dev->id.vendor);
}
static ssize_t modalias_show(struct device *d,
struct device_attribute *attr, char *buf)
{
struct vop_device *dev = dev_to_vop(d);
return sprintf(buf, "vop:d%08Xv%08X\n",
dev->id.device, dev->id.vendor);
}
static inline int vop_id_match(const struct vop_device *dev,
const struct vop_device_id *id)
{
if (id->device != dev->id.device && id->device != VOP_DEV_ANY_ID)
return 0;
return id->vendor == VOP_DEV_ANY_ID || id->vendor == dev->id.vendor;
}
static int vop_dev_match(struct device *dv, struct device_driver *dr)
{
unsigned int i;
struct vop_device *dev = dev_to_vop(dv);
const struct vop_device_id *ids;
ids = drv_to_vop(dr)->id_table;
for (i = 0; ids[i].device; i++)
if (vop_id_match(dev, &ids[i]))
return 1;
return 0;
}
static int vop_uevent(struct device *dv, struct kobj_uevent_env *env)
{
struct vop_device *dev = dev_to_vop(dv);
return add_uevent_var(env, "MODALIAS=vop:d%08Xv%08X",
dev->id.device, dev->id.vendor);
}
static int vop_dev_probe(struct device *d)
{
struct vop_device *dev = dev_to_vop(d);
struct vop_driver *drv = drv_to_vop(dev->dev.driver);
return drv->probe(dev);
}
static int vop_dev_remove(struct device *d)
{
struct vop_device *dev = dev_to_vop(d);
struct vop_driver *drv = drv_to_vop(dev->dev.driver);
drv->remove(dev);
return 0;
}
int vop_register_driver(struct vop_driver *driver)
{
driver->driver.bus = &vop_bus;
return driver_register(&driver->driver);
}
void vop_unregister_driver(struct vop_driver *driver)
{
driver_unregister(&driver->driver);
}
static void vop_release_dev(struct device *d)
{
put_device(d);
}
struct vop_device *
vop_register_device(struct device *pdev, int id,
const struct dma_map_ops *dma_ops,
struct vop_hw_ops *hw_ops, u8 dnode, struct mic_mw *aper,
struct dma_chan *chan)
{
int ret;
struct vop_device *vdev;
vdev = kzalloc(sizeof(*vdev), GFP_KERNEL);
if (!vdev)
return ERR_PTR(-ENOMEM);
vdev->dev.parent = pdev;
vdev->id.device = id;
vdev->id.vendor = VOP_DEV_ANY_ID;
vdev->dev.archdata.dma_ops = (struct dma_map_ops *)dma_ops;
vdev->dev.dma_mask = &vdev->dev.coherent_dma_mask;
dma_set_mask(&vdev->dev, DMA_BIT_MASK(64));
vdev->dev.release = vop_release_dev;
vdev->hw_ops = hw_ops;
vdev->dev.bus = &vop_bus;
vdev->dnode = dnode;
vdev->aper = aper;
vdev->dma_ch = chan;
vdev->index = dnode - 1;
dev_set_name(&vdev->dev, "vop-dev%u", vdev->index);
ret = device_register(&vdev->dev);
if (ret)
goto free_vdev;
return vdev;
free_vdev:
kfree(vdev);
return ERR_PTR(ret);
}
void vop_unregister_device(struct vop_device *dev)
{
device_unregister(&dev->dev);
}
static int __init vop_init(void)
{
return bus_register(&vop_bus);
}
static void __exit vop_exit(void)
{
bus_unregister(&vop_bus);
}
