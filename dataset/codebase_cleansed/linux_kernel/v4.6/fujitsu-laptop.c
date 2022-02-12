static int call_fext_func(int cmd, int arg0, int arg1, int arg2)
{
acpi_status status = AE_OK;
union acpi_object params[4] = {
{ .type = ACPI_TYPE_INTEGER },
{ .type = ACPI_TYPE_INTEGER },
{ .type = ACPI_TYPE_INTEGER },
{ .type = ACPI_TYPE_INTEGER }
};
struct acpi_object_list arg_list = { 4, &params[0] };
unsigned long long value;
acpi_handle handle = NULL;
status = acpi_get_handle(fujitsu_hotkey->acpi_handle, "FUNC", &handle);
if (ACPI_FAILURE(status)) {
vdbg_printk(FUJLAPTOP_DBG_ERROR,
"FUNC interface is not present\n");
return -ENODEV;
}
params[0].integer.value = cmd;
params[1].integer.value = arg0;
params[2].integer.value = arg1;
params[3].integer.value = arg2;
status = acpi_evaluate_integer(handle, NULL, &arg_list, &value);
if (ACPI_FAILURE(status)) {
vdbg_printk(FUJLAPTOP_DBG_WARN,
"FUNC 0x%x (args 0x%x, 0x%x, 0x%x) call failed\n",
cmd, arg0, arg1, arg2);
return -ENODEV;
}
vdbg_printk(FUJLAPTOP_DBG_TRACE,
"FUNC 0x%x (args 0x%x, 0x%x, 0x%x) returned 0x%x\n",
cmd, arg0, arg1, arg2, (int)value);
return value;
}
static void logolamp_set(struct led_classdev *cdev,
enum led_brightness brightness)
{
if (brightness >= LED_FULL) {
call_fext_func(FUNC_LEDS, 0x1, LOGOLAMP_POWERON, FUNC_LED_ON);
call_fext_func(FUNC_LEDS, 0x1, LOGOLAMP_ALWAYS, FUNC_LED_ON);
} else if (brightness >= LED_HALF) {
call_fext_func(FUNC_LEDS, 0x1, LOGOLAMP_POWERON, FUNC_LED_ON);
call_fext_func(FUNC_LEDS, 0x1, LOGOLAMP_ALWAYS, FUNC_LED_OFF);
} else {
call_fext_func(FUNC_LEDS, 0x1, LOGOLAMP_POWERON, FUNC_LED_OFF);
}
}
static void kblamps_set(struct led_classdev *cdev,
enum led_brightness brightness)
{
if (brightness >= LED_FULL)
call_fext_func(FUNC_LEDS, 0x1, KEYBOARD_LAMPS, FUNC_LED_ON);
else
call_fext_func(FUNC_LEDS, 0x1, KEYBOARD_LAMPS, FUNC_LED_OFF);
}
static enum led_brightness logolamp_get(struct led_classdev *cdev)
{
enum led_brightness brightness = LED_OFF;
int poweron, always;
poweron = call_fext_func(FUNC_LEDS, 0x2, LOGOLAMP_POWERON, 0x0);
if (poweron == FUNC_LED_ON) {
brightness = LED_HALF;
always = call_fext_func(FUNC_LEDS, 0x2, LOGOLAMP_ALWAYS, 0x0);
if (always == FUNC_LED_ON)
brightness = LED_FULL;
}
return brightness;
}
static enum led_brightness kblamps_get(struct led_classdev *cdev)
{
enum led_brightness brightness = LED_OFF;
if (call_fext_func(FUNC_LEDS, 0x2, KEYBOARD_LAMPS, 0x0) == FUNC_LED_ON)
brightness = LED_FULL;
return brightness;
}
static int set_lcd_level(int level)
{
acpi_status status = AE_OK;
acpi_handle handle = NULL;
vdbg_printk(FUJLAPTOP_DBG_TRACE, "set lcd level via SBLL [%d]\n",
level);
if (level < 0 || level >= fujitsu->max_brightness)
return -EINVAL;
status = acpi_get_handle(fujitsu->acpi_handle, "SBLL", &handle);
if (ACPI_FAILURE(status)) {
vdbg_printk(FUJLAPTOP_DBG_ERROR, "SBLL not present\n");
return -ENODEV;
}
status = acpi_execute_simple_method(handle, NULL, level);
if (ACPI_FAILURE(status))
return -ENODEV;
return 0;
}
static int set_lcd_level_alt(int level)
{
acpi_status status = AE_OK;
acpi_handle handle = NULL;
vdbg_printk(FUJLAPTOP_DBG_TRACE, "set lcd level via SBL2 [%d]\n",
level);
if (level < 0 || level >= fujitsu->max_brightness)
return -EINVAL;
status = acpi_get_handle(fujitsu->acpi_handle, "SBL2", &handle);
if (ACPI_FAILURE(status)) {
vdbg_printk(FUJLAPTOP_DBG_ERROR, "SBL2 not present\n");
return -ENODEV;
}
status = acpi_execute_simple_method(handle, NULL, level);
if (ACPI_FAILURE(status))
return -ENODEV;
return 0;
}
static int get_lcd_level(void)
{
unsigned long long state = 0;
acpi_status status = AE_OK;
vdbg_printk(FUJLAPTOP_DBG_TRACE, "get lcd level via GBLL\n");
status =
acpi_evaluate_integer(fujitsu->acpi_handle, "GBLL", NULL, &state);
if (ACPI_FAILURE(status))
return 0;
fujitsu->brightness_level = state & 0x0fffffff;
if (state & 0x80000000)
fujitsu->brightness_changed = 1;
else
fujitsu->brightness_changed = 0;
return fujitsu->brightness_level;
}
static int get_max_brightness(void)
{
unsigned long long state = 0;
acpi_status status = AE_OK;
vdbg_printk(FUJLAPTOP_DBG_TRACE, "get max lcd level via RBLL\n");
status =
acpi_evaluate_integer(fujitsu->acpi_handle, "RBLL", NULL, &state);
if (ACPI_FAILURE(status))
return -1;
fujitsu->max_brightness = state;
return fujitsu->max_brightness;
}
static int bl_get_brightness(struct backlight_device *b)
{
return get_lcd_level();
}
static int bl_update_status(struct backlight_device *b)
{
int ret;
if (b->props.power == FB_BLANK_POWERDOWN)
ret = call_fext_func(FUNC_BACKLIGHT, 0x1, 0x4, 0x3);
else
ret = call_fext_func(FUNC_BACKLIGHT, 0x1, 0x4, 0x0);
if (ret != 0)
vdbg_printk(FUJLAPTOP_DBG_ERROR,
"Unable to adjust backlight power, error code %i\n",
ret);
if (use_alt_lcd_levels)
ret = set_lcd_level_alt(b->props.brightness);
else
ret = set_lcd_level(b->props.brightness);
if (ret != 0)
vdbg_printk(FUJLAPTOP_DBG_ERROR,
"Unable to adjust LCD brightness, error code %i\n",
ret);
return ret;
}
static ssize_t
show_max_brightness(struct device *dev,
struct device_attribute *attr, char *buf)
{
int ret;
ret = get_max_brightness();
if (ret < 0)
return ret;
return sprintf(buf, "%i\n", ret);
}
static ssize_t
show_brightness_changed(struct device *dev,
struct device_attribute *attr, char *buf)
{
int ret;
ret = fujitsu->brightness_changed;
if (ret < 0)
return ret;
return sprintf(buf, "%i\n", ret);
}
static ssize_t show_lcd_level(struct device *dev,
struct device_attribute *attr, char *buf)
{
int ret;
ret = get_lcd_level();
if (ret < 0)
return ret;
return sprintf(buf, "%i\n", ret);
}
static ssize_t store_lcd_level(struct device *dev,
struct device_attribute *attr, const char *buf,
size_t count)
{
int level, ret;
if (sscanf(buf, "%i", &level) != 1
|| (level < 0 || level >= fujitsu->max_brightness))
return -EINVAL;
if (use_alt_lcd_levels)
ret = set_lcd_level_alt(level);
else
ret = set_lcd_level(level);
if (ret < 0)
return ret;
ret = get_lcd_level();
if (ret < 0)
return ret;
return count;
}
static ssize_t
ignore_store(struct device *dev,
struct device_attribute *attr, const char *buf, size_t count)
{
return count;
}
static ssize_t
show_lid_state(struct device *dev,
struct device_attribute *attr, char *buf)
{
if (!(fujitsu_hotkey->rfkill_supported & 0x100))
return sprintf(buf, "unknown\n");
if (fujitsu_hotkey->rfkill_state & 0x100)
return sprintf(buf, "open\n");
else
return sprintf(buf, "closed\n");
}
static ssize_t
show_dock_state(struct device *dev,
struct device_attribute *attr, char *buf)
{
if (!(fujitsu_hotkey->rfkill_supported & 0x200))
return sprintf(buf, "unknown\n");
if (fujitsu_hotkey->rfkill_state & 0x200)
return sprintf(buf, "docked\n");
else
return sprintf(buf, "undocked\n");
}
static ssize_t
show_radios_state(struct device *dev,
struct device_attribute *attr, char *buf)
{
if (!(fujitsu_hotkey->rfkill_supported & 0x20))
return sprintf(buf, "unknown\n");
if (fujitsu_hotkey->rfkill_state & 0x20)
return sprintf(buf, "on\n");
else
return sprintf(buf, "killed\n");
}
static void __init dmi_check_cb_common(const struct dmi_system_id *id)
{
pr_info("Identified laptop model '%s'\n", id->ident);
if (use_alt_lcd_levels == -1) {
if (acpi_has_method(NULL,
"\\_SB.PCI0.LPCB.FJEX.SBL2"))
use_alt_lcd_levels = 1;
else
use_alt_lcd_levels = 0;
vdbg_printk(FUJLAPTOP_DBG_TRACE, "auto-detected usealt as "
"%i\n", use_alt_lcd_levels);
}
}
static int __init dmi_check_cb_s6410(const struct dmi_system_id *id)
{
dmi_check_cb_common(id);
fujitsu->keycode1 = KEY_SCREENLOCK;
fujitsu->keycode2 = KEY_HELP;
return 1;
}
static int __init dmi_check_cb_s6420(const struct dmi_system_id *id)
{
dmi_check_cb_common(id);
fujitsu->keycode1 = KEY_SCREENLOCK;
fujitsu->keycode2 = KEY_HELP;
return 1;
}
static int __init dmi_check_cb_p8010(const struct dmi_system_id *id)
{
dmi_check_cb_common(id);
fujitsu->keycode1 = KEY_HELP;
fujitsu->keycode3 = KEY_SWITCHVIDEOMODE;
fujitsu->keycode4 = KEY_WWW;
return 1;
}
static int acpi_fujitsu_add(struct acpi_device *device)
{
int state = 0;
struct input_dev *input;
int error;
if (!device)
return -EINVAL;
fujitsu->acpi_handle = device->handle;
sprintf(acpi_device_name(device), "%s", ACPI_FUJITSU_DEVICE_NAME);
sprintf(acpi_device_class(device), "%s", ACPI_FUJITSU_CLASS);
device->driver_data = fujitsu;
fujitsu->input = input = input_allocate_device();
if (!input) {
error = -ENOMEM;
goto err_stop;
}
snprintf(fujitsu->phys, sizeof(fujitsu->phys),
"%s/video/input0", acpi_device_hid(device));
input->name = acpi_device_name(device);
input->phys = fujitsu->phys;
input->id.bustype = BUS_HOST;
input->id.product = 0x06;
input->dev.parent = &device->dev;
input->evbit[0] = BIT(EV_KEY);
set_bit(KEY_BRIGHTNESSUP, input->keybit);
set_bit(KEY_BRIGHTNESSDOWN, input->keybit);
set_bit(KEY_UNKNOWN, input->keybit);
error = input_register_device(input);
if (error)
goto err_free_input_dev;
error = acpi_bus_update_power(fujitsu->acpi_handle, &state);
if (error) {
pr_err("Error reading power state\n");
goto err_unregister_input_dev;
}
pr_info("ACPI: %s [%s] (%s)\n",
acpi_device_name(device), acpi_device_bid(device),
!device->power.state ? "on" : "off");
fujitsu->dev = device;
if (acpi_has_method(device->handle, METHOD_NAME__INI)) {
vdbg_printk(FUJLAPTOP_DBG_INFO, "Invoking _INI\n");
if (ACPI_FAILURE
(acpi_evaluate_object
(device->handle, METHOD_NAME__INI, NULL, NULL)))
pr_err("_INI Method failed\n");
}
use_alt_lcd_levels = use_alt_lcd_levels == 1 ? 1 : 0;
disable_brightness_adjust = disable_brightness_adjust == 1 ? 1 : 0;
vdbg_printk(FUJLAPTOP_DBG_INFO,
"config: [alt interface: %d], [adjust disable: %d]\n",
use_alt_lcd_levels, disable_brightness_adjust);
if (get_max_brightness() <= 0)
fujitsu->max_brightness = FUJITSU_LCD_N_LEVELS;
get_lcd_level();
return 0;
err_unregister_input_dev:
input_unregister_device(input);
input = NULL;
err_free_input_dev:
input_free_device(input);
err_stop:
return error;
}
static int acpi_fujitsu_remove(struct acpi_device *device)
{
struct fujitsu_t *fujitsu = acpi_driver_data(device);
struct input_dev *input = fujitsu->input;
input_unregister_device(input);
fujitsu->acpi_handle = NULL;
return 0;
}
static void acpi_fujitsu_notify(struct acpi_device *device, u32 event)
{
struct input_dev *input;
int keycode;
int oldb, newb;
input = fujitsu->input;
switch (event) {
case ACPI_FUJITSU_NOTIFY_CODE1:
keycode = 0;
oldb = fujitsu->brightness_level;
get_lcd_level();
newb = fujitsu->brightness_level;
vdbg_printk(FUJLAPTOP_DBG_TRACE,
"brightness button event [%i -> %i (%i)]\n",
oldb, newb, fujitsu->brightness_changed);
if (oldb < newb) {
if (disable_brightness_adjust != 1) {
if (use_alt_lcd_levels)
set_lcd_level_alt(newb);
else
set_lcd_level(newb);
}
keycode = KEY_BRIGHTNESSUP;
} else if (oldb > newb) {
if (disable_brightness_adjust != 1) {
if (use_alt_lcd_levels)
set_lcd_level_alt(newb);
else
set_lcd_level(newb);
}
keycode = KEY_BRIGHTNESSDOWN;
}
break;
default:
keycode = KEY_UNKNOWN;
vdbg_printk(FUJLAPTOP_DBG_WARN,
"unsupported event [0x%x]\n", event);
break;
}
if (keycode != 0) {
input_report_key(input, keycode, 1);
input_sync(input);
input_report_key(input, keycode, 0);
input_sync(input);
}
}
static int acpi_fujitsu_hotkey_add(struct acpi_device *device)
{
int result = 0;
int state = 0;
struct input_dev *input;
int error;
int i;
if (!device)
return -EINVAL;
fujitsu_hotkey->acpi_handle = device->handle;
sprintf(acpi_device_name(device), "%s",
ACPI_FUJITSU_HOTKEY_DEVICE_NAME);
sprintf(acpi_device_class(device), "%s", ACPI_FUJITSU_CLASS);
device->driver_data = fujitsu_hotkey;
spin_lock_init(&fujitsu_hotkey->fifo_lock);
error = kfifo_alloc(&fujitsu_hotkey->fifo, RINGBUFFERSIZE * sizeof(int),
GFP_KERNEL);
if (error) {
pr_err("kfifo_alloc failed\n");
goto err_stop;
}
fujitsu_hotkey->input = input = input_allocate_device();
if (!input) {
error = -ENOMEM;
goto err_free_fifo;
}
snprintf(fujitsu_hotkey->phys, sizeof(fujitsu_hotkey->phys),
"%s/video/input0", acpi_device_hid(device));
input->name = acpi_device_name(device);
input->phys = fujitsu_hotkey->phys;
input->id.bustype = BUS_HOST;
input->id.product = 0x06;
input->dev.parent = &device->dev;
set_bit(EV_KEY, input->evbit);
set_bit(fujitsu->keycode1, input->keybit);
set_bit(fujitsu->keycode2, input->keybit);
set_bit(fujitsu->keycode3, input->keybit);
set_bit(fujitsu->keycode4, input->keybit);
set_bit(fujitsu->keycode5, input->keybit);
set_bit(KEY_UNKNOWN, input->keybit);
error = input_register_device(input);
if (error)
goto err_free_input_dev;
error = acpi_bus_update_power(fujitsu_hotkey->acpi_handle, &state);
if (error) {
pr_err("Error reading power state\n");
goto err_unregister_input_dev;
}
pr_info("ACPI: %s [%s] (%s)\n",
acpi_device_name(device), acpi_device_bid(device),
!device->power.state ? "on" : "off");
fujitsu_hotkey->dev = device;
if (acpi_has_method(device->handle, METHOD_NAME__INI)) {
vdbg_printk(FUJLAPTOP_DBG_INFO, "Invoking _INI\n");
if (ACPI_FAILURE
(acpi_evaluate_object
(device->handle, METHOD_NAME__INI, NULL, NULL)))
pr_err("_INI Method failed\n");
}
i = 0;
while (call_fext_func(FUNC_BUTTONS, 0x1, 0x0, 0x0) != 0
&& (i++) < MAX_HOTKEY_RINGBUFFER_SIZE)
;
vdbg_printk(FUJLAPTOP_DBG_INFO, "Discarded %i ringbuffer entries\n", i);
fujitsu_hotkey->rfkill_supported =
call_fext_func(FUNC_RFKILL, 0x0, 0x0, 0x0);
if (fujitsu_hotkey->rfkill_supported == UNSUPPORTED_CMD)
fujitsu_hotkey->rfkill_supported = 0;
if (fujitsu_hotkey->rfkill_supported)
fujitsu_hotkey->rfkill_state =
call_fext_func(FUNC_RFKILL, 0x4, 0x0, 0x0);
pr_info("BTNI: [0x%x]\n", call_fext_func(FUNC_BUTTONS, 0x0, 0x0, 0x0));
#if defined(CONFIG_LEDS_CLASS) || defined(CONFIG_LEDS_CLASS_MODULE)
if (call_fext_func(FUNC_LEDS, 0x0, 0x0, 0x0) & LOGOLAMP_POWERON) {
result = led_classdev_register(&fujitsu->pf_device->dev,
&logolamp_led);
if (result == 0) {
fujitsu_hotkey->logolamp_registered = 1;
} else {
pr_err("Could not register LED handler for logo lamp, error %i\n",
result);
}
}
if ((call_fext_func(FUNC_LEDS, 0x0, 0x0, 0x0) & KEYBOARD_LAMPS) &&
(call_fext_func(FUNC_BUTTONS, 0x0, 0x0, 0x0) == 0x0)) {
result = led_classdev_register(&fujitsu->pf_device->dev,
&kblamps_led);
if (result == 0) {
fujitsu_hotkey->kblamps_registered = 1;
} else {
pr_err("Could not register LED handler for keyboard lamps, error %i\n",
result);
}
}
#endif
return result;
err_unregister_input_dev:
input_unregister_device(input);
input = NULL;
err_free_input_dev:
input_free_device(input);
err_free_fifo:
kfifo_free(&fujitsu_hotkey->fifo);
err_stop:
return error;
}
static int acpi_fujitsu_hotkey_remove(struct acpi_device *device)
{
struct fujitsu_hotkey_t *fujitsu_hotkey = acpi_driver_data(device);
struct input_dev *input = fujitsu_hotkey->input;
#if defined(CONFIG_LEDS_CLASS) || defined(CONFIG_LEDS_CLASS_MODULE)
if (fujitsu_hotkey->logolamp_registered)
led_classdev_unregister(&logolamp_led);
if (fujitsu_hotkey->kblamps_registered)
led_classdev_unregister(&kblamps_led);
#endif
input_unregister_device(input);
kfifo_free(&fujitsu_hotkey->fifo);
fujitsu_hotkey->acpi_handle = NULL;
return 0;
}
static void acpi_fujitsu_hotkey_notify(struct acpi_device *device, u32 event)
{
struct input_dev *input;
int keycode, keycode_r;
unsigned int irb = 1;
int i, status;
input = fujitsu_hotkey->input;
if (fujitsu_hotkey->rfkill_supported)
fujitsu_hotkey->rfkill_state =
call_fext_func(FUNC_RFKILL, 0x4, 0x0, 0x0);
switch (event) {
case ACPI_FUJITSU_NOTIFY_CODE1:
i = 0;
while ((irb =
call_fext_func(FUNC_BUTTONS, 0x1, 0x0, 0x0)) != 0
&& (i++) < MAX_HOTKEY_RINGBUFFER_SIZE) {
switch (irb & 0x4ff) {
case KEY1_CODE:
keycode = fujitsu->keycode1;
break;
case KEY2_CODE:
keycode = fujitsu->keycode2;
break;
case KEY3_CODE:
keycode = fujitsu->keycode3;
break;
case KEY4_CODE:
keycode = fujitsu->keycode4;
break;
case KEY5_CODE:
keycode = fujitsu->keycode5;
break;
case 0:
keycode = 0;
break;
default:
vdbg_printk(FUJLAPTOP_DBG_WARN,
"Unknown GIRB result [%x]\n", irb);
keycode = -1;
break;
}
if (keycode > 0) {
vdbg_printk(FUJLAPTOP_DBG_TRACE,
"Push keycode into ringbuffer [%d]\n",
keycode);
status = kfifo_in_locked(&fujitsu_hotkey->fifo,
(unsigned char *)&keycode,
sizeof(keycode),
&fujitsu_hotkey->fifo_lock);
if (status != sizeof(keycode)) {
vdbg_printk(FUJLAPTOP_DBG_WARN,
"Could not push keycode [0x%x]\n",
keycode);
} else {
input_report_key(input, keycode, 1);
input_sync(input);
}
} else if (keycode == 0) {
while ((status =
kfifo_out_locked(
&fujitsu_hotkey->fifo,
(unsigned char *) &keycode_r,
sizeof(keycode_r),
&fujitsu_hotkey->fifo_lock))
== sizeof(keycode_r)) {
input_report_key(input, keycode_r, 0);
input_sync(input);
vdbg_printk(FUJLAPTOP_DBG_TRACE,
"Pop keycode from ringbuffer [%d]\n",
keycode_r);
}
}
}
break;
default:
keycode = KEY_UNKNOWN;
vdbg_printk(FUJLAPTOP_DBG_WARN,
"Unsupported event [0x%x]\n", event);
input_report_key(input, keycode, 1);
input_sync(input);
input_report_key(input, keycode, 0);
input_sync(input);
break;
}
}
static int __init fujitsu_init(void)
{
int ret, result, max_brightness;
if (acpi_disabled)
return -ENODEV;
fujitsu = kzalloc(sizeof(struct fujitsu_t), GFP_KERNEL);
if (!fujitsu)
return -ENOMEM;
fujitsu->keycode1 = KEY_PROG1;
fujitsu->keycode2 = KEY_PROG2;
fujitsu->keycode3 = KEY_PROG3;
fujitsu->keycode4 = KEY_PROG4;
fujitsu->keycode5 = KEY_RFKILL;
dmi_check_system(fujitsu_dmi_table);
result = acpi_bus_register_driver(&acpi_fujitsu_driver);
if (result < 0) {
ret = -ENODEV;
goto fail_acpi;
}
fujitsu->pf_device = platform_device_alloc("fujitsu-laptop", -1);
if (!fujitsu->pf_device) {
ret = -ENOMEM;
goto fail_platform_driver;
}
ret = platform_device_add(fujitsu->pf_device);
if (ret)
goto fail_platform_device1;
ret =
sysfs_create_group(&fujitsu->pf_device->dev.kobj,
&fujitsupf_attribute_group);
if (ret)
goto fail_platform_device2;
if (acpi_video_get_backlight_type() == acpi_backlight_vendor) {
struct backlight_properties props;
memset(&props, 0, sizeof(struct backlight_properties));
max_brightness = fujitsu->max_brightness;
props.type = BACKLIGHT_PLATFORM;
props.max_brightness = max_brightness - 1;
fujitsu->bl_device = backlight_device_register("fujitsu-laptop",
NULL, NULL,
&fujitsubl_ops,
&props);
if (IS_ERR(fujitsu->bl_device)) {
ret = PTR_ERR(fujitsu->bl_device);
fujitsu->bl_device = NULL;
goto fail_sysfs_group;
}
fujitsu->bl_device->props.brightness = fujitsu->brightness_level;
}
ret = platform_driver_register(&fujitsupf_driver);
if (ret)
goto fail_backlight;
fujitsu_hotkey = kzalloc(sizeof(struct fujitsu_hotkey_t), GFP_KERNEL);
if (!fujitsu_hotkey) {
ret = -ENOMEM;
goto fail_hotkey;
}
result = acpi_bus_register_driver(&acpi_fujitsu_hotkey_driver);
if (result < 0) {
ret = -ENODEV;
goto fail_hotkey1;
}
if (acpi_video_get_backlight_type() == acpi_backlight_vendor) {
if (call_fext_func(FUNC_BACKLIGHT, 0x2, 0x4, 0x0) == 3)
fujitsu->bl_device->props.power = FB_BLANK_POWERDOWN;
else
fujitsu->bl_device->props.power = FB_BLANK_UNBLANK;
}
pr_info("driver " FUJITSU_DRIVER_VERSION " successfully loaded\n");
return 0;
fail_hotkey1:
kfree(fujitsu_hotkey);
fail_hotkey:
platform_driver_unregister(&fujitsupf_driver);
fail_backlight:
backlight_device_unregister(fujitsu->bl_device);
fail_sysfs_group:
sysfs_remove_group(&fujitsu->pf_device->dev.kobj,
&fujitsupf_attribute_group);
fail_platform_device2:
platform_device_del(fujitsu->pf_device);
fail_platform_device1:
platform_device_put(fujitsu->pf_device);
fail_platform_driver:
acpi_bus_unregister_driver(&acpi_fujitsu_driver);
fail_acpi:
kfree(fujitsu);
return ret;
}
static void __exit fujitsu_cleanup(void)
{
acpi_bus_unregister_driver(&acpi_fujitsu_hotkey_driver);
kfree(fujitsu_hotkey);
platform_driver_unregister(&fujitsupf_driver);
backlight_device_unregister(fujitsu->bl_device);
sysfs_remove_group(&fujitsu->pf_device->dev.kobj,
&fujitsupf_attribute_group);
platform_device_unregister(fujitsu->pf_device);
acpi_bus_unregister_driver(&acpi_fujitsu_driver);
kfree(fujitsu);
pr_info("driver unloaded\n");
}
