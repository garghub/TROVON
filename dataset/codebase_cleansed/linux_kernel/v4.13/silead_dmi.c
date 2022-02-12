static void silead_ts_dmi_add_props(struct i2c_client *client)
{
struct device *dev = &client->dev;
int error;
if (has_acpi_companion(dev) &&
!strncmp(silead_ts_data->acpi_name, client->name, I2C_NAME_SIZE)) {
error = device_add_properties(dev, silead_ts_data->properties);
if (error)
dev_err(dev, "failed to add properties: %d\n", error);
}
}
static int silead_ts_dmi_notifier_call(struct notifier_block *nb,
unsigned long action, void *data)
{
struct device *dev = data;
struct i2c_client *client;
switch (action) {
case BUS_NOTIFY_ADD_DEVICE:
client = i2c_verify_client(dev);
if (client)
silead_ts_dmi_add_props(client);
break;
default:
break;
}
return 0;
}
static int __init silead_ts_dmi_init(void)
{
const struct dmi_system_id *dmi_id;
int error;
dmi_id = dmi_first_match(silead_ts_dmi_table);
if (!dmi_id)
return 0;
silead_ts_data = dmi_id->driver_data;
error = bus_register_notifier(&i2c_bus_type, &silead_ts_dmi_notifier);
if (error)
pr_err("%s: failed to register i2c bus notifier: %d\n",
__func__, error);
return error;
}
