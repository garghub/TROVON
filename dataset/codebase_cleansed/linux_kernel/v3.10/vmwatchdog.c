static int __diag288(enum vmwdt_func func, unsigned int timeout,
char *cmd, size_t len)
{
register unsigned long __func asm("2") = func;
register unsigned long __timeout asm("3") = timeout;
register unsigned long __cmdp asm("4") = virt_to_phys(cmd);
register unsigned long __cmdl asm("5") = len;
int err;
err = -EINVAL;
asm volatile(
" diag %1,%3,0x288\n"
"0: la %0,0\n"
"1:\n"
EX_TABLE(0b,1b)
: "+d" (err) : "d"(__func), "d"(__timeout),
"d"(__cmdp), "d"(__cmdl) : "1", "cc");
return err;
}
static int vmwdt_keepalive(void)
{
static char *ebc_cmd;
size_t len;
int ret;
unsigned int func;
ebc_cmd = kmalloc(MAX_CMDLEN, GFP_KERNEL);
if (!ebc_cmd)
return -ENOMEM;
len = strlcpy(ebc_cmd, vmwdt_cmd, MAX_CMDLEN);
ASCEBC(ebc_cmd, MAX_CMDLEN);
EBC_TOUPPER(ebc_cmd, MAX_CMDLEN);
func = vmwdt_conceal ? (wdt_init | wdt_conceal) : wdt_init;
set_bit(VMWDT_RUNNING, &vmwdt_is_open);
ret = __diag288(func, vmwdt_interval, ebc_cmd, len);
WARN_ON(ret != 0);
kfree(ebc_cmd);
return ret;
}
static int vmwdt_disable(void)
{
int ret = __diag288(wdt_cancel, 0, "", 0);
WARN_ON(ret != 0);
clear_bit(VMWDT_RUNNING, &vmwdt_is_open);
return ret;
}
static int __init vmwdt_probe(void)
{
static char __initdata ebc_begin[] = {
194, 197, 199, 201, 213
};
if (__diag288(wdt_init, 15, ebc_begin, sizeof(ebc_begin)) != 0)
return -EINVAL;
return vmwdt_disable();
}
static int vmwdt_open(struct inode *i, struct file *f)
{
int ret;
if (test_and_set_bit(VMWDT_OPEN, &vmwdt_is_open))
return -EBUSY;
ret = vmwdt_keepalive();
if (ret)
clear_bit(VMWDT_OPEN, &vmwdt_is_open);
return ret ? ret : nonseekable_open(i, f);
}
static int vmwdt_close(struct inode *i, struct file *f)
{
if (vmwdt_expect_close == 42)
vmwdt_disable();
vmwdt_expect_close = 0;
clear_bit(VMWDT_OPEN, &vmwdt_is_open);
return 0;
}
static int __vmwdt_ioctl(unsigned int cmd, unsigned long arg)
{
switch (cmd) {
case WDIOC_GETSUPPORT:
if (copy_to_user((void __user *)arg, &vmwdt_info,
sizeof(vmwdt_info)))
return -EFAULT;
return 0;
case WDIOC_GETSTATUS:
case WDIOC_GETBOOTSTATUS:
return put_user(0, (int __user *)arg);
case WDIOC_GETTEMP:
return -EINVAL;
case WDIOC_SETOPTIONS:
{
int options, ret;
if (get_user(options, (int __user *)arg))
return -EFAULT;
ret = -EINVAL;
if (options & WDIOS_DISABLECARD) {
ret = vmwdt_disable();
if (ret)
return ret;
}
if (options & WDIOS_ENABLECARD) {
ret = vmwdt_keepalive();
}
return ret;
}
case WDIOC_GETTIMEOUT:
return put_user(vmwdt_interval, (int __user *)arg);
case WDIOC_SETTIMEOUT:
{
int interval;
if (get_user(interval, (int __user *)arg))
return -EFAULT;
if (interval < MIN_INTERVAL)
return -EINVAL;
vmwdt_interval = interval;
}
return vmwdt_keepalive();
case WDIOC_KEEPALIVE:
return vmwdt_keepalive();
}
return -EINVAL;
}
static long vmwdt_ioctl(struct file *f, unsigned int cmd, unsigned long arg)
{
int rc;
mutex_lock(&vmwdt_mutex);
rc = __vmwdt_ioctl(cmd, arg);
mutex_unlock(&vmwdt_mutex);
return (long) rc;
}
static ssize_t vmwdt_write(struct file *f, const char __user *buf,
size_t count, loff_t *ppos)
{
if(count) {
if (!vmwdt_nowayout) {
size_t i;
vmwdt_expect_close = 0;
for (i = 0; i != count; i++) {
char c;
if (get_user(c, buf+i))
return -EFAULT;
if (c == 'V')
vmwdt_expect_close = 42;
}
}
vmwdt_keepalive();
}
return count;
}
static int vmwdt_resume(void)
{
clear_bit(VMWDT_OPEN, &vmwdt_is_open);
return NOTIFY_DONE;
}
static int vmwdt_suspend(void)
{
if (test_and_set_bit(VMWDT_OPEN, &vmwdt_is_open)) {
pr_err("The system cannot be suspended while the watchdog"
" is in use\n");
return notifier_from_errno(-EBUSY);
}
if (test_bit(VMWDT_RUNNING, &vmwdt_is_open)) {
clear_bit(VMWDT_OPEN, &vmwdt_is_open);
pr_err("The system cannot be suspended while the watchdog"
" is running\n");
return notifier_from_errno(-EBUSY);
}
return NOTIFY_DONE;
}
static int vmwdt_power_event(struct notifier_block *this, unsigned long event,
void *ptr)
{
switch (event) {
case PM_POST_HIBERNATION:
case PM_POST_SUSPEND:
return vmwdt_resume();
case PM_HIBERNATION_PREPARE:
case PM_SUSPEND_PREPARE:
return vmwdt_suspend();
default:
return NOTIFY_DONE;
}
}
static int __init vmwdt_init(void)
{
int ret;
ret = vmwdt_probe();
if (ret)
return ret;
ret = register_pm_notifier(&vmwdt_power_notifier);
if (ret)
return ret;
ret = misc_register(&vmwdt_dev);
if (ret) {
unregister_pm_notifier(&vmwdt_power_notifier);
return ret;
}
return 0;
}
static void __exit vmwdt_exit(void)
{
unregister_pm_notifier(&vmwdt_power_notifier);
misc_deregister(&vmwdt_dev);
}
