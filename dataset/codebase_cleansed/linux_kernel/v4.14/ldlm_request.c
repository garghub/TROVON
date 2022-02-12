static void interrupted_completion_wait(void *data)
{
}
static int ldlm_request_bufsize(int count, int type)
{
int avail = LDLM_LOCKREQ_HANDLES;
if (type == LDLM_ENQUEUE)
avail -= LDLM_ENQUEUE_CANCEL_OFF;
if (count > avail)
avail = (count - avail) * sizeof(struct lustre_handle);
else
avail = 0;
return sizeof(struct ldlm_request) + avail;
}
static int ldlm_expired_completion_wait(void *data)
{
struct lock_wait_data *lwd = data;
struct ldlm_lock *lock = lwd->lwd_lock;
struct obd_import *imp;
struct obd_device *obd;
if (!lock->l_conn_export) {
static unsigned long next_dump, last_dump;
LDLM_ERROR(lock, "lock timed out (enqueued at %lld, %llds ago); not entering recovery in server code, just going back to sleep",
(s64)lock->l_last_activity,
(s64)(ktime_get_real_seconds() -
lock->l_last_activity));
if (cfs_time_after(cfs_time_current(), next_dump)) {
last_dump = next_dump;
next_dump = cfs_time_shift(300);
ldlm_namespace_dump(D_DLMTRACE,
ldlm_lock_to_ns(lock));
if (last_dump == 0)
libcfs_debug_dumplog();
}
return 0;
}
obd = lock->l_conn_export->exp_obd;
imp = obd->u.cli.cl_import;
ptlrpc_fail_import(imp, lwd->lwd_conn_cnt);
LDLM_ERROR(lock, "lock timed out (enqueued at %lld, %llds ago), entering recovery for %s@%s",
(s64)lock->l_last_activity,
(s64)(ktime_get_real_seconds() - lock->l_last_activity),
obd2cli_tgt(obd), imp->imp_connection->c_remote_uuid.uuid);
return 0;
}
static unsigned int ldlm_cp_timeout(struct ldlm_lock *lock)
{
unsigned int timeout;
if (AT_OFF)
return obd_timeout;
timeout = at_get(ldlm_lock_to_ns_at(lock));
return max(3 * timeout, ldlm_enqueue_min);
}
static int ldlm_completion_tail(struct ldlm_lock *lock, void *data)
{
long delay;
int result = 0;
if (ldlm_is_destroyed(lock) || ldlm_is_failed(lock)) {
LDLM_DEBUG(lock, "client-side enqueue: destroyed");
result = -EIO;
} else if (!data) {
LDLM_DEBUG(lock, "client-side enqueue: granted");
} else {
delay = ktime_get_real_seconds() - lock->l_last_activity;
LDLM_DEBUG(lock, "client-side enqueue: granted after %lds",
delay);
at_measured(ldlm_lock_to_ns_at(lock), delay);
}
return result;
}
int ldlm_completion_ast_async(struct ldlm_lock *lock, __u64 flags, void *data)
{
if (flags == LDLM_FL_WAIT_NOREPROC) {
LDLM_DEBUG(lock, "client-side enqueue waiting on pending lock");
return 0;
}
if (!(flags & LDLM_FL_BLOCKED_MASK)) {
wake_up(&lock->l_waitq);
return ldlm_completion_tail(lock, data);
}
LDLM_DEBUG(lock, "client-side enqueue returned a blocked lock, going forward");
return 0;
}
int ldlm_completion_ast(struct ldlm_lock *lock, __u64 flags, void *data)
{
struct lock_wait_data lwd;
struct obd_device *obd;
struct obd_import *imp = NULL;
struct l_wait_info lwi;
__u32 timeout;
int rc = 0;
if (flags == LDLM_FL_WAIT_NOREPROC) {
LDLM_DEBUG(lock, "client-side enqueue waiting on pending lock");
goto noreproc;
}
if (!(flags & LDLM_FL_BLOCKED_MASK)) {
wake_up(&lock->l_waitq);
return 0;
}
LDLM_DEBUG(lock, "client-side enqueue returned a blocked lock, sleeping");
noreproc:
obd = class_exp2obd(lock->l_conn_export);
if (obd)
imp = obd->u.cli.cl_import;
timeout = ldlm_cp_timeout(lock);
lwd.lwd_lock = lock;
lock->l_last_activity = ktime_get_real_seconds();
if (ldlm_is_no_timeout(lock)) {
LDLM_DEBUG(lock, "waiting indefinitely because of NO_TIMEOUT");
lwi = LWI_INTR(interrupted_completion_wait, &lwd);
} else {
lwi = LWI_TIMEOUT_INTR(cfs_time_seconds(timeout),
ldlm_expired_completion_wait,
interrupted_completion_wait, &lwd);
}
if (imp) {
spin_lock(&imp->imp_lock);
lwd.lwd_conn_cnt = imp->imp_conn_cnt;
spin_unlock(&imp->imp_lock);
}
if (OBD_FAIL_CHECK_RESET(OBD_FAIL_LDLM_INTR_CP_AST,
OBD_FAIL_LDLM_CP_BL_RACE | OBD_FAIL_ONCE)) {
ldlm_set_fail_loc(lock);
rc = -EINTR;
} else {
rc = l_wait_event(lock->l_waitq,
is_granted_or_cancelled(lock), &lwi);
}
if (rc) {
LDLM_DEBUG(lock, "client-side enqueue waking up: failed (%d)",
rc);
return rc;
}
return ldlm_completion_tail(lock, data);
}
static void failed_lock_cleanup(struct ldlm_namespace *ns,
struct ldlm_lock *lock, int mode)
{
int need_cancel = 0;
lock_res_and_lock(lock);
if ((lock->l_req_mode != lock->l_granted_mode) &&
!ldlm_is_failed(lock)) {
lock->l_flags |= LDLM_FL_LOCAL_ONLY | LDLM_FL_FAILED |
LDLM_FL_ATOMIC_CB | LDLM_FL_CBPENDING;
need_cancel = 1;
}
unlock_res_and_lock(lock);
if (need_cancel)
LDLM_DEBUG(lock,
"setting FL_LOCAL_ONLY | LDLM_FL_FAILED | LDLM_FL_ATOMIC_CB | LDLM_FL_CBPENDING");
else
LDLM_DEBUG(lock, "lock was granted or failed in race");
if (lock->l_resource->lr_type == LDLM_FLOCK) {
lock_res_and_lock(lock);
if (!ldlm_is_destroyed(lock)) {
ldlm_resource_unlink_lock(lock);
ldlm_lock_decref_internal_nolock(lock, mode);
ldlm_lock_destroy_nolock(lock);
}
unlock_res_and_lock(lock);
} else {
ldlm_lock_decref_internal(lock, mode);
}
}
int ldlm_cli_enqueue_fini(struct obd_export *exp, struct ptlrpc_request *req,
enum ldlm_type type, __u8 with_policy,
enum ldlm_mode mode,
__u64 *flags, void *lvb, __u32 lvb_len,
const struct lustre_handle *lockh, int rc)
{
struct ldlm_namespace *ns = exp->exp_obd->obd_namespace;
int is_replay = *flags & LDLM_FL_REPLAY;
struct ldlm_lock *lock;
struct ldlm_reply *reply;
int cleanup_phase = 1;
lock = ldlm_handle2lock(lockh);
if (!lock) {
LASSERT(type == LDLM_FLOCK);
return -ENOLCK;
}
LASSERTF(ergo(lvb_len != 0, lvb_len == lock->l_lvb_len),
"lvb_len = %d, l_lvb_len = %d\n", lvb_len, lock->l_lvb_len);
if (rc != ELDLM_OK) {
LASSERT(!is_replay);
LDLM_DEBUG(lock, "client-side enqueue END (%s)",
rc == ELDLM_LOCK_ABORTED ? "ABORTED" : "FAILED");
if (rc != ELDLM_LOCK_ABORTED)
goto cleanup;
}
reply = req_capsule_server_get(&req->rq_pill, &RMF_DLM_REP);
if (!reply) {
rc = -EPROTO;
goto cleanup;
}
if (lvb_len > 0) {
int size = 0;
size = req_capsule_get_size(&req->rq_pill, &RMF_DLM_LVB,
RCL_SERVER);
if (size < 0) {
LDLM_ERROR(lock, "Fail to get lvb_len, rc = %d", size);
rc = size;
goto cleanup;
} else if (unlikely(size > lvb_len)) {
LDLM_ERROR(lock, "Replied LVB is larger than expectation, expected = %d, replied = %d",
lvb_len, size);
rc = -EINVAL;
goto cleanup;
}
lvb_len = size;
}
if (rc == ELDLM_LOCK_ABORTED) {
if (lvb_len > 0 && lvb)
rc = ldlm_fill_lvb(lock, &req->rq_pill, RCL_SERVER,
lvb, lvb_len);
if (rc == 0)
rc = ELDLM_LOCK_ABORTED;
goto cleanup;
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
LDLM_FL_INHERIT_MASK);
unlock_res_and_lock(lock);
CDEBUG(D_INFO, "local: %p, remote cookie: %#llx, flags: 0x%llx\n",
lock, reply->lock_handle.cookie, *flags);
if ((*flags) & LDLM_FL_LOCK_CHANGED) {
int newmode = reply->lock_desc.l_req_mode;
LASSERT(!is_replay);
if (newmode && newmode != lock->l_req_mode) {
LDLM_DEBUG(lock, "server returned different mode %s",
ldlm_lockname[newmode]);
lock->l_req_mode = newmode;
}
if (!ldlm_res_eq(&reply->lock_desc.l_resource.lr_name,
&lock->l_resource->lr_name)) {
CDEBUG(D_INFO, "remote intent success, locking " DLDLMRES
" instead of " DLDLMRES "\n",
PLDLMRES(&reply->lock_desc.l_resource),
PLDLMRES(lock->l_resource));
rc = ldlm_lock_change_resource(ns, lock,
&reply->lock_desc.l_resource.lr_name);
if (rc || !lock->l_resource) {
rc = -ENOMEM;
goto cleanup;
}
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
LDLM_DEBUG(lock,
"client-side enqueue, new policy data");
}
if ((*flags) & LDLM_FL_AST_SENT) {
lock_res_and_lock(lock);
lock->l_flags |= LDLM_FL_CBPENDING | LDLM_FL_BL_AST;
unlock_res_and_lock(lock);
LDLM_DEBUG(lock, "enqueue reply includes blocking AST");
}
if (lvb_len > 0) {
lock_res_and_lock(lock);
if (lock->l_req_mode != lock->l_granted_mode)
rc = ldlm_fill_lvb(lock, &req->rq_pill, RCL_SERVER,
lock->l_lvb_data, lvb_len);
unlock_res_and_lock(lock);
if (rc < 0) {
cleanup_phase = 1;
goto cleanup;
}
}
if (!is_replay) {
rc = ldlm_lock_enqueue(ns, &lock, NULL, flags);
if (lock->l_completion_ast) {
int err = lock->l_completion_ast(lock, *flags, NULL);
if (!rc)
rc = err;
if (rc)
cleanup_phase = 1;
}
}
if (lvb_len > 0 && lvb) {
memcpy(lvb, lock->l_lvb_data, lvb_len);
}
LDLM_DEBUG(lock, "client-side enqueue END");
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
avail = min_t(int, LDLM_MAXREQSIZE, PAGE_SIZE - 512) - req_size;
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
u32 size = req_capsule_msg_size(pill, loc);
return ldlm_req_handles_avail(size, off);
}
static inline int ldlm_format_handles_avail(struct obd_import *imp,
const struct req_format *fmt,
enum req_location loc, int off)
{
u32 size = req_capsule_fmt_size(imp->imp_msg_magic, fmt, loc);
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
if (!cancels)
cancels = &head;
if (ns_connect_cancelset(ns)) {
req_capsule_filled_sizes(pill, RCL_CLIENT);
avail = ldlm_capsule_handles_avail(pill, RCL_CLIENT, canceloff);
flags = ns_connect_lru_resize(ns) ?
LDLM_LRU_FLAG_LRUR_NO_WAIT : LDLM_LRU_FLAG_AGED;
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
return rc;
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
return 0;
}
int ldlm_prep_enqueue_req(struct obd_export *exp, struct ptlrpc_request *req,
struct list_head *cancels, int count)
{
return ldlm_prep_elc_req(exp, req, LUSTRE_DLM_VERSION, LDLM_ENQUEUE,
LDLM_ENQUEUE_CANCEL_OFF, cancels, count);
}
static struct ptlrpc_request *ldlm_enqueue_pack(struct obd_export *exp,
int lvb_len)
{
struct ptlrpc_request *req;
int rc;
req = ptlrpc_request_alloc(class_exp2cliimp(exp), &RQF_LDLM_ENQUEUE);
if (!req)
return ERR_PTR(-ENOMEM);
rc = ldlm_prep_enqueue_req(exp, req, NULL, 0);
if (rc) {
ptlrpc_request_free(req);
return ERR_PTR(rc);
}
req_capsule_set_size(&req->rq_pill, &RMF_DLM_LVB, RCL_SERVER, lvb_len);
ptlrpc_request_set_replen(req);
return req;
}
int ldlm_cli_enqueue(struct obd_export *exp, struct ptlrpc_request **reqp,
struct ldlm_enqueue_info *einfo,
const struct ldlm_res_id *res_id,
union ldlm_policy_data const *policy, __u64 *flags,
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
ns = exp->exp_obd->obd_namespace;
if (is_replay) {
lock = ldlm_handle2lock_long(lockh, 0);
LASSERT(lock);
LDLM_DEBUG(lock, "client-side enqueue START");
LASSERT(exp == lock->l_conn_export);
} else {
const struct ldlm_callback_suite cbs = {
.lcs_completion = einfo->ei_cb_cp,
.lcs_blocking = einfo->ei_cb_bl,
.lcs_glimpse = einfo->ei_cb_gl
};
lock = ldlm_lock_create(ns, res_id, einfo->ei_type,
einfo->ei_mode, &cbs, einfo->ei_cbdata,
lvb_len, lvb_type);
if (IS_ERR(lock))
return PTR_ERR(lock);
ldlm_lock_addref_internal(lock, einfo->ei_mode);
ldlm_lock2handle(lock, lockh);
if (policy)
lock->l_policy_data = *policy;
if (einfo->ei_type == LDLM_EXTENT) {
if (!policy)
LBUG();
lock->l_req_extent = policy->l_extent;
}
LDLM_DEBUG(lock, "client-side enqueue START, flags %llx",
*flags);
}
lock->l_conn_export = exp;
lock->l_export = NULL;
lock->l_blocking_ast = einfo->ei_cb_bl;
lock->l_flags |= (*flags & (LDLM_FL_NO_LRU | LDLM_FL_EXCL));
lock->l_last_activity = ktime_get_real_seconds();
if (!reqp || !*reqp) {
req = ldlm_enqueue_pack(exp, lvb_len);
if (IS_ERR(req)) {
failed_lock_cleanup(ns, lock, einfo->ei_mode);
LDLM_LOCK_RELEASE(lock);
return PTR_ERR(req);
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
if (async) {
LASSERT(reqp);
return 0;
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
if (!req_passed_in && req) {
ptlrpc_req_finished(req);
if (reqp)
*reqp = NULL;
}
return rc;
}
static __u64 ldlm_cli_cancel_local(struct ldlm_lock *lock)
{
__u64 rc = LDLM_FL_LOCAL_ONLY;
if (lock->l_conn_export) {
bool local_only;
LDLM_DEBUG(lock, "client-side cancel");
lock_res_and_lock(lock);
ldlm_set_cbpending(lock);
local_only = !!(lock->l_flags &
(LDLM_FL_LOCAL_ONLY | LDLM_FL_CANCEL_ON_BLOCK));
ldlm_cancel_callback(lock);
rc = ldlm_is_bl_ast(lock) ? LDLM_FL_BL_AST : LDLM_FL_CANCELING;
unlock_res_and_lock(lock);
if (local_only) {
CDEBUG(D_DLMTRACE, "not sending request (at caller's instruction)\n");
rc = LDLM_FL_LOCAL_ONLY;
}
ldlm_lock_cancel(lock);
} else {
LDLM_ERROR(lock, "Trying to cancel local lock");
LBUG();
}
return rc;
}
static void ldlm_cancel_pack(struct ptlrpc_request *req,
struct list_head *head, int count)
{
struct ldlm_request *dlm;
struct ldlm_lock *lock;
int max, packed = 0;
dlm = req_capsule_client_get(&req->rq_pill, &RMF_DLM_REQ);
LASSERT(dlm);
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
}
static int ldlm_cli_cancel_req(struct obd_export *exp,
struct list_head *cancels,
int count, enum ldlm_cancel_flags flags)
{
struct ptlrpc_request *req = NULL;
struct obd_import *imp;
int free, sent = 0;
int rc = 0;
LASSERT(exp);
LASSERT(count > 0);
CFS_FAIL_TIMEOUT(OBD_FAIL_LDLM_PAUSE_CANCEL, cfs_fail_val);
if (CFS_FAIL_CHECK(OBD_FAIL_LDLM_CANCEL_RACE))
return count;
free = ldlm_format_handles_avail(class_exp2cliimp(exp),
&RQF_LDLM_CANCEL, RCL_CLIENT, 0);
if (count > free)
count = free;
while (1) {
imp = class_exp2cliimp(exp);
if (!imp || imp->imp_invalid) {
CDEBUG(D_DLMTRACE,
"skipping cancel on invalid import %p\n", imp);
return count;
}
req = ptlrpc_request_alloc(imp, &RQF_LDLM_CANCEL);
if (!req) {
rc = -ENOMEM;
goto out;
}
req_capsule_filled_sizes(&req->rq_pill, RCL_CLIENT);
req_capsule_set_size(&req->rq_pill, &RMF_DLM_REQ, RCL_CLIENT,
ldlm_request_bufsize(count, LDLM_CANCEL));
rc = ptlrpc_request_pack(req, LUSTRE_DLM_VERSION, LDLM_CANCEL);
if (rc) {
ptlrpc_request_free(req);
goto out;
}
req->rq_request_portal = LDLM_CANCEL_REQUEST_PORTAL;
req->rq_reply_portal = LDLM_CANCEL_REPLY_PORTAL;
ptlrpc_at_set_req_timeout(req);
ldlm_cancel_pack(req, cancels, count);
ptlrpc_request_set_replen(req);
if (flags & LCF_ASYNC) {
ptlrpcd_add_req(req);
sent = count;
goto out;
}
rc = ptlrpc_queue_wait(req);
if (rc == LUSTRE_ESTALE) {
CDEBUG(D_DLMTRACE, "client/server (nid %s) out of sync -- not fatal\n",
libcfs_nid2str(req->rq_import->
imp_connection->c_peer.nid));
rc = 0;
} else if (rc == -ETIMEDOUT &&
req->rq_import_generation == imp->imp_generation) {
ptlrpc_req_finished(req);
continue;
} else if (rc != ELDLM_OK) {
CDEBUG_LIMIT(rc == -ESHUTDOWN ? D_DLMTRACE : D_ERROR,
"Got rc %d from cancel RPC: canceling anyway\n",
rc);
break;
}
sent = count;
break;
}
ptlrpc_req_finished(req);
out:
return sent ? sent : rc;
}
static inline struct ldlm_pool *ldlm_imp2pl(struct obd_import *imp)
{
return &imp->imp_obd->obd_namespace->ns_pool;
}
int ldlm_cli_update_pool(struct ptlrpc_request *req)
{
struct obd_device *obd;
__u64 new_slv;
__u32 new_limit;
if (unlikely(!req->rq_import || !req->rq_import->imp_obd ||
!imp_connect_lru_resize(req->rq_import))) {
return 0;
}
if (lustre_msg_get_slv(req->rq_repmsg) == 0 ||
lustre_msg_get_limit(req->rq_repmsg) == 0) {
DEBUG_REQ(D_HA, req,
"Zero SLV or Limit found (SLV: %llu, Limit: %u)",
lustre_msg_get_slv(req->rq_repmsg),
lustre_msg_get_limit(req->rq_repmsg));
return 0;
}
new_limit = lustre_msg_get_limit(req->rq_repmsg);
new_slv = lustre_msg_get_slv(req->rq_repmsg);
obd = req->rq_import->imp_obd;
write_lock(&obd->obd_pool_lock);
obd->obd_pool_slv = new_slv;
obd->obd_pool_limit = new_limit;
write_unlock(&obd->obd_pool_lock);
return 0;
}
int ldlm_cli_cancel(const struct lustre_handle *lockh,
enum ldlm_cancel_flags cancel_flags)
{
struct obd_export *exp;
int avail, flags, count = 1;
__u64 rc = 0;
struct ldlm_namespace *ns;
struct ldlm_lock *lock;
LIST_HEAD(cancels);
lock = ldlm_handle2lock_long(lockh, 0);
if (!lock) {
LDLM_DEBUG_NOLOCK("lock is already being destroyed");
return 0;
}
lock_res_and_lock(lock);
if (ldlm_is_canceling(lock) && (cancel_flags & LCF_ASYNC)) {
unlock_res_and_lock(lock);
LDLM_LOCK_RELEASE(lock);
return 0;
}
ldlm_set_canceling(lock);
unlock_res_and_lock(lock);
rc = ldlm_cli_cancel_local(lock);
if (rc == LDLM_FL_LOCAL_ONLY || cancel_flags & LCF_LOCAL) {
LDLM_LOCK_RELEASE(lock);
return 0;
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
LDLM_LRU_FLAG_LRUR : LDLM_LRU_FLAG_AGED;
count += ldlm_cancel_lru_local(ns, &cancels, 0, avail - 1,
LCF_BL_AST, flags);
}
ldlm_cli_cancel_list(&cancels, count, NULL, cancel_flags);
return 0;
}
int ldlm_cli_cancel_list_local(struct list_head *cancels, int count,
enum ldlm_cancel_flags flags)
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
return count;
}
static enum ldlm_policy_res
ldlm_cancel_no_wait_policy(struct ldlm_namespace *ns, struct ldlm_lock *lock,
int unused, int added, int count)
{
enum ldlm_policy_res result = LDLM_POLICY_CANCEL_LOCK;
switch (lock->l_resource->lr_type) {
case LDLM_EXTENT:
case LDLM_IBITS:
if (ns->ns_cancel && ns->ns_cancel(lock) != 0)
break;
default:
result = LDLM_POLICY_SKIP_LOCK;
lock_res_and_lock(lock);
ldlm_set_skipped(lock);
unlock_res_and_lock(lock);
break;
}
return result;
}
static enum ldlm_policy_res ldlm_cancel_lrur_policy(struct ldlm_namespace *ns,
struct ldlm_lock *lock,
int unused, int added,
int count)
{
unsigned long cur = cfs_time_current();
struct ldlm_pool *pl = &ns->ns_pool;
__u64 slv, lvf, lv;
unsigned long la;
if (count && added >= count)
return LDLM_POLICY_KEEP_LOCK;
if (cfs_time_after(cfs_time_current(),
cfs_time_add(lock->l_last_used, ns->ns_max_age)))
return LDLM_POLICY_CANCEL_LOCK;
slv = ldlm_pool_get_slv(pl);
lvf = ldlm_pool_get_lvf(pl);
la = cfs_duration_sec(cfs_time_sub(cur, lock->l_last_used));
lv = lvf * la * unused;
ldlm_pool_set_clv(pl, lv);
if (slv == 0 || lv < slv)
return LDLM_POLICY_KEEP_LOCK;
return LDLM_POLICY_CANCEL_LOCK;
}
static enum ldlm_policy_res ldlm_cancel_passed_policy(struct ldlm_namespace *ns,
struct ldlm_lock *lock,
int unused, int added,
int count)
{
return (added >= count) ?
LDLM_POLICY_KEEP_LOCK : LDLM_POLICY_CANCEL_LOCK;
}
static enum ldlm_policy_res ldlm_cancel_aged_policy(struct ldlm_namespace *ns,
struct ldlm_lock *lock,
int unused, int added,
int count)
{
if ((added >= count) &&
time_before(cfs_time_current(),
cfs_time_add(lock->l_last_used, ns->ns_max_age)))
return LDLM_POLICY_KEEP_LOCK;
return LDLM_POLICY_CANCEL_LOCK;
}
static enum ldlm_policy_res
ldlm_cancel_lrur_no_wait_policy(struct ldlm_namespace *ns,
struct ldlm_lock *lock,
int unused, int added,
int count)
{
enum ldlm_policy_res result;
result = ldlm_cancel_lrur_policy(ns, lock, unused, added, count);
if (result == LDLM_POLICY_KEEP_LOCK)
return result;
return ldlm_cancel_no_wait_policy(ns, lock, unused, added, count);
}
static enum ldlm_policy_res
ldlm_cancel_default_policy(struct ldlm_namespace *ns, struct ldlm_lock *lock,
int unused, int added, int count)
{
return (added >= count) ?
LDLM_POLICY_KEEP_LOCK : LDLM_POLICY_CANCEL_LOCK;
}
static ldlm_cancel_lru_policy_t
ldlm_cancel_lru_policy(struct ldlm_namespace *ns, int flags)
{
if (flags & LDLM_LRU_FLAG_NO_WAIT)
return ldlm_cancel_no_wait_policy;
if (ns_connect_lru_resize(ns)) {
if (flags & LDLM_LRU_FLAG_SHRINK)
return ldlm_cancel_passed_policy;
else if (flags & LDLM_LRU_FLAG_LRUR)
return ldlm_cancel_lrur_policy;
else if (flags & LDLM_LRU_FLAG_PASSED)
return ldlm_cancel_passed_policy;
else if (flags & LDLM_LRU_FLAG_LRUR_NO_WAIT)
return ldlm_cancel_lrur_no_wait_policy;
} else {
if (flags & LDLM_LRU_FLAG_AGED)
return ldlm_cancel_aged_policy;
}
return ldlm_cancel_default_policy;
}
static int ldlm_prepare_lru_list(struct ldlm_namespace *ns,
struct list_head *cancels, int count, int max,
int flags)
{
ldlm_cancel_lru_policy_t pf;
struct ldlm_lock *lock, *next;
int added = 0, unused, remained;
int no_wait = flags & (LDLM_LRU_FLAG_NO_WAIT | LDLM_LRU_FLAG_LRUR_NO_WAIT);
spin_lock(&ns->ns_lock);
unused = ns->ns_nr_unused;
remained = unused;
if (!ns_connect_lru_resize(ns))
count += unused - ns->ns_max_unused;
pf = ldlm_cancel_lru_policy(ns, flags);
LASSERT(pf);
while (!list_empty(&ns->ns_unused_list)) {
enum ldlm_policy_res result;
time_t last_use = 0;
if (remained-- <= 0)
break;
if (max && added >= max)
break;
list_for_each_entry_safe(lock, next, &ns->ns_unused_list,
l_lru) {
LASSERT(!ldlm_is_bl_ast(lock));
if (no_wait && ldlm_is_skipped(lock))
continue;
last_use = lock->l_last_used;
if (last_use == cfs_time_current())
continue;
if (!ldlm_is_canceling(lock))
break;
ldlm_lock_remove_from_lru_nolock(lock);
}
if (&lock->l_lru == &ns->ns_unused_list)
break;
LDLM_LOCK_GET(lock);
spin_unlock(&ns->ns_lock);
lu_ref_add(&lock->l_reference, __func__, current);
result = pf(ns, lock, unused, added, count);
if (result == LDLM_POLICY_KEEP_LOCK) {
lu_ref_del(&lock->l_reference,
__func__, current);
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
if (ldlm_is_canceling(lock) ||
(ldlm_lock_remove_from_lru_check(lock, last_use) == 0)) {
unlock_res_and_lock(lock);
lu_ref_del(&lock->l_reference,
__func__, current);
LDLM_LOCK_RELEASE(lock);
spin_lock(&ns->ns_lock);
continue;
}
LASSERT(!lock->l_readers && !lock->l_writers);
ldlm_clear_cancel_on_block(lock);
lock->l_flags |= LDLM_FL_CBPENDING | LDLM_FL_CANCELING;
LASSERT(list_empty(&lock->l_bl_ast));
list_add(&lock->l_bl_ast, cancels);
unlock_res_and_lock(lock);
lu_ref_del(&lock->l_reference, __func__, current);
spin_lock(&ns->ns_lock);
added++;
unused--;
}
spin_unlock(&ns->ns_lock);
return added;
}
int ldlm_cancel_lru_local(struct ldlm_namespace *ns,
struct list_head *cancels, int count, int max,
enum ldlm_cancel_flags cancel_flags, int flags)
{
int added;
added = ldlm_prepare_lru_list(ns, cancels, count, max, flags);
if (added <= 0)
return added;
return ldlm_cli_cancel_list_local(cancels, added, cancel_flags);
}
int ldlm_cancel_lru(struct ldlm_namespace *ns, int nr,
enum ldlm_cancel_flags cancel_flags,
int flags)
{
LIST_HEAD(cancels);
int count, rc;
count = ldlm_prepare_lru_list(ns, &cancels, nr, 0, flags);
rc = ldlm_bl_to_thread_list(ns, NULL, &cancels, count, cancel_flags);
if (rc == 0)
return count;
return 0;
}
int ldlm_cancel_resource_local(struct ldlm_resource *res,
struct list_head *cancels,
union ldlm_policy_data *policy,
enum ldlm_mode mode, __u64 lock_flags,
enum ldlm_cancel_flags cancel_flags,
void *opaque)
{
struct ldlm_lock *lock;
int count = 0;
lock_res(res);
list_for_each_entry(lock, &res->lr_granted, l_res_link) {
if (opaque && lock->l_ast_data != opaque) {
LDLM_ERROR(lock, "data %p doesn't match opaque %p",
lock->l_ast_data, opaque);
continue;
}
if (lock->l_readers || lock->l_writers)
continue;
if (ldlm_is_bl_ast(lock) || ldlm_is_canceling(lock))
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
return ldlm_cli_cancel_list_local(cancels, count, cancel_flags);
}
int ldlm_cli_cancel_list(struct list_head *cancels, int count,
struct ptlrpc_request *req,
enum ldlm_cancel_flags flags)
{
struct ldlm_lock *lock;
int res = 0;
if (list_empty(cancels) || count == 0)
return 0;
while (count > 0) {
LASSERT(!list_empty(cancels));
lock = list_entry(cancels->next, struct ldlm_lock, l_bl_ast);
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
"%s: %d\n", __func__, res);
res = count;
}
count -= res;
ldlm_lock_list_put(cancels, l_bl_ast, res);
}
LASSERT(count == 0);
return 0;
}
int ldlm_cli_cancel_unused_resource(struct ldlm_namespace *ns,
const struct ldlm_res_id *res_id,
union ldlm_policy_data *policy,
enum ldlm_mode mode,
enum ldlm_cancel_flags flags,
void *opaque)
{
struct ldlm_resource *res;
LIST_HEAD(cancels);
int count;
int rc;
res = ldlm_resource_get(ns, NULL, res_id, 0, 0);
if (IS_ERR(res)) {
CDEBUG(D_INFO, "No resource %llu\n", res_id->name[0]);
return 0;
}
LDLM_RESOURCE_ADDREF(res);
count = ldlm_cancel_resource_local(res, &cancels, policy, mode,
0, flags | LCF_BL_AST, opaque);
rc = ldlm_cli_cancel_list(&cancels, count, NULL, flags);
if (rc != ELDLM_OK)
CERROR("canceling unused lock " DLDLMRES ": rc = %d\n",
PLDLMRES(res), rc);
LDLM_RESOURCE_DELREF(res);
ldlm_resource_putref(res);
return 0;
}
static int ldlm_cli_hash_cancel_unused(struct cfs_hash *hs,
struct cfs_hash_bd *bd,
struct hlist_node *hnode, void *arg)
{
struct ldlm_resource *res = cfs_hash_object(hs, hnode);
struct ldlm_cli_cancel_arg *lc = arg;
ldlm_cli_cancel_unused_resource(ldlm_res_to_ns(res), &res->lr_name,
NULL, LCK_MINMODE,
lc->lc_flags, lc->lc_opaque);
return 0;
}
int ldlm_cli_cancel_unused(struct ldlm_namespace *ns,
const struct ldlm_res_id *res_id,
enum ldlm_cancel_flags flags, void *opaque)
{
struct ldlm_cli_cancel_arg arg = {
.lc_flags = flags,
.lc_opaque = opaque,
};
if (!ns)
return ELDLM_OK;
if (res_id) {
return ldlm_cli_cancel_unused_resource(ns, res_id, NULL,
LCK_MINMODE, flags,
opaque);
} else {
cfs_hash_for_each_nolock(ns->ns_rs_hash,
ldlm_cli_hash_cancel_unused, &arg, 0);
return ELDLM_OK;
}
}
static int ldlm_resource_foreach(struct ldlm_resource *res,
ldlm_iterator_t iter, void *closure)
{
struct list_head *tmp, *next;
struct ldlm_lock *lock;
int rc = LDLM_ITER_CONTINUE;
if (!res)
return LDLM_ITER_CONTINUE;
lock_res(res);
list_for_each_safe(tmp, next, &res->lr_granted) {
lock = list_entry(tmp, struct ldlm_lock, l_res_link);
if (iter(lock, closure) == LDLM_ITER_STOP) {
rc = LDLM_ITER_STOP;
goto out;
}
}
list_for_each_safe(tmp, next, &res->lr_waiting) {
lock = list_entry(tmp, struct ldlm_lock, l_res_link);
if (iter(lock, closure) == LDLM_ITER_STOP) {
rc = LDLM_ITER_STOP;
goto out;
}
}
out:
unlock_res(res);
return rc;
}
static int ldlm_iter_helper(struct ldlm_lock *lock, void *closure)
{
struct iter_helper_data *helper = closure;
return helper->iter(lock, helper->closure);
}
static int ldlm_res_iter_helper(struct cfs_hash *hs, struct cfs_hash_bd *bd,
struct hlist_node *hnode, void *arg)
{
struct ldlm_resource *res = cfs_hash_object(hs, hnode);
return ldlm_resource_foreach(res, ldlm_iter_helper, arg) ==
LDLM_ITER_STOP;
}
static void ldlm_namespace_foreach(struct ldlm_namespace *ns,
ldlm_iterator_t iter, void *closure)
{
struct iter_helper_data helper = {
.iter = iter,
.closure = closure,
};
cfs_hash_for_each_nolock(ns->ns_rs_hash,
ldlm_res_iter_helper, &helper, 0);
}
int ldlm_resource_iterate(struct ldlm_namespace *ns,
const struct ldlm_res_id *res_id,
ldlm_iterator_t iter, void *data)
{
struct ldlm_resource *res;
int rc;
LASSERTF(ns, "must pass in namespace\n");
res = ldlm_resource_get(ns, NULL, res_id, 0, 0);
if (IS_ERR(res))
return 0;
LDLM_RESOURCE_ADDREF(res);
rc = ldlm_resource_foreach(res, iter, data);
LDLM_RESOURCE_DELREF(res);
ldlm_resource_putref(res);
return rc;
}
static int ldlm_chain_lock_for_replay(struct ldlm_lock *lock, void *closure)
{
struct list_head *list = closure;
LASSERTF(list_empty(&lock->l_pending_chain),
"lock %p next %p prev %p\n",
lock, &lock->l_pending_chain.next,
&lock->l_pending_chain.prev);
if (!(lock->l_flags & (LDLM_FL_FAILED | LDLM_FL_BL_DONE))) {
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
atomic_dec(&req->rq_import->imp_replay_inflight);
if (rc != ELDLM_OK)
goto out;
reply = req_capsule_server_get(&req->rq_pill, &RMF_DLM_REP);
if (!reply) {
rc = -EPROTO;
goto out;
}
lock = ldlm_handle2lock(&aa->lock_handle);
if (!lock) {
CERROR("received replay ack for unknown local cookie %#llx remote cookie %#llx from server %s id %s\n",
aa->lock_handle.cookie, reply->lock_handle.cookie,
req->rq_export->exp_client_uuid.uuid,
libcfs_id2str(req->rq_peer));
rc = -ESTALE;
goto out;
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
return rc;
}
static int replay_one_lock(struct obd_import *imp, struct ldlm_lock *lock)
{
struct ptlrpc_request *req;
struct ldlm_async_args *aa;
struct ldlm_request *body;
int flags;
if (ldlm_is_bl_done(lock)) {
LDLM_DEBUG(lock, "Not replaying canceled lock:");
return 0;
}
if (ldlm_is_cancel_on_block(lock)) {
LDLM_DEBUG(lock, "Not replaying reply-less lock:");
ldlm_lock_cancel(lock);
return 0;
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
if (!req)
return -ENOMEM;
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
BUILD_BUG_ON(sizeof(*aa) > sizeof(req->rq_async_args));
aa = ptlrpc_req_async_args(req);
aa->lock_handle = body->lock_handle[0];
req->rq_interpret_reply = (ptlrpc_interpterer_t)replay_lock_interpret;
ptlrpcd_add_req(req);
return 0;
}
static void ldlm_cancel_unused_locks_for_replay(struct ldlm_namespace *ns)
{
int canceled;
LIST_HEAD(cancels);
CDEBUG(D_DLMTRACE, "Dropping as many unused locks as possible before replay for namespace %s (%d)\n",
ldlm_ns_name(ns), ns->ns_nr_unused);
canceled = ldlm_cancel_lru_local(ns, &cancels, ns->ns_nr_unused, 0,
LCF_LOCAL, LDLM_LRU_FLAG_NO_WAIT);
CDEBUG(D_DLMTRACE, "Canceled %d unused locks from namespace %s\n",
canceled, ldlm_ns_name(ns));
}
int ldlm_replay_locks(struct obd_import *imp)
{
struct ldlm_namespace *ns = imp->imp_obd->obd_namespace;
LIST_HEAD(list);
struct ldlm_lock *lock, *next;
int rc = 0;
LASSERT(atomic_read(&imp->imp_replay_inflight) == 0);
if (imp->imp_vbr_failed)
return 0;
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
return rc;
}
