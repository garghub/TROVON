static int mipi_dsi_device_match(struct device *dev, struct device_driver *drv)
{
return of_driver_match_device(dev, drv);
}
static void mipi_dsi_dev_release(struct device *dev)
{
struct mipi_dsi_device *dsi = to_mipi_dsi_device(dev);
of_node_put(dev->of_node);
kfree(dsi);
}
static struct mipi_dsi_device *mipi_dsi_device_alloc(struct mipi_dsi_host *host)
{
struct mipi_dsi_device *dsi;
dsi = kzalloc(sizeof(*dsi), GFP_KERNEL);
if (!dsi)
return ERR_PTR(-ENOMEM);
dsi->host = host;
dsi->dev.bus = &mipi_dsi_bus_type;
dsi->dev.parent = host->dev;
dsi->dev.type = &mipi_dsi_device_type;
device_initialize(&dsi->dev);
return dsi;
}
static int mipi_dsi_device_add(struct mipi_dsi_device *dsi)
{
struct mipi_dsi_host *host = dsi->host;
dev_set_name(&dsi->dev, "%s.%d", dev_name(host->dev), dsi->channel);
return device_add(&dsi->dev);
}
static struct mipi_dsi_device *
of_mipi_dsi_device_add(struct mipi_dsi_host *host, struct device_node *node)
{
struct mipi_dsi_device *dsi;
struct device *dev = host->dev;
int ret;
u32 reg;
ret = of_property_read_u32(node, "reg", &reg);
if (ret) {
dev_err(dev, "device node %s has no valid reg property: %d\n",
node->full_name, ret);
return ERR_PTR(-EINVAL);
}
if (reg > 3) {
dev_err(dev, "device node %s has invalid reg property: %u\n",
node->full_name, reg);
return ERR_PTR(-EINVAL);
}
dsi = mipi_dsi_device_alloc(host);
if (IS_ERR(dsi)) {
dev_err(dev, "failed to allocate DSI device %s: %ld\n",
node->full_name, PTR_ERR(dsi));
return dsi;
}
dsi->dev.of_node = of_node_get(node);
dsi->channel = reg;
ret = mipi_dsi_device_add(dsi);
if (ret) {
dev_err(dev, "failed to add DSI device %s: %d\n",
node->full_name, ret);
kfree(dsi);
return ERR_PTR(ret);
}
return dsi;
}
int mipi_dsi_host_register(struct mipi_dsi_host *host)
{
struct device_node *node;
for_each_available_child_of_node(host->dev->of_node, node) {
if (!of_find_property(node, "reg", NULL))
continue;
of_mipi_dsi_device_add(host, node);
}
return 0;
}
static int mipi_dsi_remove_device_fn(struct device *dev, void *priv)
{
struct mipi_dsi_device *dsi = to_mipi_dsi_device(dev);
device_unregister(&dsi->dev);
return 0;
}
void mipi_dsi_host_unregister(struct mipi_dsi_host *host)
{
device_for_each_child(host->dev, NULL, mipi_dsi_remove_device_fn);
}
int mipi_dsi_attach(struct mipi_dsi_device *dsi)
{
const struct mipi_dsi_host_ops *ops = dsi->host->ops;
if (!ops || !ops->attach)
return -ENOSYS;
return ops->attach(dsi->host, dsi);
}
int mipi_dsi_detach(struct mipi_dsi_device *dsi)
{
const struct mipi_dsi_host_ops *ops = dsi->host->ops;
if (!ops || !ops->detach)
return -ENOSYS;
return ops->detach(dsi->host, dsi);
}
int mipi_dsi_dcs_write(struct mipi_dsi_device *dsi, unsigned int channel,
const void *data, size_t len)
{
const struct mipi_dsi_host_ops *ops = dsi->host->ops;
struct mipi_dsi_msg msg = {
.channel = channel,
.tx_buf = data,
.tx_len = len
};
if (!ops || !ops->transfer)
return -ENOSYS;
switch (len) {
case 0:
return -EINVAL;
case 1:
msg.type = MIPI_DSI_DCS_SHORT_WRITE;
break;
case 2:
msg.type = MIPI_DSI_DCS_SHORT_WRITE_PARAM;
break;
default:
msg.type = MIPI_DSI_DCS_LONG_WRITE;
break;
}
return ops->transfer(dsi->host, &msg);
}
ssize_t mipi_dsi_dcs_read(struct mipi_dsi_device *dsi, unsigned int channel,
u8 cmd, void *data, size_t len)
{
const struct mipi_dsi_host_ops *ops = dsi->host->ops;
struct mipi_dsi_msg msg = {
.channel = channel,
.type = MIPI_DSI_DCS_READ,
.tx_buf = &cmd,
.tx_len = 1,
.rx_buf = data,
.rx_len = len
};
if (!ops || !ops->transfer)
return -ENOSYS;
return ops->transfer(dsi->host, &msg);
}
static int mipi_dsi_drv_probe(struct device *dev)
{
struct mipi_dsi_driver *drv = to_mipi_dsi_driver(dev->driver);
struct mipi_dsi_device *dsi = to_mipi_dsi_device(dev);
return drv->probe(dsi);
}
static int mipi_dsi_drv_remove(struct device *dev)
{
struct mipi_dsi_driver *drv = to_mipi_dsi_driver(dev->driver);
struct mipi_dsi_device *dsi = to_mipi_dsi_device(dev);
return drv->remove(dsi);
}
static void mipi_dsi_drv_shutdown(struct device *dev)
{
struct mipi_dsi_driver *drv = to_mipi_dsi_driver(dev->driver);
struct mipi_dsi_device *dsi = to_mipi_dsi_device(dev);
drv->shutdown(dsi);
}
int mipi_dsi_driver_register(struct mipi_dsi_driver *drv)
{
drv->driver.bus = &mipi_dsi_bus_type;
if (drv->probe)
drv->driver.probe = mipi_dsi_drv_probe;
if (drv->remove)
drv->driver.remove = mipi_dsi_drv_remove;
if (drv->shutdown)
drv->driver.shutdown = mipi_dsi_drv_shutdown;
return driver_register(&drv->driver);
}
void mipi_dsi_driver_unregister(struct mipi_dsi_driver *drv)
{
driver_unregister(&drv->driver);
}
static int __init mipi_dsi_bus_init(void)
{
return bus_register(&mipi_dsi_bus_type);
}
