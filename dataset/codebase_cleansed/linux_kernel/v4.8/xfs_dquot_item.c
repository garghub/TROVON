static inline struct xfs_dq_logitem *DQUOT_ITEM(struct xfs_log_item *lip)
{
return container_of(lip, struct xfs_dq_logitem, qli_item);
}
STATIC void
xfs_qm_dquot_logitem_size(
struct xfs_log_item *lip,
int *nvecs,
int *nbytes)
{
*nvecs += 2;
*nbytes += sizeof(struct xfs_dq_logformat) +
sizeof(struct xfs_disk_dquot);
}
STATIC void
xfs_qm_dquot_logitem_format(
struct xfs_log_item *lip,
struct xfs_log_vec *lv)
{
struct xfs_dq_logitem *qlip = DQUOT_ITEM(lip);
struct xfs_log_iovec *vecp = NULL;
struct xfs_dq_logformat *qlf;
qlf = xlog_prepare_iovec(lv, &vecp, XLOG_REG_TYPE_QFORMAT);
qlf->qlf_type = XFS_LI_DQUOT;
qlf->qlf_size = 2;
qlf->qlf_id = be32_to_cpu(qlip->qli_dquot->q_core.d_id);
qlf->qlf_blkno = qlip->qli_dquot->q_blkno;
qlf->qlf_len = 1;
qlf->qlf_boffset = qlip->qli_dquot->q_bufoffset;
xlog_finish_iovec(lv, vecp, sizeof(struct xfs_dq_logformat));
xlog_copy_iovec(lv, &vecp, XLOG_REG_TYPE_DQUOT,
&qlip->qli_dquot->q_core,
sizeof(struct xfs_disk_dquot));
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
struct list_head *buffer_list) __releases(&lip->li_ailp->xa_lock
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
}
static inline struct xfs_qoff_logitem *QOFF_ITEM(struct xfs_log_item *lip)
{
return container_of(lip, struct xfs_qoff_logitem, qql_item);
}
STATIC void
xfs_qm_qoff_logitem_size(
struct xfs_log_item *lip,
int *nvecs,
int *nbytes)
{
*nvecs += 1;
*nbytes += sizeof(struct xfs_qoff_logitem);
}
STATIC void
xfs_qm_qoff_logitem_format(
struct xfs_log_item *lip,
struct xfs_log_vec *lv)
{
struct xfs_qoff_logitem *qflip = QOFF_ITEM(lip);
struct xfs_log_iovec *vecp = NULL;
struct xfs_qoff_logformat *qlf;
qlf = xlog_prepare_iovec(lv, &vecp, XLOG_REG_TYPE_QUOTAOFF);
qlf->qf_type = XFS_LI_QUOTAOFF;
qlf->qf_size = 1;
qlf->qf_flags = qflip->qql_flags;
xlog_finish_iovec(lv, vecp, sizeof(struct xfs_qoff_logitem));
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
kmem_free(qfs->qql_item.li_lv_shadow);
kmem_free(lip->li_lv_shadow);
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
qf->qql_start_lip = start;
qf->qql_flags = flags;
return qf;
}
