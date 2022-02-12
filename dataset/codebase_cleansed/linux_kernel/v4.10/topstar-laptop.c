static void acpi_topstar_notify(struct acpi_device *device, u32 event)
{
static bool dup_evnt[2];
bool *dup;
struct topstar_hkey *hkey = acpi_driver_data(device);
if (event == 0x83 || event == 0x84) {
dup = &dup_evnt[event - 0x83];
if (*dup) {
*dup = false;
return;
}
*dup = true;
}
if (!sparse_keymap_report_event(hkey->inputdev, event, 1, true))
pr_info("unknown event = 0x%02x\n", event);
}
static int acpi_topstar_fncx_switch(struct acpi_device *device, bool state)
{
acpi_status status;
status = acpi_execute_simple_method(device->handle, "FNCX",
state ? 0x86 : 0x87);
if (ACPI_FAILURE(status)) {
pr_err("Unable to switch FNCX notifications\n");
return -ENODEV;
}
return 0;
}
static int acpi_topstar_init_hkey(struct topstar_hkey *hkey)
{
struct input_dev *input;
int error;
input = input_allocate_device();
if (!input)
return -ENOMEM;
input->name = "Topstar Laptop extra buttons";
input->phys = "topstar/input0";
input->id.bustype = BUS_HOST;
error = sparse_keymap_setup(input, topstar_keymap, NULL);
if (error) {
pr_err("Unable to setup input device keymap\n");
goto err_free_dev;
}
error = input_register_device(input);
if (error) {
pr_err("Unable to register input device\n");
goto err_free_keymap;
}
hkey->inputdev = input;
return 0;
err_free_keymap:
sparse_keymap_free(input);
err_free_dev:
input_free_device(input);
return error;
}
static int acpi_topstar_add(struct acpi_device *device)
{
struct topstar_hkey *tps_hkey;
tps_hkey = kzalloc(sizeof(struct topstar_hkey), GFP_KERNEL);
if (!tps_hkey)
return -ENOMEM;
strcpy(acpi_device_name(device), "Topstar TPSACPI");
strcpy(acpi_device_class(device), ACPI_TOPSTAR_CLASS);
if (acpi_topstar_fncx_switch(device, true))
goto add_err;
if (acpi_topstar_init_hkey(tps_hkey))
goto add_err;
device->driver_data = tps_hkey;
return 0;
add_err:
kfree(tps_hkey);
return -ENODEV;
}
static int acpi_topstar_remove(struct acpi_device *device)
{
struct topstar_hkey *tps_hkey = acpi_driver_data(device);
acpi_topstar_fncx_switch(device, false);
sparse_keymap_free(tps_hkey->inputdev);
input_unregister_device(tps_hkey->inputdev);
kfree(tps_hkey);
return 0;
}
