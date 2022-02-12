STATIC struct xfs_qm *
xfs_Gqm_init(void)
{
xfs_dqhash_t *udqhash, *gdqhash;
xfs_qm_t *xqm;
size_t hsize;
uint i;
udqhash = kmem_zalloc_greedy(&hsize,
XFS_QM_HASHSIZE_LOW * sizeof(xfs_dqhash_t),
XFS_QM_HASHSIZE_HIGH * sizeof(xfs_dqhash_t));
if (!udqhash)
goto out;
gdqhash = kmem_zalloc_large(hsize);
if (!gdqhash)
goto out_free_udqhash;
hsize /= sizeof(xfs_dqhash_t);
xqm = kmem_zalloc(sizeof(xfs_qm_t), KM_SLEEP);
xqm->qm_dqhashmask = hsize - 1;
xqm->qm_usr_dqhtable = udqhash;
xqm->qm_grp_dqhtable = gdqhash;
ASSERT(xqm->qm_usr_dqhtable != NULL);
ASSERT(xqm->qm_grp_dqhtable != NULL);
for (i = 0; i < hsize; i++) {
xfs_qm_list_init(&(xqm->qm_usr_dqhtable[i]), "uxdqh", i);
xfs_qm_list_init(&(xqm->qm_grp_dqhtable[i]), "gxdqh", i);
}
INIT_LIST_HEAD(&xqm->qm_dqfrlist);
xqm->qm_dqfrlist_cnt = 0;
mutex_init(&xqm->qm_dqfrlist_lock);
if (!qm_dqzone) {
xqm->qm_dqzone = kmem_zone_init(sizeof(xfs_dquot_t),
"xfs_dquots");
qm_dqzone = xqm->qm_dqzone;
} else
xqm->qm_dqzone = qm_dqzone;
register_shrinker(&xfs_qm_shaker);
if (!qm_dqtrxzone) {
xqm->qm_dqtrxzone = kmem_zone_init(sizeof(xfs_dquot_acct_t),
"xfs_dqtrx");
qm_dqtrxzone = xqm->qm_dqtrxzone;
} else
xqm->qm_dqtrxzone = qm_dqtrxzone;
atomic_set(&xqm->qm_totaldquots, 0);
xqm->qm_nrefs = 0;
return xqm;
out_free_udqhash:
kmem_free_large(udqhash);
out:
return NULL;
}
STATIC void
xfs_qm_destroy(
struct xfs_qm *xqm)
{
int hsize, i;
ASSERT(xqm != NULL);
ASSERT(xqm->qm_nrefs == 0);
unregister_shrinker(&xfs_qm_shaker);
mutex_lock(&xqm->qm_dqfrlist_lock);
ASSERT(list_empty(&xqm->qm_dqfrlist));
mutex_unlock(&xqm->qm_dqfrlist_lock);
hsize = xqm->qm_dqhashmask + 1;
for (i = 0; i < hsize; i++) {
xfs_qm_list_destroy(&(xqm->qm_usr_dqhtable[i]));
xfs_qm_list_destroy(&(xqm->qm_grp_dqhtable[i]));
}
kmem_free_large(xqm->qm_usr_dqhtable);
kmem_free_large(xqm->qm_grp_dqhtable);
xqm->qm_usr_dqhtable = NULL;
xqm->qm_grp_dqhtable = NULL;
xqm->qm_dqhashmask = 0;
kmem_free(xqm);
}
STATIC int
xfs_qm_hold_quotafs_ref(
struct xfs_mount *mp)
{
mutex_lock(&xfs_Gqm_lock);
if (!xfs_Gqm) {
xfs_Gqm = xfs_Gqm_init();
if (!xfs_Gqm) {
mutex_unlock(&xfs_Gqm_lock);
return ENOMEM;
}
}
xfs_Gqm->qm_nrefs++;
mutex_unlock(&xfs_Gqm_lock);
return 0;
}
STATIC void
xfs_qm_rele_quotafs_ref(
struct xfs_mount *mp)
{
ASSERT(xfs_Gqm);
ASSERT(xfs_Gqm->qm_nrefs > 0);
mutex_lock(&xfs_Gqm_lock);
if (--xfs_Gqm->qm_nrefs == 0) {
xfs_qm_destroy(xfs_Gqm);
xfs_Gqm = NULL;
}
mutex_unlock(&xfs_Gqm_lock);
}
void
xfs_qm_unmount(
struct xfs_mount *mp)
{
if (mp->m_quotainfo) {
xfs_qm_dqpurge_all(mp, XFS_QMOPT_QUOTALL);
xfs_qm_destroy_quotainfo(mp);
}
}
void
xfs_qm_mount_quotas(
xfs_mount_t *mp)
{
int error = 0;
uint sbf;
if (mp->m_sb.sb_rextents) {
xfs_notice(mp, "Cannot turn on quotas for realtime filesystem");
mp->m_qflags = 0;
goto write_changes;
}
ASSERT(XFS_IS_QUOTA_RUNNING(mp));
error = xfs_qm_init_quotainfo(mp);
if (error) {
ASSERT(mp->m_quotainfo == NULL);
mp->m_qflags = 0;
goto write_changes;
}
if (XFS_QM_NEED_QUOTACHECK(mp)) {
error = xfs_qm_quotacheck(mp);
if (error) {
return;
}
}
if (!XFS_IS_UQUOTA_ON(mp))
mp->m_qflags &= ~XFS_UQUOTA_CHKD;
if (!(XFS_IS_GQUOTA_ON(mp) || XFS_IS_PQUOTA_ON(mp)))
mp->m_qflags &= ~XFS_OQUOTA_CHKD;
write_changes:
spin_lock(&mp->m_sb_lock);
sbf = mp->m_sb.sb_qflags;
mp->m_sb.sb_qflags = mp->m_qflags & XFS_MOUNT_QUOTA_ALL;
spin_unlock(&mp->m_sb_lock);
if (sbf != (mp->m_qflags & XFS_MOUNT_QUOTA_ALL)) {
if (xfs_qm_write_sb_changes(mp, XFS_SB_QFLAGS)) {
ASSERT(!(XFS_IS_QUOTA_RUNNING(mp)));
xfs_alert(mp, "%s: Superblock update failed!",
__func__);
}
}
if (error) {
xfs_warn(mp, "Failed to initialize disk quotas.");
return;
}
}
void
xfs_qm_unmount_quotas(
xfs_mount_t *mp)
{
ASSERT(mp->m_rootip);
xfs_qm_dqdetach(mp->m_rootip);
if (mp->m_rbmip)
xfs_qm_dqdetach(mp->m_rbmip);
if (mp->m_rsumip)
xfs_qm_dqdetach(mp->m_rsumip);
if (mp->m_quotainfo) {
if (mp->m_quotainfo->qi_uquotaip) {
IRELE(mp->m_quotainfo->qi_uquotaip);
mp->m_quotainfo->qi_uquotaip = NULL;
}
if (mp->m_quotainfo->qi_gquotaip) {
IRELE(mp->m_quotainfo->qi_gquotaip);
mp->m_quotainfo->qi_gquotaip = NULL;
}
}
}
STATIC int
xfs_qm_dqflush_all(
struct xfs_mount *mp)
{
struct xfs_quotainfo *q = mp->m_quotainfo;
int recl;
struct xfs_dquot *dqp;
int error;
if (!q)
return 0;
again:
mutex_lock(&q->qi_dqlist_lock);
list_for_each_entry(dqp, &q->qi_dqlist, q_mplist) {
xfs_dqlock(dqp);
if ((dqp->dq_flags & XFS_DQ_FREEING) ||
!XFS_DQ_IS_DIRTY(dqp)) {
xfs_dqunlock(dqp);
continue;
}
recl = q->qi_dqreclaims;
if (!xfs_dqflock_nowait(dqp)) {
xfs_dqflock_pushbuf_wait(dqp);
}
mutex_unlock(&q->qi_dqlist_lock);
error = xfs_qm_dqflush(dqp, 0);
xfs_dqunlock(dqp);
if (error)
return error;
mutex_lock(&q->qi_dqlist_lock);
if (recl != q->qi_dqreclaims) {
mutex_unlock(&q->qi_dqlist_lock);
goto again;
}
}
mutex_unlock(&q->qi_dqlist_lock);
return 0;
}
STATIC void
xfs_qm_detach_gdquots(
struct xfs_mount *mp)
{
struct xfs_quotainfo *q = mp->m_quotainfo;
struct xfs_dquot *dqp, *gdqp;
again:
ASSERT(mutex_is_locked(&q->qi_dqlist_lock));
list_for_each_entry(dqp, &q->qi_dqlist, q_mplist) {
xfs_dqlock(dqp);
if (dqp->dq_flags & XFS_DQ_FREEING) {
xfs_dqunlock(dqp);
mutex_unlock(&q->qi_dqlist_lock);
delay(1);
mutex_lock(&q->qi_dqlist_lock);
goto again;
}
gdqp = dqp->q_gdquot;
if (gdqp)
dqp->q_gdquot = NULL;
xfs_dqunlock(dqp);
if (gdqp)
xfs_qm_dqrele(gdqp);
}
}
STATIC int
xfs_qm_dqpurge_int(
struct xfs_mount *mp,
uint flags)
{
struct xfs_quotainfo *q = mp->m_quotainfo;
struct xfs_dquot *dqp, *n;
uint dqtype;
int nmisses = 0;
LIST_HEAD (dispose_list);
if (!q)
return 0;
dqtype = (flags & XFS_QMOPT_UQUOTA) ? XFS_DQ_USER : 0;
dqtype |= (flags & XFS_QMOPT_PQUOTA) ? XFS_DQ_PROJ : 0;
dqtype |= (flags & XFS_QMOPT_GQUOTA) ? XFS_DQ_GROUP : 0;
mutex_lock(&q->qi_dqlist_lock);
xfs_qm_detach_gdquots(mp);
list_for_each_entry_safe(dqp, n, &q->qi_dqlist, q_mplist) {
xfs_dqlock(dqp);
if ((dqp->dq_flags & dqtype) != 0 &&
!(dqp->dq_flags & XFS_DQ_FREEING)) {
if (dqp->q_nrefs == 0) {
dqp->dq_flags |= XFS_DQ_FREEING;
list_move_tail(&dqp->q_mplist, &dispose_list);
} else
nmisses++;
}
xfs_dqunlock(dqp);
}
mutex_unlock(&q->qi_dqlist_lock);
list_for_each_entry_safe(dqp, n, &dispose_list, q_mplist)
xfs_qm_dqpurge(dqp);
return nmisses;
}
int
xfs_qm_dqpurge_all(
xfs_mount_t *mp,
uint flags)
{
int ndquots;
if (mp->m_quotainfo) {
while ((ndquots = xfs_qm_dqpurge_int(mp, flags))) {
delay(ndquots * 10);
}
}
return 0;
}
STATIC int
xfs_qm_dqattach_one(
xfs_inode_t *ip,
xfs_dqid_t id,
uint type,
uint doalloc,
xfs_dquot_t *udqhint,
xfs_dquot_t **IO_idqpp)
{
xfs_dquot_t *dqp;
int error;
ASSERT(xfs_isilocked(ip, XFS_ILOCK_EXCL));
error = 0;
dqp = *IO_idqpp;
if (dqp) {
trace_xfs_dqattach_found(dqp);
return 0;
}
if (udqhint) {
ASSERT(type == XFS_DQ_GROUP || type == XFS_DQ_PROJ);
xfs_dqlock(udqhint);
dqp = udqhint->q_gdquot;
if (dqp && be32_to_cpu(dqp->q_core.d_id) == id) {
ASSERT(*IO_idqpp == NULL);
*IO_idqpp = xfs_qm_dqhold(dqp);
xfs_dqunlock(udqhint);
return 0;
}
xfs_dqunlock(udqhint);
}
error = xfs_qm_dqget(ip->i_mount, ip, id, type,
doalloc | XFS_QMOPT_DOWARN, &dqp);
if (error)
return error;
trace_xfs_dqattach_get(dqp);
*IO_idqpp = dqp;
xfs_dqunlock(dqp);
return 0;
}
STATIC void
xfs_qm_dqattach_grouphint(
xfs_dquot_t *udq,
xfs_dquot_t *gdq)
{
xfs_dquot_t *tmp;
xfs_dqlock(udq);
tmp = udq->q_gdquot;
if (tmp) {
if (tmp == gdq)
goto done;
udq->q_gdquot = NULL;
xfs_qm_dqrele(tmp);
}
udq->q_gdquot = xfs_qm_dqhold(gdq);
done:
xfs_dqunlock(udq);
}
int
xfs_qm_dqattach_locked(
xfs_inode_t *ip,
uint flags)
{
xfs_mount_t *mp = ip->i_mount;
uint nquotas = 0;
int error = 0;
if (!XFS_IS_QUOTA_RUNNING(mp) ||
!XFS_IS_QUOTA_ON(mp) ||
!XFS_NOT_DQATTACHED(mp, ip) ||
ip->i_ino == mp->m_sb.sb_uquotino ||
ip->i_ino == mp->m_sb.sb_gquotino)
return 0;
ASSERT(xfs_isilocked(ip, XFS_ILOCK_EXCL));
if (XFS_IS_UQUOTA_ON(mp)) {
error = xfs_qm_dqattach_one(ip, ip->i_d.di_uid, XFS_DQ_USER,
flags & XFS_QMOPT_DQALLOC,
NULL, &ip->i_udquot);
if (error)
goto done;
nquotas++;
}
ASSERT(xfs_isilocked(ip, XFS_ILOCK_EXCL));
if (XFS_IS_OQUOTA_ON(mp)) {
error = XFS_IS_GQUOTA_ON(mp) ?
xfs_qm_dqattach_one(ip, ip->i_d.di_gid, XFS_DQ_GROUP,
flags & XFS_QMOPT_DQALLOC,
ip->i_udquot, &ip->i_gdquot) :
xfs_qm_dqattach_one(ip, xfs_get_projid(ip), XFS_DQ_PROJ,
flags & XFS_QMOPT_DQALLOC,
ip->i_udquot, &ip->i_gdquot);
if (error)
goto done;
nquotas++;
}
if (nquotas == 2) {
ASSERT(xfs_isilocked(ip, XFS_ILOCK_EXCL));
ASSERT(ip->i_udquot);
ASSERT(ip->i_gdquot);
if (ip->i_udquot->q_gdquot != ip->i_gdquot)
xfs_qm_dqattach_grouphint(ip->i_udquot, ip->i_gdquot);
}
done:
#ifdef DEBUG
if (!error) {
if (XFS_IS_UQUOTA_ON(mp))
ASSERT(ip->i_udquot);
if (XFS_IS_OQUOTA_ON(mp))
ASSERT(ip->i_gdquot);
}
ASSERT(xfs_isilocked(ip, XFS_ILOCK_EXCL));
#endif
return error;
}
int
xfs_qm_dqattach(
struct xfs_inode *ip,
uint flags)
{
int error;
xfs_ilock(ip, XFS_ILOCK_EXCL);
error = xfs_qm_dqattach_locked(ip, flags);
xfs_iunlock(ip, XFS_ILOCK_EXCL);
return error;
}
void
xfs_qm_dqdetach(
xfs_inode_t *ip)
{
if (!(ip->i_udquot || ip->i_gdquot))
return;
trace_xfs_dquot_dqdetach(ip);
ASSERT(ip->i_ino != ip->i_mount->m_sb.sb_uquotino);
ASSERT(ip->i_ino != ip->i_mount->m_sb.sb_gquotino);
if (ip->i_udquot) {
xfs_qm_dqrele(ip->i_udquot);
ip->i_udquot = NULL;
}
if (ip->i_gdquot) {
xfs_qm_dqrele(ip->i_gdquot);
ip->i_gdquot = NULL;
}
}
STATIC int
xfs_qm_init_quotainfo(
xfs_mount_t *mp)
{
xfs_quotainfo_t *qinf;
int error;
xfs_dquot_t *dqp;
ASSERT(XFS_IS_QUOTA_RUNNING(mp));
if ((error = xfs_qm_hold_quotafs_ref(mp))) {
return error;
}
qinf = mp->m_quotainfo = kmem_zalloc(sizeof(xfs_quotainfo_t), KM_SLEEP);
if ((error = xfs_qm_init_quotainos(mp))) {
kmem_free(qinf);
mp->m_quotainfo = NULL;
return error;
}
INIT_LIST_HEAD(&qinf->qi_dqlist);
mutex_init(&qinf->qi_dqlist_lock);
lockdep_set_class(&qinf->qi_dqlist_lock, &xfs_quota_mplist_class);
qinf->qi_dqreclaims = 0;
mutex_init(&qinf->qi_quotaofflock);
qinf->qi_dqchunklen = XFS_FSB_TO_BB(mp, XFS_DQUOT_CLUSTER_SIZE_FSB);
ASSERT(qinf->qi_dqchunklen);
qinf->qi_dqperchunk = BBTOB(qinf->qi_dqchunklen);
do_div(qinf->qi_dqperchunk, sizeof(xfs_dqblk_t));
mp->m_qflags |= (mp->m_sb.sb_qflags & XFS_ALL_QUOTA_CHKD);
error = xfs_qm_dqread(mp, 0,
XFS_IS_UQUOTA_RUNNING(mp) ? XFS_DQ_USER :
(XFS_IS_GQUOTA_RUNNING(mp) ? XFS_DQ_GROUP :
XFS_DQ_PROJ),
XFS_QMOPT_DOWARN, &dqp);
if (!error) {
xfs_disk_dquot_t *ddqp = &dqp->q_core;
qinf->qi_btimelimit = ddqp->d_btimer ?
be32_to_cpu(ddqp->d_btimer) : XFS_QM_BTIMELIMIT;
qinf->qi_itimelimit = ddqp->d_itimer ?
be32_to_cpu(ddqp->d_itimer) : XFS_QM_ITIMELIMIT;
qinf->qi_rtbtimelimit = ddqp->d_rtbtimer ?
be32_to_cpu(ddqp->d_rtbtimer) : XFS_QM_RTBTIMELIMIT;
qinf->qi_bwarnlimit = ddqp->d_bwarns ?
be16_to_cpu(ddqp->d_bwarns) : XFS_QM_BWARNLIMIT;
qinf->qi_iwarnlimit = ddqp->d_iwarns ?
be16_to_cpu(ddqp->d_iwarns) : XFS_QM_IWARNLIMIT;
qinf->qi_rtbwarnlimit = ddqp->d_rtbwarns ?
be16_to_cpu(ddqp->d_rtbwarns) : XFS_QM_RTBWARNLIMIT;
qinf->qi_bhardlimit = be64_to_cpu(ddqp->d_blk_hardlimit);
qinf->qi_bsoftlimit = be64_to_cpu(ddqp->d_blk_softlimit);
qinf->qi_ihardlimit = be64_to_cpu(ddqp->d_ino_hardlimit);
qinf->qi_isoftlimit = be64_to_cpu(ddqp->d_ino_softlimit);
qinf->qi_rtbhardlimit = be64_to_cpu(ddqp->d_rtb_hardlimit);
qinf->qi_rtbsoftlimit = be64_to_cpu(ddqp->d_rtb_softlimit);
xfs_qm_dqdestroy(dqp);
} else {
qinf->qi_btimelimit = XFS_QM_BTIMELIMIT;
qinf->qi_itimelimit = XFS_QM_ITIMELIMIT;
qinf->qi_rtbtimelimit = XFS_QM_RTBTIMELIMIT;
qinf->qi_bwarnlimit = XFS_QM_BWARNLIMIT;
qinf->qi_iwarnlimit = XFS_QM_IWARNLIMIT;
qinf->qi_rtbwarnlimit = XFS_QM_RTBWARNLIMIT;
}
return 0;
}
void
xfs_qm_destroy_quotainfo(
xfs_mount_t *mp)
{
xfs_quotainfo_t *qi;
qi = mp->m_quotainfo;
ASSERT(qi != NULL);
ASSERT(xfs_Gqm != NULL);
xfs_qm_rele_quotafs_ref(mp);
ASSERT(list_empty(&qi->qi_dqlist));
mutex_destroy(&qi->qi_dqlist_lock);
if (qi->qi_uquotaip) {
IRELE(qi->qi_uquotaip);
qi->qi_uquotaip = NULL;
}
if (qi->qi_gquotaip) {
IRELE(qi->qi_gquotaip);
qi->qi_gquotaip = NULL;
}
mutex_destroy(&qi->qi_quotaofflock);
kmem_free(qi);
mp->m_quotainfo = NULL;
}
STATIC void
xfs_qm_list_init(
xfs_dqlist_t *list,
char *str,
int n)
{
mutex_init(&list->qh_lock);
INIT_LIST_HEAD(&list->qh_list);
list->qh_version = 0;
list->qh_nelems = 0;
}
STATIC void
xfs_qm_list_destroy(
xfs_dqlist_t *list)
{
mutex_destroy(&(list->qh_lock));
}
STATIC int
xfs_qm_qino_alloc(
xfs_mount_t *mp,
xfs_inode_t **ip,
__int64_t sbfields,
uint flags)
{
xfs_trans_t *tp;
int error;
int committed;
tp = xfs_trans_alloc(mp, XFS_TRANS_QM_QINOCREATE);
if ((error = xfs_trans_reserve(tp,
XFS_QM_QINOCREATE_SPACE_RES(mp),
XFS_CREATE_LOG_RES(mp), 0,
XFS_TRANS_PERM_LOG_RES,
XFS_CREATE_LOG_COUNT))) {
xfs_trans_cancel(tp, 0);
return error;
}
error = xfs_dir_ialloc(&tp, NULL, S_IFREG, 1, 0, 0, 1, ip, &committed);
if (error) {
xfs_trans_cancel(tp, XFS_TRANS_RELEASE_LOG_RES |
XFS_TRANS_ABORT);
return error;
}
spin_lock(&mp->m_sb_lock);
if (flags & XFS_QMOPT_SBVERSION) {
ASSERT(!xfs_sb_version_hasquota(&mp->m_sb));
ASSERT((sbfields & (XFS_SB_VERSIONNUM | XFS_SB_UQUOTINO |
XFS_SB_GQUOTINO | XFS_SB_QFLAGS)) ==
(XFS_SB_VERSIONNUM | XFS_SB_UQUOTINO |
XFS_SB_GQUOTINO | XFS_SB_QFLAGS));
xfs_sb_version_addquota(&mp->m_sb);
mp->m_sb.sb_uquotino = NULLFSINO;
mp->m_sb.sb_gquotino = NULLFSINO;
mp->m_sb.sb_qflags = 0;
}
if (flags & XFS_QMOPT_UQUOTA)
mp->m_sb.sb_uquotino = (*ip)->i_ino;
else
mp->m_sb.sb_gquotino = (*ip)->i_ino;
spin_unlock(&mp->m_sb_lock);
xfs_mod_sb(tp, sbfields);
if ((error = xfs_trans_commit(tp, XFS_TRANS_RELEASE_LOG_RES))) {
xfs_alert(mp, "%s failed (error %d)!", __func__, error);
return error;
}
return 0;
}
STATIC void
xfs_qm_reset_dqcounts(
xfs_mount_t *mp,
xfs_buf_t *bp,
xfs_dqid_t id,
uint type)
{
xfs_disk_dquot_t *ddq;
int j;
trace_xfs_reset_dqcounts(bp, _RET_IP_);
#ifdef DEBUG
j = XFS_FSB_TO_B(mp, XFS_DQUOT_CLUSTER_SIZE_FSB);
do_div(j, sizeof(xfs_dqblk_t));
ASSERT(mp->m_quotainfo->qi_dqperchunk == j);
#endif
ddq = bp->b_addr;
for (j = 0; j < mp->m_quotainfo->qi_dqperchunk; j++) {
(void) xfs_qm_dqcheck(mp, ddq, id+j, type, XFS_QMOPT_DQREPAIR,
"xfs_quotacheck");
ddq->d_bcount = 0;
ddq->d_icount = 0;
ddq->d_rtbcount = 0;
ddq->d_btimer = 0;
ddq->d_itimer = 0;
ddq->d_rtbtimer = 0;
ddq->d_bwarns = 0;
ddq->d_iwarns = 0;
ddq->d_rtbwarns = 0;
ddq = (xfs_disk_dquot_t *) ((xfs_dqblk_t *)ddq + 1);
}
}
STATIC int
xfs_qm_dqiter_bufs(
xfs_mount_t *mp,
xfs_dqid_t firstid,
xfs_fsblock_t bno,
xfs_filblks_t blkcnt,
uint flags)
{
xfs_buf_t *bp;
int error;
int type;
ASSERT(blkcnt > 0);
type = flags & XFS_QMOPT_UQUOTA ? XFS_DQ_USER :
(flags & XFS_QMOPT_PQUOTA ? XFS_DQ_PROJ : XFS_DQ_GROUP);
error = 0;
while (blkcnt--) {
error = xfs_trans_read_buf(mp, NULL, mp->m_ddev_targp,
XFS_FSB_TO_DADDR(mp, bno),
mp->m_quotainfo->qi_dqchunklen, 0, &bp);
if (error)
break;
xfs_qm_reset_dqcounts(mp, bp, firstid, type);
xfs_buf_delwri_queue(bp);
xfs_buf_relse(bp);
bno++;
firstid += mp->m_quotainfo->qi_dqperchunk;
}
return error;
}
STATIC int
xfs_qm_dqiterate(
xfs_mount_t *mp,
xfs_inode_t *qip,
uint flags)
{
xfs_bmbt_irec_t *map;
int i, nmaps;
int error;
xfs_fileoff_t lblkno;
xfs_filblks_t maxlblkcnt;
xfs_dqid_t firstid;
xfs_fsblock_t rablkno;
xfs_filblks_t rablkcnt;
error = 0;
if (qip->i_d.di_nblocks == 0)
return 0;
map = kmem_alloc(XFS_DQITER_MAP_SIZE * sizeof(*map), KM_SLEEP);
lblkno = 0;
maxlblkcnt = XFS_B_TO_FSB(mp, (xfs_ufsize_t)XFS_MAXIOFFSET(mp));
do {
nmaps = XFS_DQITER_MAP_SIZE;
xfs_ilock(qip, XFS_ILOCK_SHARED);
error = xfs_bmapi_read(qip, lblkno, maxlblkcnt - lblkno,
map, &nmaps, 0);
xfs_iunlock(qip, XFS_ILOCK_SHARED);
if (error)
break;
ASSERT(nmaps <= XFS_DQITER_MAP_SIZE);
for (i = 0; i < nmaps; i++) {
ASSERT(map[i].br_startblock != DELAYSTARTBLOCK);
ASSERT(map[i].br_blockcount);
lblkno += map[i].br_blockcount;
if (map[i].br_startblock == HOLESTARTBLOCK)
continue;
firstid = (xfs_dqid_t) map[i].br_startoff *
mp->m_quotainfo->qi_dqperchunk;
if ((i+1 < nmaps) &&
(map[i+1].br_startblock != HOLESTARTBLOCK)) {
rablkcnt = map[i+1].br_blockcount;
rablkno = map[i+1].br_startblock;
while (rablkcnt--) {
xfs_buf_readahead(mp->m_ddev_targp,
XFS_FSB_TO_DADDR(mp, rablkno),
mp->m_quotainfo->qi_dqchunklen);
rablkno++;
}
}
if ((error = xfs_qm_dqiter_bufs(mp,
firstid,
map[i].br_startblock,
map[i].br_blockcount,
flags))) {
break;
}
}
if (error)
break;
} while (nmaps > 0);
kmem_free(map);
return error;
}
STATIC int
xfs_qm_quotacheck_dqadjust(
struct xfs_inode *ip,
xfs_dqid_t id,
uint type,
xfs_qcnt_t nblks,
xfs_qcnt_t rtblks)
{
struct xfs_mount *mp = ip->i_mount;
struct xfs_dquot *dqp;
int error;
error = xfs_qm_dqget(mp, ip, id, type,
XFS_QMOPT_DQALLOC | XFS_QMOPT_DOWARN, &dqp);
if (error) {
ASSERT(error != ESRCH);
ASSERT(error != ENOENT);
return error;
}
trace_xfs_dqadjust(dqp);
be64_add_cpu(&dqp->q_core.d_icount, 1);
dqp->q_res_icount++;
if (nblks) {
be64_add_cpu(&dqp->q_core.d_bcount, nblks);
dqp->q_res_bcount += nblks;
}
if (rtblks) {
be64_add_cpu(&dqp->q_core.d_rtbcount, rtblks);
dqp->q_res_rtbcount += rtblks;
}
if (dqp->q_core.d_id) {
xfs_qm_adjust_dqlimits(mp, &dqp->q_core);
xfs_qm_adjust_dqtimers(mp, &dqp->q_core);
}
dqp->dq_flags |= XFS_DQ_DIRTY;
xfs_qm_dqput(dqp);
return 0;
}
STATIC int
xfs_qm_get_rtblks(
xfs_inode_t *ip,
xfs_qcnt_t *O_rtblks)
{
xfs_filblks_t rtblks;
xfs_extnum_t idx;
xfs_ifork_t *ifp;
xfs_extnum_t nextents;
int error;
ASSERT(XFS_IS_REALTIME_INODE(ip));
ifp = XFS_IFORK_PTR(ip, XFS_DATA_FORK);
if (!(ifp->if_flags & XFS_IFEXTENTS)) {
if ((error = xfs_iread_extents(NULL, ip, XFS_DATA_FORK)))
return error;
}
rtblks = 0;
nextents = ifp->if_bytes / (uint)sizeof(xfs_bmbt_rec_t);
for (idx = 0; idx < nextents; idx++)
rtblks += xfs_bmbt_get_blockcount(xfs_iext_get_ext(ifp, idx));
*O_rtblks = (xfs_qcnt_t)rtblks;
return 0;
}
STATIC int
xfs_qm_dqusage_adjust(
xfs_mount_t *mp,
xfs_ino_t ino,
void __user *buffer,
int ubsize,
int *ubused,
int *res)
{
xfs_inode_t *ip;
xfs_qcnt_t nblks, rtblks = 0;
int error;
ASSERT(XFS_IS_QUOTA_RUNNING(mp));
if (ino == mp->m_sb.sb_uquotino || ino == mp->m_sb.sb_gquotino) {
*res = BULKSTAT_RV_NOTHING;
return XFS_ERROR(EINVAL);
}
error = xfs_iget(mp, NULL, ino, 0, XFS_ILOCK_EXCL, &ip);
if (error) {
*res = BULKSTAT_RV_NOTHING;
return error;
}
ASSERT(ip->i_delayed_blks == 0);
if (XFS_IS_REALTIME_INODE(ip)) {
error = xfs_qm_get_rtblks(ip, &rtblks);
if (error)
goto error0;
}
nblks = (xfs_qcnt_t)ip->i_d.di_nblocks - rtblks;
if (XFS_IS_UQUOTA_ON(mp)) {
error = xfs_qm_quotacheck_dqadjust(ip, ip->i_d.di_uid,
XFS_DQ_USER, nblks, rtblks);
if (error)
goto error0;
}
if (XFS_IS_GQUOTA_ON(mp)) {
error = xfs_qm_quotacheck_dqadjust(ip, ip->i_d.di_gid,
XFS_DQ_GROUP, nblks, rtblks);
if (error)
goto error0;
}
if (XFS_IS_PQUOTA_ON(mp)) {
error = xfs_qm_quotacheck_dqadjust(ip, xfs_get_projid(ip),
XFS_DQ_PROJ, nblks, rtblks);
if (error)
goto error0;
}
xfs_iunlock(ip, XFS_ILOCK_EXCL);
IRELE(ip);
*res = BULKSTAT_RV_DIDONE;
return 0;
error0:
xfs_iunlock(ip, XFS_ILOCK_EXCL);
IRELE(ip);
*res = BULKSTAT_RV_GIVEUP;
return error;
}
int
xfs_qm_quotacheck(
xfs_mount_t *mp)
{
int done, count, error;
xfs_ino_t lastino;
size_t structsz;
xfs_inode_t *uip, *gip;
uint flags;
count = INT_MAX;
structsz = 1;
lastino = 0;
flags = 0;
ASSERT(mp->m_quotainfo->qi_uquotaip || mp->m_quotainfo->qi_gquotaip);
ASSERT(XFS_IS_QUOTA_RUNNING(mp));
ASSERT(list_empty(&mp->m_quotainfo->qi_dqlist));
xfs_notice(mp, "Quotacheck needed: Please wait.");
uip = mp->m_quotainfo->qi_uquotaip;
if (uip) {
error = xfs_qm_dqiterate(mp, uip, XFS_QMOPT_UQUOTA);
if (error)
goto error_return;
flags |= XFS_UQUOTA_CHKD;
}
gip = mp->m_quotainfo->qi_gquotaip;
if (gip) {
error = xfs_qm_dqiterate(mp, gip, XFS_IS_GQUOTA_ON(mp) ?
XFS_QMOPT_GQUOTA : XFS_QMOPT_PQUOTA);
if (error)
goto error_return;
flags |= XFS_OQUOTA_CHKD;
}
do {
error = xfs_bulkstat(mp, &lastino, &count,
xfs_qm_dqusage_adjust,
structsz, NULL, &done);
if (error)
break;
} while (!done);
if (!error)
error = xfs_qm_dqflush_all(mp);
if (error) {
xfs_qm_dqpurge_all(mp, XFS_QMOPT_QUOTALL);
goto error_return;
}
xfs_flush_buftarg(mp->m_ddev_targp, 1);
mp->m_qflags &= ~(XFS_OQUOTA_CHKD | XFS_UQUOTA_CHKD);
mp->m_qflags |= flags;
error_return:
if (error) {
xfs_warn(mp,
"Quotacheck: Unsuccessful (Error %d): Disabling quotas.",
error);
ASSERT(mp->m_quotainfo != NULL);
ASSERT(xfs_Gqm != NULL);
xfs_qm_destroy_quotainfo(mp);
if (xfs_mount_reset_sbqflags(mp)) {
xfs_warn(mp,
"Quotacheck: Failed to reset quota flags.");
}
} else
xfs_notice(mp, "Quotacheck: Done.");
return (error);
}
STATIC int
xfs_qm_init_quotainos(
xfs_mount_t *mp)
{
xfs_inode_t *uip, *gip;
int error;
__int64_t sbflags;
uint flags;
ASSERT(mp->m_quotainfo);
uip = gip = NULL;
sbflags = 0;
flags = 0;
if (xfs_sb_version_hasquota(&mp->m_sb)) {
if (XFS_IS_UQUOTA_ON(mp) &&
mp->m_sb.sb_uquotino != NULLFSINO) {
ASSERT(mp->m_sb.sb_uquotino > 0);
if ((error = xfs_iget(mp, NULL, mp->m_sb.sb_uquotino,
0, 0, &uip)))
return XFS_ERROR(error);
}
if (XFS_IS_OQUOTA_ON(mp) &&
mp->m_sb.sb_gquotino != NULLFSINO) {
ASSERT(mp->m_sb.sb_gquotino > 0);
if ((error = xfs_iget(mp, NULL, mp->m_sb.sb_gquotino,
0, 0, &gip))) {
if (uip)
IRELE(uip);
return XFS_ERROR(error);
}
}
} else {
flags |= XFS_QMOPT_SBVERSION;
sbflags |= (XFS_SB_VERSIONNUM | XFS_SB_UQUOTINO |
XFS_SB_GQUOTINO | XFS_SB_QFLAGS);
}
if (XFS_IS_UQUOTA_ON(mp) && uip == NULL) {
if ((error = xfs_qm_qino_alloc(mp, &uip,
sbflags | XFS_SB_UQUOTINO,
flags | XFS_QMOPT_UQUOTA)))
return XFS_ERROR(error);
flags &= ~XFS_QMOPT_SBVERSION;
}
if (XFS_IS_OQUOTA_ON(mp) && gip == NULL) {
flags |= (XFS_IS_GQUOTA_ON(mp) ?
XFS_QMOPT_GQUOTA : XFS_QMOPT_PQUOTA);
error = xfs_qm_qino_alloc(mp, &gip,
sbflags | XFS_SB_GQUOTINO, flags);
if (error) {
if (uip)
IRELE(uip);
return XFS_ERROR(error);
}
}
mp->m_quotainfo->qi_uquotaip = uip;
mp->m_quotainfo->qi_gquotaip = gip;
return 0;
}
STATIC void
xfs_qm_dqfree_one(
struct xfs_dquot *dqp)
{
struct xfs_mount *mp = dqp->q_mount;
struct xfs_quotainfo *qi = mp->m_quotainfo;
mutex_lock(&dqp->q_hash->qh_lock);
list_del_init(&dqp->q_hashlist);
dqp->q_hash->qh_version++;
mutex_unlock(&dqp->q_hash->qh_lock);
mutex_lock(&qi->qi_dqlist_lock);
list_del_init(&dqp->q_mplist);
qi->qi_dquots--;
qi->qi_dqreclaims++;
mutex_unlock(&qi->qi_dqlist_lock);
xfs_qm_dqdestroy(dqp);
}
STATIC void
xfs_qm_dqreclaim_one(
struct xfs_dquot *dqp,
struct list_head *dispose_list)
{
struct xfs_mount *mp = dqp->q_mount;
int error;
if (!xfs_dqlock_nowait(dqp))
goto out_busy;
if (dqp->q_nrefs) {
xfs_dqunlock(dqp);
trace_xfs_dqreclaim_want(dqp);
XQM_STATS_INC(xqmstats.xs_qm_dqwants);
list_del_init(&dqp->q_freelist);
xfs_Gqm->qm_dqfrlist_cnt--;
return;
}
ASSERT(dqp->q_hash);
ASSERT(!list_empty(&dqp->q_mplist));
if (!xfs_dqflock_nowait(dqp))
goto out_busy;
if (XFS_DQ_IS_DIRTY(dqp)) {
trace_xfs_dqreclaim_dirty(dqp);
error = xfs_qm_dqflush(dqp, 0);
if (error) {
xfs_warn(mp, "%s: dquot %p flush failed",
__func__, dqp);
}
goto out_busy;
}
xfs_dqfunlock(dqp);
dqp->dq_flags |= XFS_DQ_FREEING;
xfs_dqunlock(dqp);
ASSERT(dqp->q_nrefs == 0);
list_move_tail(&dqp->q_freelist, dispose_list);
xfs_Gqm->qm_dqfrlist_cnt--;
trace_xfs_dqreclaim_done(dqp);
XQM_STATS_INC(xqmstats.xs_qm_dqreclaims);
return;
out_busy:
xfs_dqunlock(dqp);
list_move_tail(&dqp->q_freelist, &xfs_Gqm->qm_dqfrlist);
trace_xfs_dqreclaim_busy(dqp);
XQM_STATS_INC(xqmstats.xs_qm_dqreclaim_misses);
}
STATIC int
xfs_qm_shake(
struct shrinker *shrink,
struct shrink_control *sc)
{
int nr_to_scan = sc->nr_to_scan;
LIST_HEAD (dispose_list);
struct xfs_dquot *dqp;
if ((sc->gfp_mask & (__GFP_FS|__GFP_WAIT)) != (__GFP_FS|__GFP_WAIT))
return 0;
if (!nr_to_scan)
goto out;
mutex_lock(&xfs_Gqm->qm_dqfrlist_lock);
while (!list_empty(&xfs_Gqm->qm_dqfrlist)) {
if (nr_to_scan-- <= 0)
break;
dqp = list_first_entry(&xfs_Gqm->qm_dqfrlist, struct xfs_dquot,
q_freelist);
xfs_qm_dqreclaim_one(dqp, &dispose_list);
}
mutex_unlock(&xfs_Gqm->qm_dqfrlist_lock);
while (!list_empty(&dispose_list)) {
dqp = list_first_entry(&dispose_list, struct xfs_dquot,
q_freelist);
list_del_init(&dqp->q_freelist);
xfs_qm_dqfree_one(dqp);
}
out:
return (xfs_Gqm->qm_dqfrlist_cnt / 100) * sysctl_vfs_cache_pressure;
}
int
xfs_qm_write_sb_changes(
xfs_mount_t *mp,
__int64_t flags)
{
xfs_trans_t *tp;
int error;
tp = xfs_trans_alloc(mp, XFS_TRANS_QM_SBCHANGE);
if ((error = xfs_trans_reserve(tp, 0,
mp->m_sb.sb_sectsize + 128, 0,
0,
XFS_DEFAULT_LOG_COUNT))) {
xfs_trans_cancel(tp, 0);
return error;
}
xfs_mod_sb(tp, flags);
error = xfs_trans_commit(tp, 0);
return error;
}
int
xfs_qm_vop_dqalloc(
struct xfs_inode *ip,
uid_t uid,
gid_t gid,
prid_t prid,
uint flags,
struct xfs_dquot **O_udqpp,
struct xfs_dquot **O_gdqpp)
{
struct xfs_mount *mp = ip->i_mount;
struct xfs_dquot *uq, *gq;
int error;
uint lockflags;
if (!XFS_IS_QUOTA_RUNNING(mp) || !XFS_IS_QUOTA_ON(mp))
return 0;
lockflags = XFS_ILOCK_EXCL;
xfs_ilock(ip, lockflags);
if ((flags & XFS_QMOPT_INHERIT) && XFS_INHERIT_GID(ip))
gid = ip->i_d.di_gid;
if (XFS_NOT_DQATTACHED(mp, ip)) {
error = xfs_qm_dqattach_locked(ip, XFS_QMOPT_DQALLOC);
if (error) {
xfs_iunlock(ip, lockflags);
return error;
}
}
uq = gq = NULL;
if ((flags & XFS_QMOPT_UQUOTA) && XFS_IS_UQUOTA_ON(mp)) {
if (ip->i_d.di_uid != uid) {
xfs_iunlock(ip, lockflags);
if ((error = xfs_qm_dqget(mp, NULL, (xfs_dqid_t) uid,
XFS_DQ_USER,
XFS_QMOPT_DQALLOC |
XFS_QMOPT_DOWARN,
&uq))) {
ASSERT(error != ENOENT);
return error;
}
xfs_dqunlock(uq);
lockflags = XFS_ILOCK_SHARED;
xfs_ilock(ip, lockflags);
} else {
ASSERT(ip->i_udquot);
uq = xfs_qm_dqhold(ip->i_udquot);
}
}
if ((flags & XFS_QMOPT_GQUOTA) && XFS_IS_GQUOTA_ON(mp)) {
if (ip->i_d.di_gid != gid) {
xfs_iunlock(ip, lockflags);
if ((error = xfs_qm_dqget(mp, NULL, (xfs_dqid_t)gid,
XFS_DQ_GROUP,
XFS_QMOPT_DQALLOC |
XFS_QMOPT_DOWARN,
&gq))) {
if (uq)
xfs_qm_dqrele(uq);
ASSERT(error != ENOENT);
return error;
}
xfs_dqunlock(gq);
lockflags = XFS_ILOCK_SHARED;
xfs_ilock(ip, lockflags);
} else {
ASSERT(ip->i_gdquot);
gq = xfs_qm_dqhold(ip->i_gdquot);
}
} else if ((flags & XFS_QMOPT_PQUOTA) && XFS_IS_PQUOTA_ON(mp)) {
if (xfs_get_projid(ip) != prid) {
xfs_iunlock(ip, lockflags);
if ((error = xfs_qm_dqget(mp, NULL, (xfs_dqid_t)prid,
XFS_DQ_PROJ,
XFS_QMOPT_DQALLOC |
XFS_QMOPT_DOWARN,
&gq))) {
if (uq)
xfs_qm_dqrele(uq);
ASSERT(error != ENOENT);
return (error);
}
xfs_dqunlock(gq);
lockflags = XFS_ILOCK_SHARED;
xfs_ilock(ip, lockflags);
} else {
ASSERT(ip->i_gdquot);
gq = xfs_qm_dqhold(ip->i_gdquot);
}
}
if (uq)
trace_xfs_dquot_dqalloc(ip);
xfs_iunlock(ip, lockflags);
if (O_udqpp)
*O_udqpp = uq;
else if (uq)
xfs_qm_dqrele(uq);
if (O_gdqpp)
*O_gdqpp = gq;
else if (gq)
xfs_qm_dqrele(gq);
return 0;
}
xfs_dquot_t *
xfs_qm_vop_chown(
xfs_trans_t *tp,
xfs_inode_t *ip,
xfs_dquot_t **IO_olddq,
xfs_dquot_t *newdq)
{
xfs_dquot_t *prevdq;
uint bfield = XFS_IS_REALTIME_INODE(ip) ?
XFS_TRANS_DQ_RTBCOUNT : XFS_TRANS_DQ_BCOUNT;
ASSERT(xfs_isilocked(ip, XFS_ILOCK_EXCL));
ASSERT(XFS_IS_QUOTA_RUNNING(ip->i_mount));
prevdq = *IO_olddq;
ASSERT(prevdq);
ASSERT(prevdq != newdq);
xfs_trans_mod_dquot(tp, prevdq, bfield, -(ip->i_d.di_nblocks));
xfs_trans_mod_dquot(tp, prevdq, XFS_TRANS_DQ_ICOUNT, -1);
xfs_trans_mod_dquot(tp, newdq, bfield, ip->i_d.di_nblocks);
xfs_trans_mod_dquot(tp, newdq, XFS_TRANS_DQ_ICOUNT, 1);
*IO_olddq = xfs_qm_dqhold(newdq);
return prevdq;
}
int
xfs_qm_vop_chown_reserve(
xfs_trans_t *tp,
xfs_inode_t *ip,
xfs_dquot_t *udqp,
xfs_dquot_t *gdqp,
uint flags)
{
xfs_mount_t *mp = ip->i_mount;
uint delblks, blkflags, prjflags = 0;
xfs_dquot_t *unresudq, *unresgdq, *delblksudq, *delblksgdq;
int error;
ASSERT(xfs_isilocked(ip, XFS_ILOCK_EXCL|XFS_ILOCK_SHARED));
ASSERT(XFS_IS_QUOTA_RUNNING(mp));
delblks = ip->i_delayed_blks;
delblksudq = delblksgdq = unresudq = unresgdq = NULL;
blkflags = XFS_IS_REALTIME_INODE(ip) ?
XFS_QMOPT_RES_RTBLKS : XFS_QMOPT_RES_REGBLKS;
if (XFS_IS_UQUOTA_ON(mp) && udqp &&
ip->i_d.di_uid != (uid_t)be32_to_cpu(udqp->q_core.d_id)) {
delblksudq = udqp;
if (delblks) {
ASSERT(ip->i_udquot);
unresudq = ip->i_udquot;
}
}
if (XFS_IS_OQUOTA_ON(ip->i_mount) && gdqp) {
if (XFS_IS_PQUOTA_ON(ip->i_mount) &&
xfs_get_projid(ip) != be32_to_cpu(gdqp->q_core.d_id))
prjflags = XFS_QMOPT_ENOSPC;
if (prjflags ||
(XFS_IS_GQUOTA_ON(ip->i_mount) &&
ip->i_d.di_gid != be32_to_cpu(gdqp->q_core.d_id))) {
delblksgdq = gdqp;
if (delblks) {
ASSERT(ip->i_gdquot);
unresgdq = ip->i_gdquot;
}
}
}
if ((error = xfs_trans_reserve_quota_bydquots(tp, ip->i_mount,
delblksudq, delblksgdq, ip->i_d.di_nblocks, 1,
flags | blkflags | prjflags)))
return (error);
if (delblks) {
ASSERT(delblksudq || delblksgdq);
ASSERT(unresudq || unresgdq);
if ((error = xfs_trans_reserve_quota_bydquots(NULL, ip->i_mount,
delblksudq, delblksgdq, (xfs_qcnt_t)delblks, 0,
flags | blkflags | prjflags)))
return (error);
xfs_trans_reserve_quota_bydquots(NULL, ip->i_mount,
unresudq, unresgdq, -((xfs_qcnt_t)delblks), 0,
blkflags);
}
return (0);
}
int
xfs_qm_vop_rename_dqattach(
struct xfs_inode **i_tab)
{
struct xfs_mount *mp = i_tab[0]->i_mount;
int i;
if (!XFS_IS_QUOTA_RUNNING(mp) || !XFS_IS_QUOTA_ON(mp))
return 0;
for (i = 0; (i < 4 && i_tab[i]); i++) {
struct xfs_inode *ip = i_tab[i];
int error;
if (i == 0 || ip != i_tab[i-1]) {
if (XFS_NOT_DQATTACHED(mp, ip)) {
error = xfs_qm_dqattach(ip, 0);
if (error)
return error;
}
}
}
return 0;
}
void
xfs_qm_vop_create_dqattach(
struct xfs_trans *tp,
struct xfs_inode *ip,
struct xfs_dquot *udqp,
struct xfs_dquot *gdqp)
{
struct xfs_mount *mp = tp->t_mountp;
if (!XFS_IS_QUOTA_RUNNING(mp) || !XFS_IS_QUOTA_ON(mp))
return;
ASSERT(xfs_isilocked(ip, XFS_ILOCK_EXCL));
ASSERT(XFS_IS_QUOTA_RUNNING(mp));
if (udqp) {
ASSERT(ip->i_udquot == NULL);
ASSERT(XFS_IS_UQUOTA_ON(mp));
ASSERT(ip->i_d.di_uid == be32_to_cpu(udqp->q_core.d_id));
ip->i_udquot = xfs_qm_dqhold(udqp);
xfs_trans_mod_dquot(tp, udqp, XFS_TRANS_DQ_ICOUNT, 1);
}
if (gdqp) {
ASSERT(ip->i_gdquot == NULL);
ASSERT(XFS_IS_OQUOTA_ON(mp));
ASSERT((XFS_IS_GQUOTA_ON(mp) ?
ip->i_d.di_gid : xfs_get_projid(ip)) ==
be32_to_cpu(gdqp->q_core.d_id));
ip->i_gdquot = xfs_qm_dqhold(gdqp);
xfs_trans_mod_dquot(tp, gdqp, XFS_TRANS_DQ_ICOUNT, 1);
}
}
