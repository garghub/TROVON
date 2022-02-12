int
xfs_reflink_find_shared(
struct xfs_mount *mp,
xfs_agnumber_t agno,
xfs_agblock_t agbno,
xfs_extlen_t aglen,
xfs_agblock_t *fbno,
xfs_extlen_t *flen,
bool find_end_of_shared)
{
struct xfs_buf *agbp;
struct xfs_btree_cur *cur;
int error;
error = xfs_alloc_read_agf(mp, NULL, agno, 0, &agbp);
if (error)
return error;
cur = xfs_refcountbt_init_cursor(mp, NULL, agbp, agno, NULL);
error = xfs_refcount_find_shared(cur, agbno, aglen, fbno, flen,
find_end_of_shared);
xfs_btree_del_cursor(cur, error ? XFS_BTREE_ERROR : XFS_BTREE_NOERROR);
xfs_buf_relse(agbp);
return error;
}
int
xfs_reflink_trim_around_shared(
struct xfs_inode *ip,
struct xfs_bmbt_irec *irec,
bool *shared,
bool *trimmed)
{
xfs_agnumber_t agno;
xfs_agblock_t agbno;
xfs_extlen_t aglen;
xfs_agblock_t fbno;
xfs_extlen_t flen;
int error = 0;
if (!xfs_is_reflink_inode(ip) ||
ISUNWRITTEN(irec) ||
irec->br_startblock == HOLESTARTBLOCK ||
irec->br_startblock == DELAYSTARTBLOCK ||
isnullstartblock(irec->br_startblock)) {
*shared = false;
return 0;
}
trace_xfs_reflink_trim_around_shared(ip, irec);
agno = XFS_FSB_TO_AGNO(ip->i_mount, irec->br_startblock);
agbno = XFS_FSB_TO_AGBNO(ip->i_mount, irec->br_startblock);
aglen = irec->br_blockcount;
error = xfs_reflink_find_shared(ip->i_mount, agno, agbno,
aglen, &fbno, &flen, true);
if (error)
return error;
*shared = *trimmed = false;
if (fbno == NULLAGBLOCK) {
return 0;
} else if (fbno == agbno) {
irec->br_blockcount = flen;
*shared = true;
if (flen != aglen)
*trimmed = true;
return 0;
} else {
irec->br_blockcount = fbno - agbno;
*trimmed = true;
return 0;
}
}
int
xfs_reflink_reserve_cow(
struct xfs_inode *ip,
struct xfs_bmbt_irec *imap,
bool *shared)
{
struct xfs_ifork *ifp = XFS_IFORK_PTR(ip, XFS_COW_FORK);
struct xfs_bmbt_irec got;
int error = 0;
bool eof = false, trimmed;
xfs_extnum_t idx;
if (!xfs_iext_lookup_extent(ip, ifp, imap->br_startoff, &idx, &got))
eof = true;
if (!eof && got.br_startoff <= imap->br_startoff) {
trace_xfs_reflink_cow_found(ip, imap);
xfs_trim_extent(imap, got.br_startoff, got.br_blockcount);
*shared = true;
return 0;
}
error = xfs_reflink_trim_around_shared(ip, imap, shared, &trimmed);
if (error)
return error;
if (!*shared)
return 0;
error = xfs_qm_dqattach_locked(ip, 0);
if (error)
return error;
error = xfs_bmapi_reserve_delalloc(ip, XFS_COW_FORK, imap->br_startoff,
imap->br_blockcount, 0, &got, &idx, eof);
if (error == -ENOSPC || error == -EDQUOT)
trace_xfs_reflink_cow_enospc(ip, imap);
if (error)
return error;
trace_xfs_reflink_cow_alloc(ip, &got);
return 0;
}
STATIC int
xfs_reflink_convert_cow_extent(
struct xfs_inode *ip,
struct xfs_bmbt_irec *imap,
xfs_fileoff_t offset_fsb,
xfs_filblks_t count_fsb,
struct xfs_defer_ops *dfops)
{
xfs_fsblock_t first_block;
int nimaps = 1;
if (imap->br_state == XFS_EXT_NORM)
return 0;
xfs_trim_extent(imap, offset_fsb, count_fsb);
trace_xfs_reflink_convert_cow(ip, imap);
if (imap->br_blockcount == 0)
return 0;
return xfs_bmapi_write(NULL, ip, imap->br_startoff, imap->br_blockcount,
XFS_BMAPI_COWFORK | XFS_BMAPI_CONVERT, &first_block,
0, imap, &nimaps, dfops);
}
int
xfs_reflink_convert_cow(
struct xfs_inode *ip,
xfs_off_t offset,
xfs_off_t count)
{
struct xfs_bmbt_irec got;
struct xfs_defer_ops dfops;
struct xfs_mount *mp = ip->i_mount;
struct xfs_ifork *ifp = XFS_IFORK_PTR(ip, XFS_COW_FORK);
xfs_fileoff_t offset_fsb = XFS_B_TO_FSBT(mp, offset);
xfs_fileoff_t end_fsb = XFS_B_TO_FSB(mp, offset + count);
xfs_extnum_t idx;
bool found;
int error = 0;
xfs_ilock(ip, XFS_ILOCK_EXCL);
for (found = xfs_iext_lookup_extent(ip, ifp, offset_fsb, &idx, &got);
found && got.br_startoff < end_fsb;
found = xfs_iext_get_extent(ifp, ++idx, &got)) {
error = xfs_reflink_convert_cow_extent(ip, &got, offset_fsb,
end_fsb - offset_fsb, &dfops);
if (error)
break;
}
xfs_iunlock(ip, XFS_ILOCK_EXCL);
return error;
}
int
xfs_reflink_allocate_cow(
struct xfs_inode *ip,
struct xfs_bmbt_irec *imap,
bool *shared,
uint *lockmode)
{
struct xfs_mount *mp = ip->i_mount;
xfs_fileoff_t offset_fsb = imap->br_startoff;
xfs_filblks_t count_fsb = imap->br_blockcount;
struct xfs_bmbt_irec got;
struct xfs_defer_ops dfops;
struct xfs_trans *tp = NULL;
xfs_fsblock_t first_block;
int nimaps, error = 0;
bool trimmed;
xfs_filblks_t resaligned;
xfs_extlen_t resblks = 0;
xfs_extnum_t idx;
retry:
ASSERT(xfs_is_reflink_inode(ip));
ASSERT(xfs_isilocked(ip, XFS_ILOCK_EXCL | XFS_ILOCK_SHARED));
if (xfs_iext_lookup_extent(ip, ip->i_cowfp, offset_fsb, &idx, &got) &&
got.br_startoff <= offset_fsb) {
*shared = true;
if (!isnullstartblock(got.br_startblock)) {
xfs_trim_extent(&got, offset_fsb, count_fsb);
*imap = got;
goto convert;
}
xfs_trim_extent(imap, got.br_startoff, got.br_blockcount);
} else {
error = xfs_reflink_trim_around_shared(ip, imap, shared, &trimmed);
if (error || !*shared)
goto out;
}
if (!tp) {
resaligned = xfs_aligned_fsb_count(imap->br_startoff,
imap->br_blockcount, xfs_get_cowextsz_hint(ip));
resblks = XFS_DIOSTRAT_SPACE_RES(mp, resaligned);
xfs_iunlock(ip, *lockmode);
error = xfs_trans_alloc(mp, &M_RES(mp)->tr_write, resblks, 0, 0, &tp);
*lockmode = XFS_ILOCK_EXCL;
xfs_ilock(ip, *lockmode);
if (error)
return error;
error = xfs_qm_dqattach_locked(ip, 0);
if (error)
goto out;
goto retry;
}
error = xfs_trans_reserve_quota_nblks(tp, ip, resblks, 0,
XFS_QMOPT_RES_REGBLKS);
if (error)
goto out;
xfs_trans_ijoin(tp, ip, 0);
xfs_defer_init(&dfops, &first_block);
nimaps = 1;
error = xfs_bmapi_write(tp, ip, imap->br_startoff, imap->br_blockcount,
XFS_BMAPI_COWFORK | XFS_BMAPI_PREALLOC, &first_block,
resblks, imap, &nimaps, &dfops);
if (error)
goto out_bmap_cancel;
error = xfs_defer_finish(&tp, &dfops, NULL);
if (error)
goto out_bmap_cancel;
error = xfs_trans_commit(tp);
if (error)
return error;
convert:
return xfs_reflink_convert_cow_extent(ip, imap, offset_fsb, count_fsb,
&dfops);
out_bmap_cancel:
xfs_defer_cancel(&dfops);
xfs_trans_unreserve_quota_nblks(tp, ip, (long)resblks, 0,
XFS_QMOPT_RES_REGBLKS);
out:
if (tp)
xfs_trans_cancel(tp);
return error;
}
bool
xfs_reflink_find_cow_mapping(
struct xfs_inode *ip,
xfs_off_t offset,
struct xfs_bmbt_irec *imap)
{
struct xfs_ifork *ifp = XFS_IFORK_PTR(ip, XFS_COW_FORK);
xfs_fileoff_t offset_fsb;
struct xfs_bmbt_irec got;
xfs_extnum_t idx;
ASSERT(xfs_isilocked(ip, XFS_ILOCK_EXCL | XFS_ILOCK_SHARED));
ASSERT(xfs_is_reflink_inode(ip));
offset_fsb = XFS_B_TO_FSBT(ip->i_mount, offset);
if (!xfs_iext_lookup_extent(ip, ifp, offset_fsb, &idx, &got))
return false;
if (got.br_startoff > offset_fsb)
return false;
trace_xfs_reflink_find_cow_mapping(ip, offset, 1, XFS_IO_OVERWRITE,
&got);
*imap = got;
return true;
}
void
xfs_reflink_trim_irec_to_next_cow(
struct xfs_inode *ip,
xfs_fileoff_t offset_fsb,
struct xfs_bmbt_irec *imap)
{
struct xfs_ifork *ifp = XFS_IFORK_PTR(ip, XFS_COW_FORK);
struct xfs_bmbt_irec got;
xfs_extnum_t idx;
if (!xfs_is_reflink_inode(ip))
return;
if (!xfs_iext_lookup_extent(ip, ifp, offset_fsb, &idx, &got))
return;
if (got.br_startoff < offset_fsb) {
if (!xfs_iext_get_extent(ifp, idx + 1, &got))
return;
}
if (got.br_startoff >= imap->br_startoff + imap->br_blockcount)
return;
imap->br_blockcount = got.br_startoff - imap->br_startoff;
trace_xfs_reflink_trim_irec(ip, imap);
}
int
xfs_reflink_cancel_cow_blocks(
struct xfs_inode *ip,
struct xfs_trans **tpp,
xfs_fileoff_t offset_fsb,
xfs_fileoff_t end_fsb,
bool cancel_real)
{
struct xfs_ifork *ifp = XFS_IFORK_PTR(ip, XFS_COW_FORK);
struct xfs_bmbt_irec got, del;
xfs_extnum_t idx;
xfs_fsblock_t firstfsb;
struct xfs_defer_ops dfops;
int error = 0;
if (!xfs_is_reflink_inode(ip))
return 0;
if (!xfs_iext_lookup_extent(ip, ifp, offset_fsb, &idx, &got))
return 0;
while (got.br_startoff < end_fsb) {
del = got;
xfs_trim_extent(&del, offset_fsb, end_fsb - offset_fsb);
trace_xfs_reflink_cancel_cow(ip, &del);
if (isnullstartblock(del.br_startblock)) {
error = xfs_bmap_del_extent_delay(ip, XFS_COW_FORK,
&idx, &got, &del);
if (error)
break;
} else if (del.br_state == XFS_EXT_UNWRITTEN || cancel_real) {
xfs_trans_ijoin(*tpp, ip, 0);
xfs_defer_init(&dfops, &firstfsb);
error = xfs_refcount_free_cow_extent(ip->i_mount,
&dfops, del.br_startblock,
del.br_blockcount);
if (error)
break;
xfs_bmap_add_free(ip->i_mount, &dfops,
del.br_startblock, del.br_blockcount,
NULL);
xfs_trans_mod_dquot_byino(*tpp, ip, XFS_TRANS_DQ_BCOUNT,
-(long)del.br_blockcount);
error = xfs_defer_finish(tpp, &dfops, ip);
if (error) {
xfs_defer_cancel(&dfops);
break;
}
xfs_bmap_del_extent_cow(ip, &idx, &got, &del);
}
if (!xfs_iext_get_extent(ifp, ++idx, &got))
break;
}
if (!ifp->if_bytes)
xfs_inode_clear_cowblocks_tag(ip);
return error;
}
int
xfs_reflink_cancel_cow_range(
struct xfs_inode *ip,
xfs_off_t offset,
xfs_off_t count,
bool cancel_real)
{
struct xfs_trans *tp;
xfs_fileoff_t offset_fsb;
xfs_fileoff_t end_fsb;
int error;
trace_xfs_reflink_cancel_cow_range(ip, offset, count);
ASSERT(xfs_is_reflink_inode(ip));
offset_fsb = XFS_B_TO_FSBT(ip->i_mount, offset);
if (count == NULLFILEOFF)
end_fsb = NULLFILEOFF;
else
end_fsb = XFS_B_TO_FSB(ip->i_mount, offset + count);
error = xfs_trans_alloc(ip->i_mount, &M_RES(ip->i_mount)->tr_write,
0, 0, 0, &tp);
if (error)
goto out;
xfs_ilock(ip, XFS_ILOCK_EXCL);
xfs_trans_ijoin(tp, ip, 0);
error = xfs_reflink_cancel_cow_blocks(ip, &tp, offset_fsb, end_fsb,
cancel_real);
if (error)
goto out_cancel;
error = xfs_trans_commit(tp);
xfs_iunlock(ip, XFS_ILOCK_EXCL);
return error;
out_cancel:
xfs_trans_cancel(tp);
xfs_iunlock(ip, XFS_ILOCK_EXCL);
out:
trace_xfs_reflink_cancel_cow_range_error(ip, error, _RET_IP_);
return error;
}
int
xfs_reflink_end_cow(
struct xfs_inode *ip,
xfs_off_t offset,
xfs_off_t count)
{
struct xfs_ifork *ifp = XFS_IFORK_PTR(ip, XFS_COW_FORK);
struct xfs_bmbt_irec got, del;
struct xfs_trans *tp;
xfs_fileoff_t offset_fsb;
xfs_fileoff_t end_fsb;
xfs_fsblock_t firstfsb;
struct xfs_defer_ops dfops;
int error;
unsigned int resblks;
xfs_filblks_t rlen;
xfs_extnum_t idx;
trace_xfs_reflink_end_cow(ip, offset, count);
if (ifp->if_bytes == 0)
return 0;
offset_fsb = XFS_B_TO_FSBT(ip->i_mount, offset);
end_fsb = XFS_B_TO_FSB(ip->i_mount, offset + count);
resblks = XFS_EXTENTADD_SPACE_RES(ip->i_mount, XFS_DATA_FORK);
error = xfs_trans_alloc(ip->i_mount, &M_RES(ip->i_mount)->tr_write,
resblks, 0, 0, &tp);
if (error)
goto out;
xfs_ilock(ip, XFS_ILOCK_EXCL);
xfs_trans_ijoin(tp, ip, 0);
if (!xfs_iext_lookup_extent(ip, ifp, end_fsb - 1, &idx, &got) ||
got.br_startoff > end_fsb) {
ASSERT(idx > 0);
xfs_iext_get_extent(ifp, --idx, &got);
}
while (got.br_startoff + got.br_blockcount > offset_fsb) {
del = got;
xfs_trim_extent(&del, offset_fsb, end_fsb - offset_fsb);
if (!del.br_blockcount) {
idx--;
goto next_extent;
}
ASSERT(!isnullstartblock(got.br_startblock));
if (got.br_state == XFS_EXT_UNWRITTEN) {
idx--;
goto next_extent;
}
xfs_defer_init(&dfops, &firstfsb);
rlen = del.br_blockcount;
error = __xfs_bunmapi(tp, ip, del.br_startoff, &rlen, 0, 1,
&firstfsb, &dfops);
if (error)
goto out_defer;
if (rlen) {
xfs_trim_extent(&del, del.br_startoff + rlen,
del.br_blockcount - rlen);
}
trace_xfs_reflink_cow_remap(ip, &del);
error = xfs_refcount_free_cow_extent(tp->t_mountp, &dfops,
del.br_startblock, del.br_blockcount);
if (error)
goto out_defer;
error = xfs_bmap_map_extent(tp->t_mountp, &dfops, ip, &del);
if (error)
goto out_defer;
xfs_bmap_del_extent_cow(ip, &idx, &got, &del);
error = xfs_defer_finish(&tp, &dfops, ip);
if (error)
goto out_defer;
next_extent:
if (!xfs_iext_get_extent(ifp, idx, &got))
break;
}
error = xfs_trans_commit(tp);
xfs_iunlock(ip, XFS_ILOCK_EXCL);
if (error)
goto out;
return 0;
out_defer:
xfs_defer_cancel(&dfops);
xfs_trans_cancel(tp);
xfs_iunlock(ip, XFS_ILOCK_EXCL);
out:
trace_xfs_reflink_end_cow_error(ip, error, _RET_IP_);
return error;
}
int
xfs_reflink_recover_cow(
struct xfs_mount *mp)
{
xfs_agnumber_t agno;
int error = 0;
if (!xfs_sb_version_hasreflink(&mp->m_sb))
return 0;
for (agno = 0; agno < mp->m_sb.sb_agcount; agno++) {
error = xfs_refcount_recover_cow_leftovers(mp, agno);
if (error)
break;
}
return error;
}
STATIC int
xfs_reflink_set_inode_flag(
struct xfs_inode *src,
struct xfs_inode *dest)
{
struct xfs_mount *mp = src->i_mount;
int error;
struct xfs_trans *tp;
if (xfs_is_reflink_inode(src) && xfs_is_reflink_inode(dest))
return 0;
error = xfs_trans_alloc(mp, &M_RES(mp)->tr_ichange, 0, 0, 0, &tp);
if (error)
goto out_error;
if (src->i_ino == dest->i_ino)
xfs_ilock(src, XFS_ILOCK_EXCL);
else
xfs_lock_two_inodes(src, dest, XFS_ILOCK_EXCL);
if (!xfs_is_reflink_inode(src)) {
trace_xfs_reflink_set_inode_flag(src);
xfs_trans_ijoin(tp, src, XFS_ILOCK_EXCL);
src->i_d.di_flags2 |= XFS_DIFLAG2_REFLINK;
xfs_trans_log_inode(tp, src, XFS_ILOG_CORE);
xfs_ifork_init_cow(src);
} else
xfs_iunlock(src, XFS_ILOCK_EXCL);
if (src->i_ino == dest->i_ino)
goto commit_flags;
if (!xfs_is_reflink_inode(dest)) {
trace_xfs_reflink_set_inode_flag(dest);
xfs_trans_ijoin(tp, dest, XFS_ILOCK_EXCL);
dest->i_d.di_flags2 |= XFS_DIFLAG2_REFLINK;
xfs_trans_log_inode(tp, dest, XFS_ILOG_CORE);
xfs_ifork_init_cow(dest);
} else
xfs_iunlock(dest, XFS_ILOCK_EXCL);
commit_flags:
error = xfs_trans_commit(tp);
if (error)
goto out_error;
return error;
out_error:
trace_xfs_reflink_set_inode_flag_error(dest, error, _RET_IP_);
return error;
}
STATIC int
xfs_reflink_update_dest(
struct xfs_inode *dest,
xfs_off_t newlen,
xfs_extlen_t cowextsize,
bool is_dedupe)
{
struct xfs_mount *mp = dest->i_mount;
struct xfs_trans *tp;
int error;
if (is_dedupe && newlen <= i_size_read(VFS_I(dest)) && cowextsize == 0)
return 0;
error = xfs_trans_alloc(mp, &M_RES(mp)->tr_ichange, 0, 0, 0, &tp);
if (error)
goto out_error;
xfs_ilock(dest, XFS_ILOCK_EXCL);
xfs_trans_ijoin(tp, dest, XFS_ILOCK_EXCL);
if (newlen > i_size_read(VFS_I(dest))) {
trace_xfs_reflink_update_inode_size(dest, newlen);
i_size_write(VFS_I(dest), newlen);
dest->i_d.di_size = newlen;
}
if (cowextsize) {
dest->i_d.di_cowextsize = cowextsize;
dest->i_d.di_flags2 |= XFS_DIFLAG2_COWEXTSIZE;
}
if (!is_dedupe) {
xfs_trans_ichgtime(tp, dest,
XFS_ICHGTIME_MOD | XFS_ICHGTIME_CHG);
}
xfs_trans_log_inode(tp, dest, XFS_ILOG_CORE);
error = xfs_trans_commit(tp);
if (error)
goto out_error;
return error;
out_error:
trace_xfs_reflink_update_inode_size_error(dest, error, _RET_IP_);
return error;
}
static int
xfs_reflink_ag_has_free_space(
struct xfs_mount *mp,
xfs_agnumber_t agno)
{
struct xfs_perag *pag;
int error = 0;
if (!xfs_sb_version_hasrmapbt(&mp->m_sb))
return 0;
pag = xfs_perag_get(mp, agno);
if (xfs_ag_resv_critical(pag, XFS_AG_RESV_AGFL) ||
xfs_ag_resv_critical(pag, XFS_AG_RESV_METADATA))
error = -ENOSPC;
xfs_perag_put(pag);
return error;
}
STATIC int
xfs_reflink_remap_extent(
struct xfs_inode *ip,
struct xfs_bmbt_irec *irec,
xfs_fileoff_t destoff,
xfs_off_t new_isize)
{
struct xfs_mount *mp = ip->i_mount;
struct xfs_trans *tp;
xfs_fsblock_t firstfsb;
unsigned int resblks;
struct xfs_defer_ops dfops;
struct xfs_bmbt_irec uirec;
bool real_extent;
xfs_filblks_t rlen;
xfs_filblks_t unmap_len;
xfs_off_t newlen;
int error;
unmap_len = irec->br_startoff + irec->br_blockcount - destoff;
trace_xfs_reflink_punch_range(ip, destoff, unmap_len);
real_extent = (irec->br_startblock != HOLESTARTBLOCK &&
irec->br_startblock != DELAYSTARTBLOCK &&
!ISUNWRITTEN(irec));
if (real_extent) {
error = xfs_reflink_ag_has_free_space(mp,
XFS_FSB_TO_AGNO(mp, irec->br_startblock));
if (error)
goto out;
}
resblks = XFS_EXTENTADD_SPACE_RES(ip->i_mount, XFS_DATA_FORK);
error = xfs_trans_alloc(mp, &M_RES(mp)->tr_write, resblks, 0, 0, &tp);
if (error)
goto out;
xfs_ilock(ip, XFS_ILOCK_EXCL);
xfs_trans_ijoin(tp, ip, 0);
if (real_extent) {
error = xfs_trans_reserve_quota_nblks(tp, ip,
irec->br_blockcount, 0, XFS_QMOPT_RES_REGBLKS);
if (error)
goto out_cancel;
}
trace_xfs_reflink_remap(ip, irec->br_startoff,
irec->br_blockcount, irec->br_startblock);
rlen = unmap_len;
while (rlen) {
xfs_defer_init(&dfops, &firstfsb);
error = __xfs_bunmapi(tp, ip, destoff, &rlen, 0, 1,
&firstfsb, &dfops);
if (error)
goto out_defer;
uirec.br_startblock = irec->br_startblock + rlen;
uirec.br_startoff = irec->br_startoff + rlen;
uirec.br_blockcount = unmap_len - rlen;
unmap_len = rlen;
if (!real_extent || uirec.br_blockcount == 0)
goto next_extent;
trace_xfs_reflink_remap(ip, uirec.br_startoff,
uirec.br_blockcount, uirec.br_startblock);
error = xfs_refcount_increase_extent(mp, &dfops, &uirec);
if (error)
goto out_defer;
error = xfs_bmap_map_extent(mp, &dfops, ip, &uirec);
if (error)
goto out_defer;
xfs_trans_mod_dquot_byino(tp, ip, XFS_TRANS_DQ_BCOUNT,
uirec.br_blockcount);
newlen = XFS_FSB_TO_B(mp,
uirec.br_startoff + uirec.br_blockcount);
newlen = min_t(xfs_off_t, newlen, new_isize);
if (newlen > i_size_read(VFS_I(ip))) {
trace_xfs_reflink_update_inode_size(ip, newlen);
i_size_write(VFS_I(ip), newlen);
ip->i_d.di_size = newlen;
xfs_trans_log_inode(tp, ip, XFS_ILOG_CORE);
}
next_extent:
error = xfs_defer_finish(&tp, &dfops, ip);
if (error)
goto out_defer;
}
error = xfs_trans_commit(tp);
xfs_iunlock(ip, XFS_ILOCK_EXCL);
if (error)
goto out;
return 0;
out_defer:
xfs_defer_cancel(&dfops);
out_cancel:
xfs_trans_cancel(tp);
xfs_iunlock(ip, XFS_ILOCK_EXCL);
out:
trace_xfs_reflink_remap_extent_error(ip, error, _RET_IP_);
return error;
}
STATIC int
xfs_reflink_remap_blocks(
struct xfs_inode *src,
xfs_fileoff_t srcoff,
struct xfs_inode *dest,
xfs_fileoff_t destoff,
xfs_filblks_t len,
xfs_off_t new_isize)
{
struct xfs_bmbt_irec imap;
int nimaps;
int error = 0;
xfs_filblks_t range_len;
while (len) {
trace_xfs_reflink_remap_blocks_loop(src, srcoff, len,
dest, destoff);
nimaps = 1;
xfs_ilock(src, XFS_ILOCK_EXCL);
error = xfs_bmapi_read(src, srcoff, len, &imap, &nimaps, 0);
xfs_iunlock(src, XFS_ILOCK_EXCL);
if (error)
goto err;
ASSERT(nimaps == 1);
trace_xfs_reflink_remap_imap(src, srcoff, len, XFS_IO_OVERWRITE,
&imap);
range_len = imap.br_startoff + imap.br_blockcount - srcoff;
imap.br_startoff += destoff - srcoff;
error = xfs_reflink_remap_extent(dest, &imap, destoff,
new_isize);
if (error)
goto err;
if (fatal_signal_pending(current)) {
error = -EINTR;
goto err;
}
srcoff += range_len;
destoff += range_len;
len -= range_len;
}
return 0;
err:
trace_xfs_reflink_remap_blocks_error(dest, error, _RET_IP_);
return error;
}
int
xfs_reflink_remap_range(
struct file *file_in,
loff_t pos_in,
struct file *file_out,
loff_t pos_out,
u64 len,
bool is_dedupe)
{
struct inode *inode_in = file_inode(file_in);
struct xfs_inode *src = XFS_I(inode_in);
struct inode *inode_out = file_inode(file_out);
struct xfs_inode *dest = XFS_I(inode_out);
struct xfs_mount *mp = src->i_mount;
bool same_inode = (inode_in == inode_out);
xfs_fileoff_t sfsbno, dfsbno;
xfs_filblks_t fsblen;
xfs_extlen_t cowextsize;
ssize_t ret;
if (!xfs_sb_version_hasreflink(&mp->m_sb))
return -EOPNOTSUPP;
if (XFS_FORCED_SHUTDOWN(mp))
return -EIO;
lock_two_nondirectories(inode_in, inode_out);
if (same_inode)
xfs_ilock(src, XFS_MMAPLOCK_EXCL);
else
xfs_lock_two_inodes(src, dest, XFS_MMAPLOCK_EXCL);
ret = -EINVAL;
if (XFS_IS_REALTIME_INODE(src) || XFS_IS_REALTIME_INODE(dest))
goto out_unlock;
if (IS_DAX(inode_in) || IS_DAX(inode_out))
goto out_unlock;
ret = vfs_clone_file_prep_inodes(inode_in, pos_in, inode_out, pos_out,
&len, is_dedupe);
if (ret <= 0)
goto out_unlock;
trace_xfs_reflink_remap_range(src, pos_in, len, dest, pos_out);
ret = xfs_reflink_set_inode_flag(src, dest);
if (ret)
goto out_unlock;
dfsbno = XFS_B_TO_FSBT(mp, pos_out);
sfsbno = XFS_B_TO_FSBT(mp, pos_in);
fsblen = XFS_B_TO_FSB(mp, len);
ret = xfs_reflink_remap_blocks(src, sfsbno, dest, dfsbno, fsblen,
pos_out + len);
if (ret)
goto out_unlock;
truncate_inode_pages_range(&inode_out->i_data, pos_out,
PAGE_ALIGN(pos_out + len) - 1);
cowextsize = 0;
if (pos_in == 0 && len == i_size_read(inode_in) &&
(src->i_d.di_flags2 & XFS_DIFLAG2_COWEXTSIZE) &&
pos_out == 0 && len >= i_size_read(inode_out) &&
!(dest->i_d.di_flags2 & XFS_DIFLAG2_COWEXTSIZE))
cowextsize = src->i_d.di_cowextsize;
ret = xfs_reflink_update_dest(dest, pos_out + len, cowextsize,
is_dedupe);
out_unlock:
xfs_iunlock(src, XFS_MMAPLOCK_EXCL);
if (!same_inode)
xfs_iunlock(dest, XFS_MMAPLOCK_EXCL);
unlock_two_nondirectories(inode_in, inode_out);
if (ret)
trace_xfs_reflink_remap_range_error(dest, ret, _RET_IP_);
return ret;
}
STATIC int
xfs_reflink_dirty_extents(
struct xfs_inode *ip,
xfs_fileoff_t fbno,
xfs_filblks_t end,
xfs_off_t isize)
{
struct xfs_mount *mp = ip->i_mount;
xfs_agnumber_t agno;
xfs_agblock_t agbno;
xfs_extlen_t aglen;
xfs_agblock_t rbno;
xfs_extlen_t rlen;
xfs_off_t fpos;
xfs_off_t flen;
struct xfs_bmbt_irec map[2];
int nmaps;
int error = 0;
while (end - fbno > 0) {
nmaps = 1;
error = xfs_bmapi_read(ip, fbno, end - fbno, map, &nmaps, 0);
if (error)
goto out;
if (nmaps == 0)
break;
if (map[0].br_startblock == HOLESTARTBLOCK ||
map[0].br_startblock == DELAYSTARTBLOCK ||
ISUNWRITTEN(&map[0]))
goto next;
map[1] = map[0];
while (map[1].br_blockcount) {
agno = XFS_FSB_TO_AGNO(mp, map[1].br_startblock);
agbno = XFS_FSB_TO_AGBNO(mp, map[1].br_startblock);
aglen = map[1].br_blockcount;
error = xfs_reflink_find_shared(mp, agno, agbno, aglen,
&rbno, &rlen, true);
if (error)
goto out;
if (rbno == NULLAGBLOCK)
break;
xfs_iunlock(ip, XFS_ILOCK_EXCL);
fpos = XFS_FSB_TO_B(mp, map[1].br_startoff +
(rbno - agbno));
flen = XFS_FSB_TO_B(mp, rlen);
if (fpos + flen > isize)
flen = isize - fpos;
error = iomap_file_dirty(VFS_I(ip), fpos, flen,
&xfs_iomap_ops);
xfs_ilock(ip, XFS_ILOCK_EXCL);
if (error)
goto out;
map[1].br_blockcount -= (rbno - agbno + rlen);
map[1].br_startoff += (rbno - agbno + rlen);
map[1].br_startblock += (rbno - agbno + rlen);
}
next:
fbno = map[0].br_startoff + map[0].br_blockcount;
}
out:
return error;
}
int
xfs_reflink_clear_inode_flag(
struct xfs_inode *ip,
struct xfs_trans **tpp)
{
struct xfs_mount *mp = ip->i_mount;
xfs_fileoff_t fbno;
xfs_filblks_t end;
xfs_agnumber_t agno;
xfs_agblock_t agbno;
xfs_extlen_t aglen;
xfs_agblock_t rbno;
xfs_extlen_t rlen;
struct xfs_bmbt_irec map;
int nmaps;
int error = 0;
ASSERT(xfs_is_reflink_inode(ip));
fbno = 0;
end = XFS_B_TO_FSB(mp, i_size_read(VFS_I(ip)));
while (end - fbno > 0) {
nmaps = 1;
error = xfs_bmapi_read(ip, fbno, end - fbno, &map, &nmaps, 0);
if (error)
return error;
if (nmaps == 0)
break;
if (map.br_startblock == HOLESTARTBLOCK ||
map.br_startblock == DELAYSTARTBLOCK ||
ISUNWRITTEN(&map))
goto next;
agno = XFS_FSB_TO_AGNO(mp, map.br_startblock);
agbno = XFS_FSB_TO_AGBNO(mp, map.br_startblock);
aglen = map.br_blockcount;
error = xfs_reflink_find_shared(mp, agno, agbno, aglen,
&rbno, &rlen, false);
if (error)
return error;
if (rbno != NULLAGBLOCK)
return 0;
next:
fbno = map.br_startoff + map.br_blockcount;
}
error = xfs_reflink_cancel_cow_blocks(ip, tpp, 0, NULLFILEOFF, true);
if (error)
return error;
trace_xfs_reflink_unset_inode_flag(ip);
ip->i_d.di_flags2 &= ~XFS_DIFLAG2_REFLINK;
xfs_inode_clear_cowblocks_tag(ip);
xfs_trans_ijoin(*tpp, ip, 0);
xfs_trans_log_inode(*tpp, ip, XFS_ILOG_CORE);
return error;
}
STATIC int
xfs_reflink_try_clear_inode_flag(
struct xfs_inode *ip)
{
struct xfs_mount *mp = ip->i_mount;
struct xfs_trans *tp;
int error = 0;
error = xfs_trans_alloc(mp, &M_RES(mp)->tr_write, 0, 0, 0, &tp);
if (error)
return error;
xfs_ilock(ip, XFS_ILOCK_EXCL);
xfs_trans_ijoin(tp, ip, 0);
error = xfs_reflink_clear_inode_flag(ip, &tp);
if (error)
goto cancel;
error = xfs_trans_commit(tp);
if (error)
goto out;
xfs_iunlock(ip, XFS_ILOCK_EXCL);
return 0;
cancel:
xfs_trans_cancel(tp);
out:
xfs_iunlock(ip, XFS_ILOCK_EXCL);
return error;
}
int
xfs_reflink_unshare(
struct xfs_inode *ip,
xfs_off_t offset,
xfs_off_t len)
{
struct xfs_mount *mp = ip->i_mount;
xfs_fileoff_t fbno;
xfs_filblks_t end;
xfs_off_t isize;
int error;
if (!xfs_is_reflink_inode(ip))
return 0;
trace_xfs_reflink_unshare(ip, offset, len);
inode_dio_wait(VFS_I(ip));
xfs_ilock(ip, XFS_ILOCK_EXCL);
fbno = XFS_B_TO_FSBT(mp, offset);
isize = i_size_read(VFS_I(ip));
end = XFS_B_TO_FSB(mp, offset + len);
error = xfs_reflink_dirty_extents(ip, fbno, end, isize);
if (error)
goto out_unlock;
xfs_iunlock(ip, XFS_ILOCK_EXCL);
error = filemap_write_and_wait(VFS_I(ip)->i_mapping);
if (error)
goto out;
error = xfs_reflink_try_clear_inode_flag(ip);
if (error)
goto out;
return 0;
out_unlock:
xfs_iunlock(ip, XFS_ILOCK_EXCL);
out:
trace_xfs_reflink_unshare_error(ip, error, _RET_IP_);
return error;
}
