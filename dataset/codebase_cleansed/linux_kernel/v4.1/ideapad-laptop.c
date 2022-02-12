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
static int debugfs_status_show(struct seq_file *s, void *data)
{
struct ideapad_private *priv = s->private;
unsigned long value;
if (!priv)
return -EINVAL;
if (!read_ec_data(priv->adev->handle, VPCCMD_R_BL_MAX, &value))
seq_printf(s, "Backlight max:\t%lu\n", value);
if (!read_ec_data(priv->adev->handle, VPCCMD_R_BL, &value))
seq_printf(s, "Backlight now:\t%lu\n", value);
if (!read_ec_data(priv->adev->handle, VPCCMD_R_BL_POWER, &value))
seq_printf(s, "BL power value:\t%s\n", value ? "On" : "Off");
seq_printf(s, "=====================\n");
if (!read_ec_data(priv->adev->handle, VPCCMD_R_RF, &value))
seq_printf(s, "Radio status:\t%s(%lu)\n",
value ? "On" : "Off", value);
if (!read_ec_data(priv->adev->handle, VPCCMD_R_WIFI, &value))
seq_printf(s, "Wifi status:\t%s(%lu)\n",
value ? "On" : "Off", value);
if (!read_ec_data(priv->adev->handle, VPCCMD_R_BT, &value))
seq_printf(s, "BT status:\t%s(%lu)\n",
value ? "On" : "Off", value);
if (!read_ec_data(priv->adev->handle, VPCCMD_R_3G, &value))
seq_printf(s, "3G status:\t%s(%lu)\n",
value ? "On" : "Off", value);
seq_printf(s, "=====================\n");
if (!read_ec_data(priv->adev->handle, VPCCMD_R_TOUCHPAD, &value))
seq_printf(s, "Touchpad status:%s(%lu)\n",
value ? "On" : "Off", value);
if (!read_ec_data(priv->adev->handle, VPCCMD_R_CAMERA, &value))
seq_printf(s, "Camera status:\t%s(%lu)\n",
value ? "On" : "Off", value);
return 0;
}
static int debugfs_status_open(struct inode *inode, struct file *file)
{
return single_open(file, debugfs_status_show, inode->i_private);
}
static int debugfs_cfg_show(struct seq_file *s, void *data)
{
struct ideapad_private *priv = s->private;
if (!priv) {
seq_printf(s, "cfg: N/A\n");
} else {
seq_printf(s, "cfg: 0x%.8lX\n\nCapability: ",
priv->cfg);
if (test_bit(CFG_BT_BIT, &priv->cfg))
seq_printf(s, "Bluetooth ");
if (test_bit(CFG_3G_BIT, &priv->cfg))
seq_printf(s, "3G ");
if (test_bit(CFG_WIFI_BIT, &priv->cfg))
seq_printf(s, "Wireless ");
if (test_bit(CFG_CAMERA_BIT, &priv->cfg))
seq_printf(s, "Camera ");
seq_printf(s, "\nGraphic: ");
switch ((priv->cfg)&0x700) {
case 0x100:
seq_printf(s, "Intel");
break;
case 0x200:
seq_printf(s, "ATI");
break;
case 0x300:
seq_printf(s, "Nvidia");
break;
case 0x400:
seq_printf(s, "Intel and ATI");
break;
case 0x500:
seq_printf(s, "Intel and Nvidia");
break;
}
seq_printf(s, "\n");
}
return 0;
}
static int debugfs_cfg_open(struct inode *inode, struct file *file)
{
return single_open(file, debugfs_cfg_show, inode->i_private);
}
static int ideapad_debugfs_init(struct ideapad_private *priv)
{
struct dentry *node;
priv->debug = debugfs_create_dir("ideapad", NULL);
if (priv->debug == NULL) {
pr_err("failed to create debugfs directory");
goto errout;
}
node = debugfs_create_file("cfg", S_IRUGO, priv->debug, priv,
&debugfs_cfg_fops);
if (!node) {
pr_err("failed to create cfg in debugfs");
goto errout;
}
node = debugfs_create_file("status", S_IRUGO, priv->debug, priv,
&debugfs_status_fops);
if (!node) {
pr_err("failed to create status in debugfs");
goto errout;
}
return 0;
errout:
return -ENOMEM;
}
static void ideapad_debugfs_exit(struct ideapad_private *priv)
{
debugfs_remove_recursive(priv->debug);
priv->debug = NULL;
}
static ssize_t show_ideapad_cam(struct device *dev,
struct device_attribute *attr,
char *buf)
{
unsigned long result;
struct ideapad_private *priv = dev_get_drvdata(dev);
if (read_ec_data(priv->adev->handle, VPCCMD_R_CAMERA, &result))
return sprintf(buf, "-1\n");
return sprintf(buf, "%lu\n", result);
}
static ssize_t store_ideapad_cam(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
int ret, state;
struct ideapad_private *priv = dev_get_drvdata(dev);
if (!count)
return 0;
if (sscanf(buf, "%i", &state) != 1)
return -EINVAL;
ret = write_ec_cmd(priv->adev->handle, VPCCMD_W_CAMERA, state);
if (ret < 0)
return -EIO;
return count;
}
static ssize_t show_ideapad_fan(struct device *dev,
struct device_attribute *attr,
char *buf)
{
unsigned long result;
struct ideapad_private *priv = dev_get_drvdata(dev);
if (read_ec_data(priv->adev->handle, VPCCMD_R_FAN, &result))
return sprintf(buf, "-1\n");
return sprintf(buf, "%lu\n", result);
}
static ssize_t store_ideapad_fan(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
int ret, state;
struct ideapad_private *priv = dev_get_drvdata(dev);
if (!count)
return 0;
if (sscanf(buf, "%i", &state) != 1)
return -EINVAL;
if (state < 0 || state > 4 || state == 3)
return -EINVAL;
ret = write_ec_cmd(priv->adev->handle, VPCCMD_W_FAN, state);
if (ret < 0)
return -EIO;
return count;
}
static umode_t ideapad_is_visible(struct kobject *kobj,
struct attribute *attr,
int idx)
{
struct device *dev = container_of(kobj, struct device, kobj);
struct ideapad_private *priv = dev_get_drvdata(dev);
bool supported;
if (attr == &dev_attr_camera_power.attr)
supported = test_bit(CFG_CAMERA_BIT, &(priv->cfg));
else if (attr == &dev_attr_fan_mode.attr) {
unsigned long value;
supported = !read_ec_data(priv->adev->handle, VPCCMD_R_FAN,
&value);
} else
supported = true;
return supported ? attr->mode : 0;
}
static int ideapad_rfk_set(void *data, bool blocked)
{
struct ideapad_rfk_priv *priv = data;
return write_ec_cmd(priv->priv->adev->handle, priv->dev, !blocked);
}
static void ideapad_sync_rfk_state(struct ideapad_private *priv)
{
unsigned long hw_blocked = 0;
int i;
if (priv->has_hw_rfkill_switch) {
if (read_ec_data(priv->adev->handle, VPCCMD_R_RF, &hw_blocked))
return;
hw_blocked = !hw_blocked;
}
for (i = 0; i < IDEAPAD_RFKILL_DEV_NUM; i++)
if (priv->rfk[i])
rfkill_set_hw_state(priv->rfk[i], hw_blocked);
}
static int ideapad_register_rfkill(struct ideapad_private *priv, int dev)
{
int ret;
unsigned long sw_blocked;
if (no_bt_rfkill &&
(ideapad_rfk_data[dev].type == RFKILL_TYPE_BLUETOOTH)) {
write_ec_cmd(priv->adev->handle,
ideapad_rfk_data[dev].opcode, 1);
return 0;
}
priv->rfk_priv[dev].dev = dev;
priv->rfk_priv[dev].priv = priv;
priv->rfk[dev] = rfkill_alloc(ideapad_rfk_data[dev].name,
&priv->platform_device->dev,
ideapad_rfk_data[dev].type,
&ideapad_rfk_ops,
&priv->rfk_priv[dev]);
if (!priv->rfk[dev])
return -ENOMEM;
if (read_ec_data(priv->adev->handle, ideapad_rfk_data[dev].opcode-1,
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
static void ideapad_unregister_rfkill(struct ideapad_private *priv, int dev)
{
if (!priv->rfk[dev])
return;
rfkill_unregister(priv->rfk[dev]);
rfkill_destroy(priv->rfk[dev]);
}
static int ideapad_sysfs_init(struct ideapad_private *priv)
{
return sysfs_create_group(&priv->platform_device->dev.kobj,
&ideapad_attribute_group);
}
static void ideapad_sysfs_exit(struct ideapad_private *priv)
{
sysfs_remove_group(&priv->platform_device->dev.kobj,
&ideapad_attribute_group);
}
static int ideapad_input_init(struct ideapad_private *priv)
{
struct input_dev *inputdev;
int error;
inputdev = input_allocate_device();
if (!inputdev)
return -ENOMEM;
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
static void ideapad_input_novokey(struct ideapad_private *priv)
{
unsigned long long_pressed;
if (read_ec_data(priv->adev->handle, VPCCMD_R_NOVO, &long_pressed))
return;
if (long_pressed)
ideapad_input_report(priv, 17);
else
ideapad_input_report(priv, 16);
}
static void ideapad_check_special_buttons(struct ideapad_private *priv)
{
unsigned long bit, value;
read_ec_data(priv->adev->handle, VPCCMD_R_SPECIAL_BUTTONS, &value);
for (bit = 0; bit < 16; bit++) {
if (test_bit(bit, &value)) {
switch (bit) {
case 0:
case 6:
ideapad_input_report(priv, 65);
break;
case 1:
ideapad_input_report(priv, 64);
break;
default:
pr_info("Unknown special button: %lu\n", bit);
break;
}
}
}
}
static int ideapad_backlight_get_brightness(struct backlight_device *blightdev)
{
struct ideapad_private *priv = bl_get_data(blightdev);
unsigned long now;
if (!priv)
return -EINVAL;
if (read_ec_data(priv->adev->handle, VPCCMD_R_BL, &now))
return -EIO;
return now;
}
static int ideapad_backlight_update_status(struct backlight_device *blightdev)
{
struct ideapad_private *priv = bl_get_data(blightdev);
if (!priv)
return -EINVAL;
if (write_ec_cmd(priv->adev->handle, VPCCMD_W_BL,
blightdev->props.brightness))
return -EIO;
if (write_ec_cmd(priv->adev->handle, VPCCMD_W_BL_POWER,
blightdev->props.power == FB_BLANK_POWERDOWN ? 0 : 1))
return -EIO;
return 0;
}
static int ideapad_backlight_init(struct ideapad_private *priv)
{
struct backlight_device *blightdev;
struct backlight_properties props;
unsigned long max, now, power;
if (read_ec_data(priv->adev->handle, VPCCMD_R_BL_MAX, &max))
return -EIO;
if (read_ec_data(priv->adev->handle, VPCCMD_R_BL, &now))
return -EIO;
if (read_ec_data(priv->adev->handle, VPCCMD_R_BL_POWER, &power))
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
backlight_device_unregister(priv->blightdev);
priv->blightdev = NULL;
}
static void ideapad_backlight_notify_power(struct ideapad_private *priv)
{
unsigned long power;
struct backlight_device *blightdev = priv->blightdev;
if (!blightdev)
return;
if (read_ec_data(priv->adev->handle, VPCCMD_R_BL_POWER, &power))
return;
blightdev->props.power = power ? FB_BLANK_UNBLANK : FB_BLANK_POWERDOWN;
}
static void ideapad_backlight_notify_brightness(struct ideapad_private *priv)
{
unsigned long now;
if (priv->blightdev == NULL) {
read_ec_data(priv->adev->handle, VPCCMD_R_BL, &now);
return;
}
backlight_force_update(priv->blightdev, BACKLIGHT_UPDATE_HOTKEY);
}
static void ideapad_sync_touchpad_state(struct ideapad_private *priv)
{
unsigned long value;
if (!read_ec_data(priv->adev->handle, VPCCMD_R_TOUCHPAD, &value)) {
unsigned char param;
i8042_command(&param, value ? I8042_CMD_AUX_ENABLE :
I8042_CMD_AUX_DISABLE);
ideapad_input_report(priv, value ? 67 : 66);
}
}
static void ideapad_acpi_notify(acpi_handle handle, u32 event, void *data)
{
struct ideapad_private *priv = data;
unsigned long vpc1, vpc2, vpc_bit;
if (read_ec_data(handle, VPCCMD_R_VPC1, &vpc1))
return;
if (read_ec_data(handle, VPCCMD_R_VPC2, &vpc2))
return;
vpc1 = (vpc2 << 8) | vpc1;
for (vpc_bit = 0; vpc_bit < 16; vpc_bit++) {
if (test_bit(vpc_bit, &vpc1)) {
switch (vpc_bit) {
case 9:
ideapad_sync_rfk_state(priv);
break;
case 13:
case 11:
case 7:
case 6:
ideapad_input_report(priv, vpc_bit);
break;
case 5:
ideapad_sync_touchpad_state(priv);
break;
case 4:
ideapad_backlight_notify_brightness(priv);
break;
case 3:
ideapad_input_novokey(priv);
break;
case 2:
ideapad_backlight_notify_power(priv);
break;
case 0:
ideapad_check_special_buttons(priv);
break;
default:
pr_info("Unknown event: %lu\n", vpc_bit);
}
}
}
}
static int ideapad_acpi_add(struct platform_device *pdev)
{
int ret, i;
int cfg;
struct ideapad_private *priv;
struct acpi_device *adev;
ret = acpi_bus_get_device(ACPI_HANDLE(&pdev->dev), &adev);
if (ret)
return -ENODEV;
if (read_method_int(adev->handle, "_CFG", &cfg))
return -ENODEV;
priv = devm_kzalloc(&pdev->dev, sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
dev_set_drvdata(&pdev->dev, priv);
priv->cfg = cfg;
priv->adev = adev;
priv->platform_device = pdev;
priv->has_hw_rfkill_switch = !dmi_check_system(no_hw_rfkill_list);
ret = ideapad_sysfs_init(priv);
if (ret)
return ret;
ret = ideapad_debugfs_init(priv);
if (ret)
goto debugfs_failed;
ret = ideapad_input_init(priv);
if (ret)
goto input_failed;
if (!priv->has_hw_rfkill_switch)
write_ec_cmd(priv->adev->handle, VPCCMD_W_RF, 1);
for (i = 0; i < IDEAPAD_RFKILL_DEV_NUM; i++)
if (test_bit(ideapad_rfk_data[i].cfgbit, &priv->cfg))
ideapad_register_rfkill(priv, i);
ideapad_sync_rfk_state(priv);
ideapad_sync_touchpad_state(priv);
if (!acpi_video_backlight_support()) {
ret = ideapad_backlight_init(priv);
if (ret && ret != -ENODEV)
goto backlight_failed;
}
ret = acpi_install_notify_handler(adev->handle,
ACPI_DEVICE_NOTIFY, ideapad_acpi_notify, priv);
if (ret)
goto notification_failed;
return 0;
notification_failed:
ideapad_backlight_exit(priv);
backlight_failed:
for (i = 0; i < IDEAPAD_RFKILL_DEV_NUM; i++)
ideapad_unregister_rfkill(priv, i);
ideapad_input_exit(priv);
input_failed:
ideapad_debugfs_exit(priv);
debugfs_failed:
ideapad_sysfs_exit(priv);
return ret;
}
static int ideapad_acpi_remove(struct platform_device *pdev)
{
struct ideapad_private *priv = dev_get_drvdata(&pdev->dev);
int i;
acpi_remove_notify_handler(priv->adev->handle,
ACPI_DEVICE_NOTIFY, ideapad_acpi_notify);
ideapad_backlight_exit(priv);
for (i = 0; i < IDEAPAD_RFKILL_DEV_NUM; i++)
ideapad_unregister_rfkill(priv, i);
ideapad_input_exit(priv);
ideapad_debugfs_exit(priv);
ideapad_sysfs_exit(priv);
dev_set_drvdata(&pdev->dev, NULL);
return 0;
}
static int ideapad_acpi_resume(struct device *device)
{
struct ideapad_private *priv;
if (!device)
return -EINVAL;
priv = dev_get_drvdata(device);
ideapad_sync_rfk_state(priv);
ideapad_sync_touchpad_state(priv);
return 0;
}
