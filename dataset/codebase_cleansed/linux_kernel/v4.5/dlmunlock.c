static enum dlm_status dlmunlock_common(struct dlm_ctxt *dlm,
struct dlm_lock_resource *res,
struct dlm_lock *lock,
struct dlm_lockstatus *lksb,
int flags, int *call_ast,
int master_node)
{
enum dlm_status status;
int actions = 0;
int in_use;
u8 owner;
mlog(0, "master_node = %d, valblk = %d\n", master_node,
flags & LKM_VALBLK);
if (master_node)
BUG_ON(res->owner != dlm->node_num);
else
BUG_ON(res->owner == dlm->node_num);
spin_lock(&dlm->ast_lock);
in_use = !list_empty(&lock->ast_list);
spin_unlock(&dlm->ast_lock);
if (in_use && !(flags & LKM_CANCEL)) {
mlog(ML_ERROR, "lockres %.*s: Someone is calling dlmunlock "
"while waiting for an ast!", res->lockname.len,
res->lockname.name);
return DLM_BADPARAM;
}
spin_lock(&res->spinlock);
if (res->state & DLM_LOCK_RES_IN_PROGRESS) {
if (master_node && !(flags & LKM_CANCEL)) {
mlog(ML_ERROR, "lockres in progress!\n");
spin_unlock(&res->spinlock);
return DLM_FORWARD;
}
__dlm_wait_on_lockres(res);
res->state |= DLM_LOCK_RES_IN_PROGRESS;
}
spin_lock(&lock->spinlock);
if (res->state & DLM_LOCK_RES_RECOVERING) {
status = DLM_RECOVERING;
goto leave;
}
if (res->state & DLM_LOCK_RES_MIGRATING) {
status = DLM_MIGRATING;
goto leave;
}
if (flags & LKM_CANCEL)
status = dlm_get_cancel_actions(dlm, res, lock, lksb, &actions);
else
status = dlm_get_unlock_actions(dlm, res, lock, lksb, &actions);
if (status != DLM_NORMAL && (status != DLM_CANCELGRANT || !master_node))
goto leave;
if (flags & LKM_VALBLK) {
if (master_node)
memcpy(res->lvb, lksb->lvb, DLM_LVB_LEN);
else
flags |= LKM_PUT_LVB;
}
if (!master_node) {
owner = res->owner;
if (flags & LKM_CANCEL)
lock->cancel_pending = 1;
else
lock->unlock_pending = 1;
spin_unlock(&lock->spinlock);
spin_unlock(&res->spinlock);
status = dlm_send_remote_unlock_request(dlm, res, lock, lksb,
flags, owner);
spin_lock(&res->spinlock);
spin_lock(&lock->spinlock);
if (status == DLM_CANCELGRANT) {
actions &= ~(DLM_UNLOCK_REMOVE_LOCK|
DLM_UNLOCK_REGRANT_LOCK|
DLM_UNLOCK_CLEAR_CONVERT_TYPE);
} else if (status == DLM_RECOVERING ||
status == DLM_MIGRATING ||
status == DLM_FORWARD ||
status == DLM_NOLOCKMGR
) {
mlog(0, "%s:%.*s: clearing actions, %s\n",
dlm->name, res->lockname.len,
res->lockname.name,
status==DLM_RECOVERING?"recovering":
(status==DLM_MIGRATING?"migrating":
(status == DLM_FORWARD ? "forward" :
"nolockmanager")));
actions = 0;
}
if (flags & LKM_CANCEL)
lock->cancel_pending = 0;
else
lock->unlock_pending = 0;
}
dlm_lock_get(lock);
if (actions & DLM_UNLOCK_REMOVE_LOCK) {
list_del_init(&lock->list);
dlm_lock_put(lock);
}
if (actions & DLM_UNLOCK_REGRANT_LOCK) {
dlm_lock_get(lock);
list_add_tail(&lock->list, &res->granted);
}
if (actions & DLM_UNLOCK_CLEAR_CONVERT_TYPE) {
mlog(0, "clearing convert_type at %smaster node\n",
master_node ? "" : "non-");
lock->ml.convert_type = LKM_IVMODE;
}
dlm_lock_put(lock);
leave:
res->state &= ~DLM_LOCK_RES_IN_PROGRESS;
if (!dlm_lock_on_list(&res->converting, lock))
BUG_ON(lock->ml.convert_type != LKM_IVMODE);
else
BUG_ON(lock->ml.convert_type == LKM_IVMODE);
spin_unlock(&lock->spinlock);
spin_unlock(&res->spinlock);
wake_up(&res->wq);
if (actions & DLM_UNLOCK_FREE_LOCK) {
BUG_ON(!(actions & DLM_UNLOCK_REMOVE_LOCK));
mlog(0, "lock %u:%llu should be gone now! refs=%d\n",
dlm_get_lock_cookie_node(be64_to_cpu(lock->ml.cookie)),
dlm_get_lock_cookie_seq(be64_to_cpu(lock->ml.cookie)),
atomic_read(&lock->lock_refs.refcount)-1);
dlm_lock_put(lock);
}
if (actions & DLM_UNLOCK_CALL_AST)
*call_ast = 1;
if (status == DLM_NORMAL)
lksb->flags &= ~(DLM_LKSB_PUT_LVB|DLM_LKSB_GET_LVB);
return status;
}
void dlm_commit_pending_unlock(struct dlm_lock_resource *res,
struct dlm_lock *lock)
{
list_del_init(&lock->list);
}
void dlm_commit_pending_cancel(struct dlm_lock_resource *res,
struct dlm_lock *lock)
{
list_move_tail(&lock->list, &res->granted);
lock->ml.convert_type = LKM_IVMODE;
}
static inline enum dlm_status dlmunlock_master(struct dlm_ctxt *dlm,
struct dlm_lock_resource *res,
struct dlm_lock *lock,
struct dlm_lockstatus *lksb,
int flags,
int *call_ast)
{
return dlmunlock_common(dlm, res, lock, lksb, flags, call_ast, 1);
}
static inline enum dlm_status dlmunlock_remote(struct dlm_ctxt *dlm,
struct dlm_lock_resource *res,
struct dlm_lock *lock,
struct dlm_lockstatus *lksb,
int flags, int *call_ast)
{
return dlmunlock_common(dlm, res, lock, lksb, flags, call_ast, 0);
}
static enum dlm_status dlm_send_remote_unlock_request(struct dlm_ctxt *dlm,
struct dlm_lock_resource *res,
struct dlm_lock *lock,
struct dlm_lockstatus *lksb,
int flags,
u8 owner)
{
struct dlm_unlock_lock unlock;
int tmpret;
enum dlm_status ret;
int status = 0;
struct kvec vec[2];
size_t veclen = 1;
mlog(0, "%.*s\n", res->lockname.len, res->lockname.name);
if (owner == dlm->node_num) {
mlog(0, "%s:%.*s: this node became the master due to a "
"migration, re-evaluate now\n", dlm->name,
res->lockname.len, res->lockname.name);
return DLM_FORWARD;
}
memset(&unlock, 0, sizeof(unlock));
unlock.node_idx = dlm->node_num;
unlock.flags = cpu_to_be32(flags);
unlock.cookie = lock->ml.cookie;
unlock.namelen = res->lockname.len;
memcpy(unlock.name, res->lockname.name, unlock.namelen);
vec[0].iov_len = sizeof(struct dlm_unlock_lock);
vec[0].iov_base = &unlock;
if (flags & LKM_PUT_LVB) {
vec[1].iov_len = DLM_LVB_LEN;
vec[1].iov_base = lock->lksb->lvb;
veclen++;
}
tmpret = o2net_send_message_vec(DLM_UNLOCK_LOCK_MSG, dlm->key,
vec, veclen, owner, &status);
if (tmpret >= 0) {
if (status == DLM_FORWARD)
mlog(0, "master was in-progress. retry\n");
ret = status;
} else {
mlog(ML_ERROR, "Error %d when sending message %u (key 0x%x) to "
"node %u\n", tmpret, DLM_UNLOCK_LOCK_MSG, dlm->key, owner);
if (dlm_is_host_down(tmpret)) {
if (dlm_is_node_dead(dlm, owner))
ret = DLM_NORMAL;
else
ret = DLM_NOLOCKMGR;
} else {
ret = dlm_err_to_dlm_status(tmpret);
}
}
return ret;
}
int dlm_unlock_lock_handler(struct o2net_msg *msg, u32 len, void *data,
void **ret_data)
{
struct dlm_ctxt *dlm = data;
struct dlm_unlock_lock *unlock = (struct dlm_unlock_lock *)msg->buf;
struct dlm_lock_resource *res = NULL;
struct dlm_lock *lock = NULL;
enum dlm_status status = DLM_NORMAL;
int found = 0, i;
struct dlm_lockstatus *lksb = NULL;
int ignore;
u32 flags;
struct list_head *queue;
flags = be32_to_cpu(unlock->flags);
if (flags & LKM_GET_LVB) {
mlog(ML_ERROR, "bad args! GET_LVB specified on unlock!\n");
return DLM_BADARGS;
}
if ((flags & (LKM_PUT_LVB|LKM_CANCEL)) == (LKM_PUT_LVB|LKM_CANCEL)) {
mlog(ML_ERROR, "bad args! cannot modify lvb on a CANCEL "
"request!\n");
return DLM_BADARGS;
}
if (unlock->namelen > DLM_LOCKID_NAME_MAX) {
mlog(ML_ERROR, "Invalid name length in unlock handler!\n");
return DLM_IVBUFLEN;
}
if (!dlm_grab(dlm))
return DLM_FORWARD;
mlog_bug_on_msg(!dlm_domain_fully_joined(dlm),
"Domain %s not fully joined!\n", dlm->name);
mlog(0, "lvb: %s\n", flags & LKM_PUT_LVB ? "put lvb" : "none");
res = dlm_lookup_lockres(dlm, unlock->name, unlock->namelen);
if (!res) {
mlog(0, "returning DLM_FORWARD -- res no longer exists\n");
status = DLM_FORWARD;
goto not_found;
}
queue=&res->granted;
found = 0;
spin_lock(&res->spinlock);
if (res->state & DLM_LOCK_RES_RECOVERING) {
spin_unlock(&res->spinlock);
mlog(0, "returning DLM_RECOVERING\n");
status = DLM_RECOVERING;
goto leave;
}
if (res->state & DLM_LOCK_RES_MIGRATING) {
spin_unlock(&res->spinlock);
mlog(0, "returning DLM_MIGRATING\n");
status = DLM_MIGRATING;
goto leave;
}
if (res->owner != dlm->node_num) {
spin_unlock(&res->spinlock);
mlog(0, "returning DLM_FORWARD -- not master\n");
status = DLM_FORWARD;
goto leave;
}
for (i=0; i<3; i++) {
list_for_each_entry(lock, queue, list) {
if (lock->ml.cookie == unlock->cookie &&
lock->ml.node == unlock->node_idx) {
dlm_lock_get(lock);
found = 1;
break;
}
}
if (found)
break;
queue++;
}
spin_unlock(&res->spinlock);
if (!found) {
status = DLM_IVLOCKID;
goto not_found;
}
lksb = lock->lksb;
if (flags & (LKM_VALBLK|LKM_PUT_LVB) &&
lock->ml.type != LKM_EXMODE)
flags &= ~(LKM_VALBLK|LKM_PUT_LVB);
if (flags & LKM_PUT_LVB) {
lksb->flags |= DLM_LKSB_PUT_LVB;
memcpy(&lksb->lvb[0], &unlock->lvb[0], DLM_LVB_LEN);
}
status = dlmunlock_master(dlm, res, lock, lksb, flags, &ignore);
if (status == DLM_FORWARD)
mlog(0, "lockres is in progress\n");
if (flags & LKM_PUT_LVB)
lksb->flags &= ~DLM_LKSB_PUT_LVB;
dlm_lockres_calc_usage(dlm, res);
dlm_kick_thread(dlm, res);
not_found:
if (!found)
mlog(ML_ERROR, "failed to find lock to unlock! "
"cookie=%u:%llu\n",
dlm_get_lock_cookie_node(be64_to_cpu(unlock->cookie)),
dlm_get_lock_cookie_seq(be64_to_cpu(unlock->cookie)));
else
dlm_lock_put(lock);
leave:
if (res)
dlm_lockres_put(res);
dlm_put(dlm);
return status;
}
static enum dlm_status dlm_get_cancel_actions(struct dlm_ctxt *dlm,
struct dlm_lock_resource *res,
struct dlm_lock *lock,
struct dlm_lockstatus *lksb,
int *actions)
{
enum dlm_status status;
if (dlm_lock_on_list(&res->blocked, lock)) {
status = DLM_NORMAL;
*actions = (DLM_UNLOCK_CALL_AST |
DLM_UNLOCK_REMOVE_LOCK);
} else if (dlm_lock_on_list(&res->converting, lock)) {
status = DLM_NORMAL;
*actions = (DLM_UNLOCK_CALL_AST |
DLM_UNLOCK_REMOVE_LOCK |
DLM_UNLOCK_REGRANT_LOCK |
DLM_UNLOCK_CLEAR_CONVERT_TYPE);
} else if (dlm_lock_on_list(&res->granted, lock)) {
status = DLM_CANCELGRANT;
*actions = DLM_UNLOCK_CALL_AST;
} else {
mlog(ML_ERROR, "lock to cancel is not on any list!\n");
status = DLM_IVLOCKID;
*actions = 0;
}
return status;
}
static enum dlm_status dlm_get_unlock_actions(struct dlm_ctxt *dlm,
struct dlm_lock_resource *res,
struct dlm_lock *lock,
struct dlm_lockstatus *lksb,
int *actions)
{
enum dlm_status status;
if (!dlm_lock_on_list(&res->granted, lock)) {
status = DLM_DENIED;
dlm_error(status);
*actions = 0;
} else {
status = DLM_NORMAL;
*actions = (DLM_UNLOCK_FREE_LOCK |
DLM_UNLOCK_CALL_AST |
DLM_UNLOCK_REMOVE_LOCK);
}
return status;
}
enum dlm_status dlmunlock(struct dlm_ctxt *dlm, struct dlm_lockstatus *lksb,
int flags, dlm_astunlockfunc_t *unlockast, void *data)
{
enum dlm_status status;
struct dlm_lock_resource *res;
struct dlm_lock *lock = NULL;
int call_ast, is_master;
if (!lksb) {
dlm_error(DLM_BADARGS);
return DLM_BADARGS;
}
if (flags & ~(LKM_CANCEL | LKM_VALBLK | LKM_INVVALBLK)) {
dlm_error(DLM_BADPARAM);
return DLM_BADPARAM;
}
if ((flags & (LKM_VALBLK | LKM_CANCEL)) == (LKM_VALBLK | LKM_CANCEL)) {
mlog(0, "VALBLK given with CANCEL: ignoring VALBLK\n");
flags &= ~LKM_VALBLK;
}
if (!lksb->lockid || !lksb->lockid->lockres) {
dlm_error(DLM_BADPARAM);
return DLM_BADPARAM;
}
lock = lksb->lockid;
BUG_ON(!lock);
dlm_lock_get(lock);
res = lock->lockres;
BUG_ON(!res);
dlm_lockres_get(res);
retry:
call_ast = 0;
mlog(0, "lock=%p res=%p\n", lock, res);
spin_lock(&res->spinlock);
is_master = (res->owner == dlm->node_num);
if (flags & LKM_VALBLK && lock->ml.type != LKM_EXMODE)
flags &= ~LKM_VALBLK;
spin_unlock(&res->spinlock);
if (is_master) {
status = dlmunlock_master(dlm, res, lock, lksb, flags,
&call_ast);
mlog(0, "done calling dlmunlock_master: returned %d, "
"call_ast is %d\n", status, call_ast);
} else {
status = dlmunlock_remote(dlm, res, lock, lksb, flags,
&call_ast);
mlog(0, "done calling dlmunlock_remote: returned %d, "
"call_ast is %d\n", status, call_ast);
}
if (status == DLM_RECOVERING ||
status == DLM_MIGRATING ||
status == DLM_FORWARD ||
status == DLM_NOLOCKMGR) {
msleep(50);
mlog(0, "retrying unlock due to pending recovery/"
"migration/in-progress/reconnect\n");
goto retry;
}
if (call_ast) {
mlog(0, "calling unlockast(%p, %d)\n", data, status);
if (is_master) {
dlm_kick_thread(dlm, NULL);
wait_event(dlm->ast_wq,
dlm_lock_basts_flushed(dlm, lock));
}
(*unlockast)(data, status);
}
if (status == DLM_CANCELGRANT)
status = DLM_NORMAL;
if (status == DLM_NORMAL) {
mlog(0, "kicking the thread\n");
dlm_kick_thread(dlm, res);
} else
dlm_error(status);
dlm_lockres_calc_usage(dlm, res);
dlm_lockres_put(res);
dlm_lock_put(lock);
mlog(0, "returning status=%d!\n", status);
return status;
}
