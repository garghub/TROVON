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
if (ulpi->id.vendor == 0)
return of_driver_match_device(dev, driver);
for (id = drv->id_table; id->vendor; id++)
if (id->vendor == ulpi->id.vendor &&
id->product == ulpi->id.product)
return 1;
return 0;
}
static int ulpi_uevent(struct device *dev, struct kobj_uevent_env *env)
{
struct ulpi *ulpi = to_ulpi_dev(dev);
int ret;
ret = of_device_uevent_modalias(dev, env);
if (ret != -ENODEV)
return ret;
if (add_uevent_var(env, "MODALIAS=ulpi:v%04xp%04x",
ulpi->id.vendor, ulpi->id.product))
return -ENOMEM;
return 0;
}
static int ulpi_probe(struct device *dev)
{
struct ulpi_driver *drv = to_ulpi_driver(dev->driver);
int ret;
ret = of_clk_set_defaults(dev->of_node, false);
if (ret < 0)
return ret;
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
int len;
struct ulpi *ulpi = to_ulpi_dev(dev);
len = of_device_modalias(dev, buf, PAGE_SIZE);
if (len != -ENODEV)
return len;
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
static int ulpi_of_register(struct ulpi *ulpi)
{
struct device_node *np = NULL, *child;
struct device *parent;
parent = ulpi->dev.parent;
if (parent->of_node)
np = of_find_node_by_name(parent->of_node, "ulpi");
else if (parent->parent && parent->parent->of_node)
np = of_find_node_by_name(parent->parent->of_node, "ulpi");
if (!np)
return 0;
child = of_get_next_available_child(np, NULL);
of_node_put(np);
if (!child)
return -EINVAL;
ulpi->dev.of_node = child;
return 0;
}
static int ulpi_read_id(struct ulpi *ulpi)
{
int ret;
ret = ulpi_write(ulpi, ULPI_SCRATCH, 0xaa);
if (ret < 0)
goto err;
ret = ulpi_read(ulpi, ULPI_SCRATCH);
if (ret < 0)
return ret;
if (ret != 0xaa)
goto err;
ulpi->id.vendor = ulpi_read(ulpi, ULPI_VENDOR_ID_LOW);
ulpi->id.vendor |= ulpi_read(ulpi, ULPI_VENDOR_ID_HIGH) << 8;
ulpi->id.product = ulpi_read(ulpi, ULPI_PRODUCT_ID_LOW);
ulpi->id.product |= ulpi_read(ulpi, ULPI_PRODUCT_ID_HIGH) << 8;
if (ulpi->id.vendor == 0)
goto err;
request_module("ulpi:v%04xp%04x", ulpi->id.vendor, ulpi->id.product);
return 0;
err:
of_device_request_module(&ulpi->dev);
return 0;
}
static int ulpi_register(struct device *dev, struct ulpi *ulpi)
{
int ret;
ulpi->dev.parent = dev;
ulpi->dev.bus = &ulpi_bus;
ulpi->dev.type = &ulpi_dev_type;
dev_set_name(&ulpi->dev, "%s.ulpi", dev_name(dev));
ACPI_COMPANION_SET(&ulpi->dev, ACPI_COMPANION(dev));
ret = ulpi_of_register(ulpi);
if (ret)
return ret;
ret = ulpi_read_id(ulpi);
if (ret)
return ret;
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
of_node_put(ulpi->dev.of_node);
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
