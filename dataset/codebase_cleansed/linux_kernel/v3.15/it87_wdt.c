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
else if (test_bit(WDTS_USE_CIR, &wdt_status))
outb(0x55, CIR_DR(base));
else {
if (superio_enter())
return;
superio_select(GPIO);
wdt_update_timeout();
superio_exit();
}
set_bit(WDTS_KEEPALIVE, &wdt_status);
}
static int wdt_start(void)
{
int ret = superio_enter();
if (ret)
return ret;
superio_select(GPIO);
if (test_bit(WDTS_USE_GP, &wdt_status))
superio_outb(WDT_GAMEPORT, WDTCTRL);
else if (test_bit(WDTS_USE_CIR, &wdt_status))
superio_outb(WDT_CIRINT, WDTCTRL);
wdt_update_timeout();
superio_exit();
return 0;
}
static int wdt_stop(void)
{
int ret = superio_enter();
if (ret)
return ret;
superio_select(GPIO);
superio_outb(0x00, WDTCTRL);
superio_outb(WDT_TOV1, WDTCFG);
superio_outb(0x00, WDTVALLSB);
if (max_units > 255)
superio_outb(0x00, WDTVALMSB);
superio_exit();
return 0;
}
static int wdt_set_timeout(int t)
{
if (t < 1 || t > max_units * 60)
return -EINVAL;
if (t > max_units)
timeout = wdt_round_time(t);
else
timeout = t;
if (test_bit(WDTS_TIMER_RUN, &wdt_status)) {
int ret = superio_enter();
if (ret)
return ret;
superio_select(GPIO);
wdt_update_timeout();
superio_exit();
}
return 0;
}
static int wdt_get_status(int *status)
{
*status = 0;
if (testmode) {
int ret = superio_enter();
if (ret)
return ret;
superio_select(GPIO);
if (superio_inb(WDTCTRL) & WDT_ZERO) {
superio_outb(0x00, WDTCTRL);
clear_bit(WDTS_TIMER_RUN, &wdt_status);
*status |= WDIOF_CARDRESET;
}
superio_exit();
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
int ret;
if (nowayout && !test_and_set_bit(WDTS_LOCKED, &wdt_status))
__module_get(THIS_MODULE);
ret = wdt_start();
if (ret) {
clear_bit(WDTS_LOCKED, &wdt_status);
clear_bit(WDTS_TIMER_RUN, &wdt_status);
clear_bit(WDTS_DEV_OPEN, &wdt_status);
return ret;
}
}
return nonseekable_open(inode, file);
}
static int wdt_release(struct inode *inode, struct file *file)
{
if (test_bit(WDTS_TIMER_RUN, &wdt_status)) {
if (test_and_clear_bit(WDTS_EXPECTED, &wdt_status)) {
int ret = wdt_stop();
if (ret) {
set_bit(WDTS_EXPECTED, &wdt_status);
wdt_keepalive();
return ret;
}
clear_bit(WDTS_TIMER_RUN, &wdt_status);
} else {
wdt_keepalive();
pr_crit("unexpected close, not stopping watchdog!\n");
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
rc = wdt_get_status(&status);
if (rc)
return rc;
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
if (test_bit(WDTS_TIMER_RUN, &wdt_status)) {
rc = wdt_stop();
if (rc)
return rc;
}
clear_bit(WDTS_TIMER_RUN, &wdt_status);
return 0;
case WDIOS_ENABLECARD:
if (!test_and_set_bit(WDTS_TIMER_RUN, &wdt_status)) {
rc = wdt_start();
if (rc) {
clear_bit(WDTS_TIMER_RUN, &wdt_status);
return rc;
}
}
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
int gp_rreq_fail = 0;
wdt_status = 0;
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
case IT8718_ID:
case IT8720_ID:
case IT8721_ID:
case IT8728_ID:
max_units = 65535;
try_gameport = 0;
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
if (try_gameport) {
superio_select(GAMEPORT);
base = superio_inw(BASEREG);
if (!base) {
base = GP_BASE_DEFAULT;
superio_outw(base, BASEREG);
}
gpact = superio_inb(ACTREG);
superio_outb(0x01, ACTREG);
if (request_region(base, 1, WATCHDOG_NAME))
set_bit(WDTS_USE_GP, &wdt_status);
else
gp_rreq_fail = 1;
}
if (!nocir && !test_bit(WDTS_USE_GP, &wdt_status)) {
if (!request_region(CIR_BASE, 8, WATCHDOG_NAME)) {
if (gp_rreq_fail)
pr_err("I/O Address 0x%04x and 0x%04x already in use\n",
base, CIR_BASE);
else
pr_err("I/O Address 0x%04x already in use\n",
CIR_BASE);
rc = -EIO;
goto err_out;
}
base = CIR_BASE;
superio_select(CIR);
superio_outw(base, BASEREG);
superio_outb(0x00, CIR_ILS);
ciract = superio_inb(ACTREG);
superio_outb(0x01, ACTREG);
if (gp_rreq_fail) {
superio_select(GAMEPORT);
superio_outb(gpact, ACTREG);
}
set_bit(WDTS_USE_CIR, &wdt_status);
}
if (timeout < 1 || timeout > max_units * 60) {
timeout = DEFAULT_TIMEOUT;
pr_warn("Timeout value out of range, use default %d sec\n",
DEFAULT_TIMEOUT);
}
if (timeout > max_units)
timeout = wdt_round_time(timeout);
rc = register_reboot_notifier(&wdt_notifier);
if (rc) {
pr_err("Cannot register reboot notifier (err=%d)\n", rc);
goto err_out_region;
}
rc = misc_register(&wdt_miscdev);
if (rc) {
pr_err("Cannot register miscdev on minor=%d (err=%d)\n",
wdt_miscdev.minor, rc);
goto err_out_reboot;
}
if (test_bit(WDTS_USE_CIR, &wdt_status)) {
outb(0x00, CIR_RCR(base));
outb(0xc0, CIR_TCR1(base));
outb(0x5c, CIR_TCR2(base));
outb(0x10, CIR_IER(base));
outb(0x00, CIR_BDHR(base));
outb(0x01, CIR_BDLR(base));
outb(0x09, CIR_IER(base));
}
pr_info("Chip IT%04x revision %d initialized. timeout=%d sec (nowayout=%d testmode=%d exclusive=%d nogameport=%d nocir=%d)\n",
chip_type, chip_rev, timeout,
nowayout, testmode, exclusive, nogameport, nocir);
superio_exit();
return 0;
err_out_reboot:
unregister_reboot_notifier(&wdt_notifier);
err_out_region:
if (test_bit(WDTS_USE_GP, &wdt_status))
release_region(base, 1);
else if (test_bit(WDTS_USE_CIR, &wdt_status)) {
release_region(base, 8);
superio_select(CIR);
superio_outb(ciract, ACTREG);
}
err_out:
if (try_gameport) {
superio_select(GAMEPORT);
superio_outb(gpact, ACTREG);
}
superio_exit();
return rc;
}
static void __exit it87_wdt_exit(void)
{
if (superio_enter() == 0) {
superio_select(GPIO);
superio_outb(0x00, WDTCTRL);
superio_outb(0x00, WDTCFG);
superio_outb(0x00, WDTVALLSB);
if (max_units > 255)
superio_outb(0x00, WDTVALMSB);
if (test_bit(WDTS_USE_GP, &wdt_status)) {
superio_select(GAMEPORT);
superio_outb(gpact, ACTREG);
} else if (test_bit(WDTS_USE_CIR, &wdt_status)) {
superio_select(CIR);
superio_outb(ciract, ACTREG);
}
superio_exit();
}
misc_deregister(&wdt_miscdev);
unregister_reboot_notifier(&wdt_notifier);
if (test_bit(WDTS_USE_GP, &wdt_status))
release_region(base, 1);
else if (test_bit(WDTS_USE_CIR, &wdt_status))
release_region(base, 8);
}
