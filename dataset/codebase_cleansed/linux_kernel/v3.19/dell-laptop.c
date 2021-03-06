static int __init dmi_matched(const struct dmi_system_id *dmi)
{
quirks = dmi->driver_data;
return 1;
}
static void get_buffer(void)
{
mutex_lock(&buffer_mutex);
memset(buffer, 0, sizeof(struct calling_interface_buffer));
}
static void release_buffer(void)
{
mutex_unlock(&buffer_mutex);
}
static void __init parse_da_table(const struct dmi_header *dm)
{
int tokens = (dm->length-11)/sizeof(struct calling_interface_token)-1;
struct calling_interface_token *new_da_tokens;
struct calling_interface_structure *table =
container_of(dm, struct calling_interface_structure, header);
if (dm->length < 17)
return;
da_command_address = table->cmdIOAddress;
da_command_code = table->cmdIOCode;
new_da_tokens = krealloc(da_tokens, (da_num_tokens + tokens) *
sizeof(struct calling_interface_token),
GFP_KERNEL);
if (!new_da_tokens)
return;
da_tokens = new_da_tokens;
memcpy(da_tokens+da_num_tokens, table->tokens,
sizeof(struct calling_interface_token) * tokens);
da_num_tokens += tokens;
}
static void __init find_tokens(const struct dmi_header *dm, void *dummy)
{
switch (dm->type) {
case 0xd4:
case 0xd5:
case 0xd6:
break;
case 0xda:
parse_da_table(dm);
break;
}
}
static int find_token_location(int tokenid)
{
int i;
for (i = 0; i < da_num_tokens; i++) {
if (da_tokens[i].tokenID == tokenid)
return da_tokens[i].location;
}
return -1;
}
static struct calling_interface_buffer *
dell_send_request(struct calling_interface_buffer *buffer, int class,
int select)
{
struct smi_cmd command;
command.magic = SMI_CMD_MAGIC;
command.command_address = da_command_address;
command.command_code = da_command_code;
command.ebx = virt_to_phys(buffer);
command.ecx = 0x42534931;
buffer->class = class;
buffer->select = select;
dcdbas_smi_request(&command);
return buffer;
}
static int dell_rfkill_set(void *data, bool blocked)
{
int disable = blocked ? 1 : 0;
unsigned long radio = (unsigned long)data;
int hwswitch_bit = (unsigned long)data - 1;
get_buffer();
dell_send_request(buffer, 17, 11);
if ((hwswitch_state & BIT(hwswitch_bit)) &&
!(buffer->output[1] & BIT(16)))
disable = 1;
buffer->input[0] = (1 | (radio<<8) | (disable << 16));
dell_send_request(buffer, 17, 11);
release_buffer();
return 0;
}
static void dell_rfkill_update_sw_state(struct rfkill *rfkill, int radio,
int status)
{
if (status & BIT(0)) {
int block = rfkill_blocked(rfkill);
buffer->input[0] = (1 | (radio << 8) | (block << 16));
dell_send_request(buffer, 17, 11);
} else {
rfkill_set_sw_state(rfkill, !!(status & BIT(radio + 16)));
}
}
static void dell_rfkill_update_hw_state(struct rfkill *rfkill, int radio,
int status)
{
if (hwswitch_state & (BIT(radio - 1)))
rfkill_set_hw_state(rfkill, !(status & BIT(16)));
}
static void dell_rfkill_query(struct rfkill *rfkill, void *data)
{
int status;
get_buffer();
dell_send_request(buffer, 17, 11);
status = buffer->output[1];
dell_rfkill_update_hw_state(rfkill, (unsigned long)data, status);
release_buffer();
}
static int dell_debugfs_show(struct seq_file *s, void *data)
{
int status;
get_buffer();
dell_send_request(buffer, 17, 11);
status = buffer->output[1];
release_buffer();
seq_printf(s, "status:\t0x%X\n", status);
seq_printf(s, "Bit 0 : Hardware switch supported: %lu\n",
status & BIT(0));
seq_printf(s, "Bit 1 : Wifi locator supported: %lu\n",
(status & BIT(1)) >> 1);
seq_printf(s, "Bit 2 : Wifi is supported: %lu\n",
(status & BIT(2)) >> 2);
seq_printf(s, "Bit 3 : Bluetooth is supported: %lu\n",
(status & BIT(3)) >> 3);
seq_printf(s, "Bit 4 : WWAN is supported: %lu\n",
(status & BIT(4)) >> 4);
seq_printf(s, "Bit 5 : Wireless keyboard supported: %lu\n",
(status & BIT(5)) >> 5);
seq_printf(s, "Bit 8 : Wifi is installed: %lu\n",
(status & BIT(8)) >> 8);
seq_printf(s, "Bit 9 : Bluetooth is installed: %lu\n",
(status & BIT(9)) >> 9);
seq_printf(s, "Bit 10: WWAN is installed: %lu\n",
(status & BIT(10)) >> 10);
seq_printf(s, "Bit 16: Hardware switch is on: %lu\n",
(status & BIT(16)) >> 16);
seq_printf(s, "Bit 17: Wifi is blocked: %lu\n",
(status & BIT(17)) >> 17);
seq_printf(s, "Bit 18: Bluetooth is blocked: %lu\n",
(status & BIT(18)) >> 18);
seq_printf(s, "Bit 19: WWAN is blocked: %lu\n",
(status & BIT(19)) >> 19);
seq_printf(s, "\nhwswitch_state:\t0x%X\n", hwswitch_state);
seq_printf(s, "Bit 0 : Wifi controlled by switch: %lu\n",
hwswitch_state & BIT(0));
seq_printf(s, "Bit 1 : Bluetooth controlled by switch: %lu\n",
(hwswitch_state & BIT(1)) >> 1);
seq_printf(s, "Bit 2 : WWAN controlled by switch: %lu\n",
(hwswitch_state & BIT(2)) >> 2);
seq_printf(s, "Bit 7 : Wireless switch config locked: %lu\n",
(hwswitch_state & BIT(7)) >> 7);
seq_printf(s, "Bit 8 : Wifi locator enabled: %lu\n",
(hwswitch_state & BIT(8)) >> 8);
seq_printf(s, "Bit 15: Wifi locator setting locked: %lu\n",
(hwswitch_state & BIT(15)) >> 15);
return 0;
}
static int dell_debugfs_open(struct inode *inode, struct file *file)
{
return single_open(file, dell_debugfs_show, inode->i_private);
}
static void dell_update_rfkill(struct work_struct *ignored)
{
int status;
get_buffer();
dell_send_request(buffer, 17, 11);
status = buffer->output[1];
if (wifi_rfkill) {
dell_rfkill_update_hw_state(wifi_rfkill, 1, status);
dell_rfkill_update_sw_state(wifi_rfkill, 1, status);
}
if (bluetooth_rfkill) {
dell_rfkill_update_hw_state(bluetooth_rfkill, 2, status);
dell_rfkill_update_sw_state(bluetooth_rfkill, 2, status);
}
if (wwan_rfkill) {
dell_rfkill_update_hw_state(wwan_rfkill, 3, status);
dell_rfkill_update_sw_state(wwan_rfkill, 3, status);
}
release_buffer();
}
static bool dell_laptop_i8042_filter(unsigned char data, unsigned char str,
struct serio *port)
{
static bool extended;
if (str & I8042_STR_AUXDATA)
return false;
if (unlikely(data == 0xe0)) {
extended = true;
return false;
} else if (unlikely(extended)) {
switch (data) {
case 0x8:
schedule_delayed_work(&dell_rfkill_work,
round_jiffies_relative(HZ / 4));
break;
}
extended = false;
}
return false;
}
static int __init dell_setup_rfkill(void)
{
int status, ret, whitelisted;
const char *product;
whitelisted = 0;
product = dmi_get_system_info(DMI_PRODUCT_NAME);
if (product && (strncmp(product, "Latitude", 8) == 0 ||
strncmp(product, "Precision", 9) == 0))
whitelisted = 1;
if (!force_rfkill && !whitelisted)
return 0;
get_buffer();
dell_send_request(buffer, 17, 11);
status = buffer->output[1];
buffer->input[0] = 0x2;
dell_send_request(buffer, 17, 11);
hwswitch_state = buffer->output[1];
release_buffer();
if (!(status & BIT(0))) {
if (force_rfkill) {
hwswitch_state &= ~7;
} else {
return 0;
}
}
if ((status & (1<<2|1<<8)) == (1<<2|1<<8)) {
wifi_rfkill = rfkill_alloc("dell-wifi", &platform_device->dev,
RFKILL_TYPE_WLAN,
&dell_rfkill_ops, (void *) 1);
if (!wifi_rfkill) {
ret = -ENOMEM;
goto err_wifi;
}
ret = rfkill_register(wifi_rfkill);
if (ret)
goto err_wifi;
}
if ((status & (1<<3|1<<9)) == (1<<3|1<<9)) {
bluetooth_rfkill = rfkill_alloc("dell-bluetooth",
&platform_device->dev,
RFKILL_TYPE_BLUETOOTH,
&dell_rfkill_ops, (void *) 2);
if (!bluetooth_rfkill) {
ret = -ENOMEM;
goto err_bluetooth;
}
ret = rfkill_register(bluetooth_rfkill);
if (ret)
goto err_bluetooth;
}
if ((status & (1<<4|1<<10)) == (1<<4|1<<10)) {
wwan_rfkill = rfkill_alloc("dell-wwan",
&platform_device->dev,
RFKILL_TYPE_WWAN,
&dell_rfkill_ops, (void *) 3);
if (!wwan_rfkill) {
ret = -ENOMEM;
goto err_wwan;
}
ret = rfkill_register(wwan_rfkill);
if (ret)
goto err_wwan;
}
ret = i8042_install_filter(dell_laptop_i8042_filter);
if (ret) {
pr_warn("Unable to install key filter\n");
goto err_filter;
}
return 0;
err_filter:
if (wwan_rfkill)
rfkill_unregister(wwan_rfkill);
err_wwan:
rfkill_destroy(wwan_rfkill);
if (bluetooth_rfkill)
rfkill_unregister(bluetooth_rfkill);
err_bluetooth:
rfkill_destroy(bluetooth_rfkill);
if (wifi_rfkill)
rfkill_unregister(wifi_rfkill);
err_wifi:
rfkill_destroy(wifi_rfkill);
return ret;
}
static void dell_cleanup_rfkill(void)
{
if (wifi_rfkill) {
rfkill_unregister(wifi_rfkill);
rfkill_destroy(wifi_rfkill);
}
if (bluetooth_rfkill) {
rfkill_unregister(bluetooth_rfkill);
rfkill_destroy(bluetooth_rfkill);
}
if (wwan_rfkill) {
rfkill_unregister(wwan_rfkill);
rfkill_destroy(wwan_rfkill);
}
}
static int dell_send_intensity(struct backlight_device *bd)
{
int ret = 0;
get_buffer();
buffer->input[0] = find_token_location(BRIGHTNESS_TOKEN);
buffer->input[1] = bd->props.brightness;
if (buffer->input[0] == -1) {
ret = -ENODEV;
goto out;
}
if (power_supply_is_system_supplied() > 0)
dell_send_request(buffer, 1, 2);
else
dell_send_request(buffer, 1, 1);
out:
release_buffer();
return ret;
}
static int dell_get_intensity(struct backlight_device *bd)
{
int ret = 0;
get_buffer();
buffer->input[0] = find_token_location(BRIGHTNESS_TOKEN);
if (buffer->input[0] == -1) {
ret = -ENODEV;
goto out;
}
if (power_supply_is_system_supplied() > 0)
dell_send_request(buffer, 0, 2);
else
dell_send_request(buffer, 0, 1);
ret = buffer->output[1];
out:
release_buffer();
return ret;
}
static void touchpad_led_on(void)
{
int command = 0x97;
char data = 1;
i8042_command(&data, command | 1 << 12);
}
static void touchpad_led_off(void)
{
int command = 0x97;
char data = 2;
i8042_command(&data, command | 1 << 12);
}
static void touchpad_led_set(struct led_classdev *led_cdev,
enum led_brightness value)
{
if (value > 0)
touchpad_led_on();
else
touchpad_led_off();
}
static int __init touchpad_led_init(struct device *dev)
{
return led_classdev_register(dev, &touchpad_led);
}
static void touchpad_led_exit(void)
{
led_classdev_unregister(&touchpad_led);
}
static int __init dell_init(void)
{
int max_intensity = 0;
int ret;
if (!dmi_check_system(dell_device_table))
return -ENODEV;
quirks = NULL;
dmi_check_system(dell_quirks);
dmi_walk(find_tokens, NULL);
if (!da_tokens) {
pr_info("Unable to find dmi tokens\n");
return -ENODEV;
}
ret = platform_driver_register(&platform_driver);
if (ret)
goto fail_platform_driver;
platform_device = platform_device_alloc("dell-laptop", -1);
if (!platform_device) {
ret = -ENOMEM;
goto fail_platform_device1;
}
ret = platform_device_add(platform_device);
if (ret)
goto fail_platform_device2;
bufferpage = alloc_page(GFP_KERNEL | GFP_DMA32);
if (!bufferpage) {
ret = -ENOMEM;
goto fail_buffer;
}
buffer = page_address(bufferpage);
ret = dell_setup_rfkill();
if (ret) {
pr_warn("Unable to setup rfkill\n");
goto fail_rfkill;
}
if (quirks && quirks->touchpad_led)
touchpad_led_init(&platform_device->dev);
dell_laptop_dir = debugfs_create_dir("dell_laptop", NULL);
if (dell_laptop_dir != NULL)
debugfs_create_file("rfkill", 0444, dell_laptop_dir, NULL,
&dell_debugfs_fops);
#ifdef CONFIG_ACPI
if (acpi_video_backlight_support())
return 0;
#endif
get_buffer();
buffer->input[0] = find_token_location(BRIGHTNESS_TOKEN);
if (buffer->input[0] != -1) {
dell_send_request(buffer, 0, 2);
max_intensity = buffer->output[3];
}
release_buffer();
if (max_intensity) {
struct backlight_properties props;
memset(&props, 0, sizeof(struct backlight_properties));
props.type = BACKLIGHT_PLATFORM;
props.max_brightness = max_intensity;
dell_backlight_device = backlight_device_register("dell_backlight",
&platform_device->dev,
NULL,
&dell_ops,
&props);
if (IS_ERR(dell_backlight_device)) {
ret = PTR_ERR(dell_backlight_device);
dell_backlight_device = NULL;
goto fail_backlight;
}
dell_backlight_device->props.brightness =
dell_get_intensity(dell_backlight_device);
backlight_update_status(dell_backlight_device);
}
return 0;
fail_backlight:
i8042_remove_filter(dell_laptop_i8042_filter);
cancel_delayed_work_sync(&dell_rfkill_work);
dell_cleanup_rfkill();
fail_rfkill:
free_page((unsigned long)bufferpage);
fail_buffer:
platform_device_del(platform_device);
fail_platform_device2:
platform_device_put(platform_device);
fail_platform_device1:
platform_driver_unregister(&platform_driver);
fail_platform_driver:
kfree(da_tokens);
return ret;
}
static void __exit dell_exit(void)
{
debugfs_remove_recursive(dell_laptop_dir);
if (quirks && quirks->touchpad_led)
touchpad_led_exit();
i8042_remove_filter(dell_laptop_i8042_filter);
cancel_delayed_work_sync(&dell_rfkill_work);
backlight_device_unregister(dell_backlight_device);
dell_cleanup_rfkill();
if (platform_device) {
platform_device_unregister(platform_device);
platform_driver_unregister(&platform_driver);
}
kfree(da_tokens);
free_page((unsigned long)buffer);
}
