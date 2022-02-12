void __lockfunc tty_lock(struct tty_struct *tty)
{
if (tty->magic != TTY_MAGIC) {
pr_err("L Bad %p\n", tty);
WARN_ON(1);
return;
}
tty_kref_get(tty);
mutex_lock(&tty->legacy_mutex);
}
void __lockfunc tty_unlock(struct tty_struct *tty)
{
if (tty->magic != TTY_MAGIC) {
pr_err("U Bad %p\n", tty);
WARN_ON(1);
return;
}
mutex_unlock(&tty->legacy_mutex);
tty_kref_put(tty);
}
void __lockfunc tty_lock_slave(struct tty_struct *tty)
{
if (tty && tty != tty->link)
tty_lock(tty);
}
void __lockfunc tty_unlock_slave(struct tty_struct *tty)
{
if (tty && tty != tty->link)
tty_unlock(tty);
}
void tty_set_lock_subclass(struct tty_struct *tty)
{
lockdep_set_subclass(&tty->legacy_mutex, TTY_LOCK_SLAVE);
}
