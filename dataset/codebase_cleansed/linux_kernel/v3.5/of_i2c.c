void of_i2c_register_devices(struct i2c_adapter *adap)
{
void *result;
struct device_node *node;
if (!adap->dev.of_node)
return;
dev_dbg(&adap->dev, "of_i2c: walking child nodes\n");
for_each_child_of_node(adap->dev.of_node, node) {
struct i2c_board_info info = {};
struct dev_archdata dev_ad = {};
const __be32 *addr;
int len;
dev_dbg(&adap->dev, "of_i2c: register %s\n", node->full_name);
if (of_modalias_node(node, info.type, sizeof(info.type)) < 0) {
dev_err(&adap->dev, "of_i2c: modalias failure on %s\n",
node->full_name);
continue;
}
addr = of_get_property(node, "reg", &len);
if (!addr || (len < sizeof(int))) {
dev_err(&adap->dev, "of_i2c: invalid reg on %s\n",
node->full_name);
continue;
}
info.addr = be32_to_cpup(addr);
if (info.addr > (1 << 10) - 1) {
dev_err(&adap->dev, "of_i2c: invalid addr=%x on %s\n",
info.addr, node->full_name);
continue;
}
info.irq = irq_of_parse_and_map(node, 0);
info.of_node = of_node_get(node);
info.archdata = &dev_ad;
request_module("%s%s", I2C_MODULE_PREFIX, info.type);
result = i2c_new_device(adap, &info);
if (result == NULL) {
dev_err(&adap->dev, "of_i2c: Failure registering %s\n",
node->full_name);
of_node_put(node);
irq_dispose_mapping(info.irq);
continue;
}
}
}
static int of_dev_node_match(struct device *dev, void *data)
{
return dev->of_node == data;
}
struct i2c_client *of_find_i2c_device_by_node(struct device_node *node)
{
struct device *dev;
dev = bus_find_device(&i2c_bus_type, NULL, node,
of_dev_node_match);
if (!dev)
return NULL;
return i2c_verify_client(dev);
}
struct i2c_adapter *of_find_i2c_adapter_by_node(struct device_node *node)
{
struct device *dev;
dev = bus_find_device(&i2c_bus_type, NULL, node,
of_dev_node_match);
if (!dev)
return NULL;
return i2c_verify_adapter(dev);
}
