static int umc_bus_pre_reset_helper(struct device *dev, void *data)
{
int ret = 0;
if (dev->driver) {
struct umc_dev *umc = to_umc_dev(dev);
struct umc_driver *umc_drv = to_umc_driver(dev->driver);
if (umc_drv->pre_reset)
ret = umc_drv->pre_reset(umc);
else
device_release_driver(dev);
}
return ret;
}
static int umc_bus_post_reset_helper(struct device *dev, void *data)
{
int ret = 0;
if (dev->driver) {
struct umc_dev *umc = to_umc_dev(dev);
struct umc_driver *umc_drv = to_umc_driver(dev->driver);
if (umc_drv->post_reset)
ret = umc_drv->post_reset(umc);
} else
ret = device_attach(dev);
return ret;
}
int umc_controller_reset(struct umc_dev *umc)
{
struct device *parent = umc->dev.parent;
int ret = 0;
if (!device_trylock(parent))
return -EAGAIN;
ret = device_for_each_child(parent, parent, umc_bus_pre_reset_helper);
if (ret >= 0)
ret = device_for_each_child(parent, parent, umc_bus_post_reset_helper);
device_unlock(parent);
return ret;
}
int umc_match_pci_id(struct umc_driver *umc_drv, struct umc_dev *umc)
{
const struct pci_device_id *id_table = umc_drv->match_data;
struct pci_dev *pci;
if (umc->dev.parent->bus != &pci_bus_type)
return 0;
pci = to_pci_dev(umc->dev.parent);
return pci_match_id(id_table, pci) != NULL;
}
static int umc_bus_rescan_helper(struct device *dev, void *data)
{
int ret = 0;
if (!dev->driver)
ret = device_attach(dev);
return ret;
}
static void umc_bus_rescan(struct device *parent)
{
int err;
err = device_for_each_child(parent, NULL, umc_bus_rescan_helper);
if (err < 0)
printk(KERN_WARNING "%s: rescan of bus failed: %d\n",
KBUILD_MODNAME, err);
}
static int umc_bus_match(struct device *dev, struct device_driver *drv)
{
struct umc_dev *umc = to_umc_dev(dev);
struct umc_driver *umc_driver = to_umc_driver(drv);
if (umc->cap_id == umc_driver->cap_id) {
if (umc_driver->match)
return umc_driver->match(umc_driver, umc);
else
return 1;
}
return 0;
}
static int umc_device_probe(struct device *dev)
{
struct umc_dev *umc;
struct umc_driver *umc_driver;
int err;
umc_driver = to_umc_driver(dev->driver);
umc = to_umc_dev(dev);
get_device(dev);
err = umc_driver->probe(umc);
if (err)
put_device(dev);
else
umc_bus_rescan(dev->parent);
return err;
}
static int umc_device_remove(struct device *dev)
{
struct umc_dev *umc;
struct umc_driver *umc_driver;
umc_driver = to_umc_driver(dev->driver);
umc = to_umc_dev(dev);
umc_driver->remove(umc);
put_device(dev);
return 0;
}
static int umc_device_suspend(struct device *dev, pm_message_t state)
{
struct umc_dev *umc;
struct umc_driver *umc_driver;
int err = 0;
umc = to_umc_dev(dev);
if (dev->driver) {
umc_driver = to_umc_driver(dev->driver);
if (umc_driver->suspend)
err = umc_driver->suspend(umc, state);
}
return err;
}
static int umc_device_resume(struct device *dev)
{
struct umc_dev *umc;
struct umc_driver *umc_driver;
int err = 0;
umc = to_umc_dev(dev);
if (dev->driver) {
umc_driver = to_umc_driver(dev->driver);
if (umc_driver->resume)
err = umc_driver->resume(umc);
}
return err;
}
static ssize_t capability_id_show(struct device *dev, struct device_attribute *attr, char *buf)
{
struct umc_dev *umc = to_umc_dev(dev);
return sprintf(buf, "0x%02x\n", umc->cap_id);
}
static ssize_t version_show(struct device *dev, struct device_attribute *attr, char *buf)
{
struct umc_dev *umc = to_umc_dev(dev);
return sprintf(buf, "0x%04x\n", umc->version);
}
static int __init umc_bus_init(void)
{
return bus_register(&umc_bus_type);
}
static void __exit umc_bus_exit(void)
{
bus_unregister(&umc_bus_type);
}
