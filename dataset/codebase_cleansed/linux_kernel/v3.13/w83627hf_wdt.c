static void superio_outb(int reg, int val)
{
outb(reg, WDT_EFER);
outb(val, WDT_EFDR);
}
static inline int superio_inb(int reg)
{
outb(reg, WDT_EFER);
return inb(WDT_EFDR);
}
static int superio_enter(void)
{
if (!request_muxed_region(wdt_io, 2, WATCHDOG_NAME))
return -EBUSY;
outb_p(0x87, WDT_EFER);
outb_p(0x87, WDT_EFER);
return 0;
}
static void superio_select(int ld)
{
superio_outb(0x07, ld);
}
static void superio_exit(void)
{
outb_p(0xAA, WDT_EFER);
release_region(wdt_io, 2);
}
static int w83627hf_init(struct watchdog_device *wdog)
{
int ret;
unsigned char t;
ret = superio_enter();
if (ret)
return ret;
superio_select(W83627HF_LD_WDT);
t = superio_inb(0x20);
if (t == 0x82) {
t = (superio_inb(0x2b) & 0xf7);
superio_outb(0x2b, t | 0x04);
} else if (t == 0x88 || t == 0xa0) {
t = superio_inb(0x2d);
superio_outb(0x2d, t & ~0x01);
}
t = superio_inb(0x30);
if (!(t & 0x01))
superio_outb(0x30, t | 0x01);
t = superio_inb(0xF6);
if (t != 0) {
pr_info("Watchdog already running. Resetting timeout to %d sec\n",
wdog->timeout);
superio_outb(0xF6, wdog->timeout);
}
t = superio_inb(0xF5) & ~0x0C;
t |= 0x02;
superio_outb(0xF5, t);
t = superio_inb(0xF7) & ~0xC0;
superio_outb(0xF7, t);
superio_exit();
return 0;
}
static int wdt_set_time(unsigned int timeout)
{
int ret;
ret = superio_enter();
if (ret)
return ret;
superio_select(W83627HF_LD_WDT);
superio_outb(0xF6, timeout);
superio_exit();
return 0;
}
static int wdt_start(struct watchdog_device *wdog)
{
return wdt_set_time(wdog->timeout);
}
static int wdt_stop(struct watchdog_device *wdog)
{
return wdt_set_time(0);
}
static int wdt_set_timeout(struct watchdog_device *wdog, unsigned int timeout)
{
wdog->timeout = timeout;
return 0;
}
static unsigned int wdt_get_time(struct watchdog_device *wdog)
{
unsigned int timeleft;
int ret;
ret = superio_enter();
if (ret)
return 0;
superio_select(W83627HF_LD_WDT);
timeleft = superio_inb(0xF6);
superio_exit();
return timeleft;
}
static int wdt_notify_sys(struct notifier_block *this, unsigned long code,
void *unused)
{
if (code == SYS_DOWN || code == SYS_HALT)
wdt_set_time(0);
return NOTIFY_DONE;
}
static int __init wdt_init(void)
{
int ret;
pr_info("WDT driver for the Winbond(TM) W83627HF/THF/HG/DHG Super I/O chip initialising\n");
watchdog_init_timeout(&wdt_dev, timeout, NULL);
watchdog_set_nowayout(&wdt_dev, nowayout);
ret = w83627hf_init(&wdt_dev);
if (ret) {
pr_err("failed to initialize watchdog (err=%d)\n", ret);
return ret;
}
ret = register_reboot_notifier(&wdt_notifier);
if (ret != 0) {
pr_err("cannot register reboot notifier (err=%d)\n", ret);
return ret;
}
ret = watchdog_register_device(&wdt_dev);
if (ret)
goto unreg_reboot;
pr_info("initialized. timeout=%d sec (nowayout=%d)\n",
wdt_dev.timeout, nowayout);
return ret;
unreg_reboot:
unregister_reboot_notifier(&wdt_notifier);
return ret;
}
static void __exit wdt_exit(void)
{
watchdog_unregister_device(&wdt_dev);
unregister_reboot_notifier(&wdt_notifier);
}
