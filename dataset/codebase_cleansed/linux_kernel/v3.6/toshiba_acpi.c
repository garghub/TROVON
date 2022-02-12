static __inline__ void _set_bit(u32 * word, u32 mask, int value)
{
*word = (*word & ~mask) | (mask * value);
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
return (status == AE_OK) ? 0 : -EIO;
}
static acpi_status hci_raw(struct toshiba_acpi_dev *dev,
const u32 in[HCI_WORDS], u32 out[HCI_WORDS])
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
status = acpi_evaluate_object(dev->acpi_dev->handle,
(char *)dev->method_hci, &params,
&results);
if ((status == AE_OK) && (out_objs->package.count <= HCI_WORDS)) {
for (i = 0; i < out_objs->package.count; ++i) {
out[i] = out_objs->package.elements[i].integer.value;
}
}
return status;
}
static acpi_status hci_write1(struct toshiba_acpi_dev *dev, u32 reg,
u32 in1, u32 *result)
{
u32 in[HCI_WORDS] = { HCI_SET, reg, in1, 0, 0, 0 };
u32 out[HCI_WORDS];
acpi_status status = hci_raw(dev, in, out);
*result = (status == AE_OK) ? out[0] : HCI_FAILURE;
return status;
}
static acpi_status hci_read1(struct toshiba_acpi_dev *dev, u32 reg,
u32 *out1, u32 *result)
{
u32 in[HCI_WORDS] = { HCI_GET, reg, 0, 0, 0, 0 };
u32 out[HCI_WORDS];
acpi_status status = hci_raw(dev, in, out);
*out1 = out[2];
*result = (status == AE_OK) ? out[0] : HCI_FAILURE;
return status;
}
static acpi_status hci_write2(struct toshiba_acpi_dev *dev, u32 reg,
u32 in1, u32 in2, u32 *result)
{
u32 in[HCI_WORDS] = { HCI_SET, reg, in1, in2, 0, 0 };
u32 out[HCI_WORDS];
acpi_status status = hci_raw(dev, in, out);
*result = (status == AE_OK) ? out[0] : HCI_FAILURE;
return status;
}
static acpi_status hci_read2(struct toshiba_acpi_dev *dev, u32 reg,
u32 *out1, u32 *out2, u32 *result)
{
u32 in[HCI_WORDS] = { HCI_GET, reg, *out1, *out2, 0, 0 };
u32 out[HCI_WORDS];
acpi_status status = hci_raw(dev, in, out);
*out1 = out[2];
*out2 = out[3];
*result = (status == AE_OK) ? out[0] : HCI_FAILURE;
return status;
}
static int toshiba_illumination_available(struct toshiba_acpi_dev *dev)
{
u32 in[HCI_WORDS] = { 0, 0, 0, 0, 0, 0 };
u32 out[HCI_WORDS];
acpi_status status;
in[0] = 0xf100;
status = hci_raw(dev, in, out);
if (ACPI_FAILURE(status)) {
pr_info("Illumination device not available\n");
return 0;
}
in[0] = 0xf400;
status = hci_raw(dev, in, out);
return 1;
}
static void toshiba_illumination_set(struct led_classdev *cdev,
enum led_brightness brightness)
{
struct toshiba_acpi_dev *dev = container_of(cdev,
struct toshiba_acpi_dev, led_dev);
u32 in[HCI_WORDS] = { 0, 0, 0, 0, 0, 0 };
u32 out[HCI_WORDS];
acpi_status status;
in[0] = 0xf100;
status = hci_raw(dev, in, out);
if (ACPI_FAILURE(status)) {
pr_info("Illumination device not available\n");
return;
}
if (brightness) {
in[0] = 0xf400;
in[1] = 0x14e;
in[2] = 1;
status = hci_raw(dev, in, out);
if (ACPI_FAILURE(status)) {
pr_info("ACPI call for illumination failed\n");
return;
}
} else {
in[0] = 0xf400;
in[1] = 0x14e;
in[2] = 0;
status = hci_raw(dev, in, out);
if (ACPI_FAILURE(status)) {
pr_info("ACPI call for illumination failed.\n");
return;
}
}
in[0] = 0xf200;
in[1] = 0;
in[2] = 0;
hci_raw(dev, in, out);
}
static enum led_brightness toshiba_illumination_get(struct led_classdev *cdev)
{
struct toshiba_acpi_dev *dev = container_of(cdev,
struct toshiba_acpi_dev, led_dev);
u32 in[HCI_WORDS] = { 0, 0, 0, 0, 0, 0 };
u32 out[HCI_WORDS];
acpi_status status;
enum led_brightness result;
in[0] = 0xf100;
status = hci_raw(dev, in, out);
if (ACPI_FAILURE(status)) {
pr_info("Illumination device not available\n");
return LED_OFF;
}
in[0] = 0xf300;
in[1] = 0x14e;
status = hci_raw(dev, in, out);
if (ACPI_FAILURE(status)) {
pr_info("ACPI call for illumination failed.\n");
return LED_OFF;
}
result = out[2] ? LED_FULL : LED_OFF;
in[0] = 0xf200;
in[1] = 0;
in[2] = 0;
hci_raw(dev, in, out);
return result;
}
static u32 hci_get_bt_present(struct toshiba_acpi_dev *dev, bool *present)
{
u32 hci_result;
u32 value, value2;
value = 0;
value2 = 0;
hci_read2(dev, HCI_WIRELESS, &value, &value2, &hci_result);
if (hci_result == HCI_SUCCESS)
*present = (value & HCI_WIRELESS_BT_PRESENT) ? true : false;
return hci_result;
}
static u32 hci_get_radio_state(struct toshiba_acpi_dev *dev, bool *radio_state)
{
u32 hci_result;
u32 value, value2;
value = 0;
value2 = 0x0001;
hci_read2(dev, HCI_WIRELESS, &value, &value2, &hci_result);
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
if (hci_get_radio_state(dev, &radio_state) != HCI_SUCCESS) {
err = -EIO;
goto out;
}
if (!radio_state) {
err = 0;
goto out;
}
hci_write2(dev, HCI_WIRELESS, value, HCI_WIRELESS_BT_POWER, &result1);
hci_write2(dev, HCI_WIRELESS, value, HCI_WIRELESS_BT_ATTACH, &result2);
if (result1 != HCI_SUCCESS || result2 != HCI_SUCCESS)
err = -EIO;
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
hci_result = hci_get_radio_state(dev, &value);
if (hci_result != HCI_SUCCESS) {
mutex_unlock(&dev->mutex);
return;
}
new_rfk_state = value;
mutex_unlock(&dev->mutex);
if (rfkill_set_hw_state(rfkill, !new_rfk_state))
bt_rfkill_set_block(data, true);
}
static int get_tr_backlight_status(struct toshiba_acpi_dev *dev, bool *enabled)
{
u32 hci_result;
u32 status;
hci_read1(dev, HCI_TR_BACKLIGHT, &status, &hci_result);
*enabled = !status;
return hci_result == HCI_SUCCESS ? 0 : -EIO;
}
static int set_tr_backlight_status(struct toshiba_acpi_dev *dev, bool enable)
{
u32 hci_result;
u32 value = !enable;
hci_write1(dev, HCI_TR_BACKLIGHT, value, &hci_result);
return hci_result == HCI_SUCCESS ? 0 : -EIO;
}
static int __get_lcd_brightness(struct toshiba_acpi_dev *dev)
{
u32 hci_result;
u32 value;
int brightness = 0;
if (dev->tr_backlight_supported) {
bool enabled;
int ret = get_tr_backlight_status(dev, &enabled);
if (ret)
return ret;
if (enabled)
return 0;
brightness++;
}
hci_read1(dev, HCI_LCD_BRIGHTNESS, &value, &hci_result);
if (hci_result == HCI_SUCCESS)
return brightness + (value >> HCI_LCD_BRIGHTNESS_SHIFT);
return -EIO;
}
static int get_lcd_brightness(struct backlight_device *bd)
{
struct toshiba_acpi_dev *dev = bl_get_data(bd);
return __get_lcd_brightness(dev);
}
static int lcd_proc_show(struct seq_file *m, void *v)
{
struct toshiba_acpi_dev *dev = m->private;
int value;
int levels;
if (!dev->backlight_dev)
return -ENODEV;
levels = dev->backlight_dev->props.max_brightness + 1;
value = get_lcd_brightness(dev->backlight_dev);
if (value >= 0) {
seq_printf(m, "brightness: %d\n", value);
seq_printf(m, "brightness_levels: %d\n", levels);
return 0;
}
pr_err("Error reading LCD brightness\n");
return -EIO;
}
static int lcd_proc_open(struct inode *inode, struct file *file)
{
return single_open(file, lcd_proc_show, PDE(inode)->data);
}
static int set_lcd_brightness(struct toshiba_acpi_dev *dev, int value)
{
u32 hci_result;
if (dev->tr_backlight_supported) {
bool enable = !value;
int ret = set_tr_backlight_status(dev, enable);
if (ret)
return ret;
if (value)
value--;
}
value = value << HCI_LCD_BRIGHTNESS_SHIFT;
hci_write1(dev, HCI_LCD_BRIGHTNESS, value, &hci_result);
return hci_result == HCI_SUCCESS ? 0 : -EIO;
}
static int set_lcd_status(struct backlight_device *bd)
{
struct toshiba_acpi_dev *dev = bl_get_data(bd);
return set_lcd_brightness(dev, bd->props.brightness);
}
static ssize_t lcd_proc_write(struct file *file, const char __user *buf,
size_t count, loff_t *pos)
{
struct toshiba_acpi_dev *dev = PDE(file->f_path.dentry->d_inode)->data;
char cmd[42];
size_t len;
int value;
int ret;
int levels = dev->backlight_dev->props.max_brightness + 1;
len = min(count, sizeof(cmd) - 1);
if (copy_from_user(cmd, buf, len))
return -EFAULT;
cmd[len] = '\0';
if (sscanf(cmd, " brightness : %i", &value) == 1 &&
value >= 0 && value < levels) {
ret = set_lcd_brightness(dev, value);
if (ret == 0)
ret = count;
} else {
ret = -EINVAL;
}
return ret;
}
static int get_video_status(struct toshiba_acpi_dev *dev, u32 *status)
{
u32 hci_result;
hci_read1(dev, HCI_VIDEO_OUT, status, &hci_result);
return hci_result == HCI_SUCCESS ? 0 : -EIO;
}
static int video_proc_show(struct seq_file *m, void *v)
{
struct toshiba_acpi_dev *dev = m->private;
u32 value;
int ret;
ret = get_video_status(dev, &value);
if (!ret) {
int is_lcd = (value & HCI_VIDEO_OUT_LCD) ? 1 : 0;
int is_crt = (value & HCI_VIDEO_OUT_CRT) ? 1 : 0;
int is_tv = (value & HCI_VIDEO_OUT_TV) ? 1 : 0;
seq_printf(m, "lcd_out: %d\n", is_lcd);
seq_printf(m, "crt_out: %d\n", is_crt);
seq_printf(m, "tv_out: %d\n", is_tv);
}
return ret;
}
static int video_proc_open(struct inode *inode, struct file *file)
{
return single_open(file, video_proc_show, PDE(inode)->data);
}
static ssize_t video_proc_write(struct file *file, const char __user *buf,
size_t count, loff_t *pos)
{
struct toshiba_acpi_dev *dev = PDE(file->f_path.dentry->d_inode)->data;
char *cmd, *buffer;
int ret;
int value;
int remain = count;
int lcd_out = -1;
int crt_out = -1;
int tv_out = -1;
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
ret = get_video_status(dev, &video_out);
if (!ret) {
unsigned int new_video_out = video_out;
if (lcd_out != -1)
_set_bit(&new_video_out, HCI_VIDEO_OUT_LCD, lcd_out);
if (crt_out != -1)
_set_bit(&new_video_out, HCI_VIDEO_OUT_CRT, crt_out);
if (tv_out != -1)
_set_bit(&new_video_out, HCI_VIDEO_OUT_TV, tv_out);
if (new_video_out != video_out)
ret = write_acpi_int(METHOD_VIDEO_OUT, new_video_out);
}
return ret ? ret : count;
}
static int get_fan_status(struct toshiba_acpi_dev *dev, u32 *status)
{
u32 hci_result;
hci_read1(dev, HCI_FAN, status, &hci_result);
return hci_result == HCI_SUCCESS ? 0 : -EIO;
}
static int fan_proc_show(struct seq_file *m, void *v)
{
struct toshiba_acpi_dev *dev = m->private;
int ret;
u32 value;
ret = get_fan_status(dev, &value);
if (!ret) {
seq_printf(m, "running: %d\n", (value > 0));
seq_printf(m, "force_on: %d\n", dev->force_fan);
}
return ret;
}
static int fan_proc_open(struct inode *inode, struct file *file)
{
return single_open(file, fan_proc_show, PDE(inode)->data);
}
static ssize_t fan_proc_write(struct file *file, const char __user *buf,
size_t count, loff_t *pos)
{
struct toshiba_acpi_dev *dev = PDE(file->f_path.dentry->d_inode)->data;
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
hci_write1(dev, HCI_FAN, value, &hci_result);
if (hci_result != HCI_SUCCESS)
return -EIO;
else
dev->force_fan = value;
} else {
return -EINVAL;
}
return count;
}
static int keys_proc_show(struct seq_file *m, void *v)
{
struct toshiba_acpi_dev *dev = m->private;
u32 hci_result;
u32 value;
if (!dev->key_event_valid && dev->system_event_supported) {
hci_read1(dev, HCI_SYSTEM_EVENT, &value, &hci_result);
if (hci_result == HCI_SUCCESS) {
dev->key_event_valid = 1;
dev->last_key_event = value;
} else if (hci_result == HCI_EMPTY) {
} else if (hci_result == HCI_NOT_SUPPORTED) {
hci_write1(dev, HCI_SYSTEM_EVENT, 1, &hci_result);
pr_notice("Re-enabled hotkeys\n");
} else {
pr_err("Error reading hotkey status\n");
return -EIO;
}
}
seq_printf(m, "hotkey_ready: %d\n", dev->key_event_valid);
seq_printf(m, "hotkey: 0x%04x\n", dev->last_key_event);
return 0;
}
static int keys_proc_open(struct inode *inode, struct file *file)
{
return single_open(file, keys_proc_show, PDE(inode)->data);
}
static ssize_t keys_proc_write(struct file *file, const char __user *buf,
size_t count, loff_t *pos)
{
struct toshiba_acpi_dev *dev = PDE(file->f_path.dentry->d_inode)->data;
char cmd[42];
size_t len;
int value;
len = min(count, sizeof(cmd) - 1);
if (copy_from_user(cmd, buf, len))
return -EFAULT;
cmd[len] = '\0';
if (sscanf(cmd, " hotkey_ready : %i", &value) == 1 && value == 0) {
dev->key_event_valid = 0;
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
static void __devinit
create_toshiba_proc_entries(struct toshiba_acpi_dev *dev)
{
if (dev->backlight_dev)
proc_create_data("lcd", S_IRUGO | S_IWUSR, toshiba_proc_dir,
&lcd_proc_fops, dev);
if (dev->video_supported)
proc_create_data("video", S_IRUGO | S_IWUSR, toshiba_proc_dir,
&video_proc_fops, dev);
if (dev->fan_supported)
proc_create_data("fan", S_IRUGO | S_IWUSR, toshiba_proc_dir,
&fan_proc_fops, dev);
if (dev->hotkey_dev)
proc_create_data("keys", S_IRUGO | S_IWUSR, toshiba_proc_dir,
&keys_proc_fops, dev);
proc_create_data("version", S_IRUGO, toshiba_proc_dir,
&version_proc_fops, dev);
}
static void remove_toshiba_proc_entries(struct toshiba_acpi_dev *dev)
{
if (dev->backlight_dev)
remove_proc_entry("lcd", toshiba_proc_dir);
if (dev->video_supported)
remove_proc_entry("video", toshiba_proc_dir);
if (dev->fan_supported)
remove_proc_entry("fan", toshiba_proc_dir);
if (dev->hotkey_dev)
remove_proc_entry("keys", toshiba_proc_dir);
remove_proc_entry("version", toshiba_proc_dir);
}
static bool toshiba_acpi_i8042_filter(unsigned char data, unsigned char str,
struct serio *port)
{
if (str & 0x20)
return false;
if (unlikely(data == 0xe0))
return false;
if ((data & 0x7f) == TOS1900_FN_SCAN) {
schedule_work(&toshiba_acpi->hotkey_work);
return true;
}
return false;
}
static void toshiba_acpi_hotkey_work(struct work_struct *work)
{
acpi_handle ec_handle = ec_get_handle();
acpi_status status;
if (!ec_handle)
return;
status = acpi_evaluate_object(ec_handle, "NTFY", NULL, NULL);
if (ACPI_FAILURE(status))
pr_err("ACPI NTFY method execution failed\n");
}
static int toshiba_acpi_query_hotkey(struct toshiba_acpi_dev *dev)
{
struct acpi_buffer buf;
union acpi_object out_obj;
acpi_status status;
buf.pointer = &out_obj;
buf.length = sizeof(out_obj);
status = acpi_evaluate_object(dev->acpi_dev->handle, "INFO",
NULL, &buf);
if (ACPI_FAILURE(status) || out_obj.type != ACPI_TYPE_INTEGER) {
pr_err("ACPI INFO method execution failed\n");
return -EIO;
}
return out_obj.integer.value;
}
static void toshiba_acpi_report_hotkey(struct toshiba_acpi_dev *dev,
int scancode)
{
if (scancode == 0x100)
return;
if (scancode & 0x80)
return;
if (!sparse_keymap_report_event(dev->hotkey_dev, scancode, 1, true))
pr_info("Unknown key %x\n", scancode);
}
static int __devinit toshiba_acpi_setup_keyboard(struct toshiba_acpi_dev *dev)
{
acpi_status status;
acpi_handle ec_handle, handle;
int error;
u32 hci_result;
dev->hotkey_dev = input_allocate_device();
if (!dev->hotkey_dev) {
pr_info("Unable to register input device\n");
return -ENOMEM;
}
dev->hotkey_dev->name = "Toshiba input device";
dev->hotkey_dev->phys = "toshiba_acpi/input0";
dev->hotkey_dev->id.bustype = BUS_HOST;
error = sparse_keymap_setup(dev->hotkey_dev, toshiba_acpi_keymap, NULL);
if (error)
goto err_free_dev;
status = AE_ERROR;
ec_handle = ec_get_handle();
if (ec_handle)
status = acpi_get_handle(ec_handle, "NTFY", &handle);
if (ACPI_SUCCESS(status)) {
INIT_WORK(&dev->hotkey_work, toshiba_acpi_hotkey_work);
error = i8042_install_filter(toshiba_acpi_i8042_filter);
if (error) {
pr_err("Error installing key filter\n");
goto err_free_keymap;
}
dev->ntfy_supported = 1;
}
status = acpi_get_handle(dev->acpi_dev->handle, "INFO", &handle);
if (ACPI_SUCCESS(status)) {
dev->info_supported = 1;
} else {
hci_write1(dev, HCI_SYSTEM_EVENT, 1, &hci_result);
if (hci_result == HCI_SUCCESS)
dev->system_event_supported = 1;
}
if (!dev->info_supported && !dev->system_event_supported) {
pr_warn("No hotkey query interface found\n");
goto err_remove_filter;
}
status = acpi_evaluate_object(dev->acpi_dev->handle, "ENAB", NULL, NULL);
if (ACPI_FAILURE(status)) {
pr_info("Unable to enable hotkeys\n");
error = -ENODEV;
goto err_remove_filter;
}
error = input_register_device(dev->hotkey_dev);
if (error) {
pr_info("Unable to register input device\n");
goto err_remove_filter;
}
hci_write1(dev, HCI_HOTKEY_EVENT, HCI_HOTKEY_ENABLE, &hci_result);
return 0;
err_remove_filter:
if (dev->ntfy_supported)
i8042_remove_filter(toshiba_acpi_i8042_filter);
err_free_keymap:
sparse_keymap_free(dev->hotkey_dev);
err_free_dev:
input_free_device(dev->hotkey_dev);
dev->hotkey_dev = NULL;
return error;
}
static int __devinit toshiba_acpi_setup_backlight(struct toshiba_acpi_dev *dev)
{
struct backlight_properties props;
int brightness;
int ret;
bool enabled;
brightness = __get_lcd_brightness(dev);
if (brightness < 0)
return 0;
ret = set_lcd_brightness(dev, brightness);
if (ret) {
pr_debug("Backlight method is read-only, disabling backlight support\n");
return 0;
}
ret = get_tr_backlight_status(dev, &enabled);
dev->tr_backlight_supported = !ret;
memset(&props, 0, sizeof(props));
props.type = BACKLIGHT_PLATFORM;
props.max_brightness = HCI_LCD_BRIGHTNESS_LEVELS - 1;
if (dev->tr_backlight_supported)
props.max_brightness++;
dev->backlight_dev = backlight_device_register("toshiba",
&dev->acpi_dev->dev,
dev,
&toshiba_backlight_data,
&props);
if (IS_ERR(dev->backlight_dev)) {
ret = PTR_ERR(dev->backlight_dev);
pr_err("Could not register toshiba backlight device\n");
dev->backlight_dev = NULL;
return ret;
}
dev->backlight_dev->props.brightness = brightness;
return 0;
}
static int toshiba_acpi_remove(struct acpi_device *acpi_dev, int type)
{
struct toshiba_acpi_dev *dev = acpi_driver_data(acpi_dev);
remove_toshiba_proc_entries(dev);
if (dev->ntfy_supported) {
i8042_remove_filter(toshiba_acpi_i8042_filter);
cancel_work_sync(&dev->hotkey_work);
}
if (dev->hotkey_dev) {
input_unregister_device(dev->hotkey_dev);
sparse_keymap_free(dev->hotkey_dev);
}
if (dev->bt_rfk) {
rfkill_unregister(dev->bt_rfk);
rfkill_destroy(dev->bt_rfk);
}
if (dev->backlight_dev)
backlight_device_unregister(dev->backlight_dev);
if (dev->illumination_supported)
led_classdev_unregister(&dev->led_dev);
if (toshiba_acpi)
toshiba_acpi = NULL;
kfree(dev);
return 0;
}
static const char * __devinit find_hci_method(acpi_handle handle)
{
acpi_status status;
acpi_handle hci_handle;
status = acpi_get_handle(handle, "GHCI", &hci_handle);
if (ACPI_SUCCESS(status))
return "GHCI";
status = acpi_get_handle(handle, "SPFC", &hci_handle);
if (ACPI_SUCCESS(status))
return "SPFC";
return NULL;
}
static int __devinit toshiba_acpi_add(struct acpi_device *acpi_dev)
{
struct toshiba_acpi_dev *dev;
const char *hci_method;
u32 dummy;
bool bt_present;
int ret = 0;
if (toshiba_acpi)
return -EBUSY;
pr_info("Toshiba Laptop ACPI Extras version %s\n",
TOSHIBA_ACPI_VERSION);
hci_method = find_hci_method(acpi_dev->handle);
if (!hci_method) {
pr_err("HCI interface not found\n");
return -ENODEV;
}
dev = kzalloc(sizeof(*dev), GFP_KERNEL);
if (!dev)
return -ENOMEM;
dev->acpi_dev = acpi_dev;
dev->method_hci = hci_method;
acpi_dev->driver_data = dev;
if (toshiba_acpi_setup_keyboard(dev))
pr_info("Unable to activate hotkeys\n");
mutex_init(&dev->mutex);
ret = toshiba_acpi_setup_backlight(dev);
if (ret)
goto error;
if (hci_get_bt_present(dev, &bt_present) == HCI_SUCCESS && bt_present) {
dev->bt_rfk = rfkill_alloc("Toshiba Bluetooth",
&acpi_dev->dev,
RFKILL_TYPE_BLUETOOTH,
&toshiba_rfk_ops,
dev);
if (!dev->bt_rfk) {
pr_err("unable to allocate rfkill device\n");
ret = -ENOMEM;
goto error;
}
ret = rfkill_register(dev->bt_rfk);
if (ret) {
pr_err("unable to register rfkill device\n");
rfkill_destroy(dev->bt_rfk);
goto error;
}
}
if (toshiba_illumination_available(dev)) {
dev->led_dev.name = "toshiba::illumination";
dev->led_dev.max_brightness = 1;
dev->led_dev.brightness_set = toshiba_illumination_set;
dev->led_dev.brightness_get = toshiba_illumination_get;
if (!led_classdev_register(&acpi_dev->dev, &dev->led_dev))
dev->illumination_supported = 1;
}
ret = get_video_status(dev, &dummy);
dev->video_supported = !ret;
ret = get_fan_status(dev, &dummy);
dev->fan_supported = !ret;
create_toshiba_proc_entries(dev);
toshiba_acpi = dev;
return 0;
error:
toshiba_acpi_remove(acpi_dev, 0);
return ret;
}
static void toshiba_acpi_notify(struct acpi_device *acpi_dev, u32 event)
{
struct toshiba_acpi_dev *dev = acpi_driver_data(acpi_dev);
u32 hci_result, value;
int retries = 3;
int scancode;
if (event != 0x80)
return;
if (dev->info_supported) {
scancode = toshiba_acpi_query_hotkey(dev);
if (scancode < 0)
pr_err("Failed to query hotkey event\n");
else if (scancode != 0)
toshiba_acpi_report_hotkey(dev, scancode);
} else if (dev->system_event_supported) {
do {
hci_read1(dev, HCI_SYSTEM_EVENT, &value, &hci_result);
switch (hci_result) {
case HCI_SUCCESS:
toshiba_acpi_report_hotkey(dev, (int)value);
break;
case HCI_NOT_SUPPORTED:
hci_write1(dev, HCI_SYSTEM_EVENT, 1,
&hci_result);
pr_notice("Re-enabled hotkeys\n");
default:
retries--;
break;
}
} while (retries && hci_result != HCI_EMPTY);
}
}
static int toshiba_acpi_suspend(struct device *device)
{
struct toshiba_acpi_dev *dev = acpi_driver_data(to_acpi_device(device));
u32 result;
if (dev->hotkey_dev)
hci_write1(dev, HCI_HOTKEY_EVENT, HCI_HOTKEY_DISABLE, &result);
return 0;
}
static int toshiba_acpi_resume(struct device *device)
{
struct toshiba_acpi_dev *dev = acpi_driver_data(to_acpi_device(device));
u32 result;
if (dev->hotkey_dev)
hci_write1(dev, HCI_HOTKEY_EVENT, HCI_HOTKEY_ENABLE, &result);
return 0;
}
static int __init toshiba_acpi_init(void)
{
int ret;
if (wmi_has_guid(TOSHIBA_WMI_EVENT_GUID))
return -ENODEV;
toshiba_proc_dir = proc_mkdir(PROC_TOSHIBA, acpi_root_dir);
if (!toshiba_proc_dir) {
pr_err("Unable to create proc dir " PROC_TOSHIBA "\n");
return -ENODEV;
}
ret = acpi_bus_register_driver(&toshiba_acpi_driver);
if (ret) {
pr_err("Failed to register ACPI driver: %d\n", ret);
remove_proc_entry(PROC_TOSHIBA, acpi_root_dir);
}
return ret;
}
static void __exit toshiba_acpi_exit(void)
{
acpi_bus_unregister_driver(&toshiba_acpi_driver);
if (toshiba_proc_dir)
remove_proc_entry(PROC_TOSHIBA, acpi_root_dir);
}
