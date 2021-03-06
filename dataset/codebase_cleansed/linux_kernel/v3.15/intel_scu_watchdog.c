static void watchdog_fire(void)
{
if (force_boot) {
pr_crit("Initiating system reboot\n");
emergency_restart();
pr_crit("Reboot didn't ?????\n");
}
else {
pr_crit("Immediate Reboot Disabled\n");
pr_crit("System will reset when watchdog timer times out!\n");
}
}
static int check_timer_margin(int new_margin)
{
if ((new_margin < MIN_TIME_CYCLE) ||
(new_margin > MAX_TIME - timer_set)) {
pr_debug("value of new_margin %d is out of the range %d to %d\n",
new_margin, MIN_TIME_CYCLE, MAX_TIME - timer_set);
return -EINVAL;
}
return 0;
}
static int watchdog_set_ipc(int soft_threshold, int threshold)
{
u32 *ipc_wbuf;
u8 cbuf[16] = { '\0' };
int ipc_ret = 0;
ipc_wbuf = (u32 *)&cbuf;
ipc_wbuf[0] = soft_threshold;
ipc_wbuf[1] = threshold;
ipc_ret = intel_scu_ipc_command(
IPC_SET_WATCHDOG_TIMER,
0,
ipc_wbuf,
2,
NULL,
0);
if (ipc_ret != 0)
pr_err("Error setting SCU watchdog timer: %x\n", ipc_ret);
return ipc_ret;
}
static irqreturn_t watchdog_timer_interrupt(int irq, void *dev_id)
{
int int_status;
int_status = ioread32(watchdog_device.timer_interrupt_status_addr);
pr_debug("irq, int_status: %x\n", int_status);
if (int_status != 0)
return IRQ_NONE;
if (watchdog_device.timer_started == 0) {
pr_debug("spurious interrupt received\n");
return IRQ_HANDLED;
}
iowrite32(0x00000002, watchdog_device.timer_control_addr);
iowrite32(watchdog_device.threshold,
watchdog_device.timer_load_count_addr);
iowrite32(0x00000003, watchdog_device.timer_control_addr);
return IRQ_HANDLED;
}
static int intel_scu_keepalive(void)
{
ioread32(watchdog_device.timer_clear_interrupt_addr);
iowrite32(0x00000002, watchdog_device.timer_control_addr);
iowrite32(watchdog_device.soft_threshold,
watchdog_device.timer_load_count_addr);
iowrite32(0x00000003, watchdog_device.timer_control_addr);
return 0;
}
static int intel_scu_stop(void)
{
iowrite32(0, watchdog_device.timer_control_addr);
return 0;
}
static int intel_scu_set_heartbeat(u32 t)
{
int ipc_ret;
int retry_count;
u32 soft_value;
u32 hw_value;
watchdog_device.timer_set = t;
watchdog_device.threshold =
timer_margin * watchdog_device.timer_tbl_ptr->freq_hz;
watchdog_device.soft_threshold =
(watchdog_device.timer_set - timer_margin)
* watchdog_device.timer_tbl_ptr->freq_hz;
pr_debug("set_heartbeat: timer freq is %d\n",
watchdog_device.timer_tbl_ptr->freq_hz);
pr_debug("set_heartbeat: timer_set is %x (hex)\n",
watchdog_device.timer_set);
pr_debug("set_hearbeat: timer_margin is %x (hex)\n", timer_margin);
pr_debug("set_heartbeat: threshold is %x (hex)\n",
watchdog_device.threshold);
pr_debug("set_heartbeat: soft_threshold is %x (hex)\n",
watchdog_device.soft_threshold);
watchdog_device.threshold =
watchdog_device.threshold / FREQ_ADJUSTMENT;
watchdog_device.soft_threshold =
watchdog_device.soft_threshold / FREQ_ADJUSTMENT;
iowrite32(0x00000002, watchdog_device.timer_control_addr);
ipc_ret = watchdog_set_ipc(watchdog_device.soft_threshold,
watchdog_device.threshold);
if (ipc_ret != 0) {
intel_scu_stop();
return ipc_ret;
}
retry_count = 0;
soft_value = watchdog_device.soft_threshold & 0xFFFF0000;
do {
intel_scu_stop();
if (MAX_RETRY < retry_count++) {
pr_err("Unable to set timer\n");
return -ENODEV;
}
iowrite32(watchdog_device.soft_threshold,
watchdog_device.timer_load_count_addr);
ioread32(watchdog_device.timer_load_count_addr);
iowrite32(0x00000003, watchdog_device.timer_control_addr);
hw_value = ioread32(watchdog_device.timer_load_count_addr);
hw_value = hw_value & 0xFFFF0000;
} while (soft_value != hw_value);
watchdog_device.timer_started = 1;
return 0;
}
static int intel_scu_open(struct inode *inode, struct file *file)
{
if (test_and_set_bit(0, &watchdog_device.driver_open))
return -EBUSY;
if (watchdog_device.driver_closed)
return -EPERM;
return nonseekable_open(inode, file);
}
static int intel_scu_release(struct inode *inode, struct file *file)
{
if (!test_and_clear_bit(0, &watchdog_device.driver_open)) {
pr_debug("intel_scu_release, without open\n");
return -ENOTTY;
}
if (!watchdog_device.timer_started) {
pr_debug("closed, without starting timer\n");
return 0;
}
pr_crit("Unexpected close of /dev/watchdog!\n");
watchdog_device.driver_closed = 1;
intel_scu_keepalive();
watchdog_fire();
return 0;
}
static ssize_t intel_scu_write(struct file *file,
char const *data,
size_t len,
loff_t *ppos)
{
if (watchdog_device.timer_started)
intel_scu_keepalive();
else
intel_scu_set_heartbeat(watchdog_device.timer_set);
return len;
}
static long intel_scu_ioctl(struct file *file,
unsigned int cmd,
unsigned long arg)
{
void __user *argp = (void __user *)arg;
u32 __user *p = argp;
u32 new_margin;
static const struct watchdog_info ident = {
.options = WDIOF_SETTIMEOUT
| WDIOF_KEEPALIVEPING,
.firmware_version = 0,
.identity = "Intel_SCU IOH Watchdog"
};
switch (cmd) {
case WDIOC_GETSUPPORT:
return copy_to_user(argp,
&ident,
sizeof(ident)) ? -EFAULT : 0;
case WDIOC_GETSTATUS:
case WDIOC_GETBOOTSTATUS:
return put_user(0, p);
case WDIOC_KEEPALIVE:
intel_scu_keepalive();
return 0;
case WDIOC_SETTIMEOUT:
if (get_user(new_margin, p))
return -EFAULT;
if (check_timer_margin(new_margin))
return -EINVAL;
if (intel_scu_set_heartbeat(new_margin))
return -EINVAL;
return 0;
case WDIOC_GETTIMEOUT:
return put_user(watchdog_device.soft_threshold, p);
default:
return -ENOTTY;
}
}
static int intel_scu_notify_sys(struct notifier_block *this,
unsigned long code,
void *another_unused)
{
if (code == SYS_DOWN || code == SYS_HALT)
intel_scu_stop();
return NOTIFY_DONE;
}
static int __init intel_scu_watchdog_init(void)
{
int ret;
u32 __iomem *tmp_addr;
if (!intel_mid_identify_cpu())
return -ENODEV;
if ((timer_set < MIN_TIME_CYCLE) ||
(timer_set > MAX_TIME - MIN_TIME_CYCLE)) {
pr_err("value of timer_set %x (hex) is out of range from %x to %x (hex)\n",
timer_set, MIN_TIME_CYCLE, MAX_TIME - MIN_TIME_CYCLE);
return -EINVAL;
}
if (check_timer_margin(timer_margin))
return -EINVAL;
watchdog_device.timer_tbl_ptr = sfi_get_mtmr(sfi_mtimer_num-1);
if (watchdog_device.timer_tbl_ptr == NULL) {
pr_debug("timer is not available\n");
return -ENODEV;
}
if (watchdog_device.timer_tbl_ptr->phys_addr == 0) {
pr_debug("timer %d does not have valid physical memory\n",
sfi_mtimer_num);
return -ENODEV;
}
if (watchdog_device.timer_tbl_ptr->irq == 0) {
pr_debug("timer %d invalid irq\n", sfi_mtimer_num);
return -ENODEV;
}
tmp_addr = ioremap_nocache(watchdog_device.timer_tbl_ptr->phys_addr,
20);
if (tmp_addr == NULL) {
pr_debug("timer unable to ioremap\n");
return -ENOMEM;
}
watchdog_device.timer_load_count_addr = tmp_addr++;
watchdog_device.timer_current_value_addr = tmp_addr++;
watchdog_device.timer_control_addr = tmp_addr++;
watchdog_device.timer_clear_interrupt_addr = tmp_addr++;
watchdog_device.timer_interrupt_status_addr = tmp_addr++;
watchdog_device.timer_set = timer_set;
watchdog_device.threshold =
timer_margin * watchdog_device.timer_tbl_ptr->freq_hz;
watchdog_device.soft_threshold =
(watchdog_device.timer_set - timer_margin)
* watchdog_device.timer_tbl_ptr->freq_hz;
watchdog_device.intel_scu_notifier.notifier_call =
intel_scu_notify_sys;
ret = register_reboot_notifier(&watchdog_device.intel_scu_notifier);
if (ret) {
pr_err("cannot register notifier %d)\n", ret);
goto register_reboot_error;
}
watchdog_device.miscdev.minor = WATCHDOG_MINOR;
watchdog_device.miscdev.name = "watchdog";
watchdog_device.miscdev.fops = &intel_scu_fops;
ret = misc_register(&watchdog_device.miscdev);
if (ret) {
pr_err("cannot register miscdev %d err =%d\n",
WATCHDOG_MINOR, ret);
goto misc_register_error;
}
ret = request_irq((unsigned int)watchdog_device.timer_tbl_ptr->irq,
watchdog_timer_interrupt,
IRQF_SHARED, "watchdog",
&watchdog_device.timer_load_count_addr);
if (ret) {
pr_err("error requesting irq %d\n", ret);
goto request_irq_error;
}
intel_scu_stop();
return 0;
request_irq_error:
misc_deregister(&watchdog_device.miscdev);
misc_register_error:
unregister_reboot_notifier(&watchdog_device.intel_scu_notifier);
register_reboot_error:
intel_scu_stop();
iounmap(watchdog_device.timer_load_count_addr);
return ret;
}
static void __exit intel_scu_watchdog_exit(void)
{
misc_deregister(&watchdog_device.miscdev);
unregister_reboot_notifier(&watchdog_device.intel_scu_notifier);
iowrite32(0x00000002, watchdog_device.timer_control_addr);
iounmap(watchdog_device.timer_load_count_addr);
}
