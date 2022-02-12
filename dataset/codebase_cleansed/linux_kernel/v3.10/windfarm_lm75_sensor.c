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
int rc, ds1775 = id->driver_data;
const char *name, *loc;
DBG("wf_lm75: creating %s device at address 0x%02x\n",
ds1775 ? "ds1775" : "lm75", client->addr);
loc = of_get_property(client->dev.of_node, "hwsensor-location", NULL);
if (!loc) {
dev_warn(&client->dev, "Missing hwsensor-location property!\n");
return -ENXIO;
}
if (!strcmp(loc, "Hard drive") || !strcmp(loc, "DRIVE BAY"))
name = "hd-temp";
else if (!strcmp(loc, "Incoming Air Temp"))
name = "incoming-air-temp";
else if (!strcmp(loc, "ODD Temp"))
name = "optical-drive-temp";
else if (!strcmp(loc, "HD Temp"))
name = "hard-drive-temp";
else if (!strcmp(loc, "PCI SLOTS"))
name = "slots-temp";
else if (!strcmp(loc, "CPU A INLET"))
name = "cpu-inlet-temp-0";
else if (!strcmp(loc, "CPU B INLET"))
name = "cpu-inlet-temp-1";
else
return -ENXIO;
lm = kzalloc(sizeof(struct wf_lm75_sensor), GFP_KERNEL);
if (lm == NULL)
return -ENODEV;
lm->inited = 0;
lm->ds1775 = ds1775;
lm->i2c = client;
lm->sens.name = (char *)name;
lm->sens.ops = &wf_lm75_ops;
i2c_set_clientdata(client, lm);
rc = wf_register_sensor(&lm->sens);
if (rc)
kfree(lm);
return rc;
}
static int wf_lm75_remove(struct i2c_client *client)
{
struct wf_lm75_sensor *lm = i2c_get_clientdata(client);
DBG("wf_lm75: i2c detatch called for %s\n", lm->sens.name);
lm->i2c = NULL;
wf_unregister_sensor(&lm->sens);
return 0;
}
