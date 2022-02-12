static void wdt_service(void)
{
spin_lock(&io_lock);
iowrite32(WDKEY_SEQ0, wdt_base + WDTCR);
iowrite32(WDKEY_SEQ1, wdt_base + WDTCR);
spin_unlock(&io_lock);
}
static void wdt_enable(void)
{
u32 tgcr;
u32 timer_margin;
unsigned long wdt_freq;
wdt_freq = clk_get_rate(wdt_clk);
spin_lock(&io_lock);
iowrite32(0, wdt_base + TCR);
iowrite32(0, wdt_base + TGCR);
tgcr = TIMMODE_64BIT_WDOG | TIM12RS_UNRESET | TIM34RS_UNRESET;
iowrite32(tgcr, wdt_base + TGCR);
iowrite32(0, wdt_base + TIM12);
iowrite32(0, wdt_base + TIM34);
timer_margin = (((u64)heartbeat * wdt_freq) & 0xffffffff);
iowrite32(timer_margin, wdt_base + PRD12);
timer_margin = (((u64)heartbeat * wdt_freq) >> 32);
iowrite32(timer_margin, wdt_base + PRD34);
iowrite32(ENAMODE12_PERIODIC, wdt_base + TCR);
iowrite32(WDKEY_SEQ0 | WDEN, wdt_base + WDTCR);
iowrite32(WDKEY_SEQ1 | WDEN, wdt_base + WDTCR);
spin_unlock(&io_lock);
}
static int davinci_wdt_open(struct inode *inode, struct file *file)
{
if (test_and_set_bit(WDT_IN_USE, &wdt_status))
return -EBUSY;
wdt_enable();
return nonseekable_open(inode, file);
}
static ssize_t
davinci_wdt_write(struct file *file, const char *data, size_t len,
loff_t *ppos)
{
if (len)
wdt_service();
return len;
}
static long davinci_wdt_ioctl(struct file *file,
unsigned int cmd, unsigned long arg)
{
int ret = -ENOTTY;
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
wdt_service();
ret = 0;
break;
case WDIOC_GETTIMEOUT:
ret = put_user(heartbeat, (int *)arg);
break;
}
return ret;
}
static int davinci_wdt_release(struct inode *inode, struct file *file)
{
wdt_service();
clear_bit(WDT_IN_USE, &wdt_status);
return 0;
}
static int davinci_wdt_probe(struct platform_device *pdev)
{
int ret = 0, size;
struct device *dev = &pdev->dev;
wdt_clk = clk_get(dev, NULL);
if (WARN_ON(IS_ERR(wdt_clk)))
return PTR_ERR(wdt_clk);
clk_prepare_enable(wdt_clk);
if (heartbeat < 1 || heartbeat > MAX_HEARTBEAT)
heartbeat = DEFAULT_HEARTBEAT;
dev_info(dev, "heartbeat %d sec\n", heartbeat);
wdt_mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (wdt_mem == NULL) {
dev_err(dev, "failed to get memory region resource\n");
return -ENOENT;
}
size = resource_size(wdt_mem);
if (!request_mem_region(wdt_mem->start, size, pdev->name)) {
dev_err(dev, "failed to get memory region\n");
return -ENOENT;
}
wdt_base = ioremap(wdt_mem->start, size);
if (!wdt_base) {
dev_err(dev, "failed to map memory region\n");
release_mem_region(wdt_mem->start, size);
wdt_mem = NULL;
return -ENOMEM;
}
ret = misc_register(&davinci_wdt_miscdev);
if (ret < 0) {
dev_err(dev, "cannot register misc device\n");
release_mem_region(wdt_mem->start, size);
wdt_mem = NULL;
} else {
set_bit(WDT_DEVICE_INITED, &wdt_status);
}
iounmap(wdt_base);
return ret;
}
static int davinci_wdt_remove(struct platform_device *pdev)
{
misc_deregister(&davinci_wdt_miscdev);
if (wdt_mem) {
release_mem_region(wdt_mem->start, resource_size(wdt_mem));
wdt_mem = NULL;
}
clk_disable_unprepare(wdt_clk);
clk_put(wdt_clk);
return 0;
}
