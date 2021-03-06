static int wm831x_reg_locked(struct wm831x *wm831x, unsigned short reg)
{
if (!wm831x->locked)
return 0;
switch (reg) {
case WM831X_WATCHDOG:
case WM831X_DC4_CONTROL:
case WM831X_ON_PIN_CONTROL:
case WM831X_BACKUP_CHARGER_CONTROL:
case WM831X_CHARGER_CONTROL_1:
case WM831X_CHARGER_CONTROL_2:
return 1;
default:
return 0;
}
}
void wm831x_reg_lock(struct wm831x *wm831x)
{
int ret;
ret = wm831x_reg_write(wm831x, WM831X_SECURITY_KEY, 0);
if (ret == 0) {
dev_vdbg(wm831x->dev, "Registers locked\n");
mutex_lock(&wm831x->io_lock);
WARN_ON(wm831x->locked);
wm831x->locked = 1;
mutex_unlock(&wm831x->io_lock);
} else {
dev_err(wm831x->dev, "Failed to lock registers: %d\n", ret);
}
}
int wm831x_reg_unlock(struct wm831x *wm831x)
{
int ret;
ret = wm831x_reg_write(wm831x, WM831X_SECURITY_KEY, 0x9716);
if (ret == 0) {
dev_vdbg(wm831x->dev, "Registers unlocked\n");
mutex_lock(&wm831x->io_lock);
WARN_ON(!wm831x->locked);
wm831x->locked = 0;
mutex_unlock(&wm831x->io_lock);
}
return ret;
}
static bool wm831x_reg_readable(struct device *dev, unsigned int reg)
{
switch (reg) {
case WM831X_RESET_ID:
case WM831X_REVISION:
case WM831X_PARENT_ID:
case WM831X_SYSVDD_CONTROL:
case WM831X_THERMAL_MONITORING:
case WM831X_POWER_STATE:
case WM831X_WATCHDOG:
case WM831X_ON_PIN_CONTROL:
case WM831X_RESET_CONTROL:
case WM831X_CONTROL_INTERFACE:
case WM831X_SECURITY_KEY:
case WM831X_SOFTWARE_SCRATCH:
case WM831X_OTP_CONTROL:
case WM831X_GPIO_LEVEL:
case WM831X_SYSTEM_STATUS:
case WM831X_ON_SOURCE:
case WM831X_OFF_SOURCE:
case WM831X_SYSTEM_INTERRUPTS:
case WM831X_INTERRUPT_STATUS_1:
case WM831X_INTERRUPT_STATUS_2:
case WM831X_INTERRUPT_STATUS_3:
case WM831X_INTERRUPT_STATUS_4:
case WM831X_INTERRUPT_STATUS_5:
case WM831X_IRQ_CONFIG:
case WM831X_SYSTEM_INTERRUPTS_MASK:
case WM831X_INTERRUPT_STATUS_1_MASK:
case WM831X_INTERRUPT_STATUS_2_MASK:
case WM831X_INTERRUPT_STATUS_3_MASK:
case WM831X_INTERRUPT_STATUS_4_MASK:
case WM831X_INTERRUPT_STATUS_5_MASK:
case WM831X_RTC_WRITE_COUNTER:
case WM831X_RTC_TIME_1:
case WM831X_RTC_TIME_2:
case WM831X_RTC_ALARM_1:
case WM831X_RTC_ALARM_2:
case WM831X_RTC_CONTROL:
case WM831X_RTC_TRIM:
case WM831X_TOUCH_CONTROL_1:
case WM831X_TOUCH_CONTROL_2:
case WM831X_TOUCH_DATA_X:
case WM831X_TOUCH_DATA_Y:
case WM831X_TOUCH_DATA_Z:
case WM831X_AUXADC_DATA:
case WM831X_AUXADC_CONTROL:
case WM831X_AUXADC_SOURCE:
case WM831X_COMPARATOR_CONTROL:
case WM831X_COMPARATOR_1:
case WM831X_COMPARATOR_2:
case WM831X_COMPARATOR_3:
case WM831X_COMPARATOR_4:
case WM831X_GPIO1_CONTROL:
case WM831X_GPIO2_CONTROL:
case WM831X_GPIO3_CONTROL:
case WM831X_GPIO4_CONTROL:
case WM831X_GPIO5_CONTROL:
case WM831X_GPIO6_CONTROL:
case WM831X_GPIO7_CONTROL:
case WM831X_GPIO8_CONTROL:
case WM831X_GPIO9_CONTROL:
case WM831X_GPIO10_CONTROL:
case WM831X_GPIO11_CONTROL:
case WM831X_GPIO12_CONTROL:
case WM831X_GPIO13_CONTROL:
case WM831X_GPIO14_CONTROL:
case WM831X_GPIO15_CONTROL:
case WM831X_GPIO16_CONTROL:
case WM831X_CHARGER_CONTROL_1:
case WM831X_CHARGER_CONTROL_2:
case WM831X_CHARGER_STATUS:
case WM831X_BACKUP_CHARGER_CONTROL:
case WM831X_STATUS_LED_1:
case WM831X_STATUS_LED_2:
case WM831X_CURRENT_SINK_1:
case WM831X_CURRENT_SINK_2:
case WM831X_DCDC_ENABLE:
case WM831X_LDO_ENABLE:
case WM831X_DCDC_STATUS:
case WM831X_LDO_STATUS:
case WM831X_DCDC_UV_STATUS:
case WM831X_LDO_UV_STATUS:
case WM831X_DC1_CONTROL_1:
case WM831X_DC1_CONTROL_2:
case WM831X_DC1_ON_CONFIG:
case WM831X_DC1_SLEEP_CONTROL:
case WM831X_DC1_DVS_CONTROL:
case WM831X_DC2_CONTROL_1:
case WM831X_DC2_CONTROL_2:
case WM831X_DC2_ON_CONFIG:
case WM831X_DC2_SLEEP_CONTROL:
case WM831X_DC2_DVS_CONTROL:
case WM831X_DC3_CONTROL_1:
case WM831X_DC3_CONTROL_2:
case WM831X_DC3_ON_CONFIG:
case WM831X_DC3_SLEEP_CONTROL:
case WM831X_DC4_CONTROL:
case WM831X_DC4_SLEEP_CONTROL:
case WM831X_EPE1_CONTROL:
case WM831X_EPE2_CONTROL:
case WM831X_LDO1_CONTROL:
case WM831X_LDO1_ON_CONTROL:
case WM831X_LDO1_SLEEP_CONTROL:
case WM831X_LDO2_CONTROL:
case WM831X_LDO2_ON_CONTROL:
case WM831X_LDO2_SLEEP_CONTROL:
case WM831X_LDO3_CONTROL:
case WM831X_LDO3_ON_CONTROL:
case WM831X_LDO3_SLEEP_CONTROL:
case WM831X_LDO4_CONTROL:
case WM831X_LDO4_ON_CONTROL:
case WM831X_LDO4_SLEEP_CONTROL:
case WM831X_LDO5_CONTROL:
case WM831X_LDO5_ON_CONTROL:
case WM831X_LDO5_SLEEP_CONTROL:
case WM831X_LDO6_CONTROL:
case WM831X_LDO6_ON_CONTROL:
case WM831X_LDO6_SLEEP_CONTROL:
case WM831X_LDO7_CONTROL:
case WM831X_LDO7_ON_CONTROL:
case WM831X_LDO7_SLEEP_CONTROL:
case WM831X_LDO8_CONTROL:
case WM831X_LDO8_ON_CONTROL:
case WM831X_LDO8_SLEEP_CONTROL:
case WM831X_LDO9_CONTROL:
case WM831X_LDO9_ON_CONTROL:
case WM831X_LDO9_SLEEP_CONTROL:
case WM831X_LDO10_CONTROL:
case WM831X_LDO10_ON_CONTROL:
case WM831X_LDO10_SLEEP_CONTROL:
case WM831X_LDO11_ON_CONTROL:
case WM831X_LDO11_SLEEP_CONTROL:
case WM831X_POWER_GOOD_SOURCE_1:
case WM831X_POWER_GOOD_SOURCE_2:
case WM831X_CLOCK_CONTROL_1:
case WM831X_CLOCK_CONTROL_2:
case WM831X_FLL_CONTROL_1:
case WM831X_FLL_CONTROL_2:
case WM831X_FLL_CONTROL_3:
case WM831X_FLL_CONTROL_4:
case WM831X_FLL_CONTROL_5:
case WM831X_UNIQUE_ID_1:
case WM831X_UNIQUE_ID_2:
case WM831X_UNIQUE_ID_3:
case WM831X_UNIQUE_ID_4:
case WM831X_UNIQUE_ID_5:
case WM831X_UNIQUE_ID_6:
case WM831X_UNIQUE_ID_7:
case WM831X_UNIQUE_ID_8:
case WM831X_FACTORY_OTP_ID:
case WM831X_FACTORY_OTP_1:
case WM831X_FACTORY_OTP_2:
case WM831X_FACTORY_OTP_3:
case WM831X_FACTORY_OTP_4:
case WM831X_FACTORY_OTP_5:
case WM831X_CUSTOMER_OTP_ID:
case WM831X_DC1_OTP_CONTROL:
case WM831X_DC2_OTP_CONTROL:
case WM831X_DC3_OTP_CONTROL:
case WM831X_LDO1_2_OTP_CONTROL:
case WM831X_LDO3_4_OTP_CONTROL:
case WM831X_LDO5_6_OTP_CONTROL:
case WM831X_LDO7_8_OTP_CONTROL:
case WM831X_LDO9_10_OTP_CONTROL:
case WM831X_LDO11_EPE_CONTROL:
case WM831X_GPIO1_OTP_CONTROL:
case WM831X_GPIO2_OTP_CONTROL:
case WM831X_GPIO3_OTP_CONTROL:
case WM831X_GPIO4_OTP_CONTROL:
case WM831X_GPIO5_OTP_CONTROL:
case WM831X_GPIO6_OTP_CONTROL:
case WM831X_DBE_CHECK_DATA:
return true;
default:
return false;
}
}
static bool wm831x_reg_writeable(struct device *dev, unsigned int reg)
{
struct wm831x *wm831x = dev_get_drvdata(dev);
if (wm831x_reg_locked(wm831x, reg))
return false;
switch (reg) {
case WM831X_SYSVDD_CONTROL:
case WM831X_THERMAL_MONITORING:
case WM831X_POWER_STATE:
case WM831X_WATCHDOG:
case WM831X_ON_PIN_CONTROL:
case WM831X_RESET_CONTROL:
case WM831X_CONTROL_INTERFACE:
case WM831X_SECURITY_KEY:
case WM831X_SOFTWARE_SCRATCH:
case WM831X_OTP_CONTROL:
case WM831X_GPIO_LEVEL:
case WM831X_INTERRUPT_STATUS_1:
case WM831X_INTERRUPT_STATUS_2:
case WM831X_INTERRUPT_STATUS_3:
case WM831X_INTERRUPT_STATUS_4:
case WM831X_INTERRUPT_STATUS_5:
case WM831X_IRQ_CONFIG:
case WM831X_SYSTEM_INTERRUPTS_MASK:
case WM831X_INTERRUPT_STATUS_1_MASK:
case WM831X_INTERRUPT_STATUS_2_MASK:
case WM831X_INTERRUPT_STATUS_3_MASK:
case WM831X_INTERRUPT_STATUS_4_MASK:
case WM831X_INTERRUPT_STATUS_5_MASK:
case WM831X_RTC_TIME_1:
case WM831X_RTC_TIME_2:
case WM831X_RTC_ALARM_1:
case WM831X_RTC_ALARM_2:
case WM831X_RTC_CONTROL:
case WM831X_RTC_TRIM:
case WM831X_TOUCH_CONTROL_1:
case WM831X_TOUCH_CONTROL_2:
case WM831X_AUXADC_CONTROL:
case WM831X_AUXADC_SOURCE:
case WM831X_COMPARATOR_CONTROL:
case WM831X_COMPARATOR_1:
case WM831X_COMPARATOR_2:
case WM831X_COMPARATOR_3:
case WM831X_COMPARATOR_4:
case WM831X_GPIO1_CONTROL:
case WM831X_GPIO2_CONTROL:
case WM831X_GPIO3_CONTROL:
case WM831X_GPIO4_CONTROL:
case WM831X_GPIO5_CONTROL:
case WM831X_GPIO6_CONTROL:
case WM831X_GPIO7_CONTROL:
case WM831X_GPIO8_CONTROL:
case WM831X_GPIO9_CONTROL:
case WM831X_GPIO10_CONTROL:
case WM831X_GPIO11_CONTROL:
case WM831X_GPIO12_CONTROL:
case WM831X_GPIO13_CONTROL:
case WM831X_GPIO14_CONTROL:
case WM831X_GPIO15_CONTROL:
case WM831X_GPIO16_CONTROL:
case WM831X_CHARGER_CONTROL_1:
case WM831X_CHARGER_CONTROL_2:
case WM831X_CHARGER_STATUS:
case WM831X_BACKUP_CHARGER_CONTROL:
case WM831X_STATUS_LED_1:
case WM831X_STATUS_LED_2:
case WM831X_CURRENT_SINK_1:
case WM831X_CURRENT_SINK_2:
case WM831X_DCDC_ENABLE:
case WM831X_LDO_ENABLE:
case WM831X_DC1_CONTROL_1:
case WM831X_DC1_CONTROL_2:
case WM831X_DC1_ON_CONFIG:
case WM831X_DC1_SLEEP_CONTROL:
case WM831X_DC1_DVS_CONTROL:
case WM831X_DC2_CONTROL_1:
case WM831X_DC2_CONTROL_2:
case WM831X_DC2_ON_CONFIG:
case WM831X_DC2_SLEEP_CONTROL:
case WM831X_DC2_DVS_CONTROL:
case WM831X_DC3_CONTROL_1:
case WM831X_DC3_CONTROL_2:
case WM831X_DC3_ON_CONFIG:
case WM831X_DC3_SLEEP_CONTROL:
case WM831X_DC4_CONTROL:
case WM831X_DC4_SLEEP_CONTROL:
case WM831X_EPE1_CONTROL:
case WM831X_EPE2_CONTROL:
case WM831X_LDO1_CONTROL:
case WM831X_LDO1_ON_CONTROL:
case WM831X_LDO1_SLEEP_CONTROL:
case WM831X_LDO2_CONTROL:
case WM831X_LDO2_ON_CONTROL:
case WM831X_LDO2_SLEEP_CONTROL:
case WM831X_LDO3_CONTROL:
case WM831X_LDO3_ON_CONTROL:
case WM831X_LDO3_SLEEP_CONTROL:
case WM831X_LDO4_CONTROL:
case WM831X_LDO4_ON_CONTROL:
case WM831X_LDO4_SLEEP_CONTROL:
case WM831X_LDO5_CONTROL:
case WM831X_LDO5_ON_CONTROL:
case WM831X_LDO5_SLEEP_CONTROL:
case WM831X_LDO6_CONTROL:
case WM831X_LDO6_ON_CONTROL:
case WM831X_LDO6_SLEEP_CONTROL:
case WM831X_LDO7_CONTROL:
case WM831X_LDO7_ON_CONTROL:
case WM831X_LDO7_SLEEP_CONTROL:
case WM831X_LDO8_CONTROL:
case WM831X_LDO8_ON_CONTROL:
case WM831X_LDO8_SLEEP_CONTROL:
case WM831X_LDO9_CONTROL:
case WM831X_LDO9_ON_CONTROL:
case WM831X_LDO9_SLEEP_CONTROL:
case WM831X_LDO10_CONTROL:
case WM831X_LDO10_ON_CONTROL:
case WM831X_LDO10_SLEEP_CONTROL:
case WM831X_LDO11_ON_CONTROL:
case WM831X_LDO11_SLEEP_CONTROL:
case WM831X_POWER_GOOD_SOURCE_1:
case WM831X_POWER_GOOD_SOURCE_2:
case WM831X_CLOCK_CONTROL_1:
case WM831X_CLOCK_CONTROL_2:
case WM831X_FLL_CONTROL_1:
case WM831X_FLL_CONTROL_2:
case WM831X_FLL_CONTROL_3:
case WM831X_FLL_CONTROL_4:
case WM831X_FLL_CONTROL_5:
return true;
default:
return false;
}
}
static bool wm831x_reg_volatile(struct device *dev, unsigned int reg)
{
switch (reg) {
case WM831X_SYSTEM_STATUS:
case WM831X_ON_SOURCE:
case WM831X_OFF_SOURCE:
case WM831X_GPIO_LEVEL:
case WM831X_SYSTEM_INTERRUPTS:
case WM831X_INTERRUPT_STATUS_1:
case WM831X_INTERRUPT_STATUS_2:
case WM831X_INTERRUPT_STATUS_3:
case WM831X_INTERRUPT_STATUS_4:
case WM831X_INTERRUPT_STATUS_5:
case WM831X_RTC_TIME_1:
case WM831X_RTC_TIME_2:
case WM831X_TOUCH_DATA_X:
case WM831X_TOUCH_DATA_Y:
case WM831X_TOUCH_DATA_Z:
case WM831X_AUXADC_DATA:
case WM831X_CHARGER_STATUS:
case WM831X_DCDC_STATUS:
case WM831X_LDO_STATUS:
case WM831X_DCDC_UV_STATUS:
case WM831X_LDO_UV_STATUS:
return true;
default:
return false;
}
}
int wm831x_reg_read(struct wm831x *wm831x, unsigned short reg)
{
unsigned int val;
int ret;
ret = regmap_read(wm831x->regmap, reg, &val);
if (ret < 0)
return ret;
else
return val;
}
int wm831x_bulk_read(struct wm831x *wm831x, unsigned short reg,
int count, u16 *buf)
{
return regmap_bulk_read(wm831x->regmap, reg, buf, count);
}
static int wm831x_write(struct wm831x *wm831x, unsigned short reg,
int bytes, void *src)
{
u16 *buf = src;
int i, ret;
BUG_ON(bytes % 2);
BUG_ON(bytes <= 0);
for (i = 0; i < bytes / 2; i++) {
if (wm831x_reg_locked(wm831x, reg))
return -EPERM;
dev_vdbg(wm831x->dev, "Write %04x to R%d(0x%x)\n",
buf[i], reg + i, reg + i);
ret = regmap_write(wm831x->regmap, reg + i, buf[i]);
if (ret != 0)
return ret;
}
return 0;
}
int wm831x_reg_write(struct wm831x *wm831x, unsigned short reg,
unsigned short val)
{
int ret;
mutex_lock(&wm831x->io_lock);
ret = wm831x_write(wm831x, reg, 2, &val);
mutex_unlock(&wm831x->io_lock);
return ret;
}
int wm831x_set_bits(struct wm831x *wm831x, unsigned short reg,
unsigned short mask, unsigned short val)
{
int ret;
mutex_lock(&wm831x->io_lock);
if (!wm831x_reg_locked(wm831x, reg))
ret = regmap_update_bits(wm831x->regmap, reg, mask, val);
else
ret = -EPERM;
mutex_unlock(&wm831x->io_lock);
return ret;
}
int wm831x_device_init(struct wm831x *wm831x, int irq)
{
struct wm831x_pdata *pdata = &wm831x->pdata;
int rev, wm831x_num;
enum wm831x_parent parent;
int ret, i;
mutex_init(&wm831x->io_lock);
mutex_init(&wm831x->key_lock);
dev_set_drvdata(wm831x->dev, wm831x);
wm831x->soft_shutdown = pdata->soft_shutdown;
ret = wm831x_reg_read(wm831x, WM831X_PARENT_ID);
if (ret < 0) {
dev_err(wm831x->dev, "Failed to read parent ID: %d\n", ret);
goto err;
}
switch (ret) {
case 0x6204:
case 0x6246:
break;
default:
dev_err(wm831x->dev, "Device is not a WM831x: ID %x\n", ret);
ret = -EINVAL;
goto err;
}
ret = wm831x_reg_read(wm831x, WM831X_REVISION);
if (ret < 0) {
dev_err(wm831x->dev, "Failed to read revision: %d\n", ret);
goto err;
}
rev = (ret & WM831X_PARENT_REV_MASK) >> WM831X_PARENT_REV_SHIFT;
ret = wm831x_reg_read(wm831x, WM831X_RESET_ID);
if (ret < 0) {
dev_err(wm831x->dev, "Failed to read device ID: %d\n", ret);
goto err;
}
if (ret == 0) {
dev_info(wm831x->dev, "Device is an engineering sample\n");
ret = wm831x->type;
}
switch (ret) {
case WM8310:
parent = WM8310;
wm831x->num_gpio = 16;
wm831x->charger_irq_wake = 1;
if (rev > 0) {
wm831x->has_gpio_ena = 1;
wm831x->has_cs_sts = 1;
}
dev_info(wm831x->dev, "WM8310 revision %c\n", 'A' + rev);
break;
case WM8311:
parent = WM8311;
wm831x->num_gpio = 16;
wm831x->charger_irq_wake = 1;
if (rev > 0) {
wm831x->has_gpio_ena = 1;
wm831x->has_cs_sts = 1;
}
dev_info(wm831x->dev, "WM8311 revision %c\n", 'A' + rev);
break;
case WM8312:
parent = WM8312;
wm831x->num_gpio = 16;
wm831x->charger_irq_wake = 1;
if (rev > 0) {
wm831x->has_gpio_ena = 1;
wm831x->has_cs_sts = 1;
}
dev_info(wm831x->dev, "WM8312 revision %c\n", 'A' + rev);
break;
case WM8320:
parent = WM8320;
wm831x->num_gpio = 12;
dev_info(wm831x->dev, "WM8320 revision %c\n", 'A' + rev);
break;
case WM8321:
parent = WM8321;
wm831x->num_gpio = 12;
dev_info(wm831x->dev, "WM8321 revision %c\n", 'A' + rev);
break;
case WM8325:
parent = WM8325;
wm831x->num_gpio = 12;
dev_info(wm831x->dev, "WM8325 revision %c\n", 'A' + rev);
break;
case WM8326:
parent = WM8326;
wm831x->num_gpio = 12;
dev_info(wm831x->dev, "WM8326 revision %c\n", 'A' + rev);
break;
default:
dev_err(wm831x->dev, "Unknown WM831x device %04x\n", ret);
ret = -EINVAL;
goto err;
}
if (parent != wm831x->type)
dev_warn(wm831x->dev, "Device was registered as a WM%x\n",
wm831x->type);
ret = wm831x_reg_read(wm831x, WM831X_SECURITY_KEY);
if (ret < 0) {
dev_err(wm831x->dev, "Failed to read security key: %d\n", ret);
goto err;
}
if (ret != 0) {
dev_warn(wm831x->dev, "Security key had non-zero value %x\n",
ret);
wm831x_reg_write(wm831x, WM831X_SECURITY_KEY, 0);
}
wm831x->locked = 1;
if (pdata->pre_init) {
ret = pdata->pre_init(wm831x);
if (ret != 0) {
dev_err(wm831x->dev, "pre_init() failed: %d\n", ret);
goto err;
}
}
for (i = 0; i < ARRAY_SIZE(pdata->gpio_defaults); i++) {
if (!pdata->gpio_defaults[i])
continue;
wm831x_reg_write(wm831x,
WM831X_GPIO1_CONTROL + i,
pdata->gpio_defaults[i] & 0xffff);
}
if (pdata->wm831x_num)
wm831x_num = pdata->wm831x_num * 10;
else
wm831x_num = -1;
ret = wm831x_irq_init(wm831x, irq);
if (ret != 0)
goto err;
wm831x_auxadc_init(wm831x);
switch (parent) {
case WM8310:
ret = mfd_add_devices(wm831x->dev, wm831x_num,
wm8310_devs, ARRAY_SIZE(wm8310_devs),
NULL, 0, NULL);
break;
case WM8311:
ret = mfd_add_devices(wm831x->dev, wm831x_num,
wm8311_devs, ARRAY_SIZE(wm8311_devs),
NULL, 0, NULL);
if (!pdata->disable_touch)
mfd_add_devices(wm831x->dev, wm831x_num,
touch_devs, ARRAY_SIZE(touch_devs),
NULL, 0, NULL);
break;
case WM8312:
ret = mfd_add_devices(wm831x->dev, wm831x_num,
wm8312_devs, ARRAY_SIZE(wm8312_devs),
NULL, 0, NULL);
if (!pdata->disable_touch)
mfd_add_devices(wm831x->dev, wm831x_num,
touch_devs, ARRAY_SIZE(touch_devs),
NULL, 0, NULL);
break;
case WM8320:
case WM8321:
case WM8325:
case WM8326:
ret = mfd_add_devices(wm831x->dev, wm831x_num,
wm8320_devs, ARRAY_SIZE(wm8320_devs),
NULL, 0, NULL);
break;
default:
BUG();
}
if (ret != 0) {
dev_err(wm831x->dev, "Failed to add children\n");
goto err_irq;
}
ret = wm831x_reg_read(wm831x, WM831X_CLOCK_CONTROL_2);
if (ret < 0) {
dev_err(wm831x->dev, "Failed to read clock status: %d\n", ret);
goto err_irq;
}
if (ret & WM831X_XTAL_ENA) {
ret = mfd_add_devices(wm831x->dev, wm831x_num,
rtc_devs, ARRAY_SIZE(rtc_devs),
NULL, 0, NULL);
if (ret != 0) {
dev_err(wm831x->dev, "Failed to add RTC: %d\n", ret);
goto err_irq;
}
} else {
dev_info(wm831x->dev, "32.768kHz clock disabled, no RTC\n");
}
if (pdata->backlight) {
ret = mfd_add_devices(wm831x->dev, wm831x_num, backlight_devs,
ARRAY_SIZE(backlight_devs), NULL,
0, NULL);
if (ret < 0)
dev_err(wm831x->dev, "Failed to add backlight: %d\n",
ret);
}
wm831x_otp_init(wm831x);
if (pdata->post_init) {
ret = pdata->post_init(wm831x);
if (ret != 0) {
dev_err(wm831x->dev, "post_init() failed: %d\n", ret);
goto err_irq;
}
}
return 0;
err_irq:
wm831x_irq_exit(wm831x);
err:
mfd_remove_devices(wm831x->dev);
return ret;
}
void wm831x_device_exit(struct wm831x *wm831x)
{
wm831x_otp_exit(wm831x);
mfd_remove_devices(wm831x->dev);
free_irq(wm831x_irq(wm831x, WM831X_IRQ_AUXADC_DATA), wm831x);
wm831x_irq_exit(wm831x);
}
int wm831x_device_suspend(struct wm831x *wm831x)
{
int reg, mask;
if (wm831x->charger_irq_wake) {
reg = wm831x_reg_read(wm831x, WM831X_INTERRUPT_STATUS_2_MASK);
mask = WM831X_CHG_BATT_HOT_EINT |
WM831X_CHG_BATT_COLD_EINT |
WM831X_CHG_BATT_FAIL_EINT |
WM831X_CHG_OV_EINT | WM831X_CHG_END_EINT |
WM831X_CHG_TO_EINT | WM831X_CHG_MODE_EINT |
WM831X_CHG_START_EINT;
if (reg & mask)
reg = wm831x_reg_read(wm831x,
WM831X_INTERRUPT_STATUS_2);
if (reg & mask) {
dev_info(wm831x->dev,
"Acknowledging masked charger IRQs: %x\n",
reg & mask);
wm831x_reg_write(wm831x, WM831X_INTERRUPT_STATUS_2,
reg & mask);
}
}
return 0;
}
void wm831x_device_shutdown(struct wm831x *wm831x)
{
if (wm831x->soft_shutdown) {
dev_info(wm831x->dev, "Initiating shutdown...\n");
wm831x_set_bits(wm831x, WM831X_POWER_STATE, WM831X_CHIP_ON, 0);
}
}
