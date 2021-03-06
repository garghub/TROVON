static int ovl_check_fd(const void *data, struct file *f, unsigned int fd)
{
const struct dentry *dentry = data;
if (f->f_inode == d_inode(dentry))
pr_warn_ratelimited("overlayfs: Warning: Copying up %pD, but open R/O on fd %u which will cease to be coherent [pid=%d %s]\n",
f, fd, current->pid, current->comm);
return 0;
}
static void ovl_do_check_copy_up(struct dentry *dentry)
{
if (ovl_check_copy_up)
iterate_fd(current->files, 0, ovl_check_fd, dentry);
}
int ovl_copy_xattr(struct dentry *old, struct dentry *new)
{
ssize_t list_size, size, value_size = 0;
char *buf, *name, *value = NULL;
int uninitialized_var(error);
if (!old->d_inode->i_op->getxattr ||
!new->d_inode->i_op->getxattr)
return 0;
list_size = vfs_listxattr(old, NULL, 0);
if (list_size <= 0) {
if (list_size == -EOPNOTSUPP)
return 0;
return list_size;
}
buf = kzalloc(list_size, GFP_KERNEL);
if (!buf)
return -ENOMEM;
list_size = vfs_listxattr(old, buf, list_size);
if (list_size <= 0) {
error = list_size;
goto out;
}
for (name = buf; name < (buf + list_size); name += strlen(name) + 1) {
retry:
size = vfs_getxattr(old, name, value, value_size);
if (size == -ERANGE)
size = vfs_getxattr(old, name, NULL, 0);
if (size < 0) {
error = size;
break;
}
if (size > value_size) {
void *new;
new = krealloc(value, size, GFP_KERNEL);
if (!new) {
error = -ENOMEM;
break;
}
value = new;
value_size = size;
goto retry;
}
error = vfs_setxattr(new, name, value, size, 0);
if (error)
break;
}
kfree(value);
out:
kfree(buf);
return error;
}
static int ovl_copy_up_data(struct path *old, struct path *new, loff_t len)
{
struct file *old_file;
struct file *new_file;
loff_t old_pos = 0;
loff_t new_pos = 0;
int error = 0;
if (len == 0)
return 0;
old_file = ovl_path_open(old, O_LARGEFILE | O_RDONLY);
if (IS_ERR(old_file))
return PTR_ERR(old_file);
new_file = ovl_path_open(new, O_LARGEFILE | O_WRONLY);
if (IS_ERR(new_file)) {
error = PTR_ERR(new_file);
goto out_fput;
}
while (len) {
size_t this_len = OVL_COPY_UP_CHUNK_SIZE;
long bytes;
if (len < this_len)
this_len = len;
if (signal_pending_state(TASK_KILLABLE, current)) {
error = -EINTR;
break;
}
bytes = do_splice_direct(old_file, &old_pos,
new_file, &new_pos,
this_len, SPLICE_F_MOVE);
if (bytes <= 0) {
error = bytes;
break;
}
WARN_ON(old_pos != new_pos);
len -= bytes;
}
fput(new_file);
out_fput:
fput(old_file);
return error;
}
static char *ovl_read_symlink(struct dentry *realdentry)
{
int res;
char *buf;
struct inode *inode = realdentry->d_inode;
mm_segment_t old_fs;
res = -EINVAL;
if (!inode->i_op->readlink)
goto err;
res = -ENOMEM;
buf = (char *) __get_free_page(GFP_KERNEL);
if (!buf)
goto err;
old_fs = get_fs();
set_fs(get_ds());
res = inode->i_op->readlink(realdentry,
(char __user *)buf, PAGE_SIZE - 1);
set_fs(old_fs);
if (res < 0) {
free_page((unsigned long) buf);
goto err;
}
buf[res] = '\0';
return buf;
err:
return ERR_PTR(res);
}
static int ovl_set_timestamps(struct dentry *upperdentry, struct kstat *stat)
{
struct iattr attr = {
.ia_valid =
ATTR_ATIME | ATTR_MTIME | ATTR_ATIME_SET | ATTR_MTIME_SET,
.ia_atime = stat->atime,
.ia_mtime = stat->mtime,
};
return notify_change(upperdentry, &attr, NULL);
}
int ovl_set_attr(struct dentry *upperdentry, struct kstat *stat)
{
int err = 0;
if (!S_ISLNK(stat->mode)) {
struct iattr attr = {
.ia_valid = ATTR_MODE,
.ia_mode = stat->mode,
};
err = notify_change(upperdentry, &attr, NULL);
}
if (!err) {
struct iattr attr = {
.ia_valid = ATTR_UID | ATTR_GID,
.ia_uid = stat->uid,
.ia_gid = stat->gid,
};
err = notify_change(upperdentry, &attr, NULL);
}
if (!err)
ovl_set_timestamps(upperdentry, stat);
return err;
}
static int ovl_copy_up_locked(struct dentry *workdir, struct dentry *upperdir,
struct dentry *dentry, struct path *lowerpath,
struct kstat *stat, const char *link)
{
struct inode *wdir = workdir->d_inode;
struct inode *udir = upperdir->d_inode;
struct dentry *newdentry = NULL;
struct dentry *upper = NULL;
umode_t mode = stat->mode;
int err;
newdentry = ovl_lookup_temp(workdir, dentry);
err = PTR_ERR(newdentry);
if (IS_ERR(newdentry))
goto out;
upper = lookup_one_len(dentry->d_name.name, upperdir,
dentry->d_name.len);
err = PTR_ERR(upper);
if (IS_ERR(upper))
goto out1;
stat->mode &= S_IFMT;
err = ovl_create_real(wdir, newdentry, stat, link, NULL, true);
stat->mode = mode;
if (err)
goto out2;
if (S_ISREG(stat->mode)) {
struct path upperpath;
ovl_path_upper(dentry, &upperpath);
BUG_ON(upperpath.dentry != NULL);
upperpath.dentry = newdentry;
err = ovl_copy_up_data(lowerpath, &upperpath, stat->size);
if (err)
goto out_cleanup;
}
err = ovl_copy_xattr(lowerpath->dentry, newdentry);
if (err)
goto out_cleanup;
inode_lock(newdentry->d_inode);
err = ovl_set_attr(newdentry, stat);
inode_unlock(newdentry->d_inode);
if (err)
goto out_cleanup;
err = ovl_do_rename(wdir, newdentry, udir, upper, 0);
if (err)
goto out_cleanup;
ovl_dentry_update(dentry, newdentry);
newdentry = NULL;
if (!S_ISDIR(stat->mode))
ovl_dentry_set_opaque(dentry, true);
out2:
dput(upper);
out1:
dput(newdentry);
out:
return err;
out_cleanup:
ovl_cleanup(wdir, newdentry);
goto out2;
}
int ovl_copy_up_one(struct dentry *parent, struct dentry *dentry,
struct path *lowerpath, struct kstat *stat)
{
struct dentry *workdir = ovl_workdir(dentry);
int err;
struct kstat pstat;
struct path parentpath;
struct dentry *upperdir;
struct dentry *upperdentry;
const struct cred *old_cred;
char *link = NULL;
if (WARN_ON(!workdir))
return -EROFS;
ovl_do_check_copy_up(lowerpath->dentry);
ovl_path_upper(parent, &parentpath);
upperdir = parentpath.dentry;
err = vfs_getattr(&parentpath, &pstat);
if (err)
return err;
if (S_ISLNK(stat->mode)) {
link = ovl_read_symlink(lowerpath->dentry);
if (IS_ERR(link))
return PTR_ERR(link);
}
old_cred = ovl_override_creds(dentry->d_sb);
err = -EIO;
if (lock_rename(workdir, upperdir) != NULL) {
pr_err("overlayfs: failed to lock workdir+upperdir\n");
goto out_unlock;
}
upperdentry = ovl_dentry_upper(dentry);
if (upperdentry) {
err = 0;
goto out_unlock;
}
err = ovl_copy_up_locked(workdir, upperdir, dentry, lowerpath,
stat, link);
if (!err) {
ovl_set_timestamps(upperdir, &pstat);
}
out_unlock:
unlock_rename(workdir, upperdir);
revert_creds(old_cred);
if (link)
free_page((unsigned long) link);
return err;
}
int ovl_copy_up(struct dentry *dentry)
{
int err;
err = 0;
while (!err) {
struct dentry *next;
struct dentry *parent;
struct path lowerpath;
struct kstat stat;
enum ovl_path_type type = ovl_path_type(dentry);
if (OVL_TYPE_UPPER(type))
break;
next = dget(dentry);
for (;;) {
parent = dget_parent(next);
type = ovl_path_type(parent);
if (OVL_TYPE_UPPER(type))
break;
dput(next);
next = parent;
}
ovl_path_lower(next, &lowerpath);
err = vfs_getattr(&lowerpath, &stat);
if (!err)
err = ovl_copy_up_one(parent, next, &lowerpath, &stat);
dput(parent);
dput(next);
}
return err;
}
