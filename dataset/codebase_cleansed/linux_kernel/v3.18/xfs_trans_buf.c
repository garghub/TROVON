STATIC struct xfs_buf *
xfs_trans_buf_item_match(
struct xfs_trans *tp,
struct xfs_buftarg *target,
struct xfs_buf_map *map,
int nmaps)
{
struct xfs_log_item_desc *lidp;
struct xfs_buf_log_item *blip;
int len = 0;
int i;
for (i = 0; i < nmaps; i++)
len += map[i].bm_len;
list_for_each_entry(lidp, &tp->t_items, lid_trans) {
blip = (struct xfs_buf_log_item *)lidp->lid_item;
if (blip->bli_item.li_type == XFS_LI_BUF &&
blip->bli_buf->b_target == target &&
XFS_BUF_ADDR(blip->bli_buf) == map[0].bm_bn &&
blip->bli_buf->b_length == len) {
ASSERT(blip->bli_buf->b_map_count == nmaps);
return blip->bli_buf;
}
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
ASSERT(!(bip->__bli_format.blf_flags & XFS_BLF_CANCEL));
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
struct xfs_buf *
xfs_trans_get_buf_map(
struct xfs_trans *tp,
struct xfs_buftarg *target,
struct xfs_buf_map *map,
int nmaps,
xfs_buf_flags_t flags)
{
xfs_buf_t *bp;
xfs_buf_log_item_t *bip;
if (!tp)
return xfs_buf_get_map(target, map, nmaps, flags);
bp = xfs_trans_buf_item_match(tp, target, map, nmaps);
if (bp != NULL) {
ASSERT(xfs_buf_islocked(bp));
if (XFS_FORCED_SHUTDOWN(tp->t_mountp)) {
xfs_buf_stale(bp);
XFS_BUF_DONE(bp);
}
ASSERT(bp->b_transp == tp);
bip = bp->b_fspriv;
ASSERT(bip != NULL);
ASSERT(atomic_read(&bip->bli_refcount) > 0);
bip->bli_recur++;
trace_xfs_trans_get_buf_recur(bip);
return bp;
}
bp = xfs_buf_get_map(target, map, nmaps, flags);
if (bp == NULL) {
return NULL;
}
ASSERT(!bp->b_error);
_xfs_trans_bjoin(tp, bp, 1);
trace_xfs_trans_get_buf(bp->b_fspriv);
return bp;
}
xfs_buf_t *
xfs_trans_getsb(xfs_trans_t *tp,
struct xfs_mount *mp,
int flags)
{
xfs_buf_t *bp;
xfs_buf_log_item_t *bip;
if (tp == NULL)
return xfs_getsb(mp, flags);
bp = mp->m_sb_bp;
if (bp->b_transp == tp) {
bip = bp->b_fspriv;
ASSERT(bip != NULL);
ASSERT(atomic_read(&bip->bli_refcount) > 0);
bip->bli_recur++;
trace_xfs_trans_getsb_recur(bip);
return bp;
}
bp = xfs_getsb(mp, flags);
if (bp == NULL)
return NULL;
_xfs_trans_bjoin(tp, bp, 1);
trace_xfs_trans_getsb(bp->b_fspriv);
return bp;
}
int
xfs_trans_read_buf_map(
struct xfs_mount *mp,
struct xfs_trans *tp,
struct xfs_buftarg *target,
struct xfs_buf_map *map,
int nmaps,
xfs_buf_flags_t flags,
struct xfs_buf **bpp,
const struct xfs_buf_ops *ops)
{
xfs_buf_t *bp;
xfs_buf_log_item_t *bip;
int error;
*bpp = NULL;
if (!tp) {
bp = xfs_buf_read_map(target, map, nmaps, flags, ops);
if (!bp)
return (flags & XBF_TRYLOCK) ?
-EAGAIN : -ENOMEM;
if (bp->b_error) {
error = bp->b_error;
xfs_buf_ioerror_alert(bp, __func__);
XFS_BUF_UNDONE(bp);
xfs_buf_stale(bp);
xfs_buf_relse(bp);
if (error == -EFSBADCRC)
error = -EFSCORRUPTED;
return error;
}
#ifdef DEBUG
if (xfs_do_error) {
if (xfs_error_target == target) {
if (((xfs_req_num++) % xfs_error_mod) == 0) {
xfs_buf_relse(bp);
xfs_debug(mp, "Returning error!");
return -EIO;
}
}
}
#endif
if (XFS_FORCED_SHUTDOWN(mp))
goto shutdown_abort;
*bpp = bp;
return 0;
}
bp = xfs_trans_buf_item_match(tp, target, map, nmaps);
if (bp != NULL) {
ASSERT(xfs_buf_islocked(bp));
ASSERT(bp->b_transp == tp);
ASSERT(bp->b_fspriv != NULL);
ASSERT(!bp->b_error);
if (!(XFS_BUF_ISDONE(bp))) {
trace_xfs_trans_read_buf_io(bp, _RET_IP_);
ASSERT(!XFS_BUF_ISASYNC(bp));
ASSERT(bp->b_iodone == NULL);
XFS_BUF_READ(bp);
bp->b_ops = ops;
error = xfs_buf_submit_wait(bp);
if (error) {
if (!XFS_FORCED_SHUTDOWN(mp))
xfs_buf_ioerror_alert(bp, __func__);
xfs_buf_relse(bp);
if (tp->t_flags & XFS_TRANS_DIRTY)
xfs_force_shutdown(tp->t_mountp,
SHUTDOWN_META_IO_ERROR);
if (error == -EFSBADCRC)
error = -EFSCORRUPTED;
return error;
}
}
if (XFS_FORCED_SHUTDOWN(mp)) {
trace_xfs_trans_read_buf_shut(bp, _RET_IP_);
*bpp = NULL;
return -EIO;
}
bip = bp->b_fspriv;
bip->bli_recur++;
ASSERT(atomic_read(&bip->bli_refcount) > 0);
trace_xfs_trans_read_buf_recur(bip);
*bpp = bp;
return 0;
}
bp = xfs_buf_read_map(target, map, nmaps, flags, ops);
if (bp == NULL) {
*bpp = NULL;
return (flags & XBF_TRYLOCK) ?
0 : -ENOMEM;
}
if (bp->b_error) {
error = bp->b_error;
xfs_buf_stale(bp);
XFS_BUF_DONE(bp);
xfs_buf_ioerror_alert(bp, __func__);
if (tp->t_flags & XFS_TRANS_DIRTY)
xfs_force_shutdown(tp->t_mountp, SHUTDOWN_META_IO_ERROR);
xfs_buf_relse(bp);
if (error == -EFSBADCRC)
error = -EFSCORRUPTED;
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
return -EIO;
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
trace_xfs_trans_read_buf_shut(bp, _RET_IP_);
xfs_buf_relse(bp);
*bpp = NULL;
return -EIO;
}
void
xfs_trans_brelse(xfs_trans_t *tp,
xfs_buf_t *bp)
{
xfs_buf_log_item_t *bip;
if (tp == NULL) {
ASSERT(bp->b_transp == NULL);
xfs_buf_relse(bp);
return;
}
ASSERT(bp->b_transp == tp);
bip = bp->b_fspriv;
ASSERT(bip->bli_item.li_type == XFS_LI_BUF);
ASSERT(!(bip->bli_flags & XFS_BLI_STALE));
ASSERT(!(bip->__bli_format.blf_flags & XFS_BLF_CANCEL));
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
}
bp->b_transp = NULL;
xfs_buf_relse(bp);
}
void
xfs_trans_bhold(xfs_trans_t *tp,
xfs_buf_t *bp)
{
xfs_buf_log_item_t *bip = bp->b_fspriv;
ASSERT(bp->b_transp == tp);
ASSERT(bip != NULL);
ASSERT(!(bip->bli_flags & XFS_BLI_STALE));
ASSERT(!(bip->__bli_format.blf_flags & XFS_BLF_CANCEL));
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
ASSERT(!(bip->__bli_format.blf_flags & XFS_BLF_CANCEL));
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
ASSERT(first <= last && last < BBTOB(bp->b_length));
ASSERT(bp->b_iodone == NULL ||
bp->b_iodone == xfs_buf_iodone_callbacks);
XFS_BUF_DONE(bp);
ASSERT(atomic_read(&bip->bli_refcount) > 0);
bp->b_iodone = xfs_buf_iodone_callbacks;
bip->bli_item.li_cb = xfs_buf_iodone;
trace_xfs_trans_log_buf(bip);
if (bip->bli_flags & XFS_BLI_STALE) {
bip->bli_flags &= ~XFS_BLI_STALE;
ASSERT(XFS_BUF_ISSTALE(bp));
XFS_BUF_UNSTALE(bp);
bip->__bli_format.blf_flags &= ~XFS_BLF_CANCEL;
}
tp->t_flags |= XFS_TRANS_DIRTY;
bip->bli_item.li_desc->lid_flags |= XFS_LID_DIRTY;
bip->bli_flags |= XFS_BLI_DIRTY | XFS_BLI_LOGGED;
if (!(bip->bli_flags & XFS_BLI_ORDERED))
xfs_buf_item_log(bip, first, last);
}
void
xfs_trans_binval(
xfs_trans_t *tp,
xfs_buf_t *bp)
{
xfs_buf_log_item_t *bip = bp->b_fspriv;
int i;
ASSERT(bp->b_transp == tp);
ASSERT(bip != NULL);
ASSERT(atomic_read(&bip->bli_refcount) > 0);
trace_xfs_trans_binval(bip);
if (bip->bli_flags & XFS_BLI_STALE) {
ASSERT(XFS_BUF_ISSTALE(bp));
ASSERT(!(bip->bli_flags & (XFS_BLI_LOGGED | XFS_BLI_DIRTY)));
ASSERT(!(bip->__bli_format.blf_flags & XFS_BLF_INODE_BUF));
ASSERT(!(bip->__bli_format.blf_flags & XFS_BLFT_MASK));
ASSERT(bip->__bli_format.blf_flags & XFS_BLF_CANCEL);
ASSERT(bip->bli_item.li_desc->lid_flags & XFS_LID_DIRTY);
ASSERT(tp->t_flags & XFS_TRANS_DIRTY);
return;
}
xfs_buf_stale(bp);
bip->bli_flags |= XFS_BLI_STALE;
bip->bli_flags &= ~(XFS_BLI_INODE_BUF | XFS_BLI_LOGGED | XFS_BLI_DIRTY);
bip->__bli_format.blf_flags &= ~XFS_BLF_INODE_BUF;
bip->__bli_format.blf_flags |= XFS_BLF_CANCEL;
bip->__bli_format.blf_flags &= ~XFS_BLFT_MASK;
for (i = 0; i < bip->bli_format_count; i++) {
memset(bip->bli_formats[i].blf_data_map, 0,
(bip->bli_formats[i].blf_map_size * sizeof(uint)));
}
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
xfs_trans_buf_set_type(tp, bp, XFS_BLFT_DINO_BUF);
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
xfs_trans_buf_set_type(tp, bp, XFS_BLFT_DINO_BUF);
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
xfs_trans_buf_set_type(tp, bp, XFS_BLFT_DINO_BUF);
}
void
xfs_trans_ordered_buf(
struct xfs_trans *tp,
struct xfs_buf *bp)
{
struct xfs_buf_log_item *bip = bp->b_fspriv;
ASSERT(bp->b_transp == tp);
ASSERT(bip != NULL);
ASSERT(atomic_read(&bip->bli_refcount) > 0);
bip->bli_flags |= XFS_BLI_ORDERED;
trace_xfs_buf_item_ordered(bip);
}
void
xfs_trans_buf_set_type(
struct xfs_trans *tp,
struct xfs_buf *bp,
enum xfs_blft type)
{
struct xfs_buf_log_item *bip = bp->b_fspriv;
if (!tp)
return;
ASSERT(bp->b_transp == tp);
ASSERT(bip != NULL);
ASSERT(atomic_read(&bip->bli_refcount) > 0);
xfs_blft_to_flags(&bip->__bli_format, type);
}
void
xfs_trans_buf_copy_type(
struct xfs_buf *dst_bp,
struct xfs_buf *src_bp)
{
struct xfs_buf_log_item *sbip = src_bp->b_fspriv;
struct xfs_buf_log_item *dbip = dst_bp->b_fspriv;
enum xfs_blft type;
type = xfs_blft_from_flags(&sbip->__bli_format);
xfs_blft_to_flags(&dbip->__bli_format, type);
}
void
xfs_trans_dquot_buf(
xfs_trans_t *tp,
xfs_buf_t *bp,
uint type)
{
struct xfs_buf_log_item *bip = bp->b_fspriv;
ASSERT(type == XFS_BLF_UDQUOT_BUF ||
type == XFS_BLF_PDQUOT_BUF ||
type == XFS_BLF_GDQUOT_BUF);
bip->__bli_format.blf_flags |= type;
switch (type) {
case XFS_BLF_UDQUOT_BUF:
type = XFS_BLFT_UDQUOT_BUF;
break;
case XFS_BLF_PDQUOT_BUF:
type = XFS_BLFT_PDQUOT_BUF;
break;
case XFS_BLF_GDQUOT_BUF:
type = XFS_BLFT_GDQUOT_BUF;
break;
default:
type = XFS_BLFT_UNKNOWN_BUF;
break;
}
xfs_trans_buf_set_type(tp, bp, type);
}
