static inline void w83697hf_unlock(void)
{
outb_p(0x87, W83697HF_EFER);
outb_p(0x87, W83697HF_EFER);
}
static inline void w83697hf_lock(void)
{
outb_p(0xAA, W83697HF_EFER);
}
static unsigned char w83697hf_get_reg(unsigned char reg)
{
outb_p(reg, W83697HF_EFIR);
return inb_p(W83697HF_EFDR);
}
static void w83697hf_set_reg(unsigned char reg, unsigned char data)
{
outb_p(reg, W83697HF_EFIR);
outb_p(data, W83697HF_EFDR);
}
static void w83697hf_write_timeout(int timeout)
{
w83697hf_set_reg(0xF4, timeout);
}
static void w83697hf_select_wdt(void)
{
w83697hf_unlock();
w83697hf_set_reg(0x07, 0x08);
}
static inline void w83697hf_deselect_wdt(void)
{
w83697hf_lock();
}
static void w83697hf_init(void)
{
unsigned char bbuf;
w83697hf_select_wdt();
bbuf = w83697hf_get_reg(0x29);
bbuf &= ~0x60;
bbuf |= 0x20;
w83697hf_set_reg(0x29, bbuf);
bbuf = w83697hf_get_reg(0xF3);
bbuf &= ~0x04;
w83697hf_set_reg(0xF3, bbuf);
w83697hf_deselect_wdt();
}
static void wdt_ping(void)
{
spin_lock(&io_lock);
w83697hf_select_wdt();
w83697hf_write_timeout(timeout);
w83697hf_deselect_wdt();
spin_unlock(&io_lock);
}
static void wdt_enable(void)
{
spin_lock(&io_lock);
w83697hf_select_wdt();
w83697hf_write_timeout(timeout);
w83697hf_set_reg(0x30, 1);
w83697hf_deselect_wdt();
spin_unlock(&io_lock);
}
static void wdt_disable(void)
{
spin_lock(&io_lock);
w83697hf_select_wdt();
w83697hf_set_reg(0x30, 0);
w83697hf_write_timeout(0);
w83697hf_deselect_wdt();
spin_unlock(&io_lock);
}
static unsigned char wdt_running(void)
{
unsigned char t;
spin_lock(&io_lock);
w83697hf_select_wdt();
t = w83697hf_get_reg(0xF4);
w83697hf_deselect_wdt();
spin_unlock(&io_lock);
return t;
}
static int wdt_set_heartbeat(int t)
{
if (t < 1 || t > 255)
return -EINVAL;
timeout = t;
return 0;
}
static ssize_t wdt_write(struct file *file, const char __user *buf,
size_t count, loff_t *ppos)
{
if (count) {
if (!nowayout) {
size_t i;
expect_close = 0;
for (i = 0; i != count; i++) {
char c;
if (get_user(c, buf + i))
return -EFAULT;
if (c == 'V')
expect_close = 42;
}
}
wdt_ping();
}
return count;
}
static long wdt_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
void __user *argp = (void __user *)arg;
int __user *p = argp;
int new_timeout;
static const struct watchdog_info ident = {
.options = WDIOF_KEEPALIVEPING | WDIOF_SETTIMEOUT
| WDIOF_MAGICCLOSE,
.firmware_version = 1,
.identity = "W83697HF WDT",
};
switch (cmd) {
case WDIOC_GETSUPPORT:
if (copy_to_user(argp, &ident, sizeof(ident)))
return -EFAULT;
break;
case WDIOC_GETSTATUS:
case WDIOC_GETBOOTSTATUS:
return put_user(0, p);
case WDIOC_SETOPTIONS:
{
int options, retval = -EINVAL;
if (get_user(options, p))
return -EFAULT;
if (options & WDIOS_DISABLECARD) {
wdt_disable();
retval = 0;
}
if (options & WDIOS_ENABLECARD) {
wdt_enable();
retval = 0;
}
return retval;
}
case WDIOC_KEEPALIVE:
wdt_ping();
break;
case WDIOC_SETTIMEOUT:
if (get_user(new_timeout, p))
return -EFAULT;
if (wdt_set_heartbeat(new_timeout))
return -EINVAL;
wdt_ping();
case WDIOC_GETTIMEOUT:
return put_user(timeout, p);
default:
return -ENOTTY;
}
return 0;
}
static int wdt_open(struct inode *inode, struct file *file)
{
if (test_and_set_bit(0, &wdt_is_open))
return -EBUSY;
wdt_enable();
return nonseekable_open(inode, file);
}
static int wdt_close(struct inode *inode, struct file *file)
{
if (expect_close == 42)
wdt_disable();
else {
pr_crit("Unexpected close, not stopping watchdog!\n");
wdt_ping();
}
expect_close = 0;
clear_bit(0, &wdt_is_open);
return 0;
}
static int wdt_notify_sys(struct notifier_block *this, unsigned long code,
void *unused)
{
if (code == SYS_DOWN || code == SYS_HALT)
wdt_disable();
return NOTIFY_DONE;
}
static int w83697hf_check_wdt(void)
{
if (!request_region(wdt_io, 2, WATCHDOG_NAME)) {
pr_err("I/O address 0x%x already in use\n", wdt_io);
return -EIO;
}
pr_debug("Looking for watchdog at address 0x%x\n", wdt_io);
w83697hf_unlock();
if (w83697hf_get_reg(0x20) == 0x60) {
pr_info("watchdog found at address 0x%x\n", wdt_io);
w83697hf_lock();
return 0;
}
w83697hf_lock();
pr_info("watchdog not found at address 0x%x\n", wdt_io);
release_region(wdt_io, 2);
return -EIO;
}
static int __init wdt_init(void)
{
int ret, i, found = 0;
pr_info("WDT driver for W83697HF/HG initializing\n");
if (wdt_io == 0) {
for (i = 0; ((!found) && (w83697hf_ioports[i] != 0)); i++) {
wdt_io = w83697hf_ioports[i];
if (!w83697hf_check_wdt())
found++;
}
} else {
if (!w83697hf_check_wdt())
found++;
}
if (!found) {
pr_err("No W83697HF/HG could be found\n");
ret = -EIO;
goto out;
}
w83697hf_init();
if (early_disable) {
if (wdt_running())
pr_warn("Stopping previously enabled watchdog until userland kicks in\n");
wdt_disable();
}
if (wdt_set_heartbeat(timeout)) {
wdt_set_heartbeat(WATCHDOG_TIMEOUT);
pr_info("timeout value must be 1 <= timeout <= 255, using %d\n",
WATCHDOG_TIMEOUT);
}
ret = register_reboot_notifier(&wdt_notifier);
if (ret != 0) {
pr_err("cannot register reboot notifier (err=%d)\n", ret);
goto unreg_regions;
}
ret = misc_register(&wdt_miscdev);
if (ret != 0) {
pr_err("cannot register miscdev on minor=%d (err=%d)\n",
WATCHDOG_MINOR, ret);
goto unreg_reboot;
}
pr_info("initialized. timeout=%d sec (nowayout=%d)\n",
timeout, nowayout);
out:
return ret;
unreg_reboot:
unregister_reboot_notifier(&wdt_notifier);
unreg_regions:
release_region(wdt_io, 2);
goto out;
}
static void __exit wdt_exit(void)
{
misc_deregister(&wdt_miscdev);
unregister_reboot_notifier(&wdt_notifier);
release_region(wdt_io, 2);
}
