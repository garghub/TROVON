void sbwdog_set(char __iomem *wdog, unsigned long t)
{
spin_lock(&sbwd_lock);
__raw_writeb(0, wdog);
__raw_writeq(t & 0x7fffffUL, wdog - 0x10);
spin_unlock(&sbwd_lock);
}
void sbwdog_pet(char __iomem *wdog)
{
spin_lock(&sbwd_lock);
__raw_writeb(__raw_readb(wdog) | 1, wdog);
spin_unlock(&sbwd_lock);
}
static int sbwdog_open(struct inode *inode, struct file *file)
{
nonseekable_open(inode, file);
if (test_and_set_bit(0, &sbwdog_gate))
return -EBUSY;
__module_get(THIS_MODULE);
sbwdog_set(user_dog, timeout);
__raw_writeb(1, user_dog);
return 0;
}
static int sbwdog_release(struct inode *inode, struct file *file)
{
if (expect_close == 42) {
__raw_writeb(0, user_dog);
module_put(THIS_MODULE);
} else {
printk(KERN_CRIT
"%s: Unexpected close, not stopping watchdog!\n",
ident.identity);
sbwdog_pet(user_dog);
}
clear_bit(0, &sbwdog_gate);
expect_close = 0;
return 0;
}
static ssize_t sbwdog_write(struct file *file, const char __user *data,
size_t len, loff_t *ppos)
{
int i;
if (len) {
expect_close = 0;
for (i = 0; i != len; i++) {
char c;
if (get_user(c, data + i))
return -EFAULT;
if (c == 'V')
expect_close = 42;
}
sbwdog_pet(user_dog);
}
return len;
}
static long sbwdog_ioctl(struct file *file, unsigned int cmd,
unsigned long arg)
{
int ret = -ENOTTY;
unsigned long time;
void __user *argp = (void __user *)arg;
int __user *p = argp;
switch (cmd) {
case WDIOC_GETSUPPORT:
ret = copy_to_user(argp, &ident, sizeof(ident)) ? -EFAULT : 0;
break;
case WDIOC_GETSTATUS:
case WDIOC_GETBOOTSTATUS:
ret = put_user(0, p);
break;
case WDIOC_KEEPALIVE:
sbwdog_pet(user_dog);
ret = 0;
break;
case WDIOC_SETTIMEOUT:
ret = get_user(time, p);
if (ret)
break;
time *= 1000000;
if (time > 0x7fffffUL) {
ret = -EINVAL;
break;
}
timeout = time;
sbwdog_set(user_dog, timeout);
sbwdog_pet(user_dog);
case WDIOC_GETTIMEOUT:
ret = put_user(__raw_readq(user_dog - 8) / 1000000, p);
break;
}
return ret;
}
static int sbwdog_notify_sys(struct notifier_block *this, unsigned long code,
void *erf)
{
if (code == SYS_DOWN || code == SYS_HALT) {
__raw_writeb(0, user_dog);
__raw_writeb(0, kern_dog);
}
return NOTIFY_DONE;
}
irqreturn_t sbwdog_interrupt(int irq, void *addr)
{
unsigned long wd_init;
char *wd_cfg_reg = (char *)addr;
u8 cfg;
cfg = __raw_readb(wd_cfg_reg);
wd_init = __raw_readq(wd_cfg_reg - 8) & 0x7fffff;
if (wd_cfg_reg == user_dog)
printk(KERN_CRIT "%s in danger of initiating system reset "
"in %ld.%01ld seconds\n",
ident.identity,
wd_init / 1000000, (wd_init / 100000) % 10);
else
cfg |= 1;
__raw_writeb(cfg, wd_cfg_reg);
return IRQ_HANDLED;
}
static int __init sbwdog_init(void)
{
int ret;
ret = register_reboot_notifier(&sbwdog_notifier);
if (ret) {
printk(KERN_ERR
"%s: cannot register reboot notifier (err=%d)\n",
ident.identity, ret);
return ret;
}
ret = request_irq(1, sbwdog_interrupt, IRQF_SHARED,
ident.identity, (void *)user_dog);
if (ret) {
printk(KERN_ERR "%s: failed to request irq 1 - %d\n",
ident.identity, ret);
goto out;
}
ret = misc_register(&sbwdog_miscdev);
if (ret == 0) {
printk(KERN_INFO "%s: timeout is %ld.%ld secs\n",
ident.identity,
timeout / 1000000, (timeout / 100000) % 10);
return 0;
}
free_irq(1, (void *)user_dog);
out:
unregister_reboot_notifier(&sbwdog_notifier);
return ret;
}
static void __exit sbwdog_exit(void)
{
misc_deregister(&sbwdog_miscdev);
free_irq(1, (void *)user_dog);
unregister_reboot_notifier(&sbwdog_notifier);
}
