void range_lock_tree_init(struct range_lock_tree *tree)
{
tree->rlt_root = NULL;
tree->rlt_sequence = 0;
spin_lock_init(&tree->rlt_lock);
}
int range_lock_init(struct range_lock *lock, __u64 start, __u64 end)
{
int rc;
memset(&lock->rl_node, 0, sizeof(lock->rl_node));
if (end != LUSTRE_EOF)
end >>= PAGE_SHIFT;
rc = interval_set(&lock->rl_node, start >> PAGE_SHIFT, end);
if (rc)
return rc;
INIT_LIST_HEAD(&lock->rl_next_lock);
lock->rl_task = NULL;
lock->rl_lock_count = 0;
lock->rl_blocking_ranges = 0;
lock->rl_sequence = 0;
return rc;
}
static inline struct range_lock *next_lock(struct range_lock *lock)
{
return list_entry(lock->rl_next_lock.next, typeof(*lock), rl_next_lock);
}
static enum interval_iter range_unlock_cb(struct interval_node *node, void *arg)
{
struct range_lock *lock = arg;
struct range_lock *overlap = node2rangelock(node);
struct range_lock *iter;
list_for_each_entry(iter, &overlap->rl_next_lock, rl_next_lock) {
if (iter->rl_sequence > lock->rl_sequence) {
--iter->rl_blocking_ranges;
LASSERT(iter->rl_blocking_ranges > 0);
}
}
if (overlap->rl_sequence > lock->rl_sequence) {
--overlap->rl_blocking_ranges;
if (overlap->rl_blocking_ranges == 0)
wake_up_process(overlap->rl_task);
}
return INTERVAL_ITER_CONT;
}
void range_unlock(struct range_lock_tree *tree, struct range_lock *lock)
{
spin_lock(&tree->rlt_lock);
if (!list_empty(&lock->rl_next_lock)) {
struct range_lock *next;
if (interval_is_intree(&lock->rl_node)) {
next = next_lock(lock);
next->rl_lock_count = lock->rl_lock_count - 1;
interval_erase(&lock->rl_node, &tree->rlt_root);
interval_insert(&next->rl_node, &tree->rlt_root);
} else {
list_for_each_entry(next, &lock->rl_next_lock,
rl_next_lock) {
if (!interval_is_intree(&next->rl_node))
continue;
LASSERT(next->rl_lock_count > 0);
next->rl_lock_count--;
break;
}
}
list_del_init(&lock->rl_next_lock);
} else {
LASSERT(interval_is_intree(&lock->rl_node));
interval_erase(&lock->rl_node, &tree->rlt_root);
}
interval_search(tree->rlt_root, &lock->rl_node.in_extent,
range_unlock_cb, lock);
spin_unlock(&tree->rlt_lock);
}
static enum interval_iter range_lock_cb(struct interval_node *node, void *arg)
{
struct range_lock *lock = arg;
struct range_lock *overlap = node2rangelock(node);
lock->rl_blocking_ranges += overlap->rl_lock_count + 1;
return INTERVAL_ITER_CONT;
}
int range_lock(struct range_lock_tree *tree, struct range_lock *lock)
{
struct interval_node *node;
int rc = 0;
spin_lock(&tree->rlt_lock);
interval_search(tree->rlt_root, &lock->rl_node.in_extent,
range_lock_cb, lock);
node = interval_insert(&lock->rl_node, &tree->rlt_root);
if (node) {
struct range_lock *tmp = node2rangelock(node);
list_add_tail(&lock->rl_next_lock, &tmp->rl_next_lock);
tmp->rl_lock_count++;
}
lock->rl_sequence = ++tree->rlt_sequence;
while (lock->rl_blocking_ranges > 0) {
lock->rl_task = current;
__set_current_state(TASK_INTERRUPTIBLE);
spin_unlock(&tree->rlt_lock);
schedule();
if (signal_pending(current)) {
range_unlock(tree, lock);
rc = -EINTR;
goto out;
}
spin_lock(&tree->rlt_lock);
}
spin_unlock(&tree->rlt_lock);
out:
return rc;
}
