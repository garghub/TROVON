static void interrupted_completion_wait(void *data)
{
}
int ldlm_expired_completion_wait(void *data)
{
struct lock_wait_data *lwd = data;
struct ldlm_lock *lock = lwd->lwd_lock;
struct obd_import *imp;
struct obd_device *obd;
ENTRY;
if (lock->l_conn_export == NULL) {
static cfs_time_t next_dump = 0, last_dump = 0;
if (ptlrpc_check_suspend())
RETURN(0);
LCONSOLE_WARN("lock timed out (enqueued at "CFS_TIME_T", "
CFS_DURATION_T"s ago)\n",
lock->l_last_activity,
cfs_time_sub(cfs_time_current_sec(),
lock->l_last_activity));
LDLM_DEBUG(lock, "lock timed out (enqueued at "CFS_TIME_T", "
CFS_DURATION_T"s ago); not entering recovery in "
"server code, just going back to sleep",
lock->l_last_activity,
cfs_time_sub(cfs_time_current_sec(),
lock->l_last_activity));
if (cfs_time_after(cfs_time_current(), next_dump)) {
last_dump = next_dump;
next_dump = cfs_time_shift(300);
ldlm_namespace_dump(D_DLMTRACE,
ldlm_lock_to_ns(lock));
if (last_dump == 0)
libcfs_debug_dumplog();
}
RETURN(0);
}
obd = lock->l_conn_export->exp_obd;
imp = obd->u.cli.cl_import;
ptlrpc_fail_import(imp, lwd->lwd_conn_cnt);
LDLM_ERROR(lock, "lock timed out (enqueued at "CFS_TIME_T", "
CFS_DURATION_T"s ago), entering recovery for %s@%s",
lock->l_last_activity,
cfs_time_sub(cfs_time_current_sec(), lock->l_last_activity),
obd2cli_tgt(obd), imp->imp_connection->c_remote_uuid.uuid);
RETURN(0);
}
int ldlm_get_enq_timeout(struct ldlm_lock *lock)
{
int timeout = at_get(ldlm_lock_to_ns_at(lock));
if (AT_OFF)
return obd_timeout / 2;
timeout = min_t(int, at_max, timeout + (timeout >> 1));
return max(timeout, ldlm_enqueue_min);
}
static int ldlm_completion_tail(struct ldlm_lock *lock)
{
long delay;
int result;
if (lock->l_destroyed || lock->l_flags & LDLM_FL_FAILED) {
LDLM_DEBUG(lock, "client-side enqueue: destroyed");
result = -EIO;
} else {
delay = cfs_time_sub(cfs_time_current_sec(),
lock->l_last_activity);
LDLM_DEBUG(lock, "client-side enqueue: granted after "
CFS_DURATION_T"s", delay);
at_measured(ldlm_lock_to_ns_at(lock),
delay);
result = 0;
}
return result;
}
int ldlm_completion_ast_async(struct ldlm_lock *lock, __u64 flags, void *data)
{
ENTRY;
if (flags == LDLM_FL_WAIT_NOREPROC) {
LDLM_DEBUG(lock, "client-side enqueue waiting on pending lock");
RETURN(0);
}
if (!(flags & (LDLM_FL_BLOCK_WAIT | LDLM_FL_BLOCK_GRANTED |
LDLM_FL_BLOCK_CONV))) {
wake_up(&lock->l_waitq);
RETURN(ldlm_completion_tail(lock));
}
LDLM_DEBUG(lock, "client-side enqueue returned a blocked lock, "
"going forward");
ldlm_reprocess_all(lock->l_resource);
RETURN(0);
}
int ldlm_completion_ast(struct ldlm_lock *lock, __u64 flags, void *data)
{
struct lock_wait_data lwd;
struct obd_device *obd;
struct obd_import *imp = NULL;
struct l_wait_info lwi;
__u32 timeout;
int rc = 0;
ENTRY;
if (flags == LDLM_FL_WAIT_NOREPROC) {
LDLM_DEBUG(lock, "client-side enqueue waiting on pending lock");
goto noreproc;
}
if (!(flags & (LDLM_FL_BLOCK_WAIT | LDLM_FL_BLOCK_GRANTED |
LDLM_FL_BLOCK_CONV))) {
wake_up(&lock->l_waitq);
RETURN(0);
}
LDLM_DEBUG(lock, "client-side enqueue returned a blocked lock, "
"sleeping");
noreproc:
obd = class_exp2obd(lock->l_conn_export);
if (obd != NULL) {
imp = obd->u.cli.cl_import;
}
timeout = ldlm_get_enq_timeout(lock) * 2;
lwd.lwd_lock = lock;
if (lock->l_flags & LDLM_FL_NO_TIMEOUT) {
LDLM_DEBUG(lock, "waiting indefinitely because of NO_TIMEOUT");
lwi = LWI_INTR(interrupted_completion_wait, &lwd);
} else {
lwi = LWI_TIMEOUT_INTR(cfs_time_seconds(timeout),
ldlm_expired_completion_wait,
interrupted_completion_wait, &lwd);
}
if (imp != NULL) {
spin_lock(&imp->imp_lock);
lwd.lwd_conn_cnt = imp->imp_conn_cnt;
spin_unlock(&imp->imp_lock);
}
if (ns_is_client(ldlm_lock_to_ns(lock)) &&
OBD_FAIL_CHECK_RESET(OBD_FAIL_LDLM_INTR_CP_AST,
OBD_FAIL_LDLM_CP_BL_RACE | OBD_FAIL_ONCE)) {
lock->l_flags |= LDLM_FL_FAIL_LOC;
rc = -EINTR;
} else {
rc = l_wait_event(lock->l_waitq,
is_granted_or_cancelled(lock), &lwi);
}
if (rc) {
LDLM_DEBUG(lock, "client-side enqueue waking up: failed (%d)",
rc);
RETURN(rc);
}
RETURN(ldlm_completion_tail(lock));
}
int ldlm_blocking_ast_nocheck(struct ldlm_lock *lock)
{
int do_ast;
ENTRY;
lock->l_flags |= LDLM_FL_CBPENDING;
do_ast = (!lock->l_readers && !lock->l_writers);
unlock_res_and_lock(lock);
if (do_ast) {
struct lustre_handle lockh;
int rc;
LDLM_DEBUG(lock, "already unused, calling ldlm_cli_cancel");
ldlm_lock2handle(lock, &lockh);
rc = ldlm_cli_cancel(&lockh, LCF_ASYNC);
if (rc < 0)
CERROR("ldlm_cli_cancel: %d\n", rc);
} else {
LDLM_DEBUG(lock, "Lock still has references, will be "
"cancelled later");
}
RETURN(0);
}
int ldlm_blocking_ast(struct ldlm_lock *lock, struct ldlm_lock_desc *desc,
void *data, int flag)
{
ENTRY;
if (flag == LDLM_CB_CANCELING) {
RETURN(0);
}
lock_res_and_lock(lock);
if (lock->l_blocking_ast != ldlm_blocking_ast) {
unlock_res_and_lock(lock);
RETURN(0);
}
RETURN(ldlm_blocking_ast_nocheck(lock));
}
int ldlm_glimpse_ast(struct ldlm_lock *lock, void *reqp)
{
return -ELDLM_NO_LOCK_DATA;
}
int ldlm_cli_enqueue_local(struct ldlm_namespace *ns,
const struct ldlm_res_id *res_id,
ldlm_type_t type, ldlm_policy_data_t *policy,
ldlm_mode_t mode, __u64 *flags,
ldlm_blocking_callback blocking,
ldlm_completion_callback completion,
ldlm_glimpse_callback glimpse,
void *data, __u32 lvb_len, enum lvb_type lvb_type,
const __u64 *client_cookie,
struct lustre_handle *lockh)
{
struct ldlm_lock *lock;
int err;
const struct ldlm_callback_suite cbs = { .lcs_completion = completion,
.lcs_blocking = blocking,
.lcs_glimpse = glimpse,
};
ENTRY;
LASSERT(!(*flags & LDLM_FL_REPLAY));
if (unlikely(ns_is_client(ns))) {
CERROR("Trying to enqueue local lock in a shadow namespace\n");
LBUG();
}
lock = ldlm_lock_create(ns, res_id, type, mode, &cbs, data, lvb_len,
lvb_type);
if (unlikely(!lock))
GOTO(out_nolock, err = -ENOMEM);
ldlm_lock2handle(lock, lockh);
ldlm_lock_addref_internal_nolock(lock, mode);
lock->l_flags |= LDLM_FL_LOCAL;
if (*flags & LDLM_FL_ATOMIC_CB)
lock->l_flags |= LDLM_FL_ATOMIC_CB;
if (policy != NULL)
lock->l_policy_data = *policy;
if (client_cookie != NULL)
lock->l_client_cookie = *client_cookie;
if (type == LDLM_EXTENT)
lock->l_req_extent = policy->l_extent;
err = ldlm_lock_enqueue(ns, &lock, policy, flags);
if (unlikely(err != ELDLM_OK))
GOTO(out, err);
if (policy != NULL)
*policy = lock->l_policy_data;
if (lock->l_completion_ast)
lock->l_completion_ast(lock, *flags, NULL);
LDLM_DEBUG(lock, "client-side local enqueue handler, new lock created");
EXIT;
out:
LDLM_LOCK_RELEASE(lock);
out_nolock:
return err;
}
static void failed_lock_cleanup(struct ldlm_namespace *ns,
struct ldlm_lock *lock, int mode)
{
int need_cancel = 0;
lock_res_and_lock(lock);
if ((lock->l_req_mode != lock->l_granted_mode) &&
!(lock->l_flags & LDLM_FL_FAILED)) {
lock->l_flags |= LDLM_FL_LOCAL_ONLY | LDLM_FL_FAILED |
LDLM_FL_ATOMIC_CB | LDLM_FL_CBPENDING;
need_cancel = 1;
}
unlock_res_and_lock(lock);
if (need_cancel)
LDLM_DEBUG(lock,
"setting FL_LOCAL_ONLY | LDLM_FL_FAILED | "
"LDLM_FL_ATOMIC_CB | LDLM_FL_CBPENDING");
else
LDLM_DEBUG(lock, "lock was granted or failed in race");
ldlm_lock_decref_internal(lock, mode);
if (lock->l_resource->lr_type == LDLM_FLOCK) {
lock_res_and_lock(lock);
ldlm_resource_unlink_lock(lock);
ldlm_lock_destroy_nolock(lock);
unlock_res_and_lock(lock);
}
}
int ldlm_cli_enqueue_fini(struct obd_export *exp, struct ptlrpc_request *req,
ldlm_type_t type, __u8 with_policy, ldlm_mode_t mode,
__u64 *flags, void *lvb, __u32 lvb_len,
struct lustre_handle *lockh,int rc)
{
struct ldlm_namespace *ns = exp->exp_obd->obd_namespace;
int is_replay = *flags & LDLM_FL_REPLAY;
struct ldlm_lock *lock;
struct ldlm_reply *reply;
int cleanup_phase = 1;
int size = 0;
ENTRY;
lock = ldlm_handle2lock(lockh);
if (!lock) {
LASSERT(type == LDLM_FLOCK);
RETURN(-ENOLCK);
}
LASSERTF(ergo(lvb_len != 0, lvb_len == lock->l_lvb_len),
"lvb_len = %d, l_lvb_len = %d\n", lvb_len, lock->l_lvb_len);
if (rc != ELDLM_OK) {
LASSERT(!is_replay);
LDLM_DEBUG(lock, "client-side enqueue END (%s)",
rc == ELDLM_LOCK_ABORTED ? "ABORTED" : "FAILED");
if (rc != ELDLM_LOCK_ABORTED)
GOTO(cleanup, rc);
}
reply = req_capsule_server_get(&req->rq_pill, &RMF_DLM_REP);
if (reply == NULL)
GOTO(cleanup, rc = -EPROTO);
if (lvb_len != 0) {
LASSERT(lvb != NULL);
size = req_capsule_get_size(&req->rq_pill, &RMF_DLM_LVB,
RCL_SERVER);
if (size < 0) {
LDLM_ERROR(lock, "Fail to get lvb_len, rc = %d", size);
GOTO(cleanup, rc = size);
} else if (unlikely(size > lvb_len)) {
LDLM_ERROR(lock, "Replied LVB is larger than "
"expectation, expected = %d, replied = %d",
lvb_len, size);
GOTO(cleanup, rc = -EINVAL);
}
}
if (rc == ELDLM_LOCK_ABORTED) {
if (lvb_len != 0)
rc = ldlm_fill_lvb(lock, &req->rq_pill, RCL_SERVER,
lvb, size);
GOTO(cleanup, rc = (rc != 0 ? rc : ELDLM_LOCK_ABORTED));
}
cleanup_phase = 0;
lock_res_and_lock(lock);
if (exp->exp_lock_hash) {
cfs_hash_rehash_key(exp->exp_lock_hash,
&lock->l_remote_handle,
&reply->lock_handle,
&lock->l_exp_hash);
} else {
lock->l_remote_handle = reply->lock_handle;
}
*flags = ldlm_flags_from_wire(reply->lock_flags);
lock->l_flags |= ldlm_flags_from_wire(reply->lock_flags &
LDLM_INHERIT_FLAGS);
lock->l_flags |= ldlm_flags_from_wire(reply->lock_flags &
LDLM_FL_NO_TIMEOUT);
unlock_res_and_lock(lock);
CDEBUG(D_INFO, "local: %p, remote cookie: "LPX64", flags: 0x%llx\n",
lock, reply->lock_handle.cookie, *flags);
if ((*flags) & LDLM_FL_LOCK_CHANGED) {
int newmode = reply->lock_desc.l_req_mode;
LASSERT(!is_replay);
if (newmode && newmode != lock->l_req_mode) {
LDLM_DEBUG(lock, "server returned different mode %s",
ldlm_lockname[newmode]);
lock->l_req_mode = newmode;
}
if (memcmp(reply->lock_desc.l_resource.lr_name.name,
lock->l_resource->lr_name.name,
sizeof(struct ldlm_res_id))) {
CDEBUG(D_INFO, "remote intent success, locking "
"(%ld,%ld,%ld) instead of "
"(%ld,%ld,%ld)\n",
(long)reply->lock_desc.l_resource.lr_name.name[0],
(long)reply->lock_desc.l_resource.lr_name.name[1],
(long)reply->lock_desc.l_resource.lr_name.name[2],
(long)lock->l_resource->lr_name.name[0],
(long)lock->l_resource->lr_name.name[1],
(long)lock->l_resource->lr_name.name[2]);
rc = ldlm_lock_change_resource(ns, lock,
&reply->lock_desc.l_resource.lr_name);
if (rc || lock->l_resource == NULL)
GOTO(cleanup, rc = -ENOMEM);
LDLM_DEBUG(lock, "client-side enqueue, new resource");
}
if (with_policy)
if (!(type == LDLM_IBITS &&
!(exp_connect_flags(exp) & OBD_CONNECT_IBITS)))
ldlm_convert_policy_to_local(exp,
lock->l_resource->lr_type,
&reply->lock_desc.l_policy_data,
&lock->l_policy_data);
if (type != LDLM_PLAIN)
LDLM_DEBUG(lock,"client-side enqueue, new policy data");
}
if ((*flags) & LDLM_FL_AST_SENT ||
(LIBLUSTRE_CLIENT && type == LDLM_EXTENT)) {
lock_res_and_lock(lock);
lock->l_flags |= LDLM_FL_CBPENDING | LDLM_FL_BL_AST;
unlock_res_and_lock(lock);
LDLM_DEBUG(lock, "enqueue reply includes blocking AST");
}
if (lvb_len != 0) {
lock_res_and_lock(lock);
if (lock->l_req_mode != lock->l_granted_mode)
rc = ldlm_fill_lvb(lock, &req->rq_pill, RCL_SERVER,
lock->l_lvb_data, size);
unlock_res_and_lock(lock);
if (rc < 0) {
cleanup_phase = 1;
GOTO(cleanup, rc);
}
}
if (!is_replay) {
rc = ldlm_lock_enqueue(ns, &lock, NULL, flags);
if (lock->l_completion_ast != NULL) {
int err = lock->l_completion_ast(lock, *flags, NULL);
if (!rc)
rc = err;
if (rc)
cleanup_phase = 1;
}
}
if (lvb_len && lvb != NULL) {
memcpy(lvb, lock->l_lvb_data, lvb_len);
}
LDLM_DEBUG(lock, "client-side enqueue END");
EXIT;
cleanup:
if (cleanup_phase == 1 && rc)
failed_lock_cleanup(ns, lock, mode);
LDLM_LOCK_PUT(lock);
LDLM_LOCK_RELEASE(lock);
return rc;
}
static inline int ldlm_req_handles_avail(int req_size, int off)
{
int avail;
avail = min_t(int, LDLM_MAXREQSIZE, PAGE_CACHE_SIZE - 512) - req_size;
if (likely(avail >= 0))
avail /= (int)sizeof(struct lustre_handle);
else
avail = 0;
avail += LDLM_LOCKREQ_HANDLES - off;
return avail;
}
static inline int ldlm_capsule_handles_avail(struct req_capsule *pill,
enum req_location loc,
int off)
{
int size = req_capsule_msg_size(pill, loc);
return ldlm_req_handles_avail(size, off);
}
static inline int ldlm_format_handles_avail(struct obd_import *imp,
const struct req_format *fmt,
enum req_location loc, int off)
{
int size = req_capsule_fmt_size(imp->imp_msg_magic, fmt, loc);
return ldlm_req_handles_avail(size, off);
}
int ldlm_prep_elc_req(struct obd_export *exp, struct ptlrpc_request *req,
int version, int opc, int canceloff,
struct list_head *cancels, int count)
{
struct ldlm_namespace *ns = exp->exp_obd->obd_namespace;
struct req_capsule *pill = &req->rq_pill;
struct ldlm_request *dlm = NULL;
int flags, avail, to_free, pack = 0;
LIST_HEAD(head);
int rc;
ENTRY;
if (cancels == NULL)
cancels = &head;
if (ns_connect_cancelset(ns)) {
req_capsule_filled_sizes(pill, RCL_CLIENT);
avail = ldlm_capsule_handles_avail(pill, RCL_CLIENT, canceloff);
flags = ns_connect_lru_resize(ns) ?
LDLM_CANCEL_LRUR : LDLM_CANCEL_AGED;
to_free = !ns_connect_lru_resize(ns) &&
opc == LDLM_ENQUEUE ? 1 : 0;
if (avail > count)
count += ldlm_cancel_lru_local(ns, cancels, to_free,
avail - count, 0, flags);
if (avail > count)
pack = count;
else
pack = avail;
req_capsule_set_size(pill, &RMF_DLM_REQ, RCL_CLIENT,
ldlm_request_bufsize(pack, opc));
}
rc = ptlrpc_request_pack(req, version, opc);
if (rc) {
ldlm_lock_list_put(cancels, l_bl_ast, count);
RETURN(rc);
}
if (ns_connect_cancelset(ns)) {
if (canceloff) {
dlm = req_capsule_client_get(pill, &RMF_DLM_REQ);
LASSERT(dlm);
dlm->lock_count = canceloff;
}
ldlm_cli_cancel_list(cancels, pack, req, 0);
ldlm_cli_cancel_list(cancels, count - pack, NULL, 0);
} else {
ldlm_lock_list_put(cancels, l_bl_ast, count);
}
RETURN(0);
}
int ldlm_prep_enqueue_req(struct obd_export *exp, struct ptlrpc_request *req,
struct list_head *cancels, int count)
{
return ldlm_prep_elc_req(exp, req, LUSTRE_DLM_VERSION, LDLM_ENQUEUE,
LDLM_ENQUEUE_CANCEL_OFF, cancels, count);
}
struct ptlrpc_request *ldlm_enqueue_pack(struct obd_export *exp, int lvb_len)
{
struct ptlrpc_request *req;
int rc;
ENTRY;
req = ptlrpc_request_alloc(class_exp2cliimp(exp), &RQF_LDLM_ENQUEUE);
if (req == NULL)
RETURN(ERR_PTR(-ENOMEM));
rc = ldlm_prep_enqueue_req(exp, req, NULL, 0);
if (rc) {
ptlrpc_request_free(req);
RETURN(ERR_PTR(rc));
}
req_capsule_set_size(&req->rq_pill, &RMF_DLM_LVB, RCL_SERVER, lvb_len);
ptlrpc_request_set_replen(req);
RETURN(req);
}
int ldlm_cli_enqueue(struct obd_export *exp, struct ptlrpc_request **reqp,
struct ldlm_enqueue_info *einfo,
const struct ldlm_res_id *res_id,
ldlm_policy_data_t const *policy, __u64 *flags,
void *lvb, __u32 lvb_len, enum lvb_type lvb_type,
struct lustre_handle *lockh, int async)
{
struct ldlm_namespace *ns;
struct ldlm_lock *lock;
struct ldlm_request *body;
int is_replay = *flags & LDLM_FL_REPLAY;
int req_passed_in = 1;
int rc, err;
struct ptlrpc_request *req;
ENTRY;
LASSERT(exp != NULL);
ns = exp->exp_obd->obd_namespace;
if (is_replay) {
lock = ldlm_handle2lock_long(lockh, 0);
LASSERT(lock != NULL);
LDLM_DEBUG(lock, "client-side enqueue START");
LASSERT(exp == lock->l_conn_export);
} else {
const struct ldlm_callback_suite cbs = {
.lcs_completion = einfo->ei_cb_cp,
.lcs_blocking = einfo->ei_cb_bl,
.lcs_glimpse = einfo->ei_cb_gl,
.lcs_weigh = einfo->ei_cb_wg
};
lock = ldlm_lock_create(ns, res_id, einfo->ei_type,
einfo->ei_mode, &cbs, einfo->ei_cbdata,
lvb_len, lvb_type);
if (lock == NULL)
RETURN(-ENOMEM);
ldlm_lock_addref_internal(lock, einfo->ei_mode);
ldlm_lock2handle(lock, lockh);
if (policy != NULL) {
if (einfo->ei_type == LDLM_IBITS &&
!(exp_connect_flags(exp) &
OBD_CONNECT_IBITS))
lock->l_policy_data.l_inodebits.bits =
MDS_INODELOCK_LOOKUP |
MDS_INODELOCK_UPDATE;
else
lock->l_policy_data = *policy;
}
if (einfo->ei_type == LDLM_EXTENT)
lock->l_req_extent = policy->l_extent;
LDLM_DEBUG(lock, "client-side enqueue START, flags %llx\n",
*flags);
}
lock->l_conn_export = exp;
lock->l_export = NULL;
lock->l_blocking_ast = einfo->ei_cb_bl;
lock->l_flags |= (*flags & LDLM_FL_NO_LRU);
if (reqp == NULL || *reqp == NULL) {
req = ptlrpc_request_alloc_pack(class_exp2cliimp(exp),
&RQF_LDLM_ENQUEUE,
LUSTRE_DLM_VERSION,
LDLM_ENQUEUE);
if (req == NULL) {
failed_lock_cleanup(ns, lock, einfo->ei_mode);
LDLM_LOCK_RELEASE(lock);
RETURN(-ENOMEM);
}
req_passed_in = 0;
if (reqp)
*reqp = req;
} else {
int len;
req = *reqp;
len = req_capsule_get_size(&req->rq_pill, &RMF_DLM_REQ,
RCL_CLIENT);
LASSERTF(len >= sizeof(*body), "buflen[%d] = %d, not %d\n",
DLM_LOCKREQ_OFF, len, (int)sizeof(*body));
}
body = req_capsule_client_get(&req->rq_pill, &RMF_DLM_REQ);
ldlm_lock2desc(lock, &body->lock_desc);
body->lock_flags = ldlm_flags_to_wire(*flags);
body->lock_handle[0] = *lockh;
if (!req_passed_in) {
if (lvb_len > 0)
req_capsule_extend(&req->rq_pill,
&RQF_LDLM_ENQUEUE_LVB);
req_capsule_set_size(&req->rq_pill, &RMF_DLM_LVB, RCL_SERVER,
lvb_len);
ptlrpc_request_set_replen(req);
}
LASSERT(ergo(LIBLUSTRE_CLIENT, einfo->ei_type != LDLM_EXTENT ||
policy->l_extent.end == OBD_OBJECT_EOF));
if (async) {
LASSERT(reqp != NULL);
RETURN(0);
}
LDLM_DEBUG(lock, "sending request");
rc = ptlrpc_queue_wait(req);
err = ldlm_cli_enqueue_fini(exp, req, einfo->ei_type, policy ? 1 : 0,
einfo->ei_mode, flags, lvb, lvb_len,
lockh, rc);
if (err == -ENOLCK)
LDLM_LOCK_RELEASE(lock);
else
rc = err;
if (!req_passed_in && req != NULL) {
ptlrpc_req_finished(req);
if (reqp)
*reqp = NULL;
}
RETURN(rc);
}
static int ldlm_cli_convert_local(struct ldlm_lock *lock, int new_mode,
__u32 *flags)
{
struct ldlm_resource *res;
int rc;
ENTRY;
if (ns_is_client(ldlm_lock_to_ns(lock))) {
CERROR("Trying to cancel local lock\n");
LBUG();
}
LDLM_DEBUG(lock, "client-side local convert");
res = ldlm_lock_convert(lock, new_mode, flags);
if (res) {
ldlm_reprocess_all(res);
rc = 0;
} else {
rc = EDEADLOCK;
}
LDLM_DEBUG(lock, "client-side local convert handler END");
LDLM_LOCK_PUT(lock);
RETURN(rc);
}
int ldlm_cli_convert(struct lustre_handle *lockh, int new_mode, __u32 *flags)
{
struct ldlm_request *body;
struct ldlm_reply *reply;
struct ldlm_lock *lock;
struct ldlm_resource *res;
struct ptlrpc_request *req;
int rc;
ENTRY;
lock = ldlm_handle2lock(lockh);
if (!lock) {
LBUG();
RETURN(-EINVAL);
}
*flags = 0;
if (lock->l_conn_export == NULL)
RETURN(ldlm_cli_convert_local(lock, new_mode, flags));
LDLM_DEBUG(lock, "client-side convert");
req = ptlrpc_request_alloc_pack(class_exp2cliimp(lock->l_conn_export),
&RQF_LDLM_CONVERT, LUSTRE_DLM_VERSION,
LDLM_CONVERT);
if (req == NULL) {
LDLM_LOCK_PUT(lock);
RETURN(-ENOMEM);
}
body = req_capsule_client_get(&req->rq_pill, &RMF_DLM_REQ);
body->lock_handle[0] = lock->l_remote_handle;
body->lock_desc.l_req_mode = new_mode;
body->lock_flags = ldlm_flags_to_wire(*flags);
ptlrpc_request_set_replen(req);
rc = ptlrpc_queue_wait(req);
if (rc != ELDLM_OK)
GOTO(out, rc);
reply = req_capsule_server_get(&req->rq_pill, &RMF_DLM_REP);
if (reply == NULL)
GOTO(out, rc = -EPROTO);
if (req->rq_status)
GOTO(out, rc = req->rq_status);
res = ldlm_lock_convert(lock, new_mode, &reply->lock_flags);
if (res != NULL) {
ldlm_reprocess_all(res);
if (lock->l_completion_ast) {
rc = lock->l_completion_ast(lock, LDLM_FL_WAIT_NOREPROC,
NULL);
if (rc)
GOTO(out, rc);
}
} else {
rc = EDEADLOCK;
}
EXIT;
out:
LDLM_LOCK_PUT(lock);
ptlrpc_req_finished(req);
return rc;
}
static __u64 ldlm_cli_cancel_local(struct ldlm_lock *lock)
{
__u64 rc = LDLM_FL_LOCAL_ONLY;
ENTRY;
if (lock->l_conn_export) {
bool local_only;
LDLM_DEBUG(lock, "client-side cancel");
lock_res_and_lock(lock);
lock->l_flags |= LDLM_FL_CBPENDING;
local_only = !!(lock->l_flags &
(LDLM_FL_LOCAL_ONLY|LDLM_FL_CANCEL_ON_BLOCK));
ldlm_cancel_callback(lock);
rc = (lock->l_flags & LDLM_FL_BL_AST) ?
LDLM_FL_BL_AST : LDLM_FL_CANCELING;
unlock_res_and_lock(lock);
if (local_only) {
CDEBUG(D_DLMTRACE, "not sending request (at caller's "
"instruction)\n");
rc = LDLM_FL_LOCAL_ONLY;
}
ldlm_lock_cancel(lock);
} else {
if (ns_is_client(ldlm_lock_to_ns(lock))) {
LDLM_ERROR(lock, "Trying to cancel local lock");
LBUG();
}
LDLM_DEBUG(lock, "server-side local cancel");
ldlm_lock_cancel(lock);
ldlm_reprocess_all(lock->l_resource);
}
RETURN(rc);
}
static void ldlm_cancel_pack(struct ptlrpc_request *req,
struct list_head *head, int count)
{
struct ldlm_request *dlm;
struct ldlm_lock *lock;
int max, packed = 0;
ENTRY;
dlm = req_capsule_client_get(&req->rq_pill, &RMF_DLM_REQ);
LASSERT(dlm != NULL);
max = req_capsule_get_size(&req->rq_pill, &RMF_DLM_REQ, RCL_CLIENT) -
sizeof(struct ldlm_request);
max /= sizeof(struct lustre_handle);
max += LDLM_LOCKREQ_HANDLES;
LASSERT(max >= dlm->lock_count + count);
list_for_each_entry(lock, head, l_bl_ast) {
if (!count--)
break;
LASSERT(lock->l_conn_export);
LDLM_DEBUG(lock, "packing");
dlm->lock_handle[dlm->lock_count++] = lock->l_remote_handle;
packed++;
}
CDEBUG(D_DLMTRACE, "%d locks packed\n", packed);
EXIT;
}
int ldlm_cli_cancel_req(struct obd_export *exp, struct list_head *cancels,
int count, ldlm_cancel_flags_t flags)
{
struct ptlrpc_request *req = NULL;
struct obd_import *imp;
int free, sent = 0;
int rc = 0;
ENTRY;
LASSERT(exp != NULL);
LASSERT(count > 0);
CFS_FAIL_TIMEOUT(OBD_FAIL_LDLM_PAUSE_CANCEL, cfs_fail_val);
if (CFS_FAIL_CHECK(OBD_FAIL_LDLM_CANCEL_RACE))
RETURN(count);
free = ldlm_format_handles_avail(class_exp2cliimp(exp),
&RQF_LDLM_CANCEL, RCL_CLIENT, 0);
if (count > free)
count = free;
while (1) {
imp = class_exp2cliimp(exp);
if (imp == NULL || imp->imp_invalid) {
CDEBUG(D_DLMTRACE,
"skipping cancel on invalid import %p\n", imp);
RETURN(count);
}
req = ptlrpc_request_alloc(imp, &RQF_LDLM_CANCEL);
if (req == NULL)
GOTO(out, rc = -ENOMEM);
req_capsule_filled_sizes(&req->rq_pill, RCL_CLIENT);
req_capsule_set_size(&req->rq_pill, &RMF_DLM_REQ, RCL_CLIENT,
ldlm_request_bufsize(count, LDLM_CANCEL));
rc = ptlrpc_request_pack(req, LUSTRE_DLM_VERSION, LDLM_CANCEL);
if (rc) {
ptlrpc_request_free(req);
GOTO(out, rc);
}
req->rq_request_portal = LDLM_CANCEL_REQUEST_PORTAL;
req->rq_reply_portal = LDLM_CANCEL_REPLY_PORTAL;
ptlrpc_at_set_req_timeout(req);
ldlm_cancel_pack(req, cancels, count);
ptlrpc_request_set_replen(req);
if (flags & LCF_ASYNC) {
ptlrpcd_add_req(req, PDL_POLICY_LOCAL, -1);
sent = count;
GOTO(out, 0);
} else {
rc = ptlrpc_queue_wait(req);
}
if (rc == ESTALE) {
CDEBUG(D_DLMTRACE, "client/server (nid %s) "
"out of sync -- not fatal\n",
libcfs_nid2str(req->rq_import->
imp_connection->c_peer.nid));
rc = 0;
} else if (rc == -ETIMEDOUT &&
req->rq_import_generation == imp->imp_generation) {
ptlrpc_req_finished(req);
continue;
} else if (rc != ELDLM_OK) {
CDEBUG_LIMIT(rc == -ESHUTDOWN ? D_DLMTRACE : D_ERROR,
"Got rc %d from cancel RPC: "
"canceling anyway\n", rc);
break;
}
sent = count;
break;
}
ptlrpc_req_finished(req);
EXIT;
out:
return sent ? sent : rc;
}
static inline struct ldlm_pool *ldlm_imp2pl(struct obd_import *imp)
{
LASSERT(imp != NULL);
return &imp->imp_obd->obd_namespace->ns_pool;
}
int ldlm_cli_update_pool(struct ptlrpc_request *req)
{
struct obd_device *obd;
__u64 new_slv;
__u32 new_limit;
ENTRY;
if (unlikely(!req->rq_import || !req->rq_import->imp_obd ||
!imp_connect_lru_resize(req->rq_import)))
{
RETURN(0);
}
if (lustre_msg_get_slv(req->rq_repmsg) == 0 ||
lustre_msg_get_limit(req->rq_repmsg) == 0) {
DEBUG_REQ(D_HA, req, "Zero SLV or Limit found "
"(SLV: "LPU64", Limit: %u)",
lustre_msg_get_slv(req->rq_repmsg),
lustre_msg_get_limit(req->rq_repmsg));
RETURN(0);
}
new_limit = lustre_msg_get_limit(req->rq_repmsg);
new_slv = lustre_msg_get_slv(req->rq_repmsg);
obd = req->rq_import->imp_obd;
write_lock(&obd->obd_pool_lock);
obd->obd_pool_slv = new_slv;
obd->obd_pool_limit = new_limit;
write_unlock(&obd->obd_pool_lock);
RETURN(0);
}
int ldlm_cli_cancel(struct lustre_handle *lockh,
ldlm_cancel_flags_t cancel_flags)
{
struct obd_export *exp;
int avail, flags, count = 1;
__u64 rc = 0;
struct ldlm_namespace *ns;
struct ldlm_lock *lock;
LIST_HEAD(cancels);
ENTRY;
lock = ldlm_handle2lock_long(lockh, LDLM_FL_CANCELING);
if (lock == NULL) {
LDLM_DEBUG_NOLOCK("lock is already being destroyed\n");
RETURN(0);
}
rc = ldlm_cli_cancel_local(lock);
if (rc == LDLM_FL_LOCAL_ONLY) {
LDLM_LOCK_RELEASE(lock);
RETURN(0);
}
LASSERT(list_empty(&lock->l_bl_ast));
list_add(&lock->l_bl_ast, &cancels);
exp = lock->l_conn_export;
if (exp_connect_cancelset(exp)) {
avail = ldlm_format_handles_avail(class_exp2cliimp(exp),
&RQF_LDLM_CANCEL,
RCL_CLIENT, 0);
LASSERT(avail > 0);
ns = ldlm_lock_to_ns(lock);
flags = ns_connect_lru_resize(ns) ?
LDLM_CANCEL_LRUR : LDLM_CANCEL_AGED;
count += ldlm_cancel_lru_local(ns, &cancels, 0, avail - 1,
LCF_BL_AST, flags);
}
ldlm_cli_cancel_list(&cancels, count, NULL, cancel_flags);
RETURN(0);
}
int ldlm_cli_cancel_list_local(struct list_head *cancels, int count,
ldlm_cancel_flags_t flags)
{
LIST_HEAD(head);
struct ldlm_lock *lock, *next;
int left = 0, bl_ast = 0;
__u64 rc;
left = count;
list_for_each_entry_safe(lock, next, cancels, l_bl_ast) {
if (left-- == 0)
break;
if (flags & LCF_LOCAL) {
rc = LDLM_FL_LOCAL_ONLY;
ldlm_lock_cancel(lock);
} else {
rc = ldlm_cli_cancel_local(lock);
}
if (!(flags & LCF_BL_AST) && (rc == LDLM_FL_BL_AST)) {
LDLM_DEBUG(lock, "Cancel lock separately");
list_del_init(&lock->l_bl_ast);
list_add(&lock->l_bl_ast, &head);
bl_ast++;
continue;
}
if (rc == LDLM_FL_LOCAL_ONLY) {
list_del_init(&lock->l_bl_ast);
LDLM_LOCK_RELEASE(lock);
count--;
}
}
if (bl_ast > 0) {
count -= bl_ast;
ldlm_cli_cancel_list(&head, bl_ast, NULL, 0);
}
RETURN(count);
}
static ldlm_policy_res_t ldlm_cancel_no_wait_policy(struct ldlm_namespace *ns,
struct ldlm_lock *lock,
int unused, int added,
int count)
{
ldlm_policy_res_t result = LDLM_POLICY_CANCEL_LOCK;
ldlm_cancel_for_recovery cb = ns->ns_cancel_for_recovery;
lock_res_and_lock(lock);
switch (lock->l_resource->lr_type) {
case LDLM_EXTENT:
case LDLM_IBITS:
if (cb && cb(lock))
break;
default:
result = LDLM_POLICY_SKIP_LOCK;
lock->l_flags |= LDLM_FL_SKIPPED;
break;
}
unlock_res_and_lock(lock);
RETURN(result);
}
static ldlm_policy_res_t ldlm_cancel_lrur_policy(struct ldlm_namespace *ns,
struct ldlm_lock *lock,
int unused, int added,
int count)
{
cfs_time_t cur = cfs_time_current();
struct ldlm_pool *pl = &ns->ns_pool;
__u64 slv, lvf, lv;
cfs_time_t la;
if (count && added >= count)
return LDLM_POLICY_KEEP_LOCK;
slv = ldlm_pool_get_slv(pl);
lvf = ldlm_pool_get_lvf(pl);
la = cfs_duration_sec(cfs_time_sub(cur,
lock->l_last_used));
lv = lvf * la * unused;
ldlm_pool_set_clv(pl, lv);
return (slv == 0 || lv < slv) ?
LDLM_POLICY_KEEP_LOCK : LDLM_POLICY_CANCEL_LOCK;
}
static ldlm_policy_res_t ldlm_cancel_passed_policy(struct ldlm_namespace *ns,
struct ldlm_lock *lock,
int unused, int added,
int count)
{
return (added >= count) ?
LDLM_POLICY_KEEP_LOCK : LDLM_POLICY_CANCEL_LOCK;
}
static ldlm_policy_res_t ldlm_cancel_aged_policy(struct ldlm_namespace *ns,
struct ldlm_lock *lock,
int unused, int added,
int count)
{
return ((added >= count) &&
cfs_time_before(cfs_time_current(),
cfs_time_add(lock->l_last_used,
ns->ns_max_age))) ?
LDLM_POLICY_KEEP_LOCK : LDLM_POLICY_CANCEL_LOCK;
}
static ldlm_policy_res_t ldlm_cancel_default_policy(struct ldlm_namespace *ns,
struct ldlm_lock *lock,
int unused, int added,
int count)
{
return (added >= count) ?
LDLM_POLICY_KEEP_LOCK : LDLM_POLICY_CANCEL_LOCK;
}
static ldlm_cancel_lru_policy_t
ldlm_cancel_lru_policy(struct ldlm_namespace *ns, int flags)
{
if (flags & LDLM_CANCEL_NO_WAIT)
return ldlm_cancel_no_wait_policy;
if (ns_connect_lru_resize(ns)) {
if (flags & LDLM_CANCEL_SHRINK)
return ldlm_cancel_passed_policy;
else if (flags & LDLM_CANCEL_LRUR)
return ldlm_cancel_lrur_policy;
else if (flags & LDLM_CANCEL_PASSED)
return ldlm_cancel_passed_policy;
} else {
if (flags & LDLM_CANCEL_AGED)
return ldlm_cancel_aged_policy;
}
return ldlm_cancel_default_policy;
}
static int ldlm_prepare_lru_list(struct ldlm_namespace *ns, struct list_head *cancels,
int count, int max, int flags)
{
ldlm_cancel_lru_policy_t pf;
struct ldlm_lock *lock, *next;
int added = 0, unused, remained;
ENTRY;
spin_lock(&ns->ns_lock);
unused = ns->ns_nr_unused;
remained = unused;
if (!ns_connect_lru_resize(ns))
count += unused - ns->ns_max_unused;
pf = ldlm_cancel_lru_policy(ns, flags);
LASSERT(pf != NULL);
while (!list_empty(&ns->ns_unused_list)) {
ldlm_policy_res_t result;
if (remained-- <= 0)
break;
if (max && added >= max)
break;
list_for_each_entry_safe(lock, next, &ns->ns_unused_list,
l_lru) {
LASSERT(!(lock->l_flags & LDLM_FL_BL_AST));
if (flags & LDLM_CANCEL_NO_WAIT &&
lock->l_flags & LDLM_FL_SKIPPED)
continue;
if (!(lock->l_flags & LDLM_FL_CANCELING))
break;
ldlm_lock_remove_from_lru_nolock(lock);
}
if (&lock->l_lru == &ns->ns_unused_list)
break;
LDLM_LOCK_GET(lock);
spin_unlock(&ns->ns_lock);
lu_ref_add(&lock->l_reference, __FUNCTION__, current);
result = pf(ns, lock, unused, added, count);
if (result == LDLM_POLICY_KEEP_LOCK) {
lu_ref_del(&lock->l_reference,
__FUNCTION__, current);
LDLM_LOCK_RELEASE(lock);
spin_lock(&ns->ns_lock);
break;
}
if (result == LDLM_POLICY_SKIP_LOCK) {
lu_ref_del(&lock->l_reference,
__func__, current);
LDLM_LOCK_RELEASE(lock);
spin_lock(&ns->ns_lock);
continue;
}
lock_res_and_lock(lock);
if ((lock->l_flags & LDLM_FL_CANCELING) ||
(ldlm_lock_remove_from_lru(lock) == 0)) {
unlock_res_and_lock(lock);
lu_ref_del(&lock->l_reference,
__FUNCTION__, current);
LDLM_LOCK_RELEASE(lock);
spin_lock(&ns->ns_lock);
continue;
}
LASSERT(!lock->l_readers && !lock->l_writers);
lock->l_flags &= ~LDLM_FL_CANCEL_ON_BLOCK;
lock->l_flags |= LDLM_FL_CBPENDING | LDLM_FL_CANCELING;
LASSERT(list_empty(&lock->l_bl_ast));
list_add(&lock->l_bl_ast, cancels);
unlock_res_and_lock(lock);
lu_ref_del(&lock->l_reference, __FUNCTION__, current);
spin_lock(&ns->ns_lock);
added++;
unused--;
}
spin_unlock(&ns->ns_lock);
RETURN(added);
}
int ldlm_cancel_lru_local(struct ldlm_namespace *ns, struct list_head *cancels,
int count, int max, ldlm_cancel_flags_t cancel_flags,
int flags)
{
int added;
added = ldlm_prepare_lru_list(ns, cancels, count, max, flags);
if (added <= 0)
return added;
return ldlm_cli_cancel_list_local(cancels, added, cancel_flags);
}
int ldlm_cancel_lru(struct ldlm_namespace *ns, int nr,
ldlm_cancel_flags_t cancel_flags,
int flags)
{
LIST_HEAD(cancels);
int count, rc;
ENTRY;
count = ldlm_prepare_lru_list(ns, &cancels, nr, 0, flags);
rc = ldlm_bl_to_thread_list(ns, NULL, &cancels, count, cancel_flags);
if (rc == 0)
RETURN(count);
RETURN(0);
}
int ldlm_cancel_resource_local(struct ldlm_resource *res,
struct list_head *cancels,
ldlm_policy_data_t *policy,
ldlm_mode_t mode, int lock_flags,
ldlm_cancel_flags_t cancel_flags, void *opaque)
{
struct ldlm_lock *lock;
int count = 0;
ENTRY;
lock_res(res);
list_for_each_entry(lock, &res->lr_granted, l_res_link) {
if (opaque != NULL && lock->l_ast_data != opaque) {
LDLM_ERROR(lock, "data %p doesn't match opaque %p",
lock->l_ast_data, opaque);
continue;
}
if (lock->l_readers || lock->l_writers)
continue;
if (lock->l_flags & LDLM_FL_BL_AST ||
lock->l_flags & LDLM_FL_CANCELING)
continue;
if (lockmode_compat(lock->l_granted_mode, mode))
continue;
if (policy && (lock->l_resource->lr_type == LDLM_IBITS) &&
!(lock->l_policy_data.l_inodebits.bits &
policy->l_inodebits.bits))
continue;
lock->l_flags |= LDLM_FL_CBPENDING | LDLM_FL_CANCELING |
lock_flags;
LASSERT(list_empty(&lock->l_bl_ast));
list_add(&lock->l_bl_ast, cancels);
LDLM_LOCK_GET(lock);
count++;
}
unlock_res(res);
RETURN(ldlm_cli_cancel_list_local(cancels, count, cancel_flags));
}
int ldlm_cli_cancel_list(struct list_head *cancels, int count,
struct ptlrpc_request *req, ldlm_cancel_flags_t flags)
{
struct ldlm_lock *lock;
int res = 0;
ENTRY;
if (list_empty(cancels) || count == 0)
RETURN(0);
while (count > 0) {
LASSERT(!list_empty(cancels));
lock = list_entry(cancels->next, struct ldlm_lock,
l_bl_ast);
LASSERT(lock->l_conn_export);
if (exp_connect_cancelset(lock->l_conn_export)) {
res = count;
if (req)
ldlm_cancel_pack(req, cancels, count);
else
res = ldlm_cli_cancel_req(lock->l_conn_export,
cancels, count,
flags);
} else {
res = ldlm_cli_cancel_req(lock->l_conn_export,
cancels, 1, flags);
}
if (res < 0) {
CDEBUG_LIMIT(res == -ESHUTDOWN ? D_DLMTRACE : D_ERROR,
"ldlm_cli_cancel_list: %d\n", res);
res = count;
}
count -= res;
ldlm_lock_list_put(cancels, l_bl_ast, res);
}
LASSERT(count == 0);
RETURN(0);
}
int ldlm_cli_cancel_unused_resource(struct ldlm_namespace *ns,
const struct ldlm_res_id *res_id,
ldlm_policy_data_t *policy,
ldlm_mode_t mode,
ldlm_cancel_flags_t flags,
void *opaque)
{
struct ldlm_resource *res;
LIST_HEAD(cancels);
int count;
int rc;
ENTRY;
res = ldlm_resource_get(ns, NULL, res_id, 0, 0);
if (res == NULL) {
CDEBUG(D_INFO, "No resource "LPU64"\n", res_id->name[0]);
RETURN(0);
}
LDLM_RESOURCE_ADDREF(res);
count = ldlm_cancel_resource_local(res, &cancels, policy, mode,
0, flags | LCF_BL_AST, opaque);
rc = ldlm_cli_cancel_list(&cancels, count, NULL, flags);
if (rc != ELDLM_OK)
CERROR("ldlm_cli_cancel_unused_resource: %d\n", rc);
LDLM_RESOURCE_DELREF(res);
ldlm_resource_putref(res);
RETURN(0);
}
static int ldlm_cli_hash_cancel_unused(cfs_hash_t *hs, cfs_hash_bd_t *bd,
struct hlist_node *hnode, void *arg)
{
struct ldlm_resource *res = cfs_hash_object(hs, hnode);
struct ldlm_cli_cancel_arg *lc = arg;
int rc;
rc = ldlm_cli_cancel_unused_resource(ldlm_res_to_ns(res), &res->lr_name,
NULL, LCK_MINMODE,
lc->lc_flags, lc->lc_opaque);
if (rc != 0) {
CERROR("ldlm_cli_cancel_unused ("LPU64"): %d\n",
res->lr_name.name[0], rc);
}
return 0;
}
int ldlm_cli_cancel_unused(struct ldlm_namespace *ns,
const struct ldlm_res_id *res_id,
ldlm_cancel_flags_t flags, void *opaque)
{
struct ldlm_cli_cancel_arg arg = {
.lc_flags = flags,
.lc_opaque = opaque,
};
ENTRY;
if (ns == NULL)
RETURN(ELDLM_OK);
if (res_id != NULL) {
RETURN(ldlm_cli_cancel_unused_resource(ns, res_id, NULL,
LCK_MINMODE, flags,
opaque));
} else {
cfs_hash_for_each_nolock(ns->ns_rs_hash,
ldlm_cli_hash_cancel_unused, &arg);
RETURN(ELDLM_OK);
}
}
int ldlm_resource_foreach(struct ldlm_resource *res, ldlm_iterator_t iter,
void *closure)
{
struct list_head *tmp, *next;
struct ldlm_lock *lock;
int rc = LDLM_ITER_CONTINUE;
ENTRY;
if (!res)
RETURN(LDLM_ITER_CONTINUE);
lock_res(res);
list_for_each_safe(tmp, next, &res->lr_granted) {
lock = list_entry(tmp, struct ldlm_lock, l_res_link);
if (iter(lock, closure) == LDLM_ITER_STOP)
GOTO(out, rc = LDLM_ITER_STOP);
}
list_for_each_safe(tmp, next, &res->lr_converting) {
lock = list_entry(tmp, struct ldlm_lock, l_res_link);
if (iter(lock, closure) == LDLM_ITER_STOP)
GOTO(out, rc = LDLM_ITER_STOP);
}
list_for_each_safe(tmp, next, &res->lr_waiting) {
lock = list_entry(tmp, struct ldlm_lock, l_res_link);
if (iter(lock, closure) == LDLM_ITER_STOP)
GOTO(out, rc = LDLM_ITER_STOP);
}
out:
unlock_res(res);
RETURN(rc);
}
static int ldlm_iter_helper(struct ldlm_lock *lock, void *closure)
{
struct iter_helper_data *helper = closure;
return helper->iter(lock, helper->closure);
}
static int ldlm_res_iter_helper(cfs_hash_t *hs, cfs_hash_bd_t *bd,
struct hlist_node *hnode, void *arg)
{
struct ldlm_resource *res = cfs_hash_object(hs, hnode);
return ldlm_resource_foreach(res, ldlm_iter_helper, arg) ==
LDLM_ITER_STOP;
}
void ldlm_namespace_foreach(struct ldlm_namespace *ns,
ldlm_iterator_t iter, void *closure)
{
struct iter_helper_data helper = { iter: iter, closure: closure };
cfs_hash_for_each_nolock(ns->ns_rs_hash,
ldlm_res_iter_helper, &helper);
}
int ldlm_resource_iterate(struct ldlm_namespace *ns,
const struct ldlm_res_id *res_id,
ldlm_iterator_t iter, void *data)
{
struct ldlm_resource *res;
int rc;
ENTRY;
if (ns == NULL) {
CERROR("must pass in namespace\n");
LBUG();
}
res = ldlm_resource_get(ns, NULL, res_id, 0, 0);
if (res == NULL)
RETURN(0);
LDLM_RESOURCE_ADDREF(res);
rc = ldlm_resource_foreach(res, iter, data);
LDLM_RESOURCE_DELREF(res);
ldlm_resource_putref(res);
RETURN(rc);
}
static int ldlm_chain_lock_for_replay(struct ldlm_lock *lock, void *closure)
{
struct list_head *list = closure;
LASSERTF(list_empty(&lock->l_pending_chain),
"lock %p next %p prev %p\n",
lock, &lock->l_pending_chain.next,&lock->l_pending_chain.prev);
if (!(lock->l_flags & (LDLM_FL_FAILED|LDLM_FL_CANCELING))) {
list_add(&lock->l_pending_chain, list);
LDLM_LOCK_GET(lock);
}
return LDLM_ITER_CONTINUE;
}
static int replay_lock_interpret(const struct lu_env *env,
struct ptlrpc_request *req,
struct ldlm_async_args *aa, int rc)
{
struct ldlm_lock *lock;
struct ldlm_reply *reply;
struct obd_export *exp;
ENTRY;
atomic_dec(&req->rq_import->imp_replay_inflight);
if (rc != ELDLM_OK)
GOTO(out, rc);
reply = req_capsule_server_get(&req->rq_pill, &RMF_DLM_REP);
if (reply == NULL)
GOTO(out, rc = -EPROTO);
lock = ldlm_handle2lock(&aa->lock_handle);
if (!lock) {
CERROR("received replay ack for unknown local cookie "LPX64
" remote cookie "LPX64 " from server %s id %s\n",
aa->lock_handle.cookie, reply->lock_handle.cookie,
req->rq_export->exp_client_uuid.uuid,
libcfs_id2str(req->rq_peer));
GOTO(out, rc = -ESTALE);
}
exp = req->rq_export;
if (exp && exp->exp_lock_hash) {
cfs_hash_rehash_key(exp->exp_lock_hash,
&lock->l_remote_handle,
&reply->lock_handle,
&lock->l_exp_hash);
} else {
lock->l_remote_handle = reply->lock_handle;
}
LDLM_DEBUG(lock, "replayed lock:");
ptlrpc_import_recovery_state_machine(req->rq_import);
LDLM_LOCK_PUT(lock);
out:
if (rc != ELDLM_OK)
ptlrpc_connect_import(req->rq_import);
RETURN(rc);
}
static int replay_one_lock(struct obd_import *imp, struct ldlm_lock *lock)
{
struct ptlrpc_request *req;
struct ldlm_async_args *aa;
struct ldlm_request *body;
int flags;
ENTRY;
if (lock->l_flags & LDLM_FL_CANCELING) {
LDLM_DEBUG(lock, "Not replaying canceled lock:");
RETURN(0);
}
if (lock->l_flags & LDLM_FL_CANCEL_ON_BLOCK) {
LDLM_DEBUG(lock, "Not replaying reply-less lock:");
ldlm_lock_cancel(lock);
RETURN(0);
}
if (lock->l_granted_mode == lock->l_req_mode)
flags = LDLM_FL_REPLAY | LDLM_FL_BLOCK_GRANTED;
else if (lock->l_granted_mode)
flags = LDLM_FL_REPLAY | LDLM_FL_BLOCK_CONV;
else if (!list_empty(&lock->l_res_link))
flags = LDLM_FL_REPLAY | LDLM_FL_BLOCK_WAIT;
else
flags = LDLM_FL_REPLAY;
req = ptlrpc_request_alloc_pack(imp, &RQF_LDLM_ENQUEUE,
LUSTRE_DLM_VERSION, LDLM_ENQUEUE);
if (req == NULL)
RETURN(-ENOMEM);
req->rq_send_state = LUSTRE_IMP_REPLAY_LOCKS;
body = req_capsule_client_get(&req->rq_pill, &RMF_DLM_REQ);
ldlm_lock2desc(lock, &body->lock_desc);
body->lock_flags = ldlm_flags_to_wire(flags);
ldlm_lock2handle(lock, &body->lock_handle[0]);
if (lock->l_lvb_len > 0)
req_capsule_extend(&req->rq_pill, &RQF_LDLM_ENQUEUE_LVB);
req_capsule_set_size(&req->rq_pill, &RMF_DLM_LVB, RCL_SERVER,
lock->l_lvb_len);
ptlrpc_request_set_replen(req);
lustre_msg_set_flags(req->rq_reqmsg, MSG_REQ_REPLAY_DONE);
LDLM_DEBUG(lock, "replaying lock:");
atomic_inc(&req->rq_import->imp_replay_inflight);
CLASSERT(sizeof(*aa) <= sizeof(req->rq_async_args));
aa = ptlrpc_req_async_args(req);
aa->lock_handle = body->lock_handle[0];
req->rq_interpret_reply = (ptlrpc_interpterer_t)replay_lock_interpret;
ptlrpcd_add_req(req, PDL_POLICY_LOCAL, -1);
RETURN(0);
}
static void ldlm_cancel_unused_locks_for_replay(struct ldlm_namespace *ns)
{
int canceled;
LIST_HEAD(cancels);
CDEBUG(D_DLMTRACE, "Dropping as many unused locks as possible before"
"replay for namespace %s (%d)\n",
ldlm_ns_name(ns), ns->ns_nr_unused);
canceled = ldlm_cancel_lru_local(ns, &cancels, ns->ns_nr_unused, 0,
LCF_LOCAL, LDLM_CANCEL_NO_WAIT);
CDEBUG(D_DLMTRACE, "Canceled %d unused locks from namespace %s\n",
canceled, ldlm_ns_name(ns));
}
int ldlm_replay_locks(struct obd_import *imp)
{
struct ldlm_namespace *ns = imp->imp_obd->obd_namespace;
LIST_HEAD(list);
struct ldlm_lock *lock, *next;
int rc = 0;
ENTRY;
LASSERT(atomic_read(&imp->imp_replay_inflight) == 0);
if (imp->imp_vbr_failed)
RETURN(0);
atomic_inc(&imp->imp_replay_inflight);
if (ldlm_cancel_unused_locks_before_replay)
ldlm_cancel_unused_locks_for_replay(ns);
ldlm_namespace_foreach(ns, ldlm_chain_lock_for_replay, &list);
list_for_each_entry_safe(lock, next, &list, l_pending_chain) {
list_del_init(&lock->l_pending_chain);
if (rc) {
LDLM_LOCK_RELEASE(lock);
continue;
}
rc = replay_one_lock(imp, lock);
LDLM_LOCK_RELEASE(lock);
}
atomic_dec(&imp->imp_replay_inflight);
RETURN(rc);
}
