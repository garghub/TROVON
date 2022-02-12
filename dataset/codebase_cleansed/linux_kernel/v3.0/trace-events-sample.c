static void simple_thread_func(int cnt)
{
set_current_state(TASK_INTERRUPTIBLE);
schedule_timeout(HZ);
trace_foo_bar("hello", cnt);
}
static int simple_thread(void *arg)
{
int cnt = 0;
while (!kthread_should_stop())
simple_thread_func(cnt++);
return 0;
}
static int __init trace_event_init(void)
{
simple_tsk = kthread_run(simple_thread, NULL, "event-sample");
if (IS_ERR(simple_tsk))
return -1;
return 0;
}
static void __exit trace_event_exit(void)
{
kthread_stop(simple_tsk);
}
