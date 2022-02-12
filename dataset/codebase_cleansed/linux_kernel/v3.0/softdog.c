static void watchdog_fire(unsigned long data)
{
if (test_and_clear_bit(0, &orphan_timer))
module_put(THIS_MODULE);
if (soft_noboot)
printk(KERN_CRIT PFX "Triggered - Reboot ignored.\n");
else if (soft_panic) {
printk(KERN_CRIT PFX "Initiating panic.\n");
panic("Software Watchdog Timer expired.");
} else {
printk(KERN_CRIT PFX "Initiating system reboot.\n");
emergency_restart();
printk(KERN_CRIT PFX "Reboot didn't ?????\n");
}
}
static int softdog_keepalive(void)
{
mod_timer(&watchdog_ticktock, jiffies+(soft_margin*HZ));
return 0;
}
static int softdog_stop(void)
{
del_timer(&watchdog_ticktock);
return 0;
}
static int softdog_set_heartbeat(int t)
{
if ((t < 0x0001) || (t > 0xFFFF))
return -EINVAL;
soft_margin = t;
return 0;
}
static int softdog_open(struct inode *inode, struct file *file)
{
if (test_and_set_bit(0, &driver_open))
return -EBUSY;
if (!test_and_clear_bit(0, &orphan_timer))
__module_get(THIS_MODULE);
softdog_keepalive();
return nonseekable_open(inode, file);
}
static int softdog_release(struct inode *inode, struct file *file)
{
if (expect_close == 42) {
softdog_stop();
module_put(THIS_MODULE);
} else {
printk(KERN_CRIT PFX
"Unexpected close, not stopping watchdog!\n");
set_bit(0, &orphan_timer);
softdog_keepalive();
}
clear_bit(0, &driver_open);
expect_close = 0;
return 0;
}
static ssize_t softdog_write(struct file *file, const char __user *data,
size_t len, loff_t *ppos)
{
if (len) {
if (!nowayout) {
size_t i;
expect_close = 0;
for (i = 0; i != len; i++) {
char c;
if (get_user(c, data + i))
return -EFAULT;
if (c == 'V')
expect_close = 42;
}
}
softdog_keepalive();
}
return len;
}
static long softdog_ioctl(struct file *file, unsigned int cmd,
unsigned long arg)
{
void __user *argp = (void __user *)arg;
int __user *p = argp;
int new_margin;
static const struct watchdog_info ident = {
.options = WDIOF_SETTIMEOUT |
WDIOF_KEEPALIVEPING |
WDIOF_MAGICCLOSE,
.firmware_version = 0,
.identity = "Software Watchdog",
};
switch (cmd) {
case WDIOC_GETSUPPORT:
return copy_to_user(argp, &ident, sizeof(ident)) ? -EFAULT : 0;
case WDIOC_GETSTATUS:
case WDIOC_GETBOOTSTATUS:
return put_user(0, p);
case WDIOC_KEEPALIVE:
softdog_keepalive();
return 0;
case WDIOC_SETTIMEOUT:
if (get_user(new_margin, p))
return -EFAULT;
if (softdog_set_heartbeat(new_margin))
return -EINVAL;
softdog_keepalive();
case WDIOC_GETTIMEOUT:
return put_user(soft_margin, p);
default:
return -ENOTTY;
}
}
static int softdog_notify_sys(struct notifier_block *this, unsigned long code,
void *unused)
{
if (code == SYS_DOWN || code == SYS_HALT)
softdog_stop();
return NOTIFY_DONE;
}
static int __init watchdog_init(void)
{
int ret;
if (softdog_set_heartbeat(soft_margin)) {
softdog_set_heartbeat(TIMER_MARGIN);
printk(KERN_INFO PFX
"soft_margin must be 0 < soft_margin < 65536, using %d\n",
TIMER_MARGIN);
}
ret = register_reboot_notifier(&softdog_notifier);
if (ret) {
printk(KERN_ERR PFX
"cannot register reboot notifier (err=%d)\n", ret);
return ret;
}
ret = misc_register(&softdog_miscdev);
if (ret) {
printk(KERN_ERR PFX
"cannot register miscdev on minor=%d (err=%d)\n",
WATCHDOG_MINOR, ret);
unregister_reboot_notifier(&softdog_notifier);
return ret;
}
printk(banner, soft_noboot, soft_margin, soft_panic, nowayout);
return 0;
}
static void __exit watchdog_exit(void)
{
misc_deregister(&softdog_miscdev);
unregister_reboot_notifier(&softdog_notifier);
}
