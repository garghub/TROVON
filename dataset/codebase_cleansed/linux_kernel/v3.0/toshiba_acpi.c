static __inline__ void _set_bit(u32 * word, u32 mask, int value)
{
*word = (*word & ~mask) | (mask * value);
}
static int is_valid_acpi_path(const char *methodName)
{
acpi_handle handle;
acpi_status status;
status = acpi_get_handle(NULL, (char *)methodName, &handle);
return !ACPI_FAILURE(status);
}
static int write_acpi_int(const char *methodName, int val)
{
struct acpi_object_list params;
union acpi_object in_objs[1];
acpi_status status;
params.count = ARRAY_SIZE(in_objs);
params.pointer = in_objs;
in_objs[0].type = ACPI_TYPE_INTEGER;
in_objs[0].integer.value = val;
status = acpi_evaluate_object(NULL, (char *)methodName, &params, NULL);
return (status == AE_OK);
}
static acpi_status hci_raw(const u32 in[HCI_WORDS], u32 out[HCI_WORDS])
{
struct acpi_object_list params;
union acpi_object in_objs[HCI_WORDS];
struct acpi_buffer results;
union acpi_object out_objs[HCI_WORDS + 1];
acpi_status status;
int i;
params.count = HCI_WORDS;
params.pointer = in_objs;
for (i = 0; i < HCI_WORDS; ++i) {
in_objs[i].type = ACPI_TYPE_INTEGER;
in_objs[i].integer.value = in[i];
}
results.length = sizeof(out_objs);
results.pointer = out_objs;
status = acpi_evaluate_object(NULL, (char *)method_hci, &params,
&results);
if ((status == AE_OK) && (out_objs->package.count <= HCI_WORDS)) {
for (i = 0; i < out_objs->package.count; ++i) {
out[i] = out_objs->package.elements[i].integer.value;
}
}
return status;
}
static acpi_status hci_write1(u32 reg, u32 in1, u32 * result)
{
u32 in[HCI_WORDS] = { HCI_SET, reg, in1, 0, 0, 0 };
u32 out[HCI_WORDS];
acpi_status status = hci_raw(in, out);
*result = (status == AE_OK) ? out[0] : HCI_FAILURE;
return status;
}
static acpi_status hci_read1(u32 reg, u32 * out1, u32 * result)
{
u32 in[HCI_WORDS] = { HCI_GET, reg, 0, 0, 0, 0 };
u32 out[HCI_WORDS];
acpi_status status = hci_raw(in, out);
*out1 = out[2];
*result = (status == AE_OK) ? out[0] : HCI_FAILURE;
return status;
}
static acpi_status hci_write2(u32 reg, u32 in1, u32 in2, u32 *result)
{
u32 in[HCI_WORDS] = { HCI_SET, reg, in1, in2, 0, 0 };
u32 out[HCI_WORDS];
acpi_status status = hci_raw(in, out);
*result = (status == AE_OK) ? out[0] : HCI_FAILURE;
return status;
}
static acpi_status hci_read2(u32 reg, u32 *out1, u32 *out2, u32 *result)
{
u32 in[HCI_WORDS] = { HCI_GET, reg, *out1, *out2, 0, 0 };
u32 out[HCI_WORDS];
acpi_status status = hci_raw(in, out);
*out1 = out[2];
*out2 = out[3];
*result = (status == AE_OK) ? out[0] : HCI_FAILURE;
return status;
}
static int toshiba_illumination_available(void)
{
u32 in[HCI_WORDS] = { 0, 0, 0, 0, 0, 0 };
u32 out[HCI_WORDS];
acpi_status status;
in[0] = 0xf100;
status = hci_raw(in, out);
if (ACPI_FAILURE(status)) {
pr_info("Illumination device not available\n");
return 0;
}
in[0] = 0xf400;
status = hci_raw(in, out);
return 1;
}
static void toshiba_illumination_set(struct led_classdev *cdev,
enum led_brightness brightness)
{
u32 in[HCI_WORDS] = { 0, 0, 0, 0, 0, 0 };
u32 out[HCI_WORDS];
acpi_status status;
in[0] = 0xf100;
status = hci_raw(in, out);
if (ACPI_FAILURE(status)) {
pr_info("Illumination device not available\n");
return;
}
if (brightness) {
in[0] = 0xf400;
in[1] = 0x14e;
in[2] = 1;
status = hci_raw(in, out);
if (ACPI_FAILURE(status)) {
pr_info("ACPI call for illumination failed\n");
return;
}
} else {
in[0] = 0xf400;
in[1] = 0x14e;
in[2] = 0;
status = hci_raw(in, out);
if (ACPI_FAILURE(status)) {
pr_info("ACPI call for illumination failed.\n");
return;
}
}
in[0] = 0xf200;
in[1] = 0;
in[2] = 0;
hci_raw(in, out);
}
static enum led_brightness toshiba_illumination_get(struct led_classdev *cdev)
{
u32 in[HCI_WORDS] = { 0, 0, 0, 0, 0, 0 };
u32 out[HCI_WORDS];
acpi_status status;
enum led_brightness result;
in[0] = 0xf100;
status = hci_raw(in, out);
if (ACPI_FAILURE(status)) {
pr_info("Illumination device not available\n");
return LED_OFF;
}
in[0] = 0xf300;
in[1] = 0x14e;
status = hci_raw(in, out);
if (ACPI_FAILURE(status)) {
pr_info("ACPI call for illumination failed.\n");
return LED_OFF;
}
result = out[2] ? LED_FULL : LED_OFF;
in[0] = 0xf200;
in[1] = 0;
in[2] = 0;
hci_raw(in, out);
return result;
}
static u32 hci_get_bt_present(bool *present)
{
u32 hci_result;
u32 value, value2;
value = 0;
value2 = 0;
hci_read2(HCI_WIRELESS, &value, &value2, &hci_result);
if (hci_result == HCI_SUCCESS)
*present = (value & HCI_WIRELESS_BT_PRESENT) ? true : false;
return hci_result;
}
static u32 hci_get_radio_state(bool *radio_state)
{
u32 hci_result;
u32 value, value2;
value = 0;
value2 = 0x0001;
hci_read2(HCI_WIRELESS, &value, &value2, &hci_result);
*radio_state = value & HCI_WIRELESS_KILL_SWITCH;
return hci_result;
}
static int bt_rfkill_set_block(void *data, bool blocked)
{
struct toshiba_acpi_dev *dev = data;
u32 result1, result2;
u32 value;
int err;
bool radio_state;
value = (blocked == false);
mutex_lock(&dev->mutex);
if (hci_get_radio_state(&radio_state) != HCI_SUCCESS) {
err = -EBUSY;
goto out;
}
if (!radio_state) {
err = 0;
goto out;
}
hci_write2(HCI_WIRELESS, value, HCI_WIRELESS_BT_POWER, &result1);
hci_write2(HCI_WIRELESS, value, HCI_WIRELESS_BT_ATTACH, &result2);
if (result1 != HCI_SUCCESS || result2 != HCI_SUCCESS)
err = -EBUSY;
else
err = 0;
out:
mutex_unlock(&dev->mutex);
return err;
}
static void bt_rfkill_poll(struct rfkill *rfkill, void *data)
{
bool new_rfk_state;
bool value;
u32 hci_result;
struct toshiba_acpi_dev *dev = data;
mutex_lock(&dev->mutex);
hci_result = hci_get_radio_state(&value);
if (hci_result != HCI_SUCCESS) {
mutex_unlock(&dev->mutex);
return;
}
new_rfk_state = value;
mutex_unlock(&dev->mutex);
if (rfkill_set_hw_state(rfkill, !new_rfk_state))
bt_rfkill_set_block(data, true);
}
static int get_lcd(struct backlight_device *bd)
{
u32 hci_result;
u32 value;
hci_read1(HCI_LCD_BRIGHTNESS, &value, &hci_result);
if (hci_result == HCI_SUCCESS) {
return (value >> HCI_LCD_BRIGHTNESS_SHIFT);
} else
return -EFAULT;
}
static int lcd_proc_show(struct seq_file *m, void *v)
{
int value = get_lcd(NULL);
if (value >= 0) {
seq_printf(m, "brightness: %d\n", value);
seq_printf(m, "brightness_levels: %d\n",
HCI_LCD_BRIGHTNESS_LEVELS);
} else {
pr_err("Error reading LCD brightness\n");
}
return 0;
}
static int lcd_proc_open(struct inode *inode, struct file *file)
{
return single_open(file, lcd_proc_show, NULL);
}
static int set_lcd(int value)
{
u32 hci_result;
value = value << HCI_LCD_BRIGHTNESS_SHIFT;
hci_write1(HCI_LCD_BRIGHTNESS, value, &hci_result);
if (hci_result != HCI_SUCCESS)
return -EFAULT;
return 0;
}
static int set_lcd_status(struct backlight_device *bd)
{
return set_lcd(bd->props.brightness);
}
static ssize_t lcd_proc_write(struct file *file, const char __user *buf,
size_t count, loff_t *pos)
{
char cmd[42];
size_t len;
int value;
int ret;
len = min(count, sizeof(cmd) - 1);
if (copy_from_user(cmd, buf, len))
return -EFAULT;
cmd[len] = '\0';
if (sscanf(cmd, " brightness : %i", &value) == 1 &&
value >= 0 && value < HCI_LCD_BRIGHTNESS_LEVELS) {
ret = set_lcd(value);
if (ret == 0)
ret = count;
} else {
ret = -EINVAL;
}
return ret;
}
static int video_proc_show(struct seq_file *m, void *v)
{
u32 hci_result;
u32 value;
hci_read1(HCI_VIDEO_OUT, &value, &hci_result);
if (hci_result == HCI_SUCCESS) {
int is_lcd = (value & HCI_VIDEO_OUT_LCD) ? 1 : 0;
int is_crt = (value & HCI_VIDEO_OUT_CRT) ? 1 : 0;
int is_tv = (value & HCI_VIDEO_OUT_TV) ? 1 : 0;
seq_printf(m, "lcd_out: %d\n", is_lcd);
seq_printf(m, "crt_out: %d\n", is_crt);
seq_printf(m, "tv_out: %d\n", is_tv);
} else {
pr_err("Error reading video out status\n");
}
return 0;
}
static int video_proc_open(struct inode *inode, struct file *file)
{
return single_open(file, video_proc_show, NULL);
}
static ssize_t video_proc_write(struct file *file, const char __user *buf,
size_t count, loff_t *pos)
{
char *cmd, *buffer;
int value;
int remain = count;
int lcd_out = -1;
int crt_out = -1;
int tv_out = -1;
u32 hci_result;
u32 video_out;
cmd = kmalloc(count + 1, GFP_KERNEL);
if (!cmd)
return -ENOMEM;
if (copy_from_user(cmd, buf, count)) {
kfree(cmd);
return -EFAULT;
}
cmd[count] = '\0';
buffer = cmd;
while (remain) {
if (sscanf(buffer, " lcd_out : %i", &value) == 1)
lcd_out = value & 1;
else if (sscanf(buffer, " crt_out : %i", &value) == 1)
crt_out = value & 1;
else if (sscanf(buffer, " tv_out : %i", &value) == 1)
tv_out = value & 1;
do {
++buffer;
--remain;
}
while (remain && *(buffer - 1) != ';');
}
kfree(cmd);
hci_read1(HCI_VIDEO_OUT, &video_out, &hci_result);
if (hci_result == HCI_SUCCESS) {
unsigned int new_video_out = video_out;
if (lcd_out != -1)
_set_bit(&new_video_out, HCI_VIDEO_OUT_LCD, lcd_out);
if (crt_out != -1)
_set_bit(&new_video_out, HCI_VIDEO_OUT_CRT, crt_out);
if (tv_out != -1)
_set_bit(&new_video_out, HCI_VIDEO_OUT_TV, tv_out);
if (new_video_out != video_out)
write_acpi_int(METHOD_VIDEO_OUT, new_video_out);
} else {
return -EFAULT;
}
return count;
}
static int fan_proc_show(struct seq_file *m, void *v)
{
u32 hci_result;
u32 value;
hci_read1(HCI_FAN, &value, &hci_result);
if (hci_result == HCI_SUCCESS) {
seq_printf(m, "running: %d\n", (value > 0));
seq_printf(m, "force_on: %d\n", force_fan);
} else {
pr_err("Error reading fan status\n");
}
return 0;
}
static int fan_proc_open(struct inode *inode, struct file *file)
{
return single_open(file, fan_proc_show, NULL);
}
static ssize_t fan_proc_write(struct file *file, const char __user *buf,
size_t count, loff_t *pos)
{
char cmd[42];
size_t len;
int value;
u32 hci_result;
len = min(count, sizeof(cmd) - 1);
if (copy_from_user(cmd, buf, len))
return -EFAULT;
cmd[len] = '\0';
if (sscanf(cmd, " force_on : %i", &value) == 1 &&
value >= 0 && value <= 1) {
hci_write1(HCI_FAN, value, &hci_result);
if (hci_result != HCI_SUCCESS)
return -EFAULT;
else
force_fan = value;
} else {
return -EINVAL;
}
return count;
}
static int keys_proc_show(struct seq_file *m, void *v)
{
u32 hci_result;
u32 value;
if (!key_event_valid) {
hci_read1(HCI_SYSTEM_EVENT, &value, &hci_result);
if (hci_result == HCI_SUCCESS) {
key_event_valid = 1;
last_key_event = value;
} else if (hci_result == HCI_EMPTY) {
} else if (hci_result == HCI_NOT_SUPPORTED) {
hci_write1(HCI_SYSTEM_EVENT, 1, &hci_result);
pr_notice("Re-enabled hotkeys\n");
} else {
pr_err("Error reading hotkey status\n");
goto end;
}
}
seq_printf(m, "hotkey_ready: %d\n", key_event_valid);
seq_printf(m, "hotkey: 0x%04x\n", last_key_event);
end:
return 0;
}
static int keys_proc_open(struct inode *inode, struct file *file)
{
return single_open(file, keys_proc_show, NULL);
}
static ssize_t keys_proc_write(struct file *file, const char __user *buf,
size_t count, loff_t *pos)
{
char cmd[42];
size_t len;
int value;
len = min(count, sizeof(cmd) - 1);
if (copy_from_user(cmd, buf, len))
return -EFAULT;
cmd[len] = '\0';
if (sscanf(cmd, " hotkey_ready : %i", &value) == 1 && value == 0) {
key_event_valid = 0;
} else {
return -EINVAL;
}
return count;
}
static int version_proc_show(struct seq_file *m, void *v)
{
seq_printf(m, "driver: %s\n", TOSHIBA_ACPI_VERSION);
seq_printf(m, "proc_interface: %d\n", PROC_INTERFACE_VERSION);
return 0;
}
static int version_proc_open(struct inode *inode, struct file *file)
{
return single_open(file, version_proc_show, PDE(inode)->data);
}
static void __init create_toshiba_proc_entries(void)
{
proc_create("lcd", S_IRUGO | S_IWUSR, toshiba_proc_dir, &lcd_proc_fops);
proc_create("video", S_IRUGO | S_IWUSR, toshiba_proc_dir, &video_proc_fops);
proc_create("fan", S_IRUGO | S_IWUSR, toshiba_proc_dir, &fan_proc_fops);
proc_create("keys", S_IRUGO | S_IWUSR, toshiba_proc_dir, &keys_proc_fops);
proc_create("version", S_IRUGO, toshiba_proc_dir, &version_proc_fops);
}
static void remove_toshiba_proc_entries(void)
{
remove_proc_entry("lcd", toshiba_proc_dir);
remove_proc_entry("video", toshiba_proc_dir);
remove_proc_entry("fan", toshiba_proc_dir);
remove_proc_entry("keys", toshiba_proc_dir);
remove_proc_entry("version", toshiba_proc_dir);
}
static void toshiba_acpi_notify(acpi_handle handle, u32 event, void *context)
{
u32 hci_result, value;
if (event != 0x80)
return;
do {
hci_read1(HCI_SYSTEM_EVENT, &value, &hci_result);
if (hci_result == HCI_SUCCESS) {
if (value == 0x100)
continue;
if (value & 0x80)
continue;
if (!sparse_keymap_report_event(toshiba_acpi.hotkey_dev,
value, 1, true)) {
pr_info("Unknown key %x\n",
value);
}
} else if (hci_result == HCI_NOT_SUPPORTED) {
hci_write1(HCI_SYSTEM_EVENT, 1, &hci_result);
pr_notice("Re-enabled hotkeys\n");
}
} while (hci_result != HCI_EMPTY);
}
static int __init toshiba_acpi_setup_keyboard(char *device)
{
acpi_status status;
int error;
status = acpi_get_handle(NULL, device, &toshiba_acpi.handle);
if (ACPI_FAILURE(status)) {
pr_info("Unable to get notification device\n");
return -ENODEV;
}
toshiba_acpi.hotkey_dev = input_allocate_device();
if (!toshiba_acpi.hotkey_dev) {
pr_info("Unable to register input device\n");
return -ENOMEM;
}
toshiba_acpi.hotkey_dev->name = "Toshiba input device";
toshiba_acpi.hotkey_dev->phys = device;
toshiba_acpi.hotkey_dev->id.bustype = BUS_HOST;
error = sparse_keymap_setup(toshiba_acpi.hotkey_dev,
toshiba_acpi_keymap, NULL);
if (error)
goto err_free_dev;
status = acpi_install_notify_handler(toshiba_acpi.handle,
ACPI_DEVICE_NOTIFY, toshiba_acpi_notify, NULL);
if (ACPI_FAILURE(status)) {
pr_info("Unable to install hotkey notification\n");
error = -ENODEV;
goto err_free_keymap;
}
status = acpi_evaluate_object(toshiba_acpi.handle, "ENAB", NULL, NULL);
if (ACPI_FAILURE(status)) {
pr_info("Unable to enable hotkeys\n");
error = -ENODEV;
goto err_remove_notify;
}
error = input_register_device(toshiba_acpi.hotkey_dev);
if (error) {
pr_info("Unable to register input device\n");
goto err_remove_notify;
}
return 0;
err_remove_notify:
acpi_remove_notify_handler(toshiba_acpi.handle,
ACPI_DEVICE_NOTIFY, toshiba_acpi_notify);
err_free_keymap:
sparse_keymap_free(toshiba_acpi.hotkey_dev);
err_free_dev:
input_free_device(toshiba_acpi.hotkey_dev);
toshiba_acpi.hotkey_dev = NULL;
return error;
}
static void toshiba_acpi_exit(void)
{
if (toshiba_acpi.hotkey_dev) {
acpi_remove_notify_handler(toshiba_acpi.handle,
ACPI_DEVICE_NOTIFY, toshiba_acpi_notify);
sparse_keymap_free(toshiba_acpi.hotkey_dev);
input_unregister_device(toshiba_acpi.hotkey_dev);
}
if (toshiba_acpi.bt_rfk) {
rfkill_unregister(toshiba_acpi.bt_rfk);
rfkill_destroy(toshiba_acpi.bt_rfk);
}
if (toshiba_backlight_device)
backlight_device_unregister(toshiba_backlight_device);
remove_toshiba_proc_entries();
if (toshiba_proc_dir)
remove_proc_entry(PROC_TOSHIBA, acpi_root_dir);
if (toshiba_acpi.illumination_installed)
led_classdev_unregister(&toshiba_led);
platform_device_unregister(toshiba_acpi.p_dev);
return;
}
static int __init toshiba_acpi_init(void)
{
u32 hci_result;
bool bt_present;
int ret = 0;
struct backlight_properties props;
if (acpi_disabled)
return -ENODEV;
if (is_valid_acpi_path(TOSH_INTERFACE_1 GHCI_METHOD)) {
method_hci = TOSH_INTERFACE_1 GHCI_METHOD;
if (toshiba_acpi_setup_keyboard(TOSH_INTERFACE_1))
pr_info("Unable to activate hotkeys\n");
} else if (is_valid_acpi_path(TOSH_INTERFACE_2 GHCI_METHOD)) {
method_hci = TOSH_INTERFACE_2 GHCI_METHOD;
if (toshiba_acpi_setup_keyboard(TOSH_INTERFACE_2))
pr_info("Unable to activate hotkeys\n");
} else
return -ENODEV;
pr_info("Toshiba Laptop ACPI Extras version %s\n",
TOSHIBA_ACPI_VERSION);
pr_info(" HCI method: %s\n", method_hci);
mutex_init(&toshiba_acpi.mutex);
toshiba_acpi.p_dev = platform_device_register_simple("toshiba_acpi",
-1, NULL, 0);
if (IS_ERR(toshiba_acpi.p_dev)) {
ret = PTR_ERR(toshiba_acpi.p_dev);
pr_err("unable to register platform device\n");
toshiba_acpi.p_dev = NULL;
toshiba_acpi_exit();
return ret;
}
force_fan = 0;
key_event_valid = 0;
hci_write1(HCI_SYSTEM_EVENT, 1, &hci_result);
toshiba_proc_dir = proc_mkdir(PROC_TOSHIBA, acpi_root_dir);
if (!toshiba_proc_dir) {
toshiba_acpi_exit();
return -ENODEV;
} else {
create_toshiba_proc_entries();
}
props.type = BACKLIGHT_PLATFORM;
props.max_brightness = HCI_LCD_BRIGHTNESS_LEVELS - 1;
toshiba_backlight_device = backlight_device_register("toshiba",
&toshiba_acpi.p_dev->dev,
NULL,
&toshiba_backlight_data,
&props);
if (IS_ERR(toshiba_backlight_device)) {
ret = PTR_ERR(toshiba_backlight_device);
pr_err("Could not register toshiba backlight device\n");
toshiba_backlight_device = NULL;
toshiba_acpi_exit();
return ret;
}
if (hci_get_bt_present(&bt_present) == HCI_SUCCESS && bt_present) {
toshiba_acpi.bt_rfk = rfkill_alloc(toshiba_acpi.bt_name,
&toshiba_acpi.p_dev->dev,
RFKILL_TYPE_BLUETOOTH,
&toshiba_rfk_ops,
&toshiba_acpi);
if (!toshiba_acpi.bt_rfk) {
pr_err("unable to allocate rfkill device\n");
toshiba_acpi_exit();
return -ENOMEM;
}
ret = rfkill_register(toshiba_acpi.bt_rfk);
if (ret) {
pr_err("unable to register rfkill device\n");
rfkill_destroy(toshiba_acpi.bt_rfk);
toshiba_acpi_exit();
return ret;
}
}
toshiba_acpi.illumination_installed = 0;
if (toshiba_illumination_available()) {
if (!led_classdev_register(&(toshiba_acpi.p_dev->dev),
&toshiba_led))
toshiba_acpi.illumination_installed = 1;
}
return 0;
}
