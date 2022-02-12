int configfs_is_root(struct config_item *item)
{
return item == &configfs_root_group.cg_item;
}
static int configfs_fill_super(struct super_block *sb, void *data, int silent)
{
struct inode *inode;
struct dentry *root;
sb->s_blocksize = PAGE_SIZE;
sb->s_blocksize_bits = PAGE_SHIFT;
sb->s_magic = CONFIGFS_MAGIC;
sb->s_op = &configfs_ops;
sb->s_time_gran = 1;
inode = configfs_new_inode(S_IFDIR | S_IRWXU | S_IRUGO | S_IXUGO,
&configfs_root, sb);
if (inode) {
inode->i_op = &configfs_root_inode_operations;
inode->i_fop = &configfs_dir_operations;
inc_nlink(inode);
} else {
pr_debug("could not get root inode\n");
return -ENOMEM;
}
root = d_make_root(inode);
if (!root) {
pr_debug("%s: could not get root dentry!\n",__func__);
return -ENOMEM;
}
config_group_init(&configfs_root_group);
configfs_root_group.cg_item.ci_dentry = root;
root->d_fsdata = &configfs_root;
sb->s_root = root;
sb->s_d_op = &configfs_dentry_ops;
return 0;
}
static struct dentry *configfs_do_mount(struct file_system_type *fs_type,
int flags, const char *dev_name, void *data)
{
return mount_single(fs_type, flags, data, configfs_fill_super);
}
struct dentry *configfs_pin_fs(void)
{
int err = simple_pin_fs(&configfs_fs_type, &configfs_mount,
&configfs_mnt_count);
return err ? ERR_PTR(err) : configfs_mount->mnt_root;
}
void configfs_release_fs(void)
{
simple_release_fs(&configfs_mount, &configfs_mnt_count);
}
static int __init configfs_init(void)
{
int err = -ENOMEM;
configfs_dir_cachep = kmem_cache_create("configfs_dir_cache",
sizeof(struct configfs_dirent),
0, 0, NULL);
if (!configfs_dir_cachep)
goto out;
err = sysfs_create_mount_point(kernel_kobj, "config");
if (err)
goto out2;
err = register_filesystem(&configfs_fs_type);
if (err)
goto out3;
return 0;
out3:
pr_err("Unable to register filesystem!\n");
sysfs_remove_mount_point(kernel_kobj, "config");
out2:
kmem_cache_destroy(configfs_dir_cachep);
configfs_dir_cachep = NULL;
out:
return err;
}
static void __exit configfs_exit(void)
{
unregister_filesystem(&configfs_fs_type);
sysfs_remove_mount_point(kernel_kobj, "config");
kmem_cache_destroy(configfs_dir_cachep);
configfs_dir_cachep = NULL;
}
