static inline int mode_to_o2dlm(int mode)
{
BUG_ON(mode > LKM_MAXMODE);
return mode;
}
static int flags_to_o2dlm(u32 flags)
{
int o2dlm_flags = 0;
map_flag(DLM_LKF_NOQUEUE, LKM_NOQUEUE);
map_flag(DLM_LKF_CANCEL, LKM_CANCEL);
map_flag(DLM_LKF_CONVERT, LKM_CONVERT);
map_flag(DLM_LKF_VALBLK, LKM_VALBLK);
map_flag(DLM_LKF_IVVALBLK, LKM_INVVALBLK);
map_flag(DLM_LKF_ORPHAN, LKM_ORPHAN);
map_flag(DLM_LKF_FORCEUNLOCK, LKM_FORCE);
map_flag(DLM_LKF_TIMEOUT, LKM_TIMEOUT);
map_flag(DLM_LKF_LOCAL, LKM_LOCAL);
BUG_ON(flags != 0);
return o2dlm_flags;
}
static int dlm_status_to_errno(enum dlm_status status)
{
BUG_ON(status < 0 || status >= ARRAY_SIZE(status_map));
return status_map[status];
}
static void o2dlm_lock_ast_wrapper(void *astarg)
{
struct ocfs2_dlm_lksb *lksb = astarg;
lksb->lksb_conn->cc_proto->lp_lock_ast(lksb);
}
static void o2dlm_blocking_ast_wrapper(void *astarg, int level)
{
struct ocfs2_dlm_lksb *lksb = astarg;
lksb->lksb_conn->cc_proto->lp_blocking_ast(lksb, level);
}
static void o2dlm_unlock_ast_wrapper(void *astarg, enum dlm_status status)
{
struct ocfs2_dlm_lksb *lksb = astarg;
int error = dlm_status_to_errno(status);
if (status == DLM_CANCELGRANT)
return;
lksb->lksb_conn->cc_proto->lp_unlock_ast(lksb, error);
}
static int o2cb_dlm_lock(struct ocfs2_cluster_connection *conn,
int mode,
struct ocfs2_dlm_lksb *lksb,
u32 flags,
void *name,
unsigned int namelen)
{
enum dlm_status status;
int o2dlm_mode = mode_to_o2dlm(mode);
int o2dlm_flags = flags_to_o2dlm(flags);
int ret;
status = dlmlock(conn->cc_lockspace, o2dlm_mode, &lksb->lksb_o2dlm,
o2dlm_flags, name, namelen,
o2dlm_lock_ast_wrapper, lksb,
o2dlm_blocking_ast_wrapper);
ret = dlm_status_to_errno(status);
return ret;
}
static int o2cb_dlm_unlock(struct ocfs2_cluster_connection *conn,
struct ocfs2_dlm_lksb *lksb,
u32 flags)
{
enum dlm_status status;
int o2dlm_flags = flags_to_o2dlm(flags);
int ret;
status = dlmunlock(conn->cc_lockspace, &lksb->lksb_o2dlm,
o2dlm_flags, o2dlm_unlock_ast_wrapper, lksb);
ret = dlm_status_to_errno(status);
return ret;
}
static int o2cb_dlm_lock_status(struct ocfs2_dlm_lksb *lksb)
{
return dlm_status_to_errno(lksb->lksb_o2dlm.status);
}
static int o2cb_dlm_lvb_valid(struct ocfs2_dlm_lksb *lksb)
{
return 1;
}
static void *o2cb_dlm_lvb(struct ocfs2_dlm_lksb *lksb)
{
return (void *)(lksb->lksb_o2dlm.lvb);
}
static void o2cb_dump_lksb(struct ocfs2_dlm_lksb *lksb)
{
dlm_print_one_lock(lksb->lksb_o2dlm.lockid);
}
static int o2cb_cluster_check(void)
{
u8 node_num;
int i;
unsigned long hbmap[BITS_TO_LONGS(O2NM_MAX_NODES)];
unsigned long netmap[BITS_TO_LONGS(O2NM_MAX_NODES)];
node_num = o2nm_this_node();
if (node_num == O2NM_MAX_NODES) {
printk(KERN_ERR "o2cb: This node has not been configured.\n");
return -EINVAL;
}
#define O2CB_MAP_STABILIZE_COUNT 60
for (i = 0; i < O2CB_MAP_STABILIZE_COUNT; ++i) {
o2hb_fill_node_map(hbmap, sizeof(hbmap));
if (!test_bit(node_num, hbmap)) {
printk(KERN_ERR "o2cb: %s heartbeat has not been "
"started.\n", (o2hb_global_heartbeat_active() ?
"Global" : "Local"));
return -EINVAL;
}
o2net_fill_node_map(netmap, sizeof(netmap));
set_bit(node_num, netmap);
if (!memcmp(hbmap, netmap, sizeof(hbmap)))
return 0;
if (i < O2CB_MAP_STABILIZE_COUNT)
msleep(1000);
}
printk(KERN_ERR "o2cb: This node could not connect to nodes:");
i = -1;
while ((i = find_next_bit(hbmap, O2NM_MAX_NODES,
i + 1)) < O2NM_MAX_NODES) {
if (!test_bit(i, netmap))
printk(" %u", i);
}
printk(".\n");
return -ENOTCONN;
}
static void o2dlm_eviction_cb(int node_num, void *data)
{
struct ocfs2_cluster_connection *conn = data;
printk(KERN_NOTICE "o2cb: o2dlm has evicted node %d from domain %.*s\n",
node_num, conn->cc_namelen, conn->cc_name);
conn->cc_recovery_handler(node_num, conn->cc_recovery_data);
}
static int o2cb_cluster_connect(struct ocfs2_cluster_connection *conn)
{
int rc = 0;
u32 dlm_key;
struct dlm_ctxt *dlm;
struct o2dlm_private *priv;
struct dlm_protocol_version fs_version;
BUG_ON(conn == NULL);
BUG_ON(conn->cc_proto == NULL);
rc = o2cb_cluster_check();
if (rc) {
printk(KERN_ERR "o2cb: Cluster check failed. Fix errors "
"before retrying.\n");
goto out;
}
priv = kzalloc(sizeof(struct o2dlm_private), GFP_KERNEL);
if (!priv) {
rc = -ENOMEM;
goto out_free;
}
dlm_setup_eviction_cb(&priv->op_eviction_cb, o2dlm_eviction_cb,
conn);
conn->cc_private = priv;
dlm_key = crc32_le(0, conn->cc_name, conn->cc_namelen);
fs_version.pv_major = conn->cc_version.pv_major;
fs_version.pv_minor = conn->cc_version.pv_minor;
dlm = dlm_register_domain(conn->cc_name, dlm_key, &fs_version);
if (IS_ERR(dlm)) {
rc = PTR_ERR(dlm);
mlog_errno(rc);
goto out_free;
}
conn->cc_version.pv_major = fs_version.pv_major;
conn->cc_version.pv_minor = fs_version.pv_minor;
conn->cc_lockspace = dlm;
dlm_register_eviction_cb(dlm, &priv->op_eviction_cb);
out_free:
if (rc)
kfree(conn->cc_private);
out:
return rc;
}
static int o2cb_cluster_disconnect(struct ocfs2_cluster_connection *conn)
{
struct dlm_ctxt *dlm = conn->cc_lockspace;
struct o2dlm_private *priv = conn->cc_private;
dlm_unregister_eviction_cb(&priv->op_eviction_cb);
conn->cc_private = NULL;
kfree(priv);
dlm_unregister_domain(dlm);
conn->cc_lockspace = NULL;
return 0;
}
static int o2cb_cluster_this_node(unsigned int *node)
{
int node_num;
node_num = o2nm_this_node();
if (node_num == O2NM_INVALID_NODE_NUM)
return -ENOENT;
if (node_num >= O2NM_MAX_NODES)
return -EOVERFLOW;
*node = node_num;
return 0;
}
static int __init o2cb_stack_init(void)
{
return ocfs2_stack_glue_register(&o2cb_stack);
}
static void __exit o2cb_stack_exit(void)
{
ocfs2_stack_glue_unregister(&o2cb_stack);
}
