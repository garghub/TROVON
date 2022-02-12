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
static int wm831x_read(struct wm831x *wm831x, unsigned short reg,
int bytes, void *dest)
{
int ret, i;
u16 *buf = dest;
BUG_ON(bytes % 2);
BUG_ON(bytes <= 0);
ret = wm831x->read_dev(wm831x, reg, bytes, dest);
if (ret < 0)
return ret;
for (i = 0; i < bytes / 2; i++) {
buf[i] = be16_to_cpu(buf[i]);
dev_vdbg(wm831x->dev, "Read %04x from R%d(0x%x)\n",
buf[i], reg + i, reg + i);
}
return 0;
}
int wm831x_reg_read(struct wm831x *wm831x, unsigned short reg)
{
unsigned short val;
int ret;
mutex_lock(&wm831x->io_lock);
ret = wm831x_read(wm831x, reg, 2, &val);
mutex_unlock(&wm831x->io_lock);
if (ret < 0)
return ret;
else
return val;
}
int wm831x_bulk_read(struct wm831x *wm831x, unsigned short reg,
int count, u16 *buf)
{
int ret;
mutex_lock(&wm831x->io_lock);
ret = wm831x_read(wm831x, reg, count * 2, buf);
mutex_unlock(&wm831x->io_lock);
return ret;
}
static int wm831x_write(struct wm831x *wm831x, unsigned short reg,
int bytes, void *src)
{
u16 *buf = src;
int i;
BUG_ON(bytes % 2);
BUG_ON(bytes <= 0);
for (i = 0; i < bytes / 2; i++) {
if (wm831x_reg_locked(wm831x, reg))
return -EPERM;
dev_vdbg(wm831x->dev, "Write %04x to R%d(0x%x)\n",
buf[i], reg + i, reg + i);
buf[i] = cpu_to_be16(buf[i]);
}
return wm831x->write_dev(wm831x, reg, bytes, src);
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
u16 r;
mutex_lock(&wm831x->io_lock);
ret = wm831x_read(wm831x, reg, 2, &r);
if (ret < 0)
goto out;
r &= ~mask;
r |= val & mask;
ret = wm831x_write(wm831x, reg, 2, &r);
out:
mutex_unlock(&wm831x->io_lock);
return ret;
}
int wm831x_device_init(struct wm831x *wm831x, unsigned long id, int irq)
{
struct wm831x_pdata *pdata = wm831x->dev->platform_data;
int rev, wm831x_num;
enum wm831x_parent parent;
int ret, i;
mutex_init(&wm831x->io_lock);
mutex_init(&wm831x->key_lock);
dev_set_drvdata(wm831x->dev, wm831x);
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
ret = id;
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
if (parent != id)
dev_warn(wm831x->dev, "Device was registered as a WM%lx\n",
id);
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
if (pdata && pdata->pre_init) {
ret = pdata->pre_init(wm831x);
if (ret != 0) {
dev_err(wm831x->dev, "pre_init() failed: %d\n", ret);
goto err;
}
}
if (pdata) {
for (i = 0; i < ARRAY_SIZE(pdata->gpio_defaults); i++) {
if (!pdata->gpio_defaults[i])
continue;
wm831x_reg_write(wm831x,
WM831X_GPIO1_CONTROL + i,
pdata->gpio_defaults[i] & 0xffff);
}
}
if (pdata && pdata->wm831x_num)
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
NULL, wm831x->irq_base);
break;
case WM8311:
ret = mfd_add_devices(wm831x->dev, wm831x_num,
wm8311_devs, ARRAY_SIZE(wm8311_devs),
NULL, wm831x->irq_base);
if (!pdata || !pdata->disable_touch)
mfd_add_devices(wm831x->dev, wm831x_num,
touch_devs, ARRAY_SIZE(touch_devs),
NULL, wm831x->irq_base);
break;
case WM8312:
ret = mfd_add_devices(wm831x->dev, wm831x_num,
wm8312_devs, ARRAY_SIZE(wm8312_devs),
NULL, wm831x->irq_base);
if (!pdata || !pdata->disable_touch)
mfd_add_devices(wm831x->dev, wm831x_num,
touch_devs, ARRAY_SIZE(touch_devs),
NULL, wm831x->irq_base);
break;
case WM8320:
case WM8321:
case WM8325:
case WM8326:
ret = mfd_add_devices(wm831x->dev, wm831x_num,
wm8320_devs, ARRAY_SIZE(wm8320_devs),
NULL, wm831x->irq_base);
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
NULL, wm831x->irq_base);
if (ret != 0) {
dev_err(wm831x->dev, "Failed to add RTC: %d\n", ret);
goto err_irq;
}
} else {
dev_info(wm831x->dev, "32.768kHz clock disabled, no RTC\n");
}
if (pdata && pdata->backlight) {
ret = mfd_add_devices(wm831x->dev, wm831x_num, backlight_devs,
ARRAY_SIZE(backlight_devs), NULL,
wm831x->irq_base);
if (ret < 0)
dev_err(wm831x->dev, "Failed to add backlight: %d\n",
ret);
}
wm831x_otp_init(wm831x);
if (pdata && pdata->post_init) {
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
kfree(wm831x);
return ret;
}
void wm831x_device_exit(struct wm831x *wm831x)
{
wm831x_otp_exit(wm831x);
mfd_remove_devices(wm831x->dev);
if (wm831x->irq_base)
free_irq(wm831x->irq_base + WM831X_IRQ_AUXADC_DATA, wm831x);
wm831x_irq_exit(wm831x);
kfree(wm831x);
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
