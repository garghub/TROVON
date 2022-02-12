STATIC int
xfs_iomap_eof_align_last_fsb(
xfs_mount_t *mp,
xfs_inode_t *ip,
xfs_extlen_t extsize,
xfs_fileoff_t *last_fsb)
{
xfs_extlen_t align = 0;
int eof, error;
if (!XFS_IS_REALTIME_INODE(ip)) {
if (mp->m_swidth && (mp->m_flags & XFS_MOUNT_SWALLOC))
align = mp->m_swidth;
else if (mp->m_dalign)
align = mp->m_dalign;
if (align && XFS_ISIZE(ip) < XFS_FSB_TO_B(mp, align))
align = 0;
}
if (extsize) {
if (align)
align = roundup_64(align, extsize);
else
align = extsize;
}
if (align) {
xfs_fileoff_t new_last_fsb = roundup_64(*last_fsb, align);
error = xfs_bmap_eof(ip, new_last_fsb, XFS_DATA_FORK, &eof);
if (error)
return error;
if (eof)
*last_fsb = new_last_fsb;
}
return 0;
}
STATIC int
xfs_alert_fsblock_zero(
xfs_inode_t *ip,
xfs_bmbt_irec_t *imap)
{
xfs_alert_tag(ip->i_mount, XFS_PTAG_FSBLOCK_ZERO,
"Access to block zero in inode %llu "
"start_block: %llx start_off: %llx "
"blkcnt: %llx extent-state: %x",
(unsigned long long)ip->i_ino,
(unsigned long long)imap->br_startblock,
(unsigned long long)imap->br_startoff,
(unsigned long long)imap->br_blockcount,
imap->br_state);
return -EFSCORRUPTED;
}
int
xfs_iomap_write_direct(
xfs_inode_t *ip,
xfs_off_t offset,
size_t count,
xfs_bmbt_irec_t *imap,
int nmaps)
{
xfs_mount_t *mp = ip->i_mount;
xfs_fileoff_t offset_fsb;
xfs_fileoff_t last_fsb;
xfs_filblks_t count_fsb, resaligned;
xfs_fsblock_t firstfsb;
xfs_extlen_t extsz, temp;
int nimaps;
int quota_flag;
int rt;
xfs_trans_t *tp;
struct xfs_defer_ops dfops;
uint qblocks, resblks, resrtextents;
int error;
int lockmode;
int bmapi_flags = XFS_BMAPI_PREALLOC;
uint tflags = 0;
rt = XFS_IS_REALTIME_INODE(ip);
extsz = xfs_get_extsz_hint(ip);
lockmode = XFS_ILOCK_SHARED;
ASSERT(xfs_isilocked(ip, lockmode));
offset_fsb = XFS_B_TO_FSBT(mp, offset);
last_fsb = XFS_B_TO_FSB(mp, ((xfs_ufsize_t)(offset + count)));
if ((offset + count) > XFS_ISIZE(ip)) {
ASSERT(XFS_IFORK_PTR(ip, XFS_DATA_FORK)->if_flags &
XFS_IFEXTENTS);
error = xfs_iomap_eof_align_last_fsb(mp, ip, extsz, &last_fsb);
if (error)
goto out_unlock;
} else {
if (nmaps && (imap->br_startblock == HOLESTARTBLOCK))
last_fsb = MIN(last_fsb, (xfs_fileoff_t)
imap->br_blockcount +
imap->br_startoff);
}
count_fsb = last_fsb - offset_fsb;
ASSERT(count_fsb > 0);
resaligned = count_fsb;
if (unlikely(extsz)) {
if ((temp = do_mod(offset_fsb, extsz)))
resaligned += temp;
if ((temp = do_mod(resaligned, extsz)))
resaligned += extsz - temp;
}
if (unlikely(rt)) {
resrtextents = qblocks = resaligned;
resrtextents /= mp->m_sb.sb_rextsize;
resblks = XFS_DIOSTRAT_SPACE_RES(mp, 0);
quota_flag = XFS_QMOPT_RES_RTBLKS;
} else {
resrtextents = 0;
resblks = qblocks = XFS_DIOSTRAT_SPACE_RES(mp, resaligned);
quota_flag = XFS_QMOPT_RES_REGBLKS;
}
xfs_iunlock(ip, lockmode);
error = xfs_qm_dqattach(ip, 0);
if (error)
return error;
if (IS_DAX(VFS_I(ip))) {
bmapi_flags = XFS_BMAPI_CONVERT | XFS_BMAPI_ZERO;
if (ISUNWRITTEN(imap)) {
tflags |= XFS_TRANS_RESERVE;
resblks = XFS_DIOSTRAT_SPACE_RES(mp, 0) << 1;
}
}
error = xfs_trans_alloc(mp, &M_RES(mp)->tr_write, resblks, resrtextents,
tflags, &tp);
if (error)
return error;
lockmode = XFS_ILOCK_EXCL;
xfs_ilock(ip, lockmode);
error = xfs_trans_reserve_quota_nblks(tp, ip, qblocks, 0, quota_flag);
if (error)
goto out_trans_cancel;
xfs_trans_ijoin(tp, ip, 0);
xfs_defer_init(&dfops, &firstfsb);
nimaps = 1;
error = xfs_bmapi_write(tp, ip, offset_fsb, count_fsb,
bmapi_flags, &firstfsb, resblks, imap,
&nimaps, &dfops);
if (error)
goto out_bmap_cancel;
error = xfs_defer_finish(&tp, &dfops, NULL);
if (error)
goto out_bmap_cancel;
error = xfs_trans_commit(tp);
if (error)
goto out_unlock;
if (nimaps == 0) {
error = -ENOSPC;
goto out_unlock;
}
if (!(imap->br_startblock || XFS_IS_REALTIME_INODE(ip)))
error = xfs_alert_fsblock_zero(ip, imap);
out_unlock:
xfs_iunlock(ip, lockmode);
return error;
out_bmap_cancel:
xfs_defer_cancel(&dfops);
xfs_trans_unreserve_quota_nblks(tp, ip, (long)qblocks, 0, quota_flag);
out_trans_cancel:
xfs_trans_cancel(tp);
goto out_unlock;
}
STATIC int
xfs_iomap_eof_want_preallocate(
xfs_mount_t *mp,
xfs_inode_t *ip,
xfs_off_t offset,
size_t count,
xfs_bmbt_irec_t *imap,
int nimaps,
int *prealloc)
{
xfs_fileoff_t start_fsb;
xfs_filblks_t count_fsb;
int n, error, imaps;
int found_delalloc = 0;
*prealloc = 0;
if (offset + count <= XFS_ISIZE(ip))
return 0;
if (!(mp->m_flags & XFS_MOUNT_DFLT_IOSIZE) &&
XFS_ISIZE(ip) < XFS_FSB_TO_B(mp, mp->m_writeio_blocks))
return 0;
start_fsb = XFS_B_TO_FSBT(mp, ((xfs_ufsize_t)(offset + count - 1)));
count_fsb = XFS_B_TO_FSB(mp, mp->m_super->s_maxbytes);
while (count_fsb > 0) {
imaps = nimaps;
error = xfs_bmapi_read(ip, start_fsb, count_fsb, imap, &imaps,
0);
if (error)
return error;
for (n = 0; n < imaps; n++) {
if ((imap[n].br_startblock != HOLESTARTBLOCK) &&
(imap[n].br_startblock != DELAYSTARTBLOCK))
return 0;
start_fsb += imap[n].br_blockcount;
count_fsb -= imap[n].br_blockcount;
if (imap[n].br_startblock == DELAYSTARTBLOCK)
found_delalloc = 1;
}
}
if (!found_delalloc)
*prealloc = 1;
return 0;
}
STATIC xfs_fsblock_t
xfs_iomap_eof_prealloc_initial_size(
struct xfs_mount *mp,
struct xfs_inode *ip,
xfs_off_t offset,
xfs_bmbt_irec_t *imap,
int nimaps)
{
xfs_fileoff_t start_fsb;
int imaps = 1;
int error;
ASSERT(nimaps >= imaps);
if (mp->m_flags & XFS_MOUNT_DFLT_IOSIZE)
return 0;
if (XFS_ISIZE(ip) < XFS_FSB_TO_B(mp, mp->m_dalign))
return 0;
start_fsb = XFS_B_TO_FSB(mp, offset);
if (start_fsb)
start_fsb--;
error = xfs_bmapi_read(ip, start_fsb, 1, imap, &imaps, XFS_BMAPI_ENTIRE);
if (error)
return 0;
ASSERT(imaps == 1);
if (imap[0].br_startblock == HOLESTARTBLOCK)
return 0;
if (imap[0].br_blockcount <= (MAXEXTLEN >> 1))
return imap[0].br_blockcount << 1;
return XFS_B_TO_FSB(mp, offset);
}
STATIC bool
xfs_quota_need_throttle(
struct xfs_inode *ip,
int type,
xfs_fsblock_t alloc_blocks)
{
struct xfs_dquot *dq = xfs_inode_dquot(ip, type);
if (!dq || !xfs_this_quota_on(ip->i_mount, type))
return false;
if (!dq->q_prealloc_hi_wmark)
return false;
if (dq->q_res_bcount + alloc_blocks < dq->q_prealloc_lo_wmark)
return false;
return true;
}
STATIC void
xfs_quota_calc_throttle(
struct xfs_inode *ip,
int type,
xfs_fsblock_t *qblocks,
int *qshift,
int64_t *qfreesp)
{
int64_t freesp;
int shift = 0;
struct xfs_dquot *dq = xfs_inode_dquot(ip, type);
if (!dq || dq->q_res_bcount >= dq->q_prealloc_hi_wmark) {
*qblocks = 0;
*qfreesp = 0;
return;
}
freesp = dq->q_prealloc_hi_wmark - dq->q_res_bcount;
if (freesp < dq->q_low_space[XFS_QLOWSP_5_PCNT]) {
shift = 2;
if (freesp < dq->q_low_space[XFS_QLOWSP_3_PCNT])
shift += 2;
if (freesp < dq->q_low_space[XFS_QLOWSP_1_PCNT])
shift += 2;
}
if (freesp < *qfreesp)
*qfreesp = freesp;
if ((freesp >> shift) < (*qblocks >> *qshift)) {
*qblocks = freesp;
*qshift = shift;
}
}
STATIC xfs_fsblock_t
xfs_iomap_prealloc_size(
struct xfs_mount *mp,
struct xfs_inode *ip,
xfs_off_t offset,
struct xfs_bmbt_irec *imap,
int nimaps)
{
xfs_fsblock_t alloc_blocks = 0;
int shift = 0;
int64_t freesp;
xfs_fsblock_t qblocks;
int qshift = 0;
alloc_blocks = xfs_iomap_eof_prealloc_initial_size(mp, ip, offset,
imap, nimaps);
if (!alloc_blocks)
goto check_writeio;
qblocks = alloc_blocks;
alloc_blocks = XFS_FILEOFF_MIN(roundup_pow_of_two(MAXEXTLEN),
alloc_blocks);
freesp = percpu_counter_read_positive(&mp->m_fdblocks);
if (freesp < mp->m_low_space[XFS_LOWSP_5_PCNT]) {
shift = 2;
if (freesp < mp->m_low_space[XFS_LOWSP_4_PCNT])
shift++;
if (freesp < mp->m_low_space[XFS_LOWSP_3_PCNT])
shift++;
if (freesp < mp->m_low_space[XFS_LOWSP_2_PCNT])
shift++;
if (freesp < mp->m_low_space[XFS_LOWSP_1_PCNT])
shift++;
}
if (xfs_quota_need_throttle(ip, XFS_DQ_USER, alloc_blocks))
xfs_quota_calc_throttle(ip, XFS_DQ_USER, &qblocks, &qshift,
&freesp);
if (xfs_quota_need_throttle(ip, XFS_DQ_GROUP, alloc_blocks))
xfs_quota_calc_throttle(ip, XFS_DQ_GROUP, &qblocks, &qshift,
&freesp);
if (xfs_quota_need_throttle(ip, XFS_DQ_PROJ, alloc_blocks))
xfs_quota_calc_throttle(ip, XFS_DQ_PROJ, &qblocks, &qshift,
&freesp);
alloc_blocks = MIN(alloc_blocks, qblocks);
shift = MAX(shift, qshift);
if (shift)
alloc_blocks >>= shift;
if (alloc_blocks)
alloc_blocks = rounddown_pow_of_two(alloc_blocks);
if (alloc_blocks > MAXEXTLEN)
alloc_blocks = MAXEXTLEN;
while (alloc_blocks && alloc_blocks >= freesp)
alloc_blocks >>= 4;
check_writeio:
if (alloc_blocks < mp->m_writeio_blocks)
alloc_blocks = mp->m_writeio_blocks;
trace_xfs_iomap_prealloc_size(ip, alloc_blocks, shift,
mp->m_writeio_blocks);
return alloc_blocks;
}
int
xfs_iomap_write_delay(
xfs_inode_t *ip,
xfs_off_t offset,
size_t count,
xfs_bmbt_irec_t *ret_imap)
{
xfs_mount_t *mp = ip->i_mount;
xfs_fileoff_t offset_fsb;
xfs_fileoff_t last_fsb;
xfs_off_t aligned_offset;
xfs_fileoff_t ioalign;
xfs_extlen_t extsz;
int nimaps;
xfs_bmbt_irec_t imap[XFS_WRITE_IMAPS];
int prealloc;
int error;
ASSERT(xfs_isilocked(ip, XFS_ILOCK_EXCL));
error = xfs_qm_dqattach_locked(ip, 0);
if (error)
return error;
extsz = xfs_get_extsz_hint(ip);
offset_fsb = XFS_B_TO_FSBT(mp, offset);
error = xfs_iomap_eof_want_preallocate(mp, ip, offset, count,
imap, XFS_WRITE_IMAPS, &prealloc);
if (error)
return error;
retry:
if (prealloc) {
xfs_fsblock_t alloc_blocks;
alloc_blocks = xfs_iomap_prealloc_size(mp, ip, offset, imap,
XFS_WRITE_IMAPS);
aligned_offset = XFS_WRITEIO_ALIGN(mp, (offset + count - 1));
ioalign = XFS_B_TO_FSBT(mp, aligned_offset);
last_fsb = ioalign + alloc_blocks;
} else {
last_fsb = XFS_B_TO_FSB(mp, ((xfs_ufsize_t)(offset + count)));
}
if (prealloc || extsz) {
error = xfs_iomap_eof_align_last_fsb(mp, ip, extsz, &last_fsb);
if (error)
return error;
}
if (last_fsb > XFS_B_TO_FSB(mp, mp->m_super->s_maxbytes))
last_fsb = XFS_B_TO_FSB(mp, mp->m_super->s_maxbytes);
ASSERT(last_fsb > offset_fsb);
nimaps = XFS_WRITE_IMAPS;
error = xfs_bmapi_delay(ip, offset_fsb, last_fsb - offset_fsb,
imap, &nimaps, XFS_BMAPI_ENTIRE);
switch (error) {
case 0:
case -ENOSPC:
case -EDQUOT:
break;
default:
return error;
}
if (nimaps == 0) {
trace_xfs_delalloc_enospc(ip, offset, count);
if (prealloc) {
prealloc = 0;
error = 0;
goto retry;
}
return error ? error : -ENOSPC;
}
if (!(imap[0].br_startblock || XFS_IS_REALTIME_INODE(ip)))
return xfs_alert_fsblock_zero(ip, &imap[0]);
if (prealloc)
xfs_inode_set_eofblocks_tag(ip);
*ret_imap = imap[0];
return 0;
}
int
xfs_iomap_write_allocate(
xfs_inode_t *ip,
xfs_off_t offset,
xfs_bmbt_irec_t *imap)
{
xfs_mount_t *mp = ip->i_mount;
xfs_fileoff_t offset_fsb, last_block;
xfs_fileoff_t end_fsb, map_start_fsb;
xfs_fsblock_t first_block;
struct xfs_defer_ops dfops;
xfs_filblks_t count_fsb;
xfs_trans_t *tp;
int nimaps;
int error = 0;
int nres;
error = xfs_qm_dqattach(ip, 0);
if (error)
return error;
offset_fsb = XFS_B_TO_FSBT(mp, offset);
count_fsb = imap->br_blockcount;
map_start_fsb = imap->br_startoff;
XFS_STATS_ADD(mp, xs_xstrat_bytes, XFS_FSB_TO_B(mp, count_fsb));
while (count_fsb != 0) {
nimaps = 0;
while (nimaps == 0) {
nres = XFS_EXTENTADD_SPACE_RES(mp, XFS_DATA_FORK);
error = xfs_trans_alloc(mp, &M_RES(mp)->tr_write, 0,
0, XFS_TRANS_RESERVE, &tp);
if (error)
return error;
xfs_ilock(ip, XFS_ILOCK_EXCL);
xfs_trans_ijoin(tp, ip, 0);
xfs_defer_init(&dfops, &first_block);
nimaps = 1;
end_fsb = XFS_B_TO_FSB(mp, XFS_ISIZE(ip));
error = xfs_bmap_last_offset(ip, &last_block,
XFS_DATA_FORK);
if (error)
goto trans_cancel;
last_block = XFS_FILEOFF_MAX(last_block, end_fsb);
if ((map_start_fsb + count_fsb) > last_block) {
count_fsb = last_block - map_start_fsb;
if (count_fsb == 0) {
error = -EAGAIN;
goto trans_cancel;
}
}
error = xfs_bmapi_write(tp, ip, map_start_fsb,
count_fsb, 0, &first_block,
nres, imap, &nimaps,
&dfops);
if (error)
goto trans_cancel;
error = xfs_defer_finish(&tp, &dfops, NULL);
if (error)
goto trans_cancel;
error = xfs_trans_commit(tp);
if (error)
goto error0;
xfs_iunlock(ip, XFS_ILOCK_EXCL);
}
if (!(imap->br_startblock || XFS_IS_REALTIME_INODE(ip)))
return xfs_alert_fsblock_zero(ip, imap);
if ((offset_fsb >= imap->br_startoff) &&
(offset_fsb < (imap->br_startoff +
imap->br_blockcount))) {
XFS_STATS_INC(mp, xs_xstrat_quick);
return 0;
}
count_fsb -= imap->br_blockcount;
map_start_fsb = imap->br_startoff + imap->br_blockcount;
}
trans_cancel:
xfs_defer_cancel(&dfops);
xfs_trans_cancel(tp);
error0:
xfs_iunlock(ip, XFS_ILOCK_EXCL);
return error;
}
int
xfs_iomap_write_unwritten(
xfs_inode_t *ip,
xfs_off_t offset,
xfs_off_t count)
{
xfs_mount_t *mp = ip->i_mount;
xfs_fileoff_t offset_fsb;
xfs_filblks_t count_fsb;
xfs_filblks_t numblks_fsb;
xfs_fsblock_t firstfsb;
int nimaps;
xfs_trans_t *tp;
xfs_bmbt_irec_t imap;
struct xfs_defer_ops dfops;
xfs_fsize_t i_size;
uint resblks;
int error;
trace_xfs_unwritten_convert(ip, offset, count);
offset_fsb = XFS_B_TO_FSBT(mp, offset);
count_fsb = XFS_B_TO_FSB(mp, (xfs_ufsize_t)offset + count);
count_fsb = (xfs_filblks_t)(count_fsb - offset_fsb);
resblks = XFS_DIOSTRAT_SPACE_RES(mp, 0) << 1;
do {
error = xfs_trans_alloc(mp, &M_RES(mp)->tr_write, resblks, 0,
XFS_TRANS_RESERVE | XFS_TRANS_NOFS, &tp);
if (error)
return error;
xfs_ilock(ip, XFS_ILOCK_EXCL);
xfs_trans_ijoin(tp, ip, 0);
xfs_defer_init(&dfops, &firstfsb);
nimaps = 1;
error = xfs_bmapi_write(tp, ip, offset_fsb, count_fsb,
XFS_BMAPI_CONVERT, &firstfsb, resblks,
&imap, &nimaps, &dfops);
if (error)
goto error_on_bmapi_transaction;
i_size = XFS_FSB_TO_B(mp, offset_fsb + count_fsb);
if (i_size > offset + count)
i_size = offset + count;
i_size = xfs_new_eof(ip, i_size);
if (i_size) {
ip->i_d.di_size = i_size;
xfs_trans_log_inode(tp, ip, XFS_ILOG_CORE);
}
error = xfs_defer_finish(&tp, &dfops, NULL);
if (error)
goto error_on_bmapi_transaction;
error = xfs_trans_commit(tp);
xfs_iunlock(ip, XFS_ILOCK_EXCL);
if (error)
return error;
if (!(imap.br_startblock || XFS_IS_REALTIME_INODE(ip)))
return xfs_alert_fsblock_zero(ip, &imap);
if ((numblks_fsb = imap.br_blockcount) == 0) {
ASSERT(imap.br_blockcount);
break;
}
offset_fsb += numblks_fsb;
count_fsb -= numblks_fsb;
} while (count_fsb > 0);
return 0;
error_on_bmapi_transaction:
xfs_defer_cancel(&dfops);
xfs_trans_cancel(tp);
xfs_iunlock(ip, XFS_ILOCK_EXCL);
return error;
}
void
xfs_bmbt_to_iomap(
struct xfs_inode *ip,
struct iomap *iomap,
struct xfs_bmbt_irec *imap)
{
struct xfs_mount *mp = ip->i_mount;
if (imap->br_startblock == HOLESTARTBLOCK) {
iomap->blkno = IOMAP_NULL_BLOCK;
iomap->type = IOMAP_HOLE;
} else if (imap->br_startblock == DELAYSTARTBLOCK) {
iomap->blkno = IOMAP_NULL_BLOCK;
iomap->type = IOMAP_DELALLOC;
} else {
iomap->blkno = xfs_fsb_to_db(ip, imap->br_startblock);
if (imap->br_state == XFS_EXT_UNWRITTEN)
iomap->type = IOMAP_UNWRITTEN;
else
iomap->type = IOMAP_MAPPED;
}
iomap->offset = XFS_FSB_TO_B(mp, imap->br_startoff);
iomap->length = XFS_FSB_TO_B(mp, imap->br_blockcount);
iomap->bdev = xfs_find_bdev_for_inode(VFS_I(ip));
}
static inline bool imap_needs_alloc(struct xfs_bmbt_irec *imap, int nimaps)
{
return !nimaps ||
imap->br_startblock == HOLESTARTBLOCK ||
imap->br_startblock == DELAYSTARTBLOCK;
}
static int
xfs_file_iomap_begin(
struct inode *inode,
loff_t offset,
loff_t length,
unsigned flags,
struct iomap *iomap)
{
struct xfs_inode *ip = XFS_I(inode);
struct xfs_mount *mp = ip->i_mount;
struct xfs_bmbt_irec imap;
xfs_fileoff_t offset_fsb, end_fsb;
int nimaps = 1, error = 0;
if (XFS_FORCED_SHUTDOWN(mp))
return -EIO;
xfs_ilock(ip, XFS_ILOCK_EXCL);
ASSERT(offset <= mp->m_super->s_maxbytes);
if ((xfs_fsize_t)offset + length > mp->m_super->s_maxbytes)
length = mp->m_super->s_maxbytes - offset;
offset_fsb = XFS_B_TO_FSBT(mp, offset);
end_fsb = XFS_B_TO_FSB(mp, offset + length);
error = xfs_bmapi_read(ip, offset_fsb, end_fsb - offset_fsb, &imap,
&nimaps, XFS_BMAPI_ENTIRE);
if (error) {
xfs_iunlock(ip, XFS_ILOCK_EXCL);
return error;
}
if ((flags & IOMAP_WRITE) && imap_needs_alloc(&imap, nimaps)) {
length = min_t(loff_t, length, 1024 * PAGE_SIZE);
if (xfs_get_extsz_hint(ip)) {
xfs_ilock_demote(ip, XFS_ILOCK_EXCL);
error = xfs_iomap_write_direct(ip, offset, length, &imap,
nimaps);
} else {
error = xfs_iomap_write_delay(ip, offset, length, &imap);
xfs_iunlock(ip, XFS_ILOCK_EXCL);
}
if (error)
return error;
trace_xfs_iomap_alloc(ip, offset, length, 0, &imap);
} else {
ASSERT(nimaps);
xfs_iunlock(ip, XFS_ILOCK_EXCL);
trace_xfs_iomap_found(ip, offset, length, 0, &imap);
}
xfs_bmbt_to_iomap(ip, iomap, &imap);
return 0;
}
static int
xfs_file_iomap_end_delalloc(
struct xfs_inode *ip,
loff_t offset,
loff_t length,
ssize_t written)
{
struct xfs_mount *mp = ip->i_mount;
xfs_fileoff_t start_fsb;
xfs_fileoff_t end_fsb;
int error = 0;
start_fsb = XFS_B_TO_FSB(mp, offset + written);
end_fsb = XFS_B_TO_FSB(mp, offset + length);
if (start_fsb < end_fsb) {
xfs_ilock(ip, XFS_ILOCK_EXCL);
error = xfs_bmap_punch_delalloc_range(ip, start_fsb,
end_fsb - start_fsb);
xfs_iunlock(ip, XFS_ILOCK_EXCL);
if (error && !XFS_FORCED_SHUTDOWN(mp)) {
xfs_alert(mp, "%s: unable to clean up ino %lld",
__func__, ip->i_ino);
return error;
}
}
return 0;
}
static int
xfs_file_iomap_end(
struct inode *inode,
loff_t offset,
loff_t length,
ssize_t written,
unsigned flags,
struct iomap *iomap)
{
if ((flags & IOMAP_WRITE) && iomap->type == IOMAP_DELALLOC)
return xfs_file_iomap_end_delalloc(XFS_I(inode), offset,
length, written);
return 0;
}
static int
xfs_xattr_iomap_begin(
struct inode *inode,
loff_t offset,
loff_t length,
unsigned flags,
struct iomap *iomap)
{
struct xfs_inode *ip = XFS_I(inode);
struct xfs_mount *mp = ip->i_mount;
xfs_fileoff_t offset_fsb = XFS_B_TO_FSBT(mp, offset);
xfs_fileoff_t end_fsb = XFS_B_TO_FSB(mp, offset + length);
struct xfs_bmbt_irec imap;
int nimaps = 1, error = 0;
unsigned lockmode;
if (XFS_FORCED_SHUTDOWN(mp))
return -EIO;
lockmode = xfs_ilock_data_map_shared(ip);
if (XFS_IFORK_Q(ip) || !ip->i_d.di_anextents) {
error = -ENOENT;
goto out_unlock;
}
ASSERT(ip->i_d.di_aformat != XFS_DINODE_FMT_LOCAL);
error = xfs_bmapi_read(ip, offset_fsb, end_fsb - offset_fsb, &imap,
&nimaps, XFS_BMAPI_ENTIRE | XFS_BMAPI_ATTRFORK);
out_unlock:
xfs_iunlock(ip, lockmode);
if (!error) {
ASSERT(nimaps);
xfs_bmbt_to_iomap(ip, iomap, &imap);
}
return error;
}
