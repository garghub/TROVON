int ulpi_read(struct ulpi *ulpi, u8 addr)
{
return ulpi->ops->read(ulpi->dev.parent, addr);
}
int ulpi_write(struct ulpi *ulpi, u8 addr, u8 val)
{
return ulpi->ops->write(ulpi->dev.parent, addr, val);
}
static int ulpi_match(struct device *dev, struct device_driver *driver)
{
struct ulpi_driver *drv = to_ulpi_driver(driver);
struct ulpi *ulpi = to_ulpi_dev(dev);
const struct ulpi_device_id *id;
for (id = drv->id_table; id->vendor; id++)
if (id->vendor == ulpi->id.vendor &&
id->product == ulpi->id.product)
return 1;
return 0;
}
static int ulpi_uevent(struct device *dev, struct kobj_uevent_env *env)
{
struct ulpi *ulpi = to_ulpi_dev(dev);
if (add_uevent_var(env, "MODALIAS=ulpi:v%04xp%04x",
ulpi->id.vendor, ulpi->id.product))
return -ENOMEM;
return 0;
}
static int ulpi_probe(struct device *dev)
{
struct ulpi_driver *drv = to_ulpi_driver(dev->driver);
return drv->probe(to_ulpi_dev(dev));
}
static int ulpi_remove(struct device *dev)
{
struct ulpi_driver *drv = to_ulpi_driver(dev->driver);
if (drv->remove)
drv->remove(to_ulpi_dev(dev));
return 0;
}
static ssize_t modalias_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct ulpi *ulpi = to_ulpi_dev(dev);
return sprintf(buf, "ulpi:v%04xp%04x\n",
ulpi->id.vendor, ulpi->id.product);
}
static void ulpi_dev_release(struct device *dev)
{
kfree(to_ulpi_dev(dev));
}
int __ulpi_register_driver(struct ulpi_driver *drv, struct module *module)
{
if (!drv->probe)
return -EINVAL;
drv->driver.owner = module;
drv->driver.bus = &ulpi_bus;
return driver_register(&drv->driver);
}
void ulpi_unregister_driver(struct ulpi_driver *drv)
{
driver_unregister(&drv->driver);
}
static int ulpi_register(struct device *dev, struct ulpi *ulpi)
{
int ret;
ulpi->dev.parent = dev;
ret = ulpi_write(ulpi, ULPI_SCRATCH, 0xaa);
if (ret < 0)
return ret;
ret = ulpi_read(ulpi, ULPI_SCRATCH);
if (ret < 0)
return ret;
if (ret != 0xaa)
return -ENODEV;
ulpi->id.vendor = ulpi_read(ulpi, ULPI_VENDOR_ID_LOW);
ulpi->id.vendor |= ulpi_read(ulpi, ULPI_VENDOR_ID_HIGH) << 8;
ulpi->id.product = ulpi_read(ulpi, ULPI_PRODUCT_ID_LOW);
ulpi->id.product |= ulpi_read(ulpi, ULPI_PRODUCT_ID_HIGH) << 8;
ulpi->dev.bus = &ulpi_bus;
ulpi->dev.type = &ulpi_dev_type;
dev_set_name(&ulpi->dev, "%s.ulpi", dev_name(dev));
ACPI_COMPANION_SET(&ulpi->dev, ACPI_COMPANION(dev));
request_module("ulpi:v%04xp%04x", ulpi->id.vendor, ulpi->id.product);
ret = device_register(&ulpi->dev);
if (ret)
return ret;
dev_dbg(&ulpi->dev, "registered ULPI PHY: vendor %04x, product %04x\n",
ulpi->id.vendor, ulpi->id.product);
return 0;
}
struct ulpi *ulpi_register_interface(struct device *dev,
const struct ulpi_ops *ops)
{
struct ulpi *ulpi;
int ret;
ulpi = kzalloc(sizeof(*ulpi), GFP_KERNEL);
if (!ulpi)
return ERR_PTR(-ENOMEM);
ulpi->ops = ops;
ret = ulpi_register(dev, ulpi);
if (ret) {
kfree(ulpi);
return ERR_PTR(ret);
}
return ulpi;
}
void ulpi_unregister_interface(struct ulpi *ulpi)
{
device_unregister(&ulpi->dev);
}
static int __init ulpi_init(void)
{
return bus_register(&ulpi_bus);
}
static void __exit ulpi_exit(void)
{
bus_unregister(&ulpi_bus);
}
