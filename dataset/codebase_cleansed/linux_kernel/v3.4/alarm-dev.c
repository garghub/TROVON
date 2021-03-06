static long alarm_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
int rv = 0;
unsigned long flags;
struct timespec new_alarm_time;
struct timespec new_rtc_time;
struct timespec tmp_time;
enum android_alarm_type alarm_type = ANDROID_ALARM_IOCTL_TO_TYPE(cmd);
uint32_t alarm_type_mask = 1U << alarm_type;
if (alarm_type >= ANDROID_ALARM_TYPE_COUNT)
return -EINVAL;
if (ANDROID_ALARM_BASE_CMD(cmd) != ANDROID_ALARM_GET_TIME(0)) {
if ((file->f_flags & O_ACCMODE) == O_RDONLY)
return -EPERM;
if (file->private_data == NULL &&
cmd != ANDROID_ALARM_SET_RTC) {
spin_lock_irqsave(&alarm_slock, flags);
if (alarm_opened) {
spin_unlock_irqrestore(&alarm_slock, flags);
return -EBUSY;
}
alarm_opened = 1;
file->private_data = (void *)1;
spin_unlock_irqrestore(&alarm_slock, flags);
}
}
switch (ANDROID_ALARM_BASE_CMD(cmd)) {
case ANDROID_ALARM_CLEAR(0):
spin_lock_irqsave(&alarm_slock, flags);
pr_alarm(IO, "alarm %d clear\n", alarm_type);
android_alarm_try_to_cancel(&alarms[alarm_type]);
if (alarm_pending) {
alarm_pending &= ~alarm_type_mask;
if (!alarm_pending && !wait_pending)
wake_unlock(&alarm_wake_lock);
}
alarm_enabled &= ~alarm_type_mask;
spin_unlock_irqrestore(&alarm_slock, flags);
break;
case ANDROID_ALARM_SET_OLD:
case ANDROID_ALARM_SET_AND_WAIT_OLD:
if (get_user(new_alarm_time.tv_sec, (int __user *)arg)) {
rv = -EFAULT;
goto err1;
}
new_alarm_time.tv_nsec = 0;
goto from_old_alarm_set;
case ANDROID_ALARM_SET_AND_WAIT(0):
case ANDROID_ALARM_SET(0):
if (copy_from_user(&new_alarm_time, (void __user *)arg,
sizeof(new_alarm_time))) {
rv = -EFAULT;
goto err1;
}
from_old_alarm_set:
spin_lock_irqsave(&alarm_slock, flags);
pr_alarm(IO, "alarm %d set %ld.%09ld\n", alarm_type,
new_alarm_time.tv_sec, new_alarm_time.tv_nsec);
alarm_enabled |= alarm_type_mask;
android_alarm_start_range(&alarms[alarm_type],
timespec_to_ktime(new_alarm_time),
timespec_to_ktime(new_alarm_time));
spin_unlock_irqrestore(&alarm_slock, flags);
if (ANDROID_ALARM_BASE_CMD(cmd) != ANDROID_ALARM_SET_AND_WAIT(0)
&& cmd != ANDROID_ALARM_SET_AND_WAIT_OLD)
break;
case ANDROID_ALARM_WAIT:
spin_lock_irqsave(&alarm_slock, flags);
pr_alarm(IO, "alarm wait\n");
if (!alarm_pending && wait_pending) {
wake_unlock(&alarm_wake_lock);
wait_pending = 0;
}
spin_unlock_irqrestore(&alarm_slock, flags);
rv = wait_event_interruptible(alarm_wait_queue, alarm_pending);
if (rv)
goto err1;
spin_lock_irqsave(&alarm_slock, flags);
rv = alarm_pending;
wait_pending = 1;
alarm_pending = 0;
spin_unlock_irqrestore(&alarm_slock, flags);
break;
case ANDROID_ALARM_SET_RTC:
if (copy_from_user(&new_rtc_time, (void __user *)arg,
sizeof(new_rtc_time))) {
rv = -EFAULT;
goto err1;
}
rv = android_alarm_set_rtc(new_rtc_time);
spin_lock_irqsave(&alarm_slock, flags);
alarm_pending |= ANDROID_ALARM_TIME_CHANGE_MASK;
wake_up(&alarm_wait_queue);
spin_unlock_irqrestore(&alarm_slock, flags);
if (rv < 0)
goto err1;
break;
case ANDROID_ALARM_GET_TIME(0):
switch (alarm_type) {
case ANDROID_ALARM_RTC_WAKEUP:
case ANDROID_ALARM_RTC:
getnstimeofday(&tmp_time);
break;
case ANDROID_ALARM_ELAPSED_REALTIME_WAKEUP:
case ANDROID_ALARM_ELAPSED_REALTIME:
tmp_time =
ktime_to_timespec(alarm_get_elapsed_realtime());
break;
case ANDROID_ALARM_TYPE_COUNT:
case ANDROID_ALARM_SYSTEMTIME:
ktime_get_ts(&tmp_time);
break;
}
if (copy_to_user((void __user *)arg, &tmp_time,
sizeof(tmp_time))) {
rv = -EFAULT;
goto err1;
}
break;
default:
rv = -EINVAL;
goto err1;
}
err1:
return rv;
}
static int alarm_open(struct inode *inode, struct file *file)
{
file->private_data = NULL;
return 0;
}
static int alarm_release(struct inode *inode, struct file *file)
{
int i;
unsigned long flags;
spin_lock_irqsave(&alarm_slock, flags);
if (file->private_data != 0) {
for (i = 0; i < ANDROID_ALARM_TYPE_COUNT; i++) {
uint32_t alarm_type_mask = 1U << i;
if (alarm_enabled & alarm_type_mask) {
pr_alarm(INFO, "alarm_release: clear alarm, "
"pending %d\n",
!!(alarm_pending & alarm_type_mask));
alarm_enabled &= ~alarm_type_mask;
}
spin_unlock_irqrestore(&alarm_slock, flags);
android_alarm_cancel(&alarms[i]);
spin_lock_irqsave(&alarm_slock, flags);
}
if (alarm_pending | wait_pending) {
if (alarm_pending)
pr_alarm(INFO, "alarm_release: clear "
"pending alarms %x\n", alarm_pending);
wake_unlock(&alarm_wake_lock);
wait_pending = 0;
alarm_pending = 0;
}
alarm_opened = 0;
}
spin_unlock_irqrestore(&alarm_slock, flags);
return 0;
}
static void alarm_triggered(struct android_alarm *alarm)
{
unsigned long flags;
uint32_t alarm_type_mask = 1U << alarm->type;
pr_alarm(INT, "alarm_triggered type %d\n", alarm->type);
spin_lock_irqsave(&alarm_slock, flags);
if (alarm_enabled & alarm_type_mask) {
wake_lock_timeout(&alarm_wake_lock, 5 * HZ);
alarm_enabled &= ~alarm_type_mask;
alarm_pending |= alarm_type_mask;
wake_up(&alarm_wait_queue);
}
spin_unlock_irqrestore(&alarm_slock, flags);
}
static int __init alarm_dev_init(void)
{
int err;
int i;
err = misc_register(&alarm_device);
if (err)
return err;
for (i = 0; i < ANDROID_ALARM_TYPE_COUNT; i++)
android_alarm_init(&alarms[i], i, alarm_triggered);
wake_lock_init(&alarm_wake_lock, WAKE_LOCK_SUSPEND, "alarm");
return 0;
}
static void __exit alarm_dev_exit(void)
{
misc_deregister(&alarm_device);
wake_lock_destroy(&alarm_wake_lock);
}
