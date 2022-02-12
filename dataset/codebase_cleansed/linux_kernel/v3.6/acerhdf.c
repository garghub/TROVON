static int acerhdf_get_temp(int *temp)
{
u8 read_temp;
if (ec_read(bios_cfg->tempreg, &read_temp))
return -EINVAL;
*temp = read_temp * 1000;
return 0;
}
static int acerhdf_get_fanstate(int *state)
{
u8 fan;
if (ec_read(bios_cfg->fanreg, &fan))
return -EINVAL;
if (fan != bios_cfg->cmd.cmd_off)
*state = ACERHDF_FAN_AUTO;
else
*state = ACERHDF_FAN_OFF;
return 0;
}
static void acerhdf_change_fanstate(int state)
{
unsigned char cmd;
if (verbose)
pr_notice("fan %s\n", state == ACERHDF_FAN_OFF ? "OFF" : "ON");
if ((state != ACERHDF_FAN_OFF) && (state != ACERHDF_FAN_AUTO)) {
pr_err("invalid fan state %d requested, setting to auto!\n",
state);
state = ACERHDF_FAN_AUTO;
}
cmd = (state == ACERHDF_FAN_OFF) ? bios_cfg->cmd.cmd_off
: bios_cfg->cmd.cmd_auto;
fanstate = state;
ec_write(bios_cfg->fanreg, cmd);
}
static void acerhdf_check_param(struct thermal_zone_device *thermal)
{
if (fanon > ACERHDF_MAX_FANON) {
pr_err("fanon temperature too high, set to %d\n",
ACERHDF_MAX_FANON);
fanon = ACERHDF_MAX_FANON;
}
if (kernelmode && prev_interval != interval) {
if (interval > ACERHDF_MAX_INTERVAL) {
pr_err("interval too high, set to %d\n",
ACERHDF_MAX_INTERVAL);
interval = ACERHDF_MAX_INTERVAL;
}
if (verbose)
pr_notice("interval changed to: %d\n", interval);
thermal->polling_delay = interval*1000;
prev_interval = interval;
}
}
static int acerhdf_get_ec_temp(struct thermal_zone_device *thermal,
unsigned long *t)
{
int temp, err = 0;
acerhdf_check_param(thermal);
err = acerhdf_get_temp(&temp);
if (err)
return err;
if (verbose)
pr_notice("temp %d\n", temp);
*t = temp;
return 0;
}
static int acerhdf_bind(struct thermal_zone_device *thermal,
struct thermal_cooling_device *cdev)
{
if (cdev != cl_dev)
return 0;
if (thermal_zone_bind_cooling_device(thermal, 0, cdev)) {
pr_err("error binding cooling dev\n");
return -EINVAL;
}
return 0;
}
static int acerhdf_unbind(struct thermal_zone_device *thermal,
struct thermal_cooling_device *cdev)
{
if (cdev != cl_dev)
return 0;
if (thermal_zone_unbind_cooling_device(thermal, 0, cdev)) {
pr_err("error unbinding cooling dev\n");
return -EINVAL;
}
return 0;
}
static inline void acerhdf_revert_to_bios_mode(void)
{
acerhdf_change_fanstate(ACERHDF_FAN_AUTO);
kernelmode = 0;
if (thz_dev)
thz_dev->polling_delay = 0;
pr_notice("kernel mode fan control OFF\n");
}
static inline void acerhdf_enable_kernelmode(void)
{
kernelmode = 1;
thz_dev->polling_delay = interval*1000;
thermal_zone_device_update(thz_dev);
pr_notice("kernel mode fan control ON\n");
}
static int acerhdf_get_mode(struct thermal_zone_device *thermal,
enum thermal_device_mode *mode)
{
if (verbose)
pr_notice("kernel mode fan control %d\n", kernelmode);
*mode = (kernelmode) ? THERMAL_DEVICE_ENABLED
: THERMAL_DEVICE_DISABLED;
return 0;
}
static int acerhdf_set_mode(struct thermal_zone_device *thermal,
enum thermal_device_mode mode)
{
if (mode == THERMAL_DEVICE_DISABLED && kernelmode)
acerhdf_revert_to_bios_mode();
else if (mode == THERMAL_DEVICE_ENABLED && !kernelmode)
acerhdf_enable_kernelmode();
return 0;
}
static int acerhdf_get_trip_type(struct thermal_zone_device *thermal, int trip,
enum thermal_trip_type *type)
{
if (trip == 0)
*type = THERMAL_TRIP_ACTIVE;
return 0;
}
static int acerhdf_get_trip_temp(struct thermal_zone_device *thermal, int trip,
unsigned long *temp)
{
if (trip == 0)
*temp = fanon;
return 0;
}
static int acerhdf_get_crit_temp(struct thermal_zone_device *thermal,
unsigned long *temperature)
{
*temperature = ACERHDF_TEMP_CRIT;
return 0;
}
static int acerhdf_get_max_state(struct thermal_cooling_device *cdev,
unsigned long *state)
{
*state = 1;
return 0;
}
static int acerhdf_get_cur_state(struct thermal_cooling_device *cdev,
unsigned long *state)
{
int err = 0, tmp;
err = acerhdf_get_fanstate(&tmp);
if (err)
return err;
*state = (tmp == ACERHDF_FAN_AUTO) ? 1 : 0;
return 0;
}
static int acerhdf_set_cur_state(struct thermal_cooling_device *cdev,
unsigned long state)
{
int cur_temp, cur_state, err = 0;
if (!kernelmode)
return 0;
err = acerhdf_get_temp(&cur_temp);
if (err) {
pr_err("error reading temperature, hand off control to BIOS\n");
goto err_out;
}
err = acerhdf_get_fanstate(&cur_state);
if (err) {
pr_err("error reading fan state, hand off control to BIOS\n");
goto err_out;
}
if (state == 0) {
if ((cur_state == ACERHDF_FAN_AUTO) &&
(cur_temp < fanoff))
acerhdf_change_fanstate(ACERHDF_FAN_OFF);
} else {
if (cur_state == ACERHDF_FAN_OFF)
acerhdf_change_fanstate(ACERHDF_FAN_AUTO);
}
return 0;
err_out:
acerhdf_revert_to_bios_mode();
return -EINVAL;
}
static int acerhdf_suspend(struct device *dev)
{
if (kernelmode)
acerhdf_change_fanstate(ACERHDF_FAN_AUTO);
if (verbose)
pr_notice("going suspend\n");
return 0;
}
static int __devinit acerhdf_probe(struct platform_device *device)
{
return 0;
}
static int acerhdf_remove(struct platform_device *device)
{
return 0;
}
static int str_starts_with(const char *str, const char *start)
{
unsigned long str_len = 0, start_len = 0;
str_len = strlen(str);
start_len = strlen(start);
if (str_len >= start_len &&
!strncmp(str, start, start_len))
return 1;
return 0;
}
static int acerhdf_check_hardware(void)
{
char const *vendor, *version, *product;
const struct bios_settings_t *bt = NULL;
vendor = dmi_get_system_info(DMI_SYS_VENDOR);
version = dmi_get_system_info(DMI_BIOS_VERSION);
product = dmi_get_system_info(DMI_PRODUCT_NAME);
if (!vendor || !version || !product) {
pr_err("error getting hardware information\n");
return -EINVAL;
}
pr_info("Acer Aspire One Fan driver, v.%s\n", DRV_VER);
if (force_bios[0]) {
version = force_bios;
pr_info("forcing BIOS version: %s\n", version);
kernelmode = 0;
}
if (force_product[0]) {
product = force_product;
pr_info("forcing BIOS product: %s\n", product);
kernelmode = 0;
}
if (verbose)
pr_info("BIOS info: %s %s, product: %s\n",
vendor, version, product);
for (bt = bios_tbl; bt->vendor[0]; bt++) {
if (str_starts_with(vendor, bt->vendor) &&
str_starts_with(product, bt->product) &&
str_starts_with(version, bt->version)) {
bios_cfg = bt;
break;
}
}
if (!bios_cfg) {
pr_err("unknown (unsupported) BIOS version %s/%s/%s, please report, aborting!\n",
vendor, product, version);
return -EINVAL;
}
if (!kernelmode) {
pr_notice("Fan control off, to enable do:\n");
pr_notice("echo -n \"enabled\" > /sys/class/thermal/thermal_zone0/mode\n");
}
return 0;
}
static int acerhdf_register_platform(void)
{
int err = 0;
err = platform_driver_register(&acerhdf_driver);
if (err)
return err;
acerhdf_dev = platform_device_alloc("acerhdf", -1);
if (!acerhdf_dev) {
err = -ENOMEM;
goto err_device_alloc;
}
err = platform_device_add(acerhdf_dev);
if (err)
goto err_device_add;
return 0;
err_device_add:
platform_device_put(acerhdf_dev);
err_device_alloc:
platform_driver_unregister(&acerhdf_driver);
return err;
}
static void acerhdf_unregister_platform(void)
{
platform_device_unregister(acerhdf_dev);
platform_driver_unregister(&acerhdf_driver);
}
static int acerhdf_register_thermal(void)
{
cl_dev = thermal_cooling_device_register("acerhdf-fan", NULL,
&acerhdf_cooling_ops);
if (IS_ERR(cl_dev))
return -EINVAL;
thz_dev = thermal_zone_device_register("acerhdf", 1, 0, NULL,
&acerhdf_dev_ops, 0, 0, 0,
(kernelmode) ? interval*1000 : 0);
if (IS_ERR(thz_dev))
return -EINVAL;
return 0;
}
static void acerhdf_unregister_thermal(void)
{
if (cl_dev) {
thermal_cooling_device_unregister(cl_dev);
cl_dev = NULL;
}
if (thz_dev) {
thermal_zone_device_unregister(thz_dev);
thz_dev = NULL;
}
}
static int __init acerhdf_init(void)
{
int err = 0;
err = acerhdf_check_hardware();
if (err)
goto out_err;
err = acerhdf_register_platform();
if (err)
goto out_err;
err = acerhdf_register_thermal();
if (err)
goto err_unreg;
return 0;
err_unreg:
acerhdf_unregister_thermal();
acerhdf_unregister_platform();
out_err:
return err;
}
static void __exit acerhdf_exit(void)
{
acerhdf_change_fanstate(ACERHDF_FAN_AUTO);
acerhdf_unregister_thermal();
acerhdf_unregister_platform();
}
