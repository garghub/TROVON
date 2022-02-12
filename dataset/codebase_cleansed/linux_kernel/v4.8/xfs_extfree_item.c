static inline struct xfs_efi_log_item *EFI_ITEM(struct xfs_log_item *lip)
{
return container_of(lip, struct xfs_efi_log_item, efi_item);
}
void
xfs_efi_item_free(
struct xfs_efi_log_item *efip)
{
kmem_free(efip->efi_item.li_lv_shadow);
if (efip->efi_format.efi_nextents > XFS_EFI_MAX_FAST_EXTENTS)
kmem_free(efip);
else
kmem_zone_free(xfs_efi_zone, efip);
}
static inline int
xfs_efi_item_sizeof(
struct xfs_efi_log_item *efip)
{
return sizeof(struct xfs_efi_log_format) +
(efip->efi_format.efi_nextents - 1) * sizeof(xfs_extent_t);
}
STATIC void
xfs_efi_item_size(
struct xfs_log_item *lip,
int *nvecs,
int *nbytes)
{
*nvecs += 1;
*nbytes += xfs_efi_item_sizeof(EFI_ITEM(lip));
}
STATIC void
xfs_efi_item_format(
struct xfs_log_item *lip,
struct xfs_log_vec *lv)
{
struct xfs_efi_log_item *efip = EFI_ITEM(lip);
struct xfs_log_iovec *vecp = NULL;
ASSERT(atomic_read(&efip->efi_next_extent) ==
efip->efi_format.efi_nextents);
efip->efi_format.efi_type = XFS_LI_EFI;
efip->efi_format.efi_size = 1;
xlog_copy_iovec(lv, &vecp, XLOG_REG_TYPE_EFI_FORMAT,
&efip->efi_format,
xfs_efi_item_sizeof(efip));
}
STATIC void
xfs_efi_item_pin(
struct xfs_log_item *lip)
{
}
STATIC void
xfs_efi_item_unpin(
struct xfs_log_item *lip,
int remove)
{
struct xfs_efi_log_item *efip = EFI_ITEM(lip);
xfs_efi_release(efip);
}
STATIC uint
xfs_efi_item_push(
struct xfs_log_item *lip,
struct list_head *buffer_list)
{
return XFS_ITEM_PINNED;
}
STATIC void
xfs_efi_item_unlock(
struct xfs_log_item *lip)
{
if (lip->li_flags & XFS_LI_ABORTED)
xfs_efi_item_free(EFI_ITEM(lip));
}
STATIC xfs_lsn_t
xfs_efi_item_committed(
struct xfs_log_item *lip,
xfs_lsn_t lsn)
{
return lsn;
}
STATIC void
xfs_efi_item_committing(
struct xfs_log_item *lip,
xfs_lsn_t lsn)
{
}
struct xfs_efi_log_item *
xfs_efi_init(
struct xfs_mount *mp,
uint nextents)
{
struct xfs_efi_log_item *efip;
uint size;
ASSERT(nextents > 0);
if (nextents > XFS_EFI_MAX_FAST_EXTENTS) {
size = (uint)(sizeof(xfs_efi_log_item_t) +
((nextents - 1) * sizeof(xfs_extent_t)));
efip = kmem_zalloc(size, KM_SLEEP);
} else {
efip = kmem_zone_zalloc(xfs_efi_zone, KM_SLEEP);
}
xfs_log_item_init(mp, &efip->efi_item, XFS_LI_EFI, &xfs_efi_item_ops);
efip->efi_format.efi_nextents = nextents;
efip->efi_format.efi_id = (uintptr_t)(void *)efip;
atomic_set(&efip->efi_next_extent, 0);
atomic_set(&efip->efi_refcount, 2);
return efip;
}
int
xfs_efi_copy_format(xfs_log_iovec_t *buf, xfs_efi_log_format_t *dst_efi_fmt)
{
xfs_efi_log_format_t *src_efi_fmt = buf->i_addr;
uint i;
uint len = sizeof(xfs_efi_log_format_t) +
(src_efi_fmt->efi_nextents - 1) * sizeof(xfs_extent_t);
uint len32 = sizeof(xfs_efi_log_format_32_t) +
(src_efi_fmt->efi_nextents - 1) * sizeof(xfs_extent_32_t);
uint len64 = sizeof(xfs_efi_log_format_64_t) +
(src_efi_fmt->efi_nextents - 1) * sizeof(xfs_extent_64_t);
if (buf->i_len == len) {
memcpy((char *)dst_efi_fmt, (char*)src_efi_fmt, len);
return 0;
} else if (buf->i_len == len32) {
xfs_efi_log_format_32_t *src_efi_fmt_32 = buf->i_addr;
dst_efi_fmt->efi_type = src_efi_fmt_32->efi_type;
dst_efi_fmt->efi_size = src_efi_fmt_32->efi_size;
dst_efi_fmt->efi_nextents = src_efi_fmt_32->efi_nextents;
dst_efi_fmt->efi_id = src_efi_fmt_32->efi_id;
for (i = 0; i < dst_efi_fmt->efi_nextents; i++) {
dst_efi_fmt->efi_extents[i].ext_start =
src_efi_fmt_32->efi_extents[i].ext_start;
dst_efi_fmt->efi_extents[i].ext_len =
src_efi_fmt_32->efi_extents[i].ext_len;
}
return 0;
} else if (buf->i_len == len64) {
xfs_efi_log_format_64_t *src_efi_fmt_64 = buf->i_addr;
dst_efi_fmt->efi_type = src_efi_fmt_64->efi_type;
dst_efi_fmt->efi_size = src_efi_fmt_64->efi_size;
dst_efi_fmt->efi_nextents = src_efi_fmt_64->efi_nextents;
dst_efi_fmt->efi_id = src_efi_fmt_64->efi_id;
for (i = 0; i < dst_efi_fmt->efi_nextents; i++) {
dst_efi_fmt->efi_extents[i].ext_start =
src_efi_fmt_64->efi_extents[i].ext_start;
dst_efi_fmt->efi_extents[i].ext_len =
src_efi_fmt_64->efi_extents[i].ext_len;
}
return 0;
}
return -EFSCORRUPTED;
}
void
xfs_efi_release(
struct xfs_efi_log_item *efip)
{
if (atomic_dec_and_test(&efip->efi_refcount)) {
xfs_trans_ail_remove(&efip->efi_item, SHUTDOWN_LOG_IO_ERROR);
xfs_efi_item_free(efip);
}
}
static inline struct xfs_efd_log_item *EFD_ITEM(struct xfs_log_item *lip)
{
return container_of(lip, struct xfs_efd_log_item, efd_item);
}
STATIC void
xfs_efd_item_free(struct xfs_efd_log_item *efdp)
{
kmem_free(efdp->efd_item.li_lv_shadow);
if (efdp->efd_format.efd_nextents > XFS_EFD_MAX_FAST_EXTENTS)
kmem_free(efdp);
else
kmem_zone_free(xfs_efd_zone, efdp);
}
static inline int
xfs_efd_item_sizeof(
struct xfs_efd_log_item *efdp)
{
return sizeof(xfs_efd_log_format_t) +
(efdp->efd_format.efd_nextents - 1) * sizeof(xfs_extent_t);
}
STATIC void
xfs_efd_item_size(
struct xfs_log_item *lip,
int *nvecs,
int *nbytes)
{
*nvecs += 1;
*nbytes += xfs_efd_item_sizeof(EFD_ITEM(lip));
}
STATIC void
xfs_efd_item_format(
struct xfs_log_item *lip,
struct xfs_log_vec *lv)
{
struct xfs_efd_log_item *efdp = EFD_ITEM(lip);
struct xfs_log_iovec *vecp = NULL;
ASSERT(efdp->efd_next_extent == efdp->efd_format.efd_nextents);
efdp->efd_format.efd_type = XFS_LI_EFD;
efdp->efd_format.efd_size = 1;
xlog_copy_iovec(lv, &vecp, XLOG_REG_TYPE_EFD_FORMAT,
&efdp->efd_format,
xfs_efd_item_sizeof(efdp));
}
STATIC void
xfs_efd_item_pin(
struct xfs_log_item *lip)
{
}
STATIC void
xfs_efd_item_unpin(
struct xfs_log_item *lip,
int remove)
{
}
STATIC uint
xfs_efd_item_push(
struct xfs_log_item *lip,
struct list_head *buffer_list)
{
return XFS_ITEM_PINNED;
}
STATIC void
xfs_efd_item_unlock(
struct xfs_log_item *lip)
{
struct xfs_efd_log_item *efdp = EFD_ITEM(lip);
if (lip->li_flags & XFS_LI_ABORTED) {
xfs_efi_release(efdp->efd_efip);
xfs_efd_item_free(efdp);
}
}
STATIC xfs_lsn_t
xfs_efd_item_committed(
struct xfs_log_item *lip,
xfs_lsn_t lsn)
{
struct xfs_efd_log_item *efdp = EFD_ITEM(lip);
xfs_efi_release(efdp->efd_efip);
xfs_efd_item_free(efdp);
return (xfs_lsn_t)-1;
}
STATIC void
xfs_efd_item_committing(
struct xfs_log_item *lip,
xfs_lsn_t lsn)
{
}
struct xfs_efd_log_item *
xfs_efd_init(
struct xfs_mount *mp,
struct xfs_efi_log_item *efip,
uint nextents)
{
struct xfs_efd_log_item *efdp;
uint size;
ASSERT(nextents > 0);
if (nextents > XFS_EFD_MAX_FAST_EXTENTS) {
size = (uint)(sizeof(xfs_efd_log_item_t) +
((nextents - 1) * sizeof(xfs_extent_t)));
efdp = kmem_zalloc(size, KM_SLEEP);
} else {
efdp = kmem_zone_zalloc(xfs_efd_zone, KM_SLEEP);
}
xfs_log_item_init(mp, &efdp->efd_item, XFS_LI_EFD, &xfs_efd_item_ops);
efdp->efd_efip = efip;
efdp->efd_format.efd_nextents = nextents;
efdp->efd_format.efd_efi_id = efip->efi_format.efi_id;
return efdp;
}
int
xfs_efi_recover(
struct xfs_mount *mp,
struct xfs_efi_log_item *efip)
{
struct xfs_efd_log_item *efdp;
struct xfs_trans *tp;
int i;
int error = 0;
xfs_extent_t *extp;
xfs_fsblock_t startblock_fsb;
struct xfs_owner_info oinfo;
ASSERT(!test_bit(XFS_EFI_RECOVERED, &efip->efi_flags));
for (i = 0; i < efip->efi_format.efi_nextents; i++) {
extp = &efip->efi_format.efi_extents[i];
startblock_fsb = XFS_BB_TO_FSB(mp,
XFS_FSB_TO_DADDR(mp, extp->ext_start));
if (startblock_fsb == 0 ||
extp->ext_len == 0 ||
startblock_fsb >= mp->m_sb.sb_dblocks ||
extp->ext_len >= mp->m_sb.sb_agblocks) {
set_bit(XFS_EFI_RECOVERED, &efip->efi_flags);
xfs_efi_release(efip);
return -EIO;
}
}
error = xfs_trans_alloc(mp, &M_RES(mp)->tr_itruncate, 0, 0, 0, &tp);
if (error)
return error;
efdp = xfs_trans_get_efd(tp, efip, efip->efi_format.efi_nextents);
xfs_rmap_skip_owner_update(&oinfo);
for (i = 0; i < efip->efi_format.efi_nextents; i++) {
extp = &efip->efi_format.efi_extents[i];
error = xfs_trans_free_extent(tp, efdp, extp->ext_start,
extp->ext_len, &oinfo);
if (error)
goto abort_error;
}
set_bit(XFS_EFI_RECOVERED, &efip->efi_flags);
error = xfs_trans_commit(tp);
return error;
abort_error:
xfs_trans_cancel(tp);
return error;
}
