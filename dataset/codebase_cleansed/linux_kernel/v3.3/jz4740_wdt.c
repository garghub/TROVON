static void jz4740_wdt_service(void)
{
writew(0x0, jz4740_wdt.base + JZ_REG_WDT_TIMER_COUNTER);
}
static void jz4740_wdt_set_heartbeat(int new_heartbeat)
{
unsigned int rtc_clk_rate;
unsigned int timeout_value;
unsigned short clock_div = JZ_WDT_CLOCK_DIV_1;
heartbeat = new_heartbeat;
rtc_clk_rate = clk_get_rate(jz4740_wdt.rtc_clk);
timeout_value = rtc_clk_rate * heartbeat;
while (timeout_value > 0xffff) {
if (clock_div == JZ_WDT_CLOCK_DIV_1024) {
timeout_value = 0xffff;
break;
}
timeout_value >>= 2;
clock_div += (1 << JZ_WDT_CLOCK_DIV_SHIFT);
}
writeb(0x0, jz4740_wdt.base + JZ_REG_WDT_COUNTER_ENABLE);
writew(clock_div, jz4740_wdt.base + JZ_REG_WDT_TIMER_CONTROL);
writew((u16)timeout_value, jz4740_wdt.base + JZ_REG_WDT_TIMER_DATA);
writew(0x0, jz4740_wdt.base + JZ_REG_WDT_TIMER_COUNTER);
writew(clock_div | JZ_WDT_CLOCK_RTC,
jz4740_wdt.base + JZ_REG_WDT_TIMER_CONTROL);
writeb(0x1, jz4740_wdt.base + JZ_REG_WDT_COUNTER_ENABLE);
}
static void jz4740_wdt_enable(void)
{
jz4740_timer_enable_watchdog();
jz4740_wdt_set_heartbeat(heartbeat);
}
static void jz4740_wdt_disable(void)
{
jz4740_timer_disable_watchdog();
writeb(0x0, jz4740_wdt.base + JZ_REG_WDT_COUNTER_ENABLE);
}
static int jz4740_wdt_open(struct inode *inode, struct file *file)
{
if (test_and_set_bit(WDT_IN_USE, &jz4740_wdt.status))
return -EBUSY;
jz4740_wdt_enable();
return nonseekable_open(inode, file);
}
static ssize_t jz4740_wdt_write(struct file *file, const char *data,
size_t len, loff_t *ppos)
{
if (len) {
size_t i;
clear_bit(WDT_OK_TO_CLOSE, &jz4740_wdt.status);
for (i = 0; i != len; i++) {
char c;
if (get_user(c, data + i))
return -EFAULT;
if (c == 'V')
set_bit(WDT_OK_TO_CLOSE, &jz4740_wdt.status);
}
jz4740_wdt_service();
}
return len;
}
static long jz4740_wdt_ioctl(struct file *file,
unsigned int cmd, unsigned long arg)
{
int ret = -ENOTTY;
int heartbeat_seconds;
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
jz4740_wdt_service();
return 0;
case WDIOC_SETTIMEOUT:
if (get_user(heartbeat_seconds, (int __user *)arg))
return -EFAULT;
jz4740_wdt_set_heartbeat(heartbeat_seconds);
return 0;
case WDIOC_GETTIMEOUT:
return put_user(heartbeat, (int *)arg);
default:
break;
}
return ret;
}
static int jz4740_wdt_release(struct inode *inode, struct file *file)
{
jz4740_wdt_service();
if (test_and_clear_bit(WDT_OK_TO_CLOSE, &jz4740_wdt.status))
jz4740_wdt_disable();
clear_bit(WDT_IN_USE, &jz4740_wdt.status);
return 0;
}
static int __devinit jz4740_wdt_probe(struct platform_device *pdev)
{
int ret = 0, size;
struct resource *res;
struct device *dev = &pdev->dev;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (res == NULL) {
dev_err(dev, "failed to get memory region resource\n");
return -ENXIO;
}
size = resource_size(res);
jz4740_wdt.mem = request_mem_region(res->start, size, pdev->name);
if (jz4740_wdt.mem == NULL) {
dev_err(dev, "failed to get memory region\n");
return -EBUSY;
}
jz4740_wdt.base = ioremap_nocache(res->start, size);
if (jz4740_wdt.base == NULL) {
dev_err(dev, "failed to map memory region\n");
ret = -EBUSY;
goto err_release_region;
}
jz4740_wdt.rtc_clk = clk_get(NULL, "rtc");
if (IS_ERR(jz4740_wdt.rtc_clk)) {
dev_err(dev, "cannot find RTC clock\n");
ret = PTR_ERR(jz4740_wdt.rtc_clk);
goto err_iounmap;
}
ret = misc_register(&jz4740_wdt_miscdev);
if (ret < 0) {
dev_err(dev, "cannot register misc device\n");
goto err_disable_clk;
}
return 0;
err_disable_clk:
clk_put(jz4740_wdt.rtc_clk);
err_iounmap:
iounmap(jz4740_wdt.base);
err_release_region:
release_mem_region(jz4740_wdt.mem->start,
resource_size(jz4740_wdt.mem));
return ret;
}
static int __devexit jz4740_wdt_remove(struct platform_device *pdev)
{
jz4740_wdt_disable();
misc_deregister(&jz4740_wdt_miscdev);
clk_put(jz4740_wdt.rtc_clk);
iounmap(jz4740_wdt.base);
jz4740_wdt.base = NULL;
release_mem_region(jz4740_wdt.mem->start,
resource_size(jz4740_wdt.mem));
jz4740_wdt.mem = NULL;
return 0;
}
