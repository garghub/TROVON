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
static inline void ldlm_flock_blocking_link(struct ldlm_lock *req,
struct ldlm_lock *lock)
{
if (req->l_export == NULL)
return;
LASSERT(hlist_unhashed(&req->l_exp_flock_hash));
req->l_policy_data.l_flock.blocking_owner =
lock->l_policy_data.l_flock.owner;
req->l_policy_data.l_flock.blocking_export =
lock->l_export;
req->l_policy_data.l_flock.blocking_refs = 0;
cfs_hash_add(req->l_export->exp_flock_hash,
&req->l_policy_data.l_flock.owner,
&req->l_exp_flock_hash);
}
static inline void ldlm_flock_blocking_unlink(struct ldlm_lock *req)
{
if (req->l_export == NULL)
return;
check_res_locked(req->l_resource);
if (req->l_export->exp_flock_hash != NULL &&
!hlist_unhashed(&req->l_exp_flock_hash))
cfs_hash_del(req->l_export->exp_flock_hash,
&req->l_policy_data.l_flock.owner,
&req->l_exp_flock_hash);
}
static inline void
ldlm_flock_destroy(struct ldlm_lock *lock, ldlm_mode_t mode, __u64 flags)
{
LDLM_DEBUG(lock, "ldlm_flock_destroy(mode: %d, flags: 0x%llx)",
mode, flags);
LASSERT(hlist_unhashed(&lock->l_exp_flock_hash));
list_del_init(&lock->l_res_link);
if (flags == LDLM_FL_WAIT_NOREPROC &&
!(lock->l_flags & LDLM_FL_FAILED)) {
lock->l_flags |= LDLM_FL_LOCAL_ONLY | LDLM_FL_CBPENDING;
ldlm_lock_decref_internal_nolock(lock, mode);
}
ldlm_lock_destroy_nolock(lock);
}
static int
ldlm_flock_deadlock(struct ldlm_lock *req, struct ldlm_lock *bl_lock)
{
struct obd_export *req_exp = req->l_export;
struct obd_export *bl_exp = bl_lock->l_export;
__u64 req_owner = req->l_policy_data.l_flock.owner;
__u64 bl_owner = bl_lock->l_policy_data.l_flock.owner;
if (req_exp == NULL)
return 0;
class_export_get(bl_exp);
while (1) {
struct obd_export *bl_exp_new;
struct ldlm_lock *lock = NULL;
struct ldlm_flock *flock;
if (bl_exp->exp_flock_hash != NULL)
lock = cfs_hash_lookup(bl_exp->exp_flock_hash,
&bl_owner);
if (lock == NULL)
break;
LASSERT(req != lock);
flock = &lock->l_policy_data.l_flock;
LASSERT(flock->owner == bl_owner);
bl_owner = flock->blocking_owner;
bl_exp_new = class_export_get(flock->blocking_export);
class_export_put(bl_exp);
cfs_hash_put(bl_exp->exp_flock_hash, &lock->l_exp_flock_hash);
bl_exp = bl_exp_new;
if (bl_owner == req_owner && bl_exp == req_exp) {
class_export_put(bl_exp);
return 1;
}
}
class_export_put(bl_exp);
return 0;
}
static void ldlm_flock_cancel_on_deadlock(struct ldlm_lock *lock,
struct list_head *work_list)
{
CDEBUG(D_INFO, "reprocess deadlock req=%p\n", lock);
if ((exp_connect_flags(lock->l_export) &
OBD_CONNECT_FLOCK_DEAD) == 0) {
CERROR(
"deadlock found, but client doesn't support flock canceliation\n");
} else {
LASSERT(lock->l_completion_ast);
LASSERT((lock->l_flags & LDLM_FL_AST_SENT) == 0);
lock->l_flags |= LDLM_FL_AST_SENT | LDLM_FL_CANCEL_ON_BLOCK |
LDLM_FL_FLOCK_DEADLOCK;
ldlm_flock_blocking_unlink(lock);
ldlm_resource_unlink_lock(lock);
ldlm_add_ast_work_item(lock, NULL, work_list);
}
}
int
ldlm_process_flock_lock(struct ldlm_lock *req, __u64 *flags, int first_enq,
ldlm_error_t *err, struct list_head *work_list)
{
struct ldlm_resource *res = req->l_resource;
struct ldlm_namespace *ns = ldlm_res_to_ns(res);
struct list_head *tmp;
struct list_head *ownlocks = NULL;
struct ldlm_lock *lock = NULL;
struct ldlm_lock *new = req;
struct ldlm_lock *new2 = NULL;
ldlm_mode_t mode = req->l_req_mode;
int local = ns_is_client(ns);
int added = (mode == LCK_NL);
int overlaps = 0;
int splitted = 0;
const struct ldlm_callback_suite null_cbs = { NULL };
CDEBUG(D_DLMTRACE, "flags %#llx owner %llu pid %u mode %u start %llu end %llu\n",
*flags, new->l_policy_data.l_flock.owner,
new->l_policy_data.l_flock.pid, mode,
req->l_policy_data.l_flock.start,
req->l_policy_data.l_flock.end);
*err = ELDLM_OK;
if (local) {
req->l_blocking_ast = NULL;
} else {
req->l_blocking_ast = ldlm_flock_blocking_ast;
}
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
if (ldlm_flock_deadlock(req, lock)) {
ldlm_flock_cancel_on_deadlock(req,
work_list);
return LDLM_ITER_CONTINUE;
}
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
ldlm_flock_blocking_link(req, lock);
if (ldlm_flock_deadlock(req, lock)) {
ldlm_flock_blocking_unlink(req);
ldlm_flock_destroy(req, mode, *flags);
*err = -EDEADLK;
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
ldlm_flock_blocking_unlink(req);
if (!ownlocks)
ownlocks = &res->lr_granted;
list_for_remaining_safe(ownlocks, tmp, &res->lr_granted) {
lock = list_entry(ownlocks, struct ldlm_lock, l_res_link);
if (!ldlm_same_flock_owner(lock, new))
break;
if (lock->l_granted_mode == mode) {
if ((new->l_policy_data.l_flock.start >
(lock->l_policy_data.l_flock.end + 1))
&& (lock->l_policy_data.l_flock.end !=
OBD_OBJECT_EOF))
continue;
if ((new->l_policy_data.l_flock.end <
(lock->l_policy_data.l_flock.start - 1))
&& (lock->l_policy_data.l_flock.start != 0))
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
if (lock->l_export != NULL) {
new2->l_export = class_export_lock_get(lock->l_export, new2);
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
if (splitted == 0 && new2 != NULL)
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
ldlm_flock_blocking_unlink(lock);
lock->l_flags |= LDLM_FL_CBPENDING;
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
ldlm_error_t err;
int rc = 0;
CDEBUG(D_DLMTRACE, "flags: 0x%llx data: %p getlk: %p\n",
flags, data, getlk);
if ((lock->l_flags & (LDLM_FL_FAILED|LDLM_FL_LOCAL_ONLY)) ==
(LDLM_FL_FAILED|LDLM_FL_LOCAL_ONLY)) {
if (lock->l_req_mode == lock->l_granted_mode &&
lock->l_granted_mode != LCK_NL &&
NULL == data)
ldlm_lock_decref_internal(lock, lock->l_req_mode);
wake_up(&lock->l_waitq);
return 0;
}
LASSERT(flags != LDLM_FL_WAIT_NOREPROC);
if (!(flags & (LDLM_FL_BLOCK_WAIT | LDLM_FL_BLOCK_GRANTED |
LDLM_FL_BLOCK_CONV))) {
if (NULL == data)
goto granted;
wake_up(&lock->l_waitq);
return 0;
}
LDLM_DEBUG(lock, "client-side enqueue returned a blocked lock, "
"sleeping");
fwd.fwd_lock = lock;
obd = class_exp2obd(lock->l_conn_export);
if (NULL != obd)
imp = obd->u.cli.cl_import;
if (NULL != imp) {
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
if (lock->l_flags & LDLM_FL_DESTROYED) {
LDLM_DEBUG(lock, "client-side enqueue waking up: destroyed");
return 0;
}
if (lock->l_flags & LDLM_FL_FAILED) {
LDLM_DEBUG(lock, "client-side enqueue waking up: failed");
return -EIO;
}
if (rc) {
LDLM_DEBUG(lock, "client-side enqueue waking up: failed (%d)",
rc);
return rc;
}
LDLM_DEBUG(lock, "client-side enqueue granted");
lock_res_and_lock(lock);
ldlm_flock_blocking_unlink(lock);
list_del_init(&lock->l_res_link);
if (lock->l_flags & LDLM_FL_FLOCK_DEADLOCK) {
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
int ldlm_flock_blocking_ast(struct ldlm_lock *lock, struct ldlm_lock_desc *desc,
void *data, int flag)
{
LASSERT(lock);
LASSERT(flag == LDLM_CB_CANCELING);
lock_res_and_lock(lock);
ldlm_flock_blocking_unlink(lock);
unlock_res_and_lock(lock);
return 0;
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
static unsigned
ldlm_export_flock_hash(struct cfs_hash *hs, const void *key, unsigned mask)
{
return cfs_hash_u64_hash(*(__u64 *)key, mask);
}
static void *
ldlm_export_flock_key(struct hlist_node *hnode)
{
struct ldlm_lock *lock;
lock = hlist_entry(hnode, struct ldlm_lock, l_exp_flock_hash);
return &lock->l_policy_data.l_flock.owner;
}
static int
ldlm_export_flock_keycmp(const void *key, struct hlist_node *hnode)
{
return !memcmp(ldlm_export_flock_key(hnode), key, sizeof(__u64));
}
static void *
ldlm_export_flock_object(struct hlist_node *hnode)
{
return hlist_entry(hnode, struct ldlm_lock, l_exp_flock_hash);
}
static void
ldlm_export_flock_get(struct cfs_hash *hs, struct hlist_node *hnode)
{
struct ldlm_lock *lock;
struct ldlm_flock *flock;
lock = hlist_entry(hnode, struct ldlm_lock, l_exp_flock_hash);
LDLM_LOCK_GET(lock);
flock = &lock->l_policy_data.l_flock;
LASSERT(flock->blocking_export != NULL);
class_export_get(flock->blocking_export);
flock->blocking_refs++;
}
static void
ldlm_export_flock_put(struct cfs_hash *hs, struct hlist_node *hnode)
{
struct ldlm_lock *lock;
struct ldlm_flock *flock;
lock = hlist_entry(hnode, struct ldlm_lock, l_exp_flock_hash);
LDLM_LOCK_RELEASE(lock);
flock = &lock->l_policy_data.l_flock;
LASSERT(flock->blocking_export != NULL);
class_export_put(flock->blocking_export);
if (--flock->blocking_refs == 0) {
flock->blocking_owner = 0;
flock->blocking_export = NULL;
}
}
int ldlm_init_flock_export(struct obd_export *exp)
{
if (strcmp(exp->exp_obd->obd_type->typ_name, LUSTRE_MDT_NAME) != 0)
return 0;
exp->exp_flock_hash =
cfs_hash_create(obd_uuid2str(&exp->exp_client_uuid),
HASH_EXP_LOCK_CUR_BITS,
HASH_EXP_LOCK_MAX_BITS,
HASH_EXP_LOCK_BKT_BITS, 0,
CFS_HASH_MIN_THETA, CFS_HASH_MAX_THETA,
&ldlm_export_flock_ops,
CFS_HASH_DEFAULT | CFS_HASH_NBLK_CHANGE);
if (!exp->exp_flock_hash)
return -ENOMEM;
return 0;
}
void ldlm_destroy_flock_export(struct obd_export *exp)
{
if (exp->exp_flock_hash) {
cfs_hash_putref(exp->exp_flock_hash);
exp->exp_flock_hash = NULL;
}
}
