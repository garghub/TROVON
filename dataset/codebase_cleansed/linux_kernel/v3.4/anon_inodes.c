static char *anon_inodefs_dname(struct dentry *dentry, char *buffer, int buflen)
{
return dynamic_dname(dentry, buffer, buflen, "anon_inode:%s",
dentry->d_name.name);
}
static int anon_set_page_dirty(struct page *page)
{
return 0;
}
static struct inode *anon_inode_mkinode(struct super_block *s)
{
struct inode *inode = new_inode_pseudo(s);
if (!inode)
return ERR_PTR(-ENOMEM);
inode->i_ino = get_next_ino();
inode->i_fop = &anon_inode_fops;
inode->i_mapping->a_ops = &anon_aops;
inode->i_state = I_DIRTY;
inode->i_mode = S_IRUSR | S_IWUSR;
inode->i_uid = current_fsuid();
inode->i_gid = current_fsgid();
inode->i_flags |= S_PRIVATE;
inode->i_atime = inode->i_mtime = inode->i_ctime = CURRENT_TIME;
return inode;
}
static struct dentry *anon_inodefs_mount(struct file_system_type *fs_type,
int flags, const char *dev_name, void *data)
{
struct dentry *root;
root = mount_pseudo(fs_type, "anon_inode:", NULL,
&anon_inodefs_dentry_operations, ANON_INODE_FS_MAGIC);
if (!IS_ERR(root)) {
struct super_block *s = root->d_sb;
anon_inode_inode = anon_inode_mkinode(s);
if (IS_ERR(anon_inode_inode)) {
dput(root);
deactivate_locked_super(s);
root = ERR_CAST(anon_inode_inode);
}
}
return root;
}
struct file *anon_inode_getfile(const char *name,
const struct file_operations *fops,
void *priv, int flags)
{
struct qstr this;
struct path path;
struct file *file;
int error;
if (IS_ERR(anon_inode_inode))
return ERR_PTR(-ENODEV);
if (fops->owner && !try_module_get(fops->owner))
return ERR_PTR(-ENOENT);
error = -ENOMEM;
this.name = name;
this.len = strlen(name);
this.hash = 0;
path.dentry = d_alloc_pseudo(anon_inode_mnt->mnt_sb, &this);
if (!path.dentry)
goto err_module;
path.mnt = mntget(anon_inode_mnt);
ihold(anon_inode_inode);
d_instantiate(path.dentry, anon_inode_inode);
error = -ENFILE;
file = alloc_file(&path, OPEN_FMODE(flags), fops);
if (!file)
goto err_dput;
file->f_mapping = anon_inode_inode->i_mapping;
file->f_pos = 0;
file->f_flags = flags & (O_ACCMODE | O_NONBLOCK);
file->f_version = 0;
file->private_data = priv;
return file;
err_dput:
path_put(&path);
err_module:
module_put(fops->owner);
return ERR_PTR(error);
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
int error;
error = register_filesystem(&anon_inode_fs_type);
if (error)
goto err_exit;
anon_inode_mnt = kern_mount(&anon_inode_fs_type);
if (IS_ERR(anon_inode_mnt)) {
error = PTR_ERR(anon_inode_mnt);
goto err_unregister_filesystem;
}
return 0;
err_unregister_filesystem:
unregister_filesystem(&anon_inode_fs_type);
err_exit:
panic(KERN_ERR "anon_inode_init() failed (%d)\n", error);
}
