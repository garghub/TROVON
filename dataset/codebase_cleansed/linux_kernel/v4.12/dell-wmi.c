static int __init dmi_matched(const struct dmi_system_id *dmi)
{
wmi_requires_smbios_request = 1;
return 1;
}
static void dell_wmi_process_key(int type, int code)
{
const struct key_entry *key;
key = sparse_keymap_entry_from_scancode(dell_wmi_input_dev,
(type << 16) | code);
if (!key) {
pr_info("Unknown key with type 0x%04x and code 0x%04x pressed\n",
type, code);
return;
}
pr_debug("Key with type 0x%04x and code 0x%04x pressed\n", type, code);
if ((key->keycode == KEY_BRIGHTNESSUP ||
key->keycode == KEY_BRIGHTNESSDOWN) &&
acpi_video_handles_brightness_key_presses())
return;
if (type == 0x0000 && code == 0xe025 && !wmi_requires_smbios_request)
return;
if (key->keycode == KEY_KBDILLUMTOGGLE)
dell_laptop_call_notifier(
DELL_LAPTOP_KBD_BACKLIGHT_BRIGHTNESS_CHANGED, NULL);
sparse_keymap_report_entry(dell_wmi_input_dev, key, 1, true);
}
static void dell_wmi_notify(u32 value, void *context)
{
struct acpi_buffer response = { ACPI_ALLOCATE_BUFFER, NULL };
union acpi_object *obj;
acpi_status status;
acpi_size buffer_size;
u16 *buffer_entry, *buffer_end;
int len, i;
status = wmi_get_event_data(value, &response);
if (status != AE_OK) {
pr_warn("bad event status 0x%x\n", status);
return;
}
obj = (union acpi_object *)response.pointer;
if (!obj) {
pr_warn("no response\n");
return;
}
if (obj->type != ACPI_TYPE_BUFFER) {
pr_warn("bad response type %x\n", obj->type);
kfree(obj);
return;
}
pr_debug("Received WMI event (%*ph)\n",
obj->buffer.length, obj->buffer.pointer);
buffer_entry = (u16 *)obj->buffer.pointer;
buffer_size = obj->buffer.length/2;
buffer_end = buffer_entry + buffer_size;
if (dell_wmi_interface_version == 0 && buffer_entry < buffer_end)
if (buffer_end > buffer_entry + buffer_entry[0] + 1)
buffer_end = buffer_entry + buffer_entry[0] + 1;
while (buffer_entry < buffer_end) {
len = buffer_entry[0];
if (len == 0)
break;
len++;
if (buffer_entry + len > buffer_end) {
pr_warn("Invalid length of WMI event\n");
break;
}
pr_debug("Process buffer (%*ph)\n", len*2, buffer_entry);
switch (buffer_entry[1]) {
case 0x0000:
if (len > 2)
dell_wmi_process_key(0x0000, buffer_entry[2]);
break;
case 0x0010:
case 0x0011:
for (i = 2; i < len; ++i)
dell_wmi_process_key(buffer_entry[1],
buffer_entry[i]);
break;
default:
pr_info("Unknown WMI event type 0x%x\n",
(int)buffer_entry[1]);
break;
}
buffer_entry += len;
}
kfree(obj);
}
static bool have_scancode(u32 scancode, const struct key_entry *keymap, int len)
{
int i;
for (i = 0; i < len; i++)
if (keymap[i].code == scancode)
return true;
return false;
}
static void __init handle_dmi_entry(const struct dmi_header *dm,
void *opaque)
{
struct dell_dmi_results *results = opaque;
struct dell_bios_hotkey_table *table;
int hotkey_num, i, pos = 0;
struct key_entry *keymap;
if (results->err || results->keymap)
return;
if (dm->type != 0xb2)
return;
table = container_of(dm, struct dell_bios_hotkey_table, header);
hotkey_num = (table->header.length -
sizeof(struct dell_bios_hotkey_table)) /
sizeof(struct dell_bios_keymap_entry);
if (hotkey_num < 1) {
return;
}
keymap = kcalloc(hotkey_num, sizeof(struct key_entry), GFP_KERNEL);
if (!keymap) {
results->err = -ENOMEM;
return;
}
for (i = 0; i < hotkey_num; i++) {
const struct dell_bios_keymap_entry *bios_entry =
&table->keymap[i];
u16 keycode = (bios_entry->keycode <
ARRAY_SIZE(bios_to_linux_keycode)) ?
bios_to_linux_keycode[bios_entry->keycode] :
KEY_RESERVED;
if (keycode == KEY_RESERVED) {
pr_info("firmware scancode 0x%x maps to unrecognized keycode 0x%x\n",
bios_entry->scancode, bios_entry->keycode);
continue;
}
if (keycode == KEY_KBDILLUMTOGGLE)
keymap[pos].type = KE_IGNORE;
else
keymap[pos].type = KE_KEY;
keymap[pos].code = bios_entry->scancode;
keymap[pos].keycode = keycode;
pos++;
}
results->keymap = keymap;
results->keymap_size = pos;
}
static int __init dell_wmi_input_setup(void)
{
struct dell_dmi_results dmi_results = {};
struct key_entry *keymap;
int err, i, pos = 0;
dell_wmi_input_dev = input_allocate_device();
if (!dell_wmi_input_dev)
return -ENOMEM;
dell_wmi_input_dev->name = "Dell WMI hotkeys";
dell_wmi_input_dev->phys = "wmi/input0";
dell_wmi_input_dev->id.bustype = BUS_HOST;
if (dmi_walk(handle_dmi_entry, &dmi_results)) {
pr_warn("no DMI; using the old-style hotkey interface\n");
}
if (dmi_results.err) {
err = dmi_results.err;
goto err_free_dev;
}
keymap = kcalloc(dmi_results.keymap_size +
ARRAY_SIZE(dell_wmi_keymap_type_0000) +
ARRAY_SIZE(dell_wmi_keymap_type_0010) +
ARRAY_SIZE(dell_wmi_keymap_type_0011) +
1,
sizeof(struct key_entry), GFP_KERNEL);
if (!keymap) {
kfree(dmi_results.keymap);
err = -ENOMEM;
goto err_free_dev;
}
for (i = 0; i < dmi_results.keymap_size; i++) {
keymap[pos] = dmi_results.keymap[i];
keymap[pos].code |= (0x0010 << 16);
pos++;
}
kfree(dmi_results.keymap);
for (i = 0; i < ARRAY_SIZE(dell_wmi_keymap_type_0010); i++) {
const struct key_entry *entry = &dell_wmi_keymap_type_0010[i];
if (dmi_results.keymap_size &&
have_scancode(entry->code | (0x0010 << 16),
keymap, dmi_results.keymap_size)
)
continue;
keymap[pos] = *entry;
keymap[pos].code |= (0x0010 << 16);
pos++;
}
for (i = 0; i < ARRAY_SIZE(dell_wmi_keymap_type_0011); i++) {
keymap[pos] = dell_wmi_keymap_type_0011[i];
keymap[pos].code |= (0x0011 << 16);
pos++;
}
for (i = 0; i < ARRAY_SIZE(dell_wmi_keymap_type_0000); i++) {
keymap[pos] = dell_wmi_keymap_type_0000[i];
pos++;
}
keymap[pos].type = KE_END;
err = sparse_keymap_setup(dell_wmi_input_dev, keymap, NULL);
kfree(keymap);
if (err)
goto err_free_dev;
err = input_register_device(dell_wmi_input_dev);
if (err)
goto err_free_dev;
return 0;
err_free_dev:
input_free_device(dell_wmi_input_dev);
return err;
}
static int __init dell_wmi_check_descriptor_buffer(void)
{
struct acpi_buffer out = { ACPI_ALLOCATE_BUFFER, NULL };
union acpi_object *obj;
acpi_status status;
u32 *buffer;
status = wmi_query_block(DELL_DESCRIPTOR_GUID, 0, &out);
if (ACPI_FAILURE(status)) {
pr_err("Cannot read Dell descriptor buffer - %d\n", status);
return status;
}
obj = (union acpi_object *)out.pointer;
if (!obj) {
pr_err("Dell descriptor buffer is empty\n");
return -EINVAL;
}
if (obj->type != ACPI_TYPE_BUFFER) {
pr_err("Cannot read Dell descriptor buffer\n");
kfree(obj);
return -EINVAL;
}
if (obj->buffer.length != 128) {
pr_err("Dell descriptor buffer has invalid length (%d)\n",
obj->buffer.length);
if (obj->buffer.length < 16) {
kfree(obj);
return -EINVAL;
}
}
buffer = (u32 *)obj->buffer.pointer;
if (buffer[0] != 0x4C4C4544 && buffer[1] != 0x494D5720)
pr_warn("Dell descriptor buffer has invalid signature (%*ph)\n",
8, buffer);
if (buffer[2] != 0 && buffer[2] != 1)
pr_warn("Dell descriptor buffer has unknown version (%d)\n",
buffer[2]);
if (buffer[3] != 4096)
pr_warn("Dell descriptor buffer has invalid buffer length (%d)\n",
buffer[3]);
dell_wmi_interface_version = buffer[2];
pr_info("Detected Dell WMI interface version %u\n",
dell_wmi_interface_version);
kfree(obj);
return 0;
}
static int dell_wmi_events_set_enabled(bool enable)
{
struct calling_interface_buffer *buffer;
int ret;
buffer = dell_smbios_get_buffer();
buffer->input[0] = 0x10000;
buffer->input[1] = 0x51534554;
buffer->input[3] = enable;
dell_smbios_send_request(17, 3);
ret = buffer->output[0];
dell_smbios_release_buffer();
return dell_smbios_error(ret);
}
static int __init dell_wmi_init(void)
{
int err;
acpi_status status;
if (!wmi_has_guid(DELL_EVENT_GUID) ||
!wmi_has_guid(DELL_DESCRIPTOR_GUID)) {
pr_warn("Dell WMI GUID were not found\n");
return -ENODEV;
}
err = dell_wmi_check_descriptor_buffer();
if (err)
return err;
err = dell_wmi_input_setup();
if (err)
return err;
status = wmi_install_notify_handler(DELL_EVENT_GUID,
dell_wmi_notify, NULL);
if (ACPI_FAILURE(status)) {
input_unregister_device(dell_wmi_input_dev);
pr_err("Unable to register notify handler - %d\n", status);
return -ENODEV;
}
dmi_check_system(dell_wmi_smbios_list);
if (wmi_requires_smbios_request) {
err = dell_wmi_events_set_enabled(true);
if (err) {
pr_err("Failed to enable WMI events\n");
wmi_remove_notify_handler(DELL_EVENT_GUID);
input_unregister_device(dell_wmi_input_dev);
return err;
}
}
return 0;
}
static void __exit dell_wmi_exit(void)
{
if (wmi_requires_smbios_request)
dell_wmi_events_set_enabled(false);
wmi_remove_notify_handler(DELL_EVENT_GUID);
input_unregister_device(dell_wmi_input_dev);
}
