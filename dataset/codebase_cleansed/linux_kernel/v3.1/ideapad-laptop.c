static int read_method_int(acpi_handle handle, const char *method, int *val)
{
acpi_status status;
unsigned long long result;
status = acpi_evaluate_integer(handle, (char *)method, NULL, &result);
if (ACPI_FAILURE(status)) {
*val = -1;
return -1;
} else {
*val = result;
return 0;
}
}
static int method_vpcr(acpi_handle handle, int cmd, int *ret)
{
acpi_status status;
unsigned long long result;
struct acpi_object_list params;
union acpi_object in_obj;
params.count = 1;
params.pointer = &in_obj;
in_obj.type = ACPI_TYPE_INTEGER;
in_obj.integer.value = cmd;
status = acpi_evaluate_integer(handle, "VPCR", &params, &result);
if (ACPI_FAILURE(status)) {
*ret = -1;
return -1;
} else {
*ret = result;
return 0;
}
}
static int method_vpcw(acpi_handle handle, int cmd, int data)
{
struct acpi_object_list params;
union acpi_object in_obj[2];
acpi_status status;
params.count = 2;
params.pointer = in_obj;
in_obj[0].type = ACPI_TYPE_INTEGER;
in_obj[0].integer.value = cmd;
in_obj[1].type = ACPI_TYPE_INTEGER;
in_obj[1].integer.value = data;
status = acpi_evaluate_object(handle, "VPCW", &params, NULL);
if (status != AE_OK)
return -1;
return 0;
}
static int read_ec_data(acpi_handle handle, int cmd, unsigned long *data)
{
int val;
unsigned long int end_jiffies;
if (method_vpcw(handle, 1, cmd))
return -1;
for (end_jiffies = jiffies+(HZ)*IDEAPAD_EC_TIMEOUT/1000+1;
time_before(jiffies, end_jiffies);) {
schedule();
if (method_vpcr(handle, 1, &val))
return -1;
if (val == 0) {
if (method_vpcr(handle, 0, &val))
return -1;
*data = val;
return 0;
}
}
pr_err("timeout in read_ec_cmd\n");
return -1;
}
static int write_ec_cmd(acpi_handle handle, int cmd, unsigned long data)
{
int val;
unsigned long int end_jiffies;
if (method_vpcw(handle, 0, data))
return -1;
if (method_vpcw(handle, 1, cmd))
return -1;
for (end_jiffies = jiffies+(HZ)*IDEAPAD_EC_TIMEOUT/1000+1;
time_before(jiffies, end_jiffies);) {
schedule();
if (method_vpcr(handle, 1, &val))
return -1;
if (val == 0)
return 0;
}
pr_err("timeout in write_ec_cmd\n");
return -1;
}
static ssize_t show_ideapad_cam(struct device *dev,
struct device_attribute *attr,
char *buf)
{
unsigned long result;
if (read_ec_data(ideapad_handle, 0x1D, &result))
return sprintf(buf, "-1\n");
return sprintf(buf, "%lu\n", result);
}
static ssize_t store_ideapad_cam(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
int ret, state;
if (!count)
return 0;
if (sscanf(buf, "%i", &state) != 1)
return -EINVAL;
ret = write_ec_cmd(ideapad_handle, 0x1E, state);
if (ret < 0)
return ret;
return count;
}
static ssize_t show_ideapad_cfg(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct ideapad_private *priv = dev_get_drvdata(dev);
return sprintf(buf, "0x%.8lX\n", priv->cfg);
}
static mode_t ideapad_is_visible(struct kobject *kobj,
struct attribute *attr,
int idx)
{
struct device *dev = container_of(kobj, struct device, kobj);
struct ideapad_private *priv = dev_get_drvdata(dev);
bool supported;
if (attr == &dev_attr_camera_power.attr)
supported = test_bit(CFG_CAMERA_BIT, &(priv->cfg));
else
supported = true;
return supported ? attr->mode : 0;
}
static int ideapad_rfk_set(void *data, bool blocked)
{
unsigned long opcode = (unsigned long)data;
return write_ec_cmd(ideapad_handle, opcode, !blocked);
}
static void ideapad_sync_rfk_state(struct acpi_device *adevice)
{
struct ideapad_private *priv = dev_get_drvdata(&adevice->dev);
unsigned long hw_blocked;
int i;
if (read_ec_data(ideapad_handle, 0x23, &hw_blocked))
return;
hw_blocked = !hw_blocked;
for (i = 0; i < IDEAPAD_RFKILL_DEV_NUM; i++)
if (priv->rfk[i])
rfkill_set_hw_state(priv->rfk[i], hw_blocked);
}
static int __devinit ideapad_register_rfkill(struct acpi_device *adevice,
int dev)
{
struct ideapad_private *priv = dev_get_drvdata(&adevice->dev);
int ret;
unsigned long sw_blocked;
if (no_bt_rfkill &&
(ideapad_rfk_data[dev].type == RFKILL_TYPE_BLUETOOTH)) {
write_ec_cmd(ideapad_handle,
ideapad_rfk_data[dev].opcode, 1);
return 0;
}
priv->rfk[dev] = rfkill_alloc(ideapad_rfk_data[dev].name, &adevice->dev,
ideapad_rfk_data[dev].type, &ideapad_rfk_ops,
(void *)(long)dev);
if (!priv->rfk[dev])
return -ENOMEM;
if (read_ec_data(ideapad_handle, ideapad_rfk_data[dev].opcode-1,
&sw_blocked)) {
rfkill_init_sw_state(priv->rfk[dev], 0);
} else {
sw_blocked = !sw_blocked;
rfkill_init_sw_state(priv->rfk[dev], sw_blocked);
}
ret = rfkill_register(priv->rfk[dev]);
if (ret) {
rfkill_destroy(priv->rfk[dev]);
return ret;
}
return 0;
}
static void ideapad_unregister_rfkill(struct acpi_device *adevice, int dev)
{
struct ideapad_private *priv = dev_get_drvdata(&adevice->dev);
if (!priv->rfk[dev])
return;
rfkill_unregister(priv->rfk[dev]);
rfkill_destroy(priv->rfk[dev]);
}
static int __devinit ideapad_platform_init(struct ideapad_private *priv)
{
int result;
priv->platform_device = platform_device_alloc("ideapad", -1);
if (!priv->platform_device)
return -ENOMEM;
platform_set_drvdata(priv->platform_device, priv);
result = platform_device_add(priv->platform_device);
if (result)
goto fail_platform_device;
result = sysfs_create_group(&priv->platform_device->dev.kobj,
&ideapad_attribute_group);
if (result)
goto fail_sysfs;
return 0;
fail_sysfs:
platform_device_del(priv->platform_device);
fail_platform_device:
platform_device_put(priv->platform_device);
return result;
}
static void ideapad_platform_exit(struct ideapad_private *priv)
{
sysfs_remove_group(&priv->platform_device->dev.kobj,
&ideapad_attribute_group);
platform_device_unregister(priv->platform_device);
}
static int __devinit ideapad_input_init(struct ideapad_private *priv)
{
struct input_dev *inputdev;
int error;
inputdev = input_allocate_device();
if (!inputdev) {
pr_info("Unable to allocate input device\n");
return -ENOMEM;
}
inputdev->name = "Ideapad extra buttons";
inputdev->phys = "ideapad/input0";
inputdev->id.bustype = BUS_HOST;
inputdev->dev.parent = &priv->platform_device->dev;
error = sparse_keymap_setup(inputdev, ideapad_keymap, NULL);
if (error) {
pr_err("Unable to setup input device keymap\n");
goto err_free_dev;
}
error = input_register_device(inputdev);
if (error) {
pr_err("Unable to register input device\n");
goto err_free_keymap;
}
priv->inputdev = inputdev;
return 0;
err_free_keymap:
sparse_keymap_free(inputdev);
err_free_dev:
input_free_device(inputdev);
return error;
}
static void ideapad_input_exit(struct ideapad_private *priv)
{
sparse_keymap_free(priv->inputdev);
input_unregister_device(priv->inputdev);
priv->inputdev = NULL;
}
static void ideapad_input_report(struct ideapad_private *priv,
unsigned long scancode)
{
sparse_keymap_report_event(priv->inputdev, scancode, 1, true);
}
static int ideapad_backlight_get_brightness(struct backlight_device *blightdev)
{
unsigned long now;
if (read_ec_data(ideapad_handle, 0x12, &now))
return -EIO;
return now;
}
static int ideapad_backlight_update_status(struct backlight_device *blightdev)
{
if (write_ec_cmd(ideapad_handle, 0x13, blightdev->props.brightness))
return -EIO;
if (write_ec_cmd(ideapad_handle, 0x33,
blightdev->props.power == FB_BLANK_POWERDOWN ? 0 : 1))
return -EIO;
return 0;
}
static int ideapad_backlight_init(struct ideapad_private *priv)
{
struct backlight_device *blightdev;
struct backlight_properties props;
unsigned long max, now, power;
if (read_ec_data(ideapad_handle, 0x11, &max))
return -EIO;
if (read_ec_data(ideapad_handle, 0x12, &now))
return -EIO;
if (read_ec_data(ideapad_handle, 0x18, &power))
return -EIO;
memset(&props, 0, sizeof(struct backlight_properties));
props.max_brightness = max;
props.type = BACKLIGHT_PLATFORM;
blightdev = backlight_device_register("ideapad",
&priv->platform_device->dev,
priv,
&ideapad_backlight_ops,
&props);
if (IS_ERR(blightdev)) {
pr_err("Could not register backlight device\n");
return PTR_ERR(blightdev);
}
priv->blightdev = blightdev;
blightdev->props.brightness = now;
blightdev->props.power = power ? FB_BLANK_UNBLANK : FB_BLANK_POWERDOWN;
backlight_update_status(blightdev);
return 0;
}
static void ideapad_backlight_exit(struct ideapad_private *priv)
{
if (priv->blightdev)
backlight_device_unregister(priv->blightdev);
priv->blightdev = NULL;
}
static void ideapad_backlight_notify_power(struct ideapad_private *priv)
{
unsigned long power;
struct backlight_device *blightdev = priv->blightdev;
if (read_ec_data(ideapad_handle, 0x18, &power))
return;
blightdev->props.power = power ? FB_BLANK_UNBLANK : FB_BLANK_POWERDOWN;
}
static void ideapad_backlight_notify_brightness(struct ideapad_private *priv)
{
unsigned long now;
if (priv->blightdev == NULL) {
read_ec_data(ideapad_handle, 0x12, &now);
return;
}
backlight_force_update(priv->blightdev, BACKLIGHT_UPDATE_HOTKEY);
}
static int __devinit ideapad_acpi_add(struct acpi_device *adevice)
{
int ret, i;
unsigned long cfg;
struct ideapad_private *priv;
if (read_method_int(adevice->handle, "_CFG", (int *)&cfg))
return -ENODEV;
priv = kzalloc(sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
dev_set_drvdata(&adevice->dev, priv);
ideapad_handle = adevice->handle;
priv->cfg = cfg;
ret = ideapad_platform_init(priv);
if (ret)
goto platform_failed;
ret = ideapad_input_init(priv);
if (ret)
goto input_failed;
for (i = 0; i < IDEAPAD_RFKILL_DEV_NUM; i++) {
if (test_bit(ideapad_rfk_data[i].cfgbit, &cfg))
ideapad_register_rfkill(adevice, i);
else
priv->rfk[i] = NULL;
}
ideapad_sync_rfk_state(adevice);
if (!acpi_video_backlight_support()) {
ret = ideapad_backlight_init(priv);
if (ret && ret != -ENODEV)
goto backlight_failed;
}
return 0;
backlight_failed:
for (i = 0; i < IDEAPAD_RFKILL_DEV_NUM; i++)
ideapad_unregister_rfkill(adevice, i);
ideapad_input_exit(priv);
input_failed:
ideapad_platform_exit(priv);
platform_failed:
kfree(priv);
return ret;
}
static int __devexit ideapad_acpi_remove(struct acpi_device *adevice, int type)
{
struct ideapad_private *priv = dev_get_drvdata(&adevice->dev);
int i;
ideapad_backlight_exit(priv);
for (i = 0; i < IDEAPAD_RFKILL_DEV_NUM; i++)
ideapad_unregister_rfkill(adevice, i);
ideapad_input_exit(priv);
ideapad_platform_exit(priv);
dev_set_drvdata(&adevice->dev, NULL);
kfree(priv);
return 0;
}
static void ideapad_acpi_notify(struct acpi_device *adevice, u32 event)
{
struct ideapad_private *priv = dev_get_drvdata(&adevice->dev);
acpi_handle handle = adevice->handle;
unsigned long vpc1, vpc2, vpc_bit;
if (read_ec_data(handle, 0x10, &vpc1))
return;
if (read_ec_data(handle, 0x1A, &vpc2))
return;
vpc1 = (vpc2 << 8) | vpc1;
for (vpc_bit = 0; vpc_bit < 16; vpc_bit++) {
if (test_bit(vpc_bit, &vpc1)) {
switch (vpc_bit) {
case 9:
ideapad_sync_rfk_state(adevice);
break;
case 4:
ideapad_backlight_notify_brightness(priv);
break;
case 2:
ideapad_backlight_notify_power(priv);
break;
default:
ideapad_input_report(priv, vpc_bit);
}
}
}
}
static int __init ideapad_acpi_module_init(void)
{
return acpi_bus_register_driver(&ideapad_acpi_driver);
}
static void __exit ideapad_acpi_module_exit(void)
{
acpi_bus_unregister_driver(&ideapad_acpi_driver);
}
