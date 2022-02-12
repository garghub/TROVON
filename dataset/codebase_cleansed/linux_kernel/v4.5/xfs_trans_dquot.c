void
xfs_trans_dqjoin(
xfs_trans_t *tp,
xfs_dquot_t *dqp)
{
ASSERT(dqp->q_transp != tp);
ASSERT(XFS_DQ_IS_LOCKED(dqp));
ASSERT(dqp->q_logitem.qli_dquot == dqp);
xfs_trans_add_item(tp, &dqp->q_logitem.qli_item);
dqp->q_transp = tp;
}
void
xfs_trans_log_dquot(
xfs_trans_t *tp,
xfs_dquot_t *dqp)
{
ASSERT(dqp->q_transp == tp);
ASSERT(XFS_DQ_IS_LOCKED(dqp));
tp->t_flags |= XFS_TRANS_DIRTY;
dqp->q_logitem.qli_item.li_desc->lid_flags |= XFS_LID_DIRTY;
}
void
xfs_trans_dup_dqinfo(
xfs_trans_t *otp,
xfs_trans_t *ntp)
{
xfs_dqtrx_t *oq, *nq;
int i, j;
xfs_dqtrx_t *oqa, *nqa;
ulong blk_res_used;
if (!otp->t_dqinfo)
return;
xfs_trans_alloc_dqinfo(ntp);
if (otp->t_flags & XFS_TRANS_DQ_DIRTY)
ntp->t_flags |= XFS_TRANS_DQ_DIRTY;
for (j = 0; j < XFS_QM_TRANS_DQTYPES; j++) {
oqa = otp->t_dqinfo->dqs[j];
nqa = ntp->t_dqinfo->dqs[j];
for (i = 0; i < XFS_QM_TRANS_MAXDQS; i++) {
blk_res_used = 0;
if (oqa[i].qt_dquot == NULL)
break;
oq = &oqa[i];
nq = &nqa[i];
if (oq->qt_blk_res && oq->qt_bcount_delta > 0)
blk_res_used = oq->qt_bcount_delta;
nq->qt_dquot = oq->qt_dquot;
nq->qt_bcount_delta = nq->qt_icount_delta = 0;
nq->qt_rtbcount_delta = 0;
nq->qt_blk_res = oq->qt_blk_res - blk_res_used;
oq->qt_blk_res = blk_res_used;
nq->qt_rtblk_res = oq->qt_rtblk_res -
oq->qt_rtblk_res_used;
oq->qt_rtblk_res = oq->qt_rtblk_res_used;
nq->qt_ino_res = oq->qt_ino_res - oq->qt_ino_res_used;
oq->qt_ino_res = oq->qt_ino_res_used;
}
}
}
void
xfs_trans_mod_dquot_byino(
xfs_trans_t *tp,
xfs_inode_t *ip,
uint field,
long delta)
{
xfs_mount_t *mp = tp->t_mountp;
if (!XFS_IS_QUOTA_RUNNING(mp) ||
!XFS_IS_QUOTA_ON(mp) ||
xfs_is_quota_inode(&mp->m_sb, ip->i_ino))
return;
if (tp->t_dqinfo == NULL)
xfs_trans_alloc_dqinfo(tp);
if (XFS_IS_UQUOTA_ON(mp) && ip->i_udquot)
(void) xfs_trans_mod_dquot(tp, ip->i_udquot, field, delta);
if (XFS_IS_GQUOTA_ON(mp) && ip->i_gdquot)
(void) xfs_trans_mod_dquot(tp, ip->i_gdquot, field, delta);
if (XFS_IS_PQUOTA_ON(mp) && ip->i_pdquot)
(void) xfs_trans_mod_dquot(tp, ip->i_pdquot, field, delta);
}
STATIC struct xfs_dqtrx *
xfs_trans_get_dqtrx(
struct xfs_trans *tp,
struct xfs_dquot *dqp)
{
int i;
struct xfs_dqtrx *qa;
if (XFS_QM_ISUDQ(dqp))
qa = tp->t_dqinfo->dqs[XFS_QM_TRANS_USR];
else if (XFS_QM_ISGDQ(dqp))
qa = tp->t_dqinfo->dqs[XFS_QM_TRANS_GRP];
else if (XFS_QM_ISPDQ(dqp))
qa = tp->t_dqinfo->dqs[XFS_QM_TRANS_PRJ];
else
return NULL;
for (i = 0; i < XFS_QM_TRANS_MAXDQS; i++) {
if (qa[i].qt_dquot == NULL ||
qa[i].qt_dquot == dqp)
return &qa[i];
}
return NULL;
}
void
xfs_trans_mod_dquot(
xfs_trans_t *tp,
xfs_dquot_t *dqp,
uint field,
long delta)
{
xfs_dqtrx_t *qtrx;
ASSERT(tp);
ASSERT(XFS_IS_QUOTA_RUNNING(tp->t_mountp));
qtrx = NULL;
if (tp->t_dqinfo == NULL)
xfs_trans_alloc_dqinfo(tp);
qtrx = xfs_trans_get_dqtrx(tp, dqp);
ASSERT(qtrx);
if (qtrx->qt_dquot == NULL)
qtrx->qt_dquot = dqp;
switch (field) {
case XFS_TRANS_DQ_RES_BLKS:
qtrx->qt_blk_res += (ulong)delta;
break;
case XFS_TRANS_DQ_RES_INOS:
qtrx->qt_ino_res += (ulong)delta;
break;
case XFS_TRANS_DQ_BCOUNT:
qtrx->qt_bcount_delta += delta;
break;
case XFS_TRANS_DQ_DELBCOUNT:
qtrx->qt_delbcnt_delta += delta;
break;
case XFS_TRANS_DQ_ICOUNT:
if (qtrx->qt_ino_res && delta > 0) {
qtrx->qt_ino_res_used += (ulong)delta;
ASSERT(qtrx->qt_ino_res >= qtrx->qt_ino_res_used);
}
qtrx->qt_icount_delta += delta;
break;
case XFS_TRANS_DQ_RES_RTBLKS:
qtrx->qt_rtblk_res += (ulong)delta;
break;
case XFS_TRANS_DQ_RTBCOUNT:
if (qtrx->qt_rtblk_res && delta > 0) {
qtrx->qt_rtblk_res_used += (ulong)delta;
ASSERT(qtrx->qt_rtblk_res >= qtrx->qt_rtblk_res_used);
}
qtrx->qt_rtbcount_delta += delta;
break;
case XFS_TRANS_DQ_DELRTBCOUNT:
qtrx->qt_delrtb_delta += delta;
break;
default:
ASSERT(0);
}
tp->t_flags |= XFS_TRANS_DQ_DIRTY;
}
STATIC void
xfs_trans_dqlockedjoin(
xfs_trans_t *tp,
xfs_dqtrx_t *q)
{
ASSERT(q[0].qt_dquot != NULL);
if (q[1].qt_dquot == NULL) {
xfs_dqlock(q[0].qt_dquot);
xfs_trans_dqjoin(tp, q[0].qt_dquot);
} else {
ASSERT(XFS_QM_TRANS_MAXDQS == 2);
xfs_dqlock2(q[0].qt_dquot, q[1].qt_dquot);
xfs_trans_dqjoin(tp, q[0].qt_dquot);
xfs_trans_dqjoin(tp, q[1].qt_dquot);
}
}
void
xfs_trans_apply_dquot_deltas(
struct xfs_trans *tp)
{
int i, j;
struct xfs_dquot *dqp;
struct xfs_dqtrx *qtrx, *qa;
struct xfs_disk_dquot *d;
long totalbdelta;
long totalrtbdelta;
if (!(tp->t_flags & XFS_TRANS_DQ_DIRTY))
return;
ASSERT(tp->t_dqinfo);
for (j = 0; j < XFS_QM_TRANS_DQTYPES; j++) {
qa = tp->t_dqinfo->dqs[j];
if (qa[0].qt_dquot == NULL)
continue;
xfs_trans_dqlockedjoin(tp, qa);
for (i = 0; i < XFS_QM_TRANS_MAXDQS; i++) {
qtrx = &qa[i];
if ((dqp = qtrx->qt_dquot) == NULL)
break;
ASSERT(XFS_DQ_IS_LOCKED(dqp));
ASSERT(dqp->q_transp == tp);
d = &dqp->q_core;
totalbdelta = qtrx->qt_bcount_delta +
qtrx->qt_delbcnt_delta;
totalrtbdelta = qtrx->qt_rtbcount_delta +
qtrx->qt_delrtb_delta;
#ifdef DEBUG
if (totalbdelta < 0)
ASSERT(be64_to_cpu(d->d_bcount) >=
-totalbdelta);
if (totalrtbdelta < 0)
ASSERT(be64_to_cpu(d->d_rtbcount) >=
-totalrtbdelta);
if (qtrx->qt_icount_delta < 0)
ASSERT(be64_to_cpu(d->d_icount) >=
-qtrx->qt_icount_delta);
#endif
if (totalbdelta)
be64_add_cpu(&d->d_bcount, (xfs_qcnt_t)totalbdelta);
if (qtrx->qt_icount_delta)
be64_add_cpu(&d->d_icount, (xfs_qcnt_t)qtrx->qt_icount_delta);
if (totalrtbdelta)
be64_add_cpu(&d->d_rtbcount, (xfs_qcnt_t)totalrtbdelta);
if (d->d_id) {
xfs_qm_adjust_dqlimits(tp->t_mountp, dqp);
xfs_qm_adjust_dqtimers(tp->t_mountp, d);
}
dqp->dq_flags |= XFS_DQ_DIRTY;
xfs_trans_log_dquot(tp, dqp);
if (qtrx->qt_blk_res != 0) {
ulong blk_res_used = 0;
if (qtrx->qt_bcount_delta > 0)
blk_res_used = qtrx->qt_bcount_delta;
if (qtrx->qt_blk_res != blk_res_used) {
if (qtrx->qt_blk_res > blk_res_used)
dqp->q_res_bcount -= (xfs_qcnt_t)
(qtrx->qt_blk_res -
blk_res_used);
else
dqp->q_res_bcount -= (xfs_qcnt_t)
(blk_res_used -
qtrx->qt_blk_res);
}
} else {
if (qtrx->qt_bcount_delta) {
dqp->q_res_bcount +=
(xfs_qcnt_t)qtrx->qt_bcount_delta;
}
}
if (qtrx->qt_rtblk_res != 0) {
if (qtrx->qt_rtblk_res != qtrx->qt_rtblk_res_used) {
if (qtrx->qt_rtblk_res >
qtrx->qt_rtblk_res_used)
dqp->q_res_rtbcount -= (xfs_qcnt_t)
(qtrx->qt_rtblk_res -
qtrx->qt_rtblk_res_used);
else
dqp->q_res_rtbcount -= (xfs_qcnt_t)
(qtrx->qt_rtblk_res_used -
qtrx->qt_rtblk_res);
}
} else {
if (qtrx->qt_rtbcount_delta)
dqp->q_res_rtbcount +=
(xfs_qcnt_t)qtrx->qt_rtbcount_delta;
}
if (qtrx->qt_ino_res != 0) {
ASSERT(qtrx->qt_ino_res >=
qtrx->qt_ino_res_used);
if (qtrx->qt_ino_res > qtrx->qt_ino_res_used)
dqp->q_res_icount -= (xfs_qcnt_t)
(qtrx->qt_ino_res -
qtrx->qt_ino_res_used);
} else {
if (qtrx->qt_icount_delta)
dqp->q_res_icount +=
(xfs_qcnt_t)qtrx->qt_icount_delta;
}
ASSERT(dqp->q_res_bcount >=
be64_to_cpu(dqp->q_core.d_bcount));
ASSERT(dqp->q_res_icount >=
be64_to_cpu(dqp->q_core.d_icount));
ASSERT(dqp->q_res_rtbcount >=
be64_to_cpu(dqp->q_core.d_rtbcount));
}
}
}
void
xfs_trans_unreserve_and_mod_dquots(
xfs_trans_t *tp)
{
int i, j;
xfs_dquot_t *dqp;
xfs_dqtrx_t *qtrx, *qa;
bool locked;
if (!tp->t_dqinfo || !(tp->t_flags & XFS_TRANS_DQ_DIRTY))
return;
for (j = 0; j < XFS_QM_TRANS_DQTYPES; j++) {
qa = tp->t_dqinfo->dqs[j];
for (i = 0; i < XFS_QM_TRANS_MAXDQS; i++) {
qtrx = &qa[i];
if ((dqp = qtrx->qt_dquot) == NULL)
break;
locked = false;
if (qtrx->qt_blk_res) {
xfs_dqlock(dqp);
locked = true;
dqp->q_res_bcount -=
(xfs_qcnt_t)qtrx->qt_blk_res;
}
if (qtrx->qt_ino_res) {
if (!locked) {
xfs_dqlock(dqp);
locked = true;
}
dqp->q_res_icount -=
(xfs_qcnt_t)qtrx->qt_ino_res;
}
if (qtrx->qt_rtblk_res) {
if (!locked) {
xfs_dqlock(dqp);
locked = true;
}
dqp->q_res_rtbcount -=
(xfs_qcnt_t)qtrx->qt_rtblk_res;
}
if (locked)
xfs_dqunlock(dqp);
}
}
}
STATIC void
xfs_quota_warn(
struct xfs_mount *mp,
struct xfs_dquot *dqp,
int type)
{
enum quota_type qtype;
if (dqp->dq_flags & XFS_DQ_PROJ)
qtype = PRJQUOTA;
else if (dqp->dq_flags & XFS_DQ_USER)
qtype = USRQUOTA;
else
qtype = GRPQUOTA;
quota_send_warning(make_kqid(&init_user_ns, qtype,
be32_to_cpu(dqp->q_core.d_id)),
mp->m_super->s_dev, type);
}
STATIC int
xfs_trans_dqresv(
xfs_trans_t *tp,
xfs_mount_t *mp,
xfs_dquot_t *dqp,
long nblks,
long ninos,
uint flags)
{
xfs_qcnt_t hardlimit;
xfs_qcnt_t softlimit;
time_t timer;
xfs_qwarncnt_t warns;
xfs_qwarncnt_t warnlimit;
xfs_qcnt_t total_count;
xfs_qcnt_t *resbcountp;
xfs_quotainfo_t *q = mp->m_quotainfo;
xfs_dqlock(dqp);
if (flags & XFS_TRANS_DQ_RES_BLKS) {
hardlimit = be64_to_cpu(dqp->q_core.d_blk_hardlimit);
if (!hardlimit)
hardlimit = q->qi_bhardlimit;
softlimit = be64_to_cpu(dqp->q_core.d_blk_softlimit);
if (!softlimit)
softlimit = q->qi_bsoftlimit;
timer = be32_to_cpu(dqp->q_core.d_btimer);
warns = be16_to_cpu(dqp->q_core.d_bwarns);
warnlimit = dqp->q_mount->m_quotainfo->qi_bwarnlimit;
resbcountp = &dqp->q_res_bcount;
} else {
ASSERT(flags & XFS_TRANS_DQ_RES_RTBLKS);
hardlimit = be64_to_cpu(dqp->q_core.d_rtb_hardlimit);
if (!hardlimit)
hardlimit = q->qi_rtbhardlimit;
softlimit = be64_to_cpu(dqp->q_core.d_rtb_softlimit);
if (!softlimit)
softlimit = q->qi_rtbsoftlimit;
timer = be32_to_cpu(dqp->q_core.d_rtbtimer);
warns = be16_to_cpu(dqp->q_core.d_rtbwarns);
warnlimit = dqp->q_mount->m_quotainfo->qi_rtbwarnlimit;
resbcountp = &dqp->q_res_rtbcount;
}
if ((flags & XFS_QMOPT_FORCE_RES) == 0 &&
dqp->q_core.d_id &&
((XFS_IS_UQUOTA_ENFORCED(dqp->q_mount) && XFS_QM_ISUDQ(dqp)) ||
(XFS_IS_GQUOTA_ENFORCED(dqp->q_mount) && XFS_QM_ISGDQ(dqp)) ||
(XFS_IS_PQUOTA_ENFORCED(dqp->q_mount) && XFS_QM_ISPDQ(dqp)))) {
if (nblks > 0) {
total_count = *resbcountp + nblks;
if (hardlimit && total_count > hardlimit) {
xfs_quota_warn(mp, dqp, QUOTA_NL_BHARDWARN);
goto error_return;
}
if (softlimit && total_count > softlimit) {
if ((timer != 0 && get_seconds() > timer) ||
(warns != 0 && warns >= warnlimit)) {
xfs_quota_warn(mp, dqp,
QUOTA_NL_BSOFTLONGWARN);
goto error_return;
}
xfs_quota_warn(mp, dqp, QUOTA_NL_BSOFTWARN);
}
}
if (ninos > 0) {
total_count = be64_to_cpu(dqp->q_core.d_icount) + ninos;
timer = be32_to_cpu(dqp->q_core.d_itimer);
warns = be16_to_cpu(dqp->q_core.d_iwarns);
warnlimit = dqp->q_mount->m_quotainfo->qi_iwarnlimit;
hardlimit = be64_to_cpu(dqp->q_core.d_ino_hardlimit);
if (!hardlimit)
hardlimit = q->qi_ihardlimit;
softlimit = be64_to_cpu(dqp->q_core.d_ino_softlimit);
if (!softlimit)
softlimit = q->qi_isoftlimit;
if (hardlimit && total_count > hardlimit) {
xfs_quota_warn(mp, dqp, QUOTA_NL_IHARDWARN);
goto error_return;
}
if (softlimit && total_count > softlimit) {
if ((timer != 0 && get_seconds() > timer) ||
(warns != 0 && warns >= warnlimit)) {
xfs_quota_warn(mp, dqp,
QUOTA_NL_ISOFTLONGWARN);
goto error_return;
}
xfs_quota_warn(mp, dqp, QUOTA_NL_ISOFTWARN);
}
}
}
(*resbcountp) += (xfs_qcnt_t)nblks;
if (ninos != 0)
dqp->q_res_icount += (xfs_qcnt_t)ninos;
if (tp) {
ASSERT(tp->t_dqinfo);
ASSERT(flags & XFS_QMOPT_RESBLK_MASK);
if (nblks != 0)
xfs_trans_mod_dquot(tp, dqp,
flags & XFS_QMOPT_RESBLK_MASK,
nblks);
if (ninos != 0)
xfs_trans_mod_dquot(tp, dqp,
XFS_TRANS_DQ_RES_INOS,
ninos);
}
ASSERT(dqp->q_res_bcount >= be64_to_cpu(dqp->q_core.d_bcount));
ASSERT(dqp->q_res_rtbcount >= be64_to_cpu(dqp->q_core.d_rtbcount));
ASSERT(dqp->q_res_icount >= be64_to_cpu(dqp->q_core.d_icount));
xfs_dqunlock(dqp);
return 0;
error_return:
xfs_dqunlock(dqp);
if (flags & XFS_QMOPT_ENOSPC)
return -ENOSPC;
return -EDQUOT;
}
int
xfs_trans_reserve_quota_bydquots(
struct xfs_trans *tp,
struct xfs_mount *mp,
struct xfs_dquot *udqp,
struct xfs_dquot *gdqp,
struct xfs_dquot *pdqp,
long nblks,
long ninos,
uint flags)
{
int error;
if (!XFS_IS_QUOTA_RUNNING(mp) || !XFS_IS_QUOTA_ON(mp))
return 0;
if (tp && tp->t_dqinfo == NULL)
xfs_trans_alloc_dqinfo(tp);
ASSERT(flags & XFS_QMOPT_RESBLK_MASK);
if (udqp) {
error = xfs_trans_dqresv(tp, mp, udqp, nblks, ninos,
(flags & ~XFS_QMOPT_ENOSPC));
if (error)
return error;
}
if (gdqp) {
error = xfs_trans_dqresv(tp, mp, gdqp, nblks, ninos, flags);
if (error)
goto unwind_usr;
}
if (pdqp) {
error = xfs_trans_dqresv(tp, mp, pdqp, nblks, ninos, flags);
if (error)
goto unwind_grp;
}
return 0;
unwind_grp:
flags |= XFS_QMOPT_FORCE_RES;
if (gdqp)
xfs_trans_dqresv(tp, mp, gdqp, -nblks, -ninos, flags);
unwind_usr:
flags |= XFS_QMOPT_FORCE_RES;
if (udqp)
xfs_trans_dqresv(tp, mp, udqp, -nblks, -ninos, flags);
return error;
}
int
xfs_trans_reserve_quota_nblks(
struct xfs_trans *tp,
struct xfs_inode *ip,
long nblks,
long ninos,
uint flags)
{
struct xfs_mount *mp = ip->i_mount;
if (!XFS_IS_QUOTA_RUNNING(mp) || !XFS_IS_QUOTA_ON(mp))
return 0;
if (XFS_IS_PQUOTA_ON(mp))
flags |= XFS_QMOPT_ENOSPC;
ASSERT(!xfs_is_quota_inode(&mp->m_sb, ip->i_ino));
ASSERT(xfs_isilocked(ip, XFS_ILOCK_EXCL));
ASSERT((flags & ~(XFS_QMOPT_FORCE_RES | XFS_QMOPT_ENOSPC)) ==
XFS_TRANS_DQ_RES_RTBLKS ||
(flags & ~(XFS_QMOPT_FORCE_RES | XFS_QMOPT_ENOSPC)) ==
XFS_TRANS_DQ_RES_BLKS);
return xfs_trans_reserve_quota_bydquots(tp, mp,
ip->i_udquot, ip->i_gdquot,
ip->i_pdquot,
nblks, ninos, flags);
}
xfs_qoff_logitem_t *
xfs_trans_get_qoff_item(
xfs_trans_t *tp,
xfs_qoff_logitem_t *startqoff,
uint flags)
{
xfs_qoff_logitem_t *q;
ASSERT(tp != NULL);
q = xfs_qm_qoff_logitem_init(tp->t_mountp, startqoff, flags);
ASSERT(q != NULL);
xfs_trans_add_item(tp, &q->qql_item);
return q;
}
void
xfs_trans_log_quotaoff_item(
xfs_trans_t *tp,
xfs_qoff_logitem_t *qlp)
{
tp->t_flags |= XFS_TRANS_DIRTY;
qlp->qql_item.li_desc->lid_flags |= XFS_LID_DIRTY;
}
STATIC void
xfs_trans_alloc_dqinfo(
xfs_trans_t *tp)
{
tp->t_dqinfo = kmem_zone_zalloc(xfs_qm_dqtrxzone, KM_SLEEP);
}
void
xfs_trans_free_dqinfo(
xfs_trans_t *tp)
{
if (!tp->t_dqinfo)
return;
kmem_zone_free(xfs_qm_dqtrxzone, tp->t_dqinfo);
tp->t_dqinfo = NULL;
}
