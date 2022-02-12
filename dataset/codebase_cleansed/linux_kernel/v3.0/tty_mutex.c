void __lockfunc tty_lock(void)
{
struct task_struct *task = current;
WARN_ON(__big_tty_mutex_owner == task);
mutex_lock(&big_tty_mutex);
__big_tty_mutex_owner = task;
}
void __lockfunc tty_unlock(void)
{
struct task_struct *task = current;
WARN_ON(__big_tty_mutex_owner != task);
__big_tty_mutex_owner = NULL;
mutex_unlock(&big_tty_mutex);
}
