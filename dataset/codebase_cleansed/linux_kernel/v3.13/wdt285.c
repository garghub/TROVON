static void watchdog_fire(int irq, void *dev_id)
{
pr_crit("Would Reboot\n");
*CSR_TIMER4_CNTL = 0;
*CSR_TIMER4_CLR = 0;
}
static void watchdog_ping(void)
{
*CSR_TIMER4_LOAD = reload;
}
static int watchdog_open(struct inode *inode, struct file *file)
{
int ret;
if (*CSR_SA110_CNTL & (1 << 13))
return -EBUSY;
if (test_and_set_bit(1, &timer_alive))
return -EBUSY;
reload = soft_margin * (mem_fclk_21285 / 256);
*CSR_TIMER4_CLR = 0;
watchdog_ping();
*CSR_TIMER4_CNTL = TIMER_CNTL_ENABLE | TIMER_CNTL_AUTORELOAD
| TIMER_CNTL_DIV256;
#ifdef ONLY_TESTING
ret = request_irq(IRQ_TIMER4, watchdog_fire, 0, "watchdog", NULL);
if (ret) {
*CSR_TIMER4_CNTL = 0;
clear_bit(1, &timer_alive);
}
#else
*CSR_SA110_CNTL |= 1 << 13;
ret = 0;
#endif
nonseekable_open(inode, file);
return ret;
}
static int watchdog_release(struct inode *inode, struct file *file)
{
#ifdef ONLY_TESTING
free_irq(IRQ_TIMER4, NULL);
clear_bit(1, &timer_alive);
#endif
return 0;
}
static ssize_t watchdog_write(struct file *file, const char __user *data,
size_t len, loff_t *ppos)
{
if (len)
watchdog_ping();
return len;
}
static long watchdog_ioctl(struct file *file, unsigned int cmd,
unsigned long arg)
{
unsigned int new_margin;
int __user *int_arg = (int __user *)arg;
int ret = -ENOTTY;
switch (cmd) {
case WDIOC_GETSUPPORT:
ret = 0;
if (copy_to_user((void __user *)arg, &ident, sizeof(ident)))
ret = -EFAULT;
break;
case WDIOC_GETSTATUS:
case WDIOC_GETBOOTSTATUS:
ret = put_user(0, int_arg);
break;
case WDIOC_KEEPALIVE:
watchdog_ping();
ret = 0;
break;
case WDIOC_SETTIMEOUT:
ret = get_user(new_margin, int_arg);
if (ret)
break;
if (new_margin < 0 || new_margin > 60) {
ret = -EINVAL;
break;
}
soft_margin = new_margin;
reload = soft_margin * (mem_fclk_21285 / 256);
watchdog_ping();
case WDIOC_GETTIMEOUT:
ret = put_user(soft_margin, int_arg);
break;
}
return ret;
}
static int __init footbridge_watchdog_init(void)
{
int retval;
if (machine_is_netwinder())
return -ENODEV;
retval = misc_register(&watchdog_miscdev);
if (retval < 0)
return retval;
pr_info("Footbridge Watchdog Timer: 0.01, timer margin: %d sec\n",
soft_margin);
if (machine_is_cats())
pr_warn("Warning: Watchdog reset may not work on this machine\n");
return 0;
}
static void __exit footbridge_watchdog_exit(void)
{
misc_deregister(&watchdog_miscdev);
}
