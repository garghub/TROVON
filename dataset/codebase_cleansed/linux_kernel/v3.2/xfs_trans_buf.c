STATIC struct xfs_buf *
xfs_trans_buf_item_match(
struct xfs_trans *tp,
struct xfs_buftarg *target,
xfs_daddr_t blkno,
int len)
{
struct xfs_log_item_desc *lidp;
struct xfs_buf_log_item *blip;
len = BBTOB(len);
list_for_each_entry(lidp, &tp->t_items, lid_trans) {
blip = (struct xfs_buf_log_item *)lidp->lid_item;
if (blip->bli_item.li_type == XFS_LI_BUF &&
blip->bli_buf->b_target == target &&
XFS_BUF_ADDR(blip->bli_buf) == blkno &&
XFS_BUF_COUNT(blip->bli_buf) == len)
return blip->bli_buf;
}
return NULL;
}
STATIC void
_xfs_trans_bjoin(
struct xfs_trans *tp,
struct xfs_buf *bp,
int reset_recur)
{
struct xfs_buf_log_item *bip;
ASSERT(bp->b_transp == NULL);
xfs_buf_item_init(bp, tp->t_mountp);
bip = bp->b_fspriv;
ASSERT(!(bip->bli_flags & XFS_BLI_STALE));
ASSERT(!(bip->bli_format.blf_flags & XFS_BLF_CANCEL));
ASSERT(!(bip->bli_flags & XFS_BLI_LOGGED));
if (reset_recur)
bip->bli_recur = 0;
atomic_inc(&bip->bli_refcount);
xfs_trans_add_item(tp, &bip->bli_item);
bp->b_transp = tp;
}
void
xfs_trans_bjoin(
struct xfs_trans *tp,
struct xfs_buf *bp)
{
_xfs_trans_bjoin(tp, bp, 0);
trace_xfs_trans_bjoin(bp->b_fspriv);
}
xfs_buf_t *
xfs_trans_get_buf(xfs_trans_t *tp,
xfs_buftarg_t *target_dev,
xfs_daddr_t blkno,
int len,
uint flags)
{
xfs_buf_t *bp;
xfs_buf_log_item_t *bip;
if (flags == 0)
flags = XBF_LOCK | XBF_MAPPED;
if (tp == NULL)
return xfs_buf_get(target_dev, blkno, len,
flags | XBF_DONT_BLOCK);
bp = xfs_trans_buf_item_match(tp, target_dev, blkno, len);
if (bp != NULL) {
ASSERT(xfs_buf_islocked(bp));
if (XFS_FORCED_SHUTDOWN(tp->t_mountp)) {
xfs_buf_stale(bp);
XFS_BUF_DONE(bp);
}
else if (XFS_BUF_ISSTALE(bp))
ASSERT(!XFS_BUF_ISDELAYWRITE(bp));
ASSERT(bp->b_transp == tp);
bip = bp->b_fspriv;
ASSERT(bip != NULL);
ASSERT(atomic_read(&bip->bli_refcount) > 0);
bip->bli_recur++;
trace_xfs_trans_get_buf_recur(bip);
return (bp);
}
bp = xfs_buf_get(target_dev, blkno, len, flags | XBF_DONT_BLOCK);
if (bp == NULL) {
return NULL;
}
ASSERT(!bp->b_error);
_xfs_trans_bjoin(tp, bp, 1);
trace_xfs_trans_get_buf(bp->b_fspriv);
return (bp);
}
xfs_buf_t *
xfs_trans_getsb(xfs_trans_t *tp,
struct xfs_mount *mp,
int flags)
{
xfs_buf_t *bp;
xfs_buf_log_item_t *bip;
if (tp == NULL) {
return (xfs_getsb(mp, flags));
}
bp = mp->m_sb_bp;
if (bp->b_transp == tp) {
bip = bp->b_fspriv;
ASSERT(bip != NULL);
ASSERT(atomic_read(&bip->bli_refcount) > 0);
bip->bli_recur++;
trace_xfs_trans_getsb_recur(bip);
return (bp);
}
bp = xfs_getsb(mp, flags);
if (bp == NULL)
return NULL;
_xfs_trans_bjoin(tp, bp, 1);
trace_xfs_trans_getsb(bp->b_fspriv);
return (bp);
}
int
xfs_trans_read_buf(
xfs_mount_t *mp,
xfs_trans_t *tp,
xfs_buftarg_t *target,
xfs_daddr_t blkno,
int len,
uint flags,
xfs_buf_t **bpp)
{
xfs_buf_t *bp;
xfs_buf_log_item_t *bip;
int error;
if (flags == 0)
flags = XBF_LOCK | XBF_MAPPED;
if (tp == NULL) {
bp = xfs_buf_read(target, blkno, len, flags | XBF_DONT_BLOCK);
if (!bp)
return (flags & XBF_TRYLOCK) ?
EAGAIN : XFS_ERROR(ENOMEM);
if (bp->b_error) {
error = bp->b_error;
xfs_buf_ioerror_alert(bp, __func__);
xfs_buf_relse(bp);
return error;
}
#ifdef DEBUG
if (xfs_do_error) {
if (xfs_error_target == target) {
if (((xfs_req_num++) % xfs_error_mod) == 0) {
xfs_buf_relse(bp);
xfs_debug(mp, "Returning error!");
return XFS_ERROR(EIO);
}
}
}
#endif
if (XFS_FORCED_SHUTDOWN(mp))
goto shutdown_abort;
*bpp = bp;
return 0;
}
bp = xfs_trans_buf_item_match(tp, target, blkno, len);
if (bp != NULL) {
ASSERT(xfs_buf_islocked(bp));
ASSERT(bp->b_transp == tp);
ASSERT(bp->b_fspriv != NULL);
ASSERT(!bp->b_error);
if (!(XFS_BUF_ISDONE(bp))) {
trace_xfs_trans_read_buf_io(bp, _RET_IP_);
ASSERT(!XFS_BUF_ISASYNC(bp));
XFS_BUF_READ(bp);
xfsbdstrat(tp->t_mountp, bp);
error = xfs_buf_iowait(bp);
if (error) {
xfs_buf_ioerror_alert(bp, __func__);
xfs_buf_relse(bp);
if (tp->t_flags & XFS_TRANS_DIRTY)
xfs_force_shutdown(tp->t_mountp,
SHUTDOWN_META_IO_ERROR);
return error;
}
}
if (XFS_FORCED_SHUTDOWN(mp)) {
trace_xfs_trans_read_buf_shut(bp, _RET_IP_);
*bpp = NULL;
return XFS_ERROR(EIO);
}
bip = bp->b_fspriv;
bip->bli_recur++;
ASSERT(atomic_read(&bip->bli_refcount) > 0);
trace_xfs_trans_read_buf_recur(bip);
*bpp = bp;
return 0;
}
bp = xfs_buf_read(target, blkno, len, flags | XBF_DONT_BLOCK);
if (bp == NULL) {
*bpp = NULL;
return (flags & XBF_TRYLOCK) ?
0 : XFS_ERROR(ENOMEM);
}
if (bp->b_error) {
error = bp->b_error;
xfs_buf_stale(bp);
XFS_BUF_DONE(bp);
xfs_buf_ioerror_alert(bp, __func__);
if (tp->t_flags & XFS_TRANS_DIRTY)
xfs_force_shutdown(tp->t_mountp, SHUTDOWN_META_IO_ERROR);
xfs_buf_relse(bp);
return error;
}
#ifdef DEBUG
if (xfs_do_error && !(tp->t_flags & XFS_TRANS_DIRTY)) {
if (xfs_error_target == target) {
if (((xfs_req_num++) % xfs_error_mod) == 0) {
xfs_force_shutdown(tp->t_mountp,
SHUTDOWN_META_IO_ERROR);
xfs_buf_relse(bp);
xfs_debug(mp, "Returning trans error!");
return XFS_ERROR(EIO);
}
}
}
#endif
if (XFS_FORCED_SHUTDOWN(mp))
goto shutdown_abort;
_xfs_trans_bjoin(tp, bp, 1);
trace_xfs_trans_read_buf(bp->b_fspriv);
*bpp = bp;
return 0;
shutdown_abort:
#if defined(DEBUG)
if (XFS_BUF_ISSTALE(bp) && XFS_BUF_ISDELAYWRITE(bp))
xfs_notice(mp, "about to pop assert, bp == 0x%p", bp);
#endif
ASSERT((bp->b_flags & (XBF_STALE|XBF_DELWRI)) !=
(XBF_STALE|XBF_DELWRI));
trace_xfs_trans_read_buf_shut(bp, _RET_IP_);
xfs_buf_relse(bp);
*bpp = NULL;
return XFS_ERROR(EIO);
}
void
xfs_trans_brelse(xfs_trans_t *tp,
xfs_buf_t *bp)
{
xfs_buf_log_item_t *bip;
if (tp == NULL) {
struct xfs_log_item *lip = bp->b_fspriv;
ASSERT(bp->b_transp == NULL);
if (lip != NULL && lip->li_type == XFS_LI_BUF) {
bip = bp->b_fspriv;
xfs_trans_unlocked_item(bip->bli_item.li_ailp, lip);
}
xfs_buf_relse(bp);
return;
}
ASSERT(bp->b_transp == tp);
bip = bp->b_fspriv;
ASSERT(bip->bli_item.li_type == XFS_LI_BUF);
ASSERT(!(bip->bli_flags & XFS_BLI_STALE));
ASSERT(!(bip->bli_format.blf_flags & XFS_BLF_CANCEL));
ASSERT(atomic_read(&bip->bli_refcount) > 0);
trace_xfs_trans_brelse(bip);
if (bip->bli_recur > 0) {
bip->bli_recur--;
return;
}
if (bip->bli_item.li_desc->lid_flags & XFS_LID_DIRTY)
return;
if (bip->bli_flags & XFS_BLI_STALE)
return;
ASSERT(!(bip->bli_flags & XFS_BLI_LOGGED));
xfs_trans_del_item(&bip->bli_item);
if (bip->bli_flags & XFS_BLI_HOLD) {
bip->bli_flags &= ~XFS_BLI_HOLD;
}
atomic_dec(&bip->bli_refcount);
if (!xfs_buf_item_dirty(bip)) {
ASSERT(atomic_read(&bip->bli_refcount) == 0);
ASSERT(!(bip->bli_item.li_flags & XFS_LI_IN_AIL));
ASSERT(!(bip->bli_flags & XFS_BLI_INODE_ALLOC_BUF));
xfs_buf_item_relse(bp);
bip = NULL;
}
bp->b_transp = NULL;
if (bip != NULL) {
xfs_trans_unlocked_item(bip->bli_item.li_ailp,
(xfs_log_item_t*)bip);
}
xfs_buf_relse(bp);
return;
}
void
xfs_trans_bhold(xfs_trans_t *tp,
xfs_buf_t *bp)
{
xfs_buf_log_item_t *bip = bp->b_fspriv;
ASSERT(bp->b_transp == tp);
ASSERT(bip != NULL);
ASSERT(!(bip->bli_flags & XFS_BLI_STALE));
ASSERT(!(bip->bli_format.blf_flags & XFS_BLF_CANCEL));
ASSERT(atomic_read(&bip->bli_refcount) > 0);
bip->bli_flags |= XFS_BLI_HOLD;
trace_xfs_trans_bhold(bip);
}
void
xfs_trans_bhold_release(xfs_trans_t *tp,
xfs_buf_t *bp)
{
xfs_buf_log_item_t *bip = bp->b_fspriv;
ASSERT(bp->b_transp == tp);
ASSERT(bip != NULL);
ASSERT(!(bip->bli_flags & XFS_BLI_STALE));
ASSERT(!(bip->bli_format.blf_flags & XFS_BLF_CANCEL));
ASSERT(atomic_read(&bip->bli_refcount) > 0);
ASSERT(bip->bli_flags & XFS_BLI_HOLD);
bip->bli_flags &= ~XFS_BLI_HOLD;
trace_xfs_trans_bhold_release(bip);
}
void
xfs_trans_log_buf(xfs_trans_t *tp,
xfs_buf_t *bp,
uint first,
uint last)
{
xfs_buf_log_item_t *bip = bp->b_fspriv;
ASSERT(bp->b_transp == tp);
ASSERT(bip != NULL);
ASSERT((first <= last) && (last < XFS_BUF_COUNT(bp)));
ASSERT(bp->b_iodone == NULL ||
bp->b_iodone == xfs_buf_iodone_callbacks);
XFS_BUF_DONE(bp);
ASSERT(atomic_read(&bip->bli_refcount) > 0);
bp->b_iodone = xfs_buf_iodone_callbacks;
bip->bli_item.li_cb = xfs_buf_iodone;
xfs_buf_delwri_queue(bp);
trace_xfs_trans_log_buf(bip);
if (bip->bli_flags & XFS_BLI_STALE) {
bip->bli_flags &= ~XFS_BLI_STALE;
ASSERT(XFS_BUF_ISSTALE(bp));
XFS_BUF_UNSTALE(bp);
bip->bli_format.blf_flags &= ~XFS_BLF_CANCEL;
}
tp->t_flags |= XFS_TRANS_DIRTY;
bip->bli_item.li_desc->lid_flags |= XFS_LID_DIRTY;
bip->bli_flags |= XFS_BLI_LOGGED;
xfs_buf_item_log(bip, first, last);
}
void
xfs_trans_binval(
xfs_trans_t *tp,
xfs_buf_t *bp)
{
xfs_buf_log_item_t *bip = bp->b_fspriv;
ASSERT(bp->b_transp == tp);
ASSERT(bip != NULL);
ASSERT(atomic_read(&bip->bli_refcount) > 0);
trace_xfs_trans_binval(bip);
if (bip->bli_flags & XFS_BLI_STALE) {
ASSERT(!(XFS_BUF_ISDELAYWRITE(bp)));
ASSERT(XFS_BUF_ISSTALE(bp));
ASSERT(!(bip->bli_flags & (XFS_BLI_LOGGED | XFS_BLI_DIRTY)));
ASSERT(!(bip->bli_format.blf_flags & XFS_BLF_INODE_BUF));
ASSERT(bip->bli_format.blf_flags & XFS_BLF_CANCEL);
ASSERT(bip->bli_item.li_desc->lid_flags & XFS_LID_DIRTY);
ASSERT(tp->t_flags & XFS_TRANS_DIRTY);
return;
}
xfs_buf_stale(bp);
bip->bli_flags |= XFS_BLI_STALE;
bip->bli_flags &= ~(XFS_BLI_INODE_BUF | XFS_BLI_LOGGED | XFS_BLI_DIRTY);
bip->bli_format.blf_flags &= ~XFS_BLF_INODE_BUF;
bip->bli_format.blf_flags |= XFS_BLF_CANCEL;
memset((char *)(bip->bli_format.blf_data_map), 0,
(bip->bli_format.blf_map_size * sizeof(uint)));
bip->bli_item.li_desc->lid_flags |= XFS_LID_DIRTY;
tp->t_flags |= XFS_TRANS_DIRTY;
}
void
xfs_trans_inode_buf(
xfs_trans_t *tp,
xfs_buf_t *bp)
{
xfs_buf_log_item_t *bip = bp->b_fspriv;
ASSERT(bp->b_transp == tp);
ASSERT(bip != NULL);
ASSERT(atomic_read(&bip->bli_refcount) > 0);
bip->bli_flags |= XFS_BLI_INODE_BUF;
}
void
xfs_trans_stale_inode_buf(
xfs_trans_t *tp,
xfs_buf_t *bp)
{
xfs_buf_log_item_t *bip = bp->b_fspriv;
ASSERT(bp->b_transp == tp);
ASSERT(bip != NULL);
ASSERT(atomic_read(&bip->bli_refcount) > 0);
bip->bli_flags |= XFS_BLI_STALE_INODE;
bip->bli_item.li_cb = xfs_buf_iodone;
}
void
xfs_trans_inode_alloc_buf(
xfs_trans_t *tp,
xfs_buf_t *bp)
{
xfs_buf_log_item_t *bip = bp->b_fspriv;
ASSERT(bp->b_transp == tp);
ASSERT(bip != NULL);
ASSERT(atomic_read(&bip->bli_refcount) > 0);
bip->bli_flags |= XFS_BLI_INODE_ALLOC_BUF;
}
void
xfs_trans_dquot_buf(
xfs_trans_t *tp,
xfs_buf_t *bp,
uint type)
{
xfs_buf_log_item_t *bip = bp->b_fspriv;
ASSERT(bp->b_transp == tp);
ASSERT(bip != NULL);
ASSERT(type == XFS_BLF_UDQUOT_BUF ||
type == XFS_BLF_PDQUOT_BUF ||
type == XFS_BLF_GDQUOT_BUF);
ASSERT(atomic_read(&bip->bli_refcount) > 0);
bip->bli_format.blf_flags |= type;
}
