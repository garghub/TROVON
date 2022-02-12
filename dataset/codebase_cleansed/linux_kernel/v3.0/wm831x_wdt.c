static int wm831x_wdt_set_timeout(struct wm831x *wm831x, u16 value)
{
int ret;
mutex_lock(&wdt_mutex);
ret = wm831x_reg_unlock(wm831x);
if (ret == 0) {
ret = wm831x_set_bits(wm831x, WM831X_WATCHDOG,
WM831X_WDOG_TO_MASK, value);
wm831x_reg_lock(wm831x);
} else {
dev_err(wm831x->dev, "Failed to unlock security key: %d\n",
ret);
}
mutex_unlock(&wdt_mutex);
return ret;
}
static int wm831x_wdt_start(struct wm831x *wm831x)
{
int ret;
mutex_lock(&wdt_mutex);
ret = wm831x_reg_unlock(wm831x);
if (ret == 0) {
ret = wm831x_set_bits(wm831x, WM831X_WATCHDOG,
WM831X_WDOG_ENA, WM831X_WDOG_ENA);
wm831x_reg_lock(wm831x);
} else {
dev_err(wm831x->dev, "Failed to unlock security key: %d\n",
ret);
}
mutex_unlock(&wdt_mutex);
return ret;
}
static int wm831x_wdt_stop(struct wm831x *wm831x)
{
int ret;
mutex_lock(&wdt_mutex);
ret = wm831x_reg_unlock(wm831x);
if (ret == 0) {
ret = wm831x_set_bits(wm831x, WM831X_WATCHDOG,
WM831X_WDOG_ENA, 0);
wm831x_reg_lock(wm831x);
} else {
dev_err(wm831x->dev, "Failed to unlock security key: %d\n",
ret);
}
mutex_unlock(&wdt_mutex);
return ret;
}
static int wm831x_wdt_kick(struct wm831x *wm831x)
{
int ret;
u16 reg;
mutex_lock(&wdt_mutex);
if (update_gpio) {
gpio_set_value_cansleep(update_gpio, update_state);
update_state = !update_state;
ret = 0;
goto out;
}
reg = wm831x_reg_read(wm831x, WM831X_WATCHDOG);
if (!(reg & WM831X_WDOG_RST_SRC)) {
dev_err(wm831x->dev, "Hardware watchdog update unsupported\n");
ret = -EINVAL;
goto out;
}
reg |= WM831X_WDOG_RESET;
ret = wm831x_reg_unlock(wm831x);
if (ret == 0) {
ret = wm831x_reg_write(wm831x, WM831X_WATCHDOG, reg);
wm831x_reg_lock(wm831x);
} else {
dev_err(wm831x->dev, "Failed to unlock security key: %d\n",
ret);
}
out:
mutex_unlock(&wdt_mutex);
return ret;
}
static int wm831x_wdt_open(struct inode *inode, struct file *file)
{
int ret;
if (!wm831x)
return -ENODEV;
if (test_and_set_bit(0, &wm831x_wdt_users))
return -EBUSY;
ret = wm831x_wdt_start(wm831x);
if (ret != 0)
return ret;
return nonseekable_open(inode, file);
}
static int wm831x_wdt_release(struct inode *inode, struct file *file)
{
if (wm831x_wdt_expect_close)
wm831x_wdt_stop(wm831x);
else {
dev_warn(wm831x->dev, "Watchdog device closed uncleanly\n");
wm831x_wdt_kick(wm831x);
}
clear_bit(0, &wm831x_wdt_users);
return 0;
}
static ssize_t wm831x_wdt_write(struct file *file,
const char __user *data, size_t count,
loff_t *ppos)
{
size_t i;
if (count) {
wm831x_wdt_kick(wm831x);
if (!nowayout) {
wm831x_wdt_expect_close = 0;
for (i = 0; i != count; i++) {
char c;
if (get_user(c, data + i))
return -EFAULT;
if (c == 'V')
wm831x_wdt_expect_close = 42;
}
}
}
return count;
}
static long wm831x_wdt_ioctl(struct file *file, unsigned int cmd,
unsigned long arg)
{
int ret = -ENOTTY, time, i;
void __user *argp = (void __user *)arg;
int __user *p = argp;
u16 reg;
switch (cmd) {
case WDIOC_GETSUPPORT:
ret = copy_to_user(argp, &ident, sizeof(ident)) ? -EFAULT : 0;
break;
case WDIOC_GETSTATUS:
case WDIOC_GETBOOTSTATUS:
ret = put_user(0, p);
break;
case WDIOC_SETOPTIONS:
{
int options;
if (get_user(options, p))
return -EFAULT;
ret = -EINVAL;
if (options == WDIOS_DISABLECARD)
ret = wm831x_wdt_start(wm831x);
if (options == WDIOS_ENABLECARD)
ret = wm831x_wdt_stop(wm831x);
break;
}
case WDIOC_KEEPALIVE:
ret = wm831x_wdt_kick(wm831x);
break;
case WDIOC_SETTIMEOUT:
ret = get_user(time, p);
if (ret)
break;
if (time == 0) {
if (nowayout)
ret = -EINVAL;
else
wm831x_wdt_stop(wm831x);
break;
}
for (i = 0; i < ARRAY_SIZE(wm831x_wdt_cfgs); i++)
if (wm831x_wdt_cfgs[i].time == time)
break;
if (i == ARRAY_SIZE(wm831x_wdt_cfgs))
ret = -EINVAL;
else
ret = wm831x_wdt_set_timeout(wm831x,
wm831x_wdt_cfgs[i].val);
break;
case WDIOC_GETTIMEOUT:
reg = wm831x_reg_read(wm831x, WM831X_WATCHDOG);
reg &= WM831X_WDOG_TO_MASK;
for (i = 0; i < ARRAY_SIZE(wm831x_wdt_cfgs); i++)
if (wm831x_wdt_cfgs[i].val == reg)
break;
if (i == ARRAY_SIZE(wm831x_wdt_cfgs)) {
dev_warn(wm831x->dev,
"Unknown watchdog configuration: %x\n", reg);
ret = -EINVAL;
} else
ret = put_user(wm831x_wdt_cfgs[i].time, p);
}
return ret;
}
static int __devinit wm831x_wdt_probe(struct platform_device *pdev)
{
struct wm831x_pdata *chip_pdata;
struct wm831x_watchdog_pdata *pdata;
int reg, ret;
if (wm831x) {
dev_err(&pdev->dev, "wm831x watchdog already registered\n");
return -EBUSY;
}
wm831x = dev_get_drvdata(pdev->dev.parent);
ret = wm831x_reg_read(wm831x, WM831X_WATCHDOG);
if (ret < 0) {
dev_err(wm831x->dev, "Failed to read watchdog status: %d\n",
ret);
goto err;
}
reg = ret;
if (reg & WM831X_WDOG_DEBUG)
dev_warn(wm831x->dev, "Watchdog is paused\n");
if (pdev->dev.parent->platform_data) {
chip_pdata = pdev->dev.parent->platform_data;
pdata = chip_pdata->watchdog;
} else {
pdata = NULL;
}
if (pdata) {
reg &= ~(WM831X_WDOG_SECACT_MASK | WM831X_WDOG_PRIMACT_MASK |
WM831X_WDOG_RST_SRC);
reg |= pdata->primary << WM831X_WDOG_PRIMACT_SHIFT;
reg |= pdata->secondary << WM831X_WDOG_SECACT_SHIFT;
reg |= pdata->software << WM831X_WDOG_RST_SRC_SHIFT;
if (pdata->update_gpio) {
ret = gpio_request(pdata->update_gpio,
"Watchdog update");
if (ret < 0) {
dev_err(wm831x->dev,
"Failed to request update GPIO: %d\n",
ret);
goto err;
}
ret = gpio_direction_output(pdata->update_gpio, 0);
if (ret != 0) {
dev_err(wm831x->dev,
"gpio_direction_output returned: %d\n",
ret);
goto err_gpio;
}
update_gpio = pdata->update_gpio;
reg |= WM831X_WDOG_RST_SRC;
}
ret = wm831x_reg_unlock(wm831x);
if (ret == 0) {
ret = wm831x_reg_write(wm831x, WM831X_WATCHDOG, reg);
wm831x_reg_lock(wm831x);
} else {
dev_err(wm831x->dev,
"Failed to unlock security key: %d\n", ret);
goto err_gpio;
}
}
wm831x_wdt_miscdev.parent = &pdev->dev;
ret = misc_register(&wm831x_wdt_miscdev);
if (ret != 0) {
dev_err(wm831x->dev, "Failed to register miscdev: %d\n", ret);
goto err_gpio;
}
return 0;
err_gpio:
if (update_gpio) {
gpio_free(update_gpio);
update_gpio = 0;
}
err:
return ret;
}
static int __devexit wm831x_wdt_remove(struct platform_device *pdev)
{
if (update_gpio) {
gpio_free(update_gpio);
update_gpio = 0;
}
misc_deregister(&wm831x_wdt_miscdev);
return 0;
}
static int __init wm831x_wdt_init(void)
{
return platform_driver_register(&wm831x_wdt_driver);
}
static void __exit wm831x_wdt_exit(void)
{
platform_driver_unregister(&wm831x_wdt_driver);
}
