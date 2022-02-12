static unsigned short zf_readw(unsigned char port)
{
outb(port, INDEX);
return inw(DATA_W);
}
static inline void zf_set_status(unsigned char new)
{
zf_writeb(STATUS, new);
}
static inline unsigned short zf_get_control(void)
{
return zf_readw(CONTROL);
}
static inline void zf_set_control(unsigned short new)
{
zf_writew(CONTROL, new);
}
static inline void zf_set_timer(unsigned short new, unsigned char n)
{
switch (n) {
case WD1:
zf_writew(COUNTER_1, new);
case WD2:
zf_writeb(COUNTER_2, new > 0xff ? 0xff : new);
default:
return;
}
}
static void zf_timer_off(void)
{
unsigned int ctrl_reg = 0;
unsigned long flags;
del_timer_sync(&zf_timer);
spin_lock_irqsave(&zf_port_lock, flags);
ctrl_reg = zf_get_control();
ctrl_reg |= (ENABLE_WD1|ENABLE_WD2);
ctrl_reg &= ~(ENABLE_WD1|ENABLE_WD2);
zf_set_control(ctrl_reg);
spin_unlock_irqrestore(&zf_port_lock, flags);
printk(KERN_INFO PFX ": Watchdog timer is now disabled\n");
}
static void zf_timer_on(void)
{
unsigned int ctrl_reg = 0;
unsigned long flags;
spin_lock_irqsave(&zf_port_lock, flags);
zf_writeb(PULSE_LEN, 0xff);
zf_set_timer(ZF_CTIMEOUT, WD1);
next_heartbeat = jiffies + ZF_USER_TIMEO;
mod_timer(&zf_timer, jiffies + ZF_HW_TIMEO);
ctrl_reg = zf_get_control();
ctrl_reg |= (ENABLE_WD1|zf_action);
zf_set_control(ctrl_reg);
spin_unlock_irqrestore(&zf_port_lock, flags);
printk(KERN_INFO PFX ": Watchdog timer is now enabled\n");
}
static void zf_ping(unsigned long data)
{
unsigned int ctrl_reg = 0;
unsigned long flags;
zf_writeb(COUNTER_2, 0xff);
if (time_before(jiffies, next_heartbeat)) {
dprintk("time_before: %ld\n", next_heartbeat - jiffies);
spin_lock_irqsave(&zf_port_lock, flags);
ctrl_reg = zf_get_control();
ctrl_reg |= RESET_WD1;
zf_set_control(ctrl_reg);
ctrl_reg &= ~(RESET_WD1);
zf_set_control(ctrl_reg);
spin_unlock_irqrestore(&zf_port_lock, flags);
mod_timer(&zf_timer, jiffies + ZF_HW_TIMEO);
} else
printk(KERN_CRIT PFX ": I will reset your machine\n");
}
static ssize_t zf_write(struct file *file, const char __user *buf, size_t count,
loff_t *ppos)
{
if (count) {
if (!nowayout) {
size_t ofs;
zf_expect_close = 0;
for (ofs = 0; ofs != count; ofs++) {
char c;
if (get_user(c, buf + ofs))
return -EFAULT;
if (c == 'V') {
zf_expect_close = 42;
dprintk("zf_expect_close = 42\n");
}
}
}
next_heartbeat = jiffies + ZF_USER_TIMEO;
dprintk("user ping at %ld\n", jiffies);
}
return count;
}
static long zf_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
void __user *argp = (void __user *)arg;
int __user *p = argp;
switch (cmd) {
case WDIOC_GETSUPPORT:
if (copy_to_user(argp, &zf_info, sizeof(zf_info)))
return -EFAULT;
break;
case WDIOC_GETSTATUS:
case WDIOC_GETBOOTSTATUS:
return put_user(0, p);
case WDIOC_KEEPALIVE:
zf_ping(0);
break;
default:
return -ENOTTY;
}
return 0;
}
static int zf_open(struct inode *inode, struct file *file)
{
if (test_and_set_bit(0, &zf_is_open))
return -EBUSY;
if (nowayout)
__module_get(THIS_MODULE);
zf_timer_on();
return nonseekable_open(inode, file);
}
static int zf_close(struct inode *inode, struct file *file)
{
if (zf_expect_close == 42)
zf_timer_off();
else {
del_timer(&zf_timer);
printk(KERN_ERR PFX ": device file closed unexpectedly. "
"Will not stop the WDT!\n");
}
clear_bit(0, &zf_is_open);
zf_expect_close = 0;
return 0;
}
static int zf_notify_sys(struct notifier_block *this, unsigned long code,
void *unused)
{
if (code == SYS_DOWN || code == SYS_HALT)
zf_timer_off();
return NOTIFY_DONE;
}
static void __init zf_show_action(int act)
{
static const char * const str[] = { "RESET", "SMI", "NMI", "SCI" };
printk(KERN_INFO PFX ": Watchdog using action = %s\n", str[act]);
}
static int __init zf_init(void)
{
int ret;
printk(KERN_INFO PFX
": MachZ ZF-Logic Watchdog driver initializing.\n");
ret = zf_get_ZFL_version();
if (!ret || ret == 0xffff) {
printk(KERN_WARNING PFX ": no ZF-Logic found\n");
return -ENODEV;
}
if (action <= 3 && action >= 0)
zf_action = zf_action >> action;
else
action = 0;
zf_show_action(action);
if (!request_region(ZF_IOBASE, 3, "MachZ ZFL WDT")) {
printk(KERN_ERR "cannot reserve I/O ports at %d\n",
ZF_IOBASE);
ret = -EBUSY;
goto no_region;
}
ret = register_reboot_notifier(&zf_notifier);
if (ret) {
printk(KERN_ERR "can't register reboot notifier (err=%d)\n",
ret);
goto no_reboot;
}
ret = misc_register(&zf_miscdev);
if (ret) {
printk(KERN_ERR "can't misc_register on minor=%d\n",
WATCHDOG_MINOR);
goto no_misc;
}
zf_set_status(0);
zf_set_control(0);
return 0;
no_misc:
unregister_reboot_notifier(&zf_notifier);
no_reboot:
release_region(ZF_IOBASE, 3);
no_region:
return ret;
}
static void __exit zf_exit(void)
{
zf_timer_off();
misc_deregister(&zf_miscdev);
unregister_reboot_notifier(&zf_notifier);
release_region(ZF_IOBASE, 3);
}
