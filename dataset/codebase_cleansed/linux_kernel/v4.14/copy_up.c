static int ovl_check_fd(const void *data, struct file *f, unsigned int fd)
{
const struct dentry *dentry = data;
if (file_inode(f) == d_inode(dentry))
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
size_t slen;
if (!(old->d_inode->i_opflags & IOP_XATTR) ||
!(new->d_inode->i_opflags & IOP_XATTR))
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
for (name = buf; list_size; name += slen) {
slen = strnlen(name, list_size) + 1;
if (WARN_ON(slen > list_size)) {
error = -EIO;
break;
}
list_size -= slen;
if (ovl_is_private_xattr(name))
continue;
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
error = security_inode_copy_up_xattr(name);
if (error < 0 && error != -EOPNOTSUPP)
break;
if (error == 1) {
error = 0;
continue;
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
error = vfs_clone_file_range(old_file, 0, new_file, 0, len);
if (!error)
goto out;
error = 0;
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
out:
if (!error)
error = vfs_fsync(new_file, 0);
fput(new_file);
out_fput:
fput(old_file);
return error;
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
struct ovl_fh *ovl_encode_fh(struct dentry *lower, bool is_upper)
{
struct ovl_fh *fh;
int fh_type, fh_len, dwords;
void *buf;
int buflen = MAX_HANDLE_SZ;
uuid_t *uuid = &lower->d_sb->s_uuid;
buf = kmalloc(buflen, GFP_KERNEL);
if (!buf)
return ERR_PTR(-ENOMEM);
dwords = buflen >> 2;
fh_type = exportfs_encode_fh(lower, buf, &dwords, 0);
buflen = (dwords << 2);
fh = ERR_PTR(-EIO);
if (WARN_ON(fh_type < 0) ||
WARN_ON(buflen > MAX_HANDLE_SZ) ||
WARN_ON(fh_type == FILEID_INVALID))
goto out;
BUILD_BUG_ON(MAX_HANDLE_SZ + offsetof(struct ovl_fh, fid) > 255);
fh_len = offsetof(struct ovl_fh, fid) + buflen;
fh = kmalloc(fh_len, GFP_KERNEL);
if (!fh) {
fh = ERR_PTR(-ENOMEM);
goto out;
}
fh->version = OVL_FH_VERSION;
fh->magic = OVL_FH_MAGIC;
fh->type = fh_type;
fh->flags = OVL_FH_FLAG_CPU_ENDIAN;
if (is_upper)
fh->flags |= OVL_FH_FLAG_PATH_UPPER;
fh->len = fh_len;
fh->uuid = *uuid;
memcpy(fh->fid, buf, buflen);
out:
kfree(buf);
return fh;
}
static int ovl_set_origin(struct dentry *dentry, struct dentry *lower,
struct dentry *upper)
{
const struct ovl_fh *fh = NULL;
int err;
if (ovl_can_decode_fh(lower->d_sb)) {
fh = ovl_encode_fh(lower, false);
if (IS_ERR(fh))
return PTR_ERR(fh);
}
err = ovl_check_setxattr(dentry, upper, OVL_XATTR_ORIGIN, fh,
fh ? fh->len : 0, 0);
kfree(fh);
return err;
}
static int ovl_link_up(struct ovl_copy_up_ctx *c)
{
int err;
struct dentry *upper;
struct dentry *upperdir = ovl_dentry_upper(c->parent);
struct inode *udir = d_inode(upperdir);
err = ovl_set_impure(c->parent, upperdir);
if (err)
return err;
err = ovl_set_nlink_lower(c->dentry);
if (err)
return err;
inode_lock_nested(udir, I_MUTEX_PARENT);
upper = lookup_one_len(c->dentry->d_name.name, upperdir,
c->dentry->d_name.len);
err = PTR_ERR(upper);
if (!IS_ERR(upper)) {
err = ovl_do_link(ovl_dentry_upper(c->dentry), udir, upper,
true);
dput(upper);
if (!err) {
ovl_set_timestamps(upperdir, &c->pstat);
ovl_dentry_set_upper_alias(c->dentry);
}
}
inode_unlock(udir);
ovl_set_nlink_upper(c->dentry);
return err;
}
static int ovl_install_temp(struct ovl_copy_up_ctx *c, struct dentry *temp,
struct dentry **newdentry)
{
int err;
struct dentry *upper;
struct inode *udir = d_inode(c->destdir);
upper = lookup_one_len(c->destname.name, c->destdir, c->destname.len);
if (IS_ERR(upper))
return PTR_ERR(upper);
if (c->tmpfile)
err = ovl_do_link(temp, udir, upper, true);
else
err = ovl_do_rename(d_inode(c->workdir), temp, udir, upper, 0);
if (!err)
*newdentry = dget(c->tmpfile ? upper : temp);
dput(upper);
return err;
}
static int ovl_get_tmpfile(struct ovl_copy_up_ctx *c, struct dentry **tempp)
{
int err;
struct dentry *temp;
const struct cred *old_creds = NULL;
struct cred *new_creds = NULL;
struct cattr cattr = {
.mode = c->stat.mode & S_IFMT,
.rdev = c->stat.rdev,
.link = c->link
};
err = security_inode_copy_up(c->dentry, &new_creds);
if (err < 0)
goto out;
if (new_creds)
old_creds = override_creds(new_creds);
if (c->tmpfile) {
temp = ovl_do_tmpfile(c->workdir, c->stat.mode);
if (IS_ERR(temp))
goto temp_err;
} else {
temp = ovl_lookup_temp(c->workdir);
if (IS_ERR(temp))
goto temp_err;
err = ovl_create_real(d_inode(c->workdir), temp, &cattr,
NULL, true);
if (err) {
dput(temp);
goto out;
}
}
err = 0;
*tempp = temp;
out:
if (new_creds) {
revert_creds(old_creds);
put_cred(new_creds);
}
return err;
temp_err:
err = PTR_ERR(temp);
goto out;
}
static int ovl_copy_up_inode(struct ovl_copy_up_ctx *c, struct dentry *temp)
{
int err;
if (S_ISREG(c->stat.mode)) {
struct path upperpath;
ovl_path_upper(c->dentry, &upperpath);
BUG_ON(upperpath.dentry != NULL);
upperpath.dentry = temp;
err = ovl_copy_up_data(&c->lowerpath, &upperpath, c->stat.size);
if (err)
return err;
}
err = ovl_copy_xattr(c->lowerpath.dentry, temp);
if (err)
return err;
inode_lock(temp->d_inode);
err = ovl_set_attr(temp, &c->stat);
inode_unlock(temp->d_inode);
if (err)
return err;
if (c->origin) {
err = ovl_set_origin(c->dentry, c->lowerpath.dentry, temp);
if (err)
return err;
}
return 0;
}
static int ovl_copy_up_locked(struct ovl_copy_up_ctx *c)
{
struct inode *udir = c->destdir->d_inode;
struct dentry *newdentry = NULL;
struct dentry *temp = NULL;
int err;
err = ovl_get_tmpfile(c, &temp);
if (err)
goto out;
err = ovl_copy_up_inode(c, temp);
if (err)
goto out_cleanup;
if (c->tmpfile) {
inode_lock_nested(udir, I_MUTEX_PARENT);
err = ovl_install_temp(c, temp, &newdentry);
inode_unlock(udir);
} else {
err = ovl_install_temp(c, temp, &newdentry);
}
if (err)
goto out_cleanup;
ovl_inode_update(d_inode(c->dentry), newdentry);
out:
dput(temp);
return err;
out_cleanup:
if (!c->tmpfile)
ovl_cleanup(d_inode(c->workdir), temp);
goto out;
}
static int ovl_do_copy_up(struct ovl_copy_up_ctx *c)
{
int err;
struct ovl_fs *ofs = c->dentry->d_sb->s_fs_info;
bool indexed = false;
if (ovl_indexdir(c->dentry->d_sb) && !S_ISDIR(c->stat.mode) &&
c->stat.nlink > 1)
indexed = true;
if (S_ISDIR(c->stat.mode) || c->stat.nlink == 1 || indexed)
c->origin = true;
if (indexed) {
c->destdir = ovl_indexdir(c->dentry->d_sb);
err = ovl_get_index_name(c->lowerpath.dentry, &c->destname);
if (err)
return err;
} else {
err = ovl_set_impure(c->parent, c->destdir);
if (err)
return err;
}
if (S_ISREG(c->stat.mode) && ofs->tmpfile) {
c->tmpfile = true;
err = ovl_copy_up_locked(c);
} else {
err = ovl_lock_rename_workdir(c->workdir, c->destdir);
if (!err) {
err = ovl_copy_up_locked(c);
unlock_rename(c->workdir, c->destdir);
}
}
if (indexed) {
if (!err)
ovl_set_flag(OVL_INDEX, d_inode(c->dentry));
kfree(c->destname.name);
} else if (!err) {
struct inode *udir = d_inode(c->destdir);
inode_lock(udir);
ovl_set_timestamps(c->destdir, &c->pstat);
inode_unlock(udir);
ovl_dentry_set_upper_alias(c->dentry);
}
return err;
}
static int ovl_copy_up_one(struct dentry *parent, struct dentry *dentry,
int flags)
{
int err;
DEFINE_DELAYED_CALL(done);
struct path parentpath;
struct ovl_copy_up_ctx ctx = {
.parent = parent,
.dentry = dentry,
.workdir = ovl_workdir(dentry),
};
if (WARN_ON(!ctx.workdir))
return -EROFS;
ovl_path_lower(dentry, &ctx.lowerpath);
err = vfs_getattr(&ctx.lowerpath, &ctx.stat,
STATX_BASIC_STATS, AT_STATX_SYNC_AS_STAT);
if (err)
return err;
ovl_path_upper(parent, &parentpath);
ctx.destdir = parentpath.dentry;
ctx.destname = dentry->d_name;
err = vfs_getattr(&parentpath, &ctx.pstat,
STATX_ATIME | STATX_MTIME, AT_STATX_SYNC_AS_STAT);
if (err)
return err;
if (flags & O_TRUNC)
ctx.stat.size = 0;
if (S_ISLNK(ctx.stat.mode)) {
ctx.link = vfs_get_link(ctx.lowerpath.dentry, &done);
if (IS_ERR(ctx.link))
return PTR_ERR(ctx.link);
}
ovl_do_check_copy_up(ctx.lowerpath.dentry);
err = ovl_copy_up_start(dentry);
if (unlikely(err)) {
if (err > 0)
err = 0;
} else {
if (!ovl_dentry_upper(dentry))
err = ovl_do_copy_up(&ctx);
if (!err && !ovl_dentry_has_upper_alias(dentry))
err = ovl_link_up(&ctx);
ovl_copy_up_end(dentry);
}
do_delayed_call(&done);
return err;
}
int ovl_copy_up_flags(struct dentry *dentry, int flags)
{
int err = 0;
const struct cred *old_cred = ovl_override_creds(dentry->d_sb);
while (!err) {
struct dentry *next;
struct dentry *parent;
if (ovl_dentry_upper(dentry) &&
ovl_dentry_has_upper_alias(dentry))
break;
next = dget(dentry);
for (;;) {
parent = dget_parent(next);
if (ovl_dentry_upper(parent))
break;
dput(next);
next = parent;
}
err = ovl_copy_up_one(parent, next, flags);
dput(parent);
dput(next);
}
revert_creds(old_cred);
return err;
}
int ovl_copy_up(struct dentry *dentry)
{
return ovl_copy_up_flags(dentry, 0);
}
