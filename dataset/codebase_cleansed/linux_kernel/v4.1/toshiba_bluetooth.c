static int toshiba_bluetooth_present(acpi_handle handle)
{
acpi_status result;
u64 bt_present;
result = acpi_evaluate_integer(handle, "_STA", NULL, &bt_present);
if (ACPI_FAILURE(result)) {
pr_err("ACPI call to query Bluetooth presence failed");
return -ENXIO;
} else if (!bt_present) {
pr_info("Bluetooth device not present\n");
return -ENODEV;
}
return 0;
}
static int toshiba_bluetooth_status(acpi_handle handle)
{
acpi_status result;
u64 status;
result = acpi_evaluate_integer(handle, "BTST", NULL, &status);
if (ACPI_FAILURE(result)) {
pr_err("Could not get Bluetooth device status\n");
return -ENXIO;
}
pr_info("Bluetooth status %llu\n", status);
return status;
}
static int toshiba_bluetooth_enable(acpi_handle handle)
{
acpi_status result;
bool killswitch;
bool powered;
bool plugged;
int status;
status = toshiba_bluetooth_status(handle);
if (status < 0)
return status;
killswitch = (status & BT_KILLSWITCH_MASK) ? true : false;
powered = (status & BT_POWER_MASK) ? true : false;
plugged = (status & BT_PLUGGED_MASK) ? true : false;
if (!killswitch)
return 0;
if (powered || plugged)
return 0;
result = acpi_evaluate_object(handle, "AUSB", NULL, NULL);
if (ACPI_FAILURE(result)) {
pr_err("Could not attach USB Bluetooth device\n");
return -ENXIO;
}
result = acpi_evaluate_object(handle, "BTPO", NULL, NULL);
if (ACPI_FAILURE(result)) {
pr_err("Could not power ON Bluetooth device\n");
return -ENXIO;
}
return 0;
}
static int toshiba_bluetooth_disable(acpi_handle handle)
{
acpi_status result;
result = acpi_evaluate_object(handle, "BTPF", NULL, NULL);
if (ACPI_FAILURE(result)) {
pr_err("Could not power OFF Bluetooth device\n");
return -ENXIO;
}
result = acpi_evaluate_object(handle, "DUSB", NULL, NULL);
if (ACPI_FAILURE(result)) {
pr_err("Could not detach USB Bluetooth device\n");
return -ENXIO;
}
return 0;
}
static void toshiba_bt_rfkill_notify(struct acpi_device *device, u32 event)
{
toshiba_bluetooth_enable(device->handle);
}
static int toshiba_bt_resume(struct device *dev)
{
return toshiba_bluetooth_enable(to_acpi_device(dev)->handle);
}
static int toshiba_bt_rfkill_add(struct acpi_device *device)
{
int result;
result = toshiba_bluetooth_present(device->handle);
if (result)
return result;
pr_info("Toshiba ACPI Bluetooth device driver\n");
result = toshiba_bluetooth_enable(device->handle);
if (result)
return result;
return result;
}
static int toshiba_bt_rfkill_remove(struct acpi_device *device)
{
return toshiba_bluetooth_disable(device->handle);
}
