void btrfs_set_lock_blocking_rw(struct extent_buffer *eb, int rw)
{
if (eb->lock_nested && current->pid == eb->lock_owner)
return;
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
if (eb->lock_nested && current->pid == eb->lock_owner)
return;
if (rw == BTRFS_WRITE_LOCK_BLOCKING) {
BUG_ON(atomic_read(&eb->blocking_writers) != 1);
write_lock(&eb->lock);
WARN_ON(atomic_read(&eb->spinning_writers));
atomic_inc(&eb->spinning_writers);
if (atomic_dec_and_test(&eb->blocking_writers) &&
waitqueue_active(&eb->write_lock_wq))
wake_up(&eb->write_lock_wq);
} else if (rw == BTRFS_READ_LOCK_BLOCKING) {
BUG_ON(atomic_read(&eb->blocking_readers) == 0);
read_lock(&eb->lock);
atomic_inc(&eb->spinning_readers);
if (atomic_dec_and_test(&eb->blocking_readers) &&
waitqueue_active(&eb->read_lock_wq))
wake_up(&eb->read_lock_wq);
}
return;
}
void btrfs_tree_read_lock(struct extent_buffer *eb)
{
again:
BUG_ON(!atomic_read(&eb->blocking_writers) &&
current->pid == eb->lock_owner);
read_lock(&eb->lock);
if (atomic_read(&eb->blocking_writers) &&
current->pid == eb->lock_owner) {
BUG_ON(eb->lock_nested);
eb->lock_nested = 1;
read_unlock(&eb->lock);
return;
}
if (atomic_read(&eb->blocking_writers)) {
read_unlock(&eb->lock);
wait_event(eb->write_lock_wq,
atomic_read(&eb->blocking_writers) == 0);
goto again;
}
atomic_inc(&eb->read_locks);
atomic_inc(&eb->spinning_readers);
}
int btrfs_tree_read_lock_atomic(struct extent_buffer *eb)
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
int btrfs_try_tree_read_lock(struct extent_buffer *eb)
{
if (atomic_read(&eb->blocking_writers))
return 0;
if (!read_trylock(&eb->lock))
return 0;
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
eb->lock_owner = current->pid;
return 1;
}
void btrfs_tree_read_unlock(struct extent_buffer *eb)
{
if (eb->lock_nested && current->pid == eb->lock_owner) {
eb->lock_nested = 0;
return;
}
btrfs_assert_tree_read_locked(eb);
WARN_ON(atomic_read(&eb->spinning_readers) == 0);
atomic_dec(&eb->spinning_readers);
atomic_dec(&eb->read_locks);
read_unlock(&eb->lock);
}
void btrfs_tree_read_unlock_blocking(struct extent_buffer *eb)
{
if (eb->lock_nested && current->pid == eb->lock_owner) {
eb->lock_nested = 0;
return;
}
btrfs_assert_tree_read_locked(eb);
WARN_ON(atomic_read(&eb->blocking_readers) == 0);
if (atomic_dec_and_test(&eb->blocking_readers) &&
waitqueue_active(&eb->read_lock_wq))
wake_up(&eb->read_lock_wq);
atomic_dec(&eb->read_locks);
}
void btrfs_tree_lock(struct extent_buffer *eb)
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
eb->lock_owner = current->pid;
}
void btrfs_tree_unlock(struct extent_buffer *eb)
{
int blockers = atomic_read(&eb->blocking_writers);
BUG_ON(blockers > 1);
btrfs_assert_tree_locked(eb);
eb->lock_owner = 0;
atomic_dec(&eb->write_locks);
if (blockers) {
WARN_ON(atomic_read(&eb->spinning_writers));
atomic_dec(&eb->blocking_writers);
smp_mb();
if (waitqueue_active(&eb->write_lock_wq))
wake_up(&eb->write_lock_wq);
} else {
WARN_ON(atomic_read(&eb->spinning_writers) != 1);
atomic_dec(&eb->spinning_writers);
write_unlock(&eb->lock);
}
}
void btrfs_assert_tree_locked(struct extent_buffer *eb)
{
BUG_ON(!atomic_read(&eb->write_locks));
}
static void btrfs_assert_tree_read_locked(struct extent_buffer *eb)
{
BUG_ON(!atomic_read(&eb->read_locks));
}
