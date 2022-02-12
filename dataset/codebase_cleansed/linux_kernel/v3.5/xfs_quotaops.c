STATIC int
xfs_quota_type(int type)
{
switch (type) {
case USRQUOTA:
return XFS_DQ_USER;
case GRPQUOTA:
return XFS_DQ_GROUP;
default:
return XFS_DQ_PROJ;
}
}
STATIC int
xfs_fs_get_xstate(
struct super_block *sb,
struct fs_quota_stat *fqs)
{
struct xfs_mount *mp = XFS_M(sb);
if (!XFS_IS_QUOTA_RUNNING(mp))
return -ENOSYS;
return -xfs_qm_scall_getqstat(mp, fqs);
}
STATIC int
xfs_fs_set_xstate(
struct super_block *sb,
unsigned int uflags,
int op)
{
struct xfs_mount *mp = XFS_M(sb);
unsigned int flags = 0;
if (sb->s_flags & MS_RDONLY)
return -EROFS;
if (op != Q_XQUOTARM && !XFS_IS_QUOTA_RUNNING(mp))
return -ENOSYS;
if (uflags & FS_QUOTA_UDQ_ACCT)
flags |= XFS_UQUOTA_ACCT;
if (uflags & FS_QUOTA_PDQ_ACCT)
flags |= XFS_PQUOTA_ACCT;
if (uflags & FS_QUOTA_GDQ_ACCT)
flags |= XFS_GQUOTA_ACCT;
if (uflags & FS_QUOTA_UDQ_ENFD)
flags |= XFS_UQUOTA_ENFD;
if (uflags & (FS_QUOTA_PDQ_ENFD|FS_QUOTA_GDQ_ENFD))
flags |= XFS_OQUOTA_ENFD;
switch (op) {
case Q_XQUOTAON:
return -xfs_qm_scall_quotaon(mp, flags);
case Q_XQUOTAOFF:
if (!XFS_IS_QUOTA_ON(mp))
return -EINVAL;
return -xfs_qm_scall_quotaoff(mp, flags);
case Q_XQUOTARM:
if (XFS_IS_QUOTA_ON(mp))
return -EINVAL;
return -xfs_qm_scall_trunc_qfiles(mp, flags);
}
return -EINVAL;
}
STATIC int
xfs_fs_get_dqblk(
struct super_block *sb,
int type,
qid_t id,
struct fs_disk_quota *fdq)
{
struct xfs_mount *mp = XFS_M(sb);
if (!XFS_IS_QUOTA_RUNNING(mp))
return -ENOSYS;
if (!XFS_IS_QUOTA_ON(mp))
return -ESRCH;
return -xfs_qm_scall_getquota(mp, id, xfs_quota_type(type), fdq);
}
STATIC int
xfs_fs_set_dqblk(
struct super_block *sb,
int type,
qid_t id,
struct fs_disk_quota *fdq)
{
struct xfs_mount *mp = XFS_M(sb);
if (sb->s_flags & MS_RDONLY)
return -EROFS;
if (!XFS_IS_QUOTA_RUNNING(mp))
return -ENOSYS;
if (!XFS_IS_QUOTA_ON(mp))
return -ESRCH;
return -xfs_qm_scall_setqlim(mp, id, xfs_quota_type(type), fdq);
}
