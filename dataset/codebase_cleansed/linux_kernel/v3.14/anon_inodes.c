static char *anon_inodefs_dname(struct dentry *dentry, char *buffer, int buflen)
{
return dynamic_dname(dentry, buffer, buflen, "anon_inode:%s",
dentry->d_name.name);
}
static struct dentry *anon_inodefs_mount(struct file_system_type *fs_type,
int flags, const char *dev_name, void *data)
{
return mount_pseudo(fs_type, "anon_inode:", NULL,
&anon_inodefs_dentry_operations, ANON_INODE_FS_MAGIC);
}
struct file *anon_inode_getfile(const char *name,
const struct file_operations *fops,
void *priv, int flags)
{
struct qstr this;
struct path path;
struct file *file;
if (IS_ERR(anon_inode_inode))
return ERR_PTR(-ENODEV);
if (fops->owner && !try_module_get(fops->owner))
return ERR_PTR(-ENOENT);
file = ERR_PTR(-ENOMEM);
this.name = name;
this.len = strlen(name);
this.hash = 0;
path.dentry = d_alloc_pseudo(anon_inode_mnt->mnt_sb, &this);
if (!path.dentry)
goto err_module;
path.mnt = mntget(anon_inode_mnt);
ihold(anon_inode_inode);
d_instantiate(path.dentry, anon_inode_inode);
file = alloc_file(&path, OPEN_FMODE(flags), fops);
if (IS_ERR(file))
goto err_dput;
file->f_mapping = anon_inode_inode->i_mapping;
file->f_flags = flags & (O_ACCMODE | O_NONBLOCK);
file->private_data = priv;
return file;
err_dput:
path_put(&path);
err_module:
module_put(fops->owner);
return file;
}
int anon_inode_getfd(const char *name, const struct file_operations *fops,
void *priv, int flags)
{
int error, fd;
struct file *file;
error = get_unused_fd_flags(flags);
if (error < 0)
return error;
fd = error;
file = anon_inode_getfile(name, fops, priv, flags);
if (IS_ERR(file)) {
error = PTR_ERR(file);
goto err_put_unused_fd;
}
fd_install(fd, file);
return fd;
err_put_unused_fd:
put_unused_fd(fd);
return error;
}
static int __init anon_inode_init(void)
{
anon_inode_mnt = kern_mount(&anon_inode_fs_type);
if (IS_ERR(anon_inode_mnt))
panic("anon_inode_init() kernel mount failed (%ld)\n", PTR_ERR(anon_inode_mnt));
anon_inode_inode = alloc_anon_inode(anon_inode_mnt->mnt_sb);
if (IS_ERR(anon_inode_inode))
panic("anon_inode_init() inode allocation failed (%ld)\n", PTR_ERR(anon_inode_inode));
return 0;
}
