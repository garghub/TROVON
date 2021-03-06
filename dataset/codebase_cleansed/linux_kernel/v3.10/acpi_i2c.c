static int acpi_i2c_add_resource(struct acpi_resource *ares, void *data)
{
struct i2c_board_info *info = data;
if (ares->type == ACPI_RESOURCE_TYPE_SERIAL_BUS) {
struct acpi_resource_i2c_serialbus *sb;
sb = &ares->data.i2c_serial_bus;
if (sb->type == ACPI_RESOURCE_SERIAL_TYPE_I2C) {
info->addr = sb->slave_address;
if (sb->access_mode == ACPI_I2C_10BIT_MODE)
info->flags |= I2C_CLIENT_TEN;
}
} else if (info->irq < 0) {
struct resource r;
if (acpi_dev_resource_interrupt(ares, 0, &r))
info->irq = r.start;
}
return 1;
}
static acpi_status acpi_i2c_add_device(acpi_handle handle, u32 level,
void *data, void **return_value)
{
struct i2c_adapter *adapter = data;
struct list_head resource_list;
struct i2c_board_info info;
struct acpi_device *adev;
int ret;
if (acpi_bus_get_device(handle, &adev))
return AE_OK;
if (acpi_bus_get_status(adev) || !adev->status.present)
return AE_OK;
memset(&info, 0, sizeof(info));
info.acpi_node.handle = handle;
info.irq = -1;
INIT_LIST_HEAD(&resource_list);
ret = acpi_dev_get_resources(adev, &resource_list,
acpi_i2c_add_resource, &info);
acpi_dev_free_resource_list(&resource_list);
if (ret < 0 || !info.addr)
return AE_OK;
strlcpy(info.type, dev_name(&adev->dev), sizeof(info.type));
if (!i2c_new_device(adapter, &info)) {
dev_err(&adapter->dev,
"failed to add I2C device %s from ACPI\n",
dev_name(&adev->dev));
}
return AE_OK;
}
void acpi_i2c_register_devices(struct i2c_adapter *adapter)
{
acpi_handle handle;
acpi_status status;
handle = ACPI_HANDLE(adapter->dev.parent);
if (!handle)
return;
status = acpi_walk_namespace(ACPI_TYPE_DEVICE, handle, 1,
acpi_i2c_add_device, NULL,
adapter, NULL);
if (ACPI_FAILURE(status))
dev_warn(&adapter->dev, "failed to enumerate I2C slaves\n");
}
