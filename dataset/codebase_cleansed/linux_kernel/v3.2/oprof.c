int oprofile_setup(void)
{
int err;
mutex_lock(&start_mutex);
if ((err = alloc_cpu_buffers()))
goto out;
if ((err = alloc_event_buffer()))
goto out1;
if (oprofile_ops.setup && (err = oprofile_ops.setup()))
goto out2;
if (oprofile_ops.sync_start) {
int sync_ret = oprofile_ops.sync_start();
switch (sync_ret) {
case 0:
goto post_sync;
case 1:
goto do_generic;
case -1:
goto out3;
default:
goto out3;
}
}
do_generic:
if ((err = sync_start()))
goto out3;
post_sync:
is_setup = 1;
mutex_unlock(&start_mutex);
return 0;
out3:
if (oprofile_ops.shutdown)
oprofile_ops.shutdown();
out2:
free_event_buffer();
out1:
free_cpu_buffers();
out:
mutex_unlock(&start_mutex);
return err;
}
static void start_switch_worker(void)
{
if (oprofile_ops.switch_events)
schedule_delayed_work(&switch_work, oprofile_time_slice);
}
static void stop_switch_worker(void)
{
cancel_delayed_work_sync(&switch_work);
}
static void switch_worker(struct work_struct *work)
{
if (oprofile_ops.switch_events())
return;
atomic_inc(&oprofile_stats.multiplex_counter);
start_switch_worker();
}
int oprofile_set_timeout(unsigned long val_msec)
{
int err = 0;
unsigned long time_slice;
mutex_lock(&start_mutex);
if (oprofile_started) {
err = -EBUSY;
goto out;
}
if (!oprofile_ops.switch_events) {
err = -EINVAL;
goto out;
}
time_slice = msecs_to_jiffies(val_msec);
if (time_slice == MAX_JIFFY_OFFSET) {
err = -EINVAL;
goto out;
}
oprofile_time_slice = time_slice;
out:
mutex_unlock(&start_mutex);
return err;
}
static inline void start_switch_worker(void) { }
static inline void stop_switch_worker(void) { }
int oprofile_start(void)
{
int err = -EINVAL;
mutex_lock(&start_mutex);
if (!is_setup)
goto out;
err = 0;
if (oprofile_started)
goto out;
oprofile_reset_stats();
if ((err = oprofile_ops.start()))
goto out;
start_switch_worker();
oprofile_started = 1;
out:
mutex_unlock(&start_mutex);
return err;
}
void oprofile_stop(void)
{
mutex_lock(&start_mutex);
if (!oprofile_started)
goto out;
oprofile_ops.stop();
oprofile_started = 0;
stop_switch_worker();
wake_up_buffer_waiter();
out:
mutex_unlock(&start_mutex);
}
void oprofile_shutdown(void)
{
mutex_lock(&start_mutex);
if (oprofile_ops.sync_stop) {
int sync_ret = oprofile_ops.sync_stop();
switch (sync_ret) {
case 0:
goto post_sync;
case 1:
goto do_generic;
default:
goto post_sync;
}
}
do_generic:
sync_stop();
post_sync:
if (oprofile_ops.shutdown)
oprofile_ops.shutdown();
is_setup = 0;
free_event_buffer();
free_cpu_buffers();
mutex_unlock(&start_mutex);
}
int oprofile_set_ulong(unsigned long *addr, unsigned long val)
{
int err = -EBUSY;
mutex_lock(&start_mutex);
if (!oprofile_started) {
*addr = val;
err = 0;
}
mutex_unlock(&start_mutex);
return err;
}
static int __init oprofile_init(void)
{
int err;
err = oprofile_arch_init(&oprofile_ops);
timer_mode = err || timer;
if (timer_mode) {
if (!err)
oprofile_arch_exit();
err = oprofile_timer_init(&oprofile_ops);
if (err)
return err;
}
err = oprofilefs_register();
if (!err)
return 0;
if (timer_mode)
oprofile_timer_exit();
else
oprofile_arch_exit();
return err;
}
static void __exit oprofile_exit(void)
{
oprofilefs_unregister();
if (timer_mode)
oprofile_timer_exit();
else
oprofile_arch_exit();
}
