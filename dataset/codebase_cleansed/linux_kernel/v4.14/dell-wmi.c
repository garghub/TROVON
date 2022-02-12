static int __init dmi_matched(const struct dmi_system_id *dmi)
{
wmi_requires_smbios_request = 1;
return 1;
}
static void dell_wmi_process_key(struct wmi_device *wdev, int type, int code)
{
struct dell_wmi_priv *priv = dev_get_drvdata(&wdev->dev);
const struct key_entry *key;
key = sparse_keymap_entry_from_scancode(priv->input_dev,
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
sparse_keymap_report_entry(priv->input_dev, key, 1, true);
}
static void dell_wmi_notify(struct wmi_device *wdev,
union acpi_object *obj)
{
struct dell_wmi_priv *priv = dev_get_drvdata(&wdev->dev);
u16 *buffer_entry, *buffer_end;
acpi_size buffer_size;
int len, i;
if (obj->type != ACPI_TYPE_BUFFER) {
pr_warn("bad response type %x\n", obj->type);
return;
}
pr_debug("Received WMI event (%*ph)\n",
obj->buffer.length, obj->buffer.pointer);
buffer_entry = (u16 *)obj->buffer.pointer;
buffer_size = obj->buffer.length/2;
buffer_end = buffer_entry + buffer_size;
if (priv->interface_version == 0 && buffer_entry < buffer_end)
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
dell_wmi_process_key(wdev, 0x0000,
buffer_entry[2]);
break;
case 0x0010:
case 0x0011:
for (i = 2; i < len; ++i)
dell_wmi_process_key(wdev, buffer_entry[1],
buffer_entry[i]);
break;
default:
pr_info("Unknown WMI event type 0x%x\n",
(int)buffer_entry[1]);
break;
}
buffer_entry += len;
}
}
static bool have_scancode(u32 scancode, const struct key_entry *keymap, int len)
{
int i;
for (i = 0; i < len; i++)
if (keymap[i].code == scancode)
return true;
return false;
}
static void handle_dmi_entry(const struct dmi_header *dm, void *opaque)
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
static int dell_wmi_input_setup(struct wmi_device *wdev)
{
struct dell_wmi_priv *priv = dev_get_drvdata(&wdev->dev);
struct dell_dmi_results dmi_results = {};
struct key_entry *keymap;
int err, i, pos = 0;
priv->input_dev = input_allocate_device();
if (!priv->input_dev)
return -ENOMEM;
priv->input_dev->name = "Dell WMI hotkeys";
priv->input_dev->id.bustype = BUS_HOST;
priv->input_dev->dev.parent = &wdev->dev;
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
err = sparse_keymap_setup(priv->input_dev, keymap, NULL);
kfree(keymap);
if (err)
goto err_free_dev;
err = input_register_device(priv->input_dev);
if (err)
goto err_free_dev;
return 0;
err_free_dev:
input_free_device(priv->input_dev);
return err;
}
static void dell_wmi_input_destroy(struct wmi_device *wdev)
{
struct dell_wmi_priv *priv = dev_get_drvdata(&wdev->dev);
input_unregister_device(priv->input_dev);
}
static int dell_wmi_check_descriptor_buffer(struct wmi_device *wdev)
{
struct dell_wmi_priv *priv = dev_get_drvdata(&wdev->dev);
union acpi_object *obj = NULL;
struct wmi_device *desc_dev;
u32 *buffer;
int ret;
desc_dev = wmidev_get_other_guid(wdev, DELL_DESCRIPTOR_GUID);
if (!desc_dev) {
dev_err(&wdev->dev, "Dell WMI descriptor does not exist\n");
return -ENODEV;
}
obj = wmidev_block_query(desc_dev, 0);
if (!obj) {
dev_err(&wdev->dev, "failed to read Dell WMI descriptor\n");
ret = -EIO;
goto out;
}
if (obj->type != ACPI_TYPE_BUFFER) {
dev_err(&wdev->dev, "Dell descriptor has wrong type\n");
ret = -EINVAL;
goto out;
}
if (obj->buffer.length != 128) {
dev_err(&wdev->dev,
"Dell descriptor buffer has invalid length (%d)\n",
obj->buffer.length);
if (obj->buffer.length < 16) {
ret = -EINVAL;
goto out;
}
}
buffer = (u32 *)obj->buffer.pointer;
if (buffer[0] != 0x4C4C4544 && buffer[1] != 0x494D5720)
dev_warn(&wdev->dev, "Dell descriptor buffer has invalid signature (%*ph)\n",
8, buffer);
if (buffer[2] != 0 && buffer[2] != 1)
dev_warn(&wdev->dev, "Dell descriptor buffer has unknown version (%d)\n",
buffer[2]);
if (buffer[3] != 4096)
dev_warn(&wdev->dev, "Dell descriptor buffer has invalid buffer length (%d)\n",
buffer[3]);
priv->interface_version = buffer[2];
ret = 0;
dev_info(&wdev->dev, "Detected Dell WMI interface version %u\n",
priv->interface_version);
out:
kfree(obj);
put_device(&desc_dev->dev);
return ret;
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
static int dell_wmi_probe(struct wmi_device *wdev)
{
struct dell_wmi_priv *priv;
int err;
priv = devm_kzalloc(
&wdev->dev, sizeof(struct dell_wmi_priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
dev_set_drvdata(&wdev->dev, priv);
err = dell_wmi_check_descriptor_buffer(wdev);
if (err)
return err;
return dell_wmi_input_setup(wdev);
}
static int dell_wmi_remove(struct wmi_device *wdev)
{
dell_wmi_input_destroy(wdev);
return 0;
}
static int __init dell_wmi_init(void)
{
int err;
dmi_check_system(dell_wmi_smbios_list);
if (wmi_requires_smbios_request) {
err = dell_wmi_events_set_enabled(true);
if (err) {
pr_err("Failed to enable WMI events\n");
return err;
}
}
return wmi_driver_register(&dell_wmi_driver);
}
static void __exit dell_wmi_exit(void)
{
if (wmi_requires_smbios_request)
dell_wmi_events_set_enabled(false);
wmi_driver_unregister(&dell_wmi_driver);
}
