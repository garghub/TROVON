STATIC int
xfs_iomap_eof_align_last_fsb(
xfs_mount_t *mp,
xfs_inode_t *ip,
xfs_extlen_t extsize,
xfs_fileoff_t *last_fsb)
{
xfs_fileoff_t new_last_fsb = 0;
xfs_extlen_t align = 0;
int eof, error;
if (!XFS_IS_REALTIME_INODE(ip)) {
if (mp->m_swidth && (mp->m_flags & XFS_MOUNT_SWALLOC))
align = mp->m_swidth;
else if (mp->m_dalign)
align = mp->m_dalign;
if (align && XFS_ISIZE(ip) >= XFS_FSB_TO_B(mp, align))
new_last_fsb = roundup_64(*last_fsb, align);
}
if (extsize) {
if (new_last_fsb)
align = roundup_64(new_last_fsb, extsize);
else
align = extsize;
new_last_fsb = roundup_64(*last_fsb, align);
}
if (new_last_fsb) {
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
return EFSCORRUPTED;
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
xfs_bmap_free_t free_list;
uint qblocks, resblks, resrtextents;
int committed;
int error;
error = xfs_qm_dqattach(ip, 0);
if (error)
return XFS_ERROR(error);
rt = XFS_IS_REALTIME_INODE(ip);
extsz = xfs_get_extsz_hint(ip);
offset_fsb = XFS_B_TO_FSBT(mp, offset);
last_fsb = XFS_B_TO_FSB(mp, ((xfs_ufsize_t)(offset + count)));
if ((offset + count) > XFS_ISIZE(ip)) {
error = xfs_iomap_eof_align_last_fsb(mp, ip, extsz, &last_fsb);
if (error)
return XFS_ERROR(error);
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
tp = xfs_trans_alloc(mp, XFS_TRANS_DIOSTRAT);
error = xfs_trans_reserve(tp, &M_RES(mp)->tr_write,
resblks, resrtextents);
if (error) {
xfs_trans_cancel(tp, 0);
return XFS_ERROR(error);
}
xfs_ilock(ip, XFS_ILOCK_EXCL);
error = xfs_trans_reserve_quota_nblks(tp, ip, qblocks, 0, quota_flag);
if (error)
goto out_trans_cancel;
xfs_trans_ijoin(tp, ip, 0);
xfs_bmap_init(&free_list, &firstfsb);
nimaps = 1;
error = xfs_bmapi_write(tp, ip, offset_fsb, count_fsb,
XFS_BMAPI_PREALLOC, &firstfsb, 0,
imap, &nimaps, &free_list);
if (error)
goto out_bmap_cancel;
error = xfs_bmap_finish(&tp, &free_list, &committed);
if (error)
goto out_bmap_cancel;
error = xfs_trans_commit(tp, XFS_TRANS_RELEASE_LOG_RES);
if (error)
goto out_unlock;
if (nimaps == 0) {
error = XFS_ERROR(ENOSPC);
goto out_unlock;
}
if (!(imap->br_startblock || XFS_IS_REALTIME_INODE(ip)))
error = xfs_alert_fsblock_zero(ip, imap);
out_unlock:
xfs_iunlock(ip, XFS_ILOCK_EXCL);
return error;
out_bmap_cancel:
xfs_bmap_cancel(&free_list);
xfs_trans_unreserve_quota_nblks(tp, ip, (long)qblocks, 0, quota_flag);
out_trans_cancel:
xfs_trans_cancel(tp, XFS_TRANS_RELEASE_LOG_RES | XFS_TRANS_ABORT);
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
xfs_fsblock_t firstblock;
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
firstblock = NULLFSBLOCK;
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
int *qshift)
{
int64_t freesp;
int shift = 0;
struct xfs_dquot *dq = xfs_inode_dquot(ip, type);
if (dq->q_res_bcount >= dq->q_prealloc_hi_wmark) {
*qblocks = 0;
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
xfs_icsb_sync_counters(mp, XFS_ICSB_LAZY_COUNT);
freesp = mp->m_sb.sb_fdblocks;
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
xfs_quota_calc_throttle(ip, XFS_DQ_USER, &qblocks, &qshift);
if (xfs_quota_need_throttle(ip, XFS_DQ_GROUP, alloc_blocks))
xfs_quota_calc_throttle(ip, XFS_DQ_GROUP, &qblocks, &qshift);
if (xfs_quota_need_throttle(ip, XFS_DQ_PROJ, alloc_blocks))
xfs_quota_calc_throttle(ip, XFS_DQ_PROJ, &qblocks, &qshift);
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
return XFS_ERROR(error);
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
case ENOSPC:
case EDQUOT:
break;
default:
return XFS_ERROR(error);
}
if (nimaps == 0) {
trace_xfs_delalloc_enospc(ip, offset, count);
if (prealloc) {
prealloc = 0;
error = 0;
goto retry;
}
return XFS_ERROR(error ? error : ENOSPC);
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
xfs_bmap_free_t free_list;
xfs_filblks_t count_fsb;
xfs_trans_t *tp;
int nimaps, committed;
int error = 0;
int nres;
error = xfs_qm_dqattach(ip, 0);
if (error)
return XFS_ERROR(error);
offset_fsb = XFS_B_TO_FSBT(mp, offset);
count_fsb = imap->br_blockcount;
map_start_fsb = imap->br_startoff;
XFS_STATS_ADD(xs_xstrat_bytes, XFS_FSB_TO_B(mp, count_fsb));
while (count_fsb != 0) {
nimaps = 0;
while (nimaps == 0) {
tp = xfs_trans_alloc(mp, XFS_TRANS_STRAT_WRITE);
tp->t_flags |= XFS_TRANS_RESERVE;
nres = XFS_EXTENTADD_SPACE_RES(mp, XFS_DATA_FORK);
error = xfs_trans_reserve(tp, &M_RES(mp)->tr_write,
nres, 0);
if (error) {
xfs_trans_cancel(tp, 0);
return XFS_ERROR(error);
}
xfs_ilock(ip, XFS_ILOCK_EXCL);
xfs_trans_ijoin(tp, ip, 0);
xfs_bmap_init(&free_list, &first_block);
nimaps = 1;
end_fsb = XFS_B_TO_FSB(mp, XFS_ISIZE(ip));
error = xfs_bmap_last_offset(NULL, ip, &last_block,
XFS_DATA_FORK);
if (error)
goto trans_cancel;
last_block = XFS_FILEOFF_MAX(last_block, end_fsb);
if ((map_start_fsb + count_fsb) > last_block) {
count_fsb = last_block - map_start_fsb;
if (count_fsb == 0) {
error = EAGAIN;
goto trans_cancel;
}
}
error = xfs_bmapi_write(tp, ip, map_start_fsb,
count_fsb,
XFS_BMAPI_STACK_SWITCH,
&first_block, 1,
imap, &nimaps, &free_list);
if (error)
goto trans_cancel;
error = xfs_bmap_finish(&tp, &free_list, &committed);
if (error)
goto trans_cancel;
error = xfs_trans_commit(tp, XFS_TRANS_RELEASE_LOG_RES);
if (error)
goto error0;
xfs_iunlock(ip, XFS_ILOCK_EXCL);
}
if (!(imap->br_startblock || XFS_IS_REALTIME_INODE(ip)))
return xfs_alert_fsblock_zero(ip, imap);
if ((offset_fsb >= imap->br_startoff) &&
(offset_fsb < (imap->br_startoff +
imap->br_blockcount))) {
XFS_STATS_INC(xs_xstrat_quick);
return 0;
}
count_fsb -= imap->br_blockcount;
map_start_fsb = imap->br_startoff + imap->br_blockcount;
}
trans_cancel:
xfs_bmap_cancel(&free_list);
xfs_trans_cancel(tp, XFS_TRANS_RELEASE_LOG_RES | XFS_TRANS_ABORT);
error0:
xfs_iunlock(ip, XFS_ILOCK_EXCL);
return XFS_ERROR(error);
}
int
xfs_iomap_write_unwritten(
xfs_inode_t *ip,
xfs_off_t offset,
size_t count)
{
xfs_mount_t *mp = ip->i_mount;
xfs_fileoff_t offset_fsb;
xfs_filblks_t count_fsb;
xfs_filblks_t numblks_fsb;
xfs_fsblock_t firstfsb;
int nimaps;
xfs_trans_t *tp;
xfs_bmbt_irec_t imap;
xfs_bmap_free_t free_list;
xfs_fsize_t i_size;
uint resblks;
int committed;
int error;
trace_xfs_unwritten_convert(ip, offset, count);
offset_fsb = XFS_B_TO_FSBT(mp, offset);
count_fsb = XFS_B_TO_FSB(mp, (xfs_ufsize_t)offset + count);
count_fsb = (xfs_filblks_t)(count_fsb - offset_fsb);
resblks = XFS_DIOSTRAT_SPACE_RES(mp, 0) << 1;
do {
sb_start_intwrite(mp->m_super);
tp = _xfs_trans_alloc(mp, XFS_TRANS_STRAT_WRITE, KM_NOFS);
tp->t_flags |= XFS_TRANS_RESERVE | XFS_TRANS_FREEZE_PROT;
error = xfs_trans_reserve(tp, &M_RES(mp)->tr_write,
resblks, 0);
if (error) {
xfs_trans_cancel(tp, 0);
return XFS_ERROR(error);
}
xfs_ilock(ip, XFS_ILOCK_EXCL);
xfs_trans_ijoin(tp, ip, 0);
xfs_bmap_init(&free_list, &firstfsb);
nimaps = 1;
error = xfs_bmapi_write(tp, ip, offset_fsb, count_fsb,
XFS_BMAPI_CONVERT, &firstfsb,
1, &imap, &nimaps, &free_list);
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
error = xfs_bmap_finish(&tp, &free_list, &committed);
if (error)
goto error_on_bmapi_transaction;
error = xfs_trans_commit(tp, XFS_TRANS_RELEASE_LOG_RES);
xfs_iunlock(ip, XFS_ILOCK_EXCL);
if (error)
return XFS_ERROR(error);
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
xfs_bmap_cancel(&free_list);
xfs_trans_cancel(tp, (XFS_TRANS_RELEASE_LOG_RES | XFS_TRANS_ABORT));
xfs_iunlock(ip, XFS_ILOCK_EXCL);
return XFS_ERROR(error);
}
