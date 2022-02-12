static inline void eurwdt_write_reg(u8 index, u8 data)
{
outb(index, io);
outb(data, io+1);
}
static inline void eurwdt_lock_chip(void)
{
outb(0xaa, io);
}
static inline void eurwdt_unlock_chip(void)
{
outb(0x55, io);
eurwdt_write_reg(0x07, 0x08);
}
static inline void eurwdt_set_timeout(int timeout)
{
eurwdt_write_reg(WDT_TIMEOUT_VAL, (u8) timeout);
}
static inline void eurwdt_disable_timer(void)
{
eurwdt_set_timeout(0);
}
static void eurwdt_activate_timer(void)
{
eurwdt_disable_timer();
eurwdt_write_reg(WDT_CTRL_REG, 0x01);
eurwdt_write_reg(WDT_OUTPIN_CFG,
!strcmp("int", ev) ? WDT_EVENT_INT : WDT_EVENT_REBOOT);
if (irq == 2 || irq > 15 || irq < 0) {
printk(KERN_ERR ": invalid irq number\n");
irq = 0;
}
if (irq == 0)
printk(KERN_INFO ": interrupt disabled\n");
eurwdt_write_reg(WDT_TIMER_CFG, irq << 4);
eurwdt_write_reg(WDT_UNIT_SEL, WDT_UNIT_SECS);
eurwdt_set_timeout(0);
}
static irqreturn_t eurwdt_interrupt(int irq, void *dev_id)
{
printk(KERN_CRIT "timeout WDT timeout\n");
#ifdef ONLY_TESTING
printk(KERN_CRIT "Would Reboot.\n");
#else
printk(KERN_CRIT "Initiating system reboot.\n");
emergency_restart();
#endif
return IRQ_HANDLED;
}
static void eurwdt_ping(void)
{
eurwdt_set_timeout(eurwdt_timeout);
}
static ssize_t eurwdt_write(struct file *file, const char __user *buf,
size_t count, loff_t *ppos)
{
if (count) {
if (!nowayout) {
size_t i;
eur_expect_close = 0;
for (i = 0; i != count; i++) {
char c;
if (get_user(c, buf + i))
return -EFAULT;
if (c == 'V')
eur_expect_close = 42;
}
}
spin_lock(&eurwdt_lock);
eurwdt_ping();
spin_unlock(&eurwdt_lock);
}
return count;
}
static long eurwdt_ioctl(struct file *file,
unsigned int cmd, unsigned long arg)
{
void __user *argp = (void __user *)arg;
int __user *p = argp;
static const struct watchdog_info ident = {
.options = WDIOF_KEEPALIVEPING | WDIOF_SETTIMEOUT
| WDIOF_MAGICCLOSE,
.firmware_version = 1,
.identity = "WDT Eurotech CPU-1220/1410",
};
int time;
int options, retval = -EINVAL;
switch (cmd) {
case WDIOC_GETSUPPORT:
return copy_to_user(argp, &ident, sizeof(ident)) ? -EFAULT : 0;
case WDIOC_GETSTATUS:
case WDIOC_GETBOOTSTATUS:
return put_user(0, p);
case WDIOC_SETOPTIONS:
if (get_user(options, p))
return -EFAULT;
spin_lock(&eurwdt_lock);
if (options & WDIOS_DISABLECARD) {
eurwdt_disable_timer();
retval = 0;
}
if (options & WDIOS_ENABLECARD) {
eurwdt_activate_timer();
eurwdt_ping();
retval = 0;
}
spin_unlock(&eurwdt_lock);
return retval;
case WDIOC_KEEPALIVE:
spin_lock(&eurwdt_lock);
eurwdt_ping();
spin_unlock(&eurwdt_lock);
return 0;
case WDIOC_SETTIMEOUT:
if (copy_from_user(&time, p, sizeof(int)))
return -EFAULT;
if (time < 0 || time > 255)
return -EINVAL;
spin_lock(&eurwdt_lock);
eurwdt_timeout = time;
eurwdt_set_timeout(time);
spin_unlock(&eurwdt_lock);
case WDIOC_GETTIMEOUT:
return put_user(eurwdt_timeout, p);
default:
return -ENOTTY;
}
}
static int eurwdt_open(struct inode *inode, struct file *file)
{
if (test_and_set_bit(0, &eurwdt_is_open))
return -EBUSY;
eurwdt_timeout = WDT_TIMEOUT;
eurwdt_activate_timer();
return nonseekable_open(inode, file);
}
static int eurwdt_release(struct inode *inode, struct file *file)
{
if (eur_expect_close == 42)
eurwdt_disable_timer();
else {
printk(KERN_CRIT
"eurwdt: Unexpected close, not stopping watchdog!\n");
eurwdt_ping();
}
clear_bit(0, &eurwdt_is_open);
eur_expect_close = 0;
return 0;
}
static int eurwdt_notify_sys(struct notifier_block *this, unsigned long code,
void *unused)
{
if (code == SYS_DOWN || code == SYS_HALT)
eurwdt_disable_timer();
return NOTIFY_DONE;
}
static void __exit eurwdt_exit(void)
{
eurwdt_lock_chip();
misc_deregister(&eurwdt_miscdev);
unregister_reboot_notifier(&eurwdt_notifier);
release_region(io, 2);
free_irq(irq, NULL);
}
static int __init eurwdt_init(void)
{
int ret;
ret = request_irq(irq, eurwdt_interrupt, 0, "eurwdt", NULL);
if (ret) {
printk(KERN_ERR "eurwdt: IRQ %d is not free.\n", irq);
goto out;
}
if (!request_region(io, 2, "eurwdt")) {
printk(KERN_ERR "eurwdt: IO %X is not free.\n", io);
ret = -EBUSY;
goto outirq;
}
ret = register_reboot_notifier(&eurwdt_notifier);
if (ret) {
printk(KERN_ERR
"eurwdt: can't register reboot notifier (err=%d)\n", ret);
goto outreg;
}
ret = misc_register(&eurwdt_miscdev);
if (ret) {
printk(KERN_ERR "eurwdt: can't misc_register on minor=%d\n",
WATCHDOG_MINOR);
goto outreboot;
}
eurwdt_unlock_chip();
ret = 0;
printk(KERN_INFO "Eurotech WDT driver 0.01 at %X (Interrupt %d)"
" - timeout event: %s\n",
io, irq, (!strcmp("int", ev) ? "int" : "reboot"));
out:
return ret;
outreboot:
unregister_reboot_notifier(&eurwdt_notifier);
outreg:
release_region(io, 2);
outirq:
free_irq(irq, NULL);
goto out;
}
