static void simple_thread_func(int cnt)
{
int array[6];
int len = cnt % 5;
int i;
set_current_state(TASK_INTERRUPTIBLE);
schedule_timeout(HZ);
for (i = 0; i < len; i++)
array[i] = i + 1;
array[i] = 0;
trace_foo_bar("hello", cnt, array, random_strings[len],
tsk_cpus_allowed(current));
trace_foo_with_template_simple("HELLO", cnt);
trace_foo_bar_with_cond("Some times print", cnt);
trace_foo_with_template_cond("prints other times", cnt);
trace_foo_with_template_print("I have to be different", cnt);
}
static int simple_thread(void *arg)
{
int cnt = 0;
while (!kthread_should_stop())
simple_thread_func(cnt++);
return 0;
}
static void simple_thread_func_fn(int cnt)
{
set_current_state(TASK_INTERRUPTIBLE);
schedule_timeout(HZ);
trace_foo_bar_with_fn("Look at me", cnt);
trace_foo_with_template_fn("Look at me too", cnt);
}
static int simple_thread_fn(void *arg)
{
int cnt = 0;
while (!kthread_should_stop())
simple_thread_func_fn(cnt++);
return 0;
}
int foo_bar_reg(void)
{
pr_info("Starting thread for foo_bar_fn\n");
mutex_lock(&thread_mutex);
simple_tsk_fn = kthread_run(simple_thread_fn, NULL, "event-sample-fn");
mutex_unlock(&thread_mutex);
return 0;
}
void foo_bar_unreg(void)
{
pr_info("Killing thread for foo_bar_fn\n");
mutex_lock(&thread_mutex);
if (simple_tsk_fn)
kthread_stop(simple_tsk_fn);
simple_tsk_fn = NULL;
mutex_unlock(&thread_mutex);
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
mutex_lock(&thread_mutex);
if (simple_tsk_fn)
kthread_stop(simple_tsk_fn);
simple_tsk_fn = NULL;
mutex_unlock(&thread_mutex);
}
