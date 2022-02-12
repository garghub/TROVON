static void dell_wmi_notify(u32 value, void *context)
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
if (obj && obj->type == ACPI_TYPE_BUFFER) {
const struct key_entry *key;
int reported_key;
u16 *buffer_entry = (u16 *)obj->buffer.pointer;
if (dell_new_hk_type && (buffer_entry[1] != 0x10)) {
pr_info("Received unknown WMI event (0x%x)\n",
buffer_entry[1]);
kfree(obj);
return;
}
if (dell_new_hk_type || buffer_entry[1] == 0x0)
reported_key = (int)buffer_entry[2];
else
reported_key = (int)buffer_entry[1] & 0xffff;
key = sparse_keymap_entry_from_scancode(dell_wmi_input_dev,
reported_key);
if (!key) {
pr_info("Unknown key %x pressed\n", reported_key);
} else if ((key->keycode == KEY_BRIGHTNESSUP ||
key->keycode == KEY_BRIGHTNESSDOWN) && acpi_video) {
;
} else {
sparse_keymap_report_entry(dell_wmi_input_dev, key,
1, true);
}
}
kfree(obj);
}
static const struct key_entry * __init dell_wmi_prepare_new_keymap(void)
{
int hotkey_num = (dell_bios_hotkey_table->header.length - 4) /
sizeof(struct dell_bios_keymap_entry);
struct key_entry *keymap;
int i;
keymap = kcalloc(hotkey_num + 1, sizeof(struct key_entry), GFP_KERNEL);
if (!keymap)
return NULL;
for (i = 0; i < hotkey_num; i++) {
const struct dell_bios_keymap_entry *bios_entry =
&dell_bios_hotkey_table->keymap[i];
keymap[i].type = KE_KEY;
keymap[i].code = bios_entry->scancode;
keymap[i].keycode = bios_entry->keycode < 256 ?
bios_to_linux_keycode[bios_entry->keycode] :
KEY_RESERVED;
}
keymap[hotkey_num].type = KE_END;
return keymap;
}
static int __init dell_wmi_input_setup(void)
{
int err;
dell_wmi_input_dev = input_allocate_device();
if (!dell_wmi_input_dev)
return -ENOMEM;
dell_wmi_input_dev->name = "Dell WMI hotkeys";
dell_wmi_input_dev->phys = "wmi/input0";
dell_wmi_input_dev->id.bustype = BUS_HOST;
if (dell_new_hk_type) {
const struct key_entry *keymap = dell_wmi_prepare_new_keymap();
if (!keymap) {
err = -ENOMEM;
goto err_free_dev;
}
err = sparse_keymap_setup(dell_wmi_input_dev, keymap, NULL);
kfree(keymap);
} else {
err = sparse_keymap_setup(dell_wmi_input_dev,
dell_wmi_legacy_keymap, NULL);
}
if (err)
goto err_free_dev;
err = input_register_device(dell_wmi_input_dev);
if (err)
goto err_free_keymap;
return 0;
err_free_keymap:
sparse_keymap_free(dell_wmi_input_dev);
err_free_dev:
input_free_device(dell_wmi_input_dev);
return err;
}
static void dell_wmi_input_destroy(void)
{
sparse_keymap_free(dell_wmi_input_dev);
input_unregister_device(dell_wmi_input_dev);
}
static void __init find_hk_type(const struct dmi_header *dm, void *dummy)
{
if (dm->type == 0xb2 && dm->length > 6) {
dell_new_hk_type = true;
dell_bios_hotkey_table =
container_of(dm, struct dell_bios_hotkey_table, header);
}
}
static int __init dell_wmi_init(void)
{
int err;
acpi_status status;
if (!wmi_has_guid(DELL_EVENT_GUID)) {
pr_warn("No known WMI GUID found\n");
return -ENODEV;
}
dmi_walk(find_hk_type, NULL);
acpi_video = acpi_video_backlight_support();
err = dell_wmi_input_setup();
if (err)
return err;
status = wmi_install_notify_handler(DELL_EVENT_GUID,
dell_wmi_notify, NULL);
if (ACPI_FAILURE(status)) {
dell_wmi_input_destroy();
pr_err("Unable to register notify handler - %d\n", status);
return -ENODEV;
}
return 0;
}
static void __exit dell_wmi_exit(void)
{
wmi_remove_notify_handler(DELL_EVENT_GUID);
dell_wmi_input_destroy();
}
