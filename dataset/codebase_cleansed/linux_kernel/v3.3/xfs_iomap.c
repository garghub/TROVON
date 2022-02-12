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
"blkcnt: %llx extent-state: %x\n",
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
int bmapi_flag;
int quota_flag;
int rt;
xfs_trans_t *tp;
xfs_bmap_free_t free_list;
uint qblocks, resblks, resrtextents;
int committed;
int error;
error = xfs_qm_dqattach_locked(ip, 0);
if (error)
return XFS_ERROR(error);
rt = XFS_IS_REALTIME_INODE(ip);
extsz = xfs_get_extsz_hint(ip);
offset_fsb = XFS_B_TO_FSBT(mp, offset);
last_fsb = XFS_B_TO_FSB(mp, ((xfs_ufsize_t)(offset + count)));
if ((offset + count) > XFS_ISIZE(ip)) {
error = xfs_iomap_eof_align_last_fsb(mp, ip, extsz, &last_fsb);
if (error)
goto error_out;
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
xfs_iunlock(ip, XFS_ILOCK_EXCL);
tp = xfs_trans_alloc(mp, XFS_TRANS_DIOSTRAT);
error = xfs_trans_reserve(tp, resblks,
XFS_WRITE_LOG_RES(mp), resrtextents,
XFS_TRANS_PERM_LOG_RES,
XFS_WRITE_LOG_COUNT);
if (error)
xfs_trans_cancel(tp, 0);
xfs_ilock(ip, XFS_ILOCK_EXCL);
if (error)
goto error_out;
error = xfs_trans_reserve_quota_nblks(tp, ip, qblocks, 0, quota_flag);
if (error)
goto error1;
xfs_trans_ijoin(tp, ip, 0);
bmapi_flag = 0;
if (offset < XFS_ISIZE(ip) || extsz)
bmapi_flag |= XFS_BMAPI_PREALLOC;
xfs_bmap_init(&free_list, &firstfsb);
nimaps = 1;
error = xfs_bmapi_write(tp, ip, offset_fsb, count_fsb, bmapi_flag,
&firstfsb, 0, imap, &nimaps, &free_list);
if (error)
goto error0;
error = xfs_bmap_finish(&tp, &free_list, &committed);
if (error)
goto error0;
error = xfs_trans_commit(tp, XFS_TRANS_RELEASE_LOG_RES);
if (error)
goto error_out;
if (nimaps == 0) {
error = ENOSPC;
goto error_out;
}
if (!(imap->br_startblock || XFS_IS_REALTIME_INODE(ip))) {
error = xfs_alert_fsblock_zero(ip, imap);
goto error_out;
}
return 0;
error0:
xfs_bmap_cancel(&free_list);
xfs_trans_unreserve_quota_nblks(tp, ip, qblocks, 0, quota_flag);
error1:
xfs_trans_cancel(tp, XFS_TRANS_RELEASE_LOG_RES | XFS_TRANS_ABORT);
error_out:
return XFS_ERROR(error);
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
start_fsb = XFS_B_TO_FSBT(mp, ((xfs_ufsize_t)(offset + count - 1)));
count_fsb = XFS_B_TO_FSB(mp, (xfs_ufsize_t)XFS_MAXIOFFSET(mp));
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
xfs_iomap_prealloc_size(
struct xfs_mount *mp,
struct xfs_inode *ip)
{
xfs_fsblock_t alloc_blocks = 0;
if (!(mp->m_flags & XFS_MOUNT_DFLT_IOSIZE)) {
int shift = 0;
int64_t freesp;
alloc_blocks = XFS_B_TO_FSB(mp, XFS_ISIZE(ip)) + 1;
alloc_blocks = XFS_FILEOFF_MIN(MAXEXTLEN,
rounddown_pow_of_two(alloc_blocks));
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
if (shift)
alloc_blocks >>= shift;
}
if (alloc_blocks < mp->m_writeio_blocks)
alloc_blocks = mp->m_writeio_blocks;
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
int prealloc, flushed = 0;
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
xfs_fsblock_t alloc_blocks = xfs_iomap_prealloc_size(mp, ip);
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
if (flushed)
return XFS_ERROR(error ? error : ENOSPC);
if (error == ENOSPC) {
xfs_iunlock(ip, XFS_ILOCK_EXCL);
xfs_flush_inodes(ip);
xfs_ilock(ip, XFS_ILOCK_EXCL);
}
flushed = 1;
error = 0;
prealloc = 0;
goto retry;
}
if (!(imap[0].br_startblock || XFS_IS_REALTIME_INODE(ip)))
return xfs_alert_fsblock_zero(ip, &imap[0]);
*ret_imap = imap[0];
return 0;
}
int
xfs_iomap_write_allocate(
xfs_inode_t *ip,
xfs_off_t offset,
size_t count,
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
error = xfs_trans_reserve(tp, nres,
XFS_WRITE_LOG_RES(mp),
0, XFS_TRANS_PERM_LOG_RES,
XFS_WRITE_LOG_COUNT);
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
count_fsb, 0, &first_block, 1,
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
uint resblks;
int committed;
int error;
trace_xfs_unwritten_convert(ip, offset, count);
offset_fsb = XFS_B_TO_FSBT(mp, offset);
count_fsb = XFS_B_TO_FSB(mp, (xfs_ufsize_t)offset + count);
count_fsb = (xfs_filblks_t)(count_fsb - offset_fsb);
resblks = XFS_DIOSTRAT_SPACE_RES(mp, 0) << 1;
do {
xfs_wait_for_freeze(mp, SB_FREEZE_TRANS);
tp = _xfs_trans_alloc(mp, XFS_TRANS_STRAT_WRITE, KM_NOFS);
tp->t_flags |= XFS_TRANS_RESERVE;
error = xfs_trans_reserve(tp, resblks,
XFS_WRITE_LOG_RES(mp), 0,
XFS_TRANS_PERM_LOG_RES,
XFS_WRITE_LOG_COUNT);
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
error = xfs_bmap_finish(&(tp), &(free_list), &committed);
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
