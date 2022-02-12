static inline int dw_wdt_is_enabled(void)
{
return readl(dw_wdt.regs + WDOG_CONTROL_REG_OFFSET) &
WDOG_CONTROL_REG_WDT_EN_MASK;
}
static inline int dw_wdt_top_in_seconds(unsigned top)
{
return (1 << (16 + top)) / clk_get_rate(dw_wdt.clk);
}
static int dw_wdt_get_top(void)
{
int top = readl(dw_wdt.regs + WDOG_TIMEOUT_RANGE_REG_OFFSET) & 0xF;
return dw_wdt_top_in_seconds(top);
}
static inline void dw_wdt_set_next_heartbeat(void)
{
dw_wdt.next_heartbeat = jiffies + dw_wdt_get_top() * HZ;
}
static int dw_wdt_set_top(unsigned top_s)
{
int i, top_val = DW_WDT_MAX_TOP;
for (i = 0; i <= DW_WDT_MAX_TOP; ++i)
if (dw_wdt_top_in_seconds(i) >= top_s) {
top_val = i;
break;
}
writel(top_val, dw_wdt.regs + WDOG_TIMEOUT_RANGE_REG_OFFSET);
dw_wdt_set_next_heartbeat();
return dw_wdt_top_in_seconds(top_val);
}
static void dw_wdt_keepalive(void)
{
writel(WDOG_COUNTER_RESTART_KICK_VALUE, dw_wdt.regs +
WDOG_COUNTER_RESTART_REG_OFFSET);
}
static void dw_wdt_ping(unsigned long data)
{
if (time_before(jiffies, dw_wdt.next_heartbeat) ||
(!nowayout && !dw_wdt.in_use)) {
dw_wdt_keepalive();
mod_timer(&dw_wdt.timer, jiffies + WDT_TIMEOUT);
} else
pr_crit("keepalive missed, machine will reset\n");
}
static int dw_wdt_open(struct inode *inode, struct file *filp)
{
if (test_and_set_bit(0, &dw_wdt.in_use))
return -EBUSY;
__module_get(THIS_MODULE);
spin_lock(&dw_wdt.lock);
if (!dw_wdt_is_enabled()) {
dw_wdt_set_top(DW_WDT_MAX_TOP);
writel(WDOG_CONTROL_REG_WDT_EN_MASK,
dw_wdt.regs + WDOG_CONTROL_REG_OFFSET);
}
dw_wdt_set_next_heartbeat();
spin_unlock(&dw_wdt.lock);
return nonseekable_open(inode, filp);
}
static ssize_t dw_wdt_write(struct file *filp, const char __user *buf,
size_t len, loff_t *offset)
{
if (!len)
return 0;
if (!nowayout) {
size_t i;
dw_wdt.expect_close = 0;
for (i = 0; i < len; ++i) {
char c;
if (get_user(c, buf + i))
return -EFAULT;
if (c == 'V') {
dw_wdt.expect_close = 1;
break;
}
}
}
dw_wdt_set_next_heartbeat();
mod_timer(&dw_wdt.timer, jiffies + WDT_TIMEOUT);
return len;
}
static u32 dw_wdt_time_left(void)
{
return readl(dw_wdt.regs + WDOG_CURRENT_COUNT_REG_OFFSET) /
clk_get_rate(dw_wdt.clk);
}
static long dw_wdt_ioctl(struct file *filp, unsigned int cmd, unsigned long arg)
{
unsigned long val;
int timeout;
switch (cmd) {
case WDIOC_GETSUPPORT:
return copy_to_user((void __user *)arg, &dw_wdt_ident,
sizeof(dw_wdt_ident)) ? -EFAULT : 0;
case WDIOC_GETSTATUS:
case WDIOC_GETBOOTSTATUS:
return put_user(0, (int __user *)arg);
case WDIOC_KEEPALIVE:
dw_wdt_set_next_heartbeat();
return 0;
case WDIOC_SETTIMEOUT:
if (get_user(val, (int __user *)arg))
return -EFAULT;
timeout = dw_wdt_set_top(val);
return put_user(timeout , (int __user *)arg);
case WDIOC_GETTIMEOUT:
return put_user(dw_wdt_get_top(), (int __user *)arg);
case WDIOC_GETTIMELEFT:
if (get_user(val, (int __user *)arg))
return -EFAULT;
return put_user(dw_wdt_time_left(), (int __user *)arg);
default:
return -ENOTTY;
}
}
static int dw_wdt_release(struct inode *inode, struct file *filp)
{
clear_bit(0, &dw_wdt.in_use);
if (!dw_wdt.expect_close) {
del_timer(&dw_wdt.timer);
if (!nowayout)
pr_crit("unexpected close, system will reboot soon\n");
else
pr_crit("watchdog cannot be disabled, system will reboot soon\n");
}
dw_wdt.expect_close = 0;
return 0;
}
static int dw_wdt_suspend(struct device *dev)
{
clk_disable_unprepare(dw_wdt.clk);
return 0;
}
static int dw_wdt_resume(struct device *dev)
{
int err = clk_prepare_enable(dw_wdt.clk);
if (err)
return err;
dw_wdt_keepalive();
return 0;
}
static int dw_wdt_drv_probe(struct platform_device *pdev)
{
int ret;
struct resource *mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
dw_wdt.regs = devm_ioremap_resource(&pdev->dev, mem);
if (IS_ERR(dw_wdt.regs))
return PTR_ERR(dw_wdt.regs);
dw_wdt.clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(dw_wdt.clk))
return PTR_ERR(dw_wdt.clk);
ret = clk_prepare_enable(dw_wdt.clk);
if (ret)
return ret;
spin_lock_init(&dw_wdt.lock);
ret = misc_register(&dw_wdt_miscdev);
if (ret)
goto out_disable_clk;
dw_wdt_set_next_heartbeat();
setup_timer(&dw_wdt.timer, dw_wdt_ping, 0);
mod_timer(&dw_wdt.timer, jiffies + WDT_TIMEOUT);
return 0;
out_disable_clk:
clk_disable_unprepare(dw_wdt.clk);
return ret;
}
static int dw_wdt_drv_remove(struct platform_device *pdev)
{
misc_deregister(&dw_wdt_miscdev);
clk_disable_unprepare(dw_wdt.clk);
return 0;
}
