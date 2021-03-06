static int oaktrail_rfkill_set(void *data, bool blocked)
{
u8 value;
u8 result;
unsigned long radio = (unsigned long) data;
ec_read(OT_EC_DEVICE_STATE_ADDRESS, &result);
if (!blocked)
value = (u8) (result | radio);
else
value = (u8) (result & ~radio);
ec_write(OT_EC_DEVICE_STATE_ADDRESS, value);
return 0;
}
static struct rfkill *oaktrail_rfkill_new(char *name, enum rfkill_type type,
unsigned long mask)
{
struct rfkill *rfkill_dev;
u8 value;
int err;
rfkill_dev = rfkill_alloc(name, &oaktrail_device->dev, type,
&oaktrail_rfkill_ops, (void *)mask);
if (!rfkill_dev)
return ERR_PTR(-ENOMEM);
ec_read(OT_EC_DEVICE_STATE_ADDRESS, &value);
rfkill_init_sw_state(rfkill_dev, (value & mask) != 1);
err = rfkill_register(rfkill_dev);
if (err) {
rfkill_destroy(rfkill_dev);
return ERR_PTR(err);
}
return rfkill_dev;
}
static inline void __oaktrail_rfkill_cleanup(struct rfkill *rf)
{
if (rf) {
rfkill_unregister(rf);
rfkill_destroy(rf);
}
}
static void oaktrail_rfkill_cleanup(void)
{
__oaktrail_rfkill_cleanup(wifi_rfkill);
__oaktrail_rfkill_cleanup(bt_rfkill);
__oaktrail_rfkill_cleanup(gps_rfkill);
__oaktrail_rfkill_cleanup(wwan_rfkill);
}
static int oaktrail_rfkill_init(void)
{
int ret;
wifi_rfkill = oaktrail_rfkill_new("oaktrail-wifi",
RFKILL_TYPE_WLAN,
OT_EC_WIFI_MASK);
if (IS_ERR(wifi_rfkill)) {
ret = PTR_ERR(wifi_rfkill);
wifi_rfkill = NULL;
goto cleanup;
}
bt_rfkill = oaktrail_rfkill_new("oaktrail-bluetooth",
RFKILL_TYPE_BLUETOOTH,
OT_EC_BT_MASK);
if (IS_ERR(bt_rfkill)) {
ret = PTR_ERR(bt_rfkill);
bt_rfkill = NULL;
goto cleanup;
}
gps_rfkill = oaktrail_rfkill_new("oaktrail-gps",
RFKILL_TYPE_GPS,
OT_EC_GPS_MASK);
if (IS_ERR(gps_rfkill)) {
ret = PTR_ERR(gps_rfkill);
gps_rfkill = NULL;
goto cleanup;
}
wwan_rfkill = oaktrail_rfkill_new("oaktrail-wwan",
RFKILL_TYPE_WWAN,
OT_EC_WWAN_MASK);
if (IS_ERR(wwan_rfkill)) {
ret = PTR_ERR(wwan_rfkill);
wwan_rfkill = NULL;
goto cleanup;
}
return 0;
cleanup:
oaktrail_rfkill_cleanup();
return ret;
}
static int get_backlight_brightness(struct backlight_device *b)
{
u8 value;
ec_read(OT_EC_BL_BRIGHTNESS_ADDRESS, &value);
return value;
}
static int set_backlight_brightness(struct backlight_device *b)
{
u8 percent = (u8) b->props.brightness;
if (percent < 0 || percent > OT_EC_BL_BRIGHTNESS_MAX)
return -EINVAL;
ec_write(OT_EC_BL_BRIGHTNESS_ADDRESS, percent);
ec_write(OT_EC_BL_CONTROL_ADDRESS, OT_EC_BL_CONTROL_ON_DATA);
return 0;
}
static int oaktrail_backlight_init(void)
{
struct backlight_device *bd;
struct backlight_properties props;
memset(&props, 0, sizeof(struct backlight_properties));
props.type = BACKLIGHT_PLATFORM;
props.max_brightness = OT_EC_BL_BRIGHTNESS_MAX;
bd = backlight_device_register(DRIVER_NAME,
&oaktrail_device->dev, NULL,
&oaktrail_bl_ops,
&props);
if (IS_ERR(bd)) {
oaktrail_bl_device = NULL;
pr_warning("Unable to register backlight device\n");
return PTR_ERR(bd);
}
oaktrail_bl_device = bd;
bd->props.brightness = get_backlight_brightness(bd);
bd->props.power = FB_BLANK_UNBLANK;
backlight_update_status(bd);
return 0;
}
static void oaktrail_backlight_exit(void)
{
if (oaktrail_bl_device)
backlight_device_unregister(oaktrail_bl_device);
}
static int __devinit oaktrail_probe(struct platform_device *pdev)
{
return 0;
}
static int __devexit oaktrail_remove(struct platform_device *pdev)
{
return 0;
}
static int dmi_check_cb(const struct dmi_system_id *id)
{
pr_info("Identified model '%s'\n", id->ident);
return 0;
}
static int __init oaktrail_init(void)
{
int ret;
if (acpi_disabled) {
pr_err("ACPI needs to be enabled for this driver to work!\n");
return -ENODEV;
}
if (!force && !dmi_check_system(oaktrail_dmi_table)) {
pr_err("Platform not recognized (You could try the module's force-parameter)");
return -ENODEV;
}
ret = platform_driver_register(&oaktrail_driver);
if (ret) {
pr_warning("Unable to register platform driver\n");
goto err_driver_reg;
}
oaktrail_device = platform_device_alloc(DRIVER_NAME, -1);
if (!oaktrail_device) {
pr_warning("Unable to allocate platform device\n");
ret = -ENOMEM;
goto err_device_alloc;
}
ret = platform_device_add(oaktrail_device);
if (ret) {
pr_warning("Unable to add platform device\n");
goto err_device_add;
}
if (!acpi_video_backlight_support()) {
ret = oaktrail_backlight_init();
if (ret)
goto err_backlight;
} else
pr_info("Backlight controlled by ACPI video driver\n");
ret = oaktrail_rfkill_init();
if (ret) {
pr_warning("Setup rfkill failed\n");
goto err_rfkill;
}
pr_info("Driver "DRIVER_VERSION" successfully loaded\n");
return 0;
err_rfkill:
oaktrail_backlight_exit();
err_backlight:
platform_device_del(oaktrail_device);
err_device_add:
platform_device_put(oaktrail_device);
err_device_alloc:
platform_driver_unregister(&oaktrail_driver);
err_driver_reg:
return ret;
}
static void __exit oaktrail_cleanup(void)
{
oaktrail_backlight_exit();
oaktrail_rfkill_cleanup();
platform_device_unregister(oaktrail_device);
platform_driver_unregister(&oaktrail_driver);
pr_info("Driver unloaded\n");
}
