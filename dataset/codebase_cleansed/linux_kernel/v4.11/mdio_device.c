void mdio_device_free(struct mdio_device *mdiodev)
{
put_device(&mdiodev->dev);
}
static void mdio_device_release(struct device *dev)
{
kfree(to_mdio_device(dev));
}
int mdio_device_bus_match(struct device *dev, struct device_driver *drv)
{
struct mdio_device *mdiodev = to_mdio_device(dev);
struct mdio_driver *mdiodrv = to_mdio_driver(drv);
if (mdiodrv->mdiodrv.flags & MDIO_DEVICE_IS_PHY)
return 0;
return strcmp(mdiodev->modalias, drv->name) == 0;
}
struct mdio_device *mdio_device_create(struct mii_bus *bus, int addr)
{
struct mdio_device *mdiodev;
mdiodev = kzalloc(sizeof(*mdiodev), GFP_KERNEL);
if (!mdiodev)
return ERR_PTR(-ENOMEM);
mdiodev->dev.release = mdio_device_release;
mdiodev->dev.parent = &bus->dev;
mdiodev->dev.bus = &mdio_bus_type;
mdiodev->device_free = mdio_device_free;
mdiodev->device_remove = mdio_device_remove;
mdiodev->bus = bus;
mdiodev->addr = addr;
dev_set_name(&mdiodev->dev, PHY_ID_FMT, bus->id, addr);
device_initialize(&mdiodev->dev);
return mdiodev;
}
int mdio_device_register(struct mdio_device *mdiodev)
{
int err;
dev_dbg(&mdiodev->dev, "mdio_device_register\n");
err = mdiobus_register_device(mdiodev);
if (err)
return err;
err = device_add(&mdiodev->dev);
if (err) {
pr_err("MDIO %d failed to add\n", mdiodev->addr);
goto out;
}
return 0;
out:
mdiobus_unregister_device(mdiodev);
return err;
}
void mdio_device_remove(struct mdio_device *mdiodev)
{
device_del(&mdiodev->dev);
mdiobus_unregister_device(mdiodev);
}
static int mdio_probe(struct device *dev)
{
struct mdio_device *mdiodev = to_mdio_device(dev);
struct device_driver *drv = mdiodev->dev.driver;
struct mdio_driver *mdiodrv = to_mdio_driver(drv);
int err = 0;
if (mdiodrv->probe)
err = mdiodrv->probe(mdiodev);
return err;
}
static int mdio_remove(struct device *dev)
{
struct mdio_device *mdiodev = to_mdio_device(dev);
struct device_driver *drv = mdiodev->dev.driver;
struct mdio_driver *mdiodrv = to_mdio_driver(drv);
if (mdiodrv->remove)
mdiodrv->remove(mdiodev);
return 0;
}
int mdio_driver_register(struct mdio_driver *drv)
{
struct mdio_driver_common *mdiodrv = &drv->mdiodrv;
int retval;
pr_debug("mdio_driver_register: %s\n", mdiodrv->driver.name);
mdiodrv->driver.bus = &mdio_bus_type;
mdiodrv->driver.probe = mdio_probe;
mdiodrv->driver.remove = mdio_remove;
retval = driver_register(&mdiodrv->driver);
if (retval) {
pr_err("%s: Error %d in registering driver\n",
mdiodrv->driver.name, retval);
return retval;
}
return 0;
}
void mdio_driver_unregister(struct mdio_driver *drv)
{
struct mdio_driver_common *mdiodrv = &drv->mdiodrv;
driver_unregister(&mdiodrv->driver);
}
