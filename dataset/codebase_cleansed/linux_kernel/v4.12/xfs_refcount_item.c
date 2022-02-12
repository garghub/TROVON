static inline struct xfs_cui_log_item *CUI_ITEM(struct xfs_log_item *lip)
{
return container_of(lip, struct xfs_cui_log_item, cui_item);
}
void
xfs_cui_item_free(
struct xfs_cui_log_item *cuip)
{
if (cuip->cui_format.cui_nextents > XFS_CUI_MAX_FAST_EXTENTS)
kmem_free(cuip);
else
kmem_zone_free(xfs_cui_zone, cuip);
}
STATIC void
xfs_cui_item_size(
struct xfs_log_item *lip,
int *nvecs,
int *nbytes)
{
struct xfs_cui_log_item *cuip = CUI_ITEM(lip);
*nvecs += 1;
*nbytes += xfs_cui_log_format_sizeof(cuip->cui_format.cui_nextents);
}
STATIC void
xfs_cui_item_format(
struct xfs_log_item *lip,
struct xfs_log_vec *lv)
{
struct xfs_cui_log_item *cuip = CUI_ITEM(lip);
struct xfs_log_iovec *vecp = NULL;
ASSERT(atomic_read(&cuip->cui_next_extent) ==
cuip->cui_format.cui_nextents);
cuip->cui_format.cui_type = XFS_LI_CUI;
cuip->cui_format.cui_size = 1;
xlog_copy_iovec(lv, &vecp, XLOG_REG_TYPE_CUI_FORMAT, &cuip->cui_format,
xfs_cui_log_format_sizeof(cuip->cui_format.cui_nextents));
}
STATIC void
xfs_cui_item_pin(
struct xfs_log_item *lip)
{
}
STATIC void
xfs_cui_item_unpin(
struct xfs_log_item *lip,
int remove)
{
struct xfs_cui_log_item *cuip = CUI_ITEM(lip);
xfs_cui_release(cuip);
}
STATIC uint
xfs_cui_item_push(
struct xfs_log_item *lip,
struct list_head *buffer_list)
{
return XFS_ITEM_PINNED;
}
STATIC void
xfs_cui_item_unlock(
struct xfs_log_item *lip)
{
if (lip->li_flags & XFS_LI_ABORTED)
xfs_cui_item_free(CUI_ITEM(lip));
}
STATIC xfs_lsn_t
xfs_cui_item_committed(
struct xfs_log_item *lip,
xfs_lsn_t lsn)
{
return lsn;
}
STATIC void
xfs_cui_item_committing(
struct xfs_log_item *lip,
xfs_lsn_t lsn)
{
}
struct xfs_cui_log_item *
xfs_cui_init(
struct xfs_mount *mp,
uint nextents)
{
struct xfs_cui_log_item *cuip;
ASSERT(nextents > 0);
if (nextents > XFS_CUI_MAX_FAST_EXTENTS)
cuip = kmem_zalloc(xfs_cui_log_item_sizeof(nextents),
KM_SLEEP);
else
cuip = kmem_zone_zalloc(xfs_cui_zone, KM_SLEEP);
xfs_log_item_init(mp, &cuip->cui_item, XFS_LI_CUI, &xfs_cui_item_ops);
cuip->cui_format.cui_nextents = nextents;
cuip->cui_format.cui_id = (uintptr_t)(void *)cuip;
atomic_set(&cuip->cui_next_extent, 0);
atomic_set(&cuip->cui_refcount, 2);
return cuip;
}
void
xfs_cui_release(
struct xfs_cui_log_item *cuip)
{
ASSERT(atomic_read(&cuip->cui_refcount) > 0);
if (atomic_dec_and_test(&cuip->cui_refcount)) {
xfs_trans_ail_remove(&cuip->cui_item, SHUTDOWN_LOG_IO_ERROR);
xfs_cui_item_free(cuip);
}
}
static inline struct xfs_cud_log_item *CUD_ITEM(struct xfs_log_item *lip)
{
return container_of(lip, struct xfs_cud_log_item, cud_item);
}
STATIC void
xfs_cud_item_size(
struct xfs_log_item *lip,
int *nvecs,
int *nbytes)
{
*nvecs += 1;
*nbytes += sizeof(struct xfs_cud_log_format);
}
STATIC void
xfs_cud_item_format(
struct xfs_log_item *lip,
struct xfs_log_vec *lv)
{
struct xfs_cud_log_item *cudp = CUD_ITEM(lip);
struct xfs_log_iovec *vecp = NULL;
cudp->cud_format.cud_type = XFS_LI_CUD;
cudp->cud_format.cud_size = 1;
xlog_copy_iovec(lv, &vecp, XLOG_REG_TYPE_CUD_FORMAT, &cudp->cud_format,
sizeof(struct xfs_cud_log_format));
}
STATIC void
xfs_cud_item_pin(
struct xfs_log_item *lip)
{
}
STATIC void
xfs_cud_item_unpin(
struct xfs_log_item *lip,
int remove)
{
}
STATIC uint
xfs_cud_item_push(
struct xfs_log_item *lip,
struct list_head *buffer_list)
{
return XFS_ITEM_PINNED;
}
STATIC void
xfs_cud_item_unlock(
struct xfs_log_item *lip)
{
struct xfs_cud_log_item *cudp = CUD_ITEM(lip);
if (lip->li_flags & XFS_LI_ABORTED) {
xfs_cui_release(cudp->cud_cuip);
kmem_zone_free(xfs_cud_zone, cudp);
}
}
STATIC xfs_lsn_t
xfs_cud_item_committed(
struct xfs_log_item *lip,
xfs_lsn_t lsn)
{
struct xfs_cud_log_item *cudp = CUD_ITEM(lip);
xfs_cui_release(cudp->cud_cuip);
kmem_zone_free(xfs_cud_zone, cudp);
return (xfs_lsn_t)-1;
}
STATIC void
xfs_cud_item_committing(
struct xfs_log_item *lip,
xfs_lsn_t lsn)
{
}
struct xfs_cud_log_item *
xfs_cud_init(
struct xfs_mount *mp,
struct xfs_cui_log_item *cuip)
{
struct xfs_cud_log_item *cudp;
cudp = kmem_zone_zalloc(xfs_cud_zone, KM_SLEEP);
xfs_log_item_init(mp, &cudp->cud_item, XFS_LI_CUD, &xfs_cud_item_ops);
cudp->cud_cuip = cuip;
cudp->cud_format.cud_cui_id = cuip->cui_format.cui_id;
return cudp;
}
int
xfs_cui_recover(
struct xfs_mount *mp,
struct xfs_cui_log_item *cuip)
{
int i;
int error = 0;
unsigned int refc_type;
struct xfs_phys_extent *refc;
xfs_fsblock_t startblock_fsb;
bool op_ok;
struct xfs_cud_log_item *cudp;
struct xfs_trans *tp;
struct xfs_btree_cur *rcur = NULL;
enum xfs_refcount_intent_type type;
xfs_fsblock_t firstfsb;
xfs_fsblock_t new_fsb;
xfs_extlen_t new_len;
struct xfs_bmbt_irec irec;
struct xfs_defer_ops dfops;
bool requeue_only = false;
ASSERT(!test_bit(XFS_CUI_RECOVERED, &cuip->cui_flags));
for (i = 0; i < cuip->cui_format.cui_nextents; i++) {
refc = &cuip->cui_format.cui_extents[i];
startblock_fsb = XFS_BB_TO_FSB(mp,
XFS_FSB_TO_DADDR(mp, refc->pe_startblock));
switch (refc->pe_flags & XFS_REFCOUNT_EXTENT_TYPE_MASK) {
case XFS_REFCOUNT_INCREASE:
case XFS_REFCOUNT_DECREASE:
case XFS_REFCOUNT_ALLOC_COW:
case XFS_REFCOUNT_FREE_COW:
op_ok = true;
break;
default:
op_ok = false;
break;
}
if (!op_ok || startblock_fsb == 0 ||
refc->pe_len == 0 ||
startblock_fsb >= mp->m_sb.sb_dblocks ||
refc->pe_len >= mp->m_sb.sb_agblocks ||
(refc->pe_flags & ~XFS_REFCOUNT_EXTENT_FLAGS)) {
set_bit(XFS_CUI_RECOVERED, &cuip->cui_flags);
xfs_cui_release(cuip);
return -EIO;
}
}
error = xfs_trans_alloc(mp, &M_RES(mp)->tr_itruncate, 0, 0, 0, &tp);
if (error)
return error;
cudp = xfs_trans_get_cud(tp, cuip);
xfs_defer_init(&dfops, &firstfsb);
for (i = 0; i < cuip->cui_format.cui_nextents; i++) {
refc = &cuip->cui_format.cui_extents[i];
refc_type = refc->pe_flags & XFS_REFCOUNT_EXTENT_TYPE_MASK;
switch (refc_type) {
case XFS_REFCOUNT_INCREASE:
case XFS_REFCOUNT_DECREASE:
case XFS_REFCOUNT_ALLOC_COW:
case XFS_REFCOUNT_FREE_COW:
type = refc_type;
break;
default:
error = -EFSCORRUPTED;
goto abort_error;
}
if (requeue_only) {
new_fsb = refc->pe_startblock;
new_len = refc->pe_len;
} else
error = xfs_trans_log_finish_refcount_update(tp, cudp,
&dfops, type, refc->pe_startblock, refc->pe_len,
&new_fsb, &new_len, &rcur);
if (error)
goto abort_error;
if (new_len > 0) {
irec.br_startblock = new_fsb;
irec.br_blockcount = new_len;
switch (type) {
case XFS_REFCOUNT_INCREASE:
error = xfs_refcount_increase_extent(
tp->t_mountp, &dfops, &irec);
break;
case XFS_REFCOUNT_DECREASE:
error = xfs_refcount_decrease_extent(
tp->t_mountp, &dfops, &irec);
break;
case XFS_REFCOUNT_ALLOC_COW:
error = xfs_refcount_alloc_cow_extent(
tp->t_mountp, &dfops,
irec.br_startblock,
irec.br_blockcount);
break;
case XFS_REFCOUNT_FREE_COW:
error = xfs_refcount_free_cow_extent(
tp->t_mountp, &dfops,
irec.br_startblock,
irec.br_blockcount);
break;
default:
ASSERT(0);
}
if (error)
goto abort_error;
requeue_only = true;
}
}
xfs_refcount_finish_one_cleanup(tp, rcur, error);
error = xfs_defer_finish(&tp, &dfops, NULL);
if (error)
goto abort_defer;
set_bit(XFS_CUI_RECOVERED, &cuip->cui_flags);
error = xfs_trans_commit(tp);
return error;
abort_error:
xfs_refcount_finish_one_cleanup(tp, rcur, error);
abort_defer:
xfs_defer_cancel(&dfops);
xfs_trans_cancel(tp);
return error;
}
