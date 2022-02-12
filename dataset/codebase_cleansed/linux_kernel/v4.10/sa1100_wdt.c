static int sa1100dog_open(struct inode *inode, struct file *file)
{
if (test_and_set_bit(1, &sa1100wdt_users))
return -EBUSY;
writel_relaxed(readl_relaxed(OSCR) + pre_margin, OSMR3);
writel_relaxed(OSSR_M3, OSSR);
writel_relaxed(OWER_WME, OWER);
writel_relaxed(readl_relaxed(OIER) | OIER_E3, OIER);
return nonseekable_open(inode, file);
}
static int sa1100dog_release(struct inode *inode, struct file *file)
{
pr_crit("Device closed - timer will not stop\n");
clear_bit(1, &sa1100wdt_users);
return 0;
}
static ssize_t sa1100dog_write(struct file *file, const char __user *data,
size_t len, loff_t *ppos)
{
if (len)
writel_relaxed(readl_relaxed(OSCR) + pre_margin, OSMR3);
return len;
}
static long sa1100dog_ioctl(struct file *file, unsigned int cmd,
unsigned long arg)
{
int ret = -ENOTTY;
int time;
void __user *argp = (void __user *)arg;
int __user *p = argp;
switch (cmd) {
case WDIOC_GETSUPPORT:
ret = copy_to_user(argp, &ident,
sizeof(ident)) ? -EFAULT : 0;
break;
case WDIOC_GETSTATUS:
ret = put_user(0, p);
break;
case WDIOC_GETBOOTSTATUS:
ret = put_user(boot_status, p);
break;
case WDIOC_KEEPALIVE:
writel_relaxed(readl_relaxed(OSCR) + pre_margin, OSMR3);
ret = 0;
break;
case WDIOC_SETTIMEOUT:
ret = get_user(time, p);
if (ret)
break;
if (time <= 0 || (oscr_freq * (long long)time >= 0xffffffff)) {
ret = -EINVAL;
break;
}
pre_margin = oscr_freq * time;
writel_relaxed(readl_relaxed(OSCR) + pre_margin, OSMR3);
case WDIOC_GETTIMEOUT:
ret = put_user(pre_margin / oscr_freq, p);
break;
}
return ret;
}
static int __init sa1100dog_init(void)
{
int ret;
clk = clk_get(NULL, "OSTIMER0");
if (IS_ERR(clk)) {
pr_err("SA1100/PXA2xx Watchdog Timer: clock not found: %d\n",
(int) PTR_ERR(clk));
return PTR_ERR(clk);
}
ret = clk_prepare_enable(clk);
if (ret) {
pr_err("SA1100/PXA2xx Watchdog Timer: clock failed to prepare+enable: %d\n",
ret);
goto err;
}
oscr_freq = clk_get_rate(clk);
boot_status = (reset_status & RESET_STATUS_WATCHDOG) ?
WDIOF_CARDRESET : 0;
pre_margin = oscr_freq * margin;
ret = misc_register(&sa1100dog_miscdev);
if (ret == 0)
pr_info("SA1100/PXA2xx Watchdog Timer: timer margin %d sec\n",
margin);
return ret;
err:
clk_disable_unprepare(clk);
clk_put(clk);
return ret;
}
static void __exit sa1100dog_exit(void)
{
misc_deregister(&sa1100dog_miscdev);
clk_disable_unprepare(clk);
clk_put(clk);
}
