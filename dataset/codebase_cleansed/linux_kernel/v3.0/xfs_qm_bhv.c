STATIC void
xfs_fill_statvfs_from_dquot(
struct kstatfs *statp,
xfs_disk_dquot_t *dp)
{
__uint64_t limit;
limit = dp->d_blk_softlimit ?
be64_to_cpu(dp->d_blk_softlimit) :
be64_to_cpu(dp->d_blk_hardlimit);
if (limit && statp->f_blocks > limit) {
statp->f_blocks = limit;
statp->f_bfree = statp->f_bavail =
(statp->f_blocks > be64_to_cpu(dp->d_bcount)) ?
(statp->f_blocks - be64_to_cpu(dp->d_bcount)) : 0;
}
limit = dp->d_ino_softlimit ?
be64_to_cpu(dp->d_ino_softlimit) :
be64_to_cpu(dp->d_ino_hardlimit);
if (limit && statp->f_files > limit) {
statp->f_files = limit;
statp->f_ffree =
(statp->f_files > be64_to_cpu(dp->d_icount)) ?
(statp->f_ffree - be64_to_cpu(dp->d_icount)) : 0;
}
}
void
xfs_qm_statvfs(
xfs_inode_t *ip,
struct kstatfs *statp)
{
xfs_mount_t *mp = ip->i_mount;
xfs_dquot_t *dqp;
if (!xfs_qm_dqget(mp, NULL, xfs_get_projid(ip), XFS_DQ_PROJ, 0, &dqp)) {
xfs_fill_statvfs_from_dquot(statp, &dqp->q_core);
xfs_qm_dqput(dqp);
}
}
int
xfs_qm_newmount(
xfs_mount_t *mp,
uint *needquotamount,
uint *quotaflags)
{
uint quotaondisk;
uint uquotaondisk = 0, gquotaondisk = 0, pquotaondisk = 0;
quotaondisk = xfs_sb_version_hasquota(&mp->m_sb) &&
(mp->m_sb.sb_qflags & XFS_ALL_QUOTA_ACCT);
if (quotaondisk) {
uquotaondisk = mp->m_sb.sb_qflags & XFS_UQUOTA_ACCT;
pquotaondisk = mp->m_sb.sb_qflags & XFS_PQUOTA_ACCT;
gquotaondisk = mp->m_sb.sb_qflags & XFS_GQUOTA_ACCT;
}
if (((uquotaondisk && !XFS_IS_UQUOTA_ON(mp)) ||
(!uquotaondisk && XFS_IS_UQUOTA_ON(mp)) ||
(pquotaondisk && !XFS_IS_PQUOTA_ON(mp)) ||
(!pquotaondisk && XFS_IS_PQUOTA_ON(mp)) ||
(gquotaondisk && !XFS_IS_GQUOTA_ON(mp)) ||
(!gquotaondisk && XFS_IS_OQUOTA_ON(mp))) &&
xfs_dev_is_read_only(mp, "changing quota state")) {
xfs_warn(mp, "please mount with%s%s%s%s.",
(!quotaondisk ? "out quota" : ""),
(uquotaondisk ? " usrquota" : ""),
(pquotaondisk ? " prjquota" : ""),
(gquotaondisk ? " grpquota" : ""));
return XFS_ERROR(EPERM);
}
if (XFS_IS_QUOTA_ON(mp) || quotaondisk) {
if (quotaondisk && !XFS_QM_NEED_QUOTACHECK(mp)) {
xfs_qm_mount_quotas(mp);
} else {
*needquotamount = B_TRUE;
*quotaflags = mp->m_qflags;
mp->m_qflags = 0;
}
}
return 0;
}
void __init
xfs_qm_init(void)
{
printk(KERN_INFO "SGI XFS Quota Management subsystem\n");
mutex_init(&xfs_Gqm_lock);
xfs_qm_init_procfs();
}
void __exit
xfs_qm_exit(void)
{
xfs_qm_cleanup_procfs();
if (qm_dqzone)
kmem_zone_destroy(qm_dqzone);
if (qm_dqtrxzone)
kmem_zone_destroy(qm_dqtrxzone);
}
