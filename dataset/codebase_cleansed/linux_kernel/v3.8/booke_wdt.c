static unsigned long long period_to_sec(unsigned int period)
{
unsigned long long tmp = 1ULL << (64 - period);
unsigned long tmp2 = ppc_tb_freq;
tmp2 = tmp2 / 5 * 2;
do_div(tmp, tmp2);
return tmp;
}
static unsigned int sec_to_period(unsigned int secs)
{
unsigned int period;
for (period = 63; period > 0; period--) {
if (period_to_sec(period) >= secs)
return period;
}
return 0;
}
static void __booke_wdt_set(void *data)
{
u32 val;
val = mfspr(SPRN_TCR);
val &= ~WDTP_MASK;
val |= WDTP(booke_wdt_period);
mtspr(SPRN_TCR, val);
}
static void booke_wdt_set(void)
{
on_each_cpu(__booke_wdt_set, NULL, 0);
}
static void __booke_wdt_ping(void *data)
{
mtspr(SPRN_TSR, TSR_ENW|TSR_WIS);
}
static void booke_wdt_ping(void)
{
on_each_cpu(__booke_wdt_ping, NULL, 0);
}
static void __booke_wdt_enable(void *data)
{
u32 val;
__booke_wdt_ping(NULL);
val = mfspr(SPRN_TCR);
val &= ~WDTP_MASK;
val |= (TCR_WIE|TCR_WRC(WRC_CHIP)|WDTP(booke_wdt_period));
mtspr(SPRN_TCR, val);
}
static void __booke_wdt_disable(void *data)
{
u32 val;
val = mfspr(SPRN_TCR);
val &= ~(TCR_WIE | WDTP_MASK);
mtspr(SPRN_TCR, val);
__booke_wdt_ping(NULL);
}
static ssize_t booke_wdt_write(struct file *file, const char __user *buf,
size_t count, loff_t *ppos)
{
booke_wdt_ping();
return count;
}
static long booke_wdt_ioctl(struct file *file,
unsigned int cmd, unsigned long arg)
{
u32 tmp = 0;
u32 __user *p = (u32 __user *)arg;
switch (cmd) {
case WDIOC_GETSUPPORT:
return copy_to_user(p, &ident, sizeof(ident)) ? -EFAULT : 0;
case WDIOC_GETSTATUS:
return put_user(0, p);
case WDIOC_GETBOOTSTATUS:
tmp = mfspr(SPRN_TSR) & TSR_WRS(3);
return put_user((tmp ? WDIOF_CARDRESET : 0), p);
case WDIOC_SETOPTIONS:
if (get_user(tmp, p))
return -EFAULT;
if (tmp == WDIOS_ENABLECARD) {
booke_wdt_ping();
break;
} else
return -EINVAL;
return 0;
case WDIOC_KEEPALIVE:
booke_wdt_ping();
return 0;
case WDIOC_SETTIMEOUT:
if (get_user(tmp, p))
return -EFAULT;
#ifdef CONFIG_PPC_FSL_BOOK3E
if (tmp > period_to_sec(1))
return -EINVAL;
booke_wdt_period = sec_to_period(tmp);
#else
booke_wdt_period = tmp;
#endif
booke_wdt_set();
case WDIOC_GETTIMEOUT:
#ifdef CONFIG_FSL_BOOKE
return put_user(period_to_sec(booke_wdt_period), p);
#else
return put_user(booke_wdt_period, p);
#endif
default:
return -ENOTTY;
}
return 0;
}
static int booke_wdt_open(struct inode *inode, struct file *file)
{
if (test_and_set_bit(0, &wdt_is_active))
return -EBUSY;
spin_lock(&booke_wdt_lock);
if (booke_wdt_enabled == 0) {
booke_wdt_enabled = 1;
on_each_cpu(__booke_wdt_enable, NULL, 0);
pr_debug("watchdog enabled (timeout = %llu sec)\n",
period_to_sec(booke_wdt_period));
}
spin_unlock(&booke_wdt_lock);
return nonseekable_open(inode, file);
}
static int booke_wdt_release(struct inode *inode, struct file *file)
{
#ifndef CONFIG_WATCHDOG_NOWAYOUT
on_each_cpu(__booke_wdt_disable, NULL, 0);
booke_wdt_enabled = 0;
pr_debug("watchdog disabled\n");
#endif
clear_bit(0, &wdt_is_active);
return 0;
}
static void __exit booke_wdt_exit(void)
{
misc_deregister(&booke_wdt_miscdev);
}
static int __init booke_wdt_init(void)
{
int ret = 0;
pr_info("powerpc book-e watchdog driver loaded\n");
ident.firmware_version = cur_cpu_spec->pvr_value;
ret = misc_register(&booke_wdt_miscdev);
if (ret) {
pr_err("cannot register device (minor=%u, ret=%i)\n",
WATCHDOG_MINOR, ret);
return ret;
}
spin_lock(&booke_wdt_lock);
if (booke_wdt_enabled == 1) {
pr_info("watchdog enabled (timeout = %llu sec)\n",
period_to_sec(booke_wdt_period));
on_each_cpu(__booke_wdt_enable, NULL, 0);
}
spin_unlock(&booke_wdt_lock);
return ret;
}
