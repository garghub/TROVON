static void __lockfunc tty_lock_nested(struct tty_struct *tty,
unsigned int subclass)
{
if (tty->magic != TTY_MAGIC) {
printk(KERN_ERR "L Bad %p\n", tty);
WARN_ON(1);
return;
}
tty_kref_get(tty);
mutex_lock_nested(&tty->legacy_mutex, subclass);
}
void __lockfunc tty_lock(struct tty_struct *tty)
{
return tty_lock_nested(tty, TTY_MUTEX_NORMAL);
}
void __lockfunc tty_unlock(struct tty_struct *tty)
{
if (tty->magic != TTY_MAGIC) {
printk(KERN_ERR "U Bad %p\n", tty);
WARN_ON(1);
return;
}
mutex_unlock(&tty->legacy_mutex);
tty_kref_put(tty);
}
void __lockfunc tty_lock_pair(struct tty_struct *tty,
struct tty_struct *tty2)
{
if (tty < tty2) {
tty_lock(tty);
tty_lock_nested(tty2, TTY_MUTEX_NESTED);
} else {
if (tty2 && tty2 != tty)
tty_lock(tty2);
tty_lock_nested(tty, TTY_MUTEX_NESTED);
}
}
void __lockfunc tty_unlock_pair(struct tty_struct *tty,
struct tty_struct *tty2)
{
tty_unlock(tty);
if (tty2 && tty2 != tty)
tty_unlock(tty2);
}
