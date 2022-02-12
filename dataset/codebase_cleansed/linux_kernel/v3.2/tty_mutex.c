void __lockfunc tty_lock(void)
{
mutex_lock(&big_tty_mutex);
}
void __lockfunc tty_unlock(void)
{
mutex_unlock(&big_tty_mutex);
}
