static int cl_lock_invariant_trusted(const struct lu_env *env,
const struct cl_lock *lock)
{
return ergo(lock->cll_state == CLS_FREEING, lock->cll_holds == 0) &&
atomic_read(&lock->cll_ref) >= lock->cll_holds &&
lock->cll_holds >= lock->cll_users &&
lock->cll_holds >= 0 &&
lock->cll_users >= 0 &&
lock->cll_depth >= 0;
}
static int cl_lock_invariant(const struct lu_env *env,
const struct cl_lock *lock)
{
int result;
result = atomic_read(&lock->cll_ref) > 0 &&
cl_lock_invariant_trusted(env, lock);
if (!result && env != NULL)
CL_LOCK_DEBUG(D_ERROR, env, lock, "invariant broken");
return result;
}
static enum clt_nesting_level cl_lock_nesting(const struct cl_lock *lock)
{
return cl_object_header(lock->cll_descr.cld_obj)->coh_nesting;
}
static struct cl_thread_counters *cl_lock_counters(const struct lu_env *env,
const struct cl_lock *lock)
{
struct cl_thread_info *info;
enum clt_nesting_level nesting;
info = cl_env_info(env);
nesting = cl_lock_nesting(lock);
LASSERT(nesting < ARRAY_SIZE(info->clt_counters));
return &info->clt_counters[nesting];
}
static void cl_lock_trace0(int level, const struct lu_env *env,
const char *prefix, const struct cl_lock *lock,
const char *func, const int line)
{
struct cl_object_header *h = cl_object_header(lock->cll_descr.cld_obj);
CDEBUG(level, "%s: %p@(%d %p %d %d %d %d %d %lx)"
"(%p/%d/%d) at %s():%d\n",
prefix, lock, atomic_read(&lock->cll_ref),
lock->cll_guarder, lock->cll_depth,
lock->cll_state, lock->cll_error, lock->cll_holds,
lock->cll_users, lock->cll_flags,
env, h->coh_nesting, cl_lock_nr_mutexed(env),
func, line);
}
static void cl_lock_lockdep_init(struct cl_lock *lock)
{
lockdep_set_class_and_name(lock, &cl_lock_key, "EXT");
}
static void cl_lock_lockdep_acquire(const struct lu_env *env,
struct cl_lock *lock, __u32 enqflags)
{
cl_lock_counters(env, lock)->ctc_nr_locks_acquired++;
lock_map_acquire(&lock->dep_map);
}
static void cl_lock_lockdep_release(const struct lu_env *env,
struct cl_lock *lock)
{
cl_lock_counters(env, lock)->ctc_nr_locks_acquired--;
lock_release(&lock->dep_map, 0, RETIP);
}
static void cl_lock_lockdep_init(struct cl_lock *lock)
{}
static void cl_lock_lockdep_acquire(const struct lu_env *env,
struct cl_lock *lock, __u32 enqflags)
{}
static void cl_lock_lockdep_release(const struct lu_env *env,
struct cl_lock *lock)
{}
void cl_lock_slice_add(struct cl_lock *lock, struct cl_lock_slice *slice,
struct cl_object *obj,
const struct cl_lock_operations *ops)
{
ENTRY;
slice->cls_lock = lock;
list_add_tail(&slice->cls_linkage, &lock->cll_layers);
slice->cls_obj = obj;
slice->cls_ops = ops;
EXIT;
}
int cl_lock_mode_match(enum cl_lock_mode has, enum cl_lock_mode need)
{
LINVRNT(need == CLM_READ || need == CLM_WRITE ||
need == CLM_PHANTOM || need == CLM_GROUP);
LINVRNT(has == CLM_READ || has == CLM_WRITE ||
has == CLM_PHANTOM || has == CLM_GROUP);
CLASSERT(CLM_PHANTOM < CLM_READ);
CLASSERT(CLM_READ < CLM_WRITE);
CLASSERT(CLM_WRITE < CLM_GROUP);
if (has != CLM_GROUP)
return need <= has;
else
return need == has;
}
int cl_lock_ext_match(const struct cl_lock_descr *has,
const struct cl_lock_descr *need)
{
return
has->cld_start <= need->cld_start &&
has->cld_end >= need->cld_end &&
cl_lock_mode_match(has->cld_mode, need->cld_mode) &&
(has->cld_mode != CLM_GROUP || has->cld_gid == need->cld_gid);
}
int cl_lock_descr_match(const struct cl_lock_descr *has,
const struct cl_lock_descr *need)
{
return
cl_object_same(has->cld_obj, need->cld_obj) &&
cl_lock_ext_match(has, need);
}
static void cl_lock_free(const struct lu_env *env, struct cl_lock *lock)
{
struct cl_object *obj = lock->cll_descr.cld_obj;
LINVRNT(!cl_lock_is_mutexed(lock));
ENTRY;
cl_lock_trace(D_DLMTRACE, env, "free lock", lock);
might_sleep();
while (!list_empty(&lock->cll_layers)) {
struct cl_lock_slice *slice;
slice = list_entry(lock->cll_layers.next,
struct cl_lock_slice, cls_linkage);
list_del_init(lock->cll_layers.next);
slice->cls_ops->clo_fini(env, slice);
}
CS_LOCK_DEC(obj, total);
CS_LOCKSTATE_DEC(obj, lock->cll_state);
lu_object_ref_del_at(&obj->co_lu, lock->cll_obj_ref, "cl_lock", lock);
cl_object_put(env, obj);
lu_ref_fini(&lock->cll_reference);
lu_ref_fini(&lock->cll_holders);
mutex_destroy(&lock->cll_guard);
OBD_SLAB_FREE_PTR(lock, cl_lock_kmem);
EXIT;
}
void cl_lock_put(const struct lu_env *env, struct cl_lock *lock)
{
struct cl_object *obj;
LINVRNT(cl_lock_invariant(env, lock));
ENTRY;
obj = lock->cll_descr.cld_obj;
LINVRNT(obj != NULL);
CDEBUG(D_TRACE, "releasing reference: %d %p %lu\n",
atomic_read(&lock->cll_ref), lock, RETIP);
if (atomic_dec_and_test(&lock->cll_ref)) {
if (lock->cll_state == CLS_FREEING) {
LASSERT(list_empty(&lock->cll_linkage));
cl_lock_free(env, lock);
}
CS_LOCK_DEC(obj, busy);
}
EXIT;
}
void cl_lock_get(struct cl_lock *lock)
{
LINVRNT(cl_lock_invariant(NULL, lock));
CDEBUG(D_TRACE, "acquiring reference: %d %p %lu\n",
atomic_read(&lock->cll_ref), lock, RETIP);
atomic_inc(&lock->cll_ref);
}
void cl_lock_get_trust(struct cl_lock *lock)
{
CDEBUG(D_TRACE, "acquiring trusted reference: %d %p %lu\n",
atomic_read(&lock->cll_ref), lock, RETIP);
if (atomic_inc_return(&lock->cll_ref) == 1)
CS_LOCK_INC(lock->cll_descr.cld_obj, busy);
}
static void cl_lock_finish(const struct lu_env *env, struct cl_lock *lock)
{
cl_lock_mutex_get(env, lock);
cl_lock_cancel(env, lock);
cl_lock_delete(env, lock);
cl_lock_mutex_put(env, lock);
cl_lock_put(env, lock);
}
static struct cl_lock *cl_lock_alloc(const struct lu_env *env,
struct cl_object *obj,
const struct cl_io *io,
const struct cl_lock_descr *descr)
{
struct cl_lock *lock;
struct lu_object_header *head;
ENTRY;
OBD_SLAB_ALLOC_PTR_GFP(lock, cl_lock_kmem, __GFP_IO);
if (lock != NULL) {
atomic_set(&lock->cll_ref, 1);
lock->cll_descr = *descr;
lock->cll_state = CLS_NEW;
cl_object_get(obj);
lock->cll_obj_ref = lu_object_ref_add(&obj->co_lu,
"cl_lock", lock);
INIT_LIST_HEAD(&lock->cll_layers);
INIT_LIST_HEAD(&lock->cll_linkage);
INIT_LIST_HEAD(&lock->cll_inclosure);
lu_ref_init(&lock->cll_reference);
lu_ref_init(&lock->cll_holders);
mutex_init(&lock->cll_guard);
lockdep_set_class(&lock->cll_guard, &cl_lock_guard_class);
init_waitqueue_head(&lock->cll_wq);
head = obj->co_lu.lo_header;
CS_LOCKSTATE_INC(obj, CLS_NEW);
CS_LOCK_INC(obj, total);
CS_LOCK_INC(obj, create);
cl_lock_lockdep_init(lock);
list_for_each_entry(obj, &head->loh_layers,
co_lu.lo_linkage) {
int err;
err = obj->co_ops->coo_lock_init(env, obj, lock, io);
if (err != 0) {
cl_lock_finish(env, lock);
lock = ERR_PTR(err);
break;
}
}
} else
lock = ERR_PTR(-ENOMEM);
RETURN(lock);
}
enum cl_lock_state cl_lock_intransit(const struct lu_env *env,
struct cl_lock *lock)
{
enum cl_lock_state state = lock->cll_state;
LASSERT(cl_lock_is_mutexed(lock));
LASSERT(state != CLS_INTRANSIT);
LASSERTF(state >= CLS_ENQUEUED && state <= CLS_CACHED,
"Malformed lock state %d.\n", state);
cl_lock_state_set(env, lock, CLS_INTRANSIT);
lock->cll_intransit_owner = current;
cl_lock_hold_add(env, lock, "intransit", current);
return state;
}
void cl_lock_extransit(const struct lu_env *env, struct cl_lock *lock,
enum cl_lock_state state)
{
LASSERT(cl_lock_is_mutexed(lock));
LASSERT(lock->cll_state == CLS_INTRANSIT);
LASSERT(state != CLS_INTRANSIT);
LASSERT(lock->cll_intransit_owner == current);
lock->cll_intransit_owner = NULL;
cl_lock_state_set(env, lock, state);
cl_lock_unhold(env, lock, "intransit", current);
}
int cl_lock_is_intransit(struct cl_lock *lock)
{
LASSERT(cl_lock_is_mutexed(lock));
return lock->cll_state == CLS_INTRANSIT &&
lock->cll_intransit_owner != current;
}
static int cl_lock_fits_into(const struct lu_env *env,
const struct cl_lock *lock,
const struct cl_lock_descr *need,
const struct cl_io *io)
{
const struct cl_lock_slice *slice;
LINVRNT(cl_lock_invariant_trusted(env, lock));
ENTRY;
list_for_each_entry(slice, &lock->cll_layers, cls_linkage) {
if (slice->cls_ops->clo_fits_into != NULL &&
!slice->cls_ops->clo_fits_into(env, slice, need, io))
RETURN(0);
}
RETURN(1);
}
static struct cl_lock *cl_lock_lookup(const struct lu_env *env,
struct cl_object *obj,
const struct cl_io *io,
const struct cl_lock_descr *need)
{
struct cl_lock *lock;
struct cl_object_header *head;
ENTRY;
head = cl_object_header(obj);
LINVRNT(spin_is_locked(&head->coh_lock_guard));
CS_LOCK_INC(obj, lookup);
list_for_each_entry(lock, &head->coh_locks, cll_linkage) {
int matched;
matched = cl_lock_ext_match(&lock->cll_descr, need) &&
lock->cll_state < CLS_FREEING &&
lock->cll_error == 0 &&
!(lock->cll_flags & CLF_CANCELLED) &&
cl_lock_fits_into(env, lock, need, io);
CDEBUG(D_DLMTRACE, "has: "DDESCR"(%d) need: "DDESCR": %d\n",
PDESCR(&lock->cll_descr), lock->cll_state, PDESCR(need),
matched);
if (matched) {
cl_lock_get_trust(lock);
CS_LOCK_INC(obj, hit);
RETURN(lock);
}
}
RETURN(NULL);
}
static struct cl_lock *cl_lock_find(const struct lu_env *env,
const struct cl_io *io,
const struct cl_lock_descr *need)
{
struct cl_object_header *head;
struct cl_object *obj;
struct cl_lock *lock;
ENTRY;
obj = need->cld_obj;
head = cl_object_header(obj);
spin_lock(&head->coh_lock_guard);
lock = cl_lock_lookup(env, obj, io, need);
spin_unlock(&head->coh_lock_guard);
if (lock == NULL) {
lock = cl_lock_alloc(env, obj, io, need);
if (!IS_ERR(lock)) {
struct cl_lock *ghost;
spin_lock(&head->coh_lock_guard);
ghost = cl_lock_lookup(env, obj, io, need);
if (ghost == NULL) {
list_add_tail(&lock->cll_linkage,
&head->coh_locks);
spin_unlock(&head->coh_lock_guard);
CS_LOCK_INC(obj, busy);
} else {
spin_unlock(&head->coh_lock_guard);
cl_lock_finish(env, lock);
lock = ghost;
}
}
}
RETURN(lock);
}
struct cl_lock *cl_lock_peek(const struct lu_env *env, const struct cl_io *io,
const struct cl_lock_descr *need,
const char *scope, const void *source)
{
struct cl_object_header *head;
struct cl_object *obj;
struct cl_lock *lock;
obj = need->cld_obj;
head = cl_object_header(obj);
do {
spin_lock(&head->coh_lock_guard);
lock = cl_lock_lookup(env, obj, io, need);
spin_unlock(&head->coh_lock_guard);
if (lock == NULL)
return NULL;
cl_lock_mutex_get(env, lock);
if (lock->cll_state == CLS_INTRANSIT)
cl_lock_state_wait(env, lock);
if (lock->cll_state == CLS_FREEING) {
cl_lock_mutex_put(env, lock);
cl_lock_put(env, lock);
lock = NULL;
}
} while (lock == NULL);
cl_lock_hold_add(env, lock, scope, source);
cl_lock_user_add(env, lock);
if (lock->cll_state == CLS_CACHED)
cl_use_try(env, lock, 1);
if (lock->cll_state == CLS_HELD) {
cl_lock_mutex_put(env, lock);
cl_lock_lockdep_acquire(env, lock, 0);
cl_lock_put(env, lock);
} else {
cl_unuse_try(env, lock);
cl_lock_unhold(env, lock, scope, source);
cl_lock_mutex_put(env, lock);
cl_lock_put(env, lock);
lock = NULL;
}
return lock;
}
const struct cl_lock_slice *cl_lock_at(const struct cl_lock *lock,
const struct lu_device_type *dtype)
{
const struct cl_lock_slice *slice;
LINVRNT(cl_lock_invariant_trusted(NULL, lock));
ENTRY;
list_for_each_entry(slice, &lock->cll_layers, cls_linkage) {
if (slice->cls_obj->co_lu.lo_dev->ld_type == dtype)
RETURN(slice);
}
RETURN(NULL);
}
static void cl_lock_mutex_tail(const struct lu_env *env, struct cl_lock *lock)
{
struct cl_thread_counters *counters;
counters = cl_lock_counters(env, lock);
lock->cll_depth++;
counters->ctc_nr_locks_locked++;
lu_ref_add(&counters->ctc_locks_locked, "cll_guard", lock);
cl_lock_trace(D_TRACE, env, "got mutex", lock);
}
void cl_lock_mutex_get(const struct lu_env *env, struct cl_lock *lock)
{
LINVRNT(cl_lock_invariant(env, lock));
if (lock->cll_guarder == current) {
LINVRNT(cl_lock_is_mutexed(lock));
LINVRNT(lock->cll_depth > 0);
} else {
struct cl_object_header *hdr;
struct cl_thread_info *info;
int i;
LINVRNT(lock->cll_guarder != current);
hdr = cl_object_header(lock->cll_descr.cld_obj);
info = cl_env_info(env);
for (i = 0; i < hdr->coh_nesting; ++i)
LASSERT(info->clt_counters[i].ctc_nr_locks_locked == 0);
mutex_lock_nested(&lock->cll_guard, hdr->coh_nesting);
lock->cll_guarder = current;
LINVRNT(lock->cll_depth == 0);
}
cl_lock_mutex_tail(env, lock);
}
int cl_lock_mutex_try(const struct lu_env *env, struct cl_lock *lock)
{
int result;
LINVRNT(cl_lock_invariant_trusted(env, lock));
ENTRY;
result = 0;
if (lock->cll_guarder == current) {
LINVRNT(lock->cll_depth > 0);
cl_lock_mutex_tail(env, lock);
} else if (mutex_trylock(&lock->cll_guard)) {
LINVRNT(lock->cll_depth == 0);
lock->cll_guarder = current;
cl_lock_mutex_tail(env, lock);
} else
result = -EBUSY;
RETURN(result);
}
void cl_lock_mutex_put(const struct lu_env *env, struct cl_lock *lock)
{
struct cl_thread_counters *counters;
LINVRNT(cl_lock_invariant(env, lock));
LINVRNT(cl_lock_is_mutexed(lock));
LINVRNT(lock->cll_guarder == current);
LINVRNT(lock->cll_depth > 0);
counters = cl_lock_counters(env, lock);
LINVRNT(counters->ctc_nr_locks_locked > 0);
cl_lock_trace(D_TRACE, env, "put mutex", lock);
lu_ref_del(&counters->ctc_locks_locked, "cll_guard", lock);
counters->ctc_nr_locks_locked--;
if (--lock->cll_depth == 0) {
lock->cll_guarder = NULL;
mutex_unlock(&lock->cll_guard);
}
}
int cl_lock_is_mutexed(struct cl_lock *lock)
{
return lock->cll_guarder == current;
}
int cl_lock_nr_mutexed(const struct lu_env *env)
{
struct cl_thread_info *info;
int i;
int locked;
info = cl_env_info(env);
for (i = 0, locked = 0; i < ARRAY_SIZE(info->clt_counters); ++i)
locked += info->clt_counters[i].ctc_nr_locks_locked;
return locked;
}
static void cl_lock_cancel0(const struct lu_env *env, struct cl_lock *lock)
{
LINVRNT(cl_lock_is_mutexed(lock));
LINVRNT(cl_lock_invariant(env, lock));
ENTRY;
if (!(lock->cll_flags & CLF_CANCELLED)) {
const struct cl_lock_slice *slice;
lock->cll_flags |= CLF_CANCELLED;
list_for_each_entry_reverse(slice, &lock->cll_layers,
cls_linkage) {
if (slice->cls_ops->clo_cancel != NULL)
slice->cls_ops->clo_cancel(env, slice);
}
}
EXIT;
}
static void cl_lock_delete0(const struct lu_env *env, struct cl_lock *lock)
{
struct cl_object_header *head;
const struct cl_lock_slice *slice;
LINVRNT(cl_lock_is_mutexed(lock));
LINVRNT(cl_lock_invariant(env, lock));
ENTRY;
if (lock->cll_state < CLS_FREEING) {
LASSERT(lock->cll_state != CLS_INTRANSIT);
cl_lock_state_set(env, lock, CLS_FREEING);
head = cl_object_header(lock->cll_descr.cld_obj);
spin_lock(&head->coh_lock_guard);
list_del_init(&lock->cll_linkage);
spin_unlock(&head->coh_lock_guard);
list_for_each_entry_reverse(slice, &lock->cll_layers,
cls_linkage) {
if (slice->cls_ops->clo_delete != NULL)
slice->cls_ops->clo_delete(env, slice);
}
}
EXIT;
}
static void cl_lock_hold_mod(const struct lu_env *env, struct cl_lock *lock,
int delta)
{
struct cl_thread_counters *counters;
enum clt_nesting_level nesting;
lock->cll_holds += delta;
nesting = cl_lock_nesting(lock);
if (nesting == CNL_TOP) {
counters = &cl_env_info(env)->clt_counters[CNL_TOP];
counters->ctc_nr_held += delta;
LASSERT(counters->ctc_nr_held >= 0);
}
}
static void cl_lock_used_mod(const struct lu_env *env, struct cl_lock *lock,
int delta)
{
struct cl_thread_counters *counters;
enum clt_nesting_level nesting;
lock->cll_users += delta;
nesting = cl_lock_nesting(lock);
if (nesting == CNL_TOP) {
counters = &cl_env_info(env)->clt_counters[CNL_TOP];
counters->ctc_nr_used += delta;
LASSERT(counters->ctc_nr_used >= 0);
}
}
void cl_lock_hold_release(const struct lu_env *env, struct cl_lock *lock,
const char *scope, const void *source)
{
LINVRNT(cl_lock_is_mutexed(lock));
LINVRNT(cl_lock_invariant(env, lock));
LASSERT(lock->cll_holds > 0);
ENTRY;
cl_lock_trace(D_DLMTRACE, env, "hold release lock", lock);
lu_ref_del(&lock->cll_holders, scope, source);
cl_lock_hold_mod(env, lock, -1);
if (lock->cll_holds == 0) {
CL_LOCK_ASSERT(lock->cll_state != CLS_HELD, env, lock);
if (lock->cll_descr.cld_mode == CLM_PHANTOM ||
lock->cll_descr.cld_mode == CLM_GROUP ||
lock->cll_state != CLS_CACHED)
lock->cll_flags |= CLF_CANCELPEND|CLF_DOOMED;
if (lock->cll_flags & CLF_CANCELPEND) {
lock->cll_flags &= ~CLF_CANCELPEND;
cl_lock_cancel0(env, lock);
}
if (lock->cll_flags & CLF_DOOMED) {
lock->cll_flags &= ~CLF_DOOMED;
cl_lock_delete0(env, lock);
}
}
EXIT;
}
int cl_lock_state_wait(const struct lu_env *env, struct cl_lock *lock)
{
wait_queue_t waiter;
sigset_t blocked;
int result;
ENTRY;
LINVRNT(cl_lock_is_mutexed(lock));
LINVRNT(cl_lock_invariant(env, lock));
LASSERT(lock->cll_depth == 1);
LASSERT(lock->cll_state != CLS_FREEING);
cl_lock_trace(D_DLMTRACE, env, "state wait lock", lock);
result = lock->cll_error;
if (result == 0) {
blocked = cfs_block_sigsinv(LUSTRE_FATAL_SIGS);
init_waitqueue_entry_current(&waiter);
add_wait_queue(&lock->cll_wq, &waiter);
set_current_state(TASK_INTERRUPTIBLE);
cl_lock_mutex_put(env, lock);
LASSERT(cl_lock_nr_mutexed(env) == 0);
result = -ERESTARTSYS;
if (likely(!OBD_FAIL_CHECK(OBD_FAIL_LOCK_STATE_WAIT_INTR))) {
waitq_wait(&waiter, TASK_INTERRUPTIBLE);
if (!cfs_signal_pending())
result = 0;
}
cl_lock_mutex_get(env, lock);
set_current_state(TASK_RUNNING);
remove_wait_queue(&lock->cll_wq, &waiter);
cfs_restore_sigs(blocked);
}
RETURN(result);
}
static void cl_lock_state_signal(const struct lu_env *env, struct cl_lock *lock,
enum cl_lock_state state)
{
const struct cl_lock_slice *slice;
ENTRY;
LINVRNT(cl_lock_is_mutexed(lock));
LINVRNT(cl_lock_invariant(env, lock));
list_for_each_entry(slice, &lock->cll_layers, cls_linkage)
if (slice->cls_ops->clo_state != NULL)
slice->cls_ops->clo_state(env, slice, state);
wake_up_all(&lock->cll_wq);
EXIT;
}
void cl_lock_signal(const struct lu_env *env, struct cl_lock *lock)
{
ENTRY;
cl_lock_trace(D_DLMTRACE, env, "state signal lock", lock);
cl_lock_state_signal(env, lock, lock->cll_state);
EXIT;
}
void cl_lock_state_set(const struct lu_env *env, struct cl_lock *lock,
enum cl_lock_state state)
{
ENTRY;
LASSERT(lock->cll_state <= state ||
(lock->cll_state == CLS_CACHED &&
(state == CLS_HELD ||
state == CLS_NEW ||
state == CLS_INTRANSIT)) ||
lock->cll_state == CLS_INTRANSIT);
if (lock->cll_state != state) {
CS_LOCKSTATE_DEC(lock->cll_descr.cld_obj, lock->cll_state);
CS_LOCKSTATE_INC(lock->cll_descr.cld_obj, state);
cl_lock_state_signal(env, lock, state);
lock->cll_state = state;
}
EXIT;
}
static int cl_unuse_try_internal(const struct lu_env *env, struct cl_lock *lock)
{
const struct cl_lock_slice *slice;
int result;
do {
result = 0;
LINVRNT(cl_lock_is_mutexed(lock));
LINVRNT(cl_lock_invariant(env, lock));
LASSERT(lock->cll_state == CLS_INTRANSIT);
result = -ENOSYS;
list_for_each_entry_reverse(slice, &lock->cll_layers,
cls_linkage) {
if (slice->cls_ops->clo_unuse != NULL) {
result = slice->cls_ops->clo_unuse(env, slice);
if (result != 0)
break;
}
}
LASSERT(result != -ENOSYS);
} while (result == CLO_REPEAT);
return result;
}
int cl_use_try(const struct lu_env *env, struct cl_lock *lock, int atomic)
{
const struct cl_lock_slice *slice;
int result;
enum cl_lock_state state;
ENTRY;
cl_lock_trace(D_DLMTRACE, env, "use lock", lock);
LASSERT(lock->cll_state == CLS_CACHED);
if (lock->cll_error)
RETURN(lock->cll_error);
result = -ENOSYS;
state = cl_lock_intransit(env, lock);
list_for_each_entry(slice, &lock->cll_layers, cls_linkage) {
if (slice->cls_ops->clo_use != NULL) {
result = slice->cls_ops->clo_use(env, slice);
if (result != 0)
break;
}
}
LASSERT(result != -ENOSYS);
LASSERTF(lock->cll_state == CLS_INTRANSIT, "Wrong state %d.\n",
lock->cll_state);
if (result == 0) {
state = CLS_HELD;
} else {
if (result == -ESTALE) {
state = CLS_NEW;
result = CLO_REPEAT;
}
if (atomic) {
int rc;
rc = cl_unuse_try_internal(env, lock);
if (rc < 0 && result > 0)
result = rc;
}
}
cl_lock_extransit(env, lock, state);
RETURN(result);
}
static int cl_enqueue_kick(const struct lu_env *env,
struct cl_lock *lock,
struct cl_io *io, __u32 flags)
{
int result;
const struct cl_lock_slice *slice;
ENTRY;
result = -ENOSYS;
list_for_each_entry(slice, &lock->cll_layers, cls_linkage) {
if (slice->cls_ops->clo_enqueue != NULL) {
result = slice->cls_ops->clo_enqueue(env,
slice, io, flags);
if (result != 0)
break;
}
}
LASSERT(result != -ENOSYS);
RETURN(result);
}
int cl_enqueue_try(const struct lu_env *env, struct cl_lock *lock,
struct cl_io *io, __u32 flags)
{
int result;
ENTRY;
cl_lock_trace(D_DLMTRACE, env, "enqueue lock", lock);
do {
LINVRNT(cl_lock_is_mutexed(lock));
result = lock->cll_error;
if (result != 0)
break;
switch (lock->cll_state) {
case CLS_NEW:
cl_lock_state_set(env, lock, CLS_QUEUING);
case CLS_QUEUING:
result = cl_enqueue_kick(env, lock, io, flags);
if (result == 0 && lock->cll_state == CLS_QUEUING)
cl_lock_state_set(env, lock, CLS_ENQUEUED);
break;
case CLS_INTRANSIT:
LASSERT(cl_lock_is_intransit(lock));
result = CLO_WAIT;
break;
case CLS_CACHED:
result = cl_use_try(env, lock, 0);
break;
case CLS_ENQUEUED:
case CLS_HELD:
result = 0;
break;
default:
case CLS_FREEING:
LBUG();
}
} while (result == CLO_REPEAT);
RETURN(result);
}
int cl_lock_enqueue_wait(const struct lu_env *env,
struct cl_lock *lock,
int keep_mutex)
{
struct cl_lock *conflict;
int rc = 0;
ENTRY;
LASSERT(cl_lock_is_mutexed(lock));
LASSERT(lock->cll_state == CLS_QUEUING);
LASSERT(lock->cll_conflict != NULL);
conflict = lock->cll_conflict;
lock->cll_conflict = NULL;
cl_lock_mutex_put(env, lock);
LASSERT(cl_lock_nr_mutexed(env) == 0);
cl_lock_mutex_get(env, conflict);
cl_lock_trace(D_DLMTRACE, env, "enqueue wait", conflict);
cl_lock_cancel(env, conflict);
cl_lock_delete(env, conflict);
while (conflict->cll_state != CLS_FREEING) {
rc = cl_lock_state_wait(env, conflict);
if (rc != 0)
break;
}
cl_lock_mutex_put(env, conflict);
lu_ref_del(&conflict->cll_reference, "cancel-wait", lock);
cl_lock_put(env, conflict);
if (keep_mutex)
cl_lock_mutex_get(env, lock);
LASSERT(rc <= 0);
RETURN(rc);
}
static int cl_enqueue_locked(const struct lu_env *env, struct cl_lock *lock,
struct cl_io *io, __u32 enqflags)
{
int result;
ENTRY;
LINVRNT(cl_lock_is_mutexed(lock));
LINVRNT(cl_lock_invariant(env, lock));
LASSERT(lock->cll_holds > 0);
cl_lock_user_add(env, lock);
do {
result = cl_enqueue_try(env, lock, io, enqflags);
if (result == CLO_WAIT) {
if (lock->cll_conflict != NULL)
result = cl_lock_enqueue_wait(env, lock, 1);
else
result = cl_lock_state_wait(env, lock);
if (result == 0)
continue;
}
break;
} while (1);
if (result != 0)
cl_unuse_try(env, lock);
LASSERT(ergo(result == 0 && !(enqflags & CEF_AGL),
lock->cll_state == CLS_ENQUEUED ||
lock->cll_state == CLS_HELD));
RETURN(result);
}
int cl_enqueue(const struct lu_env *env, struct cl_lock *lock,
struct cl_io *io, __u32 enqflags)
{
int result;
ENTRY;
cl_lock_lockdep_acquire(env, lock, enqflags);
cl_lock_mutex_get(env, lock);
result = cl_enqueue_locked(env, lock, io, enqflags);
cl_lock_mutex_put(env, lock);
if (result != 0)
cl_lock_lockdep_release(env, lock);
LASSERT(ergo(result == 0, lock->cll_state == CLS_ENQUEUED ||
lock->cll_state == CLS_HELD));
RETURN(result);
}
int cl_unuse_try(const struct lu_env *env, struct cl_lock *lock)
{
int result;
enum cl_lock_state state = CLS_NEW;
ENTRY;
cl_lock_trace(D_DLMTRACE, env, "unuse lock", lock);
if (lock->cll_users > 1) {
cl_lock_user_del(env, lock);
RETURN(0);
}
if (!(lock->cll_state == CLS_HELD || lock->cll_state == CLS_ENQUEUED)) {
cl_lock_user_del(env, lock);
RETURN(0);
}
state = cl_lock_intransit(env, lock);
result = cl_unuse_try_internal(env, lock);
LASSERT(lock->cll_state == CLS_INTRANSIT);
LASSERT(result != CLO_WAIT);
cl_lock_user_del(env, lock);
if (result == 0 || result == -ESTALE) {
if (state == CLS_HELD && result == 0)
state = CLS_CACHED;
else
state = CLS_NEW;
cl_lock_extransit(env, lock, state);
result = 0;
} else {
CERROR("result = %d, this is unlikely!\n", result);
state = CLS_NEW;
cl_lock_extransit(env, lock, state);
}
RETURN(result ?: lock->cll_error);
}
static void cl_unuse_locked(const struct lu_env *env, struct cl_lock *lock)
{
int result;
ENTRY;
result = cl_unuse_try(env, lock);
if (result)
CL_LOCK_DEBUG(D_ERROR, env, lock, "unuse return %d\n", result);
EXIT;
}
void cl_unuse(const struct lu_env *env, struct cl_lock *lock)
{
ENTRY;
cl_lock_mutex_get(env, lock);
cl_unuse_locked(env, lock);
cl_lock_mutex_put(env, lock);
cl_lock_lockdep_release(env, lock);
EXIT;
}
int cl_wait_try(const struct lu_env *env, struct cl_lock *lock)
{
const struct cl_lock_slice *slice;
int result;
ENTRY;
cl_lock_trace(D_DLMTRACE, env, "wait lock try", lock);
do {
LINVRNT(cl_lock_is_mutexed(lock));
LINVRNT(cl_lock_invariant(env, lock));
LASSERTF(lock->cll_state == CLS_QUEUING ||
lock->cll_state == CLS_ENQUEUED ||
lock->cll_state == CLS_HELD ||
lock->cll_state == CLS_INTRANSIT,
"lock state: %d\n", lock->cll_state);
LASSERT(lock->cll_users > 0);
LASSERT(lock->cll_holds > 0);
result = lock->cll_error;
if (result != 0)
break;
if (cl_lock_is_intransit(lock)) {
result = CLO_WAIT;
break;
}
if (lock->cll_state == CLS_HELD)
break;
result = -ENOSYS;
list_for_each_entry(slice, &lock->cll_layers, cls_linkage) {
if (slice->cls_ops->clo_wait != NULL) {
result = slice->cls_ops->clo_wait(env, slice);
if (result != 0)
break;
}
}
LASSERT(result != -ENOSYS);
if (result == 0) {
LASSERT(lock->cll_state != CLS_INTRANSIT);
cl_lock_state_set(env, lock, CLS_HELD);
}
} while (result == CLO_REPEAT);
RETURN(result);
}
int cl_wait(const struct lu_env *env, struct cl_lock *lock)
{
int result;
ENTRY;
cl_lock_mutex_get(env, lock);
LINVRNT(cl_lock_invariant(env, lock));
LASSERTF(lock->cll_state == CLS_ENQUEUED || lock->cll_state == CLS_HELD,
"Wrong state %d \n", lock->cll_state);
LASSERT(lock->cll_holds > 0);
do {
result = cl_wait_try(env, lock);
if (result == CLO_WAIT) {
result = cl_lock_state_wait(env, lock);
if (result == 0)
continue;
}
break;
} while (1);
if (result < 0) {
cl_unuse_try(env, lock);
cl_lock_lockdep_release(env, lock);
}
cl_lock_trace(D_DLMTRACE, env, "wait lock", lock);
cl_lock_mutex_put(env, lock);
LASSERT(ergo(result == 0, lock->cll_state == CLS_HELD));
RETURN(result);
}
unsigned long cl_lock_weigh(const struct lu_env *env, struct cl_lock *lock)
{
const struct cl_lock_slice *slice;
unsigned long pound;
unsigned long ounce;
ENTRY;
LINVRNT(cl_lock_is_mutexed(lock));
LINVRNT(cl_lock_invariant(env, lock));
pound = 0;
list_for_each_entry_reverse(slice, &lock->cll_layers, cls_linkage) {
if (slice->cls_ops->clo_weigh != NULL) {
ounce = slice->cls_ops->clo_weigh(env, slice);
pound += ounce;
if (pound < ounce)
pound = ~0UL;
}
}
RETURN(pound);
}
int cl_lock_modify(const struct lu_env *env, struct cl_lock *lock,
const struct cl_lock_descr *desc)
{
const struct cl_lock_slice *slice;
struct cl_object *obj = lock->cll_descr.cld_obj;
struct cl_object_header *hdr = cl_object_header(obj);
int result;
ENTRY;
cl_lock_trace(D_DLMTRACE, env, "modify lock", lock);
LASSERT(obj == desc->cld_obj);
LINVRNT(cl_lock_is_mutexed(lock));
LINVRNT(cl_lock_invariant(env, lock));
list_for_each_entry_reverse(slice, &lock->cll_layers, cls_linkage) {
if (slice->cls_ops->clo_modify != NULL) {
result = slice->cls_ops->clo_modify(env, slice, desc);
if (result != 0)
RETURN(result);
}
}
CL_LOCK_DEBUG(D_DLMTRACE, env, lock, " -> "DDESCR"@"DFID"\n",
PDESCR(desc), PFID(lu_object_fid(&desc->cld_obj->co_lu)));
spin_lock(&hdr->coh_lock_guard);
lock->cll_descr = *desc;
spin_unlock(&hdr->coh_lock_guard);
RETURN(0);
}
void cl_lock_closure_init(const struct lu_env *env,
struct cl_lock_closure *closure,
struct cl_lock *origin, int wait)
{
LINVRNT(cl_lock_is_mutexed(origin));
LINVRNT(cl_lock_invariant(env, origin));
INIT_LIST_HEAD(&closure->clc_list);
closure->clc_origin = origin;
closure->clc_wait = wait;
closure->clc_nr = 0;
}
int cl_lock_closure_build(const struct lu_env *env, struct cl_lock *lock,
struct cl_lock_closure *closure)
{
const struct cl_lock_slice *slice;
int result;
ENTRY;
LINVRNT(cl_lock_is_mutexed(closure->clc_origin));
LINVRNT(cl_lock_invariant(env, closure->clc_origin));
result = cl_lock_enclosure(env, lock, closure);
if (result == 0) {
list_for_each_entry(slice, &lock->cll_layers, cls_linkage) {
if (slice->cls_ops->clo_closure != NULL) {
result = slice->cls_ops->clo_closure(env, slice,
closure);
if (result != 0)
break;
}
}
}
if (result != 0)
cl_lock_disclosure(env, closure);
RETURN(result);
}
int cl_lock_enclosure(const struct lu_env *env, struct cl_lock *lock,
struct cl_lock_closure *closure)
{
int result = 0;
ENTRY;
cl_lock_trace(D_DLMTRACE, env, "enclosure lock", lock);
if (!cl_lock_mutex_try(env, lock)) {
if (list_empty(&lock->cll_inclosure)) {
cl_lock_get_trust(lock);
lu_ref_add(&lock->cll_reference, "closure", closure);
list_add(&lock->cll_inclosure, &closure->clc_list);
closure->clc_nr++;
} else
cl_lock_mutex_put(env, lock);
result = 0;
} else {
cl_lock_disclosure(env, closure);
if (closure->clc_wait) {
cl_lock_get_trust(lock);
lu_ref_add(&lock->cll_reference, "closure-w", closure);
cl_lock_mutex_put(env, closure->clc_origin);
LASSERT(cl_lock_nr_mutexed(env) == 0);
cl_lock_mutex_get(env, lock);
cl_lock_mutex_put(env, lock);
cl_lock_mutex_get(env, closure->clc_origin);
lu_ref_del(&lock->cll_reference, "closure-w", closure);
cl_lock_put(env, lock);
}
result = CLO_REPEAT;
}
RETURN(result);
}
void cl_lock_disclosure(const struct lu_env *env,
struct cl_lock_closure *closure)
{
struct cl_lock *scan;
struct cl_lock *temp;
cl_lock_trace(D_DLMTRACE, env, "disclosure lock", closure->clc_origin);
list_for_each_entry_safe(scan, temp, &closure->clc_list,
cll_inclosure){
list_del_init(&scan->cll_inclosure);
cl_lock_mutex_put(env, scan);
lu_ref_del(&scan->cll_reference, "closure", closure);
cl_lock_put(env, scan);
closure->clc_nr--;
}
LASSERT(closure->clc_nr == 0);
}
void cl_lock_closure_fini(struct cl_lock_closure *closure)
{
LASSERT(closure->clc_nr == 0);
LASSERT(list_empty(&closure->clc_list));
}
void cl_lock_delete(const struct lu_env *env, struct cl_lock *lock)
{
LINVRNT(cl_lock_is_mutexed(lock));
LINVRNT(cl_lock_invariant(env, lock));
LASSERT(ergo(cl_lock_nesting(lock) == CNL_TOP,
cl_lock_nr_mutexed(env) == 1));
ENTRY;
cl_lock_trace(D_DLMTRACE, env, "delete lock", lock);
if (lock->cll_holds == 0)
cl_lock_delete0(env, lock);
else
lock->cll_flags |= CLF_DOOMED;
EXIT;
}
void cl_lock_error(const struct lu_env *env, struct cl_lock *lock, int error)
{
LINVRNT(cl_lock_is_mutexed(lock));
LINVRNT(cl_lock_invariant(env, lock));
ENTRY;
if (lock->cll_error == 0 && error != 0) {
cl_lock_trace(D_DLMTRACE, env, "set lock error", lock);
lock->cll_error = error;
cl_lock_signal(env, lock);
cl_lock_cancel(env, lock);
cl_lock_delete(env, lock);
}
EXIT;
}
void cl_lock_cancel(const struct lu_env *env, struct cl_lock *lock)
{
LINVRNT(cl_lock_is_mutexed(lock));
LINVRNT(cl_lock_invariant(env, lock));
ENTRY;
cl_lock_trace(D_DLMTRACE, env, "cancel lock", lock);
if (lock->cll_holds == 0)
cl_lock_cancel0(env, lock);
else
lock->cll_flags |= CLF_CANCELPEND;
EXIT;
}
struct cl_lock *cl_lock_at_pgoff(const struct lu_env *env,
struct cl_object *obj, pgoff_t index,
struct cl_lock *except,
int pending, int canceld)
{
struct cl_object_header *head;
struct cl_lock *scan;
struct cl_lock *lock;
struct cl_lock_descr *need;
ENTRY;
head = cl_object_header(obj);
need = &cl_env_info(env)->clt_descr;
lock = NULL;
need->cld_mode = CLM_READ;
need->cld_start = need->cld_end = index;
need->cld_enq_flags = 0;
spin_lock(&head->coh_lock_guard);
list_for_each_entry(scan, &head->coh_locks, cll_linkage) {
if (scan != except &&
(scan->cll_descr.cld_mode == CLM_GROUP ||
cl_lock_ext_match(&scan->cll_descr, need)) &&
scan->cll_state >= CLS_HELD &&
scan->cll_state < CLS_FREEING &&
(canceld || !(scan->cll_flags & CLF_CANCELLED)) &&
(pending || !(scan->cll_flags & CLF_CANCELPEND))) {
cl_lock_get_trust(scan);
lock = scan;
break;
}
}
spin_unlock(&head->coh_lock_guard);
RETURN(lock);
}
static pgoff_t pgoff_at_lock(struct cl_page *page, struct cl_lock *lock)
{
struct lu_device_type *dtype;
const struct cl_page_slice *slice;
dtype = lock->cll_descr.cld_obj->co_lu.lo_dev->ld_type;
slice = cl_page_at(page, dtype);
LASSERT(slice != NULL);
return slice->cpl_page->cp_index;
}
static int check_and_discard_cb(const struct lu_env *env, struct cl_io *io,
struct cl_page *page, void *cbdata)
{
struct cl_thread_info *info = cl_env_info(env);
struct cl_lock *lock = cbdata;
pgoff_t index = pgoff_at_lock(page, lock);
if (index >= info->clt_fn_index) {
struct cl_lock *tmp;
tmp = cl_lock_at_pgoff(env, lock->cll_descr.cld_obj, index,
lock, 1, 0);
if (tmp != NULL) {
info->clt_fn_index = tmp->cll_descr.cld_end + 1;
if (tmp->cll_descr.cld_end == CL_PAGE_EOF)
info->clt_fn_index = CL_PAGE_EOF;
cl_lock_put(env, tmp);
} else if (cl_page_own(env, io, page) == 0) {
cl_page_unmap(env, io, page);
cl_page_discard(env, io, page);
cl_page_disown(env, io, page);
} else {
LASSERT(page->cp_state == CPS_FREEING);
}
}
info->clt_next_index = index + 1;
return CLP_GANG_OKAY;
}
static int discard_cb(const struct lu_env *env, struct cl_io *io,
struct cl_page *page, void *cbdata)
{
struct cl_thread_info *info = cl_env_info(env);
struct cl_lock *lock = cbdata;
LASSERT(lock->cll_descr.cld_mode >= CLM_WRITE);
KLASSERT(ergo(page->cp_type == CPT_CACHEABLE,
!PageWriteback(cl_page_vmpage(env, page))));
KLASSERT(ergo(page->cp_type == CPT_CACHEABLE,
!PageDirty(cl_page_vmpage(env, page))));
info->clt_next_index = pgoff_at_lock(page, lock) + 1;
if (cl_page_own(env, io, page) == 0) {
cl_page_unmap(env, io, page);
cl_page_discard(env, io, page);
cl_page_disown(env, io, page);
} else {
LASSERT(page->cp_state == CPS_FREEING);
}
return CLP_GANG_OKAY;
}
int cl_lock_discard_pages(const struct lu_env *env, struct cl_lock *lock)
{
struct cl_thread_info *info = cl_env_info(env);
struct cl_io *io = &info->clt_io;
struct cl_lock_descr *descr = &lock->cll_descr;
cl_page_gang_cb_t cb;
int res;
int result;
LINVRNT(cl_lock_invariant(env, lock));
ENTRY;
io->ci_obj = cl_object_top(descr->cld_obj);
io->ci_ignore_layout = 1;
result = cl_io_init(env, io, CIT_MISC, io->ci_obj);
if (result != 0)
GOTO(out, result);
cb = descr->cld_mode == CLM_READ ? check_and_discard_cb : discard_cb;
info->clt_fn_index = info->clt_next_index = descr->cld_start;
do {
res = cl_page_gang_lookup(env, descr->cld_obj, io,
info->clt_next_index, descr->cld_end,
cb, (void *)lock);
if (info->clt_next_index > descr->cld_end)
break;
if (res == CLP_GANG_RESCHED)
cond_resched();
} while (res != CLP_GANG_OKAY);
out:
cl_io_fini(env, io);
RETURN(result);
}
void cl_locks_prune(const struct lu_env *env, struct cl_object *obj, int cancel)
{
struct cl_object_header *head;
struct cl_lock *lock;
ENTRY;
head = cl_object_header(obj);
LASSERT(ergo(!cancel,
head->coh_tree.rnode == NULL && head->coh_pages == 0));
spin_lock(&head->coh_lock_guard);
while (!list_empty(&head->coh_locks)) {
lock = container_of(head->coh_locks.next,
struct cl_lock, cll_linkage);
cl_lock_get_trust(lock);
spin_unlock(&head->coh_lock_guard);
lu_ref_add(&lock->cll_reference, "prune", current);
again:
cl_lock_mutex_get(env, lock);
if (lock->cll_state < CLS_FREEING) {
LASSERT(lock->cll_users <= 1);
if (unlikely(lock->cll_users == 1)) {
struct l_wait_info lwi = { 0 };
cl_lock_mutex_put(env, lock);
l_wait_event(lock->cll_wq,
lock->cll_users == 0,
&lwi);
goto again;
}
if (cancel)
cl_lock_cancel(env, lock);
cl_lock_delete(env, lock);
}
cl_lock_mutex_put(env, lock);
lu_ref_del(&lock->cll_reference, "prune", current);
cl_lock_put(env, lock);
spin_lock(&head->coh_lock_guard);
}
spin_unlock(&head->coh_lock_guard);
EXIT;
}
static struct cl_lock *cl_lock_hold_mutex(const struct lu_env *env,
const struct cl_io *io,
const struct cl_lock_descr *need,
const char *scope, const void *source)
{
struct cl_lock *lock;
ENTRY;
while (1) {
lock = cl_lock_find(env, io, need);
if (IS_ERR(lock))
break;
cl_lock_mutex_get(env, lock);
if (lock->cll_state < CLS_FREEING &&
!(lock->cll_flags & CLF_CANCELLED)) {
cl_lock_hold_mod(env, lock, +1);
lu_ref_add(&lock->cll_holders, scope, source);
lu_ref_add(&lock->cll_reference, scope, source);
break;
}
cl_lock_mutex_put(env, lock);
cl_lock_put(env, lock);
}
RETURN(lock);
}
struct cl_lock *cl_lock_hold(const struct lu_env *env, const struct cl_io *io,
const struct cl_lock_descr *need,
const char *scope, const void *source)
{
struct cl_lock *lock;
ENTRY;
lock = cl_lock_hold_mutex(env, io, need, scope, source);
if (!IS_ERR(lock))
cl_lock_mutex_put(env, lock);
RETURN(lock);
}
struct cl_lock *cl_lock_request(const struct lu_env *env, struct cl_io *io,
const struct cl_lock_descr *need,
const char *scope, const void *source)
{
struct cl_lock *lock;
int rc;
__u32 enqflags = need->cld_enq_flags;
ENTRY;
do {
lock = cl_lock_hold_mutex(env, io, need, scope, source);
if (IS_ERR(lock))
break;
rc = cl_enqueue_locked(env, lock, io, enqflags);
if (rc == 0) {
if (cl_lock_fits_into(env, lock, need, io)) {
if (!(enqflags & CEF_AGL)) {
cl_lock_mutex_put(env, lock);
cl_lock_lockdep_acquire(env, lock,
enqflags);
break;
}
rc = 1;
}
cl_unuse_locked(env, lock);
}
cl_lock_trace(D_DLMTRACE, env,
rc <= 0 ? "enqueue failed" : "agl succeed", lock);
cl_lock_hold_release(env, lock, scope, source);
cl_lock_mutex_put(env, lock);
lu_ref_del(&lock->cll_reference, scope, source);
cl_lock_put(env, lock);
if (rc > 0) {
LASSERT(enqflags & CEF_AGL);
lock = NULL;
} else if (rc != 0) {
lock = ERR_PTR(rc);
}
} while (rc == 0);
RETURN(lock);
}
void cl_lock_hold_add(const struct lu_env *env, struct cl_lock *lock,
const char *scope, const void *source)
{
LINVRNT(cl_lock_is_mutexed(lock));
LINVRNT(cl_lock_invariant(env, lock));
LASSERT(lock->cll_state != CLS_FREEING);
ENTRY;
cl_lock_hold_mod(env, lock, +1);
cl_lock_get(lock);
lu_ref_add(&lock->cll_holders, scope, source);
lu_ref_add(&lock->cll_reference, scope, source);
EXIT;
}
void cl_lock_unhold(const struct lu_env *env, struct cl_lock *lock,
const char *scope, const void *source)
{
LINVRNT(cl_lock_invariant(env, lock));
ENTRY;
cl_lock_hold_release(env, lock, scope, source);
lu_ref_del(&lock->cll_reference, scope, source);
cl_lock_put(env, lock);
EXIT;
}
void cl_lock_release(const struct lu_env *env, struct cl_lock *lock,
const char *scope, const void *source)
{
LINVRNT(cl_lock_invariant(env, lock));
ENTRY;
cl_lock_trace(D_DLMTRACE, env, "release lock", lock);
cl_lock_mutex_get(env, lock);
cl_lock_hold_release(env, lock, scope, source);
cl_lock_mutex_put(env, lock);
lu_ref_del(&lock->cll_reference, scope, source);
cl_lock_put(env, lock);
EXIT;
}
void cl_lock_user_add(const struct lu_env *env, struct cl_lock *lock)
{
LINVRNT(cl_lock_is_mutexed(lock));
LINVRNT(cl_lock_invariant(env, lock));
ENTRY;
cl_lock_used_mod(env, lock, +1);
EXIT;
}
void cl_lock_user_del(const struct lu_env *env, struct cl_lock *lock)
{
LINVRNT(cl_lock_is_mutexed(lock));
LINVRNT(cl_lock_invariant(env, lock));
LASSERT(lock->cll_users > 0);
ENTRY;
cl_lock_used_mod(env, lock, -1);
if (lock->cll_users == 0)
wake_up_all(&lock->cll_wq);
EXIT;
}
const char *cl_lock_mode_name(const enum cl_lock_mode mode)
{
static const char *names[] = {
[CLM_PHANTOM] = "P",
[CLM_READ] = "R",
[CLM_WRITE] = "W",
[CLM_GROUP] = "G"
};
if (0 <= mode && mode < ARRAY_SIZE(names))
return names[mode];
else
return "U";
}
void cl_lock_descr_print(const struct lu_env *env, void *cookie,
lu_printer_t printer,
const struct cl_lock_descr *descr)
{
const struct lu_fid *fid;
fid = lu_object_fid(&descr->cld_obj->co_lu);
(*printer)(env, cookie, DDESCR"@"DFID, PDESCR(descr), PFID(fid));
}
void cl_lock_print(const struct lu_env *env, void *cookie,
lu_printer_t printer, const struct cl_lock *lock)
{
const struct cl_lock_slice *slice;
(*printer)(env, cookie, "lock@%p[%d %d %d %d %d %08lx] ",
lock, atomic_read(&lock->cll_ref),
lock->cll_state, lock->cll_error, lock->cll_holds,
lock->cll_users, lock->cll_flags);
cl_lock_descr_print(env, cookie, printer, &lock->cll_descr);
(*printer)(env, cookie, " {\n");
list_for_each_entry(slice, &lock->cll_layers, cls_linkage) {
(*printer)(env, cookie, " %s@%p: ",
slice->cls_obj->co_lu.lo_dev->ld_type->ldt_name,
slice);
if (slice->cls_ops->clo_print != NULL)
slice->cls_ops->clo_print(env, cookie, printer, slice);
(*printer)(env, cookie, "\n");
}
(*printer)(env, cookie, "} lock@%p\n", lock);
}
int cl_lock_init(void)
{
return lu_kmem_init(cl_lock_caches);
}
void cl_lock_fini(void)
{
lu_kmem_fini(cl_lock_caches);
}
