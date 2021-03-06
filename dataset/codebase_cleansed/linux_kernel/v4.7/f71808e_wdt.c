static inline int superio_inb(int base, int reg)
{
outb(reg, base);
return inb(base + 1);
}
static int superio_inw(int base, int reg)
{
int val;
val = superio_inb(base, reg) << 8;
val |= superio_inb(base, reg + 1);
return val;
}
static inline void superio_outb(int base, int reg, u8 val)
{
outb(reg, base);
outb(val, base + 1);
}
static inline void superio_set_bit(int base, int reg, int bit)
{
unsigned long val = superio_inb(base, reg);
__set_bit(bit, &val);
superio_outb(base, reg, val);
}
static inline void superio_clear_bit(int base, int reg, int bit)
{
unsigned long val = superio_inb(base, reg);
__clear_bit(bit, &val);
superio_outb(base, reg, val);
}
static inline int superio_enter(int base)
{
if (!request_muxed_region(base, 2, DRVNAME)) {
pr_err("I/O address 0x%04x already in use\n", (int)base);
return -EBUSY;
}
outb(SIO_UNLOCK_KEY, base);
outb(SIO_UNLOCK_KEY, base);
return 0;
}
static inline void superio_select(int base, int ld)
{
outb(SIO_REG_LDSEL, base);
outb(ld, base + 1);
}
static inline void superio_exit(int base)
{
outb(SIO_LOCK_KEY, base);
release_region(base, 2);
}
static int watchdog_set_timeout(int timeout)
{
if (timeout <= 0
|| timeout > max_timeout) {
pr_err("watchdog timeout out of range\n");
return -EINVAL;
}
mutex_lock(&watchdog.lock);
watchdog.timeout = timeout;
if (timeout > 0xff) {
watchdog.timer_val = DIV_ROUND_UP(timeout, 60);
watchdog.minutes_mode = true;
} else {
watchdog.timer_val = timeout;
watchdog.minutes_mode = false;
}
mutex_unlock(&watchdog.lock);
return 0;
}
static int watchdog_set_pulse_width(unsigned int pw)
{
int err = 0;
mutex_lock(&watchdog.lock);
if (pw <= 1) {
watchdog.pulse_val = 0;
} else if (pw <= 25) {
watchdog.pulse_val = 1;
} else if (pw <= 125) {
watchdog.pulse_val = 2;
} else if (pw <= 5000) {
watchdog.pulse_val = 3;
} else {
pr_err("pulse width out of range\n");
err = -EINVAL;
goto exit_unlock;
}
watchdog.pulse_mode = pw;
exit_unlock:
mutex_unlock(&watchdog.lock);
return err;
}
static int watchdog_keepalive(void)
{
int err = 0;
mutex_lock(&watchdog.lock);
err = superio_enter(watchdog.sioaddr);
if (err)
goto exit_unlock;
superio_select(watchdog.sioaddr, SIO_F71808FG_LD_WDT);
if (watchdog.minutes_mode)
superio_set_bit(watchdog.sioaddr, F71808FG_REG_WDT_CONF,
F71808FG_FLAG_WD_UNIT);
else
superio_clear_bit(watchdog.sioaddr, F71808FG_REG_WDT_CONF,
F71808FG_FLAG_WD_UNIT);
superio_outb(watchdog.sioaddr, F71808FG_REG_WD_TIME,
watchdog.timer_val);
superio_exit(watchdog.sioaddr);
exit_unlock:
mutex_unlock(&watchdog.lock);
return err;
}
static int f71862fg_pin_configure(unsigned short ioaddr)
{
if (f71862fg_pin == 63) {
if (ioaddr) {
superio_clear_bit(ioaddr, SIO_REG_ROM_ADDR_SEL, 6);
superio_set_bit(ioaddr, SIO_REG_MFUNCT3, 4);
}
} else if (f71862fg_pin == 56) {
if (ioaddr)
superio_set_bit(ioaddr, SIO_REG_MFUNCT1, 1);
} else {
pr_err("Invalid argument f71862fg_pin=%d\n", f71862fg_pin);
return -EINVAL;
}
return 0;
}
static int watchdog_start(void)
{
int err = watchdog_keepalive();
if (err)
return err;
mutex_lock(&watchdog.lock);
err = superio_enter(watchdog.sioaddr);
if (err)
goto exit_unlock;
superio_select(watchdog.sioaddr, SIO_F71808FG_LD_WDT);
switch (watchdog.type) {
case f71808fg:
superio_clear_bit(watchdog.sioaddr, SIO_REG_MFUNCT2, 3);
superio_clear_bit(watchdog.sioaddr, SIO_REG_MFUNCT3, 3);
break;
case f71862fg:
err = f71862fg_pin_configure(watchdog.sioaddr);
if (err)
goto exit_superio;
break;
case f71869:
superio_clear_bit(watchdog.sioaddr, SIO_REG_MFUNCT1, 4);
break;
case f71882fg:
superio_set_bit(watchdog.sioaddr, SIO_REG_MFUNCT1, 1);
break;
case f71889fg:
superio_outb(watchdog.sioaddr, SIO_REG_MFUNCT3,
superio_inb(watchdog.sioaddr, SIO_REG_MFUNCT3) & 0xcf);
break;
case f81865:
superio_clear_bit(watchdog.sioaddr, SIO_REG_MFUNCT3, 5);
break;
default:
err = -ENODEV;
goto exit_superio;
}
superio_select(watchdog.sioaddr, SIO_F71808FG_LD_WDT);
superio_set_bit(watchdog.sioaddr, SIO_REG_ENABLE, 0);
if (watchdog.type == f81865)
superio_set_bit(watchdog.sioaddr, F81865_REG_WDO_CONF,
F81865_FLAG_WDOUT_EN);
else
superio_set_bit(watchdog.sioaddr, F71808FG_REG_WDO_CONF,
F71808FG_FLAG_WDOUT_EN);
superio_set_bit(watchdog.sioaddr, F71808FG_REG_WDT_CONF,
F71808FG_FLAG_WD_EN);
if (watchdog.pulse_mode) {
u8 wdt_conf = superio_inb(watchdog.sioaddr,
F71808FG_REG_WDT_CONF);
wdt_conf = (wdt_conf & 0xfc) | (watchdog.pulse_val & 0x03);
wdt_conf |= BIT(F71808FG_FLAG_WD_PULSE);
superio_outb(watchdog.sioaddr, F71808FG_REG_WDT_CONF,
wdt_conf);
} else {
superio_clear_bit(watchdog.sioaddr, F71808FG_REG_WDT_CONF,
F71808FG_FLAG_WD_PULSE);
}
exit_superio:
superio_exit(watchdog.sioaddr);
exit_unlock:
mutex_unlock(&watchdog.lock);
return err;
}
static int watchdog_stop(void)
{
int err = 0;
mutex_lock(&watchdog.lock);
err = superio_enter(watchdog.sioaddr);
if (err)
goto exit_unlock;
superio_select(watchdog.sioaddr, SIO_F71808FG_LD_WDT);
superio_clear_bit(watchdog.sioaddr, F71808FG_REG_WDT_CONF,
F71808FG_FLAG_WD_EN);
superio_exit(watchdog.sioaddr);
exit_unlock:
mutex_unlock(&watchdog.lock);
return err;
}
static int watchdog_get_status(void)
{
int status = 0;
mutex_lock(&watchdog.lock);
status = (watchdog.caused_reboot) ? WDIOF_CARDRESET : 0;
mutex_unlock(&watchdog.lock);
return status;
}
static bool watchdog_is_running(void)
{
bool is_running = true;
mutex_lock(&watchdog.lock);
if (superio_enter(watchdog.sioaddr))
goto exit_unlock;
superio_select(watchdog.sioaddr, SIO_F71808FG_LD_WDT);
is_running = (superio_inb(watchdog.sioaddr, SIO_REG_ENABLE) & BIT(0))
&& (superio_inb(watchdog.sioaddr, F71808FG_REG_WDT_CONF)
& F71808FG_FLAG_WD_EN);
superio_exit(watchdog.sioaddr);
exit_unlock:
mutex_unlock(&watchdog.lock);
return is_running;
}
static int watchdog_open(struct inode *inode, struct file *file)
{
int err;
if (test_and_set_bit(0, &watchdog.opened))
return -EBUSY;
err = watchdog_start();
if (err) {
clear_bit(0, &watchdog.opened);
return err;
}
if (nowayout)
__module_get(THIS_MODULE);
watchdog.expect_close = 0;
return nonseekable_open(inode, file);
}
static int watchdog_release(struct inode *inode, struct file *file)
{
clear_bit(0, &watchdog.opened);
if (!watchdog.expect_close) {
watchdog_keepalive();
pr_crit("Unexpected close, not stopping watchdog!\n");
} else if (!nowayout) {
watchdog_stop();
}
return 0;
}
static ssize_t watchdog_write(struct file *file, const char __user *buf,
size_t count, loff_t *ppos)
{
if (count) {
if (!nowayout) {
size_t i;
bool expect_close = false;
for (i = 0; i != count; i++) {
char c;
if (get_user(c, buf + i))
return -EFAULT;
expect_close = (c == 'V');
}
mutex_lock(&watchdog.lock);
watchdog.expect_close = expect_close;
mutex_unlock(&watchdog.lock);
}
watchdog_keepalive();
}
return count;
}
static long watchdog_ioctl(struct file *file, unsigned int cmd,
unsigned long arg)
{
int status;
int new_options;
int new_timeout;
union {
struct watchdog_info __user *ident;
int __user *i;
} uarg;
uarg.i = (int __user *)arg;
switch (cmd) {
case WDIOC_GETSUPPORT:
return copy_to_user(uarg.ident, &watchdog.ident,
sizeof(watchdog.ident)) ? -EFAULT : 0;
case WDIOC_GETSTATUS:
status = watchdog_get_status();
if (status < 0)
return status;
return put_user(status, uarg.i);
case WDIOC_GETBOOTSTATUS:
return put_user(0, uarg.i);
case WDIOC_SETOPTIONS:
if (get_user(new_options, uarg.i))
return -EFAULT;
if (new_options & WDIOS_DISABLECARD)
watchdog_stop();
if (new_options & WDIOS_ENABLECARD)
return watchdog_start();
case WDIOC_KEEPALIVE:
watchdog_keepalive();
return 0;
case WDIOC_SETTIMEOUT:
if (get_user(new_timeout, uarg.i))
return -EFAULT;
if (watchdog_set_timeout(new_timeout))
return -EINVAL;
watchdog_keepalive();
case WDIOC_GETTIMEOUT:
return put_user(watchdog.timeout, uarg.i);
default:
return -ENOTTY;
}
}
static int watchdog_notify_sys(struct notifier_block *this, unsigned long code,
void *unused)
{
if (code == SYS_DOWN || code == SYS_HALT)
watchdog_stop();
return NOTIFY_DONE;
}
static int __init watchdog_init(int sioaddr)
{
int wdt_conf, err = 0;
watchdog.sioaddr = sioaddr;
watchdog.ident.options = WDIOC_SETTIMEOUT
| WDIOF_MAGICCLOSE
| WDIOF_KEEPALIVEPING;
snprintf(watchdog.ident.identity,
sizeof(watchdog.ident.identity), "%s watchdog",
f71808e_names[watchdog.type]);
err = superio_enter(sioaddr);
if (err)
return err;
superio_select(watchdog.sioaddr, SIO_F71808FG_LD_WDT);
wdt_conf = superio_inb(sioaddr, F71808FG_REG_WDT_CONF);
watchdog.caused_reboot = wdt_conf & BIT(F71808FG_FLAG_WDTMOUT_STS);
superio_exit(sioaddr);
err = watchdog_set_timeout(timeout);
if (err)
return err;
err = watchdog_set_pulse_width(pulse_width);
if (err)
return err;
err = register_reboot_notifier(&watchdog_notifier);
if (err)
return err;
err = misc_register(&watchdog_miscdev);
if (err) {
pr_err("cannot register miscdev on minor=%d\n",
watchdog_miscdev.minor);
goto exit_reboot;
}
if (start_withtimeout) {
if (start_withtimeout <= 0
|| start_withtimeout > max_timeout) {
pr_err("starting timeout out of range\n");
err = -EINVAL;
goto exit_miscdev;
}
err = watchdog_start();
if (err) {
pr_err("cannot start watchdog timer\n");
goto exit_miscdev;
}
mutex_lock(&watchdog.lock);
err = superio_enter(sioaddr);
if (err)
goto exit_unlock;
superio_select(watchdog.sioaddr, SIO_F71808FG_LD_WDT);
if (start_withtimeout > 0xff) {
superio_set_bit(sioaddr, F71808FG_REG_WDT_CONF,
F71808FG_FLAG_WD_UNIT);
superio_outb(sioaddr, F71808FG_REG_WD_TIME,
DIV_ROUND_UP(start_withtimeout, 60));
} else {
superio_clear_bit(sioaddr, F71808FG_REG_WDT_CONF,
F71808FG_FLAG_WD_UNIT);
superio_outb(sioaddr, F71808FG_REG_WD_TIME,
start_withtimeout);
}
superio_exit(sioaddr);
mutex_unlock(&watchdog.lock);
if (nowayout)
__module_get(THIS_MODULE);
pr_info("watchdog started with initial timeout of %u sec\n",
start_withtimeout);
}
return 0;
exit_unlock:
mutex_unlock(&watchdog.lock);
exit_miscdev:
misc_deregister(&watchdog_miscdev);
exit_reboot:
unregister_reboot_notifier(&watchdog_notifier);
return err;
}
static int __init f71808e_find(int sioaddr)
{
u16 devid;
int err = superio_enter(sioaddr);
if (err)
return err;
devid = superio_inw(sioaddr, SIO_REG_MANID);
if (devid != SIO_FINTEK_ID) {
pr_debug("Not a Fintek device\n");
err = -ENODEV;
goto exit;
}
devid = force_id ? force_id : superio_inw(sioaddr, SIO_REG_DEVID);
switch (devid) {
case SIO_F71808_ID:
watchdog.type = f71808fg;
break;
case SIO_F71862_ID:
watchdog.type = f71862fg;
err = f71862fg_pin_configure(0);
break;
case SIO_F71869_ID:
case SIO_F71869A_ID:
watchdog.type = f71869;
break;
case SIO_F71882_ID:
watchdog.type = f71882fg;
break;
case SIO_F71889_ID:
watchdog.type = f71889fg;
break;
case SIO_F71858_ID:
err = -ENODEV;
goto exit;
case SIO_F81865_ID:
watchdog.type = f81865;
break;
default:
pr_info("Unrecognized Fintek device: %04x\n",
(unsigned int)devid);
err = -ENODEV;
goto exit;
}
pr_info("Found %s watchdog chip, revision %d\n",
f71808e_names[watchdog.type],
(int)superio_inb(sioaddr, SIO_REG_DEVREV));
exit:
superio_exit(sioaddr);
return err;
}
static int __init f71808e_init(void)
{
static const unsigned short addrs[] = { 0x2e, 0x4e };
int err = -ENODEV;
int i;
for (i = 0; i < ARRAY_SIZE(addrs); i++) {
err = f71808e_find(addrs[i]);
if (err == 0)
break;
}
if (i == ARRAY_SIZE(addrs))
return err;
return watchdog_init(addrs[i]);
}
static void __exit f71808e_exit(void)
{
if (watchdog_is_running()) {
pr_warn("Watchdog timer still running, stopping it\n");
watchdog_stop();
}
misc_deregister(&watchdog_miscdev);
unregister_reboot_notifier(&watchdog_notifier);
}
