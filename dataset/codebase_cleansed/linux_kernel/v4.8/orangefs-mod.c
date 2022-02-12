static int __init orangefs_init(void)
{
int ret = -1;
__u32 i = 0;
gossip_debug_mask = (unsigned long long) module_parm_debug_mask;
debug_mask_to_string(&gossip_debug_mask, 0);
debug_string_to_mask(kernel_debug_string, &gossip_debug_mask, 0);
if (gossip_debug_mask != 0)
kernel_mask_set_mod_init = true;
pr_info("%s: called with debug mask: :%s: :%llx:\n",
__func__,
kernel_debug_string,
(unsigned long long)gossip_debug_mask);
ret = bdi_init(&orangefs_backing_dev_info);
if (ret)
return ret;
if (op_timeout_secs < 0)
op_timeout_secs = 0;
if (slot_timeout_secs < 0)
slot_timeout_secs = 0;
ret = op_cache_initialize();
if (ret < 0)
goto err;
ret = orangefs_inode_cache_initialize();
if (ret < 0)
goto cleanup_op;
htable_ops_in_progress =
kcalloc(hash_table_size, sizeof(struct list_head), GFP_KERNEL);
if (!htable_ops_in_progress) {
gossip_err("Failed to initialize op hashtable");
ret = -ENOMEM;
goto cleanup_inode;
}
for (i = 0; i < hash_table_size; i++)
INIT_LIST_HEAD(&htable_ops_in_progress[i]);
ret = fsid_key_table_initialize();
if (ret < 0)
goto cleanup_progress_table;
ret = orangefs_prepare_debugfs_help_string(1);
if (ret)
goto cleanup_key_table;
ret = orangefs_debugfs_init();
if (ret)
goto debugfs_init_failed;
ret = orangefs_kernel_debug_init();
if (ret)
goto kernel_debug_init_failed;
ret = orangefs_sysfs_init();
if (ret)
goto sysfs_init_failed;
ret = orangefs_dev_init();
if (ret < 0) {
gossip_err("%s: could not initialize device subsystem %d!\n",
__func__,
ret);
goto cleanup_device;
}
ret = register_filesystem(&orangefs_fs_type);
if (ret == 0) {
pr_info("orangefs: module version %s loaded\n", ORANGEFS_VERSION);
ret = 0;
goto out;
}
orangefs_sysfs_exit();
cleanup_device:
orangefs_dev_cleanup();
sysfs_init_failed:
kernel_debug_init_failed:
debugfs_init_failed:
orangefs_debugfs_cleanup();
cleanup_key_table:
fsid_key_table_finalize();
cleanup_progress_table:
kfree(htable_ops_in_progress);
cleanup_inode:
orangefs_inode_cache_finalize();
cleanup_op:
op_cache_finalize();
err:
bdi_destroy(&orangefs_backing_dev_info);
out:
return ret;
}
static void __exit orangefs_exit(void)
{
int i = 0;
gossip_debug(GOSSIP_INIT_DEBUG, "orangefs: orangefs_exit called\n");
unregister_filesystem(&orangefs_fs_type);
orangefs_debugfs_cleanup();
orangefs_sysfs_exit();
fsid_key_table_finalize();
orangefs_dev_cleanup();
BUG_ON(!list_empty(&orangefs_request_list));
for (i = 0; i < hash_table_size; i++)
BUG_ON(!list_empty(&htable_ops_in_progress[i]));
orangefs_inode_cache_finalize();
op_cache_finalize();
kfree(htable_ops_in_progress);
bdi_destroy(&orangefs_backing_dev_info);
pr_info("orangefs: module version %s unloaded\n", ORANGEFS_VERSION);
}
void purge_inprogress_ops(void)
{
int i;
for (i = 0; i < hash_table_size; i++) {
struct orangefs_kernel_op_s *op;
struct orangefs_kernel_op_s *next;
spin_lock(&htable_ops_in_progress_lock);
list_for_each_entry_safe(op,
next,
&htable_ops_in_progress[i],
list) {
set_op_state_purged(op);
gossip_debug(GOSSIP_DEV_DEBUG,
"%s: op:%s: op_state:%d: process:%s:\n",
__func__,
get_opname_string(op),
op->op_state,
current->comm);
}
spin_unlock(&htable_ops_in_progress_lock);
}
}
