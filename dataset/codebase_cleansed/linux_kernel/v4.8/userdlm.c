static inline struct user_lock_res *user_lksb_to_lock_res(struct ocfs2_dlm_lksb *lksb)
{
return container_of(lksb, struct user_lock_res, l_lksb);
}
static inline int user_check_wait_flag(struct user_lock_res *lockres,
int flag)
{
int ret;
spin_lock(&lockres->l_lock);
ret = lockres->l_flags & flag;
spin_unlock(&lockres->l_lock);
return ret;
}
static inline void user_wait_on_busy_lock(struct user_lock_res *lockres)
{
wait_event(lockres->l_event,
!user_check_wait_flag(lockres, USER_LOCK_BUSY));
}
static inline void user_wait_on_blocked_lock(struct user_lock_res *lockres)
{
wait_event(lockres->l_event,
!user_check_wait_flag(lockres, USER_LOCK_BLOCKED));
}
static inline struct ocfs2_cluster_connection *
cluster_connection_from_user_lockres(struct user_lock_res *lockres)
{
struct dlmfs_inode_private *ip;
ip = container_of(lockres,
struct dlmfs_inode_private,
ip_lockres);
return ip->ip_conn;
}
static struct inode *
user_dlm_inode_from_user_lockres(struct user_lock_res *lockres)
{
struct dlmfs_inode_private *ip;
ip = container_of(lockres,
struct dlmfs_inode_private,
ip_lockres);
return &ip->ip_vfs_inode;
}
static inline void user_recover_from_dlm_error(struct user_lock_res *lockres)
{
spin_lock(&lockres->l_lock);
lockres->l_flags &= ~USER_LOCK_BUSY;
spin_unlock(&lockres->l_lock);
}
static inline int user_highest_compat_lock_level(int level)
{
int new_level = DLM_LOCK_EX;
if (level == DLM_LOCK_EX)
new_level = DLM_LOCK_NL;
else if (level == DLM_LOCK_PR)
new_level = DLM_LOCK_PR;
return new_level;
}
static void user_ast(struct ocfs2_dlm_lksb *lksb)
{
struct user_lock_res *lockres = user_lksb_to_lock_res(lksb);
int status;
mlog(ML_BASTS, "AST fired for lockres %.*s, level %d => %d\n",
lockres->l_namelen, lockres->l_name, lockres->l_level,
lockres->l_requested);
spin_lock(&lockres->l_lock);
status = ocfs2_dlm_lock_status(&lockres->l_lksb);
if (status) {
mlog(ML_ERROR, "lksb status value of %u on lockres %.*s\n",
status, lockres->l_namelen, lockres->l_name);
spin_unlock(&lockres->l_lock);
return;
}
mlog_bug_on_msg(lockres->l_requested == DLM_LOCK_IV,
"Lockres %.*s, requested ivmode. flags 0x%x\n",
lockres->l_namelen, lockres->l_name, lockres->l_flags);
if (lockres->l_requested < lockres->l_level) {
if (lockres->l_requested <=
user_highest_compat_lock_level(lockres->l_blocking)) {
lockres->l_blocking = DLM_LOCK_NL;
lockres->l_flags &= ~USER_LOCK_BLOCKED;
}
}
lockres->l_level = lockres->l_requested;
lockres->l_requested = DLM_LOCK_IV;
lockres->l_flags |= USER_LOCK_ATTACHED;
lockres->l_flags &= ~USER_LOCK_BUSY;
spin_unlock(&lockres->l_lock);
wake_up(&lockres->l_event);
}
static inline void user_dlm_grab_inode_ref(struct user_lock_res *lockres)
{
struct inode *inode;
inode = user_dlm_inode_from_user_lockres(lockres);
if (!igrab(inode))
BUG();
}
static void __user_dlm_queue_lockres(struct user_lock_res *lockres)
{
if (!(lockres->l_flags & USER_LOCK_QUEUED)) {
user_dlm_grab_inode_ref(lockres);
INIT_WORK(&lockres->l_work, user_dlm_unblock_lock);
queue_work(user_dlm_worker, &lockres->l_work);
lockres->l_flags |= USER_LOCK_QUEUED;
}
}
static void __user_dlm_cond_queue_lockres(struct user_lock_res *lockres)
{
int queue = 0;
if (!(lockres->l_flags & USER_LOCK_BLOCKED))
return;
switch (lockres->l_blocking) {
case DLM_LOCK_EX:
if (!lockres->l_ex_holders && !lockres->l_ro_holders)
queue = 1;
break;
case DLM_LOCK_PR:
if (!lockres->l_ex_holders)
queue = 1;
break;
default:
BUG();
}
if (queue)
__user_dlm_queue_lockres(lockres);
}
static void user_bast(struct ocfs2_dlm_lksb *lksb, int level)
{
struct user_lock_res *lockres = user_lksb_to_lock_res(lksb);
mlog(ML_BASTS, "BAST fired for lockres %.*s, blocking %d, level %d\n",
lockres->l_namelen, lockres->l_name, level, lockres->l_level);
spin_lock(&lockres->l_lock);
lockres->l_flags |= USER_LOCK_BLOCKED;
if (level > lockres->l_blocking)
lockres->l_blocking = level;
__user_dlm_queue_lockres(lockres);
spin_unlock(&lockres->l_lock);
wake_up(&lockres->l_event);
}
static void user_unlock_ast(struct ocfs2_dlm_lksb *lksb, int status)
{
struct user_lock_res *lockres = user_lksb_to_lock_res(lksb);
mlog(ML_BASTS, "UNLOCK AST fired for lockres %.*s, flags 0x%x\n",
lockres->l_namelen, lockres->l_name, lockres->l_flags);
if (status)
mlog(ML_ERROR, "dlm returns status %d\n", status);
spin_lock(&lockres->l_lock);
if (lockres->l_flags & USER_LOCK_IN_TEARDOWN
&& !(lockres->l_flags & USER_LOCK_IN_CANCEL)) {
lockres->l_level = DLM_LOCK_IV;
} else if (status == DLM_CANCELGRANT) {
BUG_ON(!(lockres->l_flags & USER_LOCK_IN_CANCEL));
lockres->l_flags &= ~USER_LOCK_IN_CANCEL;
goto out_noclear;
} else {
BUG_ON(!(lockres->l_flags & USER_LOCK_IN_CANCEL));
lockres->l_requested = DLM_LOCK_IV;
lockres->l_flags &= ~USER_LOCK_IN_CANCEL;
if (lockres->l_flags & USER_LOCK_BLOCKED)
__user_dlm_queue_lockres(lockres);
}
lockres->l_flags &= ~USER_LOCK_BUSY;
out_noclear:
spin_unlock(&lockres->l_lock);
wake_up(&lockres->l_event);
}
static inline void user_dlm_drop_inode_ref(struct user_lock_res *lockres)
{
struct inode *inode;
inode = user_dlm_inode_from_user_lockres(lockres);
iput(inode);
}
static void user_dlm_unblock_lock(struct work_struct *work)
{
int new_level, status;
struct user_lock_res *lockres =
container_of(work, struct user_lock_res, l_work);
struct ocfs2_cluster_connection *conn =
cluster_connection_from_user_lockres(lockres);
mlog(0, "lockres %.*s\n", lockres->l_namelen, lockres->l_name);
spin_lock(&lockres->l_lock);
mlog_bug_on_msg(!(lockres->l_flags & USER_LOCK_QUEUED),
"Lockres %.*s, flags 0x%x\n",
lockres->l_namelen, lockres->l_name, lockres->l_flags);
lockres->l_flags &= ~USER_LOCK_QUEUED;
if (!(lockres->l_flags & USER_LOCK_BLOCKED)) {
mlog(ML_BASTS, "lockres %.*s USER_LOCK_BLOCKED\n",
lockres->l_namelen, lockres->l_name);
spin_unlock(&lockres->l_lock);
goto drop_ref;
}
if (lockres->l_flags & USER_LOCK_IN_TEARDOWN) {
mlog(ML_BASTS, "lockres %.*s USER_LOCK_IN_TEARDOWN\n",
lockres->l_namelen, lockres->l_name);
spin_unlock(&lockres->l_lock);
goto drop_ref;
}
if (lockres->l_flags & USER_LOCK_BUSY) {
if (lockres->l_flags & USER_LOCK_IN_CANCEL) {
mlog(ML_BASTS, "lockres %.*s USER_LOCK_IN_CANCEL\n",
lockres->l_namelen, lockres->l_name);
spin_unlock(&lockres->l_lock);
goto drop_ref;
}
lockres->l_flags |= USER_LOCK_IN_CANCEL;
spin_unlock(&lockres->l_lock);
status = ocfs2_dlm_unlock(conn, &lockres->l_lksb,
DLM_LKF_CANCEL);
if (status)
user_log_dlm_error("ocfs2_dlm_unlock", status, lockres);
goto drop_ref;
}
if ((lockres->l_blocking == DLM_LOCK_EX)
&& (lockres->l_ex_holders || lockres->l_ro_holders)) {
spin_unlock(&lockres->l_lock);
mlog(ML_BASTS, "lockres %.*s, EX/PR Holders %u,%u\n",
lockres->l_namelen, lockres->l_name,
lockres->l_ex_holders, lockres->l_ro_holders);
goto drop_ref;
}
if ((lockres->l_blocking == DLM_LOCK_PR)
&& lockres->l_ex_holders) {
spin_unlock(&lockres->l_lock);
mlog(ML_BASTS, "lockres %.*s, EX Holders %u\n",
lockres->l_namelen, lockres->l_name,
lockres->l_ex_holders);
goto drop_ref;
}
new_level = user_highest_compat_lock_level(lockres->l_blocking);
lockres->l_requested = new_level;
lockres->l_flags |= USER_LOCK_BUSY;
mlog(ML_BASTS, "lockres %.*s, downconvert %d => %d\n",
lockres->l_namelen, lockres->l_name, lockres->l_level, new_level);
spin_unlock(&lockres->l_lock);
status = ocfs2_dlm_lock(conn, new_level, &lockres->l_lksb,
DLM_LKF_CONVERT|DLM_LKF_VALBLK,
lockres->l_name,
lockres->l_namelen);
if (status) {
user_log_dlm_error("ocfs2_dlm_lock", status, lockres);
user_recover_from_dlm_error(lockres);
}
drop_ref:
user_dlm_drop_inode_ref(lockres);
}
static inline void user_dlm_inc_holders(struct user_lock_res *lockres,
int level)
{
switch(level) {
case DLM_LOCK_EX:
lockres->l_ex_holders++;
break;
case DLM_LOCK_PR:
lockres->l_ro_holders++;
break;
default:
BUG();
}
}
static inline int
user_may_continue_on_blocked_lock(struct user_lock_res *lockres,
int wanted)
{
BUG_ON(!(lockres->l_flags & USER_LOCK_BLOCKED));
return wanted <= user_highest_compat_lock_level(lockres->l_blocking);
}
int user_dlm_cluster_lock(struct user_lock_res *lockres,
int level,
int lkm_flags)
{
int status, local_flags;
struct ocfs2_cluster_connection *conn =
cluster_connection_from_user_lockres(lockres);
if (level != DLM_LOCK_EX &&
level != DLM_LOCK_PR) {
mlog(ML_ERROR, "lockres %.*s: invalid request!\n",
lockres->l_namelen, lockres->l_name);
status = -EINVAL;
goto bail;
}
mlog(ML_BASTS, "lockres %.*s, level %d, flags = 0x%x\n",
lockres->l_namelen, lockres->l_name, level, lkm_flags);
again:
if (signal_pending(current)) {
status = -ERESTARTSYS;
goto bail;
}
spin_lock(&lockres->l_lock);
if ((lockres->l_flags & USER_LOCK_BUSY) &&
(level > lockres->l_level)) {
spin_unlock(&lockres->l_lock);
user_wait_on_busy_lock(lockres);
goto again;
}
if ((lockres->l_flags & USER_LOCK_BLOCKED) &&
(!user_may_continue_on_blocked_lock(lockres, level))) {
spin_unlock(&lockres->l_lock);
user_wait_on_blocked_lock(lockres);
goto again;
}
if (level > lockres->l_level) {
local_flags = lkm_flags | DLM_LKF_VALBLK;
if (lockres->l_level != DLM_LOCK_IV)
local_flags |= DLM_LKF_CONVERT;
lockres->l_requested = level;
lockres->l_flags |= USER_LOCK_BUSY;
spin_unlock(&lockres->l_lock);
BUG_ON(level == DLM_LOCK_IV);
BUG_ON(level == DLM_LOCK_NL);
status = ocfs2_dlm_lock(conn, level, &lockres->l_lksb,
local_flags, lockres->l_name,
lockres->l_namelen);
if (status) {
if ((lkm_flags & DLM_LKF_NOQUEUE) &&
(status != -EAGAIN))
user_log_dlm_error("ocfs2_dlm_lock",
status, lockres);
user_recover_from_dlm_error(lockres);
goto bail;
}
user_wait_on_busy_lock(lockres);
goto again;
}
user_dlm_inc_holders(lockres, level);
spin_unlock(&lockres->l_lock);
status = 0;
bail:
return status;
}
static inline void user_dlm_dec_holders(struct user_lock_res *lockres,
int level)
{
switch(level) {
case DLM_LOCK_EX:
BUG_ON(!lockres->l_ex_holders);
lockres->l_ex_holders--;
break;
case DLM_LOCK_PR:
BUG_ON(!lockres->l_ro_holders);
lockres->l_ro_holders--;
break;
default:
BUG();
}
}
void user_dlm_cluster_unlock(struct user_lock_res *lockres,
int level)
{
if (level != DLM_LOCK_EX &&
level != DLM_LOCK_PR) {
mlog(ML_ERROR, "lockres %.*s: invalid request!\n",
lockres->l_namelen, lockres->l_name);
return;
}
spin_lock(&lockres->l_lock);
user_dlm_dec_holders(lockres, level);
__user_dlm_cond_queue_lockres(lockres);
spin_unlock(&lockres->l_lock);
}
void user_dlm_write_lvb(struct inode *inode,
const char *val,
unsigned int len)
{
struct user_lock_res *lockres = &DLMFS_I(inode)->ip_lockres;
char *lvb;
BUG_ON(len > DLM_LVB_LEN);
spin_lock(&lockres->l_lock);
BUG_ON(lockres->l_level < DLM_LOCK_EX);
lvb = ocfs2_dlm_lvb(&lockres->l_lksb);
memcpy(lvb, val, len);
spin_unlock(&lockres->l_lock);
}
ssize_t user_dlm_read_lvb(struct inode *inode,
char *val,
unsigned int len)
{
struct user_lock_res *lockres = &DLMFS_I(inode)->ip_lockres;
char *lvb;
ssize_t ret = len;
BUG_ON(len > DLM_LVB_LEN);
spin_lock(&lockres->l_lock);
BUG_ON(lockres->l_level < DLM_LOCK_PR);
if (ocfs2_dlm_lvb_valid(&lockres->l_lksb)) {
lvb = ocfs2_dlm_lvb(&lockres->l_lksb);
memcpy(val, lvb, len);
} else
ret = 0;
spin_unlock(&lockres->l_lock);
return ret;
}
void user_dlm_lock_res_init(struct user_lock_res *lockres,
struct dentry *dentry)
{
memset(lockres, 0, sizeof(*lockres));
spin_lock_init(&lockres->l_lock);
init_waitqueue_head(&lockres->l_event);
lockres->l_level = DLM_LOCK_IV;
lockres->l_requested = DLM_LOCK_IV;
lockres->l_blocking = DLM_LOCK_IV;
BUG_ON(dentry->d_name.len >= USER_DLM_LOCK_ID_MAX_LEN);
memcpy(lockres->l_name,
dentry->d_name.name,
dentry->d_name.len);
lockres->l_namelen = dentry->d_name.len;
}
int user_dlm_destroy_lock(struct user_lock_res *lockres)
{
int status = -EBUSY;
struct ocfs2_cluster_connection *conn =
cluster_connection_from_user_lockres(lockres);
mlog(ML_BASTS, "lockres %.*s\n", lockres->l_namelen, lockres->l_name);
spin_lock(&lockres->l_lock);
if (lockres->l_flags & USER_LOCK_IN_TEARDOWN) {
spin_unlock(&lockres->l_lock);
return 0;
}
lockres->l_flags |= USER_LOCK_IN_TEARDOWN;
while (lockres->l_flags & USER_LOCK_BUSY) {
spin_unlock(&lockres->l_lock);
user_wait_on_busy_lock(lockres);
spin_lock(&lockres->l_lock);
}
if (lockres->l_ro_holders || lockres->l_ex_holders) {
spin_unlock(&lockres->l_lock);
goto bail;
}
status = 0;
if (!(lockres->l_flags & USER_LOCK_ATTACHED)) {
spin_unlock(&lockres->l_lock);
goto bail;
}
lockres->l_flags &= ~USER_LOCK_ATTACHED;
lockres->l_flags |= USER_LOCK_BUSY;
spin_unlock(&lockres->l_lock);
status = ocfs2_dlm_unlock(conn, &lockres->l_lksb, DLM_LKF_VALBLK);
if (status) {
user_log_dlm_error("ocfs2_dlm_unlock", status, lockres);
goto bail;
}
user_wait_on_busy_lock(lockres);
status = 0;
bail:
return status;
}
static void user_dlm_recovery_handler_noop(int node_num,
void *recovery_data)
{
return;
}
void user_dlm_set_locking_protocol(void)
{
ocfs2_stack_glue_set_max_proto_version(&user_dlm_lproto.lp_max_version);
}
struct ocfs2_cluster_connection *user_dlm_register(const struct qstr *name)
{
int rc;
struct ocfs2_cluster_connection *conn;
rc = ocfs2_cluster_connect_agnostic(name->name, name->len,
&user_dlm_lproto,
user_dlm_recovery_handler_noop,
NULL, &conn);
if (rc)
mlog_errno(rc);
return rc ? ERR_PTR(rc) : conn;
}
void user_dlm_unregister(struct ocfs2_cluster_connection *conn)
{
ocfs2_cluster_disconnect(conn, 0);
}
