static int write_acpi_int_ret(acpi_handle handle, const char *method, int val,
struct acpi_buffer *output)
{
struct acpi_object_list params;
union acpi_object in_obj;
acpi_status status;
if (!handle)
return -1;
params.count = 1;
params.pointer = &in_obj;
in_obj.type = ACPI_TYPE_INTEGER;
in_obj.integer.value = val;
status = acpi_evaluate_object(handle, (char *)method, &params, output);
if (status == AE_OK)
return 0;
else
return -1;
}
static int write_acpi_int(acpi_handle handle, const char *method, int val)
{
return write_acpi_int_ret(handle, method, val, NULL);
}
static int acpi_check_handle(acpi_handle handle, const char *method,
acpi_handle *ret)
{
acpi_status status;
if (method == NULL)
return -ENODEV;
if (ret)
status = acpi_get_handle(handle, (char *)method,
ret);
else {
acpi_handle dummy;
status = acpi_get_handle(handle, (char *)method,
&dummy);
}
if (status != AE_OK) {
if (ret)
pr_warn("Error finding %s\n", method);
return -ENODEV;
}
return 0;
}
static bool asus_check_pega_lucid(struct asus_laptop *asus)
{
return !strcmp(asus->name, DEVICE_NAME_PEGA) &&
!acpi_check_handle(asus->handle, METHOD_PEGA_ENABLE, NULL) &&
!acpi_check_handle(asus->handle, METHOD_PEGA_DISABLE, NULL) &&
!acpi_check_handle(asus->handle, METHOD_PEGA_READ, NULL);
}
static int asus_pega_lucid_set(struct asus_laptop *asus, int unit, bool enable)
{
char *method = enable ? METHOD_PEGA_ENABLE : METHOD_PEGA_DISABLE;
return write_acpi_int(asus->handle, method, unit);
}
static int pega_acc_axis(struct asus_laptop *asus, int curr, char *method)
{
int i, delta;
unsigned long long val;
for (i = 0; i < PEGA_ACC_RETRIES; i++) {
acpi_evaluate_integer(asus->handle, method, NULL, &val);
delta = abs(curr - (short)val);
if (delta < 128 && !(val & ~0xffff))
break;
}
return clamp_val((short)val, -PEGA_ACC_CLAMP, PEGA_ACC_CLAMP);
}
static void pega_accel_poll(struct input_polled_dev *ipd)
{
struct device *parent = ipd->input->dev.parent;
struct asus_laptop *asus = dev_get_drvdata(parent);
if (!asus->pega_acc_live) {
asus->pega_acc_live = true;
input_report_abs(ipd->input, ABS_X, 0);
input_report_abs(ipd->input, ABS_Y, 0);
input_report_abs(ipd->input, ABS_Z, 0);
input_sync(ipd->input);
return;
}
asus->pega_acc_x = pega_acc_axis(asus, asus->pega_acc_x, METHOD_XLRX);
asus->pega_acc_y = pega_acc_axis(asus, asus->pega_acc_y, METHOD_XLRY);
asus->pega_acc_z = pega_acc_axis(asus, asus->pega_acc_z, METHOD_XLRZ);
input_report_abs(ipd->input, ABS_X, -asus->pega_acc_x);
input_report_abs(ipd->input, ABS_Y, -asus->pega_acc_y);
input_report_abs(ipd->input, ABS_Z, asus->pega_acc_z);
input_sync(ipd->input);
}
static void pega_accel_exit(struct asus_laptop *asus)
{
if (asus->pega_accel_poll) {
input_unregister_polled_device(asus->pega_accel_poll);
input_free_polled_device(asus->pega_accel_poll);
}
asus->pega_accel_poll = NULL;
}
static int pega_accel_init(struct asus_laptop *asus)
{
int err;
struct input_polled_dev *ipd;
if (!asus->is_pega_lucid)
return -ENODEV;
if (acpi_check_handle(asus->handle, METHOD_XLRX, NULL) ||
acpi_check_handle(asus->handle, METHOD_XLRY, NULL) ||
acpi_check_handle(asus->handle, METHOD_XLRZ, NULL))
return -ENODEV;
ipd = input_allocate_polled_device();
if (!ipd)
return -ENOMEM;
ipd->poll = pega_accel_poll;
ipd->poll_interval = 125;
ipd->poll_interval_min = 50;
ipd->poll_interval_max = 2000;
ipd->input->name = PEGA_ACCEL_DESC;
ipd->input->phys = PEGA_ACCEL_NAME "/input0";
ipd->input->dev.parent = &asus->platform_device->dev;
ipd->input->id.bustype = BUS_HOST;
set_bit(EV_ABS, ipd->input->evbit);
input_set_abs_params(ipd->input, ABS_X,
-PEGA_ACC_CLAMP, PEGA_ACC_CLAMP, 0, 0);
input_set_abs_params(ipd->input, ABS_Y,
-PEGA_ACC_CLAMP, PEGA_ACC_CLAMP, 0, 0);
input_set_abs_params(ipd->input, ABS_Z,
-PEGA_ACC_CLAMP, PEGA_ACC_CLAMP, 0, 0);
err = input_register_polled_device(ipd);
if (err)
goto exit;
asus->pega_accel_poll = ipd;
return 0;
exit:
input_free_polled_device(ipd);
return err;
}
static int asus_led_set(struct asus_laptop *asus, const char *method,
int value)
{
if (!strcmp(method, METHOD_MLED))
value = !value;
else if (!strcmp(method, METHOD_GLED))
value = !value + 1;
else
value = !!value;
return write_acpi_int(asus->handle, method, value);
}
static void asus_led_cdev_set(struct led_classdev *led_cdev,
enum led_brightness value)
{
struct asus_led *led = container_of(led_cdev, struct asus_led, led);
struct asus_laptop *asus = led->asus;
led->wk = !!value;
queue_work(asus->led_workqueue, &led->work);
}
static void asus_led_cdev_update(struct work_struct *work)
{
struct asus_led *led = container_of(work, struct asus_led, work);
struct asus_laptop *asus = led->asus;
asus_led_set(asus, led->method, led->wk);
}
static enum led_brightness asus_led_cdev_get(struct led_classdev *led_cdev)
{
return led_cdev->brightness;
}
static int asus_kled_lvl(struct asus_laptop *asus)
{
unsigned long long kblv;
struct acpi_object_list params;
union acpi_object in_obj;
acpi_status rv;
params.count = 1;
params.pointer = &in_obj;
in_obj.type = ACPI_TYPE_INTEGER;
in_obj.integer.value = 2;
rv = acpi_evaluate_integer(asus->handle, METHOD_KBD_LIGHT_GET,
&params, &kblv);
if (ACPI_FAILURE(rv)) {
pr_warn("Error reading kled level\n");
return -ENODEV;
}
return kblv;
}
static int asus_kled_set(struct asus_laptop *asus, int kblv)
{
if (kblv > 0)
kblv = (1 << 7) | (kblv & 0x7F);
else
kblv = 0;
if (write_acpi_int(asus->handle, METHOD_KBD_LIGHT_SET, kblv)) {
pr_warn("Keyboard LED display write failed\n");
return -EINVAL;
}
return 0;
}
static void asus_kled_cdev_set(struct led_classdev *led_cdev,
enum led_brightness value)
{
struct asus_led *led = container_of(led_cdev, struct asus_led, led);
struct asus_laptop *asus = led->asus;
led->wk = value;
queue_work(asus->led_workqueue, &led->work);
}
static void asus_kled_cdev_update(struct work_struct *work)
{
struct asus_led *led = container_of(work, struct asus_led, work);
struct asus_laptop *asus = led->asus;
asus_kled_set(asus, led->wk);
}
static enum led_brightness asus_kled_cdev_get(struct led_classdev *led_cdev)
{
struct asus_led *led = container_of(led_cdev, struct asus_led, led);
struct asus_laptop *asus = led->asus;
return asus_kled_lvl(asus);
}
static void asus_led_exit(struct asus_laptop *asus)
{
if (!IS_ERR_OR_NULL(asus->mled.led.dev))
led_classdev_unregister(&asus->mled.led);
if (!IS_ERR_OR_NULL(asus->tled.led.dev))
led_classdev_unregister(&asus->tled.led);
if (!IS_ERR_OR_NULL(asus->pled.led.dev))
led_classdev_unregister(&asus->pled.led);
if (!IS_ERR_OR_NULL(asus->rled.led.dev))
led_classdev_unregister(&asus->rled.led);
if (!IS_ERR_OR_NULL(asus->gled.led.dev))
led_classdev_unregister(&asus->gled.led);
if (!IS_ERR_OR_NULL(asus->kled.led.dev))
led_classdev_unregister(&asus->kled.led);
if (asus->led_workqueue) {
destroy_workqueue(asus->led_workqueue);
asus->led_workqueue = NULL;
}
}
static int asus_led_register(struct asus_laptop *asus,
struct asus_led *led,
const char *name, const char *method)
{
struct led_classdev *led_cdev = &led->led;
if (!method || acpi_check_handle(asus->handle, method, NULL))
return 0;
led->asus = asus;
led->method = method;
INIT_WORK(&led->work, asus_led_cdev_update);
led_cdev->name = name;
led_cdev->brightness_set = asus_led_cdev_set;
led_cdev->brightness_get = asus_led_cdev_get;
led_cdev->max_brightness = 1;
return led_classdev_register(&asus->platform_device->dev, led_cdev);
}
static int asus_led_init(struct asus_laptop *asus)
{
int r;
if (asus->is_pega_lucid)
return 0;
asus->led_workqueue = create_singlethread_workqueue("led_workqueue");
if (!asus->led_workqueue)
return -ENOMEM;
r = asus_led_register(asus, &asus->mled, "asus::mail", METHOD_MLED);
if (r)
goto error;
r = asus_led_register(asus, &asus->tled, "asus::touchpad", METHOD_TLED);
if (r)
goto error;
r = asus_led_register(asus, &asus->rled, "asus::record", METHOD_RLED);
if (r)
goto error;
r = asus_led_register(asus, &asus->pled, "asus::phone", METHOD_PLED);
if (r)
goto error;
r = asus_led_register(asus, &asus->gled, "asus::gaming", METHOD_GLED);
if (r)
goto error;
if (!acpi_check_handle(asus->handle, METHOD_KBD_LIGHT_SET, NULL) &&
!acpi_check_handle(asus->handle, METHOD_KBD_LIGHT_GET, NULL)) {
struct asus_led *led = &asus->kled;
struct led_classdev *cdev = &led->led;
led->asus = asus;
INIT_WORK(&led->work, asus_kled_cdev_update);
cdev->name = "asus::kbd_backlight";
cdev->brightness_set = asus_kled_cdev_set;
cdev->brightness_get = asus_kled_cdev_get;
cdev->max_brightness = 3;
r = led_classdev_register(&asus->platform_device->dev, cdev);
}
error:
if (r)
asus_led_exit(asus);
return r;
}
static int asus_read_brightness(struct backlight_device *bd)
{
struct asus_laptop *asus = bl_get_data(bd);
unsigned long long value;
acpi_status rv = AE_OK;
rv = acpi_evaluate_integer(asus->handle, METHOD_BRIGHTNESS_GET,
NULL, &value);
if (ACPI_FAILURE(rv))
pr_warn("Error reading brightness\n");
return value;
}
static int asus_set_brightness(struct backlight_device *bd, int value)
{
struct asus_laptop *asus = bl_get_data(bd);
if (write_acpi_int(asus->handle, METHOD_BRIGHTNESS_SET, value)) {
pr_warn("Error changing brightness\n");
return -EIO;
}
return 0;
}
static int update_bl_status(struct backlight_device *bd)
{
int value = bd->props.brightness;
return asus_set_brightness(bd, value);
}
static int asus_backlight_notify(struct asus_laptop *asus)
{
struct backlight_device *bd = asus->backlight_device;
int old = bd->props.brightness;
backlight_force_update(bd, BACKLIGHT_UPDATE_HOTKEY);
return old;
}
static int asus_backlight_init(struct asus_laptop *asus)
{
struct backlight_device *bd;
struct backlight_properties props;
if (acpi_check_handle(asus->handle, METHOD_BRIGHTNESS_GET, NULL) ||
acpi_check_handle(asus->handle, METHOD_BRIGHTNESS_SET, NULL))
return 0;
memset(&props, 0, sizeof(struct backlight_properties));
props.max_brightness = 15;
props.type = BACKLIGHT_PLATFORM;
bd = backlight_device_register(ASUS_LAPTOP_FILE,
&asus->platform_device->dev, asus,
&asusbl_ops, &props);
if (IS_ERR(bd)) {
pr_err("Could not register asus backlight device\n");
asus->backlight_device = NULL;
return PTR_ERR(bd);
}
asus->backlight_device = bd;
bd->props.brightness = asus_read_brightness(bd);
bd->props.power = FB_BLANK_UNBLANK;
backlight_update_status(bd);
return 0;
}
static void asus_backlight_exit(struct asus_laptop *asus)
{
if (asus->backlight_device)
backlight_device_unregister(asus->backlight_device);
asus->backlight_device = NULL;
}
static ssize_t show_infos(struct device *dev,
struct device_attribute *attr, char *page)
{
struct asus_laptop *asus = dev_get_drvdata(dev);
int len = 0;
unsigned long long temp;
char buf[16];
acpi_status rv = AE_OK;
len += sprintf(page, ASUS_LAPTOP_NAME " " ASUS_LAPTOP_VERSION "\n");
len += sprintf(page + len, "Model reference : %s\n", asus->name);
rv = acpi_evaluate_integer(asus->handle, "SFUN", NULL, &temp);
if (!ACPI_FAILURE(rv))
len += sprintf(page + len, "SFUN value : %#x\n",
(uint) temp);
rv = acpi_evaluate_integer(asus->handle, "HRWS", NULL, &temp);
if (!ACPI_FAILURE(rv))
len += sprintf(page + len, "HRWS value : %#x\n",
(uint) temp);
rv = acpi_evaluate_integer(asus->handle, "ASYM", NULL, &temp);
if (!ACPI_FAILURE(rv))
len += sprintf(page + len, "ASYM value : %#x\n",
(uint) temp);
if (asus->dsdt_info) {
snprintf(buf, 16, "%d", asus->dsdt_info->length);
len += sprintf(page + len, "DSDT length : %s\n", buf);
snprintf(buf, 16, "%d", asus->dsdt_info->checksum);
len += sprintf(page + len, "DSDT checksum : %s\n", buf);
snprintf(buf, 16, "%d", asus->dsdt_info->revision);
len += sprintf(page + len, "DSDT revision : %s\n", buf);
snprintf(buf, 7, "%s", asus->dsdt_info->oem_id);
len += sprintf(page + len, "OEM id : %s\n", buf);
snprintf(buf, 9, "%s", asus->dsdt_info->oem_table_id);
len += sprintf(page + len, "OEM table id : %s\n", buf);
snprintf(buf, 16, "%x", asus->dsdt_info->oem_revision);
len += sprintf(page + len, "OEM revision : 0x%s\n", buf);
snprintf(buf, 5, "%s", asus->dsdt_info->asl_compiler_id);
len += sprintf(page + len, "ASL comp vendor id : %s\n", buf);
snprintf(buf, 16, "%x", asus->dsdt_info->asl_compiler_revision);
len += sprintf(page + len, "ASL comp revision : 0x%s\n", buf);
}
return len;
}
static int parse_arg(const char *buf, unsigned long count, int *val)
{
if (!count)
return 0;
if (count > 31)
return -EINVAL;
if (sscanf(buf, "%i", val) != 1)
return -EINVAL;
return count;
}
static ssize_t sysfs_acpi_set(struct asus_laptop *asus,
const char *buf, size_t count,
const char *method)
{
int rv, value;
int out = 0;
rv = parse_arg(buf, count, &value);
if (rv > 0)
out = value ? 1 : 0;
if (write_acpi_int(asus->handle, method, value))
return -ENODEV;
return rv;
}
static ssize_t show_ledd(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct asus_laptop *asus = dev_get_drvdata(dev);
return sprintf(buf, "0x%08x\n", asus->ledd_status);
}
static ssize_t store_ledd(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct asus_laptop *asus = dev_get_drvdata(dev);
int rv, value;
rv = parse_arg(buf, count, &value);
if (rv > 0) {
if (write_acpi_int(asus->handle, METHOD_LEDD, value)) {
pr_warn("LED display write failed\n");
return -ENODEV;
}
asus->ledd_status = (u32) value;
}
return rv;
}
static int asus_wireless_status(struct asus_laptop *asus, int mask)
{
unsigned long long status;
acpi_status rv = AE_OK;
if (!asus->have_rsts)
return (asus->wireless_status & mask) ? 1 : 0;
rv = acpi_evaluate_integer(asus->handle, METHOD_WL_STATUS,
NULL, &status);
if (ACPI_FAILURE(rv)) {
pr_warn("Error reading Wireless status\n");
return -EINVAL;
}
return !!(status & mask);
}
static int asus_wlan_set(struct asus_laptop *asus, int status)
{
if (write_acpi_int(asus->handle, METHOD_WLAN, !!status)) {
pr_warn("Error setting wlan status to %d\n", status);
return -EIO;
}
return 0;
}
static ssize_t show_wlan(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct asus_laptop *asus = dev_get_drvdata(dev);
return sprintf(buf, "%d\n", asus_wireless_status(asus, WL_RSTS));
}
static ssize_t store_wlan(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct asus_laptop *asus = dev_get_drvdata(dev);
return sysfs_acpi_set(asus, buf, count, METHOD_WLAN);
}
static int asus_bluetooth_set(struct asus_laptop *asus, int status)
{
if (write_acpi_int(asus->handle, METHOD_BLUETOOTH, !!status)) {
pr_warn("Error setting bluetooth status to %d\n", status);
return -EIO;
}
return 0;
}
static ssize_t show_bluetooth(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct asus_laptop *asus = dev_get_drvdata(dev);
return sprintf(buf, "%d\n", asus_wireless_status(asus, BT_RSTS));
}
static ssize_t store_bluetooth(struct device *dev,
struct device_attribute *attr, const char *buf,
size_t count)
{
struct asus_laptop *asus = dev_get_drvdata(dev);
return sysfs_acpi_set(asus, buf, count, METHOD_BLUETOOTH);
}
static int asus_wimax_set(struct asus_laptop *asus, int status)
{
if (write_acpi_int(asus->handle, METHOD_WIMAX, !!status)) {
pr_warn("Error setting wimax status to %d\n", status);
return -EIO;
}
return 0;
}
static ssize_t show_wimax(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct asus_laptop *asus = dev_get_drvdata(dev);
return sprintf(buf, "%d\n", asus_wireless_status(asus, WM_RSTS));
}
static ssize_t store_wimax(struct device *dev,
struct device_attribute *attr, const char *buf,
size_t count)
{
struct asus_laptop *asus = dev_get_drvdata(dev);
return sysfs_acpi_set(asus, buf, count, METHOD_WIMAX);
}
static int asus_wwan_set(struct asus_laptop *asus, int status)
{
if (write_acpi_int(asus->handle, METHOD_WWAN, !!status)) {
pr_warn("Error setting wwan status to %d\n", status);
return -EIO;
}
return 0;
}
static ssize_t show_wwan(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct asus_laptop *asus = dev_get_drvdata(dev);
return sprintf(buf, "%d\n", asus_wireless_status(asus, WW_RSTS));
}
static ssize_t store_wwan(struct device *dev,
struct device_attribute *attr, const char *buf,
size_t count)
{
struct asus_laptop *asus = dev_get_drvdata(dev);
return sysfs_acpi_set(asus, buf, count, METHOD_WWAN);
}
static void asus_set_display(struct asus_laptop *asus, int value)
{
if (write_acpi_int(asus->handle, METHOD_SWITCH_DISPLAY, value))
pr_warn("Error setting display\n");
return;
}
static ssize_t store_disp(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct asus_laptop *asus = dev_get_drvdata(dev);
int rv, value;
rv = parse_arg(buf, count, &value);
if (rv > 0)
asus_set_display(asus, value);
return rv;
}
static void asus_als_switch(struct asus_laptop *asus, int value)
{
int ret;
if (asus->is_pega_lucid) {
ret = asus_pega_lucid_set(asus, PEGA_ALS, value);
if (!ret)
ret = asus_pega_lucid_set(asus, PEGA_ALS_POWER, value);
} else {
ret = write_acpi_int(asus->handle, METHOD_ALS_CONTROL, value);
}
if (ret)
pr_warning("Error setting light sensor switch\n");
asus->light_switch = value;
}
static ssize_t show_lssw(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct asus_laptop *asus = dev_get_drvdata(dev);
return sprintf(buf, "%d\n", asus->light_switch);
}
static ssize_t store_lssw(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct asus_laptop *asus = dev_get_drvdata(dev);
int rv, value;
rv = parse_arg(buf, count, &value);
if (rv > 0)
asus_als_switch(asus, value ? 1 : 0);
return rv;
}
static void asus_als_level(struct asus_laptop *asus, int value)
{
if (write_acpi_int(asus->handle, METHOD_ALS_LEVEL, value))
pr_warn("Error setting light sensor level\n");
asus->light_level = value;
}
static ssize_t show_lslvl(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct asus_laptop *asus = dev_get_drvdata(dev);
return sprintf(buf, "%d\n", asus->light_level);
}
static ssize_t store_lslvl(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct asus_laptop *asus = dev_get_drvdata(dev);
int rv, value;
rv = parse_arg(buf, count, &value);
if (rv > 0) {
value = (0 < value) ? ((15 < value) ? 15 : value) : 0;
asus_als_level(asus, value);
}
return rv;
}
static int pega_int_read(struct asus_laptop *asus, int arg, int *result)
{
struct acpi_buffer buffer = { ACPI_ALLOCATE_BUFFER, NULL };
int err = write_acpi_int_ret(asus->handle, METHOD_PEGA_READ, arg,
&buffer);
if (!err) {
union acpi_object *obj = buffer.pointer;
if (obj && obj->type == ACPI_TYPE_INTEGER)
*result = obj->integer.value;
else
err = -EIO;
}
return err;
}
static ssize_t show_lsvalue(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct asus_laptop *asus = dev_get_drvdata(dev);
int err, hi, lo;
err = pega_int_read(asus, PEGA_READ_ALS_H, &hi);
if (!err)
err = pega_int_read(asus, PEGA_READ_ALS_L, &lo);
if (!err)
return sprintf(buf, "%d\n", 10 * hi + lo);
return err;
}
static int asus_gps_status(struct asus_laptop *asus)
{
unsigned long long status;
acpi_status rv = AE_OK;
rv = acpi_evaluate_integer(asus->handle, METHOD_GPS_STATUS,
NULL, &status);
if (ACPI_FAILURE(rv)) {
pr_warn("Error reading GPS status\n");
return -ENODEV;
}
return !!status;
}
static int asus_gps_switch(struct asus_laptop *asus, int status)
{
const char *meth = status ? METHOD_GPS_ON : METHOD_GPS_OFF;
if (write_acpi_int(asus->handle, meth, 0x02))
return -ENODEV;
return 0;
}
static ssize_t show_gps(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct asus_laptop *asus = dev_get_drvdata(dev);
return sprintf(buf, "%d\n", asus_gps_status(asus));
}
static ssize_t store_gps(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct asus_laptop *asus = dev_get_drvdata(dev);
int rv, value;
int ret;
rv = parse_arg(buf, count, &value);
if (rv <= 0)
return -EINVAL;
ret = asus_gps_switch(asus, !!value);
if (ret)
return ret;
rfkill_set_sw_state(asus->gps_rfkill, !value);
return rv;
}
static int asus_gps_rfkill_set(void *data, bool blocked)
{
struct asus_laptop *asus = data;
return asus_gps_switch(asus, !blocked);
}
static void asus_rfkill_exit(struct asus_laptop *asus)
{
if (asus->gps_rfkill) {
rfkill_unregister(asus->gps_rfkill);
rfkill_destroy(asus->gps_rfkill);
asus->gps_rfkill = NULL;
}
}
static int asus_rfkill_init(struct asus_laptop *asus)
{
int result;
if (acpi_check_handle(asus->handle, METHOD_GPS_ON, NULL) ||
acpi_check_handle(asus->handle, METHOD_GPS_OFF, NULL) ||
acpi_check_handle(asus->handle, METHOD_GPS_STATUS, NULL))
return 0;
asus->gps_rfkill = rfkill_alloc("asus-gps", &asus->platform_device->dev,
RFKILL_TYPE_GPS,
&asus_gps_rfkill_ops, asus);
if (!asus->gps_rfkill)
return -EINVAL;
result = rfkill_register(asus->gps_rfkill);
if (result) {
rfkill_destroy(asus->gps_rfkill);
asus->gps_rfkill = NULL;
}
return result;
}
static int pega_rfkill_set(void *data, bool blocked)
{
struct asus_pega_rfkill *pega_rfk = data;
int ret = asus_pega_lucid_set(pega_rfk->asus, pega_rfk->control_id, !blocked);
pr_warn("Setting rfkill %d, to %d; returned %d\n", pega_rfk->control_id, !blocked, ret);
return ret;
}
static void pega_rfkill_terminate(struct asus_pega_rfkill *pega_rfk)
{
pr_warn("Terminating %d\n", pega_rfk->control_id);
if (pega_rfk->rfkill) {
rfkill_unregister(pega_rfk->rfkill);
rfkill_destroy(pega_rfk->rfkill);
pega_rfk->rfkill = NULL;
}
}
static void pega_rfkill_exit(struct asus_laptop *asus)
{
pega_rfkill_terminate(&asus->wwanrfk);
pega_rfkill_terminate(&asus->btrfk);
pega_rfkill_terminate(&asus->wlanrfk);
}
static int pega_rfkill_setup(struct asus_laptop *asus, struct asus_pega_rfkill *pega_rfk,
const char *name, int controlid, int rfkill_type)
{
int result;
pr_warn("Setting up rfk %s, control %d, type %d\n", name, controlid, rfkill_type);
pega_rfk->control_id = controlid;
pega_rfk->asus = asus;
pega_rfk->rfkill = rfkill_alloc(name, &asus->platform_device->dev,
rfkill_type, &pega_rfkill_ops, pega_rfk);
if (!pega_rfk->rfkill)
return -EINVAL;
result = rfkill_register(pega_rfk->rfkill);
if (result) {
rfkill_destroy(pega_rfk->rfkill);
pega_rfk->rfkill = NULL;
}
return result;
}
static int pega_rfkill_init(struct asus_laptop *asus)
{
int ret = 0;
if(!asus->is_pega_lucid)
return -ENODEV;
ret = pega_rfkill_setup(asus, &asus->wlanrfk, "pega-wlan", PEGA_WLAN, RFKILL_TYPE_WLAN);
if(ret)
return ret;
ret = pega_rfkill_setup(asus, &asus->btrfk, "pega-bt", PEGA_BLUETOOTH, RFKILL_TYPE_BLUETOOTH);
if(ret)
goto err_btrfk;
ret = pega_rfkill_setup(asus, &asus->wwanrfk, "pega-wwan", PEGA_WWAN, RFKILL_TYPE_WWAN);
if(ret)
goto err_wwanrfk;
pr_warn("Pega rfkill init succeeded\n");
return 0;
err_wwanrfk:
pega_rfkill_terminate(&asus->btrfk);
err_btrfk:
pega_rfkill_terminate(&asus->wlanrfk);
return ret;
}
static void asus_input_notify(struct asus_laptop *asus, int event)
{
if (asus->inputdev)
sparse_keymap_report_event(asus->inputdev, event, 1, true);
}
static int asus_input_init(struct asus_laptop *asus)
{
struct input_dev *input;
int error;
input = input_allocate_device();
if (!input) {
pr_info("Unable to allocate input device\n");
return -ENOMEM;
}
input->name = "Asus Laptop extra buttons";
input->phys = ASUS_LAPTOP_FILE "/input0";
input->id.bustype = BUS_HOST;
input->dev.parent = &asus->platform_device->dev;
error = sparse_keymap_setup(input, asus_keymap, NULL);
if (error) {
pr_err("Unable to setup input device keymap\n");
goto err_free_dev;
}
error = input_register_device(input);
if (error) {
pr_info("Unable to register input device\n");
goto err_free_keymap;
}
asus->inputdev = input;
return 0;
err_free_keymap:
sparse_keymap_free(input);
err_free_dev:
input_free_device(input);
return error;
}
static void asus_input_exit(struct asus_laptop *asus)
{
if (asus->inputdev) {
sparse_keymap_free(asus->inputdev);
input_unregister_device(asus->inputdev);
}
asus->inputdev = NULL;
}
static void asus_acpi_notify(struct acpi_device *device, u32 event)
{
struct asus_laptop *asus = acpi_driver_data(device);
u16 count;
count = asus->event_count[event % 128]++;
acpi_bus_generate_proc_event(asus->device, event, count);
acpi_bus_generate_netlink_event(asus->device->pnp.device_class,
dev_name(&asus->device->dev), event,
count);
if (event >= ATKD_BR_MIN && event <= ATKD_BR_MAX) {
if (asus->backlight_device != NULL) {
asus_backlight_notify(asus);
}
return ;
}
if (asus->pega_accel_poll && event == 0xEA) {
kobject_uevent(&asus->pega_accel_poll->input->dev.kobj,
KOBJ_CHANGE);
return ;
}
asus_input_notify(asus, event);
}
static umode_t asus_sysfs_is_visible(struct kobject *kobj,
struct attribute *attr,
int idx)
{
struct device *dev = container_of(kobj, struct device, kobj);
struct platform_device *pdev = to_platform_device(dev);
struct asus_laptop *asus = platform_get_drvdata(pdev);
acpi_handle handle = asus->handle;
bool supported;
if (asus->is_pega_lucid) {
if (attr == &dev_attr_ls_switch.attr)
supported = true;
else if (attr == &dev_attr_ls_level.attr)
supported = false;
else
goto normal;
return supported;
}
normal:
if (attr == &dev_attr_wlan.attr) {
supported = !acpi_check_handle(handle, METHOD_WLAN, NULL);
} else if (attr == &dev_attr_bluetooth.attr) {
supported = !acpi_check_handle(handle, METHOD_BLUETOOTH, NULL);
} else if (attr == &dev_attr_display.attr) {
supported = !acpi_check_handle(handle, METHOD_SWITCH_DISPLAY, NULL);
} else if (attr == &dev_attr_wimax.attr) {
supported =
!acpi_check_handle(asus->handle, METHOD_WIMAX, NULL);
} else if (attr == &dev_attr_wwan.attr) {
supported = !acpi_check_handle(asus->handle, METHOD_WWAN, NULL);
} else if (attr == &dev_attr_ledd.attr) {
supported = !acpi_check_handle(handle, METHOD_LEDD, NULL);
} else if (attr == &dev_attr_ls_switch.attr ||
attr == &dev_attr_ls_level.attr) {
supported = !acpi_check_handle(handle, METHOD_ALS_CONTROL, NULL) &&
!acpi_check_handle(handle, METHOD_ALS_LEVEL, NULL);
} else if (attr == &dev_attr_ls_value.attr) {
supported = asus->is_pega_lucid;
} else if (attr == &dev_attr_gps.attr) {
supported = !acpi_check_handle(handle, METHOD_GPS_ON, NULL) &&
!acpi_check_handle(handle, METHOD_GPS_OFF, NULL) &&
!acpi_check_handle(handle, METHOD_GPS_STATUS, NULL);
} else {
supported = true;
}
return supported ? attr->mode : 0;
}
static int asus_platform_init(struct asus_laptop *asus)
{
int result;
asus->platform_device = platform_device_alloc(ASUS_LAPTOP_FILE, -1);
if (!asus->platform_device)
return -ENOMEM;
platform_set_drvdata(asus->platform_device, asus);
result = platform_device_add(asus->platform_device);
if (result)
goto fail_platform_device;
result = sysfs_create_group(&asus->platform_device->dev.kobj,
&asus_attr_group);
if (result)
goto fail_sysfs;
return 0;
fail_sysfs:
platform_device_del(asus->platform_device);
fail_platform_device:
platform_device_put(asus->platform_device);
return result;
}
static void asus_platform_exit(struct asus_laptop *asus)
{
sysfs_remove_group(&asus->platform_device->dev.kobj, &asus_attr_group);
platform_device_unregister(asus->platform_device);
}
static int asus_laptop_get_info(struct asus_laptop *asus)
{
struct acpi_buffer buffer = { ACPI_ALLOCATE_BUFFER, NULL };
union acpi_object *model = NULL;
unsigned long long bsts_result, hwrs_result;
char *string = NULL;
acpi_status status;
status = acpi_get_table(ACPI_SIG_DSDT, 1, &asus->dsdt_info);
if (ACPI_FAILURE(status))
pr_warn("Couldn't get the DSDT table header\n");
if (write_acpi_int_ret(asus->handle, "INIT", 0, &buffer)) {
pr_err("Hotkey initialization failed\n");
return -ENODEV;
}
status =
acpi_evaluate_integer(asus->handle, "BSTS", NULL, &bsts_result);
if (ACPI_FAILURE(status))
pr_warn("Error calling BSTS\n");
else if (bsts_result)
pr_notice("BSTS called, 0x%02x returned\n",
(uint) bsts_result);
if (write_acpi_int(asus->handle, "CWAP", wapf))
pr_err("Error calling CWAP(%d)\n", wapf);
if (buffer.pointer) {
model = buffer.pointer;
switch (model->type) {
case ACPI_TYPE_STRING:
string = model->string.pointer;
break;
case ACPI_TYPE_BUFFER:
string = model->buffer.pointer;
break;
default:
string = "";
break;
}
}
asus->name = kstrdup(string, GFP_KERNEL);
if (!asus->name) {
kfree(buffer.pointer);
return -ENOMEM;
}
if (*string)
pr_notice(" %s model detected\n", string);
status =
acpi_evaluate_integer(asus->handle, "HRWS", NULL, &hwrs_result);
if (!ACPI_FAILURE(status))
pr_notice(" HRWS returned %x", (int)hwrs_result);
if (!acpi_check_handle(asus->handle, METHOD_WL_STATUS, NULL))
asus->have_rsts = true;
kfree(model);
return AE_OK;
}
static int __devinit asus_acpi_init(struct asus_laptop *asus)
{
int result = 0;
result = acpi_bus_get_status(asus->device);
if (result)
return result;
if (!asus->device->status.present) {
pr_err("Hotkey device not present, aborting\n");
return -ENODEV;
}
result = asus_laptop_get_info(asus);
if (result)
return result;
if (bluetooth_status >= 0)
asus_bluetooth_set(asus, !!bluetooth_status);
if (wlan_status >= 0)
asus_wlan_set(asus, !!wlan_status);
if (wimax_status >= 0)
asus_wimax_set(asus, !!wimax_status);
if (wwan_status >= 0)
asus_wwan_set(asus, !!wwan_status);
if (!acpi_check_handle(asus->handle, METHOD_KBD_LIGHT_SET, NULL))
asus_kled_set(asus, 1);
asus->ledd_status = 0xFFF;
asus->light_switch = !!als_status;
asus->light_level = 5;
if (asus->is_pega_lucid) {
asus_als_switch(asus, asus->light_switch);
} else if (!acpi_check_handle(asus->handle, METHOD_ALS_CONTROL, NULL) &&
!acpi_check_handle(asus->handle, METHOD_ALS_LEVEL, NULL)) {
asus_als_switch(asus, asus->light_switch);
asus_als_level(asus, asus->light_level);
}
return result;
}
static void __devinit asus_dmi_check(void)
{
const char *model;
model = dmi_get_system_info(DMI_PRODUCT_NAME);
if (!model)
return;
if (strncmp(model, "L1400B", 6) == 0) {
wlan_status = -1;
}
}
static int __devinit asus_acpi_add(struct acpi_device *device)
{
struct asus_laptop *asus;
int result;
pr_notice("Asus Laptop Support version %s\n",
ASUS_LAPTOP_VERSION);
asus = kzalloc(sizeof(struct asus_laptop), GFP_KERNEL);
if (!asus)
return -ENOMEM;
asus->handle = device->handle;
strcpy(acpi_device_name(device), ASUS_LAPTOP_DEVICE_NAME);
strcpy(acpi_device_class(device), ASUS_LAPTOP_CLASS);
device->driver_data = asus;
asus->device = device;
asus_dmi_check();
result = asus_acpi_init(asus);
if (result)
goto fail_platform;
asus->is_pega_lucid = asus_check_pega_lucid(asus);
result = asus_platform_init(asus);
if (result)
goto fail_platform;
if (!acpi_video_backlight_support()) {
result = asus_backlight_init(asus);
if (result)
goto fail_backlight;
} else
pr_info("Backlight controlled by ACPI video driver\n");
result = asus_input_init(asus);
if (result)
goto fail_input;
result = asus_led_init(asus);
if (result)
goto fail_led;
result = asus_rfkill_init(asus);
if (result)
goto fail_rfkill;
result = pega_accel_init(asus);
if (result && result != -ENODEV)
goto fail_pega_accel;
result = pega_rfkill_init(asus);
if (result && result != -ENODEV)
goto fail_pega_rfkill;
asus_device_present = true;
return 0;
fail_pega_rfkill:
pega_accel_exit(asus);
fail_pega_accel:
asus_rfkill_exit(asus);
fail_rfkill:
asus_led_exit(asus);
fail_led:
asus_input_exit(asus);
fail_input:
asus_backlight_exit(asus);
fail_backlight:
asus_platform_exit(asus);
fail_platform:
kfree(asus->name);
kfree(asus);
return result;
}
static int asus_acpi_remove(struct acpi_device *device, int type)
{
struct asus_laptop *asus = acpi_driver_data(device);
asus_backlight_exit(asus);
asus_rfkill_exit(asus);
asus_led_exit(asus);
asus_input_exit(asus);
pega_accel_exit(asus);
pega_rfkill_exit(asus);
asus_platform_exit(asus);
kfree(asus->name);
kfree(asus);
return 0;
}
static int __init asus_laptop_init(void)
{
int result;
result = platform_driver_register(&platform_driver);
if (result < 0)
return result;
result = acpi_bus_register_driver(&asus_acpi_driver);
if (result < 0)
goto fail_acpi_driver;
if (!asus_device_present) {
result = -ENODEV;
goto fail_no_device;
}
return 0;
fail_no_device:
acpi_bus_unregister_driver(&asus_acpi_driver);
fail_acpi_driver:
platform_driver_unregister(&platform_driver);
return result;
}
static void __exit asus_laptop_exit(void)
{
acpi_bus_unregister_driver(&asus_acpi_driver);
platform_driver_unregister(&platform_driver);
}
