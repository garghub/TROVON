static int isp1301_probe(struct i2c_client *client,
const struct i2c_device_id *i2c_id)
{
isp1301_i2c_client = client;
return 0;
}
static int isp1301_remove(struct i2c_client *client)
{
return 0;
}
static int match(struct device *dev, void *data)
{
struct device_node *node = (struct device_node *)data;
return (dev->of_node == node) &&
(dev->driver == &isp1301_driver.driver);
}
struct i2c_client *isp1301_get_client(struct device_node *node)
{
if (node) {
struct device *dev = bus_find_device(&i2c_bus_type, NULL,
node, match);
if (!dev)
return NULL;
return to_i2c_client(dev);
} else {
return isp1301_i2c_client;
}
}
