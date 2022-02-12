static void ie6xx_wdt_unlock_registers(void)
{
outb(0x80, ie6xx_wdt_data.sch_wdtba + RR0);
outb(0x86, ie6xx_wdt_data.sch_wdtba + RR0);
}
static int ie6xx_wdt_ping(struct watchdog_device *wdd)
{
spin_lock(&ie6xx_wdt_data.unlock_sequence);
ie6xx_wdt_unlock_registers();
outb(WDT_RELOAD, ie6xx_wdt_data.sch_wdtba + RR1);
spin_unlock(&ie6xx_wdt_data.unlock_sequence);
return 0;
}
static int ie6xx_wdt_set_timeout(struct watchdog_device *wdd, unsigned int t)
{
u32 preload;
u64 clock;
u8 wdtcr;
clock = 33000000;
preload = (t * clock) >> 15;
preload -= 1;
spin_lock(&ie6xx_wdt_data.unlock_sequence);
wdtcr = resetmode & 0x38;
outb(wdtcr, ie6xx_wdt_data.sch_wdtba + WDTCR);
ie6xx_wdt_unlock_registers();
outl(0, ie6xx_wdt_data.sch_wdtba + PV1);
ie6xx_wdt_unlock_registers();
outl(preload, ie6xx_wdt_data.sch_wdtba + PV2);
ie6xx_wdt_unlock_registers();
outb(WDT_RELOAD | WDT_TOUT, ie6xx_wdt_data.sch_wdtba + RR1);
spin_unlock(&ie6xx_wdt_data.unlock_sequence);
wdd->timeout = t;
return 0;
}
static int ie6xx_wdt_start(struct watchdog_device *wdd)
{
ie6xx_wdt_set_timeout(wdd, wdd->timeout);
spin_lock(&ie6xx_wdt_data.unlock_sequence);
outb(WDT_ENABLE, ie6xx_wdt_data.sch_wdtba + WDTLR);
spin_unlock(&ie6xx_wdt_data.unlock_sequence);
return 0;
}
static int ie6xx_wdt_stop(struct watchdog_device *wdd)
{
if (inb(ie6xx_wdt_data.sch_wdtba + WDTLR) & WDT_LOCK)
return -1;
spin_lock(&ie6xx_wdt_data.unlock_sequence);
outb(0, ie6xx_wdt_data.sch_wdtba + WDTLR);
spin_unlock(&ie6xx_wdt_data.unlock_sequence);
return 0;
}
static int ie6xx_wdt_dbg_show(struct seq_file *s, void *unused)
{
seq_printf(s, "PV1 = 0x%08x\n",
inl(ie6xx_wdt_data.sch_wdtba + PV1));
seq_printf(s, "PV2 = 0x%08x\n",
inl(ie6xx_wdt_data.sch_wdtba + PV2));
seq_printf(s, "RR = 0x%08x\n",
inw(ie6xx_wdt_data.sch_wdtba + RR0));
seq_printf(s, "WDTCR = 0x%08x\n",
inw(ie6xx_wdt_data.sch_wdtba + WDTCR));
seq_printf(s, "DCR = 0x%08x\n",
inl(ie6xx_wdt_data.sch_wdtba + DCR));
seq_printf(s, "WDTLR = 0x%08x\n",
inw(ie6xx_wdt_data.sch_wdtba + WDTLR));
seq_printf(s, "\n");
return 0;
}
static int ie6xx_wdt_dbg_open(struct inode *inode, struct file *file)
{
return single_open(file, ie6xx_wdt_dbg_show, NULL);
}
static void __devinit ie6xx_wdt_debugfs_init(void)
{
ie6xx_wdt_data.debugfs = debugfs_create_file("ie6xx_wdt",
S_IFREG | S_IRUGO, NULL, NULL, &ie6xx_wdt_dbg_operations);
}
static void ie6xx_wdt_debugfs_exit(void)
{
debugfs_remove(ie6xx_wdt_data.debugfs);
}
static void __devinit ie6xx_wdt_debugfs_init(void)
{
}
static void ie6xx_wdt_debugfs_exit(void)
{
}
static int __devinit ie6xx_wdt_probe(struct platform_device *pdev)
{
struct resource *res;
u8 wdtlr;
int ret;
res = platform_get_resource(pdev, IORESOURCE_IO, 0);
if (!res)
return -ENODEV;
if (!request_region(res->start, resource_size(res), pdev->name)) {
dev_err(&pdev->dev, "Watchdog region 0x%llx already in use!\n",
(u64)res->start);
return -EBUSY;
}
ie6xx_wdt_data.sch_wdtba = res->start;
dev_dbg(&pdev->dev, "WDT = 0x%X\n", ie6xx_wdt_data.sch_wdtba);
ie6xx_wdt_dev.timeout = timeout;
watchdog_set_nowayout(&ie6xx_wdt_dev, nowayout);
spin_lock_init(&ie6xx_wdt_data.unlock_sequence);
wdtlr = inb(ie6xx_wdt_data.sch_wdtba + WDTLR);
if (wdtlr & WDT_LOCK)
dev_warn(&pdev->dev,
"Watchdog Timer is Locked (Reg=0x%x)\n", wdtlr);
ie6xx_wdt_debugfs_init();
ret = watchdog_register_device(&ie6xx_wdt_dev);
if (ret) {
dev_err(&pdev->dev,
"Watchdog timer: cannot register device (err =%d)\n",
ret);
goto misc_register_error;
}
return 0;
misc_register_error:
ie6xx_wdt_debugfs_exit();
release_region(res->start, resource_size(res));
ie6xx_wdt_data.sch_wdtba = 0;
return ret;
}
static int __devexit ie6xx_wdt_remove(struct platform_device *pdev)
{
struct resource *res;
res = platform_get_resource(pdev, IORESOURCE_IO, 0);
ie6xx_wdt_stop(NULL);
watchdog_unregister_device(&ie6xx_wdt_dev);
ie6xx_wdt_debugfs_exit();
release_region(res->start, resource_size(res));
ie6xx_wdt_data.sch_wdtba = 0;
return 0;
}
static int __init ie6xx_wdt_init(void)
{
if ((timeout < MIN_TIME) ||
(timeout > MAX_TIME)) {
pr_err("Watchdog timer: value of timeout %d (dec) "
"is out of range from %d to %d (dec)\n",
timeout, MIN_TIME, MAX_TIME);
return -EINVAL;
}
return platform_driver_register(&ie6xx_wdt_driver);
}
static void __exit ie6xx_wdt_exit(void)
{
platform_driver_unregister(&ie6xx_wdt_driver);
}
