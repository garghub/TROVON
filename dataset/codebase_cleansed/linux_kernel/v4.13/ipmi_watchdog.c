static int set_param_timeout(const char *val, const struct kernel_param *kp)
{
char *endp;
int l;
int rv = 0;
if (!val)
return -EINVAL;
l = simple_strtoul(val, &endp, 0);
if (endp == val)
return -EINVAL;
*((int *)kp->arg) = l;
if (watchdog_user)
rv = ipmi_set_timeout(IPMI_SET_TIMEOUT_HB_IF_NECESSARY);
return rv;
}
static int set_param_str(const char *val, const struct kernel_param *kp)
{
action_fn fn = (action_fn) kp->arg;
int rv = 0;
char valcp[16];
char *s;
strncpy(valcp, val, 16);
valcp[15] = '\0';
s = strstrip(valcp);
rv = fn(s, NULL);
if (rv)
goto out;
check_parms();
if (watchdog_user)
rv = ipmi_set_timeout(IPMI_SET_TIMEOUT_HB_IF_NECESSARY);
out:
return rv;
}
static int get_param_str(char *buffer, const struct kernel_param *kp)
{
action_fn fn = (action_fn) kp->arg;
int rv;
rv = fn(NULL, buffer);
if (rv)
return rv;
return strlen(buffer);
}
static int set_param_wdog_ifnum(const char *val, const struct kernel_param *kp)
{
int rv = param_set_int(val, kp);
if (rv)
return rv;
if ((ifnum_to_use < 0) || (ifnum_to_use == watchdog_ifnum))
return 0;
ipmi_unregister_watchdog(watchdog_ifnum);
ipmi_register_watchdog(ifnum_to_use);
return 0;
}
static void set_timeout_free_smi(struct ipmi_smi_msg *msg)
{
if (atomic_dec_and_test(&set_timeout_tofree))
complete(&set_timeout_wait);
}
static void set_timeout_free_recv(struct ipmi_recv_msg *msg)
{
if (atomic_dec_and_test(&set_timeout_tofree))
complete(&set_timeout_wait);
}
static int i_ipmi_set_timeout(struct ipmi_smi_msg *smi_msg,
struct ipmi_recv_msg *recv_msg,
int *send_heartbeat_now)
{
struct kernel_ipmi_msg msg;
unsigned char data[6];
int rv;
struct ipmi_system_interface_addr addr;
int hbnow = 0;
pretimeout_since_last_heartbeat = 0;
data[0] = 0;
WDOG_SET_TIMER_USE(data[0], WDOG_TIMER_USE_SMS_OS);
if ((ipmi_version_major > 1)
|| ((ipmi_version_major == 1) && (ipmi_version_minor >= 5))) {
data[0] |= WDOG_DONT_STOP_ON_SET;
} else if (ipmi_watchdog_state != WDOG_TIMEOUT_NONE) {
hbnow = 1;
}
data[1] = 0;
WDOG_SET_TIMEOUT_ACT(data[1], ipmi_watchdog_state);
if ((pretimeout > 0) && (ipmi_watchdog_state != WDOG_TIMEOUT_NONE)) {
WDOG_SET_PRETIMEOUT_ACT(data[1], preaction_val);
data[2] = pretimeout;
} else {
WDOG_SET_PRETIMEOUT_ACT(data[1], WDOG_PRETIMEOUT_NONE);
data[2] = 0;
}
data[3] = 0;
WDOG_SET_TIMEOUT(data[4], data[5], timeout);
addr.addr_type = IPMI_SYSTEM_INTERFACE_ADDR_TYPE;
addr.channel = IPMI_BMC_CHANNEL;
addr.lun = 0;
msg.netfn = 0x06;
msg.cmd = IPMI_WDOG_SET_TIMER;
msg.data = data;
msg.data_len = sizeof(data);
rv = ipmi_request_supply_msgs(watchdog_user,
(struct ipmi_addr *) &addr,
0,
&msg,
NULL,
smi_msg,
recv_msg,
1);
if (rv) {
printk(KERN_WARNING PFX "set timeout error: %d\n",
rv);
}
if (send_heartbeat_now)
*send_heartbeat_now = hbnow;
return rv;
}
static int ipmi_set_timeout(int do_heartbeat)
{
int send_heartbeat_now;
int rv;
mutex_lock(&set_timeout_lock);
atomic_set(&set_timeout_tofree, 2);
rv = i_ipmi_set_timeout(&set_timeout_smi_msg,
&set_timeout_recv_msg,
&send_heartbeat_now);
if (rv) {
mutex_unlock(&set_timeout_lock);
goto out;
}
wait_for_completion(&set_timeout_wait);
mutex_unlock(&set_timeout_lock);
if ((do_heartbeat == IPMI_SET_TIMEOUT_FORCE_HB)
|| ((send_heartbeat_now)
&& (do_heartbeat == IPMI_SET_TIMEOUT_HB_IF_NECESSARY)))
rv = ipmi_heartbeat();
out:
return rv;
}
static void panic_smi_free(struct ipmi_smi_msg *msg)
{
atomic_dec(&panic_done_count);
}
static void panic_recv_free(struct ipmi_recv_msg *msg)
{
atomic_dec(&panic_done_count);
}
static void panic_halt_ipmi_heartbeat(void)
{
struct kernel_ipmi_msg msg;
struct ipmi_system_interface_addr addr;
int rv;
if (ipmi_watchdog_state == WDOG_TIMEOUT_NONE)
return;
addr.addr_type = IPMI_SYSTEM_INTERFACE_ADDR_TYPE;
addr.channel = IPMI_BMC_CHANNEL;
addr.lun = 0;
msg.netfn = 0x06;
msg.cmd = IPMI_WDOG_RESET_TIMER;
msg.data = NULL;
msg.data_len = 0;
atomic_add(1, &panic_done_count);
rv = ipmi_request_supply_msgs(watchdog_user,
(struct ipmi_addr *) &addr,
0,
&msg,
NULL,
&panic_halt_heartbeat_smi_msg,
&panic_halt_heartbeat_recv_msg,
1);
if (rv)
atomic_sub(1, &panic_done_count);
}
static void panic_halt_ipmi_set_timeout(void)
{
int send_heartbeat_now;
int rv;
while (atomic_read(&panic_done_count) != 0)
ipmi_poll_interface(watchdog_user);
atomic_add(1, &panic_done_count);
rv = i_ipmi_set_timeout(&panic_halt_smi_msg,
&panic_halt_recv_msg,
&send_heartbeat_now);
if (rv) {
atomic_sub(1, &panic_done_count);
printk(KERN_WARNING PFX
"Unable to extend the watchdog timeout.");
} else {
if (send_heartbeat_now)
panic_halt_ipmi_heartbeat();
}
while (atomic_read(&panic_done_count) != 0)
ipmi_poll_interface(watchdog_user);
}
static void heartbeat_free_smi(struct ipmi_smi_msg *msg)
{
if (atomic_dec_and_test(&heartbeat_tofree))
complete(&heartbeat_wait);
}
static void heartbeat_free_recv(struct ipmi_recv_msg *msg)
{
if (atomic_dec_and_test(&heartbeat_tofree))
complete(&heartbeat_wait);
}
static int ipmi_heartbeat(void)
{
struct kernel_ipmi_msg msg;
int rv;
struct ipmi_system_interface_addr addr;
int timeout_retries = 0;
if (ipmi_ignore_heartbeat)
return 0;
if (ipmi_start_timer_on_heartbeat) {
ipmi_start_timer_on_heartbeat = 0;
ipmi_watchdog_state = action_val;
return ipmi_set_timeout(IPMI_SET_TIMEOUT_FORCE_HB);
} else if (pretimeout_since_last_heartbeat) {
return ipmi_set_timeout(IPMI_SET_TIMEOUT_HB_IF_NECESSARY);
}
mutex_lock(&heartbeat_lock);
restart:
atomic_set(&heartbeat_tofree, 2);
if (ipmi_watchdog_state == WDOG_TIMEOUT_NONE) {
mutex_unlock(&heartbeat_lock);
return 0;
}
addr.addr_type = IPMI_SYSTEM_INTERFACE_ADDR_TYPE;
addr.channel = IPMI_BMC_CHANNEL;
addr.lun = 0;
msg.netfn = 0x06;
msg.cmd = IPMI_WDOG_RESET_TIMER;
msg.data = NULL;
msg.data_len = 0;
rv = ipmi_request_supply_msgs(watchdog_user,
(struct ipmi_addr *) &addr,
0,
&msg,
NULL,
&heartbeat_smi_msg,
&heartbeat_recv_msg,
1);
if (rv) {
mutex_unlock(&heartbeat_lock);
printk(KERN_WARNING PFX "heartbeat failure: %d\n",
rv);
return rv;
}
wait_for_completion(&heartbeat_wait);
if (heartbeat_recv_msg.msg.data[0] == IPMI_WDOG_TIMER_NOT_INIT_RESP) {
timeout_retries++;
if (timeout_retries > 3) {
printk(KERN_ERR PFX ": Unable to restore the IPMI"
" watchdog's settings, giving up.\n");
rv = -EIO;
goto out_unlock;
}
rv = ipmi_set_timeout(IPMI_SET_TIMEOUT_NO_HB);
if (rv) {
printk(KERN_ERR PFX ": Unable to send the command to"
" set the watchdog's settings, giving up.\n");
goto out_unlock;
}
goto restart;
} else if (heartbeat_recv_msg.msg.data[0] != 0) {
rv = -EINVAL;
}
out_unlock:
mutex_unlock(&heartbeat_lock);
return rv;
}
static int ipmi_ioctl(struct file *file,
unsigned int cmd, unsigned long arg)
{
void __user *argp = (void __user *)arg;
int i;
int val;
switch (cmd) {
case WDIOC_GETSUPPORT:
i = copy_to_user(argp, &ident, sizeof(ident));
return i ? -EFAULT : 0;
case WDIOC_SETTIMEOUT:
i = copy_from_user(&val, argp, sizeof(int));
if (i)
return -EFAULT;
timeout = val;
return ipmi_set_timeout(IPMI_SET_TIMEOUT_HB_IF_NECESSARY);
case WDIOC_GETTIMEOUT:
i = copy_to_user(argp, &timeout, sizeof(timeout));
if (i)
return -EFAULT;
return 0;
case WDIOC_SETPRETIMEOUT:
i = copy_from_user(&val, argp, sizeof(int));
if (i)
return -EFAULT;
pretimeout = val;
return ipmi_set_timeout(IPMI_SET_TIMEOUT_HB_IF_NECESSARY);
case WDIOC_GETPRETIMEOUT:
i = copy_to_user(argp, &pretimeout, sizeof(pretimeout));
if (i)
return -EFAULT;
return 0;
case WDIOC_KEEPALIVE:
return ipmi_heartbeat();
case WDIOC_SETOPTIONS:
i = copy_from_user(&val, argp, sizeof(int));
if (i)
return -EFAULT;
if (val & WDIOS_DISABLECARD) {
ipmi_watchdog_state = WDOG_TIMEOUT_NONE;
ipmi_set_timeout(IPMI_SET_TIMEOUT_NO_HB);
ipmi_start_timer_on_heartbeat = 0;
}
if (val & WDIOS_ENABLECARD) {
ipmi_watchdog_state = action_val;
ipmi_set_timeout(IPMI_SET_TIMEOUT_FORCE_HB);
}
return 0;
case WDIOC_GETSTATUS:
val = 0;
i = copy_to_user(argp, &val, sizeof(val));
if (i)
return -EFAULT;
return 0;
default:
return -ENOIOCTLCMD;
}
}
static long ipmi_unlocked_ioctl(struct file *file,
unsigned int cmd,
unsigned long arg)
{
int ret;
mutex_lock(&ipmi_watchdog_mutex);
ret = ipmi_ioctl(file, cmd, arg);
mutex_unlock(&ipmi_watchdog_mutex);
return ret;
}
static ssize_t ipmi_write(struct file *file,
const char __user *buf,
size_t len,
loff_t *ppos)
{
int rv;
if (len) {
if (!nowayout) {
size_t i;
expect_close = 0;
for (i = 0; i != len; i++) {
char c;
if (get_user(c, buf + i))
return -EFAULT;
if (c == 'V')
expect_close = 42;
}
}
rv = ipmi_heartbeat();
if (rv)
return rv;
}
return len;
}
static ssize_t ipmi_read(struct file *file,
char __user *buf,
size_t count,
loff_t *ppos)
{
int rv = 0;
wait_queue_entry_t wait;
if (count <= 0)
return 0;
spin_lock(&ipmi_read_lock);
if (!data_to_read) {
if (file->f_flags & O_NONBLOCK) {
rv = -EAGAIN;
goto out;
}
init_waitqueue_entry(&wait, current);
add_wait_queue(&read_q, &wait);
while (!data_to_read) {
set_current_state(TASK_INTERRUPTIBLE);
spin_unlock(&ipmi_read_lock);
schedule();
spin_lock(&ipmi_read_lock);
}
remove_wait_queue(&read_q, &wait);
if (signal_pending(current)) {
rv = -ERESTARTSYS;
goto out;
}
}
data_to_read = 0;
out:
spin_unlock(&ipmi_read_lock);
if (rv == 0) {
if (copy_to_user(buf, &data_to_read, 1))
rv = -EFAULT;
else
rv = 1;
}
return rv;
}
static int ipmi_open(struct inode *ino, struct file *filep)
{
switch (iminor(ino)) {
case WATCHDOG_MINOR:
if (test_and_set_bit(0, &ipmi_wdog_open))
return -EBUSY;
ipmi_start_timer_on_heartbeat = 1;
return nonseekable_open(ino, filep);
default:
return (-ENODEV);
}
}
static unsigned int ipmi_poll(struct file *file, poll_table *wait)
{
unsigned int mask = 0;
poll_wait(file, &read_q, wait);
spin_lock(&ipmi_read_lock);
if (data_to_read)
mask |= (POLLIN | POLLRDNORM);
spin_unlock(&ipmi_read_lock);
return mask;
}
static int ipmi_fasync(int fd, struct file *file, int on)
{
int result;
result = fasync_helper(fd, file, on, &fasync_q);
return (result);
}
static int ipmi_close(struct inode *ino, struct file *filep)
{
if (iminor(ino) == WATCHDOG_MINOR) {
if (expect_close == 42) {
ipmi_watchdog_state = WDOG_TIMEOUT_NONE;
ipmi_set_timeout(IPMI_SET_TIMEOUT_NO_HB);
} else {
printk(KERN_CRIT PFX
"Unexpected close, not stopping watchdog!\n");
ipmi_heartbeat();
}
clear_bit(0, &ipmi_wdog_open);
}
expect_close = 0;
return 0;
}
static void ipmi_wdog_msg_handler(struct ipmi_recv_msg *msg,
void *handler_data)
{
if (msg->msg.cmd == IPMI_WDOG_RESET_TIMER &&
msg->msg.data[0] == IPMI_WDOG_TIMER_NOT_INIT_RESP)
printk(KERN_INFO PFX "response: The IPMI controller appears"
" to have been reset, will attempt to reinitialize"
" the watchdog timer\n");
else if (msg->msg.data[0] != 0)
printk(KERN_ERR PFX "response: Error %x on cmd %x\n",
msg->msg.data[0],
msg->msg.cmd);
ipmi_free_recv_msg(msg);
}
static void ipmi_wdog_pretimeout_handler(void *handler_data)
{
if (preaction_val != WDOG_PRETIMEOUT_NONE) {
if (preop_val == WDOG_PREOP_PANIC) {
if (atomic_inc_and_test(&preop_panic_excl))
panic("Watchdog pre-timeout");
} else if (preop_val == WDOG_PREOP_GIVE_DATA) {
spin_lock(&ipmi_read_lock);
data_to_read = 1;
wake_up_interruptible(&read_q);
kill_fasync(&fasync_q, SIGIO, POLL_IN);
spin_unlock(&ipmi_read_lock);
}
}
pretimeout_since_last_heartbeat = 1;
}
static void ipmi_register_watchdog(int ipmi_intf)
{
int rv = -EBUSY;
if (watchdog_user)
goto out;
if ((ifnum_to_use >= 0) && (ifnum_to_use != ipmi_intf))
goto out;
watchdog_ifnum = ipmi_intf;
rv = ipmi_create_user(ipmi_intf, &ipmi_hndlrs, NULL, &watchdog_user);
if (rv < 0) {
printk(KERN_CRIT PFX "Unable to register with ipmi\n");
goto out;
}
ipmi_get_version(watchdog_user,
&ipmi_version_major,
&ipmi_version_minor);
rv = misc_register(&ipmi_wdog_miscdev);
if (rv < 0) {
ipmi_destroy_user(watchdog_user);
watchdog_user = NULL;
printk(KERN_CRIT PFX "Unable to register misc device\n");
}
#ifdef HAVE_DIE_NMI
if (nmi_handler_registered) {
int old_pretimeout = pretimeout;
int old_timeout = timeout;
int old_preop_val = preop_val;
ipmi_watchdog_state = WDOG_TIMEOUT_RESET;
preop_val = WDOG_PREOP_NONE;
pretimeout = 99;
timeout = 100;
testing_nmi = 1;
rv = ipmi_set_timeout(IPMI_SET_TIMEOUT_FORCE_HB);
if (rv) {
printk(KERN_WARNING PFX "Error starting timer to"
" test NMI: 0x%x. The NMI pretimeout will"
" likely not work\n", rv);
rv = 0;
goto out_restore;
}
msleep(1500);
if (testing_nmi != 2) {
printk(KERN_WARNING PFX "IPMI NMI didn't seem to"
" occur. The NMI pretimeout will"
" likely not work\n");
}
out_restore:
testing_nmi = 0;
preop_val = old_preop_val;
pretimeout = old_pretimeout;
timeout = old_timeout;
}
#endif
out:
if ((start_now) && (rv == 0)) {
start_now = 0;
ipmi_watchdog_state = action_val;
ipmi_set_timeout(IPMI_SET_TIMEOUT_FORCE_HB);
printk(KERN_INFO PFX "Starting now!\n");
} else {
ipmi_watchdog_state = WDOG_TIMEOUT_NONE;
ipmi_set_timeout(IPMI_SET_TIMEOUT_NO_HB);
}
}
static void ipmi_unregister_watchdog(int ipmi_intf)
{
int rv;
if (!watchdog_user)
goto out;
if (watchdog_ifnum != ipmi_intf)
goto out;
misc_deregister(&ipmi_wdog_miscdev);
while (atomic_read(&set_timeout_tofree))
schedule_timeout_uninterruptible(1);
rv = ipmi_destroy_user(watchdog_user);
if (rv) {
printk(KERN_WARNING PFX "error unlinking from IPMI: %d\n",
rv);
}
watchdog_user = NULL;
out:
return;
}
static int
ipmi_nmi(unsigned int val, struct pt_regs *regs)
{
if (testing_nmi) {
testing_nmi = 2;
return NMI_HANDLED;
}
if (ipmi_watchdog_state == WDOG_TIMEOUT_NONE)
return NMI_DONE;
if (preaction_val != WDOG_PRETIMEOUT_NMI)
return NMI_DONE;
if (preop_val == WDOG_PREOP_PANIC) {
pretimeout_since_last_heartbeat = 1;
if (atomic_inc_and_test(&preop_panic_excl))
nmi_panic(regs, PFX "pre-timeout");
}
return NMI_HANDLED;
}
static int wdog_reboot_handler(struct notifier_block *this,
unsigned long code,
void *unused)
{
static int reboot_event_handled;
if ((watchdog_user) && (!reboot_event_handled)) {
reboot_event_handled = 1;
if (code == SYS_POWER_OFF || code == SYS_HALT) {
ipmi_watchdog_state = WDOG_TIMEOUT_NONE;
ipmi_set_timeout(IPMI_SET_TIMEOUT_NO_HB);
} else if (ipmi_watchdog_state != WDOG_TIMEOUT_NONE) {
if (timeout < 120)
timeout = 120;
pretimeout = 0;
ipmi_watchdog_state = WDOG_TIMEOUT_RESET;
ipmi_set_timeout(IPMI_SET_TIMEOUT_NO_HB);
}
}
return NOTIFY_OK;
}
static int wdog_panic_handler(struct notifier_block *this,
unsigned long event,
void *unused)
{
static int panic_event_handled;
if (watchdog_user && !panic_event_handled &&
ipmi_watchdog_state != WDOG_TIMEOUT_NONE) {
panic_event_handled = 1;
timeout = panic_wdt_timeout;
pretimeout = 0;
panic_halt_ipmi_set_timeout();
}
return NOTIFY_OK;
}
static void ipmi_new_smi(int if_num, struct device *device)
{
ipmi_register_watchdog(if_num);
}
static void ipmi_smi_gone(int if_num)
{
ipmi_unregister_watchdog(if_num);
}
static int action_op(const char *inval, char *outval)
{
if (outval)
strcpy(outval, action);
if (!inval)
return 0;
if (strcmp(inval, "reset") == 0)
action_val = WDOG_TIMEOUT_RESET;
else if (strcmp(inval, "none") == 0)
action_val = WDOG_TIMEOUT_NONE;
else if (strcmp(inval, "power_cycle") == 0)
action_val = WDOG_TIMEOUT_POWER_CYCLE;
else if (strcmp(inval, "power_off") == 0)
action_val = WDOG_TIMEOUT_POWER_DOWN;
else
return -EINVAL;
strcpy(action, inval);
return 0;
}
static int preaction_op(const char *inval, char *outval)
{
if (outval)
strcpy(outval, preaction);
if (!inval)
return 0;
if (strcmp(inval, "pre_none") == 0)
preaction_val = WDOG_PRETIMEOUT_NONE;
else if (strcmp(inval, "pre_smi") == 0)
preaction_val = WDOG_PRETIMEOUT_SMI;
#ifdef HAVE_DIE_NMI
else if (strcmp(inval, "pre_nmi") == 0)
preaction_val = WDOG_PRETIMEOUT_NMI;
#endif
else if (strcmp(inval, "pre_int") == 0)
preaction_val = WDOG_PRETIMEOUT_MSG_INT;
else
return -EINVAL;
strcpy(preaction, inval);
return 0;
}
static int preop_op(const char *inval, char *outval)
{
if (outval)
strcpy(outval, preop);
if (!inval)
return 0;
if (strcmp(inval, "preop_none") == 0)
preop_val = WDOG_PREOP_NONE;
else if (strcmp(inval, "preop_panic") == 0)
preop_val = WDOG_PREOP_PANIC;
else if (strcmp(inval, "preop_give_data") == 0)
preop_val = WDOG_PREOP_GIVE_DATA;
else
return -EINVAL;
strcpy(preop, inval);
return 0;
}
static void check_parms(void)
{
#ifdef HAVE_DIE_NMI
int do_nmi = 0;
int rv;
if (preaction_val == WDOG_PRETIMEOUT_NMI) {
do_nmi = 1;
if (preop_val == WDOG_PREOP_GIVE_DATA) {
printk(KERN_WARNING PFX "Pretimeout op is to give data"
" but NMI pretimeout is enabled, setting"
" pretimeout op to none\n");
preop_op("preop_none", NULL);
do_nmi = 0;
}
}
if (do_nmi && !nmi_handler_registered) {
rv = register_nmi_handler(NMI_UNKNOWN, ipmi_nmi, 0,
"ipmi");
if (rv) {
printk(KERN_WARNING PFX
"Can't register nmi handler\n");
return;
} else
nmi_handler_registered = 1;
} else if (!do_nmi && nmi_handler_registered) {
unregister_nmi_handler(NMI_UNKNOWN, "ipmi");
nmi_handler_registered = 0;
}
#endif
}
static int __init ipmi_wdog_init(void)
{
int rv;
if (action_op(action, NULL)) {
action_op("reset", NULL);
printk(KERN_INFO PFX "Unknown action '%s', defaulting to"
" reset\n", action);
}
if (preaction_op(preaction, NULL)) {
preaction_op("pre_none", NULL);
printk(KERN_INFO PFX "Unknown preaction '%s', defaulting to"
" none\n", preaction);
}
if (preop_op(preop, NULL)) {
preop_op("preop_none", NULL);
printk(KERN_INFO PFX "Unknown preop '%s', defaulting to"
" none\n", preop);
}
check_parms();
register_reboot_notifier(&wdog_reboot_notifier);
atomic_notifier_chain_register(&panic_notifier_list,
&wdog_panic_notifier);
rv = ipmi_smi_watcher_register(&smi_watcher);
if (rv) {
#ifdef HAVE_DIE_NMI
if (nmi_handler_registered)
unregister_nmi_handler(NMI_UNKNOWN, "ipmi");
#endif
atomic_notifier_chain_unregister(&panic_notifier_list,
&wdog_panic_notifier);
unregister_reboot_notifier(&wdog_reboot_notifier);
printk(KERN_WARNING PFX "can't register smi watcher\n");
return rv;
}
printk(KERN_INFO PFX "driver initialized\n");
return 0;
}
static void __exit ipmi_wdog_exit(void)
{
ipmi_smi_watcher_unregister(&smi_watcher);
ipmi_unregister_watchdog(watchdog_ifnum);
#ifdef HAVE_DIE_NMI
if (nmi_handler_registered)
unregister_nmi_handler(NMI_UNKNOWN, "ipmi");
#endif
atomic_notifier_chain_unregister(&panic_notifier_list,
&wdog_panic_notifier);
unregister_reboot_notifier(&wdog_reboot_notifier);
}
