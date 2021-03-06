static void orion_wdt_ping(void)
{
spin_lock(&wdt_lock);
writel(wdt_tclk * heartbeat, wdt_reg + WDT_VAL);
spin_unlock(&wdt_lock);
}
static void orion_wdt_enable(void)
{
u32 reg;
spin_lock(&wdt_lock);
writel(wdt_tclk * heartbeat, wdt_reg + WDT_VAL);
reg = readl(BRIDGE_CAUSE);
reg &= ~WDT_INT_REQ;
writel(reg, BRIDGE_CAUSE);
reg = readl(wdt_reg + TIMER_CTRL);
reg |= WDT_EN;
writel(reg, wdt_reg + TIMER_CTRL);
reg = readl(RSTOUTn_MASK);
reg |= WDT_RESET_OUT_EN;
writel(reg, RSTOUTn_MASK);
spin_unlock(&wdt_lock);
}
static void orion_wdt_disable(void)
{
u32 reg;
spin_lock(&wdt_lock);
reg = readl(RSTOUTn_MASK);
reg &= ~WDT_RESET_OUT_EN;
writel(reg, RSTOUTn_MASK);
reg = readl(wdt_reg + TIMER_CTRL);
reg &= ~WDT_EN;
writel(reg, wdt_reg + TIMER_CTRL);
spin_unlock(&wdt_lock);
}
static int orion_wdt_get_timeleft(int *time_left)
{
spin_lock(&wdt_lock);
*time_left = readl(wdt_reg + WDT_VAL) / wdt_tclk;
spin_unlock(&wdt_lock);
return 0;
}
static int orion_wdt_open(struct inode *inode, struct file *file)
{
if (test_and_set_bit(WDT_IN_USE, &wdt_status))
return -EBUSY;
clear_bit(WDT_OK_TO_CLOSE, &wdt_status);
orion_wdt_enable();
return nonseekable_open(inode, file);
}
static ssize_t orion_wdt_write(struct file *file, const char *data,
size_t len, loff_t *ppos)
{
if (len) {
if (!nowayout) {
size_t i;
clear_bit(WDT_OK_TO_CLOSE, &wdt_status);
for (i = 0; i != len; i++) {
char c;
if (get_user(c, data + i))
return -EFAULT;
if (c == 'V')
set_bit(WDT_OK_TO_CLOSE, &wdt_status);
}
}
orion_wdt_ping();
}
return len;
}
static int orion_wdt_settimeout(int new_time)
{
if ((new_time <= 0) || (new_time > wdt_max_duration))
return -EINVAL;
heartbeat = new_time;
return 0;
}
static long orion_wdt_ioctl(struct file *file, unsigned int cmd,
unsigned long arg)
{
int ret = -ENOTTY;
int time;
switch (cmd) {
case WDIOC_GETSUPPORT:
ret = copy_to_user((struct watchdog_info *)arg, &ident,
sizeof(ident)) ? -EFAULT : 0;
break;
case WDIOC_GETSTATUS:
case WDIOC_GETBOOTSTATUS:
ret = put_user(0, (int *)arg);
break;
case WDIOC_KEEPALIVE:
orion_wdt_ping();
ret = 0;
break;
case WDIOC_SETTIMEOUT:
ret = get_user(time, (int *)arg);
if (ret)
break;
if (orion_wdt_settimeout(time)) {
ret = -EINVAL;
break;
}
orion_wdt_ping();
case WDIOC_GETTIMEOUT:
ret = put_user(heartbeat, (int *)arg);
break;
case WDIOC_GETTIMELEFT:
if (orion_wdt_get_timeleft(&time)) {
ret = -EINVAL;
break;
}
ret = put_user(time, (int *)arg);
break;
}
return ret;
}
static int orion_wdt_release(struct inode *inode, struct file *file)
{
if (test_bit(WDT_OK_TO_CLOSE, &wdt_status))
orion_wdt_disable();
else
pr_crit("Device closed unexpectedly - timer will not stop\n");
clear_bit(WDT_IN_USE, &wdt_status);
clear_bit(WDT_OK_TO_CLOSE, &wdt_status);
return 0;
}
static int __devinit orion_wdt_probe(struct platform_device *pdev)
{
struct resource *res;
int ret;
clk = clk_get(&pdev->dev, NULL);
if (IS_ERR(clk)) {
printk(KERN_ERR "Orion Watchdog missing clock\n");
return -ENODEV;
}
clk_prepare_enable(clk);
wdt_tclk = clk_get_rate(clk);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
wdt_reg = ioremap(res->start, resource_size(res));
if (orion_wdt_miscdev.parent)
return -EBUSY;
orion_wdt_miscdev.parent = &pdev->dev;
wdt_max_duration = WDT_MAX_CYCLE_COUNT / wdt_tclk;
if (orion_wdt_settimeout(heartbeat))
heartbeat = wdt_max_duration;
ret = misc_register(&orion_wdt_miscdev);
if (ret)
return ret;
pr_info("Initial timeout %d sec%s\n",
heartbeat, nowayout ? ", nowayout" : "");
return 0;
}
static int __devexit orion_wdt_remove(struct platform_device *pdev)
{
int ret;
if (test_bit(WDT_IN_USE, &wdt_status)) {
orion_wdt_disable();
clear_bit(WDT_IN_USE, &wdt_status);
}
ret = misc_deregister(&orion_wdt_miscdev);
if (!ret)
orion_wdt_miscdev.parent = NULL;
clk_disable_unprepare(clk);
clk_put(clk);
return ret;
}
static void orion_wdt_shutdown(struct platform_device *pdev)
{
if (test_bit(WDT_IN_USE, &wdt_status))
orion_wdt_disable();
}
