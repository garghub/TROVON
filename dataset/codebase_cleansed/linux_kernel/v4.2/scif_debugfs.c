static int scif_dev_test(struct seq_file *s, void *unused)
{
int node;
seq_printf(s, "Total Nodes %d Self Node Id %d Maxid %d\n",
scif_info.total, scif_info.nodeid,
scif_info.maxid);
if (!scif_dev)
return 0;
seq_printf(s, "%-16s\t%-16s\n", "node_id", "state");
for (node = 0; node <= scif_info.maxid; node++)
seq_printf(s, "%-16d\t%-16s\n", scif_dev[node].node,
_scifdev_alive(&scif_dev[node]) ?
"Running" : "Offline");
return 0;
}
static int scif_dev_test_open(struct inode *inode, struct file *file)
{
return single_open(file, scif_dev_test, inode->i_private);
}
static int scif_dev_test_release(struct inode *inode, struct file *file)
{
return single_release(inode, file);
}
void __init scif_init_debugfs(void)
{
struct dentry *d;
scif_dbg = debugfs_create_dir(KBUILD_MODNAME, NULL);
if (!scif_dbg) {
dev_err(scif_info.mdev.this_device,
"can't create debugfs dir scif\n");
return;
}
d = debugfs_create_file("scif_dev", 0444, scif_dbg,
NULL, &scif_dev_ops);
debugfs_create_u8("en_msg_log", 0666, scif_dbg, &scif_info.en_msg_log);
debugfs_create_u8("p2p_enable", 0666, scif_dbg, &scif_info.p2p_enable);
}
void scif_exit_debugfs(void)
{
debugfs_remove_recursive(scif_dbg);
}
