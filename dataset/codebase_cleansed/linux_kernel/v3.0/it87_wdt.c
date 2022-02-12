static inline void superio_enter(void)
{
outb(0x87, REG);
outb(0x01, REG);
outb(0x55, REG);
outb(0x55, REG);
}
static inline void superio_exit(void)
{
outb(0x02, REG);
outb(0x02, VAL);
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
static void wdt_update_timeout(void)
{
unsigned char cfg = WDT_KRST;
int tm = timeout;
if (testmode)
cfg = 0;
if (tm <= max_units)
cfg |= WDT_TOV1;
else
tm /= 60;
if (chip_type != IT8721_ID)
cfg |= WDT_PWROK;
superio_outb(cfg, WDTCFG);
superio_outb(tm, WDTVALLSB);
if (max_units > 255)
superio_outb(tm>>8, WDTVALMSB);
}
static int wdt_round_time(int t)
{
t += 59;
t -= t % 60;
return t;
}
static void wdt_keepalive(void)
{
if (test_bit(WDTS_USE_GP, &wdt_status))
inb(base);
else
outb(0x55, CIR_DR(base));
set_bit(WDTS_KEEPALIVE, &wdt_status);
}
static void wdt_start(void)
{
unsigned long flags;
spin_lock_irqsave(&spinlock, flags);
superio_enter();
superio_select(GPIO);
if (test_bit(WDTS_USE_GP, &wdt_status))
superio_outb(WDT_GAMEPORT, WDTCTRL);
else
superio_outb(WDT_CIRINT, WDTCTRL);
wdt_update_timeout();
superio_exit();
spin_unlock_irqrestore(&spinlock, flags);
}
static void wdt_stop(void)
{
unsigned long flags;
spin_lock_irqsave(&spinlock, flags);
superio_enter();
superio_select(GPIO);
superio_outb(0x00, WDTCTRL);
superio_outb(WDT_TOV1, WDTCFG);
superio_outb(0x00, WDTVALLSB);
if (max_units > 255)
superio_outb(0x00, WDTVALMSB);
superio_exit();
spin_unlock_irqrestore(&spinlock, flags);
}
static int wdt_set_timeout(int t)
{
unsigned long flags;
if (t < 1 || t > max_units * 60)
return -EINVAL;
if (t > max_units)
timeout = wdt_round_time(t);
else
timeout = t;
spin_lock_irqsave(&spinlock, flags);
if (test_bit(WDTS_TIMER_RUN, &wdt_status)) {
superio_enter();
superio_select(GPIO);
wdt_update_timeout();
superio_exit();
}
spin_unlock_irqrestore(&spinlock, flags);
return 0;
}
static int wdt_get_status(int *status)
{
unsigned long flags;
*status = 0;
if (testmode) {
spin_lock_irqsave(&spinlock, flags);
superio_enter();
superio_select(GPIO);
if (superio_inb(WDTCTRL) & WDT_ZERO) {
superio_outb(0x00, WDTCTRL);
clear_bit(WDTS_TIMER_RUN, &wdt_status);
*status |= WDIOF_CARDRESET;
}
superio_exit();
spin_unlock_irqrestore(&spinlock, flags);
}
if (test_and_clear_bit(WDTS_KEEPALIVE, &wdt_status))
*status |= WDIOF_KEEPALIVEPING;
if (test_bit(WDTS_EXPECTED, &wdt_status))
*status |= WDIOF_MAGICCLOSE;
return 0;
}
static int wdt_open(struct inode *inode, struct file *file)
{
if (exclusive && test_and_set_bit(WDTS_DEV_OPEN, &wdt_status))
return -EBUSY;
if (!test_and_set_bit(WDTS_TIMER_RUN, &wdt_status)) {
if (nowayout && !test_and_set_bit(WDTS_LOCKED, &wdt_status))
__module_get(THIS_MODULE);
wdt_start();
}
return nonseekable_open(inode, file);
}
static int wdt_release(struct inode *inode, struct file *file)
{
if (test_bit(WDTS_TIMER_RUN, &wdt_status)) {
if (test_and_clear_bit(WDTS_EXPECTED, &wdt_status)) {
wdt_stop();
clear_bit(WDTS_TIMER_RUN, &wdt_status);
} else {
wdt_keepalive();
printk(KERN_CRIT PFX
"unexpected close, not stopping watchdog!\n");
}
}
clear_bit(WDTS_DEV_OPEN, &wdt_status);
return 0;
}
static ssize_t wdt_write(struct file *file, const char __user *buf,
size_t count, loff_t *ppos)
{
if (count) {
clear_bit(WDTS_EXPECTED, &wdt_status);
wdt_keepalive();
}
if (!nowayout) {
size_t ofs;
for (ofs = 0; ofs != count; ofs++) {
char c;
if (get_user(c, buf + ofs))
return -EFAULT;
if (c == WD_MAGIC)
set_bit(WDTS_EXPECTED, &wdt_status);
}
}
return count;
}
static long wdt_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
int rc = 0, status, new_options, new_timeout;
union {
struct watchdog_info __user *ident;
int __user *i;
} uarg;
uarg.i = (int __user *)arg;
switch (cmd) {
case WDIOC_GETSUPPORT:
return copy_to_user(uarg.ident,
&ident, sizeof(ident)) ? -EFAULT : 0;
case WDIOC_GETSTATUS:
wdt_get_status(&status);
return put_user(status, uarg.i);
case WDIOC_GETBOOTSTATUS:
return put_user(0, uarg.i);
case WDIOC_KEEPALIVE:
wdt_keepalive();
return 0;
case WDIOC_SETOPTIONS:
if (get_user(new_options, uarg.i))
return -EFAULT;
switch (new_options) {
case WDIOS_DISABLECARD:
if (test_bit(WDTS_TIMER_RUN, &wdt_status))
wdt_stop();
clear_bit(WDTS_TIMER_RUN, &wdt_status);
return 0;
case WDIOS_ENABLECARD:
if (!test_and_set_bit(WDTS_TIMER_RUN, &wdt_status))
wdt_start();
return 0;
default:
return -EFAULT;
}
case WDIOC_SETTIMEOUT:
if (get_user(new_timeout, uarg.i))
return -EFAULT;
rc = wdt_set_timeout(new_timeout);
case WDIOC_GETTIMEOUT:
if (put_user(timeout, uarg.i))
return -EFAULT;
return rc;
default:
return -ENOTTY;
}
}
static int wdt_notify_sys(struct notifier_block *this, unsigned long code,
void *unused)
{
if (code == SYS_DOWN || code == SYS_HALT)
wdt_stop();
return NOTIFY_DONE;
}
static int __init it87_wdt_init(void)
{
int rc = 0;
int try_gameport = !nogameport;
u8 chip_rev;
unsigned long flags;
wdt_status = 0;
spin_lock_irqsave(&spinlock, flags);
superio_enter();
chip_type = superio_inw(CHIPID);
chip_rev = superio_inb(CHIPREV) & 0x0f;
superio_exit();
spin_unlock_irqrestore(&spinlock, flags);
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
case IT8718_ID:
case IT8720_ID:
case IT8721_ID:
max_units = 65535;
try_gameport = 0;
break;
case IT8705_ID:
printk(KERN_ERR PFX
"Unsupported Chip found, Chip %04x Revision %02x\n",
chip_type, chip_rev);
return -ENODEV;
case NO_DEV_ID:
printk(KERN_ERR PFX "no device\n");
return -ENODEV;
default:
printk(KERN_ERR PFX
"Unknown Chip found, Chip %04x Revision %04x\n",
chip_type, chip_rev);
return -ENODEV;
}
spin_lock_irqsave(&spinlock, flags);
superio_enter();
superio_select(GPIO);
superio_outb(WDT_TOV1, WDTCFG);
superio_outb(0x00, WDTCTRL);
if (try_gameport) {
superio_select(GAMEPORT);
base = superio_inw(BASEREG);
if (!base) {
base = GP_BASE_DEFAULT;
superio_outw(base, BASEREG);
}
gpact = superio_inb(ACTREG);
superio_outb(0x01, ACTREG);
superio_exit();
spin_unlock_irqrestore(&spinlock, flags);
if (request_region(base, 1, WATCHDOG_NAME))
set_bit(WDTS_USE_GP, &wdt_status);
else
rc = -EIO;
} else {
superio_exit();
spin_unlock_irqrestore(&spinlock, flags);
}
if (!test_bit(WDTS_USE_GP, &wdt_status)) {
if (!request_region(CIR_BASE, 8, WATCHDOG_NAME)) {
if (rc == -EIO)
printk(KERN_ERR PFX
"I/O Address 0x%04x and 0x%04x"
" already in use\n", base, CIR_BASE);
else
printk(KERN_ERR PFX
"I/O Address 0x%04x already in use\n",
CIR_BASE);
rc = -EIO;
goto err_out;
}
base = CIR_BASE;
spin_lock_irqsave(&spinlock, flags);
superio_enter();
superio_select(CIR);
superio_outw(base, BASEREG);
superio_outb(0x00, CIR_ILS);
ciract = superio_inb(ACTREG);
superio_outb(0x01, ACTREG);
if (rc == -EIO) {
superio_select(GAMEPORT);
superio_outb(gpact, ACTREG);
}
superio_exit();
spin_unlock_irqrestore(&spinlock, flags);
}
if (timeout < 1 || timeout > max_units * 60) {
timeout = DEFAULT_TIMEOUT;
printk(KERN_WARNING PFX
"Timeout value out of range, use default %d sec\n",
DEFAULT_TIMEOUT);
}
if (timeout > max_units)
timeout = wdt_round_time(timeout);
rc = register_reboot_notifier(&wdt_notifier);
if (rc) {
printk(KERN_ERR PFX
"Cannot register reboot notifier (err=%d)\n", rc);
goto err_out_region;
}
rc = misc_register(&wdt_miscdev);
if (rc) {
printk(KERN_ERR PFX
"Cannot register miscdev on minor=%d (err=%d)\n",
wdt_miscdev.minor, rc);
goto err_out_reboot;
}
if (!test_bit(WDTS_USE_GP, &wdt_status)) {
outb(0x00, CIR_RCR(base));
outb(0xc0, CIR_TCR1(base));
outb(0x5c, CIR_TCR2(base));
outb(0x10, CIR_IER(base));
outb(0x00, CIR_BDHR(base));
outb(0x01, CIR_BDLR(base));
outb(0x09, CIR_IER(base));
}
printk(KERN_INFO PFX "Chip IT%04x revision %d initialized. "
"timeout=%d sec (nowayout=%d testmode=%d exclusive=%d "
"nogameport=%d)\n", chip_type, chip_rev, timeout,
nowayout, testmode, exclusive, nogameport);
return 0;
err_out_reboot:
unregister_reboot_notifier(&wdt_notifier);
err_out_region:
release_region(base, test_bit(WDTS_USE_GP, &wdt_status) ? 1 : 8);
if (!test_bit(WDTS_USE_GP, &wdt_status)) {
spin_lock_irqsave(&spinlock, flags);
superio_enter();
superio_select(CIR);
superio_outb(ciract, ACTREG);
superio_exit();
spin_unlock_irqrestore(&spinlock, flags);
}
err_out:
if (try_gameport) {
spin_lock_irqsave(&spinlock, flags);
superio_enter();
superio_select(GAMEPORT);
superio_outb(gpact, ACTREG);
superio_exit();
spin_unlock_irqrestore(&spinlock, flags);
}
return rc;
}
static void __exit it87_wdt_exit(void)
{
unsigned long flags;
int nolock;
nolock = !spin_trylock_irqsave(&spinlock, flags);
superio_enter();
superio_select(GPIO);
superio_outb(0x00, WDTCTRL);
superio_outb(0x00, WDTCFG);
superio_outb(0x00, WDTVALLSB);
if (max_units > 255)
superio_outb(0x00, WDTVALMSB);
if (test_bit(WDTS_USE_GP, &wdt_status)) {
superio_select(GAMEPORT);
superio_outb(gpact, ACTREG);
} else {
superio_select(CIR);
superio_outb(ciract, ACTREG);
}
superio_exit();
if (!nolock)
spin_unlock_irqrestore(&spinlock, flags);
misc_deregister(&wdt_miscdev);
unregister_reboot_notifier(&wdt_notifier);
release_region(base, test_bit(WDTS_USE_GP, &wdt_status) ? 1 : 8);
}
