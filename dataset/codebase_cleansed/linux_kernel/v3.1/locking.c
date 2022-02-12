void btrfs_set_lock_blocking_rw(struct extent_buffer *eb, int rw)
{
if (rw == BTRFS_WRITE_LOCK) {
if (atomic_read(&eb->blocking_writers) == 0) {
WARN_ON(atomic_read(&eb->spinning_writers) != 1);
atomic_dec(&eb->spinning_writers);
btrfs_assert_tree_locked(eb);
atomic_inc(&eb->blocking_writers);
write_unlock(&eb->lock);
}
} else if (rw == BTRFS_READ_LOCK) {
btrfs_assert_tree_read_locked(eb);
atomic_inc(&eb->blocking_readers);
WARN_ON(atomic_read(&eb->spinning_readers) == 0);
atomic_dec(&eb->spinning_readers);
read_unlock(&eb->lock);
}
return;
}
void btrfs_clear_lock_blocking_rw(struct extent_buffer *eb, int rw)
{
if (rw == BTRFS_WRITE_LOCK_BLOCKING) {
BUG_ON(atomic_read(&eb->blocking_writers) != 1);
write_lock(&eb->lock);
WARN_ON(atomic_read(&eb->spinning_writers));
atomic_inc(&eb->spinning_writers);
if (atomic_dec_and_test(&eb->blocking_writers))
wake_up(&eb->write_lock_wq);
} else if (rw == BTRFS_READ_LOCK_BLOCKING) {
BUG_ON(atomic_read(&eb->blocking_readers) == 0);
read_lock(&eb->lock);
atomic_inc(&eb->spinning_readers);
if (atomic_dec_and_test(&eb->blocking_readers))
wake_up(&eb->read_lock_wq);
}
return;
}
void btrfs_tree_read_lock(struct extent_buffer *eb)
{
again:
wait_event(eb->write_lock_wq, atomic_read(&eb->blocking_writers) == 0);
read_lock(&eb->lock);
if (atomic_read(&eb->blocking_writers)) {
read_unlock(&eb->lock);
wait_event(eb->write_lock_wq,
atomic_read(&eb->blocking_writers) == 0);
goto again;
}
atomic_inc(&eb->read_locks);
atomic_inc(&eb->spinning_readers);
}
int btrfs_try_tree_read_lock(struct extent_buffer *eb)
{
if (atomic_read(&eb->blocking_writers))
return 0;
read_lock(&eb->lock);
if (atomic_read(&eb->blocking_writers)) {
read_unlock(&eb->lock);
return 0;
}
atomic_inc(&eb->read_locks);
atomic_inc(&eb->spinning_readers);
return 1;
}
int btrfs_try_tree_write_lock(struct extent_buffer *eb)
{
if (atomic_read(&eb->blocking_writers) ||
atomic_read(&eb->blocking_readers))
return 0;
write_lock(&eb->lock);
if (atomic_read(&eb->blocking_writers) ||
atomic_read(&eb->blocking_readers)) {
write_unlock(&eb->lock);
return 0;
}
atomic_inc(&eb->write_locks);
atomic_inc(&eb->spinning_writers);
return 1;
}
void btrfs_tree_read_unlock(struct extent_buffer *eb)
{
btrfs_assert_tree_read_locked(eb);
WARN_ON(atomic_read(&eb->spinning_readers) == 0);
atomic_dec(&eb->spinning_readers);
atomic_dec(&eb->read_locks);
read_unlock(&eb->lock);
}
void btrfs_tree_read_unlock_blocking(struct extent_buffer *eb)
{
btrfs_assert_tree_read_locked(eb);
WARN_ON(atomic_read(&eb->blocking_readers) == 0);
if (atomic_dec_and_test(&eb->blocking_readers))
wake_up(&eb->read_lock_wq);
atomic_dec(&eb->read_locks);
}
int btrfs_tree_lock(struct extent_buffer *eb)
{
again:
wait_event(eb->read_lock_wq, atomic_read(&eb->blocking_readers) == 0);
wait_event(eb->write_lock_wq, atomic_read(&eb->blocking_writers) == 0);
write_lock(&eb->lock);
if (atomic_read(&eb->blocking_readers)) {
write_unlock(&eb->lock);
wait_event(eb->read_lock_wq,
atomic_read(&eb->blocking_readers) == 0);
goto again;
}
if (atomic_read(&eb->blocking_writers)) {
write_unlock(&eb->lock);
wait_event(eb->write_lock_wq,
atomic_read(&eb->blocking_writers) == 0);
goto again;
}
WARN_ON(atomic_read(&eb->spinning_writers));
atomic_inc(&eb->spinning_writers);
atomic_inc(&eb->write_locks);
return 0;
}
int btrfs_tree_unlock(struct extent_buffer *eb)
{
int blockers = atomic_read(&eb->blocking_writers);
BUG_ON(blockers > 1);
btrfs_assert_tree_locked(eb);
atomic_dec(&eb->write_locks);
if (blockers) {
WARN_ON(atomic_read(&eb->spinning_writers));
atomic_dec(&eb->blocking_writers);
smp_wmb();
wake_up(&eb->write_lock_wq);
} else {
WARN_ON(atomic_read(&eb->spinning_writers) != 1);
atomic_dec(&eb->spinning_writers);
write_unlock(&eb->lock);
}
return 0;
}
void btrfs_assert_tree_locked(struct extent_buffer *eb)
{
BUG_ON(!atomic_read(&eb->write_locks));
}
void btrfs_assert_tree_read_locked(struct extent_buffer *eb)
{
BUG_ON(!atomic_read(&eb->read_locks));
}
