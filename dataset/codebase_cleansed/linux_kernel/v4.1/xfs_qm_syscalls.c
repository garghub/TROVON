int
xfs_qm_scall_quotaoff(
xfs_mount_t *mp,
uint flags)
{
struct xfs_quotainfo *q = mp->m_quotainfo;
uint dqtype;
int error;
uint inactivate_flags;
xfs_qoff_logitem_t *qoffstart;
if ((mp->m_qflags & flags) == 0)
return -EEXIST;
error = 0;
flags &= (XFS_ALL_QUOTA_ACCT | XFS_ALL_QUOTA_ENFD);
ASSERT(q);
mutex_lock(&q->qi_quotaofflock);
if ((flags & XFS_ALL_QUOTA_ACCT) == 0) {
mp->m_qflags &= ~(flags);
spin_lock(&mp->m_sb_lock);
mp->m_sb.sb_qflags = mp->m_qflags;
spin_unlock(&mp->m_sb_lock);
mutex_unlock(&q->qi_quotaofflock);
return xfs_sync_sb(mp, false);
}
dqtype = 0;
inactivate_flags = 0;
if (flags & XFS_UQUOTA_ACCT) {
dqtype |= XFS_QMOPT_UQUOTA;
flags |= (XFS_UQUOTA_CHKD | XFS_UQUOTA_ENFD);
inactivate_flags |= XFS_UQUOTA_ACTIVE;
}
if (flags & XFS_GQUOTA_ACCT) {
dqtype |= XFS_QMOPT_GQUOTA;
flags |= (XFS_GQUOTA_CHKD | XFS_GQUOTA_ENFD);
inactivate_flags |= XFS_GQUOTA_ACTIVE;
}
if (flags & XFS_PQUOTA_ACCT) {
dqtype |= XFS_QMOPT_PQUOTA;
flags |= (XFS_PQUOTA_CHKD | XFS_PQUOTA_ENFD);
inactivate_flags |= XFS_PQUOTA_ACTIVE;
}
if ((mp->m_qflags & flags) == 0)
goto out_unlock;
error = xfs_qm_log_quotaoff(mp, &qoffstart, flags);
if (error)
goto out_unlock;
mp->m_qflags &= ~inactivate_flags;
xfs_qm_dqrele_all_inodes(mp, flags);
mp->m_qflags &= ~flags;
xfs_qm_dqpurge_all(mp, dqtype);
error = xfs_qm_log_quotaoff_end(mp, qoffstart, flags);
if (error) {
xfs_force_shutdown(mp, SHUTDOWN_CORRUPT_INCORE);
goto out_unlock;
}
if (mp->m_qflags == 0) {
mutex_unlock(&q->qi_quotaofflock);
xfs_qm_destroy_quotainfo(mp);
return 0;
}
if ((dqtype & XFS_QMOPT_UQUOTA) && q->qi_uquotaip) {
IRELE(q->qi_uquotaip);
q->qi_uquotaip = NULL;
}
if ((dqtype & XFS_QMOPT_GQUOTA) && q->qi_gquotaip) {
IRELE(q->qi_gquotaip);
q->qi_gquotaip = NULL;
}
if ((dqtype & XFS_QMOPT_PQUOTA) && q->qi_pquotaip) {
IRELE(q->qi_pquotaip);
q->qi_pquotaip = NULL;
}
out_unlock:
mutex_unlock(&q->qi_quotaofflock);
return error;
}
STATIC int
xfs_qm_scall_trunc_qfile(
struct xfs_mount *mp,
xfs_ino_t ino)
{
struct xfs_inode *ip;
struct xfs_trans *tp;
int error;
if (ino == NULLFSINO)
return 0;
error = xfs_iget(mp, NULL, ino, 0, 0, &ip);
if (error)
return error;
xfs_ilock(ip, XFS_IOLOCK_EXCL);
tp = xfs_trans_alloc(mp, XFS_TRANS_TRUNCATE_FILE);
error = xfs_trans_reserve(tp, &M_RES(mp)->tr_itruncate, 0, 0);
if (error) {
xfs_trans_cancel(tp, 0);
xfs_iunlock(ip, XFS_IOLOCK_EXCL);
goto out_put;
}
xfs_ilock(ip, XFS_ILOCK_EXCL);
xfs_trans_ijoin(tp, ip, 0);
ip->i_d.di_size = 0;
xfs_trans_log_inode(tp, ip, XFS_ILOG_CORE);
error = xfs_itruncate_extents(&tp, ip, XFS_DATA_FORK, 0);
if (error) {
xfs_trans_cancel(tp, XFS_TRANS_RELEASE_LOG_RES |
XFS_TRANS_ABORT);
goto out_unlock;
}
ASSERT(ip->i_d.di_nextents == 0);
xfs_trans_ichgtime(tp, ip, XFS_ICHGTIME_MOD | XFS_ICHGTIME_CHG);
error = xfs_trans_commit(tp, XFS_TRANS_RELEASE_LOG_RES);
out_unlock:
xfs_iunlock(ip, XFS_ILOCK_EXCL | XFS_IOLOCK_EXCL);
out_put:
IRELE(ip);
return error;
}
int
xfs_qm_scall_trunc_qfiles(
xfs_mount_t *mp,
uint flags)
{
int error = -EINVAL;
if (!xfs_sb_version_hasquota(&mp->m_sb) || flags == 0 ||
(flags & ~XFS_DQ_ALLTYPES)) {
xfs_debug(mp, "%s: flags=%x m_qflags=%x",
__func__, flags, mp->m_qflags);
return -EINVAL;
}
if (flags & XFS_DQ_USER) {
error = xfs_qm_scall_trunc_qfile(mp, mp->m_sb.sb_uquotino);
if (error)
return error;
}
if (flags & XFS_DQ_GROUP) {
error = xfs_qm_scall_trunc_qfile(mp, mp->m_sb.sb_gquotino);
if (error)
return error;
}
if (flags & XFS_DQ_PROJ)
error = xfs_qm_scall_trunc_qfile(mp, mp->m_sb.sb_pquotino);
return error;
}
int
xfs_qm_scall_quotaon(
xfs_mount_t *mp,
uint flags)
{
int error;
uint qf;
flags &= (XFS_ALL_QUOTA_ACCT | XFS_ALL_QUOTA_ENFD);
flags &= ~(XFS_ALL_QUOTA_ACCT);
if (flags == 0) {
xfs_debug(mp, "%s: zero flags, m_qflags=%x",
__func__, mp->m_qflags);
return -EINVAL;
}
if (((mp->m_sb.sb_qflags & XFS_UQUOTA_ACCT) == 0 &&
(flags & XFS_UQUOTA_ENFD)) ||
((mp->m_sb.sb_qflags & XFS_GQUOTA_ACCT) == 0 &&
(flags & XFS_GQUOTA_ENFD)) ||
((mp->m_sb.sb_qflags & XFS_PQUOTA_ACCT) == 0 &&
(flags & XFS_PQUOTA_ENFD))) {
xfs_debug(mp,
"%s: Can't enforce without acct, flags=%x sbflags=%x",
__func__, flags, mp->m_sb.sb_qflags);
return -EINVAL;
}
if ((mp->m_qflags & flags) == flags)
return -EEXIST;
spin_lock(&mp->m_sb_lock);
qf = mp->m_sb.sb_qflags;
mp->m_sb.sb_qflags = qf | flags;
spin_unlock(&mp->m_sb_lock);
if ((qf & flags) == flags)
return -EEXIST;
error = xfs_sync_sb(mp, false);
if (error)
return error;
if (((mp->m_sb.sb_qflags & XFS_UQUOTA_ACCT) !=
(mp->m_qflags & XFS_UQUOTA_ACCT)) ||
((mp->m_sb.sb_qflags & XFS_PQUOTA_ACCT) !=
(mp->m_qflags & XFS_PQUOTA_ACCT)) ||
((mp->m_sb.sb_qflags & XFS_GQUOTA_ACCT) !=
(mp->m_qflags & XFS_GQUOTA_ACCT)))
return 0;
if (! XFS_IS_QUOTA_RUNNING(mp))
return -ESRCH;
mutex_lock(&mp->m_quotainfo->qi_quotaofflock);
mp->m_qflags |= (flags & XFS_ALL_QUOTA_ENFD);
mutex_unlock(&mp->m_quotainfo->qi_quotaofflock);
return 0;
}
int
xfs_qm_scall_setqlim(
struct xfs_mount *mp,
xfs_dqid_t id,
uint type,
struct qc_dqblk *newlim)
{
struct xfs_quotainfo *q = mp->m_quotainfo;
struct xfs_disk_dquot *ddq;
struct xfs_dquot *dqp;
struct xfs_trans *tp;
int error;
xfs_qcnt_t hard, soft;
if (newlim->d_fieldmask & ~XFS_QC_MASK)
return -EINVAL;
if ((newlim->d_fieldmask & XFS_QC_MASK) == 0)
return 0;
mutex_lock(&q->qi_quotaofflock);
error = xfs_qm_dqget(mp, NULL, id, type, XFS_QMOPT_DQALLOC, &dqp);
if (error) {
ASSERT(error != -ENOENT);
goto out_unlock;
}
xfs_dqunlock(dqp);
tp = xfs_trans_alloc(mp, XFS_TRANS_QM_SETQLIM);
error = xfs_trans_reserve(tp, &M_RES(mp)->tr_qm_setqlim, 0, 0);
if (error) {
xfs_trans_cancel(tp, 0);
goto out_rele;
}
xfs_dqlock(dqp);
xfs_trans_dqjoin(tp, dqp);
ddq = &dqp->q_core;
hard = (newlim->d_fieldmask & QC_SPC_HARD) ?
(xfs_qcnt_t) XFS_B_TO_FSB(mp, newlim->d_spc_hardlimit) :
be64_to_cpu(ddq->d_blk_hardlimit);
soft = (newlim->d_fieldmask & QC_SPC_SOFT) ?
(xfs_qcnt_t) XFS_B_TO_FSB(mp, newlim->d_spc_softlimit) :
be64_to_cpu(ddq->d_blk_softlimit);
if (hard == 0 || hard >= soft) {
ddq->d_blk_hardlimit = cpu_to_be64(hard);
ddq->d_blk_softlimit = cpu_to_be64(soft);
xfs_dquot_set_prealloc_limits(dqp);
if (id == 0) {
q->qi_bhardlimit = hard;
q->qi_bsoftlimit = soft;
}
} else {
xfs_debug(mp, "blkhard %Ld < blksoft %Ld", hard, soft);
}
hard = (newlim->d_fieldmask & QC_RT_SPC_HARD) ?
(xfs_qcnt_t) XFS_B_TO_FSB(mp, newlim->d_rt_spc_hardlimit) :
be64_to_cpu(ddq->d_rtb_hardlimit);
soft = (newlim->d_fieldmask & QC_RT_SPC_SOFT) ?
(xfs_qcnt_t) XFS_B_TO_FSB(mp, newlim->d_rt_spc_softlimit) :
be64_to_cpu(ddq->d_rtb_softlimit);
if (hard == 0 || hard >= soft) {
ddq->d_rtb_hardlimit = cpu_to_be64(hard);
ddq->d_rtb_softlimit = cpu_to_be64(soft);
if (id == 0) {
q->qi_rtbhardlimit = hard;
q->qi_rtbsoftlimit = soft;
}
} else {
xfs_debug(mp, "rtbhard %Ld < rtbsoft %Ld", hard, soft);
}
hard = (newlim->d_fieldmask & QC_INO_HARD) ?
(xfs_qcnt_t) newlim->d_ino_hardlimit :
be64_to_cpu(ddq->d_ino_hardlimit);
soft = (newlim->d_fieldmask & QC_INO_SOFT) ?
(xfs_qcnt_t) newlim->d_ino_softlimit :
be64_to_cpu(ddq->d_ino_softlimit);
if (hard == 0 || hard >= soft) {
ddq->d_ino_hardlimit = cpu_to_be64(hard);
ddq->d_ino_softlimit = cpu_to_be64(soft);
if (id == 0) {
q->qi_ihardlimit = hard;
q->qi_isoftlimit = soft;
}
} else {
xfs_debug(mp, "ihard %Ld < isoft %Ld", hard, soft);
}
if (newlim->d_fieldmask & QC_SPC_WARNS)
ddq->d_bwarns = cpu_to_be16(newlim->d_spc_warns);
if (newlim->d_fieldmask & QC_INO_WARNS)
ddq->d_iwarns = cpu_to_be16(newlim->d_ino_warns);
if (newlim->d_fieldmask & QC_RT_SPC_WARNS)
ddq->d_rtbwarns = cpu_to_be16(newlim->d_rt_spc_warns);
if (id == 0) {
if (newlim->d_fieldmask & QC_SPC_TIMER) {
q->qi_btimelimit = newlim->d_spc_timer;
ddq->d_btimer = cpu_to_be32(newlim->d_spc_timer);
}
if (newlim->d_fieldmask & QC_INO_TIMER) {
q->qi_itimelimit = newlim->d_ino_timer;
ddq->d_itimer = cpu_to_be32(newlim->d_ino_timer);
}
if (newlim->d_fieldmask & QC_RT_SPC_TIMER) {
q->qi_rtbtimelimit = newlim->d_rt_spc_timer;
ddq->d_rtbtimer = cpu_to_be32(newlim->d_rt_spc_timer);
}
if (newlim->d_fieldmask & QC_SPC_WARNS)
q->qi_bwarnlimit = newlim->d_spc_warns;
if (newlim->d_fieldmask & QC_INO_WARNS)
q->qi_iwarnlimit = newlim->d_ino_warns;
if (newlim->d_fieldmask & QC_RT_SPC_WARNS)
q->qi_rtbwarnlimit = newlim->d_rt_spc_warns;
} else {
xfs_qm_adjust_dqtimers(mp, ddq);
}
dqp->dq_flags |= XFS_DQ_DIRTY;
xfs_trans_log_dquot(tp, dqp);
error = xfs_trans_commit(tp, 0);
out_rele:
xfs_qm_dqrele(dqp);
out_unlock:
mutex_unlock(&q->qi_quotaofflock);
return error;
}
STATIC int
xfs_qm_log_quotaoff_end(
xfs_mount_t *mp,
xfs_qoff_logitem_t *startqoff,
uint flags)
{
xfs_trans_t *tp;
int error;
xfs_qoff_logitem_t *qoffi;
tp = xfs_trans_alloc(mp, XFS_TRANS_QM_QUOTAOFF_END);
error = xfs_trans_reserve(tp, &M_RES(mp)->tr_qm_equotaoff, 0, 0);
if (error) {
xfs_trans_cancel(tp, 0);
return error;
}
qoffi = xfs_trans_get_qoff_item(tp, startqoff,
flags & XFS_ALL_QUOTA_ACCT);
xfs_trans_log_quotaoff_item(tp, qoffi);
xfs_trans_set_sync(tp);
error = xfs_trans_commit(tp, 0);
return error;
}
STATIC int
xfs_qm_log_quotaoff(
xfs_mount_t *mp,
xfs_qoff_logitem_t **qoffstartp,
uint flags)
{
xfs_trans_t *tp;
int error;
xfs_qoff_logitem_t *qoffi;
*qoffstartp = NULL;
tp = xfs_trans_alloc(mp, XFS_TRANS_QM_QUOTAOFF);
error = xfs_trans_reserve(tp, &M_RES(mp)->tr_qm_quotaoff, 0, 0);
if (error) {
xfs_trans_cancel(tp, 0);
goto out;
}
qoffi = xfs_trans_get_qoff_item(tp, NULL, flags & XFS_ALL_QUOTA_ACCT);
xfs_trans_log_quotaoff_item(tp, qoffi);
spin_lock(&mp->m_sb_lock);
mp->m_sb.sb_qflags = (mp->m_qflags & ~(flags)) & XFS_MOUNT_QUOTA_ALL;
spin_unlock(&mp->m_sb_lock);
xfs_log_sb(tp);
xfs_trans_set_sync(tp);
error = xfs_trans_commit(tp, 0);
if (error)
goto out;
*qoffstartp = qoffi;
out:
return error;
}
int
xfs_qm_scall_getquota(
struct xfs_mount *mp,
xfs_dqid_t id,
uint type,
struct qc_dqblk *dst)
{
struct xfs_dquot *dqp;
int error;
error = xfs_qm_dqget(mp, NULL, id, type, 0, &dqp);
if (error)
return error;
if (XFS_IS_DQUOT_UNINITIALIZED(dqp)) {
error = -ENOENT;
goto out_put;
}
memset(dst, 0, sizeof(*dst));
dst->d_spc_hardlimit =
XFS_FSB_TO_B(mp, be64_to_cpu(dqp->q_core.d_blk_hardlimit));
dst->d_spc_softlimit =
XFS_FSB_TO_B(mp, be64_to_cpu(dqp->q_core.d_blk_softlimit));
dst->d_ino_hardlimit = be64_to_cpu(dqp->q_core.d_ino_hardlimit);
dst->d_ino_softlimit = be64_to_cpu(dqp->q_core.d_ino_softlimit);
dst->d_space = XFS_FSB_TO_B(mp, dqp->q_res_bcount);
dst->d_ino_count = dqp->q_res_icount;
dst->d_spc_timer = be32_to_cpu(dqp->q_core.d_btimer);
dst->d_ino_timer = be32_to_cpu(dqp->q_core.d_itimer);
dst->d_ino_warns = be16_to_cpu(dqp->q_core.d_iwarns);
dst->d_spc_warns = be16_to_cpu(dqp->q_core.d_bwarns);
dst->d_rt_spc_hardlimit =
XFS_FSB_TO_B(mp, be64_to_cpu(dqp->q_core.d_rtb_hardlimit));
dst->d_rt_spc_softlimit =
XFS_FSB_TO_B(mp, be64_to_cpu(dqp->q_core.d_rtb_softlimit));
dst->d_rt_space = XFS_FSB_TO_B(mp, dqp->q_res_rtbcount);
dst->d_rt_spc_timer = be32_to_cpu(dqp->q_core.d_rtbtimer);
dst->d_rt_spc_warns = be16_to_cpu(dqp->q_core.d_rtbwarns);
if ((!XFS_IS_UQUOTA_ENFORCED(mp) &&
dqp->q_core.d_flags == XFS_DQ_USER) ||
(!XFS_IS_GQUOTA_ENFORCED(mp) &&
dqp->q_core.d_flags == XFS_DQ_GROUP) ||
(!XFS_IS_PQUOTA_ENFORCED(mp) &&
dqp->q_core.d_flags == XFS_DQ_PROJ)) {
dst->d_spc_timer = 0;
dst->d_ino_timer = 0;
dst->d_rt_spc_timer = 0;
}
#ifdef DEBUG
if (((XFS_IS_UQUOTA_ENFORCED(mp) && type == XFS_DQ_USER) ||
(XFS_IS_GQUOTA_ENFORCED(mp) && type == XFS_DQ_GROUP) ||
(XFS_IS_PQUOTA_ENFORCED(mp) && type == XFS_DQ_PROJ)) &&
id != 0) {
if ((dst->d_space > dst->d_spc_softlimit) &&
(dst->d_spc_softlimit > 0)) {
ASSERT(dst->d_spc_timer != 0);
}
if ((dst->d_ino_count > dst->d_ino_softlimit) &&
(dst->d_ino_softlimit > 0)) {
ASSERT(dst->d_ino_timer != 0);
}
}
#endif
out_put:
xfs_qm_dqput(dqp);
return error;
}
STATIC int
xfs_dqrele_inode(
struct xfs_inode *ip,
int flags,
void *args)
{
if (ip == ip->i_mount->m_quotainfo->qi_uquotaip ||
ip == ip->i_mount->m_quotainfo->qi_gquotaip ||
ip == ip->i_mount->m_quotainfo->qi_pquotaip) {
ASSERT(ip->i_udquot == NULL);
ASSERT(ip->i_gdquot == NULL);
ASSERT(ip->i_pdquot == NULL);
return 0;
}
xfs_ilock(ip, XFS_ILOCK_EXCL);
if ((flags & XFS_UQUOTA_ACCT) && ip->i_udquot) {
xfs_qm_dqrele(ip->i_udquot);
ip->i_udquot = NULL;
}
if ((flags & XFS_GQUOTA_ACCT) && ip->i_gdquot) {
xfs_qm_dqrele(ip->i_gdquot);
ip->i_gdquot = NULL;
}
if ((flags & XFS_PQUOTA_ACCT) && ip->i_pdquot) {
xfs_qm_dqrele(ip->i_pdquot);
ip->i_pdquot = NULL;
}
xfs_iunlock(ip, XFS_ILOCK_EXCL);
return 0;
}
void
xfs_qm_dqrele_all_inodes(
struct xfs_mount *mp,
uint flags)
{
ASSERT(mp->m_quotainfo);
xfs_inode_ag_iterator(mp, xfs_dqrele_inode, flags, NULL);
}
