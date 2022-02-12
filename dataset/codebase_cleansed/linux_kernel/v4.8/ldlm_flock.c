static inline int
ldlm_same_flock_owner(struct ldlm_lock *lock, struct ldlm_lock *new)
{
return((new->l_policy_data.l_flock.owner ==
lock->l_policy_data.l_flock.owner) &&
(new->l_export == lock->l_export));
}
static inline int
ldlm_flocks_overlap(struct ldlm_lock *lock, struct ldlm_lock *new)
{
return((new->l_policy_data.l_flock.start <=
lock->l_policy_data.l_flock.end) &&
(new->l_policy_data.l_flock.end >=
lock->l_policy_data.l_flock.start));
}
static inline void
ldlm_flock_destroy(struct ldlm_lock *lock, enum ldlm_mode mode, __u64 flags)
{
LDLM_DEBUG(lock, "ldlm_flock_destroy(mode: %d, flags: 0x%llx)",
mode, flags);
LASSERT(hlist_unhashed(&lock->l_exp_flock_hash));
list_del_init(&lock->l_res_link);
if (flags == LDLM_FL_WAIT_NOREPROC && !ldlm_is_failed(lock)) {
lock->l_flags |= LDLM_FL_LOCAL_ONLY | LDLM_FL_CBPENDING;
ldlm_lock_decref_internal_nolock(lock, mode);
}
ldlm_lock_destroy_nolock(lock);
}
static int ldlm_process_flock_lock(struct ldlm_lock *req, __u64 *flags,
int first_enq, enum ldlm_error *err,
struct list_head *work_list)
{
struct ldlm_resource *res = req->l_resource;
struct ldlm_namespace *ns = ldlm_res_to_ns(res);
struct list_head *tmp;
struct list_head *ownlocks = NULL;
struct ldlm_lock *lock = NULL;
struct ldlm_lock *new = req;
struct ldlm_lock *new2 = NULL;
enum ldlm_mode mode = req->l_req_mode;
int added = (mode == LCK_NL);
int overlaps = 0;
int splitted = 0;
const struct ldlm_callback_suite null_cbs = { NULL };
CDEBUG(D_DLMTRACE,
"flags %#llx owner %llu pid %u mode %u start %llu end %llu\n",
*flags, new->l_policy_data.l_flock.owner,
new->l_policy_data.l_flock.pid, mode,
req->l_policy_data.l_flock.start,
req->l_policy_data.l_flock.end);
*err = ELDLM_OK;
req->l_blocking_ast = NULL;
reprocess:
if ((*flags == LDLM_FL_WAIT_NOREPROC) || (mode == LCK_NL)) {
list_for_each(tmp, &res->lr_granted) {
lock = list_entry(tmp, struct ldlm_lock,
l_res_link);
if (ldlm_same_flock_owner(lock, req)) {
ownlocks = tmp;
break;
}
}
} else {
int reprocess_failed = 0;
lockmode_verify(mode);
list_for_each(tmp, &res->lr_granted) {
lock = list_entry(tmp, struct ldlm_lock,
l_res_link);
if (ldlm_same_flock_owner(lock, req)) {
if (!ownlocks)
ownlocks = tmp;
continue;
}
if (lockmode_compat(lock->l_granted_mode, mode))
continue;
if (!ldlm_flocks_overlap(lock, req))
continue;
if (!first_enq) {
reprocess_failed = 1;
continue;
}
if (*flags & LDLM_FL_BLOCK_NOWAIT) {
ldlm_flock_destroy(req, mode, *flags);
*err = -EAGAIN;
return LDLM_ITER_STOP;
}
if (*flags & LDLM_FL_TEST_LOCK) {
ldlm_flock_destroy(req, mode, *flags);
req->l_req_mode = lock->l_granted_mode;
req->l_policy_data.l_flock.pid =
lock->l_policy_data.l_flock.pid;
req->l_policy_data.l_flock.start =
lock->l_policy_data.l_flock.start;
req->l_policy_data.l_flock.end =
lock->l_policy_data.l_flock.end;
*flags |= LDLM_FL_LOCK_CHANGED;
return LDLM_ITER_STOP;
}
ldlm_resource_add_lock(res, &res->lr_waiting, req);
*flags |= LDLM_FL_BLOCK_GRANTED;
return LDLM_ITER_STOP;
}
if (reprocess_failed)
return LDLM_ITER_CONTINUE;
}
if (*flags & LDLM_FL_TEST_LOCK) {
ldlm_flock_destroy(req, mode, *flags);
req->l_req_mode = LCK_NL;
*flags |= LDLM_FL_LOCK_CHANGED;
return LDLM_ITER_STOP;
}
if (!ownlocks)
ownlocks = &res->lr_granted;
list_for_remaining_safe(ownlocks, tmp, &res->lr_granted) {
lock = list_entry(ownlocks, struct ldlm_lock, l_res_link);
if (!ldlm_same_flock_owner(lock, new))
break;
if (lock->l_granted_mode == mode) {
if ((new->l_policy_data.l_flock.start >
(lock->l_policy_data.l_flock.end + 1)) &&
(lock->l_policy_data.l_flock.end != OBD_OBJECT_EOF))
continue;
if ((new->l_policy_data.l_flock.end <
(lock->l_policy_data.l_flock.start - 1)) &&
(lock->l_policy_data.l_flock.start != 0))
break;
if (new->l_policy_data.l_flock.start <
lock->l_policy_data.l_flock.start) {
lock->l_policy_data.l_flock.start =
new->l_policy_data.l_flock.start;
} else {
new->l_policy_data.l_flock.start =
lock->l_policy_data.l_flock.start;
}
if (new->l_policy_data.l_flock.end >
lock->l_policy_data.l_flock.end) {
lock->l_policy_data.l_flock.end =
new->l_policy_data.l_flock.end;
} else {
new->l_policy_data.l_flock.end =
lock->l_policy_data.l_flock.end;
}
if (added) {
ldlm_flock_destroy(lock, mode, *flags);
} else {
new = lock;
added = 1;
}
continue;
}
if (new->l_policy_data.l_flock.start >
lock->l_policy_data.l_flock.end)
continue;
if (new->l_policy_data.l_flock.end <
lock->l_policy_data.l_flock.start)
break;
++overlaps;
if (new->l_policy_data.l_flock.start <=
lock->l_policy_data.l_flock.start) {
if (new->l_policy_data.l_flock.end <
lock->l_policy_data.l_flock.end) {
lock->l_policy_data.l_flock.start =
new->l_policy_data.l_flock.end + 1;
break;
}
ldlm_flock_destroy(lock, lock->l_req_mode, *flags);
continue;
}
if (new->l_policy_data.l_flock.end >=
lock->l_policy_data.l_flock.end) {
lock->l_policy_data.l_flock.end =
new->l_policy_data.l_flock.start - 1;
continue;
}
if (!new2) {
unlock_res_and_lock(req);
new2 = ldlm_lock_create(ns, &res->lr_name, LDLM_FLOCK,
lock->l_granted_mode, &null_cbs,
NULL, 0, LVB_T_NONE);
lock_res_and_lock(req);
if (!new2) {
ldlm_flock_destroy(req, lock->l_granted_mode,
*flags);
*err = -ENOLCK;
return LDLM_ITER_STOP;
}
goto reprocess;
}
splitted = 1;
new2->l_granted_mode = lock->l_granted_mode;
new2->l_policy_data.l_flock.pid =
new->l_policy_data.l_flock.pid;
new2->l_policy_data.l_flock.owner =
new->l_policy_data.l_flock.owner;
new2->l_policy_data.l_flock.start =
lock->l_policy_data.l_flock.start;
new2->l_policy_data.l_flock.end =
new->l_policy_data.l_flock.start - 1;
lock->l_policy_data.l_flock.start =
new->l_policy_data.l_flock.end + 1;
new2->l_conn_export = lock->l_conn_export;
if (lock->l_export) {
new2->l_export = class_export_lock_get(lock->l_export,
new2);
if (new2->l_export->exp_lock_hash &&
hlist_unhashed(&new2->l_exp_hash))
cfs_hash_add(new2->l_export->exp_lock_hash,
&new2->l_remote_handle,
&new2->l_exp_hash);
}
if (*flags == LDLM_FL_WAIT_NOREPROC)
ldlm_lock_addref_internal_nolock(new2,
lock->l_granted_mode);
ldlm_resource_add_lock(res, ownlocks, new2);
LDLM_LOCK_RELEASE(new2);
break;
}
if (splitted == 0 && new2)
ldlm_lock_destroy_nolock(new2);
req->l_granted_mode = req->l_req_mode;
if (!added) {
list_del_init(&req->l_res_link);
ldlm_resource_add_lock(res, ownlocks, req);
}
if (*flags != LDLM_FL_WAIT_NOREPROC) {
CERROR("Illegal parameter for client-side-only module.\n");
LBUG();
}
if (added)
ldlm_flock_destroy(req, mode, *flags);
ldlm_resource_dump(D_INFO, res);
return LDLM_ITER_CONTINUE;
}
static void
ldlm_flock_interrupted_wait(void *data)
{
struct ldlm_lock *lock;
lock = ((struct ldlm_flock_wait_data *)data)->fwd_lock;
lock_res_and_lock(lock);
ldlm_set_cbpending(lock);
unlock_res_and_lock(lock);
}
int
ldlm_flock_completion_ast(struct ldlm_lock *lock, __u64 flags, void *data)
{
struct file_lock *getlk = lock->l_ast_data;
struct obd_device *obd;
struct obd_import *imp = NULL;
struct ldlm_flock_wait_data fwd;
struct l_wait_info lwi;
enum ldlm_error err;
int rc = 0;
CDEBUG(D_DLMTRACE, "flags: 0x%llx data: %p getlk: %p\n",
flags, data, getlk);
if ((lock->l_flags & (LDLM_FL_FAILED|LDLM_FL_LOCAL_ONLY)) ==
(LDLM_FL_FAILED|LDLM_FL_LOCAL_ONLY)) {
if (lock->l_req_mode == lock->l_granted_mode &&
lock->l_granted_mode != LCK_NL && !data)
ldlm_lock_decref_internal(lock, lock->l_req_mode);
wake_up(&lock->l_waitq);
return 0;
}
LASSERT(flags != LDLM_FL_WAIT_NOREPROC);
if (!(flags & (LDLM_FL_BLOCK_WAIT | LDLM_FL_BLOCK_GRANTED |
LDLM_FL_BLOCK_CONV))) {
if (!data)
goto granted;
wake_up(&lock->l_waitq);
return 0;
}
LDLM_DEBUG(lock, "client-side enqueue returned a blocked lock, sleeping");
fwd.fwd_lock = lock;
obd = class_exp2obd(lock->l_conn_export);
if (obd)
imp = obd->u.cli.cl_import;
if (imp) {
spin_lock(&imp->imp_lock);
fwd.fwd_generation = imp->imp_generation;
spin_unlock(&imp->imp_lock);
}
lwi = LWI_TIMEOUT_INTR(0, NULL, ldlm_flock_interrupted_wait, &fwd);
rc = l_wait_event(lock->l_waitq, is_granted_or_cancelled(lock), &lwi);
if (rc) {
LDLM_DEBUG(lock, "client-side enqueue waking up: failed (%d)",
rc);
return rc;
}
granted:
OBD_FAIL_TIMEOUT(OBD_FAIL_LDLM_CP_CB_WAIT, 10);
if (ldlm_is_failed(lock)) {
LDLM_DEBUG(lock, "client-side enqueue waking up: failed");
return -EIO;
}
LDLM_DEBUG(lock, "client-side enqueue granted");
lock_res_and_lock(lock);
if (ldlm_is_destroyed(lock)) {
unlock_res_and_lock(lock);
LDLM_DEBUG(lock, "client-side enqueue waking up: destroyed");
return 0;
}
list_del_init(&lock->l_res_link);
if (ldlm_is_flock_deadlock(lock)) {
LDLM_DEBUG(lock, "client-side enqueue deadlock received");
rc = -EDEADLK;
} else if (flags & LDLM_FL_TEST_LOCK) {
ldlm_flock_destroy(lock, getlk->fl_type, LDLM_FL_WAIT_NOREPROC);
switch (lock->l_granted_mode) {
case LCK_PR:
getlk->fl_type = F_RDLCK;
break;
case LCK_PW:
getlk->fl_type = F_WRLCK;
break;
default:
getlk->fl_type = F_UNLCK;
}
getlk->fl_pid = (pid_t)lock->l_policy_data.l_flock.pid;
getlk->fl_start = (loff_t)lock->l_policy_data.l_flock.start;
getlk->fl_end = (loff_t)lock->l_policy_data.l_flock.end;
} else {
__u64 noreproc = LDLM_FL_WAIT_NOREPROC;
ldlm_process_flock_lock(lock, &noreproc, 1, &err, NULL);
}
unlock_res_and_lock(lock);
return rc;
}
void ldlm_flock_policy_wire18_to_local(const ldlm_wire_policy_data_t *wpolicy,
ldlm_policy_data_t *lpolicy)
{
memset(lpolicy, 0, sizeof(*lpolicy));
lpolicy->l_flock.start = wpolicy->l_flock.lfw_start;
lpolicy->l_flock.end = wpolicy->l_flock.lfw_end;
lpolicy->l_flock.pid = wpolicy->l_flock.lfw_pid;
lpolicy->l_flock.owner = wpolicy->l_flock.lfw_pid;
}
void ldlm_flock_policy_wire21_to_local(const ldlm_wire_policy_data_t *wpolicy,
ldlm_policy_data_t *lpolicy)
{
memset(lpolicy, 0, sizeof(*lpolicy));
lpolicy->l_flock.start = wpolicy->l_flock.lfw_start;
lpolicy->l_flock.end = wpolicy->l_flock.lfw_end;
lpolicy->l_flock.pid = wpolicy->l_flock.lfw_pid;
lpolicy->l_flock.owner = wpolicy->l_flock.lfw_owner;
}
void ldlm_flock_policy_local_to_wire(const ldlm_policy_data_t *lpolicy,
ldlm_wire_policy_data_t *wpolicy)
{
memset(wpolicy, 0, sizeof(*wpolicy));
wpolicy->l_flock.lfw_start = lpolicy->l_flock.start;
wpolicy->l_flock.lfw_end = lpolicy->l_flock.end;
wpolicy->l_flock.lfw_pid = lpolicy->l_flock.pid;
wpolicy->l_flock.lfw_owner = lpolicy->l_flock.owner;
}
