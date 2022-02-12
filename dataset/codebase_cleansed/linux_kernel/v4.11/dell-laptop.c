static int __init dmi_matched(const struct dmi_system_id *dmi)
{
quirks = dmi->driver_data;
return 1;
}
static int dell_rfkill_set(void *data, bool blocked)
{
struct calling_interface_buffer *buffer;
int disable = blocked ? 1 : 0;
unsigned long radio = (unsigned long)data;
int hwswitch_bit = (unsigned long)data - 1;
int hwswitch;
int status;
int ret;
buffer = dell_smbios_get_buffer();
dell_smbios_send_request(17, 11);
ret = buffer->output[0];
status = buffer->output[1];
if (ret != 0)
goto out;
dell_smbios_clear_buffer();
buffer->input[0] = 0x2;
dell_smbios_send_request(17, 11);
ret = buffer->output[0];
hwswitch = buffer->output[1];
if (ret == 0 && (hwswitch & BIT(hwswitch_bit)) &&
(status & BIT(0)) && !(status & BIT(16)))
disable = 1;
dell_smbios_clear_buffer();
buffer->input[0] = (1 | (radio<<8) | (disable << 16));
dell_smbios_send_request(17, 11);
ret = buffer->output[0];
out:
dell_smbios_release_buffer();
return dell_smbios_error(ret);
}
static void dell_rfkill_update_sw_state(struct rfkill *rfkill, int radio,
int status,
struct calling_interface_buffer *buffer)
{
if (status & BIT(0)) {
int block = rfkill_blocked(rfkill);
dell_smbios_clear_buffer();
buffer->input[0] = (1 | (radio << 8) | (block << 16));
dell_smbios_send_request(17, 11);
} else {
rfkill_set_sw_state(rfkill, !!(status & BIT(radio + 16)));
}
}
static void dell_rfkill_update_hw_state(struct rfkill *rfkill, int radio,
int status, int hwswitch)
{
if (hwswitch & (BIT(radio - 1)))
rfkill_set_hw_state(rfkill, !(status & BIT(16)));
}
static void dell_rfkill_query(struct rfkill *rfkill, void *data)
{
struct calling_interface_buffer *buffer;
int radio = ((unsigned long)data & 0xF);
int hwswitch;
int status;
int ret;
buffer = dell_smbios_get_buffer();
dell_smbios_send_request(17, 11);
ret = buffer->output[0];
status = buffer->output[1];
if (ret != 0 || !(status & BIT(0))) {
dell_smbios_release_buffer();
return;
}
dell_smbios_clear_buffer();
buffer->input[0] = 0x2;
dell_smbios_send_request(17, 11);
ret = buffer->output[0];
hwswitch = buffer->output[1];
dell_smbios_release_buffer();
if (ret != 0)
return;
dell_rfkill_update_hw_state(rfkill, radio, status, hwswitch);
}
static int dell_debugfs_show(struct seq_file *s, void *data)
{
struct calling_interface_buffer *buffer;
int hwswitch_state;
int hwswitch_ret;
int status;
int ret;
buffer = dell_smbios_get_buffer();
dell_smbios_send_request(17, 11);
ret = buffer->output[0];
status = buffer->output[1];
dell_smbios_clear_buffer();
buffer->input[0] = 0x2;
dell_smbios_send_request(17, 11);
hwswitch_ret = buffer->output[0];
hwswitch_state = buffer->output[1];
dell_smbios_release_buffer();
seq_printf(s, "return:\t%d\n", ret);
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
seq_printf(s, "Bit 6 : UWB supported: %lu\n",
(status & BIT(6)) >> 6);
seq_printf(s, "Bit 7 : WiGig supported: %lu\n",
(status & BIT(7)) >> 7);
seq_printf(s, "Bit 8 : Wifi is installed: %lu\n",
(status & BIT(8)) >> 8);
seq_printf(s, "Bit 9 : Bluetooth is installed: %lu\n",
(status & BIT(9)) >> 9);
seq_printf(s, "Bit 10: WWAN is installed: %lu\n",
(status & BIT(10)) >> 10);
seq_printf(s, "Bit 11: UWB installed: %lu\n",
(status & BIT(11)) >> 11);
seq_printf(s, "Bit 12: WiGig installed: %lu\n",
(status & BIT(12)) >> 12);
seq_printf(s, "Bit 16: Hardware switch is on: %lu\n",
(status & BIT(16)) >> 16);
seq_printf(s, "Bit 17: Wifi is blocked: %lu\n",
(status & BIT(17)) >> 17);
seq_printf(s, "Bit 18: Bluetooth is blocked: %lu\n",
(status & BIT(18)) >> 18);
seq_printf(s, "Bit 19: WWAN is blocked: %lu\n",
(status & BIT(19)) >> 19);
seq_printf(s, "Bit 20: UWB is blocked: %lu\n",
(status & BIT(20)) >> 20);
seq_printf(s, "Bit 21: WiGig is blocked: %lu\n",
(status & BIT(21)) >> 21);
seq_printf(s, "\nhwswitch_return:\t%d\n", hwswitch_ret);
seq_printf(s, "hwswitch_state:\t0x%X\n", hwswitch_state);
seq_printf(s, "Bit 0 : Wifi controlled by switch: %lu\n",
hwswitch_state & BIT(0));
seq_printf(s, "Bit 1 : Bluetooth controlled by switch: %lu\n",
(hwswitch_state & BIT(1)) >> 1);
seq_printf(s, "Bit 2 : WWAN controlled by switch: %lu\n",
(hwswitch_state & BIT(2)) >> 2);
seq_printf(s, "Bit 3 : UWB controlled by switch: %lu\n",
(hwswitch_state & BIT(3)) >> 3);
seq_printf(s, "Bit 4 : WiGig controlled by switch: %lu\n",
(hwswitch_state & BIT(4)) >> 4);
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
struct calling_interface_buffer *buffer;
int hwswitch = 0;
int status;
int ret;
buffer = dell_smbios_get_buffer();
dell_smbios_send_request(17, 11);
ret = buffer->output[0];
status = buffer->output[1];
if (ret != 0)
goto out;
dell_smbios_clear_buffer();
buffer->input[0] = 0x2;
dell_smbios_send_request(17, 11);
ret = buffer->output[0];
if (ret == 0 && (status & BIT(0)))
hwswitch = buffer->output[1];
if (wifi_rfkill) {
dell_rfkill_update_hw_state(wifi_rfkill, 1, status, hwswitch);
dell_rfkill_update_sw_state(wifi_rfkill, 1, status, buffer);
}
if (bluetooth_rfkill) {
dell_rfkill_update_hw_state(bluetooth_rfkill, 2, status,
hwswitch);
dell_rfkill_update_sw_state(bluetooth_rfkill, 2, status,
buffer);
}
if (wwan_rfkill) {
dell_rfkill_update_hw_state(wwan_rfkill, 3, status, hwswitch);
dell_rfkill_update_sw_state(wwan_rfkill, 3, status, buffer);
}
out:
dell_smbios_release_buffer();
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
static int dell_laptop_rbtn_notifier_call(struct notifier_block *nb,
unsigned long action, void *data)
{
schedule_delayed_work(&dell_rfkill_work, 0);
return NOTIFY_OK;
}
static int __init dell_setup_rfkill(void)
{
struct calling_interface_buffer *buffer;
int status, ret, whitelisted;
const char *product;
whitelisted = 0;
product = dmi_get_system_info(DMI_PRODUCT_NAME);
if (product && (strncmp(product, "Latitude", 8) == 0 ||
strncmp(product, "Precision", 9) == 0))
whitelisted = 1;
if (!force_rfkill && !whitelisted)
return 0;
buffer = dell_smbios_get_buffer();
dell_smbios_send_request(17, 11);
ret = buffer->output[0];
status = buffer->output[1];
dell_smbios_release_buffer();
if (ret != 0)
return 0;
if (!(status & BIT(0)) && !force_rfkill)
return 0;
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
dell_rbtn_notifier_register_func =
symbol_request(dell_rbtn_notifier_register);
if (dell_rbtn_notifier_register_func) {
dell_rbtn_notifier_unregister_func =
symbol_request(dell_rbtn_notifier_unregister);
if (!dell_rbtn_notifier_unregister_func) {
symbol_put(dell_rbtn_notifier_register);
dell_rbtn_notifier_register_func = NULL;
}
}
if (dell_rbtn_notifier_register_func) {
ret = dell_rbtn_notifier_register_func(
&dell_laptop_rbtn_notifier);
symbol_put(dell_rbtn_notifier_register);
dell_rbtn_notifier_register_func = NULL;
if (ret != 0) {
symbol_put(dell_rbtn_notifier_unregister);
dell_rbtn_notifier_unregister_func = NULL;
}
} else {
pr_info("Symbols from dell-rbtn acpi driver are not available\n");
ret = -ENODEV;
}
if (ret == 0) {
pr_info("Using dell-rbtn acpi driver for receiving events\n");
} else if (ret != -ENODEV) {
pr_warn("Unable to register dell rbtn notifier\n");
goto err_filter;
} else {
ret = i8042_install_filter(dell_laptop_i8042_filter);
if (ret) {
pr_warn("Unable to install key filter\n");
goto err_filter;
}
pr_info("Using i8042 filter function for receiving events\n");
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
if (dell_rbtn_notifier_unregister_func) {
dell_rbtn_notifier_unregister_func(&dell_laptop_rbtn_notifier);
symbol_put(dell_rbtn_notifier_unregister);
dell_rbtn_notifier_unregister_func = NULL;
} else {
i8042_remove_filter(dell_laptop_i8042_filter);
}
cancel_delayed_work_sync(&dell_rfkill_work);
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
struct calling_interface_buffer *buffer;
struct calling_interface_token *token;
int ret;
token = dell_smbios_find_token(BRIGHTNESS_TOKEN);
if (!token)
return -ENODEV;
buffer = dell_smbios_get_buffer();
buffer->input[0] = token->location;
buffer->input[1] = bd->props.brightness;
if (power_supply_is_system_supplied() > 0)
dell_smbios_send_request(1, 2);
else
dell_smbios_send_request(1, 1);
ret = dell_smbios_error(buffer->output[0]);
dell_smbios_release_buffer();
return ret;
}
static int dell_get_intensity(struct backlight_device *bd)
{
struct calling_interface_buffer *buffer;
struct calling_interface_token *token;
int ret;
token = dell_smbios_find_token(BRIGHTNESS_TOKEN);
if (!token)
return -ENODEV;
buffer = dell_smbios_get_buffer();
buffer->input[0] = token->location;
if (power_supply_is_system_supplied() > 0)
dell_smbios_send_request(0, 2);
else
dell_smbios_send_request(0, 1);
if (buffer->output[0])
ret = dell_smbios_error(buffer->output[0]);
else
ret = buffer->output[1];
dell_smbios_release_buffer();
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
static int kbd_get_info(struct kbd_info *info)
{
struct calling_interface_buffer *buffer;
u8 units;
int ret;
buffer = dell_smbios_get_buffer();
buffer->input[0] = 0x0;
dell_smbios_send_request(4, 11);
ret = buffer->output[0];
if (ret) {
ret = dell_smbios_error(ret);
goto out;
}
info->modes = buffer->output[1] & 0xFFFF;
info->type = (buffer->output[1] >> 24) & 0xFF;
info->triggers = buffer->output[2] & 0xFF;
units = (buffer->output[2] >> 8) & 0xFF;
info->levels = (buffer->output[2] >> 16) & 0xFF;
if (units & BIT(0))
info->seconds = (buffer->output[3] >> 0) & 0xFF;
if (units & BIT(1))
info->minutes = (buffer->output[3] >> 8) & 0xFF;
if (units & BIT(2))
info->hours = (buffer->output[3] >> 16) & 0xFF;
if (units & BIT(3))
info->days = (buffer->output[3] >> 24) & 0xFF;
out:
dell_smbios_release_buffer();
return ret;
}
static unsigned int kbd_get_max_level(void)
{
if (kbd_info.levels != 0)
return kbd_info.levels;
if (kbd_mode_levels_count > 0)
return kbd_mode_levels_count - 1;
return 0;
}
static int kbd_get_level(struct kbd_state *state)
{
int i;
if (kbd_info.levels != 0)
return state->level;
if (kbd_mode_levels_count > 0) {
for (i = 0; i < kbd_mode_levels_count; ++i)
if (kbd_mode_levels[i] == state->mode_bit)
return i;
return 0;
}
return -EINVAL;
}
static int kbd_set_level(struct kbd_state *state, u8 level)
{
if (kbd_info.levels != 0) {
if (level != 0)
kbd_previous_level = level;
if (state->level == level)
return 0;
state->level = level;
if (level != 0 && state->mode_bit == KBD_MODE_BIT_OFF)
state->mode_bit = kbd_previous_mode_bit;
else if (level == 0 && state->mode_bit != KBD_MODE_BIT_OFF) {
kbd_previous_mode_bit = state->mode_bit;
state->mode_bit = KBD_MODE_BIT_OFF;
}
return 0;
}
if (kbd_mode_levels_count > 0 && level < kbd_mode_levels_count) {
if (level != 0)
kbd_previous_level = level;
state->mode_bit = kbd_mode_levels[level];
return 0;
}
return -EINVAL;
}
static int kbd_get_state(struct kbd_state *state)
{
struct calling_interface_buffer *buffer;
int ret;
buffer = dell_smbios_get_buffer();
buffer->input[0] = 0x1;
dell_smbios_send_request(4, 11);
ret = buffer->output[0];
if (ret) {
ret = dell_smbios_error(ret);
goto out;
}
state->mode_bit = ffs(buffer->output[1] & 0xFFFF);
if (state->mode_bit != 0)
state->mode_bit--;
state->triggers = (buffer->output[1] >> 16) & 0xFF;
state->timeout_value = (buffer->output[1] >> 24) & 0x3F;
state->timeout_unit = (buffer->output[1] >> 30) & 0x3;
state->als_setting = buffer->output[2] & 0xFF;
state->als_value = (buffer->output[2] >> 8) & 0xFF;
state->level = (buffer->output[2] >> 16) & 0xFF;
out:
dell_smbios_release_buffer();
return ret;
}
static int kbd_set_state(struct kbd_state *state)
{
struct calling_interface_buffer *buffer;
int ret;
buffer = dell_smbios_get_buffer();
buffer->input[0] = 0x2;
buffer->input[1] = BIT(state->mode_bit) & 0xFFFF;
buffer->input[1] |= (state->triggers & 0xFF) << 16;
buffer->input[1] |= (state->timeout_value & 0x3F) << 24;
buffer->input[1] |= (state->timeout_unit & 0x3) << 30;
buffer->input[2] = state->als_setting & 0xFF;
buffer->input[2] |= (state->level & 0xFF) << 16;
dell_smbios_send_request(4, 11);
ret = buffer->output[0];
dell_smbios_release_buffer();
return dell_smbios_error(ret);
}
static int kbd_set_state_safe(struct kbd_state *state, struct kbd_state *old)
{
int ret;
ret = kbd_set_state(state);
if (ret == 0)
return 0;
if (kbd_set_state(old))
pr_err("Setting old previous keyboard state failed\n");
return ret;
}
static int kbd_set_token_bit(u8 bit)
{
struct calling_interface_buffer *buffer;
struct calling_interface_token *token;
int ret;
if (bit >= ARRAY_SIZE(kbd_tokens))
return -EINVAL;
token = dell_smbios_find_token(kbd_tokens[bit]);
if (!token)
return -EINVAL;
buffer = dell_smbios_get_buffer();
buffer->input[0] = token->location;
buffer->input[1] = token->value;
dell_smbios_send_request(1, 0);
ret = buffer->output[0];
dell_smbios_release_buffer();
return dell_smbios_error(ret);
}
static int kbd_get_token_bit(u8 bit)
{
struct calling_interface_buffer *buffer;
struct calling_interface_token *token;
int ret;
int val;
if (bit >= ARRAY_SIZE(kbd_tokens))
return -EINVAL;
token = dell_smbios_find_token(kbd_tokens[bit]);
if (!token)
return -EINVAL;
buffer = dell_smbios_get_buffer();
buffer->input[0] = token->location;
dell_smbios_send_request(0, 0);
ret = buffer->output[0];
val = buffer->output[1];
dell_smbios_release_buffer();
if (ret)
return dell_smbios_error(ret);
return (val == token->value);
}
static int kbd_get_first_active_token_bit(void)
{
int i;
int ret;
for (i = 0; i < ARRAY_SIZE(kbd_tokens); ++i) {
ret = kbd_get_token_bit(i);
if (ret == 1)
return i;
}
return ret;
}
static int kbd_get_valid_token_counts(void)
{
return hweight16(kbd_token_bits);
}
static inline int kbd_init_info(void)
{
struct kbd_state state;
int ret;
int i;
ret = kbd_get_info(&kbd_info);
if (ret)
return ret;
kbd_get_state(&state);
if (kbd_info.seconds > 63)
kbd_info.seconds = 63;
if (kbd_info.minutes > 63)
kbd_info.minutes = 63;
if (kbd_info.hours > 63)
kbd_info.hours = 63;
if (kbd_info.days > 63)
kbd_info.days = 63;
kbd_info.modes &= ~BIT(KBD_MODE_BIT_ON);
kbd_previous_level = kbd_get_level(&state);
kbd_previous_mode_bit = state.mode_bit;
if (kbd_previous_level == 0 && kbd_get_max_level() != 0)
kbd_previous_level = 1;
if (kbd_previous_mode_bit == KBD_MODE_BIT_OFF) {
kbd_previous_mode_bit =
ffs(kbd_info.modes & ~BIT(KBD_MODE_BIT_OFF));
if (kbd_previous_mode_bit != 0)
kbd_previous_mode_bit--;
}
if (kbd_info.modes & (BIT(KBD_MODE_BIT_ALS) |
BIT(KBD_MODE_BIT_TRIGGER_ALS)))
kbd_als_supported = true;
if (kbd_info.modes & (
BIT(KBD_MODE_BIT_TRIGGER_ALS) | BIT(KBD_MODE_BIT_TRIGGER) |
BIT(KBD_MODE_BIT_TRIGGER_25) | BIT(KBD_MODE_BIT_TRIGGER_50) |
BIT(KBD_MODE_BIT_TRIGGER_75) | BIT(KBD_MODE_BIT_TRIGGER_100)
))
kbd_triggers_supported = true;
for (i = 0; i < 16; ++i)
if (kbd_is_level_mode_bit(i) && (BIT(i) & kbd_info.modes))
kbd_mode_levels[1 + kbd_mode_levels_count++] = i;
if (kbd_mode_levels_count > 0) {
for (i = 0; i < 16; ++i) {
if (BIT(i) & kbd_info.modes) {
kbd_mode_levels[0] = i;
break;
}
}
kbd_mode_levels_count++;
}
return 0;
}
static inline void kbd_init_tokens(void)
{
int i;
for (i = 0; i < ARRAY_SIZE(kbd_tokens); ++i)
if (dell_smbios_find_token(kbd_tokens[i]))
kbd_token_bits |= BIT(i);
}
static void kbd_init(void)
{
int ret;
ret = kbd_init_info();
kbd_init_tokens();
if (kbd_token_bits != 0 || ret == 0)
kbd_led_present = true;
}
static ssize_t kbd_led_timeout_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct kbd_state new_state;
struct kbd_state state;
bool convert;
int value;
int ret;
char ch;
u8 unit;
int i;
ret = sscanf(buf, "%d %c", &value, &ch);
if (ret < 1)
return -EINVAL;
else if (ret == 1)
ch = 's';
if (value < 0)
return -EINVAL;
convert = false;
switch (ch) {
case 's':
if (value > kbd_info.seconds)
convert = true;
unit = KBD_TIMEOUT_SECONDS;
break;
case 'm':
if (value > kbd_info.minutes)
convert = true;
unit = KBD_TIMEOUT_MINUTES;
break;
case 'h':
if (value > kbd_info.hours)
convert = true;
unit = KBD_TIMEOUT_HOURS;
break;
case 'd':
if (value > kbd_info.days)
convert = true;
unit = KBD_TIMEOUT_DAYS;
break;
default:
return -EINVAL;
}
if (quirks && quirks->needs_kbd_timeouts)
convert = true;
if (convert) {
switch (unit) {
case KBD_TIMEOUT_DAYS:
value *= 24;
case KBD_TIMEOUT_HOURS:
value *= 60;
case KBD_TIMEOUT_MINUTES:
value *= 60;
unit = KBD_TIMEOUT_SECONDS;
}
if (quirks && quirks->needs_kbd_timeouts) {
for (i = 0; quirks->kbd_timeouts[i] != -1; i++) {
if (value <= quirks->kbd_timeouts[i]) {
value = quirks->kbd_timeouts[i];
break;
}
}
}
if (value <= kbd_info.seconds && kbd_info.seconds) {
unit = KBD_TIMEOUT_SECONDS;
} else if (value / 60 <= kbd_info.minutes && kbd_info.minutes) {
value /= 60;
unit = KBD_TIMEOUT_MINUTES;
} else if (value / (60 * 60) <= kbd_info.hours && kbd_info.hours) {
value /= (60 * 60);
unit = KBD_TIMEOUT_HOURS;
} else if (value / (60 * 60 * 24) <= kbd_info.days && kbd_info.days) {
value /= (60 * 60 * 24);
unit = KBD_TIMEOUT_DAYS;
} else {
return -EINVAL;
}
}
ret = kbd_get_state(&state);
if (ret)
return ret;
new_state = state;
new_state.timeout_value = value;
new_state.timeout_unit = unit;
ret = kbd_set_state_safe(&new_state, &state);
if (ret)
return ret;
return count;
}
static ssize_t kbd_led_timeout_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct kbd_state state;
int ret;
int len;
ret = kbd_get_state(&state);
if (ret)
return ret;
len = sprintf(buf, "%d", state.timeout_value);
switch (state.timeout_unit) {
case KBD_TIMEOUT_SECONDS:
return len + sprintf(buf+len, "s\n");
case KBD_TIMEOUT_MINUTES:
return len + sprintf(buf+len, "m\n");
case KBD_TIMEOUT_HOURS:
return len + sprintf(buf+len, "h\n");
case KBD_TIMEOUT_DAYS:
return len + sprintf(buf+len, "d\n");
default:
return -EINVAL;
}
return len;
}
static ssize_t kbd_led_triggers_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct kbd_state new_state;
struct kbd_state state;
bool triggers_enabled = false;
int trigger_bit = -1;
char trigger[21];
int i, ret;
ret = sscanf(buf, "%20s", trigger);
if (ret != 1)
return -EINVAL;
if (trigger[0] != '+' && trigger[0] != '-')
return -EINVAL;
ret = kbd_get_state(&state);
if (ret)
return ret;
if (kbd_triggers_supported)
triggers_enabled = kbd_is_trigger_mode_bit(state.mode_bit);
if (kbd_triggers_supported) {
for (i = 0; i < ARRAY_SIZE(kbd_led_triggers); ++i) {
if (!(kbd_info.triggers & BIT(i)))
continue;
if (!kbd_led_triggers[i])
continue;
if (strcmp(trigger+1, kbd_led_triggers[i]) != 0)
continue;
if (trigger[0] == '+' &&
triggers_enabled && (state.triggers & BIT(i)))
return count;
if (trigger[0] == '-' &&
(!triggers_enabled || !(state.triggers & BIT(i))))
return count;
trigger_bit = i;
break;
}
}
if (trigger_bit != -1) {
new_state = state;
if (trigger[0] == '+')
new_state.triggers |= BIT(trigger_bit);
else {
new_state.triggers &= ~BIT(trigger_bit);
if (trigger_bit == 1)
new_state.triggers &= ~BIT(2);
}
if ((kbd_info.triggers & new_state.triggers) !=
new_state.triggers)
return -EINVAL;
if (new_state.triggers && !triggers_enabled) {
new_state.mode_bit = KBD_MODE_BIT_TRIGGER;
kbd_set_level(&new_state, kbd_previous_level);
} else if (new_state.triggers == 0) {
kbd_set_level(&new_state, 0);
}
if (!(kbd_info.modes & BIT(new_state.mode_bit)))
return -EINVAL;
ret = kbd_set_state_safe(&new_state, &state);
if (ret)
return ret;
if (new_state.mode_bit != KBD_MODE_BIT_OFF)
kbd_previous_mode_bit = new_state.mode_bit;
return count;
}
return -EINVAL;
}
static ssize_t kbd_led_triggers_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct kbd_state state;
bool triggers_enabled;
int level, i, ret;
int len = 0;
ret = kbd_get_state(&state);
if (ret)
return ret;
len = 0;
if (kbd_triggers_supported) {
triggers_enabled = kbd_is_trigger_mode_bit(state.mode_bit);
level = kbd_get_level(&state);
for (i = 0; i < ARRAY_SIZE(kbd_led_triggers); ++i) {
if (!(kbd_info.triggers & BIT(i)))
continue;
if (!kbd_led_triggers[i])
continue;
if ((triggers_enabled || level <= 0) &&
(state.triggers & BIT(i)))
buf[len++] = '+';
else
buf[len++] = '-';
len += sprintf(buf+len, "%s ", kbd_led_triggers[i]);
}
}
if (len)
buf[len - 1] = '\n';
return len;
}
static ssize_t kbd_led_als_enabled_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct kbd_state new_state;
struct kbd_state state;
bool triggers_enabled = false;
int enable;
int ret;
ret = kstrtoint(buf, 0, &enable);
if (ret)
return ret;
ret = kbd_get_state(&state);
if (ret)
return ret;
if (enable == kbd_is_als_mode_bit(state.mode_bit))
return count;
new_state = state;
if (kbd_triggers_supported)
triggers_enabled = kbd_is_trigger_mode_bit(state.mode_bit);
if (enable) {
if (triggers_enabled)
new_state.mode_bit = KBD_MODE_BIT_TRIGGER_ALS;
else
new_state.mode_bit = KBD_MODE_BIT_ALS;
} else {
if (triggers_enabled) {
new_state.mode_bit = KBD_MODE_BIT_TRIGGER;
kbd_set_level(&new_state, kbd_previous_level);
} else {
new_state.mode_bit = KBD_MODE_BIT_ON;
}
}
if (!(kbd_info.modes & BIT(new_state.mode_bit)))
return -EINVAL;
ret = kbd_set_state_safe(&new_state, &state);
if (ret)
return ret;
kbd_previous_mode_bit = new_state.mode_bit;
return count;
}
static ssize_t kbd_led_als_enabled_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct kbd_state state;
bool enabled = false;
int ret;
ret = kbd_get_state(&state);
if (ret)
return ret;
enabled = kbd_is_als_mode_bit(state.mode_bit);
return sprintf(buf, "%d\n", enabled ? 1 : 0);
}
static ssize_t kbd_led_als_setting_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct kbd_state state;
struct kbd_state new_state;
u8 setting;
int ret;
ret = kstrtou8(buf, 10, &setting);
if (ret)
return ret;
ret = kbd_get_state(&state);
if (ret)
return ret;
new_state = state;
new_state.als_setting = setting;
ret = kbd_set_state_safe(&new_state, &state);
if (ret)
return ret;
return count;
}
static ssize_t kbd_led_als_setting_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct kbd_state state;
int ret;
ret = kbd_get_state(&state);
if (ret)
return ret;
return sprintf(buf, "%d\n", state.als_setting);
}
static enum led_brightness kbd_led_level_get(struct led_classdev *led_cdev)
{
int ret;
u16 num;
struct kbd_state state;
if (kbd_get_max_level()) {
ret = kbd_get_state(&state);
if (ret)
return 0;
ret = kbd_get_level(&state);
if (ret < 0)
return 0;
return ret;
}
if (kbd_get_valid_token_counts()) {
ret = kbd_get_first_active_token_bit();
if (ret < 0)
return 0;
for (num = kbd_token_bits; num != 0 && ret > 0; --ret)
num &= num - 1;
if (num == 0)
return 0;
return ffs(num) - 1;
}
pr_warn("Keyboard brightness level control not supported\n");
return 0;
}
static int kbd_led_level_set(struct led_classdev *led_cdev,
enum led_brightness value)
{
struct kbd_state state;
struct kbd_state new_state;
u16 num;
int ret;
if (kbd_get_max_level()) {
ret = kbd_get_state(&state);
if (ret)
return ret;
new_state = state;
ret = kbd_set_level(&new_state, value);
if (ret)
return ret;
return kbd_set_state_safe(&new_state, &state);
}
if (kbd_get_valid_token_counts()) {
for (num = kbd_token_bits; num != 0 && value > 0; --value)
num &= num - 1;
if (num == 0)
return 0;
return kbd_set_token_bit(ffs(num) - 1);
}
pr_warn("Keyboard brightness level control not supported\n");
return -ENXIO;
}
static int __init kbd_led_init(struct device *dev)
{
kbd_init();
if (!kbd_led_present)
return -ENODEV;
if (!kbd_als_supported)
kbd_led_groups[1] = NULL;
kbd_led.max_brightness = kbd_get_max_level();
if (!kbd_led.max_brightness) {
kbd_led.max_brightness = kbd_get_valid_token_counts();
if (kbd_led.max_brightness)
kbd_led.max_brightness--;
}
return led_classdev_register(dev, &kbd_led);
}
static void brightness_set_exit(struct led_classdev *led_cdev,
enum led_brightness value)
{
}
static void kbd_led_exit(void)
{
if (!kbd_led_present)
return;
kbd_led.brightness_set = brightness_set_exit;
led_classdev_unregister(&kbd_led);
}
static int __init dell_init(void)
{
struct calling_interface_buffer *buffer;
struct calling_interface_token *token;
int max_intensity = 0;
int ret;
if (!dmi_check_system(dell_device_table))
return -ENODEV;
quirks = NULL;
dmi_check_system(dell_quirks);
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
ret = dell_setup_rfkill();
if (ret) {
pr_warn("Unable to setup rfkill\n");
goto fail_rfkill;
}
if (quirks && quirks->touchpad_led)
touchpad_led_init(&platform_device->dev);
kbd_led_init(&platform_device->dev);
dell_laptop_dir = debugfs_create_dir("dell_laptop", NULL);
if (dell_laptop_dir != NULL)
debugfs_create_file("rfkill", 0444, dell_laptop_dir, NULL,
&dell_debugfs_fops);
if (acpi_video_get_backlight_type() != acpi_backlight_vendor)
return 0;
token = dell_smbios_find_token(BRIGHTNESS_TOKEN);
if (token) {
buffer = dell_smbios_get_buffer();
buffer->input[0] = token->location;
dell_smbios_send_request(0, 2);
if (buffer->output[0] == 0)
max_intensity = buffer->output[3];
dell_smbios_release_buffer();
}
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
dell_cleanup_rfkill();
fail_rfkill:
platform_device_del(platform_device);
fail_platform_device2:
platform_device_put(platform_device);
fail_platform_device1:
platform_driver_unregister(&platform_driver);
fail_platform_driver:
return ret;
}
static void __exit dell_exit(void)
{
debugfs_remove_recursive(dell_laptop_dir);
if (quirks && quirks->touchpad_led)
touchpad_led_exit();
kbd_led_exit();
backlight_device_unregister(dell_backlight_device);
dell_cleanup_rfkill();
if (platform_device) {
platform_device_unregister(platform_device);
platform_driver_unregister(&platform_driver);
}
}
