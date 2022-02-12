static inline int superio_enter(void)
{
if (!request_muxed_region(REG, 2, WATCHDOG_NAME))
return -EBUSY;
outb(0x87, REG);
outb(0x01, REG);
outb(0x55, REG);
outb(0x55, REG);
return 0;
}
static inline void superio_exit(void)
{
outb(0x02, REG);
outb(0x02, VAL);
release_region(REG, 2);
}
static inline void superio_select(int ldn)
{
outb(LDNREG, REG);
outb(ldn, VAL);
}
static inline int superio_inb(int reg)
{
outb(reg, REG);
return inb(VAL);
}
static inline void superio_outb(int val, int reg)
{
outb(reg, REG);
outb(val, VAL);
}
static inline int superio_inw(int reg)
{
int val;
outb(reg++, REG);
val = inb(VAL) << 8;
outb(reg, REG);
val |= inb(VAL);
return val;
}
static inline void superio_outw(int val, int reg)
{
outb(reg++, REG);
outb(val >> 8, VAL);
outb(reg, REG);
outb(val, VAL);
}
static void _wdt_update_timeout(unsigned int t)
{
unsigned char cfg = WDT_KRST;
if (testmode)
cfg = 0;
if (t <= max_units)
cfg |= WDT_TOV1;
else
t /= 60;
if (chip_type != IT8721_ID)
cfg |= WDT_PWROK;
superio_outb(cfg, WDTCFG);
superio_outb(t, WDTVALLSB);
if (max_units > 255)
superio_outb(t >> 8, WDTVALMSB);
}
static int wdt_update_timeout(unsigned int t)
{
int ret;
ret = superio_enter();
if (ret)
return ret;
superio_select(GPIO);
_wdt_update_timeout(t);
superio_exit();
return 0;
}
static int wdt_round_time(int t)
{
t += 59;
t -= t % 60;
return t;
}
static int wdt_start(struct watchdog_device *wdd)
{
return wdt_update_timeout(wdd->timeout);
}
static int wdt_stop(struct watchdog_device *wdd)
{
return wdt_update_timeout(0);
}
static int wdt_set_timeout(struct watchdog_device *wdd, unsigned int t)
{
int ret = 0;
if (t > max_units)
t = wdt_round_time(t);
wdd->timeout = t;
if (watchdog_hw_running(wdd))
ret = wdt_update_timeout(t);
return ret;
}
static int __init it87_wdt_init(void)
{
u8 chip_rev;
int rc;
rc = superio_enter();
if (rc)
return rc;
chip_type = superio_inw(CHIPID);
chip_rev = superio_inb(CHIPREV) & 0x0f;
superio_exit();
switch (chip_type) {
case IT8702_ID:
max_units = 255;
break;
case IT8712_ID:
max_units = (chip_rev < 8) ? 255 : 65535;
break;
case IT8716_ID:
case IT8726_ID:
max_units = 65535;
break;
case IT8607_ID:
case IT8620_ID:
case IT8622_ID:
case IT8625_ID:
case IT8628_ID:
case IT8655_ID:
case IT8665_ID:
case IT8686_ID:
case IT8718_ID:
case IT8720_ID:
case IT8721_ID:
case IT8728_ID:
case IT8783_ID:
max_units = 65535;
break;
case IT8705_ID:
pr_err("Unsupported Chip found, Chip %04x Revision %02x\n",
chip_type, chip_rev);
return -ENODEV;
case NO_DEV_ID:
pr_err("no device\n");
return -ENODEV;
default:
pr_err("Unknown Chip found, Chip %04x Revision %04x\n",
chip_type, chip_rev);
return -ENODEV;
}
rc = superio_enter();
if (rc)
return rc;
superio_select(GPIO);
superio_outb(WDT_TOV1, WDTCFG);
superio_outb(0x00, WDTCTRL);
superio_exit();
if (timeout < 1 || timeout > max_units * 60) {
timeout = DEFAULT_TIMEOUT;
pr_warn("Timeout value out of range, use default %d sec\n",
DEFAULT_TIMEOUT);
}
if (timeout > max_units)
timeout = wdt_round_time(timeout);
wdt_dev.timeout = timeout;
wdt_dev.max_timeout = max_units * 60;
watchdog_stop_on_reboot(&wdt_dev);
rc = watchdog_register_device(&wdt_dev);
if (rc) {
pr_err("Cannot register watchdog device (err=%d)\n", rc);
return rc;
}
pr_info("Chip IT%04x revision %d initialized. timeout=%d sec (nowayout=%d testmode=%d)\n",
chip_type, chip_rev, timeout, nowayout, testmode);
return 0;
}
static void __exit it87_wdt_exit(void)
{
watchdog_unregister_device(&wdt_dev);
}
