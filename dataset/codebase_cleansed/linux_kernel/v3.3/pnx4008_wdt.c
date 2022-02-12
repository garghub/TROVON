static void wdt_enable(void)
{
spin_lock(&io_lock);
__raw_writel(RESET_COUNT, WDTIM_CTRL(wdt_base));
while (__raw_readl(WDTIM_COUNTER(wdt_base)))
cpu_relax();
__raw_writel(M_RES2 | STOP_COUNT0 | RESET_COUNT0,
WDTIM_MCTRL(wdt_base));
__raw_writel(MATCH_OUTPUT_HIGH, WDTIM_EMR(wdt_base));
__raw_writel(MATCH_INT, WDTIM_INT(wdt_base));
__raw_writel(0xFFFF, WDTIM_PULSE(wdt_base));
__raw_writel(heartbeat * WDOG_COUNTER_RATE, WDTIM_MATCH0(wdt_base));
__raw_writel(COUNT_ENAB | DEBUG_EN, WDTIM_CTRL(wdt_base));
spin_unlock(&io_lock);
}
static void wdt_disable(void)
{
spin_lock(&io_lock);
__raw_writel(0, WDTIM_CTRL(wdt_base));
spin_unlock(&io_lock);
}
static int pnx4008_wdt_open(struct inode *inode, struct file *file)
{
int ret;
if (test_and_set_bit(WDT_IN_USE, &wdt_status))
return -EBUSY;
clear_bit(WDT_OK_TO_CLOSE, &wdt_status);
ret = clk_enable(wdt_clk);
if (ret) {
clear_bit(WDT_IN_USE, &wdt_status);
return ret;
}
wdt_enable();
return nonseekable_open(inode, file);
}
static ssize_t pnx4008_wdt_write(struct file *file, const char *data,
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
wdt_enable();
}
return len;
}
static long pnx4008_wdt_ioctl(struct file *file, unsigned int cmd,
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
ret = put_user(0, (int *)arg);
break;
case WDIOC_GETBOOTSTATUS:
ret = put_user(boot_status, (int *)arg);
break;
case WDIOC_KEEPALIVE:
wdt_enable();
ret = 0;
break;
case WDIOC_SETTIMEOUT:
ret = get_user(time, (int *)arg);
if (ret)
break;
if (time <= 0 || time > MAX_HEARTBEAT) {
ret = -EINVAL;
break;
}
heartbeat = time;
wdt_enable();
case WDIOC_GETTIMEOUT:
ret = put_user(heartbeat, (int *)arg);
break;
}
return ret;
}
static int pnx4008_wdt_release(struct inode *inode, struct file *file)
{
if (!test_bit(WDT_OK_TO_CLOSE, &wdt_status))
printk(KERN_WARNING "WATCHDOG: Device closed unexpectedly\n");
wdt_disable();
clk_disable(wdt_clk);
clear_bit(WDT_IN_USE, &wdt_status);
clear_bit(WDT_OK_TO_CLOSE, &wdt_status);
return 0;
}
static int __devinit pnx4008_wdt_probe(struct platform_device *pdev)
{
int ret = 0, size;
if (heartbeat < 1 || heartbeat > MAX_HEARTBEAT)
heartbeat = DEFAULT_HEARTBEAT;
printk(KERN_INFO MODULE_NAME
"PNX4008 Watchdog Timer: heartbeat %d sec\n", heartbeat);
wdt_mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (wdt_mem == NULL) {
printk(KERN_INFO MODULE_NAME
"failed to get memory region resource\n");
return -ENOENT;
}
size = resource_size(wdt_mem);
if (!request_mem_region(wdt_mem->start, size, pdev->name)) {
printk(KERN_INFO MODULE_NAME "failed to get memory region\n");
return -ENOENT;
}
wdt_base = (void __iomem *)IO_ADDRESS(wdt_mem->start);
wdt_clk = clk_get(&pdev->dev, NULL);
if (IS_ERR(wdt_clk)) {
ret = PTR_ERR(wdt_clk);
release_mem_region(wdt_mem->start, size);
wdt_mem = NULL;
goto out;
}
ret = clk_enable(wdt_clk);
if (ret) {
release_mem_region(wdt_mem->start, size);
wdt_mem = NULL;
clk_put(wdt_clk);
goto out;
}
ret = misc_register(&pnx4008_wdt_miscdev);
if (ret < 0) {
printk(KERN_ERR MODULE_NAME "cannot register misc device\n");
release_mem_region(wdt_mem->start, size);
wdt_mem = NULL;
clk_disable(wdt_clk);
clk_put(wdt_clk);
} else {
boot_status = (__raw_readl(WDTIM_RES(wdt_base)) & WDOG_RESET) ?
WDIOF_CARDRESET : 0;
wdt_disable();
clk_disable(wdt_clk);
set_bit(WDT_DEVICE_INITED, &wdt_status);
}
out:
return ret;
}
static int __devexit pnx4008_wdt_remove(struct platform_device *pdev)
{
misc_deregister(&pnx4008_wdt_miscdev);
clk_disable(wdt_clk);
clk_put(wdt_clk);
if (wdt_mem) {
release_mem_region(wdt_mem->start, resource_size(wdt_mem));
wdt_mem = NULL;
}
return 0;
}
