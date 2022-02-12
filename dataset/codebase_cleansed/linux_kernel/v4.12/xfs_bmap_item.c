static inline struct xfs_bui_log_item *BUI_ITEM(struct xfs_log_item *lip)
{
return container_of(lip, struct xfs_bui_log_item, bui_item);
}
void
xfs_bui_item_free(
struct xfs_bui_log_item *buip)
{
kmem_zone_free(xfs_bui_zone, buip);
}
STATIC void
xfs_bui_item_size(
struct xfs_log_item *lip,
int *nvecs,
int *nbytes)
{
struct xfs_bui_log_item *buip = BUI_ITEM(lip);
*nvecs += 1;
*nbytes += xfs_bui_log_format_sizeof(buip->bui_format.bui_nextents);
}
STATIC void
xfs_bui_item_format(
struct xfs_log_item *lip,
struct xfs_log_vec *lv)
{
struct xfs_bui_log_item *buip = BUI_ITEM(lip);
struct xfs_log_iovec *vecp = NULL;
ASSERT(atomic_read(&buip->bui_next_extent) ==
buip->bui_format.bui_nextents);
buip->bui_format.bui_type = XFS_LI_BUI;
buip->bui_format.bui_size = 1;
xlog_copy_iovec(lv, &vecp, XLOG_REG_TYPE_BUI_FORMAT, &buip->bui_format,
xfs_bui_log_format_sizeof(buip->bui_format.bui_nextents));
}
STATIC void
xfs_bui_item_pin(
struct xfs_log_item *lip)
{
}
STATIC void
xfs_bui_item_unpin(
struct xfs_log_item *lip,
int remove)
{
struct xfs_bui_log_item *buip = BUI_ITEM(lip);
xfs_bui_release(buip);
}
STATIC uint
xfs_bui_item_push(
struct xfs_log_item *lip,
struct list_head *buffer_list)
{
return XFS_ITEM_PINNED;
}
STATIC void
xfs_bui_item_unlock(
struct xfs_log_item *lip)
{
if (lip->li_flags & XFS_LI_ABORTED)
xfs_bui_item_free(BUI_ITEM(lip));
}
STATIC xfs_lsn_t
xfs_bui_item_committed(
struct xfs_log_item *lip,
xfs_lsn_t lsn)
{
return lsn;
}
STATIC void
xfs_bui_item_committing(
struct xfs_log_item *lip,
xfs_lsn_t lsn)
{
}
struct xfs_bui_log_item *
xfs_bui_init(
struct xfs_mount *mp)
{
struct xfs_bui_log_item *buip;
buip = kmem_zone_zalloc(xfs_bui_zone, KM_SLEEP);
xfs_log_item_init(mp, &buip->bui_item, XFS_LI_BUI, &xfs_bui_item_ops);
buip->bui_format.bui_nextents = XFS_BUI_MAX_FAST_EXTENTS;
buip->bui_format.bui_id = (uintptr_t)(void *)buip;
atomic_set(&buip->bui_next_extent, 0);
atomic_set(&buip->bui_refcount, 2);
return buip;
}
void
xfs_bui_release(
struct xfs_bui_log_item *buip)
{
ASSERT(atomic_read(&buip->bui_refcount) > 0);
if (atomic_dec_and_test(&buip->bui_refcount)) {
xfs_trans_ail_remove(&buip->bui_item, SHUTDOWN_LOG_IO_ERROR);
xfs_bui_item_free(buip);
}
}
static inline struct xfs_bud_log_item *BUD_ITEM(struct xfs_log_item *lip)
{
return container_of(lip, struct xfs_bud_log_item, bud_item);
}
STATIC void
xfs_bud_item_size(
struct xfs_log_item *lip,
int *nvecs,
int *nbytes)
{
*nvecs += 1;
*nbytes += sizeof(struct xfs_bud_log_format);
}
STATIC void
xfs_bud_item_format(
struct xfs_log_item *lip,
struct xfs_log_vec *lv)
{
struct xfs_bud_log_item *budp = BUD_ITEM(lip);
struct xfs_log_iovec *vecp = NULL;
budp->bud_format.bud_type = XFS_LI_BUD;
budp->bud_format.bud_size = 1;
xlog_copy_iovec(lv, &vecp, XLOG_REG_TYPE_BUD_FORMAT, &budp->bud_format,
sizeof(struct xfs_bud_log_format));
}
STATIC void
xfs_bud_item_pin(
struct xfs_log_item *lip)
{
}
STATIC void
xfs_bud_item_unpin(
struct xfs_log_item *lip,
int remove)
{
}
STATIC uint
xfs_bud_item_push(
struct xfs_log_item *lip,
struct list_head *buffer_list)
{
return XFS_ITEM_PINNED;
}
STATIC void
xfs_bud_item_unlock(
struct xfs_log_item *lip)
{
struct xfs_bud_log_item *budp = BUD_ITEM(lip);
if (lip->li_flags & XFS_LI_ABORTED) {
xfs_bui_release(budp->bud_buip);
kmem_zone_free(xfs_bud_zone, budp);
}
}
STATIC xfs_lsn_t
xfs_bud_item_committed(
struct xfs_log_item *lip,
xfs_lsn_t lsn)
{
struct xfs_bud_log_item *budp = BUD_ITEM(lip);
xfs_bui_release(budp->bud_buip);
kmem_zone_free(xfs_bud_zone, budp);
return (xfs_lsn_t)-1;
}
STATIC void
xfs_bud_item_committing(
struct xfs_log_item *lip,
xfs_lsn_t lsn)
{
}
struct xfs_bud_log_item *
xfs_bud_init(
struct xfs_mount *mp,
struct xfs_bui_log_item *buip)
{
struct xfs_bud_log_item *budp;
budp = kmem_zone_zalloc(xfs_bud_zone, KM_SLEEP);
xfs_log_item_init(mp, &budp->bud_item, XFS_LI_BUD, &xfs_bud_item_ops);
budp->bud_buip = buip;
budp->bud_format.bud_bui_id = buip->bui_format.bui_id;
return budp;
}
int
xfs_bui_recover(
struct xfs_mount *mp,
struct xfs_bui_log_item *buip)
{
int error = 0;
unsigned int bui_type;
struct xfs_map_extent *bmap;
xfs_fsblock_t startblock_fsb;
xfs_fsblock_t inode_fsb;
bool op_ok;
struct xfs_bud_log_item *budp;
enum xfs_bmap_intent_type type;
int whichfork;
xfs_exntst_t state;
struct xfs_trans *tp;
struct xfs_inode *ip = NULL;
struct xfs_defer_ops dfops;
xfs_fsblock_t firstfsb;
ASSERT(!test_bit(XFS_BUI_RECOVERED, &buip->bui_flags));
if (buip->bui_format.bui_nextents != XFS_BUI_MAX_FAST_EXTENTS) {
set_bit(XFS_BUI_RECOVERED, &buip->bui_flags);
xfs_bui_release(buip);
return -EIO;
}
bmap = &buip->bui_format.bui_extents[0];
startblock_fsb = XFS_BB_TO_FSB(mp,
XFS_FSB_TO_DADDR(mp, bmap->me_startblock));
inode_fsb = XFS_BB_TO_FSB(mp, XFS_FSB_TO_DADDR(mp,
XFS_INO_TO_FSB(mp, bmap->me_owner)));
switch (bmap->me_flags & XFS_BMAP_EXTENT_TYPE_MASK) {
case XFS_BMAP_MAP:
case XFS_BMAP_UNMAP:
op_ok = true;
break;
default:
op_ok = false;
break;
}
if (!op_ok || startblock_fsb == 0 ||
bmap->me_len == 0 ||
inode_fsb == 0 ||
startblock_fsb >= mp->m_sb.sb_dblocks ||
bmap->me_len >= mp->m_sb.sb_agblocks ||
inode_fsb >= mp->m_sb.sb_dblocks ||
(bmap->me_flags & ~XFS_BMAP_EXTENT_FLAGS)) {
set_bit(XFS_BUI_RECOVERED, &buip->bui_flags);
xfs_bui_release(buip);
return -EIO;
}
error = xfs_trans_alloc(mp, &M_RES(mp)->tr_itruncate,
XFS_EXTENTADD_SPACE_RES(mp, XFS_DATA_FORK), 0, 0, &tp);
if (error)
return error;
budp = xfs_trans_get_bud(tp, buip);
error = xfs_iget(mp, tp, bmap->me_owner, 0, XFS_ILOCK_EXCL, &ip);
if (error)
goto err_inode;
if (VFS_I(ip)->i_nlink == 0)
xfs_iflags_set(ip, XFS_IRECOVERY);
xfs_defer_init(&dfops, &firstfsb);
state = (bmap->me_flags & XFS_BMAP_EXTENT_UNWRITTEN) ?
XFS_EXT_UNWRITTEN : XFS_EXT_NORM;
whichfork = (bmap->me_flags & XFS_BMAP_EXTENT_ATTR_FORK) ?
XFS_ATTR_FORK : XFS_DATA_FORK;
bui_type = bmap->me_flags & XFS_BMAP_EXTENT_TYPE_MASK;
switch (bui_type) {
case XFS_BMAP_MAP:
case XFS_BMAP_UNMAP:
type = bui_type;
break;
default:
error = -EFSCORRUPTED;
goto err_dfops;
}
xfs_trans_ijoin(tp, ip, 0);
error = xfs_trans_log_finish_bmap_update(tp, budp, &dfops, type,
ip, whichfork, bmap->me_startoff,
bmap->me_startblock, bmap->me_len,
state);
if (error)
goto err_dfops;
error = xfs_defer_finish(&tp, &dfops, NULL);
if (error)
goto err_dfops;
set_bit(XFS_BUI_RECOVERED, &buip->bui_flags);
error = xfs_trans_commit(tp);
xfs_iunlock(ip, XFS_ILOCK_EXCL);
IRELE(ip);
return error;
err_dfops:
xfs_defer_cancel(&dfops);
err_inode:
xfs_trans_cancel(tp);
if (ip) {
xfs_iunlock(ip, XFS_ILOCK_EXCL);
IRELE(ip);
}
return error;
}
