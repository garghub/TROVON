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
int devtmpfs_create_node(struct device *dev)
{
const char *tmp = NULL;
struct req req;
if (!thread)
return 0;
req.mode = 0;
req.name = device_get_devnode(dev, &req.mode, &tmp);
if (!req.name)
return -ENOMEM;
if (req.mode == 0)
req.mode = 0600;
if (is_blockdev(dev))
req.mode |= S_IFBLK;
else
req.mode |= S_IFCHR;
req.dev = dev;
init_completion(&req.done);
spin_lock(&req_lock);
req.next = requests;
requests = &req;
spin_unlock(&req_lock);
wake_up_process(thread);
wait_for_completion(&req.done);
kfree(tmp);
return req.err;
}
int devtmpfs_delete_node(struct device *dev)
{
const char *tmp = NULL;
struct req req;
if (!thread)
return 0;
req.name = device_get_devnode(dev, NULL, &tmp);
if (!req.name)
return -ENOMEM;
req.mode = 0;
req.dev = dev;
init_completion(&req.done);
spin_lock(&req_lock);
req.next = requests;
requests = &req;
spin_unlock(&req_lock);
wake_up_process(thread);
wait_for_completion(&req.done);
kfree(tmp);
return req.err;
}
static int dev_mkdir(const char *name, mode_t mode)
{
struct dentry *dentry;
struct path path;
int err;
dentry = kern_path_create(AT_FDCWD, name, &path, 1);
if (IS_ERR(dentry))
return PTR_ERR(dentry);
err = vfs_mkdir(path.dentry->d_inode, dentry, mode);
if (!err)
dentry->d_inode->i_private = &thread;
dput(dentry);
mutex_unlock(&path.dentry->d_inode->i_mutex);
path_put(&path);
return err;
}
static int create_path(const char *nodepath)
{
char *path;
char *s;
int err = 0;
path = kstrdup(nodepath, GFP_KERNEL);
if (!path)
return -ENOMEM;
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
return err;
}
static int handle_create(const char *nodename, mode_t mode, struct device *dev)
{
struct dentry *dentry;
struct path path;
int err;
dentry = kern_path_create(AT_FDCWD, nodename, &path, 0);
if (dentry == ERR_PTR(-ENOENT)) {
create_path(nodename);
dentry = kern_path_create(AT_FDCWD, nodename, &path, 0);
}
if (IS_ERR(dentry))
return PTR_ERR(dentry);
err = vfs_mknod(path.dentry->d_inode,
dentry, mode, dev->devt);
if (!err) {
struct iattr newattrs;
newattrs.ia_mode = mode;
newattrs.ia_valid = ATTR_MODE;
mutex_lock(&dentry->d_inode->i_mutex);
notify_change(dentry, &newattrs);
mutex_unlock(&dentry->d_inode->i_mutex);
dentry->d_inode->i_private = &thread;
}
dput(dentry);
mutex_unlock(&path.dentry->d_inode->i_mutex);
path_put(&path);
return err;
}
static int dev_rmdir(const char *name)
{
struct nameidata nd;
struct dentry *dentry;
int err;
err = kern_path_parent(name, &nd);
if (err)
return err;
mutex_lock_nested(&nd.path.dentry->d_inode->i_mutex, I_MUTEX_PARENT);
dentry = lookup_one_len(nd.last.name, nd.path.dentry, nd.last.len);
if (!IS_ERR(dentry)) {
if (dentry->d_inode) {
if (dentry->d_inode->i_private == &thread)
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
kfree(path);
return err;
}
static int dev_mynode(struct device *dev, struct inode *inode, struct kstat *stat)
{
if (inode->i_private != &thread)
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
static int handle_remove(const char *nodename, struct device *dev)
{
struct nameidata nd;
struct dentry *dentry;
struct kstat stat;
int deleted = 1;
int err;
err = kern_path_parent(nodename, &nd);
if (err)
return err;
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
return err;
}
int devtmpfs_mount(const char *mntdir)
{
int err;
if (!mount_dev)
return 0;
if (!thread)
return 0;
err = sys_mount("devtmpfs", (char *)mntdir, "devtmpfs", MS_SILENT, NULL);
if (err)
printk(KERN_INFO "devtmpfs: error mounting %i\n", err);
else
printk(KERN_INFO "devtmpfs: mounted\n");
return err;
}
static int handle(const char *name, mode_t mode, struct device *dev)
{
if (mode)
return handle_create(name, mode, dev);
else
return handle_remove(name, dev);
}
static int devtmpfsd(void *p)
{
char options[] = "mode=0755";
int *err = p;
*err = sys_unshare(CLONE_NEWNS);
if (*err)
goto out;
*err = sys_mount("devtmpfs", "/", "devtmpfs", MS_SILENT, options);
if (*err)
goto out;
sys_chdir("/..");
sys_chroot(".");
complete(&setup_done);
while (1) {
spin_lock(&req_lock);
while (requests) {
struct req *req = requests;
requests = NULL;
spin_unlock(&req_lock);
while (req) {
struct req *next = req->next;
req->err = handle(req->name, req->mode, req->dev);
complete(&req->done);
req = next;
}
spin_lock(&req_lock);
}
set_current_state(TASK_INTERRUPTIBLE);
spin_unlock(&req_lock);
schedule();
__set_current_state(TASK_RUNNING);
}
return 0;
out:
complete(&setup_done);
return *err;
}
int __init devtmpfs_init(void)
{
int err = register_filesystem(&dev_fs_type);
if (err) {
printk(KERN_ERR "devtmpfs: unable to register devtmpfs "
"type %i\n", err);
return err;
}
thread = kthread_run(devtmpfsd, &err, "kdevtmpfs");
if (!IS_ERR(thread)) {
wait_for_completion(&setup_done);
} else {
err = PTR_ERR(thread);
thread = NULL;
}
if (err) {
printk(KERN_ERR "devtmpfs: unable to create devtmpfs %i\n", err);
unregister_filesystem(&dev_fs_type);
return err;
}
printk(KERN_INFO "devtmpfs: initialized\n");
return 0;
}
