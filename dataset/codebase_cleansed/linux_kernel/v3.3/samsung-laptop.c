static int sabi_get_command(u8 command, struct sabi_retval *sretval)
{
int retval = 0;
u16 port = readw(sabi + sabi_config->header_offsets.port);
u8 complete, iface_data;
mutex_lock(&sabi_mutex);
outb(readb(sabi + sabi_config->header_offsets.en_mem), port);
writew(sabi_config->main_function, sabi_iface + SABI_IFACE_MAIN);
writew(command, sabi_iface + SABI_IFACE_SUB);
writeb(0, sabi_iface + SABI_IFACE_COMPLETE);
outb(readb(sabi + sabi_config->header_offsets.iface_func), port);
outb(readb(sabi + sabi_config->header_offsets.re_mem), port);
complete = readb(sabi_iface + SABI_IFACE_COMPLETE);
iface_data = readb(sabi_iface + SABI_IFACE_DATA);
if (complete != 0xaa || iface_data == 0xff) {
pr_warn("SABI get command 0x%02x failed with completion flag 0x%02x and data 0x%02x\n",
command, complete, iface_data);
retval = -EINVAL;
goto exit;
}
sretval->retval[0] = readb(sabi_iface + SABI_IFACE_DATA);
sretval->retval[1] = readb(sabi_iface + SABI_IFACE_DATA + 1);
sretval->retval[2] = readb(sabi_iface + SABI_IFACE_DATA + 2);
sretval->retval[3] = readb(sabi_iface + SABI_IFACE_DATA + 3);
exit:
mutex_unlock(&sabi_mutex);
return retval;
}
static int sabi_set_command(u8 command, u8 data)
{
int retval = 0;
u16 port = readw(sabi + sabi_config->header_offsets.port);
u8 complete, iface_data;
mutex_lock(&sabi_mutex);
outb(readb(sabi + sabi_config->header_offsets.en_mem), port);
writew(sabi_config->main_function, sabi_iface + SABI_IFACE_MAIN);
writew(command, sabi_iface + SABI_IFACE_SUB);
writeb(0, sabi_iface + SABI_IFACE_COMPLETE);
writeb(data, sabi_iface + SABI_IFACE_DATA);
outb(readb(sabi + sabi_config->header_offsets.iface_func), port);
outb(readb(sabi + sabi_config->header_offsets.re_mem), port);
complete = readb(sabi_iface + SABI_IFACE_COMPLETE);
iface_data = readb(sabi_iface + SABI_IFACE_DATA);
if (complete != 0xaa || iface_data == 0xff) {
pr_warn("SABI set command 0x%02x failed with completion flag 0x%02x and data 0x%02x\n",
command, complete, iface_data);
retval = -EINVAL;
}
mutex_unlock(&sabi_mutex);
return retval;
}
static void test_backlight(void)
{
struct sabi_retval sretval;
sabi_get_command(sabi_config->commands.get_backlight, &sretval);
printk(KERN_DEBUG "backlight = 0x%02x\n", sretval.retval[0]);
sabi_set_command(sabi_config->commands.set_backlight, 0);
printk(KERN_DEBUG "backlight should be off\n");
sabi_get_command(sabi_config->commands.get_backlight, &sretval);
printk(KERN_DEBUG "backlight = 0x%02x\n", sretval.retval[0]);
msleep(1000);
sabi_set_command(sabi_config->commands.set_backlight, 1);
printk(KERN_DEBUG "backlight should be on\n");
sabi_get_command(sabi_config->commands.get_backlight, &sretval);
printk(KERN_DEBUG "backlight = 0x%02x\n", sretval.retval[0]);
}
static void test_wireless(void)
{
struct sabi_retval sretval;
sabi_get_command(sabi_config->commands.get_wireless_button, &sretval);
printk(KERN_DEBUG "wireless led = 0x%02x\n", sretval.retval[0]);
sabi_set_command(sabi_config->commands.set_wireless_button, 0);
printk(KERN_DEBUG "wireless led should be off\n");
sabi_get_command(sabi_config->commands.get_wireless_button, &sretval);
printk(KERN_DEBUG "wireless led = 0x%02x\n", sretval.retval[0]);
msleep(1000);
sabi_set_command(sabi_config->commands.set_wireless_button, 1);
printk(KERN_DEBUG "wireless led should be on\n");
sabi_get_command(sabi_config->commands.get_wireless_button, &sretval);
printk(KERN_DEBUG "wireless led = 0x%02x\n", sretval.retval[0]);
}
static u8 read_brightness(void)
{
struct sabi_retval sretval;
int user_brightness = 0;
int retval;
retval = sabi_get_command(sabi_config->commands.get_brightness,
&sretval);
if (!retval) {
user_brightness = sretval.retval[0];
if (user_brightness > sabi_config->min_brightness)
user_brightness -= sabi_config->min_brightness;
else
user_brightness = 0;
}
return user_brightness;
}
static void set_brightness(u8 user_brightness)
{
u8 user_level = user_brightness + sabi_config->min_brightness;
if (has_stepping_quirk && user_level != 0) {
if (user_brightness == read_brightness())
return;
sabi_set_command(sabi_config->commands.set_brightness, 0);
}
sabi_set_command(sabi_config->commands.set_brightness, user_level);
}
static int get_brightness(struct backlight_device *bd)
{
return (int)read_brightness();
}
static void check_for_stepping_quirk(void)
{
u8 initial_level;
u8 check_level;
u8 orig_level = read_brightness();
if (orig_level == 0)
set_brightness(1);
initial_level = read_brightness();
if (initial_level <= 2)
check_level = initial_level + 2;
else
check_level = initial_level - 2;
has_stepping_quirk = false;
set_brightness(check_level);
if (read_brightness() != check_level) {
has_stepping_quirk = true;
pr_info("enabled workaround for brightness stepping quirk\n");
}
set_brightness(orig_level);
}
static int update_status(struct backlight_device *bd)
{
set_brightness(bd->props.brightness);
if (bd->props.power == FB_BLANK_UNBLANK)
sabi_set_command(sabi_config->commands.set_backlight, 1);
else
sabi_set_command(sabi_config->commands.set_backlight, 0);
return 0;
}
static int rfkill_set(void *data, bool blocked)
{
if (blocked)
sabi_set_command(sabi_config->commands.set_wireless_button, 0);
else
sabi_set_command(sabi_config->commands.set_wireless_button, 1);
return 0;
}
static int init_wireless(struct platform_device *sdev)
{
int retval;
rfk = rfkill_alloc("samsung-wifi", &sdev->dev, RFKILL_TYPE_WLAN,
&rfkill_ops, NULL);
if (!rfk)
return -ENOMEM;
retval = rfkill_register(rfk);
if (retval) {
rfkill_destroy(rfk);
return -ENODEV;
}
return 0;
}
static void destroy_wireless(void)
{
rfkill_unregister(rfk);
rfkill_destroy(rfk);
}
static ssize_t get_performance_level(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct sabi_retval sretval;
int retval;
int i;
retval = sabi_get_command(sabi_config->commands.get_performance_level,
&sretval);
if (retval)
return retval;
for (i = 0; sabi_config->performance_levels[i].name; ++i) {
if (sretval.retval[0] == sabi_config->performance_levels[i].value)
return sprintf(buf, "%s\n", sabi_config->performance_levels[i].name);
}
return sprintf(buf, "%s\n", "unknown");
}
static ssize_t set_performance_level(struct device *dev,
struct device_attribute *attr, const char *buf,
size_t count)
{
if (count >= 1) {
int i;
for (i = 0; sabi_config->performance_levels[i].name; ++i) {
const struct sabi_performance_level *level =
&sabi_config->performance_levels[i];
if (!strncasecmp(level->name, buf, strlen(level->name))) {
sabi_set_command(sabi_config->commands.set_performance_level,
level->value);
break;
}
}
if (!sabi_config->performance_levels[i].name)
return -EINVAL;
}
return count;
}
static int __init dmi_check_cb(const struct dmi_system_id *id)
{
pr_info("found laptop model '%s'\n",
id->ident);
return 1;
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
static int __init samsung_init(void)
{
struct backlight_properties props;
struct sabi_retval sretval;
unsigned int ifaceP;
int i;
int loca;
int retval;
mutex_init(&sabi_mutex);
if (!force && !dmi_check_system(samsung_dmi_table))
return -ENODEV;
f0000_segment = ioremap_nocache(0xf0000, 0xffff);
if (!f0000_segment) {
pr_err("Can't map the segment at 0xf0000\n");
return -EINVAL;
}
for (i = 0; sabi_configs[i].test_string != 0; ++i) {
sabi_config = &sabi_configs[i];
loca = find_signature(f0000_segment, sabi_config->test_string);
if (loca != 0xffff)
break;
}
if (loca == 0xffff) {
pr_err("This computer does not support SABI\n");
goto error_no_signature;
}
loca += 1;
sabi = (f0000_segment + loca);
if (debug) {
printk(KERN_DEBUG "This computer supports SABI==%x\n",
loca + 0xf0000 - 6);
printk(KERN_DEBUG "SABI header:\n");
printk(KERN_DEBUG " SMI Port Number = 0x%04x\n",
readw(sabi + sabi_config->header_offsets.port));
printk(KERN_DEBUG " SMI Interface Function = 0x%02x\n",
readb(sabi + sabi_config->header_offsets.iface_func));
printk(KERN_DEBUG " SMI enable memory buffer = 0x%02x\n",
readb(sabi + sabi_config->header_offsets.en_mem));
printk(KERN_DEBUG " SMI restore memory buffer = 0x%02x\n",
readb(sabi + sabi_config->header_offsets.re_mem));
printk(KERN_DEBUG " SABI data offset = 0x%04x\n",
readw(sabi + sabi_config->header_offsets.data_offset));
printk(KERN_DEBUG " SABI data segment = 0x%04x\n",
readw(sabi + sabi_config->header_offsets.data_segment));
}
ifaceP = (readw(sabi + sabi_config->header_offsets.data_segment) & 0x0ffff) << 4;
ifaceP += readw(sabi + sabi_config->header_offsets.data_offset) & 0x0ffff;
sabi_iface = ioremap_nocache(ifaceP, 16);
if (!sabi_iface) {
pr_err("Can't remap %x\n", ifaceP);
goto error_no_signature;
}
if (debug) {
printk(KERN_DEBUG "ifaceP = 0x%08x\n", ifaceP);
printk(KERN_DEBUG "sabi_iface = %p\n", sabi_iface);
test_backlight();
test_wireless();
retval = sabi_get_command(sabi_config->commands.get_brightness,
&sretval);
printk(KERN_DEBUG "brightness = 0x%02x\n", sretval.retval[0]);
}
if (sabi_config->commands.set_linux != 0xff) {
retval = sabi_set_command(sabi_config->commands.set_linux,
0x81);
if (retval) {
pr_warn("Linux mode was not set!\n");
goto error_no_platform;
}
}
check_for_stepping_quirk();
sdev = platform_device_register_simple("samsung", -1, NULL, 0);
if (IS_ERR(sdev))
goto error_no_platform;
memset(&props, 0, sizeof(struct backlight_properties));
props.type = BACKLIGHT_PLATFORM;
props.max_brightness = sabi_config->max_brightness -
sabi_config->min_brightness;
backlight_device = backlight_device_register("samsung", &sdev->dev,
NULL, &backlight_ops,
&props);
if (IS_ERR(backlight_device))
goto error_no_backlight;
backlight_device->props.brightness = read_brightness();
backlight_device->props.power = FB_BLANK_UNBLANK;
backlight_update_status(backlight_device);
retval = init_wireless(sdev);
if (retval)
goto error_no_rfk;
retval = device_create_file(&sdev->dev, &dev_attr_performance_level);
if (retval)
goto error_file_create;
return 0;
error_file_create:
destroy_wireless();
error_no_rfk:
backlight_device_unregister(backlight_device);
error_no_backlight:
platform_device_unregister(sdev);
error_no_platform:
iounmap(sabi_iface);
error_no_signature:
iounmap(f0000_segment);
return -EINVAL;
}
static void __exit samsung_exit(void)
{
if (sabi_config->commands.set_linux != 0xff)
sabi_set_command(sabi_config->commands.set_linux, 0x80);
device_remove_file(&sdev->dev, &dev_attr_performance_level);
backlight_device_unregister(backlight_device);
destroy_wireless();
iounmap(sabi_iface);
iounmap(f0000_segment);
platform_device_unregister(sdev);
}
