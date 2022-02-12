int osc_lock_is_lockless(const struct osc_lock *olck)
{
return (olck->ols_cl.cls_ops == &osc_lock_lockless_ops);
}
static struct ldlm_lock *osc_handle_ptr(struct lustre_handle *handle)
{
struct ldlm_lock *lock;
lock = ldlm_handle2lock(handle);
if (lock)
LDLM_LOCK_PUT(lock);
return lock;
}
static int osc_lock_invariant(struct osc_lock *ols)
{
struct ldlm_lock *lock = osc_handle_ptr(&ols->ols_handle);
struct ldlm_lock *olock = ols->ols_dlmlock;
int handle_used = lustre_handle_is_used(&ols->ols_handle);
if (ergo(osc_lock_is_lockless(ols),
ols->ols_locklessable && !ols->ols_dlmlock))
return 1;
if (!ergo(olock, handle_used))
return 0;
if (!ergo(olock, olock->l_handle.h_cookie == ols->ols_handle.cookie))
return 0;
if (!ergo(handle_used,
ergo(lock && olock, lock == olock) &&
ergo(!lock, !olock)))
return 0;
if (!ergo(ols->ols_state == OLS_CANCELLED,
!olock && !handle_used))
return 0;
if (!ergo(olock && ols->ols_state < OLS_CANCELLED,
!ldlm_is_destroyed(olock)))
return 0;
if (!ergo(ols->ols_state == OLS_GRANTED,
olock && olock->l_req_mode == olock->l_granted_mode &&
ols->ols_hold))
return 0;
return 1;
}
static void osc_lock_fini(const struct lu_env *env,
struct cl_lock_slice *slice)
{
struct osc_lock *ols = cl2osc_lock(slice);
LINVRNT(osc_lock_invariant(ols));
LASSERT(!ols->ols_dlmlock);
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
if (enqflags & CEF_PEEK)
result |= LDLM_FL_TEST_LOCK;
return result;
}
static void osc_lock_lvb_update(const struct lu_env *env,
struct osc_object *osc,
struct ldlm_lock *dlmlock,
struct ost_lvb *lvb)
{
struct cl_object *obj = osc2cl(osc);
struct lov_oinfo *oinfo = osc->oo_oinfo;
struct cl_attr *attr = &osc_env_info(env)->oti_attr;
unsigned valid;
valid = CAT_BLOCKS | CAT_ATIME | CAT_CTIME | CAT_MTIME | CAT_SIZE;
if (!lvb)
lvb = dlmlock->l_lvb_data;
cl_lvb2attr(attr, lvb);
cl_object_attr_lock(obj);
if (dlmlock) {
__u64 size;
check_res_locked(dlmlock->l_resource);
LASSERT(lvb == dlmlock->l_lvb_data);
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
}
cl_object_attr_set(env, obj, attr, valid);
cl_object_attr_unlock(obj);
}
static void osc_lock_granted(const struct lu_env *env, struct osc_lock *oscl,
struct lustre_handle *lockh, bool lvb_update)
{
struct ldlm_lock *dlmlock;
dlmlock = ldlm_handle2lock_long(lockh, 0);
LASSERT(dlmlock);
lu_ref_add(&dlmlock->l_reference, "osc_lock", oscl);
oscl->ols_has_ref = 1;
LASSERT(!oscl->ols_dlmlock);
oscl->ols_dlmlock = dlmlock;
if (!oscl->ols_glimpse) {
lustre_handle_copy(&oscl->ols_handle, lockh);
ldlm_lock_addref(lockh, oscl->ols_einfo.ei_mode);
oscl->ols_hold = 1;
}
lock_res_and_lock(dlmlock);
if (dlmlock->l_granted_mode == dlmlock->l_req_mode) {
struct ldlm_extent *ext = &dlmlock->l_policy_data.l_extent;
struct cl_lock_descr *descr = &oscl->ols_cl.cls_lock->cll_descr;
descr->cld_mode = osc_ldlm2cl_lock(dlmlock->l_granted_mode);
descr->cld_start = cl_index(descr->cld_obj, ext->start);
descr->cld_end = cl_index(descr->cld_obj, ext->end);
descr->cld_gid = ext->gid;
if (lvb_update) {
LASSERT(oscl->ols_flags & LDLM_FL_LVB_READY);
osc_lock_lvb_update(env, cl2osc(oscl->ols_cl.cls_obj),
dlmlock, NULL);
}
LINVRNT(osc_lock_invariant(oscl));
}
unlock_res_and_lock(dlmlock);
LASSERT(oscl->ols_state != OLS_GRANTED);
oscl->ols_state = OLS_GRANTED;
}
static int osc_lock_upcall(void *cookie, struct lustre_handle *lockh,
int errcode)
{
struct osc_lock *oscl = cookie;
struct cl_lock_slice *slice = &oscl->ols_cl;
struct lu_env *env;
struct cl_env_nest nest;
int rc;
env = cl_env_nested_get(&nest);
LASSERT(!IS_ERR(env));
rc = ldlm_error2errno(errcode);
if (oscl->ols_state == OLS_ENQUEUED) {
oscl->ols_state = OLS_UPCALL_RECEIVED;
} else if (oscl->ols_state == OLS_CANCELLED) {
rc = -EIO;
} else {
CERROR("Impossible state: %d\n", oscl->ols_state);
LBUG();
}
if (rc == 0)
osc_lock_granted(env, oscl, lockh, errcode == ELDLM_OK);
if (oscl->ols_locklessable && rc == -EUSERS) {
osc_object_set_contended(cl2osc(slice->cls_obj));
LASSERT(slice->cls_ops == &osc_lock_ops);
osc_lock_to_lockless(env, oscl, 1);
oscl->ols_state = OLS_GRANTED;
rc = 0;
} else if (oscl->ols_glimpse && rc == -ENAVAIL) {
LASSERT(oscl->ols_flags & LDLM_FL_LVB_READY);
osc_lock_lvb_update(env, cl2osc(slice->cls_obj),
NULL, &oscl->ols_lvb);
rc = 0;
}
if (oscl->ols_owner)
cl_sync_io_note(env, oscl->ols_owner, rc);
cl_env_nested_put(&nest, env);
return rc;
}
static int osc_lock_upcall_agl(void *cookie, struct lustre_handle *lockh,
int errcode)
{
struct osc_object *osc = cookie;
struct ldlm_lock *dlmlock;
struct lu_env *env;
struct cl_env_nest nest;
env = cl_env_nested_get(&nest);
LASSERT(!IS_ERR(env));
if (errcode == ELDLM_LOCK_MATCHED) {
errcode = ELDLM_OK;
goto out;
}
if (errcode != ELDLM_OK)
goto out;
dlmlock = ldlm_handle2lock(lockh);
LASSERT(dlmlock);
lock_res_and_lock(dlmlock);
LASSERT(dlmlock->l_granted_mode == dlmlock->l_req_mode);
osc_lock_lvb_update(env, osc, dlmlock, NULL);
unlock_res_and_lock(dlmlock);
LDLM_LOCK_PUT(dlmlock);
out:
cl_object_put(env, osc2cl(osc));
cl_env_nested_put(&nest, env);
return ldlm_error2errno(errcode);
}
static int osc_lock_flush(struct osc_object *obj, pgoff_t start, pgoff_t end,
enum cl_lock_mode mode, int discard)
{
struct lu_env *env;
struct cl_env_nest nest;
int rc = 0;
int rc2 = 0;
env = cl_env_nested_get(&nest);
if (IS_ERR(env))
return PTR_ERR(env);
if (mode == CLM_WRITE) {
rc = osc_cache_writeback_range(env, obj, start, end, 1,
discard);
CDEBUG(D_CACHE, "object %p: [%lu -> %lu] %d pages were %s.\n",
obj, start, end, rc,
discard ? "discarded" : "written back");
if (rc > 0)
rc = 0;
}
rc2 = osc_lock_discard_pages(env, obj, start, end, mode);
if (rc == 0 && rc2 < 0)
rc = rc2;
cl_env_nested_put(&nest, env);
return rc;
}
static int osc_dlm_blocking_ast0(const struct lu_env *env,
struct ldlm_lock *dlmlock,
void *data, int flag)
{
struct cl_object *obj = NULL;
int result = 0;
int discard;
enum cl_lock_mode mode = CLM_READ;
LASSERT(flag == LDLM_CB_CANCELING);
lock_res_and_lock(dlmlock);
if (dlmlock->l_granted_mode != dlmlock->l_req_mode) {
dlmlock->l_ast_data = NULL;
unlock_res_and_lock(dlmlock);
return 0;
}
discard = ldlm_is_discard_data(dlmlock);
if (dlmlock->l_granted_mode & (LCK_PW | LCK_GROUP))
mode = CLM_WRITE;
if (dlmlock->l_ast_data) {
obj = osc2cl(dlmlock->l_ast_data);
dlmlock->l_ast_data = NULL;
cl_object_get(obj);
}
unlock_res_and_lock(dlmlock);
if (obj) {
struct ldlm_extent *extent = &dlmlock->l_policy_data.l_extent;
struct cl_attr *attr = &osc_env_info(env)->oti_attr;
__u64 old_kms;
result = osc_lock_flush(cl2osc(obj),
cl_index(obj, extent->start),
cl_index(obj, extent->end),
mode, discard);
lock_res_and_lock(dlmlock);
cl_object_attr_lock(obj);
old_kms = cl2osc(obj)->oo_oinfo->loi_kms;
attr->cat_kms = ldlm_extent_shift_kms(dlmlock, old_kms);
cl_object_attr_set(env, obj, attr, CAT_KMS);
cl_object_attr_unlock(obj);
unlock_res_and_lock(dlmlock);
cl_object_put(env, obj);
}
return result;
}
static int osc_ldlm_blocking_ast(struct ldlm_lock *dlmlock,
struct ldlm_lock_desc *new, void *data,
int flag)
{
int result = 0;
switch (flag) {
case LDLM_CB_BLOCKING: {
struct lustre_handle lockh;
ldlm_lock2handle(dlmlock, &lockh);
result = ldlm_cli_cancel(&lockh, LCF_ASYNC);
if (result == -ENODATA)
result = 0;
break;
}
case LDLM_CB_CANCELING: {
struct lu_env *env;
struct cl_env_nest nest;
env = cl_env_nested_get(&nest);
if (IS_ERR(env)) {
result = PTR_ERR(env);
break;
}
result = osc_dlm_blocking_ast0(env, dlmlock, data, flag);
cl_env_nested_put(&nest, env);
break;
}
default:
LBUG();
}
return result;
}
static int osc_ldlm_glimpse_ast(struct ldlm_lock *dlmlock, void *data)
{
struct ptlrpc_request *req = data;
struct cl_env_nest nest;
struct lu_env *env;
struct ost_lvb *lvb;
struct req_capsule *cap;
int result;
LASSERT(lustre_msg_get_opc(req->rq_reqmsg) == LDLM_GL_CALLBACK);
env = cl_env_nested_get(&nest);
if (!IS_ERR(env)) {
struct cl_object *obj = NULL;
lock_res_and_lock(dlmlock);
if (dlmlock->l_ast_data) {
obj = osc2cl(dlmlock->l_ast_data);
cl_object_get(obj);
}
unlock_res_and_lock(dlmlock);
if (obj) {
cap = &req->rq_pill;
req_capsule_extend(cap, &RQF_LDLM_GL_CALLBACK);
req_capsule_set_size(cap, &RMF_DLM_LVB, RCL_SERVER,
sizeof(*lvb));
result = req_capsule_server_pack(cap);
if (result == 0) {
lvb = req_capsule_server_get(cap, &RMF_DLM_LVB);
result = cl_object_glimpse(env, obj, lvb);
}
if (!exp_connect_lvb_type(req->rq_export))
req_capsule_shrink(&req->rq_pill,
&RMF_DLM_LVB,
sizeof(struct ost_lvb_v1),
RCL_SERVER);
cl_object_put(env, obj);
} else {
lustre_pack_reply(req, 1, NULL, NULL);
result = -ELDLM_NO_LOCK_DATA;
}
cl_env_nested_put(&nest, env);
} else {
result = PTR_ERR(env);
}
req->rq_status = result;
return result;
}
static int weigh_cb(const struct lu_env *env, struct cl_io *io,
struct osc_page *ops, void *cbdata)
{
struct cl_page *page = ops->ops_cl.cpl_page;
if (cl_page_is_vmlocked(env, page) ||
PageDirty(page->cp_vmpage) || PageWriteback(page->cp_vmpage)
)
return CLP_GANG_ABORT;
*(pgoff_t *)cbdata = osc_index(ops) + 1;
return CLP_GANG_OKAY;
}
static unsigned long osc_lock_weight(const struct lu_env *env,
struct osc_object *oscobj,
struct ldlm_extent *extent)
{
struct cl_io *io = &osc_env_info(env)->oti_io;
struct cl_object *obj = cl_object_top(&oscobj->oo_cl);
pgoff_t page_index;
int result;
io->ci_obj = obj;
io->ci_ignore_layout = 1;
result = cl_io_init(env, io, CIT_MISC, io->ci_obj);
if (result != 0)
return result;
page_index = cl_index(obj, extent->start);
do {
result = osc_page_gang_lookup(env, io, oscobj,
page_index,
cl_index(obj, extent->end),
weigh_cb, (void *)&page_index);
if (result == CLP_GANG_ABORT)
break;
if (result == CLP_GANG_RESCHED)
cond_resched();
} while (result != CLP_GANG_OKAY);
cl_io_fini(env, io);
return result == CLP_GANG_ABORT ? 1 : 0;
}
unsigned long osc_ldlm_weigh_ast(struct ldlm_lock *dlmlock)
{
struct cl_env_nest nest;
struct lu_env *env;
struct osc_object *obj;
struct osc_lock *oscl;
unsigned long weight;
bool found = false;
might_sleep();
env = cl_env_nested_get(&nest);
if (IS_ERR(env))
return 1;
LASSERT(dlmlock->l_resource->lr_type == LDLM_EXTENT);
obj = dlmlock->l_ast_data;
if (!obj) {
weight = 1;
goto out;
}
spin_lock(&obj->oo_ol_spin);
list_for_each_entry(oscl, &obj->oo_ol_list, ols_nextlock_oscobj) {
if (oscl->ols_dlmlock && oscl->ols_dlmlock != dlmlock)
continue;
found = true;
}
spin_unlock(&obj->oo_ol_spin);
if (found) {
weight = 1;
goto out;
}
weight = osc_lock_weight(env, obj, &dlmlock->l_policy_data.l_extent);
out:
cl_env_nested_put(&nest, env);
return weight;
}
static void osc_lock_build_einfo(const struct lu_env *env,
const struct cl_lock *lock,
struct osc_object *osc,
struct ldlm_enqueue_info *einfo)
{
einfo->ei_type = LDLM_EXTENT;
einfo->ei_mode = osc_cl_lock2ldlm(lock->cll_descr.cld_mode);
einfo->ei_cb_bl = osc_ldlm_blocking_ast;
einfo->ei_cb_cp = ldlm_completion_ast;
einfo->ei_cb_gl = osc_ldlm_glimpse_ast;
einfo->ei_cbdata = osc;
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
static bool osc_lock_compatible(const struct osc_lock *qing,
const struct osc_lock *qed)
{
struct cl_lock_descr *qed_descr = &qed->ols_cl.cls_lock->cll_descr;
struct cl_lock_descr *qing_descr = &qing->ols_cl.cls_lock->cll_descr;
if (qed->ols_glimpse)
return true;
if (qing_descr->cld_mode == CLM_READ && qed_descr->cld_mode == CLM_READ)
return true;
if (qed->ols_state < OLS_GRANTED)
return true;
if (qed_descr->cld_mode >= qing_descr->cld_mode &&
qed_descr->cld_start <= qing_descr->cld_start &&
qed_descr->cld_end >= qing_descr->cld_end)
return true;
return false;
}
static void osc_lock_wake_waiters(const struct lu_env *env,
struct osc_object *osc,
struct osc_lock *oscl)
{
spin_lock(&osc->oo_ol_spin);
list_del_init(&oscl->ols_nextlock_oscobj);
spin_unlock(&osc->oo_ol_spin);
spin_lock(&oscl->ols_lock);
while (!list_empty(&oscl->ols_waiting_list)) {
struct osc_lock *scan;
scan = list_entry(oscl->ols_waiting_list.next, struct osc_lock,
ols_wait_entry);
list_del_init(&scan->ols_wait_entry);
cl_sync_io_note(env, scan->ols_owner, 0);
}
spin_unlock(&oscl->ols_lock);
}
static void osc_lock_enqueue_wait(const struct lu_env *env,
struct osc_object *obj,
struct osc_lock *oscl)
{
struct osc_lock *tmp_oscl;
struct cl_lock_descr *need = &oscl->ols_cl.cls_lock->cll_descr;
struct cl_sync_io *waiter = &osc_env_info(env)->oti_anchor;
spin_lock(&obj->oo_ol_spin);
list_add_tail(&oscl->ols_nextlock_oscobj, &obj->oo_ol_list);
restart:
list_for_each_entry(tmp_oscl, &obj->oo_ol_list,
ols_nextlock_oscobj) {
struct cl_lock_descr *descr;
if (tmp_oscl == oscl)
break;
descr = &tmp_oscl->ols_cl.cls_lock->cll_descr;
if (descr->cld_start > need->cld_end ||
descr->cld_end < need->cld_start)
continue;
if (descr->cld_mode == CLM_GROUP)
break;
if (!osc_lock_is_lockless(oscl) &&
osc_lock_compatible(oscl, tmp_oscl))
continue;
cl_sync_io_init(waiter, 1, cl_sync_io_end);
oscl->ols_owner = waiter;
spin_lock(&tmp_oscl->ols_lock);
list_add_tail(&oscl->ols_wait_entry,
&tmp_oscl->ols_waiting_list);
spin_unlock(&tmp_oscl->ols_lock);
spin_unlock(&obj->oo_ol_spin);
(void)cl_sync_io_wait(env, waiter, 0);
spin_lock(&obj->oo_ol_spin);
oscl->ols_owner = NULL;
goto restart;
}
spin_unlock(&obj->oo_ol_spin);
}
static int osc_lock_enqueue(const struct lu_env *env,
const struct cl_lock_slice *slice,
struct cl_io *unused, struct cl_sync_io *anchor)
{
struct osc_thread_info *info = osc_env_info(env);
struct osc_io *oio = osc_env_io(env);
struct osc_object *osc = cl2osc(slice->cls_obj);
struct osc_lock *oscl = cl2osc_lock(slice);
struct cl_lock *lock = slice->cls_lock;
struct ldlm_res_id *resname = &info->oti_resname;
ldlm_policy_data_t *policy = &info->oti_policy;
osc_enqueue_upcall_f upcall = osc_lock_upcall;
void *cookie = oscl;
bool async = false;
int result;
LASSERTF(ergo(oscl->ols_glimpse, lock->cll_descr.cld_mode <= CLM_READ),
"lock = %p, ols = %p\n", lock, oscl);
if (oscl->ols_state == OLS_GRANTED)
return 0;
if (oscl->ols_flags & LDLM_FL_TEST_LOCK)
goto enqueue_base;
if (oscl->ols_glimpse) {
LASSERT(equi(oscl->ols_agl, !anchor));
async = true;
goto enqueue_base;
}
osc_lock_enqueue_wait(env, osc, oscl);
if (osc_lock_is_lockless(oscl)) {
oscl->ols_state = OLS_GRANTED;
oio->oi_lockless = 1;
return 0;
}
enqueue_base:
oscl->ols_state = OLS_ENQUEUED;
if (anchor) {
atomic_inc(&anchor->csi_sync_nr);
oscl->ols_owner = anchor;
}
ostid_build_res_name(&osc->oo_oinfo->loi_oi, resname);
osc_lock_build_einfo(env, lock, osc, &oscl->ols_einfo);
osc_lock_build_policy(env, lock, policy);
if (oscl->ols_agl) {
oscl->ols_einfo.ei_cbdata = NULL;
cl_object_get(osc2cl(osc));
upcall = osc_lock_upcall_agl;
cookie = osc;
}
result = osc_enqueue_base(osc_export(osc), resname, &oscl->ols_flags,
policy, &oscl->ols_lvb,
osc->oo_oinfo->loi_kms_valid,
upcall, cookie,
&oscl->ols_einfo, PTLRPCD_SET, async,
oscl->ols_agl);
if (result != 0) {
oscl->ols_state = OLS_CANCELLED;
osc_lock_wake_waiters(env, osc, oscl);
if (oscl->ols_agl) {
cl_object_put(env, osc2cl(osc));
result = 0;
}
if (anchor)
cl_sync_io_note(env, anchor, result);
} else {
if (osc_lock_is_lockless(oscl)) {
oio->oi_lockless = 1;
} else if (!async) {
LASSERT(oscl->ols_state == OLS_GRANTED);
LASSERT(oscl->ols_hold);
LASSERT(oscl->ols_dlmlock);
}
}
return result;
}
static void osc_lock_detach(const struct lu_env *env, struct osc_lock *olck)
{
struct ldlm_lock *dlmlock;
dlmlock = olck->ols_dlmlock;
if (!dlmlock)
return;
if (olck->ols_hold) {
olck->ols_hold = 0;
osc_cancel_base(&olck->ols_handle, olck->ols_einfo.ei_mode);
olck->ols_handle.cookie = 0ULL;
}
olck->ols_dlmlock = NULL;
LASSERT(olck->ols_has_ref);
lu_ref_del(&dlmlock->l_reference, "osc_lock", olck);
LDLM_LOCK_RELEASE(dlmlock);
olck->ols_has_ref = 0;
}
static void osc_lock_cancel(const struct lu_env *env,
const struct cl_lock_slice *slice)
{
struct osc_object *obj = cl2osc(slice->cls_obj);
struct osc_lock *oscl = cl2osc_lock(slice);
LINVRNT(osc_lock_invariant(oscl));
osc_lock_detach(env, oscl);
oscl->ols_state = OLS_CANCELLED;
oscl->ols_flags &= ~LDLM_FL_LVB_READY;
osc_lock_wake_waiters(env, obj, oscl);
}
static int osc_lock_print(const struct lu_env *env, void *cookie,
lu_printer_t p, const struct cl_lock_slice *slice)
{
struct osc_lock *lock = cl2osc_lock(slice);
(*p)(env, cookie, "%p %#16llx %#llx %d %p ",
lock->ols_dlmlock, lock->ols_flags, lock->ols_handle.cookie,
lock->ols_state, lock->ols_owner);
osc_lvb_print(env, cookie, p, &lock->ols_lvb);
return 0;
}
static void osc_lock_lockless_cancel(const struct lu_env *env,
const struct cl_lock_slice *slice)
{
struct osc_lock *ols = cl2osc_lock(slice);
struct osc_object *osc = cl2osc(slice->cls_obj);
struct cl_lock_descr *descr = &slice->cls_lock->cll_descr;
int result;
LASSERT(!ols->ols_dlmlock);
result = osc_lock_flush(osc, descr->cld_start, descr->cld_end,
descr->cld_mode, 0);
if (result)
CERROR("Pages for lockless lock %p were not purged(%d)\n",
ols, result);
osc_lock_wake_waiters(env, osc, ols);
}
static void osc_lock_set_writer(const struct lu_env *env,
const struct cl_io *io,
struct cl_object *obj, struct osc_lock *oscl)
{
struct cl_lock_descr *descr = &oscl->ols_cl.cls_lock->cll_descr;
pgoff_t io_start;
pgoff_t io_end;
if (!cl_object_same(io->ci_obj, obj))
return;
if (likely(io->ci_type == CIT_WRITE)) {
io_start = cl_index(obj, io->u.ci_rw.crw_pos);
io_end = cl_index(obj, io->u.ci_rw.crw_pos +
io->u.ci_rw.crw_count - 1);
if (cl_io_is_append(io)) {
io_start = 0;
io_end = CL_PAGE_EOF;
}
} else {
LASSERT(cl_io_is_mkwrite(io));
io_start = io->u.ci_fault.ft_index;
io_end = io->u.ci_fault.ft_index;
}
if (descr->cld_mode >= CLM_WRITE &&
descr->cld_start <= io_start && descr->cld_end >= io_end) {
struct osc_io *oio = osc_env_io(env);
LASSERT(!oio->oi_write_osclock);
oio->oi_write_osclock = oscl;
}
}
int osc_lock_init(const struct lu_env *env,
struct cl_object *obj, struct cl_lock *lock,
const struct cl_io *io)
{
struct osc_lock *oscl;
__u32 enqflags = lock->cll_descr.cld_enq_flags;
oscl = kmem_cache_zalloc(osc_lock_kmem, GFP_NOFS);
if (!oscl)
return -ENOMEM;
oscl->ols_state = OLS_NEW;
spin_lock_init(&oscl->ols_lock);
INIT_LIST_HEAD(&oscl->ols_waiting_list);
INIT_LIST_HEAD(&oscl->ols_wait_entry);
INIT_LIST_HEAD(&oscl->ols_nextlock_oscobj);
oscl->ols_flags = osc_enq2ldlm_flags(enqflags);
oscl->ols_agl = !!(enqflags & CEF_AGL);
if (oscl->ols_agl)
oscl->ols_flags |= LDLM_FL_BLOCK_NOWAIT;
if (oscl->ols_flags & LDLM_FL_HAS_INTENT) {
oscl->ols_flags |= LDLM_FL_BLOCK_GRANTED;
oscl->ols_glimpse = 1;
}
cl_lock_slice_add(lock, &oscl->ols_cl, obj, &osc_lock_ops);
if (!(enqflags & CEF_MUST))
osc_lock_to_lockless(env, oscl, (enqflags & CEF_NEVER));
if (oscl->ols_locklessable && !(enqflags & CEF_DISCARD_DATA))
oscl->ols_flags |= LDLM_FL_DENY_ON_CONTENTION;
if (io->ci_type == CIT_WRITE || cl_io_is_mkwrite(io))
osc_lock_set_writer(env, io, obj, oscl);
LDLM_DEBUG_NOLOCK("lock %p, osc lock %p, flags %llx",
lock, oscl, oscl->ols_flags);
return 0;
}
struct ldlm_lock *osc_dlmlock_at_pgoff(const struct lu_env *env,
struct osc_object *obj, pgoff_t index,
int pending, int canceling)
{
struct osc_thread_info *info = osc_env_info(env);
struct ldlm_res_id *resname = &info->oti_resname;
ldlm_policy_data_t *policy = &info->oti_policy;
struct lustre_handle lockh;
struct ldlm_lock *lock = NULL;
enum ldlm_mode mode;
__u64 flags;
ostid_build_res_name(&obj->oo_oinfo->loi_oi, resname);
osc_index2policy(policy, osc2cl(obj), index, index);
policy->l_extent.gid = LDLM_GID_ANY;
flags = LDLM_FL_BLOCK_GRANTED | LDLM_FL_TEST_LOCK;
if (pending)
flags |= LDLM_FL_CBPENDING;
again:
mode = ldlm_lock_match(osc_export(obj)->exp_obd->obd_namespace,
flags, resname, LDLM_EXTENT, policy,
LCK_PR | LCK_PW | LCK_GROUP, &lockh, canceling);
if (mode != 0) {
lock = ldlm_handle2lock(&lockh);
if (unlikely(!lock))
goto again;
}
return lock;
}
