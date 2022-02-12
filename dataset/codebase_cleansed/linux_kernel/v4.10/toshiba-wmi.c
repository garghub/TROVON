static void toshiba_wmi_notify(u32 value, void *context)
{
struct acpi_buffer response = { ACPI_ALLOCATE_BUFFER, NULL };
union acpi_object *obj;
acpi_status status;
status = wmi_get_event_data(value, &response);
if (ACPI_FAILURE(status)) {
pr_err("Bad event status 0x%x\n", status);
return;
}
obj = (union acpi_object *)response.pointer;
if (!obj)
return;
pr_debug("Unknown event received, obj type %x\n", obj->type);
kfree(response.pointer);
}
static int __init toshiba_wmi_input_setup(void)
{
acpi_status status;
int err;
toshiba_wmi_input_dev = input_allocate_device();
if (!toshiba_wmi_input_dev)
return -ENOMEM;
toshiba_wmi_input_dev->name = "Toshiba WMI hotkeys";
toshiba_wmi_input_dev->phys = "wmi/input0";
toshiba_wmi_input_dev->id.bustype = BUS_HOST;
err = sparse_keymap_setup(toshiba_wmi_input_dev,
toshiba_wmi_keymap, NULL);
if (err)
goto err_free_dev;
status = wmi_install_notify_handler(WMI_EVENT_GUID,
toshiba_wmi_notify, NULL);
if (ACPI_FAILURE(status)) {
err = -EIO;
goto err_free_keymap;
}
err = input_register_device(toshiba_wmi_input_dev);
if (err)
goto err_remove_notifier;
return 0;
err_remove_notifier:
wmi_remove_notify_handler(WMI_EVENT_GUID);
err_free_keymap:
sparse_keymap_free(toshiba_wmi_input_dev);
err_free_dev:
input_free_device(toshiba_wmi_input_dev);
return err;
}
static void toshiba_wmi_input_destroy(void)
{
wmi_remove_notify_handler(WMI_EVENT_GUID);
sparse_keymap_free(toshiba_wmi_input_dev);
input_unregister_device(toshiba_wmi_input_dev);
}
static int __init toshiba_wmi_init(void)
{
int ret;
if (!wmi_has_guid(WMI_EVENT_GUID) ||
!dmi_check_system(toshiba_wmi_dmi_table))
return -ENODEV;
ret = toshiba_wmi_input_setup();
if (ret) {
pr_err("Failed to setup input device\n");
return ret;
}
pr_info("Toshiba WMI Hotkey Driver\n");
return 0;
}
static void __exit toshiba_wmi_exit(void)
{
if (wmi_has_guid(WMI_EVENT_GUID))
toshiba_wmi_input_destroy();
}
