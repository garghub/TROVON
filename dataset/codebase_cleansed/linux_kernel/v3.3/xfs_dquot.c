void
xfs_qm_dqdestroy(
xfs_dquot_t *dqp)
{
ASSERT(list_empty(&dqp->q_freelist));
mutex_destroy(&dqp->q_qlock);
kmem_zone_free(xfs_Gqm->qm_dqzone, dqp);
atomic_dec(&xfs_Gqm->qm_totaldquots);
}
void
xfs_qm_adjust_dqlimits(
xfs_mount_t *mp,
xfs_disk_dquot_t *d)
{
xfs_quotainfo_t *q = mp->m_quotainfo;
ASSERT(d->d_id);
if (q->qi_bsoftlimit && !d->d_blk_softlimit)
d->d_blk_softlimit = cpu_to_be64(q->qi_bsoftlimit);
if (q->qi_bhardlimit && !d->d_blk_hardlimit)
d->d_blk_hardlimit = cpu_to_be64(q->qi_bhardlimit);
if (q->qi_isoftlimit && !d->d_ino_softlimit)
d->d_ino_softlimit = cpu_to_be64(q->qi_isoftlimit);
if (q->qi_ihardlimit && !d->d_ino_hardlimit)
d->d_ino_hardlimit = cpu_to_be64(q->qi_ihardlimit);
if (q->qi_rtbsoftlimit && !d->d_rtb_softlimit)
d->d_rtb_softlimit = cpu_to_be64(q->qi_rtbsoftlimit);
if (q->qi_rtbhardlimit && !d->d_rtb_hardlimit)
d->d_rtb_hardlimit = cpu_to_be64(q->qi_rtbhardlimit);
}
void
xfs_qm_adjust_dqtimers(
xfs_mount_t *mp,
xfs_disk_dquot_t *d)
{
ASSERT(d->d_id);
#ifdef DEBUG
if (d->d_blk_hardlimit)
ASSERT(be64_to_cpu(d->d_blk_softlimit) <=
be64_to_cpu(d->d_blk_hardlimit));
if (d->d_ino_hardlimit)
ASSERT(be64_to_cpu(d->d_ino_softlimit) <=
be64_to_cpu(d->d_ino_hardlimit));
if (d->d_rtb_hardlimit)
ASSERT(be64_to_cpu(d->d_rtb_softlimit) <=
be64_to_cpu(d->d_rtb_hardlimit));
#endif
if (!d->d_btimer) {
if ((d->d_blk_softlimit &&
(be64_to_cpu(d->d_bcount) >
be64_to_cpu(d->d_blk_softlimit))) ||
(d->d_blk_hardlimit &&
(be64_to_cpu(d->d_bcount) >
be64_to_cpu(d->d_blk_hardlimit)))) {
d->d_btimer = cpu_to_be32(get_seconds() +
mp->m_quotainfo->qi_btimelimit);
} else {
d->d_bwarns = 0;
}
} else {
if ((!d->d_blk_softlimit ||
(be64_to_cpu(d->d_bcount) <=
be64_to_cpu(d->d_blk_softlimit))) &&
(!d->d_blk_hardlimit ||
(be64_to_cpu(d->d_bcount) <=
be64_to_cpu(d->d_blk_hardlimit)))) {
d->d_btimer = 0;
}
}
if (!d->d_itimer) {
if ((d->d_ino_softlimit &&
(be64_to_cpu(d->d_icount) >
be64_to_cpu(d->d_ino_softlimit))) ||
(d->d_ino_hardlimit &&
(be64_to_cpu(d->d_icount) >
be64_to_cpu(d->d_ino_hardlimit)))) {
d->d_itimer = cpu_to_be32(get_seconds() +
mp->m_quotainfo->qi_itimelimit);
} else {
d->d_iwarns = 0;
}
} else {
if ((!d->d_ino_softlimit ||
(be64_to_cpu(d->d_icount) <=
be64_to_cpu(d->d_ino_softlimit))) &&
(!d->d_ino_hardlimit ||
(be64_to_cpu(d->d_icount) <=
be64_to_cpu(d->d_ino_hardlimit)))) {
d->d_itimer = 0;
}
}
if (!d->d_rtbtimer) {
if ((d->d_rtb_softlimit &&
(be64_to_cpu(d->d_rtbcount) >
be64_to_cpu(d->d_rtb_softlimit))) ||
(d->d_rtb_hardlimit &&
(be64_to_cpu(d->d_rtbcount) >
be64_to_cpu(d->d_rtb_hardlimit)))) {
d->d_rtbtimer = cpu_to_be32(get_seconds() +
mp->m_quotainfo->qi_rtbtimelimit);
} else {
d->d_rtbwarns = 0;
}
} else {
if ((!d->d_rtb_softlimit ||
(be64_to_cpu(d->d_rtbcount) <=
be64_to_cpu(d->d_rtb_softlimit))) &&
(!d->d_rtb_hardlimit ||
(be64_to_cpu(d->d_rtbcount) <=
be64_to_cpu(d->d_rtb_hardlimit)))) {
d->d_rtbtimer = 0;
}
}
}
STATIC void
xfs_qm_init_dquot_blk(
xfs_trans_t *tp,
xfs_mount_t *mp,
xfs_dqid_t id,
uint type,
xfs_buf_t *bp)
{
struct xfs_quotainfo *q = mp->m_quotainfo;
xfs_dqblk_t *d;
int curid, i;
ASSERT(tp);
ASSERT(xfs_buf_islocked(bp));
d = bp->b_addr;
curid = id - (id % q->qi_dqperchunk);
ASSERT(curid >= 0);
memset(d, 0, BBTOB(q->qi_dqchunklen));
for (i = 0; i < q->qi_dqperchunk; i++, d++, curid++) {
d->dd_diskdq.d_magic = cpu_to_be16(XFS_DQUOT_MAGIC);
d->dd_diskdq.d_version = XFS_DQUOT_VERSION;
d->dd_diskdq.d_id = cpu_to_be32(curid);
d->dd_diskdq.d_flags = type;
}
xfs_trans_dquot_buf(tp, bp,
(type & XFS_DQ_USER ? XFS_BLF_UDQUOT_BUF :
((type & XFS_DQ_PROJ) ? XFS_BLF_PDQUOT_BUF :
XFS_BLF_GDQUOT_BUF)));
xfs_trans_log_buf(tp, bp, 0, BBTOB(q->qi_dqchunklen) - 1);
}
STATIC int
xfs_qm_dqalloc(
xfs_trans_t **tpp,
xfs_mount_t *mp,
xfs_dquot_t *dqp,
xfs_inode_t *quotip,
xfs_fileoff_t offset_fsb,
xfs_buf_t **O_bpp)
{
xfs_fsblock_t firstblock;
xfs_bmap_free_t flist;
xfs_bmbt_irec_t map;
int nmaps, error, committed;
xfs_buf_t *bp;
xfs_trans_t *tp = *tpp;
ASSERT(tp != NULL);
trace_xfs_dqalloc(dqp);
xfs_bmap_init(&flist, &firstblock);
xfs_ilock(quotip, XFS_ILOCK_EXCL);
if (XFS_IS_THIS_QUOTA_OFF(dqp)) {
xfs_iunlock(quotip, XFS_ILOCK_EXCL);
return (ESRCH);
}
xfs_trans_ijoin(tp, quotip, XFS_ILOCK_EXCL);
nmaps = 1;
error = xfs_bmapi_write(tp, quotip, offset_fsb,
XFS_DQUOT_CLUSTER_SIZE_FSB, XFS_BMAPI_METADATA,
&firstblock, XFS_QM_DQALLOC_SPACE_RES(mp),
&map, &nmaps, &flist);
if (error)
goto error0;
ASSERT(map.br_blockcount == XFS_DQUOT_CLUSTER_SIZE_FSB);
ASSERT(nmaps == 1);
ASSERT((map.br_startblock != DELAYSTARTBLOCK) &&
(map.br_startblock != HOLESTARTBLOCK));
dqp->q_blkno = XFS_FSB_TO_DADDR(mp, map.br_startblock);
bp = xfs_trans_get_buf(tp, mp->m_ddev_targp,
dqp->q_blkno,
mp->m_quotainfo->qi_dqchunklen,
0);
error = xfs_buf_geterror(bp);
if (error)
goto error1;
xfs_qm_init_dquot_blk(tp, mp, be32_to_cpu(dqp->q_core.d_id),
dqp->dq_flags & XFS_DQ_ALLTYPES, bp);
xfs_trans_bhold(tp, bp);
if ((error = xfs_bmap_finish(tpp, &flist, &committed))) {
goto error1;
}
if (committed) {
tp = *tpp;
xfs_trans_bjoin(tp, bp);
} else {
xfs_trans_bhold_release(tp, bp);
}
*O_bpp = bp;
return 0;
error1:
xfs_bmap_cancel(&flist);
error0:
xfs_iunlock(quotip, XFS_ILOCK_EXCL);
return (error);
}
STATIC int
xfs_qm_dqtobp(
xfs_trans_t **tpp,
xfs_dquot_t *dqp,
xfs_disk_dquot_t **O_ddpp,
xfs_buf_t **O_bpp,
uint flags)
{
xfs_bmbt_irec_t map;
int nmaps = 1, error;
xfs_buf_t *bp;
xfs_inode_t *quotip = XFS_DQ_TO_QIP(dqp);
xfs_mount_t *mp = dqp->q_mount;
xfs_disk_dquot_t *ddq;
xfs_dqid_t id = be32_to_cpu(dqp->q_core.d_id);
xfs_trans_t *tp = (tpp ? *tpp : NULL);
dqp->q_fileoffset = (xfs_fileoff_t)id / mp->m_quotainfo->qi_dqperchunk;
xfs_ilock(quotip, XFS_ILOCK_SHARED);
if (XFS_IS_THIS_QUOTA_OFF(dqp)) {
xfs_iunlock(quotip, XFS_ILOCK_SHARED);
return ESRCH;
}
error = xfs_bmapi_read(quotip, dqp->q_fileoffset,
XFS_DQUOT_CLUSTER_SIZE_FSB, &map, &nmaps, 0);
xfs_iunlock(quotip, XFS_ILOCK_SHARED);
if (error)
return error;
ASSERT(nmaps == 1);
ASSERT(map.br_blockcount == 1);
dqp->q_bufoffset = (id % mp->m_quotainfo->qi_dqperchunk) *
sizeof(xfs_dqblk_t);
ASSERT(map.br_startblock != DELAYSTARTBLOCK);
if (map.br_startblock == HOLESTARTBLOCK) {
if (!(flags & XFS_QMOPT_DQALLOC))
return ENOENT;
ASSERT(tp);
error = xfs_qm_dqalloc(tpp, mp, dqp, quotip,
dqp->q_fileoffset, &bp);
if (error)
return error;
tp = *tpp;
} else {
trace_xfs_dqtobp_read(dqp);
dqp->q_blkno = XFS_FSB_TO_DADDR(mp, map.br_startblock);
error = xfs_trans_read_buf(mp, tp, mp->m_ddev_targp,
dqp->q_blkno,
mp->m_quotainfo->qi_dqchunklen,
0, &bp);
if (error || !bp)
return XFS_ERROR(error);
}
ASSERT(xfs_buf_islocked(bp));
ddq = bp->b_addr + dqp->q_bufoffset;
error = xfs_qm_dqcheck(mp, ddq, id, dqp->dq_flags & XFS_DQ_ALLTYPES,
flags & (XFS_QMOPT_DQREPAIR|XFS_QMOPT_DOWARN),
"dqtobp");
if (error) {
if (!(flags & XFS_QMOPT_DQREPAIR)) {
xfs_trans_brelse(tp, bp);
return XFS_ERROR(EIO);
}
}
*O_bpp = bp;
*O_ddpp = ddq;
return (0);
}
int
xfs_qm_dqread(
struct xfs_mount *mp,
xfs_dqid_t id,
uint type,
uint flags,
struct xfs_dquot **O_dqpp)
{
struct xfs_dquot *dqp;
struct xfs_disk_dquot *ddqp;
struct xfs_buf *bp;
struct xfs_trans *tp = NULL;
int error;
int cancelflags = 0;
dqp = kmem_zone_zalloc(xfs_Gqm->qm_dqzone, KM_SLEEP);
dqp->dq_flags = type;
dqp->q_core.d_id = cpu_to_be32(id);
dqp->q_mount = mp;
INIT_LIST_HEAD(&dqp->q_freelist);
mutex_init(&dqp->q_qlock);
init_waitqueue_head(&dqp->q_pinwait);
init_completion(&dqp->q_flush);
complete(&dqp->q_flush);
if (!(type & XFS_DQ_USER))
lockdep_set_class(&dqp->q_qlock, &xfs_dquot_other_class);
atomic_inc(&xfs_Gqm->qm_totaldquots);
trace_xfs_dqread(dqp);
if (flags & XFS_QMOPT_DQALLOC) {
tp = xfs_trans_alloc(mp, XFS_TRANS_QM_DQALLOC);
error = xfs_trans_reserve(tp, XFS_QM_DQALLOC_SPACE_RES(mp),
XFS_WRITE_LOG_RES(mp) +
BBTOB(mp->m_quotainfo->qi_dqchunklen) - 1 + 128,
0,
XFS_TRANS_PERM_LOG_RES,
XFS_WRITE_LOG_COUNT);
if (error)
goto error1;
cancelflags = XFS_TRANS_RELEASE_LOG_RES;
}
error = xfs_qm_dqtobp(&tp, dqp, &ddqp, &bp, flags);
if (error) {
trace_xfs_dqread_fail(dqp);
cancelflags |= XFS_TRANS_ABORT;
goto error1;
}
memcpy(&dqp->q_core, ddqp, sizeof(xfs_disk_dquot_t));
xfs_qm_dquot_logitem_init(dqp);
dqp->q_res_bcount = be64_to_cpu(ddqp->d_bcount);
dqp->q_res_icount = be64_to_cpu(ddqp->d_icount);
dqp->q_res_rtbcount = be64_to_cpu(ddqp->d_rtbcount);
xfs_buf_set_ref(bp, XFS_DQUOT_REF);
ASSERT(xfs_buf_islocked(bp));
xfs_trans_brelse(tp, bp);
if (tp) {
error = xfs_trans_commit(tp, XFS_TRANS_RELEASE_LOG_RES);
if (error)
goto error0;
}
*O_dqpp = dqp;
return error;
error1:
if (tp)
xfs_trans_cancel(tp, cancelflags);
error0:
xfs_qm_dqdestroy(dqp);
*O_dqpp = NULL;
return error;
}
STATIC int
xfs_qm_dqlookup(
xfs_mount_t *mp,
xfs_dqid_t id,
xfs_dqhash_t *qh,
xfs_dquot_t **O_dqpp)
{
xfs_dquot_t *dqp;
ASSERT(mutex_is_locked(&qh->qh_lock));
list_for_each_entry(dqp, &qh->qh_list, q_hashlist) {
if (be32_to_cpu(dqp->q_core.d_id) != id || dqp->q_mount != mp)
continue;
trace_xfs_dqlookup_found(dqp);
xfs_dqlock(dqp);
if (dqp->dq_flags & XFS_DQ_FREEING) {
*O_dqpp = NULL;
xfs_dqunlock(dqp);
return -1;
}
dqp->q_nrefs++;
list_move(&dqp->q_hashlist, &qh->qh_list);
trace_xfs_dqlookup_done(dqp);
*O_dqpp = dqp;
return 0;
}
*O_dqpp = NULL;
return 1;
}
int
xfs_qm_dqget(
xfs_mount_t *mp,
xfs_inode_t *ip,
xfs_dqid_t id,
uint type,
uint flags,
xfs_dquot_t **O_dqpp)
{
xfs_dquot_t *dqp;
xfs_dqhash_t *h;
uint version;
int error;
ASSERT(XFS_IS_QUOTA_RUNNING(mp));
if ((! XFS_IS_UQUOTA_ON(mp) && type == XFS_DQ_USER) ||
(! XFS_IS_PQUOTA_ON(mp) && type == XFS_DQ_PROJ) ||
(! XFS_IS_GQUOTA_ON(mp) && type == XFS_DQ_GROUP)) {
return (ESRCH);
}
h = XFS_DQ_HASH(mp, id, type);
#ifdef DEBUG
if (xfs_do_dqerror) {
if ((xfs_dqerror_target == mp->m_ddev_targp) &&
(xfs_dqreq_num++ % xfs_dqerror_mod) == 0) {
xfs_debug(mp, "Returning error in dqget");
return (EIO);
}
}
ASSERT(type == XFS_DQ_USER ||
type == XFS_DQ_PROJ ||
type == XFS_DQ_GROUP);
if (ip) {
ASSERT(xfs_isilocked(ip, XFS_ILOCK_EXCL));
if (type == XFS_DQ_USER)
ASSERT(ip->i_udquot == NULL);
else
ASSERT(ip->i_gdquot == NULL);
}
#endif
restart:
mutex_lock(&h->qh_lock);
switch (xfs_qm_dqlookup(mp, id, h, O_dqpp)) {
case -1:
XQM_STATS_INC(xqmstats.xs_qm_dquot_dups);
mutex_unlock(&h->qh_lock);
delay(1);
goto restart;
case 0:
XQM_STATS_INC(xqmstats.xs_qm_dqcachehits);
ASSERT(*O_dqpp);
ASSERT(XFS_DQ_IS_LOCKED(*O_dqpp));
mutex_unlock(&h->qh_lock);
trace_xfs_dqget_hit(*O_dqpp);
return 0;
default:
XQM_STATS_INC(xqmstats.xs_qm_dqcachemisses);
break;
}
if (ip)
xfs_iunlock(ip, XFS_ILOCK_EXCL);
version = h->qh_version;
mutex_unlock(&h->qh_lock);
error = xfs_qm_dqread(mp, id, type, flags, &dqp);
if (ip)
xfs_ilock(ip, XFS_ILOCK_EXCL);
if (error)
return error;
if (ip) {
if (type == XFS_DQ_USER) {
if (!XFS_IS_UQUOTA_ON(mp)) {
xfs_qm_dqdestroy(dqp);
return XFS_ERROR(ESRCH);
}
if (ip->i_udquot) {
xfs_qm_dqdestroy(dqp);
dqp = ip->i_udquot;
xfs_dqlock(dqp);
goto dqret;
}
} else {
if (!XFS_IS_OQUOTA_ON(mp)) {
xfs_qm_dqdestroy(dqp);
return XFS_ERROR(ESRCH);
}
if (ip->i_gdquot) {
xfs_qm_dqdestroy(dqp);
dqp = ip->i_gdquot;
xfs_dqlock(dqp);
goto dqret;
}
}
}
mutex_lock(&h->qh_lock);
if (version != h->qh_version) {
xfs_dquot_t *tmpdqp;
switch (xfs_qm_dqlookup(mp, id, h, &tmpdqp)) {
case 0:
case -1:
if (tmpdqp)
xfs_qm_dqput(tmpdqp);
mutex_unlock(&h->qh_lock);
xfs_qm_dqdestroy(dqp);
XQM_STATS_INC(xqmstats.xs_qm_dquot_dups);
goto restart;
default:
break;
}
}
ASSERT(mutex_is_locked(&h->qh_lock));
dqp->q_hash = h;
list_add(&dqp->q_hashlist, &h->qh_list);
h->qh_version++;
mutex_lock(&mp->m_quotainfo->qi_dqlist_lock);
xfs_dqlock(dqp);
dqp->q_nrefs = 1;
list_add(&dqp->q_mplist, &mp->m_quotainfo->qi_dqlist);
mp->m_quotainfo->qi_dquots++;
mutex_unlock(&mp->m_quotainfo->qi_dqlist_lock);
mutex_unlock(&h->qh_lock);
dqret:
ASSERT((ip == NULL) || xfs_isilocked(ip, XFS_ILOCK_EXCL));
trace_xfs_dqget_miss(dqp);
*O_dqpp = dqp;
return (0);
}
void
xfs_qm_dqput(
struct xfs_dquot *dqp)
{
struct xfs_dquot *gdqp;
ASSERT(dqp->q_nrefs > 0);
ASSERT(XFS_DQ_IS_LOCKED(dqp));
trace_xfs_dqput(dqp);
recurse:
if (--dqp->q_nrefs > 0) {
xfs_dqunlock(dqp);
return;
}
trace_xfs_dqput_free(dqp);
mutex_lock(&xfs_Gqm->qm_dqfrlist_lock);
if (list_empty(&dqp->q_freelist)) {
list_add_tail(&dqp->q_freelist, &xfs_Gqm->qm_dqfrlist);
xfs_Gqm->qm_dqfrlist_cnt++;
}
mutex_unlock(&xfs_Gqm->qm_dqfrlist_lock);
gdqp = dqp->q_gdquot;
if (gdqp) {
xfs_dqlock(gdqp);
dqp->q_gdquot = NULL;
}
xfs_dqunlock(dqp);
if (gdqp) {
dqp = gdqp;
goto recurse;
}
}
void
xfs_qm_dqrele(
xfs_dquot_t *dqp)
{
if (!dqp)
return;
trace_xfs_dqrele(dqp);
xfs_dqlock(dqp);
xfs_qm_dqput(dqp);
}
STATIC void
xfs_qm_dqflush_done(
struct xfs_buf *bp,
struct xfs_log_item *lip)
{
xfs_dq_logitem_t *qip = (struct xfs_dq_logitem *)lip;
xfs_dquot_t *dqp = qip->qli_dquot;
struct xfs_ail *ailp = lip->li_ailp;
if ((lip->li_flags & XFS_LI_IN_AIL) &&
lip->li_lsn == qip->qli_flush_lsn) {
spin_lock(&ailp->xa_lock);
if (lip->li_lsn == qip->qli_flush_lsn)
xfs_trans_ail_delete(ailp, lip);
else
spin_unlock(&ailp->xa_lock);
}
xfs_dqfunlock(dqp);
}
int
xfs_qm_dqflush(
xfs_dquot_t *dqp,
uint flags)
{
struct xfs_mount *mp = dqp->q_mount;
struct xfs_buf *bp;
struct xfs_disk_dquot *ddqp;
int error;
ASSERT(XFS_DQ_IS_LOCKED(dqp));
ASSERT(!completion_done(&dqp->q_flush));
trace_xfs_dqflush(dqp);
if (!XFS_DQ_IS_DIRTY(dqp) ||
((flags & SYNC_TRYLOCK) && atomic_read(&dqp->q_pincount) > 0)) {
xfs_dqfunlock(dqp);
return 0;
}
xfs_qm_dqunpin_wait(dqp);
if (XFS_FORCED_SHUTDOWN(mp)) {
dqp->dq_flags &= ~XFS_DQ_DIRTY;
xfs_dqfunlock(dqp);
return XFS_ERROR(EIO);
}
error = xfs_trans_read_buf(mp, NULL, mp->m_ddev_targp, dqp->q_blkno,
mp->m_quotainfo->qi_dqchunklen, 0, &bp);
if (error) {
ASSERT(error != ENOENT);
xfs_dqfunlock(dqp);
return error;
}
ddqp = bp->b_addr + dqp->q_bufoffset;
error = xfs_qm_dqcheck(mp, &dqp->q_core, be32_to_cpu(ddqp->d_id), 0,
XFS_QMOPT_DOWARN, "dqflush (incore copy)");
if (error) {
xfs_buf_relse(bp);
xfs_dqfunlock(dqp);
xfs_force_shutdown(mp, SHUTDOWN_CORRUPT_INCORE);
return XFS_ERROR(EIO);
}
memcpy(ddqp, &dqp->q_core, sizeof(xfs_disk_dquot_t));
dqp->dq_flags &= ~XFS_DQ_DIRTY;
xfs_trans_ail_copy_lsn(mp->m_ail, &dqp->q_logitem.qli_flush_lsn,
&dqp->q_logitem.qli_item.li_lsn);
xfs_buf_attach_iodone(bp, xfs_qm_dqflush_done,
&dqp->q_logitem.qli_item);
if (xfs_buf_ispinned(bp)) {
trace_xfs_dqflush_force(dqp);
xfs_log_force(mp, 0);
}
if (flags & SYNC_WAIT)
error = xfs_bwrite(bp);
else
xfs_buf_delwri_queue(bp);
xfs_buf_relse(bp);
trace_xfs_dqflush_done(dqp);
return error;
}
void
xfs_dqunlock(
xfs_dquot_t *dqp)
{
xfs_dqunlock_nonotify(dqp);
if (dqp->q_logitem.qli_dquot == dqp) {
xfs_trans_unlocked_item(dqp->q_logitem.qli_item.li_ailp,
&dqp->q_logitem.qli_item);
}
}
void
xfs_dqlock2(
xfs_dquot_t *d1,
xfs_dquot_t *d2)
{
if (d1 && d2) {
ASSERT(d1 != d2);
if (be32_to_cpu(d1->q_core.d_id) >
be32_to_cpu(d2->q_core.d_id)) {
mutex_lock(&d2->q_qlock);
mutex_lock_nested(&d1->q_qlock, XFS_QLOCK_NESTED);
} else {
mutex_lock(&d1->q_qlock);
mutex_lock_nested(&d2->q_qlock, XFS_QLOCK_NESTED);
}
} else if (d1) {
mutex_lock(&d1->q_qlock);
} else if (d2) {
mutex_lock(&d2->q_qlock);
}
}
void
xfs_qm_dqpurge(
struct xfs_dquot *dqp)
{
struct xfs_mount *mp = dqp->q_mount;
struct xfs_dqhash *qh = dqp->q_hash;
xfs_dqlock(dqp);
if (!xfs_dqflock_nowait(dqp)) {
xfs_dqflock_pushbuf_wait(dqp);
}
if (XFS_DQ_IS_DIRTY(dqp)) {
int error;
error = xfs_qm_dqflush(dqp, SYNC_WAIT);
if (error)
xfs_warn(mp, "%s: dquot %p flush failed",
__func__, dqp);
xfs_dqflock(dqp);
}
ASSERT(atomic_read(&dqp->q_pincount) == 0);
ASSERT(XFS_FORCED_SHUTDOWN(mp) ||
!(dqp->q_logitem.qli_item.li_flags & XFS_LI_IN_AIL));
xfs_dqfunlock(dqp);
xfs_dqunlock(dqp);
mutex_lock(&qh->qh_lock);
list_del_init(&dqp->q_hashlist);
qh->qh_version++;
mutex_unlock(&qh->qh_lock);
mutex_lock(&mp->m_quotainfo->qi_dqlist_lock);
list_del_init(&dqp->q_mplist);
mp->m_quotainfo->qi_dqreclaims++;
mp->m_quotainfo->qi_dquots--;
mutex_unlock(&mp->m_quotainfo->qi_dqlist_lock);
mutex_lock(&xfs_Gqm->qm_dqfrlist_lock);
ASSERT(!list_empty(&dqp->q_freelist));
list_del_init(&dqp->q_freelist);
xfs_Gqm->qm_dqfrlist_cnt--;
mutex_unlock(&xfs_Gqm->qm_dqfrlist_lock);
xfs_qm_dqdestroy(dqp);
}
void
xfs_dqflock_pushbuf_wait(
xfs_dquot_t *dqp)
{
xfs_mount_t *mp = dqp->q_mount;
xfs_buf_t *bp;
bp = xfs_incore(mp->m_ddev_targp, dqp->q_blkno,
mp->m_quotainfo->qi_dqchunklen, XBF_TRYLOCK);
if (!bp)
goto out_lock;
if (XFS_BUF_ISDELAYWRITE(bp)) {
if (xfs_buf_ispinned(bp))
xfs_log_force(mp, 0);
xfs_buf_delwri_promote(bp);
wake_up_process(bp->b_target->bt_task);
}
xfs_buf_relse(bp);
out_lock:
xfs_dqflock(dqp);
}
