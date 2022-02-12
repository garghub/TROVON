static int wf_lm75_get(struct wf_sensor *sr, s32 *value)
{
struct wf_lm75_sensor *lm = wf_to_lm75(sr);
s32 data;
if (lm->i2c == NULL)
return -ENODEV;
if (!lm->inited) {
u8 cfg_new, cfg = (u8)i2c_smbus_read_byte_data(lm->i2c, 1);
DBG("wf_lm75: Initializing %s, cfg was: %02x\n",
sr->name, cfg);
cfg_new = cfg & ~0x01;
i2c_smbus_write_byte_data(lm->i2c, 1, cfg_new);
lm->inited = 1;
msleep(200);
}
data = (s32)le16_to_cpu(i2c_smbus_read_word_data(lm->i2c, 0));
data <<= 8;
*value = data;
return 0;
}
static void wf_lm75_release(struct wf_sensor *sr)
{
struct wf_lm75_sensor *lm = wf_to_lm75(sr);
kfree(lm);
}
static int wf_lm75_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct wf_lm75_sensor *lm;
int rc;
lm = kzalloc(sizeof(struct wf_lm75_sensor), GFP_KERNEL);
if (lm == NULL)
return -ENODEV;
lm->inited = 0;
lm->ds1775 = id->driver_data;
lm->i2c = client;
lm->sens.name = client->dev.platform_data;
lm->sens.ops = &wf_lm75_ops;
i2c_set_clientdata(client, lm);
rc = wf_register_sensor(&lm->sens);
if (rc)
kfree(lm);
return rc;
}
static struct i2c_client *wf_lm75_create(struct i2c_adapter *adapter,
u8 addr, int ds1775,
const char *loc)
{
struct i2c_board_info info;
struct i2c_client *client;
char *name;
DBG("wf_lm75: creating %s device at address 0x%02x\n",
ds1775 ? "ds1775" : "lm75", addr);
if (!strcmp(loc, "Hard drive") || !strcmp(loc, "DRIVE BAY"))
name = "hd-temp";
else if (!strcmp(loc, "Incoming Air Temp"))
name = "incoming-air-temp";
else if (!strcmp(loc, "ODD Temp"))
name = "optical-drive-temp";
else if (!strcmp(loc, "HD Temp"))
name = "hard-drive-temp";
else
goto fail;
memset(&info, 0, sizeof(struct i2c_board_info));
info.addr = (addr >> 1) & 0x7f;
info.platform_data = name;
strlcpy(info.type, ds1775 ? "wf_ds1775" : "wf_lm75", I2C_NAME_SIZE);
client = i2c_new_device(adapter, &info);
if (client == NULL) {
printk(KERN_ERR "windfarm: failed to attach %s %s to i2c\n",
ds1775 ? "ds1775" : "lm75", name);
goto fail;
}
list_add_tail(&client->detected, &wf_lm75_driver.clients);
return client;
fail:
return NULL;
}
static int wf_lm75_attach(struct i2c_adapter *adapter)
{
struct device_node *busnode, *dev;
struct pmac_i2c_bus *bus;
DBG("wf_lm75: adapter %s detected\n", adapter->name);
bus = pmac_i2c_adapter_to_bus(adapter);
if (bus == NULL)
return -ENODEV;
busnode = pmac_i2c_get_bus_node(bus);
DBG("wf_lm75: bus found, looking for device...\n");
for (dev = NULL;
(dev = of_get_next_child(busnode, dev)) != NULL;) {
const char *loc =
of_get_property(dev, "hwsensor-location", NULL);
u8 addr;
if (!pmac_i2c_match_adapter(dev, adapter))
continue;
addr = pmac_i2c_get_dev_addr(dev);
if (loc == NULL || addr == 0)
continue;
if (of_device_is_compatible(dev, "lm75"))
wf_lm75_create(adapter, addr, 0, loc);
else if (of_device_is_compatible(dev, "ds1775"))
wf_lm75_create(adapter, addr, 1, loc);
}
return 0;
}
static int wf_lm75_remove(struct i2c_client *client)
{
struct wf_lm75_sensor *lm = i2c_get_clientdata(client);
DBG("wf_lm75: i2c detatch called for %s\n", lm->sens.name);
lm->i2c = NULL;
wf_unregister_sensor(&lm->sens);
return 0;
}
static int __init wf_lm75_sensor_init(void)
{
if (of_machine_is_compatible("PowerMac7,2") ||
of_machine_is_compatible("PowerMac7,3") ||
of_machine_is_compatible("RackMac3,1"))
return -ENODEV;
return i2c_add_driver(&wf_lm75_driver);
}
static void __exit wf_lm75_sensor_exit(void)
{
i2c_del_driver(&wf_lm75_driver);
}
