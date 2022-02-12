static void apm_error(char *str, int err)
{
int i;
for (i = 0; i < ERROR_COUNT; i++)
if (error_table[i].key == err)
break;
if (i < ERROR_COUNT)
printk(KERN_NOTICE "apm: %s: %s\n", str, error_table[i].msg);
else if (err < 0)
printk(KERN_NOTICE "apm: %s: linux error code %i\n", str, err);
else
printk(KERN_NOTICE "apm: %s: unknown error code %#2.2x\n",
str, err);
}
static inline unsigned long __apm_irq_save(void)
{
unsigned long flags;
local_save_flags(flags);
if (apm_info.allow_ints) {
if (irqs_disabled_flags(flags))
local_irq_enable();
} else
local_irq_disable();
return flags;
}
static inline void apm_irq_restore(unsigned long flags)
{
if (irqs_disabled_flags(flags))
local_irq_disable();
else if (irqs_disabled())
local_irq_enable();
}
static long __apm_bios_call(void *_call)
{
APM_DECL_SEGS
unsigned long flags;
int cpu;
struct desc_struct save_desc_40;
struct desc_struct *gdt;
struct apm_bios_call *call = _call;
cpu = get_cpu();
BUG_ON(cpu != 0);
gdt = get_cpu_gdt_table(cpu);
save_desc_40 = gdt[0x40 / 8];
gdt[0x40 / 8] = bad_bios_desc;
apm_irq_save(flags);
APM_DO_SAVE_SEGS;
apm_bios_call_asm(call->func, call->ebx, call->ecx,
&call->eax, &call->ebx, &call->ecx, &call->edx,
&call->esi);
APM_DO_RESTORE_SEGS;
apm_irq_restore(flags);
gdt[0x40 / 8] = save_desc_40;
put_cpu();
return call->eax & 0xff;
}
static int on_cpu0(long (*fn)(void *), struct apm_bios_call *call)
{
int ret;
if (get_cpu() == 0) {
ret = fn(call);
put_cpu();
} else {
put_cpu();
ret = work_on_cpu(0, fn, call);
}
if (ret < 0)
call->err = ret;
else
call->err = (call->eax >> 8) & 0xff;
return ret;
}
static int apm_bios_call(struct apm_bios_call *call)
{
return on_cpu0(__apm_bios_call, call);
}
static long __apm_bios_call_simple(void *_call)
{
u8 error;
APM_DECL_SEGS
unsigned long flags;
int cpu;
struct desc_struct save_desc_40;
struct desc_struct *gdt;
struct apm_bios_call *call = _call;
cpu = get_cpu();
BUG_ON(cpu != 0);
gdt = get_cpu_gdt_table(cpu);
save_desc_40 = gdt[0x40 / 8];
gdt[0x40 / 8] = bad_bios_desc;
apm_irq_save(flags);
APM_DO_SAVE_SEGS;
error = apm_bios_call_simple_asm(call->func, call->ebx, call->ecx,
&call->eax);
APM_DO_RESTORE_SEGS;
apm_irq_restore(flags);
gdt[0x40 / 8] = save_desc_40;
put_cpu();
return error;
}
static int apm_bios_call_simple(u32 func, u32 ebx_in, u32 ecx_in, u32 *eax,
int *err)
{
struct apm_bios_call call;
int ret;
call.func = func;
call.ebx = ebx_in;
call.ecx = ecx_in;
ret = on_cpu0(__apm_bios_call_simple, &call);
*eax = call.eax;
*err = call.err;
return ret;
}
static int apm_driver_version(u_short *val)
{
u32 eax;
int err;
if (apm_bios_call_simple(APM_FUNC_VERSION, 0, *val, &eax, &err))
return err;
*val = eax;
return APM_SUCCESS;
}
static int apm_get_event(apm_event_t *event, apm_eventinfo_t *info)
{
struct apm_bios_call call;
call.func = APM_FUNC_GET_EVENT;
call.ebx = call.ecx = 0;
if (apm_bios_call(&call))
return call.err;
*event = call.ebx;
if (apm_info.connection_version < 0x0102)
*info = ~0;
else
*info = call.ecx;
return APM_SUCCESS;
}
static int set_power_state(u_short what, u_short state)
{
u32 eax;
int err;
if (apm_bios_call_simple(APM_FUNC_SET_STATE, what, state, &eax, &err))
return err;
return APM_SUCCESS;
}
static int set_system_power_state(u_short state)
{
return set_power_state(APM_DEVICE_ALL, state);
}
static int apm_do_idle(void)
{
u32 eax;
u8 ret = 0;
int idled = 0;
int polling;
int err = 0;
polling = !!(current_thread_info()->status & TS_POLLING);
if (polling) {
current_thread_info()->status &= ~TS_POLLING;
smp_mb();
}
if (!need_resched()) {
idled = 1;
ret = apm_bios_call_simple(APM_FUNC_IDLE, 0, 0, &eax, &err);
}
if (polling)
current_thread_info()->status |= TS_POLLING;
if (!idled)
return 0;
if (ret) {
static unsigned long t;
if (++t < 5) {
printk(KERN_DEBUG "apm_do_idle failed (%d)\n", err);
t = jiffies;
}
return -1;
}
clock_slowed = (apm_info.bios.flags & APM_IDLE_SLOWS_CLOCK) != 0;
return clock_slowed;
}
static void apm_do_busy(void)
{
u32 dummy;
int err;
if (clock_slowed || ALWAYS_CALL_BUSY) {
(void)apm_bios_call_simple(APM_FUNC_BUSY, 0, 0, &dummy, &err);
clock_slowed = 0;
}
}
static void apm_cpu_idle(void)
{
static int use_apm_idle;
static unsigned int last_jiffies;
static unsigned int last_stime;
int apm_idle_done = 0;
unsigned int jiffies_since_last_check = jiffies - last_jiffies;
unsigned int bucket;
WARN_ONCE(1, "deprecated apm_cpu_idle will be deleted in 2012");
recalc:
if (jiffies_since_last_check > IDLE_CALC_LIMIT) {
use_apm_idle = 0;
last_jiffies = jiffies;
last_stime = current->stime;
} else if (jiffies_since_last_check > idle_period) {
unsigned int idle_percentage;
idle_percentage = current->stime - last_stime;
idle_percentage *= 100;
idle_percentage /= jiffies_since_last_check;
use_apm_idle = (idle_percentage > idle_threshold);
if (apm_info.forbid_idle)
use_apm_idle = 0;
last_jiffies = jiffies;
last_stime = current->stime;
}
bucket = IDLE_LEAKY_MAX;
while (!need_resched()) {
if (use_apm_idle) {
unsigned int t;
t = jiffies;
switch (apm_do_idle()) {
case 0:
apm_idle_done = 1;
if (t != jiffies) {
if (bucket) {
bucket = IDLE_LEAKY_MAX;
continue;
}
} else if (bucket) {
bucket--;
continue;
}
break;
case 1:
apm_idle_done = 1;
break;
default:
break;
}
}
if (original_pm_idle)
original_pm_idle();
else
default_idle();
local_irq_disable();
jiffies_since_last_check = jiffies - last_jiffies;
if (jiffies_since_last_check > idle_period)
goto recalc;
}
if (apm_idle_done)
apm_do_busy();
local_irq_enable();
}
static void apm_power_off(void)
{
if (apm_info.realmode_power_off) {
set_cpus_allowed_ptr(current, cpumask_of(0));
machine_real_restart(MRR_APM);
} else {
(void)set_system_power_state(APM_STATE_OFF);
}
}
static int apm_enable_power_management(int enable)
{
u32 eax;
int err;
if ((enable == 0) && (apm_info.bios.flags & APM_BIOS_DISENGAGED))
return APM_NOT_ENGAGED;
if (apm_bios_call_simple(APM_FUNC_ENABLE_PM, APM_DEVICE_BALL,
enable, &eax, &err))
return err;
if (enable)
apm_info.bios.flags &= ~APM_BIOS_DISABLED;
else
apm_info.bios.flags |= APM_BIOS_DISABLED;
return APM_SUCCESS;
}
static int apm_get_power_status(u_short *status, u_short *bat, u_short *life)
{
struct apm_bios_call call;
call.func = APM_FUNC_GET_STATUS;
call.ebx = APM_DEVICE_ALL;
call.ecx = 0;
if (apm_info.get_power_status_broken)
return APM_32_UNSUPPORTED;
if (apm_bios_call(&call))
return call.err;
*status = call.ebx;
*bat = call.ecx;
if (apm_info.get_power_status_swabinminutes) {
*life = swab16((u16)call.edx);
*life |= 0x8000;
} else
*life = call.edx;
return APM_SUCCESS;
}
static int apm_engage_power_management(u_short device, int enable)
{
u32 eax;
int err;
if ((enable == 0) && (device == APM_DEVICE_ALL)
&& (apm_info.bios.flags & APM_BIOS_DISABLED))
return APM_DISABLED;
if (apm_bios_call_simple(APM_FUNC_ENGAGE_PM, device, enable,
&eax, &err))
return err;
if (device == APM_DEVICE_ALL) {
if (enable)
apm_info.bios.flags &= ~APM_BIOS_DISENGAGED;
else
apm_info.bios.flags |= APM_BIOS_DISENGAGED;
}
return APM_SUCCESS;
}
static int apm_console_blank(int blank)
{
int error = APM_NOT_ENGAGED;
int i;
u_short state;
static const u_short dev[3] = { 0x100, 0x1FF, 0x101 };
state = blank ? APM_STATE_STANDBY : APM_STATE_READY;
for (i = 0; i < ARRAY_SIZE(dev); i++) {
error = set_power_state(dev[i], state);
if ((error == APM_SUCCESS) || (error == APM_NO_ERROR))
return 1;
if (error == APM_NOT_ENGAGED)
break;
}
if (error == APM_NOT_ENGAGED) {
static int tried;
int eng_error;
if (tried++ == 0) {
eng_error = apm_engage_power_management(APM_DEVICE_ALL, 1);
if (eng_error) {
apm_error("set display", error);
apm_error("engage interface", eng_error);
return 0;
} else
return apm_console_blank(blank);
}
}
apm_error("set display", error);
return 0;
}
static int queue_empty(struct apm_user *as)
{
return as->event_head == as->event_tail;
}
static apm_event_t get_queued_event(struct apm_user *as)
{
if (++as->event_tail >= APM_MAX_EVENTS)
as->event_tail = 0;
return as->events[as->event_tail];
}
static void queue_event(apm_event_t event, struct apm_user *sender)
{
struct apm_user *as;
spin_lock(&user_list_lock);
if (user_list == NULL)
goto out;
for (as = user_list; as != NULL; as = as->next) {
if ((as == sender) || (!as->reader))
continue;
if (++as->event_head >= APM_MAX_EVENTS)
as->event_head = 0;
if (as->event_head == as->event_tail) {
static int notified;
if (notified++ == 0)
printk(KERN_ERR "apm: an event queue overflowed\n");
if (++as->event_tail >= APM_MAX_EVENTS)
as->event_tail = 0;
}
as->events[as->event_head] = event;
if (!as->suser || !as->writer)
continue;
switch (event) {
case APM_SYS_SUSPEND:
case APM_USER_SUSPEND:
as->suspends_pending++;
suspends_pending++;
break;
case APM_SYS_STANDBY:
case APM_USER_STANDBY:
as->standbys_pending++;
standbys_pending++;
break;
}
}
wake_up_interruptible(&apm_waitqueue);
out:
spin_unlock(&user_list_lock);
}
static void reinit_timer(void)
{
#ifdef INIT_TIMER_AFTER_SUSPEND
unsigned long flags;
raw_spin_lock_irqsave(&i8253_lock, flags);
outb_p(0x34, PIT_MODE);
udelay(10);
outb_p(LATCH & 0xff, PIT_CH0);
udelay(10);
outb_p(LATCH >> 8, PIT_CH0);
udelay(10);
raw_spin_unlock_irqrestore(&i8253_lock, flags);
#endif
}
static int suspend(int vetoable)
{
int err;
struct apm_user *as;
dpm_suspend_start(PMSG_SUSPEND);
dpm_suspend_end(PMSG_SUSPEND);
local_irq_disable();
syscore_suspend();
local_irq_enable();
save_processor_state();
err = set_system_power_state(APM_STATE_SUSPEND);
ignore_normal_resume = 1;
restore_processor_state();
local_irq_disable();
reinit_timer();
if (err == APM_NO_ERROR)
err = APM_SUCCESS;
if (err != APM_SUCCESS)
apm_error("suspend", err);
err = (err == APM_SUCCESS) ? 0 : -EIO;
syscore_resume();
local_irq_enable();
dpm_resume_start(PMSG_RESUME);
dpm_resume_end(PMSG_RESUME);
queue_event(APM_NORMAL_RESUME, NULL);
spin_lock(&user_list_lock);
for (as = user_list; as != NULL; as = as->next) {
as->suspend_wait = 0;
as->suspend_result = err;
}
spin_unlock(&user_list_lock);
wake_up_interruptible(&apm_suspend_waitqueue);
return err;
}
static void standby(void)
{
int err;
dpm_suspend_end(PMSG_SUSPEND);
local_irq_disable();
syscore_suspend();
local_irq_enable();
err = set_system_power_state(APM_STATE_STANDBY);
if ((err != APM_SUCCESS) && (err != APM_NO_ERROR))
apm_error("standby", err);
local_irq_disable();
syscore_resume();
local_irq_enable();
dpm_resume_start(PMSG_RESUME);
}
static apm_event_t get_event(void)
{
int error;
apm_event_t event = APM_NO_EVENTS;
apm_eventinfo_t info;
static int notified;
error = apm_get_event(&event, &info);
if (error == APM_SUCCESS)
return event;
if ((error != APM_NO_EVENTS) && (notified++ == 0))
apm_error("get_event", error);
return 0;
}
static void check_events(void)
{
apm_event_t event;
static unsigned long last_resume;
static int ignore_bounce;
while ((event = get_event()) != 0) {
if (debug) {
if (event <= NR_APM_EVENT_NAME)
printk(KERN_DEBUG "apm: received %s notify\n",
apm_event_name[event - 1]);
else
printk(KERN_DEBUG "apm: received unknown "
"event 0x%02x\n", event);
}
if (ignore_bounce
&& (time_after(jiffies, last_resume + bounce_interval)))
ignore_bounce = 0;
switch (event) {
case APM_SYS_STANDBY:
case APM_USER_STANDBY:
queue_event(event, NULL);
if (standbys_pending <= 0)
standby();
break;
case APM_USER_SUSPEND:
#ifdef CONFIG_APM_IGNORE_USER_SUSPEND
if (apm_info.connection_version > 0x100)
set_system_power_state(APM_STATE_REJECT);
break;
#endif
case APM_SYS_SUSPEND:
if (ignore_bounce) {
if (apm_info.connection_version > 0x100)
set_system_power_state(APM_STATE_REJECT);
break;
}
if (ignore_sys_suspend)
return;
ignore_sys_suspend = 1;
queue_event(event, NULL);
if (suspends_pending <= 0)
(void) suspend(1);
break;
case APM_NORMAL_RESUME:
case APM_CRITICAL_RESUME:
case APM_STANDBY_RESUME:
ignore_sys_suspend = 0;
last_resume = jiffies;
ignore_bounce = 1;
if ((event != APM_NORMAL_RESUME)
|| (ignore_normal_resume == 0)) {
dpm_resume_end(PMSG_RESUME);
queue_event(event, NULL);
}
ignore_normal_resume = 0;
break;
case APM_CAPABILITY_CHANGE:
case APM_LOW_BATTERY:
case APM_POWER_STATUS_CHANGE:
queue_event(event, NULL);
break;
case APM_UPDATE_TIME:
break;
case APM_CRITICAL_SUSPEND:
(void)suspend(0);
break;
}
}
}
static void apm_event_handler(void)
{
static int pending_count = 4;
int err;
if ((standbys_pending > 0) || (suspends_pending > 0)) {
if ((apm_info.connection_version > 0x100) &&
(pending_count-- <= 0)) {
pending_count = 4;
if (debug)
printk(KERN_DEBUG "apm: setting state busy\n");
err = set_system_power_state(APM_STATE_BUSY);
if (err)
apm_error("busy", err);
}
} else
pending_count = 4;
check_events();
}
static void apm_mainloop(void)
{
DECLARE_WAITQUEUE(wait, current);
add_wait_queue(&apm_waitqueue, &wait);
set_current_state(TASK_INTERRUPTIBLE);
for (;;) {
schedule_timeout(APM_CHECK_TIMEOUT);
if (kthread_should_stop())
break;
set_current_state(TASK_INTERRUPTIBLE);
apm_event_handler();
}
remove_wait_queue(&apm_waitqueue, &wait);
}
static int check_apm_user(struct apm_user *as, const char *func)
{
if (as == NULL || as->magic != APM_BIOS_MAGIC) {
printk(KERN_ERR "apm: %s passed bad filp\n", func);
return 1;
}
return 0;
}
static ssize_t do_read(struct file *fp, char __user *buf, size_t count, loff_t *ppos)
{
struct apm_user *as;
int i;
apm_event_t event;
as = fp->private_data;
if (check_apm_user(as, "read"))
return -EIO;
if ((int)count < sizeof(apm_event_t))
return -EINVAL;
if ((queue_empty(as)) && (fp->f_flags & O_NONBLOCK))
return -EAGAIN;
wait_event_interruptible(apm_waitqueue, !queue_empty(as));
i = count;
while ((i >= sizeof(event)) && !queue_empty(as)) {
event = get_queued_event(as);
if (copy_to_user(buf, &event, sizeof(event))) {
if (i < count)
break;
return -EFAULT;
}
switch (event) {
case APM_SYS_SUSPEND:
case APM_USER_SUSPEND:
as->suspends_read++;
break;
case APM_SYS_STANDBY:
case APM_USER_STANDBY:
as->standbys_read++;
break;
}
buf += sizeof(event);
i -= sizeof(event);
}
if (i < count)
return count - i;
if (signal_pending(current))
return -ERESTARTSYS;
return 0;
}
static unsigned int do_poll(struct file *fp, poll_table *wait)
{
struct apm_user *as;
as = fp->private_data;
if (check_apm_user(as, "poll"))
return 0;
poll_wait(fp, &apm_waitqueue, wait);
if (!queue_empty(as))
return POLLIN | POLLRDNORM;
return 0;
}
static long do_ioctl(struct file *filp, u_int cmd, u_long arg)
{
struct apm_user *as;
int ret;
as = filp->private_data;
if (check_apm_user(as, "ioctl"))
return -EIO;
if (!as->suser || !as->writer)
return -EPERM;
switch (cmd) {
case APM_IOC_STANDBY:
mutex_lock(&apm_mutex);
if (as->standbys_read > 0) {
as->standbys_read--;
as->standbys_pending--;
standbys_pending--;
} else
queue_event(APM_USER_STANDBY, as);
if (standbys_pending <= 0)
standby();
mutex_unlock(&apm_mutex);
break;
case APM_IOC_SUSPEND:
mutex_lock(&apm_mutex);
if (as->suspends_read > 0) {
as->suspends_read--;
as->suspends_pending--;
suspends_pending--;
} else
queue_event(APM_USER_SUSPEND, as);
if (suspends_pending <= 0) {
ret = suspend(1);
mutex_unlock(&apm_mutex);
} else {
as->suspend_wait = 1;
mutex_unlock(&apm_mutex);
wait_event_interruptible(apm_suspend_waitqueue,
as->suspend_wait == 0);
ret = as->suspend_result;
}
return ret;
default:
return -ENOTTY;
}
return 0;
}
static int do_release(struct inode *inode, struct file *filp)
{
struct apm_user *as;
as = filp->private_data;
if (check_apm_user(as, "release"))
return 0;
filp->private_data = NULL;
if (as->standbys_pending > 0) {
standbys_pending -= as->standbys_pending;
if (standbys_pending <= 0)
standby();
}
if (as->suspends_pending > 0) {
suspends_pending -= as->suspends_pending;
if (suspends_pending <= 0)
(void) suspend(1);
}
spin_lock(&user_list_lock);
if (user_list == as)
user_list = as->next;
else {
struct apm_user *as1;
for (as1 = user_list;
(as1 != NULL) && (as1->next != as);
as1 = as1->next)
;
if (as1 == NULL)
printk(KERN_ERR "apm: filp not in user list\n");
else
as1->next = as->next;
}
spin_unlock(&user_list_lock);
kfree(as);
return 0;
}
static int do_open(struct inode *inode, struct file *filp)
{
struct apm_user *as;
as = kmalloc(sizeof(*as), GFP_KERNEL);
if (as == NULL) {
printk(KERN_ERR "apm: cannot allocate struct of size %d bytes\n",
sizeof(*as));
return -ENOMEM;
}
as->magic = APM_BIOS_MAGIC;
as->event_tail = as->event_head = 0;
as->suspends_pending = as->standbys_pending = 0;
as->suspends_read = as->standbys_read = 0;
as->suser = capable(CAP_SYS_ADMIN);
as->writer = (filp->f_mode & FMODE_WRITE) == FMODE_WRITE;
as->reader = (filp->f_mode & FMODE_READ) == FMODE_READ;
spin_lock(&user_list_lock);
as->next = user_list;
user_list = as;
spin_unlock(&user_list_lock);
filp->private_data = as;
return 0;
}
static int proc_apm_show(struct seq_file *m, void *v)
{
unsigned short bx;
unsigned short cx;
unsigned short dx;
int error;
unsigned short ac_line_status = 0xff;
unsigned short battery_status = 0xff;
unsigned short battery_flag = 0xff;
int percentage = -1;
int time_units = -1;
char *units = "?";
if ((num_online_cpus() == 1) &&
!(error = apm_get_power_status(&bx, &cx, &dx))) {
ac_line_status = (bx >> 8) & 0xff;
battery_status = bx & 0xff;
if ((cx & 0xff) != 0xff)
percentage = cx & 0xff;
if (apm_info.connection_version > 0x100) {
battery_flag = (cx >> 8) & 0xff;
if (dx != 0xffff) {
units = (dx & 0x8000) ? "min" : "sec";
time_units = dx & 0x7fff;
}
}
}
seq_printf(m, "%s %d.%d 0x%02x 0x%02x 0x%02x 0x%02x %d%% %d %s\n",
driver_version,
(apm_info.bios.version >> 8) & 0xff,
apm_info.bios.version & 0xff,
apm_info.bios.flags,
ac_line_status,
battery_status,
battery_flag,
percentage,
time_units,
units);
return 0;
}
static int proc_apm_open(struct inode *inode, struct file *file)
{
return single_open(file, proc_apm_show, NULL);
}
static int apm(void *unused)
{
unsigned short bx;
unsigned short cx;
unsigned short dx;
int error;
char *power_stat;
char *bat_stat;
set_cpus_allowed_ptr(current, cpumask_of(0));
BUG_ON(smp_processor_id() != 0);
if (apm_info.connection_version == 0) {
apm_info.connection_version = apm_info.bios.version;
if (apm_info.connection_version > 0x100) {
if (apm_info.connection_version > 0x0102)
apm_info.connection_version = 0x0102;
error = apm_driver_version(&apm_info.connection_version);
if (error != APM_SUCCESS) {
apm_error("driver version", error);
apm_info.connection_version = 0x100;
}
}
}
if (debug)
printk(KERN_INFO "apm: Connection version %d.%d\n",
(apm_info.connection_version >> 8) & 0xff,
apm_info.connection_version & 0xff);
#ifdef CONFIG_APM_DO_ENABLE
if (apm_info.bios.flags & APM_BIOS_DISABLED) {
error = apm_enable_power_management(1);
if (error) {
apm_error("enable power management", error);
return -1;
}
}
#endif
if ((apm_info.bios.flags & APM_BIOS_DISENGAGED)
&& (apm_info.connection_version > 0x0100)) {
error = apm_engage_power_management(APM_DEVICE_ALL, 1);
if (error) {
apm_error("engage power management", error);
return -1;
}
}
if (debug && (num_online_cpus() == 1 || smp)) {
error = apm_get_power_status(&bx, &cx, &dx);
if (error)
printk(KERN_INFO "apm: power status not available\n");
else {
switch ((bx >> 8) & 0xff) {
case 0:
power_stat = "off line";
break;
case 1:
power_stat = "on line";
break;
case 2:
power_stat = "on backup power";
break;
default:
power_stat = "unknown";
break;
}
switch (bx & 0xff) {
case 0:
bat_stat = "high";
break;
case 1:
bat_stat = "low";
break;
case 2:
bat_stat = "critical";
break;
case 3:
bat_stat = "charging";
break;
default:
bat_stat = "unknown";
break;
}
printk(KERN_INFO
"apm: AC %s, battery status %s, battery life ",
power_stat, bat_stat);
if ((cx & 0xff) == 0xff)
printk("unknown\n");
else
printk("%d%%\n", cx & 0xff);
if (apm_info.connection_version > 0x100) {
printk(KERN_INFO
"apm: battery flag 0x%02x, battery life ",
(cx >> 8) & 0xff);
if (dx == 0xffff)
printk("unknown\n");
else
printk("%d %s\n", dx & 0x7fff,
(dx & 0x8000) ?
"minutes" : "seconds");
}
}
}
if (power_off)
pm_power_off = apm_power_off;
if (num_online_cpus() == 1 || smp) {
#if defined(CONFIG_APM_DISPLAY_BLANK) && defined(CONFIG_VT)
console_blank_hook = apm_console_blank;
#endif
apm_mainloop();
#if defined(CONFIG_APM_DISPLAY_BLANK) && defined(CONFIG_VT)
console_blank_hook = NULL;
#endif
}
return 0;
}
static int __init apm_setup(char *str)
{
int invert;
while ((str != NULL) && (*str != '\0')) {
if (strncmp(str, "off", 3) == 0)
apm_disabled = 1;
if (strncmp(str, "on", 2) == 0)
apm_disabled = 0;
if ((strncmp(str, "bounce-interval=", 16) == 0) ||
(strncmp(str, "bounce_interval=", 16) == 0))
bounce_interval = simple_strtol(str + 16, NULL, 0);
if ((strncmp(str, "idle-threshold=", 15) == 0) ||
(strncmp(str, "idle_threshold=", 15) == 0))
idle_threshold = simple_strtol(str + 15, NULL, 0);
if ((strncmp(str, "idle-period=", 12) == 0) ||
(strncmp(str, "idle_period=", 12) == 0))
idle_period = simple_strtol(str + 12, NULL, 0);
invert = (strncmp(str, "no-", 3) == 0) ||
(strncmp(str, "no_", 3) == 0);
if (invert)
str += 3;
if (strncmp(str, "debug", 5) == 0)
debug = !invert;
if ((strncmp(str, "power-off", 9) == 0) ||
(strncmp(str, "power_off", 9) == 0))
power_off = !invert;
if (strncmp(str, "smp", 3) == 0) {
smp = !invert;
idle_threshold = 100;
}
if ((strncmp(str, "allow-ints", 10) == 0) ||
(strncmp(str, "allow_ints", 10) == 0))
apm_info.allow_ints = !invert;
if ((strncmp(str, "broken-psr", 10) == 0) ||
(strncmp(str, "broken_psr", 10) == 0))
apm_info.get_power_status_broken = !invert;
if ((strncmp(str, "realmode-power-off", 18) == 0) ||
(strncmp(str, "realmode_power_off", 18) == 0))
apm_info.realmode_power_off = !invert;
str = strchr(str, ',');
if (str != NULL)
str += strspn(str, ", \t");
}
return 1;
}
static int __init print_if_true(const struct dmi_system_id *d)
{
printk("%s\n", d->ident);
return 0;
}
static int __init broken_ps2_resume(const struct dmi_system_id *d)
{
printk(KERN_INFO "%s machine detected. Mousepad Resume Bug "
"workaround hopefully not needed.\n", d->ident);
return 0;
}
static int __init set_realmode_power_off(const struct dmi_system_id *d)
{
if (apm_info.realmode_power_off == 0) {
apm_info.realmode_power_off = 1;
printk(KERN_INFO "%s bios detected. "
"Using realmode poweroff only.\n", d->ident);
}
return 0;
}
static int __init set_apm_ints(const struct dmi_system_id *d)
{
if (apm_info.allow_ints == 0) {
apm_info.allow_ints = 1;
printk(KERN_INFO "%s machine detected. "
"Enabling interrupts during APM calls.\n", d->ident);
}
return 0;
}
static int __init apm_is_horked(const struct dmi_system_id *d)
{
if (apm_info.disabled == 0) {
apm_info.disabled = 1;
printk(KERN_INFO "%s machine detected. "
"Disabling APM.\n", d->ident);
}
return 0;
}
static int __init apm_is_horked_d850md(const struct dmi_system_id *d)
{
if (apm_info.disabled == 0) {
apm_info.disabled = 1;
printk(KERN_INFO "%s machine detected. "
"Disabling APM.\n", d->ident);
printk(KERN_INFO "This bug is fixed in bios P15 which is available for\n");
printk(KERN_INFO "download from support.intel.com\n");
}
return 0;
}
static int __init apm_likes_to_melt(const struct dmi_system_id *d)
{
if (apm_info.forbid_idle == 0) {
apm_info.forbid_idle = 1;
printk(KERN_INFO "%s machine detected. "
"Disabling APM idle calls.\n", d->ident);
}
return 0;
}
static int __init broken_apm_power(const struct dmi_system_id *d)
{
apm_info.get_power_status_broken = 1;
printk(KERN_WARNING "BIOS strings suggest APM bugs, "
"disabling power status reporting.\n");
return 0;
}
static int __init swab_apm_power_in_minutes(const struct dmi_system_id *d)
{
apm_info.get_power_status_swabinminutes = 1;
printk(KERN_WARNING "BIOS strings suggest APM reports battery life "
"in minutes and wrong byte order.\n");
return 0;
}
static int __init apm_init(void)
{
struct desc_struct *gdt;
int err;
dmi_check_system(apm_dmi_table);
if (apm_info.bios.version == 0 || paravirt_enabled() || machine_is_olpc()) {
printk(KERN_INFO "apm: BIOS not found.\n");
return -ENODEV;
}
printk(KERN_INFO
"apm: BIOS version %d.%d Flags 0x%02x (Driver version %s)\n",
((apm_info.bios.version >> 8) & 0xff),
(apm_info.bios.version & 0xff),
apm_info.bios.flags,
driver_version);
if ((apm_info.bios.flags & APM_32_BIT_SUPPORT) == 0) {
printk(KERN_INFO "apm: no 32 bit BIOS support\n");
return -ENODEV;
}
if (allow_ints)
apm_info.allow_ints = 1;
if (broken_psr)
apm_info.get_power_status_broken = 1;
if (realmode_power_off)
apm_info.realmode_power_off = 1;
if (apm_disabled != -1)
apm_info.disabled = apm_disabled;
if (apm_info.bios.version == 0x001)
apm_info.bios.version = 0x100;
if (apm_info.bios.version < 0x102)
apm_info.bios.cseg_16_len = 0;
if (debug) {
printk(KERN_INFO "apm: entry %x:%x cseg16 %x dseg %x",
apm_info.bios.cseg, apm_info.bios.offset,
apm_info.bios.cseg_16, apm_info.bios.dseg);
if (apm_info.bios.version > 0x100)
printk(" cseg len %x, dseg len %x",
apm_info.bios.cseg_len,
apm_info.bios.dseg_len);
if (apm_info.bios.version > 0x101)
printk(" cseg16 len %x", apm_info.bios.cseg_16_len);
printk("\n");
}
if (apm_info.disabled) {
printk(KERN_NOTICE "apm: disabled on user request.\n");
return -ENODEV;
}
if ((num_online_cpus() > 1) && !power_off && !smp) {
printk(KERN_NOTICE "apm: disabled - APM is not SMP safe.\n");
apm_info.disabled = 1;
return -ENODEV;
}
if (!acpi_disabled) {
printk(KERN_NOTICE "apm: overridden by ACPI.\n");
apm_info.disabled = 1;
return -ENODEV;
}
apm_bios_entry.offset = apm_info.bios.offset;
apm_bios_entry.segment = APM_CS;
gdt = get_cpu_gdt_table(0);
set_desc_base(&gdt[APM_CS >> 3],
(unsigned long)__va((unsigned long)apm_info.bios.cseg << 4));
set_desc_base(&gdt[APM_CS_16 >> 3],
(unsigned long)__va((unsigned long)apm_info.bios.cseg_16 << 4));
set_desc_base(&gdt[APM_DS >> 3],
(unsigned long)__va((unsigned long)apm_info.bios.dseg << 4));
proc_create("apm", 0, NULL, &apm_file_ops);
kapmd_task = kthread_create(apm, NULL, "kapmd");
if (IS_ERR(kapmd_task)) {
printk(KERN_ERR "apm: disabled - Unable to start kernel "
"thread.\n");
err = PTR_ERR(kapmd_task);
kapmd_task = NULL;
remove_proc_entry("apm", NULL);
return err;
}
wake_up_process(kapmd_task);
if (num_online_cpus() > 1 && !smp) {
printk(KERN_NOTICE
"apm: disabled - APM is not SMP safe (power off active).\n");
return 0;
}
if (misc_register(&apm_device))
printk(KERN_WARNING "apm: Could not register misc device.\n");
if (HZ != 100)
idle_period = (idle_period * HZ) / 100;
if (idle_threshold < 100) {
original_pm_idle = pm_idle;
pm_idle = apm_cpu_idle;
set_pm_idle = 1;
}
return 0;
}
static void __exit apm_exit(void)
{
int error;
if (set_pm_idle) {
pm_idle = original_pm_idle;
kick_all_cpus_sync();
}
if (((apm_info.bios.flags & APM_BIOS_DISENGAGED) == 0)
&& (apm_info.connection_version > 0x0100)) {
error = apm_engage_power_management(APM_DEVICE_ALL, 0);
if (error)
apm_error("disengage power management", error);
}
misc_deregister(&apm_device);
remove_proc_entry("apm", NULL);
if (power_off)
pm_power_off = NULL;
if (kapmd_task) {
kthread_stop(kapmd_task);
kapmd_task = NULL;
}
}
