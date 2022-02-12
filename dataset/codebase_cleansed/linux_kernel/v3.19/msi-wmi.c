static int msi_wmi_query_block(int instance, int *ret)
{
acpi_status status;
union acpi_object *obj;
struct acpi_buffer output = { ACPI_ALLOCATE_BUFFER, NULL };
status = wmi_query_block(MSIWMI_BIOS_GUID, instance, &output);
obj = output.pointer;
if (!obj || obj->type != ACPI_TYPE_INTEGER) {
if (obj) {
pr_err("query block returned object "
"type: %d - buffer length:%d\n", obj->type,
obj->type == ACPI_TYPE_BUFFER ?
obj->buffer.length : 0);
}
kfree(obj);
return -EINVAL;
}
*ret = obj->integer.value;
kfree(obj);
return 0;
}
static int msi_wmi_set_block(int instance, int value)
{
acpi_status status;
struct acpi_buffer input = { sizeof(int), &value };
pr_debug("Going to set block of instance: %d - value: %d\n",
instance, value);
status = wmi_set_block(MSIWMI_BIOS_GUID, instance, &input);
return ACPI_SUCCESS(status) ? 0 : 1;
}
static int bl_get(struct backlight_device *bd)
{
int level, err, ret;
err = msi_wmi_query_block(1, &ret);
if (err) {
pr_err("Could not query backlight: %d\n", err);
return -EINVAL;
}
pr_debug("Get: Query block returned: %d\n", ret);
for (level = 0; level < ARRAY_SIZE(backlight_map); level++) {
if (backlight_map[level] == ret) {
pr_debug("Current backlight level: 0x%X - index: %d\n",
backlight_map[level], level);
break;
}
}
if (level == ARRAY_SIZE(backlight_map)) {
pr_err("get: Invalid brightness value: 0x%X\n", ret);
return -EINVAL;
}
return level;
}
static int bl_set_status(struct backlight_device *bd)
{
int bright = bd->props.brightness;
if (bright >= ARRAY_SIZE(backlight_map) || bright < 0)
return -EINVAL;
return msi_wmi_set_block(0, backlight_map[bright]);
}
static void msi_wmi_notify(u32 value, void *context)
{
struct acpi_buffer response = { ACPI_ALLOCATE_BUFFER, NULL };
static struct key_entry *key;
union acpi_object *obj;
acpi_status status;
status = wmi_get_event_data(value, &response);
if (status != AE_OK) {
pr_info("bad event status 0x%x\n", status);
return;
}
obj = (union acpi_object *)response.pointer;
if (obj && obj->type == ACPI_TYPE_INTEGER) {
int eventcode = obj->integer.value;
pr_debug("Eventcode: 0x%x\n", eventcode);
key = sparse_keymap_entry_from_scancode(msi_wmi_input_dev,
eventcode);
if (!key) {
pr_info("Unknown key pressed - %x\n", eventcode);
goto msi_wmi_notify_exit;
}
if (event_wmi->quirk_last_pressed) {
ktime_t cur = ktime_get_real();
ktime_t diff = ktime_sub(cur, last_pressed);
if (ktime_to_us(diff) < 1000 * 50) {
pr_debug("Suppressed key event 0x%X - "
"Last press was %lld us ago\n",
key->code, ktime_to_us(diff));
goto msi_wmi_notify_exit;
}
last_pressed = cur;
}
if (key->type == KE_KEY &&
(backlight ||
(key->code != MSI_KEY_BRIGHTNESSUP &&
key->code != MSI_KEY_BRIGHTNESSDOWN))) {
pr_debug("Send key: 0x%X - Input layer keycode: %d\n",
key->code, key->keycode);
sparse_keymap_report_entry(msi_wmi_input_dev, key, 1,
true);
}
} else
pr_info("Unknown event received\n");
msi_wmi_notify_exit:
kfree(response.pointer);
}
static int __init msi_wmi_backlight_setup(void)
{
int err;
struct backlight_properties props;
memset(&props, 0, sizeof(struct backlight_properties));
props.type = BACKLIGHT_PLATFORM;
props.max_brightness = ARRAY_SIZE(backlight_map) - 1;
backlight = backlight_device_register(DRV_NAME, NULL, NULL,
&msi_backlight_ops,
&props);
if (IS_ERR(backlight))
return PTR_ERR(backlight);
err = bl_get(NULL);
if (err < 0) {
backlight_device_unregister(backlight);
return err;
}
backlight->props.brightness = err;
return 0;
}
static int __init msi_wmi_input_setup(void)
{
int err;
msi_wmi_input_dev = input_allocate_device();
if (!msi_wmi_input_dev)
return -ENOMEM;
msi_wmi_input_dev->name = "MSI WMI hotkeys";
msi_wmi_input_dev->phys = "wmi/input0";
msi_wmi_input_dev->id.bustype = BUS_HOST;
err = sparse_keymap_setup(msi_wmi_input_dev, msi_wmi_keymap, NULL);
if (err)
goto err_free_dev;
err = input_register_device(msi_wmi_input_dev);
if (err)
goto err_free_keymap;
last_pressed = ktime_set(0, 0);
return 0;
err_free_keymap:
sparse_keymap_free(msi_wmi_input_dev);
err_free_dev:
input_free_device(msi_wmi_input_dev);
return err;
}
static int __init msi_wmi_init(void)
{
int err;
int i;
for (i = 0; i < ARRAY_SIZE(event_wmis); i++) {
if (!wmi_has_guid(event_wmis[i].guid))
continue;
err = msi_wmi_input_setup();
if (err) {
pr_err("Unable to setup input device\n");
return err;
}
err = wmi_install_notify_handler(event_wmis[i].guid,
msi_wmi_notify, NULL);
if (ACPI_FAILURE(err)) {
pr_err("Unable to setup WMI notify handler\n");
goto err_free_input;
}
pr_debug("Event handler installed\n");
event_wmi = &event_wmis[i];
break;
}
if (wmi_has_guid(MSIWMI_BIOS_GUID) && !acpi_video_backlight_support()) {
err = msi_wmi_backlight_setup();
if (err) {
pr_err("Unable to setup backlight device\n");
goto err_uninstall_handler;
}
pr_debug("Backlight device created\n");
}
if (!event_wmi && !backlight) {
pr_err("This machine doesn't have neither MSI-hotkeys nor backlight through WMI\n");
return -ENODEV;
}
return 0;
err_uninstall_handler:
if (event_wmi)
wmi_remove_notify_handler(event_wmi->guid);
err_free_input:
if (event_wmi) {
sparse_keymap_free(msi_wmi_input_dev);
input_unregister_device(msi_wmi_input_dev);
}
return err;
}
static void __exit msi_wmi_exit(void)
{
if (event_wmi) {
wmi_remove_notify_handler(event_wmi->guid);
sparse_keymap_free(msi_wmi_input_dev);
input_unregister_device(msi_wmi_input_dev);
}
backlight_device_unregister(backlight);
}
