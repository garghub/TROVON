int osc_lock_is_lockless(const struct osc_lock *olck)
{
return (olck->ols_cl.cls_ops == &osc_lock_lockless_ops);
}
static struct ldlm_lock *osc_handle_ptr(struct lustre_handle *handle)
{
struct ldlm_lock *lock;
lock = ldlm_handle2lock(handle);
if (lock != NULL)
LDLM_LOCK_PUT(lock);
return lock;
}
static int osc_lock_invariant(struct osc_lock *ols)
{
struct ldlm_lock *lock = osc_handle_ptr(&ols->ols_handle);
struct ldlm_lock *olock = ols->ols_lock;
int handle_used = lustre_handle_is_used(&ols->ols_handle);
if (ergo(osc_lock_is_lockless(ols),
ols->ols_locklessable && ols->ols_lock == NULL))
return 1;
if (!ergo(olock != NULL, handle_used))
return 0;
if (!ergo(olock != NULL,
olock->l_handle.h_cookie == ols->ols_handle.cookie))
return 0;
if (!ergo(handle_used,
ergo(lock != NULL && olock != NULL, lock == olock) &&
ergo(lock == NULL, olock == NULL)))
return 0;
if (!ergo(ols->ols_state == OLS_CANCELLED,
olock == NULL && !handle_used))
return 0;
if (!ergo(olock != NULL && ols->ols_state < OLS_CANCELLED,
((olock->l_flags & LDLM_FL_DESTROYED) == 0)))
return 0;
if (!ergo(ols->ols_state == OLS_GRANTED,
olock != NULL &&
olock->l_req_mode == olock->l_granted_mode &&
ols->ols_hold))
return 0;
return 1;
}
static void osc_lock_detach(const struct lu_env *env, struct osc_lock *olck)
{
struct ldlm_lock *dlmlock;
spin_lock(&osc_ast_guard);
dlmlock = olck->ols_lock;
if (dlmlock == NULL) {
spin_unlock(&osc_ast_guard);
return;
}
olck->ols_lock = NULL;
dlmlock->l_ast_data = NULL;
olck->ols_handle.cookie = 0ULL;
spin_unlock(&osc_ast_guard);
lock_res_and_lock(dlmlock);
if (dlmlock->l_granted_mode == dlmlock->l_req_mode) {
struct cl_object *obj = olck->ols_cl.cls_obj;
struct cl_attr *attr = &osc_env_info(env)->oti_attr;
__u64 old_kms;
cl_object_attr_lock(obj);
old_kms = cl2osc(obj)->oo_oinfo->loi_kms;
attr->cat_kms = ldlm_extent_shift_kms(dlmlock, old_kms);
cl_object_attr_set(env, obj, attr, CAT_KMS);
cl_object_attr_unlock(obj);
}
unlock_res_and_lock(dlmlock);
LASSERT(olck->ols_has_ref);
lu_ref_del(&dlmlock->l_reference, "osc_lock", olck);
LDLM_LOCK_RELEASE(dlmlock);
olck->ols_has_ref = 0;
}
static int osc_lock_unhold(struct osc_lock *ols)
{
int result = 0;
if (ols->ols_hold) {
ols->ols_hold = 0;
result = osc_cancel_base(&ols->ols_handle,
ols->ols_einfo.ei_mode);
}
return result;
}
static int osc_lock_unuse(const struct lu_env *env,
const struct cl_lock_slice *slice)
{
struct osc_lock *ols = cl2osc_lock(slice);
LINVRNT(osc_lock_invariant(ols));
switch (ols->ols_state) {
case OLS_NEW:
LASSERT(!ols->ols_hold);
LASSERT(ols->ols_agl);
return 0;
case OLS_UPCALL_RECEIVED:
osc_lock_unhold(ols);
case OLS_ENQUEUED:
LASSERT(!ols->ols_hold);
osc_lock_detach(env, ols);
ols->ols_state = OLS_NEW;
return 0;
case OLS_GRANTED:
LASSERT(!ols->ols_glimpse);
LASSERT(ols->ols_hold);
ols->ols_state = OLS_RELEASED;
return osc_lock_unhold(ols);
default:
CERROR("Impossible state: %d\n", ols->ols_state);
LBUG();
}
}
static void osc_lock_fini(const struct lu_env *env,
struct cl_lock_slice *slice)
{
struct osc_lock *ols = cl2osc_lock(slice);
LINVRNT(osc_lock_invariant(ols));
osc_lock_unhold(ols);
LASSERT(ols->ols_lock == NULL);
LASSERT(atomic_read(&ols->ols_pageref) == 0 ||
atomic_read(&ols->ols_pageref) == _PAGEREF_MAGIC);
kmem_cache_free(osc_lock_kmem, ols);
}
static void osc_lock_build_policy(const struct lu_env *env,
const struct cl_lock *lock,
ldlm_policy_data_t *policy)
{
const struct cl_lock_descr *d = &lock->cll_descr;
osc_index2policy(policy, d->cld_obj, d->cld_start, d->cld_end);
policy->l_extent.gid = d->cld_gid;
}
static __u64 osc_enq2ldlm_flags(__u32 enqflags)
{
__u64 result = 0;
LASSERT((enqflags & ~CEF_MASK) == 0);
if (enqflags & CEF_NONBLOCK)
result |= LDLM_FL_BLOCK_NOWAIT;
if (enqflags & CEF_ASYNC)
result |= LDLM_FL_HAS_INTENT;
if (enqflags & CEF_DISCARD_DATA)
result |= LDLM_FL_AST_DISCARD_DATA;
return result;
}
static struct osc_lock *osc_ast_data_get(struct ldlm_lock *dlm_lock)
{
struct osc_lock *olck;
lock_res_and_lock(dlm_lock);
spin_lock(&osc_ast_guard);
olck = dlm_lock->l_ast_data;
if (olck != NULL) {
struct cl_lock *lock = olck->ols_cl.cls_lock;
if (lock->cll_state < CLS_FREEING || olck->ols_has_ref) {
cl_lock_get_trust(lock);
lu_ref_add_atomic(&lock->cll_reference,
"ast", current);
} else
olck = NULL;
}
spin_unlock(&osc_ast_guard);
unlock_res_and_lock(dlm_lock);
return olck;
}
static void osc_ast_data_put(const struct lu_env *env, struct osc_lock *olck)
{
struct cl_lock *lock;
lock = olck->ols_cl.cls_lock;
lu_ref_del(&lock->cll_reference, "ast", current);
cl_lock_put(env, lock);
}
static void osc_lock_lvb_update(const struct lu_env *env, struct osc_lock *olck,
int rc)
{
struct ost_lvb *lvb;
struct cl_object *obj;
struct lov_oinfo *oinfo;
struct cl_attr *attr;
unsigned valid;
if (!(olck->ols_flags & LDLM_FL_LVB_READY))
return;
lvb = &olck->ols_lvb;
obj = olck->ols_cl.cls_obj;
oinfo = cl2osc(obj)->oo_oinfo;
attr = &osc_env_info(env)->oti_attr;
valid = CAT_BLOCKS | CAT_ATIME | CAT_CTIME | CAT_MTIME | CAT_SIZE;
cl_lvb2attr(attr, lvb);
cl_object_attr_lock(obj);
if (rc == 0) {
struct ldlm_lock *dlmlock;
__u64 size;
dlmlock = olck->ols_lock;
LASSERT(dlmlock != NULL);
*lvb = *(struct ost_lvb *)dlmlock->l_lvb_data;
size = lvb->lvb_size;
if (size > dlmlock->l_policy_data.l_extent.end)
size = dlmlock->l_policy_data.l_extent.end + 1;
if (size >= oinfo->loi_kms) {
LDLM_DEBUG(dlmlock, "lock acquired, setting rss=%llu, kms=%llu",
lvb->lvb_size, size);
valid |= CAT_KMS;
attr->cat_kms = size;
} else {
LDLM_DEBUG(dlmlock, "lock acquired, setting rss=%llu; leaving kms=%llu, end=%llu",
lvb->lvb_size, oinfo->loi_kms,
dlmlock->l_policy_data.l_extent.end);
}
ldlm_lock_allow_match_locked(dlmlock);
} else if (rc == -ENAVAIL && olck->ols_glimpse) {
CDEBUG(D_INODE, "glimpsed, setting rss=%llu; leaving kms=%llu\n",
lvb->lvb_size, oinfo->loi_kms);
} else
valid = 0;
if (valid != 0)
cl_object_attr_set(env, obj, attr, valid);
cl_object_attr_unlock(obj);
}
static void osc_lock_granted(const struct lu_env *env, struct osc_lock *olck,
struct ldlm_lock *dlmlock, int rc)
{
struct ldlm_extent *ext;
struct cl_lock *lock;
struct cl_lock_descr *descr;
LASSERT(dlmlock->l_granted_mode == dlmlock->l_req_mode);
if (olck->ols_state < OLS_GRANTED) {
lock = olck->ols_cl.cls_lock;
ext = &dlmlock->l_policy_data.l_extent;
descr = &osc_env_info(env)->oti_descr;
descr->cld_obj = lock->cll_descr.cld_obj;
descr->cld_mode = osc_ldlm2cl_lock(dlmlock->l_granted_mode);
descr->cld_start = cl_index(descr->cld_obj, ext->start);
descr->cld_end = cl_index(descr->cld_obj, ext->end);
descr->cld_gid = ext->gid;
olck->ols_state = OLS_GRANTED;
osc_lock_lvb_update(env, olck, rc);
unlock_res_and_lock(dlmlock);
cl_lock_modify(env, lock, descr);
cl_lock_signal(env, lock);
LINVRNT(osc_lock_invariant(olck));
lock_res_and_lock(dlmlock);
}
}
static void osc_lock_upcall0(const struct lu_env *env, struct osc_lock *olck)
{
struct ldlm_lock *dlmlock;
dlmlock = ldlm_handle2lock_long(&olck->ols_handle, 0);
LASSERT(dlmlock != NULL);
lock_res_and_lock(dlmlock);
spin_lock(&osc_ast_guard);
LASSERT(dlmlock->l_ast_data == olck);
LASSERT(olck->ols_lock == NULL);
olck->ols_lock = dlmlock;
spin_unlock(&osc_ast_guard);
if (dlmlock->l_granted_mode == dlmlock->l_req_mode)
osc_lock_granted(env, olck, dlmlock, 0);
unlock_res_and_lock(dlmlock);
ldlm_lock_addref(&olck->ols_handle, olck->ols_einfo.ei_mode);
olck->ols_hold = 1;
lu_ref_add(&dlmlock->l_reference, "osc_lock", olck);
olck->ols_has_ref = 1;
}
static int osc_lock_upcall(void *cookie, int errcode)
{
struct osc_lock *olck = cookie;
struct cl_lock_slice *slice = &olck->ols_cl;
struct cl_lock *lock = slice->cls_lock;
struct lu_env *env;
struct cl_env_nest nest;
env = cl_env_nested_get(&nest);
if (!IS_ERR(env)) {
int rc;
cl_lock_mutex_get(env, lock);
LASSERT(lock->cll_state >= CLS_QUEUING);
if (olck->ols_state == OLS_ENQUEUED) {
olck->ols_state = OLS_UPCALL_RECEIVED;
rc = ldlm_error2errno(errcode);
} else if (olck->ols_state == OLS_CANCELLED) {
rc = -EIO;
} else {
CERROR("Impossible state: %d\n", olck->ols_state);
LBUG();
}
if (rc) {
struct ldlm_lock *dlmlock;
dlmlock = ldlm_handle2lock(&olck->ols_handle);
if (dlmlock != NULL) {
lock_res_and_lock(dlmlock);
spin_lock(&osc_ast_guard);
LASSERT(olck->ols_lock == NULL);
dlmlock->l_ast_data = NULL;
olck->ols_handle.cookie = 0ULL;
spin_unlock(&osc_ast_guard);
ldlm_lock_fail_match_locked(dlmlock);
unlock_res_and_lock(dlmlock);
LDLM_LOCK_PUT(dlmlock);
}
} else {
if (olck->ols_glimpse)
olck->ols_glimpse = 0;
osc_lock_upcall0(env, olck);
}
if (olck->ols_locklessable && rc == -EUSERS) {
osc_object_set_contended(cl2osc(slice->cls_obj));
LASSERT(slice->cls_ops == &osc_lock_ops);
osc_lock_to_lockless(env, olck, 1);
olck->ols_state = OLS_GRANTED;
rc = 0;
} else if (olck->ols_glimpse && rc == -ENAVAIL) {
osc_lock_lvb_update(env, olck, rc);
cl_lock_delete(env, lock);
rc = 0;
}
if (rc == 0) {
if (olck->ols_agl) {
lock->cll_flags |= CLF_FROM_UPCALL;
cl_wait_try(env, lock);
lock->cll_flags &= ~CLF_FROM_UPCALL;
if (!olck->ols_glimpse)
olck->ols_agl = 0;
}
cl_lock_signal(env, lock);
cl_unuse_try(env, lock);
} else {
cl_lock_user_del(env, lock);
cl_lock_error(env, lock, rc);
}
cl_lock_hold_release(env, lock, "upcall", lock);
cl_lock_mutex_put(env, lock);
lu_ref_del(&lock->cll_reference, "upcall", lock);
cl_lock_put(env, lock);
cl_env_nested_put(&nest, env);
} else {
LBUG();
}
return errcode;
}
static void osc_lock_blocking(const struct lu_env *env,
struct ldlm_lock *dlmlock,
struct osc_lock *olck, int blocking)
{
struct cl_lock *lock = olck->ols_cl.cls_lock;
LASSERT(olck->ols_lock == dlmlock);
CLASSERT(OLS_BLOCKED < OLS_CANCELLED);
LASSERT(!osc_lock_is_lockless(olck));
osc_lock_unhold(olck);
if (blocking && olck->ols_state < OLS_BLOCKED)
olck->ols_state = OLS_BLOCKED;
cl_lock_cancel(env, lock);
cl_lock_delete(env, lock);
}
static int osc_dlm_blocking_ast0(const struct lu_env *env,
struct ldlm_lock *dlmlock,
void *data, int flag)
{
struct osc_lock *olck;
struct cl_lock *lock;
int result;
int cancel;
LASSERT(flag == LDLM_CB_BLOCKING || flag == LDLM_CB_CANCELING);
cancel = 0;
olck = osc_ast_data_get(dlmlock);
if (olck != NULL) {
lock = olck->ols_cl.cls_lock;
cl_lock_mutex_get(env, lock);
LINVRNT(osc_lock_invariant(olck));
if (olck->ols_ast_wait) {
cl_lock_signal(env, lock);
olck->ols_ast_wait = 0;
}
if (olck == dlmlock->l_ast_data) {
LASSERT(data == olck);
osc_lock_blocking(env, dlmlock,
olck, flag == LDLM_CB_BLOCKING);
} else
cancel = 1;
cl_lock_mutex_put(env, lock);
osc_ast_data_put(env, olck);
} else
cancel = (flag == LDLM_CB_BLOCKING);
if (cancel) {
struct lustre_handle *lockh;
lockh = &osc_env_info(env)->oti_handle;
ldlm_lock2handle(dlmlock, lockh);
result = ldlm_cli_cancel(lockh, LCF_ASYNC);
} else
result = 0;
return result;
}
static int osc_ldlm_blocking_ast(struct ldlm_lock *dlmlock,
struct ldlm_lock_desc *new, void *data,
int flag)
{
struct lu_env *env;
struct cl_env_nest nest;
int result;
env = cl_env_nested_get(&nest);
if (!IS_ERR(env)) {
result = osc_dlm_blocking_ast0(env, dlmlock, data, flag);
cl_env_nested_put(&nest, env);
} else {
result = PTR_ERR(env);
LBUG();
}
if (result != 0) {
if (result == -ENODATA)
result = 0;
else
CERROR("BAST failed: %d\n", result);
}
return result;
}
static int osc_ldlm_completion_ast(struct ldlm_lock *dlmlock,
__u64 flags, void *data)
{
struct cl_env_nest nest;
struct lu_env *env;
struct osc_lock *olck;
struct cl_lock *lock;
int result;
int dlmrc;
dlmrc = ldlm_completion_ast_async(dlmlock, flags, data);
env = cl_env_nested_get(&nest);
if (!IS_ERR(env)) {
olck = osc_ast_data_get(dlmlock);
if (olck != NULL) {
lock = olck->ols_cl.cls_lock;
cl_lock_mutex_get(env, lock);
LASSERT(dlmlock->l_lvb_data != NULL);
lock_res_and_lock(dlmlock);
olck->ols_lvb = *(struct ost_lvb *)dlmlock->l_lvb_data;
if (olck->ols_lock == NULL) {
} else if (dlmlock->l_granted_mode ==
dlmlock->l_req_mode) {
osc_lock_granted(env, olck, dlmlock, dlmrc);
}
unlock_res_and_lock(dlmlock);
if (dlmrc != 0) {
CL_LOCK_DEBUG(D_ERROR, env, lock,
"dlmlock returned %d\n", dlmrc);
cl_lock_error(env, lock, dlmrc);
}
cl_lock_mutex_put(env, lock);
osc_ast_data_put(env, olck);
result = 0;
} else
result = -ELDLM_NO_LOCK_DATA;
cl_env_nested_put(&nest, env);
} else
result = PTR_ERR(env);
return dlmrc ?: result;
}
static int osc_ldlm_glimpse_ast(struct ldlm_lock *dlmlock, void *data)
{
struct ptlrpc_request *req = data;
struct osc_lock *olck;
struct cl_lock *lock;
struct cl_object *obj;
struct cl_env_nest nest;
struct lu_env *env;
struct ost_lvb *lvb;
struct req_capsule *cap;
int result;
LASSERT(lustre_msg_get_opc(req->rq_reqmsg) == LDLM_GL_CALLBACK);
env = cl_env_nested_get(&nest);
if (!IS_ERR(env)) {
olck = osc_ast_data_get(dlmlock);
if (olck != NULL) {
lock = olck->ols_cl.cls_lock;
cap = &req->rq_pill;
req_capsule_extend(cap, &RQF_LDLM_GL_CALLBACK);
req_capsule_set_size(cap, &RMF_DLM_LVB, RCL_SERVER,
sizeof(*lvb));
result = req_capsule_server_pack(cap);
if (result == 0) {
lvb = req_capsule_server_get(cap, &RMF_DLM_LVB);
obj = lock->cll_descr.cld_obj;
result = cl_object_glimpse(env, obj, lvb);
}
if (!exp_connect_lvb_type(req->rq_export))
req_capsule_shrink(&req->rq_pill,
&RMF_DLM_LVB,
sizeof(struct ost_lvb_v1),
RCL_SERVER);
osc_ast_data_put(env, olck);
} else {
lustre_pack_reply(req, 1, NULL, NULL);
result = -ELDLM_NO_LOCK_DATA;
}
cl_env_nested_put(&nest, env);
} else
result = PTR_ERR(env);
req->rq_status = result;
return result;
}
static unsigned long osc_lock_weigh(const struct lu_env *env,
const struct cl_lock_slice *slice)
{
return cl_object_header(slice->cls_obj)->coh_pages;
}
static void osc_lock_build_einfo(const struct lu_env *env,
const struct cl_lock *clock,
struct osc_lock *lock,
struct ldlm_enqueue_info *einfo)
{
enum cl_lock_mode mode;
mode = clock->cll_descr.cld_mode;
if (mode == CLM_PHANTOM)
mode = CLM_READ;
einfo->ei_type = LDLM_EXTENT;
einfo->ei_mode = osc_cl_lock2ldlm(mode);
einfo->ei_cb_bl = osc_ldlm_blocking_ast;
einfo->ei_cb_cp = osc_ldlm_completion_ast;
einfo->ei_cb_gl = osc_ldlm_glimpse_ast;
einfo->ei_cbdata = lock;
}
static void osc_lock_to_lockless(const struct lu_env *env,
struct osc_lock *ols, int force)
{
struct cl_lock_slice *slice = &ols->ols_cl;
LASSERT(ols->ols_state == OLS_NEW ||
ols->ols_state == OLS_UPCALL_RECEIVED);
if (force) {
ols->ols_locklessable = 1;
slice->cls_ops = &osc_lock_lockless_ops;
} else {
struct osc_io *oio = osc_env_io(env);
struct cl_io *io = oio->oi_cl.cis_io;
struct cl_object *obj = slice->cls_obj;
struct osc_object *oob = cl2osc(obj);
const struct osc_device *osd = lu2osc_dev(obj->co_lu.lo_dev);
struct obd_connect_data *ocd;
LASSERT(io->ci_lockreq == CILR_MANDATORY ||
io->ci_lockreq == CILR_MAYBE ||
io->ci_lockreq == CILR_NEVER);
ocd = &class_exp2cliimp(osc_export(oob))->imp_connect_data;
ols->ols_locklessable = (io->ci_type != CIT_SETATTR) &&
(io->ci_lockreq == CILR_MAYBE) &&
(ocd->ocd_connect_flags & OBD_CONNECT_SRVLOCK);
if (io->ci_lockreq == CILR_NEVER ||
(ols->ols_locklessable && osc_object_is_contended(oob)) ||
(cl_io_is_trunc(io) &&
(ocd->ocd_connect_flags & OBD_CONNECT_TRUNCLOCK) &&
osd->od_lockless_truncate)) {
ols->ols_locklessable = 1;
slice->cls_ops = &osc_lock_lockless_ops;
}
}
LASSERT(ergo(ols->ols_glimpse, !osc_lock_is_lockless(ols)));
}
static int osc_lock_compatible(const struct osc_lock *qing,
const struct osc_lock *qed)
{
enum cl_lock_mode qing_mode;
enum cl_lock_mode qed_mode;
qing_mode = qing->ols_cl.cls_lock->cll_descr.cld_mode;
if (qed->ols_glimpse &&
(qed->ols_state >= OLS_UPCALL_RECEIVED || qing_mode == CLM_READ))
return 1;
qed_mode = qed->ols_cl.cls_lock->cll_descr.cld_mode;
return ((qing_mode == CLM_READ) && (qed_mode == CLM_READ));
}
static int osc_lock_enqueue_wait(const struct lu_env *env,
const struct osc_lock *olck)
{
struct cl_lock *lock = olck->ols_cl.cls_lock;
struct cl_lock_descr *descr = &lock->cll_descr;
struct cl_object_header *hdr = cl_object_header(descr->cld_obj);
struct cl_lock *scan;
struct cl_lock *conflict = NULL;
int lockless = osc_lock_is_lockless(olck);
int rc = 0;
LASSERT(cl_lock_is_mutexed(lock));
if (olck->ols_glimpse)
return 0;
spin_lock(&hdr->coh_lock_guard);
list_for_each_entry(scan, &hdr->coh_locks, cll_linkage) {
struct cl_lock_descr *cld = &scan->cll_descr;
const struct osc_lock *scan_ols;
if (scan == lock)
break;
if (scan->cll_state < CLS_QUEUING ||
scan->cll_state == CLS_FREEING ||
cld->cld_start > descr->cld_end ||
cld->cld_end < descr->cld_start)
continue;
if (scan->cll_descr.cld_mode == CLM_GROUP) {
LASSERT(descr->cld_mode != CLM_GROUP ||
descr->cld_gid != scan->cll_descr.cld_gid);
continue;
}
scan_ols = osc_lock_at(scan);
if (!lockless && osc_lock_compatible(olck, scan_ols))
continue;
cl_lock_get_trust(scan);
conflict = scan;
break;
}
spin_unlock(&hdr->coh_lock_guard);
if (conflict) {
if (lock->cll_descr.cld_mode == CLM_GROUP) {
CDEBUG(D_DLMTRACE, "group lock %p is conflicted with %p, no wait, send to server\n",
lock, conflict);
cl_lock_put(env, conflict);
rc = 0;
} else {
CDEBUG(D_DLMTRACE, "lock %p is conflicted with %p, will wait\n",
lock, conflict);
LASSERT(lock->cll_conflict == NULL);
lu_ref_add(&conflict->cll_reference, "cancel-wait",
lock);
lock->cll_conflict = conflict;
rc = CLO_WAIT;
}
}
return rc;
}
static int osc_lock_enqueue(const struct lu_env *env,
const struct cl_lock_slice *slice,
struct cl_io *unused, __u32 enqflags)
{
struct osc_lock *ols = cl2osc_lock(slice);
struct cl_lock *lock = ols->ols_cl.cls_lock;
int result;
LASSERT(cl_lock_is_mutexed(lock));
LASSERTF(ols->ols_state == OLS_NEW,
"Impossible state: %d\n", ols->ols_state);
LASSERTF(ergo(ols->ols_glimpse, lock->cll_descr.cld_mode <= CLM_READ),
"lock = %p, ols = %p\n", lock, ols);
result = osc_lock_enqueue_wait(env, ols);
if (result == 0) {
if (!osc_lock_is_lockless(ols)) {
struct osc_object *obj = cl2osc(slice->cls_obj);
struct osc_thread_info *info = osc_env_info(env);
struct ldlm_res_id *resname = &info->oti_resname;
ldlm_policy_data_t *policy = &info->oti_policy;
struct ldlm_enqueue_info *einfo = &ols->ols_einfo;
cl_lock_hold_add(env, lock, "upcall", lock);
cl_lock_user_add(env, lock);
ols->ols_state = OLS_ENQUEUED;
ostid_build_res_name(&obj->oo_oinfo->loi_oi, resname);
osc_lock_build_policy(env, lock, policy);
result = osc_enqueue_base(osc_export(obj), resname,
&ols->ols_flags, policy,
&ols->ols_lvb,
obj->oo_oinfo->loi_kms_valid,
osc_lock_upcall,
ols, einfo, &ols->ols_handle,
PTLRPCD_SET, 1, ols->ols_agl);
if (result != 0) {
cl_lock_user_del(env, lock);
cl_lock_unhold(env, lock, "upcall", lock);
if (unlikely(result == -ECANCELED)) {
ols->ols_state = OLS_NEW;
result = 0;
}
}
} else {
ols->ols_state = OLS_GRANTED;
ols->ols_owner = osc_env_io(env);
}
}
LASSERT(ergo(ols->ols_glimpse, !osc_lock_is_lockless(ols)));
return result;
}
static int osc_lock_wait(const struct lu_env *env,
const struct cl_lock_slice *slice)
{
struct osc_lock *olck = cl2osc_lock(slice);
struct cl_lock *lock = olck->ols_cl.cls_lock;
LINVRNT(osc_lock_invariant(olck));
if (olck->ols_glimpse && olck->ols_state >= OLS_UPCALL_RECEIVED) {
if (olck->ols_flags & LDLM_FL_LVB_READY) {
return 0;
} else if (olck->ols_agl) {
if (lock->cll_flags & CLF_FROM_UPCALL)
return -ENAVAIL;
olck->ols_state = OLS_NEW;
} else {
LASSERT(lock->cll_error);
return lock->cll_error;
}
}
if (olck->ols_state == OLS_NEW) {
int rc;
LASSERT(olck->ols_agl);
olck->ols_agl = 0;
olck->ols_flags &= ~LDLM_FL_BLOCK_NOWAIT;
rc = osc_lock_enqueue(env, slice, NULL, CEF_ASYNC | CEF_MUST);
if (rc != 0)
return rc;
else
return CLO_REENQUEUED;
}
LASSERT(equi(olck->ols_state >= OLS_UPCALL_RECEIVED &&
lock->cll_error == 0, olck->ols_lock != NULL));
return lock->cll_error ?: olck->ols_state >= OLS_GRANTED ? 0 : CLO_WAIT;
}
static int osc_lock_use(const struct lu_env *env,
const struct cl_lock_slice *slice)
{
struct osc_lock *olck = cl2osc_lock(slice);
int rc;
LASSERT(!olck->ols_hold);
rc = ldlm_lock_addref_try(&olck->ols_handle, olck->ols_einfo.ei_mode);
if (rc == 0) {
olck->ols_hold = 1;
olck->ols_state = OLS_GRANTED;
} else {
struct cl_lock *lock;
lock = slice->cls_lock;
LASSERT(lock->cll_state == CLS_INTRANSIT);
LASSERT(lock->cll_users > 0);
olck->ols_ast_wait = 1;
rc = CLO_WAIT;
}
return rc;
}
static int osc_lock_flush(struct osc_lock *ols, int discard)
{
struct cl_lock *lock = ols->ols_cl.cls_lock;
struct cl_env_nest nest;
struct lu_env *env;
int result = 0;
env = cl_env_nested_get(&nest);
if (!IS_ERR(env)) {
struct osc_object *obj = cl2osc(ols->ols_cl.cls_obj);
struct cl_lock_descr *descr = &lock->cll_descr;
int rc = 0;
if (descr->cld_mode >= CLM_WRITE) {
result = osc_cache_writeback_range(env, obj,
descr->cld_start, descr->cld_end,
1, discard);
LDLM_DEBUG(ols->ols_lock,
"lock %p: %d pages were %s.\n", lock, result,
discard ? "discarded" : "written");
if (result > 0)
result = 0;
}
rc = cl_lock_discard_pages(env, lock);
if (result == 0 && rc < 0)
result = rc;
cl_env_nested_put(&nest, env);
} else
result = PTR_ERR(env);
if (result == 0) {
ols->ols_flush = 1;
LINVRNT(!osc_lock_has_pages(ols));
}
return result;
}
static void osc_lock_cancel(const struct lu_env *env,
const struct cl_lock_slice *slice)
{
struct cl_lock *lock = slice->cls_lock;
struct osc_lock *olck = cl2osc_lock(slice);
struct ldlm_lock *dlmlock = olck->ols_lock;
int result = 0;
int discard;
LASSERT(cl_lock_is_mutexed(lock));
LINVRNT(osc_lock_invariant(olck));
if (dlmlock != NULL) {
int do_cancel;
discard = !!(dlmlock->l_flags & LDLM_FL_DISCARD_DATA);
if (olck->ols_state >= OLS_GRANTED)
result = osc_lock_flush(olck, discard);
osc_lock_unhold(olck);
lock_res_and_lock(dlmlock);
do_cancel = (dlmlock->l_readers == 0 &&
dlmlock->l_writers == 0);
dlmlock->l_flags |= LDLM_FL_CBPENDING;
unlock_res_and_lock(dlmlock);
if (do_cancel)
result = ldlm_cli_cancel(&olck->ols_handle, LCF_ASYNC);
if (result < 0)
CL_LOCK_DEBUG(D_ERROR, env, lock,
"lock %p cancel failure with error(%d)\n",
lock, result);
}
olck->ols_state = OLS_CANCELLED;
olck->ols_flags &= ~LDLM_FL_LVB_READY;
osc_lock_detach(env, olck);
}
static int osc_lock_has_pages(struct osc_lock *olck)
{
return 0;
}
static void osc_lock_delete(const struct lu_env *env,
const struct cl_lock_slice *slice)
{
struct osc_lock *olck;
olck = cl2osc_lock(slice);
if (olck->ols_glimpse) {
LASSERT(!olck->ols_hold);
LASSERT(!olck->ols_lock);
return;
}
LINVRNT(osc_lock_invariant(olck));
LINVRNT(!osc_lock_has_pages(olck));
osc_lock_unhold(olck);
osc_lock_detach(env, olck);
}
static void osc_lock_state(const struct lu_env *env,
const struct cl_lock_slice *slice,
enum cl_lock_state state)
{
struct osc_lock *lock = cl2osc_lock(slice);
LINVRNT(osc_lock_invariant(lock));
if (state == CLS_HELD && slice->cls_lock->cll_state != CLS_HELD) {
struct osc_io *oio = osc_env_io(env);
LASSERT(lock->ols_owner == NULL);
lock->ols_owner = oio;
} else if (state != CLS_HELD)
lock->ols_owner = NULL;
}
static int osc_lock_print(const struct lu_env *env, void *cookie,
lu_printer_t p, const struct cl_lock_slice *slice)
{
struct osc_lock *lock = cl2osc_lock(slice);
(*p)(env, cookie, "%p %#16llx %#llx %d %p ",
lock->ols_lock, lock->ols_flags, lock->ols_handle.cookie,
lock->ols_state, lock->ols_owner);
osc_lvb_print(env, cookie, p, &lock->ols_lvb);
return 0;
}
static int osc_lock_fits_into(const struct lu_env *env,
const struct cl_lock_slice *slice,
const struct cl_lock_descr *need,
const struct cl_io *io)
{
struct osc_lock *ols = cl2osc_lock(slice);
if (need->cld_enq_flags & CEF_NEVER)
return 0;
if (ols->ols_state >= OLS_CANCELLED)
return 0;
if (need->cld_mode == CLM_PHANTOM) {
if (ols->ols_agl)
return !(ols->ols_state > OLS_RELEASED);
if (ols->ols_state < OLS_GRANTED ||
ols->ols_state > OLS_RELEASED)
return 0;
} else if (need->cld_enq_flags & CEF_MUST) {
if (ols->ols_state < OLS_UPCALL_RECEIVED &&
ols->ols_locklessable)
return 0;
}
return 1;
}
static int osc_lock_lockless_unuse(const struct lu_env *env,
const struct cl_lock_slice *slice)
{
struct osc_lock *ols = cl2osc_lock(slice);
struct cl_lock *lock = slice->cls_lock;
LASSERT(ols->ols_state == OLS_GRANTED);
LINVRNT(osc_lock_invariant(ols));
cl_lock_cancel(env, lock);
cl_lock_delete(env, lock);
return 0;
}
static void osc_lock_lockless_cancel(const struct lu_env *env,
const struct cl_lock_slice *slice)
{
struct osc_lock *ols = cl2osc_lock(slice);
int result;
result = osc_lock_flush(ols, 0);
if (result)
CERROR("Pages for lockless lock %p were not purged(%d)\n",
ols, result);
ols->ols_state = OLS_CANCELLED;
}
static int osc_lock_lockless_wait(const struct lu_env *env,
const struct cl_lock_slice *slice)
{
struct osc_lock *olck = cl2osc_lock(slice);
struct cl_lock *lock = olck->ols_cl.cls_lock;
LINVRNT(osc_lock_invariant(olck));
LASSERT(olck->ols_state >= OLS_UPCALL_RECEIVED);
return lock->cll_error;
}
static void osc_lock_lockless_state(const struct lu_env *env,
const struct cl_lock_slice *slice,
enum cl_lock_state state)
{
struct osc_lock *lock = cl2osc_lock(slice);
LINVRNT(osc_lock_invariant(lock));
if (state == CLS_HELD) {
struct osc_io *oio = osc_env_io(env);
LASSERT(ergo(lock->ols_owner, lock->ols_owner == oio));
lock->ols_owner = oio;
if (cl_object_same(oio->oi_cl.cis_obj, slice->cls_obj))
oio->oi_lockless = 1;
}
}
static int osc_lock_lockless_fits_into(const struct lu_env *env,
const struct cl_lock_slice *slice,
const struct cl_lock_descr *need,
const struct cl_io *io)
{
struct osc_lock *lock = cl2osc_lock(slice);
if (!(need->cld_enq_flags & CEF_NEVER))
return 0;
return (lock->ols_owner == osc_env_io(env));
}
int osc_lock_init(const struct lu_env *env,
struct cl_object *obj, struct cl_lock *lock,
const struct cl_io *unused)
{
struct osc_lock *clk;
int result;
clk = kmem_cache_alloc(osc_lock_kmem, GFP_NOFS | __GFP_ZERO);
if (clk != NULL) {
__u32 enqflags = lock->cll_descr.cld_enq_flags;
osc_lock_build_einfo(env, lock, clk, &clk->ols_einfo);
atomic_set(&clk->ols_pageref, 0);
clk->ols_state = OLS_NEW;
clk->ols_flags = osc_enq2ldlm_flags(enqflags);
clk->ols_agl = !!(enqflags & CEF_AGL);
if (clk->ols_agl)
clk->ols_flags |= LDLM_FL_BLOCK_NOWAIT;
if (clk->ols_flags & LDLM_FL_HAS_INTENT)
clk->ols_glimpse = 1;
cl_lock_slice_add(lock, &clk->ols_cl, obj, &osc_lock_ops);
if (!(enqflags & CEF_MUST))
osc_lock_to_lockless(env, clk, (enqflags & CEF_NEVER));
if (clk->ols_locklessable && !(enqflags & CEF_DISCARD_DATA))
clk->ols_flags |= LDLM_FL_DENY_ON_CONTENTION;
LDLM_DEBUG_NOLOCK("lock %p, osc lock %p, flags %llx\n",
lock, clk, clk->ols_flags);
result = 0;
} else
result = -ENOMEM;
return result;
}
int osc_dlm_lock_pageref(struct ldlm_lock *dlm)
{
struct osc_lock *olock;
int rc = 0;
spin_lock(&osc_ast_guard);
olock = dlm->l_ast_data;
if (olock != NULL &&
atomic_add_return(_PAGEREF_MAGIC,
&olock->ols_pageref) != _PAGEREF_MAGIC) {
atomic_sub(_PAGEREF_MAGIC, &olock->ols_pageref);
rc = 1;
}
spin_unlock(&osc_ast_guard);
return rc;
}
