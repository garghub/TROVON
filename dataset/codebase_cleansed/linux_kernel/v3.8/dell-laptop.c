static int dmi_matched(const struct dmi_system_id *dmi)
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
struct calling_interface_structure *table =
container_of(dm, struct calling_interface_structure, header);
if (dm->length < 17)
return;
da_command_address = table->cmdIOAddress;
da_command_code = table->cmdIOCode;
da_tokens = krealloc(da_tokens, (da_num_tokens + tokens) *
sizeof(struct calling_interface_token),
GFP_KERNEL);
if (!da_tokens)
return;
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
return 0;
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
static int touchpad_led_init(struct device *dev)
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
if (!bufferpage)
goto fail_buffer;
buffer = page_address(bufferpage);
if (quirks && quirks->touchpad_led)
touchpad_led_init(&platform_device->dev);
dell_laptop_dir = debugfs_create_dir("dell_laptop", NULL);
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
backlight_device_unregister(dell_backlight_device);
if (platform_device) {
platform_device_unregister(platform_device);
platform_driver_unregister(&platform_driver);
}
kfree(da_tokens);
free_page((unsigned long)buffer);
}
