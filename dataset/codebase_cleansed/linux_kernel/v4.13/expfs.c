static int exportfs_get_name(struct vfsmount *mnt, struct dentry *dir,
char *name, struct dentry *child)
{
const struct export_operations *nop = dir->d_sb->s_export_op;
struct path path = {.mnt = mnt, .dentry = dir};
if (nop->get_name)
return nop->get_name(dir, name, child);
else
return get_name(&path, name, child);
}
static struct dentry *
find_acceptable_alias(struct dentry *result,
int (*acceptable)(void *context, struct dentry *dentry),
void *context)
{
struct dentry *dentry, *toput = NULL;
struct inode *inode;
if (acceptable(context, result))
return result;
inode = result->d_inode;
spin_lock(&inode->i_lock);
hlist_for_each_entry(dentry, &inode->i_dentry, d_u.d_alias) {
dget(dentry);
spin_unlock(&inode->i_lock);
if (toput)
dput(toput);
if (dentry != result && acceptable(context, dentry)) {
dput(result);
return dentry;
}
spin_lock(&inode->i_lock);
toput = dentry;
}
spin_unlock(&inode->i_lock);
if (toput)
dput(toput);
return NULL;
}
static bool dentry_connected(struct dentry *dentry)
{
dget(dentry);
while (dentry->d_flags & DCACHE_DISCONNECTED) {
struct dentry *parent = dget_parent(dentry);
dput(dentry);
if (IS_ROOT(dentry)) {
dput(parent);
return false;
}
dentry = parent;
}
dput(dentry);
return true;
}
static void clear_disconnected(struct dentry *dentry)
{
dget(dentry);
while (dentry->d_flags & DCACHE_DISCONNECTED) {
struct dentry *parent = dget_parent(dentry);
WARN_ON_ONCE(IS_ROOT(dentry));
spin_lock(&dentry->d_lock);
dentry->d_flags &= ~DCACHE_DISCONNECTED;
spin_unlock(&dentry->d_lock);
dput(dentry);
dentry = parent;
}
dput(dentry);
}
static struct dentry *reconnect_one(struct vfsmount *mnt,
struct dentry *dentry, char *nbuf)
{
struct dentry *parent;
struct dentry *tmp;
int err;
parent = ERR_PTR(-EACCES);
inode_lock(dentry->d_inode);
if (mnt->mnt_sb->s_export_op->get_parent)
parent = mnt->mnt_sb->s_export_op->get_parent(dentry);
inode_unlock(dentry->d_inode);
if (IS_ERR(parent)) {
dprintk("%s: get_parent of %ld failed, err %d\n",
__func__, dentry->d_inode->i_ino, PTR_ERR(parent));
return parent;
}
dprintk("%s: find name of %lu in %lu\n", __func__,
dentry->d_inode->i_ino, parent->d_inode->i_ino);
err = exportfs_get_name(mnt, parent, nbuf, dentry);
if (err == -ENOENT)
goto out_reconnected;
if (err)
goto out_err;
dprintk("%s: found name: %s\n", __func__, nbuf);
tmp = lookup_one_len_unlocked(nbuf, parent, strlen(nbuf));
if (IS_ERR(tmp)) {
dprintk("%s: lookup failed: %d\n", __func__, PTR_ERR(tmp));
goto out_err;
}
if (tmp != dentry) {
dput(tmp);
goto out_reconnected;
}
dput(tmp);
if (IS_ROOT(dentry)) {
err = -ESTALE;
goto out_err;
}
return parent;
out_err:
dput(parent);
return ERR_PTR(err);
out_reconnected:
dput(parent);
if (!dentry_connected(dentry))
return ERR_PTR(-ESTALE);
return NULL;
}
static int
reconnect_path(struct vfsmount *mnt, struct dentry *target_dir, char *nbuf)
{
struct dentry *dentry, *parent;
dentry = dget(target_dir);
while (dentry->d_flags & DCACHE_DISCONNECTED) {
BUG_ON(dentry == mnt->mnt_sb->s_root);
if (IS_ROOT(dentry))
parent = reconnect_one(mnt, dentry, nbuf);
else
parent = dget_parent(dentry);
if (!parent)
break;
dput(dentry);
if (IS_ERR(parent))
return PTR_ERR(parent);
dentry = parent;
}
dput(dentry);
clear_disconnected(target_dir);
return 0;
}
static int filldir_one(struct dir_context *ctx, const char *name, int len,
loff_t pos, u64 ino, unsigned int d_type)
{
struct getdents_callback *buf =
container_of(ctx, struct getdents_callback, ctx);
int result = 0;
buf->sequence++;
if (buf->ino == ino && len <= NAME_MAX) {
memcpy(buf->name, name, len);
buf->name[len] = '\0';
buf->found = 1;
result = -1;
}
return result;
}
static int get_name(const struct path *path, char *name, struct dentry *child)
{
const struct cred *cred = current_cred();
struct inode *dir = path->dentry->d_inode;
int error;
struct file *file;
struct kstat stat;
struct path child_path = {
.mnt = path->mnt,
.dentry = child,
};
struct getdents_callback buffer = {
.ctx.actor = filldir_one,
.name = name,
};
error = -ENOTDIR;
if (!dir || !S_ISDIR(dir->i_mode))
goto out;
error = -EINVAL;
if (!dir->i_fop)
goto out;
error = vfs_getattr_nosec(&child_path, &stat,
STATX_INO, AT_STATX_SYNC_AS_STAT);
if (error)
return error;
buffer.ino = stat.ino;
file = dentry_open(path, O_RDONLY, cred);
error = PTR_ERR(file);
if (IS_ERR(file))
goto out;
error = -EINVAL;
if (!file->f_op->iterate && !file->f_op->iterate_shared)
goto out_close;
buffer.sequence = 0;
while (1) {
int old_seq = buffer.sequence;
error = iterate_dir(file, &buffer.ctx);
if (buffer.found) {
error = 0;
break;
}
if (error < 0)
break;
error = -ENOENT;
if (old_seq == buffer.sequence)
break;
}
out_close:
fput(file);
out:
return error;
}
static int export_encode_fh(struct inode *inode, struct fid *fid,
int *max_len, struct inode *parent)
{
int len = *max_len;
int type = FILEID_INO32_GEN;
if (parent && (len < 4)) {
*max_len = 4;
return FILEID_INVALID;
} else if (len < 2) {
*max_len = 2;
return FILEID_INVALID;
}
len = 2;
fid->i32.ino = inode->i_ino;
fid->i32.gen = inode->i_generation;
if (parent) {
fid->i32.parent_ino = parent->i_ino;
fid->i32.parent_gen = parent->i_generation;
len = 4;
type = FILEID_INO32_GEN_PARENT;
}
*max_len = len;
return type;
}
int exportfs_encode_inode_fh(struct inode *inode, struct fid *fid,
int *max_len, struct inode *parent)
{
const struct export_operations *nop = inode->i_sb->s_export_op;
if (nop && nop->encode_fh)
return nop->encode_fh(inode, fid->raw, max_len, parent);
return export_encode_fh(inode, fid, max_len, parent);
}
int exportfs_encode_fh(struct dentry *dentry, struct fid *fid, int *max_len,
int connectable)
{
int error;
struct dentry *p = NULL;
struct inode *inode = dentry->d_inode, *parent = NULL;
if (connectable && !S_ISDIR(inode->i_mode)) {
p = dget_parent(dentry);
parent = p->d_inode;
}
error = exportfs_encode_inode_fh(inode, fid, max_len, parent);
dput(p);
return error;
}
struct dentry *exportfs_decode_fh(struct vfsmount *mnt, struct fid *fid,
int fh_len, int fileid_type,
int (*acceptable)(void *, struct dentry *), void *context)
{
const struct export_operations *nop = mnt->mnt_sb->s_export_op;
struct dentry *result, *alias;
char nbuf[NAME_MAX+1];
int err;
if (!nop || !nop->fh_to_dentry)
return ERR_PTR(-ESTALE);
result = nop->fh_to_dentry(mnt->mnt_sb, fid, fh_len, fileid_type);
if (PTR_ERR(result) == -ENOMEM)
return ERR_CAST(result);
if (IS_ERR_OR_NULL(result))
return ERR_PTR(-ESTALE);
if (d_is_dir(result)) {
if (result->d_flags & DCACHE_DISCONNECTED) {
err = reconnect_path(mnt, result, nbuf);
if (err)
goto err_result;
}
if (!acceptable(context, result)) {
err = -EACCES;
goto err_result;
}
return result;
} else {
struct dentry *target_dir, *nresult;
alias = find_acceptable_alias(result, acceptable, context);
if (alias)
return alias;
err = -ESTALE;
if (!nop->fh_to_parent)
goto err_result;
target_dir = nop->fh_to_parent(mnt->mnt_sb, fid,
fh_len, fileid_type);
if (!target_dir)
goto err_result;
err = PTR_ERR(target_dir);
if (IS_ERR(target_dir))
goto err_result;
err = reconnect_path(mnt, target_dir, nbuf);
if (err) {
dput(target_dir);
goto err_result;
}
err = exportfs_get_name(mnt, target_dir, nbuf, result);
if (!err) {
inode_lock(target_dir->d_inode);
nresult = lookup_one_len(nbuf, target_dir,
strlen(nbuf));
inode_unlock(target_dir->d_inode);
if (!IS_ERR(nresult)) {
if (nresult->d_inode) {
dput(result);
result = nresult;
} else
dput(nresult);
}
}
dput(target_dir);
alias = find_acceptable_alias(result, acceptable, context);
if (!alias) {
err = -EACCES;
goto err_result;
}
return alias;
}
err_result:
dput(result);
if (err != -ENOMEM)
err = -ESTALE;
return ERR_PTR(err);
}
