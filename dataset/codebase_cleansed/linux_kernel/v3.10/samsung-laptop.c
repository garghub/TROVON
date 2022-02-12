static int sabi_command(struct samsung_laptop *samsung, u16 command,
struct sabi_data *in,
struct sabi_data *out)
{
const struct sabi_config *config = samsung->config;
int ret = 0;
u16 port = readw(samsung->sabi + config->header_offsets.port);
u8 complete, iface_data;
mutex_lock(&samsung->sabi_mutex);
if (debug) {
if (in)
pr_info("SABI command:0x%04x "
"data:{0x%08x, 0x%08x, 0x%04x, 0x%02x}",
command, in->d0, in->d1, in->d2, in->d3);
else
pr_info("SABI command:0x%04x", command);
}
outb(readb(samsung->sabi + config->header_offsets.en_mem), port);
writew(config->main_function, samsung->sabi_iface + SABI_IFACE_MAIN);
writew(command, samsung->sabi_iface + SABI_IFACE_SUB);
writeb(0, samsung->sabi_iface + SABI_IFACE_COMPLETE);
if (in) {
writel(in->d0, samsung->sabi_iface + SABI_IFACE_DATA);
writel(in->d1, samsung->sabi_iface + SABI_IFACE_DATA + 4);
writew(in->d2, samsung->sabi_iface + SABI_IFACE_DATA + 8);
writeb(in->d3, samsung->sabi_iface + SABI_IFACE_DATA + 10);
}
outb(readb(samsung->sabi + config->header_offsets.iface_func), port);
outb(readb(samsung->sabi + config->header_offsets.re_mem), port);
complete = readb(samsung->sabi_iface + SABI_IFACE_COMPLETE);
iface_data = readb(samsung->sabi_iface + SABI_IFACE_DATA);
if (complete != 0xaa || (iface_data == 0xff && debug))
pr_warn("SABI command 0x%04x failed with"
" completion flag 0x%02x and interface data 0x%02x",
command, complete, iface_data);
if (complete != 0xaa || iface_data == 0xff) {
ret = -EINVAL;
goto exit;
}
if (out) {
out->d0 = readl(samsung->sabi_iface + SABI_IFACE_DATA);
out->d1 = readl(samsung->sabi_iface + SABI_IFACE_DATA + 4);
out->d2 = readw(samsung->sabi_iface + SABI_IFACE_DATA + 2);
out->d3 = readb(samsung->sabi_iface + SABI_IFACE_DATA + 1);
}
if (debug && out) {
pr_info("SABI return data:{0x%08x, 0x%08x, 0x%04x, 0x%02x}",
out->d0, out->d1, out->d2, out->d3);
}
exit:
mutex_unlock(&samsung->sabi_mutex);
return ret;
}
static int sabi_set_commandb(struct samsung_laptop *samsung,
u16 command, u8 data)
{
struct sabi_data in = { { { .d0 = 0, .d1 = 0, .d2 = 0, .d3 = 0 } } };
in.data[0] = data;
return sabi_command(samsung, command, &in, NULL);
}
static int read_brightness(struct samsung_laptop *samsung)
{
const struct sabi_config *config = samsung->config;
const struct sabi_commands *commands = &samsung->config->commands;
struct sabi_data sretval;
int user_brightness = 0;
int retval;
retval = sabi_command(samsung, commands->get_brightness,
NULL, &sretval);
if (retval)
return retval;
user_brightness = sretval.data[0];
if (user_brightness > config->min_brightness)
user_brightness -= config->min_brightness;
else
user_brightness = 0;
return user_brightness;
}
static void set_brightness(struct samsung_laptop *samsung, u8 user_brightness)
{
const struct sabi_config *config = samsung->config;
const struct sabi_commands *commands = &samsung->config->commands;
u8 user_level = user_brightness + config->min_brightness;
if (samsung->has_stepping_quirk && user_level != 0) {
if (user_brightness == read_brightness(samsung))
return;
sabi_set_commandb(samsung, commands->set_brightness, 0);
}
sabi_set_commandb(samsung, commands->set_brightness, user_level);
}
static int get_brightness(struct backlight_device *bd)
{
struct samsung_laptop *samsung = bl_get_data(bd);
return read_brightness(samsung);
}
static void check_for_stepping_quirk(struct samsung_laptop *samsung)
{
int initial_level;
int check_level;
int orig_level = read_brightness(samsung);
if (orig_level == 0)
set_brightness(samsung, 1);
initial_level = read_brightness(samsung);
if (initial_level <= 2)
check_level = initial_level + 2;
else
check_level = initial_level - 2;
samsung->has_stepping_quirk = false;
set_brightness(samsung, check_level);
if (read_brightness(samsung) != check_level) {
samsung->has_stepping_quirk = true;
pr_info("enabled workaround for brightness stepping quirk\n");
}
set_brightness(samsung, orig_level);
}
static int update_status(struct backlight_device *bd)
{
struct samsung_laptop *samsung = bl_get_data(bd);
const struct sabi_commands *commands = &samsung->config->commands;
set_brightness(samsung, bd->props.brightness);
if (bd->props.power == FB_BLANK_UNBLANK)
sabi_set_commandb(samsung, commands->set_backlight, 1);
else
sabi_set_commandb(samsung, commands->set_backlight, 0);
return 0;
}
static int seclinux_rfkill_set(void *data, bool blocked)
{
struct samsung_rfkill *srfkill = data;
struct samsung_laptop *samsung = srfkill->samsung;
const struct sabi_commands *commands = &samsung->config->commands;
return sabi_set_commandb(samsung, commands->set_wireless_button,
!blocked);
}
static int swsmi_wireless_status(struct samsung_laptop *samsung,
struct sabi_data *data)
{
const struct sabi_commands *commands = &samsung->config->commands;
return sabi_command(samsung, commands->get_wireless_status,
NULL, data);
}
static int swsmi_rfkill_set(void *priv, bool blocked)
{
struct samsung_rfkill *srfkill = priv;
struct samsung_laptop *samsung = srfkill->samsung;
const struct sabi_commands *commands = &samsung->config->commands;
struct sabi_data data;
int ret, i;
ret = swsmi_wireless_status(samsung, &data);
if (ret)
return ret;
for (i = 0; i < 4; i++)
if (data.data[i] == 0x02)
data.data[1] = 0;
if (srfkill->type == RFKILL_TYPE_WLAN)
data.data[WL_STATUS_WLAN] = !blocked;
else if (srfkill->type == RFKILL_TYPE_BLUETOOTH)
data.data[WL_STATUS_BT] = !blocked;
return sabi_command(samsung, commands->set_wireless_status,
&data, &data);
}
static void swsmi_rfkill_query(struct rfkill *rfkill, void *priv)
{
struct samsung_rfkill *srfkill = priv;
struct samsung_laptop *samsung = srfkill->samsung;
struct sabi_data data;
int ret;
ret = swsmi_wireless_status(samsung, &data);
if (ret)
return ;
if (srfkill->type == RFKILL_TYPE_WLAN)
ret = data.data[WL_STATUS_WLAN];
else if (srfkill->type == RFKILL_TYPE_BLUETOOTH)
ret = data.data[WL_STATUS_BT];
else
return ;
rfkill_set_sw_state(rfkill, !ret);
}
static ssize_t get_performance_level(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct samsung_laptop *samsung = dev_get_drvdata(dev);
const struct sabi_config *config = samsung->config;
const struct sabi_commands *commands = &config->commands;
struct sabi_data sretval;
int retval;
int i;
retval = sabi_command(samsung, commands->get_performance_level,
NULL, &sretval);
if (retval)
return retval;
for (i = 0; config->performance_levels[i].name; ++i) {
if (sretval.data[0] == config->performance_levels[i].value)
return sprintf(buf, "%s\n", config->performance_levels[i].name);
}
return sprintf(buf, "%s\n", "unknown");
}
static ssize_t set_performance_level(struct device *dev,
struct device_attribute *attr, const char *buf,
size_t count)
{
struct samsung_laptop *samsung = dev_get_drvdata(dev);
const struct sabi_config *config = samsung->config;
const struct sabi_commands *commands = &config->commands;
int i;
if (count < 1)
return count;
for (i = 0; config->performance_levels[i].name; ++i) {
const struct sabi_performance_level *level =
&config->performance_levels[i];
if (!strncasecmp(level->name, buf, strlen(level->name))) {
sabi_set_commandb(samsung,
commands->set_performance_level,
level->value);
break;
}
}
if (!config->performance_levels[i].name)
return -EINVAL;
return count;
}
static int read_battery_life_extender(struct samsung_laptop *samsung)
{
const struct sabi_commands *commands = &samsung->config->commands;
struct sabi_data data;
int retval;
if (commands->get_battery_life_extender == 0xFFFF)
return -ENODEV;
memset(&data, 0, sizeof(data));
data.data[0] = 0x80;
retval = sabi_command(samsung, commands->get_battery_life_extender,
&data, &data);
if (retval)
return retval;
if (data.data[0] != 0 && data.data[0] != 1)
return -ENODEV;
return data.data[0];
}
static int write_battery_life_extender(struct samsung_laptop *samsung,
int enabled)
{
const struct sabi_commands *commands = &samsung->config->commands;
struct sabi_data data;
memset(&data, 0, sizeof(data));
data.data[0] = 0x80 | enabled;
return sabi_command(samsung, commands->set_battery_life_extender,
&data, NULL);
}
static ssize_t get_battery_life_extender(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct samsung_laptop *samsung = dev_get_drvdata(dev);
int ret;
ret = read_battery_life_extender(samsung);
if (ret < 0)
return ret;
return sprintf(buf, "%d\n", ret);
}
static ssize_t set_battery_life_extender(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct samsung_laptop *samsung = dev_get_drvdata(dev);
int ret, value;
if (!count || sscanf(buf, "%i", &value) != 1)
return -EINVAL;
ret = write_battery_life_extender(samsung, !!value);
if (ret < 0)
return ret;
return count;
}
static int read_usb_charge(struct samsung_laptop *samsung)
{
const struct sabi_commands *commands = &samsung->config->commands;
struct sabi_data data;
int retval;
if (commands->get_usb_charge == 0xFFFF)
return -ENODEV;
memset(&data, 0, sizeof(data));
data.data[0] = 0x80;
retval = sabi_command(samsung, commands->get_usb_charge,
&data, &data);
if (retval)
return retval;
if (data.data[0] != 0 && data.data[0] != 1)
return -ENODEV;
return data.data[0];
}
static int write_usb_charge(struct samsung_laptop *samsung,
int enabled)
{
const struct sabi_commands *commands = &samsung->config->commands;
struct sabi_data data;
memset(&data, 0, sizeof(data));
data.data[0] = 0x80 | enabled;
return sabi_command(samsung, commands->set_usb_charge,
&data, NULL);
}
static ssize_t get_usb_charge(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct samsung_laptop *samsung = dev_get_drvdata(dev);
int ret;
ret = read_usb_charge(samsung);
if (ret < 0)
return ret;
return sprintf(buf, "%d\n", ret);
}
static ssize_t set_usb_charge(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct samsung_laptop *samsung = dev_get_drvdata(dev);
int ret, value;
if (!count || sscanf(buf, "%i", &value) != 1)
return -EINVAL;
ret = write_usb_charge(samsung, !!value);
if (ret < 0)
return ret;
return count;
}
static int find_signature(void __iomem *memcheck, const char *testStr)
{
int i = 0;
int loca;
for (loca = 0; loca < 0xffff; loca++) {
char temp = readb(memcheck + loca);
if (temp == testStr[i]) {
if (i == strlen(testStr)-1)
break;
++i;
} else {
i = 0;
}
}
return loca;
}
static void samsung_rfkill_exit(struct samsung_laptop *samsung)
{
if (samsung->wlan.rfkill) {
rfkill_unregister(samsung->wlan.rfkill);
rfkill_destroy(samsung->wlan.rfkill);
samsung->wlan.rfkill = NULL;
}
if (samsung->bluetooth.rfkill) {
rfkill_unregister(samsung->bluetooth.rfkill);
rfkill_destroy(samsung->bluetooth.rfkill);
samsung->bluetooth.rfkill = NULL;
}
}
static int samsung_new_rfkill(struct samsung_laptop *samsung,
struct samsung_rfkill *arfkill,
const char *name, enum rfkill_type type,
const struct rfkill_ops *ops,
int blocked)
{
struct rfkill **rfkill = &arfkill->rfkill;
int ret;
arfkill->type = type;
arfkill->samsung = samsung;
*rfkill = rfkill_alloc(name, &samsung->platform_device->dev,
type, ops, arfkill);
if (!*rfkill)
return -EINVAL;
if (blocked != -1)
rfkill_init_sw_state(*rfkill, blocked);
ret = rfkill_register(*rfkill);
if (ret) {
rfkill_destroy(*rfkill);
*rfkill = NULL;
return ret;
}
return 0;
}
static int __init samsung_rfkill_init_seclinux(struct samsung_laptop *samsung)
{
return samsung_new_rfkill(samsung, &samsung->wlan, "samsung-wlan",
RFKILL_TYPE_WLAN, &seclinux_rfkill_ops, -1);
}
static int __init samsung_rfkill_init_swsmi(struct samsung_laptop *samsung)
{
struct sabi_data data;
int ret;
ret = swsmi_wireless_status(samsung, &data);
if (ret) {
if (ret == -EINVAL)
ret = samsung_rfkill_init_seclinux(samsung);
return ret;
}
if (data.data[WL_STATUS_WLAN] != 0x02)
ret = samsung_new_rfkill(samsung, &samsung->wlan,
"samsung-wlan",
RFKILL_TYPE_WLAN,
&swsmi_rfkill_ops,
!data.data[WL_STATUS_WLAN]);
if (ret)
goto exit;
if (data.data[WL_STATUS_BT] != 0x02)
ret = samsung_new_rfkill(samsung, &samsung->bluetooth,
"samsung-bluetooth",
RFKILL_TYPE_BLUETOOTH,
&swsmi_rfkill_ops,
!data.data[WL_STATUS_BT]);
if (ret)
goto exit;
exit:
if (ret)
samsung_rfkill_exit(samsung);
return ret;
}
static int __init samsung_rfkill_init(struct samsung_laptop *samsung)
{
if (samsung->config->sabi_version == 2)
return samsung_rfkill_init_seclinux(samsung);
if (samsung->config->sabi_version == 3)
return samsung_rfkill_init_swsmi(samsung);
return 0;
}
static int kbd_backlight_enable(struct samsung_laptop *samsung)
{
const struct sabi_commands *commands = &samsung->config->commands;
struct sabi_data data;
int retval;
if (commands->kbd_backlight == 0xFFFF)
return -ENODEV;
memset(&data, 0, sizeof(data));
data.d0 = 0xaabb;
retval = sabi_command(samsung, commands->kbd_backlight,
&data, &data);
if (retval)
return retval;
if (data.d0 != 0xccdd)
return -ENODEV;
return 0;
}
static int kbd_backlight_read(struct samsung_laptop *samsung)
{
const struct sabi_commands *commands = &samsung->config->commands;
struct sabi_data data;
int retval;
memset(&data, 0, sizeof(data));
data.data[0] = 0x81;
retval = sabi_command(samsung, commands->kbd_backlight,
&data, &data);
if (retval)
return retval;
return data.data[0];
}
static int kbd_backlight_write(struct samsung_laptop *samsung, int brightness)
{
const struct sabi_commands *commands = &samsung->config->commands;
struct sabi_data data;
memset(&data, 0, sizeof(data));
data.d0 = 0x82 | ((brightness & 0xFF) << 8);
return sabi_command(samsung, commands->kbd_backlight,
&data, NULL);
}
static void kbd_led_update(struct work_struct *work)
{
struct samsung_laptop *samsung;
samsung = container_of(work, struct samsung_laptop, kbd_led_work);
kbd_backlight_write(samsung, samsung->kbd_led_wk);
}
static void kbd_led_set(struct led_classdev *led_cdev,
enum led_brightness value)
{
struct samsung_laptop *samsung;
samsung = container_of(led_cdev, struct samsung_laptop, kbd_led);
if (value > samsung->kbd_led.max_brightness)
value = samsung->kbd_led.max_brightness;
else if (value < 0)
value = 0;
samsung->kbd_led_wk = value;
queue_work(samsung->led_workqueue, &samsung->kbd_led_work);
}
static enum led_brightness kbd_led_get(struct led_classdev *led_cdev)
{
struct samsung_laptop *samsung;
samsung = container_of(led_cdev, struct samsung_laptop, kbd_led);
return kbd_backlight_read(samsung);
}
static void samsung_leds_exit(struct samsung_laptop *samsung)
{
if (!IS_ERR_OR_NULL(samsung->kbd_led.dev))
led_classdev_unregister(&samsung->kbd_led);
if (samsung->led_workqueue)
destroy_workqueue(samsung->led_workqueue);
}
static int __init samsung_leds_init(struct samsung_laptop *samsung)
{
int ret = 0;
samsung->led_workqueue = create_singlethread_workqueue("led_workqueue");
if (!samsung->led_workqueue)
return -ENOMEM;
if (kbd_backlight_enable(samsung) >= 0) {
INIT_WORK(&samsung->kbd_led_work, kbd_led_update);
samsung->kbd_led.name = "samsung::kbd_backlight";
samsung->kbd_led.brightness_set = kbd_led_set;
samsung->kbd_led.brightness_get = kbd_led_get;
samsung->kbd_led.max_brightness = 8;
ret = led_classdev_register(&samsung->platform_device->dev,
&samsung->kbd_led);
}
if (ret)
samsung_leds_exit(samsung);
return ret;
}
static void samsung_backlight_exit(struct samsung_laptop *samsung)
{
if (samsung->backlight_device) {
backlight_device_unregister(samsung->backlight_device);
samsung->backlight_device = NULL;
}
}
static int __init samsung_backlight_init(struct samsung_laptop *samsung)
{
struct backlight_device *bd;
struct backlight_properties props;
if (!samsung->handle_backlight)
return 0;
memset(&props, 0, sizeof(struct backlight_properties));
props.type = BACKLIGHT_PLATFORM;
props.max_brightness = samsung->config->max_brightness -
samsung->config->min_brightness;
bd = backlight_device_register("samsung",
&samsung->platform_device->dev,
samsung, &backlight_ops,
&props);
if (IS_ERR(bd))
return PTR_ERR(bd);
samsung->backlight_device = bd;
samsung->backlight_device->props.brightness = read_brightness(samsung);
samsung->backlight_device->props.power = FB_BLANK_UNBLANK;
backlight_update_status(samsung->backlight_device);
return 0;
}
static umode_t samsung_sysfs_is_visible(struct kobject *kobj,
struct attribute *attr, int idx)
{
struct device *dev = container_of(kobj, struct device, kobj);
struct platform_device *pdev = to_platform_device(dev);
struct samsung_laptop *samsung = platform_get_drvdata(pdev);
bool ok = true;
if (attr == &dev_attr_performance_level.attr)
ok = !!samsung->config->performance_levels[0].name;
if (attr == &dev_attr_battery_life_extender.attr)
ok = !!(read_battery_life_extender(samsung) >= 0);
if (attr == &dev_attr_usb_charge.attr)
ok = !!(read_usb_charge(samsung) >= 0);
return ok ? attr->mode : 0;
}
static void samsung_sysfs_exit(struct samsung_laptop *samsung)
{
struct platform_device *device = samsung->platform_device;
sysfs_remove_group(&device->dev.kobj, &platform_attribute_group);
}
static int __init samsung_sysfs_init(struct samsung_laptop *samsung)
{
struct platform_device *device = samsung->platform_device;
return sysfs_create_group(&device->dev.kobj, &platform_attribute_group);
}
static int show_call(struct seq_file *m, void *data)
{
struct samsung_laptop *samsung = m->private;
struct sabi_data *sdata = &samsung->debug.data;
int ret;
seq_printf(m, "SABI 0x%04x {0x%08x, 0x%08x, 0x%04x, 0x%02x}\n",
samsung->debug.command,
sdata->d0, sdata->d1, sdata->d2, sdata->d3);
ret = sabi_command(samsung, samsung->debug.command, sdata, sdata);
if (ret) {
seq_printf(m, "SABI command 0x%04x failed\n",
samsung->debug.command);
return ret;
}
seq_printf(m, "SABI {0x%08x, 0x%08x, 0x%04x, 0x%02x}\n",
sdata->d0, sdata->d1, sdata->d2, sdata->d3);
return 0;
}
static int samsung_debugfs_open(struct inode *inode, struct file *file)
{
return single_open(file, show_call, inode->i_private);
}
static void samsung_debugfs_exit(struct samsung_laptop *samsung)
{
debugfs_remove_recursive(samsung->debug.root);
}
static int samsung_debugfs_init(struct samsung_laptop *samsung)
{
struct dentry *dent;
samsung->debug.root = debugfs_create_dir("samsung-laptop", NULL);
if (!samsung->debug.root) {
pr_err("failed to create debugfs directory");
goto error_debugfs;
}
samsung->debug.f0000_wrapper.data = samsung->f0000_segment;
samsung->debug.f0000_wrapper.size = 0xffff;
samsung->debug.data_wrapper.data = &samsung->debug.data;
samsung->debug.data_wrapper.size = sizeof(samsung->debug.data);
samsung->debug.sdiag_wrapper.data = samsung->sdiag;
samsung->debug.sdiag_wrapper.size = strlen(samsung->sdiag);
dent = debugfs_create_u16("command", S_IRUGO | S_IWUSR,
samsung->debug.root, &samsung->debug.command);
if (!dent)
goto error_debugfs;
dent = debugfs_create_u32("d0", S_IRUGO | S_IWUSR, samsung->debug.root,
&samsung->debug.data.d0);
if (!dent)
goto error_debugfs;
dent = debugfs_create_u32("d1", S_IRUGO | S_IWUSR, samsung->debug.root,
&samsung->debug.data.d1);
if (!dent)
goto error_debugfs;
dent = debugfs_create_u16("d2", S_IRUGO | S_IWUSR, samsung->debug.root,
&samsung->debug.data.d2);
if (!dent)
goto error_debugfs;
dent = debugfs_create_u8("d3", S_IRUGO | S_IWUSR, samsung->debug.root,
&samsung->debug.data.d3);
if (!dent)
goto error_debugfs;
dent = debugfs_create_blob("data", S_IRUGO | S_IWUSR,
samsung->debug.root,
&samsung->debug.data_wrapper);
if (!dent)
goto error_debugfs;
dent = debugfs_create_blob("f0000_segment", S_IRUSR | S_IWUSR,
samsung->debug.root,
&samsung->debug.f0000_wrapper);
if (!dent)
goto error_debugfs;
dent = debugfs_create_file("call", S_IFREG | S_IRUGO,
samsung->debug.root, samsung,
&samsung_laptop_call_io_ops);
if (!dent)
goto error_debugfs;
dent = debugfs_create_blob("sdiag", S_IRUGO | S_IWUSR,
samsung->debug.root,
&samsung->debug.sdiag_wrapper);
if (!dent)
goto error_debugfs;
return 0;
error_debugfs:
samsung_debugfs_exit(samsung);
return -ENOMEM;
}
static void samsung_sabi_exit(struct samsung_laptop *samsung)
{
const struct sabi_config *config = samsung->config;
if (config && config->commands.set_linux != 0xff)
sabi_set_commandb(samsung, config->commands.set_linux, 0x80);
if (samsung->sabi_iface) {
iounmap(samsung->sabi_iface);
samsung->sabi_iface = NULL;
}
if (samsung->f0000_segment) {
iounmap(samsung->f0000_segment);
samsung->f0000_segment = NULL;
}
samsung->config = NULL;
}
static __init void samsung_sabi_infos(struct samsung_laptop *samsung, int loca,
unsigned int ifaceP)
{
const struct sabi_config *config = samsung->config;
printk(KERN_DEBUG "This computer supports SABI==%x\n",
loca + 0xf0000 - 6);
printk(KERN_DEBUG "SABI header:\n");
printk(KERN_DEBUG " SMI Port Number = 0x%04x\n",
readw(samsung->sabi + config->header_offsets.port));
printk(KERN_DEBUG " SMI Interface Function = 0x%02x\n",
readb(samsung->sabi + config->header_offsets.iface_func));
printk(KERN_DEBUG " SMI enable memory buffer = 0x%02x\n",
readb(samsung->sabi + config->header_offsets.en_mem));
printk(KERN_DEBUG " SMI restore memory buffer = 0x%02x\n",
readb(samsung->sabi + config->header_offsets.re_mem));
printk(KERN_DEBUG " SABI data offset = 0x%04x\n",
readw(samsung->sabi + config->header_offsets.data_offset));
printk(KERN_DEBUG " SABI data segment = 0x%04x\n",
readw(samsung->sabi + config->header_offsets.data_segment));
printk(KERN_DEBUG " SABI pointer = 0x%08x\n", ifaceP);
}
static void __init samsung_sabi_diag(struct samsung_laptop *samsung)
{
int loca = find_signature(samsung->f0000_segment, "SDiaG@");
int i;
if (loca == 0xffff)
return ;
loca += 1;
for (i = 0; loca < 0xffff && i < sizeof(samsung->sdiag) - 1; loca++) {
char temp = readb(samsung->f0000_segment + loca);
if (isalnum(temp) || temp == '/' || temp == '-')
samsung->sdiag[i++] = temp;
else
break ;
}
if (debug && samsung->sdiag[0])
pr_info("sdiag: %s", samsung->sdiag);
}
static int __init samsung_sabi_init(struct samsung_laptop *samsung)
{
const struct sabi_config *config = NULL;
const struct sabi_commands *commands;
unsigned int ifaceP;
int ret = 0;
int i;
int loca;
samsung->f0000_segment = ioremap_nocache(0xf0000, 0xffff);
if (!samsung->f0000_segment) {
if (debug || force)
pr_err("Can't map the segment at 0xf0000\n");
ret = -EINVAL;
goto exit;
}
samsung_sabi_diag(samsung);
for (i = 0; sabi_configs[i].test_string != 0; ++i) {
samsung->config = &sabi_configs[i];
loca = find_signature(samsung->f0000_segment,
samsung->config->test_string);
if (loca != 0xffff)
break;
}
if (loca == 0xffff) {
if (debug || force)
pr_err("This computer does not support SABI\n");
ret = -ENODEV;
goto exit;
}
config = samsung->config;
commands = &config->commands;
loca += 1;
samsung->sabi = (samsung->f0000_segment + loca);
ifaceP = (readw(samsung->sabi + config->header_offsets.data_segment) & 0x0ffff) << 4;
ifaceP += readw(samsung->sabi + config->header_offsets.data_offset) & 0x0ffff;
if (debug)
samsung_sabi_infos(samsung, loca, ifaceP);
samsung->sabi_iface = ioremap_nocache(ifaceP, 16);
if (!samsung->sabi_iface) {
pr_err("Can't remap %x\n", ifaceP);
ret = -EINVAL;
goto exit;
}
if (commands->set_linux != 0xff) {
int retval = sabi_set_commandb(samsung,
commands->set_linux, 0x81);
if (retval) {
pr_warn("Linux mode was not set!\n");
ret = -ENODEV;
goto exit;
}
}
if (samsung->handle_backlight)
check_for_stepping_quirk(samsung);
pr_info("detected SABI interface: %s\n",
samsung->config->test_string);
exit:
if (ret)
samsung_sabi_exit(samsung);
return ret;
}
static void samsung_platform_exit(struct samsung_laptop *samsung)
{
if (samsung->platform_device) {
platform_device_unregister(samsung->platform_device);
samsung->platform_device = NULL;
}
}
static int __init samsung_platform_init(struct samsung_laptop *samsung)
{
struct platform_device *pdev;
pdev = platform_device_register_simple("samsung", -1, NULL, 0);
if (IS_ERR(pdev))
return PTR_ERR(pdev);
samsung->platform_device = pdev;
platform_set_drvdata(samsung->platform_device, samsung);
return 0;
}
static int __init samsung_dmi_matched(const struct dmi_system_id *d)
{
quirks = d->driver_data;
return 0;
}
static int __init samsung_init(void)
{
struct samsung_laptop *samsung;
int ret;
if (efi_enabled(EFI_BOOT))
return -ENODEV;
quirks = &samsung_unknown;
if (!force && !dmi_check_system(samsung_dmi_table))
return -ENODEV;
samsung = kzalloc(sizeof(*samsung), GFP_KERNEL);
if (!samsung)
return -ENOMEM;
mutex_init(&samsung->sabi_mutex);
samsung->handle_backlight = true;
samsung->quirks = quirks;
#ifdef CONFIG_ACPI
if (samsung->quirks->broken_acpi_video)
acpi_video_dmi_promote_vendor();
if (acpi_video_backlight_support()) {
samsung->handle_backlight = false;
} else if (samsung->quirks->broken_acpi_video) {
pr_info("Disabling ACPI video driver\n");
acpi_video_unregister();
}
#endif
ret = samsung_platform_init(samsung);
if (ret)
goto error_platform;
ret = samsung_sabi_init(samsung);
if (ret)
goto error_sabi;
#ifdef CONFIG_ACPI
if (acpi_video_backlight_support())
pr_info("Backlight controlled by ACPI video driver\n");
#endif
ret = samsung_sysfs_init(samsung);
if (ret)
goto error_sysfs;
ret = samsung_backlight_init(samsung);
if (ret)
goto error_backlight;
ret = samsung_rfkill_init(samsung);
if (ret)
goto error_rfkill;
ret = samsung_leds_init(samsung);
if (ret)
goto error_leds;
ret = samsung_debugfs_init(samsung);
if (ret)
goto error_debugfs;
samsung_platform_device = samsung->platform_device;
return ret;
error_debugfs:
samsung_leds_exit(samsung);
error_leds:
samsung_rfkill_exit(samsung);
error_rfkill:
samsung_backlight_exit(samsung);
error_backlight:
samsung_sysfs_exit(samsung);
error_sysfs:
samsung_sabi_exit(samsung);
error_sabi:
samsung_platform_exit(samsung);
error_platform:
kfree(samsung);
return ret;
}
static void __exit samsung_exit(void)
{
struct samsung_laptop *samsung;
samsung = platform_get_drvdata(samsung_platform_device);
samsung_debugfs_exit(samsung);
samsung_leds_exit(samsung);
samsung_rfkill_exit(samsung);
samsung_backlight_exit(samsung);
samsung_sysfs_exit(samsung);
samsung_sabi_exit(samsung);
samsung_platform_exit(samsung);
kfree(samsung);
samsung_platform_device = NULL;
}
