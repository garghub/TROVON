enum dlm_status dlmconvert_master(struct dlm_ctxt *dlm,
struct dlm_lock_resource *res,
struct dlm_lock *lock, int flags, int type)
{
int call_ast = 0, kick_thread = 0;
enum dlm_status status;
spin_lock(&res->spinlock);
__dlm_wait_on_lockres(res);
__dlm_lockres_reserve_ast(res);
res->state |= DLM_LOCK_RES_IN_PROGRESS;
status = __dlmconvert_master(dlm, res, lock, flags, type,
&call_ast, &kick_thread);
res->state &= ~DLM_LOCK_RES_IN_PROGRESS;
spin_unlock(&res->spinlock);
wake_up(&res->wq);
if (status != DLM_NORMAL && status != DLM_NOTQUEUED)
dlm_error(status);
if (call_ast)
dlm_queue_ast(dlm, lock);
else
dlm_lockres_release_ast(dlm, res);
if (kick_thread)
dlm_kick_thread(dlm, res);
return status;
}
static enum dlm_status __dlmconvert_master(struct dlm_ctxt *dlm,
struct dlm_lock_resource *res,
struct dlm_lock *lock, int flags,
int type, int *call_ast,
int *kick_thread)
{
enum dlm_status status = DLM_NORMAL;
struct list_head *iter;
struct dlm_lock *tmplock=NULL;
assert_spin_locked(&res->spinlock);
mlog(0, "type=%d, convert_type=%d, new convert_type=%d\n",
lock->ml.type, lock->ml.convert_type, type);
spin_lock(&lock->spinlock);
if (lock->ml.convert_type != LKM_IVMODE) {
mlog(ML_ERROR, "attempted to convert a lock with a lock "
"conversion pending\n");
status = DLM_DENIED;
goto unlock_exit;
}
if (!dlm_lock_on_list(&res->granted, lock)) {
mlog(ML_ERROR, "attempted to convert a lock not on grant "
"queue\n");
status = DLM_DENIED;
goto unlock_exit;
}
if (flags & LKM_VALBLK) {
switch (lock->ml.type) {
case LKM_EXMODE:
mlog(0, "will set lvb: converting %s->%s\n",
dlm_lock_mode_name(lock->ml.type),
dlm_lock_mode_name(type));
lock->lksb->flags |= DLM_LKSB_PUT_LVB;
break;
case LKM_PRMODE:
case LKM_NLMODE:
if (type > LKM_NLMODE) {
mlog(0, "will fetch new value into "
"lvb: converting %s->%s\n",
dlm_lock_mode_name(lock->ml.type),
dlm_lock_mode_name(type));
lock->lksb->flags |= DLM_LKSB_GET_LVB;
} else {
mlog(0, "will NOT fetch new value "
"into lvb: converting %s->%s\n",
dlm_lock_mode_name(lock->ml.type),
dlm_lock_mode_name(type));
flags &= ~(LKM_VALBLK);
}
break;
}
}
if (type <= lock->ml.type)
goto grant;
status = DLM_NORMAL;
list_for_each(iter, &res->granted) {
tmplock = list_entry(iter, struct dlm_lock, list);
if (tmplock == lock)
continue;
if (!dlm_lock_compatible(tmplock->ml.type, type))
goto switch_queues;
}
list_for_each(iter, &res->converting) {
tmplock = list_entry(iter, struct dlm_lock, list);
if (!dlm_lock_compatible(tmplock->ml.type, type))
goto switch_queues;
if (!dlm_lock_compatible(tmplock->ml.convert_type, type))
goto switch_queues;
}
grant:
mlog(0, "res %.*s, granting %s lock\n", res->lockname.len,
res->lockname.name, dlm_lock_mode_name(type));
lock->lksb->status = DLM_NORMAL;
if (lock->ml.node == dlm->node_num)
mlog(0, "doing in-place convert for nonlocal lock\n");
lock->ml.type = type;
if (lock->lksb->flags & DLM_LKSB_PUT_LVB)
memcpy(res->lvb, lock->lksb->lvb, DLM_LVB_LEN);
status = DLM_NORMAL;
*call_ast = 1;
goto unlock_exit;
switch_queues:
if (flags & LKM_NOQUEUE) {
mlog(0, "failed to convert NOQUEUE lock %.*s from "
"%d to %d...\n", res->lockname.len, res->lockname.name,
lock->ml.type, type);
status = DLM_NOTQUEUED;
goto unlock_exit;
}
mlog(0, "res %.*s, queueing...\n", res->lockname.len,
res->lockname.name);
lock->ml.convert_type = type;
list_move_tail(&lock->list, &res->converting);
unlock_exit:
spin_unlock(&lock->spinlock);
if (status == DLM_DENIED) {
__dlm_print_one_lock_resource(res);
}
if (status == DLM_NORMAL)
*kick_thread = 1;
return status;
}
void dlm_revert_pending_convert(struct dlm_lock_resource *res,
struct dlm_lock *lock)
{
list_move_tail(&lock->list, &res->granted);
lock->ml.convert_type = LKM_IVMODE;
lock->lksb->flags &= ~(DLM_LKSB_GET_LVB|DLM_LKSB_PUT_LVB);
}
enum dlm_status dlmconvert_remote(struct dlm_ctxt *dlm,
struct dlm_lock_resource *res,
struct dlm_lock *lock, int flags, int type)
{
enum dlm_status status;
mlog(0, "type=%d, convert_type=%d, busy=%d\n", lock->ml.type,
lock->ml.convert_type, res->state & DLM_LOCK_RES_IN_PROGRESS);
spin_lock(&res->spinlock);
if (res->state & DLM_LOCK_RES_RECOVERING) {
mlog(0, "bailing out early since res is RECOVERING "
"on secondary queue\n");
status = DLM_RECOVERING;
goto bail;
}
__dlm_wait_on_lockres(res);
if (lock->ml.convert_type != LKM_IVMODE) {
__dlm_print_one_lock_resource(res);
mlog(ML_ERROR, "converting a remote lock that is already "
"converting! (cookie=%u:%llu, conv=%d)\n",
dlm_get_lock_cookie_node(be64_to_cpu(lock->ml.cookie)),
dlm_get_lock_cookie_seq(be64_to_cpu(lock->ml.cookie)),
lock->ml.convert_type);
status = DLM_DENIED;
goto bail;
}
res->state |= DLM_LOCK_RES_IN_PROGRESS;
list_move_tail(&lock->list, &res->converting);
lock->convert_pending = 1;
lock->ml.convert_type = type;
if (flags & LKM_VALBLK) {
if (lock->ml.type == LKM_EXMODE) {
flags |= LKM_PUT_LVB;
lock->lksb->flags |= DLM_LKSB_PUT_LVB;
} else {
if (lock->ml.convert_type == LKM_NLMODE)
flags &= ~LKM_VALBLK;
else {
flags |= LKM_GET_LVB;
lock->lksb->flags |= DLM_LKSB_GET_LVB;
}
}
}
spin_unlock(&res->spinlock);
status = dlm_send_remote_convert_request(dlm, res, lock, flags, type);
spin_lock(&res->spinlock);
res->state &= ~DLM_LOCK_RES_IN_PROGRESS;
lock->convert_pending = 0;
if (status != DLM_NORMAL) {
if (status != DLM_NOTQUEUED)
dlm_error(status);
dlm_revert_pending_convert(res, lock);
}
bail:
spin_unlock(&res->spinlock);
wake_up(&res->wq);
return status;
}
static enum dlm_status dlm_send_remote_convert_request(struct dlm_ctxt *dlm,
struct dlm_lock_resource *res,
struct dlm_lock *lock, int flags, int type)
{
struct dlm_convert_lock convert;
int tmpret;
enum dlm_status ret;
int status = 0;
struct kvec vec[2];
size_t veclen = 1;
mlog(0, "%.*s\n", res->lockname.len, res->lockname.name);
memset(&convert, 0, sizeof(struct dlm_convert_lock));
convert.node_idx = dlm->node_num;
convert.requested_type = type;
convert.cookie = lock->ml.cookie;
convert.namelen = res->lockname.len;
convert.flags = cpu_to_be32(flags);
memcpy(convert.name, res->lockname.name, convert.namelen);
vec[0].iov_len = sizeof(struct dlm_convert_lock);
vec[0].iov_base = &convert;
if (flags & LKM_PUT_LVB) {
vec[1].iov_len = DLM_LVB_LEN;
vec[1].iov_base = lock->lksb->lvb;
veclen++;
}
tmpret = o2net_send_message_vec(DLM_CONVERT_LOCK_MSG, dlm->key,
vec, veclen, res->owner, &status);
if (tmpret >= 0) {
ret = status;
if (ret == DLM_RECOVERING) {
mlog(0, "node %u returned DLM_RECOVERING from convert "
"message!\n", res->owner);
} else if (ret == DLM_MIGRATING) {
mlog(0, "node %u returned DLM_MIGRATING from convert "
"message!\n", res->owner);
} else if (ret == DLM_FORWARD) {
mlog(0, "node %u returned DLM_FORWARD from convert "
"message!\n", res->owner);
} else if (ret != DLM_NORMAL && ret != DLM_NOTQUEUED)
dlm_error(ret);
} else {
mlog(ML_ERROR, "Error %d when sending message %u (key 0x%x) to "
"node %u\n", tmpret, DLM_CONVERT_LOCK_MSG, dlm->key,
res->owner);
if (dlm_is_host_down(tmpret)) {
dlm_wait_for_node_death(dlm, res->owner,
DLM_NODE_DEATH_WAIT_MAX);
ret = DLM_RECOVERING;
mlog(0, "node %u died so returning DLM_RECOVERING "
"from convert message!\n", res->owner);
} else {
ret = dlm_err_to_dlm_status(tmpret);
}
}
return ret;
}
int dlm_convert_lock_handler(struct o2net_msg *msg, u32 len, void *data,
void **ret_data)
{
struct dlm_ctxt *dlm = data;
struct dlm_convert_lock *cnv = (struct dlm_convert_lock *)msg->buf;
struct dlm_lock_resource *res = NULL;
struct list_head *iter;
struct dlm_lock *lock = NULL;
struct dlm_lockstatus *lksb;
enum dlm_status status = DLM_NORMAL;
u32 flags;
int call_ast = 0, kick_thread = 0, ast_reserved = 0, wake = 0;
if (!dlm_grab(dlm)) {
dlm_error(DLM_REJECTED);
return DLM_REJECTED;
}
mlog_bug_on_msg(!dlm_domain_fully_joined(dlm),
"Domain %s not fully joined!\n", dlm->name);
if (cnv->namelen > DLM_LOCKID_NAME_MAX) {
status = DLM_IVBUFLEN;
dlm_error(status);
goto leave;
}
flags = be32_to_cpu(cnv->flags);
if ((flags & (LKM_PUT_LVB|LKM_GET_LVB)) ==
(LKM_PUT_LVB|LKM_GET_LVB)) {
mlog(ML_ERROR, "both PUT and GET lvb specified\n");
status = DLM_BADARGS;
goto leave;
}
mlog(0, "lvb: %s\n", flags & LKM_PUT_LVB ? "put lvb" :
(flags & LKM_GET_LVB ? "get lvb" : "none"));
status = DLM_IVLOCKID;
res = dlm_lookup_lockres(dlm, cnv->name, cnv->namelen);
if (!res) {
dlm_error(status);
goto leave;
}
spin_lock(&res->spinlock);
status = __dlm_lockres_state_to_status(res);
if (status != DLM_NORMAL) {
spin_unlock(&res->spinlock);
dlm_error(status);
goto leave;
}
list_for_each(iter, &res->granted) {
lock = list_entry(iter, struct dlm_lock, list);
if (lock->ml.cookie == cnv->cookie &&
lock->ml.node == cnv->node_idx) {
dlm_lock_get(lock);
break;
}
lock = NULL;
}
spin_unlock(&res->spinlock);
if (!lock) {
status = DLM_IVLOCKID;
mlog(ML_ERROR, "did not find lock to convert on grant queue! "
"cookie=%u:%llu\n",
dlm_get_lock_cookie_node(be64_to_cpu(cnv->cookie)),
dlm_get_lock_cookie_seq(be64_to_cpu(cnv->cookie)));
dlm_print_one_lock_resource(res);
goto leave;
}
lksb = lock->lksb;
if (flags & LKM_PUT_LVB) {
BUG_ON(lksb->flags & (DLM_LKSB_PUT_LVB|DLM_LKSB_GET_LVB));
lksb->flags |= DLM_LKSB_PUT_LVB;
memcpy(&lksb->lvb[0], &cnv->lvb[0], DLM_LVB_LEN);
} else if (flags & LKM_GET_LVB) {
BUG_ON(lksb->flags & (DLM_LKSB_PUT_LVB|DLM_LKSB_GET_LVB));
lksb->flags |= DLM_LKSB_GET_LVB;
}
spin_lock(&res->spinlock);
status = __dlm_lockres_state_to_status(res);
if (status == DLM_NORMAL) {
__dlm_lockres_reserve_ast(res);
ast_reserved = 1;
res->state |= DLM_LOCK_RES_IN_PROGRESS;
status = __dlmconvert_master(dlm, res, lock, flags,
cnv->requested_type,
&call_ast, &kick_thread);
res->state &= ~DLM_LOCK_RES_IN_PROGRESS;
wake = 1;
}
spin_unlock(&res->spinlock);
if (wake)
wake_up(&res->wq);
if (status != DLM_NORMAL) {
if (status != DLM_NOTQUEUED)
dlm_error(status);
lksb->flags &= ~(DLM_LKSB_GET_LVB|DLM_LKSB_PUT_LVB);
}
leave:
if (lock)
dlm_lock_put(lock);
if (call_ast)
dlm_queue_ast(dlm, lock);
else if (ast_reserved)
dlm_lockres_release_ast(dlm, res);
if (kick_thread)
dlm_kick_thread(dlm, res);
if (res)
dlm_lockres_put(res);
dlm_put(dlm);
return status;
}
