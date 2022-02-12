static int toshiba_bluetooth_enable(acpi_handle handle)
{
acpi_status res1, res2;
u64 result;
res1 = acpi_evaluate_integer(handle, "BTST", NULL, &result);
if (ACPI_FAILURE(res1))
return res1;
if (!(result & 0x01))
return 0;
pr_info("Re-enabling Toshiba Bluetooth\n");
res1 = acpi_evaluate_object(handle, "AUSB", NULL, NULL);
res2 = acpi_evaluate_object(handle, "BTPO", NULL, NULL);
if (!ACPI_FAILURE(res1) || !ACPI_FAILURE(res2))
return 0;
pr_warn("Failed to re-enable Toshiba Bluetooth\n");
return -ENODEV;
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
acpi_status status;
u64 bt_present;
int result = -ENODEV;
status = acpi_evaluate_integer(device->handle, "_STA", NULL,
&bt_present);
if (!ACPI_FAILURE(status) && bt_present) {
pr_info("Detected Toshiba ACPI Bluetooth device - "
"installing RFKill handler\n");
result = toshiba_bluetooth_enable(device->handle);
}
return result;
}
static int toshiba_bt_rfkill_remove(struct acpi_device *device, int type)
{
return 0;
}
