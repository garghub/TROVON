static ssize_t usnic_debugfs_buildinfo_read(struct file *f, char __user *data,
size_t count, loff_t *ppos)
{
char buf[500];
int res;
if (*ppos > 0)
return 0;
res = scnprintf(buf, sizeof(buf),
"version: %s\n"
"build date: %s\n",
DRV_VERSION, DRV_RELDATE);
return simple_read_from_buffer(data, count, ppos, buf, res);
}
static ssize_t flowinfo_read(struct file *f, char __user *data,
size_t count, loff_t *ppos)
{
struct usnic_ib_qp_grp_flow *qp_flow;
int n;
int left;
char *ptr;
char buf[512];
qp_flow = f->private_data;
ptr = buf;
left = count;
if (*ppos > 0)
return 0;
spin_lock(&qp_flow->qp_grp->lock);
n = scnprintf(ptr, left,
"QP Grp ID: %d Transport: %s ",
qp_flow->qp_grp->grp_id,
usnic_transport_to_str(qp_flow->trans_type));
UPDATE_PTR_LEFT(n, ptr, left);
if (qp_flow->trans_type == USNIC_TRANSPORT_ROCE_CUSTOM) {
n = scnprintf(ptr, left, "Port_Num:%hu\n",
qp_flow->usnic_roce.port_num);
UPDATE_PTR_LEFT(n, ptr, left);
} else if (qp_flow->trans_type == USNIC_TRANSPORT_IPV4_UDP) {
n = usnic_transport_sock_to_str(ptr, left,
qp_flow->udp.sock);
UPDATE_PTR_LEFT(n, ptr, left);
n = scnprintf(ptr, left, "\n");
UPDATE_PTR_LEFT(n, ptr, left);
}
spin_unlock(&qp_flow->qp_grp->lock);
return simple_read_from_buffer(data, count, ppos, buf, ptr - buf);
}
void usnic_debugfs_init(void)
{
debugfs_root = debugfs_create_dir(DRV_NAME, NULL);
if (IS_ERR(debugfs_root)) {
usnic_err("Failed to create debugfs root dir, check if debugfs is enabled in kernel configuration\n");
goto out_clear_root;
}
flows_dentry = debugfs_create_dir("flows", debugfs_root);
if (IS_ERR_OR_NULL(flows_dentry)) {
usnic_err("Failed to create debugfs flow dir with err %ld\n",
PTR_ERR(flows_dentry));
goto out_free_root;
}
debugfs_create_file("build-info", S_IRUGO, debugfs_root,
NULL, &usnic_debugfs_buildinfo_ops);
return;
out_free_root:
debugfs_remove_recursive(debugfs_root);
out_clear_root:
debugfs_root = NULL;
}
void usnic_debugfs_exit(void)
{
if (!debugfs_root)
return;
debugfs_remove_recursive(debugfs_root);
debugfs_root = NULL;
}
void usnic_debugfs_flow_add(struct usnic_ib_qp_grp_flow *qp_flow)
{
if (IS_ERR_OR_NULL(flows_dentry))
return;
scnprintf(qp_flow->dentry_name, sizeof(qp_flow->dentry_name),
"%u", qp_flow->flow->flow_id);
qp_flow->dbgfs_dentry = debugfs_create_file(qp_flow->dentry_name,
S_IRUGO,
flows_dentry,
qp_flow,
&flowinfo_ops);
if (IS_ERR_OR_NULL(qp_flow->dbgfs_dentry)) {
usnic_err("Failed to create dbg fs entry for flow %u\n",
qp_flow->flow->flow_id);
}
}
void usnic_debugfs_flow_remove(struct usnic_ib_qp_grp_flow *qp_flow)
{
if (!IS_ERR_OR_NULL(qp_flow->dbgfs_dentry))
debugfs_remove(qp_flow->dbgfs_dentry);
}
