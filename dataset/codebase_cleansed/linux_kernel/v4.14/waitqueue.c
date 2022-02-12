void purge_waiting_ops(void)
{
struct orangefs_kernel_op_s *op;
spin_lock(&orangefs_request_list_lock);
list_for_each_entry(op, &orangefs_request_list, list) {
gossip_debug(GOSSIP_WAIT_DEBUG,
"pvfs2-client-core: purging op tag %llu %s\n",
llu(op->tag),
get_opname_string(op));
set_op_state_purged(op);
gossip_debug(GOSSIP_DEV_DEBUG,
"%s: op:%s: op_state:%d: process:%s:\n",
__func__,
get_opname_string(op),
op->op_state,
current->comm);
}
spin_unlock(&orangefs_request_list_lock);
}
int service_operation(struct orangefs_kernel_op_s *op,
const char *op_name,
int flags)
{
long timeout = MAX_SCHEDULE_TIMEOUT;
int ret = 0;
DEFINE_WAIT(wait_entry);
op->upcall.tgid = current->tgid;
op->upcall.pid = current->pid;
retry_servicing:
op->downcall.status = 0;
gossip_debug(GOSSIP_WAIT_DEBUG,
"%s: %s op:%p: process:%s: pid:%d:\n",
__func__,
op_name,
op,
current->comm,
current->pid);
if (!(flags & ORANGEFS_OP_NO_MUTEX)) {
if (flags & ORANGEFS_OP_INTERRUPTIBLE)
ret = mutex_lock_interruptible(&orangefs_request_mutex);
else
ret = mutex_lock_killable(&orangefs_request_mutex);
if (ret < 0) {
op->downcall.status = ret;
gossip_debug(GOSSIP_WAIT_DEBUG,
"%s: service_operation interrupted.\n",
__func__);
return ret;
}
}
spin_lock(&orangefs_request_list_lock);
spin_lock(&op->lock);
set_op_state_waiting(op);
gossip_debug(GOSSIP_DEV_DEBUG,
"%s: op:%s: op_state:%d: process:%s:\n",
__func__,
get_opname_string(op),
op->op_state,
current->comm);
if (flags & ORANGEFS_OP_PRIORITY)
list_add(&op->list, &orangefs_request_list);
else
list_add_tail(&op->list, &orangefs_request_list);
spin_unlock(&op->lock);
wake_up_interruptible(&orangefs_request_list_waitq);
if (!__is_daemon_in_service()) {
gossip_debug(GOSSIP_WAIT_DEBUG,
"%s:client core is NOT in service.\n",
__func__);
if (op->upcall.type == ORANGEFS_VFS_OP_FS_UMOUNT)
timeout = 0;
else
timeout = op_timeout_secs * HZ;
}
spin_unlock(&orangefs_request_list_lock);
if (!(flags & ORANGEFS_OP_NO_MUTEX))
mutex_unlock(&orangefs_request_mutex);
ret = wait_for_matching_downcall(op, timeout,
flags & ORANGEFS_OP_INTERRUPTIBLE);
gossip_debug(GOSSIP_WAIT_DEBUG,
"%s: wait_for_matching_downcall returned %d for %p\n",
__func__,
ret,
op);
if (!ret) {
spin_unlock(&op->lock);
op->downcall.status =
orangefs_normalize_to_errno(op->downcall.status);
ret = op->downcall.status;
goto out;
}
if (ret == -ETIMEDOUT) {
gossip_err("%s: %s -- wait timed out; aborting attempt.\n",
__func__,
op_name);
}
orangefs_clean_up_interrupted_operation(op);
op->downcall.status = ret;
if (ret == -EAGAIN) {
op->attempts++;
timeout = op_timeout_secs * HZ;
gossip_debug(GOSSIP_WAIT_DEBUG,
"orangefs: tag %llu (%s)"
" -- operation to be retried (%d attempt)\n",
llu(op->tag),
op_name,
op->attempts);
if (!op->uses_shared_memory)
goto retry_servicing;
}
out:
gossip_debug(GOSSIP_WAIT_DEBUG,
"%s: %s returning: %d for %p.\n",
__func__,
op_name,
ret,
op);
return ret;
}
bool orangefs_cancel_op_in_progress(struct orangefs_kernel_op_s *op)
{
u64 tag = op->tag;
if (!op_state_in_progress(op))
return false;
op->slot_to_free = op->upcall.req.io.buf_index;
memset(&op->upcall, 0, sizeof(op->upcall));
memset(&op->downcall, 0, sizeof(op->downcall));
op->upcall.type = ORANGEFS_VFS_OP_CANCEL;
op->upcall.req.cancel.op_tag = tag;
op->downcall.type = ORANGEFS_VFS_OP_INVALID;
op->downcall.status = -1;
orangefs_new_tag(op);
spin_lock(&orangefs_request_list_lock);
if (!__is_daemon_in_service()) {
spin_unlock(&orangefs_request_list_lock);
return false;
}
spin_lock(&op->lock);
set_op_state_waiting(op);
gossip_debug(GOSSIP_DEV_DEBUG,
"%s: op:%s: op_state:%d: process:%s:\n",
__func__,
get_opname_string(op),
op->op_state,
current->comm);
list_add(&op->list, &orangefs_request_list);
spin_unlock(&op->lock);
spin_unlock(&orangefs_request_list_lock);
gossip_debug(GOSSIP_WAIT_DEBUG,
"Attempting ORANGEFS operation cancellation of tag %llu\n",
llu(tag));
return true;
}
static void
orangefs_clean_up_interrupted_operation(struct orangefs_kernel_op_s *op)
{
op->op_state |= OP_VFS_STATE_GIVEN_UP;
if (list_empty(&op->list)) {
BUG_ON(op_state_serviced(op));
spin_unlock(&op->lock);
wait_for_completion(&op->waitq);
} else if (op_state_waiting(op)) {
spin_unlock(&op->lock);
spin_lock(&orangefs_request_list_lock);
list_del_init(&op->list);
spin_unlock(&orangefs_request_list_lock);
gossip_debug(GOSSIP_WAIT_DEBUG,
"Interrupted: Removed op %p from request_list\n",
op);
} else if (op_state_in_progress(op)) {
spin_unlock(&op->lock);
spin_lock(&orangefs_htable_ops_in_progress_lock);
list_del_init(&op->list);
spin_unlock(&orangefs_htable_ops_in_progress_lock);
gossip_debug(GOSSIP_WAIT_DEBUG,
"Interrupted: Removed op %p"
" from htable_ops_in_progress\n",
op);
} else {
spin_unlock(&op->lock);
gossip_err("interrupted operation is in a weird state 0x%x\n",
op->op_state);
}
reinit_completion(&op->waitq);
}
static int wait_for_matching_downcall(struct orangefs_kernel_op_s *op,
long timeout,
bool interruptible)
{
long n;
if (interruptible)
n = wait_for_completion_interruptible_timeout(&op->waitq,
timeout);
else
n = wait_for_completion_killable_timeout(&op->waitq, timeout);
spin_lock(&op->lock);
if (op_state_serviced(op))
return 0;
if (unlikely(n < 0)) {
gossip_debug(GOSSIP_WAIT_DEBUG,
"%s: operation interrupted, tag %llu, %p\n",
__func__,
llu(op->tag),
op);
return -EINTR;
}
if (op_state_purged(op)) {
gossip_debug(GOSSIP_WAIT_DEBUG,
"%s: operation purged, tag %llu, %p, %d\n",
__func__,
llu(op->tag),
op,
op->attempts);
return (op->attempts < ORANGEFS_PURGE_RETRY_COUNT) ?
-EAGAIN :
-EIO;
}
gossip_debug(GOSSIP_WAIT_DEBUG,
"%s: operation timed out, tag %llu, %p, %d)\n",
__func__,
llu(op->tag),
op,
op->attempts);
return -ETIMEDOUT;
}
