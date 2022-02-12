static inline void nuc900_wdt_keepalive(void)
{
unsigned int val;
spin_lock(&nuc900_wdt->wdt_lock);
val = __raw_readl(nuc900_wdt->wdt_base + REG_WTCR);
val |= (WTR | WTIF);
__raw_writel(val, nuc900_wdt->wdt_base + REG_WTCR);
spin_unlock(&nuc900_wdt->wdt_lock);
}
static inline void nuc900_wdt_start(void)
{
unsigned int val;
spin_lock(&nuc900_wdt->wdt_lock);
val = __raw_readl(nuc900_wdt->wdt_base + REG_WTCR);
val |= (WTRE | WTE | WTR | WTCLK | WTIF);
val &= ~WTIS;
val |= (WDT_HW_TIMEOUT << 0x04);
__raw_writel(val, nuc900_wdt->wdt_base + REG_WTCR);
spin_unlock(&nuc900_wdt->wdt_lock);
nuc900_wdt->next_heartbeat = jiffies + heartbeat * HZ;
mod_timer(&nuc900_wdt->timer, jiffies + WDT_TIMEOUT);
}
static inline void nuc900_wdt_stop(void)
{
unsigned int val;
del_timer(&nuc900_wdt->timer);
spin_lock(&nuc900_wdt->wdt_lock);
val = __raw_readl(nuc900_wdt->wdt_base + REG_WTCR);
val &= ~WTE;
__raw_writel(val, nuc900_wdt->wdt_base + REG_WTCR);
spin_unlock(&nuc900_wdt->wdt_lock);
}
static inline void nuc900_wdt_ping(void)
{
nuc900_wdt->next_heartbeat = jiffies + heartbeat * HZ;
}
static int nuc900_wdt_open(struct inode *inode, struct file *file)
{
if (test_and_set_bit(0, &nuc900wdt_busy))
return -EBUSY;
nuc900_wdt_start();
return nonseekable_open(inode, file);
}
static int nuc900_wdt_close(struct inode *inode, struct file *file)
{
if (nuc900_wdt->expect_close == 42)
nuc900_wdt_stop();
else {
dev_crit(&nuc900_wdt->pdev->dev,
"Unexpected close, not stopping watchdog!\n");
nuc900_wdt_ping();
}
nuc900_wdt->expect_close = 0;
clear_bit(0, &nuc900wdt_busy);
return 0;
}
static long nuc900_wdt_ioctl(struct file *file,
unsigned int cmd, unsigned long arg)
{
void __user *argp = (void __user *)arg;
int __user *p = argp;
int new_value;
switch (cmd) {
case WDIOC_GETSUPPORT:
return copy_to_user(argp, &nuc900_wdt_info,
sizeof(nuc900_wdt_info)) ? -EFAULT : 0;
case WDIOC_GETSTATUS:
case WDIOC_GETBOOTSTATUS:
return put_user(0, p);
case WDIOC_KEEPALIVE:
nuc900_wdt_ping();
return 0;
case WDIOC_SETTIMEOUT:
if (get_user(new_value, p))
return -EFAULT;
heartbeat = new_value;
nuc900_wdt_ping();
return put_user(new_value, p);
case WDIOC_GETTIMEOUT:
return put_user(heartbeat, p);
default:
return -ENOTTY;
}
}
static ssize_t nuc900_wdt_write(struct file *file, const char __user *data,
size_t len, loff_t *ppos)
{
if (!len)
return 0;
if (!nowayout) {
size_t i;
nuc900_wdt->expect_close = 0;
for (i = 0; i < len; i++) {
char c;
if (get_user(c, data + i))
return -EFAULT;
if (c == 'V') {
nuc900_wdt->expect_close = 42;
break;
}
}
}
nuc900_wdt_ping();
return len;
}
static void nuc900_wdt_timer_ping(unsigned long data)
{
if (time_before(jiffies, nuc900_wdt->next_heartbeat)) {
nuc900_wdt_keepalive();
mod_timer(&nuc900_wdt->timer, jiffies + WDT_TIMEOUT);
} else
dev_warn(&nuc900_wdt->pdev->dev, "Will reset the machine !\n");
}
static int nuc900wdt_probe(struct platform_device *pdev)
{
struct resource *res;
int ret = 0;
nuc900_wdt = devm_kzalloc(&pdev->dev, sizeof(*nuc900_wdt),
GFP_KERNEL);
if (!nuc900_wdt)
return -ENOMEM;
nuc900_wdt->pdev = pdev;
spin_lock_init(&nuc900_wdt->wdt_lock);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (res == NULL) {
dev_err(&pdev->dev, "no memory resource specified\n");
return -ENOENT;
}
nuc900_wdt->wdt_base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(nuc900_wdt->wdt_base))
return PTR_ERR(nuc900_wdt->wdt_base);
nuc900_wdt->wdt_clock = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(nuc900_wdt->wdt_clock)) {
dev_err(&pdev->dev, "failed to find watchdog clock source\n");
return PTR_ERR(nuc900_wdt->wdt_clock);
}
clk_enable(nuc900_wdt->wdt_clock);
setup_timer(&nuc900_wdt->timer, nuc900_wdt_timer_ping, 0);
ret = misc_register(&nuc900wdt_miscdev);
if (ret) {
dev_err(&pdev->dev, "err register miscdev on minor=%d (%d)\n",
WATCHDOG_MINOR, ret);
goto err_clk;
}
return 0;
err_clk:
clk_disable(nuc900_wdt->wdt_clock);
return ret;
}
static int nuc900wdt_remove(struct platform_device *pdev)
{
misc_deregister(&nuc900wdt_miscdev);
clk_disable(nuc900_wdt->wdt_clock);
return 0;
}
