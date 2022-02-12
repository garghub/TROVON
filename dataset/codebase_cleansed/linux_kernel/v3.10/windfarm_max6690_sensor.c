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
const char *name, *loc;
struct wf_6690_sensor *max;
int rc;
loc = of_get_property(client->dev.of_node, "hwsensor-location", NULL);
if (!loc) {
dev_warn(&client->dev, "Missing hwsensor-location property!\n");
return -ENXIO;
}
if (!strcmp(loc, "BACKSIDE") || !strcmp(loc, "SYS CTRLR AMBIENT"))
name = "backside-temp";
else if (!strcmp(loc, "NB Ambient"))
name = "north-bridge-temp";
else if (!strcmp(loc, "GPU Ambient"))
name = "gpu-temp";
else
return -ENXIO;
max = kzalloc(sizeof(struct wf_6690_sensor), GFP_KERNEL);
if (max == NULL) {
printk(KERN_ERR "windfarm: Couldn't create MAX6690 sensor: "
"no memory\n");
return -ENOMEM;
}
max->i2c = client;
max->sens.name = (char *)name;
max->sens.ops = &wf_max6690_ops;
i2c_set_clientdata(client, max);
rc = wf_register_sensor(&max->sens);
if (rc)
kfree(max);
return rc;
}
static int wf_max6690_remove(struct i2c_client *client)
{
struct wf_6690_sensor *max = i2c_get_clientdata(client);
max->i2c = NULL;
wf_unregister_sensor(&max->sens);
return 0;
}
