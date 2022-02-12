static void silead_ts_dmi_add_props(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
const struct dmi_system_id *dmi_id;
const struct silead_ts_dmi_data *ts_data;
int error;
dmi_id = dmi_first_match(silead_ts_dmi_table);
if (!dmi_id)
return;
ts_data = dmi_id->driver_data;
if (has_acpi_companion(dev) &&
!strncmp(ts_data->acpi_name, client->name, I2C_NAME_SIZE)) {
error = device_add_properties(dev, ts_data->properties);
if (error)
dev_err(dev, "failed to add properties: %d\n", error);
}
}
static int silead_ts_dmi_notifier_call(struct notifier_block *nb,
unsigned long action, void *data)
{
struct device *dev = data;
switch (action) {
case BUS_NOTIFY_ADD_DEVICE:
silead_ts_dmi_add_props(dev);
break;
default:
break;
}
return 0;
}
static int __init silead_ts_dmi_init(void)
{
int error;
error = bus_register_notifier(&i2c_bus_type, &silead_ts_dmi_notifier);
if (error)
pr_err("%s: failed to register i2c bus notifier: %d\n",
__func__, error);
return error;
}
