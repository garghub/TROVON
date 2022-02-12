static struct i2c_client *of_i2c_register_device(struct i2c_adapter *adap,
struct device_node *node)
{
struct i2c_client *result;
struct i2c_board_info info = {};
struct dev_archdata dev_ad = {};
const __be32 *addr_be;
u32 addr;
int len;
dev_dbg(&adap->dev, "of_i2c: register %pOF\n", node);
if (of_modalias_node(node, info.type, sizeof(info.type)) < 0) {
dev_err(&adap->dev, "of_i2c: modalias failure on %pOF\n",
node);
return ERR_PTR(-EINVAL);
}
addr_be = of_get_property(node, "reg", &len);
if (!addr_be || (len < sizeof(*addr_be))) {
dev_err(&adap->dev, "of_i2c: invalid reg on %pOF\n", node);
return ERR_PTR(-EINVAL);
}
addr = be32_to_cpup(addr_be);
if (addr & I2C_TEN_BIT_ADDRESS) {
addr &= ~I2C_TEN_BIT_ADDRESS;
info.flags |= I2C_CLIENT_TEN;
}
if (addr & I2C_OWN_SLAVE_ADDRESS) {
addr &= ~I2C_OWN_SLAVE_ADDRESS;
info.flags |= I2C_CLIENT_SLAVE;
}
if (i2c_check_addr_validity(addr, info.flags)) {
dev_err(&adap->dev, "of_i2c: invalid addr=%x on %pOF\n",
addr, node);
return ERR_PTR(-EINVAL);
}
info.addr = addr;
info.of_node = of_node_get(node);
info.archdata = &dev_ad;
if (of_property_read_bool(node, "host-notify"))
info.flags |= I2C_CLIENT_HOST_NOTIFY;
if (of_get_property(node, "wakeup-source", NULL))
info.flags |= I2C_CLIENT_WAKE;
result = i2c_new_device(adap, &info);
if (result == NULL) {
dev_err(&adap->dev, "of_i2c: Failure registering %pOF\n", node);
of_node_put(node);
return ERR_PTR(-EINVAL);
}
return result;
}
void of_i2c_register_devices(struct i2c_adapter *adap)
{
struct device_node *bus, *node;
struct i2c_client *client;
if (!adap->dev.of_node)
return;
dev_dbg(&adap->dev, "of_i2c: walking child nodes\n");
bus = of_get_child_by_name(adap->dev.of_node, "i2c-bus");
if (!bus)
bus = of_node_get(adap->dev.of_node);
for_each_available_child_of_node(bus, node) {
if (of_node_test_and_set_flag(node, OF_POPULATED))
continue;
client = of_i2c_register_device(adap, node);
if (IS_ERR(client)) {
dev_warn(&adap->dev,
"Failed to create I2C device for %pOF\n",
node);
of_node_clear_flag(node, OF_POPULATED);
}
}
of_node_put(bus);
}
static int of_dev_node_match(struct device *dev, void *data)
{
return dev->of_node == data;
}
struct i2c_client *of_find_i2c_device_by_node(struct device_node *node)
{
struct device *dev;
struct i2c_client *client;
dev = bus_find_device(&i2c_bus_type, NULL, node, of_dev_node_match);
if (!dev)
return NULL;
client = i2c_verify_client(dev);
if (!client)
put_device(dev);
return client;
}
struct i2c_adapter *of_find_i2c_adapter_by_node(struct device_node *node)
{
struct device *dev;
struct i2c_adapter *adapter;
dev = bus_find_device(&i2c_bus_type, NULL, node, of_dev_node_match);
if (!dev)
return NULL;
adapter = i2c_verify_adapter(dev);
if (!adapter)
put_device(dev);
return adapter;
}
struct i2c_adapter *of_get_i2c_adapter_by_node(struct device_node *node)
{
struct i2c_adapter *adapter;
adapter = of_find_i2c_adapter_by_node(node);
if (!adapter)
return NULL;
if (!try_module_get(adapter->owner)) {
put_device(&adapter->dev);
adapter = NULL;
}
return adapter;
}
static const struct of_device_id*
i2c_of_match_device_sysfs(const struct of_device_id *matches,
struct i2c_client *client)
{
const char *name;
for (; matches->compatible[0]; matches++) {
if (sysfs_streq(client->name, matches->compatible))
return matches;
name = strchr(matches->compatible, ',');
if (!name)
name = matches->compatible;
else
name++;
if (sysfs_streq(client->name, name))
return matches;
}
return NULL;
}
const struct of_device_id
*i2c_of_match_device(const struct of_device_id *matches,
struct i2c_client *client)
{
const struct of_device_id *match;
if (!(client && matches))
return NULL;
match = of_match_device(matches, &client->dev);
if (match)
return match;
return i2c_of_match_device_sysfs(matches, client);
}
static int of_i2c_notify(struct notifier_block *nb, unsigned long action,
void *arg)
{
struct of_reconfig_data *rd = arg;
struct i2c_adapter *adap;
struct i2c_client *client;
switch (of_reconfig_get_state_change(action, rd)) {
case OF_RECONFIG_CHANGE_ADD:
adap = of_find_i2c_adapter_by_node(rd->dn->parent);
if (adap == NULL)
return NOTIFY_OK;
if (of_node_test_and_set_flag(rd->dn, OF_POPULATED)) {
put_device(&adap->dev);
return NOTIFY_OK;
}
client = of_i2c_register_device(adap, rd->dn);
put_device(&adap->dev);
if (IS_ERR(client)) {
dev_err(&adap->dev, "failed to create client for '%pOF'\n",
rd->dn);
of_node_clear_flag(rd->dn, OF_POPULATED);
return notifier_from_errno(PTR_ERR(client));
}
break;
case OF_RECONFIG_CHANGE_REMOVE:
if (!of_node_check_flag(rd->dn, OF_POPULATED))
return NOTIFY_OK;
client = of_find_i2c_device_by_node(rd->dn);
if (client == NULL)
return NOTIFY_OK;
i2c_unregister_device(client);
put_device(&client->dev);
break;
}
return NOTIFY_OK;
}
