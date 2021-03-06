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
hlist_for_each_entry(dentry, &inode->i_dentry, d_alias) {
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
static struct dentry *
find_disconnected_root(struct dentry *dentry)
{
dget(dentry);
while (!IS_ROOT(dentry)) {
struct dentry *parent = dget_parent(dentry);
if (!(parent->d_flags & DCACHE_DISCONNECTED)) {
dput(parent);
break;
}
dput(dentry);
dentry = parent;
}
return dentry;
}
static int
reconnect_path(struct vfsmount *mnt, struct dentry *target_dir, char *nbuf)
{
int noprogress = 0;
int err = -ESTALE;
while (target_dir->d_flags & DCACHE_DISCONNECTED && noprogress++ < 10) {
struct dentry *pd = find_disconnected_root(target_dir);
if (!IS_ROOT(pd)) {
spin_lock(&pd->d_lock);
pd->d_flags &= ~DCACHE_DISCONNECTED;
spin_unlock(&pd->d_lock);
noprogress = 0;
} else if (pd == mnt->mnt_sb->s_root) {
printk(KERN_ERR "export: Eeek filesystem root is not connected, impossible\n");
spin_lock(&pd->d_lock);
pd->d_flags &= ~DCACHE_DISCONNECTED;
spin_unlock(&pd->d_lock);
noprogress = 0;
} else {
struct dentry *ppd = ERR_PTR(-EACCES);
struct dentry *npd;
mutex_lock(&pd->d_inode->i_mutex);
if (mnt->mnt_sb->s_export_op->get_parent)
ppd = mnt->mnt_sb->s_export_op->get_parent(pd);
mutex_unlock(&pd->d_inode->i_mutex);
if (IS_ERR(ppd)) {
err = PTR_ERR(ppd);
dprintk("%s: get_parent of %ld failed, err %d\n",
__func__, pd->d_inode->i_ino, err);
dput(pd);
break;
}
dprintk("%s: find name of %lu in %lu\n", __func__,
pd->d_inode->i_ino, ppd->d_inode->i_ino);
err = exportfs_get_name(mnt, ppd, nbuf, pd);
if (err) {
dput(ppd);
dput(pd);
if (err == -ENOENT)
continue;
break;
}
dprintk("%s: found name: %s\n", __func__, nbuf);
mutex_lock(&ppd->d_inode->i_mutex);
npd = lookup_one_len(nbuf, ppd, strlen(nbuf));
mutex_unlock(&ppd->d_inode->i_mutex);
if (IS_ERR(npd)) {
err = PTR_ERR(npd);
dprintk("%s: lookup failed: %d\n",
__func__, err);
dput(ppd);
dput(pd);
break;
}
if (npd == pd)
noprogress = 0;
else
printk("%s: npd != pd\n", __func__);
dput(npd);
dput(ppd);
if (IS_ROOT(pd)) {
dput(pd);
break;
}
}
dput(pd);
}
if (target_dir->d_flags & DCACHE_DISCONNECTED) {
if (!err)
err = -ESTALE;
return err;
}
return 0;
}
static int filldir_one(void * __buf, const char * name, int len,
loff_t pos, u64 ino, unsigned int d_type)
{
struct getdents_callback *buf = __buf;
int result = 0;
buf->sequence++;
if (buf->ino == ino) {
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
struct getdents_callback buffer;
error = -ENOTDIR;
if (!dir || !S_ISDIR(dir->i_mode))
goto out;
error = -EINVAL;
if (!dir->i_fop)
goto out;
file = dentry_open(path, O_RDONLY, cred);
error = PTR_ERR(file);
if (IS_ERR(file))
goto out;
error = -EINVAL;
if (!file->f_op->readdir)
goto out_close;
buffer.name = name;
buffer.ino = child->d_inode->i_ino;
buffer.found = 0;
buffer.sequence = 0;
while (1) {
int old_seq = buffer.sequence;
error = vfs_readdir(file, filldir_one, &buffer);
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
if (!result)
result = ERR_PTR(-ESTALE);
if (IS_ERR(result))
return result;
if (S_ISDIR(result->d_inode->i_mode)) {
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
mutex_lock(&target_dir->d_inode->i_mutex);
nresult = lookup_one_len(nbuf, target_dir,
strlen(nbuf));
mutex_unlock(&target_dir->d_inode->i_mutex);
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
return ERR_PTR(err);
}
