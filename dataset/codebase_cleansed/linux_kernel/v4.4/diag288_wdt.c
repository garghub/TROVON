static int __diag288(unsigned int func, unsigned int timeout,
unsigned long action, unsigned int len)
{
register unsigned long __func asm("2") = func;
register unsigned long __timeout asm("3") = timeout;
register unsigned long __action asm("4") = action;
register unsigned long __len asm("5") = len;
int err;
err = -EINVAL;
asm volatile(
" diag %1, %3, 0x288\n"
"0: la %0, 0\n"
"1:\n"
EX_TABLE(0b, 1b)
: "+d" (err) : "d"(__func), "d"(__timeout),
"d"(__action), "d"(__len) : "1", "cc");
return err;
}
static int __diag288_vm(unsigned int func, unsigned int timeout,
char *cmd, size_t len)
{
diag_stat_inc(DIAG_STAT_X288);
return __diag288(func, timeout, virt_to_phys(cmd), len);
}
static int __diag288_lpar(unsigned int func, unsigned int timeout,
unsigned long action)
{
diag_stat_inc(DIAG_STAT_X288);
return __diag288(func, timeout, action, 0);
}
static int wdt_start(struct watchdog_device *dev)
{
char *ebc_cmd;
size_t len;
int ret;
unsigned int func;
ret = -ENODEV;
if (MACHINE_IS_VM) {
ebc_cmd = kmalloc(MAX_CMDLEN, GFP_KERNEL);
if (!ebc_cmd)
return -ENOMEM;
len = strlcpy(ebc_cmd, wdt_cmd, MAX_CMDLEN);
ASCEBC(ebc_cmd, MAX_CMDLEN);
EBC_TOUPPER(ebc_cmd, MAX_CMDLEN);
func = conceal_on ? (WDT_FUNC_INIT | WDT_FUNC_CONCEAL)
: WDT_FUNC_INIT;
ret = __diag288_vm(func, dev->timeout, ebc_cmd, len);
WARN_ON(ret != 0);
kfree(ebc_cmd);
} else {
ret = __diag288_lpar(WDT_FUNC_INIT,
dev->timeout, LPARWDT_RESTART);
}
if (ret) {
pr_err("The watchdog cannot be activated\n");
return ret;
}
return 0;
}
static int wdt_stop(struct watchdog_device *dev)
{
int ret;
diag_stat_inc(DIAG_STAT_X288);
ret = __diag288(WDT_FUNC_CANCEL, 0, 0, 0);
return ret;
}
static int wdt_ping(struct watchdog_device *dev)
{
char *ebc_cmd;
size_t len;
int ret;
unsigned int func;
ret = -ENODEV;
if (MACHINE_IS_VM) {
ebc_cmd = kmalloc(MAX_CMDLEN, GFP_KERNEL);
if (!ebc_cmd)
return -ENOMEM;
len = strlcpy(ebc_cmd, wdt_cmd, MAX_CMDLEN);
ASCEBC(ebc_cmd, MAX_CMDLEN);
EBC_TOUPPER(ebc_cmd, MAX_CMDLEN);
func = conceal_on ? (WDT_FUNC_INIT | WDT_FUNC_CONCEAL)
: WDT_FUNC_INIT;
ret = __diag288_vm(func, dev->timeout, ebc_cmd, len);
WARN_ON(ret != 0);
kfree(ebc_cmd);
} else {
ret = __diag288_lpar(WDT_FUNC_CHANGE, dev->timeout, 0);
}
if (ret)
pr_err("The watchdog timer cannot be started or reset\n");
return ret;
}
static int wdt_set_timeout(struct watchdog_device * dev, unsigned int new_to)
{
dev->timeout = new_to;
return wdt_ping(dev);
}
static int wdt_suspend(void)
{
if (test_and_set_bit(WDOG_DEV_OPEN, &wdt_dev.status)) {
pr_err("Linux cannot be suspended while the watchdog is in use\n");
return notifier_from_errno(-EBUSY);
}
if (test_bit(WDOG_ACTIVE, &wdt_dev.status)) {
clear_bit(WDOG_DEV_OPEN, &wdt_dev.status);
pr_err("Linux cannot be suspended while the watchdog is in use\n");
return notifier_from_errno(-EBUSY);
}
return NOTIFY_DONE;
}
static int wdt_resume(void)
{
clear_bit(WDOG_DEV_OPEN, &wdt_dev.status);
return NOTIFY_DONE;
}
static int wdt_power_event(struct notifier_block *this, unsigned long event,
void *ptr)
{
switch (event) {
case PM_POST_HIBERNATION:
case PM_POST_SUSPEND:
return wdt_resume();
case PM_HIBERNATION_PREPARE:
case PM_SUSPEND_PREPARE:
return wdt_suspend();
default:
return NOTIFY_DONE;
}
}
static int __init diag288_init(void)
{
int ret;
char ebc_begin[] = {
194, 197, 199, 201, 213
};
watchdog_set_nowayout(&wdt_dev, nowayout_info);
if (MACHINE_IS_VM) {
if (__diag288_vm(WDT_FUNC_INIT, 15,
ebc_begin, sizeof(ebc_begin)) != 0) {
pr_err("The watchdog cannot be initialized\n");
return -EINVAL;
}
} else {
if (__diag288_lpar(WDT_FUNC_INIT, 30, LPARWDT_RESTART)) {
pr_err("The watchdog cannot be initialized\n");
return -EINVAL;
}
}
if (__diag288_lpar(WDT_FUNC_CANCEL, 0, 0)) {
pr_err("The watchdog cannot be deactivated\n");
return -EINVAL;
}
ret = register_pm_notifier(&wdt_power_notifier);
if (ret)
return ret;
ret = watchdog_register_device(&wdt_dev);
if (ret)
unregister_pm_notifier(&wdt_power_notifier);
return ret;
}
static void __exit diag288_exit(void)
{
watchdog_unregister_device(&wdt_dev);
unregister_pm_notifier(&wdt_power_notifier);
}
