static inline struct xfs_dq_logitem *DQUOT_ITEM(struct xfs_log_item *lip)
{
return container_of(lip, struct xfs_dq_logitem, qli_item);
}
STATIC uint
xfs_qm_dquot_logitem_size(
struct xfs_log_item *lip)
{
return 2;
}
STATIC void
xfs_qm_dquot_logitem_format(
struct xfs_log_item *lip,
struct xfs_log_iovec *logvec)
{
struct xfs_dq_logitem *qlip = DQUOT_ITEM(lip);
logvec->i_addr = &qlip->qli_format;
logvec->i_len = sizeof(xfs_dq_logformat_t);
logvec->i_type = XLOG_REG_TYPE_QFORMAT;
logvec++;
logvec->i_addr = &qlip->qli_dquot->q_core;
logvec->i_len = sizeof(xfs_disk_dquot_t);
logvec->i_type = XLOG_REG_TYPE_DQUOT;
qlip->qli_format.qlf_size = 2;
}
STATIC void
xfs_qm_dquot_logitem_pin(
struct xfs_log_item *lip)
{
struct xfs_dquot *dqp = DQUOT_ITEM(lip)->qli_dquot;
ASSERT(XFS_DQ_IS_LOCKED(dqp));
atomic_inc(&dqp->q_pincount);
}
STATIC void
xfs_qm_dquot_logitem_unpin(
struct xfs_log_item *lip,
int remove)
{
struct xfs_dquot *dqp = DQUOT_ITEM(lip)->qli_dquot;
ASSERT(atomic_read(&dqp->q_pincount) > 0);
if (atomic_dec_and_test(&dqp->q_pincount))
wake_up(&dqp->q_pinwait);
}
STATIC xfs_lsn_t
xfs_qm_dquot_logitem_committed(
struct xfs_log_item *lip,
xfs_lsn_t lsn)
{
return lsn;
}
void
xfs_qm_dqunpin_wait(
struct xfs_dquot *dqp)
{
ASSERT(XFS_DQ_IS_LOCKED(dqp));
if (atomic_read(&dqp->q_pincount) == 0)
return;
xfs_log_force(dqp->q_mount, 0);
wait_event(dqp->q_pinwait, (atomic_read(&dqp->q_pincount) == 0));
}
STATIC uint
xfs_qm_dquot_logitem_push(
struct xfs_log_item *lip,
struct list_head *buffer_list)
{
struct xfs_dquot *dqp = DQUOT_ITEM(lip)->qli_dquot;
struct xfs_buf *bp = NULL;
uint rval = XFS_ITEM_SUCCESS;
int error;
if (atomic_read(&dqp->q_pincount) > 0)
return XFS_ITEM_PINNED;
if (!xfs_dqlock_nowait(dqp))
return XFS_ITEM_LOCKED;
if (atomic_read(&dqp->q_pincount) > 0) {
rval = XFS_ITEM_PINNED;
goto out_unlock;
}
if (!xfs_dqflock_nowait(dqp)) {
rval = XFS_ITEM_FLUSHING;
goto out_unlock;
}
spin_unlock(&lip->li_ailp->xa_lock);
error = xfs_qm_dqflush(dqp, &bp);
if (error) {
xfs_warn(dqp->q_mount, "%s: push error %d on dqp %p",
__func__, error, dqp);
} else {
if (!xfs_buf_delwri_queue(bp, buffer_list))
rval = XFS_ITEM_FLUSHING;
xfs_buf_relse(bp);
}
spin_lock(&lip->li_ailp->xa_lock);
out_unlock:
xfs_dqunlock(dqp);
return rval;
}
STATIC void
xfs_qm_dquot_logitem_unlock(
struct xfs_log_item *lip)
{
struct xfs_dquot *dqp = DQUOT_ITEM(lip)->qli_dquot;
ASSERT(XFS_DQ_IS_LOCKED(dqp));
dqp->q_transp = NULL;
xfs_dqunlock(dqp);
}
STATIC void
xfs_qm_dquot_logitem_committing(
struct xfs_log_item *lip,
xfs_lsn_t lsn)
{
}
void
xfs_qm_dquot_logitem_init(
struct xfs_dquot *dqp)
{
struct xfs_dq_logitem *lp = &dqp->q_logitem;
xfs_log_item_init(dqp->q_mount, &lp->qli_item, XFS_LI_DQUOT,
&xfs_dquot_item_ops);
lp->qli_dquot = dqp;
lp->qli_format.qlf_type = XFS_LI_DQUOT;
lp->qli_format.qlf_id = be32_to_cpu(dqp->q_core.d_id);
lp->qli_format.qlf_blkno = dqp->q_blkno;
lp->qli_format.qlf_len = 1;
lp->qli_format.qlf_boffset = (__uint32_t)dqp->q_bufoffset;
}
static inline struct xfs_qoff_logitem *QOFF_ITEM(struct xfs_log_item *lip)
{
return container_of(lip, struct xfs_qoff_logitem, qql_item);
}
STATIC uint
xfs_qm_qoff_logitem_size(
struct xfs_log_item *lip)
{
return 1;
}
STATIC void
xfs_qm_qoff_logitem_format(
struct xfs_log_item *lip,
struct xfs_log_iovec *log_vector)
{
struct xfs_qoff_logitem *qflip = QOFF_ITEM(lip);
ASSERT(qflip->qql_format.qf_type == XFS_LI_QUOTAOFF);
log_vector->i_addr = &qflip->qql_format;
log_vector->i_len = sizeof(xfs_qoff_logitem_t);
log_vector->i_type = XLOG_REG_TYPE_QUOTAOFF;
qflip->qql_format.qf_size = 1;
}
STATIC void
xfs_qm_qoff_logitem_pin(
struct xfs_log_item *lip)
{
}
STATIC void
xfs_qm_qoff_logitem_unpin(
struct xfs_log_item *lip,
int remove)
{
}
STATIC uint
xfs_qm_qoff_logitem_push(
struct xfs_log_item *lip,
struct list_head *buffer_list)
{
return XFS_ITEM_LOCKED;
}
STATIC void
xfs_qm_qoff_logitem_unlock(
struct xfs_log_item *lip)
{
}
STATIC xfs_lsn_t
xfs_qm_qoff_logitem_committed(
struct xfs_log_item *lip,
xfs_lsn_t lsn)
{
return lsn;
}
STATIC xfs_lsn_t
xfs_qm_qoffend_logitem_committed(
struct xfs_log_item *lip,
xfs_lsn_t lsn)
{
struct xfs_qoff_logitem *qfe = QOFF_ITEM(lip);
struct xfs_qoff_logitem *qfs = qfe->qql_start_lip;
struct xfs_ail *ailp = qfs->qql_item.li_ailp;
spin_lock(&ailp->xa_lock);
xfs_trans_ail_delete(ailp, &qfs->qql_item, SHUTDOWN_LOG_IO_ERROR);
kmem_free(qfs);
kmem_free(qfe);
return (xfs_lsn_t)-1;
}
STATIC void
xfs_qm_qoff_logitem_committing(
struct xfs_log_item *lip,
xfs_lsn_t commit_lsn)
{
}
struct xfs_qoff_logitem *
xfs_qm_qoff_logitem_init(
struct xfs_mount *mp,
struct xfs_qoff_logitem *start,
uint flags)
{
struct xfs_qoff_logitem *qf;
qf = kmem_zalloc(sizeof(struct xfs_qoff_logitem), KM_SLEEP);
xfs_log_item_init(mp, &qf->qql_item, XFS_LI_QUOTAOFF, start ?
&xfs_qm_qoffend_logitem_ops : &xfs_qm_qoff_logitem_ops);
qf->qql_item.li_mountp = mp;
qf->qql_format.qf_type = XFS_LI_QUOTAOFF;
qf->qql_format.qf_flags = flags;
qf->qql_start_lip = start;
return qf;
}
