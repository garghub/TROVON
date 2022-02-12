static void dell_wmi_process_key(int reported_key)
{
const struct key_entry *key;
key = sparse_keymap_entry_from_scancode(dell_wmi_input_dev,
reported_key);
if (!key) {
pr_info("Unknown key with scancode 0x%x pressed\n",
reported_key);
return;
}
pr_debug("Key %x pressed\n", reported_key);
if ((key->keycode == KEY_BRIGHTNESSUP ||
key->keycode == KEY_BRIGHTNESSDOWN) &&
acpi_video_handles_brightness_key_presses())
return;
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
if (!dell_new_hk_type) {
if (buffer_size >= 3 && buffer_entry[1] == 0x0)
dell_wmi_process_key(buffer_entry[2]);
else if (buffer_size >= 2)
dell_wmi_process_key(buffer_entry[1]);
else
pr_info("Received unknown WMI event\n");
kfree(obj);
return;
}
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
case 0x00:
for (i = 2; i < len; ++i) {
switch (buffer_entry[i]) {
case 0xe043:
pr_debug("NIC Link is Up\n");
break;
case 0xe044:
pr_debug("NIC Link is Down\n");
break;
case 0xe045:
default:
pr_info("Unknown WMI event type 0x00: "
"0x%x\n", (int)buffer_entry[i]);
break;
}
}
break;
case 0x10:
for (i = 2; i < len; ++i)
dell_wmi_process_key(buffer_entry[i]);
break;
case 0x11:
for (i = 2; i < len; ++i) {
switch (buffer_entry[i]) {
case 0xfff0:
pr_debug("Battery unplugged\n");
break;
case 0xfff1:
pr_debug("Battery inserted\n");
break;
case 0x01e1:
case 0x02ea:
case 0x02eb:
case 0x02ec:
case 0x02f6:
pr_debug("Keyboard backlight level "
"changed\n");
break;
default:
pr_info("Unknown WMI event type 0x11: "
"0x%x\n", (int)buffer_entry[i]);
break;
}
}
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
keymap[i].type = KE_IGNORE;
else
keymap[i].type = KE_KEY;
keymap[i].code = bios_entry->scancode;
keymap[i].keycode = keycode;
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
dmi_walk(find_hk_type, NULL);
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
