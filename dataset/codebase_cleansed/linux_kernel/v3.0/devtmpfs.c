static int __init mount_param(char *str)
{
mount_dev = simple_strtoul(str, NULL, 0);
return 1;
}
static struct dentry *dev_mount(struct file_system_type *fs_type, int flags,
const char *dev_name, void *data)
{
#ifdef CONFIG_TMPFS
return mount_single(fs_type, flags, data, shmem_fill_super);
#else
return mount_single(fs_type, flags, data, ramfs_fill_super);
#endif
}
static inline int is_blockdev(struct device *dev)
{
return dev->class == &block_class;
}
static inline int is_blockdev(struct device *dev) { return 0; }
static int dev_mkdir(const char *name, mode_t mode)
{
struct nameidata nd;
struct dentry *dentry;
int err;
err = vfs_path_lookup(dev_mnt->mnt_root, dev_mnt,
name, LOOKUP_PARENT, &nd);
if (err)
return err;
dentry = lookup_create(&nd, 1);
if (!IS_ERR(dentry)) {
err = vfs_mkdir(nd.path.dentry->d_inode, dentry, mode);
if (!err)
dentry->d_inode->i_private = &dev_mnt;
dput(dentry);
} else {
err = PTR_ERR(dentry);
}
mutex_unlock(&nd.path.dentry->d_inode->i_mutex);
path_put(&nd.path);
return err;
}
static int create_path(const char *nodepath)
{
int err;
mutex_lock(&dirlock);
err = dev_mkdir(nodepath, 0755);
if (err == -ENOENT) {
char *path;
char *s;
path = kstrdup(nodepath, GFP_KERNEL);
if (!path) {
err = -ENOMEM;
goto out;
}
s = path;
for (;;) {
s = strchr(s, '/');
if (!s)
break;
s[0] = '\0';
err = dev_mkdir(path, 0755);
if (err && err != -EEXIST)
break;
s[0] = '/';
s++;
}
kfree(path);
}
out:
mutex_unlock(&dirlock);
return err;
}
int devtmpfs_create_node(struct device *dev)
{
const char *tmp = NULL;
const char *nodename;
const struct cred *curr_cred;
mode_t mode = 0;
struct nameidata nd;
struct dentry *dentry;
int err;
if (!dev_mnt)
return 0;
nodename = device_get_devnode(dev, &mode, &tmp);
if (!nodename)
return -ENOMEM;
if (mode == 0)
mode = 0600;
if (is_blockdev(dev))
mode |= S_IFBLK;
else
mode |= S_IFCHR;
curr_cred = override_creds(&init_cred);
err = vfs_path_lookup(dev_mnt->mnt_root, dev_mnt,
nodename, LOOKUP_PARENT, &nd);
if (err == -ENOENT) {
create_path(nodename);
err = vfs_path_lookup(dev_mnt->mnt_root, dev_mnt,
nodename, LOOKUP_PARENT, &nd);
}
if (err)
goto out;
dentry = lookup_create(&nd, 0);
if (!IS_ERR(dentry)) {
err = vfs_mknod(nd.path.dentry->d_inode,
dentry, mode, dev->devt);
if (!err) {
struct iattr newattrs;
newattrs.ia_mode = mode;
newattrs.ia_valid = ATTR_MODE;
mutex_lock(&dentry->d_inode->i_mutex);
notify_change(dentry, &newattrs);
mutex_unlock(&dentry->d_inode->i_mutex);
dentry->d_inode->i_private = &dev_mnt;
}
dput(dentry);
} else {
err = PTR_ERR(dentry);
}
mutex_unlock(&nd.path.dentry->d_inode->i_mutex);
path_put(&nd.path);
out:
kfree(tmp);
revert_creds(curr_cred);
return err;
}
static int dev_rmdir(const char *name)
{
struct nameidata nd;
struct dentry *dentry;
int err;
err = vfs_path_lookup(dev_mnt->mnt_root, dev_mnt,
name, LOOKUP_PARENT, &nd);
if (err)
return err;
mutex_lock_nested(&nd.path.dentry->d_inode->i_mutex, I_MUTEX_PARENT);
dentry = lookup_one_len(nd.last.name, nd.path.dentry, nd.last.len);
if (!IS_ERR(dentry)) {
if (dentry->d_inode) {
if (dentry->d_inode->i_private == &dev_mnt)
err = vfs_rmdir(nd.path.dentry->d_inode,
dentry);
else
err = -EPERM;
} else {
err = -ENOENT;
}
dput(dentry);
} else {
err = PTR_ERR(dentry);
}
mutex_unlock(&nd.path.dentry->d_inode->i_mutex);
path_put(&nd.path);
return err;
}
static int delete_path(const char *nodepath)
{
const char *path;
int err = 0;
path = kstrdup(nodepath, GFP_KERNEL);
if (!path)
return -ENOMEM;
mutex_lock(&dirlock);
for (;;) {
char *base;
base = strrchr(path, '/');
if (!base)
break;
base[0] = '\0';
err = dev_rmdir(path);
if (err)
break;
}
mutex_unlock(&dirlock);
kfree(path);
return err;
}
static int dev_mynode(struct device *dev, struct inode *inode, struct kstat *stat)
{
if (inode->i_private != &dev_mnt)
return 0;
if (is_blockdev(dev)) {
if (!S_ISBLK(stat->mode))
return 0;
} else {
if (!S_ISCHR(stat->mode))
return 0;
}
if (stat->rdev != dev->devt)
return 0;
return 1;
}
int devtmpfs_delete_node(struct device *dev)
{
const char *tmp = NULL;
const char *nodename;
const struct cred *curr_cred;
struct nameidata nd;
struct dentry *dentry;
struct kstat stat;
int deleted = 1;
int err;
if (!dev_mnt)
return 0;
nodename = device_get_devnode(dev, NULL, &tmp);
if (!nodename)
return -ENOMEM;
curr_cred = override_creds(&init_cred);
err = vfs_path_lookup(dev_mnt->mnt_root, dev_mnt,
nodename, LOOKUP_PARENT, &nd);
if (err)
goto out;
mutex_lock_nested(&nd.path.dentry->d_inode->i_mutex, I_MUTEX_PARENT);
dentry = lookup_one_len(nd.last.name, nd.path.dentry, nd.last.len);
if (!IS_ERR(dentry)) {
if (dentry->d_inode) {
err = vfs_getattr(nd.path.mnt, dentry, &stat);
if (!err && dev_mynode(dev, dentry->d_inode, &stat)) {
struct iattr newattrs;
newattrs.ia_uid = 0;
newattrs.ia_gid = 0;
newattrs.ia_mode = stat.mode & ~0777;
newattrs.ia_valid =
ATTR_UID|ATTR_GID|ATTR_MODE;
mutex_lock(&dentry->d_inode->i_mutex);
notify_change(dentry, &newattrs);
mutex_unlock(&dentry->d_inode->i_mutex);
err = vfs_unlink(nd.path.dentry->d_inode,
dentry);
if (!err || err == -ENOENT)
deleted = 1;
}
} else {
err = -ENOENT;
}
dput(dentry);
} else {
err = PTR_ERR(dentry);
}
mutex_unlock(&nd.path.dentry->d_inode->i_mutex);
path_put(&nd.path);
if (deleted && strchr(nodename, '/'))
delete_path(nodename);
out:
kfree(tmp);
revert_creds(curr_cred);
return err;
}
int devtmpfs_mount(const char *mntdir)
{
int err;
if (!mount_dev)
return 0;
if (!dev_mnt)
return 0;
err = sys_mount("devtmpfs", (char *)mntdir, "devtmpfs", MS_SILENT, NULL);
if (err)
printk(KERN_INFO "devtmpfs: error mounting %i\n", err);
else
printk(KERN_INFO "devtmpfs: mounted\n");
return err;
}
int __init devtmpfs_init(void)
{
int err;
struct vfsmount *mnt;
char options[] = "mode=0755";
err = register_filesystem(&dev_fs_type);
if (err) {
printk(KERN_ERR "devtmpfs: unable to register devtmpfs "
"type %i\n", err);
return err;
}
mnt = kern_mount_data(&dev_fs_type, options);
if (IS_ERR(mnt)) {
err = PTR_ERR(mnt);
printk(KERN_ERR "devtmpfs: unable to create devtmpfs %i\n", err);
unregister_filesystem(&dev_fs_type);
return err;
}
dev_mnt = mnt;
printk(KERN_INFO "devtmpfs: initialized\n");
return 0;
}
