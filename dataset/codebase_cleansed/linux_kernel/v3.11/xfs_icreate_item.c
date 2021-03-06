static inline struct xfs_icreate_item *ICR_ITEM(struct xfs_log_item *lip)
{
return container_of(lip, struct xfs_icreate_item, ic_item);
}
STATIC uint
xfs_icreate_item_size(
struct xfs_log_item *lip)
{
return 1;
}
STATIC void
xfs_icreate_item_format(
struct xfs_log_item *lip,
struct xfs_log_iovec *log_vector)
{
struct xfs_icreate_item *icp = ICR_ITEM(lip);
log_vector->i_addr = (xfs_caddr_t)&icp->ic_format;
log_vector->i_len = sizeof(struct xfs_icreate_log);
log_vector->i_type = XLOG_REG_TYPE_ICREATE;
}
STATIC void
xfs_icreate_item_pin(
struct xfs_log_item *lip)
{
}
STATIC void
xfs_icreate_item_unpin(
struct xfs_log_item *lip,
int remove)
{
}
STATIC void
xfs_icreate_item_unlock(
struct xfs_log_item *lip)
{
struct xfs_icreate_item *icp = ICR_ITEM(lip);
if (icp->ic_item.li_flags & XFS_LI_ABORTED)
kmem_zone_free(xfs_icreate_zone, icp);
return;
}
STATIC xfs_lsn_t
xfs_icreate_item_committed(
struct xfs_log_item *lip,
xfs_lsn_t lsn)
{
struct xfs_icreate_item *icp = ICR_ITEM(lip);
kmem_zone_free(xfs_icreate_zone, icp);
return (xfs_lsn_t)-1;
}
STATIC uint
xfs_icreate_item_push(
struct xfs_log_item *lip,
struct list_head *buffer_list)
{
ASSERT(0);
return XFS_ITEM_SUCCESS;
}
STATIC void
xfs_icreate_item_committing(
struct xfs_log_item *lip,
xfs_lsn_t lsn)
{
}
void
xfs_icreate_log(
struct xfs_trans *tp,
xfs_agnumber_t agno,
xfs_agblock_t agbno,
unsigned int count,
unsigned int inode_size,
xfs_agblock_t length,
unsigned int generation)
{
struct xfs_icreate_item *icp;
icp = kmem_zone_zalloc(xfs_icreate_zone, KM_SLEEP);
xfs_log_item_init(tp->t_mountp, &icp->ic_item, XFS_LI_ICREATE,
&xfs_icreate_item_ops);
icp->ic_format.icl_type = XFS_LI_ICREATE;
icp->ic_format.icl_size = 1;
icp->ic_format.icl_ag = cpu_to_be32(agno);
icp->ic_format.icl_agbno = cpu_to_be32(agbno);
icp->ic_format.icl_count = cpu_to_be32(count);
icp->ic_format.icl_isize = cpu_to_be32(inode_size);
icp->ic_format.icl_length = cpu_to_be32(length);
icp->ic_format.icl_gen = cpu_to_be32(generation);
xfs_trans_add_item(tp, &icp->ic_item);
tp->t_flags |= XFS_TRANS_DIRTY;
icp->ic_item.li_desc->lid_flags |= XFS_LID_DIRTY;
}
