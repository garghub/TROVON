void ldlm_convert_policy_to_wire(ldlm_type_t type,
const ldlm_policy_data_t *lpolicy,
ldlm_wire_policy_data_t *wpolicy)
{
ldlm_policy_local_to_wire_t convert;
convert = ldlm_policy_local_to_wire[type - LDLM_MIN_TYPE];
convert(lpolicy, wpolicy);
}
void ldlm_convert_policy_to_local(struct obd_export *exp, ldlm_type_t type,
const ldlm_wire_policy_data_t *wpolicy,
ldlm_policy_data_t *lpolicy)
{
ldlm_policy_wire_to_local_t convert;
int new_client;
new_client = (exp_connect_flags(exp) & OBD_CONNECT_FULL20) != 0;
if (new_client)
convert = ldlm_policy_wire21_to_local[type - LDLM_MIN_TYPE];
else
convert = ldlm_policy_wire18_to_local[type - LDLM_MIN_TYPE];
convert(wpolicy, lpolicy);
}
char *ldlm_it2str(int it)
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
CERROR("Unknown intent %d\n", it);
return "UNKNOWN";
}
}
void ldlm_register_intent(struct ldlm_namespace *ns, ldlm_res_policy arg)
{
ns->ns_policy = arg;
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
LASSERT(lock->l_flags & LDLM_FL_DESTROYED);
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
if (lock->l_lvb_data != NULL)
OBD_FREE(lock->l_lvb_data, lock->l_lvb_len);
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
int ldlm_lock_remove_from_lru(struct ldlm_lock *lock)
{
struct ldlm_namespace *ns = ldlm_lock_to_ns(lock);
int rc;
if (lock->l_flags & LDLM_FL_NS_SRV) {
LASSERT(list_empty(&lock->l_lru));
return 0;
}
spin_lock(&ns->ns_lock);
rc = ldlm_lock_remove_from_lru_nolock(lock);
spin_unlock(&ns->ns_lock);
return rc;
}
void ldlm_lock_add_to_lru_nolock(struct ldlm_lock *lock)
{
struct ldlm_namespace *ns = ldlm_lock_to_ns(lock);
lock->l_last_used = cfs_time_current();
LASSERT(list_empty(&lock->l_lru));
LASSERT(lock->l_resource->lr_type != LDLM_FLOCK);
list_add_tail(&lock->l_lru, &ns->ns_unused_list);
if (lock->l_flags & LDLM_FL_SKIPPED)
lock->l_flags &= ~LDLM_FL_SKIPPED;
LASSERT(ns->ns_nr_unused >= 0);
ns->ns_nr_unused++;
}
void ldlm_lock_add_to_lru(struct ldlm_lock *lock)
{
struct ldlm_namespace *ns = ldlm_lock_to_ns(lock);
spin_lock(&ns->ns_lock);
ldlm_lock_add_to_lru_nolock(lock);
spin_unlock(&ns->ns_lock);
}
void ldlm_lock_touch_in_lru(struct ldlm_lock *lock)
{
struct ldlm_namespace *ns = ldlm_lock_to_ns(lock);
if (lock->l_flags & LDLM_FL_NS_SRV) {
LASSERT(list_empty(&lock->l_lru));
return;
}
spin_lock(&ns->ns_lock);
if (!list_empty(&lock->l_lru)) {
ldlm_lock_remove_from_lru_nolock(lock);
ldlm_lock_add_to_lru_nolock(lock);
}
spin_unlock(&ns->ns_lock);
}
int ldlm_lock_destroy_internal(struct ldlm_lock *lock)
{
if (lock->l_readers || lock->l_writers) {
LDLM_ERROR(lock, "lock still has references");
LBUG();
}
if (!list_empty(&lock->l_res_link)) {
LDLM_ERROR(lock, "lock still on resource");
LBUG();
}
if (lock->l_flags & LDLM_FL_DESTROYED) {
LASSERT(list_empty(&lock->l_lru));
return 0;
}
lock->l_flags |= LDLM_FL_DESTROYED;
if (lock->l_export && lock->l_export->exp_lock_hash) {
cfs_hash_del(lock->l_export->exp_lock_hash,
&lock->l_remote_handle, &lock->l_exp_hash);
}
ldlm_lock_remove_from_lru(lock);
class_handle_unhash(&lock->l_handle);
#if 0
if (lock->l_export)
class_export_put(lock->l_export);
lock->l_export = NULL;
if (lock->l_export && lock->l_completion_ast)
lock->l_completion_ast(lock, 0);
#endif
return 1;
}
void ldlm_lock_destroy(struct ldlm_lock *lock)
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
OBD_SLAB_FREE(lock, ldlm_lock_slab, size);
}
static struct ldlm_lock *ldlm_lock_new(struct ldlm_resource *resource)
{
struct ldlm_lock *lock;
if (resource == NULL)
LBUG();
OBD_SLAB_ALLOC_PTR_GFP(lock, ldlm_lock_slab, GFP_NOFS);
if (lock == NULL)
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
INIT_LIST_HEAD(&lock->l_exp_list);
return lock;
}
int ldlm_lock_change_resource(struct ldlm_namespace *ns, struct ldlm_lock *lock,
const struct ldlm_res_id *new_resid)
{
struct ldlm_resource *oldres = lock->l_resource;
struct ldlm_resource *newres;
int type;
LASSERT(ns_is_client(ns));
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
if (newres == NULL)
return -ENOMEM;
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
lock = class_handle2object(handle->cookie);
if (lock == NULL)
return NULL;
if (flags == 0 && ((lock->l_flags & LDLM_FL_DESTROYED)== 0)) {
lu_ref_add(&lock->l_reference, "handle", current);
return lock;
}
lock_res_and_lock(lock);
LASSERT(lock->l_resource != NULL);
lu_ref_add_atomic(&lock->l_reference, "handle", current);
if (unlikely(lock->l_flags & LDLM_FL_DESTROYED)) {
unlock_res_and_lock(lock);
CDEBUG(D_INFO, "lock already destroyed: lock %p\n", lock);
LDLM_LOCK_PUT(lock);
return NULL;
}
if (flags && (lock->l_flags & flags)) {
unlock_res_and_lock(lock);
LDLM_LOCK_PUT(lock);
return NULL;
}
if (flags)
lock->l_flags |= flags;
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
void ldlm_add_bl_work_item(struct ldlm_lock *lock, struct ldlm_lock *new,
struct list_head *work_list)
{
if ((lock->l_flags & LDLM_FL_AST_SENT) == 0) {
LDLM_DEBUG(lock, "lock incompatible; sending blocking AST.");
lock->l_flags |= LDLM_FL_AST_SENT;
if (new->l_flags & LDLM_FL_AST_DISCARD_DATA)
lock->l_flags |= LDLM_FL_DISCARD_DATA;
LASSERT(list_empty(&lock->l_bl_ast));
list_add(&lock->l_bl_ast, work_list);
LDLM_LOCK_GET(lock);
LASSERT(lock->l_blocking_lock == NULL);
lock->l_blocking_lock = LDLM_LOCK_GET(new);
}
}
void ldlm_add_cp_work_item(struct ldlm_lock *lock, struct list_head *work_list)
{
if ((lock->l_flags & LDLM_FL_CP_REQD) == 0) {
lock->l_flags |= LDLM_FL_CP_REQD;
LDLM_DEBUG(lock, "lock granted; sending completion AST.");
LASSERT(list_empty(&lock->l_cp_ast));
list_add(&lock->l_cp_ast, work_list);
LDLM_LOCK_GET(lock);
}
}
void ldlm_add_ast_work_item(struct ldlm_lock *lock, struct ldlm_lock *new,
struct list_head *work_list)
{
check_res_locked(lock->l_resource);
if (new)
ldlm_add_bl_work_item(lock, new, work_list);
else
ldlm_add_cp_work_item(lock, work_list);
}
void ldlm_lock_addref(struct lustre_handle *lockh, __u32 mode)
{
struct ldlm_lock *lock;
lock = ldlm_handle2lock(lockh);
LASSERT(lock != NULL);
ldlm_lock_addref_internal(lock, mode);
LDLM_LOCK_PUT(lock);
}
void ldlm_lock_addref_internal_nolock(struct ldlm_lock *lock, __u32 mode)
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
int ldlm_lock_addref_try(struct lustre_handle *lockh, __u32 mode)
{
struct ldlm_lock *lock;
int result;
result = -EAGAIN;
lock = ldlm_handle2lock(lockh);
if (lock != NULL) {
lock_res_and_lock(lock);
if (lock->l_readers != 0 || lock->l_writers != 0 ||
!(lock->l_flags & LDLM_FL_CBPENDING)) {
ldlm_lock_addref_internal_nolock(lock, mode);
result = 0;
}
unlock_res_and_lock(lock);
LDLM_LOCK_PUT(lock);
}
return result;
}
void ldlm_lock_addref_internal(struct ldlm_lock *lock, __u32 mode)
{
lock_res_and_lock(lock);
ldlm_lock_addref_internal_nolock(lock, mode);
unlock_res_and_lock(lock);
}
void ldlm_lock_decref_internal_nolock(struct ldlm_lock *lock, __u32 mode)
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
void ldlm_lock_decref_internal(struct ldlm_lock *lock, __u32 mode)
{
struct ldlm_namespace *ns;
lock_res_and_lock(lock);
ns = ldlm_lock_to_ns(lock);
ldlm_lock_decref_internal_nolock(lock, mode);
if (lock->l_flags & LDLM_FL_LOCAL &&
!lock->l_readers && !lock->l_writers) {
CDEBUG(D_INFO, "forcing cancel of local lock\n");
lock->l_flags |= LDLM_FL_CBPENDING;
}
if (!lock->l_readers && !lock->l_writers &&
(lock->l_flags & LDLM_FL_CBPENDING)) {
if ((lock->l_flags & LDLM_FL_NS_SRV) && lock->l_export)
CERROR("FL_CBPENDING set on non-local lock--just a "
"warning\n");
LDLM_DEBUG(lock, "final decref done on cbpending lock");
LDLM_LOCK_GET(lock);
ldlm_lock_remove_from_lru(lock);
unlock_res_and_lock(lock);
if (lock->l_flags & LDLM_FL_FAIL_LOC)
OBD_RACE(OBD_FAIL_LDLM_CP_BL_RACE);
if ((lock->l_flags & LDLM_FL_ATOMIC_CB) ||
ldlm_bl_to_thread_lock(ns, NULL, lock) != 0)
ldlm_handle_bl_callback(ns, NULL, lock);
} else if (ns_is_client(ns) &&
!lock->l_readers && !lock->l_writers &&
!(lock->l_flags & LDLM_FL_NO_LRU) &&
!(lock->l_flags & LDLM_FL_BL_AST)) {
LDLM_DEBUG(lock, "add lock into lru list");
ldlm_lock_add_to_lru(lock);
unlock_res_and_lock(lock);
if (lock->l_flags & LDLM_FL_FAIL_LOC)
OBD_RACE(OBD_FAIL_LDLM_CP_BL_RACE);
if (!exp_connect_cancelset(lock->l_conn_export) &&
!ns_connect_lru_resize(ns))
ldlm_cancel_lru(ns, 0, LCF_ASYNC, 0);
} else {
LDLM_DEBUG(lock, "do not add lock into lru list");
unlock_res_and_lock(lock);
}
}
void ldlm_lock_decref(struct lustre_handle *lockh, __u32 mode)
{
struct ldlm_lock *lock = __ldlm_handle2lock(lockh, 0);
LASSERTF(lock != NULL, "Non-existing lock: %#llx\n", lockh->cookie);
ldlm_lock_decref_internal(lock, mode);
LDLM_LOCK_PUT(lock);
}
void ldlm_lock_decref_and_cancel(struct lustre_handle *lockh, __u32 mode)
{
struct ldlm_lock *lock = __ldlm_handle2lock(lockh, 0);
LASSERT(lock != NULL);
LDLM_DEBUG(lock, "ldlm_lock_decref(%s)", ldlm_lockname[mode]);
lock_res_and_lock(lock);
lock->l_flags |= LDLM_FL_CBPENDING;
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
mode_end = list_entry(lock->l_sl_mode.prev,
struct ldlm_lock, l_sl_mode);
if (lock->l_req_mode != req->l_req_mode) {
tmp = &mode_end->l_res_link;
continue;
}
if (lock->l_resource->lr_type == LDLM_PLAIN) {
prev->res_link = &mode_end->l_res_link;
prev->mode_link = &mode_end->l_sl_mode;
prev->policy_link = &req->l_sl_policy;
return;
} else if (lock->l_resource->lr_type == LDLM_IBITS) {
for (;;) {
policy_end =
list_entry(lock->l_sl_policy.prev,
struct ldlm_lock,
l_sl_policy);
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
} else {
LDLM_ERROR(lock,
"is not LDLM_PLAIN or LDLM_IBITS lock");
LBUG();
}
}
prev->res_link = queue->prev;
prev->mode_link = &req->l_sl_mode;
prev->policy_link = &req->l_sl_policy;
return;
}
static void ldlm_granted_list_add_lock(struct ldlm_lock *lock,
struct sl_insert_point *prev)
{
struct ldlm_resource *res = lock->l_resource;
check_res_locked(res);
ldlm_resource_dump(D_INFO, res);
LDLM_DEBUG(lock, "About to add lock:");
if (lock->l_flags & LDLM_FL_DESTROYED) {
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
if (res->lr_type == LDLM_PLAIN || res->lr_type == LDLM_IBITS)
ldlm_grant_lock_with_skiplist(lock);
else if (res->lr_type == LDLM_EXTENT)
ldlm_extent_add_lock(res, lock);
else
ldlm_resource_add_lock(res, &res->lr_granted, lock);
if (lock->l_granted_mode < res->lr_most_restr)
res->lr_most_restr = lock->l_granted_mode;
if (work_list && lock->l_completion_ast != NULL)
ldlm_add_ast_work_item(lock, NULL, work_list);
ldlm_pool_add(&ldlm_res_to_ns(res)->ns_pool, lock);
}
static struct ldlm_lock *search_queue(struct list_head *queue,
ldlm_mode_t *mode,
ldlm_policy_data_t *policy,
struct ldlm_lock *old_lock,
__u64 flags, int unref)
{
struct ldlm_lock *lock;
struct list_head *tmp;
list_for_each(tmp, queue) {
ldlm_mode_t match;
lock = list_entry(tmp, struct ldlm_lock, l_res_link);
if (lock == old_lock)
break;
if (ldlm_is_excl(lock))
continue;
if (lock->l_flags & LDLM_FL_CBPENDING &&
!(flags & LDLM_FL_CBPENDING))
continue;
if (!unref && lock->l_flags & LDLM_FL_CBPENDING &&
lock->l_readers == 0 && lock->l_writers == 0)
continue;
if (!(lock->l_req_mode & *mode))
continue;
match = lock->l_req_mode;
if (lock->l_resource->lr_type == LDLM_EXTENT &&
(lock->l_policy_data.l_extent.start >
policy->l_extent.start ||
lock->l_policy_data.l_extent.end < policy->l_extent.end))
continue;
if (unlikely(match == LCK_GROUP) &&
lock->l_resource->lr_type == LDLM_EXTENT &&
lock->l_policy_data.l_extent.gid != policy->l_extent.gid)
continue;
if (lock->l_resource->lr_type == LDLM_IBITS &&
((lock->l_policy_data.l_inodebits.bits &
policy->l_inodebits.bits) !=
policy->l_inodebits.bits))
continue;
if (!unref && (lock->l_flags & LDLM_FL_GONE_MASK))
continue;
if ((flags & LDLM_FL_LOCAL_ONLY) &&
!(lock->l_flags & LDLM_FL_LOCAL))
continue;
if (flags & LDLM_FL_TEST_LOCK) {
LDLM_LOCK_GET(lock);
ldlm_lock_touch_in_lru(lock);
} else {
ldlm_lock_addref_internal_nolock(lock, match);
}
*mode = match;
return lock;
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
void ldlm_lock_fail_match(struct ldlm_lock *lock)
{
lock_res_and_lock(lock);
ldlm_lock_fail_match_locked(lock);
unlock_res_and_lock(lock);
}
void ldlm_lock_allow_match_locked(struct ldlm_lock *lock)
{
lock->l_flags |= LDLM_FL_LVB_READY;
wake_up_all(&lock->l_waitq);
}
void ldlm_lock_allow_match(struct ldlm_lock *lock)
{
lock_res_and_lock(lock);
ldlm_lock_allow_match_locked(lock);
unlock_res_and_lock(lock);
}
ldlm_mode_t ldlm_lock_match(struct ldlm_namespace *ns, __u64 flags,
const struct ldlm_res_id *res_id, ldlm_type_t type,
ldlm_policy_data_t *policy, ldlm_mode_t mode,
struct lustre_handle *lockh, int unref)
{
struct ldlm_resource *res;
struct ldlm_lock *lock, *old_lock = NULL;
int rc = 0;
if (ns == NULL) {
old_lock = ldlm_handle2lock(lockh);
LASSERT(old_lock);
ns = ldlm_lock_to_ns(old_lock);
res_id = &old_lock->l_resource->lr_name;
type = old_lock->l_resource->lr_type;
mode = old_lock->l_req_mode;
}
res = ldlm_resource_get(ns, NULL, res_id, type, 0);
if (res == NULL) {
LASSERT(old_lock == NULL);
return 0;
}
LDLM_RESOURCE_ADDREF(res);
lock_res(res);
lock = search_queue(&res->lr_granted, &mode, policy, old_lock,
flags, unref);
if (lock != NULL) {
rc = 1;
goto out;
}
if (flags & LDLM_FL_BLOCK_GRANTED) {
rc = 0;
goto out;
}
lock = search_queue(&res->lr_converting, &mode, policy, old_lock,
flags, unref);
if (lock != NULL) {
rc = 1;
goto out;
}
lock = search_queue(&res->lr_waiting, &mode, policy, old_lock,
flags, unref);
if (lock != NULL) {
rc = 1;
goto out;
}
out:
unlock_res(res);
LDLM_RESOURCE_DELREF(res);
ldlm_resource_putref(res);
if (lock) {
ldlm_lock2handle(lock, lockh);
if ((flags & LDLM_FL_LVB_READY) &&
(!(lock->l_flags & LDLM_FL_LVB_READY))) {
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
if (!(lock->l_flags & LDLM_FL_LVB_READY)) {
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
ns, type, mode, res_id->name[0], res_id->name[1],
(type == LDLM_PLAIN || type == LDLM_IBITS) ?
res_id->name[2] :policy->l_extent.start,
(type == LDLM_PLAIN || type == LDLM_IBITS) ?
res_id->name[3] : policy->l_extent.end);
}
if (old_lock)
LDLM_LOCK_PUT(old_lock);
return rc ? mode : 0;
}
ldlm_mode_t ldlm_revalidate_lock_handle(struct lustre_handle *lockh,
__u64 *bits)
{
struct ldlm_lock *lock;
ldlm_mode_t mode = 0;
lock = ldlm_handle2lock(lockh);
if (lock != NULL) {
lock_res_and_lock(lock);
if (lock->l_flags & LDLM_FL_GONE_MASK)
goto out;
if (lock->l_flags & LDLM_FL_CBPENDING &&
lock->l_readers == 0 && lock->l_writers == 0)
goto out;
if (bits)
*bits = lock->l_policy_data.l_inodebits.bits;
mode = lock->l_granted_mode;
ldlm_lock_addref_internal_nolock(lock, mode);
}
out:
if (lock != NULL) {
unlock_res_and_lock(lock);
LDLM_LOCK_PUT(lock);
}
return mode;
}
int ldlm_fill_lvb(struct ldlm_lock *lock, struct req_capsule *pill,
enum req_location loc, void *data, int size)
{
void *lvb;
LASSERT(data != NULL);
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
if (unlikely(lvb == NULL)) {
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
if (unlikely(lvb == NULL)) {
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
if (unlikely(lvb == NULL)) {
LDLM_ERROR(lock, "no LVB");
return -EPROTO;
}
memcpy(data, lvb, size);
} else {
LDLM_ERROR(lock, "Replied unexpected lquota LVB size %d",
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
if (unlikely(lvb == NULL)) {
LDLM_ERROR(lock, "no LVB");
return -EPROTO;
}
memcpy(data, lvb, size);
break;
default:
LDLM_ERROR(lock, "Unknown LVB type: %d\n", lock->l_lvb_type);
dump_stack();
return -EINVAL;
}
return 0;
}
struct ldlm_lock *ldlm_lock_create(struct ldlm_namespace *ns,
const struct ldlm_res_id *res_id,
ldlm_type_t type,
ldlm_mode_t mode,
const struct ldlm_callback_suite *cbs,
void *data, __u32 lvb_len,
enum lvb_type lvb_type)
{
struct ldlm_lock *lock;
struct ldlm_resource *res;
res = ldlm_resource_get(ns, NULL, res_id, type, 1);
if (res == NULL)
return NULL;
lock = ldlm_lock_new(res);
if (lock == NULL)
return NULL;
lock->l_req_mode = mode;
lock->l_ast_data = data;
lock->l_pid = current_pid();
if (ns_is_server(ns))
lock->l_flags |= LDLM_FL_NS_SRV;
if (cbs) {
lock->l_blocking_ast = cbs->lcs_blocking;
lock->l_completion_ast = cbs->lcs_completion;
lock->l_glimpse_ast = cbs->lcs_glimpse;
}
lock->l_tree_node = NULL;
if (type == LDLM_EXTENT) {
if (ldlm_interval_alloc(lock) == NULL)
goto out;
}
if (lvb_len) {
lock->l_lvb_len = lvb_len;
OBD_ALLOC(lock->l_lvb_data, lvb_len);
if (lock->l_lvb_data == NULL)
goto out;
}
lock->l_lvb_type = lvb_type;
if (OBD_FAIL_CHECK(OBD_FAIL_LDLM_NEW_LOCK))
goto out;
return lock;
out:
ldlm_lock_destroy(lock);
LDLM_LOCK_RELEASE(lock);
return NULL;
}
ldlm_error_t ldlm_lock_enqueue(struct ldlm_namespace *ns,
struct ldlm_lock **lockp,
void *cookie, __u64 *flags)
{
struct ldlm_lock *lock = *lockp;
struct ldlm_resource *res = lock->l_resource;
int local = ns_is_client(ldlm_res_to_ns(res));
ldlm_error_t rc = ELDLM_OK;
struct ldlm_interval *node = NULL;
lock->l_last_activity = get_seconds();
if ((*flags & (LDLM_FL_HAS_INTENT|LDLM_FL_REPLAY)) == LDLM_FL_HAS_INTENT
&& !local && ns->ns_policy) {
rc = ns->ns_policy(ns, lockp, cookie, lock->l_req_mode, *flags,
NULL);
if (rc == ELDLM_LOCK_REPLACED) {
if (lock != *lockp) {
ldlm_lock_destroy(lock);
LDLM_LOCK_RELEASE(lock);
}
*flags |= LDLM_FL_LOCK_CHANGED;
return 0;
} else if (rc != ELDLM_OK ||
(rc == ELDLM_OK && (*flags & LDLM_FL_INTENT_ONLY))) {
ldlm_lock_destroy(lock);
return rc;
}
}
if (!local && (*flags & LDLM_FL_REPLAY) && res->lr_type == LDLM_EXTENT)
OBD_SLAB_ALLOC_PTR_GFP(node, ldlm_interval_slab, GFP_NOFS);
lock_res_and_lock(lock);
if (local && lock->l_req_mode == lock->l_granted_mode) {
*flags &= ~(LDLM_FL_BLOCK_GRANTED |
LDLM_FL_BLOCK_CONV | LDLM_FL_BLOCK_WAIT);
goto out;
}
ldlm_resource_unlink_lock(lock);
if (res->lr_type == LDLM_EXTENT && lock->l_tree_node == NULL) {
if (node == NULL) {
ldlm_lock_destroy_nolock(lock);
rc = -ENOMEM;
goto out;
}
INIT_LIST_HEAD(&node->li_group);
ldlm_interval_attach(node, lock);
node = NULL;
}
lock->l_flags |= *flags & LDLM_FL_AST_DISCARD_DATA;
if (local) {
if (*flags & LDLM_FL_BLOCK_CONV)
ldlm_resource_add_lock(res, &res->lr_converting, lock);
else if (*flags & (LDLM_FL_BLOCK_WAIT | LDLM_FL_BLOCK_GRANTED))
ldlm_resource_add_lock(res, &res->lr_waiting, lock);
else
ldlm_grant_lock(lock, NULL);
goto out;
} else {
CERROR("This is client-side-only module, cannot handle "
"LDLM_NAMESPACE_SERVER resource type lock.\n");
LBUG();
}
out:
unlock_res_and_lock(lock);
if (node)
OBD_SLAB_FREE(node, ldlm_interval_slab, sizeof(*node));
return rc;
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
LASSERT(lock->l_flags & LDLM_FL_AST_SENT);
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
LASSERT(lock->l_flags & LDLM_FL_CP_REQD);
completion_callback = lock->l_completion_ast;
lock->l_flags &= ~LDLM_FL_CP_REQD;
unlock_res_and_lock(lock);
if (completion_callback != NULL)
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
int ldlm_work_gl_ast_lock(struct ptlrpc_request_set *rqset, void *opaq)
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
OBD_FREE_PTR(gl_work);
return rc;
}
int ldlm_run_ast_work(struct ldlm_namespace *ns, struct list_head *rpc_list,
ldlm_desc_ast_t ast_type)
{
struct ldlm_cb_set_arg *arg;
set_producer_func work_ast_lock;
int rc;
if (list_empty(rpc_list))
return 0;
OBD_ALLOC_PTR(arg);
if (arg == NULL)
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
if (arg->set == NULL) {
rc = -ENOMEM;
goto out;
}
ptlrpc_set_wait(arg->set);
ptlrpc_set_destroy(arg->set);
rc = atomic_read(&arg->restart) ? -ERESTART : 0;
goto out;
out:
OBD_FREE_PTR(arg);
return rc;
}
static int reprocess_one_queue(struct ldlm_resource *res, void *closure)
{
ldlm_reprocess_all(res);
return LDLM_ITER_CONTINUE;
}
static int ldlm_reprocess_res(struct cfs_hash *hs, struct cfs_hash_bd *bd,
struct hlist_node *hnode, void *arg)
{
struct ldlm_resource *res = cfs_hash_object(hs, hnode);
int rc;
rc = reprocess_one_queue(res, arg);
return rc == LDLM_ITER_STOP;
}
void ldlm_reprocess_all_ns(struct ldlm_namespace *ns)
{
if (ns != NULL) {
cfs_hash_for_each_nolock(ns->ns_rs_hash,
ldlm_reprocess_res, NULL);
}
}
void ldlm_reprocess_all(struct ldlm_resource *res)
{
LIST_HEAD(rpc_list);
if (!ns_is_client(ldlm_res_to_ns(res))) {
CERROR("This is client-side-only module, cannot handle "
"LDLM_NAMESPACE_SERVER resource type lock.\n");
LBUG();
}
}
void ldlm_cancel_callback(struct ldlm_lock *lock)
{
check_res_locked(lock->l_resource);
if (!(lock->l_flags & LDLM_FL_CANCEL)) {
lock->l_flags |= LDLM_FL_CANCEL;
if (lock->l_blocking_ast) {
unlock_res_and_lock(lock);
lock->l_blocking_ast(lock, NULL, lock->l_ast_data,
LDLM_CB_CANCELING);
lock_res_and_lock(lock);
} else {
LDLM_DEBUG(lock, "no blocking ast");
}
}
lock->l_flags |= LDLM_FL_BL_DONE;
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
if (lock->l_flags & LDLM_FL_WAITED)
ldlm_del_waiting_lock(lock);
ldlm_cancel_callback(lock);
if (lock->l_flags & LDLM_FL_WAITED)
ldlm_del_waiting_lock(lock);
ldlm_resource_unlink_lock(lock);
ldlm_lock_destroy_nolock(lock);
if (lock->l_granted_mode == lock->l_req_mode)
ldlm_pool_del(&ns->ns_pool, lock);
lock->l_granted_mode = LCK_MINMODE;
unlock_res_and_lock(lock);
}
int ldlm_lock_set_data(struct lustre_handle *lockh, void *data)
{
struct ldlm_lock *lock = ldlm_handle2lock(lockh);
int rc = -EINVAL;
if (lock) {
if (lock->l_ast_data == NULL)
lock->l_ast_data = data;
if (lock->l_ast_data == data)
rc = 0;
LDLM_LOCK_PUT(lock);
}
return rc;
}
int ldlm_cancel_locks_for_export_cb(struct cfs_hash *hs, struct cfs_hash_bd *bd,
struct hlist_node *hnode, void *data)
{
struct export_cl_data *ecl = (struct export_cl_data *)data;
struct obd_export *exp = ecl->ecl_exp;
struct ldlm_lock *lock = cfs_hash_object(hs, hnode);
struct ldlm_resource *res;
res = ldlm_resource_getref(lock->l_resource);
LDLM_LOCK_GET(lock);
LDLM_DEBUG(lock, "export %p", exp);
ldlm_res_lvbo_update(res, NULL, 1);
ldlm_lock_cancel(lock);
ldlm_reprocess_all(res);
ldlm_resource_putref(res);
LDLM_LOCK_RELEASE(lock);
ecl->ecl_loop++;
if ((ecl->ecl_loop & -ecl->ecl_loop) == ecl->ecl_loop) {
CDEBUG(D_INFO,
"Cancel lock %p for export %p (loop %d), still have "
"%d locks left on hash table.\n",
lock, exp, ecl->ecl_loop,
atomic_read(&hs->hs_count));
}
return 0;
}
void ldlm_cancel_locks_for_export(struct obd_export *exp)
{
struct export_cl_data ecl = {
.ecl_exp = exp,
.ecl_loop = 0,
};
cfs_hash_for_each_empty(exp->exp_lock_hash,
ldlm_cancel_locks_for_export_cb, &ecl);
}
void ldlm_lock_downgrade(struct ldlm_lock *lock, int new_mode)
{
LASSERT(lock->l_granted_mode & (LCK_PW | LCK_EX));
LASSERT(new_mode == LCK_COS);
lock_res_and_lock(lock);
ldlm_resource_unlink_lock(lock);
ldlm_pool_del(&ldlm_lock_to_ns(lock)->ns_pool, lock);
lock->l_req_mode = new_mode;
ldlm_grant_lock(lock, NULL);
unlock_res_and_lock(lock);
ldlm_reprocess_all(lock->l_resource);
}
struct ldlm_resource *ldlm_lock_convert(struct ldlm_lock *lock, int new_mode,
__u32 *flags)
{
LIST_HEAD(rpc_list);
struct ldlm_resource *res;
struct ldlm_namespace *ns;
int granted = 0;
struct ldlm_interval *node;
if (new_mode == lock->l_granted_mode) {
*flags |= LDLM_FL_BLOCK_GRANTED;
return lock->l_resource;
}
OBD_SLAB_ALLOC_PTR_GFP(node, ldlm_interval_slab, GFP_NOFS);
if (node == NULL)
return NULL;
LASSERTF((new_mode == LCK_PW && lock->l_granted_mode == LCK_PR),
"new_mode %u, granted %u\n", new_mode, lock->l_granted_mode);
lock_res_and_lock(lock);
res = lock->l_resource;
ns = ldlm_res_to_ns(res);
lock->l_req_mode = new_mode;
if (res->lr_type == LDLM_PLAIN || res->lr_type == LDLM_IBITS) {
ldlm_resource_unlink_lock(lock);
} else {
ldlm_resource_unlink_lock(lock);
if (res->lr_type == LDLM_EXTENT) {
INIT_LIST_HEAD(&node->li_group);
ldlm_interval_attach(node, lock);
node = NULL;
}
}
ldlm_pool_del(&ns->ns_pool, lock);
if (ns_is_client(ldlm_res_to_ns(res))) {
if (*flags & (LDLM_FL_BLOCK_CONV | LDLM_FL_BLOCK_GRANTED)) {
ldlm_resource_add_lock(res, &res->lr_converting, lock);
} else {
LDLM_ERROR(lock, "Erroneous flags %x on local lock\n",
*flags);
LBUG();
ldlm_grant_lock(lock, &rpc_list);
granted = 1;
if (lock->l_completion_ast)
lock->l_completion_ast(lock, 0, NULL);
}
} else {
CERROR("This is client-side-only module, cannot handle "
"LDLM_NAMESPACE_SERVER resource type lock.\n");
LBUG();
}
unlock_res_and_lock(lock);
if (granted)
ldlm_run_ast_work(ns, &rpc_list, LDLM_WORK_CP_AST);
if (node)
OBD_SLAB_FREE(node, ldlm_interval_slab, sizeof(*node));
return res;
}
void ldlm_lock_dump_handle(int level, struct lustre_handle *lockh)
{
struct ldlm_lock *lock;
if (!((libcfs_debug | D_ERROR) & level))
return;
lock = ldlm_handle2lock(lockh);
if (lock == NULL)
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
} else if (exp && exp->exp_obd != NULL) {
struct obd_import *imp = exp->exp_obd->u.cli.cl_import;
nid = libcfs_nid2str(imp->imp_connection->c_peer.nid);
}
if (resource == NULL) {
libcfs_debug_vmsg2(msgdata, fmt, args,
" ns: \?\? lock: %p/%#llx lrc: %d/%d,%d mode: %s/%s "
"res: \?\? rrc=\?\? type: \?\?\? flags: %#llx nid: %s "
"remote: %#llx expref: %d pid: %u timeout: %lu "
"lvb_type: %d\n",
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
" ns: %s lock: %p/%#llx lrc: %d/%d,%d mode: %s/%s "
"res: "DLDLMRES" rrc: %d type: %s [%llu->%llu] "
"(req %llu->%llu) flags: %#llx nid: %s remote: "
"%#llx expref: %d pid: %u timeout: %lu lvb_type: %d\n",
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
" ns: %s lock: %p/%#llx lrc: %d/%d,%d mode: %s/%s "
"res: "DLDLMRES" rrc: %d type: %s pid: %d "
"[%llu->%llu] flags: %#llx nid: %s "
"remote: %#llx expref: %d pid: %u timeout: %lu\n",
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
" ns: %s lock: %p/%#llx lrc: %d/%d,%d mode: %s/%s "
"res: "DLDLMRES" bits %#llx rrc: %d type: %s "
"flags: %#llx nid: %s remote: %#llx expref: %d "
"pid: %u timeout: %lu lvb_type: %d\n",
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
" ns: %s lock: %p/%#llx lrc: %d/%d,%d mode: %s/%s "
"res: "DLDLMRES" rrc: %d type: %s flags: %#llx "
"nid: %s remote: %#llx expref: %d pid: %u "
"timeout: %lu lvb_type: %d\n",
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
