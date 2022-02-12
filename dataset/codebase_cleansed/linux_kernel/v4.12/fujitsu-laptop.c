static int call_fext_func(int func, int op, int feature, int state)
{
union acpi_object params[4] = {
{ .integer.type = ACPI_TYPE_INTEGER, .integer.value = func },
{ .integer.type = ACPI_TYPE_INTEGER, .integer.value = op },
{ .integer.type = ACPI_TYPE_INTEGER, .integer.value = feature },
{ .integer.type = ACPI_TYPE_INTEGER, .integer.value = state }
};
struct acpi_object_list arg_list = { 4, params };
unsigned long long value;
acpi_status status;
status = acpi_evaluate_integer(fujitsu_laptop->acpi_handle, "FUNC",
&arg_list, &value);
if (ACPI_FAILURE(status)) {
vdbg_printk(FUJLAPTOP_DBG_ERROR, "Failed to evaluate FUNC\n");
return -ENODEV;
}
vdbg_printk(FUJLAPTOP_DBG_TRACE, "FUNC 0x%x (args 0x%x, 0x%x, 0x%x) returned 0x%x\n",
func, op, feature, state, (int)value);
return value;
}
static int set_lcd_level(int level)
{
acpi_status status;
char *method;
switch (use_alt_lcd_levels) {
case -1:
if (acpi_has_method(fujitsu_bl->acpi_handle, "SBL2"))
method = "SBL2";
else
method = "SBLL";
break;
case 1:
method = "SBL2";
break;
default:
method = "SBLL";
break;
}
vdbg_printk(FUJLAPTOP_DBG_TRACE, "set lcd level via %s [%d]\n",
method, level);
if (level < 0 || level >= fujitsu_bl->max_brightness)
return -EINVAL;
status = acpi_execute_simple_method(fujitsu_bl->acpi_handle, method,
level);
if (ACPI_FAILURE(status)) {
vdbg_printk(FUJLAPTOP_DBG_ERROR, "Failed to evaluate %s\n",
method);
return -ENODEV;
}
fujitsu_bl->brightness_level = level;
return 0;
}
static int get_lcd_level(void)
{
unsigned long long state = 0;
acpi_status status = AE_OK;
vdbg_printk(FUJLAPTOP_DBG_TRACE, "get lcd level via GBLL\n");
status = acpi_evaluate_integer(fujitsu_bl->acpi_handle, "GBLL", NULL,
&state);
if (ACPI_FAILURE(status))
return 0;
fujitsu_bl->brightness_level = state & 0x0fffffff;
return fujitsu_bl->brightness_level;
}
static int get_max_brightness(void)
{
unsigned long long state = 0;
acpi_status status = AE_OK;
vdbg_printk(FUJLAPTOP_DBG_TRACE, "get max lcd level via RBLL\n");
status = acpi_evaluate_integer(fujitsu_bl->acpi_handle, "RBLL", NULL,
&state);
if (ACPI_FAILURE(status))
return -1;
fujitsu_bl->max_brightness = state;
return fujitsu_bl->max_brightness;
}
static int bl_get_brightness(struct backlight_device *b)
{
return b->props.power == FB_BLANK_POWERDOWN ? 0 : get_lcd_level();
}
static int bl_update_status(struct backlight_device *b)
{
if (b->props.power == FB_BLANK_POWERDOWN)
call_fext_func(FUNC_BACKLIGHT, 0x1, 0x4, 0x3);
else
call_fext_func(FUNC_BACKLIGHT, 0x1, 0x4, 0x0);
return set_lcd_level(b->props.brightness);
}
static ssize_t lid_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
if (!(fujitsu_laptop->flags_supported & FLAG_LID))
return sprintf(buf, "unknown\n");
if (fujitsu_laptop->flags_state & FLAG_LID)
return sprintf(buf, "open\n");
else
return sprintf(buf, "closed\n");
}
static ssize_t dock_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
if (!(fujitsu_laptop->flags_supported & FLAG_DOCK))
return sprintf(buf, "unknown\n");
if (fujitsu_laptop->flags_state & FLAG_DOCK)
return sprintf(buf, "docked\n");
else
return sprintf(buf, "undocked\n");
}
static ssize_t radios_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
if (!(fujitsu_laptop->flags_supported & FLAG_RFKILL))
return sprintf(buf, "unknown\n");
if (fujitsu_laptop->flags_state & FLAG_RFKILL)
return sprintf(buf, "on\n");
else
return sprintf(buf, "killed\n");
}
static int acpi_fujitsu_bl_input_setup(struct acpi_device *device)
{
struct fujitsu_bl *fujitsu_bl = acpi_driver_data(device);
int ret;
fujitsu_bl->input = devm_input_allocate_device(&device->dev);
if (!fujitsu_bl->input)
return -ENOMEM;
snprintf(fujitsu_bl->phys, sizeof(fujitsu_bl->phys),
"%s/video/input0", acpi_device_hid(device));
fujitsu_bl->input->name = acpi_device_name(device);
fujitsu_bl->input->phys = fujitsu_bl->phys;
fujitsu_bl->input->id.bustype = BUS_HOST;
fujitsu_bl->input->id.product = 0x06;
ret = sparse_keymap_setup(fujitsu_bl->input, keymap_backlight, NULL);
if (ret)
return ret;
return input_register_device(fujitsu_bl->input);
}
static int fujitsu_backlight_register(struct acpi_device *device)
{
const struct backlight_properties props = {
.brightness = fujitsu_bl->brightness_level,
.max_brightness = fujitsu_bl->max_brightness - 1,
.type = BACKLIGHT_PLATFORM
};
struct backlight_device *bd;
bd = devm_backlight_device_register(&device->dev, "fujitsu-laptop",
&device->dev, NULL,
&fujitsu_bl_ops, &props);
if (IS_ERR(bd))
return PTR_ERR(bd);
fujitsu_bl->bl_device = bd;
return 0;
}
static int acpi_fujitsu_bl_add(struct acpi_device *device)
{
int state = 0;
int error;
if (acpi_video_get_backlight_type() != acpi_backlight_vendor)
return -ENODEV;
if (!device)
return -EINVAL;
fujitsu_bl->acpi_handle = device->handle;
sprintf(acpi_device_name(device), "%s", ACPI_FUJITSU_BL_DEVICE_NAME);
sprintf(acpi_device_class(device), "%s", ACPI_FUJITSU_CLASS);
device->driver_data = fujitsu_bl;
error = acpi_fujitsu_bl_input_setup(device);
if (error)
return error;
error = acpi_bus_update_power(fujitsu_bl->acpi_handle, &state);
if (error) {
pr_err("Error reading power state\n");
return error;
}
pr_info("ACPI: %s [%s] (%s)\n",
acpi_device_name(device), acpi_device_bid(device),
!device->power.state ? "on" : "off");
if (acpi_has_method(device->handle, METHOD_NAME__INI)) {
vdbg_printk(FUJLAPTOP_DBG_INFO, "Invoking _INI\n");
if (ACPI_FAILURE
(acpi_evaluate_object
(device->handle, METHOD_NAME__INI, NULL, NULL)))
pr_err("_INI Method failed\n");
}
if (get_max_brightness() <= 0)
fujitsu_bl->max_brightness = FUJITSU_LCD_N_LEVELS;
get_lcd_level();
error = fujitsu_backlight_register(device);
if (error)
return error;
return 0;
}
static void acpi_fujitsu_bl_notify(struct acpi_device *device, u32 event)
{
struct input_dev *input;
int oldb, newb;
input = fujitsu_bl->input;
if (event != ACPI_FUJITSU_NOTIFY_CODE1) {
vdbg_printk(FUJLAPTOP_DBG_WARN,
"unsupported event [0x%x]\n", event);
sparse_keymap_report_event(input, -1, 1, true);
return;
}
oldb = fujitsu_bl->brightness_level;
get_lcd_level();
newb = fujitsu_bl->brightness_level;
vdbg_printk(FUJLAPTOP_DBG_TRACE, "brightness button event [%i -> %i]\n",
oldb, newb);
if (oldb == newb)
return;
if (!disable_brightness_adjust)
set_lcd_level(newb);
sparse_keymap_report_event(input, oldb < newb, 1, true);
}
static int fujitsu_laptop_dmi_keymap_override(const struct dmi_system_id *id)
{
pr_info("Identified laptop model '%s'\n", id->ident);
keymap = id->driver_data;
return 1;
}
static int acpi_fujitsu_laptop_input_setup(struct acpi_device *device)
{
struct fujitsu_laptop *fujitsu_laptop = acpi_driver_data(device);
int ret;
fujitsu_laptop->input = devm_input_allocate_device(&device->dev);
if (!fujitsu_laptop->input)
return -ENOMEM;
snprintf(fujitsu_laptop->phys, sizeof(fujitsu_laptop->phys),
"%s/video/input0", acpi_device_hid(device));
fujitsu_laptop->input->name = acpi_device_name(device);
fujitsu_laptop->input->phys = fujitsu_laptop->phys;
fujitsu_laptop->input->id.bustype = BUS_HOST;
fujitsu_laptop->input->id.product = 0x06;
dmi_check_system(fujitsu_laptop_dmi_table);
ret = sparse_keymap_setup(fujitsu_laptop->input, keymap, NULL);
if (ret)
return ret;
return input_register_device(fujitsu_laptop->input);
}
static int fujitsu_laptop_platform_add(void)
{
int ret;
fujitsu_laptop->pf_device = platform_device_alloc("fujitsu-laptop", -1);
if (!fujitsu_laptop->pf_device)
return -ENOMEM;
ret = platform_device_add(fujitsu_laptop->pf_device);
if (ret)
goto err_put_platform_device;
ret = sysfs_create_group(&fujitsu_laptop->pf_device->dev.kobj,
&fujitsu_pf_attribute_group);
if (ret)
goto err_del_platform_device;
return 0;
err_del_platform_device:
platform_device_del(fujitsu_laptop->pf_device);
err_put_platform_device:
platform_device_put(fujitsu_laptop->pf_device);
return ret;
}
static void fujitsu_laptop_platform_remove(void)
{
sysfs_remove_group(&fujitsu_laptop->pf_device->dev.kobj,
&fujitsu_pf_attribute_group);
platform_device_unregister(fujitsu_laptop->pf_device);
}
static int logolamp_set(struct led_classdev *cdev,
enum led_brightness brightness)
{
int poweron = FUNC_LED_ON, always = FUNC_LED_ON;
int ret;
if (brightness < LED_HALF)
poweron = FUNC_LED_OFF;
if (brightness < LED_FULL)
always = FUNC_LED_OFF;
ret = call_fext_func(FUNC_LEDS, 0x1, LOGOLAMP_POWERON, poweron);
if (ret < 0)
return ret;
return call_fext_func(FUNC_LEDS, 0x1, LOGOLAMP_ALWAYS, always);
}
static enum led_brightness logolamp_get(struct led_classdev *cdev)
{
int ret;
ret = call_fext_func(FUNC_LEDS, 0x2, LOGOLAMP_ALWAYS, 0x0);
if (ret == FUNC_LED_ON)
return LED_FULL;
ret = call_fext_func(FUNC_LEDS, 0x2, LOGOLAMP_POWERON, 0x0);
if (ret == FUNC_LED_ON)
return LED_HALF;
return LED_OFF;
}
static int kblamps_set(struct led_classdev *cdev,
enum led_brightness brightness)
{
if (brightness >= LED_FULL)
return call_fext_func(FUNC_LEDS, 0x1, KEYBOARD_LAMPS,
FUNC_LED_ON);
else
return call_fext_func(FUNC_LEDS, 0x1, KEYBOARD_LAMPS,
FUNC_LED_OFF);
}
static enum led_brightness kblamps_get(struct led_classdev *cdev)
{
enum led_brightness brightness = LED_OFF;
if (call_fext_func(FUNC_LEDS, 0x2, KEYBOARD_LAMPS, 0x0) == FUNC_LED_ON)
brightness = LED_FULL;
return brightness;
}
static int radio_led_set(struct led_classdev *cdev,
enum led_brightness brightness)
{
if (brightness >= LED_FULL)
return call_fext_func(FUNC_FLAGS, 0x5, RADIO_LED_ON,
RADIO_LED_ON);
else
return call_fext_func(FUNC_FLAGS, 0x5, RADIO_LED_ON, 0x0);
}
static enum led_brightness radio_led_get(struct led_classdev *cdev)
{
enum led_brightness brightness = LED_OFF;
if (call_fext_func(FUNC_FLAGS, 0x4, 0x0, 0x0) & RADIO_LED_ON)
brightness = LED_FULL;
return brightness;
}
static int eco_led_set(struct led_classdev *cdev,
enum led_brightness brightness)
{
int curr;
curr = call_fext_func(FUNC_LEDS, 0x2, ECO_LED, 0x0);
if (brightness >= LED_FULL)
return call_fext_func(FUNC_LEDS, 0x1, ECO_LED,
curr | ECO_LED_ON);
else
return call_fext_func(FUNC_LEDS, 0x1, ECO_LED,
curr & ~ECO_LED_ON);
}
static enum led_brightness eco_led_get(struct led_classdev *cdev)
{
enum led_brightness brightness = LED_OFF;
if (call_fext_func(FUNC_LEDS, 0x2, ECO_LED, 0x0) & ECO_LED_ON)
brightness = LED_FULL;
return brightness;
}
static int acpi_fujitsu_laptop_leds_register(struct acpi_device *device)
{
int result;
if (call_fext_func(FUNC_LEDS, 0x0, 0x0, 0x0) & LOGOLAMP_POWERON) {
result = devm_led_classdev_register(&device->dev,
&logolamp_led);
if (result)
return result;
}
if ((call_fext_func(FUNC_LEDS, 0x0, 0x0, 0x0) & KEYBOARD_LAMPS) &&
(call_fext_func(FUNC_BUTTONS, 0x0, 0x0, 0x0) == 0x0)) {
result = devm_led_classdev_register(&device->dev, &kblamps_led);
if (result)
return result;
}
if (call_fext_func(FUNC_BUTTONS, 0x0, 0x0, 0x0) & BIT(24)) {
result = devm_led_classdev_register(&device->dev, &radio_led);
if (result)
return result;
}
if ((call_fext_func(FUNC_LEDS, 0x0, 0x0, 0x0) & BIT(14)) &&
(call_fext_func(FUNC_LEDS, 0x2, ECO_LED, 0x0) != UNSUPPORTED_CMD)) {
result = devm_led_classdev_register(&device->dev, &eco_led);
if (result)
return result;
}
return 0;
}
static int acpi_fujitsu_laptop_add(struct acpi_device *device)
{
int state = 0;
int error;
int i;
if (!device)
return -EINVAL;
fujitsu_laptop->acpi_handle = device->handle;
sprintf(acpi_device_name(device), "%s",
ACPI_FUJITSU_LAPTOP_DEVICE_NAME);
sprintf(acpi_device_class(device), "%s", ACPI_FUJITSU_CLASS);
device->driver_data = fujitsu_laptop;
spin_lock_init(&fujitsu_laptop->fifo_lock);
error = kfifo_alloc(&fujitsu_laptop->fifo, RINGBUFFERSIZE * sizeof(int),
GFP_KERNEL);
if (error) {
pr_err("kfifo_alloc failed\n");
goto err_stop;
}
error = acpi_fujitsu_laptop_input_setup(device);
if (error)
goto err_free_fifo;
error = acpi_bus_update_power(fujitsu_laptop->acpi_handle, &state);
if (error) {
pr_err("Error reading power state\n");
goto err_free_fifo;
}
pr_info("ACPI: %s [%s] (%s)\n",
acpi_device_name(device), acpi_device_bid(device),
!device->power.state ? "on" : "off");
fujitsu_laptop->dev = device;
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
fujitsu_laptop->flags_supported =
call_fext_func(FUNC_FLAGS, 0x0, 0x0, 0x0);
if (fujitsu_laptop->flags_supported == UNSUPPORTED_CMD)
fujitsu_laptop->flags_supported = 0;
if (fujitsu_laptop->flags_supported)
fujitsu_laptop->flags_state =
call_fext_func(FUNC_FLAGS, 0x4, 0x0, 0x0);
pr_info("BTNI: [0x%x]\n", call_fext_func(FUNC_BUTTONS, 0x0, 0x0, 0x0));
if (fujitsu_bl->bl_device &&
acpi_video_get_backlight_type() == acpi_backlight_vendor) {
if (call_fext_func(FUNC_BACKLIGHT, 0x2, 0x4, 0x0) == 3)
fujitsu_bl->bl_device->props.power = FB_BLANK_POWERDOWN;
else
fujitsu_bl->bl_device->props.power = FB_BLANK_UNBLANK;
}
error = acpi_fujitsu_laptop_leds_register(device);
if (error)
goto err_free_fifo;
error = fujitsu_laptop_platform_add();
if (error)
goto err_free_fifo;
return 0;
err_free_fifo:
kfifo_free(&fujitsu_laptop->fifo);
err_stop:
return error;
}
static int acpi_fujitsu_laptop_remove(struct acpi_device *device)
{
struct fujitsu_laptop *fujitsu_laptop = acpi_driver_data(device);
fujitsu_laptop_platform_remove();
kfifo_free(&fujitsu_laptop->fifo);
return 0;
}
static void acpi_fujitsu_laptop_press(int scancode)
{
struct input_dev *input = fujitsu_laptop->input;
int status;
status = kfifo_in_locked(&fujitsu_laptop->fifo,
(unsigned char *)&scancode, sizeof(scancode),
&fujitsu_laptop->fifo_lock);
if (status != sizeof(scancode)) {
vdbg_printk(FUJLAPTOP_DBG_WARN,
"Could not push scancode [0x%x]\n", scancode);
return;
}
sparse_keymap_report_event(input, scancode, 1, false);
vdbg_printk(FUJLAPTOP_DBG_TRACE,
"Push scancode into ringbuffer [0x%x]\n", scancode);
}
static void acpi_fujitsu_laptop_release(void)
{
struct input_dev *input = fujitsu_laptop->input;
int scancode, status;
while (true) {
status = kfifo_out_locked(&fujitsu_laptop->fifo,
(unsigned char *)&scancode,
sizeof(scancode),
&fujitsu_laptop->fifo_lock);
if (status != sizeof(scancode))
return;
sparse_keymap_report_event(input, scancode, 0, false);
vdbg_printk(FUJLAPTOP_DBG_TRACE,
"Pop scancode from ringbuffer [0x%x]\n", scancode);
}
}
static void acpi_fujitsu_laptop_notify(struct acpi_device *device, u32 event)
{
struct input_dev *input;
int scancode, i = 0;
unsigned int irb;
input = fujitsu_laptop->input;
if (event != ACPI_FUJITSU_NOTIFY_CODE1) {
vdbg_printk(FUJLAPTOP_DBG_WARN,
"Unsupported event [0x%x]\n", event);
sparse_keymap_report_event(input, -1, 1, true);
return;
}
if (fujitsu_laptop->flags_supported)
fujitsu_laptop->flags_state =
call_fext_func(FUNC_FLAGS, 0x4, 0x0, 0x0);
while ((irb = call_fext_func(FUNC_BUTTONS, 0x1, 0x0, 0x0)) != 0 &&
i++ < MAX_HOTKEY_RINGBUFFER_SIZE) {
scancode = irb & 0x4ff;
if (sparse_keymap_entry_from_scancode(input, scancode))
acpi_fujitsu_laptop_press(scancode);
else if (scancode == 0)
acpi_fujitsu_laptop_release();
else
vdbg_printk(FUJLAPTOP_DBG_WARN,
"Unknown GIRB result [%x]\n", irb);
}
if ((fujitsu_laptop->flags_supported & BIT(26)) &&
(call_fext_func(FUNC_FLAGS, 0x1, 0x0, 0x0) & BIT(26)))
sparse_keymap_report_event(input, BIT(26), 1, true);
}
static int __init fujitsu_init(void)
{
int ret;
if (acpi_disabled)
return -ENODEV;
fujitsu_bl = kzalloc(sizeof(struct fujitsu_bl), GFP_KERNEL);
if (!fujitsu_bl)
return -ENOMEM;
ret = acpi_bus_register_driver(&acpi_fujitsu_bl_driver);
if (ret)
goto err_free_fujitsu_bl;
ret = platform_driver_register(&fujitsu_pf_driver);
if (ret)
goto err_unregister_acpi;
fujitsu_laptop = kzalloc(sizeof(struct fujitsu_laptop), GFP_KERNEL);
if (!fujitsu_laptop) {
ret = -ENOMEM;
goto err_unregister_platform_driver;
}
ret = acpi_bus_register_driver(&acpi_fujitsu_laptop_driver);
if (ret)
goto err_free_fujitsu_laptop;
pr_info("driver " FUJITSU_DRIVER_VERSION " successfully loaded\n");
return 0;
err_free_fujitsu_laptop:
kfree(fujitsu_laptop);
err_unregister_platform_driver:
platform_driver_unregister(&fujitsu_pf_driver);
err_unregister_acpi:
acpi_bus_unregister_driver(&acpi_fujitsu_bl_driver);
err_free_fujitsu_bl:
kfree(fujitsu_bl);
return ret;
}
static void __exit fujitsu_cleanup(void)
{
acpi_bus_unregister_driver(&acpi_fujitsu_laptop_driver);
kfree(fujitsu_laptop);
platform_driver_unregister(&fujitsu_pf_driver);
acpi_bus_unregister_driver(&acpi_fujitsu_bl_driver);
kfree(fujitsu_bl);
pr_info("driver unloaded\n");
}
