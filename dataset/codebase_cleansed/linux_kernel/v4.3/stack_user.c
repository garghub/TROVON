static inline void ocfs2_control_set_handshake_state(struct file *file,
int state)
{
struct ocfs2_control_private *p = file->private_data;
p->op_state = state;
}
static inline int ocfs2_control_get_handshake_state(struct file *file)
{
struct ocfs2_control_private *p = file->private_data;
return p->op_state;
}
static struct ocfs2_live_connection *ocfs2_connection_find(const char *name)
{
size_t len = strlen(name);
struct ocfs2_live_connection *c;
BUG_ON(!mutex_is_locked(&ocfs2_control_lock));
list_for_each_entry(c, &ocfs2_live_connection_list, oc_list) {
if ((c->oc_conn->cc_namelen == len) &&
!strncmp(c->oc_conn->cc_name, name, len))
return c;
}
return NULL;
}
static int ocfs2_live_connection_attach(struct ocfs2_cluster_connection *conn,
struct ocfs2_live_connection *c)
{
int rc = 0;
mutex_lock(&ocfs2_control_lock);
c->oc_conn = conn;
if ((c->oc_type == NO_CONTROLD) || atomic_read(&ocfs2_control_opened))
list_add(&c->oc_list, &ocfs2_live_connection_list);
else {
printk(KERN_ERR
"ocfs2: Userspace control daemon is not present\n");
rc = -ESRCH;
}
mutex_unlock(&ocfs2_control_lock);
return rc;
}
static void ocfs2_live_connection_drop(struct ocfs2_live_connection *c)
{
mutex_lock(&ocfs2_control_lock);
list_del_init(&c->oc_list);
c->oc_conn = NULL;
mutex_unlock(&ocfs2_control_lock);
kfree(c);
}
static int ocfs2_control_cfu(void *target, size_t target_len,
const char __user *buf, size_t count)
{
if ((count != target_len) ||
(count > sizeof(union ocfs2_control_message)))
return -EINVAL;
if (copy_from_user(target, buf, target_len))
return -EFAULT;
return 0;
}
static ssize_t ocfs2_control_validate_protocol(struct file *file,
const char __user *buf,
size_t count)
{
ssize_t ret;
char kbuf[OCFS2_CONTROL_PROTO_LEN];
ret = ocfs2_control_cfu(kbuf, OCFS2_CONTROL_PROTO_LEN,
buf, count);
if (ret)
return ret;
if (strncmp(kbuf, OCFS2_CONTROL_PROTO, OCFS2_CONTROL_PROTO_LEN))
return -EINVAL;
ocfs2_control_set_handshake_state(file,
OCFS2_CONTROL_HANDSHAKE_PROTOCOL);
return count;
}
static void ocfs2_control_send_down(const char *uuid,
int nodenum)
{
struct ocfs2_live_connection *c;
mutex_lock(&ocfs2_control_lock);
c = ocfs2_connection_find(uuid);
if (c) {
BUG_ON(c->oc_conn == NULL);
c->oc_conn->cc_recovery_handler(nodenum,
c->oc_conn->cc_recovery_data);
}
mutex_unlock(&ocfs2_control_lock);
}
static int ocfs2_control_install_private(struct file *file)
{
int rc = 0;
int set_p = 1;
struct ocfs2_control_private *p = file->private_data;
BUG_ON(p->op_state != OCFS2_CONTROL_HANDSHAKE_PROTOCOL);
mutex_lock(&ocfs2_control_lock);
if (p->op_this_node < 0) {
set_p = 0;
} else if ((ocfs2_control_this_node >= 0) &&
(ocfs2_control_this_node != p->op_this_node)) {
rc = -EINVAL;
goto out_unlock;
}
if (!p->op_proto.pv_major) {
set_p = 0;
} else if (!list_empty(&ocfs2_live_connection_list) &&
((running_proto.pv_major != p->op_proto.pv_major) ||
(running_proto.pv_minor != p->op_proto.pv_minor))) {
rc = -EINVAL;
goto out_unlock;
}
if (set_p) {
ocfs2_control_this_node = p->op_this_node;
running_proto.pv_major = p->op_proto.pv_major;
running_proto.pv_minor = p->op_proto.pv_minor;
}
out_unlock:
mutex_unlock(&ocfs2_control_lock);
if (!rc && set_p) {
atomic_inc(&ocfs2_control_opened);
ocfs2_control_set_handshake_state(file,
OCFS2_CONTROL_HANDSHAKE_VALID);
}
return rc;
}
static int ocfs2_control_get_this_node(void)
{
int rc;
mutex_lock(&ocfs2_control_lock);
if (ocfs2_control_this_node < 0)
rc = -EINVAL;
else
rc = ocfs2_control_this_node;
mutex_unlock(&ocfs2_control_lock);
return rc;
}
static int ocfs2_control_do_setnode_msg(struct file *file,
struct ocfs2_control_message_setn *msg)
{
long nodenum;
char *ptr = NULL;
struct ocfs2_control_private *p = file->private_data;
if (ocfs2_control_get_handshake_state(file) !=
OCFS2_CONTROL_HANDSHAKE_PROTOCOL)
return -EINVAL;
if (strncmp(msg->tag, OCFS2_CONTROL_MESSAGE_SETNODE_OP,
OCFS2_CONTROL_MESSAGE_OP_LEN))
return -EINVAL;
if ((msg->space != ' ') || (msg->newline != '\n'))
return -EINVAL;
msg->space = msg->newline = '\0';
nodenum = simple_strtol(msg->nodestr, &ptr, 16);
if (!ptr || *ptr)
return -EINVAL;
if ((nodenum == LONG_MIN) || (nodenum == LONG_MAX) ||
(nodenum > INT_MAX) || (nodenum < 0))
return -ERANGE;
p->op_this_node = nodenum;
return ocfs2_control_install_private(file);
}
static int ocfs2_control_do_setversion_msg(struct file *file,
struct ocfs2_control_message_setv *msg)
{
long major, minor;
char *ptr = NULL;
struct ocfs2_control_private *p = file->private_data;
struct ocfs2_protocol_version *max =
&ocfs2_user_plugin.sp_max_proto;
if (ocfs2_control_get_handshake_state(file) !=
OCFS2_CONTROL_HANDSHAKE_PROTOCOL)
return -EINVAL;
if (strncmp(msg->tag, OCFS2_CONTROL_MESSAGE_SETVERSION_OP,
OCFS2_CONTROL_MESSAGE_OP_LEN))
return -EINVAL;
if ((msg->space1 != ' ') || (msg->space2 != ' ') ||
(msg->newline != '\n'))
return -EINVAL;
msg->space1 = msg->space2 = msg->newline = '\0';
major = simple_strtol(msg->major, &ptr, 16);
if (!ptr || *ptr)
return -EINVAL;
minor = simple_strtol(msg->minor, &ptr, 16);
if (!ptr || *ptr)
return -EINVAL;
if ((major == LONG_MIN) || (major == LONG_MAX) ||
(major > (u8)-1) || (major < 1))
return -ERANGE;
if ((minor == LONG_MIN) || (minor == LONG_MAX) ||
(minor > (u8)-1) || (minor < 0))
return -ERANGE;
if ((major != max->pv_major) ||
(minor > max->pv_minor))
return -EINVAL;
p->op_proto.pv_major = major;
p->op_proto.pv_minor = minor;
return ocfs2_control_install_private(file);
}
static int ocfs2_control_do_down_msg(struct file *file,
struct ocfs2_control_message_down *msg)
{
long nodenum;
char *p = NULL;
if (ocfs2_control_get_handshake_state(file) !=
OCFS2_CONTROL_HANDSHAKE_VALID)
return -EINVAL;
if (strncmp(msg->tag, OCFS2_CONTROL_MESSAGE_DOWN_OP,
OCFS2_CONTROL_MESSAGE_OP_LEN))
return -EINVAL;
if ((msg->space1 != ' ') || (msg->space2 != ' ') ||
(msg->newline != '\n'))
return -EINVAL;
msg->space1 = msg->space2 = msg->newline = '\0';
nodenum = simple_strtol(msg->nodestr, &p, 16);
if (!p || *p)
return -EINVAL;
if ((nodenum == LONG_MIN) || (nodenum == LONG_MAX) ||
(nodenum > INT_MAX) || (nodenum < 0))
return -ERANGE;
ocfs2_control_send_down(msg->uuid, nodenum);
return 0;
}
static ssize_t ocfs2_control_message(struct file *file,
const char __user *buf,
size_t count)
{
ssize_t ret;
union ocfs2_control_message msg;
WARN_ON(offsetof(struct ocfs2_control_message_down, uuid) !=
(sizeof(msg.u_down.tag) + sizeof(msg.u_down.space1)));
memset(&msg, 0, sizeof(union ocfs2_control_message));
ret = ocfs2_control_cfu(&msg, count, buf, count);
if (ret)
goto out;
if ((count == OCFS2_CONTROL_MESSAGE_SETNODE_TOTAL_LEN) &&
!strncmp(msg.tag, OCFS2_CONTROL_MESSAGE_SETNODE_OP,
OCFS2_CONTROL_MESSAGE_OP_LEN))
ret = ocfs2_control_do_setnode_msg(file, &msg.u_setn);
else if ((count == OCFS2_CONTROL_MESSAGE_SETVERSION_TOTAL_LEN) &&
!strncmp(msg.tag, OCFS2_CONTROL_MESSAGE_SETVERSION_OP,
OCFS2_CONTROL_MESSAGE_OP_LEN))
ret = ocfs2_control_do_setversion_msg(file, &msg.u_setv);
else if ((count == OCFS2_CONTROL_MESSAGE_DOWN_TOTAL_LEN) &&
!strncmp(msg.tag, OCFS2_CONTROL_MESSAGE_DOWN_OP,
OCFS2_CONTROL_MESSAGE_OP_LEN))
ret = ocfs2_control_do_down_msg(file, &msg.u_down);
else
ret = -EINVAL;
out:
return ret ? ret : count;
}
static ssize_t ocfs2_control_write(struct file *file,
const char __user *buf,
size_t count,
loff_t *ppos)
{
ssize_t ret;
switch (ocfs2_control_get_handshake_state(file)) {
case OCFS2_CONTROL_HANDSHAKE_INVALID:
ret = -EINVAL;
break;
case OCFS2_CONTROL_HANDSHAKE_READ:
ret = ocfs2_control_validate_protocol(file, buf,
count);
break;
case OCFS2_CONTROL_HANDSHAKE_PROTOCOL:
case OCFS2_CONTROL_HANDSHAKE_VALID:
ret = ocfs2_control_message(file, buf, count);
break;
default:
BUG();
ret = -EIO;
break;
}
return ret;
}
static ssize_t ocfs2_control_read(struct file *file,
char __user *buf,
size_t count,
loff_t *ppos)
{
ssize_t ret;
ret = simple_read_from_buffer(buf, count, ppos,
OCFS2_CONTROL_PROTO, OCFS2_CONTROL_PROTO_LEN);
if (ret > 0 && *ppos >= OCFS2_CONTROL_PROTO_LEN)
ocfs2_control_set_handshake_state(file,
OCFS2_CONTROL_HANDSHAKE_READ);
return ret;
}
static int ocfs2_control_release(struct inode *inode, struct file *file)
{
struct ocfs2_control_private *p = file->private_data;
mutex_lock(&ocfs2_control_lock);
if (ocfs2_control_get_handshake_state(file) !=
OCFS2_CONTROL_HANDSHAKE_VALID)
goto out;
if (atomic_dec_and_test(&ocfs2_control_opened)) {
if (!list_empty(&ocfs2_live_connection_list)) {
printk(KERN_ERR
"ocfs2: Unexpected release of ocfs2_control!\n"
" Loss of cluster connection requires "
"an emergency restart!\n");
emergency_restart();
}
ocfs2_control_this_node = -1;
running_proto.pv_major = 0;
running_proto.pv_minor = 0;
}
out:
list_del_init(&p->op_list);
file->private_data = NULL;
mutex_unlock(&ocfs2_control_lock);
kfree(p);
return 0;
}
static int ocfs2_control_open(struct inode *inode, struct file *file)
{
struct ocfs2_control_private *p;
p = kzalloc(sizeof(struct ocfs2_control_private), GFP_KERNEL);
if (!p)
return -ENOMEM;
p->op_this_node = -1;
mutex_lock(&ocfs2_control_lock);
file->private_data = p;
list_add(&p->op_list, &ocfs2_control_private_list);
mutex_unlock(&ocfs2_control_lock);
return 0;
}
static int ocfs2_control_init(void)
{
int rc;
atomic_set(&ocfs2_control_opened, 0);
rc = misc_register(&ocfs2_control_device);
if (rc)
printk(KERN_ERR
"ocfs2: Unable to register ocfs2_control device "
"(errno %d)\n",
-rc);
return rc;
}
static void ocfs2_control_exit(void)
{
misc_deregister(&ocfs2_control_device);
}
static void fsdlm_lock_ast_wrapper(void *astarg)
{
struct ocfs2_dlm_lksb *lksb = astarg;
int status = lksb->lksb_fsdlm.sb_status;
if (status == -DLM_EUNLOCK || status == -DLM_ECANCEL)
lksb->lksb_conn->cc_proto->lp_unlock_ast(lksb, 0);
else
lksb->lksb_conn->cc_proto->lp_lock_ast(lksb);
}
static void fsdlm_blocking_ast_wrapper(void *astarg, int level)
{
struct ocfs2_dlm_lksb *lksb = astarg;
lksb->lksb_conn->cc_proto->lp_blocking_ast(lksb, level);
}
static int user_dlm_lock(struct ocfs2_cluster_connection *conn,
int mode,
struct ocfs2_dlm_lksb *lksb,
u32 flags,
void *name,
unsigned int namelen)
{
int ret;
if (!lksb->lksb_fsdlm.sb_lvbptr)
lksb->lksb_fsdlm.sb_lvbptr = (char *)lksb +
sizeof(struct dlm_lksb);
ret = dlm_lock(conn->cc_lockspace, mode, &lksb->lksb_fsdlm,
flags|DLM_LKF_NODLCKWT, name, namelen, 0,
fsdlm_lock_ast_wrapper, lksb,
fsdlm_blocking_ast_wrapper);
return ret;
}
static int user_dlm_unlock(struct ocfs2_cluster_connection *conn,
struct ocfs2_dlm_lksb *lksb,
u32 flags)
{
int ret;
ret = dlm_unlock(conn->cc_lockspace, lksb->lksb_fsdlm.sb_lkid,
flags, &lksb->lksb_fsdlm, lksb);
return ret;
}
static int user_dlm_lock_status(struct ocfs2_dlm_lksb *lksb)
{
return lksb->lksb_fsdlm.sb_status;
}
static int user_dlm_lvb_valid(struct ocfs2_dlm_lksb *lksb)
{
int invalid = lksb->lksb_fsdlm.sb_flags & DLM_SBF_VALNOTVALID;
return !invalid;
}
static void *user_dlm_lvb(struct ocfs2_dlm_lksb *lksb)
{
if (!lksb->lksb_fsdlm.sb_lvbptr)
lksb->lksb_fsdlm.sb_lvbptr = (char *)lksb +
sizeof(struct dlm_lksb);
return (void *)(lksb->lksb_fsdlm.sb_lvbptr);
}
static void user_dlm_dump_lksb(struct ocfs2_dlm_lksb *lksb)
{
}
static int user_plock(struct ocfs2_cluster_connection *conn,
u64 ino,
struct file *file,
int cmd,
struct file_lock *fl)
{
if (cmd == F_CANCELLK) {
cmd = F_SETLK;
fl->fl_type = F_UNLCK;
}
if (IS_GETLK(cmd))
return dlm_posix_get(conn->cc_lockspace, ino, file, fl);
else if (fl->fl_type == F_UNLCK)
return dlm_posix_unlock(conn->cc_lockspace, ino, file, fl);
else
return dlm_posix_lock(conn->cc_lockspace, ino, file, cmd, fl);
}
static int fs_protocol_compare(struct ocfs2_protocol_version *existing,
struct ocfs2_protocol_version *request)
{
if (existing->pv_major != request->pv_major)
return 1;
if (existing->pv_minor > request->pv_minor)
return 1;
if (existing->pv_minor < request->pv_minor)
request->pv_minor = existing->pv_minor;
return 0;
}
static void lvb_to_version(char *lvb, struct ocfs2_protocol_version *ver)
{
struct ocfs2_protocol_version *pv =
(struct ocfs2_protocol_version *)lvb;
ver->pv_major = pv->pv_major;
ver->pv_minor = pv->pv_minor;
}
static void version_to_lvb(struct ocfs2_protocol_version *ver, char *lvb)
{
struct ocfs2_protocol_version *pv =
(struct ocfs2_protocol_version *)lvb;
pv->pv_major = ver->pv_major;
pv->pv_minor = ver->pv_minor;
}
static void sync_wait_cb(void *arg)
{
struct ocfs2_cluster_connection *conn = arg;
struct ocfs2_live_connection *lc = conn->cc_private;
complete(&lc->oc_sync_wait);
}
static int sync_unlock(struct ocfs2_cluster_connection *conn,
struct dlm_lksb *lksb, char *name)
{
int error;
struct ocfs2_live_connection *lc = conn->cc_private;
error = dlm_unlock(conn->cc_lockspace, lksb->sb_lkid, 0, lksb, conn);
if (error) {
printk(KERN_ERR "%s lkid %x error %d\n",
name, lksb->sb_lkid, error);
return error;
}
wait_for_completion(&lc->oc_sync_wait);
if (lksb->sb_status != -DLM_EUNLOCK) {
printk(KERN_ERR "%s lkid %x status %d\n",
name, lksb->sb_lkid, lksb->sb_status);
return -1;
}
return 0;
}
static int sync_lock(struct ocfs2_cluster_connection *conn,
int mode, uint32_t flags,
struct dlm_lksb *lksb, char *name)
{
int error, status;
struct ocfs2_live_connection *lc = conn->cc_private;
error = dlm_lock(conn->cc_lockspace, mode, lksb, flags,
name, strlen(name),
0, sync_wait_cb, conn, NULL);
if (error) {
printk(KERN_ERR "%s lkid %x flags %x mode %d error %d\n",
name, lksb->sb_lkid, flags, mode, error);
return error;
}
wait_for_completion(&lc->oc_sync_wait);
status = lksb->sb_status;
if (status && status != -EAGAIN) {
printk(KERN_ERR "%s lkid %x flags %x mode %d status %d\n",
name, lksb->sb_lkid, flags, mode, status);
}
return status;
}
static int version_lock(struct ocfs2_cluster_connection *conn, int mode,
int flags)
{
struct ocfs2_live_connection *lc = conn->cc_private;
return sync_lock(conn, mode, flags,
&lc->oc_version_lksb, VERSION_LOCK);
}
static int version_unlock(struct ocfs2_cluster_connection *conn)
{
struct ocfs2_live_connection *lc = conn->cc_private;
return sync_unlock(conn, &lc->oc_version_lksb, VERSION_LOCK);
}
static int get_protocol_version(struct ocfs2_cluster_connection *conn)
{
int ret;
struct ocfs2_live_connection *lc = conn->cc_private;
struct ocfs2_protocol_version pv;
running_proto.pv_major =
ocfs2_user_plugin.sp_max_proto.pv_major;
running_proto.pv_minor =
ocfs2_user_plugin.sp_max_proto.pv_minor;
lc->oc_version_lksb.sb_lvbptr = lc->oc_lvb;
ret = version_lock(conn, DLM_LOCK_EX,
DLM_LKF_VALBLK|DLM_LKF_NOQUEUE);
if (!ret) {
conn->cc_version.pv_major = running_proto.pv_major;
conn->cc_version.pv_minor = running_proto.pv_minor;
version_to_lvb(&running_proto, lc->oc_lvb);
version_lock(conn, DLM_LOCK_PR, DLM_LKF_CONVERT|DLM_LKF_VALBLK);
} else if (ret == -EAGAIN) {
ret = version_lock(conn, DLM_LOCK_PR, DLM_LKF_VALBLK);
if (ret)
goto out;
lvb_to_version(lc->oc_lvb, &pv);
if ((pv.pv_major != running_proto.pv_major) ||
(pv.pv_minor > running_proto.pv_minor)) {
ret = -EINVAL;
goto out;
}
conn->cc_version.pv_major = pv.pv_major;
conn->cc_version.pv_minor = pv.pv_minor;
}
out:
return ret;
}
static void user_recover_prep(void *arg)
{
}
static void user_recover_slot(void *arg, struct dlm_slot *slot)
{
struct ocfs2_cluster_connection *conn = arg;
printk(KERN_INFO "ocfs2: Node %d/%d down. Initiating recovery.\n",
slot->nodeid, slot->slot);
conn->cc_recovery_handler(slot->nodeid, conn->cc_recovery_data);
}
static void user_recover_done(void *arg, struct dlm_slot *slots,
int num_slots, int our_slot,
uint32_t generation)
{
struct ocfs2_cluster_connection *conn = arg;
struct ocfs2_live_connection *lc = conn->cc_private;
int i;
for (i = 0; i < num_slots; i++)
if (slots[i].slot == our_slot) {
atomic_set(&lc->oc_this_node, slots[i].nodeid);
break;
}
lc->oc_our_slot = our_slot;
wake_up(&lc->oc_wait);
}
static int user_cluster_disconnect(struct ocfs2_cluster_connection *conn)
{
version_unlock(conn);
dlm_release_lockspace(conn->cc_lockspace, 2);
conn->cc_lockspace = NULL;
ocfs2_live_connection_drop(conn->cc_private);
conn->cc_private = NULL;
return 0;
}
static int user_cluster_connect(struct ocfs2_cluster_connection *conn)
{
dlm_lockspace_t *fsdlm;
struct ocfs2_live_connection *lc;
int rc, ops_rv;
BUG_ON(conn == NULL);
lc = kzalloc(sizeof(struct ocfs2_live_connection), GFP_KERNEL);
if (!lc)
return -ENOMEM;
init_waitqueue_head(&lc->oc_wait);
init_completion(&lc->oc_sync_wait);
atomic_set(&lc->oc_this_node, 0);
conn->cc_private = lc;
lc->oc_type = NO_CONTROLD;
rc = dlm_new_lockspace(conn->cc_name, conn->cc_cluster_name,
DLM_LSFL_FS, DLM_LVB_LEN,
&ocfs2_ls_ops, conn, &ops_rv, &fsdlm);
if (rc)
goto out;
if (ops_rv == -EOPNOTSUPP) {
lc->oc_type = WITH_CONTROLD;
printk(KERN_NOTICE "ocfs2: You seem to be using an older "
"version of dlm_controld and/or ocfs2-tools."
" Please consider upgrading.\n");
} else if (ops_rv) {
rc = ops_rv;
goto out;
}
conn->cc_lockspace = fsdlm;
rc = ocfs2_live_connection_attach(conn, lc);
if (rc)
goto out;
if (lc->oc_type == NO_CONTROLD) {
rc = get_protocol_version(conn);
if (rc) {
printk(KERN_ERR "ocfs2: Could not determine"
" locking version\n");
user_cluster_disconnect(conn);
goto out;
}
wait_event(lc->oc_wait, (atomic_read(&lc->oc_this_node) > 0));
}
if (fs_protocol_compare(&running_proto, &conn->cc_version)) {
printk(KERN_ERR
"Unable to mount with fs locking protocol version "
"%u.%u because negotiated protocol is %u.%u\n",
conn->cc_version.pv_major, conn->cc_version.pv_minor,
running_proto.pv_major, running_proto.pv_minor);
rc = -EPROTO;
ocfs2_live_connection_drop(lc);
lc = NULL;
}
out:
if (rc)
kfree(lc);
return rc;
}
static int user_cluster_this_node(struct ocfs2_cluster_connection *conn,
unsigned int *this_node)
{
int rc;
struct ocfs2_live_connection *lc = conn->cc_private;
if (lc->oc_type == WITH_CONTROLD)
rc = ocfs2_control_get_this_node();
else if (lc->oc_type == NO_CONTROLD)
rc = atomic_read(&lc->oc_this_node);
else
rc = -EINVAL;
if (rc < 0)
return rc;
*this_node = rc;
return 0;
}
static int __init ocfs2_user_plugin_init(void)
{
int rc;
rc = ocfs2_control_init();
if (!rc) {
rc = ocfs2_stack_glue_register(&ocfs2_user_plugin);
if (rc)
ocfs2_control_exit();
}
return rc;
}
static void __exit ocfs2_user_plugin_exit(void)
{
ocfs2_stack_glue_unregister(&ocfs2_user_plugin);
ocfs2_control_exit();
}
