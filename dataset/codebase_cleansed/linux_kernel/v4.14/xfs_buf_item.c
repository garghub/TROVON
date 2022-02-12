static inline struct xfs_buf_log_item *BUF_ITEM(struct xfs_log_item *lip)
{
return container_of(lip, struct xfs_buf_log_item, bli_item);
}
static inline int
xfs_buf_log_format_size(
struct xfs_buf_log_format *blfp)
{
return offsetof(struct xfs_buf_log_format, blf_data_map) +
(blfp->blf_map_size * sizeof(blfp->blf_data_map[0]));
}
STATIC void
xfs_buf_item_size_segment(
struct xfs_buf_log_item *bip,
struct xfs_buf_log_format *blfp,
int *nvecs,
int *nbytes)
{
struct xfs_buf *bp = bip->bli_buf;
int next_bit;
int last_bit;
last_bit = xfs_next_bit(blfp->blf_data_map, blfp->blf_map_size, 0);
if (last_bit == -1)
return;
*nvecs += 2;
*nbytes += xfs_buf_log_format_size(blfp) + XFS_BLF_CHUNK;
while (last_bit != -1) {
next_bit = xfs_next_bit(blfp->blf_data_map, blfp->blf_map_size,
last_bit + 1);
if (next_bit == -1) {
break;
} else if (next_bit != last_bit + 1) {
last_bit = next_bit;
(*nvecs)++;
} else if (xfs_buf_offset(bp, next_bit * XFS_BLF_CHUNK) !=
(xfs_buf_offset(bp, last_bit * XFS_BLF_CHUNK) +
XFS_BLF_CHUNK)) {
last_bit = next_bit;
(*nvecs)++;
} else {
last_bit++;
}
*nbytes += XFS_BLF_CHUNK;
}
}
STATIC void
xfs_buf_item_size(
struct xfs_log_item *lip,
int *nvecs,
int *nbytes)
{
struct xfs_buf_log_item *bip = BUF_ITEM(lip);
int i;
ASSERT(atomic_read(&bip->bli_refcount) > 0);
if (bip->bli_flags & XFS_BLI_STALE) {
trace_xfs_buf_item_size_stale(bip);
ASSERT(bip->__bli_format.blf_flags & XFS_BLF_CANCEL);
*nvecs += bip->bli_format_count;
for (i = 0; i < bip->bli_format_count; i++) {
*nbytes += xfs_buf_log_format_size(&bip->bli_formats[i]);
}
return;
}
ASSERT(bip->bli_flags & XFS_BLI_LOGGED);
if (bip->bli_flags & XFS_BLI_ORDERED) {
trace_xfs_buf_item_size_ordered(bip);
*nvecs = XFS_LOG_VEC_ORDERED;
return;
}
for (i = 0; i < bip->bli_format_count; i++) {
xfs_buf_item_size_segment(bip, &bip->bli_formats[i],
nvecs, nbytes);
}
trace_xfs_buf_item_size(bip);
}
static inline void
xfs_buf_item_copy_iovec(
struct xfs_log_vec *lv,
struct xfs_log_iovec **vecp,
struct xfs_buf *bp,
uint offset,
int first_bit,
uint nbits)
{
offset += first_bit * XFS_BLF_CHUNK;
xlog_copy_iovec(lv, vecp, XLOG_REG_TYPE_BCHUNK,
xfs_buf_offset(bp, offset),
nbits * XFS_BLF_CHUNK);
}
static inline bool
xfs_buf_item_straddle(
struct xfs_buf *bp,
uint offset,
int next_bit,
int last_bit)
{
return xfs_buf_offset(bp, offset + (next_bit << XFS_BLF_SHIFT)) !=
(xfs_buf_offset(bp, offset + (last_bit << XFS_BLF_SHIFT)) +
XFS_BLF_CHUNK);
}
static void
xfs_buf_item_format_segment(
struct xfs_buf_log_item *bip,
struct xfs_log_vec *lv,
struct xfs_log_iovec **vecp,
uint offset,
struct xfs_buf_log_format *blfp)
{
struct xfs_buf *bp = bip->bli_buf;
uint base_size;
int first_bit;
int last_bit;
int next_bit;
uint nbits;
blfp->blf_flags = bip->__bli_format.blf_flags;
base_size = xfs_buf_log_format_size(blfp);
first_bit = xfs_next_bit(blfp->blf_data_map, blfp->blf_map_size, 0);
if (!(bip->bli_flags & XFS_BLI_STALE) && first_bit == -1) {
return;
}
blfp = xlog_copy_iovec(lv, vecp, XLOG_REG_TYPE_BFORMAT, blfp, base_size);
blfp->blf_size = 1;
if (bip->bli_flags & XFS_BLI_STALE) {
trace_xfs_buf_item_format_stale(bip);
ASSERT(blfp->blf_flags & XFS_BLF_CANCEL);
return;
}
last_bit = first_bit;
nbits = 1;
for (;;) {
next_bit = xfs_next_bit(blfp->blf_data_map, blfp->blf_map_size,
(uint)last_bit + 1);
if (next_bit == -1) {
xfs_buf_item_copy_iovec(lv, vecp, bp, offset,
first_bit, nbits);
blfp->blf_size++;
break;
} else if (next_bit != last_bit + 1 ||
xfs_buf_item_straddle(bp, offset, next_bit, last_bit)) {
xfs_buf_item_copy_iovec(lv, vecp, bp, offset,
first_bit, nbits);
blfp->blf_size++;
first_bit = next_bit;
last_bit = next_bit;
nbits = 1;
} else {
last_bit++;
nbits++;
}
}
}
STATIC void
xfs_buf_item_format(
struct xfs_log_item *lip,
struct xfs_log_vec *lv)
{
struct xfs_buf_log_item *bip = BUF_ITEM(lip);
struct xfs_buf *bp = bip->bli_buf;
struct xfs_log_iovec *vecp = NULL;
uint offset = 0;
int i;
ASSERT(atomic_read(&bip->bli_refcount) > 0);
ASSERT((bip->bli_flags & XFS_BLI_LOGGED) ||
(bip->bli_flags & XFS_BLI_STALE));
ASSERT((bip->bli_flags & XFS_BLI_STALE) ||
(xfs_blft_from_flags(&bip->__bli_format) > XFS_BLFT_UNKNOWN_BUF
&& xfs_blft_from_flags(&bip->__bli_format) < XFS_BLFT_MAX_BUF));
ASSERT(!(bip->bli_flags & XFS_BLI_ORDERED) ||
(bip->bli_flags & XFS_BLI_STALE));
if (bip->bli_flags & XFS_BLI_INODE_BUF) {
if (xfs_sb_version_hascrc(&lip->li_mountp->m_sb) ||
!((bip->bli_flags & XFS_BLI_INODE_ALLOC_BUF) &&
xfs_log_item_in_current_chkpt(lip)))
bip->__bli_format.blf_flags |= XFS_BLF_INODE_BUF;
bip->bli_flags &= ~XFS_BLI_INODE_BUF;
}
for (i = 0; i < bip->bli_format_count; i++) {
xfs_buf_item_format_segment(bip, lv, &vecp, offset,
&bip->bli_formats[i]);
offset += BBTOB(bp->b_maps[i].bm_len);
}
trace_xfs_buf_item_format(bip);
}
STATIC void
xfs_buf_item_pin(
struct xfs_log_item *lip)
{
struct xfs_buf_log_item *bip = BUF_ITEM(lip);
ASSERT(atomic_read(&bip->bli_refcount) > 0);
ASSERT((bip->bli_flags & XFS_BLI_LOGGED) ||
(bip->bli_flags & XFS_BLI_ORDERED) ||
(bip->bli_flags & XFS_BLI_STALE));
trace_xfs_buf_item_pin(bip);
atomic_inc(&bip->bli_refcount);
atomic_inc(&bip->bli_buf->b_pin_count);
}
STATIC void
xfs_buf_item_unpin(
struct xfs_log_item *lip,
int remove)
{
struct xfs_buf_log_item *bip = BUF_ITEM(lip);
xfs_buf_t *bp = bip->bli_buf;
struct xfs_ail *ailp = lip->li_ailp;
int stale = bip->bli_flags & XFS_BLI_STALE;
int freed;
ASSERT(bp->b_fspriv == bip);
ASSERT(atomic_read(&bip->bli_refcount) > 0);
trace_xfs_buf_item_unpin(bip);
freed = atomic_dec_and_test(&bip->bli_refcount);
if (atomic_dec_and_test(&bp->b_pin_count))
wake_up_all(&bp->b_waiters);
if (freed && stale) {
ASSERT(bip->bli_flags & XFS_BLI_STALE);
ASSERT(xfs_buf_islocked(bp));
ASSERT(bp->b_flags & XBF_STALE);
ASSERT(bip->__bli_format.blf_flags & XFS_BLF_CANCEL);
trace_xfs_buf_item_unpin_stale(bip);
if (remove) {
if (lip->li_desc)
xfs_trans_del_item(lip);
bp->b_transp = NULL;
}
if (bip->bli_flags & XFS_BLI_STALE_INODE) {
xfs_buf_do_callbacks(bp);
bp->b_fspriv = NULL;
bp->b_iodone = NULL;
} else {
spin_lock(&ailp->xa_lock);
xfs_trans_ail_delete(ailp, lip, SHUTDOWN_LOG_IO_ERROR);
xfs_buf_item_relse(bp);
ASSERT(bp->b_fspriv == NULL);
}
xfs_buf_relse(bp);
} else if (freed && remove) {
xfs_buf_lock(bp);
xfs_buf_hold(bp);
bp->b_flags |= XBF_ASYNC;
xfs_buf_ioerror(bp, -EIO);
bp->b_flags &= ~XBF_DONE;
xfs_buf_stale(bp);
xfs_buf_ioend(bp);
}
}
STATIC uint
xfs_buf_item_push(
struct xfs_log_item *lip,
struct list_head *buffer_list)
{
struct xfs_buf_log_item *bip = BUF_ITEM(lip);
struct xfs_buf *bp = bip->bli_buf;
uint rval = XFS_ITEM_SUCCESS;
if (xfs_buf_ispinned(bp))
return XFS_ITEM_PINNED;
if (!xfs_buf_trylock(bp)) {
if (xfs_buf_ispinned(bp))
return XFS_ITEM_PINNED;
return XFS_ITEM_LOCKED;
}
ASSERT(!(bip->bli_flags & XFS_BLI_STALE));
trace_xfs_buf_item_push(bip);
if ((bp->b_flags & XBF_WRITE_FAIL) &&
___ratelimit(&xfs_buf_write_fail_rl_state, "XFS: Failing async write")) {
xfs_warn(bp->b_target->bt_mount,
"Failing async write on buffer block 0x%llx. Retrying async write.",
(long long)bp->b_bn);
}
if (!xfs_buf_delwri_queue(bp, buffer_list))
rval = XFS_ITEM_FLUSHING;
xfs_buf_unlock(bp);
return rval;
}
STATIC void
xfs_buf_item_unlock(
struct xfs_log_item *lip)
{
struct xfs_buf_log_item *bip = BUF_ITEM(lip);
struct xfs_buf *bp = bip->bli_buf;
bool aborted = !!(lip->li_flags & XFS_LI_ABORTED);
bool hold = !!(bip->bli_flags & XFS_BLI_HOLD);
bool dirty = !!(bip->bli_flags & XFS_BLI_DIRTY);
#if defined(DEBUG) || defined(XFS_WARN)
bool ordered = !!(bip->bli_flags & XFS_BLI_ORDERED);
#endif
bp->b_transp = NULL;
bip->bli_flags &= ~(XFS_BLI_LOGGED | XFS_BLI_HOLD | XFS_BLI_ORDERED);
if (bip->bli_flags & XFS_BLI_STALE) {
trace_xfs_buf_item_unlock_stale(bip);
ASSERT(bip->__bli_format.blf_flags & XFS_BLF_CANCEL);
if (!aborted) {
atomic_dec(&bip->bli_refcount);
return;
}
}
trace_xfs_buf_item_unlock(bip);
ASSERT((!ordered && dirty == xfs_buf_item_dirty_format(bip)) ||
(ordered && dirty && !xfs_buf_item_dirty_format(bip)));
if (atomic_dec_and_test(&bip->bli_refcount)) {
if (aborted) {
ASSERT(XFS_FORCED_SHUTDOWN(lip->li_mountp));
xfs_trans_ail_remove(lip, SHUTDOWN_LOG_IO_ERROR);
xfs_buf_item_relse(bp);
} else if (!dirty)
xfs_buf_item_relse(bp);
}
if (!hold)
xfs_buf_relse(bp);
}
STATIC xfs_lsn_t
xfs_buf_item_committed(
struct xfs_log_item *lip,
xfs_lsn_t lsn)
{
struct xfs_buf_log_item *bip = BUF_ITEM(lip);
trace_xfs_buf_item_committed(bip);
if ((bip->bli_flags & XFS_BLI_INODE_ALLOC_BUF) && lip->li_lsn != 0)
return lip->li_lsn;
return lsn;
}
STATIC void
xfs_buf_item_committing(
struct xfs_log_item *lip,
xfs_lsn_t commit_lsn)
{
}
STATIC int
xfs_buf_item_get_format(
struct xfs_buf_log_item *bip,
int count)
{
ASSERT(bip->bli_formats == NULL);
bip->bli_format_count = count;
if (count == 1) {
bip->bli_formats = &bip->__bli_format;
return 0;
}
bip->bli_formats = kmem_zalloc(count * sizeof(struct xfs_buf_log_format),
KM_SLEEP);
if (!bip->bli_formats)
return -ENOMEM;
return 0;
}
STATIC void
xfs_buf_item_free_format(
struct xfs_buf_log_item *bip)
{
if (bip->bli_formats != &bip->__bli_format) {
kmem_free(bip->bli_formats);
bip->bli_formats = NULL;
}
}
int
xfs_buf_item_init(
struct xfs_buf *bp,
struct xfs_mount *mp)
{
struct xfs_log_item *lip = bp->b_fspriv;
struct xfs_buf_log_item *bip;
int chunks;
int map_size;
int error;
int i;
ASSERT(bp->b_target->bt_mount == mp);
if (lip != NULL && lip->li_type == XFS_LI_BUF)
return 0;
bip = kmem_zone_zalloc(xfs_buf_item_zone, KM_SLEEP);
xfs_log_item_init(mp, &bip->bli_item, XFS_LI_BUF, &xfs_buf_item_ops);
bip->bli_buf = bp;
error = xfs_buf_item_get_format(bip, bp->b_map_count);
ASSERT(error == 0);
if (error) {
kmem_zone_free(xfs_buf_item_zone, bip);
return error;
}
for (i = 0; i < bip->bli_format_count; i++) {
chunks = DIV_ROUND_UP(BBTOB(bp->b_maps[i].bm_len),
XFS_BLF_CHUNK);
map_size = DIV_ROUND_UP(chunks, NBWORD);
bip->bli_formats[i].blf_type = XFS_LI_BUF;
bip->bli_formats[i].blf_blkno = bp->b_maps[i].bm_bn;
bip->bli_formats[i].blf_len = bp->b_maps[i].bm_len;
bip->bli_formats[i].blf_map_size = map_size;
}
if (bp->b_fspriv)
bip->bli_item.li_bio_list = bp->b_fspriv;
bp->b_fspriv = bip;
xfs_buf_hold(bp);
return 0;
}
static void
xfs_buf_item_log_segment(
uint first,
uint last,
uint *map)
{
uint first_bit;
uint last_bit;
uint bits_to_set;
uint bits_set;
uint word_num;
uint *wordp;
uint bit;
uint end_bit;
uint mask;
first_bit = first >> XFS_BLF_SHIFT;
last_bit = last >> XFS_BLF_SHIFT;
bits_to_set = last_bit - first_bit + 1;
word_num = first_bit >> BIT_TO_WORD_SHIFT;
wordp = &map[word_num];
bit = first_bit & (uint)(NBWORD - 1);
if (bit) {
end_bit = MIN(bit + bits_to_set, (uint)NBWORD);
mask = ((1U << (end_bit - bit)) - 1) << bit;
*wordp |= mask;
wordp++;
bits_set = end_bit - bit;
} else {
bits_set = 0;
}
while ((bits_to_set - bits_set) >= NBWORD) {
*wordp |= 0xffffffff;
bits_set += NBWORD;
wordp++;
}
end_bit = bits_to_set - bits_set;
if (end_bit) {
mask = (1U << end_bit) - 1;
*wordp |= mask;
}
}
void
xfs_buf_item_log(
xfs_buf_log_item_t *bip,
uint first,
uint last)
{
int i;
uint start;
uint end;
struct xfs_buf *bp = bip->bli_buf;
start = 0;
for (i = 0; i < bip->bli_format_count; i++) {
if (start > last)
break;
end = start + BBTOB(bp->b_maps[i].bm_len) - 1;
if (first > end) {
start += BBTOB(bp->b_maps[i].bm_len);
continue;
}
if (first < start)
first = start;
if (end > last)
end = last;
xfs_buf_item_log_segment(first - start, end - start,
&bip->bli_formats[i].blf_data_map[0]);
start += BBTOB(bp->b_maps[i].bm_len);
}
}
bool
xfs_buf_item_dirty_format(
struct xfs_buf_log_item *bip)
{
int i;
for (i = 0; i < bip->bli_format_count; i++) {
if (!xfs_bitmap_empty(bip->bli_formats[i].blf_data_map,
bip->bli_formats[i].blf_map_size))
return true;
}
return false;
}
STATIC void
xfs_buf_item_free(
xfs_buf_log_item_t *bip)
{
xfs_buf_item_free_format(bip);
kmem_free(bip->bli_item.li_lv_shadow);
kmem_zone_free(xfs_buf_item_zone, bip);
}
void
xfs_buf_item_relse(
xfs_buf_t *bp)
{
xfs_buf_log_item_t *bip = bp->b_fspriv;
trace_xfs_buf_item_relse(bp, _RET_IP_);
ASSERT(!(bip->bli_item.li_flags & XFS_LI_IN_AIL));
bp->b_fspriv = bip->bli_item.li_bio_list;
if (bp->b_fspriv == NULL)
bp->b_iodone = NULL;
xfs_buf_rele(bp);
xfs_buf_item_free(bip);
}
void
xfs_buf_attach_iodone(
xfs_buf_t *bp,
void (*cb)(xfs_buf_t *, xfs_log_item_t *),
xfs_log_item_t *lip)
{
xfs_log_item_t *head_lip;
ASSERT(xfs_buf_islocked(bp));
lip->li_cb = cb;
head_lip = bp->b_fspriv;
if (head_lip) {
lip->li_bio_list = head_lip->li_bio_list;
head_lip->li_bio_list = lip;
} else {
bp->b_fspriv = lip;
}
ASSERT(bp->b_iodone == NULL ||
bp->b_iodone == xfs_buf_iodone_callbacks);
bp->b_iodone = xfs_buf_iodone_callbacks;
}
STATIC void
xfs_buf_do_callbacks(
struct xfs_buf *bp)
{
struct xfs_log_item *lip;
while ((lip = bp->b_fspriv) != NULL) {
bp->b_fspriv = lip->li_bio_list;
ASSERT(lip->li_cb != NULL);
lip->li_bio_list = NULL;
lip->li_cb(bp, lip);
}
}
STATIC void
xfs_buf_do_callbacks_fail(
struct xfs_buf *bp)
{
struct xfs_log_item *next;
struct xfs_log_item *lip = bp->b_fspriv;
struct xfs_ail *ailp = lip->li_ailp;
spin_lock(&ailp->xa_lock);
for (; lip; lip = next) {
next = lip->li_bio_list;
if (lip->li_ops->iop_error)
lip->li_ops->iop_error(lip, bp);
}
spin_unlock(&ailp->xa_lock);
}
static bool
xfs_buf_iodone_callback_error(
struct xfs_buf *bp)
{
struct xfs_log_item *lip = bp->b_fspriv;
struct xfs_mount *mp = lip->li_mountp;
static ulong lasttime;
static xfs_buftarg_t *lasttarg;
struct xfs_error_cfg *cfg;
if (XFS_FORCED_SHUTDOWN(mp))
goto out_stale;
if (bp->b_target != lasttarg ||
time_after(jiffies, (lasttime + 5*HZ))) {
lasttime = jiffies;
xfs_buf_ioerror_alert(bp, __func__);
}
lasttarg = bp->b_target;
if (!(bp->b_flags & XBF_ASYNC))
goto out_stale;
trace_xfs_buf_item_iodone_async(bp, _RET_IP_);
ASSERT(bp->b_iodone != NULL);
cfg = xfs_error_get_cfg(mp, XFS_ERR_METADATA, bp->b_error);
if (!(bp->b_flags & (XBF_STALE | XBF_WRITE_FAIL)) ||
bp->b_last_error != bp->b_error) {
bp->b_flags |= (XBF_WRITE | XBF_DONE | XBF_WRITE_FAIL);
bp->b_last_error = bp->b_error;
if (cfg->retry_timeout != XFS_ERR_RETRY_FOREVER &&
!bp->b_first_retry_time)
bp->b_first_retry_time = jiffies;
xfs_buf_ioerror(bp, 0);
xfs_buf_submit(bp);
return true;
}
if (cfg->max_retries != XFS_ERR_RETRY_FOREVER &&
++bp->b_retries > cfg->max_retries)
goto permanent_error;
if (cfg->retry_timeout != XFS_ERR_RETRY_FOREVER &&
time_after(jiffies, cfg->retry_timeout + bp->b_first_retry_time))
goto permanent_error;
if ((mp->m_flags & XFS_MOUNT_UNMOUNTING) && mp->m_fail_unmount)
goto permanent_error;
xfs_buf_do_callbacks_fail(bp);
xfs_buf_ioerror(bp, 0);
xfs_buf_relse(bp);
return true;
permanent_error:
xfs_force_shutdown(mp, SHUTDOWN_META_IO_ERROR);
out_stale:
xfs_buf_stale(bp);
bp->b_flags |= XBF_DONE;
trace_xfs_buf_error_relse(bp, _RET_IP_);
return false;
}
void
xfs_buf_iodone_callbacks(
struct xfs_buf *bp)
{
if (bp->b_error && xfs_buf_iodone_callback_error(bp))
return;
bp->b_last_error = 0;
bp->b_retries = 0;
bp->b_first_retry_time = 0;
xfs_buf_do_callbacks(bp);
bp->b_fspriv = NULL;
bp->b_iodone = NULL;
xfs_buf_ioend(bp);
}
void
xfs_buf_iodone(
struct xfs_buf *bp,
struct xfs_log_item *lip)
{
struct xfs_ail *ailp = lip->li_ailp;
ASSERT(BUF_ITEM(lip)->bli_buf == bp);
xfs_buf_rele(bp);
spin_lock(&ailp->xa_lock);
xfs_trans_ail_delete(ailp, lip, SHUTDOWN_CORRUPT_INCORE);
xfs_buf_item_free(BUF_ITEM(lip));
}
bool
xfs_buf_resubmit_failed_buffers(
struct xfs_buf *bp,
struct xfs_log_item *lip,
struct list_head *buffer_list)
{
struct xfs_log_item *next;
for (; lip; lip = next) {
next = lip->li_bio_list;
xfs_clear_li_failed(lip);
}
return xfs_buf_delwri_queue(bp, buffer_list);
}
