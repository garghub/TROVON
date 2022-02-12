static int wf_max6690_get(struct wf_sensor *sr, s32 *value)
{
struct wf_6690_sensor *max = wf_to_6690(sr);
s32 data;
if (max->i2c == NULL)
return -ENODEV;
data = i2c_smbus_read_byte_data(max->i2c, MAX6690_EXTERNAL_TEMP);
if (data < 0)
return data;
*value = data << 16;
return 0;
}
static void wf_max6690_release(struct wf_sensor *sr)
{
struct wf_6690_sensor *max = wf_to_6690(sr);
kfree(max);
}
static int wf_max6690_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct wf_6690_sensor *max;
int rc;
max = kzalloc(sizeof(struct wf_6690_sensor), GFP_KERNEL);
if (max == NULL) {
printk(KERN_ERR "windfarm: Couldn't create MAX6690 sensor: "
"no memory\n");
return -ENOMEM;
}
max->i2c = client;
max->sens.name = client->dev.platform_data;
max->sens.ops = &wf_max6690_ops;
i2c_set_clientdata(client, max);
rc = wf_register_sensor(&max->sens);
if (rc) {
kfree(max);
}
return rc;
}
static struct i2c_client *wf_max6690_create(struct i2c_adapter *adapter,
u8 addr, const char *loc)
{
struct i2c_board_info info;
struct i2c_client *client;
char *name;
if (!strcmp(loc, "BACKSIDE"))
name = "backside-temp";
else if (!strcmp(loc, "NB Ambient"))
name = "north-bridge-temp";
else if (!strcmp(loc, "GPU Ambient"))
name = "gpu-temp";
else
goto fail;
memset(&info, 0, sizeof(struct i2c_board_info));
info.addr = addr >> 1;
info.platform_data = name;
strlcpy(info.type, "wf_max6690", I2C_NAME_SIZE);
client = i2c_new_device(adapter, &info);
if (client == NULL) {
printk(KERN_ERR "windfarm: failed to attach MAX6690 sensor\n");
goto fail;
}
list_add_tail(&client->detected, &wf_max6690_driver.clients);
return client;
fail:
return NULL;
}
static int wf_max6690_attach(struct i2c_adapter *adapter)
{
struct device_node *busnode, *dev = NULL;
struct pmac_i2c_bus *bus;
const char *loc;
bus = pmac_i2c_adapter_to_bus(adapter);
if (bus == NULL)
return -ENODEV;
busnode = pmac_i2c_get_bus_node(bus);
while ((dev = of_get_next_child(busnode, dev)) != NULL) {
u8 addr;
if (!pmac_i2c_match_adapter(dev, adapter))
continue;
if (!of_device_is_compatible(dev, "max6690"))
continue;
addr = pmac_i2c_get_dev_addr(dev);
loc = of_get_property(dev, "hwsensor-location", NULL);
if (loc == NULL || addr == 0)
continue;
printk("found max6690, loc=%s addr=0x%02x\n", loc, addr);
wf_max6690_create(adapter, addr, loc);
}
return 0;
}
static int wf_max6690_remove(struct i2c_client *client)
{
struct wf_6690_sensor *max = i2c_get_clientdata(client);
max->i2c = NULL;
wf_unregister_sensor(&max->sens);
return 0;
}
static int __init wf_max6690_sensor_init(void)
{
if (of_machine_is_compatible("PowerMac7,2") ||
of_machine_is_compatible("PowerMac7,3") ||
of_machine_is_compatible("RackMac3,1"))
return -ENODEV;
return i2c_add_driver(&wf_max6690_driver);
}
static void __exit wf_max6690_sensor_exit(void)
{
i2c_del_driver(&wf_max6690_driver);
}
