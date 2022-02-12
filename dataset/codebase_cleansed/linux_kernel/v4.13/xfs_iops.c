static int
xfs_initxattrs(
struct inode *inode,
const struct xattr *xattr_array,
void *fs_info)
{
const struct xattr *xattr;
struct xfs_inode *ip = XFS_I(inode);
int error = 0;
for (xattr = xattr_array; xattr->name != NULL; xattr++) {
error = xfs_attr_set(ip, xattr->name, xattr->value,
xattr->value_len, ATTR_SECURE);
if (error < 0)
break;
}
return error;
}
STATIC int
xfs_init_security(
struct inode *inode,
struct inode *dir,
const struct qstr *qstr)
{
return security_inode_init_security(inode, dir, qstr,
&xfs_initxattrs, NULL);
}
static void
xfs_dentry_to_name(
struct xfs_name *namep,
struct dentry *dentry)
{
namep->name = dentry->d_name.name;
namep->len = dentry->d_name.len;
namep->type = XFS_DIR3_FT_UNKNOWN;
}
static int
xfs_dentry_mode_to_name(
struct xfs_name *namep,
struct dentry *dentry,
int mode)
{
namep->name = dentry->d_name.name;
namep->len = dentry->d_name.len;
namep->type = xfs_mode_to_ftype(mode);
if (unlikely(namep->type == XFS_DIR3_FT_UNKNOWN))
return -EFSCORRUPTED;
return 0;
}
STATIC void
xfs_cleanup_inode(
struct inode *dir,
struct inode *inode,
struct dentry *dentry)
{
struct xfs_name teardown;
xfs_dentry_to_name(&teardown, dentry);
xfs_remove(XFS_I(dir), &teardown, XFS_I(inode));
}
STATIC int
xfs_generic_create(
struct inode *dir,
struct dentry *dentry,
umode_t mode,
dev_t rdev,
bool tmpfile)
{
struct inode *inode;
struct xfs_inode *ip = NULL;
struct posix_acl *default_acl, *acl;
struct xfs_name name;
int error;
if (S_ISCHR(mode) || S_ISBLK(mode)) {
if (unlikely(!sysv_valid_dev(rdev) || MAJOR(rdev) & ~0x1ff))
return -EINVAL;
rdev = sysv_encode_dev(rdev);
} else {
rdev = 0;
}
error = posix_acl_create(dir, &mode, &default_acl, &acl);
if (error)
return error;
error = xfs_dentry_mode_to_name(&name, dentry, mode);
if (unlikely(error))
goto out_free_acl;
if (!tmpfile) {
error = xfs_create(XFS_I(dir), &name, mode, rdev, &ip);
} else {
error = xfs_create_tmpfile(XFS_I(dir), dentry, mode, &ip);
}
if (unlikely(error))
goto out_free_acl;
inode = VFS_I(ip);
error = xfs_init_security(inode, dir, &dentry->d_name);
if (unlikely(error))
goto out_cleanup_inode;
#ifdef CONFIG_XFS_POSIX_ACL
if (default_acl) {
error = __xfs_set_acl(inode, default_acl, ACL_TYPE_DEFAULT);
if (error)
goto out_cleanup_inode;
}
if (acl) {
error = __xfs_set_acl(inode, acl, ACL_TYPE_ACCESS);
if (error)
goto out_cleanup_inode;
}
#endif
xfs_setup_iops(ip);
if (tmpfile)
d_tmpfile(dentry, inode);
else
d_instantiate(dentry, inode);
xfs_finish_inode_setup(ip);
out_free_acl:
if (default_acl)
posix_acl_release(default_acl);
if (acl)
posix_acl_release(acl);
return error;
out_cleanup_inode:
xfs_finish_inode_setup(ip);
if (!tmpfile)
xfs_cleanup_inode(dir, inode, dentry);
iput(inode);
goto out_free_acl;
}
STATIC int
xfs_vn_mknod(
struct inode *dir,
struct dentry *dentry,
umode_t mode,
dev_t rdev)
{
return xfs_generic_create(dir, dentry, mode, rdev, false);
}
STATIC int
xfs_vn_create(
struct inode *dir,
struct dentry *dentry,
umode_t mode,
bool flags)
{
return xfs_vn_mknod(dir, dentry, mode, 0);
}
STATIC int
xfs_vn_mkdir(
struct inode *dir,
struct dentry *dentry,
umode_t mode)
{
return xfs_vn_mknod(dir, dentry, mode|S_IFDIR, 0);
}
STATIC struct dentry *
xfs_vn_lookup(
struct inode *dir,
struct dentry *dentry,
unsigned int flags)
{
struct xfs_inode *cip;
struct xfs_name name;
int error;
if (dentry->d_name.len >= MAXNAMELEN)
return ERR_PTR(-ENAMETOOLONG);
xfs_dentry_to_name(&name, dentry);
error = xfs_lookup(XFS_I(dir), &name, &cip, NULL);
if (unlikely(error)) {
if (unlikely(error != -ENOENT))
return ERR_PTR(error);
d_add(dentry, NULL);
return NULL;
}
return d_splice_alias(VFS_I(cip), dentry);
}
STATIC struct dentry *
xfs_vn_ci_lookup(
struct inode *dir,
struct dentry *dentry,
unsigned int flags)
{
struct xfs_inode *ip;
struct xfs_name xname;
struct xfs_name ci_name;
struct qstr dname;
int error;
if (dentry->d_name.len >= MAXNAMELEN)
return ERR_PTR(-ENAMETOOLONG);
xfs_dentry_to_name(&xname, dentry);
error = xfs_lookup(XFS_I(dir), &xname, &ip, &ci_name);
if (unlikely(error)) {
if (unlikely(error != -ENOENT))
return ERR_PTR(error);
return NULL;
}
if (!ci_name.name)
return d_splice_alias(VFS_I(ip), dentry);
dname.name = ci_name.name;
dname.len = ci_name.len;
dentry = d_add_ci(dentry, VFS_I(ip), &dname);
kmem_free(ci_name.name);
return dentry;
}
STATIC int
xfs_vn_link(
struct dentry *old_dentry,
struct inode *dir,
struct dentry *dentry)
{
struct inode *inode = d_inode(old_dentry);
struct xfs_name name;
int error;
error = xfs_dentry_mode_to_name(&name, dentry, inode->i_mode);
if (unlikely(error))
return error;
error = xfs_link(XFS_I(dir), XFS_I(inode), &name);
if (unlikely(error))
return error;
ihold(inode);
d_instantiate(dentry, inode);
return 0;
}
STATIC int
xfs_vn_unlink(
struct inode *dir,
struct dentry *dentry)
{
struct xfs_name name;
int error;
xfs_dentry_to_name(&name, dentry);
error = xfs_remove(XFS_I(dir), &name, XFS_I(d_inode(dentry)));
if (error)
return error;
if (xfs_sb_version_hasasciici(&XFS_M(dir->i_sb)->m_sb))
d_invalidate(dentry);
return 0;
}
STATIC int
xfs_vn_symlink(
struct inode *dir,
struct dentry *dentry,
const char *symname)
{
struct inode *inode;
struct xfs_inode *cip = NULL;
struct xfs_name name;
int error;
umode_t mode;
mode = S_IFLNK |
(irix_symlink_mode ? 0777 & ~current_umask() : S_IRWXUGO);
error = xfs_dentry_mode_to_name(&name, dentry, mode);
if (unlikely(error))
goto out;
error = xfs_symlink(XFS_I(dir), &name, symname, mode, &cip);
if (unlikely(error))
goto out;
inode = VFS_I(cip);
error = xfs_init_security(inode, dir, &dentry->d_name);
if (unlikely(error))
goto out_cleanup_inode;
xfs_setup_iops(cip);
d_instantiate(dentry, inode);
xfs_finish_inode_setup(cip);
return 0;
out_cleanup_inode:
xfs_finish_inode_setup(cip);
xfs_cleanup_inode(dir, inode, dentry);
iput(inode);
out:
return error;
}
STATIC int
xfs_vn_rename(
struct inode *odir,
struct dentry *odentry,
struct inode *ndir,
struct dentry *ndentry,
unsigned int flags)
{
struct inode *new_inode = d_inode(ndentry);
int omode = 0;
int error;
struct xfs_name oname;
struct xfs_name nname;
if (flags & ~(RENAME_NOREPLACE | RENAME_EXCHANGE | RENAME_WHITEOUT))
return -EINVAL;
if (flags & RENAME_EXCHANGE)
omode = d_inode(ndentry)->i_mode;
error = xfs_dentry_mode_to_name(&oname, odentry, omode);
if (omode && unlikely(error))
return error;
error = xfs_dentry_mode_to_name(&nname, ndentry,
d_inode(odentry)->i_mode);
if (unlikely(error))
return error;
return xfs_rename(XFS_I(odir), &oname, XFS_I(d_inode(odentry)),
XFS_I(ndir), &nname,
new_inode ? XFS_I(new_inode) : NULL, flags);
}
STATIC const char *
xfs_vn_get_link(
struct dentry *dentry,
struct inode *inode,
struct delayed_call *done)
{
char *link;
int error = -ENOMEM;
if (!dentry)
return ERR_PTR(-ECHILD);
link = kmalloc(XFS_SYMLINK_MAXLEN+1, GFP_KERNEL);
if (!link)
goto out_err;
error = xfs_readlink(XFS_I(d_inode(dentry)), link);
if (unlikely(error))
goto out_kfree;
set_delayed_call(done, kfree_link, link);
return link;
out_kfree:
kfree(link);
out_err:
return ERR_PTR(error);
}
STATIC const char *
xfs_vn_get_link_inline(
struct dentry *dentry,
struct inode *inode,
struct delayed_call *done)
{
ASSERT(XFS_I(inode)->i_df.if_flags & XFS_IFINLINE);
return XFS_I(inode)->i_df.if_u1.if_data;
}
STATIC int
xfs_vn_getattr(
const struct path *path,
struct kstat *stat,
u32 request_mask,
unsigned int query_flags)
{
struct inode *inode = d_inode(path->dentry);
struct xfs_inode *ip = XFS_I(inode);
struct xfs_mount *mp = ip->i_mount;
trace_xfs_getattr(ip);
if (XFS_FORCED_SHUTDOWN(mp))
return -EIO;
stat->size = XFS_ISIZE(ip);
stat->dev = inode->i_sb->s_dev;
stat->mode = inode->i_mode;
stat->nlink = inode->i_nlink;
stat->uid = inode->i_uid;
stat->gid = inode->i_gid;
stat->ino = ip->i_ino;
stat->atime = inode->i_atime;
stat->mtime = inode->i_mtime;
stat->ctime = inode->i_ctime;
stat->blocks =
XFS_FSB_TO_BB(mp, ip->i_d.di_nblocks + ip->i_delayed_blks);
if (ip->i_d.di_version == 3) {
if (request_mask & STATX_BTIME) {
stat->result_mask |= STATX_BTIME;
stat->btime.tv_sec = ip->i_d.di_crtime.t_sec;
stat->btime.tv_nsec = ip->i_d.di_crtime.t_nsec;
}
}
if (ip->i_d.di_flags & XFS_DIFLAG_IMMUTABLE)
stat->attributes |= STATX_ATTR_IMMUTABLE;
if (ip->i_d.di_flags & XFS_DIFLAG_APPEND)
stat->attributes |= STATX_ATTR_APPEND;
if (ip->i_d.di_flags & XFS_DIFLAG_NODUMP)
stat->attributes |= STATX_ATTR_NODUMP;
switch (inode->i_mode & S_IFMT) {
case S_IFBLK:
case S_IFCHR:
stat->blksize = BLKDEV_IOSIZE;
stat->rdev = MKDEV(sysv_major(ip->i_df.if_u2.if_rdev) & 0x1ff,
sysv_minor(ip->i_df.if_u2.if_rdev));
break;
default:
if (XFS_IS_REALTIME_INODE(ip)) {
stat->blksize =
xfs_get_extsz_hint(ip) << mp->m_sb.sb_blocklog;
} else
stat->blksize = xfs_preferred_iosize(mp);
stat->rdev = 0;
break;
}
return 0;
}
static void
xfs_setattr_mode(
struct xfs_inode *ip,
struct iattr *iattr)
{
struct inode *inode = VFS_I(ip);
umode_t mode = iattr->ia_mode;
ASSERT(xfs_isilocked(ip, XFS_ILOCK_EXCL));
inode->i_mode &= S_IFMT;
inode->i_mode |= mode & ~S_IFMT;
}
void
xfs_setattr_time(
struct xfs_inode *ip,
struct iattr *iattr)
{
struct inode *inode = VFS_I(ip);
ASSERT(xfs_isilocked(ip, XFS_ILOCK_EXCL));
if (iattr->ia_valid & ATTR_ATIME)
inode->i_atime = iattr->ia_atime;
if (iattr->ia_valid & ATTR_CTIME)
inode->i_ctime = iattr->ia_ctime;
if (iattr->ia_valid & ATTR_MTIME)
inode->i_mtime = iattr->ia_mtime;
}
static int
xfs_vn_change_ok(
struct dentry *dentry,
struct iattr *iattr)
{
struct xfs_mount *mp = XFS_I(d_inode(dentry))->i_mount;
if (mp->m_flags & XFS_MOUNT_RDONLY)
return -EROFS;
if (XFS_FORCED_SHUTDOWN(mp))
return -EIO;
return setattr_prepare(dentry, iattr);
}
int
xfs_setattr_nonsize(
struct xfs_inode *ip,
struct iattr *iattr,
int flags)
{
xfs_mount_t *mp = ip->i_mount;
struct inode *inode = VFS_I(ip);
int mask = iattr->ia_valid;
xfs_trans_t *tp;
int error;
kuid_t uid = GLOBAL_ROOT_UID, iuid = GLOBAL_ROOT_UID;
kgid_t gid = GLOBAL_ROOT_GID, igid = GLOBAL_ROOT_GID;
struct xfs_dquot *udqp = NULL, *gdqp = NULL;
struct xfs_dquot *olddquot1 = NULL, *olddquot2 = NULL;
ASSERT((mask & ATTR_SIZE) == 0);
if (XFS_IS_QUOTA_ON(mp) && (mask & (ATTR_UID|ATTR_GID))) {
uint qflags = 0;
if ((mask & ATTR_UID) && XFS_IS_UQUOTA_ON(mp)) {
uid = iattr->ia_uid;
qflags |= XFS_QMOPT_UQUOTA;
} else {
uid = inode->i_uid;
}
if ((mask & ATTR_GID) && XFS_IS_GQUOTA_ON(mp)) {
gid = iattr->ia_gid;
qflags |= XFS_QMOPT_GQUOTA;
} else {
gid = inode->i_gid;
}
ASSERT(udqp == NULL);
ASSERT(gdqp == NULL);
error = xfs_qm_vop_dqalloc(ip, xfs_kuid_to_uid(uid),
xfs_kgid_to_gid(gid),
xfs_get_projid(ip),
qflags, &udqp, &gdqp, NULL);
if (error)
return error;
}
error = xfs_trans_alloc(mp, &M_RES(mp)->tr_ichange, 0, 0, 0, &tp);
if (error)
goto out_dqrele;
xfs_ilock(ip, XFS_ILOCK_EXCL);
xfs_trans_ijoin(tp, ip, 0);
if (mask & (ATTR_UID|ATTR_GID)) {
iuid = inode->i_uid;
igid = inode->i_gid;
gid = (mask & ATTR_GID) ? iattr->ia_gid : igid;
uid = (mask & ATTR_UID) ? iattr->ia_uid : iuid;
if (XFS_IS_QUOTA_RUNNING(mp) &&
((XFS_IS_UQUOTA_ON(mp) && !uid_eq(iuid, uid)) ||
(XFS_IS_GQUOTA_ON(mp) && !gid_eq(igid, gid)))) {
ASSERT(tp);
error = xfs_qm_vop_chown_reserve(tp, ip, udqp, gdqp,
NULL, capable(CAP_FOWNER) ?
XFS_QMOPT_FORCE_RES : 0);
if (error)
goto out_cancel;
}
}
if (mask & (ATTR_UID|ATTR_GID)) {
if ((inode->i_mode & (S_ISUID|S_ISGID)) &&
!capable(CAP_FSETID))
inode->i_mode &= ~(S_ISUID|S_ISGID);
if (!uid_eq(iuid, uid)) {
if (XFS_IS_QUOTA_RUNNING(mp) && XFS_IS_UQUOTA_ON(mp)) {
ASSERT(mask & ATTR_UID);
ASSERT(udqp);
olddquot1 = xfs_qm_vop_chown(tp, ip,
&ip->i_udquot, udqp);
}
ip->i_d.di_uid = xfs_kuid_to_uid(uid);
inode->i_uid = uid;
}
if (!gid_eq(igid, gid)) {
if (XFS_IS_QUOTA_RUNNING(mp) && XFS_IS_GQUOTA_ON(mp)) {
ASSERT(xfs_sb_version_has_pquotino(&mp->m_sb) ||
!XFS_IS_PQUOTA_ON(mp));
ASSERT(mask & ATTR_GID);
ASSERT(gdqp);
olddquot2 = xfs_qm_vop_chown(tp, ip,
&ip->i_gdquot, gdqp);
}
ip->i_d.di_gid = xfs_kgid_to_gid(gid);
inode->i_gid = gid;
}
}
if (mask & ATTR_MODE)
xfs_setattr_mode(ip, iattr);
if (mask & (ATTR_ATIME|ATTR_CTIME|ATTR_MTIME))
xfs_setattr_time(ip, iattr);
xfs_trans_log_inode(tp, ip, XFS_ILOG_CORE);
XFS_STATS_INC(mp, xs_ig_attrchg);
if (mp->m_flags & XFS_MOUNT_WSYNC)
xfs_trans_set_sync(tp);
error = xfs_trans_commit(tp);
xfs_iunlock(ip, XFS_ILOCK_EXCL);
xfs_qm_dqrele(olddquot1);
xfs_qm_dqrele(olddquot2);
xfs_qm_dqrele(udqp);
xfs_qm_dqrele(gdqp);
if (error)
return error;
if ((mask & ATTR_MODE) && !(flags & XFS_ATTR_NOACL)) {
error = posix_acl_chmod(inode, inode->i_mode);
if (error)
return error;
}
return 0;
out_cancel:
xfs_trans_cancel(tp);
out_dqrele:
xfs_qm_dqrele(udqp);
xfs_qm_dqrele(gdqp);
return error;
}
int
xfs_vn_setattr_nonsize(
struct dentry *dentry,
struct iattr *iattr)
{
struct xfs_inode *ip = XFS_I(d_inode(dentry));
int error;
trace_xfs_setattr(ip);
error = xfs_vn_change_ok(dentry, iattr);
if (error)
return error;
return xfs_setattr_nonsize(ip, iattr, 0);
}
int
xfs_setattr_size(
struct xfs_inode *ip,
struct iattr *iattr)
{
struct xfs_mount *mp = ip->i_mount;
struct inode *inode = VFS_I(ip);
xfs_off_t oldsize, newsize;
struct xfs_trans *tp;
int error;
uint lock_flags = 0;
bool did_zeroing = false;
ASSERT(xfs_isilocked(ip, XFS_IOLOCK_EXCL));
ASSERT(xfs_isilocked(ip, XFS_MMAPLOCK_EXCL));
ASSERT(S_ISREG(inode->i_mode));
ASSERT((iattr->ia_valid & (ATTR_UID|ATTR_GID|ATTR_ATIME|ATTR_ATIME_SET|
ATTR_MTIME_SET|ATTR_KILL_PRIV|ATTR_TIMES_SET)) == 0);
oldsize = inode->i_size;
newsize = iattr->ia_size;
if (newsize == 0 && oldsize == 0 && ip->i_d.di_nextents == 0) {
if (!(iattr->ia_valid & (ATTR_CTIME|ATTR_MTIME)))
return 0;
iattr->ia_valid &= ~ATTR_SIZE;
return xfs_setattr_nonsize(ip, iattr, 0);
}
error = xfs_qm_dqattach(ip, 0);
if (error)
return error;
inode_dio_wait(inode);
if (newsize > oldsize) {
error = xfs_zero_eof(ip, newsize, oldsize, &did_zeroing);
} else {
error = iomap_truncate_page(inode, newsize, &did_zeroing,
&xfs_iomap_ops);
}
if (error)
return error;
if (did_zeroing ||
(newsize > ip->i_d.di_size && oldsize != ip->i_d.di_size)) {
error = filemap_write_and_wait_range(VFS_I(ip)->i_mapping,
ip->i_d.di_size, newsize);
if (error)
return error;
}
truncate_setsize(inode, newsize);
error = xfs_trans_alloc(mp, &M_RES(mp)->tr_itruncate, 0, 0, 0, &tp);
if (error)
return error;
lock_flags |= XFS_ILOCK_EXCL;
xfs_ilock(ip, XFS_ILOCK_EXCL);
xfs_trans_ijoin(tp, ip, 0);
if (newsize != oldsize &&
!(iattr->ia_valid & (ATTR_CTIME | ATTR_MTIME))) {
iattr->ia_ctime = iattr->ia_mtime =
current_time(inode);
iattr->ia_valid |= ATTR_CTIME | ATTR_MTIME;
}
ip->i_d.di_size = newsize;
xfs_trans_log_inode(tp, ip, XFS_ILOG_CORE);
if (newsize <= oldsize) {
error = xfs_itruncate_extents(&tp, ip, XFS_DATA_FORK, newsize);
if (error)
goto out_trans_cancel;
xfs_iflags_set(ip, XFS_ITRUNCATED);
xfs_inode_clear_eofblocks_tag(ip);
}
if (iattr->ia_valid & ATTR_MODE)
xfs_setattr_mode(ip, iattr);
if (iattr->ia_valid & (ATTR_ATIME|ATTR_CTIME|ATTR_MTIME))
xfs_setattr_time(ip, iattr);
xfs_trans_log_inode(tp, ip, XFS_ILOG_CORE);
XFS_STATS_INC(mp, xs_ig_attrchg);
if (mp->m_flags & XFS_MOUNT_WSYNC)
xfs_trans_set_sync(tp);
error = xfs_trans_commit(tp);
out_unlock:
if (lock_flags)
xfs_iunlock(ip, lock_flags);
return error;
out_trans_cancel:
xfs_trans_cancel(tp);
goto out_unlock;
}
int
xfs_vn_setattr_size(
struct dentry *dentry,
struct iattr *iattr)
{
struct xfs_inode *ip = XFS_I(d_inode(dentry));
int error;
trace_xfs_setattr(ip);
error = xfs_vn_change_ok(dentry, iattr);
if (error)
return error;
return xfs_setattr_size(ip, iattr);
}
STATIC int
xfs_vn_setattr(
struct dentry *dentry,
struct iattr *iattr)
{
int error;
if (iattr->ia_valid & ATTR_SIZE) {
struct xfs_inode *ip = XFS_I(d_inode(dentry));
uint iolock = XFS_IOLOCK_EXCL;
error = xfs_break_layouts(d_inode(dentry), &iolock);
if (error)
return error;
xfs_ilock(ip, XFS_MMAPLOCK_EXCL);
error = xfs_vn_setattr_size(dentry, iattr);
xfs_iunlock(ip, XFS_MMAPLOCK_EXCL);
} else {
error = xfs_vn_setattr_nonsize(dentry, iattr);
}
return error;
}
STATIC int
xfs_vn_update_time(
struct inode *inode,
struct timespec *now,
int flags)
{
struct xfs_inode *ip = XFS_I(inode);
struct xfs_mount *mp = ip->i_mount;
struct xfs_trans *tp;
int error;
trace_xfs_update_time(ip);
error = xfs_trans_alloc(mp, &M_RES(mp)->tr_fsyncts, 0, 0, 0, &tp);
if (error)
return error;
xfs_ilock(ip, XFS_ILOCK_EXCL);
if (flags & S_CTIME)
inode->i_ctime = *now;
if (flags & S_MTIME)
inode->i_mtime = *now;
if (flags & S_ATIME)
inode->i_atime = *now;
xfs_trans_ijoin(tp, ip, XFS_ILOCK_EXCL);
xfs_trans_log_inode(tp, ip, XFS_ILOG_TIMESTAMP);
return xfs_trans_commit(tp);
}
STATIC int
xfs_vn_fiemap(
struct inode *inode,
struct fiemap_extent_info *fieinfo,
u64 start,
u64 length)
{
int error;
xfs_ilock(XFS_I(inode), XFS_IOLOCK_SHARED);
if (fieinfo->fi_flags & FIEMAP_FLAG_XATTR) {
fieinfo->fi_flags &= ~FIEMAP_FLAG_XATTR;
error = iomap_fiemap(inode, fieinfo, start, length,
&xfs_xattr_iomap_ops);
} else {
error = iomap_fiemap(inode, fieinfo, start, length,
&xfs_iomap_ops);
}
xfs_iunlock(XFS_I(inode), XFS_IOLOCK_SHARED);
return error;
}
STATIC int
xfs_vn_tmpfile(
struct inode *dir,
struct dentry *dentry,
umode_t mode)
{
return xfs_generic_create(dir, dentry, mode, 0, true);
}
STATIC void
xfs_diflags_to_iflags(
struct inode *inode,
struct xfs_inode *ip)
{
uint16_t flags = ip->i_d.di_flags;
inode->i_flags &= ~(S_IMMUTABLE | S_APPEND | S_SYNC |
S_NOATIME | S_DAX);
if (flags & XFS_DIFLAG_IMMUTABLE)
inode->i_flags |= S_IMMUTABLE;
if (flags & XFS_DIFLAG_APPEND)
inode->i_flags |= S_APPEND;
if (flags & XFS_DIFLAG_SYNC)
inode->i_flags |= S_SYNC;
if (flags & XFS_DIFLAG_NOATIME)
inode->i_flags |= S_NOATIME;
if (S_ISREG(inode->i_mode) &&
ip->i_mount->m_sb.sb_blocksize == PAGE_SIZE &&
!xfs_is_reflink_inode(ip) &&
(ip->i_mount->m_flags & XFS_MOUNT_DAX ||
ip->i_d.di_flags2 & XFS_DIFLAG2_DAX))
inode->i_flags |= S_DAX;
}
void
xfs_setup_inode(
struct xfs_inode *ip)
{
struct inode *inode = &ip->i_vnode;
gfp_t gfp_mask;
inode->i_ino = ip->i_ino;
inode->i_state = I_NEW;
inode_sb_list_add(inode);
hlist_add_fake(&inode->i_hash);
inode->i_uid = xfs_uid_to_kuid(ip->i_d.di_uid);
inode->i_gid = xfs_gid_to_kgid(ip->i_d.di_gid);
switch (inode->i_mode & S_IFMT) {
case S_IFBLK:
case S_IFCHR:
inode->i_rdev =
MKDEV(sysv_major(ip->i_df.if_u2.if_rdev) & 0x1ff,
sysv_minor(ip->i_df.if_u2.if_rdev));
break;
default:
inode->i_rdev = 0;
break;
}
i_size_write(inode, ip->i_d.di_size);
xfs_diflags_to_iflags(inode, ip);
if (S_ISDIR(inode->i_mode)) {
lockdep_set_class(&ip->i_lock.mr_lock, &xfs_dir_ilock_class);
ip->d_ops = ip->i_mount->m_dir_inode_ops;
} else {
ip->d_ops = ip->i_mount->m_nondir_inode_ops;
lockdep_set_class(&ip->i_lock.mr_lock, &xfs_nondir_ilock_class);
}
gfp_mask = mapping_gfp_mask(inode->i_mapping);
mapping_set_gfp_mask(inode->i_mapping, (gfp_mask & ~(__GFP_FS)));
if (!XFS_IFORK_Q(ip)) {
inode_has_no_xattr(inode);
cache_no_acl(inode);
}
}
void
xfs_setup_iops(
struct xfs_inode *ip)
{
struct inode *inode = &ip->i_vnode;
switch (inode->i_mode & S_IFMT) {
case S_IFREG:
inode->i_op = &xfs_inode_operations;
inode->i_fop = &xfs_file_operations;
inode->i_mapping->a_ops = &xfs_address_space_operations;
break;
case S_IFDIR:
if (xfs_sb_version_hasasciici(&XFS_M(inode->i_sb)->m_sb))
inode->i_op = &xfs_dir_ci_inode_operations;
else
inode->i_op = &xfs_dir_inode_operations;
inode->i_fop = &xfs_dir_file_operations;
break;
case S_IFLNK:
if (ip->i_df.if_flags & XFS_IFINLINE)
inode->i_op = &xfs_inline_symlink_inode_operations;
else
inode->i_op = &xfs_symlink_inode_operations;
break;
default:
inode->i_op = &xfs_inode_operations;
init_special_inode(inode, inode->i_mode, inode->i_rdev);
break;
}
}
