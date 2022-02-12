void
xfs_trans_ijoin(
struct xfs_trans *tp,
struct xfs_inode *ip,
uint lock_flags)
{
xfs_inode_log_item_t *iip;
ASSERT(xfs_isilocked(ip, XFS_ILOCK_EXCL));
if (ip->i_itemp == NULL)
xfs_inode_item_init(ip, ip->i_mount);
iip = ip->i_itemp;
ASSERT(iip->ili_lock_flags == 0);
iip->ili_lock_flags = lock_flags;
xfs_trans_add_item(tp, &iip->ili_item);
}
void
xfs_trans_ichgtime(
struct xfs_trans *tp,
struct xfs_inode *ip,
int flags)
{
struct inode *inode = VFS_I(ip);
timespec_t tv;
ASSERT(tp);
ASSERT(xfs_isilocked(ip, XFS_ILOCK_EXCL));
tv = current_fs_time(inode->i_sb);
if ((flags & XFS_ICHGTIME_MOD) &&
!timespec_equal(&inode->i_mtime, &tv)) {
inode->i_mtime = tv;
ip->i_d.di_mtime.t_sec = tv.tv_sec;
ip->i_d.di_mtime.t_nsec = tv.tv_nsec;
}
if ((flags & XFS_ICHGTIME_CHG) &&
!timespec_equal(&inode->i_ctime, &tv)) {
inode->i_ctime = tv;
ip->i_d.di_ctime.t_sec = tv.tv_sec;
ip->i_d.di_ctime.t_nsec = tv.tv_nsec;
}
}
void
xfs_trans_log_inode(
xfs_trans_t *tp,
xfs_inode_t *ip,
uint flags)
{
ASSERT(ip->i_itemp != NULL);
ASSERT(xfs_isilocked(ip, XFS_ILOCK_EXCL));
if (!(ip->i_itemp->ili_item.li_desc->lid_flags & XFS_LID_DIRTY) &&
IS_I_VERSION(VFS_I(ip))) {
inode_inc_iversion(VFS_I(ip));
ip->i_d.di_changecount = VFS_I(ip)->i_version;
flags |= XFS_ILOG_CORE;
}
tp->t_flags |= XFS_TRANS_DIRTY;
ip->i_itemp->ili_item.li_desc->lid_flags |= XFS_LID_DIRTY;
flags |= ip->i_itemp->ili_last_fields;
ip->i_itemp->ili_fields |= flags;
}
