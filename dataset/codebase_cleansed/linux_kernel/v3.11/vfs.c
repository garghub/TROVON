int
nfsd_cross_mnt(struct svc_rqst *rqstp, struct dentry **dpp,
struct svc_export **expp)
{
struct svc_export *exp = *expp, *exp2 = NULL;
struct dentry *dentry = *dpp;
struct path path = {.mnt = mntget(exp->ex_path.mnt),
.dentry = dget(dentry)};
int err = 0;
err = follow_down(&path);
if (err < 0)
goto out;
exp2 = rqst_exp_get_by_name(rqstp, &path);
if (IS_ERR(exp2)) {
err = PTR_ERR(exp2);
if (err == -ENOENT && !(exp->ex_flags & NFSEXP_V4ROOT))
err = 0;
path_put(&path);
goto out;
}
if (nfsd_v4client(rqstp) ||
(exp->ex_flags & NFSEXP_CROSSMOUNT) || EX_NOHIDE(exp2)) {
*dpp = path.dentry;
path.dentry = dentry;
*expp = exp2;
exp2 = exp;
}
path_put(&path);
exp_put(exp2);
out:
return err;
}
static void follow_to_parent(struct path *path)
{
struct dentry *dp;
while (path->dentry == path->mnt->mnt_root && follow_up(path))
;
dp = dget_parent(path->dentry);
dput(path->dentry);
path->dentry = dp;
}
static int nfsd_lookup_parent(struct svc_rqst *rqstp, struct dentry *dparent, struct svc_export **exp, struct dentry **dentryp)
{
struct svc_export *exp2;
struct path path = {.mnt = mntget((*exp)->ex_path.mnt),
.dentry = dget(dparent)};
follow_to_parent(&path);
exp2 = rqst_exp_parent(rqstp, &path);
if (PTR_ERR(exp2) == -ENOENT) {
*dentryp = dget(dparent);
} else if (IS_ERR(exp2)) {
path_put(&path);
return PTR_ERR(exp2);
} else {
*dentryp = dget(path.dentry);
exp_put(*exp);
*exp = exp2;
}
path_put(&path);
return 0;
}
int nfsd_mountpoint(struct dentry *dentry, struct svc_export *exp)
{
if (d_mountpoint(dentry))
return 1;
if (nfsd4_is_junction(dentry))
return 1;
if (!(exp->ex_flags & NFSEXP_V4ROOT))
return 0;
return dentry->d_inode != NULL;
}
__be32
nfsd_lookup_dentry(struct svc_rqst *rqstp, struct svc_fh *fhp,
const char *name, unsigned int len,
struct svc_export **exp_ret, struct dentry **dentry_ret)
{
struct svc_export *exp;
struct dentry *dparent;
struct dentry *dentry;
int host_err;
dprintk("nfsd: nfsd_lookup(fh %s, %.*s)\n", SVCFH_fmt(fhp), len,name);
dparent = fhp->fh_dentry;
exp = fhp->fh_export;
exp_get(exp);
if (isdotent(name, len)) {
if (len==1)
dentry = dget(dparent);
else if (dparent != exp->ex_path.dentry)
dentry = dget_parent(dparent);
else if (!EX_NOHIDE(exp) && !nfsd_v4client(rqstp))
dentry = dget(dparent);
else {
host_err = nfsd_lookup_parent(rqstp, dparent, &exp, &dentry);
if (host_err)
goto out_nfserr;
}
} else {
fh_lock(fhp);
dentry = lookup_one_len(name, dparent, len);
host_err = PTR_ERR(dentry);
if (IS_ERR(dentry))
goto out_nfserr;
if (nfsd_mountpoint(dentry, exp)) {
if ((host_err = nfsd_cross_mnt(rqstp, &dentry, &exp))) {
dput(dentry);
goto out_nfserr;
}
}
}
*dentry_ret = dentry;
*exp_ret = exp;
return 0;
out_nfserr:
exp_put(exp);
return nfserrno(host_err);
}
__be32
nfsd_lookup(struct svc_rqst *rqstp, struct svc_fh *fhp, const char *name,
unsigned int len, struct svc_fh *resfh)
{
struct svc_export *exp;
struct dentry *dentry;
__be32 err;
err = fh_verify(rqstp, fhp, S_IFDIR, NFSD_MAY_EXEC);
if (err)
return err;
err = nfsd_lookup_dentry(rqstp, fhp, name, len, &exp, &dentry);
if (err)
return err;
err = check_nfsd_access(exp, rqstp);
if (err)
goto out;
err = fh_compose(resfh, exp, dentry, fhp);
if (!err && !dentry->d_inode)
err = nfserr_noent;
out:
dput(dentry);
exp_put(exp);
return err;
}
static int nfsd_break_lease(struct inode *inode)
{
if (!S_ISREG(inode->i_mode))
return 0;
return break_lease(inode, O_WRONLY | O_NONBLOCK);
}
static int
commit_metadata(struct svc_fh *fhp)
{
struct inode *inode = fhp->fh_dentry->d_inode;
const struct export_operations *export_ops = inode->i_sb->s_export_op;
if (!EX_ISSYNC(fhp->fh_export))
return 0;
if (export_ops->commit_metadata)
return export_ops->commit_metadata(inode);
return sync_inode_metadata(inode, 1);
}
__be32
nfsd_setattr(struct svc_rqst *rqstp, struct svc_fh *fhp, struct iattr *iap,
int check_guard, time_t guardtime)
{
struct dentry *dentry;
struct inode *inode;
int accmode = NFSD_MAY_SATTR;
umode_t ftype = 0;
__be32 err;
int host_err;
int size_change = 0;
if (iap->ia_valid & (ATTR_ATIME | ATTR_MTIME | ATTR_SIZE))
accmode |= NFSD_MAY_WRITE|NFSD_MAY_OWNER_OVERRIDE;
if (iap->ia_valid & ATTR_SIZE)
ftype = S_IFREG;
err = fh_verify(rqstp, fhp, ftype, accmode);
if (err)
goto out;
dentry = fhp->fh_dentry;
inode = dentry->d_inode;
if (S_ISLNK(inode->i_mode))
iap->ia_valid &= ~ATTR_MODE;
if (!iap->ia_valid)
goto out;
#define BOTH_TIME_SET (ATTR_ATIME_SET | ATTR_MTIME_SET)
#define MAX_TOUCH_TIME_ERROR (30*60)
if ((iap->ia_valid & BOTH_TIME_SET) == BOTH_TIME_SET &&
iap->ia_mtime.tv_sec == iap->ia_atime.tv_sec) {
time_t delta = iap->ia_atime.tv_sec - get_seconds();
if (delta < 0)
delta = -delta;
if (delta < MAX_TOUCH_TIME_ERROR &&
inode_change_ok(inode, iap) != 0) {
iap->ia_valid &= ~BOTH_TIME_SET;
}
}
if (iap->ia_valid & ATTR_SIZE) {
if (iap->ia_size < inode->i_size) {
err = nfsd_permission(rqstp, fhp->fh_export, dentry,
NFSD_MAY_TRUNC|NFSD_MAY_OWNER_OVERRIDE);
if (err)
goto out;
}
host_err = get_write_access(inode);
if (host_err)
goto out_nfserr;
size_change = 1;
host_err = locks_verify_truncate(inode, NULL, iap->ia_size);
if (host_err) {
put_write_access(inode);
goto out_nfserr;
}
}
if (iap->ia_valid & ATTR_MODE) {
iap->ia_mode &= S_IALLUGO;
iap->ia_mode |= (inode->i_mode & ~S_IALLUGO);
}
if (!S_ISDIR(inode->i_mode) &&
(((iap->ia_valid & ATTR_UID) && !uid_eq(iap->ia_uid, inode->i_uid)) ||
((iap->ia_valid & ATTR_GID) && !gid_eq(iap->ia_gid, inode->i_gid)))) {
iap->ia_valid |= ATTR_KILL_PRIV;
if (iap->ia_valid & ATTR_MODE) {
iap->ia_mode &= ~S_ISUID;
if (iap->ia_mode & S_IXGRP)
iap->ia_mode &= ~S_ISGID;
} else {
iap->ia_valid |= (ATTR_KILL_SUID | ATTR_KILL_SGID);
}
}
iap->ia_valid |= ATTR_CTIME;
err = nfserr_notsync;
if (!check_guard || guardtime == inode->i_ctime.tv_sec) {
host_err = nfsd_break_lease(inode);
if (host_err)
goto out_nfserr;
fh_lock(fhp);
host_err = notify_change(dentry, iap);
err = nfserrno(host_err);
fh_unlock(fhp);
}
if (size_change)
put_write_access(inode);
if (!err)
commit_metadata(fhp);
out:
return err;
out_nfserr:
err = nfserrno(host_err);
goto out;
}
static ssize_t nfsd_getxattr(struct dentry *dentry, char *key, void **buf)
{
ssize_t buflen;
ssize_t ret;
buflen = vfs_getxattr(dentry, key, NULL, 0);
if (buflen <= 0)
return buflen;
*buf = kmalloc(buflen, GFP_KERNEL);
if (!*buf)
return -ENOMEM;
ret = vfs_getxattr(dentry, key, *buf, buflen);
if (ret < 0)
kfree(*buf);
return ret;
}
static int
set_nfsv4_acl_one(struct dentry *dentry, struct posix_acl *pacl, char *key)
{
int len;
size_t buflen;
char *buf = NULL;
int error = 0;
buflen = posix_acl_xattr_size(pacl->a_count);
buf = kmalloc(buflen, GFP_KERNEL);
error = -ENOMEM;
if (buf == NULL)
goto out;
len = posix_acl_to_xattr(&init_user_ns, pacl, buf, buflen);
if (len < 0) {
error = len;
goto out;
}
error = vfs_setxattr(dentry, key, buf, len, 0);
out:
kfree(buf);
return error;
}
__be32
nfsd4_set_nfs4_acl(struct svc_rqst *rqstp, struct svc_fh *fhp,
struct nfs4_acl *acl)
{
__be32 error;
int host_error;
struct dentry *dentry;
struct inode *inode;
struct posix_acl *pacl = NULL, *dpacl = NULL;
unsigned int flags = 0;
error = fh_verify(rqstp, fhp, 0, NFSD_MAY_SATTR);
if (error)
return error;
dentry = fhp->fh_dentry;
inode = dentry->d_inode;
if (S_ISDIR(inode->i_mode))
flags = NFS4_ACL_DIR;
host_error = nfs4_acl_nfsv4_to_posix(acl, &pacl, &dpacl, flags);
if (host_error == -EINVAL) {
return nfserr_attrnotsupp;
} else if (host_error < 0)
goto out_nfserr;
host_error = set_nfsv4_acl_one(dentry, pacl, POSIX_ACL_XATTR_ACCESS);
if (host_error < 0)
goto out_release;
if (S_ISDIR(inode->i_mode))
host_error = set_nfsv4_acl_one(dentry, dpacl, POSIX_ACL_XATTR_DEFAULT);
out_release:
posix_acl_release(pacl);
posix_acl_release(dpacl);
out_nfserr:
if (host_error == -EOPNOTSUPP)
return nfserr_attrnotsupp;
else
return nfserrno(host_error);
}
static struct posix_acl *
_get_posix_acl(struct dentry *dentry, char *key)
{
void *buf = NULL;
struct posix_acl *pacl = NULL;
int buflen;
buflen = nfsd_getxattr(dentry, key, &buf);
if (!buflen)
buflen = -ENODATA;
if (buflen <= 0)
return ERR_PTR(buflen);
pacl = posix_acl_from_xattr(&init_user_ns, buf, buflen);
kfree(buf);
return pacl;
}
int
nfsd4_get_nfs4_acl(struct svc_rqst *rqstp, struct dentry *dentry, struct nfs4_acl **acl)
{
struct inode *inode = dentry->d_inode;
int error = 0;
struct posix_acl *pacl = NULL, *dpacl = NULL;
unsigned int flags = 0;
pacl = _get_posix_acl(dentry, POSIX_ACL_XATTR_ACCESS);
if (IS_ERR(pacl) && PTR_ERR(pacl) == -ENODATA)
pacl = posix_acl_from_mode(inode->i_mode, GFP_KERNEL);
if (IS_ERR(pacl)) {
error = PTR_ERR(pacl);
pacl = NULL;
goto out;
}
if (S_ISDIR(inode->i_mode)) {
dpacl = _get_posix_acl(dentry, POSIX_ACL_XATTR_DEFAULT);
if (IS_ERR(dpacl) && PTR_ERR(dpacl) == -ENODATA)
dpacl = NULL;
else if (IS_ERR(dpacl)) {
error = PTR_ERR(dpacl);
dpacl = NULL;
goto out;
}
flags = NFS4_ACL_DIR;
}
*acl = nfs4_acl_posix_to_nfsv4(pacl, dpacl, flags);
if (IS_ERR(*acl)) {
error = PTR_ERR(*acl);
*acl = NULL;
}
out:
posix_acl_release(pacl);
posix_acl_release(dpacl);
return error;
}
int nfsd4_is_junction(struct dentry *dentry)
{
struct inode *inode = dentry->d_inode;
if (inode == NULL)
return 0;
if (inode->i_mode & S_IXUGO)
return 0;
if (!(inode->i_mode & S_ISVTX))
return 0;
if (vfs_getxattr(dentry, NFSD_JUNCTION_XATTR_NAME, NULL, 0) <= 0)
return 0;
return 1;
}
__be32 nfsd4_set_nfs4_label(struct svc_rqst *rqstp, struct svc_fh *fhp,
struct xdr_netobj *label)
{
__be32 error;
int host_error;
struct dentry *dentry;
error = fh_verify(rqstp, fhp, 0 , NFSD_MAY_SATTR);
if (error)
return error;
dentry = fhp->fh_dentry;
mutex_lock(&dentry->d_inode->i_mutex);
host_error = security_inode_setsecctx(dentry, label->data, label->len);
mutex_unlock(&dentry->d_inode->i_mutex);
return nfserrno(host_error);
}
__be32 nfsd4_set_nfs4_label(struct svc_rqst *rqstp, struct svc_fh *fhp,
struct xdr_netobj *label)
{
return nfserr_notsupp;
}
__be32
nfsd_access(struct svc_rqst *rqstp, struct svc_fh *fhp, u32 *access, u32 *supported)
{
struct accessmap *map;
struct svc_export *export;
struct dentry *dentry;
u32 query, result = 0, sresult = 0;
__be32 error;
error = fh_verify(rqstp, fhp, 0, NFSD_MAY_NOP);
if (error)
goto out;
export = fhp->fh_export;
dentry = fhp->fh_dentry;
if (S_ISREG(dentry->d_inode->i_mode))
map = nfs3_regaccess;
else if (S_ISDIR(dentry->d_inode->i_mode))
map = nfs3_diraccess;
else
map = nfs3_anyaccess;
query = *access;
for (; map->access; map++) {
if (map->access & query) {
__be32 err2;
sresult |= map->access;
err2 = nfsd_permission(rqstp, export, dentry, map->how);
switch (err2) {
case nfs_ok:
result |= map->access;
break;
case nfserr_rofs:
case nfserr_acces:
case nfserr_perm:
break;
default:
error = err2;
goto out;
}
}
}
*access = result;
if (supported)
*supported = sresult;
out:
return error;
}
static int nfsd_open_break_lease(struct inode *inode, int access)
{
unsigned int mode;
if (access & NFSD_MAY_NOT_BREAK_LEASE)
return 0;
mode = (access & NFSD_MAY_WRITE) ? O_WRONLY : O_RDONLY;
return break_lease(inode, mode | O_NONBLOCK);
}
__be32
nfsd_open(struct svc_rqst *rqstp, struct svc_fh *fhp, umode_t type,
int may_flags, struct file **filp)
{
struct path path;
struct inode *inode;
int flags = O_RDONLY|O_LARGEFILE;
__be32 err;
int host_err = 0;
validate_process_creds();
if (type == S_IFREG)
may_flags |= NFSD_MAY_OWNER_OVERRIDE;
err = fh_verify(rqstp, fhp, type, may_flags);
if (err)
goto out;
path.mnt = fhp->fh_export->ex_path.mnt;
path.dentry = fhp->fh_dentry;
inode = path.dentry->d_inode;
err = nfserr_perm;
if (IS_APPEND(inode) && (may_flags & NFSD_MAY_WRITE))
goto out;
if (S_ISREG((inode)->i_mode) && mandatory_lock(inode))
goto out;
if (!inode->i_fop)
goto out;
host_err = nfsd_open_break_lease(inode, may_flags);
if (host_err)
goto out_nfserr;
if (may_flags & NFSD_MAY_WRITE) {
if (may_flags & NFSD_MAY_READ)
flags = O_RDWR|O_LARGEFILE;
else
flags = O_WRONLY|O_LARGEFILE;
}
*filp = dentry_open(&path, flags, current_cred());
if (IS_ERR(*filp)) {
host_err = PTR_ERR(*filp);
*filp = NULL;
} else {
host_err = ima_file_check(*filp, may_flags);
if (may_flags & NFSD_MAY_64BIT_COOKIE)
(*filp)->f_mode |= FMODE_64BITHASH;
else
(*filp)->f_mode |= FMODE_32BITHASH;
}
out_nfserr:
err = nfserrno(host_err);
out:
validate_process_creds();
return err;
}
void
nfsd_close(struct file *filp)
{
fput(filp);
}
static inline struct raparms *
nfsd_get_raparms(dev_t dev, ino_t ino)
{
struct raparms *ra, **rap, **frap = NULL;
int depth = 0;
unsigned int hash;
struct raparm_hbucket *rab;
hash = jhash_2words(dev, ino, 0xfeedbeef) & RAPARM_HASH_MASK;
rab = &raparm_hash[hash];
spin_lock(&rab->pb_lock);
for (rap = &rab->pb_head; (ra = *rap); rap = &ra->p_next) {
if (ra->p_ino == ino && ra->p_dev == dev)
goto found;
depth++;
if (ra->p_count == 0)
frap = rap;
}
depth = nfsdstats.ra_size;
if (!frap) {
spin_unlock(&rab->pb_lock);
return NULL;
}
rap = frap;
ra = *frap;
ra->p_dev = dev;
ra->p_ino = ino;
ra->p_set = 0;
ra->p_hindex = hash;
found:
if (rap != &rab->pb_head) {
*rap = ra->p_next;
ra->p_next = rab->pb_head;
rab->pb_head = ra;
}
ra->p_count++;
nfsdstats.ra_depth[depth*10/nfsdstats.ra_size]++;
spin_unlock(&rab->pb_lock);
return ra;
}
static int
nfsd_splice_actor(struct pipe_inode_info *pipe, struct pipe_buffer *buf,
struct splice_desc *sd)
{
struct svc_rqst *rqstp = sd->u.data;
struct page **pp = rqstp->rq_next_page;
struct page *page = buf->page;
size_t size;
size = sd->len;
if (rqstp->rq_res.page_len == 0) {
get_page(page);
put_page(*rqstp->rq_next_page);
*(rqstp->rq_next_page++) = page;
rqstp->rq_res.page_base = buf->offset;
rqstp->rq_res.page_len = size;
} else if (page != pp[-1]) {
get_page(page);
if (*rqstp->rq_next_page)
put_page(*rqstp->rq_next_page);
*(rqstp->rq_next_page++) = page;
rqstp->rq_res.page_len += size;
} else
rqstp->rq_res.page_len += size;
return size;
}
static int nfsd_direct_splice_actor(struct pipe_inode_info *pipe,
struct splice_desc *sd)
{
return __splice_from_pipe(pipe, sd, nfsd_splice_actor);
}
static __be32
nfsd_vfs_read(struct svc_rqst *rqstp, struct svc_fh *fhp, struct file *file,
loff_t offset, struct kvec *vec, int vlen, unsigned long *count)
{
mm_segment_t oldfs;
__be32 err;
int host_err;
err = nfserr_perm;
if (file->f_op->splice_read && rqstp->rq_splice_ok) {
struct splice_desc sd = {
.len = 0,
.total_len = *count,
.pos = offset,
.u.data = rqstp,
};
rqstp->rq_next_page = rqstp->rq_respages + 1;
host_err = splice_direct_to_actor(file, &sd, nfsd_direct_splice_actor);
} else {
oldfs = get_fs();
set_fs(KERNEL_DS);
host_err = vfs_readv(file, (struct iovec __user *)vec, vlen, &offset);
set_fs(oldfs);
}
if (host_err >= 0) {
nfsdstats.io_read += host_err;
*count = host_err;
err = 0;
fsnotify_access(file);
} else
err = nfserrno(host_err);
return err;
}
static void kill_suid(struct dentry *dentry)
{
struct iattr ia;
ia.ia_valid = ATTR_KILL_SUID | ATTR_KILL_SGID | ATTR_KILL_PRIV;
mutex_lock(&dentry->d_inode->i_mutex);
notify_change(dentry, &ia);
mutex_unlock(&dentry->d_inode->i_mutex);
}
static int wait_for_concurrent_writes(struct file *file)
{
struct inode *inode = file_inode(file);
static ino_t last_ino;
static dev_t last_dev;
int err = 0;
if (atomic_read(&inode->i_writecount) > 1
|| (last_ino == inode->i_ino && last_dev == inode->i_sb->s_dev)) {
dprintk("nfsd: write defer %d\n", task_pid_nr(current));
msleep(10);
dprintk("nfsd: write resume %d\n", task_pid_nr(current));
}
if (inode->i_state & I_DIRTY) {
dprintk("nfsd: write sync %d\n", task_pid_nr(current));
err = vfs_fsync(file, 0);
}
last_ino = inode->i_ino;
last_dev = inode->i_sb->s_dev;
return err;
}
static __be32
nfsd_vfs_write(struct svc_rqst *rqstp, struct svc_fh *fhp, struct file *file,
loff_t offset, struct kvec *vec, int vlen,
unsigned long *cnt, int *stablep)
{
struct svc_export *exp;
struct dentry *dentry;
struct inode *inode;
mm_segment_t oldfs;
__be32 err = 0;
int host_err;
int stable = *stablep;
int use_wgather;
loff_t pos = offset;
dentry = file->f_path.dentry;
inode = dentry->d_inode;
exp = fhp->fh_export;
use_wgather = (rqstp->rq_vers == 2) && EX_WGATHER(exp);
if (!EX_ISSYNC(exp))
stable = 0;
oldfs = get_fs(); set_fs(KERNEL_DS);
host_err = vfs_writev(file, (struct iovec __user *)vec, vlen, &pos);
set_fs(oldfs);
if (host_err < 0)
goto out_nfserr;
*cnt = host_err;
nfsdstats.io_write += host_err;
fsnotify_modify(file);
if (inode->i_mode & (S_ISUID | S_ISGID))
kill_suid(dentry);
if (stable) {
if (use_wgather)
host_err = wait_for_concurrent_writes(file);
else
host_err = vfs_fsync_range(file, offset, offset+*cnt, 0);
}
out_nfserr:
dprintk("nfsd: write complete host_err=%d\n", host_err);
if (host_err >= 0)
err = 0;
else
err = nfserrno(host_err);
return err;
}
__be32 nfsd_read(struct svc_rqst *rqstp, struct svc_fh *fhp,
loff_t offset, struct kvec *vec, int vlen, unsigned long *count)
{
struct file *file;
struct inode *inode;
struct raparms *ra;
__be32 err;
err = nfsd_open(rqstp, fhp, S_IFREG, NFSD_MAY_READ, &file);
if (err)
return err;
inode = file_inode(file);
ra = nfsd_get_raparms(inode->i_sb->s_dev, inode->i_ino);
if (ra && ra->p_set)
file->f_ra = ra->p_ra;
err = nfsd_vfs_read(rqstp, fhp, file, offset, vec, vlen, count);
if (ra) {
struct raparm_hbucket *rab = &raparm_hash[ra->p_hindex];
spin_lock(&rab->pb_lock);
ra->p_ra = file->f_ra;
ra->p_set = 1;
ra->p_count--;
spin_unlock(&rab->pb_lock);
}
nfsd_close(file);
return err;
}
__be32
nfsd_read_file(struct svc_rqst *rqstp, struct svc_fh *fhp, struct file *file,
loff_t offset, struct kvec *vec, int vlen,
unsigned long *count)
{
__be32 err;
if (file) {
err = nfsd_permission(rqstp, fhp->fh_export, fhp->fh_dentry,
NFSD_MAY_READ|NFSD_MAY_OWNER_OVERRIDE);
if (err)
goto out;
err = nfsd_vfs_read(rqstp, fhp, file, offset, vec, vlen, count);
} else
err = nfsd_read(rqstp, fhp, offset, vec, vlen, count);
out:
return err;
}
__be32
nfsd_write(struct svc_rqst *rqstp, struct svc_fh *fhp, struct file *file,
loff_t offset, struct kvec *vec, int vlen, unsigned long *cnt,
int *stablep)
{
__be32 err = 0;
if (file) {
err = nfsd_permission(rqstp, fhp->fh_export, fhp->fh_dentry,
NFSD_MAY_WRITE|NFSD_MAY_OWNER_OVERRIDE);
if (err)
goto out;
err = nfsd_vfs_write(rqstp, fhp, file, offset, vec, vlen, cnt,
stablep);
} else {
err = nfsd_open(rqstp, fhp, S_IFREG, NFSD_MAY_WRITE, &file);
if (err)
goto out;
if (cnt)
err = nfsd_vfs_write(rqstp, fhp, file, offset, vec, vlen,
cnt, stablep);
nfsd_close(file);
}
out:
return err;
}
__be32
nfsd_commit(struct svc_rqst *rqstp, struct svc_fh *fhp,
loff_t offset, unsigned long count)
{
struct file *file;
loff_t end = LLONG_MAX;
__be32 err = nfserr_inval;
if (offset < 0)
goto out;
if (count != 0) {
end = offset + (loff_t)count - 1;
if (end < offset)
goto out;
}
err = nfsd_open(rqstp, fhp, S_IFREG,
NFSD_MAY_WRITE|NFSD_MAY_NOT_BREAK_LEASE, &file);
if (err)
goto out;
if (EX_ISSYNC(fhp->fh_export)) {
int err2 = vfs_fsync_range(file, offset, end, 0);
if (err2 != -EINVAL)
err = nfserrno(err2);
else
err = nfserr_notsupp;
}
nfsd_close(file);
out:
return err;
}
static __be32
nfsd_create_setattr(struct svc_rqst *rqstp, struct svc_fh *resfhp,
struct iattr *iap)
{
iap->ia_valid &= ~ATTR_MODE;
if (!uid_eq(current_fsuid(), GLOBAL_ROOT_UID))
iap->ia_valid &= ~(ATTR_UID|ATTR_GID);
if (iap->ia_valid)
return nfsd_setattr(rqstp, resfhp, iap, 0, (time_t)0);
return 0;
}
static void
nfsd_check_ignore_resizing(struct iattr *iap)
{
if ((iap->ia_valid & ATTR_SIZE) && (iap->ia_size == 0))
iap->ia_valid &= ~ATTR_SIZE;
}
__be32
nfsd_create(struct svc_rqst *rqstp, struct svc_fh *fhp,
char *fname, int flen, struct iattr *iap,
int type, dev_t rdev, struct svc_fh *resfhp)
{
struct dentry *dentry, *dchild = NULL;
struct inode *dirp;
__be32 err;
__be32 err2;
int host_err;
err = nfserr_perm;
if (!flen)
goto out;
err = nfserr_exist;
if (isdotent(fname, flen))
goto out;
err = fh_verify(rqstp, fhp, S_IFDIR, NFSD_MAY_CREATE);
if (err)
goto out;
dentry = fhp->fh_dentry;
dirp = dentry->d_inode;
err = nfserr_notdir;
if (!dirp->i_op->lookup)
goto out;
if (!resfhp->fh_dentry) {
host_err = fh_want_write(fhp);
if (host_err)
goto out_nfserr;
fh_lock_nested(fhp, I_MUTEX_PARENT);
dchild = lookup_one_len(fname, dentry, flen);
host_err = PTR_ERR(dchild);
if (IS_ERR(dchild))
goto out_nfserr;
err = fh_compose(resfhp, fhp->fh_export, dchild, fhp);
if (err)
goto out;
} else {
dchild = dget(resfhp->fh_dentry);
if (!fhp->fh_locked) {
printk(KERN_ERR
"nfsd_create: parent %s/%s not locked!\n",
dentry->d_parent->d_name.name,
dentry->d_name.name);
err = nfserr_io;
goto out;
}
}
err = nfserr_exist;
if (dchild->d_inode) {
dprintk("nfsd_create: dentry %s/%s not negative!\n",
dentry->d_name.name, dchild->d_name.name);
goto out;
}
if (!(iap->ia_valid & ATTR_MODE))
iap->ia_mode = 0;
iap->ia_mode = (iap->ia_mode & S_IALLUGO) | type;
err = nfserr_inval;
if (!S_ISREG(type) && !S_ISDIR(type) && !special_file(type)) {
printk(KERN_WARNING "nfsd: bad file type %o in nfsd_create\n",
type);
goto out;
}
err = 0;
host_err = 0;
switch (type) {
case S_IFREG:
host_err = vfs_create(dirp, dchild, iap->ia_mode, true);
if (!host_err)
nfsd_check_ignore_resizing(iap);
break;
case S_IFDIR:
host_err = vfs_mkdir(dirp, dchild, iap->ia_mode);
break;
case S_IFCHR:
case S_IFBLK:
case S_IFIFO:
case S_IFSOCK:
host_err = vfs_mknod(dirp, dchild, iap->ia_mode, rdev);
break;
}
if (host_err < 0)
goto out_nfserr;
err = nfsd_create_setattr(rqstp, resfhp, iap);
err2 = nfserrno(commit_metadata(fhp));
if (err2)
err = err2;
if (!err)
err = fh_update(resfhp);
out:
if (dchild && !IS_ERR(dchild))
dput(dchild);
return err;
out_nfserr:
err = nfserrno(host_err);
goto out;
}
static inline int nfsd_create_is_exclusive(int createmode)
{
return createmode == NFS3_CREATE_EXCLUSIVE
|| createmode == NFS4_CREATE_EXCLUSIVE4_1;
}
__be32
do_nfsd_create(struct svc_rqst *rqstp, struct svc_fh *fhp,
char *fname, int flen, struct iattr *iap,
struct svc_fh *resfhp, int createmode, u32 *verifier,
bool *truncp, bool *created)
{
struct dentry *dentry, *dchild = NULL;
struct inode *dirp;
__be32 err;
int host_err;
__u32 v_mtime=0, v_atime=0;
err = nfserr_perm;
if (!flen)
goto out;
err = nfserr_exist;
if (isdotent(fname, flen))
goto out;
if (!(iap->ia_valid & ATTR_MODE))
iap->ia_mode = 0;
err = fh_verify(rqstp, fhp, S_IFDIR, NFSD_MAY_EXEC);
if (err)
goto out;
dentry = fhp->fh_dentry;
dirp = dentry->d_inode;
err = nfserr_notdir;
if (!dirp->i_op->lookup)
goto out;
host_err = fh_want_write(fhp);
if (host_err)
goto out_nfserr;
fh_lock_nested(fhp, I_MUTEX_PARENT);
dchild = lookup_one_len(fname, dentry, flen);
host_err = PTR_ERR(dchild);
if (IS_ERR(dchild))
goto out_nfserr;
if (!dchild->d_inode) {
err = fh_verify(rqstp, fhp, S_IFDIR, NFSD_MAY_CREATE);
if (err)
goto out;
}
err = fh_compose(resfhp, fhp->fh_export, dchild, fhp);
if (err)
goto out;
if (nfsd_create_is_exclusive(createmode)) {
v_mtime = verifier[0]&0x7fffffff;
v_atime = verifier[1]&0x7fffffff;
}
if (dchild->d_inode) {
err = 0;
switch (createmode) {
case NFS3_CREATE_UNCHECKED:
if (! S_ISREG(dchild->d_inode->i_mode))
goto out;
else if (truncp) {
*truncp = (iap->ia_valid & ATTR_SIZE) && !iap->ia_size;
}
else {
iap->ia_valid &= ATTR_SIZE;
goto set_attr;
}
break;
case NFS3_CREATE_EXCLUSIVE:
if ( dchild->d_inode->i_mtime.tv_sec == v_mtime
&& dchild->d_inode->i_atime.tv_sec == v_atime
&& dchild->d_inode->i_size == 0 ) {
if (created)
*created = 1;
break;
}
case NFS4_CREATE_EXCLUSIVE4_1:
if ( dchild->d_inode->i_mtime.tv_sec == v_mtime
&& dchild->d_inode->i_atime.tv_sec == v_atime
&& dchild->d_inode->i_size == 0 ) {
if (created)
*created = 1;
goto set_attr;
}
case NFS3_CREATE_GUARDED:
err = nfserr_exist;
}
fh_drop_write(fhp);
goto out;
}
host_err = vfs_create(dirp, dchild, iap->ia_mode, true);
if (host_err < 0) {
fh_drop_write(fhp);
goto out_nfserr;
}
if (created)
*created = 1;
nfsd_check_ignore_resizing(iap);
if (nfsd_create_is_exclusive(createmode)) {
iap->ia_valid = ATTR_MTIME|ATTR_ATIME
| ATTR_MTIME_SET|ATTR_ATIME_SET;
iap->ia_mtime.tv_sec = v_mtime;
iap->ia_atime.tv_sec = v_atime;
iap->ia_mtime.tv_nsec = 0;
iap->ia_atime.tv_nsec = 0;
}
set_attr:
err = nfsd_create_setattr(rqstp, resfhp, iap);
if (!err)
err = nfserrno(commit_metadata(fhp));
if (!err)
err = fh_update(resfhp);
out:
fh_unlock(fhp);
if (dchild && !IS_ERR(dchild))
dput(dchild);
fh_drop_write(fhp);
return err;
out_nfserr:
err = nfserrno(host_err);
goto out;
}
__be32
nfsd_readlink(struct svc_rqst *rqstp, struct svc_fh *fhp, char *buf, int *lenp)
{
struct inode *inode;
mm_segment_t oldfs;
__be32 err;
int host_err;
struct path path;
err = fh_verify(rqstp, fhp, S_IFLNK, NFSD_MAY_NOP);
if (err)
goto out;
path.mnt = fhp->fh_export->ex_path.mnt;
path.dentry = fhp->fh_dentry;
inode = path.dentry->d_inode;
err = nfserr_inval;
if (!inode->i_op->readlink)
goto out;
touch_atime(&path);
oldfs = get_fs(); set_fs(KERNEL_DS);
host_err = inode->i_op->readlink(path.dentry, (char __user *)buf, *lenp);
set_fs(oldfs);
if (host_err < 0)
goto out_nfserr;
*lenp = host_err;
err = 0;
out:
return err;
out_nfserr:
err = nfserrno(host_err);
goto out;
}
__be32
nfsd_symlink(struct svc_rqst *rqstp, struct svc_fh *fhp,
char *fname, int flen,
char *path, int plen,
struct svc_fh *resfhp,
struct iattr *iap)
{
struct dentry *dentry, *dnew;
__be32 err, cerr;
int host_err;
err = nfserr_noent;
if (!flen || !plen)
goto out;
err = nfserr_exist;
if (isdotent(fname, flen))
goto out;
err = fh_verify(rqstp, fhp, S_IFDIR, NFSD_MAY_CREATE);
if (err)
goto out;
host_err = fh_want_write(fhp);
if (host_err)
goto out_nfserr;
fh_lock(fhp);
dentry = fhp->fh_dentry;
dnew = lookup_one_len(fname, dentry, flen);
host_err = PTR_ERR(dnew);
if (IS_ERR(dnew))
goto out_nfserr;
if (unlikely(path[plen] != 0)) {
char *path_alloced = kmalloc(plen+1, GFP_KERNEL);
if (path_alloced == NULL)
host_err = -ENOMEM;
else {
strncpy(path_alloced, path, plen);
path_alloced[plen] = 0;
host_err = vfs_symlink(dentry->d_inode, dnew, path_alloced);
kfree(path_alloced);
}
} else
host_err = vfs_symlink(dentry->d_inode, dnew, path);
err = nfserrno(host_err);
if (!err)
err = nfserrno(commit_metadata(fhp));
fh_unlock(fhp);
fh_drop_write(fhp);
cerr = fh_compose(resfhp, fhp->fh_export, dnew, fhp);
dput(dnew);
if (err==0) err = cerr;
out:
return err;
out_nfserr:
err = nfserrno(host_err);
goto out;
}
__be32
nfsd_link(struct svc_rqst *rqstp, struct svc_fh *ffhp,
char *name, int len, struct svc_fh *tfhp)
{
struct dentry *ddir, *dnew, *dold;
struct inode *dirp;
__be32 err;
int host_err;
err = fh_verify(rqstp, ffhp, S_IFDIR, NFSD_MAY_CREATE);
if (err)
goto out;
err = fh_verify(rqstp, tfhp, 0, NFSD_MAY_NOP);
if (err)
goto out;
err = nfserr_isdir;
if (S_ISDIR(tfhp->fh_dentry->d_inode->i_mode))
goto out;
err = nfserr_perm;
if (!len)
goto out;
err = nfserr_exist;
if (isdotent(name, len))
goto out;
host_err = fh_want_write(tfhp);
if (host_err) {
err = nfserrno(host_err);
goto out;
}
fh_lock_nested(ffhp, I_MUTEX_PARENT);
ddir = ffhp->fh_dentry;
dirp = ddir->d_inode;
dnew = lookup_one_len(name, ddir, len);
host_err = PTR_ERR(dnew);
if (IS_ERR(dnew))
goto out_nfserr;
dold = tfhp->fh_dentry;
err = nfserr_noent;
if (!dold->d_inode)
goto out_dput;
host_err = nfsd_break_lease(dold->d_inode);
if (host_err) {
err = nfserrno(host_err);
goto out_dput;
}
host_err = vfs_link(dold, dirp, dnew);
if (!host_err) {
err = nfserrno(commit_metadata(ffhp));
if (!err)
err = nfserrno(commit_metadata(tfhp));
} else {
if (host_err == -EXDEV && rqstp->rq_vers == 2)
err = nfserr_acces;
else
err = nfserrno(host_err);
}
out_dput:
dput(dnew);
out_unlock:
fh_unlock(ffhp);
fh_drop_write(tfhp);
out:
return err;
out_nfserr:
err = nfserrno(host_err);
goto out_unlock;
}
__be32
nfsd_rename(struct svc_rqst *rqstp, struct svc_fh *ffhp, char *fname, int flen,
struct svc_fh *tfhp, char *tname, int tlen)
{
struct dentry *fdentry, *tdentry, *odentry, *ndentry, *trap;
struct inode *fdir, *tdir;
__be32 err;
int host_err;
err = fh_verify(rqstp, ffhp, S_IFDIR, NFSD_MAY_REMOVE);
if (err)
goto out;
err = fh_verify(rqstp, tfhp, S_IFDIR, NFSD_MAY_CREATE);
if (err)
goto out;
fdentry = ffhp->fh_dentry;
fdir = fdentry->d_inode;
tdentry = tfhp->fh_dentry;
tdir = tdentry->d_inode;
err = nfserr_perm;
if (!flen || isdotent(fname, flen) || !tlen || isdotent(tname, tlen))
goto out;
host_err = fh_want_write(ffhp);
if (host_err) {
err = nfserrno(host_err);
goto out;
}
trap = lock_rename(tdentry, fdentry);
ffhp->fh_locked = tfhp->fh_locked = 1;
fill_pre_wcc(ffhp);
fill_pre_wcc(tfhp);
odentry = lookup_one_len(fname, fdentry, flen);
host_err = PTR_ERR(odentry);
if (IS_ERR(odentry))
goto out_nfserr;
host_err = -ENOENT;
if (!odentry->d_inode)
goto out_dput_old;
host_err = -EINVAL;
if (odentry == trap)
goto out_dput_old;
ndentry = lookup_one_len(tname, tdentry, tlen);
host_err = PTR_ERR(ndentry);
if (IS_ERR(ndentry))
goto out_dput_old;
host_err = -ENOTEMPTY;
if (ndentry == trap)
goto out_dput_new;
host_err = -EXDEV;
if (ffhp->fh_export->ex_path.mnt != tfhp->fh_export->ex_path.mnt)
goto out_dput_new;
if (ffhp->fh_export->ex_path.dentry != tfhp->fh_export->ex_path.dentry)
goto out_dput_new;
host_err = nfsd_break_lease(odentry->d_inode);
if (host_err)
goto out_dput_new;
if (ndentry->d_inode) {
host_err = nfsd_break_lease(ndentry->d_inode);
if (host_err)
goto out_dput_new;
}
host_err = vfs_rename(fdir, odentry, tdir, ndentry);
if (!host_err) {
host_err = commit_metadata(tfhp);
if (!host_err)
host_err = commit_metadata(ffhp);
}
out_dput_new:
dput(ndentry);
out_dput_old:
dput(odentry);
out_nfserr:
err = nfserrno(host_err);
fill_post_wcc(ffhp);
fill_post_wcc(tfhp);
unlock_rename(tdentry, fdentry);
ffhp->fh_locked = tfhp->fh_locked = 0;
fh_drop_write(ffhp);
out:
return err;
}
__be32
nfsd_unlink(struct svc_rqst *rqstp, struct svc_fh *fhp, int type,
char *fname, int flen)
{
struct dentry *dentry, *rdentry;
struct inode *dirp;
__be32 err;
int host_err;
err = nfserr_acces;
if (!flen || isdotent(fname, flen))
goto out;
err = fh_verify(rqstp, fhp, S_IFDIR, NFSD_MAY_REMOVE);
if (err)
goto out;
host_err = fh_want_write(fhp);
if (host_err)
goto out_nfserr;
fh_lock_nested(fhp, I_MUTEX_PARENT);
dentry = fhp->fh_dentry;
dirp = dentry->d_inode;
rdentry = lookup_one_len(fname, dentry, flen);
host_err = PTR_ERR(rdentry);
if (IS_ERR(rdentry))
goto out_nfserr;
if (!rdentry->d_inode) {
dput(rdentry);
err = nfserr_noent;
goto out;
}
if (!type)
type = rdentry->d_inode->i_mode & S_IFMT;
host_err = nfsd_break_lease(rdentry->d_inode);
if (host_err)
goto out_put;
if (type != S_IFDIR)
host_err = vfs_unlink(dirp, rdentry);
else
host_err = vfs_rmdir(dirp, rdentry);
if (!host_err)
host_err = commit_metadata(fhp);
out_put:
dput(rdentry);
out_nfserr:
err = nfserrno(host_err);
out:
return err;
}
static int nfsd_buffered_filldir(void *__buf, const char *name, int namlen,
loff_t offset, u64 ino, unsigned int d_type)
{
struct readdir_data *buf = __buf;
struct buffered_dirent *de = (void *)(buf->dirent + buf->used);
unsigned int reclen;
reclen = ALIGN(sizeof(struct buffered_dirent) + namlen, sizeof(u64));
if (buf->used + reclen > PAGE_SIZE) {
buf->full = 1;
return -EINVAL;
}
de->namlen = namlen;
de->offset = offset;
de->ino = ino;
de->d_type = d_type;
memcpy(de->name, name, namlen);
buf->used += reclen;
return 0;
}
static __be32 nfsd_buffered_readdir(struct file *file, filldir_t func,
struct readdir_cd *cdp, loff_t *offsetp)
{
struct buffered_dirent *de;
int host_err;
int size;
loff_t offset;
struct readdir_data buf = {
.ctx.actor = nfsd_buffered_filldir,
.dirent = (void *)__get_free_page(GFP_KERNEL)
};
if (!buf.dirent)
return nfserrno(-ENOMEM);
offset = *offsetp;
while (1) {
struct inode *dir_inode = file_inode(file);
unsigned int reclen;
cdp->err = nfserr_eof;
buf.used = 0;
buf.full = 0;
host_err = iterate_dir(file, &buf.ctx);
if (buf.full)
host_err = 0;
if (host_err < 0)
break;
size = buf.used;
if (!size)
break;
host_err = mutex_lock_killable(&dir_inode->i_mutex);
if (host_err)
break;
de = (struct buffered_dirent *)buf.dirent;
while (size > 0) {
offset = de->offset;
if (func(cdp, de->name, de->namlen, de->offset,
de->ino, de->d_type))
break;
if (cdp->err != nfs_ok)
break;
reclen = ALIGN(sizeof(*de) + de->namlen,
sizeof(u64));
size -= reclen;
de = (struct buffered_dirent *)((char *)de + reclen);
}
mutex_unlock(&dir_inode->i_mutex);
if (size > 0)
break;
offset = vfs_llseek(file, 0, SEEK_CUR);
}
free_page((unsigned long)(buf.dirent));
if (host_err)
return nfserrno(host_err);
*offsetp = offset;
return cdp->err;
}
__be32
nfsd_readdir(struct svc_rqst *rqstp, struct svc_fh *fhp, loff_t *offsetp,
struct readdir_cd *cdp, filldir_t func)
{
__be32 err;
struct file *file;
loff_t offset = *offsetp;
int may_flags = NFSD_MAY_READ;
if (rqstp->rq_vers > 2)
may_flags |= NFSD_MAY_64BIT_COOKIE;
err = nfsd_open(rqstp, fhp, S_IFDIR, may_flags, &file);
if (err)
goto out;
offset = vfs_llseek(file, offset, SEEK_SET);
if (offset < 0) {
err = nfserrno((int)offset);
goto out_close;
}
err = nfsd_buffered_readdir(file, func, cdp, offsetp);
if (err == nfserr_eof || err == nfserr_toosmall)
err = nfs_ok;
out_close:
nfsd_close(file);
out:
return err;
}
__be32
nfsd_statfs(struct svc_rqst *rqstp, struct svc_fh *fhp, struct kstatfs *stat, int access)
{
__be32 err;
err = fh_verify(rqstp, fhp, 0, NFSD_MAY_NOP | access);
if (!err) {
struct path path = {
.mnt = fhp->fh_export->ex_path.mnt,
.dentry = fhp->fh_dentry,
};
if (vfs_statfs(&path, stat))
err = nfserr_io;
}
return err;
}
static int exp_rdonly(struct svc_rqst *rqstp, struct svc_export *exp)
{
return nfsexp_flags(rqstp, exp) & NFSEXP_READONLY;
}
__be32
nfsd_permission(struct svc_rqst *rqstp, struct svc_export *exp,
struct dentry *dentry, int acc)
{
struct inode *inode = dentry->d_inode;
int err;
if ((acc & NFSD_MAY_MASK) == NFSD_MAY_NOP)
return 0;
#if 0
dprintk("nfsd: permission 0x%x%s%s%s%s%s%s%s mode 0%o%s%s%s\n",
acc,
(acc & NFSD_MAY_READ)? " read" : "",
(acc & NFSD_MAY_WRITE)? " write" : "",
(acc & NFSD_MAY_EXEC)? " exec" : "",
(acc & NFSD_MAY_SATTR)? " sattr" : "",
(acc & NFSD_MAY_TRUNC)? " trunc" : "",
(acc & NFSD_MAY_LOCK)? " lock" : "",
(acc & NFSD_MAY_OWNER_OVERRIDE)? " owneroverride" : "",
inode->i_mode,
IS_IMMUTABLE(inode)? " immut" : "",
IS_APPEND(inode)? " append" : "",
__mnt_is_readonly(exp->ex_path.mnt)? " ro" : "");
dprintk(" owner %d/%d user %d/%d\n",
inode->i_uid, inode->i_gid, current_fsuid(), current_fsgid());
#endif
if (!(acc & NFSD_MAY_LOCAL_ACCESS))
if (acc & (NFSD_MAY_WRITE | NFSD_MAY_SATTR | NFSD_MAY_TRUNC)) {
if (exp_rdonly(rqstp, exp) ||
__mnt_is_readonly(exp->ex_path.mnt))
return nfserr_rofs;
if ( IS_IMMUTABLE(inode))
return nfserr_perm;
}
if ((acc & NFSD_MAY_TRUNC) && IS_APPEND(inode))
return nfserr_perm;
if (acc & NFSD_MAY_LOCK) {
if (exp->ex_flags & NFSEXP_NOAUTHNLM)
return 0;
else
acc = NFSD_MAY_READ | NFSD_MAY_OWNER_OVERRIDE;
}
if ((acc & NFSD_MAY_OWNER_OVERRIDE) &&
uid_eq(inode->i_uid, current_fsuid()))
return 0;
err = inode_permission(inode, acc & (MAY_READ|MAY_WRITE|MAY_EXEC));
if (err == -EACCES && S_ISREG(inode->i_mode) &&
(acc == (NFSD_MAY_READ | NFSD_MAY_OWNER_OVERRIDE) ||
acc == (NFSD_MAY_READ | NFSD_MAY_READ_IF_EXEC)))
err = inode_permission(inode, MAY_EXEC);
return err? nfserrno(err) : 0;
}
void
nfsd_racache_shutdown(void)
{
struct raparms *raparm, *last_raparm;
unsigned int i;
dprintk("nfsd: freeing readahead buffers.\n");
for (i = 0; i < RAPARM_HASH_SIZE; i++) {
raparm = raparm_hash[i].pb_head;
while(raparm) {
last_raparm = raparm;
raparm = raparm->p_next;
kfree(last_raparm);
}
raparm_hash[i].pb_head = NULL;
}
}
int
nfsd_racache_init(int cache_size)
{
int i;
int j = 0;
int nperbucket;
struct raparms **raparm = NULL;
if (raparm_hash[0].pb_head)
return 0;
nperbucket = DIV_ROUND_UP(cache_size, RAPARM_HASH_SIZE);
if (nperbucket < 2)
nperbucket = 2;
cache_size = nperbucket * RAPARM_HASH_SIZE;
dprintk("nfsd: allocating %d readahead buffers.\n", cache_size);
for (i = 0; i < RAPARM_HASH_SIZE; i++) {
spin_lock_init(&raparm_hash[i].pb_lock);
raparm = &raparm_hash[i].pb_head;
for (j = 0; j < nperbucket; j++) {
*raparm = kzalloc(sizeof(struct raparms), GFP_KERNEL);
if (!*raparm)
goto out_nomem;
raparm = &(*raparm)->p_next;
}
*raparm = NULL;
}
nfsdstats.ra_size = cache_size;
return 0;
out_nomem:
dprintk("nfsd: kmalloc failed, freeing readahead buffers\n");
nfsd_racache_shutdown();
return -ENOMEM;
}
struct posix_acl *
nfsd_get_posix_acl(struct svc_fh *fhp, int type)
{
struct inode *inode = fhp->fh_dentry->d_inode;
char *name;
void *value = NULL;
ssize_t size;
struct posix_acl *acl;
if (!IS_POSIXACL(inode))
return ERR_PTR(-EOPNOTSUPP);
switch (type) {
case ACL_TYPE_ACCESS:
name = POSIX_ACL_XATTR_ACCESS;
break;
case ACL_TYPE_DEFAULT:
name = POSIX_ACL_XATTR_DEFAULT;
break;
default:
return ERR_PTR(-EOPNOTSUPP);
}
size = nfsd_getxattr(fhp->fh_dentry, name, &value);
if (size < 0)
return ERR_PTR(size);
acl = posix_acl_from_xattr(&init_user_ns, value, size);
kfree(value);
return acl;
}
int
nfsd_set_posix_acl(struct svc_fh *fhp, int type, struct posix_acl *acl)
{
struct inode *inode = fhp->fh_dentry->d_inode;
char *name;
void *value = NULL;
size_t size;
int error;
if (!IS_POSIXACL(inode) ||
!inode->i_op->setxattr || !inode->i_op->removexattr)
return -EOPNOTSUPP;
switch(type) {
case ACL_TYPE_ACCESS:
name = POSIX_ACL_XATTR_ACCESS;
break;
case ACL_TYPE_DEFAULT:
name = POSIX_ACL_XATTR_DEFAULT;
break;
default:
return -EOPNOTSUPP;
}
if (acl && acl->a_count) {
size = posix_acl_xattr_size(acl->a_count);
value = kmalloc(size, GFP_KERNEL);
if (!value)
return -ENOMEM;
error = posix_acl_to_xattr(&init_user_ns, acl, value, size);
if (error < 0)
goto getout;
size = error;
} else
size = 0;
error = fh_want_write(fhp);
if (error)
goto getout;
if (size)
error = vfs_setxattr(fhp->fh_dentry, name, value, size, 0);
else {
if (!S_ISDIR(inode->i_mode) && type == ACL_TYPE_DEFAULT)
error = 0;
else {
error = vfs_removexattr(fhp->fh_dentry, name);
if (error == -ENODATA)
error = 0;
}
}
fh_drop_write(fhp);
getout:
kfree(value);
return error;
}
