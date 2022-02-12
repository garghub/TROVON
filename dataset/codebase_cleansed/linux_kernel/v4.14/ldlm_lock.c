static void ldlm_convert_policy_to_wire(enum ldlm_type type,
const union ldlm_policy_data *lpolicy,
union ldlm_wire_policy_data *wpolicy)
{
ldlm_policy_local_to_wire_t convert;
convert = ldlm_policy_local_to_wire[type - LDLM_MIN_TYPE];
convert(lpolicy, wpolicy);
}
void ldlm_convert_policy_to_local(struct obd_export *exp, enum ldlm_type type,
const union ldlm_wire_policy_data *wpolicy,
union ldlm_policy_data *lpolicy)
{
ldlm_policy_wire_to_local_t convert;
convert = ldlm_policy_wire_to_local[type - LDLM_MIN_TYPE];
convert(wpolicy, lpolicy);
}
const char *ldlm_it2str(enum ldlm_intent_flags it)
{
switch (it) {
case IT_OPEN:
return "open";
case IT_CREAT:
return "creat";
case (IT_OPEN | IT_CREAT):
return "open|creat";
case IT_READDIR:
return "readdir";
case IT_GETATTR:
return "getattr";
case IT_LOOKUP:
return "lookup";
case IT_UNLINK:
return "unlink";
case IT_GETXATTR:
return "getxattr";
case IT_LAYOUT:
return "layout";
default:
CERROR("Unknown intent 0x%08x\n", it);
return "UNKNOWN";
}
}
struct ldlm_lock *ldlm_lock_get(struct ldlm_lock *lock)
{
atomic_inc(&lock->l_refc);
return lock;
}
void ldlm_lock_put(struct ldlm_lock *lock)
{
LASSERT(lock->l_resource != LP_POISON);
LASSERT(atomic_read(&lock->l_refc) > 0);
if (atomic_dec_and_test(&lock->l_refc)) {
struct ldlm_resource *res;
LDLM_DEBUG(lock,
"final lock_put on destroyed lock, freeing it.");
res = lock->l_resource;
LASSERT(ldlm_is_destroyed(lock));
LASSERT(list_empty(&lock->l_res_link));
LASSERT(list_empty(&lock->l_pending_chain));
lprocfs_counter_decr(ldlm_res_to_ns(res)->ns_stats,
LDLM_NSS_LOCKS);
lu_ref_del(&res->lr_reference, "lock", lock);
ldlm_resource_putref(res);
lock->l_resource = NULL;
if (lock->l_export) {
class_export_lock_put(lock->l_export, lock);
lock->l_export = NULL;
}
kfree(lock->l_lvb_data);
ldlm_interval_free(ldlm_interval_detach(lock));
lu_ref_fini(&lock->l_reference);
OBD_FREE_RCU(lock, sizeof(*lock), &lock->l_handle);
}
}
int ldlm_lock_remove_from_lru_nolock(struct ldlm_lock *lock)
{
int rc = 0;
if (!list_empty(&lock->l_lru)) {
struct ldlm_namespace *ns = ldlm_lock_to_ns(lock);
LASSERT(lock->l_resource->lr_type != LDLM_FLOCK);
list_del_init(&lock->l_lru);
LASSERT(ns->ns_nr_unused > 0);
ns->ns_nr_unused--;
rc = 1;
}
return rc;
}
int ldlm_lock_remove_from_lru_check(struct ldlm_lock *lock, time_t last_use)
{
struct ldlm_namespace *ns = ldlm_lock_to_ns(lock);
int rc = 0;
spin_lock(&ns->ns_lock);
if (last_use == 0 || last_use == lock->l_last_used)
rc = ldlm_lock_remove_from_lru_nolock(lock);
spin_unlock(&ns->ns_lock);
return rc;
}
static void ldlm_lock_add_to_lru_nolock(struct ldlm_lock *lock)
{
struct ldlm_namespace *ns = ldlm_lock_to_ns(lock);
lock->l_last_used = cfs_time_current();
LASSERT(list_empty(&lock->l_lru));
LASSERT(lock->l_resource->lr_type != LDLM_FLOCK);
list_add_tail(&lock->l_lru, &ns->ns_unused_list);
ldlm_clear_skipped(lock);
LASSERT(ns->ns_nr_unused >= 0);
ns->ns_nr_unused++;
}
static void ldlm_lock_add_to_lru(struct ldlm_lock *lock)
{
struct ldlm_namespace *ns = ldlm_lock_to_ns(lock);
spin_lock(&ns->ns_lock);
ldlm_lock_add_to_lru_nolock(lock);
spin_unlock(&ns->ns_lock);
}
static void ldlm_lock_touch_in_lru(struct ldlm_lock *lock)
{
struct ldlm_namespace *ns = ldlm_lock_to_ns(lock);
spin_lock(&ns->ns_lock);
if (!list_empty(&lock->l_lru)) {
ldlm_lock_remove_from_lru_nolock(lock);
ldlm_lock_add_to_lru_nolock(lock);
}
spin_unlock(&ns->ns_lock);
}
static int ldlm_lock_destroy_internal(struct ldlm_lock *lock)
{
if (lock->l_readers || lock->l_writers) {
LDLM_ERROR(lock, "lock still has references");
LBUG();
}
if (!list_empty(&lock->l_res_link)) {
LDLM_ERROR(lock, "lock still on resource");
LBUG();
}
if (ldlm_is_destroyed(lock)) {
LASSERT(list_empty(&lock->l_lru));
return 0;
}
ldlm_set_destroyed(lock);
if (lock->l_export && lock->l_export->exp_lock_hash) {
cfs_hash_del(lock->l_export->exp_lock_hash,
&lock->l_remote_handle, &lock->l_exp_hash);
}
ldlm_lock_remove_from_lru(lock);
class_handle_unhash(&lock->l_handle);
return 1;
}
static void ldlm_lock_destroy(struct ldlm_lock *lock)
{
int first;
lock_res_and_lock(lock);
first = ldlm_lock_destroy_internal(lock);
unlock_res_and_lock(lock);
if (first) {
lu_ref_del(&lock->l_reference, "hash", lock);
LDLM_LOCK_RELEASE(lock);
}
}
void ldlm_lock_destroy_nolock(struct ldlm_lock *lock)
{
int first;
first = ldlm_lock_destroy_internal(lock);
if (first) {
lu_ref_del(&lock->l_reference, "hash", lock);
LDLM_LOCK_RELEASE(lock);
}
}
static void lock_handle_addref(void *lock)
{
LDLM_LOCK_GET((struct ldlm_lock *)lock);
}
static void lock_handle_free(void *lock, int size)
{
LASSERT(size == sizeof(struct ldlm_lock));
kmem_cache_free(ldlm_lock_slab, lock);
}
static struct ldlm_lock *ldlm_lock_new(struct ldlm_resource *resource)
{
struct ldlm_lock *lock;
LASSERT(resource);
lock = kmem_cache_zalloc(ldlm_lock_slab, GFP_NOFS);
if (!lock)
return NULL;
spin_lock_init(&lock->l_lock);
lock->l_resource = resource;
lu_ref_add(&resource->lr_reference, "lock", lock);
atomic_set(&lock->l_refc, 2);
INIT_LIST_HEAD(&lock->l_res_link);
INIT_LIST_HEAD(&lock->l_lru);
INIT_LIST_HEAD(&lock->l_pending_chain);
INIT_LIST_HEAD(&lock->l_bl_ast);
INIT_LIST_HEAD(&lock->l_cp_ast);
INIT_LIST_HEAD(&lock->l_rk_ast);
init_waitqueue_head(&lock->l_waitq);
lock->l_blocking_lock = NULL;
INIT_LIST_HEAD(&lock->l_sl_mode);
INIT_LIST_HEAD(&lock->l_sl_policy);
INIT_HLIST_NODE(&lock->l_exp_hash);
INIT_HLIST_NODE(&lock->l_exp_flock_hash);
lprocfs_counter_incr(ldlm_res_to_ns(resource)->ns_stats,
LDLM_NSS_LOCKS);
INIT_LIST_HEAD(&lock->l_handle.h_link);
class_handle_hash(&lock->l_handle, &lock_handle_ops);
lu_ref_init(&lock->l_reference);
lu_ref_add(&lock->l_reference, "hash", lock);
lock->l_callback_timeout = 0;
#if LUSTRE_TRACKS_LOCK_EXP_REFS
INIT_LIST_HEAD(&lock->l_exp_refs_link);
lock->l_exp_refs_nr = 0;
lock->l_exp_refs_target = NULL;
#endif
return lock;
}
int ldlm_lock_change_resource(struct ldlm_namespace *ns, struct ldlm_lock *lock,
const struct ldlm_res_id *new_resid)
{
struct ldlm_resource *oldres = lock->l_resource;
struct ldlm_resource *newres;
int type;
lock_res_and_lock(lock);
if (memcmp(new_resid, &lock->l_resource->lr_name,
sizeof(lock->l_resource->lr_name)) == 0) {
unlock_res_and_lock(lock);
return 0;
}
LASSERT(new_resid->name[0] != 0);
LASSERT(list_empty(&lock->l_res_link));
type = oldres->lr_type;
unlock_res_and_lock(lock);
newres = ldlm_resource_get(ns, NULL, new_resid, type, 1);
if (IS_ERR(newres))
return PTR_ERR(newres);
lu_ref_add(&newres->lr_reference, "lock", lock);
spin_lock(&lock->l_lock);
oldres = lock->l_resource;
if (oldres < newres) {
lock_res(oldres);
lock_res_nested(newres, LRT_NEW);
} else {
lock_res(newres);
lock_res_nested(oldres, LRT_NEW);
}
LASSERT(memcmp(new_resid, &oldres->lr_name,
sizeof(oldres->lr_name)) != 0);
lock->l_resource = newres;
unlock_res(oldres);
unlock_res_and_lock(lock);
lu_ref_del(&oldres->lr_reference, "lock", lock);
ldlm_resource_putref(oldres);
return 0;
}
void ldlm_lock2handle(const struct ldlm_lock *lock, struct lustre_handle *lockh)
{
lockh->cookie = lock->l_handle.h_cookie;
}
struct ldlm_lock *__ldlm_handle2lock(const struct lustre_handle *handle,
__u64 flags)
{
struct ldlm_lock *lock;
LASSERT(handle);
lock = class_handle2object(handle->cookie, NULL);
if (!lock)
return NULL;
if (lock->l_export && lock->l_export->exp_failed) {
CDEBUG(D_INFO, "lock export failed: lock %p, exp %p\n",
lock, lock->l_export);
LDLM_LOCK_PUT(lock);
return NULL;
}
if (flags == 0 && !ldlm_is_destroyed(lock)) {
lu_ref_add(&lock->l_reference, "handle", current);
return lock;
}
lock_res_and_lock(lock);
LASSERT(lock->l_resource);
lu_ref_add_atomic(&lock->l_reference, "handle", current);
if (unlikely(ldlm_is_destroyed(lock))) {
unlock_res_and_lock(lock);
CDEBUG(D_INFO, "lock already destroyed: lock %p\n", lock);
LDLM_LOCK_PUT(lock);
return NULL;
}
if (flags) {
if (lock->l_flags & flags) {
unlock_res_and_lock(lock);
LDLM_LOCK_PUT(lock);
return NULL;
}
lock->l_flags |= flags;
}
unlock_res_and_lock(lock);
return lock;
}
void ldlm_lock2desc(struct ldlm_lock *lock, struct ldlm_lock_desc *desc)
{
ldlm_res2desc(lock->l_resource, &desc->l_resource);
desc->l_req_mode = lock->l_req_mode;
desc->l_granted_mode = lock->l_granted_mode;
ldlm_convert_policy_to_wire(lock->l_resource->lr_type,
&lock->l_policy_data,
&desc->l_policy_data);
}
static void ldlm_add_bl_work_item(struct ldlm_lock *lock, struct ldlm_lock *new,
struct list_head *work_list)
{
if (!ldlm_is_ast_sent(lock)) {
LDLM_DEBUG(lock, "lock incompatible; sending blocking AST.");
ldlm_set_ast_sent(lock);
if (ldlm_is_ast_discard_data(new))
ldlm_set_discard_data(lock);
LASSERT(list_empty(&lock->l_bl_ast));
list_add(&lock->l_bl_ast, work_list);
LDLM_LOCK_GET(lock);
LASSERT(!lock->l_blocking_lock);
lock->l_blocking_lock = LDLM_LOCK_GET(new);
}
}
static void ldlm_add_cp_work_item(struct ldlm_lock *lock,
struct list_head *work_list)
{
if (!ldlm_is_cp_reqd(lock)) {
ldlm_set_cp_reqd(lock);
LDLM_DEBUG(lock, "lock granted; sending completion AST.");
LASSERT(list_empty(&lock->l_cp_ast));
list_add(&lock->l_cp_ast, work_list);
LDLM_LOCK_GET(lock);
}
}
static void ldlm_add_ast_work_item(struct ldlm_lock *lock,
struct ldlm_lock *new,
struct list_head *work_list)
{
check_res_locked(lock->l_resource);
if (new)
ldlm_add_bl_work_item(lock, new, work_list);
else
ldlm_add_cp_work_item(lock, work_list);
}
void ldlm_lock_addref(const struct lustre_handle *lockh, enum ldlm_mode mode)
{
struct ldlm_lock *lock;
lock = ldlm_handle2lock(lockh);
LASSERTF(lock, "Non-existing lock: %llx\n", lockh->cookie);
ldlm_lock_addref_internal(lock, mode);
LDLM_LOCK_PUT(lock);
}
void ldlm_lock_addref_internal_nolock(struct ldlm_lock *lock,
enum ldlm_mode mode)
{
ldlm_lock_remove_from_lru(lock);
if (mode & (LCK_NL | LCK_CR | LCK_PR)) {
lock->l_readers++;
lu_ref_add_atomic(&lock->l_reference, "reader", lock);
}
if (mode & (LCK_EX | LCK_CW | LCK_PW | LCK_GROUP | LCK_COS)) {
lock->l_writers++;
lu_ref_add_atomic(&lock->l_reference, "writer", lock);
}
LDLM_LOCK_GET(lock);
lu_ref_add_atomic(&lock->l_reference, "user", lock);
LDLM_DEBUG(lock, "ldlm_lock_addref(%s)", ldlm_lockname[mode]);
}
int ldlm_lock_addref_try(const struct lustre_handle *lockh, enum ldlm_mode mode)
{
struct ldlm_lock *lock;
int result;
result = -EAGAIN;
lock = ldlm_handle2lock(lockh);
if (lock) {
lock_res_and_lock(lock);
if (lock->l_readers != 0 || lock->l_writers != 0 ||
!ldlm_is_cbpending(lock)) {
ldlm_lock_addref_internal_nolock(lock, mode);
result = 0;
}
unlock_res_and_lock(lock);
LDLM_LOCK_PUT(lock);
}
return result;
}
void ldlm_lock_addref_internal(struct ldlm_lock *lock, enum ldlm_mode mode)
{
lock_res_and_lock(lock);
ldlm_lock_addref_internal_nolock(lock, mode);
unlock_res_and_lock(lock);
}
void ldlm_lock_decref_internal_nolock(struct ldlm_lock *lock,
enum ldlm_mode mode)
{
LDLM_DEBUG(lock, "ldlm_lock_decref(%s)", ldlm_lockname[mode]);
if (mode & (LCK_NL | LCK_CR | LCK_PR)) {
LASSERT(lock->l_readers > 0);
lu_ref_del(&lock->l_reference, "reader", lock);
lock->l_readers--;
}
if (mode & (LCK_EX | LCK_CW | LCK_PW | LCK_GROUP | LCK_COS)) {
LASSERT(lock->l_writers > 0);
lu_ref_del(&lock->l_reference, "writer", lock);
lock->l_writers--;
}
lu_ref_del(&lock->l_reference, "user", lock);
LDLM_LOCK_RELEASE(lock);
}
void ldlm_lock_decref_internal(struct ldlm_lock *lock, enum ldlm_mode mode)
{
struct ldlm_namespace *ns;
lock_res_and_lock(lock);
ns = ldlm_lock_to_ns(lock);
ldlm_lock_decref_internal_nolock(lock, mode);
if ((ldlm_is_local(lock) || lock->l_req_mode == LCK_GROUP) &&
!lock->l_readers && !lock->l_writers) {
ldlm_set_cbpending(lock);
}
if (!lock->l_readers && !lock->l_writers && ldlm_is_cbpending(lock)) {
LDLM_DEBUG(lock, "final decref done on cbpending lock");
LDLM_LOCK_GET(lock);
ldlm_lock_remove_from_lru(lock);
unlock_res_and_lock(lock);
if (ldlm_is_fail_loc(lock))
OBD_RACE(OBD_FAIL_LDLM_CP_BL_RACE);
if (ldlm_is_atomic_cb(lock) ||
ldlm_bl_to_thread_lock(ns, NULL, lock) != 0)
ldlm_handle_bl_callback(ns, NULL, lock);
} else if (!lock->l_readers && !lock->l_writers &&
!ldlm_is_no_lru(lock) && !ldlm_is_bl_ast(lock)) {
LDLM_DEBUG(lock, "add lock into lru list");
ldlm_lock_add_to_lru(lock);
unlock_res_and_lock(lock);
if (ldlm_is_fail_loc(lock))
OBD_RACE(OBD_FAIL_LDLM_CP_BL_RACE);
if (!exp_connect_cancelset(lock->l_conn_export) &&
!ns_connect_lru_resize(ns))
ldlm_cancel_lru(ns, 0, LCF_ASYNC, 0);
} else {
LDLM_DEBUG(lock, "do not add lock into lru list");
unlock_res_and_lock(lock);
}
}
void ldlm_lock_decref(const struct lustre_handle *lockh, enum ldlm_mode mode)
{
struct ldlm_lock *lock = __ldlm_handle2lock(lockh, 0);
LASSERTF(lock, "Non-existing lock: %#llx\n", lockh->cookie);
ldlm_lock_decref_internal(lock, mode);
LDLM_LOCK_PUT(lock);
}
void ldlm_lock_decref_and_cancel(const struct lustre_handle *lockh,
enum ldlm_mode mode)
{
struct ldlm_lock *lock = __ldlm_handle2lock(lockh, 0);
LASSERT(lock);
LDLM_DEBUG(lock, "ldlm_lock_decref(%s)", ldlm_lockname[mode]);
lock_res_and_lock(lock);
ldlm_set_cbpending(lock);
unlock_res_and_lock(lock);
ldlm_lock_decref_internal(lock, mode);
LDLM_LOCK_PUT(lock);
}
static void search_granted_lock(struct list_head *queue,
struct ldlm_lock *req,
struct sl_insert_point *prev)
{
struct list_head *tmp;
struct ldlm_lock *lock, *mode_end, *policy_end;
list_for_each(tmp, queue) {
lock = list_entry(tmp, struct ldlm_lock, l_res_link);
mode_end = list_prev_entry(lock, l_sl_mode);
if (lock->l_req_mode != req->l_req_mode) {
tmp = &mode_end->l_res_link;
continue;
}
if (lock->l_resource->lr_type == LDLM_PLAIN) {
prev->res_link = &mode_end->l_res_link;
prev->mode_link = &mode_end->l_sl_mode;
prev->policy_link = &req->l_sl_policy;
return;
}
if (lock->l_resource->lr_type == LDLM_IBITS) {
for (;;) {
policy_end =
list_prev_entry(lock, l_sl_policy);
if (lock->l_policy_data.l_inodebits.bits ==
req->l_policy_data.l_inodebits.bits) {
prev->res_link =
&policy_end->l_res_link;
prev->mode_link =
&policy_end->l_sl_mode;
prev->policy_link =
&policy_end->l_sl_policy;
return;
}
if (policy_end == mode_end)
break;
tmp = policy_end->l_res_link.next;
lock = list_entry(tmp, struct ldlm_lock,
l_res_link);
}
prev->res_link = &mode_end->l_res_link;
prev->mode_link = &mode_end->l_sl_mode;
prev->policy_link = &req->l_sl_policy;
return;
}
LDLM_ERROR(lock, "is not LDLM_PLAIN or LDLM_IBITS lock");
LBUG();
}
prev->res_link = queue->prev;
prev->mode_link = &req->l_sl_mode;
prev->policy_link = &req->l_sl_policy;
}
static void ldlm_granted_list_add_lock(struct ldlm_lock *lock,
struct sl_insert_point *prev)
{
struct ldlm_resource *res = lock->l_resource;
check_res_locked(res);
ldlm_resource_dump(D_INFO, res);
LDLM_DEBUG(lock, "About to add lock:");
if (ldlm_is_destroyed(lock)) {
CDEBUG(D_OTHER, "Lock destroyed, not adding to resource\n");
return;
}
LASSERT(list_empty(&lock->l_res_link));
LASSERT(list_empty(&lock->l_sl_mode));
LASSERT(list_empty(&lock->l_sl_policy));
if (&lock->l_res_link != prev->res_link)
list_add(&lock->l_res_link, prev->res_link);
if (&lock->l_sl_mode != prev->mode_link)
list_add(&lock->l_sl_mode, prev->mode_link);
if (&lock->l_sl_policy != prev->policy_link)
list_add(&lock->l_sl_policy, prev->policy_link);
}
static void ldlm_grant_lock_with_skiplist(struct ldlm_lock *lock)
{
struct sl_insert_point prev;
LASSERT(lock->l_req_mode == lock->l_granted_mode);
search_granted_lock(&lock->l_resource->lr_granted, lock, &prev);
ldlm_granted_list_add_lock(lock, &prev);
}
void ldlm_grant_lock(struct ldlm_lock *lock, struct list_head *work_list)
{
struct ldlm_resource *res = lock->l_resource;
check_res_locked(res);
lock->l_granted_mode = lock->l_req_mode;
if (work_list && lock->l_completion_ast)
ldlm_add_ast_work_item(lock, NULL, work_list);
if (res->lr_type == LDLM_PLAIN || res->lr_type == LDLM_IBITS) {
ldlm_grant_lock_with_skiplist(lock);
} else if (res->lr_type == LDLM_EXTENT) {
ldlm_extent_add_lock(res, lock);
} else if (res->lr_type == LDLM_FLOCK) {
if (!lock->l_req_mode || lock->l_req_mode == LCK_NL ||
ldlm_is_test_lock(lock) || ldlm_is_flock_deadlock(lock))
return;
ldlm_resource_add_lock(res, &res->lr_granted, lock);
} else {
LBUG();
}
ldlm_pool_add(&ldlm_res_to_ns(res)->ns_pool, lock);
}
static int lock_matches(struct ldlm_lock *lock, struct lock_match_data *data)
{
union ldlm_policy_data *lpol = &lock->l_policy_data;
enum ldlm_mode match;
if (lock == data->lmd_old)
return INTERVAL_ITER_STOP;
if (ldlm_is_excl(lock))
return INTERVAL_ITER_CONT;
if (ldlm_is_cbpending(lock) &&
!(data->lmd_flags & LDLM_FL_CBPENDING))
return INTERVAL_ITER_CONT;
if (!data->lmd_unref && ldlm_is_cbpending(lock) &&
!lock->l_readers && !lock->l_writers)
return INTERVAL_ITER_CONT;
if (!(lock->l_req_mode & *data->lmd_mode))
return INTERVAL_ITER_CONT;
match = lock->l_req_mode;
switch (lock->l_resource->lr_type) {
case LDLM_EXTENT:
if (lpol->l_extent.start > data->lmd_policy->l_extent.start ||
lpol->l_extent.end < data->lmd_policy->l_extent.end)
return INTERVAL_ITER_CONT;
if (unlikely(match == LCK_GROUP) &&
data->lmd_policy->l_extent.gid != LDLM_GID_ANY &&
lpol->l_extent.gid != data->lmd_policy->l_extent.gid)
return INTERVAL_ITER_CONT;
break;
case LDLM_IBITS:
if ((lpol->l_inodebits.bits &
data->lmd_policy->l_inodebits.bits) !=
data->lmd_policy->l_inodebits.bits)
return INTERVAL_ITER_CONT;
break;
default:
break;
}
if (!data->lmd_unref && LDLM_HAVE_MASK(lock, GONE))
return INTERVAL_ITER_CONT;
if (!equi(data->lmd_flags & LDLM_FL_LOCAL_ONLY, ldlm_is_local(lock)))
return INTERVAL_ITER_CONT;
if (data->lmd_flags & LDLM_FL_TEST_LOCK) {
LDLM_LOCK_GET(lock);
ldlm_lock_touch_in_lru(lock);
} else {
ldlm_lock_addref_internal_nolock(lock, match);
}
*data->lmd_mode = match;
data->lmd_lock = lock;
return INTERVAL_ITER_STOP;
}
static enum interval_iter itree_overlap_cb(struct interval_node *in, void *args)
{
struct ldlm_interval *node = to_ldlm_interval(in);
struct lock_match_data *data = args;
struct ldlm_lock *lock;
int rc;
list_for_each_entry(lock, &node->li_group, l_sl_policy) {
rc = lock_matches(lock, data);
if (rc == INTERVAL_ITER_STOP)
return INTERVAL_ITER_STOP;
}
return INTERVAL_ITER_CONT;
}
static struct ldlm_lock *search_itree(struct ldlm_resource *res,
struct lock_match_data *data)
{
struct interval_node_extent ext = {
.start = data->lmd_policy->l_extent.start,
.end = data->lmd_policy->l_extent.end
};
int idx;
for (idx = 0; idx < LCK_MODE_NUM; idx++) {
struct ldlm_interval_tree *tree = &res->lr_itree[idx];
if (!tree->lit_root)
continue;
if (!(tree->lit_mode & *data->lmd_mode))
continue;
interval_search(tree->lit_root, &ext,
itree_overlap_cb, data);
}
return data->lmd_lock;
}
static struct ldlm_lock *search_queue(struct list_head *queue,
struct lock_match_data *data)
{
struct ldlm_lock *lock;
int rc;
list_for_each_entry(lock, queue, l_res_link) {
rc = lock_matches(lock, data);
if (rc == INTERVAL_ITER_STOP)
return data->lmd_lock;
}
return NULL;
}
void ldlm_lock_fail_match_locked(struct ldlm_lock *lock)
{
if ((lock->l_flags & LDLM_FL_FAIL_NOTIFIED) == 0) {
lock->l_flags |= LDLM_FL_FAIL_NOTIFIED;
wake_up_all(&lock->l_waitq);
}
}
void ldlm_lock_allow_match_locked(struct ldlm_lock *lock)
{
ldlm_set_lvb_ready(lock);
wake_up_all(&lock->l_waitq);
}
void ldlm_lock_allow_match(struct ldlm_lock *lock)
{
lock_res_and_lock(lock);
ldlm_lock_allow_match_locked(lock);
unlock_res_and_lock(lock);
}
enum ldlm_mode ldlm_lock_match(struct ldlm_namespace *ns, __u64 flags,
const struct ldlm_res_id *res_id,
enum ldlm_type type,
union ldlm_policy_data *policy,
enum ldlm_mode mode,
struct lustre_handle *lockh, int unref)
{
struct lock_match_data data = {
.lmd_old = NULL,
.lmd_lock = NULL,
.lmd_mode = &mode,
.lmd_policy = policy,
.lmd_flags = flags,
.lmd_unref = unref,
};
struct ldlm_resource *res;
struct ldlm_lock *lock;
int rc = 0;
if (!ns) {
data.lmd_old = ldlm_handle2lock(lockh);
LASSERT(data.lmd_old);
ns = ldlm_lock_to_ns(data.lmd_old);
res_id = &data.lmd_old->l_resource->lr_name;
type = data.lmd_old->l_resource->lr_type;
*data.lmd_mode = data.lmd_old->l_req_mode;
}
res = ldlm_resource_get(ns, NULL, res_id, type, 0);
if (IS_ERR(res)) {
LASSERT(!data.lmd_old);
return 0;
}
LDLM_RESOURCE_ADDREF(res);
lock_res(res);
if (res->lr_type == LDLM_EXTENT)
lock = search_itree(res, &data);
else
lock = search_queue(&res->lr_granted, &data);
if (lock) {
rc = 1;
goto out;
}
if (flags & LDLM_FL_BLOCK_GRANTED) {
rc = 0;
goto out;
}
lock = search_queue(&res->lr_waiting, &data);
if (lock) {
rc = 1;
goto out;
}
out:
unlock_res(res);
LDLM_RESOURCE_DELREF(res);
ldlm_resource_putref(res);
if (lock) {
ldlm_lock2handle(lock, lockh);
if ((flags & LDLM_FL_LVB_READY) && !ldlm_is_lvb_ready(lock)) {
__u64 wait_flags = LDLM_FL_LVB_READY |
LDLM_FL_DESTROYED | LDLM_FL_FAIL_NOTIFIED;
struct l_wait_info lwi;
if (lock->l_completion_ast) {
int err = lock->l_completion_ast(lock,
LDLM_FL_WAIT_NOREPROC,
NULL);
if (err) {
if (flags & LDLM_FL_TEST_LOCK)
LDLM_LOCK_RELEASE(lock);
else
ldlm_lock_decref_internal(lock,
mode);
rc = 0;
goto out2;
}
}
lwi = LWI_TIMEOUT_INTR(cfs_time_seconds(obd_timeout),
NULL, LWI_ON_SIGNAL_NOOP, NULL);
l_wait_event(lock->l_waitq,
lock->l_flags & wait_flags,
&lwi);
if (!ldlm_is_lvb_ready(lock)) {
if (flags & LDLM_FL_TEST_LOCK)
LDLM_LOCK_RELEASE(lock);
else
ldlm_lock_decref_internal(lock, mode);
rc = 0;
}
}
}
out2:
if (rc) {
LDLM_DEBUG(lock, "matched (%llu %llu)",
(type == LDLM_PLAIN || type == LDLM_IBITS) ?
res_id->name[2] : policy->l_extent.start,
(type == LDLM_PLAIN || type == LDLM_IBITS) ?
res_id->name[3] : policy->l_extent.end);
if (lock->l_conn_export &&
sptlrpc_import_check_ctx(
class_exp2cliimp(lock->l_conn_export))) {
if (!(flags & LDLM_FL_TEST_LOCK))
ldlm_lock_decref_internal(lock, mode);
rc = 0;
}
if (flags & LDLM_FL_TEST_LOCK)
LDLM_LOCK_RELEASE(lock);
} else if (!(flags & LDLM_FL_TEST_LOCK)) {
LDLM_DEBUG_NOLOCK("not matched ns %p type %u mode %u res %llu/%llu (%llu %llu)",
ns, type, mode, res_id->name[0],
res_id->name[1],
(type == LDLM_PLAIN || type == LDLM_IBITS) ?
res_id->name[2] : policy->l_extent.start,
(type == LDLM_PLAIN || type == LDLM_IBITS) ?
res_id->name[3] : policy->l_extent.end);
}
if (data.lmd_old)
LDLM_LOCK_PUT(data.lmd_old);
return rc ? mode : 0;
}
enum ldlm_mode ldlm_revalidate_lock_handle(const struct lustre_handle *lockh,
__u64 *bits)
{
struct ldlm_lock *lock;
enum ldlm_mode mode = 0;
lock = ldlm_handle2lock(lockh);
if (lock) {
lock_res_and_lock(lock);
if (LDLM_HAVE_MASK(lock, GONE))
goto out;
if (ldlm_is_cbpending(lock) &&
lock->l_readers == 0 && lock->l_writers == 0)
goto out;
if (bits)
*bits = lock->l_policy_data.l_inodebits.bits;
mode = lock->l_granted_mode;
ldlm_lock_addref_internal_nolock(lock, mode);
}
out:
if (lock) {
unlock_res_and_lock(lock);
LDLM_LOCK_PUT(lock);
}
return mode;
}
int ldlm_fill_lvb(struct ldlm_lock *lock, struct req_capsule *pill,
enum req_location loc, void *data, int size)
{
void *lvb;
LASSERT(data);
LASSERT(size >= 0);
switch (lock->l_lvb_type) {
case LVB_T_OST:
if (size == sizeof(struct ost_lvb)) {
if (loc == RCL_CLIENT)
lvb = req_capsule_client_swab_get(pill,
&RMF_DLM_LVB,
lustre_swab_ost_lvb);
else
lvb = req_capsule_server_swab_get(pill,
&RMF_DLM_LVB,
lustre_swab_ost_lvb);
if (unlikely(!lvb)) {
LDLM_ERROR(lock, "no LVB");
return -EPROTO;
}
memcpy(data, lvb, size);
} else if (size == sizeof(struct ost_lvb_v1)) {
struct ost_lvb *olvb = data;
if (loc == RCL_CLIENT)
lvb = req_capsule_client_swab_get(pill,
&RMF_DLM_LVB,
lustre_swab_ost_lvb_v1);
else
lvb = req_capsule_server_sized_swab_get(pill,
&RMF_DLM_LVB, size,
lustre_swab_ost_lvb_v1);
if (unlikely(!lvb)) {
LDLM_ERROR(lock, "no LVB");
return -EPROTO;
}
memcpy(data, lvb, size);
olvb->lvb_mtime_ns = 0;
olvb->lvb_atime_ns = 0;
olvb->lvb_ctime_ns = 0;
} else {
LDLM_ERROR(lock, "Replied unexpected ost LVB size %d",
size);
return -EINVAL;
}
break;
case LVB_T_LQUOTA:
if (size == sizeof(struct lquota_lvb)) {
if (loc == RCL_CLIENT)
lvb = req_capsule_client_swab_get(pill,
&RMF_DLM_LVB,
lustre_swab_lquota_lvb);
else
lvb = req_capsule_server_swab_get(pill,
&RMF_DLM_LVB,
lustre_swab_lquota_lvb);
if (unlikely(!lvb)) {
LDLM_ERROR(lock, "no LVB");
return -EPROTO;
}
memcpy(data, lvb, size);
} else {
LDLM_ERROR(lock,
"Replied unexpected lquota LVB size %d",
size);
return -EINVAL;
}
break;
case LVB_T_LAYOUT:
if (size == 0)
break;
if (loc == RCL_CLIENT)
lvb = req_capsule_client_get(pill, &RMF_DLM_LVB);
else
lvb = req_capsule_server_get(pill, &RMF_DLM_LVB);
if (unlikely(!lvb)) {
LDLM_ERROR(lock, "no LVB");
return -EPROTO;
}
memcpy(data, lvb, size);
break;
default:
LDLM_ERROR(lock, "Unknown LVB type: %d", lock->l_lvb_type);
dump_stack();
return -EINVAL;
}
return 0;
}
struct ldlm_lock *ldlm_lock_create(struct ldlm_namespace *ns,
const struct ldlm_res_id *res_id,
enum ldlm_type type,
enum ldlm_mode mode,
const struct ldlm_callback_suite *cbs,
void *data, __u32 lvb_len,
enum lvb_type lvb_type)
{
struct ldlm_lock *lock;
struct ldlm_resource *res;
int rc;
res = ldlm_resource_get(ns, NULL, res_id, type, 1);
if (IS_ERR(res))
return ERR_CAST(res);
lock = ldlm_lock_new(res);
if (!lock)
return ERR_PTR(-ENOMEM);
lock->l_req_mode = mode;
lock->l_ast_data = data;
lock->l_pid = current_pid();
if (cbs) {
lock->l_blocking_ast = cbs->lcs_blocking;
lock->l_completion_ast = cbs->lcs_completion;
lock->l_glimpse_ast = cbs->lcs_glimpse;
}
lock->l_tree_node = NULL;
if (type == LDLM_EXTENT) {
if (!ldlm_interval_alloc(lock)) {
rc = -ENOMEM;
goto out;
}
}
if (lvb_len) {
lock->l_lvb_len = lvb_len;
lock->l_lvb_data = kzalloc(lvb_len, GFP_NOFS);
if (!lock->l_lvb_data) {
rc = -ENOMEM;
goto out;
}
}
lock->l_lvb_type = lvb_type;
if (OBD_FAIL_CHECK(OBD_FAIL_LDLM_NEW_LOCK)) {
rc = -ENOENT;
goto out;
}
return lock;
out:
ldlm_lock_destroy(lock);
LDLM_LOCK_RELEASE(lock);
return ERR_PTR(rc);
}
enum ldlm_error ldlm_lock_enqueue(struct ldlm_namespace *ns,
struct ldlm_lock **lockp,
void *cookie, __u64 *flags)
{
struct ldlm_lock *lock = *lockp;
struct ldlm_resource *res = lock->l_resource;
lock_res_and_lock(lock);
if (lock->l_req_mode == lock->l_granted_mode) {
*flags &= ~LDLM_FL_BLOCKED_MASK;
goto out;
}
ldlm_resource_unlink_lock(lock);
if (res->lr_type == LDLM_EXTENT && !lock->l_tree_node)
LBUG();
if (*flags & LDLM_FL_AST_DISCARD_DATA)
ldlm_set_ast_discard_data(lock);
if (*flags & LDLM_FL_TEST_LOCK)
ldlm_set_test_lock(lock);
if (*flags & (LDLM_FL_BLOCK_WAIT | LDLM_FL_BLOCK_GRANTED))
ldlm_resource_add_lock(res, &res->lr_waiting, lock);
else
ldlm_grant_lock(lock, NULL);
out:
unlock_res_and_lock(lock);
return ELDLM_OK;
}
static int
ldlm_work_bl_ast_lock(struct ptlrpc_request_set *rqset, void *opaq)
{
struct ldlm_cb_set_arg *arg = opaq;
struct ldlm_lock_desc d;
int rc;
struct ldlm_lock *lock;
if (list_empty(arg->list))
return -ENOENT;
lock = list_entry(arg->list->next, struct ldlm_lock, l_bl_ast);
lock_res_and_lock(lock);
list_del_init(&lock->l_bl_ast);
LASSERT(ldlm_is_ast_sent(lock));
LASSERT(lock->l_bl_ast_run == 0);
LASSERT(lock->l_blocking_lock);
lock->l_bl_ast_run++;
unlock_res_and_lock(lock);
ldlm_lock2desc(lock->l_blocking_lock, &d);
rc = lock->l_blocking_ast(lock, &d, (void *)arg, LDLM_CB_BLOCKING);
LDLM_LOCK_RELEASE(lock->l_blocking_lock);
lock->l_blocking_lock = NULL;
LDLM_LOCK_RELEASE(lock);
return rc;
}
static int
ldlm_work_cp_ast_lock(struct ptlrpc_request_set *rqset, void *opaq)
{
struct ldlm_cb_set_arg *arg = opaq;
int rc = 0;
struct ldlm_lock *lock;
ldlm_completion_callback completion_callback;
if (list_empty(arg->list))
return -ENOENT;
lock = list_entry(arg->list->next, struct ldlm_lock, l_cp_ast);
lock_res_and_lock(lock);
list_del_init(&lock->l_cp_ast);
LASSERT(ldlm_is_cp_reqd(lock));
completion_callback = lock->l_completion_ast;
ldlm_clear_cp_reqd(lock);
unlock_res_and_lock(lock);
if (completion_callback)
rc = completion_callback(lock, 0, (void *)arg);
LDLM_LOCK_RELEASE(lock);
return rc;
}
static int
ldlm_work_revoke_ast_lock(struct ptlrpc_request_set *rqset, void *opaq)
{
struct ldlm_cb_set_arg *arg = opaq;
struct ldlm_lock_desc desc;
int rc;
struct ldlm_lock *lock;
if (list_empty(arg->list))
return -ENOENT;
lock = list_entry(arg->list->next, struct ldlm_lock, l_rk_ast);
list_del_init(&lock->l_rk_ast);
ldlm_lock2desc(lock, &desc);
desc.l_req_mode = LCK_EX;
desc.l_granted_mode = 0;
rc = lock->l_blocking_ast(lock, &desc, (void *)arg, LDLM_CB_BLOCKING);
LDLM_LOCK_RELEASE(lock);
return rc;
}
static int ldlm_work_gl_ast_lock(struct ptlrpc_request_set *rqset, void *opaq)
{
struct ldlm_cb_set_arg *arg = opaq;
struct ldlm_glimpse_work *gl_work;
struct ldlm_lock *lock;
int rc = 0;
if (list_empty(arg->list))
return -ENOENT;
gl_work = list_entry(arg->list->next, struct ldlm_glimpse_work,
gl_list);
list_del_init(&gl_work->gl_list);
lock = gl_work->gl_lock;
arg->gl_desc = gl_work->gl_desc;
if (lock->l_glimpse_ast(lock, (void *)arg) == 0)
rc = 1;
LDLM_LOCK_RELEASE(lock);
if ((gl_work->gl_flags & LDLM_GL_WORK_NOFREE) == 0)
kfree(gl_work);
return rc;
}
int ldlm_run_ast_work(struct ldlm_namespace *ns, struct list_head *rpc_list,
enum ldlm_desc_ast_t ast_type)
{
struct ldlm_cb_set_arg *arg;
set_producer_func work_ast_lock;
int rc;
if (list_empty(rpc_list))
return 0;
arg = kzalloc(sizeof(*arg), GFP_NOFS);
if (!arg)
return -ENOMEM;
atomic_set(&arg->restart, 0);
arg->list = rpc_list;
switch (ast_type) {
case LDLM_WORK_BL_AST:
arg->type = LDLM_BL_CALLBACK;
work_ast_lock = ldlm_work_bl_ast_lock;
break;
case LDLM_WORK_CP_AST:
arg->type = LDLM_CP_CALLBACK;
work_ast_lock = ldlm_work_cp_ast_lock;
break;
case LDLM_WORK_REVOKE_AST:
arg->type = LDLM_BL_CALLBACK;
work_ast_lock = ldlm_work_revoke_ast_lock;
break;
case LDLM_WORK_GL_AST:
arg->type = LDLM_GL_CALLBACK;
work_ast_lock = ldlm_work_gl_ast_lock;
break;
default:
LBUG();
}
arg->set = ptlrpc_prep_fcset(ns->ns_max_parallel_ast ? : UINT_MAX,
work_ast_lock, arg);
if (!arg->set) {
rc = -ENOMEM;
goto out;
}
ptlrpc_set_wait(arg->set);
ptlrpc_set_destroy(arg->set);
rc = atomic_read(&arg->restart) ? -ERESTART : 0;
goto out;
out:
kfree(arg);
return rc;
}
static bool is_bl_done(struct ldlm_lock *lock)
{
bool bl_done = true;
if (!ldlm_is_bl_done(lock)) {
lock_res_and_lock(lock);
bl_done = ldlm_is_bl_done(lock);
unlock_res_and_lock(lock);
}
return bl_done;
}
void ldlm_cancel_callback(struct ldlm_lock *lock)
{
check_res_locked(lock->l_resource);
if (!ldlm_is_cancel(lock)) {
ldlm_set_cancel(lock);
if (lock->l_blocking_ast) {
unlock_res_and_lock(lock);
lock->l_blocking_ast(lock, NULL, lock->l_ast_data,
LDLM_CB_CANCELING);
lock_res_and_lock(lock);
} else {
LDLM_DEBUG(lock, "no blocking ast");
}
ldlm_set_bl_done(lock);
wake_up_all(&lock->l_waitq);
} else if (!ldlm_is_bl_done(lock)) {
struct l_wait_info lwi = { 0 };
unlock_res_and_lock(lock);
l_wait_event(lock->l_waitq, is_bl_done(lock), &lwi);
lock_res_and_lock(lock);
}
}
void ldlm_unlink_lock_skiplist(struct ldlm_lock *req)
{
if (req->l_resource->lr_type != LDLM_PLAIN &&
req->l_resource->lr_type != LDLM_IBITS)
return;
list_del_init(&req->l_sl_policy);
list_del_init(&req->l_sl_mode);
}
void ldlm_lock_cancel(struct ldlm_lock *lock)
{
struct ldlm_resource *res;
struct ldlm_namespace *ns;
lock_res_and_lock(lock);
res = lock->l_resource;
ns = ldlm_res_to_ns(res);
if (lock->l_readers || lock->l_writers) {
LDLM_ERROR(lock, "lock still has references");
LBUG();
}
ldlm_cancel_callback(lock);
ldlm_resource_unlink_lock(lock);
ldlm_lock_destroy_nolock(lock);
if (lock->l_granted_mode == lock->l_req_mode)
ldlm_pool_del(&ns->ns_pool, lock);
lock->l_granted_mode = LCK_MINMODE;
unlock_res_and_lock(lock);
}
int ldlm_lock_set_data(const struct lustre_handle *lockh, void *data)
{
struct ldlm_lock *lock = ldlm_handle2lock(lockh);
int rc = -EINVAL;
if (lock) {
if (!lock->l_ast_data)
lock->l_ast_data = data;
if (lock->l_ast_data == data)
rc = 0;
LDLM_LOCK_PUT(lock);
}
return rc;
}
void ldlm_lock_dump_handle(int level, const struct lustre_handle *lockh)
{
struct ldlm_lock *lock;
if (!((libcfs_debug | D_ERROR) & level))
return;
lock = ldlm_handle2lock(lockh);
if (!lock)
return;
LDLM_DEBUG_LIMIT(level, lock, "###");
LDLM_LOCK_PUT(lock);
}
void _ldlm_lock_debug(struct ldlm_lock *lock,
struct libcfs_debug_msg_data *msgdata,
const char *fmt, ...)
{
va_list args;
struct obd_export *exp = lock->l_export;
struct ldlm_resource *resource = lock->l_resource;
char *nid = "local";
va_start(args, fmt);
if (exp && exp->exp_connection) {
nid = libcfs_nid2str(exp->exp_connection->c_peer.nid);
} else if (exp && exp->exp_obd) {
struct obd_import *imp = exp->exp_obd->u.cli.cl_import;
nid = libcfs_nid2str(imp->imp_connection->c_peer.nid);
}
if (!resource) {
libcfs_debug_vmsg2(msgdata, fmt, args,
" ns: \?\? lock: %p/%#llx lrc: %d/%d,%d mode: %s/%s res: \?\? rrc=\?\? type: \?\?\? flags: %#llx nid: %s remote: %#llx expref: %d pid: %u timeout: %lu lvb_type: %d\n",
lock,
lock->l_handle.h_cookie, atomic_read(&lock->l_refc),
lock->l_readers, lock->l_writers,
ldlm_lockname[lock->l_granted_mode],
ldlm_lockname[lock->l_req_mode],
lock->l_flags, nid, lock->l_remote_handle.cookie,
exp ? atomic_read(&exp->exp_refcount) : -99,
lock->l_pid, lock->l_callback_timeout, lock->l_lvb_type);
va_end(args);
return;
}
switch (resource->lr_type) {
case LDLM_EXTENT:
libcfs_debug_vmsg2(msgdata, fmt, args,
" ns: %s lock: %p/%#llx lrc: %d/%d,%d mode: %s/%s res: " DLDLMRES " rrc: %d type: %s [%llu->%llu] (req %llu->%llu) flags: %#llx nid: %s remote: %#llx expref: %d pid: %u timeout: %lu lvb_type: %d\n",
ldlm_lock_to_ns_name(lock), lock,
lock->l_handle.h_cookie, atomic_read(&lock->l_refc),
lock->l_readers, lock->l_writers,
ldlm_lockname[lock->l_granted_mode],
ldlm_lockname[lock->l_req_mode],
PLDLMRES(resource),
atomic_read(&resource->lr_refcount),
ldlm_typename[resource->lr_type],
lock->l_policy_data.l_extent.start,
lock->l_policy_data.l_extent.end,
lock->l_req_extent.start, lock->l_req_extent.end,
lock->l_flags, nid, lock->l_remote_handle.cookie,
exp ? atomic_read(&exp->exp_refcount) : -99,
lock->l_pid, lock->l_callback_timeout,
lock->l_lvb_type);
break;
case LDLM_FLOCK:
libcfs_debug_vmsg2(msgdata, fmt, args,
" ns: %s lock: %p/%#llx lrc: %d/%d,%d mode: %s/%s res: " DLDLMRES " rrc: %d type: %s pid: %d [%llu->%llu] flags: %#llx nid: %s remote: %#llx expref: %d pid: %u timeout: %lu\n",
ldlm_lock_to_ns_name(lock), lock,
lock->l_handle.h_cookie, atomic_read(&lock->l_refc),
lock->l_readers, lock->l_writers,
ldlm_lockname[lock->l_granted_mode],
ldlm_lockname[lock->l_req_mode],
PLDLMRES(resource),
atomic_read(&resource->lr_refcount),
ldlm_typename[resource->lr_type],
lock->l_policy_data.l_flock.pid,
lock->l_policy_data.l_flock.start,
lock->l_policy_data.l_flock.end,
lock->l_flags, nid, lock->l_remote_handle.cookie,
exp ? atomic_read(&exp->exp_refcount) : -99,
lock->l_pid, lock->l_callback_timeout);
break;
case LDLM_IBITS:
libcfs_debug_vmsg2(msgdata, fmt, args,
" ns: %s lock: %p/%#llx lrc: %d/%d,%d mode: %s/%s res: " DLDLMRES " bits %#llx rrc: %d type: %s flags: %#llx nid: %s remote: %#llx expref: %d pid: %u timeout: %lu lvb_type: %d\n",
ldlm_lock_to_ns_name(lock),
lock, lock->l_handle.h_cookie,
atomic_read(&lock->l_refc),
lock->l_readers, lock->l_writers,
ldlm_lockname[lock->l_granted_mode],
ldlm_lockname[lock->l_req_mode],
PLDLMRES(resource),
lock->l_policy_data.l_inodebits.bits,
atomic_read(&resource->lr_refcount),
ldlm_typename[resource->lr_type],
lock->l_flags, nid, lock->l_remote_handle.cookie,
exp ? atomic_read(&exp->exp_refcount) : -99,
lock->l_pid, lock->l_callback_timeout,
lock->l_lvb_type);
break;
default:
libcfs_debug_vmsg2(msgdata, fmt, args,
" ns: %s lock: %p/%#llx lrc: %d/%d,%d mode: %s/%s res: " DLDLMRES " rrc: %d type: %s flags: %#llx nid: %s remote: %#llx expref: %d pid: %u timeout: %lu lvb_type: %d\n",
ldlm_lock_to_ns_name(lock),
lock, lock->l_handle.h_cookie,
atomic_read(&lock->l_refc),
lock->l_readers, lock->l_writers,
ldlm_lockname[lock->l_granted_mode],
ldlm_lockname[lock->l_req_mode],
PLDLMRES(resource),
atomic_read(&resource->lr_refcount),
ldlm_typename[resource->lr_type],
lock->l_flags, nid, lock->l_remote_handle.cookie,
exp ? atomic_read(&exp->exp_refcount) : -99,
lock->l_pid, lock->l_callback_timeout,
lock->l_lvb_type);
break;
}
va_end(args);
}
