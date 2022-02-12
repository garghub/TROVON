xfs_efi_log_item_t *
xfs_trans_get_efi(xfs_trans_t *tp,
uint nextents)
{
xfs_efi_log_item_t *efip;
ASSERT(tp != NULL);
ASSERT(nextents > 0);
efip = xfs_efi_init(tp->t_mountp, nextents);
ASSERT(efip != NULL);
xfs_trans_add_item(tp, &efip->efi_item);
return efip;
}
void
xfs_trans_log_efi_extent(xfs_trans_t *tp,
xfs_efi_log_item_t *efip,
xfs_fsblock_t start_block,
xfs_extlen_t ext_len)
{
uint next_extent;
xfs_extent_t *extp;
tp->t_flags |= XFS_TRANS_DIRTY;
efip->efi_item.li_desc->lid_flags |= XFS_LID_DIRTY;
next_extent = atomic_inc_return(&efip->efi_next_extent) - 1;
ASSERT(next_extent < efip->efi_format.efi_nextents);
extp = &(efip->efi_format.efi_extents[next_extent]);
extp->ext_start = start_block;
extp->ext_len = ext_len;
}
xfs_efd_log_item_t *
xfs_trans_get_efd(xfs_trans_t *tp,
xfs_efi_log_item_t *efip,
uint nextents)
{
xfs_efd_log_item_t *efdp;
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
xfs_extlen_t ext_len)
{
uint next_extent;
struct xfs_extent *extp;
int error;
error = xfs_free_extent(tp, start_block, ext_len);
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
