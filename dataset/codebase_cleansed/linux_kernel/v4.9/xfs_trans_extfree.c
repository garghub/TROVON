struct xfs_efd_log_item *
xfs_trans_get_efd(struct xfs_trans *tp,
struct xfs_efi_log_item *efip,
uint nextents)
{
struct xfs_efd_log_item *efdp;
ASSERT(tp != NULL);
ASSERT(nextents > 0);
efdp = xfs_efd_init(tp->t_mountp, efip, nextents);
ASSERT(efdp != NULL);
xfs_trans_add_item(tp, &efdp->efd_item);
return efdp;
}
int
xfs_trans_free_extent(
struct xfs_trans *tp,
struct xfs_efd_log_item *efdp,
xfs_fsblock_t start_block,
xfs_extlen_t ext_len,
struct xfs_owner_info *oinfo)
{
struct xfs_mount *mp = tp->t_mountp;
uint next_extent;
xfs_agnumber_t agno = XFS_FSB_TO_AGNO(mp, start_block);
xfs_agblock_t agbno = XFS_FSB_TO_AGBNO(mp, start_block);
struct xfs_extent *extp;
int error;
trace_xfs_bmap_free_deferred(tp->t_mountp, agno, 0, agbno, ext_len);
error = xfs_free_extent(tp, start_block, ext_len, oinfo,
XFS_AG_RESV_NONE);
tp->t_flags |= XFS_TRANS_DIRTY;
efdp->efd_item.li_desc->lid_flags |= XFS_LID_DIRTY;
next_extent = efdp->efd_next_extent;
ASSERT(next_extent < efdp->efd_format.efd_nextents);
extp = &(efdp->efd_format.efd_extents[next_extent]);
extp->ext_start = start_block;
extp->ext_len = ext_len;
efdp->efd_next_extent++;
return error;
}
static int
xfs_extent_free_diff_items(
void *priv,
struct list_head *a,
struct list_head *b)
{
struct xfs_mount *mp = priv;
struct xfs_extent_free_item *ra;
struct xfs_extent_free_item *rb;
ra = container_of(a, struct xfs_extent_free_item, xefi_list);
rb = container_of(b, struct xfs_extent_free_item, xefi_list);
return XFS_FSB_TO_AGNO(mp, ra->xefi_startblock) -
XFS_FSB_TO_AGNO(mp, rb->xefi_startblock);
}
STATIC void *
xfs_extent_free_create_intent(
struct xfs_trans *tp,
unsigned int count)
{
struct xfs_efi_log_item *efip;
ASSERT(tp != NULL);
ASSERT(count > 0);
efip = xfs_efi_init(tp->t_mountp, count);
ASSERT(efip != NULL);
xfs_trans_add_item(tp, &efip->efi_item);
return efip;
}
STATIC void
xfs_extent_free_log_item(
struct xfs_trans *tp,
void *intent,
struct list_head *item)
{
struct xfs_efi_log_item *efip = intent;
struct xfs_extent_free_item *free;
uint next_extent;
struct xfs_extent *extp;
free = container_of(item, struct xfs_extent_free_item, xefi_list);
tp->t_flags |= XFS_TRANS_DIRTY;
efip->efi_item.li_desc->lid_flags |= XFS_LID_DIRTY;
next_extent = atomic_inc_return(&efip->efi_next_extent) - 1;
ASSERT(next_extent < efip->efi_format.efi_nextents);
extp = &efip->efi_format.efi_extents[next_extent];
extp->ext_start = free->xefi_startblock;
extp->ext_len = free->xefi_blockcount;
}
STATIC void *
xfs_extent_free_create_done(
struct xfs_trans *tp,
void *intent,
unsigned int count)
{
return xfs_trans_get_efd(tp, intent, count);
}
STATIC int
xfs_extent_free_finish_item(
struct xfs_trans *tp,
struct xfs_defer_ops *dop,
struct list_head *item,
void *done_item,
void **state)
{
struct xfs_extent_free_item *free;
int error;
free = container_of(item, struct xfs_extent_free_item, xefi_list);
error = xfs_trans_free_extent(tp, done_item,
free->xefi_startblock,
free->xefi_blockcount,
&free->xefi_oinfo);
kmem_free(free);
return error;
}
STATIC void
xfs_extent_free_abort_intent(
void *intent)
{
xfs_efi_release(intent);
}
STATIC void
xfs_extent_free_cancel_item(
struct list_head *item)
{
struct xfs_extent_free_item *free;
free = container_of(item, struct xfs_extent_free_item, xefi_list);
kmem_free(free);
}
void
xfs_extent_free_init_defer_op(void)
{
xfs_defer_init_op_type(&xfs_extent_free_defer_type);
}
