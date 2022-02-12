static int call_fext_func(struct acpi_device *device,
int func, int op, int feature, int state)
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
status = acpi_evaluate_integer(device->handle, "FUNC", &arg_list,
&value);
if (ACPI_FAILURE(status)) {
acpi_handle_err(device->handle, "Failed to evaluate FUNC\n");
return -ENODEV;
}
acpi_handle_debug(device->handle,
"FUNC 0x%x (args 0x%x, 0x%x, 0x%x) returned 0x%x\n",
func, op, feature, state, (int)value);
return value;
}
static int set_lcd_level(struct acpi_device *device, int level)
{
struct fujitsu_bl *priv = acpi_driver_data(device);
acpi_status status;
char *method;
switch (use_alt_lcd_levels) {
case -1:
if (acpi_has_method(device->handle, "SBL2"))
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
acpi_handle_debug(device->handle, "set lcd level via %s [%d]\n", method,
level);
if (level < 0 || level >= priv->max_brightness)
return -EINVAL;
status = acpi_execute_simple_method(device->handle, method, level);
if (ACPI_FAILURE(status)) {
acpi_handle_err(device->handle, "Failed to evaluate %s\n",
method);
return -ENODEV;
}
priv->brightness_level = level;
return 0;
}
static int get_lcd_level(struct acpi_device *device)
{
struct fujitsu_bl *priv = acpi_driver_data(device);
unsigned long long state = 0;
acpi_status status = AE_OK;
acpi_handle_debug(device->handle, "get lcd level via GBLL\n");
status = acpi_evaluate_integer(device->handle, "GBLL", NULL, &state);
if (ACPI_FAILURE(status))
return 0;
priv->brightness_level = state & 0x0fffffff;
return priv->brightness_level;
}
static int get_max_brightness(struct acpi_device *device)
{
struct fujitsu_bl *priv = acpi_driver_data(device);
unsigned long long state = 0;
acpi_status status = AE_OK;
acpi_handle_debug(device->handle, "get max lcd level via RBLL\n");
status = acpi_evaluate_integer(device->handle, "RBLL", NULL, &state);
if (ACPI_FAILURE(status))
return -1;
priv->max_brightness = state;
return priv->max_brightness;
}
static int bl_get_brightness(struct backlight_device *b)
{
struct acpi_device *device = bl_get_data(b);
return b->props.power == FB_BLANK_POWERDOWN ? 0 : get_lcd_level(device);
}
static int bl_update_status(struct backlight_device *b)
{
struct acpi_device *device = bl_get_data(b);
if (fext) {
if (b->props.power == FB_BLANK_POWERDOWN)
call_fext_func(fext, FUNC_BACKLIGHT, 0x1, 0x4, 0x3);
else
call_fext_func(fext, FUNC_BACKLIGHT, 0x1, 0x4, 0x0);
}
return set_lcd_level(device, b->props.brightness);
}
static ssize_t lid_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct fujitsu_laptop *priv = dev_get_drvdata(dev);
if (!(priv->flags_supported & FLAG_LID))
return sprintf(buf, "unknown\n");
if (priv->flags_state & FLAG_LID)
return sprintf(buf, "open\n");
else
return sprintf(buf, "closed\n");
}
static ssize_t dock_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct fujitsu_laptop *priv = dev_get_drvdata(dev);
if (!(priv->flags_supported & FLAG_DOCK))
return sprintf(buf, "unknown\n");
if (priv->flags_state & FLAG_DOCK)
return sprintf(buf, "docked\n");
else
return sprintf(buf, "undocked\n");
}
static ssize_t radios_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct fujitsu_laptop *priv = dev_get_drvdata(dev);
if (!(priv->flags_supported & FLAG_RFKILL))
return sprintf(buf, "unknown\n");
if (priv->flags_state & FLAG_RFKILL)
return sprintf(buf, "on\n");
else
return sprintf(buf, "killed\n");
}
static int acpi_fujitsu_bl_input_setup(struct acpi_device *device)
{
struct fujitsu_bl *priv = acpi_driver_data(device);
int ret;
priv->input = devm_input_allocate_device(&device->dev);
if (!priv->input)
return -ENOMEM;
snprintf(priv->phys, sizeof(priv->phys), "%s/video/input0",
acpi_device_hid(device));
priv->input->name = acpi_device_name(device);
priv->input->phys = priv->phys;
priv->input->id.bustype = BUS_HOST;
priv->input->id.product = 0x06;
ret = sparse_keymap_setup(priv->input, keymap_backlight, NULL);
if (ret)
return ret;
return input_register_device(priv->input);
}
static int fujitsu_backlight_register(struct acpi_device *device)
{
struct fujitsu_bl *priv = acpi_driver_data(device);
const struct backlight_properties props = {
.brightness = priv->brightness_level,
.max_brightness = priv->max_brightness - 1,
.type = BACKLIGHT_PLATFORM
};
struct backlight_device *bd;
bd = devm_backlight_device_register(&device->dev, "fujitsu-laptop",
&device->dev, device,
&fujitsu_bl_ops, &props);
if (IS_ERR(bd))
return PTR_ERR(bd);
priv->bl_device = bd;
return 0;
}
static int acpi_fujitsu_bl_add(struct acpi_device *device)
{
struct fujitsu_bl *priv;
int error;
if (acpi_video_get_backlight_type() != acpi_backlight_vendor)
return -ENODEV;
priv = devm_kzalloc(&device->dev, sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
fujitsu_bl = priv;
strcpy(acpi_device_name(device), ACPI_FUJITSU_BL_DEVICE_NAME);
strcpy(acpi_device_class(device), ACPI_FUJITSU_CLASS);
device->driver_data = priv;
error = acpi_fujitsu_bl_input_setup(device);
if (error)
return error;
pr_info("ACPI: %s [%s]\n",
acpi_device_name(device), acpi_device_bid(device));
if (get_max_brightness(device) <= 0)
priv->max_brightness = FUJITSU_LCD_N_LEVELS;
get_lcd_level(device);
error = fujitsu_backlight_register(device);
if (error)
return error;
return 0;
}
static void acpi_fujitsu_bl_notify(struct acpi_device *device, u32 event)
{
struct fujitsu_bl *priv = acpi_driver_data(device);
int oldb, newb;
if (event != ACPI_FUJITSU_NOTIFY_CODE1) {
acpi_handle_info(device->handle, "unsupported event [0x%x]\n",
event);
sparse_keymap_report_event(priv->input, -1, 1, true);
return;
}
oldb = priv->brightness_level;
get_lcd_level(device);
newb = priv->brightness_level;
acpi_handle_debug(device->handle,
"brightness button event [%i -> %i]\n", oldb, newb);
if (oldb == newb)
return;
if (!disable_brightness_adjust)
set_lcd_level(device, newb);
sparse_keymap_report_event(priv->input, oldb < newb, 1, true);
}
static int fujitsu_laptop_dmi_keymap_override(const struct dmi_system_id *id)
{
pr_info("Identified laptop model '%s'\n", id->ident);
keymap = id->driver_data;
return 1;
}
static int acpi_fujitsu_laptop_input_setup(struct acpi_device *device)
{
struct fujitsu_laptop *priv = acpi_driver_data(device);
int ret;
priv->input = devm_input_allocate_device(&device->dev);
if (!priv->input)
return -ENOMEM;
snprintf(priv->phys, sizeof(priv->phys), "%s/input0",
acpi_device_hid(device));
priv->input->name = acpi_device_name(device);
priv->input->phys = priv->phys;
priv->input->id.bustype = BUS_HOST;
dmi_check_system(fujitsu_laptop_dmi_table);
ret = sparse_keymap_setup(priv->input, keymap, NULL);
if (ret)
return ret;
return input_register_device(priv->input);
}
static int fujitsu_laptop_platform_add(struct acpi_device *device)
{
struct fujitsu_laptop *priv = acpi_driver_data(device);
int ret;
priv->pf_device = platform_device_alloc("fujitsu-laptop", -1);
if (!priv->pf_device)
return -ENOMEM;
platform_set_drvdata(priv->pf_device, priv);
ret = platform_device_add(priv->pf_device);
if (ret)
goto err_put_platform_device;
ret = sysfs_create_group(&priv->pf_device->dev.kobj,
&fujitsu_pf_attribute_group);
if (ret)
goto err_del_platform_device;
return 0;
err_del_platform_device:
platform_device_del(priv->pf_device);
err_put_platform_device:
platform_device_put(priv->pf_device);
return ret;
}
static void fujitsu_laptop_platform_remove(struct acpi_device *device)
{
struct fujitsu_laptop *priv = acpi_driver_data(device);
sysfs_remove_group(&priv->pf_device->dev.kobj,
&fujitsu_pf_attribute_group);
platform_device_unregister(priv->pf_device);
}
static int logolamp_set(struct led_classdev *cdev,
enum led_brightness brightness)
{
struct acpi_device *device = to_acpi_device(cdev->dev->parent);
int poweron = FUNC_LED_ON, always = FUNC_LED_ON;
int ret;
if (brightness < LED_HALF)
poweron = FUNC_LED_OFF;
if (brightness < LED_FULL)
always = FUNC_LED_OFF;
ret = call_fext_func(device, FUNC_LEDS, 0x1, LOGOLAMP_POWERON, poweron);
if (ret < 0)
return ret;
return call_fext_func(device, FUNC_LEDS, 0x1, LOGOLAMP_ALWAYS, always);
}
static enum led_brightness logolamp_get(struct led_classdev *cdev)
{
struct acpi_device *device = to_acpi_device(cdev->dev->parent);
int ret;
ret = call_fext_func(device, FUNC_LEDS, 0x2, LOGOLAMP_ALWAYS, 0x0);
if (ret == FUNC_LED_ON)
return LED_FULL;
ret = call_fext_func(device, FUNC_LEDS, 0x2, LOGOLAMP_POWERON, 0x0);
if (ret == FUNC_LED_ON)
return LED_HALF;
return LED_OFF;
}
static int kblamps_set(struct led_classdev *cdev,
enum led_brightness brightness)
{
struct acpi_device *device = to_acpi_device(cdev->dev->parent);
if (brightness >= LED_FULL)
return call_fext_func(device, FUNC_LEDS, 0x1, KEYBOARD_LAMPS,
FUNC_LED_ON);
else
return call_fext_func(device, FUNC_LEDS, 0x1, KEYBOARD_LAMPS,
FUNC_LED_OFF);
}
static enum led_brightness kblamps_get(struct led_classdev *cdev)
{
struct acpi_device *device = to_acpi_device(cdev->dev->parent);
enum led_brightness brightness = LED_OFF;
if (call_fext_func(device,
FUNC_LEDS, 0x2, KEYBOARD_LAMPS, 0x0) == FUNC_LED_ON)
brightness = LED_FULL;
return brightness;
}
static int radio_led_set(struct led_classdev *cdev,
enum led_brightness brightness)
{
struct acpi_device *device = to_acpi_device(cdev->dev->parent);
if (brightness >= LED_FULL)
return call_fext_func(device, FUNC_FLAGS, 0x5, RADIO_LED_ON,
RADIO_LED_ON);
else
return call_fext_func(device, FUNC_FLAGS, 0x5, RADIO_LED_ON,
0x0);
}
static enum led_brightness radio_led_get(struct led_classdev *cdev)
{
struct acpi_device *device = to_acpi_device(cdev->dev->parent);
enum led_brightness brightness = LED_OFF;
if (call_fext_func(device, FUNC_FLAGS, 0x4, 0x0, 0x0) & RADIO_LED_ON)
brightness = LED_FULL;
return brightness;
}
static int eco_led_set(struct led_classdev *cdev,
enum led_brightness brightness)
{
struct acpi_device *device = to_acpi_device(cdev->dev->parent);
int curr;
curr = call_fext_func(device, FUNC_LEDS, 0x2, ECO_LED, 0x0);
if (brightness >= LED_FULL)
return call_fext_func(device, FUNC_LEDS, 0x1, ECO_LED,
curr | ECO_LED_ON);
else
return call_fext_func(device, FUNC_LEDS, 0x1, ECO_LED,
curr & ~ECO_LED_ON);
}
static enum led_brightness eco_led_get(struct led_classdev *cdev)
{
struct acpi_device *device = to_acpi_device(cdev->dev->parent);
enum led_brightness brightness = LED_OFF;
if (call_fext_func(device, FUNC_LEDS, 0x2, ECO_LED, 0x0) & ECO_LED_ON)
brightness = LED_FULL;
return brightness;
}
static int acpi_fujitsu_laptop_leds_register(struct acpi_device *device)
{
struct led_classdev *led;
int result;
if (call_fext_func(device,
FUNC_LEDS, 0x0, 0x0, 0x0) & LOGOLAMP_POWERON) {
led = devm_kzalloc(&device->dev, sizeof(*led), GFP_KERNEL);
if (!led)
return -ENOMEM;
led->name = "fujitsu::logolamp";
led->brightness_set_blocking = logolamp_set;
led->brightness_get = logolamp_get;
result = devm_led_classdev_register(&device->dev, led);
if (result)
return result;
}
if ((call_fext_func(device,
FUNC_LEDS, 0x0, 0x0, 0x0) & KEYBOARD_LAMPS) &&
(call_fext_func(device, FUNC_BUTTONS, 0x0, 0x0, 0x0) == 0x0)) {
led = devm_kzalloc(&device->dev, sizeof(*led), GFP_KERNEL);
if (!led)
return -ENOMEM;
led->name = "fujitsu::kblamps";
led->brightness_set_blocking = kblamps_set;
led->brightness_get = kblamps_get;
result = devm_led_classdev_register(&device->dev, led);
if (result)
return result;
}
if (call_fext_func(device, FUNC_BUTTONS, 0x0, 0x0, 0x0) & BIT(24)) {
led = devm_kzalloc(&device->dev, sizeof(*led), GFP_KERNEL);
if (!led)
return -ENOMEM;
led->name = "fujitsu::radio_led";
led->brightness_set_blocking = radio_led_set;
led->brightness_get = radio_led_get;
led->default_trigger = "rfkill-any";
result = devm_led_classdev_register(&device->dev, led);
if (result)
return result;
}
if ((call_fext_func(device, FUNC_LEDS, 0x0, 0x0, 0x0) & BIT(14)) &&
(call_fext_func(device,
FUNC_LEDS, 0x2, ECO_LED, 0x0) != UNSUPPORTED_CMD)) {
led = devm_kzalloc(&device->dev, sizeof(*led), GFP_KERNEL);
if (!led)
return -ENOMEM;
led->name = "fujitsu::eco_led";
led->brightness_set_blocking = eco_led_set;
led->brightness_get = eco_led_get;
result = devm_led_classdev_register(&device->dev, led);
if (result)
return result;
}
return 0;
}
static int acpi_fujitsu_laptop_add(struct acpi_device *device)
{
struct fujitsu_laptop *priv;
int error;
int i;
priv = devm_kzalloc(&device->dev, sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
WARN_ONCE(fext, "More than one FUJ02E3 ACPI device was found. Driver may not work as intended.");
fext = device;
strcpy(acpi_device_name(device), ACPI_FUJITSU_LAPTOP_DEVICE_NAME);
strcpy(acpi_device_class(device), ACPI_FUJITSU_CLASS);
device->driver_data = priv;
spin_lock_init(&priv->fifo_lock);
error = kfifo_alloc(&priv->fifo, RINGBUFFERSIZE * sizeof(int),
GFP_KERNEL);
if (error) {
pr_err("kfifo_alloc failed\n");
goto err_stop;
}
error = acpi_fujitsu_laptop_input_setup(device);
if (error)
goto err_free_fifo;
pr_info("ACPI: %s [%s]\n",
acpi_device_name(device), acpi_device_bid(device));
i = 0;
while (call_fext_func(device, FUNC_BUTTONS, 0x1, 0x0, 0x0) != 0
&& (i++) < MAX_HOTKEY_RINGBUFFER_SIZE)
;
acpi_handle_debug(device->handle, "Discarded %i ringbuffer entries\n",
i);
priv->flags_supported = call_fext_func(device, FUNC_FLAGS, 0x0, 0x0,
0x0);
if (priv->flags_supported == UNSUPPORTED_CMD)
priv->flags_supported = 0;
if (priv->flags_supported)
priv->flags_state = call_fext_func(device, FUNC_FLAGS, 0x4, 0x0,
0x0);
acpi_handle_info(device->handle, "BTNI: [0x%x]\n",
call_fext_func(device, FUNC_BUTTONS, 0x0, 0x0, 0x0));
if (fujitsu_bl && fujitsu_bl->bl_device &&
acpi_video_get_backlight_type() == acpi_backlight_vendor) {
if (call_fext_func(fext, FUNC_BACKLIGHT, 0x2, 0x4, 0x0) == 3)
fujitsu_bl->bl_device->props.power = FB_BLANK_POWERDOWN;
else
fujitsu_bl->bl_device->props.power = FB_BLANK_UNBLANK;
}
error = acpi_fujitsu_laptop_leds_register(device);
if (error)
goto err_free_fifo;
error = fujitsu_laptop_platform_add(device);
if (error)
goto err_free_fifo;
return 0;
err_free_fifo:
kfifo_free(&priv->fifo);
err_stop:
return error;
}
static int acpi_fujitsu_laptop_remove(struct acpi_device *device)
{
struct fujitsu_laptop *priv = acpi_driver_data(device);
fujitsu_laptop_platform_remove(device);
kfifo_free(&priv->fifo);
return 0;
}
static void acpi_fujitsu_laptop_press(struct acpi_device *device, int scancode)
{
struct fujitsu_laptop *priv = acpi_driver_data(device);
int status;
status = kfifo_in_locked(&priv->fifo, (unsigned char *)&scancode,
sizeof(scancode), &priv->fifo_lock);
if (status != sizeof(scancode)) {
dev_info(&priv->input->dev, "Could not push scancode [0x%x]\n",
scancode);
return;
}
sparse_keymap_report_event(priv->input, scancode, 1, false);
dev_dbg(&priv->input->dev, "Push scancode into ringbuffer [0x%x]\n",
scancode);
}
static void acpi_fujitsu_laptop_release(struct acpi_device *device)
{
struct fujitsu_laptop *priv = acpi_driver_data(device);
int scancode, status;
while (true) {
status = kfifo_out_locked(&priv->fifo,
(unsigned char *)&scancode,
sizeof(scancode), &priv->fifo_lock);
if (status != sizeof(scancode))
return;
sparse_keymap_report_event(priv->input, scancode, 0, false);
dev_dbg(&priv->input->dev,
"Pop scancode from ringbuffer [0x%x]\n", scancode);
}
}
static void acpi_fujitsu_laptop_notify(struct acpi_device *device, u32 event)
{
struct fujitsu_laptop *priv = acpi_driver_data(device);
int scancode, i = 0;
unsigned int irb;
if (event != ACPI_FUJITSU_NOTIFY_CODE1) {
acpi_handle_info(device->handle, "Unsupported event [0x%x]\n",
event);
sparse_keymap_report_event(priv->input, -1, 1, true);
return;
}
if (priv->flags_supported)
priv->flags_state = call_fext_func(device, FUNC_FLAGS, 0x4, 0x0,
0x0);
while ((irb = call_fext_func(device,
FUNC_BUTTONS, 0x1, 0x0, 0x0)) != 0 &&
i++ < MAX_HOTKEY_RINGBUFFER_SIZE) {
scancode = irb & 0x4ff;
if (sparse_keymap_entry_from_scancode(priv->input, scancode))
acpi_fujitsu_laptop_press(device, scancode);
else if (scancode == 0)
acpi_fujitsu_laptop_release(device);
else
acpi_handle_info(device->handle,
"Unknown GIRB result [%x]\n", irb);
}
if ((priv->flags_supported & BIT(26)) &&
(call_fext_func(device, FUNC_FLAGS, 0x1, 0x0, 0x0) & BIT(26)))
sparse_keymap_report_event(priv->input, BIT(26), 1, true);
}
static int __init fujitsu_init(void)
{
int ret;
ret = acpi_bus_register_driver(&acpi_fujitsu_bl_driver);
if (ret)
return ret;
ret = platform_driver_register(&fujitsu_pf_driver);
if (ret)
goto err_unregister_acpi;
ret = acpi_bus_register_driver(&acpi_fujitsu_laptop_driver);
if (ret)
goto err_unregister_platform_driver;
pr_info("driver " FUJITSU_DRIVER_VERSION " successfully loaded\n");
return 0;
err_unregister_platform_driver:
platform_driver_unregister(&fujitsu_pf_driver);
err_unregister_acpi:
acpi_bus_unregister_driver(&acpi_fujitsu_bl_driver);
return ret;
}
static void __exit fujitsu_cleanup(void)
{
acpi_bus_unregister_driver(&acpi_fujitsu_laptop_driver);
platform_driver_unregister(&fujitsu_pf_driver);
acpi_bus_unregister_driver(&acpi_fujitsu_bl_driver);
pr_info("driver unloaded\n");
}
