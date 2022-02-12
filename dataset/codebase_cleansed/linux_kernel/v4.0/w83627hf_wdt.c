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
static int w83627hf_init(struct watchdog_device *wdog, enum chips chip)
{
int ret;
unsigned char t;
ret = superio_enter();
if (ret)
return ret;
superio_select(W83627HF_LD_WDT);
t = superio_inb(0x30);
if (!(t & 0x01))
superio_outb(0x30, t | 0x01);
switch (chip) {
case w83627hf:
case w83627s:
t = superio_inb(0x2B) & ~0x10;
superio_outb(0x2B, t);
break;
case w83697hf:
t = superio_inb(0x29) & ~0x60;
t |= 0x20;
superio_outb(0x29, t);
break;
case w83697ug:
t = superio_inb(0x2b) & ~0x04;
superio_outb(0x2b, t);
break;
case w83627thf:
t = (superio_inb(0x2B) & ~0x08) | 0x04;
superio_outb(0x2B, t);
break;
case w83627dhg:
case w83627dhg_p:
t = superio_inb(0x2D) & ~0x01;
superio_outb(0x2D, t);
t = superio_inb(cr_wdt_control);
t |= 0x02;
superio_outb(cr_wdt_control, t);
break;
case w83637hf:
break;
case w83687thf:
t = superio_inb(0x2C) & ~0x80;
superio_outb(0x2C, t);
break;
case w83627ehf:
case w83627uhg:
case w83667hg:
case w83667hg_b:
case nct6775:
case nct6776:
case nct6779:
case nct6791:
case nct6792:
t = superio_inb(cr_wdt_control);
t |= 0x02;
superio_outb(cr_wdt_control, t);
break;
default:
break;
}
t = superio_inb(cr_wdt_timeout);
if (t != 0) {
if (early_disable) {
pr_warn("Stopping previously enabled watchdog until userland kicks in\n");
superio_outb(cr_wdt_timeout, 0);
} else {
pr_info("Watchdog already running. Resetting timeout to %d sec\n",
wdog->timeout);
superio_outb(cr_wdt_timeout, wdog->timeout);
}
}
t = superio_inb(cr_wdt_control) & ~0x0C;
superio_outb(cr_wdt_control, t);
t = superio_inb(0xF7) & ~0xD0;
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
superio_outb(cr_wdt_timeout, timeout);
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
timeleft = superio_inb(cr_wdt_timeout);
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
static int wdt_find(int addr)
{
u8 val;
int ret;
cr_wdt_timeout = W83627HF_WDT_TIMEOUT;
cr_wdt_control = W83627HF_WDT_CONTROL;
ret = superio_enter();
if (ret)
return ret;
superio_select(W83627HF_LD_WDT);
val = superio_inb(0x20);
switch (val) {
case W83627HF_ID:
ret = w83627hf;
break;
case W83627S_ID:
ret = w83627s;
break;
case W83697HF_ID:
ret = w83697hf;
cr_wdt_timeout = W83697HF_WDT_TIMEOUT;
cr_wdt_control = W83697HF_WDT_CONTROL;
break;
case W83697UG_ID:
ret = w83697ug;
cr_wdt_timeout = W83697HF_WDT_TIMEOUT;
cr_wdt_control = W83697HF_WDT_CONTROL;
break;
case W83637HF_ID:
ret = w83637hf;
break;
case W83627THF_ID:
ret = w83627thf;
break;
case W83687THF_ID:
ret = w83687thf;
break;
case W83627EHF_ID:
ret = w83627ehf;
break;
case W83627DHG_ID:
ret = w83627dhg;
break;
case W83627DHG_P_ID:
ret = w83627dhg_p;
break;
case W83627UHG_ID:
ret = w83627uhg;
break;
case W83667HG_ID:
ret = w83667hg;
break;
case W83667HG_B_ID:
ret = w83667hg_b;
break;
case NCT6775_ID:
ret = nct6775;
break;
case NCT6776_ID:
ret = nct6776;
break;
case NCT6779_ID:
ret = nct6779;
break;
case NCT6791_ID:
ret = nct6791;
break;
case NCT6792_ID:
ret = nct6792;
break;
case 0xff:
ret = -ENODEV;
break;
default:
ret = -ENODEV;
pr_err("Unsupported chip ID: 0x%02x\n", val);
break;
}
superio_exit();
return ret;
}
static int __init wdt_init(void)
{
int ret;
int chip;
const char * const chip_name[] = {
"W83627HF",
"W83627S",
"W83697HF",
"W83697UG",
"W83637HF",
"W83627THF",
"W83687THF",
"W83627EHF",
"W83627DHG",
"W83627UHG",
"W83667HG",
"W83667DHG-P",
"W83667HG-B",
"NCT6775",
"NCT6776",
"NCT6779",
"NCT6791",
"NCT6792",
};
wdt_io = 0x2e;
chip = wdt_find(0x2e);
if (chip < 0) {
wdt_io = 0x4e;
chip = wdt_find(0x4e);
if (chip < 0)
return chip;
}
pr_info("WDT driver for %s Super I/O chip initialising\n",
chip_name[chip]);
watchdog_init_timeout(&wdt_dev, timeout, NULL);
watchdog_set_nowayout(&wdt_dev, nowayout);
ret = w83627hf_init(&wdt_dev, chip);
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
