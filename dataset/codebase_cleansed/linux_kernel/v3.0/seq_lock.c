void snd_use_lock_sync_helper(snd_use_lock_t *lockp, const char *file, int line)
{
int max_count = 5 * HZ;
if (atomic_read(lockp) < 0) {
printk(KERN_WARNING "seq_lock: lock trouble [counter = %d] in %s:%d\n", atomic_read(lockp), file, line);
return;
}
while (atomic_read(lockp) > 0) {
if (max_count == 0) {
snd_printk(KERN_WARNING "seq_lock: timeout [%d left] in %s:%d\n", atomic_read(lockp), file, line);
break;
}
schedule_timeout_uninterruptible(1);
max_count--;
}
}
