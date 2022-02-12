static void dell_wmi_aio_notify(u32 value, void *context)
{
struct acpi_buffer response = { ACPI_ALLOCATE_BUFFER, NULL };
union acpi_object *obj;
acpi_status status;
status = wmi_get_event_data(value, &response);
if (status != AE_OK) {
pr_info("bad event status 0x%x\n", status);
return;
}
obj = (union acpi_object *)response.pointer;
if (obj) {
unsigned int scancode;
switch (obj->type) {
case ACPI_TYPE_INTEGER:
scancode = obj->integer.value;
sparse_keymap_report_event(dell_wmi_aio_input_dev,
scancode, 1, true);
break;
case ACPI_TYPE_BUFFER:
if (obj->buffer.pointer && obj->buffer.length > 0) {
scancode = obj->buffer.pointer[0];
sparse_keymap_report_event(
dell_wmi_aio_input_dev,
scancode, 1, true);
}
break;
}
}
kfree(obj);
}
static int __init dell_wmi_aio_input_setup(void)
{
int err;
dell_wmi_aio_input_dev = input_allocate_device();
if (!dell_wmi_aio_input_dev)
return -ENOMEM;
dell_wmi_aio_input_dev->name = "Dell AIO WMI hotkeys";
dell_wmi_aio_input_dev->phys = "wmi/input0";
dell_wmi_aio_input_dev->id.bustype = BUS_HOST;
err = sparse_keymap_setup(dell_wmi_aio_input_dev,
dell_wmi_aio_keymap, NULL);
if (err) {
pr_err("Unable to setup input device keymap\n");
goto err_free_dev;
}
err = input_register_device(dell_wmi_aio_input_dev);
if (err) {
pr_info("Unable to register input device\n");
goto err_free_keymap;
}
return 0;
err_free_keymap:
sparse_keymap_free(dell_wmi_aio_input_dev);
err_free_dev:
input_free_device(dell_wmi_aio_input_dev);
return err;
}
static const char *dell_wmi_aio_find(void)
{
int i;
for (i = 0; dell_wmi_aio_guids[i] != NULL; i++)
if (wmi_has_guid(dell_wmi_aio_guids[i]))
return dell_wmi_aio_guids[i];
return NULL;
}
static int __init dell_wmi_aio_init(void)
{
int err;
const char *guid;
guid = dell_wmi_aio_find();
if (!guid) {
pr_warn("No known WMI GUID found\n");
return -ENXIO;
}
err = dell_wmi_aio_input_setup();
if (err)
return err;
err = wmi_install_notify_handler(guid, dell_wmi_aio_notify, NULL);
if (err) {
pr_err("Unable to register notify handler - %d\n", err);
sparse_keymap_free(dell_wmi_aio_input_dev);
input_unregister_device(dell_wmi_aio_input_dev);
return err;
}
return 0;
}
static void __exit dell_wmi_aio_exit(void)
{
const char *guid;
guid = dell_wmi_aio_find();
wmi_remove_notify_handler(guid);
sparse_keymap_free(dell_wmi_aio_input_dev);
input_unregister_device(dell_wmi_aio_input_dev);
}
