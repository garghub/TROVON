static inline struct xfs_rui_log_item *RUI_ITEM(struct xfs_log_item *lip)
{
return container_of(lip, struct xfs_rui_log_item, rui_item);
}
void
xfs_rui_item_free(
struct xfs_rui_log_item *ruip)
{
if (ruip->rui_format.rui_nextents > XFS_RUI_MAX_FAST_EXTENTS)
kmem_free(ruip);
else
kmem_zone_free(xfs_rui_zone, ruip);
}
STATIC void
xfs_rui_item_size(
struct xfs_log_item *lip,
int *nvecs,
int *nbytes)
{
struct xfs_rui_log_item *ruip = RUI_ITEM(lip);
*nvecs += 1;
*nbytes += xfs_rui_log_format_sizeof(ruip->rui_format.rui_nextents);
}
STATIC void
xfs_rui_item_format(
struct xfs_log_item *lip,
struct xfs_log_vec *lv)
{
struct xfs_rui_log_item *ruip = RUI_ITEM(lip);
struct xfs_log_iovec *vecp = NULL;
ASSERT(atomic_read(&ruip->rui_next_extent) ==
ruip->rui_format.rui_nextents);
ruip->rui_format.rui_type = XFS_LI_RUI;
ruip->rui_format.rui_size = 1;
xlog_copy_iovec(lv, &vecp, XLOG_REG_TYPE_RUI_FORMAT, &ruip->rui_format,
xfs_rui_log_format_sizeof(ruip->rui_format.rui_nextents));
}
STATIC void
xfs_rui_item_pin(
struct xfs_log_item *lip)
{
}
STATIC void
xfs_rui_item_unpin(
struct xfs_log_item *lip,
int remove)
{
struct xfs_rui_log_item *ruip = RUI_ITEM(lip);
xfs_rui_release(ruip);
}
STATIC uint
xfs_rui_item_push(
struct xfs_log_item *lip,
struct list_head *buffer_list)
{
return XFS_ITEM_PINNED;
}
STATIC void
xfs_rui_item_unlock(
struct xfs_log_item *lip)
{
if (lip->li_flags & XFS_LI_ABORTED)
xfs_rui_item_free(RUI_ITEM(lip));
}
STATIC xfs_lsn_t
xfs_rui_item_committed(
struct xfs_log_item *lip,
xfs_lsn_t lsn)
{
return lsn;
}
STATIC void
xfs_rui_item_committing(
struct xfs_log_item *lip,
xfs_lsn_t lsn)
{
}
struct xfs_rui_log_item *
xfs_rui_init(
struct xfs_mount *mp,
uint nextents)
{
struct xfs_rui_log_item *ruip;
ASSERT(nextents > 0);
if (nextents > XFS_RUI_MAX_FAST_EXTENTS)
ruip = kmem_zalloc(xfs_rui_log_item_sizeof(nextents), KM_SLEEP);
else
ruip = kmem_zone_zalloc(xfs_rui_zone, KM_SLEEP);
xfs_log_item_init(mp, &ruip->rui_item, XFS_LI_RUI, &xfs_rui_item_ops);
ruip->rui_format.rui_nextents = nextents;
ruip->rui_format.rui_id = (uintptr_t)(void *)ruip;
atomic_set(&ruip->rui_next_extent, 0);
atomic_set(&ruip->rui_refcount, 2);
return ruip;
}
int
xfs_rui_copy_format(
struct xfs_log_iovec *buf,
struct xfs_rui_log_format *dst_rui_fmt)
{
struct xfs_rui_log_format *src_rui_fmt;
uint len;
src_rui_fmt = buf->i_addr;
len = xfs_rui_log_format_sizeof(src_rui_fmt->rui_nextents);
if (buf->i_len != len)
return -EFSCORRUPTED;
memcpy(dst_rui_fmt, src_rui_fmt, len);
return 0;
}
void
xfs_rui_release(
struct xfs_rui_log_item *ruip)
{
ASSERT(atomic_read(&ruip->rui_refcount) > 0);
if (atomic_dec_and_test(&ruip->rui_refcount)) {
xfs_trans_ail_remove(&ruip->rui_item, SHUTDOWN_LOG_IO_ERROR);
xfs_rui_item_free(ruip);
}
}
static inline struct xfs_rud_log_item *RUD_ITEM(struct xfs_log_item *lip)
{
return container_of(lip, struct xfs_rud_log_item, rud_item);
}
STATIC void
xfs_rud_item_size(
struct xfs_log_item *lip,
int *nvecs,
int *nbytes)
{
*nvecs += 1;
*nbytes += sizeof(struct xfs_rud_log_format);
}
STATIC void
xfs_rud_item_format(
struct xfs_log_item *lip,
struct xfs_log_vec *lv)
{
struct xfs_rud_log_item *rudp = RUD_ITEM(lip);
struct xfs_log_iovec *vecp = NULL;
rudp->rud_format.rud_type = XFS_LI_RUD;
rudp->rud_format.rud_size = 1;
xlog_copy_iovec(lv, &vecp, XLOG_REG_TYPE_RUD_FORMAT, &rudp->rud_format,
sizeof(struct xfs_rud_log_format));
}
STATIC void
xfs_rud_item_pin(
struct xfs_log_item *lip)
{
}
STATIC void
xfs_rud_item_unpin(
struct xfs_log_item *lip,
int remove)
{
}
STATIC uint
xfs_rud_item_push(
struct xfs_log_item *lip,
struct list_head *buffer_list)
{
return XFS_ITEM_PINNED;
}
STATIC void
xfs_rud_item_unlock(
struct xfs_log_item *lip)
{
struct xfs_rud_log_item *rudp = RUD_ITEM(lip);
if (lip->li_flags & XFS_LI_ABORTED) {
xfs_rui_release(rudp->rud_ruip);
kmem_zone_free(xfs_rud_zone, rudp);
}
}
STATIC xfs_lsn_t
xfs_rud_item_committed(
struct xfs_log_item *lip,
xfs_lsn_t lsn)
{
struct xfs_rud_log_item *rudp = RUD_ITEM(lip);
xfs_rui_release(rudp->rud_ruip);
kmem_zone_free(xfs_rud_zone, rudp);
return (xfs_lsn_t)-1;
}
STATIC void
xfs_rud_item_committing(
struct xfs_log_item *lip,
xfs_lsn_t lsn)
{
}
struct xfs_rud_log_item *
xfs_rud_init(
struct xfs_mount *mp,
struct xfs_rui_log_item *ruip)
{
struct xfs_rud_log_item *rudp;
rudp = kmem_zone_zalloc(xfs_rud_zone, KM_SLEEP);
xfs_log_item_init(mp, &rudp->rud_item, XFS_LI_RUD, &xfs_rud_item_ops);
rudp->rud_ruip = ruip;
rudp->rud_format.rud_rui_id = ruip->rui_format.rui_id;
return rudp;
}
int
xfs_rui_recover(
struct xfs_mount *mp,
struct xfs_rui_log_item *ruip)
{
int i;
int error = 0;
struct xfs_map_extent *rmap;
xfs_fsblock_t startblock_fsb;
bool op_ok;
struct xfs_rud_log_item *rudp;
enum xfs_rmap_intent_type type;
int whichfork;
xfs_exntst_t state;
struct xfs_trans *tp;
struct xfs_btree_cur *rcur = NULL;
ASSERT(!test_bit(XFS_RUI_RECOVERED, &ruip->rui_flags));
for (i = 0; i < ruip->rui_format.rui_nextents; i++) {
rmap = &ruip->rui_format.rui_extents[i];
startblock_fsb = XFS_BB_TO_FSB(mp,
XFS_FSB_TO_DADDR(mp, rmap->me_startblock));
switch (rmap->me_flags & XFS_RMAP_EXTENT_TYPE_MASK) {
case XFS_RMAP_EXTENT_MAP:
case XFS_RMAP_EXTENT_MAP_SHARED:
case XFS_RMAP_EXTENT_UNMAP:
case XFS_RMAP_EXTENT_UNMAP_SHARED:
case XFS_RMAP_EXTENT_CONVERT:
case XFS_RMAP_EXTENT_CONVERT_SHARED:
case XFS_RMAP_EXTENT_ALLOC:
case XFS_RMAP_EXTENT_FREE:
op_ok = true;
break;
default:
op_ok = false;
break;
}
if (!op_ok || startblock_fsb == 0 ||
rmap->me_len == 0 ||
startblock_fsb >= mp->m_sb.sb_dblocks ||
rmap->me_len >= mp->m_sb.sb_agblocks ||
(rmap->me_flags & ~XFS_RMAP_EXTENT_FLAGS)) {
set_bit(XFS_RUI_RECOVERED, &ruip->rui_flags);
xfs_rui_release(ruip);
return -EIO;
}
}
error = xfs_trans_alloc(mp, &M_RES(mp)->tr_itruncate, 0, 0, 0, &tp);
if (error)
return error;
rudp = xfs_trans_get_rud(tp, ruip);
for (i = 0; i < ruip->rui_format.rui_nextents; i++) {
rmap = &ruip->rui_format.rui_extents[i];
state = (rmap->me_flags & XFS_RMAP_EXTENT_UNWRITTEN) ?
XFS_EXT_UNWRITTEN : XFS_EXT_NORM;
whichfork = (rmap->me_flags & XFS_RMAP_EXTENT_ATTR_FORK) ?
XFS_ATTR_FORK : XFS_DATA_FORK;
switch (rmap->me_flags & XFS_RMAP_EXTENT_TYPE_MASK) {
case XFS_RMAP_EXTENT_MAP:
type = XFS_RMAP_MAP;
break;
case XFS_RMAP_EXTENT_MAP_SHARED:
type = XFS_RMAP_MAP_SHARED;
break;
case XFS_RMAP_EXTENT_UNMAP:
type = XFS_RMAP_UNMAP;
break;
case XFS_RMAP_EXTENT_UNMAP_SHARED:
type = XFS_RMAP_UNMAP_SHARED;
break;
case XFS_RMAP_EXTENT_CONVERT:
type = XFS_RMAP_CONVERT;
break;
case XFS_RMAP_EXTENT_CONVERT_SHARED:
type = XFS_RMAP_CONVERT_SHARED;
break;
case XFS_RMAP_EXTENT_ALLOC:
type = XFS_RMAP_ALLOC;
break;
case XFS_RMAP_EXTENT_FREE:
type = XFS_RMAP_FREE;
break;
default:
error = -EFSCORRUPTED;
goto abort_error;
}
error = xfs_trans_log_finish_rmap_update(tp, rudp, type,
rmap->me_owner, whichfork,
rmap->me_startoff, rmap->me_startblock,
rmap->me_len, state, &rcur);
if (error)
goto abort_error;
}
xfs_rmap_finish_one_cleanup(tp, rcur, error);
set_bit(XFS_RUI_RECOVERED, &ruip->rui_flags);
error = xfs_trans_commit(tp);
return error;
abort_error:
xfs_rmap_finish_one_cleanup(tp, rcur, error);
xfs_trans_cancel(tp);
return error;
}
