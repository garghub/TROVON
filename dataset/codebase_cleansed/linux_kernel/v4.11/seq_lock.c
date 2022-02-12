void snd_use_lock_sync_helper(snd_use_lock_t *lockp, const char *file, int line)
{
int warn_count = 5 * HZ;
if (atomic_read(lockp) < 0) {
pr_warn("ALSA: seq_lock: lock trouble [counter = %d] in %s:%d\n", atomic_read(lockp), file, line);
return;
}
while (atomic_read(lockp) > 0) {
if (warn_count-- == 0)
pr_warn("ALSA: seq_lock: waiting [%d left] in %s:%d\n", atomic_read(lockp), file, line);
schedule_timeout_uninterruptible(1);
}
}
