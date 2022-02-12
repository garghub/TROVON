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
xfs_trans_inode_broot_debug(ip);
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
}
if ((flags & XFS_ICHGTIME_CHG) &&
!timespec_equal(&inode->i_ctime, &tv)) {
inode->i_ctime = tv;
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
tp->t_flags |= XFS_TRANS_DIRTY;
ip->i_itemp->ili_item.li_desc->lid_flags |= XFS_LID_DIRTY;
flags |= ip->i_itemp->ili_last_fields;
ip->i_itemp->ili_format.ilf_fields |= flags;
}
STATIC void
xfs_trans_inode_broot_debug(
xfs_inode_t *ip)
{
xfs_inode_log_item_t *iip;
ASSERT(ip->i_itemp != NULL);
iip = ip->i_itemp;
if (iip->ili_root_size != 0) {
ASSERT(iip->ili_orig_root != NULL);
kmem_free(iip->ili_orig_root);
iip->ili_root_size = 0;
iip->ili_orig_root = NULL;
}
if (ip->i_d.di_format == XFS_DINODE_FMT_BTREE) {
ASSERT((ip->i_df.if_broot != NULL) &&
(ip->i_df.if_broot_bytes > 0));
iip->ili_root_size = ip->i_df.if_broot_bytes;
iip->ili_orig_root =
(char*)kmem_alloc(iip->ili_root_size, KM_SLEEP);
memcpy(iip->ili_orig_root, (char*)(ip->i_df.if_broot),
iip->ili_root_size);
}
}
